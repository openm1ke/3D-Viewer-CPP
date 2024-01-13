#ifndef SRC_VIEW_S21_VIEW_H_
#define SRC_VIEW_S21_VIEW_H_

#include <QColor>
#include <QColorDialog>
#include <QComboBox>
#include <QDebug>
#include <QFileDialog>
#include <QFileInfo>
#include <QFrame>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QMainWindow>
#include <QSettings>

#include "../controller/s21_controller.h"
#include "../controller/s21_opengl.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace s21 {
enum class Projection;

const QString ORGANIZATION_NAME = "School21";
const QString ORGANIZATION_DOMAIN = "www.21-school.ru";
const QString APPLICATION_NAME = "3DViewer_v2.0";

class view : public QMainWindow {
  Q_OBJECT
 public slots:
  void change_slider_position(int val, char dir);

 public:
  explicit view(s21::controller *controller = nullptr);
  ~view();

 private slots:
  void on_open_button_clicked();
  void on_parallel_rbutton_toggled();
  void on_central_rbutton_toggled();
  void on_bg_color_picker_clicked();
  void on_bg_color_picker_2_clicked();
  void on_bg_color_picker_3_clicked();
  void on_spinBox_valueChanged(int value);
  void on_line_style_combobox_currentIndexChanged(int index);
  void on_comboBox_currentIndexChanged(int index);
  void on_spinBox_2_valueChanged(int value);

 private:
  Ui::MainWindow *ui;
  QGridLayout *layout;
  s21::controller *controller_;
  s21::opengl *opengl_;
  void resizeEvent(QResizeEvent *);
  void loadSettings();
  void saveSettings();
  void loadDefaults();
};
}  // namespace s21

#endif  // SRC_VIEW_S21_VIEW_H_
