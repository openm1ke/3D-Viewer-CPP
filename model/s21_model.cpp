#include "s21_model.h"

void s21::model::clearData() {
  vertices_.clear();
  faces_.clear();
  minmax_ = {-1, 1, -1, 1, -1, 1};
  prj_ = {0, 0, 0, 0, 0, 0};
  vert_count_ = 0;
  face_count_ = 0;
}

void s21::model::setMinMax(std::array<float, 3> xyz) {
  minmax_[0] = std::min(minmax_[0], xyz[0]);
  minmax_[1] = std::max(minmax_[1], xyz[0]);
  minmax_[2] = std::min(minmax_[2], xyz[1]);
  minmax_[3] = std::max(minmax_[3], xyz[1]);
  minmax_[4] = std::min(minmax_[4], xyz[2]);
  minmax_[5] = std::max(minmax_[5], xyz[2]);
}

std::array<double, 6> &s21::model::getPrj() {
  double range =
      0.6 * std::max(std::max(minmax_[1] - minmax_[0], minmax_[3] - minmax_[2]),
                     minmax_[5] - minmax_[4]);
  double fov = 60.0 * M_PI / 180.0;
  double nearest = 3 * (minmax_[3] / (2.0 * tan((fov / 2.0))));
  double cX = (minmax_[1] + minmax_[0]) / 2.0;
  double cY = (minmax_[3] + minmax_[2]) / 2.0;
  prj_ = {cX - range, cX + range, cY - range, cY + range, nearest, 3000};
  return prj_;
}

int s21::model::getRot(char axis) { return rotation_[axis]; }

void s21::model::setRot(int value, char axis) { rotation_[axis] = value; }

int s21::model::getPos(char axis) { return position_[axis]; }

void s21::model::setPos(int value, char axis) { position_[axis] = value; }

void s21::model::rotateObj(int value, char axis) {
  double angle = (double)value / 180 * M_PI;
  switch (axis) {
    case 'x':
      for (unsigned int i = 0; i < vertices_.size(); i += 3) {
        float y = vertices_[i + 1];
        float z = vertices_[i + 2];
        vertices_[i + 1] = y * cos(angle) - z * sin(angle);
        vertices_[i + 2] = y * sin(angle) + z * cos(angle);
      }
      break;
    case 'y':
      for (unsigned int i = 0; i < vertices_.size(); i += 3) {
        float x = vertices_[i];
        float z = vertices_[i + 2];
        vertices_[i] = x * cos(angle) + z * sin(angle);
        vertices_[i + 2] = -x * sin(angle) + z * cos(angle);
      }
      break;
    case 'z':
      for (unsigned int i = 0; i < vertices_.size(); i += 3) {
        float x = vertices_[i];
        float y = vertices_[i + 1];
        vertices_[i] = x * cos(angle) - y * sin(angle);
        vertices_[i + 1] = x * sin(angle) + y * cos(angle);
      }
      break;
  }
  setRot(value + getRot(axis), axis);
}

void s21::model::moveObj(int value, char axis) {
  switch (axis) {
    case 'x':
      for (unsigned int i = 0; i < vertices_.size(); i += 3) {
        vertices_[i] += value;
      }
      break;
    case 'y':
      for (unsigned int i = 0; i < vertices_.size(); i += 3) {
        vertices_[i + 1] += value;
      }
      break;
    case 'z':
      for (unsigned int i = 0; i < vertices_.size(); i += 3) {
        vertices_[i + 2] += value;
      }
      break;
  }
  setPos(value + getPos(axis), axis);
}

void s21::model::parseObjFile(const std::string &filename) {
  std::ifstream objFile(filename);

  if (!objFile.is_open()) {
    std::cerr << "Не удалось открыть файл: " << filename << std::endl;
    return;
  }

  std::string line;

  while (std::getline(objFile, line)) {
    std::istringstream iss(line);
    std::string token;

    iss >> token;

    if (token == "v") {
      std::array<float, 3> vertex;
      iss >> vertex[0] >> vertex[1] >> vertex[2];
      vertices_.push_back(vertex[0]);
      vertices_.push_back(vertex[1]);
      vertices_.push_back(vertex[2]);
      setMinMax(vertex);
      vert_count_++;
    } else if (token == "f") {
      std::vector<unsigned int> edge;
      while (iss >> token) {
        int vertexIndex = std::abs(std::stoi(token));
        edge.push_back(vertexIndex);
      }
      for (auto it = edge.begin(); it != edge.end(); it++) {
        faces_.push_back(*it - 1);
        if (it + 1 != edge.end())
          faces_.push_back(*(it + 1) - 1);
        else
          faces_.push_back(*(edge.begin()) - 1);
      }
      face_count_++;
    }
  }

  objFile.close();
}

int s21::model::getVertCount() { return vert_count_; }

int s21::model::getFaceCount() { return face_count_; }

std::vector<float> &s21::model::getVertices() { return vertices_; }

std::vector<unsigned int> &s21::model::getFaces() { return faces_; }

std::array<float, 6> s21::model::getMinMax() { return minmax_; }

void s21::model::setScale(int scale) {
  double new_scale = 1 + (double)scale / 100.0;
  for (unsigned int i = 0; i < vertices_.size(); i++) {
    vertices_[i] /= base_scale_;
    vertices_[i] *= new_scale;
  }
  base_scale_ = new_scale;
}

double s21::model::getScale() { return base_scale_; }

void s21::model::changeProjection(s21::Projection projection) {
  projection_ = static_cast<short>(projection);
}

int s21::model::getProjection() { return projection_; }

void s21::model::setLineWidth(int value) { line_width_ = value; }

int s21::model::getLineWidth() { return line_width_; }

int s21::model::getLineStyle() { return line_style_; }

void s21::model::setLineStyle(int value) { line_style_ = value; }

int s21::model::getPointSize() { return point_size_; }

void s21::model::setPointSize(int value) { point_size_ = value; }

void s21::model::setPointStyle(int value) { point_style_ = value; }

int s21::model::getPointStyle() { return point_style_; }

void s21::model::setBgColor(float r, float g, float b) {
  bg_color_['r'] = r;
  bg_color_['g'] = g;
  bg_color_['b'] = b;
  bg_color_['a'] = 1;
}

void s21::model::setLineColor(float r, float g, float b) {
  line_color_['r'] = r;
  line_color_['g'] = g;
  line_color_['b'] = b;
  line_color_['a'] = 1;
}

void s21::model::setPointColor(float r, float g, float b) {
  point_color_['r'] = r;
  point_color_['g'] = g;
  point_color_['b'] = b;
  line_color_['a'] = 1;
}

std::map<char, float> s21::model::getBgColor() { return bg_color_; }
std::map<char, float> s21::model::getLineColor() { return line_color_; }
std::map<char, float> s21::model::getPointColor() { return point_color_; }
