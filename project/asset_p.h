#ifndef ASSET_P_H
#define ASSET_P_H

#include <QObject>
#include "asset.h"

class AssetPrivate
{
public:
    Q_DISABLE_COPY(AssetPrivate)

    type assetType;
    QString name;
    double allocation;//percentage
};

#endif // ASSET_P_H
