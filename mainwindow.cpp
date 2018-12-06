#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rectangle.h"
#include <QDebug>
#include <circle.h>
#include <iostream>
#include <QMap>
#include <QColorDialog>
#include <colorbutton.h>
#include <drawingtoolselector.h>
#include <QMouseEvent>
#include <QLabel>
#include <QStyle>
using namespace std;

/**
 * @brief MainWindow::MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);      ///<User Interface wird aufgerufen

    toolObject = new Tools;                 ///<Tools - Objekt wird erstellt und Default - Werte werden gesetzt.
    toolObject->setBorderColor(Qt::black);
    toolObject->setFillColor(Qt::black);
    toolObject->setDrawTool(Tools::GRABBER);
    toolObject->setOptionTool(Tools::OptionTool::GRUNDRISS);

    ui->actionOpen->setIcon(this->style()->standardIcon(QStyle::SP_DirOpenIcon));       ///<Setzt Systemtypisches Icon für Menüpunkt "Open"
    ui->actionSave->setIcon(this->style()->standardIcon(QStyle::SP_DialogSaveButton));  ///<Setzt Systemtypisches Icon für Menüpunkt "Save"

    ui->actionOpen->setShortcut(QKeySequence::Open);    ///<Setzt Systemtypische Shortcut für den Menüpunkt "Open"
    ui->actionSave->setShortcut(QKeySequence::Save);    ///<Setzt Systemtypische Shortcut für den Menüpunkt "Save"
    ui->actionPrint->setShortcut(QKeySequence::Print);  ///<Setzt Systemtypische Shortcut für den Menüpunkt "Print"

    /**
     * Damit das hier funktioniert, muss erst ein Label dem CentralWidget hinzugefügt werden. (im GUI - Creator)
     */
    ui->statusBar->addPermanentWidget(ui->label_cursor);    ///<Das Label wird hiermit der Statusbar beigefügt.

//    ui->BorderColorButton->setColor(Qt::red);
//    ui->FillColorButton->setColor(Qt::red);

    scene = new GraphicsScene;  ///<GraphicScene - Objekt wird erstellt

    ui->graphicsView->setScene(scene);              ///<Das GraphicScene - Objekt wird dem graphicsView - Widget übergeben
    ui->graphicsView->setSceneRect(0,0,500,300);  ///<Größe der GraphicScene wird gesetzt.
    ui->AddObject->setEnabled(false);           ///<Graut AddObject - Button aus.
