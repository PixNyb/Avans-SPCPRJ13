
/**
 * @file window.hpp
 * @author Robin Pijnappels
 * @brief This file contains the Window class definition.
 * @version 0.1
 * @date 2023-11-07
 *
 * The Window class provides an interface for window management within the game engine.
 * It abstracts the details of window creation, manipulation, and destruction behind a facade.
 * The actual implementation of window operations is delegated to the SDL2Facade class, ensuring
 * that the engine is not directly coupled to the SDL2 library.
 */


#ifndef DEFUNBOBENGINE_WINDOW_H
#define DEFUNBOBENGINE_WINDOW_H

#include "io_facade.hpp"

/**
 * @class Window
 * @brief Manages a game window through an abstract facade interface.
 *
 * This class is responsible for window operations such as creation, event handling, and destruction.
 * It communicates with an abstract facade interface for all operations to maintain a separation
 * from the concrete implementation details, which could be SDL2 or any other windowing system.
 */
class Window {
private:
    IOFacade* ioFacade;
public:
    /**
     * @brief Construct a new Window object with a reference to an IOFacade.
     * @param ioFacade Pointer to the IOFacade that will manage the actual window creation.
     */
    Window(IOFacade* ioFacade) : ioFacade(ioFacade) {}

    /**
      * @brief Creates a window with the given title and dimensions using the IOFacade.
      * @param title The title to display on the window's title bar.
      * @param width The width of the window in pixels.
      * @param height The height of the window in pixels.
      */
    void create(const char* title, int width, int height) {
        if (ioFacade) {
            ioFacade->createWindow(title, width, height);
        }
    }

    /**
     * @brief Destroys the window, freeing any associated resources.
     */
    void destroy() {
        if (ioFacade) {
            ioFacade->destroyWindow();  // Assuming the IOFacade has a method destroyWindow()
        }
    }

    // Other window management methods might include:
    // void show();
    // void hide();
    // void resize(int width, int height);
    // void setTitle(const char* title);
    // etc.

    // Additionally, you might need getter methods to retrieve information about the window if necessary
};

#endif //DEFUNBOBENGINE_WINDOW_H
