#include <iostream>
#include <sstream>
#include "system/utils/system_manager.hpp"
#include "logger/logger.hpp"

int main() {
    SystemManager manager;

    // List registered system types
    Logger::getInstance().listRegisteredSystems();

    std::string command;
    std::string action, name, type;

    std::cout << "[INFO] Enter commands to manage systems. Type 'start(Name, Type)' or 'stop(Name)'." << std::endl;

    while (true) {
        std::getline(std::cin, command);
        std::istringstream iss(command);
        std::getline(iss, action, '(');
        
        if (action == "start") {
            std::getline(iss, name, ',');
            std::getline(iss, type, ')');
            manager.startSystem(name, type);
        } else if (action == "stop") {
            std::getline(iss, name, ')');
            manager.stopSystem(name);
        } else {
            Logger::getInstance().logError("Unknown command.");
        }
    }

    return 0;
}