#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <string>

int getInt();
unsigned int* loadMemory(std::string inputPath);
void execMemory(unsigned int* memory);

#endif //INTERPRETER_H
