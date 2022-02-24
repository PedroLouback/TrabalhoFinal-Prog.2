#include "Associacao.h"

using namespace std;

Associacao::Associacao(string nome, string endereco, string cpf) : PessoaFisica(nome, endereco, cpf) {
	this->lpj = lpj;
	this->proxAssociacao = NULL;
}

//Gets
ListaPessoaJuridica Associacao::getListaPessoaJuridica()
{
	return lpj;
}
Associacao* Associacao::getProxAssociacao() {
	return proxAssociacao;
}

//Sets
void Associacao::setListaPessoaJuridica(ListaPessoaJuridica lpj) {
	this->lpj = lpj;
}
void Associacao::setProxAssociacao(Associacao* proxAssociacao) {
	this->proxAssociacao = proxAssociacao;
}