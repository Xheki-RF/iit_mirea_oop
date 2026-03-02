#ifndef __CHARACTER__H
#define __CHARACTER__H

class Character
{
private:
    int hp;

public:
    void setHP(int hp);
    int getHP();
    void changeHP(int hp);
};

#endif