#ifndef IPMONITORENGINE_H
#define IPMONITORENGINE_H

#include <Plasma/DataEngine>

class IpMonitorEngine : public Plasma::DataEngine
{
    Q_OBJECT

public:
    IpMonitorEngine(QObject *parent, const QVariantList& args);

protected:
    bool updateSourceEvent(const QString& source);
};

K_EXPORT_PLASMA_DATAENGINE(ipmonitor, IpMonitorEngine)

#endif // IPMONITORENGINE_H
