#ifndef LISTAPESSOAJURIDICA_HPP
#define LISTAPESSOAJURIDICA_HPP
#include "ExcecaoCNPJInvalido.h"
#include "PessoaJuridica.h"
#include <Windows.h>

using namespace std;

class ListaPessoaJuridica
{
private:
	PessoaJuridica* cabeca; // primeiro elemento
	PessoaJuridica* cauda; // último elemento


public:
	ListaPessoaJuridica();

	PessoaJuridica* getCabeca();
	void setCabeca(PessoaJuridica* cabeca);

	ListaPessoaJuridica(string nome, string endereco, string cnpj);

	void mostrarTodosPJ();

	bool vazia();

	void inserir_inicio(PessoaJuridica pj);

	// insere no final (semelhante a push_back da list)
	void inserir_final(PessoaJuridica pj);

	int size();

	bool existe(string cnpj);

	void remover();

	bool TrataCNPJ(string cnpj);

	void removePJ(string cnpj);

};

#endif