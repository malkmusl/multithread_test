#ifndef HOT_RELOAD_SYSTEM_HPP
#define HOT_RELOAD_SYSTEM_HPP

#include "../system.hpp"

class HotReloadSystem : public System {
public:
    HotReloadSystem(const std::string& name);
    virtual ~HotReloadSystem();
    void update() override;
};

#endif // HOT_RELOAD_SYSTEM_H