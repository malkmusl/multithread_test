#include "state_name.hpp"

std::string stateName(SYSTEM_STATE state) {
    switch (state) {
        case INIT: return "INIT";
        case STARTING: return "STARTING";
        case RUNNING: return "RUNNING";
        case STOPPING: return "STOPPING";
        case STOP: return "STOP";
        default: return "UNKNOWN";
    }
}