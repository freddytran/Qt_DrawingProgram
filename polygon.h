#ifndef POLYGON_H
#define POLYGON_H
#include <graphicsobject.h>
#include <QObject>
#include <QColor>
#include <QString>

/**
 * @brief The Polygon class - Klasse für das Polygon Objekt abgeleitet von Graphic Objekt.
 */
class Polygon : public GraphicsObject
{
    Q_OBJECT

public:
    /**
     * @brief Polygon - Default Konstruktor für das Polygon Objekt.
     * @param parent
     */
    Polygon(QObject *parent = nullptr);

    /**
     * @brief Polygon - Destruktor
     */
    ~Polygon();

    /**
     * @brief Polygon - Selbst erstellter Konstruktor für das Polygon Objekt
     * @param polygon
     * @param pen
     * @param brush
     */
    Polygon(QPolygon polygon, QColor pen, QColor brush);

    /**
     * @brief graphicShapeItem - Gibt das QGraphicsPoygonItem zurück.
     * @return m_graphicsPolygon
     */
    virtual QAbstractGraphicsShapeItem *graphicShapeItem() const;

    /**
     * @brief toString - Methode für das Polygon Objekt.
     * @return Eigenschaften des Polygons
     */
    virtual QString toString();

protected:
    static unsigned long m_polygonCounter;
    QGraphicsPolygonItem *m_graphicsPolygon;
};

#endif // POLYGON_H
