/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Vitor Carneiro Silva de Oliveira
Descricao: Prototipo da funcao MultiplicarMatrizes

$Author$ 
$Date$ 
$Log$

*/

#ifndef _AULA0601_
#define _AULA0601_                              "@(#)aula0601.h $Revision$"

#define MAXIMO_LINHAS                           100
#define MAXIMO_COLUNAS                          100

typedef enum
{
	ok,
	matrizInvalida,
	comprimentoExcedido
}tipoErros;

tipoErros
MultiplicarMatrizes(unsigned short, /* numero de linhas da matriz 1 (E) */
                    unsigned short, /* numero de colunas da matriz 1 (E) */
                    unsigned short, /* numero de linhas da matriz 2 (E) */
                    unsigned short, /* numero de colunas da matriz 2 (E) */
                    double [MAXIMO_LINHAS][MAXIMO_COLUNAS], /* matriz 1 (E) */
                    double [MAXIMO_LINHAS][MAXIMO_COLUNAS], /* matriz 2 (E) */
                    double [MAXIMO_LINHAS][MAXIMO_COLUNAS]); /* matriz produto (S) */

tipoErros
ObterMatrizTransposta (unsigned short, /* numero de linhas da matriz original (E) */
                        unsigned short, /* numero de colunas da matriz original (E) */
                        double[MAXIMO_LINHAS][MAXIMO_COLUNAS], /* matriz original (E) */
                        double[MAXIMO_LINHAS][MAXIMO_COLUNAS]); /* matriz transposta (S) */

#endif 

/*$RCSfile$*/
