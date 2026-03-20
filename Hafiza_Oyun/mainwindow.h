#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QTimer>
#include <QLabel>
class Card;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onCardClicked(Card *card);
    void checkForMismatch();



private:
    Ui::MainWindow *ui;
    QVector<Card*> cards;
    Card *firstCard;
    Card *secondCard;
    QTimer mismatchTimer;
    void setupBoard();
    void shuffleCards();
    int basarisizTahminSayisi = 0;/*****/
    QLabel *tahminLabel;/*****/
};

#endif // MAINWINDOW_H
