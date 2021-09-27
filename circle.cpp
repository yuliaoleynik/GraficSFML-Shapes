#include "circle.h"

Circle::Circle()
{
    int index = 0;
    float m_radius = 60.f;

    circle.setPrimitiveType(sf::TriangleFan);
    circle.resize(size_of_vertices);

    while(index < size_of_vertices)
    {
        static const float pi = 3.141592654f;

        float angle = index * 2 * pi / size_of_vertices - pi / 2;
        float x = std::cos(angle) * m_radius;
        float y = std::sin(angle) * m_radius;
        circle[index].position = Vector2f(m_radius+x, m_radius+y);

        circle[index].color = Color::White;
        ++index;
    }

    setOrigin(60,60);
    SetCenter();

}

Circle::~Circle()
{

}

void Circle :: Change_Collor(int counter)
{
        switch(counter)
        {
           case 0 :
                   for(int i = 0; i < size_of_vertices; i++)
                     circle[i].color = Color::Magenta;
            break;
           case 1 :
                   for(int i = 0; i < size_of_vertices; i++)
                     circle[i].color = Color::Red;
            break;
           case 2 :
                   for(int i = 0; i < size_of_vertices; i++)
                     circle[i].color = Color::Blue;
            break;
           case 3 :
                   for(int i = 0; i < size_of_vertices; i++)
                     circle[i].color = Color::Green;
            break;
           case 4 :
                   for(int i = 0; i < size_of_vertices; i++)
                     circle[i].color = Color::Yellow;
            break;
        }

        collor = counter;
}

Shapes* Circle :: Copy_Figure()
{
    return new Circle(*this);
}

