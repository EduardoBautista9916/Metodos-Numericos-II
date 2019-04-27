#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <math.h>
#include <iostream>
#include <ctype.h>
#include "Barras.cpp"

using namespace std;

int cont;

struct coordenadas{
    double x;
    double y;
};

void bienvenida();
void introduccion();
void menu();
void instrucciones();
double *split(string cadena);

int main(){
    coordenadas matriz;
    string matrizX, matrizY;
    int tamX, tamY;
    bienvenida();
    introduccion();
    instrucciones();
    Reingresar:
    printf("Ingrese los Valores que Corresponden a X\n>");
    getline(cin, matrizX);
    printf("Ingrese los Valores que Corresponden a Y\n>");
    getline(cin, matrizY);
    double *matriz1 = split(matrizX);
    tamX = cont;
    double *matriz2 = split(matrizY);
    tamY = cont;
    if(tamX>tamY){
        barra(100);sl(1);
        barra(2);espacios(2);
        printf("La Cantidad de valores de X son mas que los valores de Y, asi que debes de reingresar los");
        espacios(4); barra(2);sl(1);
        barra(2);espacios(2);
        printf("datos, y esta vez procura no equivocarte");
        espacios(52); barra(2);sl(1);
        barra(100);sl(1);
        goto Reingresar;
    }
    else if(tamX<tamY){
         barra(100);sl(1);
        barra(2);espacios(2);
        printf("La Cantidad de valores de Y son mas que los valores de X, asi que debes de reingresar los");
        espacios(4); barra(2);sl(1);
        barra(2);espacios(2);
        printf("datos, y esta vez procura no equivocarte");
        espacios(52); barra(2);sl(1);
        barra(100);sl(1);
        goto Reingresar;
    }
    printf("Valores X:\n");
    for(int i=0;i<tamX;i++){
        printf("%f\t", matriz1[i]);
    }
    printf("Valores Y:\n");
    for(int i=0;i<tamY;i++){
        printf("%f\t", matriz2[i]);
    }
    system("pause");
}

void bienvenida(){
    system("cls");
    barra(100);sl(1);
    barra(45);
    printf("BIENVENIDO");
    barra(45);sl(1);
    barra(100);sl(1);
    barra(2);espacios(29);
    printf("UNIVERSIDAD NACIONAL AUT%cNOMA DE M%cXICO",oO,eE);
    espacios(28);barra(2);sl(1);
    barra(2);espacios(29);
    printf("FACULTAD DE ESTUDIOS SUPERIORES ACATL%cN", aA);
    espacios(28);barra(2);sl(1);
    barra(2);espacios(38);
    printf("M%cTODOS NUM%cRICOS II",eE,eE);
    espacios(38);barra(2);sl(1);
    barra(2);espacios(36);
    printf("M%cTODO DE NEWTON-RAPSHON",eE);
    espacios(36);barra(2);sl(1);
    barra(2);espacios(5);
    printf("Miembros del equipo:");
    espacios(71);barra(2);sl(1);
    barra(2);espacios(10);
    printf("%c%clvarez Cortes Kevin Alejandro", 126, aA);
    espacios(55);barra(2);sl(1);
    barra(2);espacios(10);
    printf("%cBautista Gaona Luis Eduardo",126);
    espacios(58);barra(2);sl(1);
    barra(2);espacios(10);
    printf("%cFlores Hern%cndez Itzel",126, a);
    espacios(63);barra(2);sl(1);
    barra(2);espacios(10);
    printf("%cFlores Velasco Jos%c Juan",126,e);
    espacios(61);barra(2);sl(1);
    barra(100);printf("\n");
    system("pause");
    system("cls");
}

void introduccion(){
    system("cls");
    barra(100);sl(1);
    barra(2);espacios(2);
    printf("Este programa est%c dise%cado para la interpolaci%cn de un valor dado una tabla con los valores", a, n, o);
    espacios(2);barra(2);sl(1);
    barra(2);espacios(2);
    printf("de x & y mediante el m%ctodo de Newton Progresivo y Regresivo, adem%cs de poder realizar el", e, a);
    espacios(5);barra(2);sl(1);
    barra(2);espacios(2);
    printf("ajuste de curvas mediante el m%ctodo de Spline Cubico"), e;
    espacios(42);barra(2);sl(1);
    barra(100);sl(1);
    system("pause");
    system("cls");
}

