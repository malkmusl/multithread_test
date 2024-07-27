#include "system.hpp"
#include <iostream>
#include <chrono>
#include "../logger/logger.hpp"

System::System(const std::string& name) : m_name(name), m_state(INIT), m_running(false) {
    start();
}

System::~System() {
    stop();
    if (m_thread.joinable()) {
        m_thread.join();
    }
}

void System::start() {
    if (m_state == INIT || m_state == STOP) {
        m_state = STARTING;
        Logger::getInstance().log("[INFO] Initializing System: " + m_name);
        m_running = true;
        m_state = RUNNING;
        startThread();
    }
}

void System::stop() {
    if (m_state == RUNNING) {
        m_state = STOPPING;
        Logger::getInstance().log("[INFO] Stopping System: " + m_name);
        m_running = false;
        m_state = STOP;
    }
}

void System::update() {}

SYSTEM_STATE System::getState() const {
    return m_state;
}

void System::startThread() {
    m_thread = std::thread([this]() {
        while (m_running) {
            if (m_state == RUNNING) {
                update();
                std::this_thread::sleep_for(std::chrono::milliseconds(20));
            }
        }
    });
}