#ifndef PORTFOLIO_P_H
#define PORTFOLIO_P_H

#include <QList>
#include "portfolio.h"

class PortfolioPrivate
{
public:
    Q_DISABLE_COPY(PortfolioPrivate)

    QList<Asset*> assetList;//list of assets imported from portfolio file
};


#endif // PORTFOLIO_P_H
