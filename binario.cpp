#include <climits>
#include "binario.h"

unsigned short ligarBit(unsigned short solucao1, int bit)
{
	unsigned short mask = 1 << bit;   // cria uma máscara binária com o valor 1 e move esse bit à esquerda de acordo com o valor da variável bit
	return orBinario(solucao1, mask); // faz um OR entre a solução e a máscara, o resultado da operação vai retornar o valor da solução com o respectivo bit ligado
}

unsigned short desligarBit(unsigned short solucao1, int bit)
{
	unsigned short mask = ~(1 << bit); // cria uma máscara binária com valor 1, move esse bit à esquerda e inverte todos os outros 15 bits
	return andBinario(solucao1, mask); // faz um AND entre a solução e a máscara, o resultado da operação vai retornar o valor da solução com o respectivo bit desligado
}

bool testarBit(unsigned short solucao1, int bit)
{
	unsigned short mask = 1 << bit;
	if (andBinario(solucao1, mask)) // faz um and entre o valor da solução e um bit alocado a uma posição à esquerda
		return 1;                   // caso for verdadeiro, significa que o respectivo bit está ativo, pois o resultado da operação AND só restorna verdadeiro caso os dois valores forem verdadeiros
	else
		return 0;					// caso seja falso significa que o bit está desativado
}

unsigned short andBinario(unsigned short binario1, unsigned short binario2)
{
	return binario1 & binario2; // realiza a operação AND entre dois números
}

unsigned short orBinario(unsigned short binario1, unsigned short binario2)
{
	return binario1 | binario2;   // realiza a operação OR entre dois números
}

unsigned short bitsBaixos(unsigned short estado)
{
	unsigned short mask = UCHAR_MAX;	// cria uma máscara com o valor da capacidade máxima de um unsigned char (o valor 255)
	return andBinario(estado, mask);	// retorna o resultado da operação AND entre uma solução e a máscara, o que resulta nos bits baixos da solução
}

unsigned short bitsAltos(unsigned short estado)
{
	unsigned short mask = ~UCHAR_MAX;	// cria uma máscara com o valor da capacidade máxima de um unsigned char e inverte todos os bits desse valor (o valor 65280)
	return andBinario(estado, mask);	// retorna o resultado da operação AND entre uma solução e a máscara, o que resulta nos bits altos da solução
}