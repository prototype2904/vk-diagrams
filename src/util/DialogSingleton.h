#ifndef DIALOGSINGLETON_H
#define DIALOGSINGLETON_H

#include "dialog.h"

class Dialog;

class DialogSingleton
{
  public:
    static Dialog& get()
    {
        // согласно стандарту, этот код ленивый и потокобезопасный
        static Dialog s;
        return s;
    }

  private:
    DialogSingleton() {}
};

#endif // DIALOGSINGLETON_H