//  ui->PositionDimension->setVisible(false);   ///<Macht PositionDimension unsichtbar
    ui->objectOptions->setVisible(false);           ///<Macht Positionen / Dimensionen Feld unsichtbar (Default)
    ui->action_AddObject->setEnabled(false);        ///<Graut Menüpunkt AddObject aus

    /**
     * @brief connect Verbindung zwischen dem toolObject aus MainWindow und dem eigenem Widget für Zeichenwerkzeuge
     *          Richtung: toolObject zu eigenem Widget.
     */
    connect(toolObject, SIGNAL(activeDrawToolChanged(Tools::DrawTool)),
            ui->drawingToolSelector, SLOT(setActiveDrawingTool(Tools::DrawTool)));

    /**
     * @brief connect Verbindung zwischen dem eigenem Widget für Zeichenwerkzeuge und dem toolObject aus MainWindow
     *          Richtung: eigenes Widget zu toolObject
     */
    connect(ui->drawingToolSelector, SIGNAL(activeDrawingToolChanged(Tools::DrawTool)),
            toolObject, SLOT(setDrawTool(Tools::DrawTool)));

    /**
     * @brief connect Verbindung zwischen toolObject und dem eigenem Widget zur Farbauswahl für die Rahmenfarbe
     *          Richtung: toolObject zu eigenem Widget
     */
    connect(toolObject, SIGNAL(activeBorderColorChanged(QColor)),
            ui->colorSelector, SLOT(setActiveBorderColor(QColor)));

    /**
     * @brief connect Verbindung zwischen eigenem Widget zur Farbauswahl für die Rahmenfarbe und dem toolObject
     *          Richtung: eigenes Widget zu toolObject
     */
    connect(ui->colorSelector, SIGNAL(activeBorderColorChanged(QColor)),
            toolObject, SLOT(setBorderColor(QColor)));

    /**
     * @brief connect Verbindung zwischen dem toolObject und dem eigenem Widget zur Farbauswahl für die Füllfarbe
     *          Richtung: toolObject zu eigenem Widget
     */
    connect(toolObject, SIGNAL(activeFillColorChanged(QColor)),
            ui->colorSelector, SLOT(setActiveFillColor(QColor)));

    /**
     * @brief connect Verbindung zwischen dem eigenem Widget für die Füllfarbe zu dem toolObject
     *          Richtung: eigenes Widget zu toolObject.
     */
    connect(ui->colorSelector, SIGNAL(activeFillColorChanged(QColor)),
            toolObject, SLOT(setFillColor(QColor)));

    /**
     * @brief connect Verbindung zwischen dem eigenem Widget und dem MainWindow.
     *          Richtung: eigenes Widget zu MainWindow.
     */
    connect(ui->drawingToolSelector, SIGNAL(activeDrawingToolChanged(Tools::DrawTool)),
            SLOT(onDrawToolChanged(Tools::DrawTool)));

    /**
     * @brief connect Verbindung zwischen der Scene und dem MainWindow (CursorKoordinaten werden an Statusbar gesendet)
     *          Richtung: Scene zu MainWindow
     */
    connect(scene, SIGNAL(sendMousePosition(QPointF)), this, SLOT(recieveMousePosition(QPointF)));

    /**
     * @brief connect Verbindung zwischen dem DrawingToolSelector und der Graphicsscene.
     *          Richtung: DrawingToolSelector zu Scene
     */
    connect(ui->drawingToolSelector, SIGNAL(activeDrawingToolChanged(Tools::DrawTool)),
            scene, SLOT(setDrawTool(Tools::DrawTool)));

    /**
     * @brief connect Verbindung zwischen der Scene und dem MainWindow für die Mausposition wenn mit der Maus auf die Scene geklickt wird.
     *          Richtung: Scene zu MainWindow (funktioniert nur, wenn PolygonTool ausgewählt wurde.)
     */
    connect(scene, SIGNAL(sendMouseClickedPosition(QPointF)), this, SLOT(recieveMouseClickedPosition(QPointF)));

    /**
     * @brief connect Verbindung zwischen dem DrawinToolSelector und dem ToolObject für die Wahl zwischen Grundriss und Moebel.
     *          Richtung: DrawingtoolSelector zu toolObject
     */
    connect(ui->drawingToolSelector, SIGNAL(activeOptionToolChanged(Tools::OptionTool)),
            toolObject, SLOT(setOptionTool(Tools::OptionTool)));

}

/**
 * @brief MainWindow::~MainWindow ist der Dekonstruktor
 */
MainWindow::~MainWindow()
{
    delete ui;
}

///**
// * @brief MainWindow::on_ChooseTool_clicked. Event - Handling wenn ChooseTool Button gedrückt ist.
// */
//void MainWindow::on_ChooseTool_clicked()
//{
//    toolObject->setState(Tools::GRABBER_ACTIVE);
//    toolObject->setDrawTool(Tools::GRABBER);
//    //qDebug("Status: %d", toolObject->getState());
//    //qDebug("Objekt: %d", toolObject->getDrawTool());
//    ui->AddObject->setEnabled(false);
//    ui->PositionDimension->setVisible(false);
//}

///**
// * @brief MainWindow::on_RectButton_clicked. Event - Handling wenn Rectangle Button gedrückt ist.
// * Einstellungen, wenn der Rectangle Button gedrückt ist
// */
//void MainWindow::on_RectButton_clicked()
//{
//    toolObject->setState(Tools::RECT_ACTIVE);
//    toolObject->setDrawTool(Tools::RECTANGLE);
//    //qDebug("Status: %d", toolObject->getState());
//    //qDebug("Objekt: %d", toolObject->getDrawTool());
//    ui->AddObject->setEnabled(true);
//    ui->PositionDimension->setVisible(true);
//}

