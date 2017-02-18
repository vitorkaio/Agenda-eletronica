#include "EntradaEValidacoes.h"

//Recebe o id do usu�rio, retorna o id em caso de sucesso, -1 caso de cancelamento e 0 caso de erro.
int entradaId(){

	string codigo;
	int id, testa;

	cout << "\n\n\n******************* Id *******************\n\n";

	do{
		do {
			cout << "Forne�a o id: ";
			cin >> codigo;
			cin.ignore();

			if (codigo == "-1")
				return -1;

			//Verificando se � um n�mero.
			testa = verificaLetra(codigo);

		} while (testa == 1);

		id = atoi(codigo.c_str());
	
	} while (id == 0);

	//Se id for igual a zero n�o foi possivel converter. Se o id � negativo n�o aceita, por isso retorna 0.
	if (id == 0 || id < -1)
		return 0;

	//Se o n�mero foi digitado corretamente.
	else
		return id;


	return id;

}//entradaId()


//Verifica se o id j� existe, se sim retorna a posi��o, caso contr�rio retorna -1.
int verificaId(vector<Pessoa>&agenda, int &id){

	for (size_t cont = 0; cont < agenda.size(); cont++){

		if (id == agenda.at(cont).getCodigo()){

			return cont;

		}		

	}

	return -1;

}//verificaId()


//Recebe o nome do usu�rio, retorna 1 em caso de sucesso, -1 caso de cancelamento e 0 caso de erro.
int entradaNome(string &nome){

	cout << "\n\n******************* Nome *******************\n";

	//N�o pode ter nome vazio.
	do{

		cout << "\n Nome: ";
		getline(cin, nome);

		//Se o nome for igual a -1, o usu�rio deseja cancelar a opera��o, por isso retorna -1.
		if (nome == "-1")
			return -1;
	
	} while (nome.length() == 0);
	
	return 1;

}//entradaNome()


//Verifica se o nome j� existe, se sim retorna a posi��o, caso contr�rio o retorna 0.
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


