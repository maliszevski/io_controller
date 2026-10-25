#pragma once
#include <string>

class Input{
private:
    std::string input_name;
    bool input_state;
    const bool& relay_state;

public:
    Input(const std::string &input_name, const bool& relay_state);
    void update_input_state();
    bool get_input_state() const;
    const std::string& get_input_name() const;
    


};