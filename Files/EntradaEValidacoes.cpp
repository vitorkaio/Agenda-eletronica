#include "EntradaEValidacoes.h"

//Recebe o id do usuário, retorna o id em caso de sucesso, -1 caso de cancelamento e 0 caso de erro.
int entradaId(){

	string codigo;
	int id, testa;

	cout << "\n\n\n******************* Id *******************\n\n";

	do{
		do {
			cout << "Forneça o id: ";
			cin >> codigo;
			cin.ignore();

			if (codigo == "-1")
				return -1;

			//Verificando se é um número.
			testa = verificaLetra(codigo);

		} while (testa == 1);

		id = atoi(codigo.c_str());
	
	} while (id == 0);

	//Se id for igual a zero não foi possivel converter. Se o id é negativo não aceita, por isso retorna 0.
	if (id == 0 || id < -1)
		return 0;

	//Se o número foi digitado corretamente.
	else
		return id;


	return id;

}//entradaId()


//Verifica se o id já existe, se sim retorna a posição, caso contrário retorna -1.
int verificaId(vector<Pessoa>&agenda, int &id){

	for (size_t cont = 0; cont < agenda.size(); cont++){

		if (id == agenda.at(cont).getCodigo()){

			return cont;

		}		

	}

	return -1;

}//verificaId()


//Recebe o nome do usuário, retorna 1 em caso de sucesso, -1 caso de cancelamento e 0 caso de erro.
int entradaNome(string &nome){

	cout << "\n\n******************* Nome *******************\n";

	//Não pode ter nome vazio.
	do{

		cout << "\n Nome: ";
		getline(cin, nome);

		//Se o nome for igual a -1, o usuário deseja cancelar a operação, por isso retorna -1.
		if (nome == "-1")
			return -1;
	
	} while (nome.length() == 0);
	
	return 1;

}//entradaNome()


//Verifica se o nome já existe, se sim retorna a posição, caso contrário o retorna 0.
int verificaNome(vector<Pessoa>&agenda, const string nome){

	const char *nome1 = nome.c_str();

	for (size_t contador = 0; contador < agenda.size(); contador++){

		string nome2 = agenda.at(contador).getNome();
		const char *temp = nome2.c_str();

		if (!_stricmp(nome1, temp))
			return contador;


	}

	return -1;

}//verificaNome()


//Recebe a data de aniversário da pessoa, retorna 1 caso de sucesso e 0 caso contrário e -1 para cancelar.
int entradaDataDeAniversario(string &data){

	string dat, diaAux, mesAux, anoAux;
	int d, m, a, testa;

	cout << "\n\n******************* Data de Aniversário *******************\n";

	do{

		cout << "\n Data(DD/MM/AAAA): ";
		getline(cin, dat);
	
	} while (dat.length() == 0);

	//Usuário deseja cancelar a operação.
	if (dat == "-1")
		return -1;

	//Verificando se a data está no formato DD/MM/AAAA.

	//Verificando se há 10 digitos. 
	if (dat.length() < 10)
		return 0;

	//O terceiro e sexto elemento da string tem que ser uma / (barra). Se houver alguma alteração nessa ordem, a data é inválida.
	if (dat[2] != '/' || dat[5] != '/')
		return 0;

	/*É verificado se existe quatro elementos depois da segunda / (barra). Para isso basta subtrair o tamanho da string
	pela posição da segunda barra que é 5.*/
	if (dat.size() - 6 != 4)
		return 0;

	//Essa variável salva a data, pois serão feitas operações no formato da data.
	string salva = dat;

	/*Pegando os dois primeiros caracteres da string, pois eles serão convertidos para inteiros e verificado se são dias
	válidos. */
	diaAux = diaAux + dat[0] + dat[1];

	//Verificando se tem letra no meio.
	testa = verificaLetra(diaAux);

	if (testa == 1)
		return 0;

	//O mesmo que o de cima, só que para os meses.
	mesAux = mesAux + dat[3] + dat[4];

	//Verificando se tem letra no meio.
	testa = verificaLetra(mesAux);

	if (testa == 1)
		return 0;

	//Para os anos.
	anoAux = anoAux + dat[6] + dat[7] + dat[8] + dat[9];

	//Verificando se tem letra no meio.
	testa = verificaLetra(anoAux);

	if (testa == 1)
		return 0;

	//Convertendo os dígitos em inteiros, para verificar se os números são válidos.
	d = atoi(diaAux.c_str());
	m = atoi(mesAux.c_str());
	a = atoi(anoAux.c_str());

	//Validando a data.
	testa = validaData(d, m, a);

	if (testa == 0)
		return 0;

	//data recebe a data validada e formadata.
	data = diaAux + "/" + mesAux + "/" + anoAux;

	return 1;

}//entradaDataDeAniversario()


