#include <climits>
#include "binario.h"

unsigned short ligarBit(unsigned short solucao1, int bit)
{
	unsigned short mask = 1 << bit;   // cria uma m�scara bin�ria com o valor 1 e move esse bit � esquerda de acordo com o valor da vari�vel bit
	return orBinario(solucao1, mask); // faz um OR entre a solu��o e a m�scara, o resultado da opera��o vai retornar o valor da solu��o com o respectivo bit ligado
}

unsigned short desligarBit(unsigned short solucao1, int bit)
{
	unsigned short mask = ~(1 << bit); // cria uma m�scara bin�ria com valor 1, move esse bit � esquerda e inverte todos os outros 15 bits
	return andBinario(solucao1, mask); // faz um AND entre a solu��o e a m�scara, o resultado da opera��o vai retornar o valor da solu��o com o respectivo bit desligado
}

bool testarBit(unsigned short solucao1, int bit)
{
	unsigned short mask = 1 << bit;
	if (andBinario(solucao1, mask)) // faz um and entre o valor da solu��o e um bit alocado a uma posi��o � esquerda
		return 1;                   // caso for verdadeiro, significa que o respectivo bit est� ativo, pois o resultado da opera��o AND s� restorna verdadeiro caso os dois valores forem verdadeiros
	else
		return 0;					// caso seja falso significa que o bit est� desativado
}

unsigned short andBinario(unsigned short binario1, unsigned short binario2)
{
	return binario1 & binario2; // realiza a opera��o AND entre dois n�meros
}

unsigned short orBinario(unsigned short binario1, unsigned short binario2)
{
	return binario1 | binario2;   // realiza a opera��o OR entre dois n�meros
}

unsigned short bitsBaixos(unsigned short estado)
{
	unsigned short mask = UCHAR_MAX;	// cria uma m�scara com o valor da capacidade m�xima de um unsigned char (o valor 255)
	return andBinario(estado, mask);	// retorna o resultado da opera��o AND entre uma solu��o e a m�scara, o que resulta nos bits baixos da solu��o
}

unsigned short bitsAltos(unsigned short estado)
{
	unsigned short mask = ~UCHAR_MAX;	// cria uma m�scara com o valor da capacidade m�xima de um unsigned char e inverte todos os bits desse valor (o valor 65280)
	return andBinario(estado, mask);	// retorna o resultado da opera��o AND entre uma solu��o e a m�scara, o que resulta nos bits altos da solu��o
}