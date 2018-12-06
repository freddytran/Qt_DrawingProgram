#include "graphicsscene.h"
#include <QMouseEvent>
#include <QDebug>
#include <QGraphicsItem>

/**
 * @brief GraphicsScene::GraphicsScene. Scene in der die Rechteck & Kreis - Objekte erstellt werden.
 */
GraphicsScene::GraphicsScene()
{

}

/**
 * @brief GraphicsScene::mousePressEvent
 * @param mouseEvent
 */
void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    /**
     * button() gibt den Button zurück der das Event ausgelöst hat.
     * Diese if - Anweisung wird aufgerufen wenn die linke Maustaste gedrückt wird
     */
    if(mouseEvent->button() == Qt::LeftButton){

        qDebug()<<"Left Mouse Button Pressed." << endl;

    }

    /**
     * Fall, sobald das Polygon ausgwählt wurde und auf der Scene mit der Maus geklickt wird.
     */
    if((mouseEvent->button() == Qt::LeftButton) && (m_activeTool == Tools::DrawTool::POLYGON)){
        qDebug()<<"SOLLTE NUR HIER SEIN WENN POLYGON GEWÄHLT IST"<< endl;
        emit sendMouseClickedPosition(mouseEvent->scenePos());
    }

    if(m_activeTool == Tools::DrawTool::GRABBER){
        QGraphicsScene::mousePressEvent(mouseEvent);
    }
}

/**
 * @brief GraphicsScene::mouseReleaseEvent
 * @param mouseEvent
 */
void GraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    /**
     * button() gibt den Button zurück der das Event ausgelöst hat.
     * Wenn dieser Button der Linke MausButton war dann wird der qDebug ausgegeben.
     */
    if(mouseEvent->button() == Qt::LeftButton){

        qDebug()<<"Left Mouse Button Release." << endl;
    }

    QGraphicsScene::mouseReleaseEvent(mouseEvent);

}

/**
 * @brief GraphicsScene::mouseMoveEvent - Methode die ausgeführt wird wenn sich die Maus innerhalb der GraphicsScene bewegt.
 * @param mouseEvent
 */
void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    emit sendMousePosition(mouseEvent->scenePos());     ///<Sendet Signal aus mit den Positionsdaten des Cursors
    QGraphicsScene::mouseMoveEvent(mouseEvent);
}

/**
 * @brief GraphicsScene::setDrawTool - Setter Methode für das Zeichenwerkzeug
 * @param drawtool
 */
void GraphicsScene::setDrawTool(const Tools::DrawTool drawtool)
{
    m_activeTool = drawtool;
}

void GraphicsScene::setOptionTool(const Tools::OptionTool optionTool)
{
    m_activeOptionTool = optionTool;
}