///**
// * @brief MainWindow::on_CircButton_clicked. Event - Handling wenn Circle Button gedrückt ist.
// * Einstellungen, wenn der Rectangle Button gedrückt ist
// */
//void MainWindow::on_CircButton_clicked()
//{
//    toolObject->setState(Tools::CIRC_ACTIVE);
//    toolObject->setDrawTool(Tools::CIRCLE);
//    //qDebug("Status: %d", toolObject->getState());
//    //qDebug("Objekt: %d", toolObject->getDrawTool());
//    ui->AddObject->setEnabled(true);
//    ui->PositionDimension->setVisible(true);
//}

/**
 * @brief MainWindow::on_AddObject_clicked. Event - Handling wenn AddObject - Button gedrückt ist.
 * Hier wird reingeschrieben, was passiert wenn der AddObject Button gedrückt wurde
 */
void MainWindow::on_AddObject_clicked()
{   
    if(toolObject->getDrawTool() == Tools::DrawTool::RECTANGLE){ ///<Der Zweig der verwendet wird, wenn Rectangle ausgewählt ist.

//        rect = new Rectangle(ui->SpinXPos->value(), ui->SpinYPos->value(), ui->SpinWidth->value(), ui->SpinHeight->value(),
//                             toolObject->getFillColor(), toolObject->getBorderColor()); ///<Mit dieser Anweisung wird QGraphicRectItem erstellt. Wie genau das passiert steht im Konstruktor

        rect = new Rectangle(ui->objectOptions->xkoord(), ui->objectOptions->ykoord(), ui->objectOptions->width(),
                             ui->objectOptions->height(), toolObject->getFillColor(), toolObject->getBorderColor());


        if(toolObject->getOptionTool() == Tools::OptionTool::GRUNDRISS){    ///< Wenn Grundriss gewählt wurde, wird Z Value gesetzt.

            rect->graphicShapeItem()->setZValue(-5);                        ///< Z-Value wird gesetzt.
            //qDebug()<<"Z Value wurde gesetzt" << rect->graphicShapeItem()->zValue() << endl;
        }

        map.insert(rect->graphicShapeItem(), rect); ///<Das QGraphicRectItem wird in die Liste hinzugefügt
        scene->addItem(rect->graphicShapeItem());   ///<Das QGraphicRectItem wird an die QGraphicScene übergeben
        qDebug() << map.keys() << " : " << map.values() << endl;    ///<Key Value Paar wird ausgegeben.
    }

    if(toolObject->getDrawTool() == Tools::DrawTool::CIRCLE){ ///<Der Zweig der verwendet wird, wenn Circle ausgewählt ist.
//        circ = new Circle(ui->SpinXPos->value(), ui->SpinYPos->value(), ui->SpinWidth->value(), ui->SpinHeight->value(),
//                          toolObject->getFillColor(), toolObject->getBorderColor());    ///<Mit dieser Anweisung wird QGraphicEllipseItem erstellt. Wie genau das passiert steht im Konstruktor

        circ = new Circle(ui->objectOptions->xkoord(), ui->objectOptions->ykoord(), ui->objectOptions->width(),
                          ui->objectOptions->height(),toolObject->getFillColor(), toolObject->getBorderColor());

        if(toolObject->getOptionTool() == Tools::OptionTool::GRUNDRISS){    ///< Wenn Grundriss gewählt wurde, wird Z Value gesetzt.

            circ->graphicShapeItem()->setZValue(-5);                        ///< Z-Value wird gesetzt.
            //qDebug()<<"Z Value wurde gesetzt" << circ->graphicShapeItem()->zValue() << endl;
        }

        map.insert(circ->graphicShapeItem(), circ);     ///<Das QGraphicEllipseItem wird in die Liste hinzugefügt
        scene->addItem(circ->graphicShapeItem());       ///<Das QGraphicEllipseItem wird an die QGraphicScene übergeben
        qDebug() << map.keys() << " : " << map.values() << endl;    ///<Key Value Paar wird ausgegeben.
    }

    if(toolObject->getDrawTool() == Tools::DrawTool::POLYGON){
        QPolygon polygonT;

        int index = 0;
        while(index < polyMap.size()){

            qDebug()<< polyMap.value(index).x() << endl;
            polygonT.putPoints(index, 1, polyMap.value(index).x(),polyMap.value(index).y());
            index++;
        }
        poly = new Polygon(polygonT, toolObject->getBorderColor(), toolObject->getFillColor());

        if(toolObject->getOptionTool() == Tools::OptionTool::GRUNDRISS){    ///< Wenn Grundriss gewählt wurde, wird Z Value gesetzt.

            poly->graphicShapeItem()->setZValue(-5);                        ///< Z-Value wird gesetzt.
            //qDebug()<<"Z Value wurde gesetzt" << poly->graphicShapeItem()->zValue() << endl;
        }

        map.insert(poly->graphicShapeItem(), poly);
        scene->addItem(poly->graphicShapeItem());

        //Schleife, um die "Hilfskreise", die für das Polygon verwendet wurde, wieder zu löschen.
        QMap<QGraphicsItem*, GraphicsObject*>::Iterator k;
        for(k = delList.begin(); k != delList.end(); k++){
            scene->removeItem(k.key());                         ///<Löscht die "Hilfskreise" von der Scene
        }

        delList.clear();                                        ///<Löscht die "Hilfskreise" aus der Liste
        polyMap.clear();                                        ///<Löscht die Koordinaten der "Hilfskreise" aus der Liste
    }
}

