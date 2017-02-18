#include "Excluir.h"

//Exclui uma pessoa da agenda. Retorna em caso de sucesso e -1 caso contrário.
int excluiPessoa(vector<Pessoa>&agenda){

	string nome, data;
	int testa, geral;
	Pessoa cidadao;

	cout << "\n\n******************* Exclui Pessoa *******************\n";

	//Lendo um nome e verificando se ele existe, se sim, testa receberá sua posição.
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

	//guarda a posição real.
	geral = testa;

	//Exibe os dados da pessoa.
	exibePessoa(testa, agenda);

	if (confirmacao() == 'S'){

		//Remove a pessoa solicitada do vector.
		agenda.erase(agenda.begin() + testa);
		return 1;

	}

	else
		return -1;


	return 1;

}//excluiPessoa()


//Exclui um telefone da pessoa. Retorna em caso de sucesso e -1 caso contrário.
int excluiTelefone(vector<Pessoa>&agenda){

	string nome, tell, aux;
	int testa, geral, testaTelefone, geralTelefone;
	Pessoa cidadao;

	cout << "\n\n******************* Exclui Telefone *******************\n";

	//Lendo um nome e verificando se ele existe, se sim, testa receberá sua posição.
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

	//Exibe os telefones da pessoa.
	exibeTelefones(testa, agenda);

	//guarda a posição real.
	geral = testa;

	//Salva os dados da pessoa, pois a operação for cancelada, ela retorna.
	cidadao = agenda.at(testa);

	//Se a lista de telefones estiver vazia, retorne.
	if (cidadao.quantidadeDeTelefones() == 0){

		cout << "\n\n Lista vazia\n";
		return 0;

	}

	//Retira a pessoa do vector.
	agenda.erase(agenda.begin() + testa);


	do{

		//Limpando as strings.
		tell.clear();
		aux.clear();

		//Lendo o telefone que deseja excluir.
		cout << "\n\n\n Telefone que deseja excluir: ";
		getline(cin, tell);

		//Se o usuário deseja sair, deve-se retorna o cidadao para o vector.
		if (tell == "-1"){

			agenda.push_back(cidadao);
			return -1;

		}

		//Colando () nas posições 0 e 3, - na posição 8.
		aux = aux + '(' + tell[0] + tell[1];
		aux = aux + ')' + tell[2] + tell[3] + tell[4] + tell[5];
		aux = aux + '-' + tell[6] + tell[7] + tell[8] + tell[9];

		//Pesquisando o telefone no vector.
		testaTelefone = cidadao.pesquisarTelefone(aux);

		if (testaTelefone == -1)
			cout << "\n\n Telefone inválido";

	} while (testaTelefone == -1);

	//Recebendo a referência do telefone que deseja excluir.
	Telefone phone, *telefone = cidadao.obterTelefone(testaTelefone);

	phone = *telefone;

	//Segurança.
	geralTelefone = testaTelefone;

	//Revome o telefone do vector.
	cidadao.removerTelefone(testaTelefone);

		//Exibe uma mensagem de confirmação, se for sim a operação é confirmado.
	if (confirmacao() == 'S'){

		agenda.push_back(cidadao);

	}

		else{

			cidadao.adicionarTelefone(phone);
			agenda.push_back(cidadao);
			return -1;

		}	

	cout << "\n\n******************* Novos Dados *******************\n";

	//Exibe os dados da pessoa.
	exibeIdentificacao(testa, agenda);

	//Exibe os telefones da pessoa.
	exibeTelefones(testa, agenda);

	return 1;


}//excluiTelefone()