//Recebe a data de anivers�rio da pessoa, retorna 1 caso de sucesso e 0 caso contr�rio e -1 para cancelar.
int entradaDataDeAniversario(string &data){

	string dat, diaAux, mesAux, anoAux;
	int d, m, a, testa;

	cout << "\n\n******************* Data de Anivers�rio *******************\n";

	do{

		cout << "\n Data(DD/MM/AAAA): ";
		getline(cin, dat);
	
	} while (dat.length() == 0);

	//Usu�rio deseja cancelar a opera��o.
	if (dat == "-1")
		return -1;

	//Verificando se a data est� no formato DD/MM/AAAA.

	//Verificando se h� 10 digitos. 
	if (dat.length() < 10)
		return 0;

	//O terceiro e sexto elemento da string tem que ser uma / (barra). Se houver alguma altera��o nessa ordem, a data � inv�lida.
	if (dat[2] != '/' || dat[5] != '/')
		return 0;

	/*� verificado se existe quatro elementos depois da segunda / (barra). Para isso basta subtrair o tamanho da string
	pela posi��o da segunda barra que � 5.*/
	if (dat.size() - 6 != 4)
		return 0;

	//Essa vari�vel salva a data, pois ser�o feitas opera��es no formato da data.
	string salva = dat;

	/*Pegando os dois primeiros caracteres da string, pois eles ser�o convertidos para inteiros e verificado se s�o dias
	v�lidos. */
	diaAux = diaAux + dat[0] + dat[1];

	//Verificando se tem letra no meio.
	testa = verificaLetra(diaAux);

	if (testa == 1)
		return 0;

	//O mesmo que o de cima, s� que para os meses.
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

	//Convertendo os d�gitos em inteiros, para verificar se os n�meros s�o v�lidos.
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


//Recebe e valida o telefone da pessoa. Retorna 1 em caso de sucesso, 0 caso contr�rio e -1 para cancelar.
int entradaEValida��oDoTelefone(Pessoa cidadao, Telefone &telefone){

	string phone, aux;
	string uso, tipo;

	cout << "\n\n******************* Telefone *******************\n";

	//(99) 9999-99999
	cout << "\nForne�a o telefone [(99)9999-99999]: ";
	getline(cin, phone);

	//verificando se o usu�rio deseja pular o cadastro.
	if (phone.length() == 0)
		return 2;

	//Verificando se quer cancelar.
	if (phone == "-1")
		return -1;

	//Verificando se o telefone tem (99)9999-9999 - 10 n�meros.
	if (phone.length() != 10)
		return 0;

	int teste = verificaLetra(phone);

	if (teste == 1)
		return 0;

	//Colando () nas posi��es 0 e 3, - na posi��o 8.

	aux = aux + '(' + phone[0] + phone[1];
	aux = aux + ')' + phone[2] + phone[3] + phone[4] + phone[5];
	aux = aux + '-' + phone[6] + phone[7] + phone[8] + phone[9];

	//Verificando se este n�mero � repetido.

	teste = cidadao.pesquisarTelefone(aux);

	//Se teste for diferente de -1 quer dizer que esse telefone j� est� cadastrado.
	if (teste != -1)
		return 0;

	//L� e valida o uso, se o uso for diferente de um dos padr�es, fica preso no loop.
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

		//Verifica se o usu�rio deseja sair do cadastro.
		if (uso == "-1")
			return -1;

		//Verifica se tipo � igual � um dos tipos definidos. Se sim teste recebe 0 e sai do loop.
		if ((uso == "P") || (uso == "T"))
			teste = 0;

		else{
			cout << "\n Uso indefinido";
			teste = 1;
		}

	} while (teste == 1);

	//L� e valida o tipo, se o tipo for diferente de um dos padr�es, fica preso no loop.
	do{
		int tamanho;
		do {
			cout << "\n M�vel ('M'), Fixo ('F') ou Fax ('A'): ";
			getline(cin, tipo);
			tamanho = verificaLetraECaractere(tipo);

			if (tamanho == 0)
				break;
			else
				cout << "\n Entrada incorreta!";
		} while (tamanho == 1);

		tipo = toupper(tipo[0]);

		//Verifica se o usu�rio deseja sair do cadastro.
		if (tipo == "-1")
			return -1;

		//Verifica se tipo � igual � um dos tipos definidos. Se sim teste recebe 0 e sai do loop.
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

}//entradaEValida��oDoTelefone()


//Recebe e valida o email da pessoa. Retorna 1 em caso de sucesso, 0 caso contr�rio, -1 para cancelar e 2 se quiser pular.
int entradaEValida��oDoEmail(Pessoa cidadao, Email &mail){

	string email;
	string uso;

	cout << "\n\n******************* Email *******************\n";

	cout << "\n Forne�a o email: ";
	getline(cin, email);

	//verificando se o usu�rio deseja pular o cadastro.
	if (email.length() == 0)
		return 2;

	if (email == "-1")
		return -1;

	//contador ser� utilizada para pegar cada caractere da estring;
	size_t contador, contador2;
	char caractere;

	//Para verifica quantos @ existem;
	int quantidade = 0;

	/*Basicamente um email deve possuir as seguintes op��es em seu campo.

	N�o possuir espa�os;
	Possuir o @;
	Possuir algum caracter ap�s o @;
	Possuir algum caracter antes do @;
	Possuir pelo menos um ponto ap�s o caracter depois do @;
	Possuir algum caracter ap�s o ponto.
	Exemplos de email v�lido: vitor@C++.com */


	for (contador = 0; contador < email.length(); contador++){

		//Verificando se existe o @ na string, se n�o houver, � um email inv�lido.
		caractere = email.at(contador);

		if (caractere == '@')
			quantidade++;

	}

	//Se n�o houver um @ ou houver mais de 1, email � inv�lido.
	if (quantidade == 0 || quantidade > 1)
		return 0;

	//Verificando se existe espa�os em branco.
	for (contador = 0; contador < email.length(); contador++){

		//Verificando se existe o espa�o na string, se houver, � um email inv�lido.
		caractere = email.at(contador);

		if (caractere == ' ')
			return 0;

	}


	for (contador = 0; contador < email.length(); contador++){

		//Verificando onde est� o @.
		caractere = email.at(contador);

		if (caractere == '@')
			break;

	}

	//Quer dizer que @ est� na �ltima posi��o.
	if (contador == email.length())
		return 0;

	//Se depois do @ houver espa�o vazio ou ponto est� errado.
	if (email[contador + 1] == ' ' || email[contador + 1] == '.')
		return 0;

	//Quer dizer que o @ est� no inicio.
	if (contador == 0)
		return 0;

	quantidade = 0;

	//Procurando o .
	for (contador2 = contador; contador2 < email.length(); contador2++){

		char caractere = email[contador2];

		if (caractere == '.')
			quantidade++;

	}

	//Se for verdadeiro, n�o existe ponto.
	if (quantidade == 0)
		return 0;


	//Procurando o .
	for (contador2 = contador; contador2 < email.length(); contador2++){

		char caractere = email[contador2];

		if (caractere == '.')
			break;

	}

	//verificando se o que tem atr� do . � o @
	if (email[contador2 - 1] == '@')
		return 0;

	//verificado se � o �ltimo.
	if (contador2 == email.length())
		return 0;

	//Verificando se j� existe esse email.
	int teste;

	teste = cidadao.pesquisarEmail(email);

	if (teste != -1)
		return 0;



	/**/
	//L� e valida o uso, se o uso for diferente de um dos padr�es, fica preso no loop.
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

		//Verifica se o usu�rio deseja sair do cadastro.
		if (uso == "-1")
			return -1;

		//Verifica se tipo � igual � um dos tipos definidos. Se sim teste recebe 0 e sai do loop.
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

}//entradaEValida��oDoEmail()


//Recebe e valida a tarefa da pessoa. Retorna 1 em caso de sucesso, 0 caso contr�rio, -1 para cancelar e 2 se quiser pular.
int entradaEValida��oDaTarefa(Pessoa cidadao, Tarefa &tarefa){

	string texto;
	int id;

	cout << "\n\n******************* Tarefa *******************\n";

	//Gerando o id aleatoriamente.
	srand((unsigned)time(NULL));

	int teste;

	do{

		//Gera um id de 1 a 10000.
		id = 1 + (rand() % 10000);

		//Verificando se j� existe o id.
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


	cout << "\n Descri��o da tarefa: ";
	getline(cin, texto);

	//Verificando se o usu�rio quer pular a tarefa.
	if (texto.length() == 0)
		return 2;

	//Verificando se o usu�rio quer cancelar a opera��o.
	if (texto == "-1")
		return -1;

	//Verificando se j� existe esta tarefa.
	teste = cidadao.pesquisarTarefa(texto);

	if (teste != -1)
		return 0;



	//********************************************* Data da Tarefa *********************************************
    
	string dat, diaAux, mesAux, anoAux;
	int d, m, a, testa;

	//Fica no loop enquanto n�o digitar a data certa.
	do{

		//Limpando as strings.
		dat.clear();
		diaAux.clear();
		mesAux.clear();
		anoAux.clear();

		do{

			cout << "\n Data(DD/MM/AAAA): ";
			getline(cin, dat);

			//Usu�rio deseja cancelar a opera��o.
			if (dat == "-1")
				return -1;

			//Verificando se a data est� no formato DD/MM/AAAA.

			//Verificando se h� 10 digitos. 
			if (dat.length() < 10){

				testa = 0;
				break;

			}

			//O terceiro e sexto elemento da string tem que ser uma / (barra). Se houver alguma altera��o nessa ordem, a data � inv�lida.
			if (dat[2] != '/' || dat[5] != '/'){

				testa = 0;
				break;

			}

			/*� verificado se existe quatro elementos depois da segunda / (barra). Para isso basta subtrair o tamanho da string
			pela posi��o da segunda barra que � 5.*/
			if (dat.size() - 6 != 4){

				testa = 0;
				break;

			}

			//Essa vari�vel salva a data, pois ser�o feitas opera��es no formato da data.
			string salva = dat;

			/*Pegando os dois primeiros caracteres da string, pois eles ser�o convertidos para inteiros e verificado se s�o dias.
			v�lidos. */
			diaAux = diaAux + dat[0] + dat[1];
			
			//Verificando se tem letra no meio.
			testa = verificaLetra(diaAux);

			if (testa == 1){

				testa = 0;
				break;

			}

			//O mesmo que o de cima, s� que para os meses.
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

			//Convertendo os d�gitos em inteiros, para verificar se os n�meros s�o v�lidos.
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
			cout << "\n\n Data inv�lida\n\n";
	
	
	} while (testa == 0);

	

	//********************************************* Hora da tarefa *********************************************

	string horario, hh, mm;
	int h, mi, s;

	//Fica no loop enquanto n�o digitar a data certa.
	do{

		horario.clear();
		hh.clear();
		mm.clear();

		do{

			cout << "\n Hor�rio(HH:MM): ";
			getline(cin, horario);

			//Verificando se o usu�rio quer cancelar a opera��o.
			if (horario == "-1")
				return -1;

			//verificando o formato HH:MM

			//Verificando se o : est� na posi��o 2.
			if (horario[2] != ':'){

				testa = 0;
				break;

			}

			//verificando se existe 2 n�meros depois do :
			if (horario.size() - 3 != 2){

				testa = 0;
				break;

			}

			//verificando se as horas s�o numeros e n�o letras.
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

			//Convertendo para inteiro e verificando se s�o n�mero v�lidos.
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
			cout << "\n\n Hor�rio inv�lido\n\n";
	
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


//Valida as horas. Retorna 1 em caso de sucesso e 0 caso contr�rio.
int validaHoras(int horas, int minutos, int segundos){

	if ((horas < 0 || horas > 23) || (minutos < 0 || minutos > 59) || (segundos < 0 || segundos > 59))
		return 0;

	return 1;


}//validaHoras()


//Pesquisa a tarefa de acordo com a data. Retorna a posi��o caso exista, caso contr�rio retorna -1.
int pesquisaTarefaData(Pessoa individuo, int dia, int mes, int ano){

	Tarefa *tarefa;
	tm tempo;

	for (int contador = 0; contador < individuo.quantidadeDeTarefas(); contador++){

		//tarefa recebe uma ref�ncia do objeto que est� no vector.
		tarefa = individuo.obterTarefa(contador);

		//tempo recebe a struct tm do vector.
		tempo = tarefa->getTempo();

		//Verificando se a data passada � igual a data de alguma tarefa. Se for, retorna a posi��o da tarefa.
		if (tempo.tm_year + 1900 == ano && tempo.tm_mon + 1 == mes && tempo.tm_mday == dia)
			return contador;


	}

	return -1;

}


//L� uma data.
int lendoUmaData(int &dia, int &mes, int &ano){

	//********************************************* Data da Tarefa *********************************************

	string dat, diaAux, mesAux, anoAux;
	int d, m, a, testa;

	//Fica no loop enquanto n�o digitar a data certa.
	do{

		//Limpando as strings.
		dat.clear();
		diaAux.clear();
		mesAux.clear();
		anoAux.clear();

		do{

			cout << "\n\n Data(DD/MM/AAAA): ";
			getline(cin, dat);

			//Usu�rio deseja cancelar a opera��o.
			if (dat == "-1")
				return -1;

			//Verificando se a data est� no formato DD/MM/AAAA.

			//Verificando se h� 10 digitos. 
			if (dat.length() < 10){

				testa = 0;
				break;

			}

			//O terceiro e sexto elemento da string tem que ser uma / (barra). Se houver alguma altera��o nessa ordem, a data � inv�lida.
			if (dat[2] != '/' || dat[5] != '/'){

				testa = 0;
				break;

			}

			/*� verificado se existe quatro elementos depois da segunda / (barra). Para isso basta subtrair o tamanho da string
			pela posi��o da segunda barra que � 5.*/
			if (dat.size() - 6 != 4){

				testa = 0;
				break;

			}

			//Essa vari�vel salva a data, pois ser�o feitas opera��es no formato da data.
			string salva = dat;

			/*Pegando os dois primeiros caracteres da string, pois eles ser�o convertidos para inteiros e verificado se s�o dias.
			v�lidos. */
			diaAux = diaAux + dat[0] + dat[1];

			//Verificando se tem letra no meio.
			testa = verificaLetra(diaAux);

			if (testa == 1){

				testa = 0;
				break;

			}

			//O mesmo que o de cima, s� que para os meses.
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

			//Convertendo os d�gitos em inteiros, para verificar se os n�meros s�o v�lidos.
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
			cout << "\n\n Data inv�lida\n\n";


	} while (testa == 0);

	//************************************************************

	dia = d;
	mes = m;
	ano = a;

	return 1;

}