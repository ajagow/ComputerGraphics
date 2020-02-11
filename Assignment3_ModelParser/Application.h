/**
 * The primary application code.
 */

#include <QtGui>
#include <QtCore>
#include <QtWidgets>


#ifndef Application_H
#define Application_H

class Application : public QMainWindow
{
  Q_OBJECT

public:
  Application(QWidget* parent=0);
  virtual ~Application();
  
signals:

public slots:

private:
  void buildGui();
};

#endif
