#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <tools.h>

/**
 * @brief The GraphicsScene class - Klasse für die GraphicsScene abgeleitet von QGraphicsScene.
 */
class GraphicsScene: public QGraphicsScene
{
    Q_OBJECT

public:
    GraphicsScene();

    /**
     * @brief mousePressEvent
     * @param mouseEvent
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);

    /**
     * @brief mouseReleaseEvent
     * @param mouseEvent
     */
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);

    /**
     * @brief mouseMoveEvent
     * @param mouseEvent
     */
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);

private slots:

    /**
     * @brief setDrawTool - Methode/Slot um das Zeichenwerkzeug zu setzen.
     * @param drawtool
     */
    void setDrawTool(const Tools::DrawTool drawtool);

    /**
     * @brief setOptionTool - Methode/Slot um das OptionTool zu setzen.
     * @param optionTool
     */
    void setOptionTool(const Tools::OptionTool optionTool);

signals:

    /**
     * @brief sendMousePosition - Signal, dass die Positionsdaten des Cursors aussendet.
     * @param mouse_position
     */
    void sendMousePosition(QPointF mouse_position);

    /**
     * @brief sendMouseClickedPosition - Signal, dass die Positionsdaten des Cursors aussenden sobald geklickt wird.
     * @param mouse_clicked_position
     */
    void sendMouseClickedPosition(QPointF mouse_clicked_position);


protected:
    Tools::DrawTool m_activeTool;
    Tools::OptionTool m_activeOptionTool;
};

#endif // GRAPHICSSCENE_H
