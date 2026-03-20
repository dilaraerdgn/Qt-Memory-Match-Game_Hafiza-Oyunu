#include "card.h"
#include <QMouseEvent>

Card::Card(int id, const QPixmap &frontPixmap, QWidget *parent)
    : QPushButton(parent),
    m_id(id),
    m_front(frontPixmap),
    m_back(QStringLiteral(":/images/back.png")),
    m_revealed(false),
    m_matched(false)
{
    setFixedSize(100, 140);
    setIcon(m_back);
    setIconSize(size());
    setFlat(true);
    setStyleSheet("QPushButton { border: none; background: none; }");
}

int Card::id() const { return m_id; }
bool Card::isRevealed() const { return m_revealed; }
bool Card::isMatched() const { return m_matched; }
void Card::setMatched(bool matched) { m_matched = matched; }

void Card::reveal()
{

    if (!m_revealed) {
        m_revealed = true;
        setIcon(m_front); // ön yüzü göster
        setIconSize(size());
    }
}

void Card::hideBack()
{
    //if (m_matched) return;
    m_revealed = false;
    setIcon(m_back);
    setIconSize(size());
    //setEnabled(true);
}

void Card::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && !m_revealed && !m_matched) {
        emit cardClicked(this);
    }
    // QPushButton default davranışı gerekirse çağrılabilir:
    QPushButton::mousePressEvent(event);
}

