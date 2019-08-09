#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include <QObject>

#include "asset.h"

class PortfolioPrivate;//PIMPL

class portfolio : public QObject
{
    Q_OBJECT
public:
    portfolio(const QString &path);
    // explicit portfolio(QObject *parent = nullptr);
    bool isValid();
    void addAsset(Asset &newAsset);
    bool createList(QJsonDocument &jsonDoc);

protected:
signals:
public slots:

private:
    Q_DECLARE_PRIVATE(Portfolio)
};

#endif // PORTFOLIO_H
