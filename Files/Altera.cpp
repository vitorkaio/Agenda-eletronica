#include "Altera.h"

//Altera o nome, id ou a data. retorna 1 em caso de sucesso e -1 caso contr�rio.
int alteraPessoa(vector<Pessoa>&agenda){

	string nome, data;
	int testa, geral, id;
	Pessoa cidadao;

	cout << "\n\n******************* Altera Pessoa *******************\n";

	//Lendo um nome e verificando se ele existe, se sim, testa receber� sua posi��o.
	do{

		cout << "\n Forne�a o nome: ";
		getline(cin, nome);

		if (nome == "-1")
			return -1;

		//Verifica se existe alguma pessoa com esse nome.
		testa = verificaNome(agenda, nome);

		if (testa == -1)
			cout << "\n\n Nome inv�lido\n";


	} while (testa == -1);

	//guarda a posi��o real.
	geral = testa;

	//Exibe os dados da pessoa.
	exibeIdentificacao(testa, agenda);

	//Salva os dados da pessoa, pois se a opera��o for cancelada, ela retorna.
	cidadao = agenda.at(testa);

	//Retira a pessoa do vector.
	agenda.erase(agenda.begin() + testa);

	cout << "\n\n******************* Novos Dados *******************\n";

	//L� um nome v�lido para os novos dados.
	do{

		cout << "\n Forne�a o nome: ";
		getline(cin, nome);

		if (nome == "-1"){

			//Se a opera��o for cancelada, retorna a pessoa para o vector.
			agenda.push_back(cidadao);
			return -1;

		}
		return -1;

		//Verifica se existe alguma pessoa com esse nome.
		testa = verificaNome(agenda, nome);

		if (testa != -1)
			cout << "\n\n Nome inv�lido\n";


	} while (testa != -1);

	/*************************************** id ***************************************/

	//L� um c�digo v�lido para os novos dados.

	//Fica no loop at� o id for passado corretamente ou a opera��o for cancelada.
	do{

		/*id recebe o id passado pelo usu�rio, se for 0 houve algum erro, se for -1 o usu�rio deseja
		encerrar a opera��o, caso contr�rio o id recebera normalmente a entrada.*/
		id = entradaId();

		//Usu�rio deseja sair.
		if (id == -1){

			//Se a opera��o for cancelada, retorna a pessoa para o vector.
			agenda.push_back(cidadao);
			return -1;

		}

		//Verificando se o id j� existe na agenda.
		testa = verificaId(agenda, id);

		if (testa != -1)
			cout << "\n\n id inv�lido\n\n";

	} while (testa != -1);

	/*************************************** Data ***************************************/

	do{

		//L� uma data v�lida para os novos dados.
		testa = entradaDataDeAniversario(data);

		if (testa == -1){
			//Se a opera��o for cancelada, retorna a pessoa para o vector.
			agenda.push_back(cidadao);
			return -1;

		}

		if (testa == 0)
			cout << "\n\n Data inv�lida\n\n";

	} while (testa == 0);

	/******************************************************************************/

	//Se a opera��o for confirmada, altera e insere no vector.
	if (confirmacao() == 'S'){

		cidadao.setNome(nome);
		cidadao.setCodigo(id);
		cidadao.setDataAniversario(data);

		agenda.push_back(cidadao);

	}

	//Se a opera��o for cancelada, retorna a pessoa para o vector.
	else{

		agenda.push_back(cidadao);

	}

	return 1;

}//alteraPessoa()


//Altera o telefone de uma pessoa. Retorna 1 em caso de sucesso e -1 caso contr�rio.
int alteraTelefone(vector<Pessoa>&agenda){

	string nome, tell, aux;
	int testa, geral, testaTelefone, geralTelefone;
	Pessoa cidadao;

	cout << "\n\n******************* Altera Telefone *******************\n";

	//Lendo um nome e verificando se ele existe, se sim, testa receber� sua posi��o.
	do{

		cout << "\n Forne�a o nome: ";
		getline(cin, nome);

		if (nome == "-1")
			return -1;

		//Verifica se existe alguma pessoa com esse nome.
		testa = verificaNome(agenda, nome);

		if (testa == -1)
			cout << "\n\n Nome inv�lido\n";


	} while (testa == -1);

	//Exibe os dados da pessoa.
	exibeIdentificacao(testa, agenda);

	//Exibe os telefones da pessoa.
	exibeTelefones(testa, agenda);

	//guarda a posi��o real.
	geral = testa;

	//Salva os dados da pessoa, pois a opera��o for cancelada, ela retorna.
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

		//Se o usu�rio deseja sair, deve-se retorna o cidadao para o vector.
		if (tell == "-1"){

			agenda.push_back(cidadao);
			return -1;

		}

		//Colando () nas posi��es 0 e 3, - na posi��o 8.
		aux = aux + '(' + tell[0] + tell[1];
		aux = aux + ')' + tell[2] + tell[3] + tell[4] + tell[5];
		aux = aux + '-' + tell[6] + tell[7] + tell[8] + tell[9];

		//Pesquisando o telefone no vector.
		testaTelefone = cidadao.pesquisarTelefone(aux);

		if (testaTelefone == -1){

			cout << "\n\n Telefone inv�lido";
			aux.clear();
			tell.clear();

		}

	} while (testaTelefone == -1);

	//Recebendo a refer�ncia do telefone que deseja alterar.
	Telefone phone, *telefone = cidadao.obterTelefone(testaTelefone);

	//phone recebe *telefone, pois ao excluir o telefone a refer�ncia muda.
	phone = *telefone;

	//Seguran�a.
	geralTelefone = testaTelefone;

	//Revome o telefone do vector.
	cidadao.removerTelefone(testaTelefone);

	Telefone telefoneNovo;

	/*************************************** Novo Telefone ***************************************/

	/*Lendo o novo telefone. Se o retorno da fun��o for igual a -1, o usu�rio deseja sair, e por isso
	  Deve-se voltar o telefone para o cidadao e a pessoa para a agenda.*/

	int verifica;

	do{

		verifica = entradaEValida��oDoTelefone(cidadao, telefoneNovo);

		//Se o usu�rio deseja sair, deve-se voltar o telefone ao seu lugar.
		if (verifica == -1){

			cidadao.adicionarTelefone(phone);
			agenda.push_back(cidadao);
			return -1;

		}

		if (verifica == 0)
			cout << "\n\n Telefone inv�lido\n\n";


	} while (verifica == 0);


	//Exibe uma mensagem de confirma��o, se for sim a opera��o � confirmado.
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



