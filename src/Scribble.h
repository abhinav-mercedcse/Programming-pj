#pragma once

#include "Shape.h"
#include "Point.h"
#include <vector>

class Scribble : public Shape {
private:
    std::vector<Point> points;

public:
    Scribble(float r, float g, float b);

    void addPoint(float x, float y);

    void draw() ;
    bool contains(float x, float y);
    void move(float dx, float dy);
    void setColor(float r, float g, float b);
    void setPosition(float newX, float newY);
    void resize(float size);

    float getX() const;
    float getY() const ;
};
