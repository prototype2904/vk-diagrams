#include "dialog.h"
#include <graphwidget.h>
#include <QtWidgets>
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
Dialog::Dialog()
{
    userServiceFacade = new UserServiceFacade();
    idInput = new QLineEdit();
    submitButton = new QPushButton(tr("Submit"));
    connect(submitButton, SIGNAL(released()), this, SLOT(submit()));

    createMenu();
    createHorizontalGroupBox();
    createGridGroupBox();
//    createFormGroupBox();


    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                     | QDialogButtonBox::Cancel);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setMenuBar(menuBar);
    mainLayout->addWidget(horizontalGroupBox);
    mainLayout->addWidget(gridGroupBox);
//    mainLayout->addWidget(formGroupBox);
    mainLayout->addWidget(buttonBox);


    setLayout(mainLayout);

    setWindowTitle(tr("Basic Layouts"));
}

void Dialog::submit(){
    userServiceFacade->selectVkUser(idInput->text(), gridGroupBox);
}

void Dialog::createMenu()
{
    menuBar = new QMenuBar;

    fileMenu = new QMenu(tr("&File"), this);
    exitAction = fileMenu->addAction(tr("E&xit"));
    menuBar->addMenu(fileMenu);

    connect(exitAction, SIGNAL(triggered()), this, SLOT(accept()));
}

void Dialog::createHorizontalGroupBox()
{
    horizontalGroupBox = new QGroupBox(tr("Input id"));
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(idInput);
    layout->addWidget(submitButton);
    horizontalGroupBox->setLayout(layout);
}

void Dialog::createGridGroupBox()
{
    gridGroupBox = new QGroupBox(tr("Grid layout"));
    QGridLayout *layout = new QGridLayout;

    QLabel *fio_label =  new QLabel(tr("FIO:"));
    QLabel *fio =  new QLabel(tr("Super fio"));
    layout->addWidget(fio_label, 0, 0);
    layout->addWidget(fio, 0, 1);

    GraphWidget *graphwidget = new GraphWidget(NULL, NULL, gridGroupBox);
    layout->addWidget(graphwidget, 0, 2, 4, 1);

    layout->setColumnStretch(1, 10);
    layout->setColumnStretch(2, 20);
    gridGroupBox->setLayout(layout);
}

void Dialog::createFormGroupBox()
{
    formGroupBox = new QGroupBox(tr("Form layout"));
    QFormLayout *layout = new QFormLayout;
    layout->addRow(new QLabel(tr("Line 1:")), new QLineEdit);
    layout->addRow(new QLabel(tr("Line 2, long text:")), new QComboBox);
    layout->addRow(new QLabel(tr("Line 3:")), new QSpinBox);
    formGroupBox->setLayout(layout);
}

void Dialog::submitVkUser(QString idUser, QGroupBox *grid){
    int i = 0;
    if(friendFio != NULL) delete friendFio;
    if(numCommonFriends != NULL) delete numCommonFriends;
    if(numCommonGroups != NULL) delete numCommonGroups;
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
    fioLabel = new QLabel(vkUser.getFirstName());
    idLabel = new QLabel(QString::number(vkUser.getId()));
    friendFio = new QLabel();
    numCommonFriends = new QLabel();
    numCommonGroups = new QLabel();
    layout->addWidget(new QLabel(QObject::tr("ID:")), i,0);
    layout->addWidget(idLabel, i++, 1);
    layout->addWidget(fio_label, i, 0);
    layout->addWidget(fioLabel, i++, 1);

    layout->addWidget(new QLabel(QObject::tr("Friend FIO:")), i, 0);
    layout->addWidget(friendFio, i++, 1);

    layout->addWidget(new QLabel(QObject::tr("Number Common Friends:")), i, 0);
    layout->addWidget(numCommonFriends, i++, 1);

    layout->addWidget(new QLabel(QObject::tr("Number Common Groups:")), i, 0);
    layout->addWidget(numCommonGroups, i++, 1);

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
}

//void Dialog::selectFriend(QString idUser, QGroupBox *grid){

//    User user = vkServise->getUser(id);
//    const VkUser vkUser = user.getVkUser();
//    QList<VkUser> users = generate();
//    VkUser vkUser = users.at(0);
//    QLabel *fio_label =  new QLabel(QObject::tr("FIO:"));
//    QLabel *fio = new QLabel(vkUser.getFirstName());
//    layout->addWidget(fio_label, 0, 0);
//    layout->addWidget(fio, 0, 1);
////    QList<VkUser> friends = vkServise->getFriends(id);
//    Node *center = new Node(&vkUser);
//     QList<VkUser> friends = users;
//     QList<Node*> *nodes = new QList<Node*>();
//    diagram->insert_atribut(vkUser.getFirstName().toStdString(), vkUser);
//    foreach (VkUser user, friends) {
//        Er<VkUser> *er = new Er<VkUser>();
//        er -> insert_atribut(user.getFirstName().toStdString(), user);
//        diagram->insert_relation(QObject::tr("Has").toStdString(), er);
//        nodes->append(new Node(&user));
//    }

//    GraphWidget *graphwidget = new GraphWidget(center, nodes, grid);
//    layout->addWidget(graphwidget, 0, 3, 4, 1);
//    grid->setLayout(layout);
//}

