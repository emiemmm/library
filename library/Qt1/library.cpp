#include "library.h"
#include "ui_library.h"

library::library(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::library)
{
    ui->setupUi(this);
}

library::~library()
{
    delete ui;
}
