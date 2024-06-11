#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton_open, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton_close, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton_divide, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton_degree, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton_multiply, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton_percent, SIGNAL(clicked()), this, SLOT(on_clicked()));

  connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(on_clicked()));

  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(on_clicked()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(on_clicked()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_clicked() {
  QPushButton *button = qobject_cast<QPushButton *>(sender());
  QString buttonText = button->text();
  QString currentText = ui->labelText->text();
  int index = currentText.indexOf("Ошибка");
  if (index == -1) {
    if (currentText == "0") {
      currentText.clear();
    }
    bool allDigits = true;
    for (QChar ch : buttonText) {
      if (!ch.isDigit()) {
        allDigits = false;
        break;
      }
    }
    if (allDigits) {
      currentText += buttonText;
    } else {
      currentText += " " + buttonText + " ";
    }
    ui->labelText->setText(currentText);
  } else {
    ui->labelText->setText("0");
  }
}

void MainWindow::on_pushButton_backspace_clicked() {
  QString currentText = ui->labelText->text();
  if (currentText.isEmpty() || currentText == "0") {
    currentText = "0";
  } else {
    currentText.chop(1);
    if (currentText.isEmpty()) {
      currentText = "0";
    }
  }
  ui->labelText->setText(currentText);
}

void MainWindow::on_pushButton_graph_clicked() { myGraph.show(); }

void MainWindow::on_pushButton_ac_clicked() { ui->labelText->setText("0"); }

void MainWindow::on_pushButton_dot_clicked() {
  QString currentText = ui->labelText->text();
  int currentIndex = currentText.lastIndexOf(' ');
  if (currentIndex == -1) {
    currentIndex = 0;
  }
  int dotIndex = currentText.indexOf('.', currentIndex);
  if (dotIndex == -1 || dotIndex == currentText.length() - 1) {
    if (currentText.length() > dotIndex + 1 &&
        currentText.at(dotIndex + 1) != '.') {
      currentText += ".";
      ui->labelText->setText(currentText);
    }
  }
}

void MainWindow::on_pushButton_equals_clicked() {
  QString currentText = ui->labelText->text();
  QString text_x = ui->labelText_x->toPlainText();
  int index = currentText.indexOf("x");

  if (index != -1) {
    if (!text_x.isEmpty()) {
      bool isDouble;
      double numberX = text_x.toDouble(&isDouble);

      if (isDouble && numberX > 0) {
        myGraph.graphDraw(currentText);
        std::string stdStringCurrent = currentText.toStdString();
        const char *cStringCurrent = stdStringCurrent.c_str();
        char *result = startRPN(cStringCurrent, numberX);
        QString resultString = QString::fromUtf8(result);
        ui->labelText->setText(resultString);
        delete[] result;
      } else {
        ui->labelText->setText("Ошибка: Неправильное значение для х");
      }
    } else {
      ui->labelText->setText("Ошибка: Пустое значение для х");
    }
  } else {
    std::string stdStringCurrent = currentText.toStdString();
    const char *cStringCurrent = stdStringCurrent.c_str();
    char *result = startRPN(cStringCurrent, 1);
    QString resultString = QString::fromUtf8(result);
    int index = resultString.indexOf("Ошибка");
    if (index == -1) {
      myGraph.graphDraw(currentText);
    }
    ui->labelText->setText(resultString);
    delete[] result;
  }
}
