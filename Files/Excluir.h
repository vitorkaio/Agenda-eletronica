#ifndef EXCLUIR_H
#define EXCLUIR_H

#include "Relatorio.h"
#include "Altera.h"

//Neste arquivo ser� implementada as fun��es que gerenciam a exclus�o.

//Exclui uma pessoa da agenda. Retorna em caso de sucesso e -1 caso contr�rio.
int excluiPessoa(vector<Pessoa>&agenda);

//Exclui um telefone da pessoa. Retorna em caso de sucesso e -1 caso contr�rio.
int excluiTelefone(vector<Pessoa>&agenda);

//Exclui um email da pessoa. Retorna em caso de sucesso e -1 caso contr�rio.
int excluiEmail(vector<Pessoa>&agenda);

//Exclui uma tarefa da pessoa. Retorna em caso de sucesso e -1 caso contr�rio.
int excluiTarefa(vector<Pessoa>&agenda);


#endif