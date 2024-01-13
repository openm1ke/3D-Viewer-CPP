#ifndef SRC_CONTROLLER_S21_STRATEGY_H_
#define SRC_CONTROLLER_S21_STRATEGY_H_

#include "s21_controller.h"
#include "s21_opengl.h"

namespace s21 {

class IProjectionStrategy {
 public:
  virtual ~IProjectionStrategy() = default;
  virtual void applyProjection() = 0;

 protected:
  s21::controller* controller_;

  explicit IProjectionStrategy(s21::controller* controller)
      : controller_(controller) {}

  void applyLineWidth();
  void applyLineStyle();
  void applyPointSettings();
  void setLineColor();
  void setBackgroundColor();
  void applyLineSettings();
};

class OrthographicProjection : public IProjectionStrategy {
 public:
  explicit OrthographicProjection(s21::controller* controller)
      : IProjectionStrategy(controller) {}

  void applyProjection() override;
};

class PerspectiveProjection : public IProjectionStrategy {
 public:
  explicit PerspectiveProjection(s21::controller* controller)
      : IProjectionStrategy(controller) {}

  void applyProjection() override;
};

}  // namespace s21

#endif  // SRC_CONTROLLER_S21_STRATEGY_H_
