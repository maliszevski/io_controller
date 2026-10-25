#pragma once
#include <string>


class Relay{
private:
    std::string name;
    bool relay_state;

public:
    Relay(const std::string &relay_name);

    bool toggle();
    bool turn_off();
    const bool& get_state() const;
    const std::string& get_name() const;
};