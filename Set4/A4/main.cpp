/* CSCI 200: Assignment 4 Bubble Bobble:
 *
 * Author: Westly Bouchard
 *
 * More complete description here...
 */

#include <iostream>
#include <time.h>
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

#include "Bubble.h"

// Constants for window sizing
#define WINDOW_WIDTH 650
#define WINDOW_HEIGHT 650

/**
 * @brief Helper function for generating randomized bubbles
 * 
 * @param min minimum of the range
 * @param max maximum of the range
 * @return A random double within the given range
 */
double randomInRange(double min, double max);

// Main Function
int main() {
    // Seed the random number generator
    srand(time(0));

    // Setup window, I thought that resizing might be a little weird with this assignment, so I
    // decided that the window would not be resizable
    RenderWindow window(
        VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
        "Bubble Bobble",
        Style::Titlebar | Style::Close
    );

    // Set up event for event polling
    Event event;
    // We only want to add or delete one bubble at a time, holding down left click or delete should
    // only perform the desired operation once
    bool dWasPressed = false;
    bool mouseWasPressed = false;

    // Vector of bubbles
    vector<Bubble> bubbles;

    // Setup first five bubbles
    for (int i = 0; i < 5; i++) {
        bubbles.push_back(Bubble(
            randomInRange(100, 400),
            randomInRange(100, 400),
            randomInRange(-0.1667, 0.1667),
            randomInRange(-0.1667, 0.1667),
            randomInRange(10, 50),
            Color (
                randomInRange(0, 255),
                randomInRange(0, 255),
                randomInRange(0, 255)
            ) 
        ));
    }

    // Start clock to track how often we should update bubble position
    Clock clock;

    // Main loop
    while (window.isOpen()) {

        // Handle events
        while (window.pollEvent(event)) {
            // Pattern matching on the event type
            switch (event.type) {
                // If the event is a window closed event, close the window
                case Event::Closed:
                    window.close();
                    break;

                // Check for key presses
                case Event::KeyPressed: {
                    // If the `Escape` or `Q` key was pressed, close the window, per UI
                    // specification on the assignment page
                    if (
                        event.key.scancode == Keyboard::Scan::Escape
                        || event.key.scancode == Keyboard::Scan::Q
                    ) {
                        window.close();
                    }

                    // If `D` is currently pressed, and it wasn't previously pressed, we can perform
                    // the operation. And set the previously pressed flag to true
                    if (event.key.scancode == Keyboard::Scan::D && !dWasPressed) {
                        dWasPressed = true;
                        // Delete bubble from vector
                        bubbles.pop_back();
                    }

                    break;
                }

                // Handle key released events
                case Event::KeyReleased:
                    // If the `D` key was released, we need to reset the flag so that it's ready to
                    // for next time
                    if (event.key.scancode == Keyboard::Scan::D) {
                        dWasPressed = false;
                    }

                    break;

                // Handle mouse button events
                case Event::MouseButtonPressed:
                    // If the left click was pressed, and it wasn't previously pressed, we can
                    // perform the operation. And set the previously pressed flag to true
                    if (event.mouseButton.button == Mouse::Left && !mouseWasPressed) {
                        mouseWasPressed = true;
                        // Create new bubble with the x and y position of the mouse cursor when it
                        // was pressed. The other values are randomized as they should be
                        bubbles.push_back(Bubble(
                            event.mouseButton.x,
                            event.mouseButton.y,
                            randomInRange(-0.1667, 0.1667),
                            randomInRange(-0.1667, 0.1667),
                            randomInRange(10, 50),
                            Color (
                                randomInRange(0, 255),
                                randomInRange(0, 255),
                                randomInRange(0, 255)
                            ) 
                        ));
                    }

                    break;

                // Handle mouse button released events
                case Event::MouseButtonReleased:
                    // If the left click button was released, we need to reset the flag so it's 
                    // ready to use for the next operation
                    if (event.mouseButton.button == Mouse::Left) {
                        mouseWasPressed = false;
                    }

                    break;

                default:
                    break;
            }
        }

        // If the current time on the clock is greater than 1 / 60 of a second, we need to update
        // the positions of the bubbles.
        if (clock.getElapsedTime().asSeconds() >= (1 / 60)) {
            // Restart the clock to 0
            clock.restart();

            // Iterate through the bubbles and update their positions
            for (auto& bubble : bubbles) {
                bubble.updatePosition(WINDOW_WIDTH, WINDOW_HEIGHT);
            }
        }

        // Clear the window
        window.clear();

        // Iterate through the bubbles and draw them to the window
        for (auto bubble : bubbles) {
            bubble.draw(window);
        }

        // Paint to the window
        window.display();
        
    }

    return 0;
}

double randomInRange(double min, double max) {
    return min + (max - min) * (rand() % RAND_MAX) / RAND_MAX;
}