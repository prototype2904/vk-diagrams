TEMPLATE = app
CONFIG +=  c++11
QT       += core gui
QT += network
QT += widgets


SOURCES += main.cpp \
    entity/vk/VkGroup.cpp \
    entity/vk/VkUser.cpp \
    entity/User.cpp \
    servise/VkServise.cpp \
    util/JsonParser.cpp \
    util/RestClient.cpp \
    util/VkRequestBuilder.cpp \
    dialog.cpp \
    servise/userservicefacade.cpp \
    node.cpp \
    edge.cpp \
    graphwidget.cpp



HEADERS += \
    entity/vk/VkGroup.h \
    entity/vk/VkUser.h \
    entity/User.h \
    servise/VkServise.h \
    util/enums.h \
    util/JsonParser.h \
    util/RestClient.h \
    util/VkRequestBuilder.h \
    dialog.h \
    servise/userservicefacade.h \
    node.h \
    edge.h \
    graphwidget.h \
    er_diagram.h \
    util/DialogSingleton.h