//Valida a data.
int validaData(int dia, int mes, int ano){


	if ((dia >= 1 && dia <= 31) && (mes >= 1 && mes <= 12) && (ano >= 1900 && ano <= 2100)) //verifica se os numeros sao validos
	{
		if ((dia == 29 && mes == 2) && ((ano % 4) == 0)) //verifica se o ano e bissexto
		{
			return 1;
		}
		if (dia <= 28 && mes == 2) //verifica o mes de feveireiro
		{
			return 1;
		}
		if ((dia <= 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11)) //verifica os meses de 30 dias
		{
			return 1;
		}
		if ((dia <= 31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)) //verifica os meses de 31 dias
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}

}//validaData()


//Recebe e valida o telefone da pessoa. Retorna 1 em caso de sucesso, 0 caso contrário e -1 para cancelar.
int entradaEValidaçãoDoTelefone(Pessoa cidadao, Telefone &telefone){

	string phone, aux;
	string uso, tipo;

	cout << "\n\n******************* Telefone *******************\n";

	//(99) 9999-99999
	cout << "\nForneça o telefone [(99)9999-99999]: ";
	getline(cin, phone);

	//verificando se o usuário deseja pular o cadastro.
	if (phone.length() == 0)
		return 2;

	//Verificando se quer cancelar.
	if (phone == "-1")
		return -1;

	//Verificando se o telefone tem (99)9999-9999 - 10 números.
	if (phone.length() != 10)
		return 0;

	int teste = verificaLetra(phone);

	if (teste == 1)
		return 0;

	//Colando () nas posições 0 e 3, - na posição 8.

	aux = aux + '(' + phone[0] + phone[1];
	aux = aux + ')' + phone[2] + phone[3] + phone[4] + phone[5];
	aux = aux + '-' + phone[6] + phone[7] + phone[8] + phone[9];

	//Verificando se este número é repetido.

	teste = cidadao.pesquisarTelefone(aux);

	//Se teste for diferente de -1 quer dizer que esse telefone já está cadastrado.
	if (teste != -1)
		return 0;

	//Lê e valida o uso, se o uso for diferente de um dos padrões, fica preso no loop.
	do{
		int tamanho;
		do {
			cout << "\n Pessoal ('P') ou Trabalho ('T'): ";
			getline(cin, uso);
			tamanho = verificaLetraECaractere(uso);

			if (tamanho == 0)
				break;
			else
				cout << "\n Entrada incorreta!";
		} while (tamanho == 1);
		
		uso = toupper(uso[0]);

		//Verifica se o usuário deseja sair do cadastro.
		if (uso == "-1")
			return -1;

		//Verifica se tipo é igual à um dos tipos definidos. Se sim teste recebe 0 e sai do loop.
		if ((uso == "P") || (uso == "T"))
			teste = 0;

		else{
			cout << "\n Uso indefinido";
			teste = 1;
		}

	} while (teste == 1);

	//Lê e valida o tipo, se o tipo for diferente de um dos padrões, fica preso no loop.
	do{
		int tamanho;
		do {
			cout << "\n Móvel ('M'), Fixo ('F') ou Fax ('A'): ";
			getline(cin, tipo);
			tamanho = verificaLetraECaractere(tipo);

			if (tamanho == 0)
				break;
			else
				cout << "\n Entrada incorreta!";
		} while (tamanho == 1);

		tipo = toupper(tipo[0]);

		//Verifica se o usuário deseja sair do cadastro.
		if (tipo == "-1")
			return -1;

		//Verifica se tipo é igual à um dos tipos definidos. Se sim teste recebe 0 e sai do loop.
		if ((tipo == "F") || (tipo == "M") || (tipo == "A"))
			teste = 0;

		else{

			cout << "\n Tipo indefinido";
			teste = 1;
		}


	} while (teste == 1);

	telefone.setNumero(aux);
	telefone.setUso(uso[0]);
	telefone.setTipo(tipo[0]);

	return 1;

}//entradaEValidaçãoDoTelefone()


