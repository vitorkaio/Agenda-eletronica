#include "Adicionar.h"

//Adiciona uma pessoa na agenda.
int adicionaPessoa(vector<Pessoa>&agenda){

	Pessoa cidadao;
	Telefone telefone;
	Email email;
	Tarefa tarefa;

	int id, testaOpcao;
	string nomeDaPessoa, dataDeAniversario;

	cout << "\n******************* Cadastra Pessoa *******************\n\n";

	//****************************** Recebe o id da pessoa ******************************

	//Fica no loop até o id for passado corretamente ou a operação for cancelada.
	do{

		/*id recebe o id passado pelo usuário, se for 0 houve algum erro, se for -1 o usuário deseja
		encerrar a operação, caso contrário o id recebera normalmente a entrada.*/
		id = entradaId();

		//Usuário deseja sair.
		if (id == -1 || id == 0)
			return -1;

		//Verificando se o id já existe na agenda.
		testaOpcao = verificaId(agenda, id);

		if (testaOpcao != -1)
			cout << "\n\n id inválido\n\n";

	} while (testaOpcao != -1);

	//************************************************************

	//****************************** Recebe o nome da pessoa ******************************

	//Fica no loop até o usuário digitar um nome que não tenha sido cadastrado, ou -1 apra cancelar.
	do{

		testaOpcao = entradaNome(nomeDaPessoa);

		//Usuário deseja sair.
		if (testaOpcao == -1)
			return -1;

		testaOpcao = verificaNome(agenda, nomeDaPessoa);

		if (testaOpcao != -1)
			cout << "\n\n Nome inválido\n\n";

	} while (testaOpcao != -1);

	//************************************************************

	//****************************** Recebe a data de aniversário da pessoa ******************************

	//Fica no loop até ser cancelado -1 ou a data ser digitada corretamente.
	do{

		testaOpcao = entradaDataDeAniversario(dataDeAniversario);

		//Usuário deseja sair.
		if (testaOpcao == -1)
			return -1;

		if (testaOpcao == 0)
			cout << "\n\n Data inválida\n\n";

	} while (testaOpcao == 0);

	//************************************************************

	//****************************** Recebe o telefone da pessoa ******************************

	//Fica no loop até o usuário digitar 'N', ou pular o cadastro do telefone.
	do{

		//Se o usuário não quiser cadastar agora, passa uma string vazia e o loop para.
		int verifica;

		do{

			verifica = entradaEValidaçãoDoTelefone(cidadao, telefone);

			//Usuário deseja sair.
			if (verifica == -1)
				return -1;

			else if (verifica == 0)
				cout << "\n\n Telefone inválido";

			else if (verifica == 1)
				cidadao.adicionarTelefone(telefone);

			//Caso isso ocorra o usuário não deseja cadastrar telefone agora.
			else
				break;
		
		} while (verifica == 0);

		if (verifica == 2)
			break;
	
	} while (pergunta() == 'S');

	//************************************************************

	//****************************** Recebe o email da pessoa ******************************

	//Fica no loop até o usuário digitar 'N', ou pular o cadastro do email.
	do{

		//Se o usuário não quiser cadastar agora, passa uma string vazia e o loop para.
		int verifica;

		do{

			verifica = entradaEValidaçãoDoEmail(cidadao, email);

			//Usuário deseja sair.
			if (verifica == -1)
				return -1;

			else if (verifica == 0)
				cout << "\n\n Email inválido";

			else if (verifica == 1)
				cidadao.adicionarEmail(email);

			//Caso isso ocorra o usuário não deseja cadastrar telefone agora.
			else
				break;
		
		} while (verifica == 0);

		if (verifica == 2)
			break;
	
	} while (pergunta() == 'S');

	//************************************************************

	//****************************** Recebe a tarefa da pessoa ******************************

	//Fica no loop até o usuário digitar 'N', ou pular o cadastro do email.
	do{

		//Se o usuário não quiser cadastar agora, passa uma string vazia e o loop para.
		int verifica;

		do{

			verifica = entradaEValidaçãoDaTarefa(cidadao, tarefa);

			//Usuário deseja sair.
			if (verifica == -1)
				return -1;

			else if (verifica == 0)
				cout << "\n\n Tarefa inválida";

			else if (verifica == 1)
				cidadao.adicionarTarefa(tarefa);

			//Caso isso ocorra o usuário não deseja cadastrar telefone agora.
			else
				break;
	
		
		} while (verifica == 0);
	
		if (verifica == 2)
			break;

	} while (pergunta() == 'S');

	cidadao.setCodigo(id);
	cidadao.setNome(nomeDaPessoa);
	cidadao.setDataAniversario(dataDeAniversario);

	agenda.push_back(cidadao);

	return 1;
}

