struct Point {
    double x;
    double y;
};

struct Triangle {
    Point vertexA;
    Point vertexB;
    Point vertexC;
};

bool isPointInsideTriangleVector(const Triangle& triangle, const Point& point, double epsilon = 1e-9);
bool isPointOnTriangleBoundary(const Triangle& triangle, const Point& point, double epsilon = 1e-9);
double calculateTriangleAreaHeron(const Triangle& triangle);
bool isPointInsideTriangleHeron(const Triangle& triangle, const Point& point, double epsilon = 1e-9);
bool isTriangleDegenerate(const Triangle& triangle);