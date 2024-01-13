#include "s21_view.h"

#include "ui_view.h"

s21::view::view(s21::controller *controller)
    : QMainWindow(), ui(new Ui::MainWindow), controller_(controller) {
  ui->setupUi(this);
  this->opengl_ = new s21::opengl(ui->opengl_frame, controller);
  controller_->setOpenGl(this->opengl_);
  this->setWindowTitle(s21::APPLICATION_NAME);
  QVBoxLayout *layout = new QVBoxLayout(ui->opengl_frame);
  layout->addWidget(opengl_);

  connect(this->controller_, &s21::controller::change_rotation, this,
          &s21::view::change_slider_position);

  connect(ui->rotation_x_slider, &QSlider::valueChanged, [this](int value) {
    controller_->handleRotationSliderValueChanged(value, 'x');
  });
  connect(ui->rotation_y_slider, &QSlider::valueChanged, [this](int value) {
    controller_->handleRotationSliderValueChanged(value, 'y');
  });
  connect(ui->rotation_z_slider, &QSlider::valueChanged, [this](int value) {
    controller_->handleRotationSliderValueChanged(value, 'z');
  });

  connect(ui->move_x_slider, &QSlider::valueChanged, [this](int value) {
    controller_->handleMoveSliderValueChanged(value, 'x');
  });
  connect(ui->move_y_slider, &QSlider::valueChanged, [this](int value) {
    controller_->handleMoveSliderValueChanged(value, 'y');
  });
  connect(ui->move_z_slider, &QSlider::valueChanged, [this](int value) {
    controller_->handleMoveSliderValueChanged(value, 'z');
  });

  connect(ui->scale_slider, &QSlider::valueChanged, controller_,
          &s21::controller::handleScaleSliderValueChanged);

  loadSettings();

  ui->opengl_frame->setLayout(layout);

  this->opengl_->update();
}

s21::view::~view() {
  saveSettings();
  delete ui;
}

void s21::view::on_open_button_clicked() {
  QString fileName_open;
  fileName_open =
      QFileDialog::getOpenFileName(this, "Open file ...", "~/", "*.obj",
                                   nullptr, QFileDialog::DontUseNativeDialog);
  if (fileName_open.isNull()) {
    return;
  } else {
    saveSettings();
    loadDefaults();
    QFileInfo fileInfo(fileName_open);
    QString justFileName = fileInfo.fileName();
    controller_->startParsing(fileName_open.toStdString());
    ui->filename_label->setText(justFileName);
    ui->info_label->setText(QString::fromStdString(controller_->getObjInfo()));
  }
}

void s21::view::resizeEvent(QResizeEvent *) {
  // ui->horizontalLayoutWidget->resize(this->size());
}

void s21::view::change_slider_position(int val, char dir) {
  int degrees = val % 360 + (val < 0 ? 360 : 0);
  if (dir == 'x') ui->rotation_x_slider->setValue(degrees);
  if (dir == 'y') ui->rotation_y_slider->setValue(degrees);
}

void s21::view::on_parallel_rbutton_toggled() {
  controller_->changeProjection(s21::Projection::ORTHOGRAPHIC);
}

void s21::view::on_central_rbutton_toggled() {
  controller_->changeProjection(s21::Projection::PERSPECTIVE);
}

void s21::view::on_bg_color_picker_clicked() {
  QColor color = QColorDialog::getColor(Qt::black, this, "Select color");
  if (color.isValid()) {
    controller_->setBgColor(color);
    this->ui->bg_color_picker->setStyleSheet(
        QString("background-color: %1").arg(color.name()));
  }
}

void s21::view::on_bg_color_picker_2_clicked() {
  QColor color = QColorDialog::getColor(Qt::black, this, "Select color");
  if (color.isValid()) {
    controller_->setLineColor(color);
    this->ui->bg_color_picker_2->setStyleSheet(
        QString("background-color: %1").arg(color.name()));
  }
}

void s21::view::on_bg_color_picker_3_clicked() {
  QColor color = QColorDialog::getColor(Qt::black, this, "Select color");
  if (color.isValid()) {
    controller_->setPointColor(color);
    this->ui->bg_color_picker_3->setStyleSheet(
        QString("background-color: %1").arg(color.name()));
  }
}

void s21::view::on_spinBox_valueChanged(int value) {
  controller_->setLineWidth(value);
}

void s21::view::on_line_style_combobox_currentIndexChanged(int index) {
  controller_->setLineStyle(index);
}

void s21::view::on_spinBox_2_valueChanged(int value) {
  controller_->setPointSize(value);
}

void s21::view::on_comboBox_currentIndexChanged(int index) {
  controller_->setPointStyle(index);
}

void s21::view::loadDefaults() {
  ui->scale_slider->setValue(1);
  ui->rotation_x_slider->setValue(0);
  ui->rotation_y_slider->setValue(0);
  ui->rotation_z_slider->setValue(0);
  ui->move_x_slider->setValue(0);
  ui->move_y_slider->setValue(0);
  ui->move_z_slider->setValue(0);
}

void s21::view::loadSettings() {
  QSettings settings(ORGANIZATION_NAME, APPLICATION_NAME);
  ui->parallel_rbutton->setChecked(settings.value("Parallel", false).toBool());
  ui->central_rbutton->setChecked(settings.value("Central", false).toBool());
  ui->spinBox->setValue(settings.value("LineWidth", 1).toInt());
  ui->line_style_combobox->setCurrentIndex(
      settings.value("LineStyle", 0).toInt());
  ui->spinBox_2->setValue(settings.value("PointSize", 1).toInt());
  ui->comboBox->setCurrentIndex(settings.value("PointStyle", 0).toInt());

  QColor color = settings.value("BgColor", QColor(Qt::black)).value<QColor>();
  ui->bg_color_picker->setStyleSheet(
      QString("background-color: %1").arg(color.name()));
  controller_->setBgColor(color);

  color = settings.value("LineColor", QColor(Qt::black)).value<QColor>();
  ui->bg_color_picker_2->setStyleSheet(
      QString("background-color: %1").arg(color.name()));
  controller_->setLineColor(color);

  color = settings.value("PointColor", QColor(Qt::black)).value<QColor>();
  ui->bg_color_picker_3->setStyleSheet(
      QString("background-color: %1").arg(color.name()));
  controller_->setPointColor(color);
}

void s21::view::saveSettings() {
  QSettings settings(ORGANIZATION_NAME, APPLICATION_NAME);
  settings.setValue("Parallel", ui->parallel_rbutton->isChecked());
  settings.setValue("Central", ui->central_rbutton->isChecked());
  settings.setValue("LineWidth", ui->spinBox->value());
  settings.setValue("LineStyle", ui->line_style_combobox->currentIndex());
  settings.setValue("PointSize", ui->spinBox_2->value());
  settings.setValue("PointStyle", ui->comboBox->currentIndex());

  settings.setValue("BgColor", ui->bg_color_picker->palette().button().color());
  settings.setValue("LineColor",
                    ui->bg_color_picker_2->palette().button().color());
  settings.setValue("PointColor",
                    ui->bg_color_picker_3->palette().button().color());
  settings.sync();
}
