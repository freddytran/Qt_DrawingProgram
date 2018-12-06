#include "circle.h"
#include <QPen>
#include <QBrush>
#include <QGraphicsItem>

unsigned long Circle::m_circleCounter = 0;  ///<Initialisiert m_circleCounter auf 0.

/**
 * @brief Circle::Circle Konstruktor
 * @param parent
 */
Circle::Circle(QObject *parent) : GraphicsObject(parent)
{
    m_graphicsEllipse = new QGraphicsEllipseItem;
    m_name = QString("circle_%1").arg(m_circleCounter);
    m_circleCounter++;
}

/**
 * @brief Circle::~Circle Dekonstruktor
 */
Circle::~Circle()
{
    delete m_graphicsEllipse;
}

/**
 * @brief Circle::Circle Konstruktor, in dem ein QGraphicEllipseItem erstellt wird.
 * @param xkoord
 * @param ykoord
 * @param width
 * @param height
 * @param fill
 * @param border
 */
Circle::Circle(qreal xkoord, qreal ykoord,qreal width, qreal height, QColor fill, QColor border)
{
    m_graphicsEllipse = new QGraphicsEllipseItem;
    m_name = QString("GraphicCircle_%1").arg(m_circleCounter);
    m_graphicsEllipse->setRect(xkoord,ykoord,width,height);
    m_graphicsEllipse->setPen(border);
    m_graphicsEllipse->setBrush(fill);
    m_graphicsEllipse->setFlag(QGraphicsItem::ItemIsSelectable);
    m_graphicsEllipse->setFlag(QGraphicsItem::ItemIsMovable);
    m_circleCounter++;
    //qDebug(m_name.toUtf8());
}

/**
 * @brief Circle::graphicShapeItem
 * @return m_graphicsEllipse
 */
QAbstractGraphicsShapeItem *Circle::graphicShapeItem() const
{
    return m_graphicsEllipse;
}

/**
 * @brief Circle::toString gibt alle Daten des QGraphicObject aus.
 */
QString Circle::toString()
{
    return "Circle: " + m_name
            + " x: " + QString::number(m_graphicsEllipse->rect().x())
            + " y: " + QString::number(m_graphicsEllipse->rect().y())
            + " width: " + QString::number(m_graphicsEllipse->rect().width())
            + " height: " + QString::number(m_graphicsEllipse->rect().height())
            + " Fill Color: " + m_graphicsEllipse->brush().color().name()
            + " Border Color: " + m_graphicsEllipse->pen().color().name();
}
