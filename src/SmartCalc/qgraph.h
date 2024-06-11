// qgraph.h

/**
 * @file qgraph.h
 */

#ifndef QGRAPH_H
#define QGRAPH_H

#include <QVector>
#include <QWidget>

#include "qcustomplot.h"

/**
 * @brief Класс qgraph
 *
 * Класс qgraph представляет собой виджет типа QWidget, предоставляющий
 * функциональность для отрисовки математических выражений в виде графиков с
 * использованием библиотеки QCustomPlot.
 */
namespace Ui {
class qgraph;
}

class qgraph : public QWidget {
  Q_OBJECT

 public:
  /**
   * @brief Конструктор для класса qgraph.
   *
   * @param parent Родительский виджет (по умолчанию - nullptr).
   */
  explicit qgraph(QWidget *parent = nullptr);

  /**
   * @brief Деструктор для класса qgraph.
   */
  ~qgraph();

  /**
   * @brief Нарисовать график на основе заданного математического выражения.
   *
   * Эта функция принимает математическое выражение в виде строки (QString) и
   * строит соответствующий график с использованием библиотеки QCustomPlot.
   *
   * @param expression Математическое выражение для построения графика.
   */
  void graphDraw(QString &expression);

 private:
  Ui::qgraph *ui;           ///< Компонент UI для qgraph.
  QCustomPlot *customPlot;  ///< Экземпляр QCustomPlot для построения графиков.
  QVector<double> x_vector, y_vector;  ///< Векторы для координат x и y.
  double x_min = -5, x_max = 5, y_min = -5, y_max = 5, X_temp,
         h_step;  ///< Диапазон и шаг для построения графика.
  int N;  ///< Количество точек для построения.

  /**
   * @brief Настройка начальной конфигурации для графика.
   */
  void setupPlot();
};

#endif  // QGRAPH_H