/**
 * @brief MainWindow::onDrawToolChanged - Der Slot der die Fallunterscheidung unternimmt, wann die Position / Dimension
 *                                        angezeigt wird und auch ob AddObject anklickbar ist.
 * @param activeDrawTool
 */
void MainWindow::onDrawToolChanged(Tools::DrawTool activeDrawTool)
{
    if(activeDrawTool == Tools::DrawTool::GRABBER){
        ui->AddObject->setEnabled(false);               ///<AddObject Button wird nicht mehr klickbar.
        ui->objectOptions->setVisible(false);           ///<Position und Dimensionen - Feld wird angezeigt.
        ui->action_AddObject->setEnabled(false);        ///<Menüoptionen an Buttons anpassen
        ui->actionSelect->setChecked(true);
        ui->actionRectangle->setChecked(false);
        ui->actionCircle->setChecked(false);
        ui->actionPolygon->setChecked(false);
        qDebug()<<"Grabber"<<endl;

    }

    if(activeDrawTool == Tools::DrawTool::RECTANGLE){
        ui->AddObject->setEnabled(true);                ///<AddObject Button wird hier klickbar gemacht.
        ui->objectOptions->setVisible(true);            ///<Position und Dimensionen - Feld wird angezeigt.
        ui->action_AddObject->setEnabled(true);         ///<Menüoptionen an Buttons anpassen
        ui->actionRectangle->setChecked(true);
        ui->actionSelect->setChecked(false);
        ui->actionCircle->setChecked(false);
        ui->actionPolygon->setChecked(false);
    }

    if(activeDrawTool == Tools::DrawTool::CIRCLE){
        ui->AddObject->setEnabled(true);                ///<AddObject Button wird hier klickbar gemacht.
        ui->objectOptions->setVisible(true);            ///<Position und Dimensionen - Feld wird angezeigt.
        ui->action_AddObject->setEnabled(true);         ///<Menüoptionen an Buttons anpassen
        ui->actionCircle->setChecked(true);
        ui->actionSelect->setChecked(false);
        ui->actionRectangle->setChecked(false);
        ui->actionPolygon->setChecked(false);
    }

    if(activeDrawTool == Tools::DrawTool::POLYGON){
        ui->AddObject->setEnabled(true);
        ui->objectOptions->setVisible(false);
        ui->action_AddObject->setEnabled(true);
        ui->actionCircle->setChecked(false);
        ui->actionRectangle->setChecked(false);
        ui->actionSelect->setChecked(false);
        ui->actionPolygon->setChecked(true);
    }
}

/**
 * @brief MainWindow::on_Show_clicked
 * Hier wird der Iterator der QMap Liste aufgerufen und mit seiner Hilfe werden alle
 * Objekte in der Liste ausgegeben. Um es leserlicher zu machen wird die toString - Methode verwendet.
 */
