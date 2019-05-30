void iniciar2(float *x0, int iteraciones, float tolerancia);
float **jacobina2(float *x);
float *m_FuncionX2(float *x);
float *calculo_xn2(float *x, float **j1x, float *fx);
float **jacobina_inversa2(float **jx);
float cal_tolerancia2(float *x0, float *x1);
void imprimir2(int n, float *x, float *fx, float **jx, float **j1x, float tol);

int grado2 = 2;

void iniciar2(float *x0, int iteraciones, float tolerancia){
    float *x1, *fx, **jx, **j1x, tol=0;
    esi(1);bh(98);esd(1);sl(1);
    bv(1);espacios(37);printf("M%cTODO DE NEWTON-RAPSHON", eE);espacios(37);bv(1);sl(1);
    biiv(1);bh(98);bidv(1);sl(1);
    bv(1);espacios(39);printf("%c1(x, y)=x%c+xy-10=0",f,253);espacios(40); bv(1);sl(1);
    bv(1);espacios(39);printf("%c2(x, y)=y+3xy%c-50=0",f,253);espacios(39); bv(1);sl(1);

    biiv(1);bh(3);
    bsih(1);bh(13);
    bsih(1);bh(13);
    bsih(1);bh(27);
    bsih(1);bh(27);
    bsih(1);bh(10);bidv(1);sl(1);

    bv(1);espacios(1);printf("n");espacios(1);
    bv(1);espacios(6);printf("X");espacios(6);
    bv(1);espacios(4);printf("F(X)");espacios(5);
    bv(1);espacios(11);printf("J(X)");espacios(12);
    bv(1);espacios(10);printf("J%c%c(X)", 238,251);espacios(11);
    bv(1);printf("Tolerancia");bv(1);sl(1);

    biiv(1);bh(3);
    bii(1);bh(13);
    bii(1);bh(13);
    bii(1);bh(13);
    bsih(1);bh(13);
    bii(1);bh(13);
    bsih(1);bh(13);
    bii(1);bh(10);bidv(1);sl(1);

    for(int i = 0;i <= tolerancia ;i++){
        fx = m_FuncionX2(x0);
        jx = jacobina2(x0);
        j1x = jacobina_inversa2(jx);
        x1 = calculo_xn2(x0,j1x,fx);
        imprimir2(i, x0, fx, jx, j1x, tol);
        tol = cal_tolerancia2(x0, x1);
        x0 = x1;
        if(tol<=tolerancia)
            break;
    }
    eii(1);bh(3);
    biih(1);bh(13);
    biih(1);bh(13);
    biih(1);bh(13);
    biih(1);bh(13);
    biih(1);bh(13);
    biih(1);bh(13);
    biih(1);bh(10);eid(1);sl(1);

    system("pause");
}

float **jacobina2(float *x){
    float **jx;
    jx = new float *[grado];
    for(int i = 0; i<grado;i++){
        jx[i]=new float[grado];
    }

    jx[0][0]=2*x[0];
    jx[0][1]=2*x[1];
    jx[1][0]=-exp(x[0]);
    jx[1][1]=2;

    return jx;
}

float *m_FuncionX2(float *x){
    float *fx = new float[grado2];
    fx[0]=(x[0]*x[0])+(x[1]*x[1])-9;
    fx[1]=(-exp(x[0]))-(2*x[1])-3;
    return fx;
}

float *calculo_xn2(float *x, float **j1x, float *fx){
    float *xn = new float[grado];
    xn[0] = x[0]-((j1x[0][0]*fx[0])+(j1x[0][1]*fx[1]));
    xn[1] = x[1]-((j1x[1][0]*fx[0])+(j1x[1][1]*fx[1]));

    return xn;
}

float **jacobina_inversa2(float **jx){
    float **j1x;
    float det;
    j1x = new float *[grado];
    for(int i = 0; i<grado;i++){
        j1x[i]=new float[grado];
    }
    det = (jx[0][0]*jx[1][1])-(jx[0][1]*jx[1][0]);
    if(det!=0){
        j1x[0][0]=jx[1][1]/det;
        j1x[0][1]=-jx[0][1]/det;
        j1x[1][0]=-jx[1][0]/det;
        j1x[1][1]=jx[0][0]/det;
    }
    else{
        j1x[0][0]=0;
        j1x[0][1]=0;
        j1x[1][0]=0;
        j1x[1][1]=0;
    }
    return j1x;
}

float cal_tolerancia2(float *x0, float *x1){
    float tempX = fabs(fabs(x1[0])-fabs(x0[0]));
    float tempY = fabs(fabs(x1[1])-fabs(x0[1]));
    if(tempX>=tempY)
        return tempX;
    else
        return tempY;
}

