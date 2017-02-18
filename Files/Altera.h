#ifndef ALTERA_H
#define ALTERA_H

#include "Relatorio.h"

//Neste arquivo ser� implementado as fun��o que alteram as pessoas.

//Altera o nome, id ou a data. retorna 1 em caso de sucesso e -1 caso contr�rio.
int alteraPessoa(vector<Pessoa>&agenda);

//Altera o telefone de uma pessoa. Retorna 1 em caso de sucesso e -1 caso contr�rio.
int alteraTelefone(vector<Pessoa>&agenda);

//Altera o email de uma pessoa. Retorna 1 em caso de sucesso e -1 caso contr�rio.
int alteraEmail(vector<Pessoa>&agenda);

//Altera a tarefa de uma pessoa. Retorna 1 em caso de sucesso e -1 caso contr�rio.
int alteraTarefa(vector<Pessoa>&agenda);

#endif