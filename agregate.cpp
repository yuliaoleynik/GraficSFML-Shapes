#include "agregate.h"

Agregate :: Agregate(Shapes* obj_1,Shapes* obj_2)
{
    agregats.push_back(obj_1);
    agregats.push_back(obj_2);

    setOrigin((obj_1 -> getPosition().x + obj_2 -> getPosition().x)/2,
              (obj_1 -> getPosition().y + obj_2 -> getPosition().y)/2);
    setPosition((obj_1 -> getPosition().x + obj_2 -> getPosition().x)/2,
            (obj_1 -> getPosition().y + obj_2 -> getPosition().y)/2);
}

Agregate :: ~Agregate()
{

}

Shapes* Agregate :: Copy_Figure()
{
    Agregate* temp = new Agregate(*this);

    for(size_t i = 0;i<agregats.size();i++)
    {
        temp -> agregats[i];
    }

    return temp;
}

void  Agregate :: Change_Collor(int counter)
{
    agregats[0] ->Change_Collor(counter);
    agregats[1] ->Change_Collor(counter);
    collor=counter;
}

