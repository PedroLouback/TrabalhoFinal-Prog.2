#ifndef ASSOCIACAO_H
#define ASSOCIACAO_H
#include <iostream>
#include <string>
#include "PessoaFisica.h"
#include "ListaPessoaJuridica.h"

using namespace std;

class Associacao:public PessoaFisica
{
private:

	ListaPessoaJuridica lpj;
	Associacao* proxAssociacao;

public:

	Associacao(string nome, string endereco, string cpf);

	//Gets
	ListaPessoaJuridica getListaPessoaJuridica();
	Associacao* getProxAssociacao();

	//Sets
	void setListaPessoaJuridica(ListaPessoaJuridica lpj);
	void setProxAssociacao(Associacao* proxAssociacao);

};
#endif
