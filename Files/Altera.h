#ifndef ALTERA_H
#define ALTERA_H

#include "Relatorio.h"

//Neste arquivo será implementado as função que alteram as pessoas.

//Altera o nome, id ou a data. retorna 1 em caso de sucesso e -1 caso contrário.
int alteraPessoa(vector<Pessoa>&agenda);

//Altera o telefone de uma pessoa. Retorna 1 em caso de sucesso e -1 caso contrário.
int alteraTelefone(vector<Pessoa>&agenda);

//Altera o email de uma pessoa. Retorna 1 em caso de sucesso e -1 caso contrário.
int alteraEmail(vector<Pessoa>&agenda);

//Altera a tarefa de uma pessoa. Retorna 1 em caso de sucesso e -1 caso contrário.
int alteraTarefa(vector<Pessoa>&agenda);

#endif