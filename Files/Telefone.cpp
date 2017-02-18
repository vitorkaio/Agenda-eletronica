#include "Telefone.h"

Telefone::Telefone(){

	tipo = '0';
	uso = '0';

}

Telefone::Telefone(string numero, char tipo, char uso){

	setNumero(numero);
	setTipo(tipo);
	setUso(uso);

}//Telefone().


string Telefone::getNumero(){

	return numero;

}//getNumero().


void Telefone::setNumero(string numero){

	this->numero = numero;


}//setNumero().


char Telefone::getTipo(){

	return tipo;

}//getTelefone().


void Telefone::setTipo(char tipo){

	this->tipo = tipo;

}//setTipo().


char Telefone::getUso(){

	return uso;

}//getUso().


void Telefone::setUso(char uso){

	this->uso = uso;

}//setUso().
