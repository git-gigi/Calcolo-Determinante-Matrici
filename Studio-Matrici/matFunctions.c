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
    int determinante = 0, i, j;
    int matCompleta[MAXDIM][5];
    
    //Calcolo Matrice Completa
    for (i = 0; i < dim; i++) {
        for (j = 0; j < 2*dim - 1; j++) {
            if (j < dim)
                matCompleta[i][j] = v[i][j];
            else if (j >= dim)
                matCompleta[i][j] = v[i][j-dim];
        }
    }
    
    // Calcolo Determinante
    i = 0;
    for (j = 0; j < 2*dim -1; j++) {
        if (j < dim)
            determinante = determinante + (matCompleta[i][j]*matCompleta[i+1][j+1]*matCompleta[i+2][j+2]);
        if (j >= dim - 1)
            determinante = determinante - (matCompleta[i][j]*matCompleta[i+1][j-1]*matCompleta[i+2][j-2]);
    }
    
    return determinante;
}

int mat4x4 (int v[][MAXDIM], int dim)
{
    int i = 0, j, k = 0, s = 0, determinante = 0, detMinore = 0;
    int N[MAXDIM][MAXDIM] = {0};
    
    //Calcolo del Determinante con Formula di Laplace
    for (j = 0; j < dim; j++)
    {
        i = 0; //Scelgo sempre prima riga
        if (j == 0)//Cancello prima riga e prima colonna
        {
            //Calcolo il Minore Complementare
             for (k = 1; k < dim; k++)
             {
                for (s = 1; s < dim; s++)
                {
                    N[k-1][s-1] = v[k][s];
                }
             }
            detMinore = mat3x3 (N, dim - 1);

        }
        else if (j == 1)//Cancello prima riga e seconda colonna
        {
            //Calcolo il Minore Complementare
             for (k = 1; k < dim; k++)
             {
                for (s = 0; s < dim; s++)
                {
                    if (s < 1)
                        N[k-1][s] = v[k][s];
                    else if (s > 1)
                        N[k-1][s-1] = v[k][s];
                }
             }
             detMinore = mat3x3 (N, dim - 1);
        }
        else if (j == 2)//Cancello prima riga e terza colonna
        {
            //Calcolo il Minore Complementare
             for (k = 1; k < dim; k++)
             {
                 for (s = 0; s < dim; s++)
                {
                    if (s < 2)
                        N[k-1][s] = v[k][s];
                    else if (s > 2)
                        N[k-1][s-1] = v[k][s];
                }
             }
             detMinore = mat3x3 (N, dim - 1);


        }
        else if (j == 3)//Cancello prima riga e quarta colonna
        {
            //Calcolo il Minore Complementare
             for (k = 1; k < dim; k++)
             {
                 for (s = 0; s < dim; s++)
                {
                    if (s < 3)
                        N[k-1][s] = v[k][s];
                    else if (s > 3)
                        N[k-1][s-1] = v[k][s];
                }
             }
             detMinore = mat3x3 (N, dim - 1);
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

void trasposta (int v[][MAXDIM], int dim, int matTrasposta[][MAXDIM])
{
    int i, j;
    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            matTrasposta[j][i] = v[i][j];
        }
    }
    return;
}

void inversa3x3 (int v[][MAXDIM], int dim, double matInversaDouble[][MAXDIM])
{
    int i, j, k, s;
    int A; //Cofattore
    int detMinore = 0;
    int N[MAXDIM][MAXDIM] = {0}; //Minore complementare
    int matCofattori[MAXDIM][MAXDIM]; //Matrice dei Cofattori
    int matTraspCofattori[MAXDIM][MAXDIM]; //Matrice Trasposta dei Cofatto
    
    
    for (i = 0; i < dim; i++) 
    {
        for (j = 0; j < dim; j++)
        {
            if (i == 0) 
            {
                if (j == 0)//Cancello riga prima e prima colonna
                {
                    //Calcolo il Minore Complementare
                    for (k = 1; k < dim; k++)
                    {
                        for (s = 1; s < dim; s++)
                        {
                            N[k-1][s-1] = v[k][s];
                        }
                    }
                    detMinore = mat2x2(N, dim - 1);
                    
                }
                else if (j == 1)//Cancello prima riga e seconda colonna
                {
                    //Calcolo il Minore Complementare
                    for (k = 1; k < dim; k++)
                    {
                        for (s = 0; s < dim; s++)
                        {
                            if (s < 1)
                                N[k-1][s] = v[k][s];
                            else if (s > 1)
                                N[k-1][s-1] = v[k][s];
                        }
                    }
                    detMinore = mat2x2(N, dim - 1);
                }
                else if (j == 2)//Cancello prima riga e terza colonna
                {
                    //Calcolo il Minore Complementare
                    for (k = 1; k < dim; k++)
                    {
                        for (s = 0; s < dim; s++)
                        {
                            if (s < 2)
                                N[k-1][s] = v[k][s];
                        }
                    }
                    detMinore = mat2x2 (N, dim - 1);
                }
            }
            else if (i == 1)
            {
                if (j == 0)//Cancello seconda riga e prima colonna
                {
                    //Calcolo il Minore Complementare
                    for (k = 0; k < dim; k++)
                    {
                        if (k < 1) {
                            for (s = 1; s < dim; s++){
                                N[k][s-1] = v[k][s];
                            }
                        }
                        else if (k > 1)
                        {
                            for (s = 1; s < dim; s++){
                                N[k-1][s-1] = v[k][s];
                            }
                        }
                    }
                    detMinore = mat2x2(N, dim - 1);
                }
                else if (j == 1)//Cancello seconda riga e seconda colonna
                {
                    //Calcolo il Minore Complementare
                    for (k = 0; k < dim; k++)
                    {
                        if (k < 1) {
                            for (s = 0; s < dim; s++){
                                if (s < 1)
                                    N[k][s] = v[k][s];
                                else if (s > 1)
                                    N[k][s-1] = v[k][s];
                            }
                        }
                        else if (k > 1)
                        {
                            for (s = 0; s < dim; s++){
                                if (s < 1)
                                    N[k-1][s] = v[k][s];
                                else if (s > 1)
                                    N[k-1][s-1] = v[k][s];
                            }
                        }
                    }
                    detMinore = mat2x2(N, dim - 1);
                }
                else if (j == 2)//Cancello seconda riga e terza colonna
                {
                    //Calcolo il Minore Complementare
                    for (k = 0; k < dim; k++)
                    {
                        if (k < 1) {
                            for (s = 0; s < dim; s++){
                                if (s < 2)
                                    N[k][s] = v[k][s];
                            }
                        }
                        else if (k > 1)
                        {
                            for (s = 0; s < dim; s++){
                                if (s < 2)
                                    N[k-1][s] = v[k][s];
                            }
                        }
                    }
                    detMinore = mat2x2 (N, dim - 1);
                }
            }
            else if (i == 2)
            {
                if (j == 0)//Cancello terza riga e prima colonna
                {
                    //Calcolo il Minore Complementare
                    
                    for (k = 0; k < dim; k++)
                    {
                        if (k < 2) {
                            for (s = 1; s < dim; s++)
                            {
                                N[k][s-1] = v[k][s];
                            }
                        }
                    }
                    detMinore = mat2x2(N, dim - 1);
                    
                }
                else if (j == 1)//Cancello terza riga e seconda colonna
                {
                    //Calcolo il Minore Complementare
                    for (k = 0; k < dim; k++)
                    {
                        if (k < 2) {
                            for (s = 0; s < dim; s++)
                            {
                                if (s < 1)
                                    N[k][s] = v[k][s];
                                else if (s > 1)
                                    N[k][s-1] = v[k][s];
                            }
                        }
                    }
                    detMinore = mat2x2(N, dim - 1);
                }
                else if (j == 2)//Cancello terza riga e terza colonna
                {
                    //Calcolo il Minore Complementare
                    for (k = 0; k < dim; k++)
                    {
                        if (k < 2) {
                            for (s = 0; s < dim; s++)
                            {
                                if (s < 2)
                                    N[k][s] = v[k][s];
                            }
                        }
                    }
                    detMinore = mat2x2 (N, dim - 1);
                }
            }
            A = (pow(-1, (i+1) + (j+1)))*detMinore;
            matCofattori[i][j] = A;
        }
    }
    
    trasposta(matCofattori, dim, matTraspCofattori);
    
    for (i = 0; i < dim; i++)
    {
        for (j = 0; j < dim ; j++) 
        {
            matInversaDouble[i][j] = (double)matTraspCofattori[i][j]/(double)(mat3x3(v, dim));
        }
    }
        
}

void autovalori (int v[][MAXDIM], int dim, double* lamda1, double* lamda2)
{
    int a, b, c, d; //Valori della matrice
    int A, B, C; // Coefficienti della forma AX^2 + BX + C
    
    a = v[0][0];
    b = v[0][1];
    c = v[1][0];
    d = v[1][1];
    
    A = 1;
    B = (-(a+d));
    C = ((a*d) - (b*c));
    
    *lamda1 = (double)(-B + sqrt(pow(B, 2) - (4*A*C)))/(double)2*A;
    *lamda2 = (double)(-B - sqrt(pow(B, 2) - (4*A*C)))/(double)2*A;

    
/*      
        Schema Risolutivo per trovare gli autovalori
        (a-lamda) * (d - lambda) - bc --> Determinante della matrice caratteristica 2x2
            
        ad - a*lamda - d*lamda + lamda^2 - bc = 0;
 
        lamda^2 - lamda(a+d) +ad -bc = 0
 
        A = 1;
        B = -(a+d)
        C = ad - bc
 
        lamda1 = (B + sqrt(B^2 - 4*A*C))/2A
        lamda2 = (B - sqrt(B^2 - 4*A*C))/2A
*/
}

