#ifndef GETNETSPEED_H
#define GETNETSPEED_H

#include <QObject>
#include <QTimer>


class getNetSpeed : public QObject
{
    Q_OBJECT
public:
    explicit getNetSpeed(QObject *parent = nullptr);
    unsigned long long int getReceiveBytes();
    unsigned long long int getSendBytes();


private:
    unsigned long long int m_receiveBytes;
    unsigned long long int m_sendBytes;

signals:

public slots:
    void getNetworkBandWidth(unsigned long long int &receiveBytes, unsigned long long int &sendBytes);
};

#endif // GETNETSPEED_H
