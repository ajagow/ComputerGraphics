#include "App.h"

#include "BasicWidget.h"

App::App(std::string filePath, QWidget* parent) : QMainWindow(parent)
{
  buildGui(filePath);
}



App::~App()
{}

void App::buildGui(std::string filePath)
{
  // A simple menubar.
  QMenuBar* menu = menuBar();
  QMenu* file = menu->addMenu("File");
  QAction* exit = file->addAction("Quit", [this]() {close();});

  // Our basic widget.
  BasicWidget* widget = new BasicWidget(filePath, this);
  setCentralWidget(widget);
}
