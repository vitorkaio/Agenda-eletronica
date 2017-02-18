#include "Funcoes.h"

//Apresenta um menu com a op��o de add mais ou n�o.
char pergunta(){

	char op;

	do{

		cout << "\n\n Adicionar mais[S/n]: ";
		cin >> op;
		cin.ignore();

		op = toupper(op);

		if (op == 'S' || op == 'N')
			break;

	} while (op != 'S' && op != 'N');

	return op;

}


//Tem certeza?
char confirmacao(){

	char op;

	do{

		cout << "\n\n Confirma a opera��o? [S,n]: ";
		cin >> op;
		cin.ignore();
		op = toupper(op);

		if (op == 'S' || op == 'N')
			break;

	} while (op != 'S' && op != 'N');

	if (op == 'S')
		cout << "\n\n****** Opera��o confirmada ******\n\n";

	else
		cout << "\n\n****** Opera��o cancelada ******\n\n";

	return op;

}


//Verifica se tem letra na string. Retorna 1 se tiver e 0 caso contr�rio.
int verificaLetra(const string numero){

	//verificando se a string phone � um n�mero.
	for (size_t cont = 0; cont < numero.size(); cont++){

		/*Para esse verifica��o, pegaremos cada caractere e tentaremos comparar com a tabelas ascii
		se falhar algum, n�o � um n�meor v�lido.*/

		char verifica = numero.at(cont);

		if (verifica < 48 || verifica > 59)
			return 1;

	}

	return 0;
}

// Verifica a letra ou char.
int verificaLetraECaractere(const string caractere) {

	if (caractere.length() > 1)
		return 1;
	else
		return 0;
}


//Exibe um menu.
void menu(){

	cout << "\n\t\t\t********** Agenda **********\n\n";

	cout << "\n 1.Cadastro"
		<< "\n 2.Consulta"
		<< "\n 3.Altera��o"
		<< "\n 4.Exclus�o"
		<< "\n 5.Relat�rio"
		<< "\n 6.Extra"
		<< "\n 7.Sair"
		<< "\n Op��o: ";

}


//Exibe um subMenu.
void subMenu(){

	cout << "\n 1.Pessoa"
		<< "\n 2.Telefone"
		<< "\n 3.Email"
		<< "\n 4.Tarefa"
		<< "\n 5.Sair"
		<< "\n Op��o: ";

}


//Periodo de aniversariantes.
int periodoDeAniversariantes(vector<Pessoa> &agenda) {
	int diaPeriodoUm, mesPeriodoUm, diaPeriodoDois, mesPeriodoDois, diaPeriodoTres, mesPeriodoTres, testa;
	string dat1, dat2;

	do{
		cout << "\n Data do primeiro per�odo (DD/MM): ";
		getline(cin, dat1);

		// Verifica se o usu�rio deseja sair.
		if (dat1 == "-1")
			return 0;

		// Verifica se a data � v�lida.
		testa = validaPersistenciaData(dat1);

		if (testa == 0)
			cout << "\n Data inv�lida!";

	} while (testa == 0);

	do{
		cout << "\n Data do segundo per�odo (DD/MM): ";
		getline(cin, dat2);

		// Verifica se o usu�rio deseja sair.
		if (dat2 == "-1")
			return 0;

		// Verifica se a data � v�lida.
		testa = validaPersistenciaData(dat2);

		if (testa == 0)
			cout << "\n Data inv�lida!";

	} while (testa == 0);

	//Convertendo string da data em uma data de inteiro dia e mes.
	converteDiaMes(dat1, diaPeriodoUm, mesPeriodoUm);
	converteDiaMes(dat2, diaPeriodoDois, mesPeriodoDois);

	Pessoa ciadadao;

	//Percorrendo o vector agenda em busca de aniversariantes dentro do per�odo.
	for (size_t cont = 0; cont < agenda.size(); cont++){

		ciadadao = agenda.at(cont);

		//Pegando a data de anivers�rio do cidad�o.
		string data = agenda.at(cont).getDataAniversario();

		//Convertendo a data para verificar o per�odo.
		converteDiaMes(data, diaPeriodoTres, mesPeriodoTres);

		testa = verificaData(diaPeriodoUm, mesPeriodoUm, diaPeriodoDois, mesPeriodoDois, diaPeriodoTres, mesPeriodoTres);

		//Se testa for igual a um, imprima o nome do sujeito.
		if (testa == 1)
			exibeIdentificacao(cont, agenda);


	}

	return 1;

} // periodoDeAniversariantes()

// Validando persist�ncia da data de anivers�rio
int validaPersistenciaData(string &data) {
	int dia, mes, ano, testa;
	string dd, mm, aaaa;

	if (data.length() == 0) {
		return 0;
	}

	if (data.size() != 5) {
		return 0;
	}

	if (data[2] != '/') {
		return 0;
	}

	dd = dd + data[0] + data[1];
	testa = verificaLetra(dd);

	if (testa == 1)
		return 0;

	mm = mm + data[3] + data[4];
	testa = verificaLetra(mm);

	if (testa == 1)
		return 0;

	dia = atoi(dd.c_str());
	mes = atoi(mm.c_str());
	ano = 2000;

	if (testa = validaData(dia, mes, ano) == 0) return 0;

	return 1;
}

