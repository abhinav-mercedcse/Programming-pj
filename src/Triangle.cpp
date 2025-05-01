#include "Triangle.h"
#include <GL/freeglut.h>

Triangle::Triangle() {
    x = 0.0;
    y = 0.0;
    width = 0.4;
    height = 0.4;
    r = 0.0;
    g = 0.0;
    b = 0.0;
}

Triangle::Triangle(float x, float y, float width, float height, float r, float g, float b) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->r = r;
    this->g = g;
    this->b = b;
}

void Triangle::draw() {
    glColor3f(r, g, b); 

    glBegin(GL_TRIANGLES);
        glVertex2f(x, y + height / 2);
        glVertex2f(x - width / 2, y - height / 2);  
        glVertex2f(x + width / 2, y - height / 2);  
    glEnd();
}
