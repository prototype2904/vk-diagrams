#ifndef DIALOG_H
#define DIALOG_H

#include <QtWidgets/QDialog>
#include <servise/userservicefacade.h>
#include <er_diagram.h>
#include <servise/VkServise.h>

class VkServise;

QT_BEGIN_NAMESPACE
class QAction;
class QDialogButtonBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QMenu;
class QMenuBar;
class QPushButton;
class QTextEdit;
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog();
    void submitVkUser(QString idUser, QGroupBox *grid);
    void selectFriend(QGroupBox *grid);
    void setNumCommonFriedns(int number){
        this->numCommonFriends->setText(QString::number(number));
    }
    void setNumCommonGroups(int number){
        this->numCommonGroups->setText(QString::number(number));
    }
private slots:
    void submit();
private:
    void createMenu();
    void createHorizontalGroupBox();
    void createGridGroupBox();
    void createFormGroupBox();

    enum { NumGridRows = 3, NumButtons = 4 };

    QPushButton *submitButton;
    QLineEdit *idInput;
    UserServiceFacade *userServiceFacade;

    QLabel* fioLabel;
    QLabel* idLabel;
    QMenuBar *menuBar;
    QGroupBox *horizontalGroupBox;
    QGroupBox *gridGroupBox;
    QGroupBox *formGroupBox;
    QTextEdit *smallEditor;
    QTextEdit *bigEditor;
    QLabel *labels[NumGridRows];
    QLineEdit *lineEdits[NumGridRows];
    QPushButton *buttons[NumButtons];
    QDialogButtonBox *buttonBox;

    QMenu *fileMenu;
    QAction *exitAction;
    Er<VkUser> *diagram;
    VkServise *vkServise;

     QLabel* friendFio;
     QLabel* numCommonFriends;
     QLabel* numCommonGroups;
};
#endif
