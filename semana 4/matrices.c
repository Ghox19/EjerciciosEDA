#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"
#include "Archivo.h"

int main(int argc,char* argv[]){
    FILE *fp_e;
    fp_e = abrir_archivo(argv[1],"r");
    int n1= elementos_matriz(fp_e);
    printf("%d",n1);
    return 0;
}