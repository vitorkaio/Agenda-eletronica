#ifndef ENTRADAEVALIDACOES_H
#define ENTRADAEVALIDACOES_H

#include "Pessoa.h"
#include "Funcoes.h"

//Recebe o id do usuário, retorna 1 em caso de sucesso, -1 caso de cancelamento e 0 caso de erro.
int entradaId();

//Verifica se o id já existe, se sim retorna a posição, caso contrário retorna -1.
int verificaId(vector<Pessoa>&agenda, int &id);

//Recebe o nome do usuário, retorna 1 em caso de sucesso, -1 caso de cancelamento e 0 caso de erro.
int entradaNome(string &nome);

//Verifica se o nome já existe, se sim retorna a posição, caso contrário o retorna 0.
int verificaNome(vector<Pessoa>&agenda, const string nome);

//Recebe a data de aniversário da pessoa, retorna 1 caso de sucesso e 0 caso contrário e -1 para cancelar.
int entradaDataDeAniversario(string &data);

//Valida a data. retorna 1 em caso de sucesso e 0 caso contrário.
int validaData(int dia, int mes, int ano);

//Recebe e valida o telefone da pessoa. Retorna 1 em caso de sucesso, 0 caso contrário, -1 para cancelar e 2 se quiser pular.
int entradaEValidaçãoDoTelefone(Pessoa cidadao, Telefone &telefone);

//Recebe e valida o email da pessoa. Retorna 1 em caso de sucesso, 0 caso contrário, -1 para cancelar e 2 se quiser pular.
int entradaEValidaçãoDoEmail(Pessoa cidadao, Email &email);

//Recebe e valida a tarefa da pessoa. Retorna 1 em caso de sucesso, 0 caso contrário, -1 para cancelar e 2 se quiser pular.
int entradaEValidaçãoDaTarefa(Pessoa cidadao, Tarefa &tarefa);

//Valida as horas. Retorna 1 em caso de sucesso e 0 caso contrário.
int validaHoras(int horas, int minutos, int segundos);

//Pesquisa a tarefa de acordo com a data.
int pesquisaTarefaData(Pessoa individuo, int dia, int mes, int ano);

//Lê uma data.
int lendoUmaData(int &dia, int &mes, int &ano);

#endif