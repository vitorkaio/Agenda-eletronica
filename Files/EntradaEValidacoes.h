#ifndef ENTRADAEVALIDACOES_H
#define ENTRADAEVALIDACOES_H

#include "Pessoa.h"
#include "Funcoes.h"

//Recebe o id do usu�rio, retorna 1 em caso de sucesso, -1 caso de cancelamento e 0 caso de erro.
int entradaId();

//Verifica se o id j� existe, se sim retorna a posi��o, caso contr�rio retorna -1.
int verificaId(vector<Pessoa>&agenda, int &id);

//Recebe o nome do usu�rio, retorna 1 em caso de sucesso, -1 caso de cancelamento e 0 caso de erro.
int entradaNome(string &nome);

//Verifica se o nome j� existe, se sim retorna a posi��o, caso contr�rio o retorna 0.
int verificaNome(vector<Pessoa>&agenda, const string nome);

//Recebe a data de anivers�rio da pessoa, retorna 1 caso de sucesso e 0 caso contr�rio e -1 para cancelar.
int entradaDataDeAniversario(string &data);

//Valida a data. retorna 1 em caso de sucesso e 0 caso contr�rio.
int validaData(int dia, int mes, int ano);

//Recebe e valida o telefone da pessoa. Retorna 1 em caso de sucesso, 0 caso contr�rio, -1 para cancelar e 2 se quiser pular.
int entradaEValida��oDoTelefone(Pessoa cidadao, Telefone &telefone);

//Recebe e valida o email da pessoa. Retorna 1 em caso de sucesso, 0 caso contr�rio, -1 para cancelar e 2 se quiser pular.
int entradaEValida��oDoEmail(Pessoa cidadao, Email &email);

//Recebe e valida a tarefa da pessoa. Retorna 1 em caso de sucesso, 0 caso contr�rio, -1 para cancelar e 2 se quiser pular.
int entradaEValida��oDaTarefa(Pessoa cidadao, Tarefa &tarefa);

//Valida as horas. Retorna 1 em caso de sucesso e 0 caso contr�rio.
int validaHoras(int horas, int minutos, int segundos);

//Pesquisa a tarefa de acordo com a data.
int pesquisaTarefaData(Pessoa individuo, int dia, int mes, int ano);

//L� uma data.
int lendoUmaData(int &dia, int &mes, int &ano);

#endif