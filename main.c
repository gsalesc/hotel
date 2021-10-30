/* */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>

#include "hotelModel.h"
#include "hotelView.h"
#include "hotelController.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    inicializaController();
    return 0;
}


