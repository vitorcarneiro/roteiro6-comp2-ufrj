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

#define MIN_NUMERO_ARGUMENTOS				7
#define EOS        							'\0'

int
main(int argc, char *argv[])
{
	unsigned long aux = 0;
	char *verificacao;

  	unsigned indiceLinha, indiceColuna, indiceArgumento = 5;

	unsigned short  linhasMatriz1, colunasMatriz1, linhasMatriz2, colunasMatriz2;

	double matriz1 [MAXIMO_LINHAS][MAXIMO_COLUNAS];
	double matriz2 [MAXIMO_LINHAS][MAXIMO_COLUNAS]; 
	double matrizProduto [MAXIMO_LINHAS][MAXIMO_COLUNAS];
	
	if(argc < MIN_NUMERO_ARGUMENTOS)
	{
		printf("Numero de argumentos invalido\n");
        printf("Uso: %s <L1> <C1> <L2> <C2> <A11> <A12> <A21> ... <Amn> ... <B11> ... <Bmn>\n", argv[0]);
        printf("\n");
        printf("Digite cada valor como um unico argumento\n");
		printf("Primeiro digite o numero de linhas da primeira matriz, seguido do numero de colunas\n");
		printf("Depois, digite o numero de linhas da segunda matriz, seguido do numero de colunas\n");
		printf("E depois, digite os valores do termo em sequencia A11, A12 ... Amn, e depois o da segunda da matriz\n");
		
		exit(NUMERO_ARGUMENTOS_INVALIDO);
	}

	for (indiceLinha = 1; indiceLinha <= 4; indiceLinha++)
		if (argv[indiceLinha][0] == '-')
		{
			printf ("Caracter invalido: '-'\n");
			printf ("Linhas e Colunas de qualquer matriz deve ser um valor positivo.\n");
			exit (ARGUMENTO_INVALIDO);	
		}

	/* Converte o argumento referente a linha da primeira matriz*/
	aux = strtoul(argv[1], &verificacao, 10);
	linhasMatriz1 = aux;

	if(*verificacao != EOS)
	{	
		printf ("Argumento 1 (linhas matriz 1) contem caractere invalido. \n");
		printf ("Primeiro caractere invalido \'%c\'.\n", *verificacao);
		exit (ARGUMENTO_INVALIDO);
	}

	if(aux != linhasMatriz1)
	{	
		printf("O valor para linhas da matriz deve ser no maximo %hu (unsigned short)\n", USHRT_MAX);
		exit(ARGUMENTO_INVALIDO);
	}

	
	/* Converte o argumento referente a coluna da primeira matriz*/
	aux = strtoul(argv[2], &verificacao, 10);
	colunasMatriz1 = aux;

	if(*verificacao != EOS)
	{
		printf ("Argumento 2 (colunas matriz 1) contem caractere invalido. \n");
		printf ("Primeiro caractere invalido \'%c\'.\n", *verificacao);
		exit(ARGUMENTO_INVALIDO);
	}

	if(aux != colunasMatriz1)
	{
		printf("O valor para colunas da matriz deve ser no maximo %hu (unsigned short)\n", USHRT_MAX);
		exit(ARGUMENTO_INVALIDO);
	}


	/* Converte o argumento referente a linha da segunda matriz*/
	aux = strtoul(argv[3], &verificacao, 10);
	linhasMatriz2 = aux;

	if(*verificacao != EOS)
	{
		printf ("Argumento 3 (linhas matriz 2) contem caractere invalido. \n");
		printf ("Primeiro caractere invalido \'%c\'.\n", *verificacao);
		exit (ARGUMENTO_INVALIDO);;
	}

	if(aux != linhasMatriz2)
	{
		printf("O valor para linhas da matriz deve ser no maximo %hu (unsigned short)\n", USHRT_MAX);
		exit(ARGUMENTO_INVALIDO);
	}


	/* Converte o argumento referente a coluna da segunda matriz*/
	aux = strtoul(argv[4], &verificacao, 10);
	colunasMatriz2 = aux;

	if(*verificacao != EOS)
	{
		printf ("Argumento 4 (colunas matriz 2) contem caractere invalido. \n");
		printf ("Primeiro caractere invalido \'%c\'.\n", *verificacao);
		exit(ARGUMENTO_INVALIDO);
	}

	if(aux != colunasMatriz2)
	{
		printf("O valor para colunas da matriz deve ser no maximo %hu (unsigned short)\n", USHRT_MAX);
		exit(ARGUMENTO_INVALIDO);
	}
	
	if(colunasMatriz1 != linhasMatriz2)
	{
		printf ("Para multiplicar 2 matrizes, a quantidade de colunas da matriz 1 deve ser igual as linhas da matriz 2.\n");
		exit(ARGUMENTO_INVALIDO);	
	}
  
	for (indiceLinha = 0; indiceLinha < linhasMatriz1; indiceLinha++)
		for (indiceColuna = 0; indiceColuna < colunasMatriz1; indiceColuna++)
		{
			matriz1[indiceLinha][indiceColuna] = strtod(argv[indiceArgumento], &verificacao);
			indiceArgumento++;

			if(errno == ERANGE )
			{
				printf("Overflow no argumento %u (A %ux%u).\n", indiceArgumento, indiceLinha + 1, indiceColuna + 1);
				printf("Valor maximo: %f (double_max).\n", DBL_MAX);
				printf("Valor minimo: %f (double_min).\n", DBL_MIN);
				exit(ARGUMENTO_INVALIDO);
			}

			if(*verificacao != EOS)
			{
				printf ("Argumento %u (A %ux%u) contem caractere invalido. \n", indiceArgumento, indiceLinha + 1, indiceColuna + 1);
				printf ("Primeiro caractere invalido \'%c\'.\n", *verificacao);
				exit(ARGUMENTO_INVALIDO);
			}

		}
	

	for (indiceLinha = 0; indiceLinha < linhasMatriz2; indiceLinha++)
		for (indiceColuna = 0; indiceColuna < colunasMatriz2; indiceColuna++)
		{
			matriz2 [indiceLinha][indiceColuna] = strtod(argv[indiceArgumento],&verificacao);
			indiceArgumento++;
				
			if(errno == ERANGE )
			{
				printf("Overflow no argumento %u (A %ux%u).\n", indiceArgumento, indiceLinha + 1, indiceColuna + 1);
				printf("Valor maximo: %f (double_max).\n", DBL_MAX);
				printf("Valor minimo: %f (double_min).\n", DBL_MIN);
				exit(ARGUMENTO_INVALIDO);
			}

			if(*verificacao != EOS)
			{
				printf ("Argumento %u (B %ux%u) contem caractere invalido. \n", indiceArgumento, indiceLinha + 1, indiceColuna + 1);
				printf ("Primeiro caractere invalido \'%c\'.\n", *verificacao);
				exit(ARGUMENTO_INVALIDO);
			}
		}
	
  	MultiplicarMatrizes(linhasMatriz1, colunasMatriz1, linhasMatriz2, colunasMatriz2, &matriz1[0], &matriz2[0], &matrizProduto[0]);

	printf("\n");
  	printf(" ---- Matriz resultado -----\n\n");
	for (indiceLinha = 0; indiceLinha < linhasMatriz1; indiceLinha++)
	{
		for (indiceColuna = 0; indiceColuna < colunasMatriz2; indiceColuna++)
			printf("%.05lf   \t", matrizProduto[indiceLinha][indiceColuna]);
		
	
		printf("\n\n");
	}

return OK; 
}

/*$RCSfile$*/
