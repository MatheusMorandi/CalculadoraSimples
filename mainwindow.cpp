#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 🛠 Inicializando os atributos da calculadora
    firstNum = 0;
    userIsTypingSecondNumber = false;
    pendingOperator = "";

    //adicionando os signals e slots dos numericos
    //utilizando uma funcao lambda
    connect(ui->pushButton_0, &QPushButton::clicked, this, [=](){ digitPressed("0"); });

    connect(ui->pushButton_1, &QPushButton::clicked, this, [=](){ digitPressed("1"); });

    connect(ui->pushButton_2, &QPushButton::clicked, this, [=](){ digitPressed("2"); });

    connect(ui->pushButton_3, &QPushButton::clicked, this, [=](){ digitPressed("3"); });

    connect(ui->pushButton_4, &QPushButton::clicked, this, [=](){ digitPressed("4"); });

    connect(ui->pushButton_5, &QPushButton::clicked, this, [=](){ digitPressed("5"); });

    connect(ui->pushButton_6, &QPushButton::clicked, this, [=](){ digitPressed("6"); });

    connect(ui->pushButton_7, &QPushButton::clicked, this, [=](){ digitPressed("7"); });

    connect(ui->pushButton_8, &QPushButton::clicked, this, [=](){ digitPressed("8"); });

    connect(ui->pushButton_9, &QPushButton::clicked, this, [=](){ digitPressed("9"); });

    // Operadores
    connect(ui->pushButton_Add, &QPushButton::clicked, this, [=](){ operatorPressed("+"); });
    connect(ui->pushButton_Sub, &QPushButton::clicked, this, [=](){ operatorPressed("-"); });
    connect(ui->pushButton_Mul, &QPushButton::clicked, this, [=](){ operatorPressed("*"); });
    connect(ui->pushButton_Div, &QPushButton::clicked, this, [=](){ operatorPressed("/"); });

    // Outros botões
    connect(ui->pushButton_Eq, &QPushButton::clicked, this, &MainWindow::equalsPressed);
    connect(ui->pushButton_Clear, &QPushButton::clicked, this, &MainWindow::clearPressed);
}

void MainWindow::digitPressed(QString digit) {
    if (userIsTypingSecondNumber) {
        // Começando novo número após uma operação
        ui->lineEdit->setText(digit);
        userIsTypingSecondNumber = false;
    } else {
        // Continuando a digitação
        ui->lineEdit->setText(ui->lineEdit->text() + digit);
    }
}

void MainWindow::operatorPressed(QString op) {
    firstNum = ui->lineEdit->text().toDouble();
    pendingOperator = op;
    userIsTypingSecondNumber = true;
}

void MainWindow::equalsPressed() {
    double secondNum = ui->lineEdit->text().toDouble();
    double result = 0.0;

    if (pendingOperator == "+") result = firstNum + secondNum;
    else if (pendingOperator == "-") result = firstNum - secondNum;
    else if (pendingOperator == "*") result = firstNum * secondNum;
    else if (pendingOperator == "/") {
        if (secondNum != 0.0)
            result = firstNum / secondNum;
        else {
            ui->lineEdit->setText("Erro");
            return;
        }
    }

    ui->lineEdit->setText(QString::number(result));
    userIsTypingSecondNumber = false;
}

void MainWindow::clearPressed() {
    ui->lineEdit->clear();
    firstNum = 0;
    pendingOperator = "";
    userIsTypingSecondNumber = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

