#include "triangle.h"
#include <cmath>
#include <iostream>

double vectorCrossProduct(const Point& A, const Point& B, const Point& C) {
    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}

double calculateDistance(const Point& A, const Point& B) {
    return std::sqrt((B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y));
}

double calculateTriangleAreaHeron(const Triangle& triangle) {
    double a = calculateDistance(triangle.vertexA, triangle.vertexB);
    double b = calculateDistance(triangle.vertexB, triangle.vertexC);
    double c = calculateDistance(triangle.vertexC, triangle.vertexA);

    double semiPerimeter = (a + b + c) / 2.0;
    return std::sqrt(semiPerimeter * (semiPerimeter - a) * (semiPerimeter - b) * (semiPerimeter - c));
}

bool isTriangleDegenerate(const Triangle& triangle) {
    return std::abs(vectorCrossProduct(triangle.vertexA, triangle.vertexB, triangle.vertexC)) < std::numeric_limits<double>::epsilon();
}

bool isPointOnSegment(const Point& A, const Point& B, const Point& P, double epsilon) {
    double crossProduct = vectorCrossProduct(A, B, P);
    if (std::abs(crossProduct) > epsilon) return false;

    double dotProduct = (P.x - A.x) * (B.x - A.x) + (P.y - A.y) * (B.y - A.y);
    double squaredLength = (B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y);

    return (dotProduct >= -epsilon && dotProduct <= squaredLength + epsilon);
}

bool isPointOnTriangleBoundary(const Triangle& triangle, const Point& point, double epsilon) {
    return isPointOnSegment(triangle.vertexA, triangle.vertexB, point, epsilon) ||
           isPointOnSegment(triangle.vertexB, triangle.vertexC, point, epsilon) ||
           isPointOnSegment(triangle.vertexC, triangle.vertexA, point, epsilon);
}

bool isPointInsideTriangleVector(const Triangle& triangle, const Point& point, double epsilon) {
    double d1 = vectorCrossProduct(point, triangle.vertexA, triangle.vertexB);
    double d2 = vectorCrossProduct(point, triangle.vertexB, triangle.vertexC);
    double d3 = vectorCrossProduct(point, triangle.vertexC, triangle.vertexA);

    if (std::abs(d1) < epsilon || std::abs(d2) < epsilon || std::abs(d3) < epsilon) return false;

    return (d1 > 0 && d2 > 0 && d3 > 0) || (d1 < 0 && d2 < 0 && d3 < 0);
}

bool isPointInsideTriangleHeron(const Triangle& triangle, const Point& point, double epsilon) {
    Triangle t1 = {point, triangle.vertexA, triangle.vertexB};
    Triangle t2 = {point, triangle.vertexB, triangle.vertexC};
    Triangle t3 = {point, triangle.vertexC, triangle.vertexA};

    double originalArea = calculateTriangleAreaHeron(triangle);
    double subAreaSum = calculateTriangleAreaHeron(t1) + calculateTriangleAreaHeron(t2) + calculateTriangleAreaHeron(t3);

    return std::abs(originalArea - subAreaSum) < epsilon;
}