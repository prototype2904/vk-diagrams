#include "userservicefacade.h"
#include <QtWidgets>

UserServiceFacade::UserServiceFacade()
{
    QString access_token = "";
    vkServise = new VkServise(access_token);
}

void UserServiceFacade::selectVkUser(QString idUser, QGridLayout *layout){
    int id = idUser.toInt();
    User user = vkServise->getUser(id);
    QLabel *fio_label =  new QLabel(tr("FIO:"));
    QLabel *fio = new QLabel(user.getVkUser().getFirstName());
    layout->addWidget(fio_label, 0, 0);
    layout->addWidget(fio, 0, 1);
}
