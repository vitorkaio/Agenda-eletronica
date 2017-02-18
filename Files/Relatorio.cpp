#include "Relatorio.h"


//Exibe os dados de todas as pessoas da agenda.
void exibeAgenda(vector<Pessoa>&agenda){

	//Array com os dias da semana.
	string diaDaSemana[] = { "Domingo", "Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sábado" };

	Telefone *telefone;
	Email *email;
	Tarefa *tarefa;

	for (size_t posicao = 0; posicao < agenda.size(); posicao++){

		/*Os blocos abaixo retornam as informações de um objeto pessoa, de acador com sua posição.
		Para conseguir a posição basta passar o id na função pesquisaCodigo(), ela retorna a posição.*/
		cout << "\n\n******************* Pessoa *******************\n";

		cout << "\n Nome: " << agenda.at(posicao).getNome()
			<< "\n id: " << agenda.at(posicao).getCodigo()
			<< "\n Data de Aniversáio: " << agenda.at(posicao).getDataAniversario();

		cout << "\n\n******************* Telefones *******************";

		for (int contador = 0; contador < agenda.at(posicao).quantidadeDeTelefones(); contador++){

			telefone = agenda.at(posicao).obterTelefone(contador);

			cout << "\n Número: " << telefone->getNumero()
				<< "\n Tipo: " << telefone->getTipo()
				<< "\n Uso: " << telefone->getUso();

		}

		cout << "\n\n******************* Emails *******************";

		for (int contador = 0; contador < agenda.at(posicao).quantidadeDeEmails(); contador++){

			email = agenda.at(posicao).obterEmail(contador);

			cout << "\n Email: " << email->getEmail()
				<< "\n Uso: " << email->getUso();

		}

		cout << "\n\n******************* Tarefas *******************";

		for (int contador = 0; contador < agenda.at(posicao).quantidadeDeTarefas(); contador++){

			tarefa = agenda.at(posicao).obterTarefa(contador);

			tm tempo = tarefa->getTempo();

			cout << "\n  " << diaDaSemana[tempo.tm_wday]
				<< ", " << tempo.tm_mday
				<< "/ " << tempo.tm_mon + 1
				<< "/ " << tempo.tm_year + 1900
				<< "  ás " << tempo.tm_hour
				<< ":" << tempo.tm_min
				<< " - " << tarefa->getTarefa();

		}

		printf("\n\n");
	}

	

}

//Exibe os dados de uma pessoa.
void exibePessoa(int posicao, vector<Pessoa>&agenda){

	//Array com os dias da semana.
	string diaDaSemana[] = { "Domingo", "Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sábado" };

	Telefone *telefone;
	Email *email;
	Tarefa *tarefa;

	/*Os blocos abaixo retornam as informações de um objeto pessoa, de acador com sua posição.
	  Para conseguir a posição basta passar o id na função pesquisaCodigo(), ela retorna a posição.*/
	cout << "\n\n******************* Pessoa *******************\n";

	cout << "\n Nome: " << agenda.at(posicao).getNome()
		<< "\n id: " << agenda.at(posicao).getCodigo()
		<< "\n Data de Aniversáio: " << agenda.at(posicao).getDataAniversario();

	cout << "\n\n******************* Telefones *******************";

	for (int contador = 0; contador < agenda.at(posicao).quantidadeDeTelefones(); contador++){

		telefone = agenda.at(posicao).obterTelefone(contador);

		cout << "\n Número: " << telefone->getNumero()
			<< "\n Tipo: " << telefone->getTipo()
			<< "\n Uso: " << telefone->getUso();

	}

	cout << "\n\n******************* Emails *******************";

	for (int contador = 0; contador < agenda.at(posicao).quantidadeDeEmails(); contador++){

		email = agenda.at(posicao).obterEmail(contador);

		cout << "\n Email: " << email->getEmail()
			<< "\n Uso: " << email->getUso();

	}

	cout << "\n\n******************* Tarefas *******************";

	for (int contador = 0; contador < agenda.at(posicao).quantidadeDeTarefas(); contador++){

		tarefa = agenda.at(posicao).obterTarefa(contador);

		tm tempo = tarefa->getTempo();

		cout << "\n  " << diaDaSemana[tempo.tm_wday]
			<< ", " << tempo.tm_mday
			<< "/ " << tempo.tm_mon + 1
			<< "/ " << tempo.tm_year + 1900
			<< "  ás " << tempo.tm_hour
			<< ":" << tempo.tm_min
			<< " - " << tarefa->getTarefa();

	}


}//exibePessoa()


//Exibe o nome, id e data de nascimento.
void exibeIdentificacao(int posicao, vector<Pessoa>&agenda){

	string nome, data;
	int id;

	nome = agenda.at(posicao).getNome();
	id = agenda.at(posicao).getCodigo();
	data = agenda.at(posicao).getDataAniversario();

	cout << "\n\n******************* Pessoa *******************\n";

	cout << "\n\n Nome: " << nome
		<< "\n id: " << id
		<< "\n Data de Nascimento: " << data << endl;

}//exibeIdentificacao()


