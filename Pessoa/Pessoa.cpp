#include <iostream>
#include "Pessoa.h"

Pessoa::Pessoa(){

}

Pessoa::Pessoa(string nome, string endereco)
{
    this->nome = nome;
    this->endereco = endereco;

}

string Pessoa::getNome()
{
    return this->nome;
}
string Pessoa::getEndereco()
{
    return this->endereco;
}

//Sets
void Pessoa::setNome(string nome)
{
    this->nome = nome;
}
void Pessoa::setEndereco(string endereco)
{
    this->endereco = endereco;
}
