#include "triangle.h"
#include <cmath>

using namespace std;

double vectorCrossProduct(const Point& A, const Point& B, const Point& C) {
    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}

bool isTriangleDegenerate(const Triangle& triangle) {
    return abs(vectorCrossProduct(triangle.vertexA, triangle.vertexB, triangle.vertexC)) == 0;
}

bool isPointInsideTriangle(const Triangle& triangle, const Point& point) {
    double d1 = vectorCrossProduct(point, triangle.vertexA, triangle.vertexB);
    double d2 = vectorCrossProduct(point, triangle.vertexB, triangle.vertexC);
    double d3 = vectorCrossProduct(point, triangle.vertexC, triangle.vertexA);

    if (d1 == 0 || d2 == 0 || d3 == 0) return false; // Точка на межі
    return (d1 > 0 && d2 > 0 && d3 > 0) || (d1 < 0 && d2 < 0 && d3 < 0);
}

bool isPointOnSegment(const Point& A, const Point& B, const Point& P) {
    double crossProduct = vectorCrossProduct(A, B, P);
    if (crossProduct != 0) return false;

    double dotProduct = (P.x - A.x) * (B.x - A.x) + (P.y - A.y) * (B.y - A.y);
    double squaredLength = (B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y);

    return (dotProduct >= 0 && dotProduct <= squaredLength);
}

bool isPointOnTriangleBoundary(const Triangle& triangle, const Point& point) {
    return isPointOnSegment(triangle.vertexA, triangle.vertexB, point) ||
           isPointOnSegment(triangle.vertexB, triangle.vertexC, point) ||
           isPointOnSegment(triangle.vertexC, triangle.vertexA, point);
}
