#include "Scribble.h"
#include <GL/gl.h>
#include <cmath>

Scribble::Scribble(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

void Scribble::addPoint(float x, float y) {
    points.push_back(Point(x, y, r, g, b));
}

void Scribble::draw() {
    glColor3f(r, g, b);
    glPointSize(5.0);
    glBegin(GL_POINTS);
    for (std::size_t i = 0; i < points.size(); i++) {
        glVertex2f(points[i].getX(), points[i].getY());
    }
    glEnd();
}

bool Scribble::contains(float x, float y) {
    for (std::size_t i = 0; i < points.size(); i++) {
        float dx = points[i].getX() - x;
        float dy = points[i].getY() - y;
        if (std::sqrt(dx * dx + dy * dy) < 0.1) {
            return true;
        }
    }
    return false;
}

void Scribble::move(float dx, float dy) {
    for (std::size_t i = 0; i < points.size(); i++) {
        float newX = points[i].getX() + dx;
        float newY = points[i].getY() + dy;
        points[i].setX(newX);
        points[i].setY(newY);
    }
}

void Scribble::setColor(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
    for (std::size_t i = 0; i < points.size(); i++) {
        points[i].setColor(r, g, b);
    }
}

float Scribble::getX() const {
    if (points.empty()) {
        return 0.0;
    } 
    else {
        return points[0].getX();
    }
}

float Scribble::getY() const {
    if (points.empty()) {
        return 0.0;
    }
    else {
        return points[0].getY();
    }
}

void Scribble::setPosition(float newX, float newY) {
    float currentX = getX();
    float currentY = getY();
    float dx = newX - currentX;
    float dy = newY - currentY;
    move(dx, dy);
}

