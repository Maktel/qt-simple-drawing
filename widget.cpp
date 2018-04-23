#include "widget.h"
#include <cstdlib>

Widget::Widget(QWidget* parent) : QWidget(parent) {
  setMaximumSize(QDesktopWidget().availableGeometry(this).size() * 0.9);
  resize(maximumSize());

  QLayout* widgetLayout = new QVBoxLayout();
  setLayout(widgetLayout);

  //  createChildElements();

  image = new QImage(maximumWidth(), maximumHeight(), QImage::Format_ARGB32);

  qDebug() << "width: " << maximumWidth();
  qDebug() << "height: " << maximumHeight();

  drawOnImage();

  createTimer();
}

Widget::~Widget() { delete image; }

void Widget::paintEvent(QPaintEvent*) {
  QPainter painter(this);
  painter.drawImage(0, 0, *image);
}

void Widget::createChildElements() {
  addLabel("Hello dankness my old friend");
  addImage("../example5.png");
  addLabel("I've come to talk with you again");
}

void Widget::drawOnImage() {
  const int red = rand() % 256;
  const int green = rand() % 256;
  const int blue = rand() % 256;

  image->fill(QColor(red, green, blue));
  QPainter painter(image);

  QPen pen(Qt::SolidLine);
  QColor color(255, 255, 255);
  pen.setColor(color);
  painter.setPen(pen);


  QVector<QPoint> points;
  const int offset = 5;
  //  points.push_back(QPoint(offset, offset));
  //  points.push_back(QPoint(image->width() - offset, offset));
  //  points.push_back(QPoint(image->width() - offset, image->height() -
  //  offset));
  //  points.push_back(QPoint(offset, image->height() - offset));
  points.push_back(QPoint(100, 100));
  points.push_back(QPoint(150, 100));
  points.push_back(QPoint(180, 120));
  points.push_back(QPoint(250, 250));
  points.push_back(QPoint(400, 450));
  points.push_back(QPoint(120, 180));

  //  for (const auto& point : points) {
  //    qDebug() << point;
  //  }

  // 1. petla for wyglada tak samo jak w javie
  // 2. points.size();
  // 3. points[0];
  // 4. painter.drawLine(QPoint, QPoint);

  for (int i = 0; i < points.size() - 1; ++i) {
    painter.drawLine(points[i], points[i + 1]);
  }
  painter.drawLine(points[points.size() - 1], points[0]);

  image->save("../image.png");
}

void Widget::createTimer() {
  timer = new QTimer(this);
  QObject::connect(timer, SIGNAL(timeout()), this, SLOT(animate()));
  timer->start(1000);  // time specified in ms
}

void Widget::animate() {
  drawOnImage();
  update();
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
