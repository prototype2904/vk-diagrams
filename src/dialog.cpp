#include "dialog.h"
#include <QtWidgets>

Dialog::Dialog()
{
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

    smallEditor = new QTextEdit;
    smallEditor->setPlainText(tr("This widget takes up about two thirds of the "
                                 "grid layout."));
    layout->addWidget(smallEditor, 0, 2, 4, 1);

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
