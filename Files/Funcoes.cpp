#include "Funcoes.h"

//Apresenta um menu com a opção de add mais ou não.
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

		cout << "\n\n Confirma a operação? [S,n]: ";
		cin >> op;
		cin.ignore();
		op = toupper(op);

		if (op == 'S' || op == 'N')
			break;

	} while (op != 'S' && op != 'N');

	if (op == 'S')
		cout << "\n\n****** Operação confirmada ******\n\n";

	else
		cout << "\n\n****** Operação cancelada ******\n\n";

	return op;

}


//Verifica se tem letra na string. Retorna 1 se tiver e 0 caso contrário.
int verificaLetra(const string numero){

	//verificando se a string phone é um número.
	for (size_t cont = 0; cont < numero.size(); cont++){

		/*Para esse verificação, pegaremos cada caractere e tentaremos comparar com a tabelas ascii
		se falhar algum, não é um númeor válido.*/

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
		<< "\n 3.Alteração"
		<< "\n 4.Exclusão"
		<< "\n 5.Relatório"
		<< "\n 6.Extra"
		<< "\n 7.Sair"
		<< "\n Opção: ";

}


//Exibe um subMenu.
void subMenu(){

	cout << "\n 1.Pessoa"
		<< "\n 2.Telefone"
		<< "\n 3.Email"
		<< "\n 4.Tarefa"
		<< "\n 5.Sair"
		<< "\n Opção: ";

}


//Periodo de aniversariantes.
int periodoDeAniversariantes(vector<Pessoa> &agenda) {
	int diaPeriodoUm, mesPeriodoUm, diaPeriodoDois, mesPeriodoDois, diaPeriodoTres, mesPeriodoTres, testa;
	string dat1, dat2;

	do{
		cout << "\n Data do primeiro período (DD/MM): ";
		getline(cin, dat1);

		// Verifica se o usuário deseja sair.
		if (dat1 == "-1")
			return 0;

		// Verifica se a data é válida.
		testa = validaPersistenciaData(dat1);

		if (testa == 0)
			cout << "\n Data inválida!";

	} while (testa == 0);

	do{
		cout << "\n Data do segundo período (DD/MM): ";
		getline(cin, dat2);

		// Verifica se o usuário deseja sair.
		if (dat2 == "-1")
			return 0;

		// Verifica se a data é válida.
		testa = validaPersistenciaData(dat2);

		if (testa == 0)
			cout << "\n Data inválida!";

	} while (testa == 0);

	//Convertendo string da data em uma data de inteiro dia e mes.
	converteDiaMes(dat1, diaPeriodoUm, mesPeriodoUm);
	converteDiaMes(dat2, diaPeriodoDois, mesPeriodoDois);

	Pessoa ciadadao;

	//Percorrendo o vector agenda em busca de aniversariantes dentro do período.
	for (size_t cont = 0; cont < agenda.size(); cont++){

		ciadadao = agenda.at(cont);

		//Pegando a data de aniversário do cidadão.
		string data = agenda.at(cont).getDataAniversario();

		//Convertendo a data para verificar o período.
		converteDiaMes(data, diaPeriodoTres, mesPeriodoTres);

		testa = verificaData(diaPeriodoUm, mesPeriodoUm, diaPeriodoDois, mesPeriodoDois, diaPeriodoTres, mesPeriodoTres);

		//Se testa for igual a um, imprima o nome do sujeito.
		if (testa == 1)
			exibeIdentificacao(cont, agenda);


	}

	return 1;

} // periodoDeAniversariantes()

// Validando persistência da data de aniversário
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

	//Recebe o mês.
	mm = mm + data[3] + data[4];

	//converte a string dd para inteiro.
	dia = atoi(dd.c_str());

	//converte a string mm para inteiro.
	mes = atoi(mm.c_str());

	return 1;
}


//Função que verifica se a data de aniversário está dentro do período, se sim retorna 1, caso contrário retorna 0.
int verificaData(const int diaPeriodoUm, const int mesPeriodoUm, const int diaPeriodoDois, const int mesPeriodoDois, const int diaPeriodoTres, const int mesPeriodoTres){

	//Veririfca se o mês passado é maior que o primeiro período.
	if (mesPeriodoTres >= mesPeriodoUm){

		/*Verifica-se se o mes passado é menor que o segundo período. Caso seja verdadeiro a data passada
		pelo usuário está entre os dois períodos.*/

		if (mesPeriodoTres <= mesPeriodoDois){

			/*Após verificar os extremos do mês, é necessário verifica se o dia fornecido é persistente.
			Primeiro verifica se o mês é igual a um dos extremos. Se o mês fornecido for igual ao do primeiro
			período, verifica se o dia fornecido é maior que do primeiro perído. Se o mês fornecido for igual ao do segundo,
			verifica se o dia fornecido é menor. Se o mês fornecido é maior e menor ao primeiro e segundo perído
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


//Verifica quem faz aniversário nos próximos sete dias.
void verificaAniversarioSeteDias(vector<Pessoa>&agenda){

	string data;
	char dat[9];
	int dia, mes, ano = 0, diaAniversario, mesAniversario, anoAniversário = 0;

	//Pega a data do sistema.
	_strdate_s(dat);

	data = dat;

	//Converte o dia e mes em int.
	converteDiaMes(data, dia, mes);

	int aux, dd, mm, aa;

	aux = dia;
	dia = mes;
	mes = aux;

	//Cópia da data.
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

		//Verificando se faz aniversário nos próximos sete dias se sim, imprima.
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
		//validação ano bissexto
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


//Função que verifica se alguém faz aniversário hoje.
int verificaAniversariantes(vector<Pessoa>&agenda){

	string data;
	char dat[9];
	int dia, mes, ano = 0, diaAniversario, mesAniversario, anoAniversário = 0, testa = 0;

	//Pega a data do sistema.
	_strdate_s(dat);

	data = dat;

	//Converte o dia e mes em int.
	converteDiaMes(data, dia, mes);

	int aux, dd, mm, aa;

	aux = dia;
	dia = mes;
	mes = aux;

	//Cópia da data.
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