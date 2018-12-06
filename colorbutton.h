#ifndef COLORBUTTON_H
#define COLORBUTTON_H
#include <QPushButton>

/**
 * @brief The ColorButton class - Klasse für die Farb Buttons abgeleitet von QPushButton
 */
class ColorButton: public QPushButton
{
public:
    explicit ColorButton(QWidget *parent = 0);
    explicit ColorButton(QColor color, QWidget *parent = 0);

    /**
     * @brief paintEvent
     */
    void paintEvent(QPaintEvent *);

    /**
     * @brief Getter - Methode für m_color
     * @return
     */
    QColor color() const;

    /**
     * @brief Setter - Methode für m_color
     * @param color
     */
    void setColor(const QColor &color);

protected:
    QColor m_color;
};

#endif // COLORBUTTON_H
