#include "matFunctions.h"
#include <math.h>

int mat2x2 (int v[][MAXDIM], int dim)
{
    int a1, a2, determinante, i;
    for (i = 0; i < dim; i++) {
        printf("Inserisci i coefficienti della %d riga: \n", i+1);
        scanf("%d %d", &v[i][0], &v[i][1]);
    }
    
    //Addendi
    a1 = v[0][0]*v[1][1];
    a2 = v[1][0]*v[0][1];
    
    determinante = a1 - a2;
    
    return determinante;
}

int mat3x3 (int v[][MAXDIM], int dim)
{
    int a1, a2, a3, a4, a5, a6;
    int i, determinante;
   
    for (i = 0; i < dim; i++)
    {
        printf("Inserisci i coefficienti della %d riga: \n", i+1);
        scanf("%d %d %d", &v[i][0], &v[i][1], &v[i][2]);
    }
    
    //Addendi
    a1 = v[0][0]*v[1][1]*v[2][2];
    a2 = v[0][1]*v[1][2]*v[2][0];
    a3 = v[0][2]*v[1][0]*v[2][1];
    a4 = v[0][2]*v[1][1]*v[2][0];
    a5 = v[0][0]*v[1][2]*v[2][1];
    a6 = v[0][1]*v[1][0]*v[2][2];
    
    determinante = a1 + a2 + a3 + (-a4) + (-a5) + (-a6);
    
    return determinante;
}

int mat4x4 (int v[][MAXDIM], int dim)
{
    int i = 0, j, determinante = 0, detMinore = 0;
   
    for (i = 0; i < dim; i++)
    {
        printf("Inserisci i coefficienti della %d riga: \n", i+1);
        scanf("%d %d %d %d", &v[i][0], &v[i][1], &v[i][2], &v[i][3]);
    }
    
    for (j = 0; j < dim; j++)
    {
        i = 0; //Scelgo sempre prima riga
        if (j == 0)
        {
            detMinore = (v[1][1]*v[2][2]*v[3][3]) + (v[1][2]*v[2][3]*v[3][1]) + (v[1][3]*v[2][1]*v[3][2]) + (-(v[1][3]*v[2][2]*v[3][1])) + (-(v[1][1]*v[2][3]*v[3][2])) + (-(v[1][2]*v[2][1]*v[3][3]));
        }
        else if (j == 1)
        {
            detMinore = (v[1][0]*v[2][2]*v[3][3]) + (v[1][2]*v[2][3]*v[3][0]) + (v[1][3]*v[2][0]*v[3][2]) + (-(v[1][3]*v[2][2]*v[3][0])) + (-(v[1][0]*v[2][3]*v[3][2])) + (-(v[1][2]*v[2][0]*v[3][3]));
        }
        else if (j == 2)
        {
            detMinore = (v[1][0]*v[2][1]*v[3][3]) + (v[1][1]*v[2][3]*v[3][0]) + (v[1][3]*v[2][0]*v[3][1]) + (-(v[1][3]*v[2][1]*v[3][0])) + (-(v[1][0]*v[2][3]*v[3][1])) + (-(v[1][1]*v[2][0]*v[3][3]));
        }
        else if (j == 3)
        {
            detMinore = (v[1][0]*v[2][1]*v[3][2]) + (v[1][1]*v[2][2]*v[3][0]) + (v[1][2]*v[2][0]*v[3][1]) + (-(v[1][2]*v[2][1]*v[3][0])) + (-(v[1][0]*v[2][2]*v[3][1])) + (-(v[1][1]*v[2][0]*v[3][2]));
        }
        determinante = determinante + (pow(-1, i + j))*v[i][j]*detMinore;
    }
    return determinante;
}
