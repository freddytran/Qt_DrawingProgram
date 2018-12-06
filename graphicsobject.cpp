#include "graphicsobject.h"

unsigned long GraphicsObject::m_graphicsObjectCounter = 0; ///<GraphicsObjectCounter wird initialisiert.

/**
 * @brief GraphicsObject::GraphicsObject
 * @param parent
 */
GraphicsObject::GraphicsObject(QObject *parent) : QObject(parent)
{
    m_name = QString("graphicsObject_%1").arg(m_graphicsObjectCounter);
    m_graphicsObjectCounter++;
}

/**
 * @brief Getter - Methode für den Namen des GraphicsObject - Objekt.
 * @return m_name
 */
QString GraphicsObject::name() const
{
    return m_name;
}

/**
*@brief Setter - Methode für Name des GraphicsObject - Objekt.
*@param name
*/
void GraphicsObject::setName(const QString &name)
{
    qDebug(name.toUtf8());  ///<toUtf8 gibt die QString werte als Schrift aus.
    m_name = name;
}

/**
 * @brief GraphicsObject::graphicShapeItem.
 * @return 0
 */
QAbstractGraphicsShapeItem *GraphicsObject::graphicShapeItem() const
{
    return 0;
}

/**
 * @brief GraphicsObject::toString
 * @return m_name.
 */
QString GraphicsObject::toString()
{
    return "GraphicsObject: " + m_name;
}

