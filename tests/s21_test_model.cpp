#include <gtest/gtest.h>

#include <array>

#include "../model/s21_model.h"

TEST(Parser, parse1) {
  s21::model& model = s21::model::getInstance();
  model.parseObjFile("./obj/cube.obj");
  EXPECT_EQ(model.getFaceCount(), 12);
  EXPECT_EQ(model.getVertCount(), 8);
  model.clearData();
  EXPECT_EQ(model.getFaceCount(), 0);
  EXPECT_EQ(model.getVertCount(), 0);
}

TEST(Parser, parse2) {
  s21::model& model = s21::model::getInstance();
  model.parseObjFile("./obj/cube.obj");
  std::array<float, 6> arr = {-1.000000, 1.000000,  -1.000000,
                              1.000000,  -1.000000, 1.000001};
  EXPECT_EQ(model.getMinMax(), arr);
  model.clearData();
}

TEST(Parser, parse3) {
  s21::model& model = s21::model::getInstance();
  model.parseObjFile("./obj/cube.obj");
  std::array<double, 6> prj = {-1.2, 1.2, -1.2, 1.2, 2.59808, 3000.0};
  std::array<double, 6> prj2 = model.getPrj();
  EXPECT_NEAR(prj2[0], prj[0], 1e-5);
  EXPECT_NEAR(prj2[1], prj[1], 1e-5);
  EXPECT_NEAR(prj2[2], prj[2], 1e-5);
  EXPECT_NEAR(prj2[3], prj[3], 1e-5);
  EXPECT_NEAR(prj2[4], prj[4], 1e-5);
  EXPECT_NEAR(prj2[5], prj[5], 1e-5);
  model.clearData();
}

TEST(Parser, parse4) {
  s21::model& model = s21::model::getInstance();
  model.parseObjFile("./obj/cube.obj");
  model.rotateObj(45, 'x');
  model.rotateObj(45, 'y');
  model.rotateObj(45, 'z');
  auto vert = model.getVertices();
  auto face = model.getFaces();
  std::vector<float> expect_vert = {
      -0.207107, -0.207107, -1.70711,  1.5,      -0.5,     -0.707107,
      0.5,       -1.5,      0.707107,  -1.20711, -1.20711, -0.292893,
      -0.499999, 1.5,       -0.707106, 1.20711,  1.20711,  0.292894,
      0.207107,  0.207107,  1.70711,   -1.5,     0.5,      0.707107};
  std::vector<unsigned int> expect_face = {
      1, 2, 2, 3, 3, 1, 7, 6, 6, 5, 5, 7, 4, 5, 5, 1, 1, 4, 5, 6, 6, 2, 2, 5,
      2, 6, 6, 7, 7, 2, 0, 3, 3, 7, 7, 0, 0, 1, 1, 3, 3, 0, 4, 7, 7, 5, 5, 4,
      0, 4, 4, 1, 1, 0, 1, 5, 5, 2, 2, 1, 3, 2, 2, 7, 7, 3, 4, 0, 0, 7, 7, 4};
  for (unsigned int i = 0; i < vert.size(); i += 3) {
    EXPECT_NEAR(vert[i], expect_vert[i], 1e-5);
    EXPECT_NEAR(vert[i + 1], expect_vert[i + 1], 1e-5);
    EXPECT_NEAR(vert[i + 2], expect_vert[i + 2], 1e-5);
  }

  for (unsigned int i = 0; i < face.size(); i += 1) {
    EXPECT_EQ(face[i], expect_face[i]);
  }

  model.clearData();
}

TEST(Parser, parse5) {
  s21::model& model = s21::model::getInstance();
  model.parseObjFile("./obj/cube.obj");
  model.moveObj(2, 'x');
  model.moveObj(2, 'y');
  model.moveObj(2, 'z');
  auto vert = model.getVertices();
  std::vector<float> expect_vert = {
      3, 1, 1, 3, 1, 3, 1, 1, 3, 1, 1, 1, 3, 3, 1, 3, 3, 3, 1, 3, 3, 1, 3, 1,
      1, 2, 2, 3, 3, 1, 7, 6, 6, 5, 5, 7, 4, 5, 5, 1, 1, 4, 5, 6, 6, 2, 2, 5,
      2, 6, 6, 7, 7, 2, 0, 3, 3, 7, 7, 0, 0, 1, 1, 3, 3, 0, 4, 7, 7, 5, 5, 4,
      0, 4, 4, 1, 1, 0, 1, 5, 5, 2, 2, 1, 3, 2, 2, 7, 7, 3, 4, 0, 0, 7, 7, 4};
  for (unsigned int i = 0; i < vert.size(); i += 3) {
    EXPECT_NEAR(vert[i], expect_vert[i], 1e-5);
    EXPECT_NEAR(vert[i + 1], expect_vert[i + 1], 1e-5);
    EXPECT_NEAR(vert[i + 2], expect_vert[i + 2], 1e-5);
  }
  model.clearData();
}

TEST(Parser, parse6) {
  s21::model& model = s21::model::getInstance();
  model.parseObjFile("./obj/cube.obj");
  EXPECT_DOUBLE_EQ(model.getScale(), 1.0);
  model.setScale(20);
  auto vert = model.getVertices();
  std::vector<float> expect_vert = {
      1.2, -1.2, -1.2, 1.2, -1.2, 1.2, -1.2, -1.2, 1.2, -1.2, -1.2, -1.2,
      1.2, 1.2,  -1.2, 1.2, 1.2,  1.2, -1.2, 1.2,  1.2, -1.2, 1.2,  -1.2};
  for (unsigned int i = 0; i < vert.size(); i += 3) {
    EXPECT_NEAR(vert[i], expect_vert[i], 1e-5);
    EXPECT_NEAR(vert[i + 1], expect_vert[i + 1], 1e-5);
    EXPECT_NEAR(vert[i + 2], expect_vert[i + 2], 1e-5);
  }
  model.clearData();
}

TEST(Parser, parse7) {
  s21::model& model = s21::model::getInstance();
  model.parseObjFile("./obj/cube.obj");
  model.setBgColor(255, 255, 255);
  model.setLineColor(0, 0, 0);
  model.setPointColor(255, 0, 0);
  model.setLineWidth(2);
  model.setLineStyle(0);
  model.setPointSize(3);
  model.setPointStyle(0);
  model.changeProjection(s21::Projection::PERSPECTIVE);
  auto get_bg_color = model.getBgColor();
  auto get_line_color = model.getLineColor();
  auto get_point_color = model.getPointColor();
  EXPECT_FLOAT_EQ(get_bg_color['r'], 255);
  EXPECT_FLOAT_EQ(get_bg_color['g'], 255);
  EXPECT_FLOAT_EQ(get_bg_color['b'], 255);
  EXPECT_FLOAT_EQ(get_line_color['r'], 0);
  EXPECT_FLOAT_EQ(get_line_color['g'], 0);
  EXPECT_FLOAT_EQ(get_line_color['b'], 0);
  EXPECT_FLOAT_EQ(get_point_color['r'], 255);
  EXPECT_FLOAT_EQ(get_point_color['g'], 0);
  EXPECT_FLOAT_EQ(get_point_color['b'], 0);
  EXPECT_EQ(model.getLineWidth(), 2);
  EXPECT_EQ(model.getLineStyle(), 0);
  EXPECT_EQ(model.getPointSize(), 3);
  EXPECT_EQ(model.getPointStyle(), 0);
  EXPECT_EQ(model.getProjection(), 1);
  model.clearData();
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
