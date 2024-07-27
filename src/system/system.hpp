#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <string>
#include <thread>
#include <atomic>

enum SYSTEM_STATE {
    INIT,
    STARTING,
    RUNNING,
    STOPPING,
    STOP
};

class System {
public:
    System(const std::string& name);
    virtual ~System();

    void start();
    void stop();
    virtual void update();
    SYSTEM_STATE getState() const;

protected:
    void startThread();

private:
    std::string m_name;
    SYSTEM_STATE m_state;
    std::thread m_thread;
    std::atomic<bool> m_running; // Use atomic to safely stop thread
};

#endif // SYSTEM_H