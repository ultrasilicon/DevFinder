#include "widget.h"

Widget::Widget(QWidget *parent)
  : QWidget(parent)
{
  tool_hide_file_ckbx = new QCheckBox("Show hidden file");
  tool_full_path_ckbx = new QCheckBox("Show full path in Finder");

  confirm_btn = new QPushButton("Go !");
  confirm_btn->setDefault(true);

  main_layout = new QVBoxLayout(this);
  main_layout->addWidget(tool_full_path_ckbx);
  main_layout->addWidget(tool_hide_file_ckbx);
  main_layout->addWidget(confirm_btn);

  connect(confirm_btn, SIGNAL(clicked()), this, SLOT(Go()));

  this->setWindowOpacity(0.9);
  this->setWindowTitle("DevFinder 2");
  this->setFixedHeight(100);
  this->setFixedWidth(250);
}

Widget::~Widget()
{

}

void Widget::Go()
{
  if (tool_hide_file_ckbx->isChecked())
    {
      QProcess::execute("defaults write com.apple.finder AppleShowAllFiles -bool true");
    }
  else
    {
      QProcess::execute("defaults write com.apple.finder AppleShowAllFiles -bool false");
    }

  if (tool_full_path_ckbx->isChecked())
    {
      QProcess::execute("defaults write com.apple.finder _FXShowPosixPathInTitle -bool true");
    }
  else
    {
      QProcess::execute("defaults write com.apple.finder _FXShowPosixPathInTitle -bool false");
    }

  QProcess::execute("killall Finder");
}