//Recebe e valida o email da pessoa. Retorna 1 em caso de sucesso, 0 caso contrário, -1 para cancelar e 2 se quiser pular.
int entradaEValidaçãoDoEmail(Pessoa cidadao, Email &mail){

	string email;
	string uso;

	cout << "\n\n******************* Email *******************\n";

	cout << "\n Forneça o email: ";
	getline(cin, email);

	//verificando se o usuário deseja pular o cadastro.
	if (email.length() == 0)
		return 2;

	if (email == "-1")
		return -1;

	//contador será utilizada para pegar cada caractere da estring;
	size_t contador, contador2;
	char caractere;

	//Para verifica quantos @ existem;
	int quantidade = 0;

	/*Basicamente um email deve possuir as seguintes opções em seu campo.

	Não possuir espaços;
	Possuir o @;
	Possuir algum caracter após o @;
	Possuir algum caracter antes do @;
	Possuir pelo menos um ponto após o caracter depois do @;
	Possuir algum caracter após o ponto.
	Exemplos de email válido: vitor@C++.com */


	for (contador = 0; contador < email.length(); contador++){

		//Verificando se existe o @ na string, se não houver, é um email inválido.
		caractere = email.at(contador);

		if (caractere == '@')
			quantidade++;

	}

	//Se não houver um @ ou houver mais de 1, email é inválido.
	if (quantidade == 0 || quantidade > 1)
		return 0;

	//Verificando se existe espaços em branco.
	for (contador = 0; contador < email.length(); contador++){

		//Verificando se existe o espaço na string, se houver, é um email inválido.
		caractere = email.at(contador);

		if (caractere == ' ')
			return 0;

	}


	for (contador = 0; contador < email.length(); contador++){

		//Verificando onde está o @.
		caractere = email.at(contador);

		if (caractere == '@')
			break;

	}

	//Quer dizer que @ está na última posição.
	if (contador == email.length())
		return 0;

	//Se depois do @ houver espaço vazio ou ponto está errado.
	if (email[contador + 1] == ' ' || email[contador + 1] == '.')
		return 0;

	//Quer dizer que o @ está no inicio.
	if (contador == 0)
		return 0;

	quantidade = 0;

	//Procurando o .
	for (contador2 = contador; contador2 < email.length(); contador2++){

		char caractere = email[contador2];

		if (caractere == '.')
			quantidade++;

	}

	//Se for verdadeiro, não existe ponto.
	if (quantidade == 0)
		return 0;


	//Procurando o .
	for (contador2 = contador; contador2 < email.length(); contador2++){

		char caractere = email[contador2];

		if (caractere == '.')
			break;

	}

	//verificando se o que tem atrá do . é o @
	if (email[contador2 - 1] == '@')
		return 0;

	//verificado se é o último.
	if (contador2 == email.length())
		return 0;

	//Verificando se já existe esse email.
	int teste;

	teste = cidadao.pesquisarEmail(email);

	if (teste != -1)
		return 0;



	/**/
	//Lê e valida o uso, se o uso for diferente de um dos padrões, fica preso no loop.
	do{
		int tamanho;
		do {
			cout << "\n Pessoal ('P') ou Trabalho ('T'): ";
			getline(cin, uso);

			tamanho = verificaLetraECaractere(uso);

			if (tamanho == 0)
				break;
			else
				cout << "\n Entrada incorreta!";
		} while (tamanho == 1);

		uso = toupper(uso[0]);

		//Verifica se o usuário deseja sair do cadastro.
		if (uso == "-1")
			return -1;

		//Verifica se tipo é igual à um dos tipos definidos. Se sim teste recebe 0 e sai do loop.
		if ((uso == "P") || (uso == "T"))
			teste = 0;

		else{

			cout << "\n Uso indefinido";
			teste = 1;
		}

	} while (teste == 1);

	mail.setEmail(email);
	mail.setUso(uso[0]);

	return 1;

}//entradaEValidaçãoDoEmail()


