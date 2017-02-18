#include "Pessoa.h"

Pessoa::Pessoa(){

	codigo = 0;

}//Pessoa().

Pessoa::Pessoa(int codigo, string nome, string dataDeAniversario) {

	setCodigo(codigo);
	setNome(nome);
	setDataAniversario(dataDeAniversario);

}

int Pessoa::getCodigo(){

	return codigo;

}//getCodigo().


void Pessoa::setCodigo(int codigo){

	this->codigo = codigo;

}//setCodigo().


string Pessoa::getNome(){

	return nome;

}//getNome().


void Pessoa::setNome(string nome){

	this->nome = nome;

}//setNome().


string Pessoa::getDataAniversario(){

	return dataDeAniversario;

}//getDataAniversario().


void Pessoa::setDataAniversario(string dataDeAniversario){

	this->dataDeAniversario = dataDeAniversario;

}//setDataAniversario().


// Informa a quantidade atual de e-mails do objeto Pessoa.
int Pessoa::quantidadeDeEmails(){

	return emails.size();

}//quantidadeDeEmail().


// Informa a quantidade atual de tarefas do objeto Pessoa.
int Pessoa::quantidadeDeTarefas(){

	return tarefas.size();

}//quantidadeDeTarefas().


// Informa a quantidade atual de telefones do objeto Pessoa.
int Pessoa::quantidadeDeTelefones(){

	return telefones.size();

}//quantidadeDeTelefone().


// Cadastra um e-mail.
void Pessoa::adicionarEmail(Email email){

	emails.push_back(email);

}//adicioEmail().


// Cadastra uma tarefa. 
void Pessoa::adicionarTarefa(Tarefa tarefa){

	tarefas.push_back(tarefa);

}//adicionaTarefa().

// Cadastra um telefone.
void Pessoa::adicionarTelefone(Telefone telefone){

	telefones.push_back(telefone);

}//adicionaTelefone().


// Pesquisa por um e-mail. Retorna a posição do e-mail. Se o objeto não estiver cadastrado retorna -1.
int Pessoa::pesquisarEmail(string email){

	//temp irá receber os emails vindo do vector emails;
	const char *email1 = email.c_str();
	size_t contador;

	//Loop que percorre o vector em busca do elemento.
	for (contador = 0; contador < emails.size(); contador++){

		string email2 = emails.at(contador).getEmail();
		const char *temp = email2.c_str();

		if (!_stricmp(email1, temp))
			return contador;

	}

	return -1;

}//pesuisarEmail().



// Pesquisa por uma tarefa. Retorna a posição da tarefa. Se o objeto não estiver cadastrado retorna -1.
int Pessoa::pesquisarTarefa(string tarefa){

	//temp irá receber as tarefas vindo do vector tarefas;
	const char *taf = tarefa.c_str();
	size_t contador;

	//Loop que percorre o vector em busca do elemento.
	for (contador = 0; contador < tarefas.size(); contador++){

		string tarefa2 = tarefas.at(contador).getTarefa();
		const char *temp = tarefa2.c_str();

		if (!_stricmp(taf, temp))
			return contador;


	}

	return -1;

}//pesquisarTarefa().


// Pesquisa por um telefone. Retorna a posição do telefone. Se o objeto não estiver cadastrado retorna -1.
int Pessoa::pesquisarTelefone(string telefone){

	const char *telefone1 = telefone.c_str();
	size_t contador;

	for (contador = 0; contador < telefones.size(); contador++){

		string telefone2 = telefones.at(contador).getNumero();
		const char *temp = telefone2.c_str();

		if (!_stricmp(telefone1,temp))
			return contador;

	}

	return -1;

}//pesquisarTelefone().


// Obtém a referência do objeto Email armazenado na posição indicada. Retorna NULL se a posição é inválida.
Email* Pessoa::obterEmail(int posicao){

	Email *email = &emails.at(posicao);

	return email;

}//obterEmail().


// Obtém a referência do objeto Tarefa armazenado na posição indicada. Retorna NULL se a posição é inválida.
Tarefa* Pessoa::obterTarefa(int posicao){

	Tarefa *tarefa = &tarefas.at(posicao);

	return tarefa;

}//obterTarefa().


// Obtém a referência do objeto Telefone armazenado na posição indicada. Retorna NULL se a posição é inválida.
Telefone* Pessoa::obterTelefone(int posicao){

	Telefone *telefone = &telefones.at(posicao);

	return telefone;

}//obterTelefone().


// Exclui um e-mail na posição indicada. Retorna false se não foi excluído porque a posição é inválida, caso contrário, retorna true.
bool Pessoa::removerEmail(int posicao){

	size_t contador;

	contador = posicao;

	//Verificando se a posição está no intervalo, se a posição é válida.
	if (contador >= 0 && contador <= emails.size())
		emails.erase(emails.begin() + contador);
		
	
	else
	  return false;

	return true;
	
}//removerEmail().


// Exclui uma tarefa na posição indicada. Retorna false se não foi excluído porque a posição é inválida, caso contrário, retorna true.
bool Pessoa::removerTarefa(int posicao){

	size_t contador;

	contador = posicao;

	//Verificando se a posição está no intervalo, se a posição é válida.
	if (contador >= 0 && contador <= tarefas.size())
		tarefas.erase(tarefas.begin() + contador);
		
	else
		return false;

	return true;

}//removerTarefa().


// Exclui um telefone na posição indicada. Retorna false se não foi excluído porque a posição é inválida, caso contrário, retorna true.
bool Pessoa::removerTelefone(int posicao){

	size_t contador;

	contador = posicao;

	//Verificando se a posição está no intervalo, se a posição é válida.
	if (contador >= 0 && contador <= telefones.size())
		telefones.erase(telefones.begin() + contador);

	else
		return false;

	

	return true;

}//removerTelefone().