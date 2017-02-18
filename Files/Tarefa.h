#ifndef TAREFA_H
#define TAREFA_H

#include "Telefone.h"

class Tarefa {
public:
	Tarefa();
	Tarefa(int codigo, string tarefa, tm tempo);

	int getCodigo();
	void setCodigo(int codigo);

	string getTarefa();
	void setTarefa(string tarefa);

	tm getTempo();
	void setTempo(tm tempo);

private:
	int codigo; // Código único de identificação da tarefa. 
	string tarefa; // Texto breve e objetivo que descreve a tarefa a ser realizada.
	tm tempo; // Esta estrutura armazena a data e a hora em que a tarefa será realizada.
};
#endif