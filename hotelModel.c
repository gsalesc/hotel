//funcionalidades
#include <string.h>
#include <stdio.h>
#include "hotelModel.h"

char op;
int i;
bool achouReserva;
char cpfReserva[15];


void inicializaQuartos(){
    for(int andar = 0; andar < ANDARES; andar++)
    {
        for(int apto = 0; apto < APTOS; apto++)
        {
            hotel[andar][apto].situacao = LIVRE; // marca os aparamentos como livres
            hotel[andar][apto].numeroQuarto = apto+1;
            hotel[andar][apto].andar = andar+1;
        }
    }
}

void funcionalidadesHospedes(int and, int apt, int opc){

    int andar = and;
    int apto = apt;
    int op = opc;


    if (op == 1){
        verificaQuarto(andar, apto, opc);
    }

    else if(op == 2){
        fazerCheckOut(andar, apto, opc);
    }

    else if (op == 3){
        fazerCheckInReserva(andar, apto, opc);
    }
}

void cadastrarCliente(int x, int and, int apt){

    int andar, apto, opcao;
    andar = and;
    apto = apt;
    opcao = x;

    //int n = qtdHosp;
    char op;

    printf("*****************************************************\n");

    printf("Entre com as informações do hóspede\n");
    printf("Entre com o nome: ");

    while( (op = fgetc(stdin)) != EOF && op != '\n') {};
    fgets(hospedes[n].nome,60,stdin);

    printf("Entre com o CPF: ");
    fgets(hospedes[n].cpf,13,stdin);

    printf("Entre com o endereço: ");
    fgets(hospedes[n].endereco,100,stdin);

    printf("Entre com o telefone: ");
    fgets(hospedes[n].telefone,20,stdin);

    printf("Entre com o email: ");
    fgets(hospedes[n].email,40,stdin);

    printf("Entre com a idade: ");
    scanf("%d",&hospedes[n].idade);

    if(opcao == 1){
        hospedes[n].apartamento = hotel[andar-1][apto-1]; // atribui o quarto para o hospede;
        hotel[andar-1][apto-1].situacao = OCUPADO; // aloca o quarto para o hospede
        hospedes[n].apartamento = hotel[andar-1][apto-1];
        printf("Apartamento %d do andar %d foi alocado com sucesso!\n",apto,andar);

    }
    else if(opcao == 3){
        hospedes[n].apartamento = hotel[andar-1][apto-1]; // atribui o quarto para o hospede;
        hotel[andar-1][apto-1].situacao = RESERVADO; // aloca o quarto para o hospede
        hospedes[n].apartamento = hotel[andar-1][apto-1];
        printf("Apartamento %d do andar %d foi reservado com sucesso!\n",apto,andar);

    }
}

void verificarReserva(int and, int apt){

    int andar, apto, n;
    andar = and;
    apto = apt;

    if (hotel[andar-1][apto-1].situacao == OCUPADO){ // verifica se quarto está ocupado ou não

        printf("O apartamento %d do andar %d está ocupado!\n",apto,andar);
        achouReserva = false;
    }
    else{

      if (hotel[andar-1][apto-1].situacao == RESERVADO)
      {
        printf("Entre com o CPF: ");

        while( (op = fgetc(stdin)) != EOF && op != '\n') {}; //limpa teclado
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
                printf("Reserva localizada e apto alocado para o hospede!\n");
                hotel[andar-1][apto-1].situacao = OCUPADO;
                hospedes[i-1].apartamento.situacao = OCUPADO;
            }
        }
       else printf("Reserva não localizada! \n");
    }
    }
}

void verificaQuarto(int andar, int apto, int op){

    int opcao = op;

    if ((andar >= 1 && andar <= ANDARES) && (apto >= 1 && apto <= APTOS))
    {
        if (hotel[andar-1][apto-1].situacao == OCUPADO) // verifica se quarto está ocupado ou já reservado
            printf("\nO quarto está ocupado ou reservado!");

        else if (hotel[andar-1][apto-1].situacao == RESERVADO)
        {
            verificarReserva(andar, apto);
        }
        else
        {
            cadastrarCliente(opcao, andar, apto);
            n++; // atualização do contador de hospedes
        }
    }
    else printf("O numero do quarto e/ou andar está inválido!\n");
}


void fazerCheckOut(int andar, int apto, int op){

        if ((andar >= 1 && andar <= ANDARES) && (apto >= 1 && apto <= APTOS))
        {
            if (hotel[andar-1][apto-1].situacao == OCUPADO)   // verifica se quarto está ocupado ou não
            {
                hotel[andar-1][apto-1].situacao = LIVRE; // desaloca o quarto

                printf("Apartamento %d do andar %d foi desalocado com sucesso!\n",apto,andar);
                n--;
            }
            else
                printf("O apartamento %d do andar %d está livre ou reservado!\n",apto,andar);
        }
        else
            printf("O numero do quarto e/ou andar está inválido!\n");

}

void fazerCheckInReserva(int andar, int apto, int op){

        int opcao = op;

        if ((andar >= 1 && andar <= ANDARES) && (apto >= 1 && apto <= APTOS))
        {
            if (hotel[andar-1][apto-1].situacao == OCUPADO || hotel[andar-1][apto-1].situacao == RESERVADO) // verifica se quarto está ocupado ou já reservado
                printf("O apartamento %d do andar %d está ocupado ou reservado!\n",apto,andar);

            else
            {
                cadastrarCliente(opcao, andar, apto);
                n++;
            }
        }
        else printf("O numero do quarto e/ou andar está inválido!\n");
}
