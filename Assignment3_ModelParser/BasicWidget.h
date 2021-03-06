#pragma once

#include <QtGui>
#include <QtWidgets>
#include <QtOpenGL>

#include "ObjReader.h"

// TODO:  This macro should work when both true AND false
#define USE_QT_OPENGL true
// ENDTODO

/**
 * This is just a basic OpenGL widget that will allow a change of background color.
 */
class BasicWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
  Q_OBJECT

private:
  QString vertexShaderString() const;
  QString fragmentShaderString() const;
  void createShader();
  QOpenGLVertexArrayObject vao_;
  unsigned int objectType = 1;
  unsigned int frameType = 1;
  ObjReader bunny = ObjReader("../objects/bunny_centered.obj");
  ObjReader monkey = ObjReader("../objects/monkey_centered.obj");
  ObjReader obj = bunny;
  void setIndicesAndVertices();

protected:
  // Required interaction overrides
  void keyReleaseEvent(QKeyEvent *keyEvent) override;

  // Required overrides form QOpenGLWidget
  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;

  QOpenGLBuffer vbo_;
  QOpenGLBuffer ibo_;
  QOpenGLBuffer cbo_;
  QOpenGLShaderProgram shaderProgram_;

public:
  BasicWidget(QWidget *parent = nullptr);
  virtual ~BasicWidget();

  // Make sure we have some size that makes sense.
  QSize sizeHint() const { return QSize(800, 600); }

  void setShapeType(int type)
  {
    // if type = 1 then bunny, if type = 2, then monkey
    if (type == 1)
    {
      obj = bunny;
      objectType = type;
    }

    else
    {
      objectType = type;
      obj = monkey;
    }
  }

  void setWireframe(int type)
  {
    // if type = 1 then solid, if type = 2, then wireframe
    frameType = type;
  }
};