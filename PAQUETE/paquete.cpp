#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include <iostream>
#include "Barras.cpp"
#include "menus.cpp"
#include "Programa_Diferenciacion/Menu_3.cpp"
#include "Programa_Newton-Rapshon/Menu_1.cpp"

using namespace std;

 double signo(double fx0){
     if(fx0<0)
    {
              fx0=-1*fx0;
    }
     else
     {
          fx0=fx0;
     }
     return fx0;
 }
#define T 2
void asigna(float ***p,int *n)
{

	puts("Cuantas Xi va a tener nuestra tabla a interpolar?");
	scanf("%d",n);
	*p=(float **)calloc(sizeof(float *),*n);
	if(p==NULL)
	{
		puts("Memoria insuficiente");
		getch();
		exit(-1);
	}
}
void asigna_col(float **p, int n)
{
	int x,y;
	for(x=0;x<n;++x)
	{
		*(p+x)=(float *)calloc(sizeof(float),T);
		if(*p==NULL)
		{
			if(x==0)
			{
				free(*(p+x));
			}
			else
			{
				for(y=x;y>0;--y)
				{
					free(*(p+y));
				}
			}
			puts("Memoria Insuficiente");
			getch();
			free(p);
			exit(-1);
		}
	}
}
void cargaXY(float **p, int n,float *val)
{
	int x,y;
	for(x=0;x<n;++x)
	{
		for(y=0;y<T;++y)
		{
			if(y==0)
			{
				printf("Dame el valor de x%d\n",x);
				scanf("%f",*(p+x)+y);
			}
			else
			{
				printf("Dame el valor de y%d\n",x);
				scanf("%f",*(p+x)+y);
			}
		}
		if(x==0)
			*(val+0)=*(*(p+x)+0);
		else
			if(x==n-1)
				*(val+1)=*(*(p+x)+0);
	}
}
void liberainter(float **p,int n)
{
	int x;
	for(x=0;x<n;++x)
		free(*(p+x));
	free(p);
}
void mat_dif_div(double ***m,int n,float **p)
{
	*m=(double **)calloc(sizeof(double *),n-1);
	if(*m==NULL)
	{
		puts("Memoria Insuficiente");
		liberainter(p,n);
		getch();
		exit(-1);
	}
}
void mat_dif_div_col(double **m,int n,float **p)
{
	int x,y;
	for(x=0;x<n;++x)
	{
		*(m+x)=(double *)calloc(sizeof(double),n-1);
		if(*p==NULL)
		{
			if(x==0)
			{
				free(*(m+x));
			}
			else
			{
				for(y=x;y>0;--y)
				{
					free(*(m+y));
				}
			}
			puts("Memoria Insuficiente");
			getch();
			free(m);
			liberainter(p,n);
			exit(-1);
		}
	}
}
void dife_divi(double **m,int n,float **p)
{
	int i,dif,con,c2,con2;
	for(dif=0,con2=-1;dif<n-1;++dif,++con2)
	{
		con=dif+1;
		c2=dif+1;
		for(i=0;i<n-c2;++i,++con)
		{
			if(dif==0)
				*(*(m+i)+dif)=((*(*(p+con)+1))-(*(*(p+i)+1)))/((*(*(p+con)+0))-(*(*(p+i)+0)));
			else
			{
				*(*(m+i)+dif)=((*(*(m+(i+1))+con2))-(*(*(m+i)+con2)))/((*(*(p+con)+0))-(*(*(p+i)+0)));
			}
		}
	}

}
void imprimeinter2(double **m,int n,float **p)
{
	int x,y;
	system("cls");
	printf("%6c | %6c | %6c|",'i','x','y');
	for(x=1;x<n;++x)
		printf(" %6c[%d] |",'F',x);
	putchar('\n');
	for(x=0;x<n-1;++x)
	{
		printf("%4d |",x);
		for(y=0;y<T;++y)
			printf(" %4f |",*(*(p+x)+y));
		for(y=0;y<n-1;++y)
		{
			printf(" %6lf |",*(*(m+x)+y));
		}
		putchar('\n');
	}
	printf("%4d | %4f | %4f|\n",x,*(*(p+x)+0),*(*(p+x)+1));
}
int Mejor_Prox(float **p, int n, int gra,float val)
{
	double men;
	int x,inter,posi=0;
	inter=n-gra;
	if(inter>0)
	{

		men=fabs(val-(*(*(p+0)+0)));
		for(x=1;x<=inter;++x)
		{
			if(men>fabs(val-(*(*(p+x)+0))))
			{
				men=fabs(val-(*(*(p+x)+0)));
				posi=x;
			}
		}
	}
	printf("Valor que tiene mejor aproximacion y con el que se va a interpolar nuestro polinomio: %f\n",*(*(p+posi)));
	return (posi);

}
double valor_suma(float **p,double **m,int posi,int grado,float val,int n)
{
	double res=0,res2=0;
	int x,y;
	for(x=0;x<grado;++x)
	{
		for(y=0,res=0;y<=x;++y)
		{
			if(y==0)
			{
				res=*(*(m+posi)+x);
				res*=(val-(*(*(p+(posi+y))+0)));
			}
			else
				res*=(val-(*(*(p+(posi+y))+0)));
		}
		res2+=res;
	}
	return (res2);
}
double valor_poliN(float **p,double **m, int n,int grado,float val,int posi)
{
	int x;
	double res,res2;
	res=(*(*(p+posi)+1))+valor_suma(p,m,posi,grado,val,n);
	return (res);
}
void polinomioN(float **p, double **m, int n, float *val)
{
	int x,y,res,Gpol,pun_fij;
	float valor;
	double resultado;
	printf("\nRecuerda, que el valor a interpolar debe de estar entre los intervalos [%4f,%4f]\n",*(val+0),*(val+1));
	if(*(val+0)>*(val+1))
		res=1;
	else
		res=-1;
	puts("Digita el valor de interpolacion porfavor");
	if(res==1)
	{
		do
		{
			scanf("%f",&valor);
			if(valor<*(val+0)||valor>*(val+1))
				puts("Digite un valor que este entre los intervalos porfavor");
		}
		while(valor>(*(val+0))||valor<(*(val+1)));
	}
	else
	{
		do
		{
			scanf("%f",&valor);
			if(valor<*(val+0)||valor>*(val+1))
				puts("Digite un valor que este entre los intervalos porfavor");
		}
		while(valor<(*(val+0))||valor>(*(val+1)));
	}
	puts("Digita el grado del polinomio porfavor");
	do
	{
		scanf("%d",&Gpol);
		if(Gpol>n-1)
			printf("Recuerda que el grado maximo que puede tener nuestro polinomio es de %d-1\n",n);
	}
	while(Gpol>n-1);
	system("cls");
	imprimeinter2(m,n,p);
	pun_fij=Mejor_Prox(p,n-1,Gpol,valor);
	resultado=valor_poliN(p,m,n,Gpol,valor,pun_fij);
	printf("Valor del P%d(%f): %lf\n",Gpol,valor,resultado);
}
void imprimeinter(float **p,int n)
{
	int x;
	system("cls");
	puts("\tEsta es la tabla con los datos para interpolar\n");
	for(x=0;x<n;++x)
	{
		if(x==0)
			printf("%6c | %6c | %6c|\n",'i','x','y');
		printf("%4d | %4f | %4f|\n",x,*(*(p+x)+0),*(*(p+x)+1));
	}
	puts("\nOprima cualquier tecla para continuar");
	getch();
}
void liberainter2(double **m,int n)
{
	int x;
	for(x=0;x<n-1;++x)
		free(*(m+x));
	free(m);
}
main(){
	int metods;
	bienvenida();
	menu();
	printf("Que opcion desea Realizar:\n>");
	scanf("%d", &metods);
	switch(metods){
			case 1:
				menu_1();
			break;
			case 2:
				{
					char c;
					float **matXY, x0xn[2];
					double **matDDiv;
					int tam,res,elecc,res2;
					do
					{
						system("cls");
						puts("\t\t(2)Interpolacion y Ajuste de Curvas");
						asigna(&matXY,&tam);
						asigna_col(matXY,tam);
						cargaXY(matXY,tam,x0xn);
						imprimeinter(matXY,tam);
						puts("Elegir entre interpolacion o ajuste de curvas-.\n(1)Interpolacion \n(2)Ajuste de curvas\n");
						do
						{
							scanf("%d",&elecc);
							if(elecc<1||elecc>2)
								puts("Elegir una de las opciones dadas porfavor");
						}
						while(elecc<1||elecc>2);
						switch(elecc)
						{
							case 1:
							{
								mat_dif_div(&matDDiv,tam,matXY);
								mat_dif_div_col(matDDiv,tam,matXY);
								dife_divi(matDDiv,tam,matXY);
								imprimeinter2(matDDiv,tam,matXY);
								do
								{
									polinomioN(matXY,matDDiv,tam,x0xn);
									puts("Desea interpolar otro punto con la misma tabla?\n(1)Si, (2)No");
									do
									{
										scanf("%d",&res2);
										if(res2<1||res2>2)
											puts("Elegi una de las dos opciones porfavor");
									}
									while(res2<1||res2>2);
								}
								while(res2!=2);
								liberainter(matXY,tam);
								liberainter2(matDDiv,tam);
							}
							break;
							case 2:
							{
								int i=0;
								float xcuadrada[tam],xymat[tam],zxi=0,zyi=0,zxi2=0,zxiyi=0,a0=0,a1=0,pol[tam],error[tam];
								for(i=0;i<tam;++i)
								{
									xcuadrada[i]=(*(*(matXY+i)))*(*(*(matXY+i)));
								}

								for(i=0;i<tam;++i)
								{
									xymat[i]=(*(*(matXY+i)+0))*(*(*(matXY+i)+1));
								}
								for(i=0;i<tam;++i)
								{
									zxi+=(*(*(matXY+i)+0));
									zyi+=(*(*(matXY+i)+1));
									zxi2+=xcuadrada[i];
									zxiyi+=xymat[i];
								}
								a0=((zxi2*zyi)-(zxi*zxiyi))/((tam*zxi2)-(zxi*zxi));
								a1=((tam*zxiyi)-(zxi*zyi))/((tam*zxi2)-(zxi*zxi));
								printf("xi |yi |xi^2 |xiyi |p(xi) |Error\n");
								for(i=0;i<tam;++i)
								{
									pol[i]=(*(*(matXY+i)))*a1+a0;
									error[i]=pow((*(*(matXY+i)+1))-pol[i],2);
									printf("%f |%f |%f |%f |%f |%f\n",(*(*(matXY+i)+0)),(*(*(matXY+i)+1)),xcuadrada[i],xymat[i],pol[i],error[i]);
								}
							}
							break;
						}
						puts("Desea crear una nueva tabla con nuevos datos a interpolar?\n (1)Si, (2)No");
						do
						{
							scanf("%d",&res);
							if(res<1||res>2)
								puts("Digita una de las opciones dadas porfavor");
						}
						while(res<1||res>2);
					}
					while(res!=2);
					puts("\n\"Apreta cualquier tecla para continuar\"");
					getch();
				}
			break;
			case 3:
				menu_3();
			break;
	}
	
	system("cls");
	despedida();
	puts("Gracias por usar el programa..\nAprieta cualquiera tecla para terminar");
	getch();
}
