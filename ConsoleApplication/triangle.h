struct Point {
    double x;
    double y;
};

struct Triangle {
    Point vertexA;
    Point vertexB;
    Point vertexC;
};

bool isTriangleDegenerate(const Triangle& triangle);
bool isPointInsideTriangle(const Triangle& triangle, const Point& point);
bool isPointOnTriangleBoundary(const Triangle& triangle, const Point& point);

