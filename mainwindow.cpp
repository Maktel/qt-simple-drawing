#include "mainwindow.h"
#include "widget.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
  Widget* widget = new Widget(this);
  setCentralWidget(widget);

  setMaximumSize(QDesktopWidget().availableGeometry(this).size() * 0.9);
  resize(maximumSize());
}

MainWindow::~MainWindow() {}
