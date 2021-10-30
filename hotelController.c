#include <stdio.h>
#include <stdbool.h>

#include "hotelView.h"
#include "hotelModel.h"
#include "hotelController.h"

void inicializaController(){

    int opcao;
    bool fim = false; // sentinela que controla o fim do programa

    inicializaQuartos();
    do
    {
        opcao = menuHotel();
        bool entradaValida = false; // sentinela que controla se a entrada � v�lida ou n�o

        switch (opcao)
        {

        case 1: // Op��o de check-in
            do
            {
               entraQuarto(opcao);
               entradaValida = true;

            }
            while (!entradaValida);
            break;

        case 2:  // op��o de check-out
            do
            {
               entraQuarto(opcao);
               entradaValida = true;
            }
            while (!entradaValida);

            break;

        case 3:  // op��o de fazer reserva de apto
            do
            {
               entraQuarto(opcao);
               entradaValida = true;
            }
            while (!entradaValida);

            break;

        case 4:  //TO-DO: Funcionalidade de Cancelar reserva
            cancelarReserva();
            break;

        case 5:
            mostrarOcupados();
            break;

        case 6:
            porcentagemOcupados();
            break;

        case 7:
            mostrarHospedes();
            break;

        case 8:
            fim = true;
            break;

        default:
            printf("Opc�o do menu invalida\n");
        }
    }
    while (!fim);

}
