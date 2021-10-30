#ifndef HOTELMODEL_H_INCLUDED
#define HOTELMODEL_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define ANDARES 20
#define APTOS 14
#define MAXHOTEL 280

int n;

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

void inicializaQuartos();

void cadastrarCliente(int x, int and, int apt);

void verificaQuarto(int andar, int apto, int op);

void fazerCheckOut(int andar, int apto, int op);

void fazerCheckInReserva(int andar, int apto, int op);

void funcionalidadesHospedes(int and, int apt, int op);

void verificarReserva(int andar, int apto);

//checkout

#endif // HOTELMODEL_H_INCLUDED