void MainWindow::on_Show_clicked()
{
    QMap<QGraphicsItem*, GraphicsObject*>::iterator i;
    for(i = map.begin(); i != map.end(); i++){
        qDebug() << i.key() << " : " << i.value()->toString();
    }

   /*QMapIterator<QGraphicsItem*, GraphicsObject*> Iter(map);
    while(Iter.hasNext()){
        Iter.next();
        qDebug() << Iter.key() << ": " << Iter.value()->toString();
    }*/

    /*foreach(QGraphicsItem *i, map.keys()){
        qDebug() << map[i]->toString();
    }*/
}

//void MainWindow::on_BorderColorButton_clicked()
//{
//    QColor newBorderColor = QColorDialog::getColor(ui->BorderColorButton->color(), this, "Select Color", QColorDialog::ShowAlphaChannel);
//    if(newBorderColor.isValid()) {
//        ui->BorderColorButton->setColor(newBorderColor);
//        toolObject->setBorderColor(newBorderColor);
//        qDebug()<<"Die ausgewählte Farbe ist: " << ui->BorderColorButton->color().name();
//    }
//    else {
//        qDebug("Farbauswahl für Rahmenfarbe wurde abgebrochen.");
//    }
//}

//void MainWindow::on_FillColorButton_clicked()
//{
//    QColor newFillColor = QColorDialog::getColor(ui->FillColorButton->color(), this, "Select Color", QColorDialog::ShowAlphaChannel);
//    if(newFillColor.isValid()) {
//        ui->FillColorButton->setColor(newFillColor);
//        toolObject->setFillColor(newFillColor);
//        qDebug() <<"Die ausgewählte Farbe ist: " << ui->FillColorButton->color().name();
//    }
//    else {
//        qDebug("Farbauswahl für Füllfarbe wurde abgebrochen.");
//    }
//}

/**
 * @brief MainWindow::on_actionOpen_triggered
 * Menüoption "Open" gibt hier nur ein Debug aus.
 */
void MainWindow::on_actionOpen_triggered()
{
    qDebug()<<"Open wurde ausgewählt."<< endl;
}

/**
 * @brief MainWindow::on_actionSave_triggered
 * Menüoption "Save" gibt hier nur ein Debug aus.
 */
void MainWindow::on_actionSave_triggered()
{
    qDebug()<<"Save wurde ausgewählt."<< endl;
}

/**
 * @brief MainWindow::on_actionPrint_triggered
 * Menüoption "Print" macht hier genau das gleiche wie der Show - Button.
 */
void MainWindow::on_actionPrint_triggered()
{
    QMap<QGraphicsItem*, GraphicsObject*>::iterator i;
    for(i = map.begin(); i != map.end(); i++){
        qDebug() << i.key() << " : " << i.value()->toString();
    }
}

/**
 * @brief MainWindow::on_action_AddObject_triggered
 * Menüpunkt AddObject macht hier genau das gleiche wie der AddObject Button.
 */
