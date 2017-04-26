#ifndef USERSERVICEFACADE_H
#define USERSERVICEFACADE_H
#include <er_diagram.h>
#include <node.h>
#include <servise/VkServise.h>
#include <QtWidgets>
#include <QtWidgets/QDialog>


template <typename T> class Er;
class VkServise;

class UserServiceFacade
{
public:
    static Er<VkUser>* getDiagram();
    UserServiceFacade();
private:
    static Node* centerNode;
    static Er<VkUser> *diagram;
    static VkServise *vkServise;
    static QGroupBox *grid;
};

#endif // USERSERVICEFACADE_H
