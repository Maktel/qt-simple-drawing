#include <QApplication>
#include "mainwindow.h"

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  MainWindow w;

  //  w.setFixedSize(800, 800);

  w.show();

  return a.exec();
}