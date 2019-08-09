#include "asset.h"
#include "asset_p.h"//binary compatibility

Asset::Asset(QObject *parent) : QObject(parent)
{

}

Asset::Asset(AssetType assetType, QString name, double allocation)
{
    Q_D(Asset);

    d->assetType = assetType;
    d->name = name;
    d->allocation = allocation;
}

Asset::Asset(QJsonValue assetTypeJson, QJsonValue name, QJsonValue allocation)
{
    Q_D(Asset);

    //Convert json to enum value {cash, stocks, bonds etc.}
    QString assetTypeString = assetTypeJson.toString();
    assert(!assetTypeString.isEmpty());
    auto &&metaEnum = QMetaEnum::fromType<Asset::AssetType>();
    d->assetType = static_cast<AssetType>(metaEnum.keyToValue(assetTypeString.toUtf8().constData())  );

    d->name = name.toString();
    d->allocation = allocation.toDouble();
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