void MainWindow::on_action_AddObject_triggered()
{
    if(toolObject->getDrawTool() == Tools::DrawTool::RECTANGLE){ ///<Der Zweig der verwendet wird, wenn Rectangle ausgewählt ist.

//        rect = new Rectangle(ui->SpinXPos->value(), ui->SpinYPos->value(), ui->SpinWidth->value(), ui->SpinHeight->value(),
//                             toolObject->getFillColor(), toolObject->getBorderColor()); ///<Mit dieser Anweisung wird QGraphicRectItem erstellt. Wie genau das passiert steht im Konstruktor

        rect = new Rectangle(ui->objectOptions->xkoord(), ui->objectOptions->ykoord(), ui->objectOptions->height(),
                             ui->objectOptions->width(), toolObject->getFillColor(), toolObject->getBorderColor());

        if(toolObject->getOptionTool() == Tools::OptionTool::GRUNDRISS){    ///< Wenn Grundriss gewählt wurde, wird Z Value gesetzt.

            rect->graphicShapeItem()->setZValue(-5);                        ///< Z-Value wird gesetzt.
            //qDebug()<<"Z Value wurde gesetzt" << rect->graphicShapeItem()->zValue() << endl;
        }

        map.insert(rect->graphicShapeItem(), rect);                 ///<Das QGraphicRectItem wird in die Liste hinzugefügt
        scene->addItem(rect->graphicShapeItem());                   ///<Das QGraphicRectItem wird an die QGraphicScene übergeben
        qDebug() << map.keys() << " : " << map.values() << endl;    ///<Key Value Paar wird ausgegeben.
    }

    if(toolObject->getDrawTool() == Tools::DrawTool::CIRCLE){ ///<Der Zweig der verwendet wird, wenn Circle ausgewählt ist.
//        circ = new Circle(ui->SpinXPos->value(), ui->SpinYPos->value(), ui->SpinWidth->value(), ui->SpinHeight->value(),
//                          toolObject->getFillColor(), toolObject->getBorderColor());    ///<Mit dieser Anweisung wird QGraphicEllipseItem erstellt. Wie genau das passiert steht im Konstruktor

        circ = new Circle(ui->objectOptions->xkoord(), ui->objectOptions->ykoord(), ui->objectOptions->height(),
                          ui->objectOptions->width(),toolObject->getFillColor(), toolObject->getBorderColor());

        if(toolObject->getOptionTool() == Tools::OptionTool::GRUNDRISS){    ///< Wenn Grundriss gewählt wurde, wird Z Value gesetzt.

            circ->graphicShapeItem()->setZValue(-5);                        ///< Z-Value wird gesetzt.
            //qDebug()<<"Z Value wurde gesetzt" << circ->graphicShapeItem()->zValue() << endl;
        }

        map.insert(circ->graphicShapeItem(), circ);                 ///<Das QGraphicEllipseItem wird in die Liste hinzugefügt
        scene->addItem(circ->graphicShapeItem());                   ///<Das QGraphicEllipseItem wird an die QGraphicScene übergeben
        qDebug() << map.keys() << " : " << map.values() << endl;    ///<Key Value Paar wird ausgegeben.
    }

    if(toolObject->getDrawTool() == Tools::DrawTool::POLYGON){
        QPolygon polygonT;

        /**
         * @brief Schleife die verwendet wird um mit den Koordinaten der "Hilfspunkte" das Polygon zu zeichnen.
         */
        int index = 0;
        while(index < polyMap.size()){

            //qDebug()<< polyMap.value(index).x() << endl;
            polygonT.putPoints(index, 1, polyMap.value(index).x(),polyMap.value(index).y());        ///<Polygon wird Punkt für Punkt erstellt.
            index++;
        }
        poly = new Polygon(polygonT, toolObject->getBorderColor(), toolObject->getFillColor());

        //Fall: Wenn Grundriss ausgewählt ist.
        if(toolObject->getOptionTool() == Tools::OptionTool::GRUNDRISS){    ///< Wenn Grundriss gewählt wurde, wird Z Value gesetzt.

            poly->graphicShapeItem()->setZValue(-5);                        ///< Z-Value wird gesetzt.
            //qDebug()<<"Z Value wurde gesetzt" << poly->graphicShapeItem()->zValue() << endl;
        }

        map.insert(poly->graphicShapeItem(), poly);
        scene->addItem(poly->graphicShapeItem());

        //Schleife die alle benutzten "Hilfskreise", welche zur Zeichnung des Polygons verwendet wurde, wieder löscht.
        QMap<QGraphicsItem*, GraphicsObject*>::Iterator k;
        for(k = delList.begin(); k != delList.end(); k++){
            scene->removeItem(k.key());                         ///<Löscht alle "Hilfskreise" aus der Scene
        }
        delList.clear();                                        ///<Leert die Liste, in der die "Hilfskreise" gespeichert sind.
        polyMap.clear();                                        ///<Leert die Liste, in der die Koordinaten der "Hilfskreise" gespeichert sind.
    }
}

/**
 * @brief MainWindow::on_actionSelect_triggered
 * Was passiert wenn, Menüpunkt Auswahlwerkzeug: Selecter aka GRABBER gewählt wurde.
 */
