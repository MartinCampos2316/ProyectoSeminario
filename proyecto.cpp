#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

void pedirDatos();
void imprimirDatos(int **,int);
int calcularArea(int **,int);
void eliminarMemoria(int **,int);

int **puntero_matriz,puntos,a,b;

int main(){
	cout<<"";
	cout<<"Bienvenidos a Geo-ce:"<<endl;
	cout<<"Este es un programa que calcula el area de tu poligono en R^2"<<endl;
	cout<<"Presiona enter para continuar: "<<endl;
	cout<<endl;
	cout<<endl;
	getch();
	pedirDatos();
	imprimirDatos(puntero_matriz,puntos);
	cout<<"El area de tu figura en el plano cartesiano es: "<<calcularArea(puntero_matriz,puntos);
	eliminarMemoria(puntero_matriz,puntos);
	return 0;
}

void pedirDatos(){
	cout<<"Cuantos pares de puntos tiene su figura? "<<endl;
	cout<<"Respuesta: ";
	cin>>puntos;
	puntero_matriz = new int*[puntos+1];
	for(int i= 0;i<puntos+1;i++){
		puntero_matriz[i] = new int[2];
	}
	for(int i=0;i<puntos;i++){	
		cout<<"Ingrese X["<<i+1<<"]: ";
		cin>>*(*(puntero_matriz+i));
		cout<<"Ingrese Y["<<i+1<<"]: ";
		cin>>*(*(puntero_matriz+i)+1);
		cout<<endl;
		}
		*(*(puntero_matriz+puntos)) = *(*(puntero_matriz));
		*(*(puntero_matriz+puntos)+1) = *(*(puntero_matriz)+1);
	}
	
void imprimirDatos(int **puntero_matriz,int puntos){
	cout<<endl;
	cout<<"Imprimiendo Matriz: "<<endl;
	cout<<"       Matriz"<<endl;
	for(int i=0;i<puntos+1;i++){
		cout<<"      |";
		for(int j=0;j<2;j++){
			cout<<" "<<*(*(puntero_matriz+i)+j)<<" ";
		}
		cout<<"|";
		cout<<endl;
	}
		cout<<endl;
}

int calcularArea(int **puntero_matriz,int puntos){
	float area = 0;	
	for(int i=0;i<puntos;i++){
		area = area + float(*(*(puntero_matriz+i)) * *(*(puntero_matriz+i+1)+1));
	}
	for(int i=0;i<puntos;i++){
		area = area - float(*(*(puntero_matriz+i)+1) * *(*(puntero_matriz+i+1)));
	}
	area = area*(0.5);
	if (area>0){
		return area;
	}
	else{
		area = area*-1;
		return area;
	}	
}

void eliminarMemoria(int **puntero_matriz,int puntos){
	for(int i = 0;i<puntos;i++){
		delete[] puntero_matriz[i];
	}
	delete []	puntero_matriz;
}
