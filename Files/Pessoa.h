#ifndef PESSOA_H
#define PESSOA_H

#include "Email.h"
#include <vector>
#include <conio.h>

class Pessoa {
public:
	Pessoa();
	Pessoa(int codigo, string nome, string dataDeAniversario);

	int getCodigo();
	void setCodigo(int codigo);

	string getNome();
	void setNome(string nome);

	string getDataAniversario();
	void setDataAniversario(string dataDeAniversario);

	// Informa a quantidade atual de e-mails do objeto Pessoa.
	int quantidadeDeEmails();

	// Informa a quantidade atual de tarefas do objeto Pessoa.
	int quantidadeDeTarefas();

	// Informa a quantidade atual de telefones do objeto Pessoa.
	int quantidadeDeTelefones();
	
	// Cadastra um e-mail.
	void adicionarEmail(Email email);

	// Cadastra uma tarefa. 
	void adicionarTarefa(Tarefa tarefa);

	// Cadastra um telefone.
	void adicionarTelefone(Telefone telefone);

	// Pesquisa por um e-mail. Retorna a posi��o do e-mail. Se o objeto n�o estiver cadastrado retorna -1.
	int pesquisarEmail(string email);

	// Pesquisa por uma tarefa. Retorna a posi��o da tarefa. Se o objeto n�o estiver cadastrado retorna -1.
	int pesquisarTarefa(string tarefa);

	// Pesquisa por um telefone. Retorna a posi��o do telefone. Se o objeto n�o estiver cadastrado retorna -1.
	int pesquisarTelefone(string telefone);

	// Obt�m a refer�ncia do objeto Email armazenado na posi��o indicada. Retorna NULL se a posi��o � inv�lida.
	Email* obterEmail(int posicao);

	// Obt�m a refer�ncia do objeto Tarefa armazenado na posi��o indicada. Retorna NULL se a posi��o � inv�lida.
	Tarefa* obterTarefa(int posicao);

	// Obt�m a refer�ncia do objeto Telefone armazenado na posi��o indicada. Retorna NULL se a posi��o � inv�lida.
	Telefone* obterTelefone(int posicao);

	// Exclui um e-mail na posi��o indicada. Retorna false se n�o foi exclu�do porque a posi��o � inv�lida, caso contr�rio, retorna true.
	bool removerEmail(int posicao);

	// Exclui uma tarefa na posi��o indicada. Retorna false se n�o foi exclu�do porque a posi��o � inv�lida, caso contr�rio, retorna true.
	bool removerTarefa(int posicao);

	// Exclui um telefone na posi��o indicada. Retorna false se n�o foi exclu�do porque a posi��o � inv�lida, caso contr�rio, retorna true.
	bool removerTelefone(int posicao);

private:
	int codigo; // C�digo �nico de identifica��o da pessoa. 
	string nome; // Nome do contato.
	string dataDeAniversario; // Data de anivers�rio no formato "DD/MM/AAAA" ou "DD/MM".

	vector<Email> emails;
	vector<Telefone> telefones;

	/* O objeto vector tarefas registra todas as tarefas que uma pessoa possui, por exemplo:
	 *
	 * Segunda, 22/12 �s 15:00 - Comprar presente de Natal.
	 * Ter�a, 23/12 �s 8:00 - Viajar.
	 */
	vector<Tarefa> tarefas;
};
#endif