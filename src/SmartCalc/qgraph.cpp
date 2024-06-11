#include "qgraph.h"

#include "mainwindow.h"
#include "ui_qgraph.h"

qgraph::qgraph(QWidget* parent) : QWidget(parent), ui(new Ui::qgraph) {
  ui->setupUi(this);
  customPlot = new QCustomPlot(this);
  customPlot->setMinimumSize(700, 500);
  customPlot->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
  setupPlot();
}

qgraph::~qgraph() { delete ui; }

void qgraph::setupPlot() {
  customPlot->addGraph();
  customPlot->xAxis->setLabel("Y");
  customPlot->yAxis->setLabel("X");

  customPlot->xAxis->setRange(x_min, -x_min);
  customPlot->yAxis->setRange(10, -10);

  customPlot->graph(0)->setPen(QPen(Qt::blue));
  customPlot->graph(0)->setLineStyle(QCPGraph::lsLine);
  customPlot->graph(0)->setScatterStyle(
      QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::blue));
  customPlot->replot();
}

void qgraph::graphDraw(QString& expression) {
  h_step = 0.01;
  N = (x_max - x_min) / h_step + 2;
  QVector<double> x_vector, y_vector;

  for (double X = x_min; X <= x_max; X += h_step) {
    x_vector.push_back(X);
    QByteArray expressionBytes = expression.toLocal8Bit();
    const char* expressionStr = expressionBytes.constData();
    char* num = startRPN(expressionStr, X);
    double resultValue = std::stod(num);
    y_vector.push_back(resultValue);
    delete[] num;
  }

  customPlot->addGraph();
  customPlot->graph(0)->setData(x_vector, y_vector);
  customPlot->rescaleAxes();
  customPlot->replot();
  x_vector.clear();
  y_vector.clear();
}
