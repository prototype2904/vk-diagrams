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

    socialGrpahButton = new QPushButton(tr("Нарисовать социальный граф"));
    connect(socialGrpahButton, SIGNAL(released()), this, SLOT(createSocialGraph()));

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
    horizontalGroupBox = new QGroupBox(tr("Input id"));
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(idInput);
    layout->addWidget(submitButton);
    layout->addWidget(socialGrpahButton);
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

//    GraphWidget *graphwidget = new GraphWidget(this);
//    layout->addWidget(graphwidget, 0, 2, 4, 1);

//    layout->setColumnStretch(1, 10);
//    layout->setColumnStretch(2, 20);
//    gridGroupBox->setLayout(layout);
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

    if(grid != NULL){
        while(grid->layout() != NULL && grid->layout()->count() != 0)
        {
          delete grid->layout()->itemAt(0)->widget();
        }
        delete grid->layout();
    }
    QGridLayout *layout = new QGridLayout();
     layout->activate();
    ER<User*>* er = userServiceFacade->createER(idUser);
    GraphWidget *graphwidget = new GraphWidget(this, er);
    layout->addWidget(graphwidget, 0, 2, i, 1);
    grid->setLayout(layout);
    this->layout = layout;
    diagram = er;
    this->graphwidget = graphwidget;
}

void Dialog::createSocialGraph(){
    delete this->layout;
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

