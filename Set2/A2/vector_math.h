/**
 * @file vector_math.h
 * @author Westly Bouchard
 * @brief Header file for vector math helper functions
 * @date 2023-09-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef VECTOR_MATH_H
#define VECTOR_MATH_H

/**
 * @brief Prompts the user to enter an angle and updates the corresponding parameter
 * 
 * @param pAngleStore a pointer to a double where the result will be stored
 */
void angle_input(double* pAngleStore);

/**
 * @brief Converts an angle with the positive X-axis to the resultant vector on the unit circle
 * 
 * @param angle the angle to be converted, in degrees
 * @param pX a pointer to a double where the resulting x value will be stored
 * @param pY a pointer to a double where the resulting y value will be stored
 */
void angle_to_vector(const double angle, double* pX, double* pY);

/**
 * @brief Prompts the user to enter the (x, y) coordinate and updates the corresponding parameters
 * 
 * @param pX a pointer to a double where the resulting x value will be stored
 * @param pY a pointer to a double where the resulting y value will be stored
 */
void point_input(double* pX, double* pY);

/**
 * @brief Prompts the user to enter the <x, y> coordinate and updates the corresponding parameters
 * 
 * @param pX a pointer to a double where the resulting x value will be stored
 * @param pY a pointer to a double where the resulting y value will be stored
 */
void vector_input(double* pX, double* pY);

/**
 * @brief Normalizes the input vector setting the corresponding pointer parameters to the output
 *        normalized vector
 * 
 * @param x the x component of the vector to normalize
 * @param y the y component of the vector to normalize
 * @param pNormalizedX a pointer to a double where the normalized x value will be stored
 * @param pNormalizedY a pointer to a double where the normalized y value will be stored
 */
void vector_normalize(const double x, const double y, double* pNormalizedX, double* pNormalizedY);

/**
 * @brief Determines the angle the vector forms with the positive x axis based on where it
 *        intersects the unit circle. The angle is computed by taking the arctan of y over x
 * 
 * @param x the x component of the vector to convert
 * @param y the y component of the vector to convert
 * @return the angle of the vector in degrees between 0 and 360
 */
double vector_to_angle(const double x, const double y);

/**
 * @brief Performs the rotation by multiplying complex numbers.
 * 
 * @param pointX the x component of the point to rotate
 * @param pointY the y component of the point to rotate
 * @param vecX the x component of the rotation vector
 * @param vecY the y component of the rotation vector
 * @param pRotatedX a pointer to a double where the rotated x value will be stored
 * @param pRotatedY a pointer to a double where the rotated y value will be stored
 */
void rotate_point_by_vector(
    const double pointX,
    const double pointY,
    const double vecX,
    const double vecY,
    double* pRotatedX,
    double* pRotatedY
);

/**
 * @brief Rotates the given point around the given rotation point by the given vector
 * 
 * @param pointX the x component of the point to rotate
 * @param pointY the y component of the point to rotate
 * @param vecX the x component of the rotation vector
 * @param vecY the y component of the rotation vector
 * @param rotPointX the x component of the point to rotate around
 * @param rotPointY the y component of the point to rotate around
 * @param pRotatedX a pointer to a double where the rotated x value will be stored
 * @param pRotatedY a pointer to a double where the rotated y value will be stored
 */
void rotate_point_by_vector_around_point(
    const double pointX,
    const double pointY,
    const double vecX,
    const double vecY,
    const double rotPointX,
    const double rotPointY,
    double* pRotatedX,
    double* pRotatedY
);

#endif