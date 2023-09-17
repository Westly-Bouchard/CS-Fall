#include <cmath>

#include "coordinate_conversion.h"

void polar_to_cartesian(const double radius, const double angle, double* pXCoordinate, double* pYCoordinate) {
    *pXCoordinate = radius * cos(angle);
    *pYCoordinate = radius * sin(angle);
}

void cartesian_to_polar(const double xCoordinate, const double yCoordinate, double* pRadius, double* pAngle) {
    *pRadius = sqrt(pow(xCoordinate, 2) + pow(yCoordinate, 2));
    *pAngle = atan(yCoordinate / xCoordinate);
}
