#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include <QObject>

#include "asset.h"

class portfolio : public QObject
{
    Q_OBJECT
public:
    portfolio();

    portfolio(const QString &path);

    explicit portfolio(QObject *parent = nullptr);

    bool isValid();

    void addAsset(asset *newAsset);


protected:


signals:

public slots:

private:
    //linked list of items
    //type {stock, bond, etc.} -- this should also be a class probably
    //weight {percentage}
};

#endif // PORTFOLIO_H
