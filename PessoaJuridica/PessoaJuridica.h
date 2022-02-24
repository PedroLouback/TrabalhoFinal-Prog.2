#ifndef PESSOAJURIDICA_H
#define PESSOAJURIDICA_H
#include <iostream>
#include <string>
#include "Pessoa.h"

class PessoaJuridica :
    public Pessoa
{
private:

    string cnpj;
    PessoaJuridica* proxPessoaJuridica;

public:

    PessoaJuridica(string nome, string endereco, string cnpj);
    PessoaJuridica(string cnpj);
    //Gets
    string getCnpj();
    PessoaJuridica* getProxPessoaJuridica();

    //Sets
    void setCnpj(string cnpj);
    void setProxPessoaJuridica(PessoaJuridica* proxPessoaJuridica);

};
#endif