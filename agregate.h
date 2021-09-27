#ifndef AGREGATE_H
#define AGREGATE_H
#include "Shapes.h"


class Agregate: public Shapes
{
private:
    vector<Shapes*> agregats;
    int collor;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            states.transform *= getTransform();
           for(size_t i = 0; i < agregats.size();i++)
           {
               target.draw(*agregats[i], states);
           }
        }
public:
    Agregate(Shapes* obj_1,Shapes* obj_2);
    virtual ~Agregate();

    virtual Shapes* Copy_Figure();
    virtual void Change_Collor(int counter);
    virtual ShapeList get_type(){}
    virtual int Get_Collor(){return collor;}
};

#endif // AGREGATE_H
