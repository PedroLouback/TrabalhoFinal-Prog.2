#include <iostream>
#include "PessoaJuridica.h"

using namespace std;

PessoaJuridica::PessoaJuridica(string nome, string endereco, string cnpj) : Pessoa(nome, endereco)
{
    this->cnpj = cnpj;
    this->proxPessoaJuridica = NULL;

}
PessoaJuridica::PessoaJuridica(string cnpj)
{
    this->cnpj = cnpj;
    this->proxPessoaJuridica = NULL;

}

//Gets
string PessoaJuridica::getCnpj()
{
    return cnpj;
}
PessoaJuridica* PessoaJuridica::getProxPessoaJuridica() {
    return proxPessoaJuridica;
}

//Sets
void PessoaJuridica::setCnpj(string cnpj)
{
    this->cnpj = cnpj;
}
void PessoaJuridica::setProxPessoaJuridica(PessoaJuridica* proxPessoaJuridica) {
    this->proxPessoaJuridica = proxPessoaJuridica;
}
