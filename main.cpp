#include <QApplication>

#include "controller/s21_controller.h"
#include "model/s21_model.h"
#include "view/s21_view.h"

int main(int argc, char* argv[]) {
  QCoreApplication::setOrganizationName(s21::ORGANIZATION_NAME);
  QCoreApplication::setOrganizationDomain(s21::ORGANIZATION_DOMAIN);
  QCoreApplication::setApplicationName(s21::APPLICATION_NAME);
  QApplication a(argc, argv);

  s21::model& model = s21::model::getInstance();
  s21::controller controller(&model);
  s21::view view(&controller);
  view.show();
  return a.exec();
}
