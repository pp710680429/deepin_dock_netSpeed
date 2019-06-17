#include "informationwidget.h"

#include <QVBoxLayout>
#include <QTimer>
#include <QDebug>
#include <QFile>

InformationWidget::InformationWidget(QWidget *parent)
    : QWidget(parent)
    , m_infoLabel(new QLabel)
    , m_refreshTimer(new QTimer(this))
    // 使用 "/home" 初始化 QStorageInfo
    // 如果 "/home" 没有挂载到一个单独的分区上，QStorageInfo 收集的数据将会是根分区的
    , m_storageInfo(new QStorageInfo("/home"))
{
    m_infoLabel->setStyleSheet("QLabel {"
                               "color: white;"
                               "}");
    m_infoLabel->setAlignment(Qt::AlignCenter);

    QVBoxLayout *centralLayout = new QVBoxLayout;
    centralLayout->addWidget(m_infoLabel);
    centralLayout->setSpacing(0);
    centralLayout->setMargin(0);

    setLayout(centralLayout);
    m_infoLabel->setText(QString("正在加载中..."));

    //------------------------
    m_getNetSpeed = new getNetSpeed;
    m_receiveBytes = m_getNetSpeed->getReceiveBytes();
    m_sendBytes = m_getNetSpeed->getSendBytes();
    m_receiveBytes_old = m_getNetSpeed->getReceiveBytes();
    m_sendBytes_old = m_getNetSpeed->getSendBytes();

    m_infoLabel->setAlignment(Qt::AlignLeft);
    m_infoLabel->resize(80,35);

    //设置字体大小
    // 1366*768 用
       changFointSize(12);
    //-----------------------

    // 连接 Timer 超时的信号到更新数据的槽上
    connect(m_refreshTimer, &QTimer::timeout, this, &InformationWidget::refreshInfo);

    // 设置 Timer 超时为 10s，即每 10s 更新一次控件上的数据，并启动这个定时器
    m_refreshTimer->start(1000);

    refreshInfo();
}

void InformationWidget::refreshInfo()
{
    m_receiveBytes = m_getNetSpeed->getReceiveBytes();
    m_sendBytes = m_getNetSpeed->getSendBytes();
    downloadSpeed =(m_receiveBytes -m_receiveBytes_old );
    uploadSpeed =  ( m_sendBytes - m_sendBytes_old) ;

    // 更新内容
    //为了在时尚模式中好看，所以不设置上传和下载提示
    //    m_infoLabel->setText(QString("上传:%1  \n下载:%2  ").arg(this->getSpeed(uploadSpeed)).arg(this->getSpeed(downloadSpeed)));
    //感觉其它的设置没有用，只有用空格格开才有效果
    /*
     *
    m_infoLabel->setAlignment(Qt::AlignLeft);
    m_infoLabel->resize(80,35);
    */
    m_infoLabel->setText(QString("%1\t\n%2\t").arg(this->getSpeed(uploadSpeed)).arg(this->getSpeed(downloadSpeed)));


    //把时间存入旧的变量中
    m_receiveBytes_old = m_receiveBytes;
    m_sendBytes_old = m_sendBytes;
}

void InformationWidget::changeBackground(QString path)
{
    this->setAutoFillBackground(true);
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window,QBrush(QPixmap(path).scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));// 使用平滑的缩放方式
    this->setPalette(palette);// 给widget加上背景图
}

void InformationWidget::changFointSize(int i)
{
    m_infoLabel->setAlignment(Qt::AlignLeft);
    QFont ft;
    ft.setPointSize(i);
    m_infoLabel->setFont(ft);
}

QString InformationWidget::getSpeed(unsigned long long time)
{
    if(time < 1024){
        return QString("%1 B/s").arg(QString::number(time));
    }else if(time < 1024*1024){
        return QString("%1 K/s").arg(QString::number(time/1024));
    }else if(time < 1024*1024*1024){
        return QString("%1 M/s").arg(QString::number(time/(1024*1024)));
    }
    return QString("%1 G/s").arg(QString::number(time/(1024*1024*1024)));
}

bool isFileExist(QString fullFilePath)
{
    QFile file(fullFilePath);
       if(file.exists())
       {
           return true;
       }
       return false;
}
