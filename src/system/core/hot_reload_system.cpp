#include "hot_reload_system.hpp"
#include "../utils/system_factory.hpp"
#include "../../logger/logger.hpp"

// Register the HotReloadSystem with the SystemFactory
namespace {
    bool registered = []() {
        SystemFactory::instance().registerSystem("HotReloadSystem", [](const std::string& name) {
            return std::make_shared<HotReloadSystem>(name);
        });
        return true;
    }();
}

HotReloadSystem::HotReloadSystem(const std::string& name) : System(name) {
    // Additional initialization if necessary
}

HotReloadSystem::~HotReloadSystem() {
    // Cleanup if necessary
}

 
void HotReloadSystem::update() {
    std::cout << "Zes\n";
}