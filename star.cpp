#include "star.h"

Star::Star()
{
    star.setPrimitiveType(sf::TriangleFan);
    star.resize(size_of_vertices);

    star[0].position = Vector2f(500.f, 300.f);
    star[1].position = Vector2f(503.f, 200.f);
    star[2].position = Vector2f(528.f, 270.f);
    star[3].position = Vector2f(600.f,270.f);
    star[4].position = Vector2f(540.f,315.f);
    star[5].position = Vector2f(560.f,390.f);
    star[6].position = Vector2f(500.f,350.f);
    star[7].position = Vector2f(440.f,390.f);
    star[8].position = Vector2f(463.f,315.f);
    star[9].position = Vector2f(400.f,270.f);
    star[10].position = Vector2f(475.f,270.f);
    star[11].position = Vector2f(503.f, 200.f);

    for(int i = 0; i < size_of_vertices ;i++)
      star[i].color = Color::White;

    setOrigin(500.f,300.f);
    SetCenter();

}


Star::~Star()
{

}


VertexArray& Star :: get_vertices()
{
    return star;
}

void Star ::Change_Collor(int counter)
{
    switch(counter)
    {
       case 0 :
               for(int i = 0; i < size_of_vertices; i++)
                 star[i].color = Color::Magenta;
        break;
       case 1 :
               for(int i = 0; i < size_of_vertices; i++)
                 star[i].color = Color::Red;
        break;
       case 2 :
               for(int i = 0; i < size_of_vertices; i++)
                 star[i].color = Color::Blue;
        break;
       case 3 :
               for(int i = 0; i < size_of_vertices; i++)
                 star[i].color = Color::Green;
        break;
       case 4 :
               for(int i = 0; i < size_of_vertices; i++)
                 star[i].color = Color::Yellow;
        break;
    }
    collor = counter;
}

Shapes* Star :: Copy_Figure()
{
    return new Star(*this);
}
