//
// Created by Robin Pijnappels on 08/11/2023.
//

#ifndef DEFUNBOBENGINE_IO_FACADE_HPP
#define DEFUNBOBENGINE_IO_FACADE_HPP

#include <vector>
#include "project/core/events/event.hpp"

class IOFacade {
public:
    virtual ~IOFacade() {}

    virtual void init() = 0;

    virtual void pollEvents(std::vector<Event>& events) = 0;
};

#endif //DEFUNBOBENGINE_IO_FACADE_HPP
