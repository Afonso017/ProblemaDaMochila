#include <iostream>
#include "genetico.h"

#define red "\033[31m"
#define green "\033[32m"
#define default "\033[m"

using namespace std;

int main()
{
	system("chcp 1252 > nul"); // altera o código da página do console para aceitar caracteres com acentuação
	unsigned short solucao1, solucao2, solucao3, solucao4, solucao5, solucao6; // as 6 soluções iniciais
	cout << "Entre com 6 soluções iniciais (números entre 0 e 65535):" << endl;
	cin >> solucao1 >> solucao2 >> solucao3 >> solucao4 >> solucao5 >> solucao6;

	unsigned short solucao7 = cruzamentoPontoUnico(solucao1, solucao2); // cria uma nova solução e faz um cruzamento de ponto único com as duas primeiras soluções
	unsigned short solucao8 = cruzamentoAritmetico(solucao3, solucao4); // cria uma nova solução e faz um cruzamento aritmético com a terceira e quarta solução
	unsigned short solucao9 = mutacaoSimples(solucao5); // faz uma mutação simples na solução 5
	unsigned short solucao10 = mutacaoDupla(solucao6); // faz uma mutação dupla na solução 6

	cout << "\nResultado da Avaliação\n";
	cout << "-----------------------------\n";
	if (funcaoAvaliacao(solucao1))					// verifica se a solução é válida para o problema
		cout << green << "OK" << default << endl;   // mostra na tela um OK verde se a solução for válida...
	else
		cout << red << "X" << default << endl;      // se não, mostra um x vermelho

	if (funcaoAvaliacao(solucao2))
		cout << green << "OK" << default << endl;
	else
		cout << red << "X" << default << endl;

	if (funcaoAvaliacao(solucao3))
		cout << green << "OK" << default << endl;
	else
		cout << red << "X" << default << endl;

	if (funcaoAvaliacao(solucao4))
		cout << green << "OK" << default << endl;
	else
		cout << red << "X" << default << endl;

	if (funcaoAvaliacao(solucao5))
		cout << green << "OK" << default << endl;
	else
		cout << red << "X" << default << endl;

	if (funcaoAvaliacao(solucao6))
		cout << green << "OK" << default << endl;
	else
		cout << red << "X" << default << endl;

	cout << "-----------------------------\n";

	if (funcaoAvaliacao(solucao7))
		cout << green << "OK" << default << endl;
	else
		cout << red << "X" << default << endl;

	if (funcaoAvaliacao(solucao8))
		cout << green << "OK" << default << endl;
	else
		cout << red << "X" << default << endl;

	if (funcaoAvaliacao(solucao9))
		cout << green << "OK" << default << endl;
	else
		cout << red << "X" << default << endl;

	if (funcaoAvaliacao(solucao10))
		cout << green << "OK" << default << endl;
	else
		cout << red << "X" << default << endl;
}