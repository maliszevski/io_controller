
#include "../include/relay.h"

Relay::Relay(const std::string &relay_name) : name(relay_name), relay_state(false)
{

}

bool Relay::toggle() {
    relay_state = !relay_state;
    return relay_state;
}

bool Relay::turn_off() {
    relay_state = false;
    return relay_state;
}

const std::string& Relay::get_name() const{
    return name;
}

const bool& Relay::get_state() const {
    return relay_state;
}
    