/**
 * @file mainwindow.h
 *
 * @brief Заголовочный файл с определением класса MainWindow и его членов.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cstring>

#include "qgraph.h"

extern "C" {
#include "polish.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

/**
 * @class MainWindow
 * @brief Основной класс главного окна приложения.
 *
 * Этот класс представляет собой главное окно приложения, в котором пользователь
 * может вводить выражения, просматривать графики и выполнять другие действия.
 */
class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  /**
   * @brief Конструктор класса MainWindow.
   * @param parent Родительский виджет (если есть).
   */
  MainWindow(QWidget *parent = nullptr);

  /**
   * @brief Деструктор класса MainWindow.
   */
  ~MainWindow();

 private:
  Ui::MainWindow *ui;  ///< Компонент UI для MainWindow.
  qgraph myGraph;  ///< Объект для отображения графиков.

 private slots:
  /**
   * @brief Обработчик события нажатия на кнопку.
   */
  void on_clicked();

  /**
   * @brief Обработчик события нажатия на кнопку "Backspace".
   */
  void on_pushButton_backspace_clicked();

  /**
   * @brief Обработчик события нажатия на кнопку "Graph".
   */
  void on_pushButton_graph_clicked();

  /**
   * @brief Обработчик события нажатия на кнопку "AC".
   */
  void on_pushButton_ac_clicked();

  /**
   * @brief Обработчик события нажатия на кнопку "Dot".
   */
  void on_pushButton_dot_clicked();

  /**
   * @brief Обработчик события нажатия на кнопку "Equals".
   */
  void on_pushButton_equals_clicked();
};

#endif  // MAINWINDOW_H
