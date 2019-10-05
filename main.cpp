#include "analex.h"
#include <stdbool.h> 
#include <iostream>
#include <string.h> 
#include <stdlib.h> 

using namespace std;


int main(){
    string aux;
	char str[50] = "begin x    =    ( soma2    +     34); end"; 
    aux = parse(str);
    cout << endl << endl;
    
    string aux1;
    char str1[50] = "begin y=fator1/2.5; end"; 
    aux1 = parse(str1); 
    cout << endl << endl;
    
    string aux2;
	char str2[50] = "begin z = ((soma1 + 21)) * (2 / fator1); end"; 
    aux2 = parse(str2); 
	cout << endl << endl;
	
	
	
	
	
	
	
	return 0;
}