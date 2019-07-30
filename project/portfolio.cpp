#include "portfolio.h"
#include "portfolio_p.h"

#include <QFile>

// portfolio::portfolio(QObject *parent) : QObject(parent)
// {

// }

//One portfolio = one json file
portfolio::portfolio(const QString &path)
{
    Q_D(Portfolio);

    //check file existence
    QFile file(path);
    
    try
    {
        file.open(QIODevice::ReadWrite | QIODevice::Text);
    }
    catch(const std::exception& e)
    {
        qFatal ("Error (%s) opening file, perhaps it is not in a writable location.", e.what());
    }
    
    //digest json -- do in constructor as we only need to do this when it is opened
    
}

void portfolio::addAsset(Asset &newAsset)
{
    Q_D(Portfolio);

    //Add to vector, (maybe don't update file until/unless it's saved)
    d->assetList.append(&newAsset);
}

//todo: user open file
//path given from user for new portfolio file
//check that it's writeable
