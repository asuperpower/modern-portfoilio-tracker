#include "mainwindow.h"
#include <QApplication>
#include <QString>
#include <QSettings>

#include <QFileInfo>
#include <QStandardPaths>
#include <QDir>

#include "filedefs.h"

QString getConfigLocation();
QString getPortfolioPath();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}

QString getConfigLocation() //Get location of config and parse it >> TODO: Seperate into class that deals with and parses config
{
    QString configLocation = QStandardPaths::locate(QStandardPaths::ConfigLocation, CONFIG_FULLPATH, QStandardPaths::LocateFile);
    if (configLocation != "")
    {
        /*TODO: Add custom parsing to config file*/
        return configLocation;
    }
    else
    {
        QDir configDir;
        //Create fresh config
        configLocation = QStandardPaths::writableLocation(QStandardPaths::ConfigLocation);
        configLocation += CONFIG_FOLDER;
        if(configDir.exists())
            configDir.mkpath(configLocation);

        QFile file(configLocation + CONFIG_PATH);
        file.open(QIODevice::WriteOnly);
        file.close();
    }
    return configLocation;
}

QString getPortfolioPath() //Get location of portfolio and parse it >> TODO: Seperate into class that gets populated on opening file
{
    //Check QSettings for anything
        //No config file found or doesn't specify location, use default directory
        QString portfolioPath = QStandardPaths::locate(QStandardPaths::DocumentsLocation, FOLDER_NAME, QStandardPaths::LocateDirectory);
    return QString("");//todo
}
