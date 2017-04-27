#include <QtWidgets/QApplication>

#include "dialog.h"
#include "util/DialogSingleton.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Dialog& dialog = DialogSingleton::get();
    dialog.show();

    return app.exec();

//    QCoreApplication a(argc, argv);

////    https://oauth.vk.com/authorize?client_id=5961166&scope=groups&response_type=token
////    //Из этого адреса копируешь токен который просят не копировать в access_token
//    QString access_token = "63e32f3ddbe5b7b1d78c625ff3b2490242124103a18c879393a6d690c6b43ebfd65354b9038829d9320cd";
////    //Сюда вводишь id пользователя
//    int UserId = 127419409;
//    VkServise vkSer(access_token);



//    QList<VkUser> users = vkSer.getFriends(UserId);
//    qDebug()<<"Вывод всех друзей: ";
//    foreach (const VkUser & user, users) {
//        qDebug()<<user.getFirstName() << " "<<user.getLastName();
//    }


//    QList<VkGroup> groups = vkSer.getVkGroups(users.at(0).getId());
//    qDebug()<<"Вывод всех групп первого друга: ";
//    foreach (const VkGroup & group, groups) {
//        qDebug()<<group.getName();
//    }

////    User user = vkSer.getUser(UserId);
////    qDebug()<<"Вывод всех друзей: ";
////        qDebug()<<user.getVkUser().getFirstName() << " "<<user.getVkUser().getLastName();


//    return a.exec();
}

