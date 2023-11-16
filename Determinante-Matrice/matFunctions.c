#include "matFunctions.h"
#include <math.h>


int mat2x2 (int v[][MAXDIM], int dim)
{
    int a1, a2, determinante;
    
    //Addendi
    a1 = v[0][0]*v[1][1];
    a2 = v[1][0]*v[0][1];
    
    determinante = a1 - a2;
    
    return determinante;
}

int mat3x3 (int v[][MAXDIM], int dim)
{
    int a1, a2, a3, a4, a5, a6;
    int determinante;
    
    //Addendi per calcolare determinante
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
    
    //Calcolo del Determinante con Formula di Laplace
    for (j = 0; j < dim; j++)
    {
        i = 0; //Scelgo sempre prima riga
        if (j == 0)//Cancello prima riga e prima colonna
        {
            detMinore = (v[1][1]*v[2][2]*v[3][3]) + (v[1][2]*v[2][3]*v[3][1]) + (v[1][3]*v[2][1]*v[3][2]) + (-(v[1][3]*v[2][2]*v[3][1])) + (-(v[1][1]*v[2][3]*v[3][2])) + (-(v[1][2]*v[2][1]*v[3][3]));
        }
        else if (j == 1)//Cancello prima riga e seconda colonna
        {
            detMinore = (v[1][0]*v[2][2]*v[3][3]) + (v[1][2]*v[2][3]*v[3][0]) + (v[1][3]*v[2][0]*v[3][2]) + (-(v[1][3]*v[2][2]*v[3][0])) + (-(v[1][0]*v[2][3]*v[3][2])) + (-(v[1][2]*v[2][0]*v[3][3]));
        }
        else if (j == 2)//Cancello prima riga e terza colonna
        {
            detMinore = (v[1][0]*v[2][1]*v[3][3]) + (v[1][1]*v[2][3]*v[3][0]) + (v[1][3]*v[2][0]*v[3][1]) + (-(v[1][3]*v[2][1]*v[3][0])) + (-(v[1][0]*v[2][3]*v[3][1])) + (-(v[1][1]*v[2][0]*v[3][3]));
        }
        else if (j == 3)//Cancello prima riga e quarta colonna
        {
            detMinore = (v[1][0]*v[2][1]*v[3][2]) + (v[1][1]*v[2][2]*v[3][0]) + (v[1][2]*v[2][0]*v[3][1]) + (-(v[1][2]*v[2][1]*v[3][0])) + (-(v[1][0]*v[2][2]*v[3][1])) + (-(v[1][1]*v[2][0]*v[3][2]));
        }
        determinante = determinante + (pow(-1, i + j))*v[i][j]*detMinore;
    }
    return determinante;
}

void inversa2x2 (int v[][MAXDIM], int dim, double matInversaDouble[][MAXDIM])
{
    int matInversaInt[MAXDIM][MAXDIM], i, j;
    
    //Coefficienti Standard della Matrice 2x2
    int *a = &matInversaInt[0][0], *b = &matInversaInt[0][1], *c = &matInversaInt[1][0], *d = &matInversaInt[1][1];
    
    //Coefficienti della Matrice inversa
    *a = v[1][1];
    *b = (-v[0][1]);
    *c = (-v[1][0]);
    *d = v[0][0];
    
    /*Calcolo Matrice Inversa: 
        1             |d  -b|
    ---------   *     |     |
     ad - cb          |-c  a|
    */
    
    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            matInversaDouble[i][j] = (double)(1.0/(double)((*a)*(*d) + (-(*b)*(*c))))*(double)matInversaInt[i][j];
        }
    }
    return;
}

