#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
	int a,b,c,contador=1;
	cout<<" Cuantos pares de coordenadas quieres agregar?  ";
	cin>>c;
	int matriz[c+1][2];
	for(int i=0;i<c;i++){
		for(int j=0;j<1;j++){
			cout<<"Ingrese x"<<"["<<contador<<"]"<<": ";
			cin>>a;
			matriz[i][j] = a;
			cout<<"Ingrese y"<<"["<<contador<<"]"<<": ";	
			cin>>b;
			matriz[i][1] = b;
			cout<<" "<<endl;
		}
		contador++;
	}
	int e,d;
	matriz[c][0] = matriz[0][0];
	matriz[c][1] = matriz[0][1];
	cout<<"   "<<" MATRIZ"<<endl;
	for (int i=0;i<c+1;i++){
		for(int j=0;j<1;j++){
			cout<<"   |";
			cout<<matriz[i][j];
			cout<<"    ";
			cout<<matriz[i][1];	
			cout<<"|";
		}
		cout<<endl;
	}
	int suma = 0;
	int resta = 0;
	int sumaFinal = 0;
	for(int j=0,i=0;i<c;i++){
		e = matriz[i][0] ;
		j = i+1;
		d = matriz[j][1];
		suma = suma + e*d;
	}
	for(int j=0,i=0;i<c;i++){
		e = matriz[i][1];
		j = i+1;
		d = matriz[j][0];
		resta = resta + e*d;
	}
	double area;
	area = (double(suma)-double(resta))*0.5;
	area = abs(area);
	cout<<"  "<<endl;
	cout<<"El Area de tu poligono en el plano cartesiano es: "<<area;
	return 0;
	}
