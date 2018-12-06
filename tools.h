#ifndef TOOLS_H
#define TOOLS_H

#include <QObject>
#include <QColor>

/**
 * @brief The Tools class - Klasse für die Zeichenwerkzeuge und Einstellung von Füllfarbe und Rahmenfarbe.
 */
class Tools : public QObject
{
    Q_OBJECT
public:
    explicit Tools(QObject *parent = nullptr);

    /**
     * @brief Getter - Methode für BorderColor
     */
    QColor getBorderColor() const;

    /**
     * @brief Getter - Methode für FillColor
     */
    QColor getFillColor() const;


    /**
     * @brief The State enum
     */
    enum State{NONE_ACTIVE,GRABBER_ACTIVE,RECT_ACTIVE,CIRC_ACTIVE};

    /**
     * @brief The DrawTool enum
     */
    enum DrawTool{
        GRABBER,
        CIRCLE,
        RECTANGLE,
        POLYGON
    };

    /**
     * @brief The OptionTool enum
     */
    enum OptionTool{
        GRUNDRISS,
        MOEBEL
    };

    /**
     * @brief getState
     * @return
     */
    State getState();

    /**
     * @brief getDrawTool - Setter Methode für das Auswahlwerkzeug
     * @return
     */
    DrawTool getDrawTool();

    OptionTool getOptionTool();

protected:
    Tools::DrawTool werkzeug;
    Tools::OptionTool option;
    State status;
    QColor borderColor;
    QColor fillColor;

signals:
    /**
     * @brief activeDrawToolChanged - Signal, das aussendet wenn ein Auswahlwerkzeug geändert wurde.
     * @param value
     */
    void activeDrawToolChanged(const Tools::DrawTool &value);

    /**
     * @brief activeBorderColorChanged - Signal, das aussendet wenn die Rahmenfarbe geändert wurde
     * @param color
     */
    void activeBorderColorChanged(QColor color);

    /**
     * @brief activeFillColorChanged -Signal, das aussendet wenn die Füllfarbe geänert wurde
     * @param color
     */
    void activeFillColorChanged(QColor color);

    /**
     * @brief activeOptionToolChanged - Getter - Methode für das OptionTool Werkzeug.
     * @param value
     */
    void activeOptionToolChanged(const Tools::OptionTool &value);

public slots:

    /**
     * @brief setFillColor - Setter Methode für Füllfarbe
     * @param value
     */
    void setFillColor(const QColor &value);

    /**
     * @brief setBorderColor - Setter Methode für Rahmenfarbe
     * @param value
     */
    void setBorderColor(const QColor &value);

    /**
     * @brief setState - Setter Methode für State
     * @param state
     */
    void setState(State state);

    /**
     * @brief setDrawTool - Setter Methode für das Auswahlwerkzeug
     * @param drawtool
     */
    void setDrawTool(const Tools::DrawTool drawtool);

    /**
     * @brief setOptionTool - Setter Methode für das OptionTool Werkzeug.
     * @param optionTool
     */
    void setOptionTool(const Tools::OptionTool optionTool);

};

#endif // TOOLS_H
