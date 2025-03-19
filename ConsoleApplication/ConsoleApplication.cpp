#include <iostream>
#include "triangle.h"

int main() {
    Triangle triangle;
    std::cout << "Enter the coordinates of the triangle vertices:\n";
    std::cout << "Vertex A (x y): ";
    std::cin >> triangle.vertexA.x >> triangle.vertexA.y;
    std::cout << "Vertex B (x y): ";
    std::cin >> triangle.vertexB.x >> triangle.vertexB.y;
    std::cout << "Vertex C (x y): ";
    std::cin >> triangle.vertexC.x >> triangle.vertexC.y;

    if (isTriangleDegenerate(triangle)) {
        std::cout << "The triangle is degenerate.\n";
        return 1;
    }

    int numPoints;
    std::cout << "Enter the number of points to check: ";
    std::cin >> numPoints;

    for (int i = 0; i < numPoints; ++i) {
        Point point;
        std::cout << "Enter the coordinates of point " << i + 1 << " (x y): ";
        std::cin >> point.x >> point.y;

        if (isPointInsideTriangle(triangle, point)) {
            if (isPointOnTriangleBoundary(triangle, point)) {
                std::cout << "Point " << i + 1 << " lies on the boundary of the triangle.\n";
            } else {
                std::cout << "Point " << i + 1 << " is inside the triangle.\n";
            }
        } else {
            std::cout << "Point " << i + 1 << " is outside the triangle.\n";
        }
    }

    return 0;
}