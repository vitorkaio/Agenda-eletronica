#ifndef EMAIL_H
#define EMAIL_H

#include "Tarefa.h"

class Email {
public:
	Email();
	Email(string email, char uso);

	string getEmail();
	void setEmail(string email);

	char getUso();
	void setUso(char uso);

private:
	string email; // Endereço eletrônico.
	char uso; // Indica o uso do e-mail, se Pessoal ('P') ou Trabalho ('T').

};
#endif