//Exibe o nome, id, data de nascimento e os telefones da pessoa.
void exibeTelefones(int posicao, vector<Pessoa>&agenda){

	Telefone *telefone;

	//Percorre por todos os telefones da pessoa e imprime todos.
	cout << "\n\n******************* Telefones *******************";

	for (int contador = 0; contador < agenda.at(posicao).quantidadeDeTelefones(); contador++){

		telefone = agenda.at(posicao).obterTelefone(contador);

		cout << "\n Número: " << telefone->getNumero()
			<< "\n Tipo: " << telefone->getTipo()
			<< "\n Uso: " << telefone->getUso();

	}


}//exibeTelefones()


//Exibe o nome, id, data de nascimento e os emails da pessoa.
void exibeEmails(int posicao, vector<Pessoa>&agenda){

	Email *email;

	//Percorre por todos os telefones da pessoa e imprime todos.
	cout << "\n\n******************* Emails *******************";

	for (int contador = 0; contador < agenda.at(posicao).quantidadeDeEmails(); contador++){

		email = agenda.at(posicao).obterEmail(contador);

		cout << "\n Número: " << email->getEmail()
			 << "\n Uso: " << email->getUso();

	}

}//exibeEmails()


//Exibe o nome, id, data de nascimento e os tarefas da pessoa.
void exibeTarefas(int posicao, vector<Pessoa>&agenda){

	//Array com os dias da semana.
	string diaDaSemana[] = { "Domingo", "Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sábado" };

	Tarefa *tarefa;

	cout << "\n\n******************* Tarefas *******************";

	for (int contador = 0; contador < agenda.at(posicao).quantidadeDeTarefas(); contador++){

		tarefa = agenda.at(posicao).obterTarefa(contador);

		tm tempo = tarefa->getTempo();

		cout << "\n  " << diaDaSemana[tempo.tm_wday]
			<< ", " << tempo.tm_mday
			<< "/ " << tempo.tm_mon + 1
			<< "/ " << tempo.tm_year + 1900
			<< "  ás " << tempo.tm_hour
			<< ": " << tempo.tm_min
			<< " - " << tarefa->getTarefa();

	}


}

// Exibe as tarefas de acordo com a data passada.
void exibeTarefaUnica(int posicao, vector<Pessoa>&agenda, int posicaoTarefa){
	//Array com os dias da semana.
	string diaDaSemana[] = { "Domingo", "Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sábado" };
	int dia, mes, ano;
	Tarefa *tarefa;

	cout << "\n\n******************* Tarefas *******************";

	

	tarefa = agenda.at(posicao).obterTarefa(posicaoTarefa);

	tm tempo = tarefa->getTempo();

	cout << "\n  " << diaDaSemana[tempo.tm_wday]
		<< ", " << tempo.tm_mday
		<< "/ " << tempo.tm_mon + 1
		<< "/ " << tempo.tm_year + 1900
		<< "  ás " << tempo.tm_hour
		<< ": " << tempo.tm_min
		<< " - " << tarefa->getTarefa();

	dia = tempo.tm_mday;
	mes = tempo.tm_mon + 1;
	ano = tempo.tm_year + 1900;

	for (int cont = 0; cont < agenda.at(posicao).quantidadeDeTarefas(); cont++) {
		// Verifica se existem datas iguais a anterior. Se sim imprime, se não retorna 0.
		tarefa = agenda.at(posicao).obterTarefa(cont);
		tempo = tarefa->getTempo();
		if (dia == tempo.tm_mday && mes == tempo.tm_mon + 1 && ano == tempo.tm_year + 1900 && posicaoTarefa != cont) {
			cout << "\n  " << diaDaSemana[tempo.tm_wday]
				<< ", " << tempo.tm_mday
				<< "/ " << tempo.tm_mon + 1
				<< "/ " << tempo.tm_year + 1900
				<< "  ás " << tempo.tm_hour
				<< ": " << tempo.tm_min
				<< " - " << tarefa->getTarefa();
		}
	}

}


//Exibe o id, nome e a tarefa da pessoa.
void exibeRelatorio(vector<Pessoa>agenda, int posicaoDaPessoa, int posicaoDaTarefa){

	//Array com os dias da semana.
	string diaDaSemana[] = { "Domingo", "Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sábado" };

	Tarefa *tarefa;
	string nome, dataDeNascimento;
	int id;
	tm tempo;

	nome = agenda.at(posicaoDaPessoa).getNome();
	id = agenda.at(posicaoDaPessoa).getCodigo();
	dataDeNascimento = agenda.at(posicaoDaPessoa).getDataAniversario();

	tarefa = agenda.at(posicaoDaPessoa).obterTarefa(posicaoDaTarefa);

	tempo = tarefa->getTempo();

	cout << "\n\n******************* Tarefa *******************\n";

	cout << "\n Nome: " << nome
		<< "\n id: " << id
		<< "\n Data de Nascimento: " << dataDeNascimento;

	cout << "\n  " << diaDaSemana[tempo.tm_wday]
		<< ", " << tempo.tm_mday
		<< "/ " << tempo.tm_mon + 1
		<< "/ " << tempo.tm_year + 1900
		<< "  ás " << tempo.tm_hour
		<< ": " << tempo.tm_min
		<< " - " << tarefa->getTarefa();


}