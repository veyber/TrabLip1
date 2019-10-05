#ifndef ANALEX_H
#define ANALEX_H
#include <stdbool.h> 
#include <iostream>
#include <string.h> 
#include <stdlib.h> 

using namespace std;

bool ehDelimitador(char ch);
bool ehDivisor(char ch);
bool ehOperador(char ch);
bool ehIdentificador(char* str);
bool ehInteiro(char* str);
bool ehReal(char* str);
char* subString(char* str, int esq, int dir);
string parse(char* str);

#endif