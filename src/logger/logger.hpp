#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include <string>
#include <unordered_set>
#include <memory>

class Logger {
public:
    static Logger& getInstance();

    void log(const std::string& message);
    void logError(const std::string& message);

    void registerSystem(const std::string& systemName);
    void listRegisteredSystems();

private:
    Logger() = default;
    std::unordered_set<std::string> registeredSystems;
};

#endif // LOGGER_H