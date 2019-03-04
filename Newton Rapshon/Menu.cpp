#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include "Barras.cpp"
#include "Sistema1.cpp"
#include "Sistema2.cpp"
#include "Sistema3.cpp"

using namespace std;

void bienvenida();
void introduccion();
void menu();

int main(){
    float *x0, tol;
    x0 = new float[3];
    int opcion, ite;
    string opcion2;
    bool repetir = false;
    bienvenida();
    introduccion();
    do{
        menu();
        scanf("%d", &opcion);
        switch(opcion){
            case 1:{
                proceso(30);
                printf("X inicial\n>");
                scanf("%f", &x0[0]);
                printf("Y inicial\n>");
                scanf("%f", &x0[1]);
                printf("Tolerancia\n>");
                scanf("%f", &tol);
                printf("Iteraciones M%cximas\n>", a);
                scanf("%d", &ite);
                iniciar1(x0, ite, tol);
                break;
            }
            case 2:{
                proceso(30);
                printf("X inicial\n>");
                scanf("%f", &x0[0]);
                printf("Y inicial\n>");
                scanf("%f", &x0[1]);
                printf("Tolerancia\n>");
                scanf("%f", &tol);
                printf("Iteraciones M%cximas\n>", a);
                scanf("%d", &ite);
                iniciar2(x0, ite, tol);
                break;
            }
            case 3:{
                proceso(30);
                printf("X inicial\n>");
                scanf("%f", &x0[0]);
                printf("Y inicial\n>");
                scanf("%f", &x0[1]);
                printf("Z inicial\n>");
                scanf("%f", &x0[2]);
                printf("Tolerancia\n>");
                scanf("%f", &tol);
                printf("Iteraciones M%cximas\n>", a);
                scanf("%d", &ite);
                iniciar3(x0, ite, tol);
                break;
            }
            case 4:{
                proceso(30);
                printf("X inicial\n>");
                scanf("%f", &x0[0]);
                printf("Y inicial\n>");
                scanf("%f", &x0[1]);
                printf("Z inicial\n>");
                scanf("%f", &x0[2]);
                printf("Tolerancia\n>");
                scanf("%f", &tol);
                printf("Iteraciones M%cximas\n>", a);
                scanf("%d", &ite);
                iniciar3(x0, ite, tol);
                break;
            }
            default:{
                printf("Opcion No Valida");
            }
        }
        system("cls");
        barra(100);sl(1);
        barra(2);espacios(2);
        printf("%cUsted desea repetir o probar alg%cn m%ctodo si/no?", 168, u, e);
        espacios(45);barra(2);sl(1);
        barra(100);sl(1);
        printf(">");
        cin >> opcion2;
        system("cls");
        barra(100);sl(1);
        if(opcion2=="si"||opcion2=="Si"||opcion2=="sI"||opcion2=="SI"){
            repetir = true;
        }
        else if (opcion2=="no"||opcion2=="No"||opcion2=="oN"||opcion2=="NO"){
            repetir = false;
        }
        else{
            barra(2);espacios(2);
            printf("Esta Opci%cn no se reconoce, creo que terminaremos el programa hasta aqu%c", o, i);
            espacios(22);barra(2);sl(1);
        }
        
        
    }while(repetir);
    barra(2);espacios(2);
    printf("Muchas Gracias por utilizar este programa, esperamos que haya sido de su agrado y que vuelva");
    espacios(2);barra(2);sl(1);
    barra(2);espacios(2);
    printf("pronto");
    espacios(88);barra(2);sl(1);
    barra(100);sl(1);
    barra(42);
    printf("FIN DEL PROGRAMA",uU);
    barra(42);sl(1);
    barra(100);sl(1);
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
    printf("Este programa est%c dise%cado para la resoluci%cn de ciertos sistemas de ecuaciones mediante el",a,n,o);
    espacios(2);barra(2);sl(1);
    barra(2);espacios(2);
    printf("m%ctodo de Newton-Rapshon, considerado uno de los mejores m%ctodos para resolver un sistema de",e, e);
    espacios(2);barra(2);sl(1);
    barra(2);espacios(2);
    printf("ecuaciones, sus principales caracter%csticas son:", i);
    espacios(46);barra(2);sl(1);
    barra(2);espacios(10);
    printf("%cTiene convergencia cuadr%ctica", 126, a);
    espacios(56);barra(2);sl(1);
    barra(2);espacios(10);
    printf("%cEs costoso con respecto a la evaluaci%cn de funciones", 126, o);
    espacios(33);barra(2);sl(1);
    barra(2);espacios(10);
    printf("%cSe necesitan ciertos elementos, como la Matriz Jacobina, Matriz Jacobina Inversa,", 126);
    espacios(4);barra(2);sl(1);
    barra(2);espacios(10);
    printf(" X vector, F vector");
    espacios(67);barra(2);sl(1);
    barra(2);espacios(10);
    printf("%cSe auto corrige", 126);
    espacios(70);barra(2);sl(1);
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