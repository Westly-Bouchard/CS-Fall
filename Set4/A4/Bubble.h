#ifndef BUBBLE_H
#define BUBBLE_H

#include <SFML/Graphics.hpp>

class Bubble {
    public:
        /**
         * @brief Construct a new Bubble object
         * 
         * @param xPos Starting x position of the bubble
         * @param yPos Starting y position of the bubble
         * @param xDir Initial x direction of the bubble
         * @param yDir Initial y direction of the bubble
         * @param radius Radius of the bubble
         * @param color Color of thr bubble
         */
        Bubble(double xPos, double yPos, double xDir, double yDir, double radius, sf::Color color);

        /**
         * @brief Get the current x direction of the bubble
         * 
         * @return double 
         */
        double getXDir();

        /**
         * @brief Get the current y direction of the bubble
         * 
         * @return double 
         */
        double getYDir();

        /**
         * @brief Set the x direction of the bubble
         * 
         * @param dir 
         */
        void setXDir(double dir);

        /**
         * @brief Set the y direction of the bubble
         * 
         * @param dir 
         */
        void setYDir(double dir);

        /**
         * @brief Get the SFML renderable component of the bubble
         * 
         * @return CircleShape 
         */
        sf::CircleShape getSFComponent();

        /**
         * @brief Draw the bubble to the provided SFML RenderWindow
         * 
         * @param renderer
         */
        void draw(sf::RenderWindow& renderer);

        /**
         * @brief Update the position of the bubble
         * 
         * @param maxX Maximum X value of the bubble
         * @param maxY Maximum Y value of the bubble
         */
        void updatePosition(double maxX, double maxY);

    private:
        sf::CircleShape sfComponent;

        double xDir;
        double yDir;
};

#endif
