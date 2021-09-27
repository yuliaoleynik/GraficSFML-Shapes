#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shapes.h"

class Triangle: public Shapes
{
private:
    int size_of_vertices = 3;
    sf::VertexArray triangle;
    ShapeList m_type = ShapeList :: Triangle;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            states.transform *= getTransform();
            target.draw(triangle, states);
        }
public:
    Triangle();
    virtual ~Triangle();
    int collor;

    VertexArray &get_vertices();

    virtual void Change_Collor(int counter);
    virtual ShapeList get_type(){return m_type;}
    virtual Shapes* Copy_Figure();
    virtual int Get_Collor(){return collor;}
};

#endif // TRIANGLE_H
