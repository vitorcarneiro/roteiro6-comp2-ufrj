/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Vitor Carneiro Silva de Oliveira
Descricao : Programa de teste para funcao CalcularDeterminante

$Author$
$Date$
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

#define MIN_NUMERO_ARGUMENTOS				3
#define EOS        							'\0'

int
main(int argc, char *argv[])
{
	unsigned long aux;
	char *verificacao;

  	unsigned indiceLinha, indiceColuna, indice, ordem;

	double matriz[MAXIMO_LINHAS][MAXIMO_COLUNAS], det;
	
	if(argc < MIN_NUMERO_ARGUMENTOS)
	{
		printf ("Uso: <numero-inteiro-nao-negativo> <numero-real> ... <numero-real> \n"); 
		exit(NUMERO_ARGUMENTOS_INVALIDO);
	}

    if (argv[1][0] == '-')
    {
        printf ("Caracter invalido: '-'\n");
        printf ("Ordem da matriz deve ser um valor positivo.\n");
        exit (ARGUMENTO_INVALIDO);	
    }

	/* Converte o argumento referente a linha da matriz*/
	aux = strtoul(argv[1], &verificacao, 10);
	ordem = (unsigned short) aux;

	if(*verificacao != EOS)
	{	
		printf ("Argumento 1 (ordem) contem caractere invalido. \n");
		printf ("Primeiro caractere invalido \'%c\'.\n", *verificacao);
		exit (ARGUMENTO_INVALIDO);
	}

	if(aux != ordem)
	{	
		printf("O valor para ordem da matriz deve ser no maximo %d (unsigned short)\n", USHRT_MAX);
		exit(ARGUMENTO_INVALIDO);
	}

    if (argc != 2 + ordem*ordem)
	{
		printf ("A ordem (%d) da matriz nao corresponde ao numero de elementos (%d).\n", ordem, argc - 2);
		exit (ARGUMENTO_INVALIDO);
	}
  
    indice = 2;
	for (indiceLinha = 0; indiceLinha < ordem; indiceLinha++)
		for (indiceColuna = 0; indiceColuna < ordem; indiceColuna++)
		{
			matriz[indiceLinha][indiceColuna] = strtod(argv[indice], &verificacao);
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
	

	printf("\n");
  	printf(" ---- Matriz -----\n\n");
	for (indiceLinha = 0; indiceLinha < ordem; indiceLinha++)
	{
		for (indiceColuna = 0; indiceColuna < ordem; indiceColuna++)
			printf("%.05lf   \t", matriz[indiceLinha][indiceColuna]);
		
		printf("\n\n");
	}
	
    CalcularDeterminanteMatriz(ordem, &matriz[0], &det);
    
	printf ("Determinante = %lf \n", det);

return OK; 
}

/*$RCSfile$*/
