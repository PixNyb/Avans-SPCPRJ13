/**
 * @file behaviour_script_manager.hpp
 * @author "Melvin van Bree"
 * @brief TODO
 * @version 0.1
 * @date 15/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_SRC_PROJECT_MANAGERS_BEHAVIOUR_SCRIPT_MANAGER_HPP
#define DEFUNBOBENGINE_SRC_PROJECT_MANAGERS_BEHAVIOUR_SCRIPT_MANAGER_HPP

class BehaviourScriptManager
{
public:
    BehaviourScriptManager();
    ~BehaviourScriptManager();

    /**
     * @brief Calls update on all behaviour scripts. Also calls onStart if it hasn't been started
     * yet.
     */
    void Update();
};

#endif // DEFUNBOBENGINE_SRC_PROJECT_MANAGERS_BEHAVIOUR_SCRIPT_MANAGER_HPP
