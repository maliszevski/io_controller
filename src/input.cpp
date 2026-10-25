#include "../include/input.h"
#include "../include/console_interface.h"

Input::Input(const std::string &input_name, const bool& relay_state)
: input_name(input_name), input_state(false), relay_state(relay_state)
{

}

void Input::update_input_state(){
    input_state = relay_state;
}

bool Input::get_input_state() const{
    return input_state;
}

const std::string& Input::get_input_name() const{
    return input_name;
}