#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <graphicsobject.h>
#include <rectangle.h>
#include <tools.h>
#include <graphicsobjectsmap.h>
#include <circle.h>
#include <graphicsscene.h>
#include <colorbutton.h>
#include <drawingtoolselector.h>
#include <objectoptions.h>
#include <QPolygonF>
#include <QPolygon>
#include <qpolygon.h>
#include <polygon.h>

namespace Ui {
class MainWindow;
}

/**
 * @brief The MainWindow class - MainWindow Klasse
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    /**
     * @brief MainWindow
     * @param parent
     */
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

//    /**
//     * @brief on_ChooseTool_clicked
//     */
//    void on_ChooseTool_clicked();

//    /**
//     * @brief on_RectButton_clicked
//     */
//    void on_RectButton_clicked();

//    /**
//     * @brief on_CircButton_clicked
//     */
//    void on_CircButton_clicked();

    /**
     * @brief on_Show_clicked
     */
    void on_Show_clicked();

    /**
     * @brief on_AddObject_clicked
     */
    void on_AddObject_clicked();

//    void on_BorderColorButton_clicked();

//    void on_FillColorButton_clicked();

    /**
     * @brief onDrawToolChanged
     * @param activeDrawTool
     */
    void onDrawToolChanged(Tools::DrawTool activeDrawTool);

    /**
     * @brief on_actionOpen_triggered
     */
    void on_actionOpen_triggered();

    /**
     * @brief on_actionSave_triggered
     */
    void on_actionSave_triggered();

    /**
     * @brief on_actionPrint_triggered - Print/Show Button über die Menüleiste
     */
    void on_actionPrint_triggered();

    /**
     * @brief on_action_AddObject_triggered - AddObject Button über die Menüleiste
     */
    void on_action_AddObject_triggered();

    /**
     * @brief on_actionSelect_triggered - Grabber Button über die Menüleiste
     */
    void on_actionSelect_triggered();

    /**
     * @brief on_actionRectangle_triggered - Rechteck Button über die Menüleiste
     */
    void on_actionRectangle_triggered();

    /**
     * @brief on_actionCircle_triggered - Kreis Button über die Menüleiste
     */
    void on_actionCircle_triggered();

    /**
     * @brief on_actionPolygon_triggered - Polygon Button über die Menüleiste
     */
    void on_actionPolygon_triggered();

public slots:

    /**
     * @brief recieveMousePosition - Slot für das Empfangen der Maus Position.
     * @param mouse_position
     */
    void recieveMousePosition(QPointF mouse_position);

    /**
     * @brief recieveMouseClickedPosition - Slot für das Empfangen der Maus Position, wenn auf der Scene geklickt wird.
     * @param mouse_clicked_position
     */
    void recieveMouseClickedPosition(QPointF mouse_clicked_position);

    void recieveFocusedItem(qreal x, qreal y, qreal height, qreal width);


private:
    Ui::MainWindow *ui;
    Rectangle *rect;
    Circle *circ;
    QPolygonF *polygonT;
    Polygon *poly;
    Tools *toolObject;
    GraphicsObjectsMap *graphicsMap;
    QMap<QGraphicsItem*, GraphicsObject*>map;
    QList<QPointF>polyMap;
    QMap<QGraphicsItem*, GraphicsObject*>delList;
    GraphicsScene *scene;
};

#endif // MAINWINDOW_H
