#include <SFML/Graphics.hpp>
using namespace sf;

#include <iostream>
using namespace std;

int main() {

    const int WINDOW_WIDTH = 640;
    const int WINDOW_HEIGHT = 400;

    // create a window
    RenderWindow window( VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Test");

    /////////////////////////////////////
    // BEGIN ANY FILE LOADING

    // perform any file processing once before draw loop begins

    //  END  ANY FILE LOADING
    /////////////////////////////////////

    // create an event object once to store future events
    Event event;

    // Begin resource definition
    CircleShape sun;
    sun.setPosition(-35, -35);
    sun.setRadius(70);
    sun.setFillColor(Color::Yellow);

    vector<RectangleShape> buildings;

    for (int i = 0; i < WINDOW_WIDTH; i += 64) {
        RectangleShape tempBuilding;
        tempBuilding.setOutlineColor(Color::Black);
        tempBuilding.setOutlineThickness(-2);
        tempBuilding.setSize(Vector2f(64, 100 + (rand() % 150)));
        tempBuilding.setPosition(i, WINDOW_HEIGHT - tempBuilding.getSize().y);

        tempBuilding.setFillColor(
            Color (
                rand() % 256,
                rand() % 256,
                rand() % 256
            )
        );

        buildings.push_back(tempBuilding);
    }

    // while the window is open
    while( window.isOpen() ) {
        // clear any existing contents
        window.clear(Color(151, 204, 232));

        /////////////////////////////////////
        // BEGIN DRAWING HERE
            
        window.draw(sun);
        
        for (size_t i = 0; i < buildings.size(); i++) {
            window.draw(buildings.at(i));
        }

        //  END  DRAWING HERE
        /////////////////////////////////////


        // display the current contents of the window
        window.display();

        /////////////////////////////////////
        // BEGIN EVENT HANDLING HERE
        // check if any events happened since the last time checked
        while( window.pollEvent(event) ) {
            // if event type corresponds to pressing window X
            if(event.type == Event::Closed) {
                // tell the window to close
                window.close();
            }
            // check addition event types to handle additional events
        }
        //  END  EVENT HANDLING HERE
        /////////////////////////////////////
    }

    return 0;
}
