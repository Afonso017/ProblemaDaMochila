#include <iostream>
#include "binario.h"

using namespace std;

bool funcaoAvaliacao(unsigned short solucao) // função que mostra na tela o valor da solução, seu preço,
{											 // seu peso e verifica se é válida
	int peso = 0;
	int valor = 0;
	if (testarBit(solucao, 0)) // chama a função testarBit para verificar cada um dos 16 bits da solução
	{
		peso += 1;             // se o bit for 1, ou seja, estiver ativado, o peso e o valor vão incrementar
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
	cout << "$"; cout << left; cout.width(3); cout << valor << " -  "; // finais das avaliações, alinhando as soluções à direita,
	cout << right; cout.width(2); cout << peso << "Kg" << "  -  ";     // os valores à esquerda e os pesos à direita
	// na tabela, há um espaço a mais entre cada elemento para caso exista uma solução com valor maior do que 100 a tabela não fique mal formatada
	if (peso <= 20)  // verifica se o peso da solução é válido
		return 1;    // retorna um booleano verdadeiro se a solução for válida
	else
		return 0;    // ou retorna falso para a solução inválida   
}

unsigned short cruzamentoPontoUnico(unsigned short solucao1, unsigned short solucao2)
{
	solucao1 = bitsAltos(solucao1); // a variavel solucao1 vai receber apenas os bits altos dela mesma
	solucao2 = bitsBaixos(solucao2); // a variavel solucao2 vai receber apenas os bits baixos dela mesma
	return orBinario(solucao1, solucao2);  // no final, retorna o resultado da operação OR entre as duas soluções que resulta no cruzamento de ponto único
	// a operação OR serve para "juntar" os dois valores
}

unsigned short cruzamentoAritmetico(unsigned short solucao1, unsigned short solucao2)
{
	return andBinario(solucao1, solucao2); // o cruzamento aritmético é uma operação AND entre as duas soluções
}

unsigned short mutacaoSimples(unsigned short solucao1)
{
	if (testarBit(solucao1, 9))              // verifica se o 9° bit da solução está ligado ou não
		solucao1 = desligarBit(solucao1, 9); // caso esteja, desliga ele
	else 
		solucao1 = ligarBit(solucao1, 9);    // caso não, liga ele

	return solucao1; // retorna a solução com o 9° bit modificado
}

unsigned short mutacaoDupla(unsigned short solucao1)
{
	if (testarBit(solucao1, 12))              // verifica se o 12° bit da solução está ligado ou não
		solucao1 = desligarBit(solucao1, 12); // caso esteja, desliga ele
	else
		solucao1 = ligarBit(solucao1, 12);    // caso não, liga ele

	if (testarBit(solucao1, 3))              // verifica se o 3° bit da solução está ligado ou não
		solucao1 = desligarBit(solucao1, 3); // caso esteja, desliga ele
	else
		solucao1 = ligarBit(solucao1, 3);    // caso não, liga ele

	return solucao1; // retorna a solução com o 12° e o 3° bits modificados
}