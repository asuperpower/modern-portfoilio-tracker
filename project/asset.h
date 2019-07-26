#ifndef ASSET_H
#define ASSET_H

#include <QObject>

class asset : public QObject
{
    Q_OBJECT
public:
    enum type{cash, stocks, bonds};

    asset();
    explicit asset(QObject *parent = nullptr);
    asset(type assetType, QString name, double allocation);
signals:

public slots:

private:
    type assetType;
    QString name;
    double allocation;//percentage
};

#endif // ASSET_H
