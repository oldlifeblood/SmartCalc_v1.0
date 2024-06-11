/**
 * @file main.cpp
 */

#include <QApplication>

#include "mainwindow.h"

/**
 * @mainpage main.cpp Документация по проекту SmartCalc_v1.0
 *
 * Добро пожаловать в документацию по проекту SmartCalc!
 * Этот проект представляет собой калькулятор, разработанный с использованием
 * фреймворка Qt и языков программирования C и C++. SmartCalc предназначен для
 * выполнения различных математических операций с удобным и интуитивно понятным
 * интерфейсом.
 */
int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  a.setStyleSheet(
      "QPushButton { border-radius: 15px;"  // Задаем радиус скругления, чтобы
                                            // кнопка стала круглой
      "  background-color: #808080;"  // Задаем цвет фона кнопки
      "  color: white;"               // Задаем цвет текста
      "}");

  MainWindow w;
  w.show();
  return a.exec();
}
