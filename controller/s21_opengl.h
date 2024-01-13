#ifndef SRC_CONTROLLER_S21_OPENGL_H_
#define SRC_CONTROLLER_S21_OPENGL_H_

#include <QDebug>
#include <QMouseEvent>
#include <QObject>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QWidget>
#include <iostream>

#include "s21_controller.h"

namespace s21 {
enum class Projection;
class controller;

class opengl : public QOpenGLWidget, public QOpenGLFunctions {
 public slots:
  void mousePressEvent(QMouseEvent* event);
  void mouseMoveEvent(QMouseEvent* event);

 public:
  explicit opengl(QWidget* parent = nullptr,
                  s21::controller* controller = nullptr);
  ~opengl();

 protected:
  void initializeGL() override;
  void paintGL() override;
  void resizeGL(int width, int height) override;

 private:
  s21::controller* controller_;
};
}  // namespace s21

#endif  // SRC_CONTROLLER_S21_OPENGL_H_
