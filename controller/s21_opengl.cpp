#include "s21_opengl.h"

#include "s21_controller.h"
#include "s21_strategy.h"

s21::opengl::opengl(QWidget* parent, s21::controller* controller)
    : QOpenGLWidget(parent), controller_(controller) {}

s21::opengl::~opengl() {}

void s21::opengl::initializeGL() {
  initializeOpenGLFunctions();
  glEnable(GL_DEPTH_TEST);
}

void s21::opengl::resizeGL(int width, int height) {
  glViewport(0, 0, width, height);
}

void s21::opengl::mousePressEvent(QMouseEvent* event) {
  controller_->mousePressed(event);
}

void s21::opengl::mouseMoveEvent(QMouseEvent* event) {
  controller_->mouseMoved(event);
}

void s21::opengl::paintGL() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  const auto& vert = controller_->getVertices();
  const auto& face = controller_->getFaces();

  s21::IProjectionStrategy* strategy = nullptr;

  switch (controller_->getProjection()) {
    case s21::Projection::ORTHOGRAPHIC:
      strategy = new s21::OrthographicProjection(controller_);
      break;
    case s21::Projection::PERSPECTIVE:
      strategy = new s21::PerspectiveProjection(controller_);
      break;
  }

  if (strategy) {
    strategy->applyProjection();
    delete strategy;
  }

  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_FLOAT, 0, vert.data());
  glDrawElements(GL_LINES, face.size(), GL_UNSIGNED_INT, face.data());

  std::map<char, float> point = controller_->getPointColor();
  glColor3f(point['r'], point['g'], point['b']);

  glDrawArrays(GL_POINTS, 0, controller_->getVertCount());
  glDisableClientState(GL_VERTEX_ARRAY);
}
