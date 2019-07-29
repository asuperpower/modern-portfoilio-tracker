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
    void addAsset(Asset &newAsset);

protected:
signals:
public slots:

private:
    //asset class
};

#endif // PORTFOLIO_H
