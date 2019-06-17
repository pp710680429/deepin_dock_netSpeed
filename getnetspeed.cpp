#include "getnetspeed.h"

getNetSpeed::getNetSpeed(QObject *parent) : QObject(parent)
{
    //    m_refreshTime = 2000;
    //    QTimer timer;
    //    connect(&timer,&QTimer::timeout,[&](){
    //        this->getNetworkBandWidth(m_receiveBytes,m_sendBytes);
    //    });
    //    timer.start(m_refreshTime);
    //  this->getNetworkBandWidth(m_receiveBytes,m_sendBytes);
}

unsigned long long getNetSpeed::getReceiveBytes()
{
    this->getNetworkBandWidth(m_receiveBytes,m_sendBytes);
    return  m_receiveBytes;
}

unsigned long long getNetSpeed::getSendBytes()
{
    this->getNetworkBandWidth(m_receiveBytes,m_sendBytes);
    return  m_sendBytes;
}

void getNetSpeed::getNetworkBandWidth(unsigned long long &receiveBytes, unsigned long long &sendBytes)
{
    //来自王勇的尝试系统监视器中的代码
    char *buf;
    static int bufsize;
    FILE *devfd;

    buf = (char *) calloc(255, 1);
    bufsize = 255;
    devfd = fopen("/proc/net/dev", "r");

    // Ignore the first two lines of the file.
    fgets(buf, bufsize, devfd);
    fgets(buf, bufsize, devfd);

    receiveBytes = 0;
    sendBytes = 0;

    while (fgets(buf, bufsize, devfd)) {
        unsigned long long int rBytes, sBytes;
        char *line = strdup(buf);

        char *dev;
        dev = strtok(line, ":");

        // Filter lo (virtual network device).
        if (QString::fromStdString(dev).trimmed() != "lo") {
            sscanf(buf + strlen(dev) + 2, "%llu %*d %*d %*d %*d %*d %*d %*d %llu", &rBytes, &sBytes);

            receiveBytes += rBytes;
            sendBytes += sBytes;
        }

        free(line);
    }

    fclose(devfd);
    free(buf);
}
