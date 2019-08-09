#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStackedWidget *stackedWidget = ui->stackedWidget;
    greeterWidget = new Greeter;
    portfolioViewWidget = new PortfolioView;

    //Add widgets to stacked view
    stackedWidget->addWidget(greeterWidget);
    stackedWidget->addWidget(portfolioViewWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
