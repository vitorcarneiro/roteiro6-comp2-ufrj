
/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Vitor Carneiro Silva de Oliveira
Descricao : Codigo fonte funcao Multiplicar Matrizes

$Author$
$Date$
$Log$

*/

#include "aula0601.h"

tipoErros 
MultiplicarMatrizes(unsigned short numeroLinha1,
                    unsigned short numeroColunas1,
                    unsigned short numeroLinha2,
                    unsigned short numeroColunas2,
                    double matriz1[MAXIMO_LINHAS][MAXIMO_COLUNAS],
                    double matriz2[MAXIMO_LINHAS][MAXIMO_COLUNAS], 
                    double matrizProduto[MAXIMO_LINHAS][MAXIMO_COLUNAS])
{
	unsigned short indice, linha, coluna;
	
	for(linha = 0; linha < numeroLinha1; linha++)
		for(coluna = 0; coluna < numeroColunas2; coluna++)
		{
			matrizProduto[linha][coluna] = 0;
			
			for(indice = 0; indice < numeroColunas1; indice++)
				matrizProduto[linha][coluna] += matriz1[linha][indice] * matriz2[indice][coluna];
		}
			
    return ok;		
}