#include "system_manager.hpp"
#include "../../logger/logger.hpp"
#include "system_factory.hpp"

void SystemManager::startSystem(const std::string& name, const std::string& type) {
    if (running_systems.find(name) != running_systems.end()) {
        Logger::getInstance().log("System with this name already exists: " + name);
        return;
    }

    auto system = SystemFactory::instance().createSystem(type, name);
    if (system) {
        running_systems[name] = system;
        Logger::getInstance().log("Started system: " + name);
    }
}

void SystemManager::stopSystem(const std::string& name) {
    auto it = running_systems.find(name);
    if (it != running_systems.end()) {
        it->second->stop();
        running_systems.erase(it);
        Logger::getInstance().log("Stopped system: " + name);
    } else {
        Logger::getInstance().logError("System not found: " + name);
    }
}