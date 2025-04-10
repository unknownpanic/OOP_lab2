#include "triangle.h"
#include <cmath>
#include <limits>

double vectorCrossProduct(const Point& A, const Point& B, const Point& C) {
    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}

bool isPointInsideTriangle(const Triangle& triangle, const Point& point) {
    double d1 = vectorCrossProduct(point, triangle.vertexA, triangle.vertexB);
    double d2 = vectorCrossProduct(point, triangle.vertexB, triangle.vertexC);
    double d3 = vectorCrossProduct(point, triangle.vertexC, triangle.vertexA);

    bool hasNegative = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool hasPositive = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(hasNegative && hasPositive);
}

bool isTriangleDegenerate(const Triangle& triangle) {
    return std::abs(vectorCrossProduct(triangle.vertexA, triangle.vertexB, triangle.vertexC)) < std::numeric_limits<double>::epsilon();
}

bool isPointOnTriangleBoundary(const Triangle& triangle, const Point& point) {
    double d1 = vectorCrossProduct(point, triangle.vertexA, triangle.vertexB);
    double d2 = vectorCrossProduct(point, triangle.vertexB, triangle.vertexC);
    double d3 = vectorCrossProduct(point, triangle.vertexC, triangle.vertexA);

    return d1 == 0 || d2 == 0 || d3 == 0;
}