#include "Arquivo.h"

//Abre o arquivo para gravação.
int gravaNoArquivo(vector<Pessoa>&agenda){

	//Abre um arquivo para gravar os dados da agenda.
	fstream arq("arquivo.dat", ios::app | ios::out | ios::in | ios::binary);

	if (arq.is_open() && arq.good())
		cout << "\n Aberto com sucesso \n\n";

	else
		cout << "\n Erro \n\n";

	/*Por não conseguir gravar um objeto com vector, criarei arquivos separaddos para cadas pessoa, ou seja,
	  cada pessoa tera um arquivo que com seus telefones.*/
	for (size_t contador = 0; contador < agenda.size(); contador++){

		Pessoa cidadao;

		//Objeto cidadao recebe do vector todos as pessoas da agenda.
		cidadao = agenda.at(contador);
		
		//Loop que percorrer todos os telefones da pessoa, e grava em um arquivo com seu nome.
		for (int cont = 0; cont < cidadao.quantidadeDeTelefones(); cont++){

			//Objeto que recebe todos os telefones da pessoa e repassa-lo para o arquivo.
			Telefone *telefone, tell;

			//Abre um arquivo com o nome da pessoa para gravar seus telefones.
			fstream arquivo(cidadao.getNome() + " - Telefones.dat", ios::app | ios::out | ios::in | ios::binary);

			if (arquivo.is_open() && arquivo.good())
				cout << "\n Aberto com sucesso \n\n";

			else
				cout << "\n Erro \n\n";
			
			telefone = cidadao.obterTelefone(cont);
			tell = *telefone;
			//cidadao.removerTelefone(cont);

			//Grava o telefone no arquivo de telefones da pessoa.
			arquivo.write((char *)&tell, sizeof(Telefone));

			arquivo.close();

		}

		//Loop que percorrer todos os telefones da pessoa, e grava em um arquivo com seu nome.
		for (int cont = 0; cont < cidadao.quantidadeDeEmails(); cont++){

			//Objeto que recebe todos os telefones da pessoa e repassa-lo para o arquivo.
			Email *email, mail;

			//Abre um arquivo com o nome da pessoa para gravar seus telefones.
			fstream arquivo(cidadao.getNome() + " - Emails.dat", ios::app | ios::out | ios::in | ios::binary);

			if (arquivo.is_open() && arquivo.good())
				cout << "\n Aberto com sucesso \n\n";

			else
				cout << "\n Erro \n\n";

			email = cidadao.obterEmail(cont);
			mail = *email;
			//cidadao.removerTelefone(cont);

			//Grava o telefone no arquivo de telefones da pessoa.
			arquivo.write(reinterpret_cast< char * >(&mail), sizeof(Email));

			arquivo.close();

		}

		//Loop que percorrer todos os telefones da pessoa, e grava em um arquivo com seu nome.
		for (int cont = 0; cont < cidadao.quantidadeDeTarefas(); cont++){

			//Objeto que recebe todos os telefones da pessoa e repassa-lo para o arquivo.
			Tarefa *tarefa, taf;

			//Abre um arquivo com o nome da pessoa para gravar seus telefones.
			fstream arquivo(cidadao.getNome() + " - Tarefas.dat", ios::app | ios::out | ios::in | ios::binary);

			if (arquivo.is_open() && arquivo.good())
				cout << "\n Aberto com sucesso \n\n";

			else
				cout << "\n Erro \n\n";

			tarefa = cidadao.obterTarefa(cont);
			taf = *tarefa;
			//cidadao.removerTelefone(cont);

			//Grava o telefone no arquivo de telefones da pessoa.
			arquivo.write(reinterpret_cast< char * >(&taf), sizeof(Tarefa));

			arquivo.close();

		}

		arq.write((char *)&cidadao, sizeof(Pessoa));

	}

	arq.close();

	return 1;

}//gravaNoArquivo()


//Abre o arquivo para leitura.
int lerDoArquivo(vector<Pessoa>&agenda){

	//Abre um arquivo para gravar os dados da agenda.
	fstream arq("arquivo.dat", ios::app | ios::out | ios::in | ios::binary);

	if (arq.is_open() && arq.good())
		cout << "\n Aberto com sucesso \n\n";

	else
		cout << "\n Erro \n\n";

	//Coloca o ponteiro de leitura no inicio do arquivo.
	arq.seekg(0);

	Pessoa cidadao, individuo;

	//Lendo as pessoas do arquivo e inserindo-as no vector.
	while (arq.read((char *)&cidadao, sizeof(Pessoa))){

		string nome = cidadao.getNome();
		string data = cidadao.getDataAniversario();
		int codigo = cidadao.getCodigo();
		individuo.setCodigo(codigo);
		individuo.setNome(nome);
		individuo.setDataAniversario(data);

		//Abre o arquivo de telefones da pessoa.
		fstream arquivo(individuo.getNome() + " - Telefones.dat", ios::app | ios::out | ios::in | ios::binary);

		if (arquivo.is_open() && arquivo.good())
			cout << "\n Aberto com sucesso \n\n";

		else
			cout << "\n Erro \n\n";

		//Coloca o ponteiro de leitura no inicio do arquivo.
		arquivo.seekg(0);

		Telefone telefone, tell;

		//Lendo os telefones do arquivo e inserindo-as no vector.
		while (arquivo.read((char *)&telefone, sizeof(Telefone))){

			tell = telefone;
			individuo.adicionarTelefone(tell);
		
		}

		arquivo.close();

		//Abre o arquivo de Emails da pessoa.
		fstream arquivoEMail(individuo.getNome() + " - Emails.dat", ios::app | ios::out | ios::in | ios::binary);

		if (arquivoEMail.is_open() && arquivoEMail.good())
			cout << "\n Aberto com sucesso \n\n";

		else
			cout << "\n Erro \n\n";

		//Coloca o ponteiro de leitura no inicio do arquivo.
		arquivoEMail.seekg(0);

		Email email, mail;

		//Lendo os telefones do arquivo e inserindo-as no vector.
		while (arquivoEMail.read(reinterpret_cast< char * >(&email), sizeof(Email))){

			mail = email;
			individuo.adicionarEmail(mail);

		}


		arquivoEMail.close();

		//Abre o arquivo de tarefas da pessoa.
		fstream arquivoTarefa(individuo.getNome() + " - Tarefas.dat", ios::app | ios::out | ios::in | ios::binary);

		if (arquivoTarefa.is_open() && arquivoTarefa.good())
			cout << "\n Aberto com sucesso \n\n";

		else
			cout << "\n Erro \n\n";

		//Coloca o ponteiro de leitura no inicio do arquivo.
		arquivoTarefa.seekg(0);

		Tarefa tarefa, taf;

		//Lendo os telefones do arquivo e inserindo-as no vector.
		while (arquivoTarefa.read(reinterpret_cast< char * >(&tarefa), sizeof(Tarefa))){

			taf = tarefa;
			individuo.adicionarTarefa(taf);

		}

		arquivoTarefa.close();
		agenda.push_back(individuo);
		
	}
	
	arq.close();

	return 1;

}