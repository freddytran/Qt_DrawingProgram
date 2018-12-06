#include "colorbutton.h"
#include <QPen>
#include <QPainter>
#include <QString>

/**
 * @brief ColorButton::ColorButton
 * @param parent
 */
ColorButton::ColorButton(QWidget *parent): QPushButton(parent), m_color(Qt::black)
{

}

/**
 * @brief ColorButton::ColorButton
 * @param color
 * @param parent
 */
ColorButton::ColorButton(QColor color, QWidget *parent): QPushButton(parent),
    m_color(color)
{

}

/**
 * @brief ColorButton::paintEvent
 * @param paint
 */
void ColorButton::paintEvent(QPaintEvent *paint)
{
    // Als erstes wird der standardButton gezeichnet.
    QPushButton::paintEvent(paint);

    // Jetzt wird das individuelle Rechteck auf dem Button gezeichnet
    QPainter p(this);
    p.save();

    /**
     * Rechteck mit schwarzen Rahmen wird hier erstellt und bei der Breite und Höhe wird etwas abgezogen, damit
     * das individuelle Rechteck kleiner ist als der Button
     * x und y Werte werden auf 10 gesetzt damit das individuelle Rechteck Mittig liegt.
     */
    p.setPen(Qt::black);
    p.drawRect(10, 10, width()-20, height()-20);


    /**
     *Individuelle Rechteck wird mit Farbe gefüllt und zwar mit der Farbe die vom Benutzer ausgewählt wid.
     */
    p.fillRect(11, 11, width()-21, height()-21, m_color);

    p.restore();
}

/**
 * @brief ColorButton::color
 * @return m_color
 */
QColor ColorButton::color() const
{
    return m_color;
}

/**
 * @brief ColorButton::setColor
 * @param color
 */
void ColorButton::setColor(const QColor &color)
{
    m_color = color;
    repaint();
}
