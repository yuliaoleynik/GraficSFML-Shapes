#include "Shapes.h"
#include "line.h"
#include "square.h"
#include "triangle.h"
#include "star.h"
#include "circle.h"

Shapes::Shapes()
{

}

Shapes::~Shapes()
{

}

void Shapes :: Write_Trajectory(const string direction)
{
    trajectory.push_back(direction);
}

string Shapes :: Output_Trajectory(size_t index)
{
    return trajectory[index];
}