//Altera o email de uma pessoa. Retorna 1 em caso de sucesso e -1 caso contr�rio.
int alteraEmail(vector<Pessoa>&agenda){

	string nome, tell;
	int testa, geral, testaEmail, geralEmail;
	Pessoa cidadao;

	cout << "\n\n******************* Altera Email *******************\n";

	//Lendo um nome e verificando se ele existe, se sim, testa receber� sua posi��o.
	do{

		cout << "\n Forne�a o nome: ";
		getline(cin, nome);

		if (nome == "-1")
			return -1;

		//Verifica se existe alguma pessoa com esse nome.
		testa = verificaNome(agenda, nome);

		if (testa == -1)
			cout << "\n\n Nome inv�lido\n";


	} while (testa == -1);

	//Exibe os dados da pessoa.
	exibeIdentificacao(testa, agenda);

	//Exibe os telefones da pessoa.
	exibeEmails(testa, agenda);

	//guarda a posi��o real.
	geral = testa;

	//Salva os dados da pessoa, pois a opera��o for cancelada, ela retorna.
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

		//Se o usu�rio deseja sair, deve-se retorna o cidadao para o vector.
		if (tell == "-1"){

			agenda.push_back(cidadao);
			return -1;

		}

		//Pesquisando o email no vector.
		testaEmail = cidadao.pesquisarEmail(tell);

		if (testaEmail == -1)
			cout << "\n\n Email inv�lido";

	} while (testaEmail == -1);

	//Recebendo a refer�ncia do email que deseja alterar.
	Email mail, *email = cidadao.obterEmail(testaEmail);

	//mail recebe *email, pois ao excluir o telefone a refer�ncia muda.
	mail = *email;

	//Seguran�a.
	geralEmail = testaEmail;

	//Revome o telefone do vector.
	cidadao.removerEmail(testaEmail);

	/*Lendo o novo email. Se o retorno da fun��o for igual a -1, o usu�rio deseja sair, e por isso
	Deve-se voltar o email para o cidadao e a pessoa para a agenda.*/

	/*************************************** Novo Email ***************************************/

	Email emailNovo;

	int verifica;

	do{

		verifica = entradaEValida��oDoEmail(cidadao, emailNovo);

		//Se o usu�rio deseja sair, deve-se voltar o telefone ao seu lugar.
		if (verifica == -1){

			cidadao.adicionarEmail(mail);
			agenda.push_back(cidadao);
			return -1;

		}

		if (verifica == 0)
			cout << "\n\n Email inv�lido\n\n";


	} while (verifica == 0);

	//Exibe uma mensagem de confirma��o, se for sim a opera��o � confirmado.
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



//Altera a tarefa de uma pessoa. Retorna 1 em caso de sucesso e -1 caso contr�rio.
int alteraTarefa(vector<Pessoa>&agenda){

	string nome, texto;
	int testa, geral, geralTarefa, id;
	Pessoa cidadao;

	cout << "\n\n******************* Altera Tarefa *******************\n";

	//Lendo um id e verificando se ele existe, se sim, testa receber� sua posi��o.
	do{

		cout << "\n Forne�a o id: ";
		cin >> id;
		cin.ignore();

		if (id == -1)
			return -1;

		//Verifica se existe alguma pessoa com esse nome.
		testa = verificaId(agenda, id);

		if (testa == -1)
			cout << "\n\n id inv�lido\n";


	} while (testa == -1);

	//Exibe os dados da pessoa.
	exibeIdentificacao(testa, agenda);

	//Exibe as tarefas da pessoa.
	exibeTarefas(testa, agenda);

	//guarda a posi��o real.
	geral = testa;

	//Salva os dados da pessoa, pois a opera��o for cancelada, ela retorna.
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
			cout << "\n\n Data inv�lida\n\n";

	} while (verifica == -1);

	//Recebendo a refer�ncia da tarefa que deseja alterar.
	Tarefa taf, *tarefa = cidadao.obterTarefa(verifica);

	//phone recebe *telefone, pois ao excluir o telefone a refer�ncia muda.
	taf = *tarefa;

	//Seguran�a.
	geralTarefa = verifica;

	//Revome o telefone do vector.
	cidadao.removerTarefa(verifica);

	Tarefa tarefaNova;

	/*Lendo uma nova tarefa. Se o retorno da fun��o for igual a -1, o usu�rio deseja sair, e por isso
	Deve-se voltar o email para o cidadao e a pessoa para a agenda.*/

	do{

		verifica = entradaEValida��oDaTarefa(cidadao, tarefaNova);

		if (verifica == -1 || verifica == 2){

			cidadao.adicionarTarefa(taf);
			agenda.push_back(cidadao);
			return -1;

		}

		if (verifica == 0)
			cout << "\n\n Tarefa inv�lida\n\n";

	} while (verifica == 0);

	//Exibe uma mensagem de confirma��o, se for sim a opera��o � confirmado.
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
