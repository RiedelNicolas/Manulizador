#include "stdio.h"
#include "string.h"
#include "stdbool.h"

void manulizar(FILE* entrada, FILE* salida);

int main(int argc,char *argv[]){

	if(argc !=2 ){
		printf("\n cantidad de argumentos es invalida \n");
		return -1;
	}

	FILE* entrada = fopen(argv[1],"r");
	if(entrada == NULL){
		printf("No existe el archivo");
		return -1;
	}

	char aux [5];
	strcpy(aux,".temp");
	FILE* salida  = fopen(aux,"w");

	//la cosa a testear
	manulizar(entrada, salida);

	fclose(salida); fclose(entrada);
	remove(argv[1]);
	rename(aux,argv[1]);
	printf("\n el archivo %s  fue correctamente manulizado \n",argv[1] );
	return 0;
}

/*Recibe un archivo abierto y lo pasa a idioma Manu
*/
void manulizar(FILE* entrada, FILE* salida){
	char caracter = getc(entrada);
	while(caracter != EOF){
		if(caracter =='a' || caracter =='e' || caracter =='o' || caracter =='u'){
			caracter = 'i';	
		}
		if(caracter =='A' || caracter =='E' || caracter =='O' || caracter =='U' ){
			caracter = 'I';
		}
		putc(caracter,salida);
		caracter = getc(entrada);
	}
}