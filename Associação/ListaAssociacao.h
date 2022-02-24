#ifndef LISTAASSOCIACAO_H
#define LISTAASSOCIACAO_H

using namespace std;

class ListaAssociacao
{
private:

	Associacao* cabeca;
	Associacao* cauda;

public:
	ListaAssociacao();

	Associacao* getCabeca();
	void setCabeca(Associacao* cabeca);

	ListaAssociacao(string nome, string endereco, string cpf);

	void mostrarTodos();

	bool vazia();

	void inserir_inicio(Associacao a);

	// insere no final (semelhante a push_back da list)
	void inserir_final(Associacao a);

	int size();

	bool existe(string cpf);

	void associar(PessoaJuridica pj, string cpf);

	void remover();

	string removerAssociacao(string cpf);

	bool verificaCadastro(string cnpj);

	bool verificaAssociacao_Pessoa(string cpf);

	bool verificaAssociacaoJuridica(string cnpj);

	int removerAssociacaoJuridica(string cnpj);

};
#endif
