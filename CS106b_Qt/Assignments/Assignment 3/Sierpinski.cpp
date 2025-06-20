#include "Sierpinski.h"
#include "error.h"
using namespace std;

/**
 * Draws a triangle with the specified corners in the specified window. Feel free
 * to edit this function as you see fit to change things like color, fill style,
 * etc. in whatever way you'd like!
 *
 * @param window The window in which to draw the triangle.
 * @param x0 y0 The first corner of the triangle.
 * @param x1 y1 The second corner of the triangle.
 * @param x2 y2 The third corner of the triangle.
 */
void drawTriangle(GWindow& window,
                  double x0, double y0,
                  double x1, double y1,
                  double x2, double y2) {
    window.setColor("black");
    window.fillPolygon({ x0, y0, x1, y1, x2, y2 });
}

/* TODO: Refer to Sierpinski.h for more information about what this function should do.
 * Then, delete this comment.
 */
void drawSierpinskiTriangle(GWindow& window,
                            double x0, double y0,
                            double x1, double y1,
                            double x2, double y2,
                            int order) {
    if (order < 0) {
        error("invalid order!");
    } else if (order == 0) {
        drawTriangle(window, x0, y0, x1, y1, x2, y2);
    } else {
        double ax = (x0 + x1) / 2;
        double ay = (y0 + y1) / 2;
        double bx = (x0 + x2) / 2;
        double by = (y0 + y2) / 2;
        double cx = (x1 + x2) / 2;
        double cy = (y1 + y2) / 2;
        drawSierpinskiTriangle(window, x0, y0, ax, ay, bx, by, order - 1);
        drawSierpinskiTriangle(window, ax, ay, x1, y1, cx, cy, order - 1);
        drawSierpinskiTriangle(window, bx, by, cx, cy, x2, y2, order - 1);
    }
}
