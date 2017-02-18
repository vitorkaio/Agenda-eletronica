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

	// Pesquisa por um e-mail. Retorna a posição do e-mail. Se o objeto não estiver cadastrado retorna -1.
	int pesquisarEmail(string email);

	// Pesquisa por uma tarefa. Retorna a posição da tarefa. Se o objeto não estiver cadastrado retorna -1.
	int pesquisarTarefa(string tarefa);

	// Pesquisa por um telefone. Retorna a posição do telefone. Se o objeto não estiver cadastrado retorna -1.
	int pesquisarTelefone(string telefone);

	// Obtém a referência do objeto Email armazenado na posição indicada. Retorna NULL se a posição é inválida.
	Email* obterEmail(int posicao);

	// Obtém a referência do objeto Tarefa armazenado na posição indicada. Retorna NULL se a posição é inválida.
	Tarefa* obterTarefa(int posicao);

	// Obtém a referência do objeto Telefone armazenado na posição indicada. Retorna NULL se a posição é inválida.
	Telefone* obterTelefone(int posicao);

	// Exclui um e-mail na posição indicada. Retorna false se não foi excluído porque a posição é inválida, caso contrário, retorna true.
	bool removerEmail(int posicao);

	// Exclui uma tarefa na posição indicada. Retorna false se não foi excluído porque a posição é inválida, caso contrário, retorna true.
	bool removerTarefa(int posicao);

	// Exclui um telefone na posição indicada. Retorna false se não foi excluído porque a posição é inválida, caso contrário, retorna true.
	bool removerTelefone(int posicao);

private:
	int codigo; // Código único de identificação da pessoa. 
	string nome; // Nome do contato.
	string dataDeAniversario; // Data de aniversário no formato "DD/MM/AAAA" ou "DD/MM".

	vector<Email> emails;
	vector<Telefone> telefones;

	/* O objeto vector tarefas registra todas as tarefas que uma pessoa possui, por exemplo:
	 *
	 * Segunda, 22/12 às 15:00 - Comprar presente de Natal.
	 * Terça, 23/12 às 8:00 - Viajar.
	 */
	vector<Tarefa> tarefas;
};
#endif