#ifndef INFORMATIONWIDGET_H
#define INFORMATIONWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <QStorageInfo>
#include "getnetspeed.h"

class InformationWidget : public QWidget
{
    Q_OBJECT

public:
    explicit InformationWidget(QWidget *parent = nullptr);

    inline QStorageInfo * storageInfo() { return m_storageInfo; }

private slots:
    // 用于更新数据的槽函数
    void refreshInfo();

public slots:
    //更改背景图片
    void changeBackground(QString path);
    //改变显示的文字的大小
    void changFointSize(int i);
    //查检文件是否存在
    bool isFileExist(QString fullFilePath);

private:
    // 真正的数据显示在这个 Label 上
    QLabel *m_infoLabel;
    // 处理时间间隔的计时器
    QTimer *m_refreshTimer;
    // 分区数据的来源
    QStorageInfo *m_storageInfo;


    getNetSpeed * m_getNetSpeed;
    unsigned long long int m_receiveBytes;
    unsigned long long int m_sendBytes;
    unsigned long long int m_receiveBytes_old;
    unsigned long long int m_sendBytes_old;

    unsigned long long int downloadSpeed ;
    unsigned long long int uploadSpeed ;

    QString getSpeed(unsigned long long int time);
};

#endif // INFORMATIONWIDGET_H
