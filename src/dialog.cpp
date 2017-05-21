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
    createMenu();
    createHorizontalGroupBox();
    createHorizontalNumberGroupBox();
    createHorizontalInformationGroupBox();
    createGridGroupBox();
//    createFormGroupBox();


    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                     | QDialogButtonBox::Cancel);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setMenuBar(menuBar);
    mainLayout->addWidget(horizontalGroupBox);
    mainLayout->addWidget(horizontalNumberGroupBox);
    mainLayout->addWidget(horizontalInforamtionGroupBox);
    mainLayout->addWidget(gridGroupBox);
//    mainLayout->addWidget(formGroupBox);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

    setWindowTitle(tr("Basic Layouts"));
}

void Dialog::submit(){
    this->submitVkUser(idInput->text(), gridGroupBox);
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
    submitButton = new QPushButton(tr("Подтвердить"), this);
    horizontalGroupBox = new QGroupBox(tr("Введите id"));
    connect(submitButton, SIGNAL(released()), this, SLOT(submit()));

    socialGrpahButton = new QPushButton(tr("Нарисовать социальный граф"));
    connect(socialGrpahButton, SIGNAL(released()), this, SLOT(createSocialGraph()));

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(idInput);
    layout->addWidget(submitButton);
    layout->addWidget(socialGrpahButton);

    horizontalGroupBox->setLayout(layout);
    socialGrpahButton->setVisible(false);
}

void Dialog::createHorizontalInformationGroupBox()
{
    horizontalInforamtionGroupBox = new QGroupBox();
    information = new QLabel(this);
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(information);
    this->information->setVisible(false);
    horizontalInforamtionGroupBox->setLayout(layout);
}

void Dialog::createHorizontalNumberGroupBox()
{
    horizontalNumberGroupBox = new QGroupBox();
    QHBoxLayout *layout = new QHBoxLayout;
    QLabel *own_friends_label =  new QLabel(tr("Количество общих друзей:"));
    QLabel *own_groups =  new QLabel(tr("Количество общих групп:"));
    numCommonFriends = new QLabel(this);
    numCommonGroups = new QLabel(this);
    layout->addWidget(own_friends_label);
    layout->addWidget(numCommonFriends);
    layout->addWidget(own_groups);
    layout->addWidget(numCommonGroups);
    horizontalNumberGroupBox->setLayout(layout);
    horizontalNumberGroupBox->setVisible(false);
}



void Dialog::createGridGroupBox()
{
    gridGroupBox = new QGroupBox();
}

void Dialog::createFormGroupBox()
{
}

void Dialog::submitVkUser(QString idUser, QGroupBox *grid){
    this->information->setVisible(false);
    int i = 0;

    if(grid != NULL){
        while(grid->layout() != NULL && grid->layout()->count() != 0)
        {
          delete grid->layout()->itemAt(0)->widget();
        }
        delete grid->layout();
    }else{
        grid = new QGroupBox();
    }
    QGridLayout *layout = new QGridLayout();
     layout->activate();
    ER<User*>* er = userServiceFacade->createER(idUser);
    if(er != NULL){
        GraphWidget *graphwidget = new GraphWidget(this, er);
        layout->addWidget(graphwidget, 0, 2, i, 1);
        grid->setLayout(layout);
        this->layout = layout;
        diagram = er;
        this->graphwidget = graphwidget;
        this->socialGrpahButton->setVisible(true);
        this->graphwidget->setSelectedNode(NULL);
    }else{
        this->information->setText("Неверно введен id пользователя.");
        this->information->setVisible(true);
    }
}

void Dialog::createSocialGraph(){
    delete this->layout;
    this->socialGrpahButton->setVisible(false);
    QList<User*>* friends = userServiceFacade->getFriends( diagram->entityAt(0)->getValue());
    for(int i =0; i < friends->size(); i++){
        Entity<User*>* e = new Entity<User*>(friends->at(i));
        diagram->addEntity(e);
        diagram->addRelation(QObject::tr("Дружит"), diagram->entityAt(0), e, false, false, false, false);
    }
//    delete this->graphwidget;
    QGridLayout *layout = new QGridLayout();
    layout->activate();
    GraphWidget *graphwidget = new GraphWidget(this, diagram);
    layout->addWidget(graphwidget, 0, 2, 0, 1);
    gridGroupBox->setLayout(layout);
    this->graphwidget = graphwidget;
    this->layout = layout;
}

