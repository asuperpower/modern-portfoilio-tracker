#include "mainwindow.h"
#include <QApplication>
#include <QString>

#include <QFileInfo>
#include <QStandardPaths>
#include <QDir>

#include "filedefs.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //Look for config file

    //No config file found or doesn't specify location, use default directory
    QString portfolioPath = QStandardPaths::locate(QStandardPaths::Documents, FOLDER_NAME, QStandardPaths::LocateDirectory);

    return a.exec();
}
