#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "card.h"

#include <QGridLayout>
#include <QDir>
#include <QRandomGenerator>
#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    firstCard(nullptr),
    secondCard(nullptr)
{
    ui->setupUi(this);

    // mismatch için timer
    mismatchTimer.setSingleShot(true);
    connect(&mismatchTimer, &QTimer::timeout, this, &MainWindow::checkForMismatch);

    setupBoard();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupBoard()
{
    // Grid layout al (mainwindow.ui içinde merkezi widget)
    QWidget *central = centralWidget();

    QGridLayout *grid = new QGridLayout;
    central->setLayout(grid);

    // Resimleri yükle: images/img1.png ... img5.png
    QVector<QPixmap> fronts;
    for (int i = 1; i <= 5; ++i) {
        QString path = QString(":/images/img%1.png").arg(i);
        QPixmap p(path);
        if (p.isNull()) {
            // boş placeholder
            p = QPixmap(100,140);
            p.fill(Qt::gray);
        }
        fronts.append(p.scaled(100,140, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }

    // Her id'den iki tane olacak (çift)
    QVector<int> ids;
    for (int i = 0; i < fronts.size(); ++i) {
        ids.append(i);
        ids.append(i);
    }

    // karıştır
    for (int i = ids.size()-1; i>0; --i){
        int j = QRandomGenerator::global()->bounded(i+1);
        std::swap(ids[i], ids[j]);
    }

    // 2 satır 5 sütun
    int rows = 2, cols = 5;
    int idx = 0;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            int id = ids[idx++];
            Card *card = new Card(id, fronts[id], this);
            connect(card, &Card::cardClicked, this, &MainWindow::onCardClicked);
            cards.append(card);
            grid->addWidget(card, r, c);
        }
    }

    /****/
    tahminLabel = new QLabel("Başarısız tahmin: 0", this);
    tahminLabel->setAlignment(Qt::AlignCenter);

}

void MainWindow::onCardClicked(Card *card)
{
    if (firstCard && secondCard) return; // kontrol esnasında tıklama engelle

    card->reveal();

    if (!firstCard) {
        firstCard = card;
        return;
    }

    if (firstCard == card) return;

    secondCard = card;

    if (firstCard->id() == secondCard->id()) {
        // eşleşme
        firstCard->setMatched(true);
        secondCard->setMatched(true);
        firstCard = nullptr;
        secondCard = nullptr;
        // kontrol: oyun bitti mi?
    } else {
        /*******/
        basarisizTahminSayisi++;
        tahminLabel->setText(QString("Başarısız tahmin: %1").arg(basarisizTahminSayisi));

        // kısa süre sonra kapat
        mismatchTimer.start(900); // 900 ms sonra kapat
    }
}

void MainWindow::checkForMismatch()
{
    if (firstCard && secondCard) {
        firstCard->hideBack();
        secondCard->hideBack();
    }
    firstCard = nullptr;
    secondCard = nullptr;
}


