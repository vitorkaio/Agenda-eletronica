#ifndef CONSULTA_H
#define CONSULTA_H

#include "Relatorio.h"

//Neste arquivo sera implementada as função que manipulam a consulta da agenda

//Consulta os dados de uma pessoa através do nome.
int consultaPessoa(vector<Pessoa>&agenda);

//Consulta os telefone de uma pessoa.
int consultaTelefone(vector<Pessoa>&agenda);

//Consulta os emails de uma pessoa.
int consultaEmail(vector<Pessoa>&agenda);

//Consulta uma tarefa através do id da pessoa e da data da tarefa.
int consultaTarefa(vector<Pessoa>&agenda);

#endif