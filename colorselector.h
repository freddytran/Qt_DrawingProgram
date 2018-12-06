#ifndef COLORSELECTOR_H
#define COLORSELECTOR_H

#include <QWidget>
#include <QColor>
#include <colorbutton.h>

namespace Ui {
class ColorSelector;
}

/**
 * @brief The ColorSelector class - Eigenes Zusammengestelltes Widget für Farbwahl
 */
class ColorSelector : public QWidget
{
    Q_OBJECT

public:
    explicit ColorSelector(QWidget *parent = 0);
    ~ColorSelector();

private slots:

    /**
     * @brief on_BorderColorButton_clicked
     */
    void on_BorderColorButton_clicked();

    /**
     * @brief on_FillColorButton_clicked
     */
    void on_FillColorButton_clicked();

    /**
     * @brief setActiveBorderColor
     * @param color
     */
    void setActiveBorderColor(QColor color);

    /**
     * @brief setActiveFillColor
     * @param color
     */
    void setActiveFillColor(QColor color);


signals:
    /**
     * @brief activeBorderColorChanged - Signal, um zu vermitteln, dass die Rahmenfarbe geändert wurde.
     * @param color
     */
    void activeBorderColorChanged(QColor color);

    /**
     * @brief activeFillColorChanged - Signal, um zu vermitteln, dass die Füllfarbe geändert wurde
     * @param color
     */
    void activeFillColorChanged(QColor color);

private:
    Ui::ColorSelector *ui;
    ColorButton m_colorSelector;
};

#endif // COLORSELECTOR_H
