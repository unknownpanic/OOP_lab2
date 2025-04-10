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
        std::cout << "Warning: The triangle is degenerate. Points will be checked regardless.\n";
    }

    int methodChoice;
    cout << "Choose the method to check the points:\n";
    cout << "1. Vector Cross Product Method\n";
    cout << "2. Heron's Formula Method\n";
    cout << "Your choice: ";
    cin >> methodChoice;

    int numPoints;
    cout << "Enter the number of points to check: ";
    cin >> numPoints;

    double epsilon;
    cout << "Enter the error tolerance (e.g., 1e-9): ";
    cin >> epsilon;

    for (int i = 0; i < numPoints; ++i) {
        Point point;
        cout << "Enter the coordinates of point " << i + 1 << " (x y): ";
        cin >> point.x >> point.y;

        bool isInside = false;
        bool isOnBoundary = isPointOnTriangleBoundary(triangle, point, epsilon);

        if (methodChoice == 1) {
            isInside = isPointInsideTriangleVector(triangle, point, epsilon);
        } else if (methodChoice == 2) {
            isInside = isPointInsideTriangleHeron(triangle, point, epsilon);
        } else {
            cout << "Invalid method choice. Exiting...\n";
            return 1;
        }

        if (isOnBoundary) {
            cout << "Point " << i + 1 << " lies on the boundary of the triangle.\n";
        } else if (isInside) {
            cout << "Point " << i + 1 << " is inside the triangle.\n";
        } else {
            cout << "Point " << i + 1 << " is outside the triangle.\n";
        }
    }

    return 0;
}