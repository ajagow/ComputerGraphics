/**
 * The primary application code.
 */

#include <QtGui>
#include <QtCore>
#include <QtWidgets>
#include <string>

class App : public QMainWindow
{
  Q_OBJECT

public:
  App(std::string filePath, QWidget* parent=0);
  virtual ~App();
  
signals:

public slots:

private:
  void buildGui(std::string filePath);
};
