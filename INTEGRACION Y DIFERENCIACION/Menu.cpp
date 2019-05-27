#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include <iostream>
#include "Barras.cpp"
#include "menus.cpp"
#include "impresionTabla.cpp"
#include "Derivadas.cpp"
#include "Extrapolacion.cpp"
#include "Integracion.cpp"

using namespace std;

void crearTabla(int **K,double **Xs,double **Ys,int *tam);
void Llenar(double *Xs, double *Ys,int tam,float *inter);
void ImprimeTabla(double *X,double *Y,int tam);

int main(){
    int correcto;
    double *X,*Y;
	float inter;
	int *K,tam,op,op2,op3,cent=0;
    bienvenida();
    introIntegracion();
    crearTabla(&K,&X,&Y,&tam);
	do{
		do{
			Llenar(X,Y,tam,&inter);
				do{
				ImprimeTabla(X,Y,tam);
				printf("La Tabla esta Correcta? (1.si/2.no)\n>");
				scanf("%d", &correcto);
				if(correcto == 2  ){
					system("cls");
					printf("Entendio, Reingrese los Valores\n");
				}
				else if(correcto != 2 && correcto != 1){
					system("cls");
					printf("La Opcion no se Encuentra\n");
				}
			}while(correcto != 2 && correcto != 1);
		}while(correcto == 2 );
		do
		{
			menuIntegracion();
			scanf("%d",&op);
			if(op<1||op>3){
				system("cls");
				printf("Digite una de las opciones porfavor");
			}
			if(op==2&&tam<7){
				op=0;
				printf("El minimo de valores para extrapolar son 7 valores digite otra opcion porfavor");
			}
		}while(op<1||op>3);
		switch(op){
			case 1:
				system("cls");
				ImprimeTabla(X,Y,tam);
				Derivadas(X,Y,tam,inter);
				break;
			case 2:
				system("cls");
				ImprimeTabla(X,Y,tam);
				extrapolacion(X,Y,tam,inter);
				break;
			case 3:
				system("cls");
				ImprimeTabla(X,Y,tam);
				integracion(X,Y,tam);
				break;
			default:
				printf("Sucedio Un Error");
				break;

		}
		do{
			printf("Desea Realizar otra operacion? (1.si/2.no)\n>");
			scanf("%d", &op2);
			if(op2 == 1){
                do{
				system("cls");
                printf("Entendio\n");
				printf("Desea Ingresar Nuevos Valores?(1.si/2.no)\n>");
				scanf("%d", &op3);
				if(op3 != 2 && op3 != 1){
					system("cls");
					printf("Opcion No encontrada");
				}
				}while(op3 != 2 && op3 != 1);
				if(op3==1){
					system("cls");
					Llenar(X, Y, tam, &inter);
				}
            }
            else if(op2 != 2 && op2 != 1){
                system("cls");
                printf("La Opcion no se Encuentra\n");
            }
        }while(op2 != 2 && op2 != 1);
    }while(op2 == 1 );
	despedida();
}

void crearTabla(int **K,double **Xs,double **Ys,int *tam){
	puts("Cuantas datos se insertaran en la tabla?");
	scanf("%d",tam);
	*K=(int *)calloc(sizeof(int),*tam);
	*Xs=(double *)calloc(sizeof(double),*tam);
	*Ys=(double *)calloc(sizeof(double),*tam);
	if(*Xs==NULL&&*Ys==NULL){
		puts("Error Memoria Insuficiente");
		getch();
		exit(-1);
	}
}

void Llenar(double *Xs, double *Ys,int tam,float *inter){
	int x;
	float h,h2;
	puts("Recuerda que los valores de X deben de estar igualmente espaciadas");
	for(x=0;x<tam;++x){
		printf("Digita el valor de X%d\n>",x);
		if(x==0)
			scanf("%lf",(Xs+x));
		else
			if(x==1){
				scanf("%lf",(Xs+x));
				*inter=(*(Xs+0)-(*(Xs+1)));
				h=*inter;
				if(h<0)
				h*=-1;
			}
			else{
				do{
					scanf("%lf",(Xs+x));
					h2=(*(Xs+(x-1))-(*(Xs+x)));
					if(h2<0)
						h2*=-1;
					if(h2!=h)
						printf("Recuerda que los valores de X deben de estar igualmente espaciadas\nDigita otro numero porfavor con separacion de (%.8lf)\n",h);
					else
						if(*(Xs+(x-2))==*(Xs+x))
							puts("Valor de X repetido por favor digitar otro");
				}
				while(h2!=h||*(Xs+(x-2))==*(Xs+x));
			}
		printf("Digita el valor de %c(%.8lf)\n",f,*(Xs+x));
		scanf("%lf",(Ys+x));
	}
}
