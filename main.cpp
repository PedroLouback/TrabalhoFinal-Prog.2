#include <iostream>
#include <string>
#include "PessoaFisica.h"
#include "PessoaJuridica.h"
#include "ExcecaoCNPJInvalido.h"
#include "ListaPessoaFisica.h"
#include "ListaPessoaJuridica.h"
#include "ExcecaoNomeInvalido.h"
#include "ExcecaoCPFInvalido.h"
#include "Associacao.h"
#include "ListaAssociacao.h"
#include <windows.h>

using namespace std;

int main()
{
    ListaPessoaFisica lpf;
	ListaPessoaJuridica lpj;
	ListaPessoaJuridica teste;
	ListaAssociacao la;
	int escolha, i=0;
	string nome, cpf, endereco, cnpj;
	
	SetConsoleOutputCP(CP_UTF8);

	while (1) {
		cout << "\n|-------------------- > CADASTRO DE PESSOAS < -------------------------|";
		cout << "\n|   Selecione uma das alternativas abaixos conforme sua descrição!     |";
		cout << "\n|1. Cadastrar uma Pessoa Física;                                       |";
		cout << "\n|2. Excluir Pessoa Física;                                             |";
		cout << "\n|3. Cadastrar uma Pessoa Jurídica;                                     |";
		cout << "\n|4. Excluir Pessoa Juridica;                                           |";
		cout << "\n|5. Associar uma pessoa física a uma pessoa jurídica;                  |";
		cout << "\n|6. Imprimir a lista de pessoas físicas cadastradas;                   |";
		cout << "\n|7. Imprimir a lista de pessoas jurídicas cadastradas;                 |";
		cout << "\n|8. Imprimir a lista de associações entre pessoas físicas e jurídicas; |";
		cout << "\n|9. Para encerrar o programa;                                          |";
		cout << "\n|----------------------------------------------------------------------|";
		cout << ("\n\nInforme a opção em que deseja fazer: ");
		cin >> escolha;


		switch (escolha) {
			case 1:
			{
				cout << "\n||CADASTRO PESSOA FÍSICA|| \n";
				cin.ignore();
				while (true) {
					try {
						cout << "\nInforme o nome: ";
						getline(cin, nome);
						lpf.TrataNome(nome);
						break;
					}
					catch (ExcecaoNomeInvalido& exnome) {
						cout << "ERRO: " << exnome.what() << endl;
					}
				}
				cout << "Informe o endereço: ";
				getline(cin, endereco);
				while (true) {
					try {
						cout << "Informe os 11 dígitos do CPF da pessoa (somente números): ";
						getline(cin, cpf);
						lpf.TrataCPF(cpf);
						break;
					}
					catch (ExcecaoCPFInvalido& ex) {
						cout << "ERRO: " << ex.what() << endl;
					}
				}
				
				PessoaFisica pf(nome, endereco, cpf);

				lpf.inserir_final(pf);
				cout << "\nPessoa Física cadastrada com sucesso!\n";
				break;
			}
			case 2:
			{
				while (true) {
					try {
						cout << "Informe os 11 dígitos do CPF da pessoa que deseja excluir: ";
						cin.ignore();
						getline(cin, cpf);
						lpf.TrataCPF(cpf);
						break;
					}
					catch (ExcecaoCPFInvalido& ex) {
						cout << "ERRO: " << ex.what() << endl;
					}
				}

				if (lpf.existe(cpf) == true) {
					if (la.verificaAssociacao_Pessoa(cpf) == true) {
						cout << "\nAVISO: A pessoa física possui associações feitas, removendo-a irá ser removido também todas as suas associações!\n";
						do {
							la.removerAssociacao(cpf);
							i++;
						} while (i == la.size());
					}
					lpf.removePF(cpf);
					break;
				}
				else {
					cout << "\nERRO: CPF não encontrado!\n";
					break;
				}
			}
			case 3:
			{
				cout << "\n||CADASTRO PESSOA JURIDICA|| \n";
				cin.ignore();
				cout << "\nInforme o nome: ";
				getline(cin, nome);
				cout << "Informe o endereço: ";
				getline(cin, endereco);
				while (true) {
					try {
						cout << "Informe os 14 dígitos do CNPJ da pessoa juridica (somente números): ";
						getline(cin, cnpj);
						lpj.TrataCNPJ(cnpj);
						break;
					}
					catch (ExcecaoCNPJInvalido& excnpj) {
						cout << "ERRO: " << excnpj.what() << endl;
					}
				}
				PessoaJuridica pj(nome, endereco, cnpj);

				lpj.inserir_final(pj);
				cout << "\nPessoa Juridica cadastrada com sucesso!\n";
				break;
			}
			case 4:
			{
				cin.ignore();
				while (true) {
					try {
						cout << "Informe os 14 dígitos do CNPJ da pessoa juridica que deseja excluir: ";
						getline(cin, cnpj);
						lpj.TrataCNPJ(cnpj);
						break;
					}
					catch (ExcecaoCNPJInvalido& excnpj) {
						cout << "ERRO: " << excnpj.what() << endl;
					}
				}

				if (lpj.existe(cnpj) == true) {
					if (la.verificaAssociacaoJuridica(cnpj) == true) {
						cout << "\nERRO: A pessoa jurídica que deseja remover é associada a uma pessoa fisica sendo assim impossível removê-la!\n";
						break;
					}
					lpj.removePJ(cnpj);
					break;
				}
				else {
					cout << "\nERRO: CNPJ não encontrado!\n";
					break;
				}

			}
			case 5:
			{
				while (true) {
					try {
						cout << "Informe os 11 dígitos do CPF da pessoa (somente números): ";
						cin >> cpf;
						cin.ignore();
						lpf.TrataCPF(cpf);
						break;
					}
					catch (ExcecaoCPFInvalido& ex) {
						cout << "ERRO: " << ex.what() << endl;
					}
				}
				if (lpf.existe(cpf) == false) {
					cout << "\nERRO:CPF não encontrado!\n";
				}
				else {
					cout << "\nInforme o CNPJ da Pessoa Juridica que deseja associar ao CPF " << cpf << ": ";
					getline(cin, cnpj);
					if (lpj.existe(cnpj) == false) {
						cout << "\nERRO: CNPJ não encontrado!\n";
						break;
					}
					else {
						PessoaFisica* aux = lpf.getCabeca();
						while (aux) {
							if (cpf == aux->getCpf()) {
								PessoaJuridica* aux2 = lpj.getCabeca();
								while (aux2){
									if (aux2->getCnpj() == cnpj) {
										if (la.verificaCadastro(cnpj) == true) {
											cout << "\nERRO: Essa Pessoa Jurídica já é associada a uma Pessoa Física\n";
											break;
										}
										PessoaJuridica pj(aux2->getNome(), aux2->getEndereco(), aux2->getCnpj());
										Associacao a(aux->getNome(), aux->getEndereco(), aux->getCpf());
										if (la.existe(aux->getCpf()) == false)
											la.inserir_final(a);	
										la.associar(pj,cpf);
										cout << "\nPessoa com CPF '" << cpf << "' foi associado com sucesso a empresa com CNPJ '" << cnpj << "'!\n";
										break;
									}
									aux2 = aux2->getProxPessoaJuridica();
								}
							}
							aux = aux->getProxPessoaFisica();
						}
					}
				}
				break;
			}
			case 6:
			{
				lpf.mostrarTodosPF();
				break;
			}
			case 7:
			{
				lpj.mostrarTodosPJ();
				break;
			}
			case 8:
			{
				la.mostrarTodos();
				break;
			}
			case 9:
			{
				cout << "\nOpção de encerramento escolhida!";
				cout << "\nENCERRANDO...";
				return 0;
			}
		}

	}

}

