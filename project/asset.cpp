#include "asset.h"
#include "asset_p.h"//binary compatibility

Asset::Asset(QObject *parent) : QObject(parent)
{

}

Asset::Asset(type assetType, QString name, double allocation)
{
    Q_D(Asset);

    d->assetType = assetType;
    d->name = name;
    d->allocation = allocation;
}

//AssetPrivate::AssetPrivate(type assetType, QString name, double allocation) :

QJsonDocument Asset::toJson()
{
    Q_D(Asset);
    QJsonObject assetObject;

    assetObject[ASSET_TYPE] = d->assetType;
    assetObject[ASSET_NAME] = d->name;
    assetObject[ASSET_ALLOCATION] = d->allocation;

    QJsonDocument assetDocument(assetObject);
    return assetDocument;
}