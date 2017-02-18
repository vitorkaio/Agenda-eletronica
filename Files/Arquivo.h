#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "Pessoa.h"
#include <fstream>

//Abre o arquivo para gravação.
int gravaNoArquivo(vector<Pessoa>&agenda);

//Abre o arquivo para leitura.
int lerDoArquivo(vector<Pessoa>&agenda);


#endif
