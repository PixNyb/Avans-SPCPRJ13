/**
 * @file contact_listener.cpp
 * @author Daan Groot (d.groot3@student.avans.nl)
 * @brief This file contains the implementation of the class ContactListener
 * @version 0.1
 * @date 2023-11-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "contact_listener.hpp"
#include <iostream>

void ContactListener::BeginContact(b2Contact* contact) {
    std::cout << "contact" << std::endl;
}

void ContactListener::EndContact(b2Contact* contact) {
    std::cout << "end contact" << std::endl;
}
