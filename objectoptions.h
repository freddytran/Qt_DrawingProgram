#ifndef OBJECTOPTIONS_H
#define OBJECTOPTIONS_H

#include <QWidget>

namespace Ui {
class ObjectOptions;
}

/**
 * @brief The ObjectOptions class - Eigenes zusammengestelltes Widget für die Dimensonen und Position
 */
class ObjectOptions : public QWidget
{
    Q_OBJECT

public:
    explicit ObjectOptions(QWidget *parent = 0);
    ~ObjectOptions();

    /**
     * @brief Getter Methode für m_xkoord
     * @return m_xkoord
     */
    int xkoord() const;

    /**
     * @brief Getter Methode für m_ykoord
     * @return m_ykoord
     */
    int ykoord() const;

    /**
     * @brief Getter Methode für m_height
     * @return m_height
     */
    int height() const;

    /**
     * @brief Getter Methode für m_width
     * @return m_width
     */
    int width() const;

    void setXkoord(int xkoord);

    void setYkoord(int ykoord);

    void setHeight(int height);

    void setWidth(int width);

private slots:

    /**
     * @brief on_xSpinBox_valueChanged - Diese ersetzt sozusagen die Setter - Methode für m_xkoord
     * @param arg1
     */
    void on_xSpinBox_valueChanged(int arg1);

    /**
     * @brief on_ySpinBox_valueChanged - Diese ersetzt sozusagen die Setter - Methode für m_ykoord
     * @param arg1
     */
    void on_ySpinBox_valueChanged(int arg1);

    /**
     * @brief on_hSpinBox_valueChanged - Diese ersetzt sozusagen die Setter - Methode für m_height
     * @param arg1
     */
    void on_hSpinBox_valueChanged(int arg1);

    /**
     * @brief on_wSpinBox_valueChanged - Diese ersetzt sozusagen die Setter - Methode für m_width
     * @param arg1
     */
    void on_wSpinBox_valueChanged(int arg1);

private:
    Ui::ObjectOptions *ui;
    int m_xkoord;
    int m_ykoord;
    int m_height;
    int m_width;
};

#endif // OBJECTOPTIONS_H
