#ifndef HELPER_H
#define HELPER_H

#include <QGraphicsPixmapItem>
#include <QImage>
#include <QObject>
#include <QPixmap>

extern QGraphicsPixmapItem* p;

class Helper : public QObject {
  Q_OBJECT

 public:
  Helper() {}

 public slots:
  void setValue(QImage i);

 signals:
  void valueChanged(QImage i);

  /* private: */
  /*  int m_value; */
};

#endif /* end of include guard: HELPER_H */

