#include "s21_controller.h"

#include "s21_opengl.h"

void s21::controller::startParsing(const std::string &filename) {
  clear();
  model_->parseObjFile(filename);
  opengl_->update();
}

void s21::controller::mousePressed(QMouseEvent *event) {
  lastPos = event->pos();
}

void s21::controller::mouseMoved(QMouseEvent *event) {
  int dx = event->position().x() - lastPos.x();
  int dy = event->position().y() - lastPos.y();
  rotateObj(dy, 'x');
  rotateObj(dx, 'y');
  lastPos = event->pos();
  opengl_->update();
}

std::array<double, 6> &s21::controller::getPrj() { return model_->getPrj(); }

void s21::controller::handleMoveSliderValueChanged(int value, char dir) {
  switch (dir) {
    case 'x':
      moveViewer(value, 'x');
      break;
    case 'y':
      moveViewer(value, 'y');
      break;
    case 'z':
      moveViewer(value, 'z');
      break;
  }
}

void s21::controller::moveViewer(int value, char axis) {
  moveObj(value - getPos(axis), axis);
}

void s21::controller::moveObj(int value, char axis) {
  model_->moveObj(value, axis);
  opengl_->update();
}

void s21::controller::handleRotationSliderValueChanged(int value, char dir) {
  switch (dir) {
    case 'x':
      rotateViewer(value, 'x');
      break;
    case 'y':
      rotateViewer(value, 'y');
      break;
    case 'z':
      rotateViewer(value, 'z');
      break;
  }
}

void s21::controller::rotateObj(int value, char axis) {
  model_->rotateObj(value, axis);
  emit change_rotation(getRot(axis), axis);
}

void s21::controller::rotateViewer(int value, char axis) {
  this->rotateObj(value - getRot(axis), axis);
  opengl_->update();
}

void s21::controller::handleScaleSliderValueChanged(int scale) {
  model_->setScale(scale);
  opengl_->update();
}

int s21::controller::getRot(char axis) { return model_->getRot(axis); }

int s21::controller::getPos(char axis) { return model_->getPos(axis); }

void s21::controller::setPos(int value, char axis) {
  model_->setPos(value, axis);
}

void s21::controller::setRot(int value, char axis) {
  model_->setRot(value, axis);
}

void s21::controller::setOpenGl(s21::opengl *opengl) { opengl_ = opengl; }

void s21::controller::clear() { model_->clearData(); }

std::vector<float> &s21::controller::getVertices() {
  return model_->getVertices();
}

std::vector<unsigned int> &s21::controller::getFaces() {
  return model_->getFaces();
}

double s21::controller::getScale() { return model_->getScale(); }

void s21::controller::setScale(int scale) { model_->setScale(scale); }

void s21::controller::changeProjection(s21::Projection projection) {
  model_->changeProjection(projection);
  opengl_->update();
}

s21::Projection s21::controller::getProjection() {
  return static_cast<s21::Projection>(model_->getProjection());
}

std::string s21::controller::getObjInfo() {
  std::string result;
  std::ostringstream oss;
  oss << "V: " << model_->getVertCount() << " F: " << model_->getFaceCount();
  result = oss.str();
  return result;
}

int s21::controller::getVertCount() { return model_->getVertCount(); }

void s21::controller::setLineWidth(int value) {
  model_->setLineWidth(value);
  opengl_->update();
}

int s21::controller::getLineWidth() { return model_->getLineWidth(); }

void s21::controller::setLineStyle(int index) {
  model_->setLineStyle(index);
  opengl_->update();
}

int s21::controller::getLineStyle() { return model_->getLineStyle(); }

int s21::controller::getPointSize() { return model_->getPointSize(); }

void s21::controller::setPointSize(int value) {
  model_->setPointSize(value);
  opengl_->update();
}

void s21::controller::setPointStyle(int value) {
  model_->setPointStyle(value);
  opengl_->update();
}

int s21::controller::getPointStyle() { return model_->getPointStyle(); }

void s21::controller::setBgColor(QColor color) {
  model_->setBgColor(color.redF(), color.greenF(), color.blueF());
  opengl_->update();
}

void s21::controller::setLineColor(QColor color) {
  model_->setLineColor(color.redF(), color.greenF(), color.blueF());
  opengl_->update();
}

void s21::controller::setPointColor(QColor color) {
  model_->setPointColor(color.redF(), color.greenF(), color.blueF());
  opengl_->update();
}

std::map<char, float> s21::controller::getBgColor() {
  return model_->getBgColor();
}

std::map<char, float> s21::controller::getLineColor() {
  return model_->getLineColor();
}

std::map<char, float> s21::controller::getPointColor() {
  return model_->getPointColor();
}
