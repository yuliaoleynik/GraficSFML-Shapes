#include "triangle.h"

Triangle::Triangle()
{
    triangle.setPrimitiveType(sf::Triangles);
    triangle.resize(size_of_vertices);

    triangle[0].position = Vector2f(410.f, 350.f);
    triangle[1].position = Vector2f(500.f, 200.f);
    triangle[2].position = Vector2f(590.f,350.f);

    for(int i = 0; i<size_of_vertices ;i++)
        triangle[i].color = Color::White;

    setOrigin(500.f,300.f);
    SetCenter();
}

Triangle::~Triangle()
{

}


VertexArray& Triangle :: get_vertices()
{
    return triangle;
}

void Triangle ::Change_Collor(int counter)
{
    switch(counter)
    {
       case 0 :
               for(int i = 0; i < size_of_vertices; i++)
                 triangle[i].color = Color::Magenta;
        break;
       case 1 :
               for(int i = 0; i < size_of_vertices; i++)
                 triangle[i].color = Color::Red;
        break;
       case 2 :
               for(int i = 0; i < size_of_vertices; i++)
                 triangle[i].color = Color::Blue;
        break;
       case 3 :
               for(int i = 0; i < size_of_vertices; i++)
                 triangle[i].color = Color::Green;
        break;
       case 4 :
               for(int i = 0; i < size_of_vertices; i++)
                 triangle[i].color = Color::Yellow;
        break;
    }
    collor = counter;
}

Shapes* Triangle :: Copy_Figure()
{
    return new Triangle(*this);
}
