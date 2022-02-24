#ifndef PESSOA_H
#define PESSOA_H
#include <iostream>
#include <string>


using namespace std;

class Pessoa
{
private:

	string nome;
	string endereco;


public:
	Pessoa();
	Pessoa(string nome, string endereco);

	//Gets
	string getNome();
	string getEndereco();
	

	//Sets
	
	void setNome(string nome);
	void setEndereco(string endereco);

};
#endif