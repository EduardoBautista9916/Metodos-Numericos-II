void iniciar3(float *x0, int iteraciones, float tolerancia);
float **jacobina3(float *x);
float *m_FuncionX3(float *x);
float *calculo_xn3(float *x, float **j1x, float *fx);
float **jacobina_inversa3(float **jx);
float cal_tolerancia3(float *x0, float *x1);
void imprimir3(int n, float *x, float *fx, float **jx, float **j1x, float tol);

int grado3 = 3;

void iniciar3(float *x0, int iteraciones, float tolerancia){
    float *x1, *fx, **jx, **j1x, tol=0;
    esi(1);bh(111);esd(1);sl(1);
    bv(1);espacios(43);printf("M%cTODO DE NEWTON-RAPSHON", eE);espacios(44);bv(1);sl(1);
    biiv(1);bh(111);bidv(1);sl(1);
    bv(1);espacios(39);printf("%c1(x, y, z)=2x%c-4x+y%c+3z%c+6z+2=0",f,253,253,253);espacios(40); bv(1);sl(1);
    bv(1);espacios(39);printf("%c2(x, y, z)=x%c+y%c-2y+2z%c-5=0",f,253, 253, 253);espacios(44);bv(1);sl(1);
    bv(1);espacios(39);printf("%c3(x, y, z)=3x%c-10x+y%c-3z%c+8=0",f,253, 253, 253);espacios(42); bv(1);sl(1);

    biiv(1);bh(3);
    bsih(1);bh(11);
    bsih(1);bh(11);
    bsih(1);bh(35);
    bsih(1);bh(35);
    bsih(1);bh(11);bidv(1);sl(1);

    bv(1);espacios(1);printf("n");espacios(1);
    bv(1);espacios(5);printf("X");espacios(5);
    bv(1);espacios(3);printf("F(X)");espacios(4);
    bv(1);espacios(16);printf("J(X)");espacios(15);
    bv(1);espacios(15);printf("J%c%c(X)", 238,251);espacios(14);
    bv(1);espacios(1);printf("Tolerancia");bv(1);sl(1);

    biiv(1);bh(3);
    bii(1);bh(11);
    bii(1);bh(11);
    bii(1);bh(11);
    bsih(1);bh(11);
    bsih(1);bh(11);
    bii(1);bh(11);
    bsih(1);bh(11);
    bsih(1);bh(11);
    bii(1);bh(11);bidv(1);sl(1);

    for(int i = 0;i <= iteraciones;i++){
        fx = m_FuncionX3(x0);
        jx = jacobina3(x0);
        j1x = jacobina_inversa3(jx);
        x1 = calculo_xn3(x0,j1x,fx);
        imprimir3(i, x0, fx, jx, j1x, tol);
        tol = cal_tolerancia3(x0, x1);
        x0 = x1;
        if(tol<=tolerancia)
            break;
    }
    eii(1);bh(3);
    biih(1);bh(11);
    biih(1);bh(11);
    biih(1);bh(11);
    biih(1);bh(11);
    biih(1);bh(11);
    biih(1);bh(11);
    biih(1);bh(11);
    biih(1);bh(11);
    biih(1);bh(11);eid(1);sl(1);

    system("pause");
}

float **jacobina3(float *x){
    float **jx;
    jx = new float *[grado3];
    for(int i = 0; i<grado3;i++){
        jx[i]=new float[grado3];
    }

    jx[0][0]=(4*x[0])-4;
    jx[0][1]=2*x[1];
    jx[0][2]=(6*x[2])+6;
    jx[1][0]=2*x[0];
    jx[1][1]=(2*x[1])-2;
    jx[1][2]=4*x[2];
    jx[2][0]=(6*x[0])-12;
    jx[2][1]=2*x[1];
    jx[2][2]=-6*x[2];

    return jx;
}

float *m_FuncionX3(float *x){
    float *fx = new float[grado3];
    fx[0]=(2*(x[0]*x[0]))-(4*x[0])+(x[1]*x[1])+(3*(x[2]*x[2]))+(6*x[2])+2;
    fx[1]=(x[0]*x[0])+(x[1]*x[1])-(2*x[1])+(2*(x[2]*x[2]))-5;
    fx[3]=(3*(x[0]*x[0]))-(12*x[0])+(x[1]*x[1])-(3*(x[2]*x[2]))+8;
    return fx;
}

float *calculo_xn3(float *x, float **j1x, float *fx){
    float *xn = new float[grado3];
    xn[0] = x[0]-((j1x[0][0]*fx[0])+(j1x[0][1]*fx[1])+(j1x[0][2]*fx[2]));
    xn[1] = x[1]-((j1x[1][0]*fx[0])+(j1x[1][1]*fx[1])+(j1x[1][2]*fx[2]));
    xn[1] = x[2]-((j1x[2][0]*fx[0])+(j1x[2][1]*fx[1])+(j1x[2][2]*fx[2]));

    return xn;
}

