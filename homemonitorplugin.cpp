#include "homemonitorplugin.h"
#include <QFileDialog>
#include <QSettings>

HomeMonitorPlugin::HomeMonitorPlugin(QObject *parent)
    : QObject(parent)
{

}

const QString HomeMonitorPlugin::pluginDisplayName() const
{
    //插件的名字
    return QString("网速显示器");
}

const QString HomeMonitorPlugin::pluginName() const
{
    return QStringLiteral("netspeed");
}

void HomeMonitorPlugin::init(PluginProxyInterface *proxyInter)
{
    m_proxyInter = proxyInter;

    m_pluginWidget = new InformationWidget;
    m_tipsWidget = new QLabel;
    m_appletWidget = new QLabel;

    fontSize = 12;

    //设置最小的宽度，能够有足够的空间显示网速
    m_pluginWidget->setMinimumSize(80,35);

    // 如果插件没有被禁用则在初始化插件时才添加主控件到面板上
    if (!pluginIsDisable()) {
        m_proxyInter->itemAdded(this, pluginName());
    }

    //如果设置了背景图片，则要加载背景图片
    QSettings settings("netSpeedP", "网速显示器");
    QString filePath = settings.value("backgroud").toString();
    //不晓得为何，一检查就出错
//    if(m_pluginWidget->isFileExist(filePath)){
//        m_pluginWidget->changeBackground(filePath);
//    }
    m_pluginWidget->changeBackground(filePath);
}

QWidget *HomeMonitorPlugin::itemWidget(const QString &itemKey)
{
    Q_UNUSED(itemKey);

    return m_pluginWidget;
}

QWidget *HomeMonitorPlugin::itemTipsWidget(const QString &itemKey)
{
    Q_UNUSED(itemKey);

    // 当鼠标移动到插件上时

    m_tipsWidget->setText(
                QString("当前字体为:%1").arg(QString::number(fontSize))
                );

    return m_tipsWidget;
}

QWidget *HomeMonitorPlugin::itemPopupApplet(const QString &itemKey)
{
    Q_UNUSED(itemKey);


    //鼠标左键点击时显示的

    //设置字体大小
    if(fontSize == 16){
        fontSize =10;
    }
    fontSize += 1;
    m_pluginWidget->changFointSize(fontSize);

    m_appletWidget->setText(
                QString("当前字体为:%1").arg(QString::number(fontSize))
                );

    return m_appletWidget;
}

bool HomeMonitorPlugin::pluginIsAllowDisable()
{
    // 告诉 dde-dock 本插件允许禁用
    return true;
}

bool HomeMonitorPlugin::pluginIsDisable()
{
    // 第二个参数 “disabled” 表示存储这个值的键（所有配置都是以键值对的方式存储的）
    // 第三个参数表示默认值，即默认不禁用
    return m_proxyInter->getValue(this, "disabled", false).toBool();
}

void HomeMonitorPlugin::pluginStateSwitched()
{
    // 获取当前禁用状态的反值作为新的状态值
    const bool disabledNew = !pluginIsDisable();
    // 存储新的状态值
    m_proxyInter->saveValue(this, "disabled", disabledNew);

    // 根据新的禁用状态值处理主控件的加载和卸载
    if (disabledNew) {
        m_proxyInter->itemRemoved(this, pluginName());
    } else {
        m_proxyInter->itemAdded(this, pluginName());
    }
}

const QString HomeMonitorPlugin::itemContextMenu(const QString &itemKey)
{
    Q_UNUSED(itemKey);

    //这儿绝对是右建

    /*
     * 右键点击之后，先择图片进行更改背景图片
     */
    QSettings settings("netSpeedP", "网速显示器");

    QString filePath =  QFileDialog::getOpenFileName(0,tr("选择背景图片"),"~",tr("图片文件 (*.png *.jpg *.bmp)"));
    if(!filePath.isEmpty()){
        m_pluginWidget->changeBackground(filePath);
        settings.setValue("backgroud",filePath);
    }else{
        //不设置图片
        settings.setValue("backgroud","");
        m_pluginWidget->changeBackground("");
    }

    return nullptr;
}

void HomeMonitorPlugin::invokedMenuItem(const QString &itemKey, const QString &menuId, const bool checked)
{
    Q_UNUSED(itemKey);

    // 根据上面接口设置的 id 执行不同的操作
    if (menuId == "refresh") {
        m_pluginWidget->storageInfo()->refresh();
    } else if ("open") {
        QProcess::startDetached("gparted");
    }
}

