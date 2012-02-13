# A name for the project
project(plasma-ipmonitor)
 
# Find the required Libaries
include(KDE4Defaults)

add_definitions (${QT_DEFINITIONS} ${KDE4_DEFINITIONS})
include_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_BINARY_DIR}
    ${KDE4_INCLUDES}
    )

# We add our source code here
set(ipmonitor_engine_SRCS ipmonitorengine.cpp)

# Now make sure all files get to the right place
kde4_add_plugin(plasma_engine_ipmonitor ${ipmonitor_engine_SRCS})
target_link_libraries(plasma_engine_ipmonitor
    ${QT_QTNETWORK_LIBRARY}
    ${KDE4_KDECORE_LIBS}
    ${KDE4_PLASMA_LIBS})

install(TARGETS plasma_engine_ipmonitor
        DESTINATION ${PLUGIN_INSTALL_DIR})

install(FILES plasma-engine-ipmonitor.desktop
        DESTINATION ${SERVICES_INSTALL_DIR})
