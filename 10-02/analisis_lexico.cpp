/* Implemente un codigo de analisis lexico en C++ para los tokens id,
   numero, relop del caso discutido en clase. Puede utilizar solo
   condicionales (if, while), o combinarlos con switch (cases)
   
 * Comente sobre como implementaria la gramatica en C++ que acepte
   sentencias de condicionales completas. Puede construir un pseudocodigo.
 */

#include <stdexcept>
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <math.h>

std::ifstream fi;
std::ofstream fo;

enum TOKEN {
	ID, RELOP, NUM, ERROR
};

void lexicalAnalysis();

void writeTOKEN(TOKEN token, std::string value);


int main() {
	fi.open("in.txt");
	fo.open("out.txt");
	if (!fi || !fo)
		throw "Error while opening the file";
	lexicalAnalysis();
	return 0;
}

void lexicalAnalysis(){
	std::string input;

	int i = 0;
	while (std::getline(fi, input)) {
    std::cout << input << "\n";
    i = 0;
		while (i < input.size()){
			if (input[i] == ' ' || input[i] == ';')
				++i;
			else if(isdigit(input[i])){
				std::string n;
				std::string exp;
				bool isFloat = false, isExp = false;
				while (isdigit(input[i]) || input[i] == '.' || input[i]=='E') {
					if (input[i] == '.')
						if (isFloat || isExp) writeTOKEN(TOKEN::ERROR, "Invalid number");	else isFloat = true;
							
					else if (input[i] == 'E'){
						if (isExp) writeTOKEN(TOKEN::ERROR, "Invalid number"); else isExp = true;	++i;
						if (input[i] != '+' && input[i] != '-') writeTOKEN(TOKEN::ERROR, "Invalid number");
					}
					isExp ? exp.push_back(input[i]) : n.push_back(input[i]);
					++i;
				}
				double number = std::stod(n);
				if (isExp) number *= std::pow(10, std::stod(exp));
				writeTOKEN(TOKEN::NUM, std::to_string(number));
			}
			else if(isalpha(input[i])){
				std::string id;
				while (isalnum(input[i])){ 
					id.push_back(input[i]);
					++i;
				}
				writeTOKEN(TOKEN::ID, id);
			}
			else if (input[i] == '<'){
				if (input[++i] == '='){
					writeTOKEN(TOKEN::RELOP, "LE, <=");
					++i;
				}
				else
					writeTOKEN(TOKEN::RELOP, "LT, <");
			}
			else if (input[i] == '>'){
				if (input[++i] == '='){
					writeTOKEN(TOKEN::RELOP, "GE, >=");
					++i;
				}
				else
					writeTOKEN(TOKEN::RELOP, "GT, >");
			}
			else if (input[i] == '='){
				if (input[++i] == '='){
					writeTOKEN(TOKEN::RELOP, "EQ, ==");
					++i;
				}
				else
					writeTOKEN(TOKEN::ERROR, "Invalid character " + std::string(1, input[i])); ++i;
			}
			else
				writeTOKEN(TOKEN::ERROR, "Invalid character " + std::string(1, input[i])); ++i;
		}
    fo << '\n';
  }
}


void writeTOKEN(TOKEN token, std::string value){
	switch (token){
	case ID:
		fo << "<ID, " << value << "> ";
		break;
	case RELOP:
		fo << "<RELOP, " << value << "> ";
		break;
	case NUM:
		fo << "<NUMBER, " << value << "> ";
		break;
	case ERROR:
		fo << "<ERROR, " << value << "> ";	
		break;
	default:
		break;
	}
}