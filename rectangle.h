#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QObject>
#include <graphicsobject.h>

/**
 * @brief The Rectangle class - Klasse für das Rechteck Objekt abgeleitet von Graphic Objekt.
 */
class Rectangle : public GraphicsObject
{
    Q_OBJECT
public:
    /**
     * @brief Rectangle Kontruktor wid so geändert dass ein QObject *parent - Parameter erwartet wird.
     * @param parent
     */
    Rectangle(QObject *parent = nullptr);

    /**
     * @brief Rectangle Konstruktor
     * @param position
     * @param dimension
     * @param fill
     * @param border
     */
    Rectangle(qreal xkoord, qreal ykoord, qreal width, qreal height, QColor fill, QColor border);

    /**
     * @brief Rectangle Destruktor
     *
     */
    ~Rectangle();

    /**
     * @brief graphicShapeItem
     * @return
     */
    virtual QAbstractGraphicsShapeItem *graphicShapeItem() const;

    /**
     * @brief toString
     * @return
     */
    virtual QString toString();

signals:

public slots:

protected:
    static unsigned long m_rectangleCounter;
    QGraphicsRectItem *m_graphicsRect;
};

#endif // RECTANGLE_H
