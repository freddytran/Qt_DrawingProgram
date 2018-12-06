#include "colorselector.h"
#include "ui_colorselector.h"
#include <QColorDialog>
#include <QColor>
#include <QDebug>
#include <colorbutton.h>

/**
 * @brief ColorSelector::ColorSelector
 * @param parent
 */
ColorSelector::ColorSelector(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ColorSelector)
{
    ui->setupUi(this);
    m_colorSelector.setColor(Qt::black);
    ui->BorderColorButton->setColor(Qt::black);
    ui->FillColorButton->setColor(Qt::black);

}

/**
 * @brief ColorSelector::~ColorSelector
 */
ColorSelector::~ColorSelector()
{
    delete ui;
}

/**
 * @brief ColorSelector::on_BorderColorButton_clicked
 * Hier wird das Pop - Up Fenster geöffnet, wo der Benutzer eine Farbe aussuchen kann.
 * Hat er eine ausgesucht wird ein Signal mit der ausgewählten Farbe ausgesendet.
 */
void ColorSelector::on_BorderColorButton_clicked()
{
    QColor newBorderColor = QColorDialog::getColor(m_colorSelector.color(), this, "Select Color", QColorDialog::ShowAlphaChannel);
        if(newBorderColor.isValid()) {
            m_colorSelector.setColor(newBorderColor);
            setActiveBorderColor(newBorderColor);                                       ///<Setter Funktion wird aufgerufen (weiter unten)
            emit activeBorderColorChanged(m_colorSelector.color());                     ///<Signal wird ausgesendet.
            qDebug()<<"Die ausgewählte Farbe ist: " << m_colorSelector.color().name();
        }
        else {
            qDebug("Farbauswahl für Rahmenfarbe wurde abgebrochen.");
        }
}

/**
 * @brief ColorSelector::on_FillColorButton_clicked
 * Hier wird das Pop - Up Fenster geöffnet, wo der Benutzer eine Farbe aussuchen kann.
 * Hat er eine ausgesucht, wird ein Signal mit der ausgewählten Farbe ausgesendet.
 */
void ColorSelector::on_FillColorButton_clicked()
{
    QColor newFillColor = QColorDialog::getColor(m_colorSelector.color(), this, "Select Color", QColorDialog::ShowAlphaChannel);
        if(newFillColor.isValid()) {
            m_colorSelector.setColor(newFillColor);
            setActiveFillColor(newFillColor);
            emit activeFillColorChanged(m_colorSelector.color());
            qDebug() <<"Die ausgewählte Farbe ist: " << m_colorSelector.color().name();
        }
        else {
            qDebug("Farbauswahl für Füllfarbe wurde abgebrochen.");
        }
}

/**
 * @brief ColorSelector::setActiveBorderColor - Slot der empfängt welche Rahmenfarbe gewählt wurde.
 * @param color
 * Setzt die Rahmenfarbe dann auf die empfangenen Rahmenfarbe
 */
void ColorSelector::setActiveBorderColor(QColor color)
{
    ui->BorderColorButton->setColor(color);
}

/**
 * @brief ColorSelector::setActiveFillColor - Slot der empfängt welche Füllfarbe gewählt wurde
 * @param color
 * Setzt die Füllfarbe dann auf die empfangen Füllfarbe
 */
void ColorSelector::setActiveFillColor(QColor color)
{
    ui->FillColorButton->setColor(color);
}

