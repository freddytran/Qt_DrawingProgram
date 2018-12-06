#include "polygon.h"
#include <QPen>
#include <QBrush>

unsigned long Polygon::m_polygonCounter = 0;

/**
 * @brief Polygon::Polygon - Default Konstrukor für das Polygon Objekt
 * @param parent
 */
Polygon::Polygon(QObject *parent) : GraphicsObject(parent)
{
    m_graphicsPolygon = new QGraphicsPolygonItem;
    m_name = QString("Polygon_%1").arg(m_polygonCounter);
    m_polygonCounter++;
}

/**
 * @brief Polygon::~Polygon - Destruktor für das Polygon Objekt
 */
Polygon::~Polygon()
{
    delete m_graphicsPolygon;
}

/**
 * @brief Polygon::Polygon - selbst erstellter Konstruktor für das Polygon Objekt.
 * @param polygon
 * @param pen
 * @param brush
 */
Polygon::Polygon(QPolygon polygon, QColor pen, QColor brush)
{
    m_graphicsPolygon = new QGraphicsPolygonItem;
    m_name = QString("Polygon_%1").arg(m_polygonCounter);
    m_graphicsPolygon->setPolygon(polygon);
    m_graphicsPolygon->setPen(pen);
    m_graphicsPolygon->setBrush(brush);
    m_graphicsPolygon->setFlag(QGraphicsItem::ItemIsMovable, true);
    m_graphicsPolygon->setFlag(QGraphicsItem::ItemIsSelectable, true);
    m_polygonCounter++;
}

/**
 * @brief Polygon::graphicShapeItem - Gibt das QGraphicsPolygonItem zurück.
 * @return
 */
QAbstractGraphicsShapeItem *Polygon::graphicShapeItem() const
{
    return m_graphicsPolygon;
}

/**
 * @brief Polygon::toString - Methode für das Polygon Objekt.
 * @return Eigenschaften des Polygons.
 */
QString Polygon::toString()
{
    return "Polygon: " + m_name
            + " Bounding Rect X: " + QString::number(m_graphicsPolygon->boundingRect().x())
            + " Bounding Rect Y: " + QString::number(m_graphicsPolygon->boundingRect().y())
            + " Bounding Rect Width: " + QString::number(m_graphicsPolygon->boundingRect().width())
            + " Bounding Rect Height: " + QString::number(m_graphicsPolygon->boundingRect().height());
}


