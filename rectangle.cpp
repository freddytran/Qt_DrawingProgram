#include "rectangle.h"
#include <QColor>
#include <QGraphicsItem>
#include <QAbstractGraphicsShapeItem>
#include <QPen>
#include <QBrush>
#include <graphicsscene.h>

unsigned long Rectangle::m_rectangleCounter = 0;

/**
 * @brief Konstruktor vom Objekt Rectangle
 */
Rectangle::Rectangle(QObject *parent) : GraphicsObject(parent)
{

    m_graphicsRect = new QGraphicsRectItem;
    m_name = QString("rectangle_%1").arg(m_rectangleCounter);
    m_rectangleCounter++;
}

/**
 * @brief Dieser Konstruktor ist dafür gemacht, um ein aus den übergebenen Werten ein QGraphicRectItem zu machen
 * @param xkoord
 * @param ykoord
 * @param width
 * @param height
 * @param fill
 * @param border
 */
Rectangle::Rectangle(qreal xkoord, qreal ykoord, qreal width, qreal height, QColor fill, QColor border)
{
    m_graphicsRect = new QGraphicsRectItem;
    m_name = QString("GraphicRectangle_%1").arg(m_rectangleCounter);
    m_graphicsRect->setRect(xkoord,ykoord,width,height);
    m_graphicsRect->setPen(border);
    m_graphicsRect->setBrush(fill);
    m_graphicsRect->setFlag(QGraphicsRectItem::ItemIsMovable,true);
    m_graphicsRect->setFlag(QGraphicsRectItem::ItemIsSelectable, true);
    m_rectangleCounter++;
    //qDebug(m_name.toUtf8());
}

/**
 * @brief Destruktor vom Objekt Rectangle
 */
Rectangle::~Rectangle()
{
    delete m_graphicsRect;
}

/**
 * @brief virtuelle Methode, um das QGraphicRectItem wiederzugeben.
 * @return m_graphicsRect
 */
QAbstractGraphicsShapeItem *Rectangle::graphicShapeItem() const
{
    return m_graphicsRect;
}

/**
 * @brief Rectangle::toString - Methode, gibt alle Eigenschaften des Rechtecks aus.
 *
 */
QString Rectangle::toString()
{
    return "Rectangle: " + m_name
            + " x: " + QString::number(m_graphicsRect->rect().x())
            + " y: " + QString::number(m_graphicsRect->rect().y())
            + " width: " + QString::number(m_graphicsRect->rect().width())
            + " height: " + QString::number(m_graphicsRect->rect().height())
            + " Fill Color: " + m_graphicsRect->brush().color().name()
            + " Border Color: " + m_graphicsRect->pen().color().name();
}


