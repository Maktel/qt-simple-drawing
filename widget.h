#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets>

class Widget : public QWidget {
  Q_OBJECT
 public:
  explicit Widget(QWidget* parent = 0);
  virtual ~Widget();

 private:
  void addImage(QString path);
  void addLabel(QString text);
  void createChildElements();
};

#endif  // WIDGET_H
