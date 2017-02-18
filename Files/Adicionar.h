#ifndef ADICIONAR_H
#define ADICIONAR_H

#include "Relatorio.h"
#include "Pessoa.h"
#include "EntradaEValidacoes.h"
#include "Funcoes.h"

// Neste arquivo será implementado as funções que adicionam Pessoa novo telefone, email e tarefa.

//Adiciona uma pessoa na agenda.
int adicionaPessoa(vector<Pessoa>&agenda);

//Adiciona um novo telefone. Deve ser passado o id da pessoa.
int adicionaTelefone(vector<Pessoa>&agenda);

//Adiciona um novo Email. Deve ser passado o id da pessoa.
int adicionaEmail(vector<Pessoa>&agenda);

//Adiciona uma nova tarefa. Deve ser passado o id da pessoa.
int adicionaTarefa(vector<Pessoa>&agenda);

#endif