//Adiciona um novo telefone. Deve ser passado o id da pessoa.
int adicionaTelefone(vector<Pessoa>&agenda){

	int testa;
	Telefone telefone;
	string nome;

	cout << "\n\n******************* Adicionando um novo telefone *******************\n";
	
	do{

		testa = entradaNome(nome);

		if (nome == "-1")
			return -1;

		testa = verificaNome(agenda, nome);

		if (testa == -1)
			cout << "\n\n nome inválido\n";


	} while (testa == -1);

	//Exibe os dados da pessoa.
	exibeIdentificacao(testa, agenda);

	//Exibe os dados da pessoa na tela.
	exibeTelefones(testa, agenda);

	//Lê o novo telefone.
	int teste;

	do{

		teste = entradaEValidaçãoDoTelefone(agenda.at(testa), telefone);

		if (teste == -1 || teste == 2)
			return -1;

		if (teste == 0)
			cout << "\n\n Telefone inválido\n\n";
	
	} while (teste == 0);
	

	//Adiciona o novo telefone.
	agenda.at(testa).adicionarTelefone(telefone);

	//Exibe os dados da pessoa.
	exibeIdentificacao(testa, agenda);

	//Exibe os dados da pessoa na tela.
	exibeTelefones(testa, agenda);

	return 1;

}//adicionaTelefone()


//Adiciona um novo Email. Deve ser passado o id da pessoa.
int adicionaEmail(vector<Pessoa>&agenda){

	int testa;
	Email email;
	string nome;

	cout << "\n\n******************* Adicionando um novo Email *******************\n";
	do{

		testa = entradaNome(nome);

		if (nome == "-1")
			return -1;

		testa = verificaNome(agenda, nome);

		if (testa == -1)
			cout << "\n\n nome inválido\n";


	} while (testa == -1);

	//Exibe os dados da pessoa.
	exibeIdentificacao(testa, agenda);

	//Exibe os dados da pessoa na tela.
	exibeEmails(testa, agenda);

	//Lê o novo telefone.
	int teste;

	do{

		teste = entradaEValidaçãoDoEmail(agenda.at(testa), email);

		if (teste == -1 || teste == 2)
			return -1;

		if (teste == 0)
			cout << "\n\n email inválido\n\n";

	} while (teste == 0);

	//Adiciona o novo telefone.
	agenda.at(testa).adicionarEmail(email);

	//Exibe os dados da pessoa.
	exibeIdentificacao(testa, agenda);

	//Exibe os dados da pessoa na tela.
	exibeEmails(testa, agenda);

	return 1;

}//adicionaEmail()


//Adiciona uma nova tarefa. Deve ser passado o id da pessoa.
int adicionaTarefa(vector<Pessoa>&agenda){

	int testa;
	Tarefa tarefa;
	string nome;

	cout << "\n\n******************* Adicionando uma nova Tarefa *******************\n";

	do{

		testa = entradaNome(nome);

		if (nome == "-1")
			return -1;

		testa = verificaNome(agenda, nome);

		if (testa == -1)
			cout << "\n\n nome inválido\n";


	} while (testa == -1);

	//Exibe os dados da pessoa.
	exibeIdentificacao(testa, agenda);

	//Exibe os dados da pessoa na tela.
	exibeTarefas(testa, agenda);

	//Lê o novo telefone.
	int teste;

	do{

		teste = entradaEValidaçãoDaTarefa(agenda.at(testa), tarefa);

		if (teste == -1 || teste == 2)
			return -1;

		if (teste == 0)
			cout << "\n\n Tarefa inválido\n\n";

	} while (teste == 0);

	//Adiciona o novo telefone.
	agenda.at(testa).adicionarTarefa(tarefa);

	//Exibe os dados da pessoa.
	exibeIdentificacao(testa, agenda);

	//Exibe os dados da pessoa na tela.
	exibeTarefas(testa, agenda);

	return 1;

}