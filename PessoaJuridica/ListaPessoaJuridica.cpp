#include <iostream>
#include "PessoaJuridica.h"
#include "ListaPessoaJuridica.h"

ListaPessoaJuridica::ListaPessoaJuridica()
{
	// se não passar elemento, então cabeca e cauda são NULL
	cabeca = NULL;
	cauda = NULL;
}

PessoaJuridica* ListaPessoaJuridica::getCabeca() {
	return cabeca;
}
void ListaPessoaJuridica::setCabeca(PessoaJuridica* cabeca) {
	this->cabeca = cabeca;
}


ListaPessoaJuridica::ListaPessoaJuridica(string nome, string endereco, string cnpj)
{
	// se passar elemento, então cria novo No
	cabeca = new PessoaJuridica(nome, endereco, cnpj);
	cauda = cabeca;
}

// mostra todos os elementos da lista	
void ListaPessoaJuridica::mostrarTodosPJ()
{	
	int i = 0;
	cout << "\n|| Impressão de Pessoas Juridicas ||\n";
	PessoaJuridica* c = cabeca;

	if (vazia())
		cout << "ERRO: A lista não possui pessoas!\n";
	else
	{
		while (c) // percorre a lista
		{

			cout << "\nPESSOA JURIDICA " << i + 1 << endl;
			i++;
			cout << "Nome: " << c->getNome() << endl;
			cout << "Endereço: " << c->getEndereco() << endl;
			cout << "CNPJ: " << c->getCnpj() << endl;
			c = c->getProxPessoaJuridica();
		}
	}
}

bool ListaPessoaJuridica::vazia() // verifica se a lista está vazia
{
	return (cabeca == NULL);
}

// insere no início (semelhante a push_front da list)
void ListaPessoaJuridica::inserir_inicio(PessoaJuridica pf)
{
	PessoaJuridica* nova_pessoa = new PessoaJuridica(pf.getNome(), pf.getEndereco(), pf.getCnpj());

	if (vazia())
	{
		cabeca = nova_pessoa;
		cauda = nova_pessoa;
	}
	else
	{
		nova_pessoa->setProxPessoaJuridica(cabeca);
		cabeca = nova_pessoa;
	}
}

// insere no final (semelhante a push_back)
void ListaPessoaJuridica::inserir_final(PessoaJuridica pf)
{
	PessoaJuridica* nova_pessoa = new PessoaJuridica(pf.getNome(), pf.getEndereco(), pf.getCnpj());

	if (vazia())
	{
		cabeca = nova_pessoa;
		cauda = nova_pessoa;
	}
	else
	{
		cauda->setProxPessoaJuridica(nova_pessoa);
		cauda = nova_pessoa;
	}
}

// retorna o tamanho da lista
int ListaPessoaJuridica::size()
{
	if (vazia()) // se for vazia, entã retorna 0
		return 0;

	PessoaJuridica* c = cabeca;
	int tam = 0;

	// percorre a lista
	do
	{
		c = c->getProxPessoaJuridica();
		tam++;
	} while (c);

	return tam;
}

// verifica se um elemento existe na lista
bool ListaPessoaJuridica::existe(string cnpj)
{
	PessoaJuridica* c = cabeca;

	while (c)
	{
		if (c->getCnpj() == cnpj)
			return true;
		c = c->getProxPessoaJuridica();
	}
	return false;
}

// remove da lista, remoção do final
void ListaPessoaJuridica::remover()
{
	if (!vazia())
	{
		// se houver só 1 elemento
		if (cabeca->getProxPessoaJuridica() == NULL)
			cabeca = NULL;
		else if (cabeca->getProxPessoaJuridica()->getProxPessoaJuridica() == NULL) // 2 elementos
			cabeca->setProxPessoaJuridica(NULL);
		else // > 2 elementos
		{
			PessoaJuridica* ant_ant = cabeca;
			PessoaJuridica* ant = cabeca->getProxPessoaJuridica();
			PessoaJuridica* corrente = cabeca->getProxPessoaJuridica()->getProxPessoaJuridica();

			while (corrente)
			{
				PessoaJuridica* aux = ant;
				ant = corrente;
				ant_ant = aux;
				corrente = corrente->getProxPessoaJuridica();
			}
			delete ant_ant->getProxPessoaJuridica(); // libera memória
			ant_ant->setProxPessoaJuridica(NULL); // seta o prox como NULL
			cauda = ant_ant; // atualiza a cauda
		}
	}
}

bool ListaPessoaJuridica::TrataCNPJ(string cnpj) {
	if (cnpj.size() != 14) {
		throw ExcecaoCNPJInvalido();
		return false;
	}
	for (int i = 0; i < 14; i++) {
		if (!(cnpj.at(i) >= 48 && cnpj.at(i) <= 57)) {
			throw ExcecaoCNPJInvalido();
			return false;
		}
	}
	return true;
}

void ListaPessoaJuridica::removePJ(string cnpj) {

	PessoaJuridica* ant_ant = cabeca;
	PessoaJuridica* ant = cabeca->getProxPessoaJuridica();

	if (ant_ant->getCnpj() == cnpj) {
		cabeca = ant_ant->getProxPessoaJuridica();
		ant_ant->getProxPessoaJuridica() == NULL;
		cout << "\nA pessoa juridica com o CNPJ " << cnpj << " foi encontrada e excluída com sucesso!\n";
	}
	while (ant != NULL && ant->getCnpj() != cnpj)
	{
		ant_ant = ant;
		ant = ant->getProxPessoaJuridica();
	}

	if (ant != NULL) {
		ant_ant->setProxPessoaJuridica(ant->getProxPessoaJuridica());
		ant == NULL;
		cout << "\nA pessoa jurídica com o CNPJ " << cnpj << " foi encontrada e excluída com sucesso!\n";
	}

}

