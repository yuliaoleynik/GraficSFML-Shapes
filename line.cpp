#include "line.h"


Line:: Line()
{
    line.setPrimitiveType(sf::LinesStrip);
    line.resize(size_of_vertices);

    line[0].position = Vector2f(350.f, 350.f);
    line[1].position = Vector2f(450.f, 350.f);

    for(int i = 0; i < size_of_vertices; i++)
        line[i].color = Color::White;

    setOrigin(400.f,350.f);
    SetCenter();
}

Line ::~Line()
{

}

VertexArray& Line :: get_vertices()
{
    return line;
}

void Line :: Change_Collor(int counter)
{
        switch(counter)
        {
           case 0 :
                   for(int i = 0; i < size_of_vertices; i++)
                     line[i].color = Color::Magenta;
            break;
           case 1 :
                   for(int i = 0; i < size_of_vertices; i++)
                     line[i].color = Color::Red;
            break;
           case 2 :
                   for(int i = 0; i < size_of_vertices; i++)
                     line[i].color = Color::Blue;
            break;
           case 3 :
                   for(int i = 0; i < size_of_vertices; i++)
                     line[i].color = Color::Green;
            break;
           case 4 :
                   for(int i = 0; i < size_of_vertices; i++)
                     line[i].color = Color::Yellow;
            break;
        }
        collor = counter;
}

Shapes* Line :: Copy_Figure()
{
    return new Line(*this);
}
