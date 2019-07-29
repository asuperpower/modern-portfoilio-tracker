#ifndef PORTFOLIO_P_H
#define PORTFOLIO_P_H

#include <QLinkedList>
#include "portfolio.h"

class PortfolioPrivate
{
public:
    Q_DISABLE_COPY(PortfolioPrivate)

    QLinkedList<Asset> assetList;//list of assets imported from portfolio file
};


#endif // PORTFOLIO_P_H
