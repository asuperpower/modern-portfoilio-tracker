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
