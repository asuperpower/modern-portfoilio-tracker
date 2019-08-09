#ifndef GREETER_H
#define GREETER_H

#include <QWidget>

class Greeter : public QWidget
{
    Q_OBJECT
public:
    explicit Greeter(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // GREETER_H
