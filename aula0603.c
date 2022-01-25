/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Vitor Carneiro Silva de Oliveira
Descricao : Programa de teste para funcao MultiplicarMatrizes

$Author$
$Date $
$Log$

*/

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __ISO_C_VISIBLE 1999
#define __LONG_LONG_SUPPORTED
#endif

#include "aula0601.h"

#include <stdio.h>              
#include <stdlib.h>              
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <math.h>
#include <float.h>

#define OK                    				0
#define NUMERO_ARGUMENTOS_INVALIDO      	1
#define ARGUMENTO_INVALIDO	      			2

#define MIN_NUMERO_ARGUMENTOS				4
#define EOS        							'\0'

int
main(int argc, char *argv[])
{
	unsigned long aux;
	char *verificacao;

  	unsigned indiceLinha, indiceColuna, indice;

	unsigned short  linhasMatriz, colunasMatriz;

	double matrizOriginal[MAXIMO_LINHAS][MAXIMO_COLUNAS];
	double matrizTransposta[MAXIMO_LINHAS][MAXIMO_COLUNAS];
	
	if(argc < MIN_NUMERO_ARGUMENTOS)
	{
		printf("Numero de argumentos invalido\n");
        printf("Uso: %s <LINHAS> <COLUNAS> <A11> <A12> <A21> <A31> ... <A32> ... <Amn>\n", argv[0]);
        printf("\n");
        printf("Digite cada valor como um unico argumento\n");
		printf("Primeiro digite o numero de linhas da matriz, seguido do numero de colunas\n");
		printf("E depois, digite os valores do termo em sequencia A11, A12 ... Amn\n");
		
		exit(NUMERO_ARGUMENTOS_INVALIDO);
	}

	for (indiceLinha = 1; indiceLinha <= 2; indiceLinha++)
		if (argv[indiceLinha][0] == '-')
		{
			printf ("Caracter invalido: '-'\n");
			printf ("Linhas e Colunas da matriz deve ser um valor positivo.\n");
			exit (ARGUMENTO_INVALIDO);	
		}

	/* Converte o argumento referente a linha da matriz*/
	aux = strtoul(argv[1], &verificacao, 10);
	linhasMatriz = aux;

	if(*verificacao != EOS)
	{	
		printf ("Argumento 1 (linhas matriz 1) contem caractere invalido. \n");
		printf ("Primeiro caractere invalido \'%c\'.\n", *verificacao);
		exit (ARGUMENTO_INVALIDO);
	}

	if(aux != linhasMatriz)
	{	
		printf("O valor para linhas da matriz deve ser no maximo %d (unsigned short)\n", USHRT_MAX);
		exit(ARGUMENTO_INVALIDO);
	}

	
	/* Converte o argumento referente a coluna da matriz*/
	aux = strtoul(argv[2], &verificacao, 10);
	colunasMatriz = aux;

	if(*verificacao != EOS)
	{
		printf ("Argumento 2 (colunas matriz 1) contem caractere invalido. \n");
		printf ("Primeiro caractere invalido \'%c\'.\n", *verificacao);
		exit(ARGUMENTO_INVALIDO);
	}

	if(aux != colunasMatriz)
	{
		printf("O valor para colunas da matriz deve ser no maximo %d (unsigned short)\n", USHRT_MAX);
		exit(ARGUMENTO_INVALIDO);
	}

    if (argc != 3 + linhasMatriz * colunasMatriz)
	{
		printf("Argumentos invalidos (%d).\n", argc);
		exit(ARGUMENTO_INVALIDO);
	}
  
    indice = 3;
	for (indiceLinha = 0; indiceLinha < linhasMatriz; indiceLinha++)
		for (indiceColuna = 0; indiceColuna < colunasMatriz; indiceColuna++)
		{
			matrizOriginal[indiceLinha][indiceColuna] = strtod(argv[indice], &verificacao);
			indice++;

			if(errno == ERANGE )
			{
				printf("Overflow no argumento %u (A %ux%u).\n", indice, indiceLinha + 1, indiceColuna + 1);
				printf("Valor maximo: %f (double_max).\n", DBL_MAX);
				printf("Valor minimo: %f (double_min).\n", DBL_MIN);
				exit(ARGUMENTO_INVALIDO);
			}

			if(*verificacao != EOS)
			{
				printf ("Argumento %u (A %ux%u) contem caractere invalido. \n", indice, indiceLinha + 1, indiceColuna + 1);
				printf ("Primeiro caractere invalido \'%c\'.\n", *verificacao);
				exit(ARGUMENTO_INVALIDO);
			}
		}
	
	ObterMatrizTransposta(linhasMatriz, colunasMatriz, &matrizOriginal[0], &matrizTransposta[0]);

	printf("\n");
  	printf(" ---- Matriz transposta -----\n\n");
	for (indiceLinha = 0; indiceLinha < linhasMatriz; indiceLinha++)
	{
		for (indiceColuna = 0; indiceColuna < colunasMatriz; indiceColuna++)
			printf("%.05lf   \t", matrizTransposta[indiceLinha][indiceColuna]);
		
		printf("\n\n");
	}

return OK; 
}

/*$RCSfile$*/
