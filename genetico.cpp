#include <iostream>
#include "binario.h"

using namespace std;

bool funcaoAvaliacao(unsigned short solucao) // fun��o que mostra na tela o valor da solu��o, seu pre�o,
{											 // seu peso e verifica se � v�lida
	int peso = 0;
	int valor = 0;
	if (testarBit(solucao, 0)) // chama a fun��o testarBit para verificar cada um dos 16 bits da solu��o
	{
		peso += 1;             // se o bit for 1, ou seja, estiver ativado, o peso e o valor v�o incrementar
		valor += 12;           // de acordo com seu respectivo objeto
	}

	if (testarBit(solucao, 1))
	{
		peso += 4;
		valor += 4;
	}

	if (testarBit(solucao, 2))
	{
		peso += 2;
		valor += 3;
	}

	if (testarBit(solucao, 3))
	{
		peso += 5;
		valor += 10;
	}

	if (testarBit(solucao, 4))
	{
		peso += 4;
		valor += 15;
	}

	if (testarBit(solucao, 5))
	{
		peso += 2;
		valor += 20;
	}

	if (testarBit(solucao, 6))
	{
		peso += 1;
		valor += 10;
	}

	if (testarBit(solucao, 7))
	{
		peso += 4;
		valor += 2;
	}

	if (testarBit(solucao, 8))
	{
		peso += 3;
		valor += 1;
	}

	if (testarBit(solucao, 9))
	{
		peso += 2;
		valor += 1;
	}

	if (testarBit(solucao, 10))
	{
		peso += 1;
		valor += 3;
	}

	if (testarBit(solucao, 11))
	{
		peso += 9;
		valor += 15;
	}

	if (testarBit(solucao, 12))
	{
		peso += 4;
		valor += 10;
	}

	if (testarBit(solucao, 13))
	{
		peso += 5;
		valor += 8;
	}

	if (testarBit(solucao, 14))
	{
		peso += 3;
		valor += 4;
	}

	if (testarBit(solucao, 15))
	{
		peso += 12;
		valor += 4;
	}

	cout << right; cout.width(5); cout << solucao << "  -  ";          // mostra na tela a tabela dos resultados
	cout << "$"; cout << left; cout.width(3); cout << valor << " -  "; // finais das avalia��es, alinhando as solu��es � direita,
	cout << right; cout.width(2); cout << peso << "Kg" << "  -  ";     // os valores � esquerda e os pesos � direita
	// na tabela, h� um espa�o a mais entre cada elemento para caso exista uma solu��o com valor maior do que 100 a tabela n�o fique mal formatada
	if (peso <= 20)  // verifica se o peso da solu��o � v�lido
		return 1;    // retorna um booleano verdadeiro se a solu��o for v�lida
	else
		return 0;    // ou retorna falso para a solu��o inv�lida   
}

unsigned short cruzamentoPontoUnico(unsigned short solucao1, unsigned short solucao2)
{
	solucao1 = bitsAltos(solucao1); // a variavel solucao1 vai receber apenas os bits altos dela mesma
	solucao2 = bitsBaixos(solucao2); // a variavel solucao2 vai receber apenas os bits baixos dela mesma
	return orBinario(solucao1, solucao2);  // no final, retorna o resultado da opera��o OR entre as duas solu��es que resulta no cruzamento de ponto �nico
	// a opera��o OR serve para "juntar" os dois valores
}

unsigned short cruzamentoAritmetico(unsigned short solucao1, unsigned short solucao2)
{
	return andBinario(solucao1, solucao2); // o cruzamento aritm�tico � uma opera��o AND entre as duas solu��es
}

unsigned short mutacaoSimples(unsigned short solucao1)
{
	if (testarBit(solucao1, 9))              // verifica se o 9� bit da solu��o est� ligado ou n�o
		solucao1 = desligarBit(solucao1, 9); // caso esteja, desliga ele
	else 
		solucao1 = ligarBit(solucao1, 9);    // caso n�o, liga ele

	return solucao1; // retorna a solu��o com o 9� bit modificado
}

unsigned short mutacaoDupla(unsigned short solucao1)
{
	if (testarBit(solucao1, 12))              // verifica se o 12� bit da solu��o est� ligado ou n�o
		solucao1 = desligarBit(solucao1, 12); // caso esteja, desliga ele
	else
		solucao1 = ligarBit(solucao1, 12);    // caso n�o, liga ele

	if (testarBit(solucao1, 3))              // verifica se o 3� bit da solu��o est� ligado ou n�o
		solucao1 = desligarBit(solucao1, 3); // caso esteja, desliga ele
	else
		solucao1 = ligarBit(solucao1, 3);    // caso n�o, liga ele

	return solucao1; // retorna a solu��o com o 12� e o 3� bits modificados
}