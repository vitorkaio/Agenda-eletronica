#include "Consulta.h"

//Neste arquivo sera implementada as função que manipulam a consulta da agenda
int consultaPessoa(vector<Pessoa>&agenda){

	string nome;
	int testa;

	cout << "\n\n******************* Consulta *******************\n";

	do{

		cout << "\n Forneça o nome: ";
		getline(cin, nome);

		if (nome == "-1")
			return -1;

		//Verifica se existe alguma pessoa com esse nome.
		testa = verificaNome(agenda, nome);

		if (testa == -1)
			cout << "\n\n Nome inválido\n";


	} while (testa == -1);

	exibePessoa(testa,agenda);

	return 1;

}//consultaPessoa()


//Consulta os telefone de uma pessoa.
int consultaTelefone(vector<Pessoa>&agenda){

	string nome;
	int testa;

	cout << "\n\n******************* Consulta Telefone *******************\n";

	do{

		cout << "\n Forneça o nome: ";
		getline(cin, nome);

		if (nome == "-1")
			return -1;

		//Verifica se existe alguma pessoa com esse nome.
		testa = verificaNome(agenda, nome);

		if (testa == -1)
			cout << "\n\n Nome inválido\n";

	} while (testa == -1);
	
	//Exibe os dados da pessoa.
	exibeIdentificacao(testa, agenda);
	exibeTelefones(testa, agenda);

	return 1;

}//consultaTelefone()


//Consulta os emails de uma pessoa.
int consultaEmail(vector<Pessoa>&agenda){

	string nome;
	int testa;

	cout << "\n\n******************* Consulta Telefone *******************\n";

	do{

		cout << "\n Forneça o nome: ";
		getline(cin, nome);

		if (nome == "-1")
			return -1;

		//Verifica se existe alguma pessoa com esse nome.
		testa = verificaNome(agenda, nome);

		if (testa == -1)
			cout << "\n\n Nome inválido\n";

	} while (testa == -1);

	//Exibe os dados da pessoa.
	exibeIdentificacao(testa, agenda);
	exibeEmails(testa, agenda);

	return 1;

}//consultaEmail()


//Consulta uma tarefa através do id da pessoa e da data da tarefa.
int consultaTarefa(vector<Pessoa>&agenda){

	int id, testaId, testa;

	cout << "\n\n******************* Consulta Tarefa *******************\n";

	do{

		cout << "\n Forneça o id: ";
		cin >> id;
		cin.ignore();

		if (id == -1)
			return -1;

		//Verifica se existe alguma pessoa com esse nome.
		testaId = verificaId(agenda, id);

		if (testaId == -1)
			cout << "\n\n id inválido\n";

	} while (testaId == -1);

	//********************************************* Data da Tarefa *********************************************

	// Lendo e validando a data.

	int d, m, a, verifica;

	do{

		testa = lendoUmaData(d, m, a);

		if (testa == -1)
			return -1;

		verifica = pesquisaTarefaData(agenda.at(testaId), d, m, a);

		if (verifica == -1)
			cout << "\n\n Data inválida\n\n";
	
	
	} while (verifica == -1);

	//Exibe os dados da pessoa.
	exibeIdentificacao(testaId, agenda);
	exibeTarefaUnica(testaId, agenda, verifica);


	return 1;
}