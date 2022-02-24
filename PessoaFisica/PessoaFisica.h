#ifndef PESSOAFISICA_H
#define PESSOAFISICA_H
#include <iostream>
#include <string>
#include <Windows.h>
#include "Pessoa.h"
#include "ListaPessoaJuridica.h"

using namespace std;

class PessoaFisica :
    public Pessoa
{
private:
     
    string cpf;
    PessoaFisica* proxPessoaFisica;

public:
    PessoaFisica(string nome, string endereco, string cpf);
    
    //Gets
    string getCpf();
    PessoaFisica* getProxPessoaFisica();

    //Sets
    void setCpf(string cpf);
    void setProxPessoaFisica(PessoaFisica* proxPessoaFisica);

};
#endif
