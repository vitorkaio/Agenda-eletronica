#include "Tarefa.h"

Tarefa::Tarefa(){

	codigo = 0;

}

Tarefa::Tarefa(int codigo, string tarefa, tm tempo){

	setCodigo(codigo);
	setTarefa(tarefa);
	setTempo(tempo);

}//Tarefa().

int Tarefa::getCodigo() {

	return codigo;

} // getCodigo()

void Tarefa::setCodigo(int codigo){

	this->codigo = codigo;

} // setCodigo()


string Tarefa::getTarefa(){

	return tarefa;

}//getTarefa().


void Tarefa::setTarefa(string tarefa){

	this->tarefa = tarefa;

}//setTarefa().


tm Tarefa::getTempo(){

	return tempo;

}//getTempo().


void Tarefa::setTempo(tm tempo){

	this->tempo = tempo;

}//setTempo().