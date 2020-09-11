#include<iostream>
#include <SFML/Graphics.hpp>
#include "Inputs.hh"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define GAME_NAME "Roguelike game"

//const int windowWidth{800};

int main()
{

    //Creacion de la ventana del grafico
    sf::Window* window = new sf::Window(sf::VideoMode(800, 600), "Roguelike game");
    //Aqui se guardan los eventos dentor de la ventana, por ejemplo mouse, teclado, etc
    sf::Event event;
    //loop principal para que se ejecute mientras la ventana este abierta, y no llegue a return 0

    Inputs* inputs = new Inputs();

    while(window->isOpen())
    {
        //Mientras se esten ejecutando eventos dentro de la ventana, esto se va a repetir
        while(window->pollEvent(event))
        {
            //si el evento fue la accion de cerrar la ventana, entonces termina la aplicacion
            if(event.type == sf::Event::Closed)
            {
                window->close();
            }
        }

              
        Vec2* keyboardAxis{inputs->GetKeyboardAxis()};
        Vec2* joystickAxis{inputs->GetJoystickAxis()};
        //std::cout << "keyboard axis x: " << keyboardAxis->x << " keyboard axis y: " << keyboardAxis->y << std::endl;
        
        std::cout << "joystick axis x: " << joystickAxis->x << " joystick axis y: " << joystickAxis->y << std::endl;

        //inputs->GetJoystickAxis();
        delete keyboardAxis;
        delete joystickAxis;

    }

    return 0;
}