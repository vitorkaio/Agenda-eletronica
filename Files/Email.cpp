#include "Email.h"

Email::Email(){

	uso = '0';

}

Email::Email(string email, char uso){

	setEmail(email);
	setUso(uso);

}//Email().


string Email::getEmail(){

	return email;

}//getEmail().


void Email::setEmail(string email){

	this->email = email;

}//setEmail().


char Email::getUso(){

	return uso;

}//getEmail().


void Email::setUso(char uso){

	this->uso = uso;

}//setUso().