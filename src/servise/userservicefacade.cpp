#include "userservicefacade.h"
#include<graphwidget.h>
#include <node.h>
#include <

QList<VkUser> generate(){
    QList<VkUser> users;
    for(int i = 0; i < 10; i++){
        VkUser user;
        user.setFirstName(QString::number(rand()));
        user.setLastName(QString::number(rand()));
        users.append(user);
    }
   return users;
}
UserServiceFacade::UserServiceFacade(QGroupBox *grid, Dialog)
{
    this->grid = grid;
    diagram = new Er<VkUser>();
    QString access_token = "b3f4e474c861d5851d8475da8a9b141f751f835a1b3e7a8fa3450e358d58bd96683648e3b3334e143186d";
    vkServise = new VkServise(access_token);
}

void UserServiceFacade::selectVkUser(QString idUser, QGroupBox *grid){
    while(grid->layout()->count() != 0)
    {
      delete grid->layout()->itemAt(0)->widget();
    }
    delete grid->layout();
     QGridLayout *layout = new QGridLayout;
//    User user = vkServise->getUser(id);
//    const VkUser vkUser = user.getVkUser();
    QList<VkUser> users = generate();
    VkUser vkUser = users.at(0);
    QLabel *fio_label =  new QLabel(QObject::tr("FIO:"));
    QLabel *fio = new QLabel(vkUser.getFirstName());
    layout->addWidget(fio_label, 0, 0);
    layout->addWidget(fio, 0, 1);
//    QList<VkUser> friends = vkServise->getFriends(id);
    Node *center = new Node(&vkUser);
     QList<VkUser> friends = users;
     QList<Node*> *nodes = new QList<Node*>();
    diagram->insert_atribut(vkUser.getFirstName().toStdString(), vkUser);
    foreach (VkUser user, friends) {
        Er<VkUser> *er = new Er<VkUser>();
        er -> insert_atribut(user.getFirstName().toStdString(), user);
        diagram->insert_relation(QObject::tr("Has").toStdString(), er);
        nodes->append(new Node(&user));
    }

    GraphWidget *graphwidget = new GraphWidget(center, nodes, grid);
    layout->addWidget(graphwidget, 0, 3, 4, 1);
    grid->setLayout(layout);
    this->grid = grid;
}

void UserServiceFacade::chooseFriend(Node *choosedNode){
    while(grid->layout()->count() != 0)
    {
      delete grid->layout()->itemAt(0)->widget();
    }
    delete grid->layout();
     QGridLayout *layout = new QGridLayout;
//    User user = vkServise->getUser(id);
//    const VkUser vkUser = user.getVkUser();
    QList<VkUser> users = generate();
    VkUser vkUser = users.at(0);
    QLabel *fio_label =  new QLabel(QObject::tr("FIO:"));
    QLabel *fio = new QLabel(vkUser.getFirstName());
    layout->addWidget(fio_label, 0, 0);
    layout->addWidget(fio, 0, 1);
//    QList<VkUser> friends = vkServise->getFriends(id);
    Node *center = new Node(&vkUser);
     QList<VkUser> friends = users;
     QList<Node*> *nodes = new QList<Node*>();
    diagram->insert_atribut(vkUser.getFirstName().toStdString(), vkUser);
    foreach (VkUser user, friends) {
        Er<VkUser> *er = new Er<VkUser>();
        er -> insert_atribut(user.getFirstName().toStdString(), user);
        diagram->insert_relation(QObject::tr("Has").toStdString(), er);
        nodes->append(new Node(&user));
    }

    GraphWidget *graphwidget = new GraphWidget(center, nodes, grid);
    layout->addWidget(graphwidget, 0, 3, 4, 1);
    grid->setLayout(layout);
    this->grid = grid;
}


