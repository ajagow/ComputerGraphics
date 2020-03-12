// /**
//  * Support code written by Erik W. Anderson
//  */

#include <QtCore>
#include <QtGui>
#include <QtOpenGL>
#include <map> 

// Lab application
#include "App.h"

#include "ObjReader.h"
#include <iostream>

static bool enableGLDebug = true;

int main(int argc, char **argv)
{
  QApplication a(argc, argv);
  QString appDir = a.applicationDirPath();
  QDir::setCurrent(appDir);

  QSurfaceFormat fmt;
  fmt.setDepthBufferSize(24);
  fmt.setStencilBufferSize(8);
  fmt.setVersion(3, 3);
  fmt.setProfile(QSurfaceFormat::CoreProfile);
  if (enableGLDebug)
  {
    fmt.setOption(QSurfaceFormat::DebugContext);
  }
  QSurfaceFormat::setDefaultFormat(fmt);

  App app;
  app.show();

  // ObjReader house = ObjReader("../objects/house/house_obj.obj");

  // ObjReader::VertexData newVertex(-1, -1, -1, -0.57735, -0.57735);
  // ObjReader::VertexData newVertex2(-1, -1, 1, -0.57735, -0.57735);

  // bool isEqual = newVertex == newVertex2;
  // std::cout<<"hello: " << isEqual << "\n";


  // std::vector<ObjReader::VertexData> v = house.getVerticesAndTextures2();

  // std::map<ObjReader::VertexData, int> vals;

  // for (int i = 0; i < v.size(); i++)
  // {
  //   ObjReader::VertexData vector = v[i];
  //   vals.insert(std::pair<ObjReader::VertexData, int>(vector, i));
  // }



  //     try {
  //       int value = vals.at(newVertex2);
  //       std::cout << "Value of key \"" << value << std::endl;
  //       // TODO: Handle the element found.
  //   }
  //   catch (const std::out_of_range&) {
  //       std::cout << "Key \"" << "not found" << std::endl;

  //   }

  



  return QApplication::exec();
}
