#ifndef CARD_H
#define CARD_H

#include <QPushButton>
#include <QPixmap>

class Card : public QPushButton
{
    Q_OBJECT
public:
    explicit Card(int id, const QPixmap &frontPixmap, QWidget *parent = nullptr);

    int id() const;
    bool isRevealed() const;
    bool isMatched() const;
    void setMatched(bool matched);

    void reveal();   // göster (ön yüz)
    void hideBack(); // kapat (arka yüz göster)
signals:
    void cardClicked(Card *card);

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    int m_id;
    QPixmap m_front;
    QPixmap m_back;
    bool m_revealed;
    bool m_matched;
};

#endif // CARD_H
