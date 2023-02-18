#include <iostream>
#include "genetico.h"

#define red "\033[31m"
#define green "\033[32m"
#define default "\033[m"

using namespace std;

int main()
{
	system("chcp 1252 > nul"); // altera o c�digo da p�gina do console para aceitar caracteres com acentua��o
	unsigned short solucao1, solucao2, solucao3, solucao4, solucao5, solucao6; // as 6 solu��es iniciais
	cout << "Entre com 6 solu��es iniciais (n�meros entre 0 e 65535):" << endl;
	cin >> solucao1 >> solucao2 >> solucao3 >> solucao4 >> solucao5 >> solucao6;

	unsigned short solucao7 = cruzamentoPontoUnico(solucao1, solucao2); // cria uma nova solu��o e faz um cruzamento de ponto �nico com as duas primeiras solu��es
	unsigned short solucao8 = cruzamentoAritmetico(solucao3, solucao4); // cria uma nova solu��o e faz um cruzamento aritm�tico com a terceira e quarta solu��o
	unsigned short solucao9 = mutacaoSimples(solucao5); // faz uma muta��o simples na solu��o 5
	unsigned short solucao10 = mutacaoDupla(solucao6); // faz uma muta��o dupla na solu��o 6

	cout << "\nResultado da Avalia��o\n";
	cout << "-----------------------------\n";
	if (funcaoAvaliacao(solucao1))					// verifica se a solu��o � v�lida para o problema
		cout << green << "OK" << default << endl;   // mostra na tela um OK verde se a solu��o for v�lida...
	else
		cout << red << "X" << default << endl;      // se n�o, mostra um x vermelho

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