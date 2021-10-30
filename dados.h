#ifndef DADOS_H_INCLUDED
#define DADOS_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef enum status {LIVRE,OCUPADO,RESERVADO} tipoStatusApto;

typedef struct Apartamento
{
    int andar;
    int numeroQuarto;
    tipoStatusApto situacao;
} tipoApartamento;

typedef struct Hospede
{
    char nome[60];
    char endereco[100];
    char telefone[20];
    char cpf[13];
    int idade;
    char email[40];
    tipoApartamento apartamento;
} tipoHospede;

tipoHospede hospedes[MAXHOTEL];
tipoApartamento hotel[20][14];

int andar, apto;
char op;
char msgSituacao[3][11] = {"LIVRE","OCUPADO","RESERVADO"};
int andar, apto;
int n = 0; // controla a quantidade de hospedes no hotel
int opcao, i;
bool fim = false;  // sentinela que controla o fim do programa
bool entradaValida; // sentinela que controla se a entrada é válida ou não
float taxaOcupacao, ocupados;

#endif // DADOS_H_INCLUDED