//Recebe e valida a tarefa da pessoa. Retorna 1 em caso de sucesso, 0 caso contrário, -1 para cancelar e 2 se quiser pular.
int entradaEValidaçãoDaTarefa(Pessoa cidadao, Tarefa &tarefa){

	string texto;
	int id;

	cout << "\n\n******************* Tarefa *******************\n";

	//Gerando o id aleatoriamente.
	srand((unsigned)time(NULL));

	int teste;

	do{

		//Gera um id de 1 a 10000.
		id = 1 + (rand() % 10000);

		//Verificando se já existe o id.
		teste = 1;

		for (int contador = 0; contador < cidadao.quantidadeDeTarefas(); contador++){

			

			Tarefa *taf = cidadao.obterTarefa(contador);
			int codigo = taf->getCodigo();

			if (id == codigo){

				teste = 0;
				break;

			}

		}
	
	} while (teste == 0);


	cout << "\n Descrição da tarefa: ";
	getline(cin, texto);

	//Verificando se o usuário quer pular a tarefa.
	if (texto.length() == 0)
		return 2;

	//Verificando se o usuário quer cancelar a operação.
	if (texto == "-1")
		return -1;

	//Verificando se já existe esta tarefa.
	teste = cidadao.pesquisarTarefa(texto);

	if (teste != -1)
		return 0;



	//********************************************* Data da Tarefa *********************************************
    
	string dat, diaAux, mesAux, anoAux;
	int d, m, a, testa;

	//Fica no loop enquanto não digitar a data certa.
	do{

		//Limpando as strings.
		dat.clear();
		diaAux.clear();
		mesAux.clear();
		anoAux.clear();

		do{

			cout << "\n Data(DD/MM/AAAA): ";
			getline(cin, dat);

			//Usuário deseja cancelar a operação.
			if (dat == "-1")
				return -1;

			//Verificando se a data está no formato DD/MM/AAAA.

			//Verificando se há 10 digitos. 
			if (dat.length() < 10){

				testa = 0;
				break;

			}

			//O terceiro e sexto elemento da string tem que ser uma / (barra). Se houver alguma alteração nessa ordem, a data é inválida.
			if (dat[2] != '/' || dat[5] != '/'){

				testa = 0;
				break;

			}

			/*É verificado se existe quatro elementos depois da segunda / (barra). Para isso basta subtrair o tamanho da string
			pela posição da segunda barra que é 5.*/
			if (dat.size() - 6 != 4){

				testa = 0;
				break;

			}

			//Essa variável salva a data, pois serão feitas operações no formato da data.
			string salva = dat;

			/*Pegando os dois primeiros caracteres da string, pois eles serão convertidos para inteiros e verificado se são dias.
			válidos. */
			diaAux = diaAux + dat[0] + dat[1];
			
			//Verificando se tem letra no meio.
			testa = verificaLetra(diaAux);

			if (testa == 1){

				testa = 0;
				break;

			}

			//O mesmo que o de cima, só que para os meses.
			mesAux = mesAux + dat[3] + dat[4];

			//Verificando se tem letra no meio.
			testa = verificaLetra(mesAux);

			if (testa == 1){

				testa = 0;
				break;

			}

			//Para os anos.
			anoAux = anoAux + dat[6] + dat[7] + dat[8] + dat[9];

			//Verificando se tem letra no meio.
			testa = verificaLetra(anoAux);

			if (testa == 1){

				testa = 0;
				break;

			}

			//Convertendo os dígitos em inteiros, para verificar se os números são válidos.
			d = atoi(diaAux.c_str());
			m = atoi(mesAux.c_str());
			a = atoi(anoAux.c_str());

			//Validando a data.
			testa = validaData(d, m, a);

			if (testa == 0){

				testa = 0;
				break;

			}

			testa = 1;

		} while (dat.length() == 0);

		if (testa == 0)
			cout << "\n\n Data inválida\n\n";
	
	
	} while (testa == 0);

	

	//********************************************* Hora da tarefa *********************************************

	string horario, hh, mm;
	int h, mi, s;

	//Fica no loop enquanto não digitar a data certa.
	do{

		horario.clear();
		hh.clear();
		mm.clear();

		do{

			cout << "\n Horário(HH:MM): ";
			getline(cin, horario);

			//Verificando se o usuário quer cancelar a operação.
			if (horario == "-1")
				return -1;

			//verificando o formato HH:MM

			//Verificando se o : está na posição 2.
			if (horario[2] != ':'){

				testa = 0;
				break;

			}

			//verificando se existe 2 números depois do :
			if (horario.size() - 3 != 2){

				testa = 0;
				break;

			}

			//verificando se as horas são numeros e não letras.
			hh = hh + horario[0] + horario[1];

			testa = verificaLetra(hh);

			if (testa == 1){

				testa = 0;
				break;

			}

			mm = mm + horario[3] + horario[4];

			testa = verificaLetra(mm);

			if (testa == 1){

				testa = 0;
				break;

			}

			//Convertendo para inteiro e verificando se são número válidos.
			h = atoi(hh.c_str());
			mi = atoi(mm.c_str());
			s = 5;

			testa = validaHoras(h, mi, s);

			if (testa == 0){

				testa = 0;
				break;

			}

			testa = 1;

		} while (horario.length() == 0);

		if (testa == 0)
			cout << "\n\n Horário inválido\n\n";
	
	} while (testa == 0);


	//********************************************* Preenchendo a struct tm *********************************************
   
	time_t rawtime;
	tm tempo;

	time(&rawtime);

	localtime_s(&tempo, &rawtime);

	tempo.tm_year = a - 1900;
	tempo.tm_mon = m - 1;
	tempo.tm_mday = d;
	tempo.tm_hour = h;
	tempo.tm_min = mi;
	tempo.tm_sec = s;

	//Converte o tempo local em uma struct tm.
	mktime(&tempo);

	tarefa.setCodigo(id);
	tarefa.setTarefa(texto);
	tarefa.setTempo(tempo);

	return 1;
}


