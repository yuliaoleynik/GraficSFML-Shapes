#ifndef LINE_H
#define LINE_H
#include "Shapes.h"

class Line : public Shapes
{
private:
    int size_of_vertices = 2;
    sf::VertexArray line;
    ShapeList m_type = ShapeList ::Line;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            states.transform *= getTransform();
            target.draw(line, states);
        }
public:
    Line();
    virtual ~Line();
    int collor;

    VertexArray &get_vertices();

    virtual void Change_Collor(int counter);
    virtual ShapeList get_type(){return m_type;}
    virtual Shapes* Copy_Figure();
    virtual int Get_Collor(){return collor;}
};

#endif // LINE_H
