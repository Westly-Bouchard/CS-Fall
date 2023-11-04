#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate {
    public:
        double x;
        double y;

        /**
         * @brief Construct a new Coordinate object
         *        Default is (0, 0)
         */
        Coordinate();

        /**
         * @brief Construct a new Coordinate object
         * 
         * @param x horizontal component
         * @param y vertical component
         */
        Coordinate(double x, double y);
};

#endif