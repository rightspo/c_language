#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileDialog>
#include <QMainWindow>
#include <QSettings>
#include <QTimer>
#include <QtOpenGLWidgets>

#include "../gifLib/src/gifimage/qgifimage.h"
#include "modelviewer.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

 signals:
  void sendFilepath(QString filepath);
  void width_and_size_changed(float width, float size);

 private slots:
  void on_change_model_button_clicked();
  void on_pushButton_apply_color_clicked();
  void on_pushButton_apply_width_clicked();

  void on_btnScreenShot_clicked();

  void on_btnRecordGif_clicked();
  void recordSlot();
  void loadSettings();
  void saveSettings();
  //    void on_btnScreenShot_clicked();
  //    void on_btnRecordGif_clicked();
  //    void recordSlot();

  void on_comboBox_line_currentTextChanged(QString arg1);
  void on_comboBox_point_currentTextChanged(QString arg1);

  void on_horizontalSlider_X_valueChanged(int value);
  void on_horizontalSlider_Y_valueChanged(int value);
  void on_horizontalSlider_Z_valueChanged(int value);

  void on_pushButton_load_clicked();

  void on_checkBox_change_view_stateChanged(int arg1);

 private:
  modelViewer* modelWidget;
  QTimer* timer;
  Ui::MainWindow* ui;
  QGifImage* gifka;
  QTimer* timerGif;
  QString gifFilePath;
  QSettings* settings;

  QVector3D modelColor;
  QVector3D backgroundColor;
  QVector3D pointColor;

  QString fileName;

  QString point_type;
  QString line_type;

  float red;
  float green;
  float blue;

  float width;
  float size;

  int x;
  int y;
  int z;
};
#endif  // MAINWINDOW_H
