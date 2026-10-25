#pragma once
#include <array>
#include <cstdint>
#include <relay.h>
#include <input.h>
#include "../include/config.h"

void print_IO_menu(const std::array<Relay, RELAY_COUNT> &relays, const std::array<Input, RELAY_COUNT> &inputs);
void clear_screen();
void refresh(const std::array<Relay, RELAY_COUNT> &relays, const std::array<Input, RELAY_COUNT> &inputs);
void delay_ms(std::uint32_t milliseconds);
int get_user_choice();