//Converte uma string que armazana data(DD/MM) em inteiro.
int converteDiaMes(string &data, int &dia, int &mes){

	string dd, mm;

	//Recebe o dia.
	dd = dd + data[0] + data[1];

	//Recebe o m�s.
	mm = mm + data[3] + data[4];

	//converte a string dd para inteiro.
	dia = atoi(dd.c_str());

	//converte a string mm para inteiro.
	mes = atoi(mm.c_str());

	return 1;
}


//Fun��o que verifica se a data de anivers�rio est� dentro do per�odo, se sim retorna 1, caso contr�rio retorna 0.
int verificaData(const int diaPeriodoUm, const int mesPeriodoUm, const int diaPeriodoDois, const int mesPeriodoDois, const int diaPeriodoTres, const int mesPeriodoTres){

	//Veririfca se o m�s passado � maior que o primeiro per�odo.
	if (mesPeriodoTres >= mesPeriodoUm){

		/*Verifica-se se o mes passado � menor que o segundo per�odo. Caso seja verdadeiro a data passada
		pelo usu�rio est� entre os dois per�odos.*/

		if (mesPeriodoTres <= mesPeriodoDois){

			/*Ap�s verificar os extremos do m�s, � necess�rio verifica se o dia fornecido � persistente.
			Primeiro verifica se o m�s � igual a um dos extremos. Se o m�s fornecido for igual ao do primeiro
			per�odo, verifica se o dia fornecido � maior que do primeiro per�do. Se o m�s fornecido for igual ao do segundo,
			verifica se o dia fornecido � menor. Se o m�s fornecido � maior e menor ao primeiro e segundo per�do
			imprima todos os aniversariantes, independente do dia.
			*/

			if (mesPeriodoTres == mesPeriodoDois){

				if (diaPeriodoTres <= diaPeriodoDois){

					return 1;

				}

				else
					return 0;

			}

			else if (mesPeriodoTres == mesPeriodoUm){

				if (diaPeriodoTres >= diaPeriodoUm){

					return 1;

				}

				else
					return 0;

			}

			else
				return 1;

		}

		else
			return 0;


	}

	else
		return 0;



}


//Verifica quem faz anivers�rio nos pr�ximos sete dias.
void verificaAniversarioSeteDias(vector<Pessoa>&agenda){

	string data;
	char dat[9];
	int dia, mes, ano = 0, diaAniversario, mesAniversario, anoAnivers�rio = 0;

	//Pega a data do sistema.
	_strdate_s(dat);

	data = dat;

	//Converte o dia e mes em int.
	converteDiaMes(data, dia, mes);

	int aux, dd, mm, aa;

	aux = dia;
	dia = mes;
	mes = aux;

	//C�pia da data.
	dd = dia;
	mm = mes;
	aa = ano;

	Pessoa cidadao;

	for (size_t cont = 0; cont < agenda.size(); cont++){

		dia = dd;
		mes = mm;
		ano = aa;

		cidadao = agenda.at(cont);

		data = cidadao.getDataAniversario();

		converteDiaMes(data, diaAniversario, mesAniversario);

		//Verificando se faz anivers�rio nos pr�ximos sete dias se sim, imprima.
		for (int contador = 0; contador < 7; contador++){

			if (dia == diaAniversario && mes == mesAniversario)
				exibeIdentificacao(cont, agenda);

			incrementaData(dia, mes, ano);

		}

	}



}


//Incrementa a data.
void incrementaData(int &dia, int &mes, int &ano){


	dia += 1;

	if (mes == 2){
		//valida��o ano bissexto
		if (ano % 4 == 0 || ano % 100 != 0 || ano % 400 == 0){

			if (dia > 29){

				dia = 1;
				mes++;
			}
		}

		else if (dia > 28){

			dia = 1;
			mes++;
		}



	}
	else if (mes == 4 || mes == 6 || mes == 9 || mes == 11){

		if (dia > 30){

			dia = 1;
			mes++;

		}

	}
	else{
		if (dia > 31){
			//date->dia=date->dia%30;
			dia = 1;
			mes++;
		}
	}
	if (mes > 12){
		ano++;
		mes = 1;
	}

}


//Fun��o que verifica se algu�m faz anivers�rio hoje.
int verificaAniversariantes(vector<Pessoa>&agenda){

	string data;
	char dat[9];
	int dia, mes, ano = 0, diaAniversario, mesAniversario, anoAnivers�rio = 0, testa = 0;

	//Pega a data do sistema.
	_strdate_s(dat);

	data = dat;

	//Converte o dia e mes em int.
	converteDiaMes(data, dia, mes);

	int aux, dd, mm, aa;

	aux = dia;
	dia = mes;
	mes = aux;

	//C�pia da data.
	dd = dia;
	mm = mes;
	aa = ano;

	Pessoa cidadao;

	for (size_t cont = 0; cont < agenda.size(); cont++){

		dia = dd;
		mes = mm;
		ano = aa;

		cidadao = agenda.at(cont);

		data = cidadao.getDataAniversario();

		converteDiaMes(data, diaAniversario, mesAniversario);


		if (dia == diaAniversario && mes == mesAniversario){

			exibeIdentificacao(cont, agenda);
			testa = 1;

		}


	}

	if (testa != 1)
		return 0;

}