#ifndef DRAWINGTOOLSELECTOR_H
#define DRAWINGTOOLSELECTOR_H

#include <QWidget>
#include <tools.h>

namespace Ui {
class DrawingToolSelector;
}
/**
 * @brief The DrawingToolSelector class - Eigenes zusammengestelltes Widget für die Auswahl an Zeichenoptionen.
 */
class DrawingToolSelector : public QWidget
{
    Q_OBJECT

public:
    explicit DrawingToolSelector(QWidget *parent = 0);
    ~DrawingToolSelector();

private slots:
    /**
     * @brief on_GrabberButton_clicked - Was passiert, wenn auf den GrabberButton geklickt wird.
     */
    void on_GrabberButton_clicked();

    /**
     * @brief on_RectButton_clicked - Was passiert, wenn auf den RectButton geklickt wird.
     */
    void on_RectButton_clicked();

    /**
     * @brief on_CircButton_clicked - Was passiert, wenn auf den CircButton geklickt wird.
     */
    void on_CircButton_clicked();

    /**
     * @brief on_Grundriss_clicked - Was passiert, wenn auf den Grunriss Button geklickt wird.
     */
    void on_Grundriss_clicked();

    /**
     * @brief activeDrawingTool - Getter - Methode die das aktuell gewählte Zeichenwerkzeug zurückgibt.
     * @return aktuell gewählte Zeichenwerkzeug
     */
    Tools::DrawTool activeDrawingTool() const;

    /**
     * @brief activeOptionTool
     * @return aktuell gewählte Option
     */
    Tools::OptionTool activeOptionTool() const;

    /**
     * @brief setActiveDrawingTool Setter - Methode die das Auswahlwerkzeug settet.
     * @param activeDrawingTool
     */
    void setActiveDrawingTool(const Tools::DrawTool activeDrawingTool);

    /**
     * @brief setActiveOptionTool
     * @param activeOptionTool
     */
    void setActiveOptionTool(const Tools::OptionTool activeOptionTool);

    /**
     * @brief on_PolygonButton_clicked - Was passiert, wenn auf den Polygon Button geklickt wird.
     */
    void on_PolygonButton_clicked();

    /**
     * @brief on_Moebel_clicked - Was passiert, wenn auf den Moebel Button geklickt wird.
     */
    void on_Moebel_clicked();

signals:
    /**
     * @brief activeDrawingToolChanged - Signal um zu vemitteln, dass das Zeichenwerkzeug geändert wurde.
     * @param activeDrawingTool
     */
    void activeDrawingToolChanged(Tools::DrawTool activeDrawingTool);

    /**
     * @brief activeOptionToolChanged
     * @param activeOptionTool
     */
    void activeOptionToolChanged(Tools::OptionTool activeOptionTool);

private:
    Ui::DrawingToolSelector *ui;
    Tools::DrawTool m_activeDrawingTool;
    Tools::OptionTool m_activeOptionTool;
};

#endif // DRAWINGTOOLSELECTOR_H
