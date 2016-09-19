#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#define TALLA 20


using namespace std;


int contar_caracteres(char arr[]){
	int n=0;
	while( arr[n] != '\0' ) 
		n++;
	return n;
}

void sumar_binario(char mayor[], char menor[], char resultado[]){
	bool E = false;

	int nMayor, nMenor;
	nMayor = contar_caracteres(mayor)-1;
	nMenor = contar_caracteres(menor)-1;
	resultado[nMayor+2]  = '\0';
	resultado[0]  = '0';
	
	while(nMenor >= 0){

		if(mayor[nMayor] == menor[nMenor]){
			if(mayor[nMayor] == '1'){
				if(E == true)
					resultado[nMayor+1] = '1';
				else{
					resultado[nMayor+1] = '0';
					E = true;
				}

			}
			else{
				if(E == true){
					resultado[nMayor+1] = '1';
					E = false;
				}
				else
					resultado[nMayor+1] = '0';
			}
	
		}
		else{
			if(E == true){
				resultado[nMayor+1] = '0';
			}
			else{
				resultado[nMayor+1] = '1';
			}
		}

	nMayor--; nMenor--;
			
	}

	

	while( nMayor >= 0 ){
		if(E == true)
			if( mayor[nMayor] == '1')
				resultado[nMayor+1]  = '0';
			else{
				resultado[nMayor+1]  = '1';
				E = false;
			}
		else
			resultado[nMayor+1]  = mayor[nMayor];

		nMayor--; nMenor--;
	}

	if( E == true )
		resultado[0]  = '1';

}


void comprobar_mayor(char valorA[], char valorB[],char resultado[]){
	
	if( contar_caracteres(valorA) > contar_caracteres(valorB) )
		sumar_binario(valorA, valorB, resultado);
	else
		sumar_binario(valorB, valorA, resultado);

}

void mostrar(char arr[]){
	int n;
	n = contar_caracteres(arr);
	for(int i = 0; i < n ; i++)
		cout << arr[i];
	cout << endl;
}


int main(int argc, char const *argv[])
{
	
	
	char valorA[TALLA],valorB[TALLA], resultado[TALLA];

	cout << "Ingrese valores de A: "; cin >> valorA;
	cout << "Ingrese valores de B: "; cin >> valorB;

	comprobar_mayor(valorA,valorB, resultado);

	mostrar(resultado);


	return 0;
}

