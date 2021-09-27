#ifndef SQUARE_H
#define SQUARE_H
#include "Shapes.h"

class Square: public Shapes
{
private:
    int size_of_vertices = 4;
    sf::VertexArray quad;
    ShapeList m_type = ShapeList :: Square;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            states.transform *= getTransform();
            target.draw(quad, states);
        }
public:
    Square();
    virtual ~Square();
    int collor;

    VertexArray& get_vertices();

    virtual void Change_Collor(int counter);
    virtual ShapeList get_type(){return m_type;}
    virtual Shapes* Copy_Figure();
    virtual int Get_Collor(){return collor;}
};

#endif // SQUARE_H
