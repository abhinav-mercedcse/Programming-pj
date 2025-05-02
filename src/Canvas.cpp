#include "Canvas.h"
#include "Polygon.h"
#include "Triangle.h"
#include <GL/freeglut.h>

Canvas::Canvas(int x, int y, int w, int h) : Canvas_(x, y, w, h) {
    // 
}

void Canvas::addPoint(float x, float y, float r, float g, float b, int size) {
    points.push_back(new Point(x, y, r, g, b, size));
}

void Canvas::addRectangle(float x, float y, float width, float height, float r, float g, float b) {
    rectangles.push_back(new Rectangle(x, y, width, height, r, g, b));
}

void Canvas::addTriangle(float x, float y, float width, float height, float r, float g, float b) {
    triangles.push_back(new Triangle(x, y, width, height, r, g, b));
}

void Canvas::clear() {
    for (unsigned int i = 0 ; i < points.size(); i++) {
        delete points[i];
    }
    points.clear();

    for (unsigned int i = 0 ; i < rectangles.size(); i++) {
        delete rectangles[i];
    }
    rectangles.clear();

    for (unsigned int i = 0 ; i < triangles.size(); i++) {
        delete triangles[i];
    }
    triangles.clear();

    for (unsigned int i = 0 ; i < circles.size(); i++) {
        delete circles[i];
    }
    circles.clear();
    
    for (unsigned int i = 0 ; i < polygons.size(); i++) {
        delete polygons[i];
    }
    polygons.clear();
}

void Canvas::render() {
    for (unsigned int i = 0 ; i < points.size(); i++) {
        points[i]->draw();
    }

    for (unsigned int i = 0 ; i < rectangles.size(); i++) {
        rectangles[i]->draw();
    }

    for (unsigned int i = 0 ; i < triangles.size(); i++) {
        triangles[i]->draw();
    }

    for (unsigned int i = 0 ; i < circles.size(); i++) {
        circles[i]->draw();
    }

    for (unsigned int i = 0 ; i < polygons.size(); i++) {
        polygons[i]->draw();
    }
}