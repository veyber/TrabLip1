#include "analex.h"
#include <stdbool.h> 
#include <iostream>
#include <string.h> 
#include <string> 
#include <stdlib.h> 

using namespace std;

bool ehDelimitador(char ch) 
{ 
	if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' || 
		ch == '/' || ch == ',' || ch == ';' || ch == '=' || 
		ch == '(' || ch == ')') 
		return (true); 
	return (false); 
} 

bool ehDivisor(char ch){
    if (ch == ';' || ch == '=' || 
		ch == '(' || ch == ')') 
		return (true); 
	return (false);
}

bool ehOperador(char ch) 
{ 
	if (ch == '+' || ch == '-' || ch == '*' || 
		ch == '/' || ch == '=' ) 
		return (true); 
	return (false); 
} 

bool ehIdentificador(char* str) 
{ 
	if (str[0] == '0' || str[0] == '1' || str[0] == '2' || 
		str[0] == '3' || str[0] == '4' || str[0] == '5' || 
		str[0] == '6' || str[0] == '7' || str[0] == '8' || 
		str[0] == '9' || ehDelimitador(str[0]) == true) 
		return (false); 
	return (true); 
} 
 
bool ehInteiro(char* str) 
{ 
	int i, tam = strlen(str); 

	if (tam == 0) 
		return (false); 
	for (i = 0; i < tam; i++) { 
		if (str[i] != '0' && str[i] != '1' && str[i] != '2'
			&& str[i] != '3' && str[i] != '4' && str[i] != '5'
			&& str[i] != '6' && str[i] != '7' && str[i] != '8'
			&& str[i] != '9') 
			return (false); 
	} 
	return (true); 
} 

bool ehReal(char* str) 
{ 
	int i, tam = strlen(str); 
	bool aux = false; 

	if (tam == 0) 
		return (false); 
	for (i = 0; i < tam; i++) { 
		if (str[i] != '0' && str[i] != '1' && str[i] != '2'
			&& str[i] != '3' && str[i] != '4' && str[i] != '5'
			&& str[i] != '6' && str[i] != '7' && str[i] != '8'
			&& str[i] != '9' && str[i] != '.')
			return (false); 
		if (str[i] == '.') 
			aux = true; 
	} 
	return (aux); 
} 

bool ehChave(char* str) 
{ 
    if (!strcmp(str, "begin") || !strcmp(str, "end")) 
        return (true); 
    return (false); 
} 
char* subString(char* str, int esq, int dir) 
{ 
	int i; 
	char* subStr = (char*)malloc(sizeof(char) * (dir - esq + 2)); 

	for (i = esq; i <= dir; i++) 
		subStr[i - esq] = str[i]; 
	subStr[dir - esq + 1] = '\0'; 
	return (subStr); 
} 

string parse(char* str) 
{ 
	string llex;
	int esq = 0, dir = 0; 
	int tam = strlen(str); 

	while (dir <= tam && esq <= dir) { 
		if (ehDelimitador(str[dir]) == false) 
			dir++; 

		if (ehDelimitador(str[dir]) == true && esq == dir) { 
			if (ehDivisor(str[dir]) == true){
				llex = llex + "[div, " + str[dir] + "]";
				cout << str[dir] << " eh um divisor.\n"; 
			}
			dir++; 
			esq = dir; 
		} else if (ehDelimitador(str[dir]) == true && esq == dir) { 
			if (ehOperador(str[dir]) == true){
				llex = llex + "[op, " + str[dir] + "]";
				cout << str[dir] << " eh um operador.\n"; 
			}
			dir++; 
			esq = dir; 
		} else if (ehDelimitador(str[dir]) == true && esq != dir 
				|| (dir == tam && esq != dir)) { 
			char* subStr = subString(str, esq, dir - 1); 

			if (ehChave(subStr) == true){
				llex = llex + "[cha, " + subStr + "]";
				cout << subStr << " eh uma chave.\n";
			}

			else if (ehInteiro(subStr) == true){
				llex = llex + "[int, " + subStr + "]";
				cout << subStr << " eh um numero inteiro.\n"; 
			}

			else if (ehReal(subStr) == true){
				llex = llex + "[real, " + subStr + "]";
				cout << subStr << " eh um numero real.\n"; 
			}

			else if (ehIdentificador(subStr) == true
					&& ehDelimitador(str[dir - 1]) == false) {
				llex = llex + "[id, " + subStr + "]";
				cout << subStr << " eh um identificador valido.\n"; 
			}
			else if (ehIdentificador(subStr) == false
					&& ehDelimitador(str[dir - 1]) == false){
				cout << subStr << " nao eh um identificador valido.\n";
			}
			esq = dir; 
		} 
	} 
	return llex; 
} 
