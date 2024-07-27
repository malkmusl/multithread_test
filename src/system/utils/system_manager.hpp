#pragma once
#ifndef SYSTEM_MANAGER_HPP
#define SYSTEM_MANAGER_HPP

#include "../system.hpp"
#include <unordered_map>
#include <memory>
#include <string>

class SystemManager {
public:
    void startSystem(const std::string& name, const std::string& type);
    void stopSystem(const std::string& name);

private:
    std::unordered_map<std::string, std::shared_ptr<System>> running_systems;
};
#endif