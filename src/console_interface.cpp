
#include "../include/console_interface.h"
#include "../include/config.h"
#include <iostream>
#include <thread>
#include <chrono>

void print_IO_menu(const std::array<Relay, RELAY_COUNT> &relays, const std::array<Input, RELAY_COUNT> &inputs) {
    std::cout << "**************************************" << std::endl;
    std::cout << "*            I/O CONTROLLER          *" << std::endl;
    std::cout << "*                                    *" << std::endl;
    for (size_t i = 0; i < relays.size(); i++) {
        std::cout   << "* R" << relays[i].get_name() << " STATE: " << relays[i].get_state() 
        << "           "
        << " I" << inputs[i].get_input_name() << " STATE: " << inputs[i].get_input_state() << " *" 
        << std::endl;  
    }
    std::cout << "*                                    *" << std::endl;
    std::cout << "**************************************" << std::endl;
}

void clear_screen(){
    std::cout << "\033[2J\033[1;1H";
}

void refresh(const std::array<Relay, RELAY_COUNT> &relays, const std::array<Input, RELAY_COUNT> &inputs){
    clear_screen();
    print_IO_menu(relays, inputs);

}

void delay_ms(std::uint32_t milliseconds){
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

//This function is getting user choice to control switch loop.
//If user enters invalid value, the cin.fail() returns true and it will be repeating until user enters correct value (int).
//Then, cin.clear(); is clearing cin error state due to invalid value.
//Finally, cin.ignore(); is clearing invalid input (max 100 chars or up to the newline char.)
int get_user_choice(){
    int user_choice;
    
    while (true) {
        std::cin >> user_choice;
        if (std::cin.fail()){
            std::cout << "Invalid input. Try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(100, '\n');
        } else {
            std::cin.ignore(100, '\n');
            return user_choice;
        }
    }
}

