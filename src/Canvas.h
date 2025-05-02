#ifndef CANVAS_H
#define CANVAS_H

#include <bobcat_ui/all.h>
#include <vector>
#include "Point.h"
#include "Rectangle.h"
#include "Triangle.h"

class Canvas : public bobcat::Canvas_ {
    std::vector<Point*> points;
    std::vector<Rectangle*> rectangles;
    std::vector<Triangle*> triangles;

public:
    Canvas(int x, int y, int w, int h);

    void addPoint(float x, float y, float r, float g, float b, int size);

    void addRectangle(float x, float y, float width, float height, float r, float g, float b);
    
    void addTriangle(float x, float y, float base, float height, float r, float g, float b);

    void clear();
    //LALALALALALALALALLAALLALAL
    void render();
};

#endif
