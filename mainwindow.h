#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void digitPressed(QString digit);
    void operatorPressed(QString op);
    void equalsPressed();
    void clearPressed();

private:
    Ui::MainWindow *ui;
    double firstNum;
    bool userIsTypingSecondNumber;
    QString pendingOperator;
};
#endif // MAINWINDOW_H
