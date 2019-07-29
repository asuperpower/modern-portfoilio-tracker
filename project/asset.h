#ifndef ASSET_H
#define ASSET_H

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>

//For json array
#define ASSET_TYPE          "type"
#define ASSET_NAME          "name"
#define ASSET_ALLOCATION    "allocation"

enum type{cash, stocks, bonds};//TODO: Should find somewhere else for this as it would break the whole PIMPL methodology if something else needs to be added

class AssetPrivate;//PIMPL

class Asset : public QObject
{
    Q_OBJECT
public:
    //asset();
    // explicit Asset(QObject *parent = nullptr);
    Asset(type assetType, QString name, double allocation);
    QJsonDocument toJson();
signals:

public slots:

private:
    Q_DECLARE_PRIVATE(Asset)
};

#endif // ASSET_H
