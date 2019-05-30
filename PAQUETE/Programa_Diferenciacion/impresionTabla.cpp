void formato_float(double valor){
    if(valor>=0){
        if(valor<10){
            espacios(3);printf("%.8lf", valor);
        }
        else if(valor<100){
            espacios(2);printf("%.8lf", valor);
        }
        else if(valor<1000){
            espacios(1);printf("%.8lf", valor);
        }
        else if(valor<10000){
            printf("%.7lf", valor);
        }
        else if(valor<100000){
            printf("%.6lf", valor);
        }
        else if(valor<1000000){
            printf("%.5lf", valor);
        }
        else if(valor<10000000){
            printf("%.4lf", valor);
        }
        else if(valor<100000000){
            printf("%.3lf", valor);
        }
        else if(valor<1000000000){
            printf("%.2lf", valor);
        }
        else if(valor<10000000000){
            printf("%.1lf", valor);
        }
        else{
            printf("#############");
        }
    }
    else{
        if(valor<10){
            espacios(2);printf("%.8lf", valor);
        }
        else if(valor<100){
            espacios(1);printf("%.8lf", valor);
        }
        else if(valor<1000){
            printf("%.7lf", valor);
        }
        else if(valor<10000){
            printf("%.6lf", valor);
        }
        else if(valor<100000){
            printf("%.5lf", valor);
        }
        else if(valor<1000000){
            printf("%.4lf", valor);
        }
        else if(valor<10000000){
            printf("%.3lf", valor);
        }
        else if(valor<100000000){
            printf("%.2lf", valor);
        }
        else if(valor<1000000000){
            printf("%.1lf", valor);
        }
        else{
            printf("#############");
        }
    }
}

void ImprimeTabla(double *X,double *Y,int tam){
	int z;
    system("cls");
    esi(1);bh(27);esd(1);sl(1);
    bv(1);espacios(6);printf("TABLA INGRESADA");espacios(6);bv(1);sl(1);
    biiv(1);bh(13);
    bsih(1);bh(13);bidv(1);sl(1);
    bv(1);espacios(6);printf("X");espacios(6);
    bv(1);espacios(4);printf("%c(X)", f);espacios(5);
    bv(1);sl(1);
    biiv(1);bh(13);
    bii(1);bh(13);bidv(1);sl(1);

    for(z=0;z<tam;++z){
		bv(1);formato_float(*(X+z));
        bv(1);formato_float(*(Y+z));
        bv(1);sl(1);
    }

    eii(1);bh(13);
    biih(1);bh(13);
    eid(1);sl(1);
}

void imprimeTablaDer(double *X,double *Y,double **De,int tam)
{
	int x,y;
    esi(1);bh(55);esd(1);sl(1);
    bv(1);espacios(20);printf("TABLA RESULTADOS");espacios(19);bv(1);sl(1);
    biiv(1);bh(13);
    bsih(1);bh(13);
    bsih(1);bh(13);
    bsih(1);bh(13);bidv(1);sl(1);
    bv(1);espacios(6);printf("X");espacios(6);
    bv(1);espacios(4);printf("%c(X)", f);espacios(5);
    bv(1);espacios(4);printf("%c'(X)", f);espacios(4);
    bv(1);espacios(3);printf("%c''(X)", f);espacios(4);
    bv(1);sl(1);
    biiv(1);bh(13);
    biiv(1);bh(13);
    biiv(1);bh(13);
    bii(1);bh(13);bidv(1);sl(1);
	for(x=0;x<tam;++x){
		bv(1);formato_float(*(X+x));
        bv(1);formato_float(*(Y+x));
        bv(1);formato_float(*(*(De+x)+0));
        bv(1);formato_float(*(*(De+x)+1));
        bv(1);sl(1);
	}

    eii(1);bh(13);
    biih(1);bh(13);
    biih(1);bh(13);
    biih(1);bh(13);
    eid(1);sl(1);
}

void formato2_float(double valor){
    if(valor>=0){
        if(valor<10){
            printf("%.8lf", valor);
        }
        else if(valor<100){
            printf("%.7lf", valor);
        }
        else if(valor<1000){
            printf("%.6lf", valor);
        }
        else if(valor<10000){
            printf("%.5lf", valor);
        }
        else if(valor<100000){
            printf("%.4lf", valor);
        }
        else if(valor<1000000){
            printf("%.3lf", valor);
        }
        else if(valor<10000000){
            printf("%.2lf", valor);
        }
        else if(valor<100000000){
            printf("%.1lf", valor);
        }
        else{
            printf("#############");
        }
    }
    else{
        if(valor<10){
            printf("%.7lf", valor);
        }
        else if(valor<100){
            printf("%.6lf", valor);
        }
        else if(valor<1000){
            printf("%.5lf", valor);
        }
        else if(valor<10000){
            printf("%.4lf", valor);
        }
        else if(valor<100000){
            printf("%.3lf", valor);
        }
        else if(valor<1000000){
            printf("%.2lf", valor);
        }
        else if(valor<10000000){
            printf("%.1lf", valor);
        }
        else{
            printf("#############");
        }
    }
}

void imprimeExtrapolacion(float *H,double **extra,int lim,double valor)
{    
    int x, y;
    esi(1);bh(55);esd(1);sl(1);
    bv(1);espacios(20);printf("TABLA RESULTADOS");espacios(19);bv(1);sl(1);
    biiv(1);bh(13);
    bsih(1);bh(13);
    bsih(1);bh(13);
    bsih(1);bh(13);bidv(1);sl(1);
    bv(1);espacios(6);printf("h");espacios(6);
    bv(1);printf("%c(", f);
    formato2_float(valor);
    printf(")");
    bv(1);printf("Extrapolacion", f);
    bv(1);espacios(3);printf("%c''(X)", f);espacios(4);
    bv(1);sl(1);
    bv(1);espacios(13);
    bv(1);espacios(13);
    bv(1);printf("de 1er Orden");espacios(1);
    bv(1);printf("de 2do Orden");espacios(1);
    bv(1);sl(1);

    biiv(1);bh(13);
    biiv(1);bh(13);
    biiv(1);bh(13);
    bii(1);bh(13);bidv(1);sl(1);
    
    for(x=0;x<lim;++x){
    bv(1);formato_float(*(H+x));
    bv(1);formato_float(*(*(extra+x)+0));
    bv(1);formato_float(*(*(extra+x)+1));
    bv(1);formato_float(*(*(extra+x)+2));
    bv(1);sl(1);
    }

    eii(1);bh(13);
    biih(1);bh(13);
    biih(1);bh(13);
    biih(1);bh(13);
    eid(1);sl(1);
}