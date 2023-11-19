#include <stdio.h>
#include "matFunctions.h"

int main (void)
{
    int v[MAXDIM][MAXDIM];
    int dimMat, i, j;
    
    printf("Inserisci la dimensione della matrice quadrata:\nOpzioni:\n- 1\n- 2\n- 3\n- 4\n");
    scanf("%d", &dimMat);

//Caso Matrice 1x1
    if (dimMat == 1)
        printf("Il determinante della matrice 1x1 è il numero stesso!");
//Caso Matrice 2x2
    else if (dimMat == 2)
    {
        for (i = 0; i < dimMat; i++) {
            printf("Inserisci i coefficienti della %d riga: \n", i+1);
            scanf("%d %d", &v[i][0], &v[i][1]);
        }
        printf("Il determinante della matrice è: %d\n\n", mat2x2(v, dimMat)); //Stampa del determinante della Matrice
        
        //Calcolo Inversa se det != 0
        if (mat2x2(v, dimMat) != 0)
        {
            double matInversa[MAXDIM][MAXDIM];
            
            printf("L'inversa della matrice è: \n"); //Stampa della Matrice Inversa
            inversa2x2(v, dimMat, matInversa);
            
            for (i = 0; i < dimMat; i++) 
            {
                for (j = 0; j < dimMat; j++){
                    printf("%.2lf ", matInversa[i][j]);
                }
                printf("\n");
            }
        }
    }
//Caso Matrice 3x3
    else if (dimMat == 3)
    {
        for (i = 0; i < dimMat; i++)
        {
            printf("Inserisci i coefficienti della %d riga: \n", i+1);
            scanf("%d %d %d", &v[i][0], &v[i][1], &v[i][2]);
        }
        printf("Il determinante della matrice è: %d\n", mat3x3(v, dimMat)); //Stampa del determinante della Matrice
        
        //Calcolo Matrice Trasposta
        int matTrasposta[MAXDIM][MAXDIM];
        
        printf("\nLa Matric trasposta è: \n");
        trasposta(v, dimMat, matTrasposta);
        
        for (i = 0; i < dimMat; i++) {
            for (j = 0; j < dimMat; j++) {
                printf("%5d ", matTrasposta[i][j]);
            }
            printf("\n");
        }
        //Calcolo Matrice Inversa
        if (mat3x3(v, dimMat) != 0)
        {
            double matInversa[MAXDIM][MAXDIM];
            
            printf("\nLa Matrice Inversa è: \n");
            inversa3x3(v, dimMat, matInversa);
            for (i = 0; i < dimMat; i++) {
                for (j = 0; j < dimMat; j++) {
                    printf("%5.2lf ", matInversa[i][j]);
                }
                printf("\n");
            }
        }
    }
//Caso Matrice 4x4
    else if (dimMat == 4)
    {
        for (i = 0; i < dimMat; i++)
        {
            printf("Inserisci i coefficienti della %d riga: \n", i+1);
            scanf("%d %d %d %d", &v[i][0], &v[i][1], &v[i][2], &v[i][3]);
        }
        printf("Il determinante della matrice è: %d\n", mat4x4(v, dimMat)); //Stampa del determinante della Matrice
    }
    else
        printf("Dimensione della matrice non valida");
}
