#ifndef LIBRARY_H
#define LIBRARY_H

#include <QMainWindow>
namespace Ui {
class library;
}

class library : public QMainWindow
{
    Q_OBJECT

public:
    explicit library(QWidget *parent = 0);
    ~library();

private:
    Ui::library *ui;
};

#endif // LIBRARY_H
