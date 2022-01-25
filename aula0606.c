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
#define __ISO_C_VISIBLE         1999
#define __LONG_LONG_SUPPORTED
#endif


#include "aula0601.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <limits.h>
#include <errno.h>

#define OK						                    0
#define NUMERO_ARGUMENTOS_INVALIDO			        1
#define ARGUMENTO_INVALIDO				            2
#define COMPRIMENTO_ARGUMENTO_INVALIDO			    3	
#define VALOR_MAXIMO_EXCEDIDO				        4
#define BASE_INVALIDA					            5
#define ARGUMENTO_NEGATIVO				            6

#define END_OF_STRING					            '\0'

int main(int argc, char* argv[])
{
    int indice;
    char* validacao;
    unsigned short numero, linha, coluna, ordem, numeroLinha, numeroColuna;
    unsigned long int numeroExcedido;
    double matriz[MAXIMO_LINHAS][MAXIMO_COLUNAS], cofator[0];

    if (argc < 8) /* O valor minimo da de entrada deve ser 1 + 3 (ordem, linha, coluna) + 4 (minimo uma matriz 2x2) */
    {
        printf("Uso: <numero-inteiro-nao-negativo> <numero-inteiro-nao-negativo> <numero-inteiro-nao-negativo> <numero-real> ... <numero-real> \n");
        exit(COMPRIMENTO_ARGUMENTO_INVALIDO);
    }

    for (indice = 1; indice < 4; indice++)
    {

        if (argv[indice][0] == '-')
        {
            printf("Argumento %d contem hifen.\n", indice);
            exit(ARGUMENTO_NEGATIVO);
        }

        numeroExcedido = strtoul(argv[indice], &validacao, 10);

        if (errno == EINVAL) /* base invalida */
        {
            printf("Base invalida.\n");
            exit(BASE_INVALIDA);
        }

        if (*validacao != END_OF_STRING)
        {
            printf("Argumento caractere invalido.\n");
            exit(ARGUMENTO_INVALIDO);
        }

        numero = (unsigned short)numeroExcedido;
        if (numero != numeroExcedido)
        {
            printf("Valor maximo para funcao excedido.\n");
            exit(VALOR_MAXIMO_EXCEDIDO);
        }

        if (indice == 1)
            ordem = numero;
        if (indice == 2)
            linha = numero;
        if (indice == 3)
            coluna = numero;
    }

    if (argc != 4 + ordem * ordem)
    {
        printf("Argumentos invalidos. \n");
        exit(ARGUMENTO_INVALIDO);
    }

    indice = 4;

    for (numeroLinha = 0; numeroLinha < ordem; numeroLinha++)
    {
        for (numeroColuna = 0; numeroColuna < ordem; numeroColuna++)
        {
            matriz[numeroLinha][numeroColuna] = strtod(argv[indice], &validacao);
            indice++;


            if (errno == EINVAL) /* base invalida */
            {
                printf("Base invalida.\n");
                exit(BASE_INVALIDA);
            }

            if (errno == ERANGE) /* valor maximo excedido */
            {
                printf("Valor maximo permitido (%lf) pela funcao foi excedido.\n", DBL_MAX);
                exit(VALOR_MAXIMO_EXCEDIDO);
            }

            if (*validacao != END_OF_STRING)
            {
                printf("Argumento caractere invalido.\n");
                exit(ARGUMENTO_INVALIDO);
            }
        }
    }

    printf(" ---- Matriz -----\n\n");
    for (numeroLinha = 0; numeroLinha < ordem; numeroLinha++)
    {
        for (numeroColuna = 0; numeroColuna < ordem; numeroColuna++)
            printf("%0.05lf   \t", matriz[numeroLinha][numeroColuna]);
        
        printf("\n\n");
    }

    CalcularComplementoAlgebrico(ordem, linha, coluna, matriz, cofator);
    printf("Elemento: %lf [%d][%d]\n", matriz[linha - 1][coluna - 1], linha, coluna);
    printf("Cofator = %lf\n", cofator[0]);

    return OK;
}

/* RCSfile$ */
