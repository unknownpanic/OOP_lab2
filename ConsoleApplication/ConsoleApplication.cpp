#include <iostream>
#include "triangle.h"

using namespace std;

int main() {
    Triangle triangle;
    cout << "Enter the coordinates of the triangle vertices:\n";
    cout << "Vertex A (x y): ";
    cin >> triangle.vertexA.x >> triangle.vertexA.y;
    cout << "Vertex B (x y): ";
    cin >> triangle.vertexB.x >> triangle.vertexB.y;
    cout << "Vertex C (x y): ";
    cin >> triangle.vertexC.x >> triangle.vertexC.y;

    if (isTriangleDegenerate(triangle)) {
        cout << "The triangle is degenerate.\n";
        return 1;
    }

    int numPoints;
    cout << "Enter the number of points to check: ";
    cin >> numPoints;

    for (int i = 0; i < numPoints; ++i) {
        Point point;
        cout << "Enter the coordinates of point " << i + 1 << " (x y): ";
        cin >> point.x >> point.y;

        if (isPointInsideTriangle(triangle, point)) {
            if (isPointOnTriangleBoundary(triangle, point)) {
                cout << "Point " << i + 1 << " lies on the boundary of the triangle.\n";
            } else {
                cout << "Point " << i + 1 << " is inside the triangle.\n";
            }
        } else {
            cout << "Point " << i + 1 << " is outside the triangle.\n";
        }
    }

    return 0;
}