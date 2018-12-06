#ifndef CIRCLE_H
#define CIRCLE_H

#include <QObject>
#include <graphicsobject.h>
#include <QGraphicsItem>

/**
 * @brief The Circle class - Kreis Klasse
 */
class Circle : public GraphicsObject
{
    Q_OBJECT
public:
    /**
     * @brief Circle Kontruktor wid so geändert dass ein QObject *parent - Parameter erwartet wird.
     * @param parent
     */
    Circle(QObject *parent = nullptr);
    ~Circle();

    /**
     * @brief Circle
     * @param xkoord
     * @param ykoord
     * @param width
     * @param height
     * @param fill
     * @param border
     */
    Circle(qreal xkoord, qreal ykoord, qreal width, qreal height, QColor fill, QColor border);

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
    static unsigned long m_circleCounter;
    QGraphicsEllipseItem *m_graphicsEllipse;
};

#endif // CIRCLE_H
