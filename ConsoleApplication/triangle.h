struct Point {
    double x;
    double y;
};

struct Triangle {
    Point vertexA;
    Point vertexB;
    Point vertexC;
};

bool isPointInsideTriangle(const Triangle& triangle, const Point& point);
bool isTriangleDegenerate(const Triangle& triangle);
bool isPointOnTriangleBoundary(const Triangle& triangle, const Point& point);
