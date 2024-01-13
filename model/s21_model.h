#ifndef SRC_MODEL_S21_MODEL_H_
#define SRC_MODEL_S21_MODEL_H_

#include <math.h>

#include <array>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

namespace s21 {

enum class Projection { ORTHOGRAPHIC, PERSPECTIVE };

class model {
 public:
  /**
   * Конструктор модели
   */
  static model &getInstance() {
    static model instance_;
    return instance_;
  }
  /*
   * Парсер файла с объектом
   */
  void parseObjFile(const std::string &filename);
  /**
   * Возвращает массив с вершинами
   */
  std::vector<float> &getVertices();
  /**
   * Возвращает массив с индексами вершин
   */
  std::vector<unsigned int> &getFaces();
  /**
   * Возвращает массив с параметрами проекции
   */
  std::array<double, 6> &getPrj();
  /**
   * Возвращает угол поворота по оси
   * @param axis - ось
   * @return угол
   */
  int getRot(char axis);
  /**
   * Устанавливает угол поворота по оси
   * @param value - угол
   * @param axis - ось
   */
  void setRot(int value, char axis);
  /**
   * Возвращает позицию по оси
   * @param axis - ось
   * @return позиция
   */
  int getPos(char axis);
  /**
   * Устанавливает позицию по оси
   * @param value - позиция
   * @param axis - ось
   */
  void setPos(int value, char axis);
  /**
   * Возвращает масштаб
   */
  double getScale();
  /**
   * Устанавливает масштаб
   */
  void setScale(int scale);
  /**
   * Возвращает минимальные и максимальные значения
   * @return std::array<float, 6>
   */
  std::array<float, 6> getMinMax();
  /**
   * Очищает данные
   */
  void clearData();
  /**
   * Поворачивает объект вокруг заданной оси
   * @param value - угол
   * @param axis - ось
   */
  void rotateObj(int value, char axis);
  /**
   * Перемещает объект в заданной позиции
   * @param value - позиция
   * @param axis - ось
   */
  void moveObj(int value, char axis);
  /**
   * Изменяет проекцию
   * @param projection - проекция
   */
  void changeProjection(s21::Projection projection);
  /**
   * Возвращает проекцию
   * @return s21::Projection
   * @see s21::Projection
   */
  int getProjection();
  /**
   * Возвращает количество вершин
   * @return int
   */
  int getVertCount();
  /**
   * Возвращает количество полигонов
   * @return int
   */
  int getFaceCount();
  /**
   * Возвращает ширину линии
   * @return int
   */
  int getLineWidth();
  /**
   * Устанавливает ширину линии
   * @param value - ширина
   */
  void setLineWidth(int value);
  /**
   * Возвращает стиль линии
   * @return int
   */
  int getLineStyle();
  /**
   * Устанавливает стиль линии
   * @param value - стиль
   */
  void setLineStyle(int index);
  /**
   * Возвращает размер точки
   * @return int
   */
  int getPointSize();
  /**
   * Устанавливает размер точки
   * @param value - размер
   */
  void setPointSize(int value);
  /**
   * Устанавливает стиль точки
   * @return int
   */
  void setPointStyle(int value);
  /**
   * Возвращает стиль точки
   * @return int
   */
  int getPointStyle();
  /**
   * Устанавливает цвет заднего фона
   * @return std::map<char, float>
   */
  void setBgColor(float r, float g, float b);
  /**
   * Устанавливает цвет линии
   * @return std::map<char, float>
   */
  void setLineColor(float r, float g, float b);
  /**
   * Устанавливает цвет точки
   * @return std::map<char, float>
   */
  void setPointColor(float r, float g, float b);
  /**
   * Возвращает цвет заднего фона
   * @return std::map<char, float>
   */
  std::map<char, float> getBgColor();
  /**
   * Возвращает цвет линии
   * @return std::map<char, float>
   */
  std::map<char, float> getLineColor();
  /**
   *  Возвращает цвет точки
   *  @return std::map<char, float>
   */
  std::map<char, float> getPointColor();

 private:
  model() {}
  model(const model &);
  model &operator=(model &);
  std::vector<float> vertices_;
  std::vector<unsigned int> faces_;
  int vert_count_ = 0;
  int face_count_ = 0;
  int line_width_ = 1;
  int line_style_ = 0;
  int point_size_ = 1;
  int point_style_ = 0;
  std::map<char, float> bg_color_ = {{'r', 0}, {'g', 0}, {'b', 0}, {'a', 0}};
  std::map<char, float> line_color_ = {{'r', 0}, {'g', 0}, {'b', 0}, {'a', 0}};
  std::map<char, float> point_color_ = {{'r', 0}, {'g', 0}, {'b', 0}, {'a', 0}};
  std::array<float, 6> minmax_ = {-1, 1, -1, 1, -1, 1};
  std::array<double, 6> prj_ = {0, 0, 0, 0, 0, 0};
  std::map<char, int> rotation_ = {{'x', 0}, {'y', 0}, {'z', 0}};
  std::map<char, int> position_ = {{'x', 0}, {'y', 0}, {'z', 0}};
  double base_scale_ = 1.0;
  short projection_ = 0;

  void setMinMax(std::array<float, 3> xyz);
};
}  // namespace s21

#endif  // SRC_MODEL_S21_MODEL_H_
