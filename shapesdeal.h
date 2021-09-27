#ifndef SHAPESDEAL_H
#define SHAPESDEAL_H
#include "Shapes.h"
#include "square.h"
#include "triangle.h"
#include "star.h"
#include "line.h"
#include "circle.h"
#include "agregate.h"

class ShapesDeal
{
private:
    size_t active_object = 0;
    size_t index = 0;

    int counter = 0;
    string direction;

    float rotation_step = 5.f;
    float rotate = 0.f;
    Vector2f position;

    vector <Shapes*> objects;
public:
    string m_file;

    ShapesDeal();
    ShapesDeal (string file);
    ~ShapesDeal();

    void Menu();
    void WindowShow();
    void AddFigure();
    void Reset();
    void Agregation();
    void AddSquare();
    void Save();
    void Load();
};
#endif // SHAPESDEAL_H
