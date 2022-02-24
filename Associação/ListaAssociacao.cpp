#include <iostream>
#include "Associacao.h"
#include "ListaAssociacao.h"

using namespace std;

ListaAssociacao::ListaAssociacao() {
	cabeca = NULL;
	cauda = NULL;
}

Associacao* ListaAssociacao::getCabeca() {
	return cabeca;
}
void ListaAssociacao::setCabeca(Associacao* cabeca) {
	this->cabeca = cabeca;
}

ListaAssociacao::ListaAssociacao(string nome, string endereco, string cpf)
{
	// se passar elemento, então cria novo No
	cabeca = new Associacao(nome, endereco, cpf);
	cauda = cabeca;
}

// mostra todos os elementos da lista
void ListaAssociacao::mostrarTodos()
{
	int i = 0;
	Associacao* c = cabeca;

	if (vazia())
		cout << "ERRO: A lista não possui pessoas!\n";
	else
	{
		cout << "\n|| Impressão de pessoas físicas associadas a pessoa jurídicas ||\n";
		while (c) // percorre a lista
		{

			cout << "\nPESSOA " << i + 1 << endl;
			i++;
			cout << "Nome: " << c->getNome() << endl;
			cout << "Endereço: " << c->getEndereco() << endl;
			cout << "CPF: " << c->getCpf() << endl;
			c->getListaPessoaJuridica().mostrarTodosPJ();
			c = c->getProxAssociacao();
		}
	}
}

bool ListaAssociacao::vazia() // verifica se a lista está vazia
{
	return (cabeca == NULL);
}

// insere no início (semelhante a push_front da list)
void ListaAssociacao::inserir_inicio(Associacao a)
{
	Associacao* nova_associacao = new Associacao(a.getNome(), a.getEndereco(), a.getCpf());

	if (vazia())
	{
		cabeca = nova_associacao;
		cauda = nova_associacao;
	}
	else
	{
		nova_associacao->setProxAssociacao(cabeca);
		cabeca = nova_associacao;
	}
}

// insere no final (semelhante a push_back)
void ListaAssociacao::inserir_final(Associacao a)
{
	Associacao* nova_associacao = new Associacao(a.getNome(), a.getEndereco(), a.getCpf());

	if (vazia())
	{
		cabeca = nova_associacao;
		cauda = nova_associacao;
	}
	else
	{
		cauda->setProxAssociacao(nova_associacao);
		cauda = nova_associacao;
	}
}

// retorna o tamanho da lista
int ListaAssociacao::size()
{
	if (vazia()) // se for vazia, entã retorna 0
		return 0;

	Associacao* c = cabeca;
	int tam = 0;

	// percorre a lista
	do
	{
		c = c->getProxAssociacao();
		tam++;
	} while (c);

	return tam;
}

// verifica se um elemento existe na lista
bool ListaAssociacao::existe(string cpf)
{
	Associacao* c = cabeca;

	while (c)
	{
		if (c->getCpf() == cpf)
			return true;
		c = c->getProxAssociacao();
	}
	return false;
}

void ListaAssociacao::remover()
{
	if (!vazia())
	{
		// se houver só 1 elemento
		if (cabeca->getProxAssociacao() == NULL)
			cabeca = NULL;
		else if (cabeca->getProxAssociacao()->getProxAssociacao() == NULL) // 2 elementos
			cabeca->setProxAssociacao(NULL);
		else // > 2 elementos
		{
			Associacao* ant_ant = cabeca;
			Associacao* ant = cabeca->getProxAssociacao();
			Associacao* corrente = cabeca->getProxAssociacao()->getProxAssociacao();

			while (corrente)
			{
				Associacao* aux = ant;
				ant = corrente;
				ant_ant = aux;
				corrente = corrente->getProxAssociacao();
			}
			delete ant_ant->getProxAssociacao(); // libera memória
			ant_ant->setProxAssociacao(NULL); // seta o prox como NULL
			cauda = ant_ant; // atualiza a cauda
		}
	}
}

void ListaAssociacao::associar(PessoaJuridica pj, string cpf) {
	Associacao* c = cabeca;

	while (c) {
		if (c->getCpf() == cpf) {
			ListaPessoaJuridica l = c->getListaPessoaJuridica();
			l.inserir_final(pj);
			c->setListaPessoaJuridica(l);
			
		}
		if (c->getProxAssociacao() == NULL) {
			break;
		}
		else {
			c = c->getProxAssociacao();
		}
	}
}

bool ListaAssociacao::verificaCadastro(string cnpj) {
	Associacao* c = cabeca;
	while (c) {
		if (c->getListaPessoaJuridica().existe(cnpj) == true) {
			return true;
		}
		c = c->getProxAssociacao();
	}
	return false;
}

bool ListaAssociacao::verificaAssociacao_Pessoa(string cpf) {

	Associacao* c = cabeca;

	while (c) {
		if (c->getCpf() == cpf) {
			return true;
		}
		c = c->getProxAssociacao();
	}
	return false;
}

string ListaAssociacao::removerAssociacao(string cpf) {

	Associacao* ant_ant = cabeca;
	Associacao* ant = cabeca->getProxAssociacao();

	if (ant_ant->getCpf() == cpf) {
		cabeca = ant_ant->getProxAssociacao();
		ant_ant->getProxAssociacao() == NULL;
		return cpf;
	}
	while (ant != NULL && ant->getCpf() != cpf)
	{
		ant_ant = ant;
		ant = ant->getProxAssociacao();
	}

	if (ant != NULL) {
		ant_ant->setProxAssociacao(ant->getProxAssociacao());
		ant == NULL;
		return cpf;
	}
}

//int ListaAssociacao::removerAssociacaoJuridica(string cnpj) {
//
//	Associacao* aux1 = cabeca;
//	ListaAssociacao la;
//	ListaPessoaJuridica lpj;
//
//	while (aux1) {
//		if (aux1->getListaPessoaJuridica().size() == 1) {
//			if (aux1->getListaPessoaJuridica().existe(cnpj) == true) {
//				aux1->getListaPessoaJuridica().removePJ(cnpj);
//				aux1->setListaPessoaJuridica(lpj);
//				cout << "\nAVISO: A pessoa jurídica é associada a alguma pessoa física, removendo-a a associação será removida a associação também!\n";
//				la.removerAssociacao(aux1->getCpf());
//				return 1;
//			}
//		}
//		aux1 = aux1->getProxAssociacao();
//	}


	/*Associacao* ant_ant = cabeca;
	Associacao* ant = cabeca->getProxAssociacao();

	if (ant_ant->getListaPessoaJuridica().existe(cnpj) == true) {
		ant_ant->getListaPessoaJuridica().removePJ(cnpj);
		return cnpj;
	}
	while (ant != NULL && ant->getListaPessoaJuridica().existe(cnpj) == false)
	{
		ant_ant = ant;
		ant = ant->getProxAssociacao();
	}

	if (ant != NULL) {
		ant_ant->setProxAssociacao(ant->getProxAssociacao());
		ant == NULL;
		return cnpj;
	}*/
//}

bool ListaAssociacao::verificaAssociacaoJuridica(string cnpj) {
	Associacao* c = cabeca;

	while (c) {
		if (c->getListaPessoaJuridica().existe(cnpj) == true) {
			return true;
		}
		c = c->getProxAssociacao();
	}
	return false;
}