void MainWindow::on_actionSelect_triggered()
{
    toolObject->activeDrawToolChanged(Tools::DrawTool::GRABBER);
    ui->actionSelect->setChecked(true);                             ///<Setzt den Menüpunkt für Select auf checked
    ui->actionRectangle->setChecked(false);                         ///<Setzt den Menüpunkt für Rectangle auf unchecked
    ui->actionCircle->setChecked(false);                            ///<Setzt den Menüpunkt für Circle auf unchecked
    ui->actionPolygon->setChecked(false);
}

/**
 * @brief MainWindow::on_actionRectangle_triggered
 * Was passiert wenn, Menüpunkt Auswahlwerkzeug: Rectangle ausgewählt wurde.
 */
void MainWindow::on_actionRectangle_triggered()
{
    toolObject->activeDrawToolChanged(Tools::DrawTool::RECTANGLE);
    ui->actionRectangle->setChecked(true);                              ///<Setzt den Menüpunt Rectangle auf checked
    ui->actionSelect->setChecked(false);                                ///<Setzt den Menüpunkt Select auf unchecked
    ui->actionCircle->setChecked(false);                                ///<Setzt den Menüpunkt Circle auf unchecked
    ui->actionPolygon->setChecked(false);
}

/**
 * @brief MainWindow::on_actionCircle_triggered
 * Was passiert wenn, Menüpunkt Auswahlwerkzeug: Circle ausgewählt wurde.
 */
void MainWindow::on_actionCircle_triggered()
{
    toolObject->activeDrawToolChanged(Tools::DrawTool::CIRCLE);
    ui->actionCircle->setChecked(true);                             ///<Setzt den Menüpunkt Circle auf checked
    ui->actionSelect->setChecked(false);                            ///<Setzt den Menüpunkt Select auf unchecked
    ui->actionRectangle->setChecked(false);                         ///<Setzt den Menüpunkt Rectangle auf unchecked
    ui->actionPolygon->setChecked(false);
}

/**
 * @brief MainWindow::on_actionPolygon_triggered
 * Was passiert wenn, Menüpunkt Auswahlwerkzeug: Polygon ausgewählt wurde.
 */
void MainWindow::on_actionPolygon_triggered()
{
    toolObject->activeDrawToolChanged(Tools::DrawTool::POLYGON);
    ui->actionCircle->setChecked(false);                            ///<Setzt den Menüpunkt Circle auf unchecked
    ui->actionSelect->setChecked(false);                            ///<Setzt den Menüpunkt Select auf unchecked
    ui->actionRectangle->setChecked(false);                         ///<Setzt den Menüpunkt Rectangle auf unchecked
    ui->actionPolygon->setChecked(true);
}

/**
 * @brief MainWindow::recieveMousePosition
 * @param mouse_position
 * Der Slot der vom dem Signal(sendMousePosition) aus Graphicsscene die Mouse Position empfängt.
 * Dem Label auf der Statusbar werden dann die Maus Positionen beigefügt.
 */
void MainWindow::recieveMousePosition(QPointF mouse_position)
{

    ui->label_cursor->setText("Cursor at (x,y): (" +                            ///<Setzt den Text des Labels
                              QString::number(mouse_position.x()) + "," +       ///<Fügt xKoordinate hinzu
                              QString::number(mouse_position.y()) + ")");       ///<Fügt yKoordinate hinzu
}

/**
 * @brief MainWindow::recieveMouseClickedPosition - Methode, um die gewünschten Eckpunkte des Polygons auf die Scene zu malen
 *                                                  und die Punkte in die PolygonListe hinzuzufügen. Diese wird später zum Verbinden der Punkte benötigt.
 * @param mouse_clicked_position
 */
void MainWindow::recieveMouseClickedPosition(QPointF mouse_clicked_position)
{
    circ = new Circle(mouse_clicked_position.x(),mouse_clicked_position.y(), 5,     ///<Setzt einen Punkt an der gewünschten Position
                      5,Qt::black, Qt::black);
    polyMap.append(mouse_clicked_position);                                         ///<Fügt die Koordinaten der "Hilfskreise" in die Liste ein.
    delList.insert(circ->graphicShapeItem(),circ);                                  ///<Fügt die "Hilfskreise" in die dafür vorhandene Liste.
    scene->addItem(circ->graphicShapeItem());                                       ///<Malt den Punkt auf die Scene

}


