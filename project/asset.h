#ifndef ASSET_H
#define ASSET_H

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMetaEnum>

//For json array
#define ASSET_TYPE          "type"
#define ASSET_NAME          "name"
#define ASSET_ALLOCATION    "allocation"

class AssetPrivate;//PIMPL

class Asset : public QObject
{
    Q_OBJECT
public:
    enum AssetType{
        cash,
        stocks,
        bonds
    };
    Q_ENUM(AssetType)
    
    //asset();
    explicit Asset(QObject *parent = nullptr);
    Asset(AssetType assetType, QString name, double allocation);
    Asset(QJsonValue assetType, QJsonValue name, QJsonValue allocation);

    QJsonDocument toJson();
signals:

public slots:

private:
    Q_DECLARE_PRIVATE(Asset)
};

#endif // ASSET_H
