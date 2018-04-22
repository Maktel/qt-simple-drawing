#include "mainwindow.h"

#include <QtWidgets>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
  QWidget* widget = new QWidget(this);
  setCentralWidget(widget);

  widget->setMaximumSize(QDesktopWidget().availableGeometry(this).size() * 0.9);

  QLayout* layout = new QVBoxLayout();
  widget->setLayout(layout);

  addLabel("Hello dankness my old friend");
  addImage();
  addLabel("I've come to talk with you again");
}

MainWindow::~MainWindow() {}

void MainWindow::addLabel(QString text) {
  QLabel* label = new QLabel(text, centralWidget());
  centralWidget()->layout()->addWidget(label);
}

void MainWindow::addImage() {
  QWidget* widget = centralWidget();

  QLabel* label = new QLabel(widget);

  QPixmap pixmap;
  if (!pixmap.load("../example.png")) {
    return;
  }

  if (pixmap.width() > widget->maximumWidth() ||
      pixmap.height() > widget->maximumHeight()) {
    pixmap = pixmap.scaled(widget->maximumSize(), Qt::KeepAspectRatio);
  }

  label->setPixmap(pixmap);

  widget->layout()->addWidget(label);
}
