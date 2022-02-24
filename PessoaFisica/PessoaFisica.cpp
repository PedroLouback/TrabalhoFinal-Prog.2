#include "PessoaFisica.h"
#include "ListaPessoaFisica.h"

using namespace std;

PessoaFisica::PessoaFisica(string nome, string endereco, string cpf) : Pessoa(nome, endereco)
{
    this->cpf = cpf;
    this->proxPessoaFisica = NULL;
}

//Gets
string PessoaFisica::getCpf()
{
    return cpf;
}
PessoaFisica* PessoaFisica::getProxPessoaFisica() {
    return proxPessoaFisica;
}

//Sets
void PessoaFisica::setCpf(string cpf)
{
    this->cpf = cpf;
}
void PessoaFisica::setProxPessoaFisica(PessoaFisica* proxPessoaFisica) {
    this->proxPessoaFisica = proxPessoaFisica;
}



