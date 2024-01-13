#include "s21_strategy.h"

namespace s21 {

void IProjectionStrategy::applyLineWidth() {
  glEnable(GL_LINE_WIDTH);
  glLineWidth(controller_->getLineWidth());
}

void IProjectionStrategy::applyLineStyle() {
  glEnable(GL_LINE_STIPPLE);
  switch (controller_->getLineStyle()) {
    case 1:
      glLineStipple(1, 0xF0F0);
      break;
    case 2:
      glLineStipple(1, 0x5555);
      break;
    default:
      glDisable(GL_LINE_STIPPLE);
      break;
  }
}

void IProjectionStrategy::applyPointSettings() {
  //  point size
  glPointSize(controller_->getPointSize());
  //  point style
  switch (controller_->getPointStyle()) {
    case 1:
      glEnable(GL_POINT_SMOOTH);
      break;
    case 2:
      glDisable(GL_POINT_SMOOTH);
      break;
    default:
      glPointSize(1);
      glDisable(GL_POINT_SMOOTH);
      break;
  }
}

void IProjectionStrategy::setLineColor() {
  std::map<char, float> line = controller_->getLineColor();
  glColor3d(line['r'], line['g'], line['b']);
}

void IProjectionStrategy::setBackgroundColor() {
  std::map<char, float> bg = controller_->getBgColor();
  glClearColor(bg['r'], bg['g'], bg['b'], 1.0f);
}

void IProjectionStrategy::applyLineSettings() {
  setBackgroundColor();
  setLineColor();
  glClear(GL_COLOR_BUFFER_BIT);
  applyLineWidth();
  applyLineStyle();
  applyPointSettings();
}

void OrthographicProjection::applyProjection() {
  const auto& prj = controller_->getPrj();
  glOrtho(prj[0], prj[1], prj[2], prj[3], -prj[4], prj[5]);
  applyLineSettings();
}

void PerspectiveProjection::applyProjection() {
  const auto& prj = controller_->getPrj();
  glFrustum(prj[0], prj[1], prj[2], prj[3], prj[4], prj[5]);
  glTranslated(0, 0, -prj[4] * 2);
  applyLineSettings();
}

}  // namespace s21
