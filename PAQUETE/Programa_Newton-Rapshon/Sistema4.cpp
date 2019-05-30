int grado4 =3;
float *m_FuncionX4(float *x){
    float *fx = new float[grado4];
    fx[0]=(x[0]*x[0])-(4*x[0])+(x[1]*x[1]);
    fx[1]=(x[0]*x[0])-x[0]-(12*x[1])+1;
    fx[3]=(3*(x[0]*x[0]))-(12*x[0])+(x[1]*x[1])-(3*(x[2]*x[2]))+8;
    return fx;
}


void iniciar4(float *x0, int iteraciones, float tolerancia){
    float *x1, *fx, **jx, **j1x, tol=0;
    esi(1);bh(111);esd(1);sl(1);
    bv(1);espacios(43);printf("M%cTODO DE NEWTON-RAPSHON", eE);espacios(44);bv(1);sl(1);
    biiv(1);bh(111);bidv(1);sl(1);
    bv(1);espacios(39);printf("%c1(x, y, z)=x%c-4x+y%c=0",f,253,253);espacios(50); bv(1);sl(1);
    bv(1);espacios(39);printf("%c2(x, y, z)=x%c-x-12y+1=0",f,253);espacios(48);bv(1);sl(1);
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
        fx = m_FuncionX4(x0);
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