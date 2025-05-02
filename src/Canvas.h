#ifndef CANVAS_H
#define CANVAS_H

#include <bobcat_ui/all.h>
#include <vector>
#include "Point.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Scribble.h"
#include "Shape.h"

class Canvas : public bobcat::Canvas_ {
    std::vector<Point*> points;
    std::vector<Shape*> shapes;
    Shape* draggedShape;
    float dragX = 0;
    float dragY = 0;
    Scribble* currentScribble = nullptr;


public:
    Canvas(int x, int y, int w, int h);

    void addPoint(float x, float y, float r, float g, float b, int size);

    void addRectangle(float x, float y, float r, float g, float b);

    void addCircle(float x, float y, float r, float g, float b);

    void addTriangle(float x, float y, float r, float g, float b);

    void addPolygon(float x, float y, float r, float g, float b);

    void addScribble(float x, float y);

    void startScribble(float r, float g, float b);

    void handleEraserClick(float x, float y);

    void clear();

    void render();

    Shape* getSelectedShape(float mx, float my);
};

#endif