void menu(){
    barra(100);sl(1);
    barra(48);
    printf("MEN%c",uU);
    barra(48);sl(1);
    barra(100);sl(1);
    barra(2);espacios(2);
    printf("Escoja uno de los cuatro sistemas de ecuaciones integrado en este programa");
    espacios(20); barra(2);sl(1);
    barra(2);espacios(10);
    printf("1.-");
    espacios(83); barra(2);sl(1);
    barra(2);espacios(13);
    printf("%c1(x, y)=x%c+xy-10=0",f,253);
    espacios(64); barra(2);sl(1);
    barra(2);espacios(13);
    printf("%c2(x, y)=y+3xy%c-50=0",f,253);
    espacios(63); barra(2);sl(1);
    barra(2);espacios(10);
    printf("2.-");
    espacios(83); barra(2);sl(1);
    barra(2);espacios(13);
    printf("%c1(x, y)=x%c+y%c-9=0",f,253,253);
    espacios(65); barra(2);sl(1);
    barra(2);espacios(13);
    printf("%c2(x, y)=-e%c-2y-3=0",f,158);
    espacios(64); barra(2);sl(1);
    barra(2);espacios(10);
    printf("3.-");
    espacios(83); barra(2);sl(1);
    barra(2);espacios(13);
    printf("%c1(x, y, z)=2x%c-4x+y%c+3z%c+6z+2=0",f,253,253,253);
    espacios(51); barra(2);sl(1);
    barra(2);espacios(13);
    printf("%c2(x, y, z)=x%c+y%c-2y+2z%c-5=0",f,253, 253, 253);
    espacios(55); barra(2);sl(1);
    barra(2);espacios(13);
    printf("%c3(x, y, z)=3x%c-10x+y%c-3z%c+8=0",f,253, 253, 253);
    espacios(53); barra(2);sl(1);
    barra(2);espacios(10);
    printf("4.-");
    espacios(83); barra(2);sl(1);
    barra(2);espacios(13);
    printf("%c1(x, y, z)=x%c-4x+y%c=0",f,253,253);
    espacios(61); barra(2);sl(1);
    barra(2);espacios(13);
    printf("%c2(x, y, z)=x%c-x-12y+1=0",f,253);
    espacios(59); barra(2);sl(1);
    barra(2);espacios(13);
    printf("%c3(x, y, z)=3x%c-10x+y%c-3z%c+8=0",f,253, 253, 253);
    espacios(53); barra(2);sl(1);
    barra(100);sl(1);
    printf(">");
}

void instrucciones(){
    system("cls");
    barra(100);sl(1);
    barra(2);espacios(2);
    printf("Para que el siguiente programa sirva de la mejor manera posible se debe de seguir los");
    espacios(9);barra(2);sl(1);
    barra(2);espacios(2);
    printf("siguientes pasos:");
    espacios(77);barra(2);sl(1);
    barra(2);espacios(2);
    printf("1.- Debes de ingresar los valores para X en una sola l%cnea, separa por espacios ( ), barra", i);
    espacios(4);barra(2);sl(1);
    barra(2);espacios(2);
    printf("lateral (|), guion (-) o diagonal (/), y de igual manera con los valores de Y.");
    espacios(16);barra(2);sl(1);
    barra(2);espacios(2);
    printf("2.- Debes de verificar que los valores que est%cn capturados coincidan con los que hallas", a);
    espacios(6);barra(2);sl(1);
    barra(2);espacios(2);
    printf("ingresado. En caso de que no sean correctos debes de reingresar los valores.");
    espacios(18);barra(2);sl(1);
    barra(2);espacios(2);
    printf("3.- Debes de elegir qu%c es lo que realizaras con los valores, si es que haces interpolaci%cn",e, o);
    espacios(3);barra(2);sl(1);
    barra(2);espacios(2);
    printf("de un punto o un ajuste de curvas.");
    espacios(60);barra(2);sl(1);
    barra(2);espacios(2);
    printf("4.- En caso de que elijas interpolaci%cn debes de ingresar el punto que quieres interpolar," , o);
    espacios(4);barra(2);sl(1);
    barra(2);espacios(2);
    printf("adem%cs del grado de polinomio.", a);
    espacios(64);barra(2);sl(1);
    barra(2);espacios(2);
    printf("5.- En caso de que elijas Spline cubico no debes de ingresar nada m%cs.", a);
    espacios(24);barra(2);sl(1);
    barra(100);sl(1);
    system("pause");
    system("cls");
}

double *split(string cadena){
    int i=0, j=0;
    double *array;
    cont=0;
    while(cadena[i]!='\0'){
       if((cadena[i] == ' ' || cadena[i]=='-' || cadena[i]=='|'||cadena[i]=='/')&&isdigit(cadena[i+1])){
           cont++;
       }
       else if(isdigit(cadena[i])){}
       else{
           array = NULL;
           printf("Arreglo Vacio\n");
           return array;
       }
       i++;
    }
    i=0;
    string aux="5";
    array = new double [cont];
    while(cadena[i]!='\0'){
       if((isdigit(cadena[0])==false)&& aux!=""){
           array[j] = atof(aux.c_str());
           aux="";
           j++;
       }
       else if(isdigit(cadena[i])){
           printf("%c\n", aux);
           aux=cadena[i];
           printf("%c.",cadena[i]);
       }
       i++;
    }
    return array;
}