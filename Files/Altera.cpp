#include "Altera.h"

//Altera o nome, id ou a data. retorna 1 em caso de sucesso e -1 caso contrário.
int alteraPessoa(vector<Pessoa>&agenda){

	string nome, data;
	int testa, geral, id;
	Pessoa cidadao;

	cout << "\n\n******************* Altera Pessoa *******************\n";

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
	exibeIdentificacao(testa, agenda);

	//Salva os dados da pessoa, pois se a operação for cancelada, ela retorna.
	cidadao = agenda.at(testa);

	//Retira a pessoa do vector.
	agenda.erase(agenda.begin() + testa);

	cout << "\n\n******************* Novos Dados *******************\n";

	//Lê um nome válido para os novos dados.
	do{

		cout << "\n Forneça o nome: ";
		getline(cin, nome);

		if (nome == "-1"){

			//Se a operação for cancelada, retorna a pessoa para o vector.
			agenda.push_back(cidadao);
			return -1;

		}
		return -1;

		//Verifica se existe alguma pessoa com esse nome.
		testa = verificaNome(agenda, nome);

		if (testa != -1)
			cout << "\n\n Nome inválido\n";


	} while (testa != -1);

	/*************************************** id ***************************************/

	//Lê um código válido para os novos dados.

	//Fica no loop até o id for passado corretamente ou a operação for cancelada.
	do{

		/*id recebe o id passado pelo usuário, se for 0 houve algum erro, se for -1 o usuário deseja
		encerrar a operação, caso contrário o id recebera normalmente a entrada.*/
		id = entradaId();

		//Usuário deseja sair.
		if (id == -1){

			//Se a operação for cancelada, retorna a pessoa para o vector.
			agenda.push_back(cidadao);
			return -1;

		}

		//Verificando se o id já existe na agenda.
		testa = verificaId(agenda, id);

		if (testa != -1)
			cout << "\n\n id inválido\n\n";

	} while (testa != -1);

	/*************************************** Data ***************************************/

	do{

		//Lê uma data válida para os novos dados.
		testa = entradaDataDeAniversario(data);

		if (testa == -1){
			//Se a operação for cancelada, retorna a pessoa para o vector.
			agenda.push_back(cidadao);
			return -1;

		}

		if (testa == 0)
			cout << "\n\n Data inválida\n\n";

	} while (testa == 0);

	/******************************************************************************/

	//Se a operação for confirmada, altera e insere no vector.
	if (confirmacao() == 'S'){

		cidadao.setNome(nome);
		cidadao.setCodigo(id);
		cidadao.setDataAniversario(data);

		agenda.push_back(cidadao);

	}

	//Se a operação for cancelada, retorna a pessoa para o vector.
	else{

		agenda.push_back(cidadao);

	}

	return 1;

}//alteraPessoa()


//Altera o telefone de uma pessoa. Retorna 1 em caso de sucesso e -1 caso contrário.
int alteraTelefone(vector<Pessoa>&agenda){

	string nome, tell, aux;
	int testa, geral, testaTelefone, geralTelefone;
	Pessoa cidadao;

	cout << "\n\n******************* Altera Telefone *******************\n";

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

		//Lendo o telefone que deseja alterar.
		cout << "\n\n\n Telefone que deseja altera: ";
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

		if (testaTelefone == -1){

			cout << "\n\n Telefone inválido";
			aux.clear();
			tell.clear();

		}

	} while (testaTelefone == -1);

	//Recebendo a referência do telefone que deseja alterar.
	Telefone phone, *telefone = cidadao.obterTelefone(testaTelefone);

	//phone recebe *telefone, pois ao excluir o telefone a referência muda.
	phone = *telefone;

	//Segurança.
	geralTelefone = testaTelefone;

	//Revome o telefone do vector.
	cidadao.removerTelefone(testaTelefone);

	Telefone telefoneNovo;

	/*************************************** Novo Telefone ***************************************/

	/*Lendo o novo telefone. Se o retorno da função for igual a -1, o usuário deseja sair, e por isso
	  Deve-se voltar o telefone para o cidadao e a pessoa para a agenda.*/

	int verifica;

	do{

		verifica = entradaEValidaçãoDoTelefone(cidadao, telefoneNovo);

		//Se o usuário deseja sair, deve-se voltar o telefone ao seu lugar.
		if (verifica == -1){

			cidadao.adicionarTelefone(phone);
			agenda.push_back(cidadao);
			return -1;

		}

		if (verifica == 0)
			cout << "\n\n Telefone inválido\n\n";


	} while (verifica == 0);


	//Exibe uma mensagem de confirmação, se for sim a operação é confirmado.
	if (confirmacao() == 'S'){

		cidadao.adicionarTelefone(telefoneNovo);
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

}//alteraTelefone()



//Altera o email de uma pessoa. Retorna 1 em caso de sucesso e -1 caso contrário.
int alteraEmail(vector<Pessoa>&agenda){

	string nome, tell;
	int testa, geral, testaEmail, geralEmail;
	Pessoa cidadao;

	cout << "\n\n******************* Altera Email *******************\n";

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

	/*************************************** Email ***************************************/

	do{

		//Lendo o email que deseja alterar.
		cout << "\n\n\n Email que deseja altera: ";
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

	/*Lendo o novo email. Se o retorno da função for igual a -1, o usuário deseja sair, e por isso
	Deve-se voltar o email para o cidadao e a pessoa para a agenda.*/

	/*************************************** Novo Email ***************************************/

	Email emailNovo;

	int verifica;

	do{

		verifica = entradaEValidaçãoDoEmail(cidadao, emailNovo);

		//Se o usuário deseja sair, deve-se voltar o telefone ao seu lugar.
		if (verifica == -1){

			cidadao.adicionarEmail(mail);
			agenda.push_back(cidadao);
			return -1;

		}

		if (verifica == 0)
			cout << "\n\n Email inválido\n\n";


	} while (verifica == 0);

	//Exibe uma mensagem de confirmação, se for sim a operação é confirmado.
	if (confirmacao() == 'S'){

		cidadao.adicionarEmail(emailNovo);
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

}//alteraEmail()



//Altera a tarefa de uma pessoa. Retorna 1 em caso de sucesso e -1 caso contrário.
int alteraTarefa(vector<Pessoa>&agenda){

	string nome, texto;
	int testa, geral, geralTarefa, id;
	Pessoa cidadao;

	cout << "\n\n******************* Altera Tarefa *******************\n";

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

	//********************************************* Data da Tarefa *********************************************

	// Lendo e validando a data.

	int d, m, a, verifica;

	do{

		verifica = lendoUmaData(d, m, a);

		if (verifica == -1)
			return -1;

		verifica = pesquisaTarefaData(cidadao, d, m, a);

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

	Tarefa tarefaNova;

	/*Lendo uma nova tarefa. Se o retorno da função for igual a -1, o usuário deseja sair, e por isso
	Deve-se voltar o email para o cidadao e a pessoa para a agenda.*/

	do{

		verifica = entradaEValidaçãoDaTarefa(cidadao, tarefaNova);

		if (verifica == -1 || verifica == 2){

			cidadao.adicionarTarefa(taf);
			agenda.push_back(cidadao);
			return -1;

		}

		if (verifica == 0)
			cout << "\n\n Tarefa inválida\n\n";

	} while (verifica == 0);

	//Exibe uma mensagem de confirmação, se for sim a operação é confirmado.
	if (confirmacao() == 'S'){

		cidadao.adicionarTarefa(tarefaNova);
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