//Exclui um email da pessoa. Retorna em caso de sucesso e -1 caso contrário.
int excluiEmail(vector<Pessoa>&agenda){

	string nome, tell;
	int testa, geral, testaEmail, geralEmail;
	Pessoa cidadao;

	cout << "\n\n******************* Exclui Email *******************\n";

	//Lendo um nome e verificando se ele existe, se sim, testa receberá sua posição.
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

	//Exibe os telefones da pessoa.
	exibeEmails(testa, agenda);

	//guarda a posição real.
	geral = testa;

	//Salva os dados da pessoa, pois a operação for cancelada, ela retorna.
	cidadao = agenda.at(testa);

	//Se a lista de telefones estiver vazia, retorne.
	if (cidadao.quantidadeDeEmails() == 0){

		cout << "\n\n Lista vazia\n";
		return 0;

	}

	//Retira a pessoa do vector.
	agenda.erase(agenda.begin() + testa);


	do{

		//Lendo o email que deseja excluir.
		cout << "\n\n\n Email que deseja excluir: ";
		getline(cin, tell);

		//Se o usuário deseja sair, deve-se retorna o cidadao para o vector.
		if (tell == "-1"){

			agenda.push_back(cidadao);
			return -1;

		}

		//Pesquisando o email no vector.
		testaEmail = cidadao.pesquisarEmail(tell);

		if (testaEmail == -1)
			cout << "\n\n Email inválido";

	} while (testaEmail == -1);

	//Recebendo a referência do email que deseja alterar.
	Email mail, *email = cidadao.obterEmail(testaEmail);

	//mail recebe *email, pois ao excluir o telefone a referência muda.
	mail = *email;

	//Segurança.
	geralEmail = testaEmail;

	//Revome o telefone do vector.
	cidadao.removerEmail(testaEmail);


		//Exibe uma mensagem de confirmação, se for sim a operação é confirmado.
		if (confirmacao() == 'S'){

			agenda.push_back(cidadao);

		}

		else{

			cidadao.adicionarEmail(mail);
			agenda.push_back(cidadao);
			return -1;

		}


	cout << "\n\n******************* Novos Dados *******************\n";

	//Exibe os dados da pessoa.
	exibeIdentificacao(testa, agenda);

	//Exibe os emails da pessoa.
	exibeEmails(testa, agenda);

	return 1;

}//excluiEmail()


//Exclui uma tarefa da pessoa. Retorna em caso de sucesso e -1 caso contrário.
int excluiTarefa(vector<Pessoa>&agenda){

	string nome, texto;
	int testa, geral, geralTarefa, dia, mes, ano, id;
	Pessoa cidadao;

	cout << "\n\n******************* Exclui Tarefa *******************\n";

	//Lendo um id e verificando se ele existe, se sim, testa receberá sua posição.
	do{

		cout << "\n Forneça o id: ";
		cin >> id;
		cin.ignore();

		if (id == -1)
			return -1;

		//Verifica se existe alguma pessoa com esse nome.
		testa = verificaId(agenda, id);

		if (testa == -1)
			cout << "\n\n id inválido\n";


	} while (testa == -1);

	//Exibe os dados da pessoa.
	exibeIdentificacao(testa, agenda);

	//Exibe as tarefas da pessoa.
	exibeTarefas(testa, agenda);

	//guarda a posição real.
	geral = testa;

	//Salva os dados da pessoa, pois a operação for cancelada, ela retorna.
	cidadao = agenda.at(testa);

	//Se a lista de telefones estiver vazia, retorne.
	if (cidadao.quantidadeDeTarefas() == 0){

		cout << "\n\n Lista vazia\n";
		return 0;

	}

	//Retira a pessoa do vector.
	agenda.erase(agenda.begin() + testa);

	// Lendo e validando a data.

	int verifica;

	do{

		verifica = lendoUmaData(dia, mes, ano);

		if (verifica == -1)
			return -1;

		verifica = pesquisaTarefaData(cidadao, dia, mes, ano);

		if (verifica == -1)
			cout << "\n\n Data inválida\n\n";

	} while (verifica == -1);


	//Recebendo a referência da tarefa que deseja alterar.
	Tarefa taf, *tarefa = cidadao.obterTarefa(verifica);

	//phone recebe *telefone, pois ao excluir o telefone a referência muda.
	taf = *tarefa;

	//Segurança.
	geralTarefa = verifica;

	//Revome o telefone do vector.
	cidadao.removerTarefa(verifica);


		//Exibe uma mensagem de confirmação, se for sim a operação é confirmado.
		if (confirmacao() == 'S'){

			agenda.push_back(cidadao);

		}

		else{

			cidadao.adicionarTarefa(taf);
			agenda.push_back(cidadao);
			return -1;

		}

	


	cout << "\n\n******************* Novos Dados *******************\n";

	//Exibe os dados da pessoa.
	exibeIdentificacao(testa, agenda);

	//Exibe as tarefas da pessoa.
	exibeTarefas(testa, agenda);

	return 1;


}