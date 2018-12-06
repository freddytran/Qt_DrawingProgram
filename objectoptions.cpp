#include "objectoptions.h"
#include "ui_objectoptions.h"

ObjectOptions::ObjectOptions(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ObjectOptions)
{
    ui->setupUi(this);
    /**
     * Hier werden Default - Werte für die einzelnen Member - Variablen gesetzt.
     * Damit auch wenn beim Position/Dimensionen Feld nichts eingegeben wird bei manchen optionen
     * das gewählte Objekt trotzdem gezeichnet werden kann.
     */
    m_xkoord = 0;
    m_ykoord = 0;
    m_width = 0;
    m_height = 0;
}

ObjectOptions::~ObjectOptions()
{
    delete ui;
}

/**
 * @brief ObjectOptions::xkoord - Getter - Methode für m_xkoord
 * @return
 */
int ObjectOptions::xkoord() const
{
    return m_xkoord;
}

/**
 * @brief ObjectOptions::ykoord - Getter - Methode für m_ykoord
 * @return
 */
int ObjectOptions::ykoord() const
{
    return m_ykoord;
}

/**
 * @brief ObjectOptions::height - Getter - Methode für m_height
 * @return
 */
int ObjectOptions::height() const
{
    return m_height;
}

/**
 * @brief ObjectOptions::width - Getter - Methode für m_width
 * @return
 */
int ObjectOptions::width() const
{
    return m_width;
}

/**
 * @brief ObjectOptions::on_xSpinBox_valueChanged - Setter - Methode für m_xkoord
 * @param arg1
 */
void ObjectOptions::on_xSpinBox_valueChanged(int arg1)
{
    m_xkoord = arg1;
}

/**
 * @brief ObjectOptions::on_ySpinBox_valueChanged - Setter - Methode für ykoord
 * @param arg1
 */
void ObjectOptions::on_ySpinBox_valueChanged(int arg1)
{
    m_ykoord = arg1;
}

/**
 * @brief ObjectOptions::on_hSpinBox_valueChanged - Setter - Methode für m_height
 * @param arg1
 */
void ObjectOptions::on_hSpinBox_valueChanged(int arg1)
{
    m_height = arg1;
}

/**
 * @brief ObjectOptions::on_wSpinBox_valueChanged - Setter - Methode für m_width
 * @param arg1
 */
void ObjectOptions::on_wSpinBox_valueChanged(int arg1)
{
    m_width = arg1;
}

void ObjectOptions::setWidth(int width)
{
    m_width = width;
}

void ObjectOptions::setHeight(int height)
{
    m_height = height;
}

void ObjectOptions::setYkoord(int ykoord)
{
    m_ykoord = ykoord;
}

void ObjectOptions::setXkoord(int xkoord)
{
    m_xkoord = xkoord;
}
