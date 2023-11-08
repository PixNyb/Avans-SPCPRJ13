//
// Created by Robin Pijnappels on 08/11/2023.
//

#ifndef DEFUNBOBENGINE_INPUTHANDLER_HPP
#define DEFUNBOBENGINE_INPUTHANDLER_HPP

#include <vector>
#include "event.hpp"
#include "io_facade.hpp" // De abstracte klasse

class InputHandler : public IOFacade {
public:
    void init() override;
    void pollEvents(std::vector<Event>& events) override;
};

#endif //DEFUNBOBENGINE_INPUTHANDLER_HPP
