#ifndef GRAPHICSOBJECTSMAP_H
#define GRAPHICSOBJECTSMAP_H
#include <QMap>
#include <QGraphicsItem>
#include <graphicsobject.h>

/**
 * @brief The GraphicsObjectsMap class - Klasse für die GraphicsObjectsMap.
 */
class GraphicsObjectsMap: public QMap<QGraphicsItem*, GraphicsObject*>
{
public:
    /**
     * @brief GraphicsObjectsMap
     */
    GraphicsObjectsMap();

};

#endif // GRAPHICSOBJECTSMAP_H
