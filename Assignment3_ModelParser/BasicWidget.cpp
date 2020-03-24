#include "BasicWidget.h"

#include "ObjReader.h"

#include <iostream>

//////////////////////////////////////////////////////////////////////
// Publics
#if USE_QT_OPENGL
BasicWidget::BasicWidget(QWidget *parent) : QOpenGLWidget(parent), vbo_(QOpenGLBuffer::VertexBuffer), cbo_(QOpenGLBuffer::VertexBuffer), ibo_(QOpenGLBuffer::IndexBuffer)
#else
BasicWidget::BasicWidget(QWidget *parent) : QOpenGLWidget(parent)
#endif
{
  setFocusPolicy(Qt::StrongFocus);
}

BasicWidget::~BasicWidget()
{
#if USE_QT_OPENGL
  vbo_.release();
  vbo_.destroy();
  ibo_.release();
  ibo_.destroy();
  cbo_.release();
  cbo_.destroy();
  vao_.release();
  vao_.destroy();
#else
  glDeleteProgram(shaderID_);
  glDeleteBuffers(1, &vboID_);
  glDeleteBuffers(1, &cboID_);
  glDeleteBuffers(1, &iboID_);
#endif
}

//////////////////////////////////////////////////////////////////////
// Privates
QString BasicWidget::vertexShaderString() const
{
  QString str =
      "#version 330\n"
      "layout(location = 0) in vec3 position;\n"
      "layout(location = 1) in vec4 color;\n"
      "out vec4 vertColor;\n"
      "void main()\n"
      "{\n"
      "  gl_Position = vec4(position, 1.0);\n"
      "  vertColor = vec4(1.0,1.0,1.0, 1.0);;\n"
      "}\n";
  return str;
}

QString BasicWidget::fragmentShaderString() const
{
  QString str =
      "#version 330\n"
      "in vec4 vertColor;\n"
      "out vec4 color;\n"
      "void main()\n"
      "{\n"
      "  color = vertColor;\n"
      "}\n";
  return str;
}

void BasicWidget::setIndicesAndVertices()
{
  std::vector<float> vertices = obj.getVertices();
  float *verticesArr = &vertices[0];

  std::cout << "\n ver num: " << vertices.size() << "\n";

  std::vector<unsigned int> faces = obj.getFaces();
  unsigned int *facesArr = &faces[0];

std::cout << "\n faces num: " << faces.size() << "\n";
  vbo_.setUsagePattern(QOpenGLBuffer::StaticDraw);
  vbo_.create();
  vbo_.bind();
  vbo_.allocate(verticesArr, vertices.size() * sizeof(GL_FLOAT));

  ibo_.setUsagePattern(QOpenGLBuffer::StaticDraw);
  ibo_.create();
  ibo_.bind();
  ibo_.allocate(facesArr, faces.size() * sizeof(GL_INT));
}

#if USE_QT_OPENGL
void BasicWidget::createShader()
{
  QOpenGLShader vert(QOpenGLShader::Vertex);
  vert.compileSourceCode(vertexShaderString());
  QOpenGLShader frag(QOpenGLShader::Fragment);
  frag.compileSourceCode(fragmentShaderString());
  bool ok = shaderProgram_.addShader(&vert);
  if (!ok)
  {
    qDebug() << shaderProgram_.log();
  }
  ok = shaderProgram_.addShader(&frag);
  if (!ok)
  {
    qDebug() << shaderProgram_.log();
  }
  ok = shaderProgram_.link();
  if (!ok)
  {
    qDebug() << shaderProgram_.log();
  }
}
#else
void BasicWidget::createShader()
{
  unsigned int prog = glCreateProgram();
  unsigned int vert = compileShader(GL_VERTEX_SHADER, vertexShaderString());
  unsigned int frag = compileShader(GL_FRAGMENT_SHADER, fragmentShaderString());
  glAttachShader(prog, vert);
  glAttachShader(prog, frag);
  glLinkProgram(prog);
  glValidateProgram(prog);

  // The shaders are build and ready to use.  We can now detach the individual shaders and destroy them
  glDetachShader(prog, vert);
  glDetachShader(prog, frag);
  glDeleteShader(vert);
  glDeleteShader(frag);

  // Assign here in case there are failures we need to bail on - This has not yet been implemented, though.
  shaderID_ = prog;
}

