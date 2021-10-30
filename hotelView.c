//interação com o usuário
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>

#include "hotelModel.h"
#include "hotelView.h"

char msgSituacao[3][11] = {"LIVRE","OCUPADO","RESERVADO"};
int i;
float taxaOcupacao, ocupados;

int opc = 0;
int andar, apto = 0;

char op;
//int n = 0; // controla a quantidade de hospedes no hotel

int menuHotel(){

    printf("\n(1) - Fazer o check-in\n"); //model
    printf("(2) - Fazer o check-out\n"); //model
    printf("(3) - Fazer reserva\n"); //model
    printf("(4) - Cancelar reserva\n"); //model

    printf("(5) - Mostrar a ocupação do hotel\n"); //view
    printf("(6) - Taxa de ocupação do hotel\n"); //view
    printf("(7) - Mostrar os Hospedes do Hotel\n"); //view
    printf("(8) - Sair do programa\n");
    printf("\nEntre com a opção: ");

    scanf("%d", &opc);

    return opc;

}
void entraQuarto(int op){

    opc = op;

    printf("Entre com o numero do andar (1 a 20): ");
    scanf("%d",&andar);
    printf("Entre com o nomero do apto (1 a 14): ");
    scanf("%d",&apto);

    funcionalidadesHospedes(andar, apto, opc);

}
void cancelarReserva(){

    char op;
    int i;
    bool achouReserva;
    char cpfReserva[15];

        printf("Entre com o CPF: ");

        while( (op = fgetc(stdin)) != EOF && op != '\n') {};
        fgets(cpfReserva,13,stdin);
        printf("Verificando a reserva....\n");

        achouReserva = false;

        for(i=0; i<n && !achouReserva; i++)
            if (strcmp(cpfReserva,hospedes[i].cpf) == 0)
                achouReserva = true;

        if (achouReserva)
        {
            if ((andar == hospedes[i-1].apartamento.andar) && (apto == hospedes[i-1].apartamento.numeroQuarto))
            {
                printf("Reserva cancelada!\n");
                hotel[andar-1][apto-1].situacao = LIVRE;
                hospedes[i-1].apartamento.situacao = LIVRE;
            }
        }
       else printf("Reserva não localizada! \n");
}

void mostrarOcupados(){
    for(andar = 0; andar < ANDARES; andar++){
        printf("Andar %2d\n", andar+1);
        for(apto = 0; apto < APTOS; apto++)
            printf("%s   ", msgSituacao[hotel[andar][apto].situacao]);
        printf("\n");
    }
}

void porcentagemOcupados(){

    for(andar = 0, ocupados = 0.0; andar < ANDARES; andar++)
        for(apto = 0; apto < APTOS; apto++)
            if (hotel[andar][apto].situacao == OCUPADO) ocupados++;

    taxaOcupacao = (ocupados/(ANDARES*APTOS))*100;
    printf("A taxa de ocupação do hotel é de : %.2f\n",taxaOcupacao);
}

void mostrarHospedes(){

    for(i=0; i<n; i++)
    {
        printf("Hospede #%d\n", i+1);
        printf("Nome: %s\n",hospedes[i].nome);
        printf("Email: %s \n",hospedes[i].email);
        printf("Situação do hospede: %s\n",msgSituacao[hotel[andar][apto].situacao]);
        printf("Andar %d e Apto %d\n",hospedes[i].apartamento.andar,hospedes[i].apartamento.numeroQuarto);
        printf("****************************************************************\n");
    }
}