float **jacobina_inversa3(float **jx){
    float **j1x;
    float det;
    j1x = new float *[grado3];
    for(int i = 0; i<grado3;i++){
        j1x[i]=new float[grado3];
    }
    det = (jx[0][0]*jx[1][1]*jx[2][2])+(jx[0][1]*jx[1][2]*jx[2][0])+(jx[0][2]*jx[1][0]*jx[2][1])-(jx[0][2]*jx[1][1]*jx[2][0])-(jx[0][1]*jx[1][0]*jx[2][2])-(jx[0][0]*jx[1][2]*jx[2][1]);
    if(det!=0){
        j1x[0][0]=jx[1][1]/det;
        j1x[0][1]=-jx[0][1]/det;
        j1x[0][2]=-jx[1][0]/det;
        j1x[1][0]=jx[0][0]/det;
        j1x[1][1]=jx[1][1]/det;
        j1x[1][2]=-jx[0][1]/det;
        j1x[2][0]=-jx[1][0]/det;
        j1x[2][1]=jx[0][0]/det;
        j1x[2][2]=jx[0][0]/det;
    }
    else{
        j1x[0][0]=0;
        j1x[0][1]=0;
        j1x[1][0]=0;
        j1x[1][1]=0;
    }
    return j1x;
}

float cal_tolerancia3(float *x0, float *x1){
    float tempX = fabs(fabs(x1[0])-fabs(x0[0]));
    float tempY = fabs(fabs(x1[1])-fabs(x0[1]));
    if(tempX>=tempY)
        return tempX;
    else
        return tempY;
}

void formato_float3(float valor){
    if(valor>=0){
        if (valor==0){
            printf("0.000000000");
        } 
        else if(valor<10){
            printf("%.9f", valor);
        }
        else if(valor<100){
            printf("%.8f", valor);
        }
        else if(valor<1000){
            printf("%.7f", valor);
        }
        else if(valor<10000){
            printf("%.6f", valor);
        }
        else if(valor<100000){
            printf("%.5f", valor);
        }
        else if(valor<1000000){
            printf("%.4f", valor);
        }
        else if(valor<10000000){
            printf("%.3f", valor);
        }
        else if(valor<100000000){
            printf("%.2f", valor);
        }
        else if(valor<1000000000){
            printf("%.1f", valor);
        }
        else{
            printf("###########");
        }
    }
    else{
        if(valor>-10){
            printf("%.8f", valor);
        }
        else if(valor>-100){
            printf("%.7f", valor);
        }
        else if(valor>-1000){
            printf("%.6f", valor);
        }
        else if(valor>-10000){
            printf("%.5f", valor);
        }
        else if(valor>-100000){
            printf("%.4f", valor);
        }
        else if(valor>-1000000){
            printf("%.3f", valor);
        }
        else if(valor>-10000000){
            printf("%.2f", valor);
        }
        else if(valor>-100000000){
            printf("%.1f", valor);
        }
        else{
            printf("###########");
        }
    }
}

void imprimir3(int n, float *x, float *fx, float **jx, float **j1x, float tol){
    if(n<10){
        bv(1);espacios(3);
        bv(1);formato_float3(x[0]);
        bv(1);formato_float3(fx[0]);
        bv(1);formato_float3(jx[0][0]);
        bv(1);formato_float3(jx[0][1]);
        bv(1);formato_float3(jx[0][2]);
        bv(1);formato_float3(j1x[0][0]);
        bv(1);formato_float3(j1x[0][1]);
        bv(1);formato_float3(j1x[0][2]);
        bv(1);espacios(11);bv(1);sl(1);

        bv(1);espacios(3);
        bv(1);espacios(11);
        bv(1);espacios(11);
        biiv(1);bh(11);
        bii(1);bh(11);
        bii(1);bh(11);
        bii(1);bh(11);
        bii(1);bh(11);
        bii(1);bh(11);
        bidv(1);espacios(11);bv(1);sl(1);

        bv(1);espacios(1);printf("%d", n);espacios(1);
        bv(1);formato_float3(x[1]);
        bv(1);formato_float3(fx[1]);
        bv(1);formato_float3(jx[1][0]);
        bv(1);formato_float3(jx[1][1]);
        bv(1);formato_float3(jx[1][2]);
        bv(1);formato_float3(j1x[1][0]);
        bv(1);formato_float3(j1x[1][1]);
        bv(1);formato_float3(j1x[1][2]);
        bv(1);formato_float3(tol);bv(1);sl(1);

        bv(1);espacios(3);
        bv(1);espacios(11);
        bv(1);espacios(11);
        biiv(1);bh(11);
        bii(1);bh(11);
        bii(1);bh(11);
        bii(1);bh(11);
        bii(1);bh(11);
        bii(1);bh(11);
        bidv(1);espacios(11);bv(1);sl(1);

        bv(1);espacios(3);
        bv(1);formato_float3(x[2]);
        bv(1);formato_float3(fx[2]);
        bv(1);formato_float3(jx[2][0]);
        bv(1);formato_float3(jx[2][1]);
        bv(1);formato_float3(jx[2][2]);
        bv(1);formato_float3(j1x[2][0]);
        bv(1);formato_float3(j1x[2][1]);
        bv(1);formato_float3(j1x[2][2]);
        bv(1);espacios(11);bv(1);sl(1);

        biiv(1);bh(3);
        bii(1);bh(11);
        bii(1);bh(11);
        bii(1);bh(11);
        bii(1);bh(11);
        bii(1);bh(11);
        bii(1);bh(11);
        bii(1);bh(11);
        bii(1);bh(11);
        bii(1);bh(11);bidv(1);sl(1);
    }
    else if (n<100) {

    }
    else if(n<1000){

    }
    else{

    }
}