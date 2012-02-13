import QtQuick 1.0
import org.kde.plasma.core 0.1 as PlasmaCore
import org.kde.plasma.components 0.1 as PlasmaComponents

Item {
    id: ipmonitor
    property int minimumWidth: 150
    property int minimumHeight: 100

    PlasmaCore.DataSource {
        id: ipSource
        engine: "ipmonitor"
        connectedSources: sources
        interval: 5000
    }

    Column {
        id: view
        anchors.fill: parent
        Repeater {
            model: PlasmaCore.DataModel {
                dataSource: ipSource
            }

            PlasmaComponents.Label {
                text: model["Name"]+": "+model["Address"]
            }
        }
    }
}

