#include "drawingtoolselector.h"
#include "ui_drawingtoolselector.h"
#include <QDebug>

DrawingToolSelector::DrawingToolSelector(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DrawingToolSelector)
{
    ui->setupUi(this);
    m_activeDrawingTool = Tools::DrawTool::GRABBER;         ///< Default SetUp für m_activeDrawingTool
    m_activeOptionTool = Tools::OptionTool::GRUNDRISS;      ///<Default SetUp für m_activeOptionTool
}

/**
 * @brief DrawingToolSelector::~DrawingToolSelector
 */
DrawingToolSelector::~DrawingToolSelector()
{
    delete ui;
}

/**
 * @brief DrawingToolSelector::on_GrabberButton_clicked
 */
void DrawingToolSelector::on_GrabberButton_clicked()
{
    setActiveDrawingTool(Tools::DrawTool::GRABBER);
    //emit activeDrawingToolChanged(m_activeDrawingTool);
}

/**
 * @brief DrawingToolSelector::on_RectButton_clicked
 */
void DrawingToolSelector::on_RectButton_clicked()
{

    setActiveDrawingTool(Tools::DrawTool::RECTANGLE);
    //emit activeDrawingToolChanged(m_activeDrawingTool);
}

/**
 * @brief DrawingToolSelector::on_CircButton_clicked
 */
void DrawingToolSelector::on_CircButton_clicked()
{
    setActiveDrawingTool(Tools::DrawTool::CIRCLE);
    //emit activeDrawingToolChanged(m_activeDrawingTool);
}

/**
 * @brief DrawingToolSelector::on_PolygonButton_clicked - Was passiert, wenn auf den Polygon Button geklickt wird.
 */
void DrawingToolSelector::on_PolygonButton_clicked()
{
    setActiveDrawingTool(Tools::DrawTool::POLYGON);
}

/**
 * @brief DrawingToolSelector::activeDrawingTool
 * @return m_activeDrawingTool
 */
Tools::DrawTool DrawingToolSelector::activeDrawingTool() const
{
    return m_activeDrawingTool;
}

/**
 * @brief DrawingToolSelector::activeOptionTool - Getter - Methode für OptionTool
 * @return
 */
Tools::OptionTool DrawingToolSelector::activeOptionTool() const
{
    return m_activeOptionTool;
}

/**
 * @brief DrawingToolSelector::setActiveDrawingTool
 * @param activeDrawingTool
 */
void DrawingToolSelector::setActiveDrawingTool(const Tools::DrawTool activeDrawingTool)
{
    /**
     *  Hier wird unterschieden welches Zeichenwerkzeug gerade verwendet wird.
     *  Zu Beginn werden alle Buttons "unchecked" danach folgt die Fallunterscheidung
     *  Je nachdem welches Zeichenwerkzeug ausgewählt wurde wird der jeweilige Button "gecheckt"
     *  Die MemberVariable m_activeDrawingTool wird dann auf das auf das jeweilge DrawTool gesetzt.
     *  Danach wird mit emit activeDrawingToolChanged(m_activeDrawingTool) ein Signal ausgesendet.
     */
    if(m_activeDrawingTool != activeDrawingTool){
        ui->GrabberButton->setChecked(false);
        ui->RectButton->setChecked(false);
        ui->CircButton->setChecked(false);
        ui->PolygonButton->setChecked(false);

        if(activeDrawingTool == Tools::DrawTool::GRABBER){
            ui->GrabberButton->setChecked(true);
            //qDebug()<< "Grabber funktioniert.";
        }

        if(activeDrawingTool == Tools::DrawTool::RECTANGLE){
            ui->RectButton->setChecked(true);
            //qDebug()<< "Rechteck funktioniert.";
        }

        if(activeDrawingTool == Tools::DrawTool::CIRCLE){
            ui->CircButton->setChecked(true);
            //qDebug()<< "Kreis funktioniert.";
        }

        if(activeDrawingTool == Tools::DrawTool::POLYGON){
            ui->PolygonButton->setChecked(true);
            //qDebug()<< "Polygon funktioniert.";
        }

        m_activeDrawingTool = activeDrawingTool;
        emit activeDrawingToolChanged(m_activeDrawingTool); ///<Signal wird hier ausgesendet.
    }
}

/**
 * @brief DrawingToolSelector::setActiveOptionTool - Setter - Methode für das OptionTool
 * @param activeOptionTool
 */
void DrawingToolSelector::setActiveOptionTool(const Tools::OptionTool activeOptionTool)
{
    if(activeOptionTool == Tools::OptionTool::GRUNDRISS){
        ui->Grundriss->setChecked(true);
    }

    if(activeOptionTool == Tools::OptionTool::MOEBEL){
        ui->Moebel->setChecked(true);
    }

    m_activeOptionTool = activeOptionTool;
    emit activeOptionToolChanged(m_activeOptionTool);
}

/**
 * @brief DrawingToolSelector::on_Grundriss_clicked - Was passiert, wenn auf den Grundriss Button geklickt wird.
 */
void DrawingToolSelector::on_Grundriss_clicked()
{
    setActiveOptionTool(Tools::OptionTool::GRUNDRISS);
}

/**
 * @brief DrawingToolSelector::on_Moebel_clicked - Was passiert, wenn auf den Moebel Button geclickt wird.
 */
void DrawingToolSelector::on_Moebel_clicked()
{
    setActiveOptionTool(Tools::OptionTool::MOEBEL);
}
