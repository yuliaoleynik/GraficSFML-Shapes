#include "square.h"

Square::Square()
{
    quad.setPrimitiveType(sf::Quads);
    quad.resize(size_of_vertices);

    quad[0].position = Vector2f(450.f, 350.f);
    quad[1].position = Vector2f(450.f, 200.f);
    quad[2].position = Vector2f(600.f, 200.f);
    quad[3].position = Vector2f(600.f, 350.f);

    for(int i = 0; i< size_of_vertices; i++)
        quad[i].color = Color::White;

    setOrigin(525.f,275.f);
    SetCenter();
}


Square::~Square()
{

}


VertexArray& Square :: get_vertices()
{
    return quad;
}

void Square ::Change_Collor(int counter)
{
    switch(counter)
    {
       case 0 :
               for(int i = 0; i < size_of_vertices; i++)
                 quad[i].color = Color::Magenta;
        break;
       case 1 :
               for(int i = 0; i < size_of_vertices; i++)
                 quad[i].color = Color::Red;
        break;
       case 2 :
               for(int i = 0; i < size_of_vertices; i++)
                 quad[i].color = Color::Blue;
        break;
       case 3 :
               for(int i = 0; i < size_of_vertices; i++)
                 quad[i].color = Color::Green;
        break;
       case 4 :
               for(int i = 0; i < size_of_vertices; i++)
                 quad[i].color = Color::Yellow;
        break;
    }
    collor = counter;
}

Shapes* Square :: Copy_Figure()
{
    return new Square(*this);
}
