// hello_sfml - a very basic SFML script to open a blank window and keep it open

//include sfml header  
#include <SFML/Graphics.hpp>

int main()
{
    // window class (i guess)  
    sf::Window window(

        // show screen size
        sf::VideoMode(640, 480),
        "Hello SFML");

    // without this next while loop, the window closes immediately as it would skip to return 0  
    while (window.isOpen()) {

        // create an event object
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == 

            // (if user closes the window/stops operation...)
            sf::Event::Closed)

                // ...close the window
                window.close();

                // (otherwise keep window open)
    }
        
    return 0;
}

// need to link the sfml parts that catually run the window etc. as it is DYNAMICALLY LINKED (i.e. required to link program (my code) to library (SFML code))  
// g++-14 -Wall -std=c++23 hello_sfml.cpp -o hello_sfml -lsfml-graphics -lsfml-window -lsfml-system

