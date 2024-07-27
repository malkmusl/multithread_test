#include "system_factory.hpp"
#include "../../logger/logger.hpp"

SystemFactory& SystemFactory::instance() {
    static SystemFactory instance;
    return instance;
}

void SystemFactory::registerSystem(const std::string& typeName, SystemFactoryFunc func) {
    factoryFuncs[typeName] = func;
    Logger::getInstance().registerSystem(typeName);
}

std::shared_ptr<System> SystemFactory::createSystem(const std::string& typeName, const std::string& name) {
    auto it = factoryFuncs.find(typeName);
    if (it != factoryFuncs.end()) {
        return it->second(name);
    } else {
        Logger::getInstance().logError("System type not registered: " + typeName);
        return nullptr;
    }
}