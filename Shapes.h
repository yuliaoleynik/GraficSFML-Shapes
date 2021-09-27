#ifndef SHAPES_H
#define SHAPES_H
#include "dir.h"
#include <fstream>

class Shapes: public sf::Drawable, public sf::Transformable
{
private:
    bool m_visible = true;
    bool m_trace = true;
    bool m_trajectory = true;

    float m_x=500,m_y=300;
    string name;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const{}   
public:    
    Shapes();
    virtual ~Shapes();

    vector <string> trajectory;

    enum ShapeList
    {
      Circle,
      Triangle,
      Square,
      Star,
      Line
    };

    void  set_Visible()
    {
        m_visible = !m_visible;
    }
    bool get_Visible(){return m_visible;}

    void  set_Trace()
    {
        m_trace = !m_trace;
    }
    bool get_Trace(){return m_trace;}

    void SetCenter()
    {
        setPosition(m_x,m_y);
    }

    void  Set_M_Trajectory()
    {
        m_trajectory = !m_trajectory;
    }
    bool Get_M_Trajectory(){return m_trajectory;}
    void Delet_Trajectory(){trajectory.clear();}
    void Write_Trajectory(const string direction);
    string Output_Trajectory(size_t index);
    size_t Size_Vector(){return trajectory.size();}

    void Set_Name(const string name)
    {
        this->name = name;
    }
    string Get_Name()
    {
        return name;
    }

    virtual void Change_Collor(int counter){}
    virtual ShapeList get_type(){}
    virtual Shapes* Copy_Figure(){}
    virtual int Get_Collor(){}
};

#endif // SHAPES_H

