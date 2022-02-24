#include <iostream>
#include "PessoaFisica.h"
#include "ListaPessoaFisica.h"


using namespace std;

ListaPessoaFisica::ListaPessoaFisica()
{
	// se não passar elemento, então cabeca e cauda são NULL
	cabeca = NULL;
	cauda = NULL;
}

PessoaFisica* ListaPessoaFisica::getCabeca() {
	return this->cabeca;
}
void ListaPessoaFisica::setCabeca(PessoaFisica* cabeca) {
	this->cabeca = cabeca;
}

ListaPessoaFisica::ListaPessoaFisica(string nome, string endereco, string cpf)
{
	// se passar elemento, então cria novo No
	cabeca = new PessoaFisica(nome, endereco, cpf);
	cauda = cabeca;
}

// mostra todos os elementos da lista
void ListaPessoaFisica::mostrarTodosPF()
{
	SetConsoleOutputCP(65001);
	int i = 0;
	cout << "\n|| Impressão de Pessoas Físicas ||\n";
	PessoaFisica* c = cabeca;

	if (vazia())
		cout << "ERRO: A lista não possui pessoas!\n";
	else
	{
		while (c) // percorre a lista
		{
			cout << "\nPESSOA " << i + 1 << endl;
			i++;
			cout << "Nome: " << c->getNome() << endl;
			cout << "Endereço: " << c->getEndereco() << endl;
			cout << "CPF: " << c->getCpf() << endl;
			c = c->getProxPessoaFisica();
		}
	}
}




bool ListaPessoaFisica::vazia() // verifica se a lista está vazia
{
	return (cabeca == NULL);
}

// insere no início (semelhante a push_front da list)
void ListaPessoaFisica::inserir_inicio(PessoaFisica pf)
{
	PessoaFisica* nova_pessoa = new PessoaFisica(pf.getNome(), pf.getEndereco(), pf.getCpf());

	if (vazia())
	{
		cabeca = nova_pessoa;
		cauda = nova_pessoa;
	}
	else
	{
		nova_pessoa->setProxPessoaFisica(cabeca);
		cabeca = nova_pessoa;
	}
}

// insere no final (semelhante a push_back)
void ListaPessoaFisica::inserir_final(PessoaFisica pf)
{
	PessoaFisica* nova_pessoa = new PessoaFisica(pf.getNome(), pf.getEndereco(), pf.getCpf());

	if (vazia())
	{
		cabeca = nova_pessoa;
		cauda = nova_pessoa;
	}
	else
	{
		cauda->setProxPessoaFisica(nova_pessoa);
		cauda = nova_pessoa;
	}
}


// retorna o tamanho da lista
int ListaPessoaFisica::size()
{
	if (vazia()) // se for vazia, entã retorna 0
		return 0;

	PessoaFisica* c = cabeca;
	int tam = 0;

	// percorre a lista
	do
	{
		c = c->getProxPessoaFisica();
		tam++;
	} while (c);

	return tam;
}

// verifica se um elemento existe na lista
bool ListaPessoaFisica::existe(string cpf)
{
	PessoaFisica* c = cabeca;

	while (c)
	{
		if (c->getCpf() == cpf)
			return true;
		c = c->getProxPessoaFisica();
	}
	return false;
}

bool ListaPessoaFisica::TrataCPF(string cpf) {
	if (cpf.size() != 11) {
		throw ExcecaoCPFInvalido();
		return false;
	}
	for (int i = 0; i < 11; i++) {
		if (!(cpf.at(i) >= 48 && cpf.at(i) <= 57)) {
			throw ExcecaoCPFInvalido();
			return false;
		}
	}
	return true;
}

// remove da lista, remoção do final
void ListaPessoaFisica::remover()
{
	if (!vazia())
	{
		// se houver só 1 elemento
		if (cabeca->getProxPessoaFisica() == NULL)
			cabeca = NULL;
		else if (cabeca->getProxPessoaFisica()->getProxPessoaFisica() == NULL) // 2 elementos
			cabeca->setProxPessoaFisica(NULL);
		else // > 2 elementos
		{
			PessoaFisica* ant_ant = cabeca;
			PessoaFisica* ant = cabeca->getProxPessoaFisica();
			PessoaFisica* corrente = cabeca->getProxPessoaFisica()->getProxPessoaFisica();

			while (corrente)
			{
				PessoaFisica* aux = ant;
				ant = corrente;
				ant_ant = aux;
				corrente = corrente->getProxPessoaFisica();
			}
			delete ant_ant->getProxPessoaFisica(); // libera memória
			ant_ant->setProxPessoaFisica(NULL); // seta o prox como NULL
			cauda = ant_ant; // atualiza a cauda
		}
	}
}
string ListaPessoaFisica::removePF(string cpf) {
	SetConsoleOutputCP(CP_UTF8);
	PessoaFisica* ant_ant = cabeca;
	PessoaFisica* ant = cabeca->getProxPessoaFisica();

	if (ant_ant->getCpf() == cpf) {
		cabeca = ant_ant->getProxPessoaFisica();
		ant_ant->getProxPessoaFisica() == NULL;
		cout << "\nA pessoa física com o CPF " << cpf << " foi encontrada e excluída com sucesso!\n";
		return cpf;
	}
	while (ant != NULL && ant->getCpf() != cpf)
	{
		ant_ant = ant;
		ant = ant->getProxPessoaFisica();
	}

	if (ant != NULL) {
		ant_ant->setProxPessoaFisica(ant->getProxPessoaFisica());
		ant == NULL;
		cout << "\nA pessoa física com o CPF " << cpf << " foi encontrada e excluída com sucesso!\n";
		return cpf;
	}
}

string ListaPessoaFisica::TrataNome(string nome) {
	if (nome.size() > 99 ) {
		throw ExcecaoNomeInvalido();
		return 0;
	}
	return nome;
}

