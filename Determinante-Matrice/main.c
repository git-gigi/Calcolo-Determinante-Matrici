#include <stdio.h>
#include "matFunctions.h"

int main (void)
{
    int v[MAXDIM][MAXDIM];
    int dimMat;
    
    printf("Inserisci la dimensione della matrice quadrata: \n- 1\n- 2\n- 3\n- 4\n");
    scanf("%d", &dimMat);
    
    if (dimMat == 1)
        printf("Il determinante della matrice 1x1 è il numero stesso!");
    else if (dimMat == 2) //Caso Matrice 2x2
        printf("Il determinante della matrice è: %d\n", mat2x2(v, dimMat));
    else if (dimMat == 3) //Caso Matrice 3x3
        printf("Il determinante della matrice è: %d\n", mat3x3(v, dimMat));
    else if (dimMat == 4)
        printf("Il determinante della matrice è: %d\n", mat4x4(v, dimMat));
    else
        printf("Dimensione della matrice non valida");
}
