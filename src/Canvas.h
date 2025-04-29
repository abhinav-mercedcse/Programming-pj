#ifndef CANVAS_H
#define CANVAS_H

#include <bobcat_ui/all.h>
#include <vector>
#include "Point.h"
#include "Rectangle.h"

class Canvas : public bobcat::Canvas_ {
    std::vector<Point*> points;
    std::vector<Rectangle*> rectangles;

public:
    Canvas(int x, int y, int w, int h);

    void addPoint(float x, float y, float r, float g, float b, int size);

    void addRectangle(float x, float y, float width, float height, float r, float g, float b);

    void clear();

    void render();
};

#endif