#include "widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent) {
  setMaximumSize(QDesktopWidget().availableGeometry(this).size() * 0.9);

  QLayout* widgetLayout = new QVBoxLayout();
  setLayout(widgetLayout);

  createChildElements();
}

Widget::~Widget() {}

void Widget::createChildElements() {
  addLabel("Hello dankness my old friend");
  addImage("../example5.png");
  addLabel("I've come to talk with you again");
}

void Widget::addLabel(QString text) {
  QLabel* label = new QLabel(text, this);
  layout()->addWidget(label);
}

void Widget::addImage(QString path) {
  QPixmap pixmap;
  if (!pixmap.load(path)) {
    qDebug() << "File not loaded properly. Check if path is valid";
    return;
  }

  if (pixmap.width() > maximumWidth() || pixmap.height() > maximumHeight()) {
    pixmap = pixmap.scaled(maximumSize(), Qt::KeepAspectRatio);
  }

  QLabel* label = new QLabel(this);
  label->setPixmap(pixmap);

  layout()->addWidget(label);
}
