#ifndef matFunctions_h
#define matFunctions_h

#include <stdio.h>
#define MAXDIM 4
int mat2x2 (int v[][MAXDIM], int dim);
int mat3x3 (int v[][MAXDIM], int dim);
int mat4x4 (int v[][MAXDIM], int dim);
void inversa2x2 (int v[][MAXDIM], int dim, double matInversaDouble[][MAXDIM]);

#endif 
