#include <QCoreApplication>
#include <servise/VkServise.h>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //https://oauth.vk.com/authorize?client_id=5961166&scope=groups&response_type=token
    //Из этого адреса копируешь токен который просят не копировать в access_token
    QString access_token = "";
    //Сюда вводишь id пользователя
    int UserId = 127419409;
    VkServise vkSer(access_token);



    QList<VkUser> users = vkSer.getFriends(UserId);
    qDebug()<<"Вывод всех друзей: ";
    foreach (const VkUser & user, users) {
        qDebug()<<user.getFirstName() << " "<<user.getLastName();
    }


    QList<VkGroup> groups = vkSer.getVkGroups(users.at(0).getId());
    qDebug()<<"Вывод всех групп первого друга: ";
    foreach (const VkGroup & group, groups) {
        qDebug()<<group.getName();
    }

    return a.exec();
}

