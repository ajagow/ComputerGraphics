#include "BasicWidget.h"
#include <iostream>

//////////////////////////////////////////////////////////////////////
// Publics
BasicWidget::BasicWidget(QWidget *parent) : QOpenGLWidget(parent), logger_(this)
{
  setFocusPolicy(Qt::StrongFocus);
}

BasicWidget::~BasicWidget()
{
  for (auto renderable : renderables_)
  {
    delete renderable;
  }
  renderables_.clear();
}

//////////////////////////////////////////////////////////////////////
// Privates
///////////////////////////////////////////////////////////////////////
// Protected
void BasicWidget::keyReleaseEvent(QKeyEvent *keyEvent)
{
  // Handle key events here.
  if (keyEvent->key() == Qt::Key_Left)
  {
    qDebug() << "Left Arrow Pressed";
    update(); // We call update after we handle a key press to trigger a redraw when we are ready
  }
  else if (keyEvent->key() == Qt::Key_Right)
  {
    qDebug() << "Right Arrow Pressed";
    update(); // We call update after we handle a key press to trigger a redraw when we are ready
  }
  else
  {
    qDebug() << "You Pressed an unsupported Key!";
  }
}
void BasicWidget::initializeGL()
{
  makeCurrent();
  initializeOpenGLFunctions();

  qDebug() << QDir::currentPath();
  // QString texFile = "../objects/house/house_diffuse.ppm";
  // std::cout<< "textfile: " << "../objects/house/house_diffuse.jpg" << "\n";
  // QString texFile = "../objects/windmill/windmill_diffuse.ppm";
  // QString texFile = "../objects/capsule/capsule0.ppm";
  QString texFile = "../objects/chapel/chapel_diffuse.ppm";
  // QString texFile = "../objects/dice.png";
  QVector<QVector3D> pos;
  QVector<QVector3D> pos2;
  QVector<QVector3D> norm;
  QVector<QVector2D> texCoord;
  QVector<unsigned int> idx;
  pos << QVector3D(-0.8, -0.8, 0.0);
  pos << QVector3D(0.8, -0.8, 0.0);
  pos << QVector3D(-0.8, 0.8, 0.0);
  pos << QVector3D(0.8, 0.8, 0.0);

  // We don't actually use the normals right now, but this will be useful later!
  norm << QVector3D(0.0, 0.0, 1.0);
  norm << QVector3D(0.0, 0.0, 1.0);
  norm << QVector3D(0.0, 0.0, 1.0);
  norm << QVector3D(0.0, 0.0, 1.0);
  // TODO:  Make sure to add texture coordinates to pass into the initialization of our renderable

  texCoord << QVector2D(0.0, 0.0); // top left
  texCoord << QVector2D(1.0, 0.0); // bottom left
  texCoord << QVector2D(0.0, 1.0);
  texCoord << QVector2D(1.0, 1.0);

  idx << 0 << 1 << 2 << 2 << 1 << 3;

  Renderable *ren = new Renderable();
  ren->init(pos, norm, texCoord, idx, texFile);

  // QMatrix4x4 matrix;
  // matrix.setToIdentity();
  // matrix.ortho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);
  // ren2->setModelMatrix(matrix);

  renderables_.push_back(ren);
  glViewport(0, 0, width(), height());
  // frameTimer_.start();
}

void BasicWidget::resizeGL(int w, int h)
{
  if (!logger_.isLogging())
  {
    logger_.initialize();
    // Setup the logger for real-time messaging
    connect(&logger_, &QOpenGLDebugLogger::messageLogged, [=]() {
      const QList<QOpenGLDebugMessage> messages = logger_.loggedMessages();
      for (auto msg : messages)
      {
        qDebug() << msg;
      }
    });
    logger_.startLogging();
  }
  glViewport(0, 0, w, h);
  view_.setToIdentity();
  view_.lookAt(QVector3D(-1.0f, 1.0f, 5.0f),
               QVector3D(0.0f, 1.0f, 0.0f),
               QVector3D(0.0f, 1.0f, 0.0f));
  projection_.setToIdentity();
  projection_.perspective(90.f, (float)w / (float)h, 0.001, 1000.0);
  glViewport(0, 0, w, h);
}

void BasicWidget::paintGL()
{
  // qint64 msSinceRestart = frameTimer_.restart();
  glDisable(GL_DEPTH_TEST);
  glDisable(GL_CULL_FACE);

  glClearColor(0.f, 0.f, 0.f, 1.f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  for (auto renderable : renderables_)
  {
    // renderable->update(msSinceRestart);
    renderable->draw(view_, projection_);
  }
  update();
}
