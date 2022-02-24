#ifndef LISTAPESSOAFISICA_HPP
#define LISTAPESSOAFISICA_HPP
#include "ExcecaoCPFInvalido.h"
#include "ExcecaoNomeInvalido.h"
#include <Windows.h>

using namespace std;

class ListaPessoaFisica
{
private:
	PessoaFisica* cabeca; // primeiro elemento
	PessoaFisica* cauda; // último elemento


public:
	ListaPessoaFisica();

	ListaPessoaFisica(string nome, string endereco, string cpf);

	PessoaFisica* getCabeca();
	void setCabeca(PessoaFisica* cabeca);

	void mostrarTodosPF();

	bool vazia();

	void inserir_inicio(PessoaFisica pf);

	// insere no final (semelhante a push_back da list)
	void inserir_final(PessoaFisica pf);

	int size();

	bool existe(string cpf);

	void remover();

	bool TrataCPF(string cpf);

	string removePF(string cpf);

	string TrataNome(string nome);
	
};

#endif