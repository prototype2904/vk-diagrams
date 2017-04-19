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
    node.cpp \
    dialog.cpp \
    servise/userservicefacade.cpp



HEADERS += \
    entity/vk/VkGroup.h \
    entity/vk/VkUser.h \
    entity/User.h \
    servise/VkServise.h \
    util/enums.h \
    util/JsonParser.h \
    util/RestClient.h \
    util/VkRequestBuilder.h \
    node.h \
    dialog.h \
    servise/userservicefacade.h



