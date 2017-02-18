#ifndef TELEFONE_H
#define TELEFONE_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdarg>

using namespace std;

class Telefone {

public:
	Telefone();
	Telefone(string numero, char tipo, char uso);

	string getNumero();
	void setNumero(string numero);

	char getTipo();
	void setTipo(char tipo);

	char getUso();
	void setUso(char uso);

private:

	string numero; // Número do telefone.
	char tipo, // Indica o tipo do telefone, se Fixo ('F'), Móvel ('M') ou fAx ('A').
		 uso; // Indica o uso do telefone, se Pessoal ('P') ou Trabalho ('T').
};

#endif