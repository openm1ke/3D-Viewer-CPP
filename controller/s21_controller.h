#ifndef SRC_CONTROLLER_S21_CONTROLLER_H_
#define SRC_CONTROLLER_S21_CONTROLLER_H_

#include <QMouseEvent>

#include "../model/s21_model.h"

namespace s21 {
enum class Projection;
class opengl;

class controller : public QObject {
  Q_OBJECT
 signals:
  void change_rotation(int rotation, char direction);

 public slots:
  void handleRotationSliderValueChanged(int value, char dir);
  void handleMoveSliderValueChanged(int value, char dir);
  void handleScaleSliderValueChanged(int value);

 private:
  s21::model *model_;
  s21::opengl *opengl_;
  QPoint lastPos;

 public:
  explicit controller(s21::model *m) : model_(m) {}
  void startParsing(const std::string &filename);
  std::vector<float> &getVertices();
  std::vector<unsigned int> &getFaces();
  std::array<double, 6> &getPrj();
  std::string getObjInfo();
  int getRot(char axis);
  void setRot(int value, char axis);
  int getPos(char axis);
  void setPos(int value, char axis);
  double getScale();
  void setScale(int scale);
  void clear();
  void setOpenGl(s21::opengl *opengl);
  void rotateObj(int value, char axis);
  void rotateViewer(int value, char axis);
  void moveObj(int value, char axis);
  void moveViewer(int value, char axis);
  void changeProjection(s21::Projection projection);
  s21::Projection getProjection();
  void setLineWidth(int value);
  int getLineWidth();
  void setLineStyle(int index);
  int getLineStyle();
  int getPointSize();
  void setPointSize(int value);
  int getVertCount();
  void setPointStyle(int value);
  int getPointStyle();
  void setBgColor(QColor color);
  void setLineColor(QColor color);
  void setPointColor(QColor color);
  std::map<char, float> getBgColor();
  std::map<char, float> getLineColor();
  std::map<char, float> getPointColor();

  void mousePressed(QMouseEvent *event);
  void mouseMoved(QMouseEvent *event);
};
}  // namespace s21

#endif  // SRC_CONTROLLER_S21_CONTROLLER_H_
