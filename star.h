#ifndef STAR_H
#define STAR_H
#include "Shapes.h"

class Star: public Shapes
{
private:
    int size_of_vertices = 12;
    sf::VertexArray star;
    ShapeList m_type = ShapeList :: Star;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            states.transform *= getTransform();
            target.draw(star, states);
        }
public:
    Star();
    virtual ~Star();
    int collor;

    VertexArray& get_vertices();

    virtual void Change_Collor(int counter);
    virtual ShapeList get_type(){return m_type;}
    virtual Shapes* Copy_Figure();
    virtual int Get_Collor(){return collor;}
};


#endif // STAR_H
