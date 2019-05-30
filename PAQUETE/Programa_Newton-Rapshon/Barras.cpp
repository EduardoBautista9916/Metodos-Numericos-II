#include <stdio.h>
#include <windows.h>

const char a = 160;
const char e = 130;
const char i = 161;
const char o = 162;
const char u = 163;
const char aA = 181;
const char eE = 144;
const char iI = 214;
const char oO = 224;
const char uU = 233;
const char n = 164;
const char nN = 165;
const char f = 159;

void barra(int c){
    for(int i=0;i<c;i++)
        printf("%c", 42);
}

void espacios(int c){
    for(int i=0;i<c;i++)
        printf(" ");
}

void esi(int c){// Esquina Superior Izquierda ╔
    for(int i=0;i<c;i++)
        printf("%c", 201);
}

void bv(int c){//Barra Vertical ║
    for(int i=0;i<c;i++)
        printf("%c", 186);
}

void biiv(int c){//Barra Intermedia Izquierda Vertical ╠
    for(int i=0;i<c;i++)
        printf("%c", 204);
}

void eii(int c){//Esquina Inferior Izquierda ╚
    for(int i=0;i<c;i++)
        printf("%c", 200);
}

void bh(int c){//Barra Horizontal ═
    for(int i=0;i<c;i++)
        printf("%c", 205);
}

void bsih(int c){//Barra Superior Intermedia Horizontal ╦
    for(int i=0;i<c;i++)
        printf("%c", 203);
}

void bii(int c){//Barra Intermedia Intermedia ╬
    for(int i=0;i<c;i++)
        printf("%c", 206);
}

void biih(int c){//Barra Inferior Intermedia Horizontal ╩
    for(int i=0;i<c;i++)
        printf("%c", 202);
}

void esd(int c){//Esquina Superior Derecha ╗
    for(int i=0;i<c;i++)
        printf("%c", 187);
}

void bidv(int c){//Barra Intermedia Derecha Vertial ╣
    for(int i=0;i<c;i++)
        printf("%c", 185);
}

void eid(int c){//Esquina Inferior Derecha ╝
    for(int i=0;i<c;i++)
        printf("%c", 188);
}

void bcsup(int c){//Barra de Carga Superior ▄
    for(int i=0;i<c;i++)
        printf("%c", 220);
}

void bcint(int c){//Barra de Carga Itermedia █
    for(int i=0;i<c;i++)
        printf("%c", 219);
}

void bcinf(int c){//Barra de Carga Inferior ▀
    for(int i=0;i<c;i++)
        printf("%c", 223);
}

void sl(int c){//Salto de Linea \n
    for(int i=0;i<c;i++)
        printf("\n");
}

void proceso(int t){
    int c;
    for(int i = 0; i<99; i++){
        c = 98 - i;
        barra(100);sl(1);
        barra(2);espacios(2);
        printf("Espere un Momento, el Programa est%c cargando los Atributos y Herramientas necesarios para", a);
        espacios(5); barra(2);sl(1);
        barra(2);espacios(2);
        printf("el Proceso");
        espacios(84); barra(2);sl(1);
        barra(100);sl(2);
        espacios(45);printf("CARGANDO...");espacios(44);printf("\n");
        esi(1);bcsup(i);bh(c);esd(1);sl(1);
        bv(1);bcint(i);espacios(c);bv(1);sl(1);
        eii(1);bcinf(i);bh(c);eid(1);sl(1);
        Sleep(t);
        system("cls");
    }
}