/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Vitor Carneiro Silva de Oliveira
Descricao : Codigo fonte funcao MultiplicarMatrizes - ObterMatrizTransposta

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

	for (linha = 0; linha < numeroLinha1; linha++)
		for (coluna = 0; coluna < numeroColunas2; coluna++)
		{
			matrizProduto[linha][coluna] = 0;

			for (indice = 0; indice < numeroColunas1; indice++)
				matrizProduto[linha][coluna] += matriz1[linha][indice] * matriz2[indice][coluna];
		}

	return ok;
}

tipoErros
ObterMatrizTransposta(unsigned short numeroLinhas,
	unsigned short numeroColunas,
	double matrizOriginal[MAXIMO_LINHAS][MAXIMO_COLUNAS],
	double matrizTransposta[MAXIMO_LINHAS][MAXIMO_COLUNAS])
{
	unsigned short indiceLinha, indiceColuna;

	if (numeroLinhas > MAXIMO_LINHAS || numeroColunas > MAXIMO_COLUNAS)
		return comprimentoExcedido;

	for (indiceLinha = 0; indiceLinha < numeroLinhas; indiceLinha++)
		for (indiceColuna = 0; indiceColuna < numeroColunas; indiceColuna++)
			matrizTransposta[indiceColuna][indiceLinha] = matrizOriginal[indiceLinha][indiceColuna];

	return ok;
}

tipoErros
CalcularDeterminanteMatriz(unsigned short ordem,
	double matriz[MAXIMO_LINHAS][MAXIMO_COLUNAS],
	double* determinante)
{

	int cont1, cont2;
	double det = 0, dP = 0, dS = 0, diagonaisPrincipais = 1, diagonaisSecundarias = 1;
	double cofator[0];

	if (ordem > MAXIMO_LINHAS)
		return comprimentoExcedido;

	if (ordem == 1)
		det = matriz[0][0];

	if (ordem == 2)
	{
		det = 0;
		det = matriz[0][0] * matriz[1][1] - matriz[1][0] * matriz[0][1];
	}

	if (ordem == 3) /* Calculadora pela regra de Sarrus */
	{
		for (cont1 = 0; cont1 < ordem; cont1++)
		{
			for (cont2 = 0; cont2 < ordem; cont2++)
			{
				diagonaisPrincipais *= matriz[(cont2 + cont1) % 3][cont2];
				diagonaisSecundarias *= matriz[(-cont2 + cont1 + 2) % 3][cont2];
			}

			dP += diagonaisPrincipais;
			dS += diagonaisSecundarias;
			diagonaisPrincipais = 1;
			diagonaisSecundarias = 1;
		}

		det = dP - dS; /* Soma das diagonais princiapsis menos a soma das diagonais secundarias */
	}

	if (ordem > 3)
	{
		for (cont1 = 1; cont1 <= ordem; cont1++)
		{
			CalcularComplementoAlgebrico(ordem, cont1, 1, matriz, cofator);
			det += cofator[0] * matriz[cont1 - 1][0];
		}
	}

	*determinante = det;

	return ok;
}

tipoErros
CalcularMenorComplementar(unsigned short ordem,
	unsigned short linha, unsigned short coluna,
	double matriz[MAXIMO_LINHAS][MAXIMO_COLUNAS],
	double* menorComplementar)
{
	double matrizR[MAXIMO_LINHAS][MAXIMO_COLUNAS];
	unsigned short indiceLinha, indiceColuna;

	linha = linha - 1;
	coluna = coluna - 1;

	for (indiceLinha = 0; indiceLinha < ordem; indiceLinha++)
		for (indiceColuna = 0; indiceColuna < ordem; indiceColuna++)
		{
			if (indiceLinha < linha)
			{
				if (indiceColuna < coluna)
					matrizR[indiceLinha][indiceColuna] = matriz[indiceLinha][indiceColuna];

				else
				{
					if (indiceColuna > coluna)
						matrizR[indiceLinha][indiceColuna - 1] = matriz[indiceLinha][indiceColuna];
				}
			}

			if (indiceLinha > linha)
			{
				if (indiceColuna < coluna)
					matrizR[indiceLinha - 1][indiceColuna] = matriz[indiceLinha][indiceColuna];
				else
				{
					if (indiceColuna > coluna)
						matrizR[indiceLinha - 1][indiceColuna - 1] = matriz[indiceLinha][indiceColuna];
				}
			}
		}

	CalcularDeterminanteMatriz(ordem - 1, matrizR, menorComplementar);

	return ok;
}


tipoErros CalcularComplementoAlgebrico(unsigned short ordem,
	unsigned short linha,
	unsigned short coluna,
	double matriz[MAXIMO_LINHAS][MAXIMO_COLUNAS],
	double* cofator)
{
	double menorComplementar[1];

	CalcularMenorComplementar(ordem, linha, coluna, matriz, menorComplementar);

	unsigned short soma = 0;
	soma = linha + coluna;

	if (soma % 2 == 0)
		*cofator = 1;
	else
		*cofator = -1;

	*cofator = menorComplementar[0] * cofator[0];

	return ok;
}
