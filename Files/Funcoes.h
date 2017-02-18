#ifndef FUNCOES_H
#define FUNCOES_H

#include "Pessoa.h"
#include "Relatorio.h"
#include "EntradaEValidacoes.h"

//Apresenta um menu com a op��o de add mais ou n�o.
char pergunta();

//Tem certeza?
char confirmacao();

//Verifica se tem letra na string. Retorna 1 se tiver e 0 caso contr�rio.
int verificaLetra(const string numero);

// Verifica a letra ou char.
int verificaLetraECaractere(const string caractere);

//Exibe um menu.
void menu();

//Exibe um submenu.
void subMenu();

//Periodo de aniversariantes.
int periodoDeAniversariantes(vector<Pessoa> &agenda);

// Validando persist�ncia da data de anivers�rio
int validaPersistenciaData(string &data);

//Converte uma string que armazana data(DD/MM) em inteiro.
int converteDiaMes(string &data, int &dia, int &mes);

//Fun��o que verifica se a data de anivers�rio est� dentro do per�odo, se sim retorna 1, caso contr�rio retorna 0.
int verificaData(const int diaPeriodoUm, const int mesPeriodoUm, const int diaPeriodoDois, const int mesPeriodoDois, const int diaPeriodoTres, const int mesPeriodoTres);

//Verifica quem faz anivers�rio nos pr�ximos sete dias.
void verificaAniversarioSeteDias(vector<Pessoa>&agenda);

//Incrementa a data.
void incrementaData(int &dia, int &mes, int &ano);

//Fun��o que verifica se algu�m faz anivers�rio hoje.
int verificaAniversariantes(vector<Pessoa>&agenda);

// Limpa a Tela
void inline limpaTela() {
	system("cls");
} // limpaTela()

void inline pause() {

	cout << "\n";
	system("pause");
	cout << "\n";

} // pause()
#endif