void formato_float2(float valor){
    if(valor>=0){
        if(valor<10){
            printf("%.11f", valor);
        }
        else if(valor<100){
            printf("%.10f", valor);
        }
        else if(valor<1000){
            printf("%.9f", valor);
        }
        else if(valor<10000){
            printf("%.8f", valor);
        }
        else if(valor<100000){
            printf("%.7f", valor);
        }
        else if(valor<1000000){
            printf("%.6f", valor);
        }
        else if(valor<10000000){
            printf("%.5f", valor);
        }
        else if(valor<100000000){
            printf("%.4f", valor);
        }
        else if(valor<1000000000){
            printf("%.3f", valor);
        }
        else if(valor<10000000000){
            printf("%.2f", valor);
        }
        else if(valor<100000000000){
            printf("%.1f", valor);
        }
        else{
            printf("#############");
        }
    }
    else{
        if(valor>-10){
            printf("%.10f", valor);
        }
        else if(valor>-100){
            printf("%.9f", valor);
        }
        else if(valor>-1000){
            printf("%.8f", valor);
        }
        else if(valor>-10000){
            printf("%.7f", valor);
        }
        else if(valor>-100000){
            printf("%.6f", valor);
        }
        else if(valor>-1000000){
            printf("%.5f", valor);
        }
        else if(valor>-10000000){
            printf("%.4f", valor);
        }
        else if(valor>-100000000){
            printf("%.3f", valor);
        }
        else if(valor>-1000000000){
            printf("%.2f", valor);
        }
        else if(valor>-10000000000){
            printf("%.1f", valor);
        }
        else{
            printf("#############");
        }
    }
}

void formato2_float2(float valor){
    if(valor>=0){
        if(valor==0){
            valor=0;
        }
        if(valor<10){
            printf("%.8f", valor);
        }
        else if(valor<100){
            printf("%.7f", valor);
        }
        else if(valor<1000){
            printf("%.6f", valor);
        }
        else if(valor<10000){
            printf("%.5f", valor);
        }
        else if(valor<100000){
            printf("%.4f", valor);
        }
        else if(valor<1000000){
            printf("%.3f", valor);
        }
        else if(valor<10000000){
            printf("%.2f", valor);
        }
        else if(valor<100000000){
            printf("%.1f", valor);
        }
        else{
            printf("#############");
        }
    }
    else{
        if(valor<10){
            printf("%.7f", valor);
        }
        else if(valor<100){
            printf("%.6f", valor);
        }
        else if(valor<1000){
            printf("%.5f", valor);
        }
        else if(valor<10000){
            printf("%.4f", valor);
        }
        else if(valor<100000){
            printf("%.3f", valor);
        }
        else if(valor<1000000){
            printf("%.2f", valor);
        }
        else if(valor<10000000){
            printf("%.1f", valor);
        }
        else{
            printf("#############");
        }
    }
}

void imprimir2(int n, float *x, float *fx, float **jx, float **j1x, float tol){
    if(n<10){
        bv(1);espacios(3);
        bv(1);formato_float(x[0]);
        bv(1);formato_float(fx[0]);
        bv(1);formato_float(jx[0][0]);
        bv(1);formato_float(jx[0][1]);
        bv(1);formato_float(j1x[0][0]);
        bv(1);formato_float(j1x[0][1]);
        bv(1);espacios(10);bv(1);sl(1);

        bv(1);espacios(1);printf("%d", n);espacios(1);
        bv(1);espacios(13);
        bv(1);espacios(13);
        biiv(1);bh(13);
        bii(1);bh(13);
        bii(1);bh(13);
        bii(1);bh(13);
        bidv(1);formato2_float(tol);bv(1);sl(1);

        bv(1);espacios(3);
        bv(1);formato_float(x[1]);
        bv(1);formato_float(fx[1]);
        bv(1);formato_float(jx[1][0]);
        bv(1);formato_float(jx[1][1]);
        bv(1);formato_float(j1x[1][0]);
        bv(1);formato_float(j1x[1][1]);
        bv(1);espacios(10);bv(1);sl(1);

        biiv(1);bh(3);
        bii(1);bh(13);
        bii(1);bh(13);
        bii(1);bh(13);
        bii(1);bh(13);
        bii(1);bh(13);
        bii(1);bh(13);
        bii(1);bh(10);bidv(1);sl(1);
    }
    else if (n<100) {

    }
    else if(n<1000){

    }
    else{

    }
}