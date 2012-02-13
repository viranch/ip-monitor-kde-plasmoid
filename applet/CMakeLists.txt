project(ipmonitor)

install(DIRECTORY contents
        DESTINATION ${DATA_INSTALL_DIR}/plasma/plasmoids/org.kde.ipmonitor)

install(FILES metadata.desktop
        DESTINATION ${DATA_INSTALL_DIR}/plasma/plasmoids/org.kde.ipmonitor/)

install(FILES metadata.desktop
        DESTINATION ${SERVICES_INSTALL_DIR}
        RENAME plasma-applet-ipmonitor.desktop)

