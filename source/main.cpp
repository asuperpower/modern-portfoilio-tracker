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

    //Todo>> split looking for config file etc. into it's own location
    //Look for config file
    QString configLocation = QStandardPaths::locate(QStandardPaths::ConfigLocation, CONFIG_PATH, QStandardPaths::LocateDirectory);
    if (configLocation != "")/*TODO: Add custom parsing to config file*/
        QString todo="";

    //No config file found or doesn't specify location, use default directory
    QString portfolioPath = QStandardPaths::locate(QStandardPaths::DocumentsLocation, FOLDER_NAME, QStandardPaths::LocateDirectory);

    return a.exec();
}
