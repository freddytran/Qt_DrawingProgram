#include "tools.h"
#include <iostream>
#include <drawingtoolselector.h>

using namespace std;

/**
 * @brief Tools::Tools Konstruktor
 * @param parent
 */
Tools::Tools(QObject *parent) : QObject(parent)
{

}

/**
 * @brief Tools::getBorderColor
 * @return borderColor
 */
QColor Tools::getBorderColor() const
{
    return borderColor;
}

/**
 * @brief Tools::setBorderColor
 * @param value
 */
void Tools::setBorderColor(const QColor &value)
{
    borderColor = value;
}

/**
 * @brief Tools::getFillColor
 * @return fillColor
 */
QColor Tools::getFillColor() const
{
    return fillColor;
}

/**
 * @brief Tools::setFillColor
 * @param value
 */
void Tools::setFillColor(const QColor &value)
{
    fillColor = value;
}

/**
 * @brief Tools::setState
 * @param state
 */
void Tools::setState(State state){
    status = state;
}

/**
 * @brief Tools::setDrawTool - Setzt das Zeichenwerkzeug.
 * @param drawtool
 */
void Tools::setDrawTool(const Tools::DrawTool drawtool){
    if(werkzeug != drawtool){
      werkzeug = drawtool;
      emit activeDrawToolChanged(werkzeug);
    }
}

/**
 * @brief Tools::setOptionTool - Setzt das OptionTool (Grundriss oder Moebel)
 * @param optionTool
 */
void Tools::setOptionTool(const Tools::OptionTool optionTool)
{
    if(option != optionTool){
        option = optionTool;
        emit activeOptionToolChanged(option);
    }
}

/**
 * @brief Tools::getState
 * @return status
 */
Tools::State Tools::getState(){

    return status;
}

/**
 * @brief Tools::getDrawTool - Getter - Methode, welche das Zeichenwerkzeug zurückgibt.
 * @return werkzeug
 */
Tools::DrawTool Tools::getDrawTool(){

    return werkzeug;
}

/**
 * @brief Tools::getOptionTool - Getter - Methode, welche das Optionwerkzeug zurückgibt. (Grundriss oder Moebel)
 * @return option
 */
Tools::OptionTool Tools::getOptionTool()
{
    return option;
}



