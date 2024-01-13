/********************************************************************************
** Form generated from reading UI file 'view.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW_H
#define UI_VIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *opengl_frame;
    QFrame *control_frame;
    QLabel *move_y_label;
    QSlider *scale_slider;
    QLabel *move_z_label;
    QPushButton *open_button;
    QLabel *rotation_x_label;
    QLabel *projection_label;
    QLabel *rotation_z_label;
    QSlider *move_z_slider;
    QSlider *rotation_z_slider;
    QSlider *rotation_x_slider;
    QRadioButton *central_rbutton;
    QSlider *move_y_slider;
    QLabel *scale_label;
    QLabel *move_label;
    QSlider *move_x_slider;
    QLabel *rotation_y_label;
    QSlider *rotation_y_slider;
    QRadioButton *parallel_rbutton;
    QLabel *move_x_label;
    QLabel *rotation_label;
    QComboBox *line_style_combobox;
    QLabel *line_style_label;
    QLabel *vert_style_label;
    QComboBox *comboBox;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QLabel *label;
    QPushButton *bg_color_picker;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *bg_color_picker_2;
    QLabel *label_4;
    QPushButton *bg_color_picker_3;
    QLabel *filename_label;
    QLabel *info_label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(910, 610);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        opengl_frame = new QFrame(centralwidget);
        opengl_frame->setObjectName("opengl_frame");
        opengl_frame->setGeometry(QRect(0, 0, 700, 610));
        opengl_frame->setFrameShape(QFrame::StyledPanel);
        opengl_frame->setFrameShadow(QFrame::Raised);
        control_frame = new QFrame(centralwidget);
        control_frame->setObjectName("control_frame");
        control_frame->setGeometry(QRect(700, 0, 210, 610));
        control_frame->setMinimumSize(QSize(210, 0));
        control_frame->setFrameShape(QFrame::StyledPanel);
        control_frame->setFrameShadow(QFrame::Raised);
        move_y_label = new QLabel(control_frame);
        move_y_label->setObjectName("move_y_label");
        move_y_label->setGeometry(QRect(10, 293, 16, 16));
        scale_slider = new QSlider(control_frame);
        scale_slider->setObjectName("scale_slider");
        scale_slider->setGeometry(QRect(30, 130, 160, 21));
        scale_slider->setMinimum(-99);
        scale_slider->setMaximum(299);
        scale_slider->setSliderPosition(1);
        scale_slider->setOrientation(Qt::Horizontal);
        move_z_label = new QLabel(control_frame);
        move_z_label->setObjectName("move_z_label");
        move_z_label->setGeometry(QRect(10, 313, 16, 16));
        open_button = new QPushButton(control_frame);
        open_button->setObjectName("open_button");
        open_button->setGeometry(QRect(10, 20, 83, 21));
        rotation_x_label = new QLabel(control_frame);
        rotation_x_label->setObjectName("rotation_x_label");
        rotation_x_label->setGeometry(QRect(10, 180, 21, 16));
        projection_label = new QLabel(control_frame);
        projection_label->setObjectName("projection_label");
        projection_label->setGeometry(QRect(70, 60, 81, 16));
        rotation_z_label = new QLabel(control_frame);
        rotation_z_label->setObjectName("rotation_z_label");
        rotation_z_label->setGeometry(QRect(10, 220, 16, 16));
        move_z_slider = new QSlider(control_frame);
        move_z_slider->setObjectName("move_z_slider");
        move_z_slider->setGeometry(QRect(30, 310, 160, 21));
        move_z_slider->setMinimum(-100);
        move_z_slider->setMaximum(100);
        move_z_slider->setOrientation(Qt::Horizontal);
        rotation_z_slider = new QSlider(control_frame);
        rotation_z_slider->setObjectName("rotation_z_slider");
        rotation_z_slider->setGeometry(QRect(30, 220, 160, 21));
        rotation_z_slider->setMinimum(0);
        rotation_z_slider->setMaximum(360);
        rotation_z_slider->setOrientation(Qt::Horizontal);
        rotation_x_slider = new QSlider(control_frame);
        rotation_x_slider->setObjectName("rotation_x_slider");
        rotation_x_slider->setGeometry(QRect(30, 180, 160, 21));
        rotation_x_slider->setMinimum(0);
        rotation_x_slider->setMaximum(360);
        rotation_x_slider->setOrientation(Qt::Horizontal);
        central_rbutton = new QRadioButton(control_frame);
        central_rbutton->setObjectName("central_rbutton");
        central_rbutton->setGeometry(QRect(100, 80, 71, 22));
        move_y_slider = new QSlider(control_frame);
        move_y_slider->setObjectName("move_y_slider");
        move_y_slider->setGeometry(QRect(30, 290, 160, 21));
        move_y_slider->setMinimum(-100);
        move_y_slider->setMaximum(100);
        move_y_slider->setOrientation(Qt::Horizontal);
        scale_label = new QLabel(control_frame);
        scale_label->setObjectName("scale_label");
        scale_label->setGeometry(QRect(80, 110, 41, 16));
        move_label = new QLabel(control_frame);
        move_label->setObjectName("move_label");
        move_label->setGeometry(QRect(85, 250, 41, 16));
        move_x_slider = new QSlider(control_frame);
        move_x_slider->setObjectName("move_x_slider");
        move_x_slider->setGeometry(QRect(30, 270, 160, 21));
        move_x_slider->setMinimum(-100);
        move_x_slider->setMaximum(100);
        move_x_slider->setOrientation(Qt::Horizontal);
        rotation_y_label = new QLabel(control_frame);
        rotation_y_label->setObjectName("rotation_y_label");
        rotation_y_label->setGeometry(QRect(10, 200, 16, 16));
        rotation_y_slider = new QSlider(control_frame);
        rotation_y_slider->setObjectName("rotation_y_slider");
        rotation_y_slider->setGeometry(QRect(30, 200, 160, 21));
        rotation_y_slider->setMinimum(0);
        rotation_y_slider->setMaximum(360);
        rotation_y_slider->setOrientation(Qt::Horizontal);
        parallel_rbutton = new QRadioButton(control_frame);
        parallel_rbutton->setObjectName("parallel_rbutton");
        parallel_rbutton->setGeometry(QRect(20, 80, 71, 22));
        parallel_rbutton->setChecked(true);
        move_x_label = new QLabel(control_frame);
        move_x_label->setObjectName("move_x_label");
        move_x_label->setGeometry(QRect(10, 273, 21, 16));
        rotation_label = new QLabel(control_frame);
        rotation_label->setObjectName("rotation_label");
        rotation_label->setGeometry(QRect(80, 160, 62, 16));
        line_style_combobox = new QComboBox(control_frame);
        line_style_combobox->addItem(QString());
        line_style_combobox->addItem(QString());
        line_style_combobox->addItem(QString());
        line_style_combobox->setObjectName("line_style_combobox");
        line_style_combobox->setGeometry(QRect(30, 360, 81, 24));
        line_style_label = new QLabel(control_frame);
        line_style_label->setObjectName("line_style_label");
        line_style_label->setGeometry(QRect(80, 340, 62, 16));
        vert_style_label = new QLabel(control_frame);
        vert_style_label->setObjectName("vert_style_label");
        vert_style_label->setGeometry(QRect(60, 390, 81, 16));
        comboBox = new QComboBox(control_frame);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(30, 410, 81, 24));
        spinBox = new QSpinBox(control_frame);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(130, 360, 41, 25));
        spinBox->setMinimum(1);
        spinBox->setMaximum(15);
        spinBox_2 = new QSpinBox(control_frame);
        spinBox_2->setObjectName("spinBox_2");
        spinBox_2->setGeometry(QRect(130, 410, 41, 25));
        spinBox_2->setMinimum(1);
        spinBox_2->setMaximum(15);
        label = new QLabel(control_frame);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 450, 81, 20));
        bg_color_picker = new QPushButton(control_frame);
        bg_color_picker->setObjectName("bg_color_picker");
        bg_color_picker->setGeometry(QRect(130, 540, 41, 21));
        bg_color_picker->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        label_2 = new QLabel(control_frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 540, 81, 21));
        label_3 = new QLabel(control_frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(80, 480, 31, 21));
        bg_color_picker_2 = new QPushButton(control_frame);
        bg_color_picker_2->setObjectName("bg_color_picker_2");
        bg_color_picker_2->setGeometry(QRect(130, 480, 41, 21));
        bg_color_picker_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_4 = new QLabel(control_frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(62, 510, 51, 21));
        bg_color_picker_3 = new QPushButton(control_frame);
        bg_color_picker_3->setObjectName("bg_color_picker_3");
        bg_color_picker_3->setGeometry(QRect(130, 510, 41, 21));
        bg_color_picker_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        filename_label = new QLabel(control_frame);
        filename_label->setObjectName("filename_label");
        filename_label->setGeometry(QRect(100, 10, 91, 21));
        info_label = new QLabel(control_frame);
        info_label->setObjectName("info_label");
        info_label->setGeometry(QRect(100, 30, 101, 20));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        move_y_label->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        move_z_label->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        open_button->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        rotation_x_label->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        projection_label->setText(QCoreApplication::translate("MainWindow", "Projection", nullptr));
        rotation_z_label->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        central_rbutton->setText(QCoreApplication::translate("MainWindow", "Central", nullptr));
        scale_label->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        move_label->setText(QCoreApplication::translate("MainWindow", "Move", nullptr));
        rotation_y_label->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        parallel_rbutton->setText(QCoreApplication::translate("MainWindow", "Parallel", nullptr));
        move_x_label->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        rotation_label->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        line_style_combobox->setItemText(0, QCoreApplication::translate("MainWindow", "Solid", nullptr));
        line_style_combobox->setItemText(1, QCoreApplication::translate("MainWindow", "Dashed", nullptr));
        line_style_combobox->setItemText(2, QCoreApplication::translate("MainWindow", "Dotted", nullptr));

        line_style_label->setText(QCoreApplication::translate("MainWindow", "Line style", nullptr));
        vert_style_label->setText(QCoreApplication::translate("MainWindow", "Vertice style", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "None", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Circle", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Square", nullptr));

        label->setText(QCoreApplication::translate("MainWindow", "Color picker", nullptr));
        bg_color_picker->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "Background", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Line", nullptr));
        bg_color_picker_2->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "Vertice", nullptr));
        bg_color_picker_3->setText(QString());
        filename_label->setText(QCoreApplication::translate("MainWindow", "", nullptr));
        info_label->setText(QCoreApplication::translate("MainWindow", "", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_H
