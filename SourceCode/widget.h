#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QProcess>
#include <QCheckBox>
#include <QPushButton>
#include <QVBoxLayout>



class Widget : public QWidget
{
  Q_OBJECT

public:
  Widget(QWidget *parent = 0);
  ~Widget();

  QVBoxLayout *main_layout;
  QCheckBox *tool_hide_file_ckbx;
  QCheckBox *tool_full_path_ckbx;
  QPushButton *confirm_btn;

private slots:
  void Go();
};

#endif // WIDGET_H
