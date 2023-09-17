/**
 * @file vector_math.cpp
 * @author Westly Bouchard
 * @brief Definitions for helper functions used to complete assignment
 * @date 2023-09-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <cmath>
#include <iostream>

#include "vector_math.h"

#define DEG_TO_RAD (M_PI / 180)

using namespace std;

void angle_input(double* pAngleStore) {
    cout << "Enter an angle in degrees: ";
    cin >> *pAngleStore;
}

void angle_to_vector(const double angle, double* pX, double* pY) {
    *pX = cos(angle * DEG_TO_RAD);
    *pY = sin(angle * DEG_TO_RAD);
}

void point_input(double* pX, double* pY) {
    cout << "Enter the x component of the point: ";
    cin >> *pX;

    cout << "Enter the y component of the point: ";
    cin >> *pY;
}

void vector_input(double* pX, double* pY) {
    cout << "Enter the x component of the vector: ";
    cin >> *pX;

    cout << "Enter the y component of the vector: ";
    cin >> *pY;
}

void vector_normalize(const double x, const double y, double* pNormalizedX, double* pNormalizedY) {
    double magnitude = sqrt(pow(x, 2) + pow(y, 2));

    *pNormalizedX = x / magnitude;
    *pNormalizedY = y / magnitude;
}

double vector_to_angle(const double x, const double y) {
    if (y == 0 && x == 0) {
        return 0;
    } else if (x == 0) {
        if (y > 0) {
            return 90;
        } else {
            return 270;
        }
    } else if (y == 0) {
        if (x > 0) {
            return 0;
        } else {
            return 180;
        }
    } else {
        return atan(y / x) / DEG_TO_RAD;
    }
}

void rotate_point_by_vector(
    const double pointX,
    const double pointY,
    const double vecX,
    const double vecY,
    double* pRotatedX,
    double* pRotatedY
) {
    *pRotatedX = (pointX * vecX) - (pointY * vecY);
    *pRotatedY = (pointX * vecY) + (pointY * vecX);
}

void rotate_point_by_vector_around_point(
    const double pointX,
    const double pointY,
    const double vecX,
    const double vecY,
    const double rotPointX,
    const double rotPointY,
    double* pRotatedX,
    double* pRotatedY
) {
    double translatedX = pointX - rotPointX;
    double translatedY = pointY - rotPointY;

    double rotatedX = (translatedX * vecX) - (translatedY * vecY);
    double rotatedY = (translatedX * vecY) + (translatedY * vecX);

    *pRotatedX = rotatedX + rotPointX;
    *pRotatedY = rotatedY + rotPointY;
}