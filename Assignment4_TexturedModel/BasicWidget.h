#pragma once

#include <QtGui>
#include <QtWidgets>
#include <QtOpenGL>
#include <string>

#include "Renderable.h"
#include "ObjReader.h"

/**
 * This is just a basic OpenGL widget that will allow a change of background color.
 */
class BasicWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
  Q_OBJECT

private:
  QMatrix4x4 model_;
  QMatrix4x4 view_;
  QMatrix4x4 projection_;

  // file path
  std::string filePath;

  // frame type. 1 = textured, 2 = wireframe
  unsigned int frameType = 1;
  
  QElapsedTimer frameTimer_;

  QVector<Renderable*> renderables_;

  QOpenGLDebugLogger logger_;

protected:
  // Required interaction overrides
  void keyReleaseEvent(QKeyEvent* keyEvent) override;

  // Required overrides form QOpenGLWidget
  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;
  
public:
  BasicWidget(QWidget* parent=nullptr);
  virtual ~BasicWidget();
  
  // Make sure we have some size that makes sense.
  QSize sizeHint() const {return QSize(800,600);}

  void setWireframe(int type)
  {
      // if type = 1 then solid, if type = 2, then wireframe
      frameType = type;
  }


};