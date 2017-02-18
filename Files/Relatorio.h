#ifndef RELATORIO_H
#define RELATORIO_H

#include "Adicionar.h"
#include "Pessoa.h"


//Exibe dados.

//Exibe os dados de todas as pessoas da agenda.
void exibeAgenda(vector<Pessoa>&agenda);

//Exibe os dados de uma pessoa.
void exibePessoa(int posicao, vector<Pessoa>&agenda);

//Exibe o nome, id e data de nascimento.
void exibeIdentificacao(int posicao, vector<Pessoa>&agenda);

//Exibe o nome, id, data de nascimento e os telefones da pessoa.
void exibeTelefones(int posicao, vector<Pessoa>&agenda);

//Exibe o nome, id, data de nascimento e os emails da pessoa.
void exibeEmails(int posicao, vector<Pessoa>&agenda);

//Exibe o nome, id, data de nascimento e os tarefas da pessoa.
void exibeTarefas(int posicao, vector<Pessoa>&agenda);

// Exibe as tarefas de acordo com a data passada.
void exibeTarefaUnica(int posicao, vector<Pessoa>&agenda, int posicaoTarefa);

//Exibe o id, nome e a tarefa da pessoa.
void exibeRelatorio(vector<Pessoa>agenda, int posicaoDaPessoa, int posicaoDaTarefa);



#endif