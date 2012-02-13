#include "ipmonitorengine.h"

#include <QNetworkInterface>

IpMonitorEngine::IpMonitorEngine(QObject* parent, const QVariantList& args)
    : Plasma::DataEngine(parent, args)
{
    Q_UNUSED(args);
    setMinimumPollingInterval(3000);

    foreach(QNetworkInterface iface, QNetworkInterface::allInterfaces()) {
        updateSourceEvent(iface.name());
    }
}

bool IpMonitorEngine::updateSourceEvent(const QString &source)
{
    QNetworkInterface iface = QNetworkInterface::interfaceFromName(source);
    if (!iface.isValid())
        return false;
    if (source == "lo")
        return true;

    QString address;
    QList<QNetworkAddressEntry> addrs = iface.addressEntries();
    if (addrs.size()>0) {
        QHostAddress addr = addrs.at(0).ip();
        if (addr.protocol() == QAbstractSocket::IPv4Protocol)
            address = addr.toString();
        else
            address = "Not available";
    }
    else
        address = "Not available";

    setData(iface.name(), "Name", iface.humanReadableName());
    setData(iface.name(), "Address", address);
    return true;
}

#include "ipmonitorengine.moc"
