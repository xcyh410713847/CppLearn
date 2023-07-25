#include <iostream>
#include <cmath>

#define M_PI 3.14159265358979323846

int main()
{
    double x1, y1, x2, y2;
    std::cout << "Enter the coordinates of point A (x1, y1): ";
    std::cin >> x1 >> y1;
    std::cout << "Enter the coordinates of point B (x2, y2): ";
    std::cin >> x2 >> y2;

    double Bx = x2 - x1;
    double By = y2 - y1;

    double angle = atan2(By, Bx) * 180 / M_PI;

    std::cout << "The angle between point B and point A is: " << angle << " degrees" << std::endl;

    return 0;
}
