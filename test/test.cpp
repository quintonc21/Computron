#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "computron.h"
#include <vector>
#include <array>
#include <stdexcept>
#include <iostream>

TEST_CASE("Load from file tests") {
    std::array<int, memorySize> memory{0};

    SECTION("Valid file") {
        REQUIRE_NOTHROW(load_from_file(memory, "p1.txt"));
    }

    SECTION("Non-existent file") {
        REQUIRE_THROWS_AS(load_from_file(memory, "non_existent_file.txt"), std::runtime_error);
    }

}

TEST_CASE("Execute function tests") {
    std::array<int, memorySize> memory{0};
    int accumulator = 0;
    size_t instructionCounter = 0;
    int instructionRegister = 0;
    size_t operationCode = 0;
    size_t operand = 0;
    std::vector<int> inputs = {4, 5}; // Sample inputs for read command

    // Load a sample valid program into memory
    load_from_file(memory, "p1.txt");

    // Test case 1: Execute the program with valid memory
    SECTION("Valid execution") {
        REQUIRE_NOTHROW(execute(memory, &accumulator, &instructionCounter, 
                                 &instructionRegister, &operationCode, 
                                 &operand, inputs));
    }

    SECTION("Empty memory") {
        std::array<int, memorySize> emptyMemory{0};
        REQUIRE_NOTHROW(execute(emptyMemory, &accumulator, &instructionCounter, 
                                 &instructionRegister, &operationCode, 
                                 &operand, inputs));
    }
}

TEST_CASE("Dump function tests") {
    std::array<int, memorySize> memory{0};
    int accumulator = 0;
    size_t instructionCounter = 0;
    size_t instructionRegister = 0;
    size_t operationCode = 0;
    size_t operand = 0;

        memory[0] = 5;
        memory[1] = -10;
        memory[2] = 0;
        std::cout << "Testing memory dump with values\n";
        REQUIRE_NOTHROW(dump(memory, accumulator, instructionCounter, 
                             instructionRegister, operationCode, operand));
    
}
