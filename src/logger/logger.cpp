#include "logger.hpp"

Logger& Logger::getInstance() {
    static Logger instance;
    return instance;
}

void Logger::log(const std::string& message) {
    std::cout << message << std::endl;
}

void Logger::logError(const std::string& message) {
    std::cerr << message << std::endl;
}

void Logger::registerSystem(const std::string& systemName) {
    registeredSystems.insert(systemName);
}

void Logger::listRegisteredSystems() {
    std::cout << "[INFO] Registered System Types:" << std::endl;
    for (const auto& systemName : registeredSystems) {
        std::cout << "- " << systemName << std::endl;
    }
}