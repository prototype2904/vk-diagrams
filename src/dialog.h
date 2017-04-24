#ifndef DIALOG_H
#define DIALOG_H

#include <QtWidgets/QDialog>
#include <servise/userservicefacade.h>

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
    static void setNumCommonFriedns(int number){
        Dialog::numCommonFriends->setText(QString::number(number));
    }
    static void setNumCommonGroups(int number){
        Dialog::numCommonGroups->setText(QString::number(number));
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

    static QLabel* friendFio;
    static QLabel* numCommonFriends;
    static QLabel* numCommonGroups;
};
#endif
