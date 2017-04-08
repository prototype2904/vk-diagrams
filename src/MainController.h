#ifndef VKCONTROLLER_H
#define VKCONTROLLER_H

#include "servise/VkServise.h"
class MainController
{
public:
   static MainController& Instance()
   {
       static MainController s;
       return s;
   }
private:
    MainController();
    ~MainController();
    MainController(MainController const&) = delete;
    MainController& operator= (MainController const&) = delete;
    VkServise vkSer;
    void init();
};

#endif // VKCONTROLLER_H
