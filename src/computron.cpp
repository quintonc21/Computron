
#include "computron.h"

#include <fstream>
#include <iomanip>

void load_from_file(std::array<int, memorySize>& memory, const std::string& filename) {

  constexpr int sentinel{-99999};// terminates reading after -99999
  size_t i{0}; 
  std::string line;
  int instruction;

  
  std::ifstream inputFile(filename); 
  if (!inputFile) 
    throw std::runtime_error("invalid_input");

  
  while (std::getline(inputFile, line)) {
    instruction = std::stoi(line); 
    if (instruction == sentinel)
      break; 
     // Check if the instruction is valid using the validWord function
    // If the instruction is valid, store it in memory at position 'i' and increment 'i'
    // If the instruction is invalid, throw a runtime error with the message "invalid_input"

    if(validWord(instruction)) {
       memory[i] = instruction;
       i++;
    }
    else
       throw std::runtime_error("invalid_input");

  }
  inputFile.close();
}


Command opCodeToCommand(size_t opCode){
  switch(opCode){
    case 10: return Command::read;
      // ToDo: Complete
    case 11: return Command::write;
    case 20: return Command::load;
    case 21: return Command::store;
    case 30: return Command::add;
    case 31: return Command::subtract;
    case 32: return Command::multiply;
    case 33: return Command::divide;
    case 40: return Command::branch;
    case 41: return Command::branchNeg;
    case 42: return Command::branchZero;
    case 43: return Command::halt;
    default:
    return Command::halt;
  };
}

void execute(std::array<int, memorySize>& memory, 
            int* const acPtr, size_t* const icPtr, 
            int* const irPtr, size_t* const opCodePtr, 
            size_t* const opPtr,
            const std::vector<int>& inputs){
  
  size_t inputIndex{0}; // Tracks input
  
  do{
    //instruction counter to register
    //instructionRegister = memory [instructionCounter];
    //operationCode = instructionRegister / 100; // divide
    //operand = instructionRegister % 100; // remainder
    
    switch(int word{}; opCodeToCommand(*opCodePtr)){

      case Command::read:
        word = inputs[inputIndex];
        // Assign the value of 'word' to the memory location pointed to by 'opPtr'
        // Increment the instruction counter (icPtr) to point to the next instruction
        memory[*opPtr] = word;
        (*icPtr)++;
        inputIndex++;
        break;
      
      case Command::write:
        //Dereference 'icPtr' to access the instruction counter and increment its value by 1
         // use the below cout if needed but comment before submission
        //std::cout << "Contents of " << std::setfill('0') << std::setw(2) 
        //          << *opPtr << " : " << memory[*opPtr] << "\n";
        (*icPtr)++;

        break;
      
      case Command::load:
        //Load the value from the memory location pointed to by 'opPtr' into the accumulator (acPtr)
        //Increment the instruction counter (icPtr) to point to the next instruction
        *acPtr =  memory[*opPtr];
        (*icPtr)++;
        break;

      case Command::store:
        // Store the value in the accumulator (acPtr) into the memory location pointed to by 'opPtr'
        // Increment the instruction counter (icPtr) to move to the next instruction
        memory[*opPtr] = *acPtr;
        (*icPtr)++;
        break;

      case Command::add:
        // Add the value in the accumulator (acPtr) to the value in memory at the location pointed to by 'opPtr' and store the result in 'word'
        // If the result is valid, store it in the accumulator and increment the instruction counter
        // / If the result is invalid, throw a runtime error 
        if(validWord(*acPtr+memory[*opPtr]))
              word = *acPtr+memory[*opPtr];
       else
              throw std::runtime_error("invalid_input");
       (*icPtr)++;
        break;

      case Command::subtract:
        // Subtract the value in memory at the location pointed to by 'opPtr' from the value in the accumulator (acPtr) and store the result in 'word'
        // If the result is valid, store it in the accumulator and increment the instruction counter
        // / If the result is invalid, throw a runtime error 
        if(validWord(*acPtr-memory[*opPtr]))
              word = *acPtr-memory[*opPtr];
       else
              throw std::runtime_error("invalid_input");
       (*icPtr)++;
        break;

      case Command::multiply:
        // as above do it for multiplication
        if(validWord((*acPtr)*(memory[*opPtr])))
              word = (*acPtr)*(memory[*opPtr]);
       else
              throw std::runtime_error("invalid_input");
       (*icPtr)++;
        break;

      case Command::divide:
         // as above do it for division
         if(validWord((*acPtr)/(memory[*opPtr])) && (memory[*opPtr] != 0))
              word = (*acPtr)/(memory[*opPtr]);
        else
               throw std::runtime_error("invalid_input");
        (*icPtr)++;
        break;

      case Command::branch:
        *icPtr = *opPtr;
        break;
        
      case Command::branchNeg:
        *acPtr < 0 ? *icPtr = *opPtr : ++(*icPtr);
        break;
        
      case Command::branchZero:
        *acPtr == 0 ? *icPtr = *opPtr : ++(*icPtr);
        break;
        
      case Command::halt:
        break;
        
      default:
        break;
    };
  }while(opCodeToCommand(*opCodePtr) != Command::halt);
};


bool validWord(int word){
       return (word >= minWord && word <= maxWord);
};

void dump(std::array<int, memorySize>& memory, int accumulator, 
       size_t instructionCounter, size_t instructionRegister,
       size_t operationCode, size_t operand) {

std::cout << "Memory: " << "\n" << "    0    1     2    3    4   5    6    7    8    9";

for (size_t i = 0; i < memorySize; i++) {
    if (i % 10 == 0)
           std::cout << "\n" << i << " ";
    
    if (memory[i] > 0)
           std::cout << "+" << memory[i];
    else if (memory[i] == 0) 
           std::cout << "+0000"; 
    else 
           std::cout << memory[i]; 
}

std::cout << std::endl;  
};

