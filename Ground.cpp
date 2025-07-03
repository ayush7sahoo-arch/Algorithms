#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip> // For std::fixed and std::setprecision

const double PI = acos(-1.0);
const double EPS = 1e-7; // Small epsilon for floating-point comparisons

struct Point {
    double x, y;
};

// Function to calculate distance between two points
double dist(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Function to find the circumcenter of a triangle
// Returns true if successful, false if points are collinear
bool findCircumcenter(Point p1, Point p2, Point p3, Point& center, double& radius) {
    double D = 2 * (p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y));

    if (std::abs(D) < EPS) { // Points are collinear
        return false;
    }

    double Ux = (p1.x * p1.x + p1.y * p1.y) * (p2.y - p3.y) +
                (p2.x * p2.x + p2.y * p2.y) * (p3.y - p1.y) +
                (p3.x * p3.x + p3.y * p3.y) * (p1.y - p2.y);

    double Uy = (p1.x * p1.x + p1.y * p1.y) * (p3.x - p2.x) +
                (p2.x * p2.x + p2.y * p2.y) * (p1.x - p3.x) +
                (p3.x * p3.x + p3.y * p3.y) * (p2.x - p1.x);

    center.x = Ux / D;
    center.y = Uy / D;

    radius = dist(p1, center);
    return true;
}

// Function to normalize an angle to [0, 2*PI)
double normalizeAngle(double angle) {
    angle = fmod(angle, 2 * PI);
    if (angle < 0) {
        angle += 2 * PI;
    }
    return angle;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    Point p[3];
    for (int i = 0; i < 3; ++i) {
        std::cin >> p[i].x >> p[i].y;
    }

    Point center;
    double radius;

    // It's guaranteed that the points are not collinear (they form a polygon)
    findCircumcenter(p[0], p[1], p[2], center, radius);

    std::vector<double> angles;
    for (int i = 0; i < 3; ++i) {
        angles.push_back(normalizeAngle(atan2(p[i].y - center.y, p[i].x - center.x)));
    }
    std::sort(angles.begin(), angles.end());

    double alpha1 = angles[1] - angles[0];
    double alpha2 = angles[2] - angles[1];
    double alpha3 = 2 * PI - (angles[2] - angles[0]); // This is 2*PI - (alpha1 + alpha2)

    int min_N = -1;

    // Iterate N from 3 to 100
    for (int N = 3; N <= 100; ++N) {
        double fundamental_angle = 2 * PI / N;

        // Check if alpha1, alpha2, alpha3 are integer multiples of fundamental_angle
        bool is_valid_N = true;

        // Check alpha1
        double val1 = alpha1 / fundamental_angle;
        if (std::abs(val1 - std::round(val1)) > EPS) {
            is_valid_N = false;
        }

        // Check alpha2
        if (is_valid_N) { // Only proceed if previous check passed
            double val2 = alpha2 / fundamental_angle;
            if (std::abs(val2 - std::round(val2)) > EPS) {
                is_valid_N = false;
            }
        }
        
        // Check alpha3
        if (is_valid_N) { // Only proceed if previous check passed
            double val3 = alpha3 / fundamental_angle;
            if (std::abs(val3 - std::round(val3)) > EPS) {
                is_valid_N = false;
            }
        }

        if (is_valid_N) {
            min_N = N; // Found the smallest N (since we iterate from 3 upwards)
            break;     // Smallest N yields the smallest area, so we can stop
        }
    }

    // Calculate the area using the smallest valid N and the circumradius R
    double area = 0.5 * min_N * radius * radius * sin(2 * PI / min_N);

    std::cout << std::fixed << std::setprecision(8) << area << std::endl;

    return 0;
}