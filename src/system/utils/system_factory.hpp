#ifndef SYSTEM_FACTORY_HPP
#define SYSTEM_FACTORY_HPP

#include <functional>
#include <unordered_map>
#include <string>
#include <memory>
#include "../system.hpp"

// Define the factory type: a function that returns a shared_ptr<System>
using SystemFactoryFunc = std::function<std::shared_ptr<System>(const std::string&)>;

class SystemFactory {
public:
    static SystemFactory& instance();
    
    void registerSystem(const std::string& typeName, SystemFactoryFunc func);
    std::shared_ptr<System> createSystem(const std::string& typeName, const std::string& name);

private:
    SystemFactory() = default;
    std::unordered_map<std::string, SystemFactoryFunc> factoryFuncs;
};

#endif // SYSTEM_FACTORY_HPP
