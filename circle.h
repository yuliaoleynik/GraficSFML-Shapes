#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shapes.h"

class Circle : public Shapes
{
private:
   int size_of_vertices = 70;
   VertexArray circle;
   ShapeList m_type = ShapeList ::Circle;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            states.transform *= getTransform();
            target.draw(circle, states);
        }
public:
    Circle();
    virtual ~Circle();
    int collor;


    virtual void Change_Collor(int counter);
    virtual ShapeList get_type(){return m_type;}
    virtual Shapes* Copy_Figure();
    virtual int Get_Collor(){return collor;}
};

#endif // CIRCLE_H
