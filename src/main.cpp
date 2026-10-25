#include <iostream>
#include <array>
#include "../include/relay.h"
#include "../include/input.h"
#include "../include/console_interface.h"
#include "../include/config.h"

int main() {
    // Relay objects initialization. By default they are set to OFF (state = false)
    // Relays are named "1", "2", "3" (std::string) and their state is set default to OFF at the beginning.
    std::array<Relay, RELAY_COUNT> relays = {
        Relay("1"),
        Relay("2"), 
        Relay("3")
    }; 
    
    //Input objects initialization. Each Input has the same name corresponding to Relay name and holds a reference to its state.
    //By default, each Input has it's own state set to false (not required in the class constructor).
    //This is dictated by simulating I/O controller Input delays.
    std::array<Input, RELAY_COUNT> inputs = {
        Input("1", relays[0].get_state()),
        Input("2", relays[1].get_state()),
        Input("3", relays[2].get_state())
    };

    //Bool variable that holds whole program in a loop.
    bool is_running = true;

    while (is_running){
        //Redraws the screen (clears it and prints the current I/O menu).
        refresh(relays, inputs);
        //Waiting for user input.
        std::cout << "             Your choice: " << std::endl;
        int user_choice = get_user_choice();

        switch (user_choice){

            /*
            If the user chooses 1, 2, or 3, the 'index' variable stores the input decreased by 1, because arrays are 0-indexed.
            Next, if the chosen Relay state is already true, it informs the user that this Relay is ON.
            Otherwise, it toggles the Relay state, clears the screen to show the updated Relay state, 
            and waits 700ms before updating the corresponding Input state (simulating an I/O controller delay).
            Finally, it clears the terminal again and prints the fresh I/O states.
            */
            case 1:
            case 2:
            case 3: {
                int index = user_choice - 1;
                if (relays[index].get_state()) {
                    std::cout << "R" << index + 1 << " already ON" << std::endl;
                } else {
                    std::cout << "R" << index + 1 << " chosen." << std::endl;
                    relays[index].toggle();
                    refresh(relays, inputs);
                    std::cout << "R" << index + 1 << " turned ON. Waiting for input confirmation..." << std::endl;  
                    delay_ms(ON_DELAY_MS);
                    inputs[index].update_input_state();
                    refresh(relays, inputs);
                }
                break;
            }
            
            case 4: {
                std::cout << "Which output to disable (1-3)?" << std::endl;
                int relay_to_disable = get_user_choice();

                if (relay_to_disable >= 1 && relay_to_disable <= static_cast<int>(RELAY_COUNT)) {
                    Relay& relay = relays[relay_to_disable - 1];
                    
                    if (relay.get_state()) {
                        relay.turn_off();
                        refresh(relays, inputs);
                        delay_ms(OFF_DELAY_MS);
                        inputs[relay_to_disable - 1].update_input_state();
                        refresh(relays, inputs);
                        std::cout << "R" << relay_to_disable << " disabled." << std::endl;
                        std::cout << "I" << relay_to_disable << " confirmed OFF." << std::endl;
                    } else {
                        std::cout << "R" << relay_to_disable << " already OFF" << std::endl;
                    }
                } else {
                    std::cout << "Invalid output number, please try again." << std::endl;
                }
                break;
            }
            default:
                std::cout << "Exiting program..." << std::endl;
                is_running = false;
                break;
        }
        delay_ms(MESSAGE_DELAY_MS);
    }
}