//Valida as horas. Retorna 1 em caso de sucesso e 0 caso contrário.
int validaHoras(int horas, int minutos, int segundos){

	if ((horas < 0 || horas > 23) || (minutos < 0 || minutos > 59) || (segundos < 0 || segundos > 59))
		return 0;

	return 1;


}//validaHoras()


//Pesquisa a tarefa de acordo com a data. Retorna a posição caso exista, caso contrário retorna -1.
int pesquisaTarefaData(Pessoa individuo, int dia, int mes, int ano){

	Tarefa *tarefa;
	tm tempo;

	for (int contador = 0; contador < individuo.quantidadeDeTarefas(); contador++){

		//tarefa recebe uma refência do objeto que está no vector.
		tarefa = individuo.obterTarefa(contador);

		//tempo recebe a struct tm do vector.
		tempo = tarefa->getTempo();

		//Verificando se a data passada é igual a data de alguma tarefa. Se for, retorna a posição da tarefa.
		if (tempo.tm_year + 1900 == ano && tempo.tm_mon + 1 == mes && tempo.tm_mday == dia)
			return contador;


	}

	return -1;

}


//Lê uma data.
int lendoUmaData(int &dia, int &mes, int &ano){

	//********************************************* Data da Tarefa *********************************************

	string dat, diaAux, mesAux, anoAux;
	int d, m, a, testa;

	//Fica no loop enquanto não digitar a data certa.
	do{

		//Limpando as strings.
		dat.clear();
		diaAux.clear();
		mesAux.clear();
		anoAux.clear();

		do{

			cout << "\n\n Data(DD/MM/AAAA): ";
			getline(cin, dat);

			//Usuário deseja cancelar a operação.
			if (dat == "-1")
				return -1;

			//Verificando se a data está no formato DD/MM/AAAA.

			//Verificando se há 10 digitos. 
			if (dat.length() < 10){

				testa = 0;
				break;

			}

			//O terceiro e sexto elemento da string tem que ser uma / (barra). Se houver alguma alteração nessa ordem, a data é inválida.
			if (dat[2] != '/' || dat[5] != '/'){

				testa = 0;
				break;

			}

			/*É verificado se existe quatro elementos depois da segunda / (barra). Para isso basta subtrair o tamanho da string
			pela posição da segunda barra que é 5.*/
			if (dat.size() - 6 != 4){

				testa = 0;
				break;

			}

			//Essa variável salva a data, pois serão feitas operações no formato da data.
			string salva = dat;

			/*Pegando os dois primeiros caracteres da string, pois eles serão convertidos para inteiros e verificado se são dias.
			válidos. */
			diaAux = diaAux + dat[0] + dat[1];

			//Verificando se tem letra no meio.
			testa = verificaLetra(diaAux);

			if (testa == 1){

				testa = 0;
				break;

			}

			//O mesmo que o de cima, só que para os meses.
			mesAux = mesAux + dat[3] + dat[4];

			//Verificando se tem letra no meio.
			testa = verificaLetra(mesAux);

			if (testa == 1){

				testa = 0;
				break;

			}

			//Para os anos.
			anoAux = anoAux + dat[6] + dat[7] + dat[8] + dat[9];

			//Verificando se tem letra no meio.
			testa = verificaLetra(anoAux);

			if (testa == 1){

				testa = 0;
				break;

			}

			//Convertendo os dígitos em inteiros, para verificar se os números são válidos.
			d = atoi(diaAux.c_str());
			m = atoi(mesAux.c_str());
			a = atoi(anoAux.c_str());

			//Validando a data.
			testa = validaData(d, m, a);

			if (testa == 0){

				testa = 0;
				break;

			}

			testa = 1;

		} while (dat.length() == 0);

		if (testa == 0)
			cout << "\n\n Data inválida\n\n";


	} while (testa == 0);

	//************************************************************

	dia = d;
	mes = m;
	ano = a;

	return 1;

}