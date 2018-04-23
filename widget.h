#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets>

class Widget : public QWidget {
  Q_OBJECT
 public:
  explicit Widget(QWidget* parent = 0);
  virtual ~Widget();

 public slots:
  void animate();

 protected:
  void paintEvent(QPaintEvent*) override;

 private:
  void addImage(QString path);
  void addLabel(QString text);
  void createChildElements();
  void drawOnImage();

  void createTimer();
  QTimer* timer;

  QImage* image;
};

#endif  // WIDGET_H
