#ifndef COORDINATE_CONVERSION_H
#define COORDINATE_CONVERSION_H

/**
 * @brief Converts polar(r, theta) to cartesian (x, y)
 * 
 * @param radius radius of the polar coordinate
 * @param angle angle of polar coordinate
 * @param xCoordinate the corresponding x coordinate of the given polar coordinate
 * @param yCoordinate the corresponding y coordinate of the given polar coordinate
 */
void polar_to_cartesian(
    const double radius,
    const double angle,
    double* xCoordinate,
    double* yCoordinate
);

/**
 * @brief Converts from cartesian (x, y) to polar (r, theta)
 * 
 * @param xCoordinate the x component of the coordinate
 * @param yCoordinate the y value of the coordinate
 * @param radius the corresponding radius of the given cartesian coordinate
 * @param angle the corresponding angle of the given cartesian coordinate
 */
void cartesian_to_polar(
    const double xCoordinate,
    const double yCoordinate,
    double* radius,
    double* angle
);

#endif
