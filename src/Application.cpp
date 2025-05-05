#include "Application.h"
#include "Enums.h"
#include "Point.h"
#include "Canvas.h"

using namespace bobcat;
using namespace std;

void Application::onCanvasMouseDown(bobcat::Widget* sender, float mx, float my) {
    TOOL tool = toolbar->getTool();
    Color color = colorSelector->getColor();

    if (tool == PENCIL) {
        canvas->startScribble(color.getR(), color.getG(), color.getB());
        canvas->addScribble(mx, my);
        canvas->redraw();
    }
    else if (tool == ERASER) {
        canvas->addPoint(mx, my, 1.0, 1.0, 1.0, 7);
        canvas->redraw();
    }
    else if (tool == RECTANGLE) {
        canvas->addRectangle(mx, my, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == CIRCLE) { 
        canvas->addCircle(mx, my, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == TRIANGLE) { 
        canvas->addTriangle(mx, my, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == POLYGON) { 
        canvas->addPolygon(mx, my, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == MOUSE) {
        selectedShape = canvas->getSelectedShape(mx, my);
        if (selectedShape){
            dragging = true;
            dragX = mx - selectedShape->getX();
            dragY = my - selectedShape->getY();
        }
    }

}

void Application::onCanvasDrag(bobcat::Widget* sender, float mx, float my) {
    TOOL tool = toolbar->getTool();
    Color color = colorSelector->getColor();
    
    if (tool == MOUSE && dragging && selectedShape) {
        selectedShape->setPosition(mx - dragX, my - dragY);
        canvas->redraw();
    }
    if (tool == PENCIL) {
        canvas->addScribble(mx, my);
        canvas->redraw();
    }
    else if (tool == ERASER) {
        canvas->handleEraserClick(mx, my);
        canvas->redraw();
    }

}

void Application::onToolbarChange(bobcat::Widget* sender) {
    ACTION action = toolbar->getAction();
    TOOL tool = toolbar->getTool();

    if (action == CLEAR) {
        canvas->clear();
        canvas->redraw();
    }
    else if (action == FRONT){
        canvas->bringToFront(selectedShape);
        canvas->redraw();
    }
    else if (action == BACK){
        canvas->bringToBack(selectedShape);
        canvas->redraw();
    }

    if (tool != MOUSE) {
        selectedShape = nullptr;
    }
    
}

void Application::onColorSelectorChange(bobcat::Widget* sender) {
    Color color = colorSelector->getColor();

    if (selectedShape) {
        cout << "Update selected shape color" << endl;
        selectedShape->setColor(color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
}

Application::Application() {
    window = new Window(25, 75, 400, 400, "Programming Project");

    selectedShape = nullptr;

    toolbar = new Toolbar(0, 0, 50, 400);
    canvas = new Canvas(50, 0, 350, 350);
    colorSelector = new ColorSelector(50, 350, 350, 50);
    colorSelector->box(FL_BORDER_BOX);

    window->add(toolbar);
    window->add(canvas);
    window->add(colorSelector);

    ON_MOUSE_DOWN(canvas, Application::onCanvasMouseDown);
    ON_DRAG(canvas, Application::onCanvasDrag);
    ON_CHANGE(toolbar, Application::onToolbarChange);
    ON_CHANGE(colorSelector, Application::onColorSelectorChange);

    window->show();
}