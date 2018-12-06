#ifndef GRAPHICOBJECTS_H
#define GRAPHICOBJECTS_H

#include <QObject>
#include <QString>
#include <QAbstractGraphicsShapeItem>

/**
 * @brief The GraphicsObject class - Klass für das Grafik Objekt abgeleitet von QObject.
 */
class GraphicsObject : public QObject
{
    Q_OBJECT
public:
    explicit GraphicsObject(QObject *parent = nullptr);

    /**
     * @brief Getter - Methode für name
     *
     */
    QString name() const;

    /**
     * @brief setName - Methode
     * @param name
     */
    void setName(const QString &name);

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
    QString m_name;
    static unsigned long m_graphicsObjectCounter;
};

#endif // GRAPHICOBJECTS_H
