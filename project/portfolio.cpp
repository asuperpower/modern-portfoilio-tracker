#include "portfolio.h"
#include "portfolio_p.h"

#include <QFile>
#include <QJsonArray>

// portfolio::portfolio(QObject *parent) : QObject(parent)
// {

// }

//One portfolio = one json file
portfolio::portfolio(const QString &path)
{
    Q_D(Portfolio);

    QFile file(path);
    bool fileExists = false;
    QJsonParseError err;
    
    if(file.exists())
        fileExists = true;//have to do before it's created

    try {
        file.open(QIODevice::ReadWrite | QIODevice::Text);
    }
    catch(const std::exception& e) {
        qFatal ("Error (%s) opening file, perhaps it is not in a writable location.", e.what());
    }
    
    if(fileExists) {
        //Digest json from file -- do in constructor as we only need to do this when it is opened
        QString fileData = file.readAll();
        file.close();
        QJsonDocument jsonFromFile = QJsonDocument::fromJson(fileData.toUtf8(), &err);  
        //todo err handling
    }
    else
        file.close();//just wrote new file
}

void portfolio::addAsset(Asset &newAsset) {
    Q_D(Portfolio);

    //Add to vector, (maybe don't update file until/unless it's saved)
    d->assetList.append(&newAsset);
}

//Gets json document and creates list of assets from it
bool portfolio::createList(QJsonDocument &jsonDoc)
{
    Q_D(Portfolio);
    bool dataInvalid = false;

    if (!jsonDoc.isArray())
        return dataInvalid=true;

    QJsonArray jsonArray = jsonDoc.array();

    for(auto it=jsonArray.constBegin(); it != jsonArray.constEnd(); ++it)
    {
        const QJsonValue &jsonVal = *it;

        QJsonObject jsonObj = jsonVal.toObject();
        //fun part
        d->assetList.append(new Asset(  jsonObj[ASSET_TYPE], jsonObj[ASSET_NAME], jsonObj[ASSET_ALLOCATION] ));//todo fix convert to string etc.
    }

    return dataInvalid;
}

//todo: user open file
//path given from user for new portfolio file
//check that it's writeable
