#ifndef EXCLUIR_H
#define EXCLUIR_H

#include "Relatorio.h"
#include "Altera.h"

//Neste arquivo será implementada as funções que gerenciam a exclusão.

//Exclui uma pessoa da agenda. Retorna em caso de sucesso e -1 caso contrário.
int excluiPessoa(vector<Pessoa>&agenda);

//Exclui um telefone da pessoa. Retorna em caso de sucesso e -1 caso contrário.
int excluiTelefone(vector<Pessoa>&agenda);

//Exclui um email da pessoa. Retorna em caso de sucesso e -1 caso contrário.
int excluiEmail(vector<Pessoa>&agenda);

//Exclui uma tarefa da pessoa. Retorna em caso de sucesso e -1 caso contrário.
int excluiTarefa(vector<Pessoa>&agenda);


#endif