unsigned int BasicWidget::compileShader(unsigned int type, const QString &shaderSrc)
{
  unsigned int id = glCreateShader(type);
  // Make sure we can create the shader
  if (id == 0)
  {
    return 0;
  }
  QByteArray ba = shaderSrc.toLocal8Bit();
  const char *src = ba.data();
  // Set the source
  glShaderSource(id, 1, &src, nullptr);
  // Compile
  glCompileShader(id);
  // Retrieve the result of our compilation
  int result;
  glGetShaderiv(id, GL_COMPILE_STATUS, &result);
  if (result == GL_FALSE)
  {
    int length;
    glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
    char *errorMessages = new char[length]; // Could also use alloca here.
    glGetShaderInfoLog(id, length, &length, errorMessages);
    if (type == GL_VERTEX_SHADER)
    {
      qDebug() << "ERROR: GL_VERTEX_SHADER compilation failed!\n"
               << errorMessages << "\n";
    }
    else if (type == GL_FRAGMENT_SHADER)
    {
      qDebug() << "ERROR: GL_FRAGMENT_SHADER compilation failed!\n"
               << errorMessages << "\n";
    }
    // Reclaim our memory
    delete[] errorMessages;
    // Delete our broken shader
    glDeleteShader(id);
    return 0;
  }

  return id;
}
#endif
///////////////////////////////////////////////////////////////////////
// Protected
void BasicWidget::keyReleaseEvent(QKeyEvent *keyEvent)
{
  // TODO
  // Handle key events here.
  if (keyEvent->key() == Qt::Key_1)
  {
    qDebug() << "1 Pressed";

    BasicWidget::setShapeType(1);

    BasicWidget::setIndicesAndVertices();

    update(); // We call update after we handle a key press to trigger a redraw when we are ready
  }

  else if (keyEvent->key() == Qt::Key_2)
  {
    qDebug() << "2  Pressed";
    BasicWidget::setShapeType(2);
    BasicWidget::setIndicesAndVertices();

    update(); // We call update after we handle a key press to trigger a redraw when we are ready
  }
  else if (keyEvent->key() == Qt::Key_Q)
  {
    exit(1);
  }
  else if (keyEvent->key() == Qt::Key_W)
  {
    qDebug() << "W Pressed";
    if (frameType == 1)
    {
      BasicWidget::setWireframe(2);
    }
    else
    {
      BasicWidget::setWireframe(1);
    }
    update(); // We call update after we handle a key press to trigger a redraw when we are ready
  }

  else
  {
    qDebug() << "You Pressed an unsupported Key!";
  }
  // ENDTODO
}
void BasicWidget::initializeGL()
{
  makeCurrent();
  initializeOpenGLFunctions();

  QOpenGLContext *curContext = this->context();
  qDebug() << "[BasicWidget]::initializeGL() -- Context Information:";
  qDebug() << "  Context Valid: " << std::string(curContext->isValid() ? "true" : "false").c_str();
  qDebug() << "  GL Version Used: " << curContext->format().majorVersion() << "." << curContext->format().minorVersion();
  qDebug() << "  Vendor: " << reinterpret_cast<const char *>(glGetString(GL_VENDOR));
  qDebug() << "  Renderer: " << reinterpret_cast<const char *>(glGetString(GL_RENDERER));
  qDebug() << "  Version: " << reinterpret_cast<const char *>(glGetString(GL_VERSION));
  qDebug() << "  GLSL Version: " << reinterpret_cast<const char *>(glGetString(GL_SHADING_LANGUAGE_VERSION));

  // Set up our shaders.
  createShader();

  // Set up our buffers and our vao

  // Temporary bind of our shader.
  shaderProgram_.bind();
  // Create and prepare a vbo
  BasicWidget::setIndicesAndVertices();

  // Create a VAO to keep track of things for us.
  vao_.create();
  vao_.bind();
  vbo_.bind();

  shaderProgram_.enableAttributeArray(0);
  shaderProgram_.setAttributeBuffer(0, GL_FLOAT, 0, 3);
  cbo_.bind();
  shaderProgram_.enableAttributeArray(1);
  shaderProgram_.setAttributeBuffer(1, GL_FLOAT, 0, 4);
  ibo_.bind();
  // Releae the vao THEN the vbo
  vao_.release();
  shaderProgram_.release();

  glViewport(0, 0, width(), height());
}

void BasicWidget::resizeGL(int w, int h)
{
  glViewport(0, 0, w, h);
}

void BasicWidget::paintGL()
{
  glDisable(GL_DEPTH_TEST);
  glDisable(GL_CULL_FACE);

  glDisableVertexAttribArray(1);

  glClearColor(0, 0, 0, 0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  shaderProgram_.bind();
  vao_.bind();

  if (frameType == 1)
  {
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  }

  if (frameType == 2)
  {
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  }

  glDrawElements(GL_TRIANGLES, obj.getFaces().size() * 3, GL_UNSIGNED_INT, 0);

  // ENDTODO
  vao_.release();
  shaderProgram_.release();
}