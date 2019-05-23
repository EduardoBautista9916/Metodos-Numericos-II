#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include <iostream>
#include "Barras.cpp"
#include "menus.cpp"
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
 int sistema1(){
     double nx,ny,x,y,fx,fy,a,b,c,d,error,k,p,q,r;
     int iteraciones;

     cout<<"\nNumero de iteraciones:";
     cin>>iteraciones;
     cout<<"\nError estimado:   ";
     cin>>error;
     cout<<"\nValor de x0:   ";
     cin>>x;
     cout<<"\nValor de y0:   ";
     cin>>y;

     for(int i=0;i<iteraciones;i++)
     {
          a=  (1+6*x*y)/((2*x)+y+(12*x*x*y)+(3*x*y*y));//Math
          b=  (- x)/((2*x)+y+(12*x*x*y)+(3*x*y*y));
          c=  (- 3*y*y)/((2*x)+y+(12*x*x*y)+(3*x*y*y));
          d=  ((2*x)+y)/((2*x)+y+(12*x*x*y)+(3*x*y*y));
          fx=(x*x+(x*y)-10) ;
          fy= (y+(3*x*y*y)-57);//Math
          //nuevo vector
          nx=x-(a*fx+b*fy);
          ny=y-(c*fx+d*fy);
          cout<<"\nIteraciones:   "<<i+1;
          cout<<"\nF"<<i<<"(x) = "<<fx<<"    [x"<<i+1<<"]:   "<<nx;
          cout<<"\nF"<<i<<"(y) = "<<fy<<"    [y"<<i+1<<"]:   "<<ny;
          if(x>y)
          {
              p=signo(nx);
              q=signo(x);
              k=p-q;
              r=signo(k);
              cout<<"\nError:   "<<r;
              cout<<"\n";
                if (error>r)
                {
                    cout<<"\nEl error es menor al error estimado presione una tecla para salir.";
                    cout<<"\nVector solucion: \nV(x) = "<<nx<<"	F(x) = "<<fx;
                    cout<<"\nV(y) = "<<ny<<"	F(y) = "<<fy;
                    getch();
                    return (0);
                }
          }

          else
          {
               p=signo(ny);
               q=signo(y);
               k=p-q;
               r=signo(k);
               cout<<"\nError:   "<<r;
               cout<<"\n";
               if(error>r)
               {
                    cout<<"\nEl error es menor al error estimado presione una tecla para salir.";
                    cout<<"\nVector solucion: \nV(x) = "<<nx<<"	F(x) = "<<fx;
                    cout<<"\nV(y) = "<<ny<<"	F(y) = "<<fy;
                    getch();
                    return 0;
               }
          }
     x=nx;
     y=ny;
     getch();
     }
     cout<<"\n Iteraciones completas presione una tecla para salir";
     }

 int sistema2(){
     double nx,ny,x,y,fx,fy,a,b,c,d,e,error,k,p,q,r;
     int iteraciones;
     cout<<"\n Numero de iteraciones:   ";
     cin>>iteraciones;
     cout<<"\n Error estimado:   ";
     cin>>error;
     cout<<"\n Valor de x0:   ";
     cin>>x;
     cout<<"\nValor de y0:   ";
     cin>>y;
     e=2.7182818284590452353602874713527;
     for(int i=0;i<iteraciones;i++)
     {
		  a=  (-1)/(2*x-2*(pow(e,x))*y);//Math
          b=  (2*y)/(2*x-2*(pow(e,x))*y);
          c=  (pow(e,x))/(2*x-2*(pow(e,x))*y);
          d=  (-(2*x))/(2*x-2*(pow(e,x))*y);
          fx=(4-(x*x)-(y*y)) ;
          fy= (1-pow(e,x)-y);//Math
          //nuevo vector
          nx=x-(a*fx+b*fy);
          ny=y-(c*fx+d*fy);
          cout<<"\nIteraciones:   "<<i+1;
          cout<<"\nF"<<i<<"(x) = "<<fx<<"    [x"<<i+1<<"]:   "<<nx;
          cout<<"\nF"<<i<<"(y) = "<<fy<<"    [y"<<i+1<<"]:   "<<ny;

          if(x>y)
          {
              p=signo(nx);
              q=signo(x);
              k=p-q;
              r=signo(k);
              cout<<"\nError:   "<<r;
              cout<<"\n";
              if (error>r)
              {
                   cout<<"\nEl error es menor al error estimado presione una tecla para salir.";
                   cout<<"\nVector solucion: \nV(x) = "<<nx<<"	F(x) = "<<fx;
                   cout<<"\nV(y) = "<<ny<<"	F(y) = "<<fy;
                   getch();
                   return 0;
              }
          }

          else
          {
               p=signo(ny);
               q=signo(y);
               k=p-q;
               r=signo(k);
               cout<<"\nError:   "<<r;
               cout<<"\n";
               if (error>r )
               {
                    cout<<"\nEl error es menor al error estimado presione una tecla para salir.";
					cout<<"\nVector solucion: \nV(x) = "<<nx<<"	F(x) = "<<fx;
                    cout<<"\nV(y) = "<<ny<<"	F(y) = "<<fy;
                    getch();
                    return 0;
               }
          }
     x=nx;
     y=ny;
     getch();
     }
     cout<<"\n Iteraciones completas presione una tecla para salir";
     }
 int sistema3(){
     double nx,ny,nz,x,y,z,fx,fy,fz,a,b,c,d,e,f,h,i,j,error,k,p,q,r=1,eu,pi,rant=1;
     int iteraciones;

     cout<<"\n Da el numero de Iteraciones:   ";
     cin>>iteraciones;
     cout<<"\n Da el error estimado:   ";
     cin>>error;
     cout<<"\n Recomendacion: dar valores cercanos a x=1 , y=-1 , z=0 ";
     cout<<"\n\n Ingresa el valor de x0:   ";
     cin>>x;
     cout<<"\n Ingresa el valor de y0:   ";
     cin>>y;
     cout<<"\n Ingresa el valor de z0:   ";
     cin>>z;
     pi=3.14159265358979323846264338327950288419;
     eu = 2.7182818284590452353602874713527;
     for(int it=0;it<iteraciones;it++)
     {


		  a=  (-12*z+4*y*z)/(-144+72*x+144*y-48*x*y-96*z+24*x*z+32*y*z-8*x*y*z);//Math
          b=  (12*y)/(-144+72*x+144*y-48*x*y-96*z+24*x*z+32*y*z-8*x*y*z);
          c=  (12-12*y+12*z-4*y*z)/(-144+72*x+144*y-48*x*y-96*z+24*x*z+32*y*z-8*x*y*z);
          d=  (-48*z+12*x*z)/(-144+72*x+144*y-48*x*y-96*z+24*x*z+32*y*z-8*x*y*z);
          e=  (72-36*x+48*z-12*x*z)/(-144+72*x+144*y-48*x*y-96*z+24*x*z+32*y*z-8*x*y*z);
          f=  (12*x+16*z*-4*x*z)/(-144+72*x+144*y-48*x*y-96*z+24*x*z+32*y*z-8*x*y*z);
          h=  (-24+12*x+24*y-8*x*y)/(-144+72*x+144*y-48*x*y-96*z+24*x*z+32*y*z-8*x*y*z);
          i=  (-16*y+4*x*y)/(-144+72*x+144*y-48*x*y-96*z+24*x*z+32*y*z-8*x*y*z);
          j=  (8-8*x-8*y+4*x*y)/(-144+72*x+144*y-48*x*y-96*z+24*x*z+32*y*z-8*x*y*z);

          fx=(2*x*x-4*x+y*y+3*z*z+6*z+2 );
          fy= (x*x+y*y-2*y+2*z*z-5);//Math
          fz=(3*x*x-12*x+y*y+3*z*z+8);
		  //nuevo vector
          nx=x-(a*fx+b*fy+c*fz);
          ny=y-(d*fx+e*fy+f*fz);
          nz=z-(h*fx+i*fy+j*fz)          ;
          cout<<"\nIteraciones:   "<<it+1;
          cout<<"\nF"<<it<<"(x) = "<<fx<<"    [x"<<it+1<<"]:   "<<nx;
          cout<<"\nF"<<it<<"(y) = "<<fy<<"    [y"<<it+1<<"]:   "<<ny;
          cout<<"\nF"<<it<<"(z) = "<<fz<<"    [z"<<it+1<<"]:   "<<nz;

          if(x>y && x>z)
          {
              p=signo(nx);
              q=signo(x);
              k=p-q;
              r=signo(k);
              cout<<"\nError :   "<<r;
              cout<<"\n";
              if (error>r)
              {
                    cout<<"\nEl error es menor al error estimado presione una tecla para salir.";
                    cout<<"\nVector solucion: \n(x) = "<<nx<<"	F(x) = "<<fx;
                    cout<<"\n(y) = "<<ny<<"	F(y) = "<<fy;
                    cout<<"\n(z) = "<<nz<<"	F(z) = "<<fz;
                    getch();
                    return 0;
              }
          }

          if(y>x && y>z)
          {
              p=signo(ny);
              q=signo(y);
              k=p-q;
              r=signo(k);
               cout<<"\nError :   "<<r;
               cout<<"\n";
                                                        if (error>r )  {
                                                                                        cout<<"\nEl error es menor al error estimado presione una tecla para salir.";
																						cout<<"\nVector solucion: \n(x) = "<<nx<<"	F(x) = "<<fx;
                                                                                        cout<<"\n(y) = "<<ny<<"	F(y) = "<<fy;
                                                                                        cout<<"\n(z) = "<<nz<<"	F(z) = "<<fz;

                                                                                        getch();
                                                                                        return 0;
                                                                                        }
               }

          if(z>x && z>y) {
               p=signo(nz);
              q=signo(z);
              k=p-q;
              r=signo(k);

               cout<<"\nError :   "<<r;
               cout<<"\n";
                                                        if (error>r )  {
                                                                                        cout<<"\nEl error es menor al error estimado presione una tecla para salir.";
																						cout<<"\n\nComprobacion:\nF(x) = "<<fx<<"\nF(y) = "<<fy<<"\nF(z)="<<fz;

                                                                                        getch();
                                                                                        return 0;
                                                                                        }
               }
    if(r>(rant+1000)){
         																				cout<<"\nEl sistema no converge ya que el error se hace cada vez mas grande.";
         																				cout<<"\nInicie de nuevo el programa porfavor ";
																						cout<<"\nRecuerde con  valores cercanos a: x=1 , y=-1 , z=0.";

                                                                                        getch();
                                                                                        return 0;

		 }
      rant=r;

     x=nx;
     y=ny;
     z=nz;
     getch();

     }
     cout<<"\n Iteraciones Completas presione una tecla para salir";
     }
 int sistema4(){ //queda pendiente por que no se interceptan
     double nx,ny,nz,x,y,z,fx,fy,fz,a,b,c,d,e,f,h,i,j,error,k,p,q,r=1,eu,pi,rant=1;
     int iteraciones;

     cout<<"\n Da el numero de Iteraciones:   ";
     cin>>iteraciones;
     cout<<"\n Da el error estimado:   ";
     cin>>error;
     cout<<"\n Recomendacion 1: dar valores a x=0 , y=0 , z=0 lleva a una indeterminacion";
     cout<<"\n Recomendacion 2: No dar valores muy grandes de lo contrario no se garantiza la convergencia";
     cout<<"\n\n Ingresa el valor de x0:   ";
     cin>>x;
     cout<<"\n Ingresa el valor de y0:   ";
     cin>>y;
     cout<<"\n Ingresa el valor de z0:   ";
     cin>>z;
     pi=3.14159265358979323846264338327950288419;
     eu = 2.7182818284590452353602874713527;
         if(x==0)
          {
           if(y==0) {
                    if(z==0){
                                                                                       a=  (-72*z)/(288*z-144*x*z+12*y*z-24*x*y*z);//Math
          b=  (-12*z*y)/(288*z-144*x*z+12*y*z-24*x*y*z);
          c=  0;
          d=  (6*z-12*x*z)/(288*z-144*x*z+12*y*z-24*x*y*z);
          e=  (-24*z+12*x*z)/(288*z-144*x*z+12*y*z-24*x*y*z);
          f=  0;
          h=  (-144+72*x-2*y+4*x*y)/(288*z-144*x*z+12*y*z-24*x*y*z);
          i=  (-16*y+8*x*y)/(288*z-144*x*z+12*y*z-24*x*y*z);
          j=  (48-24*x+2*y-4*x*y)/(288*z-144*x*z+12*y*z-24*x*y*z);

          fx=(x*x-4*x+y*y );
          fy= (x*x-x-12*y+1);//Math
          fz=(3*x*x-12*x+y*y+3*z*z+8);
		  //nuevo vector
          nx=x-(a*fx+b*fy+c*fz);
          ny=y-(d*fx+e*fy+f*fz);
          nz=z-(h*fx+i*fy+j*fz);


                                                                                       cout<<"\nEl sistema se indetermina como se muestra en la primera iteracion";
                                                                                       cout<<"\nF(x) = "<<fx<<"    [x]:   "<<nx;
          																			   cout<<"\nF(y) = "<<fy<<"    [y]:   "<<ny;
          																			   cout<<"\nF(z) = "<<fz<<"    [z]:   "<<nz;

                                                                                       getch();
                                                                                       return 0;

          }}}



     cout<<"\n El sistema no se intercepta para las 3 ecuaciones";
     cout<<"\n lo que hace que solo converge [x] y [y] ";
     cout<<"\n por que estas variables si se interceptan para";
     cout<<"\n la primera y segunda ecuacion pero no para la tercera.";
     cout<<"\n Las tres ecuaciones no se interceptan al graficar las ecuaciones.\n\n\n";
     for(int it=0;it<iteraciones;it++)
     {


		  a=  (-72*z)/(288*z-144*x*z+12*y*z-24*x*y*z);//Math
          b=  (-12*z*y)/(288*z-144*x*z+12*y*z-24*x*y*z);
          c=  0;
          d=  (6*z-12*x*z)/(288*z-144*x*z+12*y*z-24*x*y*z);
          e=  (-24*z+12*x*z)/(288*z-144*x*z+12*y*z-24*x*y*z);
          f=  0;
          h=  (-144+72*x-2*y+4*x*y)/(288*z-144*x*z+12*y*z-24*x*y*z);
          i=  (-16*y+8*x*y)/(288*z-144*x*z+12*y*z-24*x*y*z);
          j=  (48-24*x+2*y-4*x*y)/(288*z-144*x*z+12*y*z-24*x*y*z);

          fx=(x*x-4*x+y*y );
          fy= (x*x-x-12*y+1);//Math
          fz=(3*x*x-12*x+y*y+3*z*z+8);
		  //nuevo vector
          nx=x-(a*fx+b*fy+c*fz);
          ny=y-(d*fx+e*fy+f*fz);
          nz=z-(h*fx+i*fy+j*fz)          ;
          cout<<"\nIteraciones:   "<<it+1;
          cout<<"\nF"<<it<<"(x) = "<<fx<<"    [x"<<it+1<<"]:   "<<nx;
          cout<<"\nF"<<it<<"(y) = "<<fy<<"    [y"<<it+1<<"]:   "<<ny;
          cout<<"\nF"<<it<<"(z) = "<<fz<<"    [z"<<it+1<<"]:   "<<nz;



          if(x>y)
          {
              p=signo(nx);
              q=signo(x);
              k=p-q;
              r=signo(k);
              cout<<"\nError :   "<<r;
              cout<<"\n";
                                                       if (error>r){
                                                                                       cout<<"\nComo se explico z no converge asi que F(z) es diferente a 0";
                                                                                       cout<<"\nEl error es menor al error estimado para X y para Y "<<"\nResultado de Funciones:\nF(x) ="<<fx<<"\nF(y) = "<<fy<<"\nF(z) = "<<fz;
                                                                                       getch();
                                                                                       return 0;
                                                                                    }
          }

          else {
               p=signo(ny);
              q=signo(y);
              k=p-q;
              r=signo(k);

               cout<<"\nError :   "<<r;
               cout<<"\n";
                                                        if (error>r )  {
                                                                                        cout<<"\nComo se explico z no converge asi que F(z) es diferente a 0";
                                                                                       cout<<"\nEl error es menor al error estimado para X y para Y "<<"\n\nResultado de Funciones:\nF(x) ="<<fx<<"\nF(y) = "<<fy<<"\nF(z)="<<fz;
                                                                                       getch();
                                                                                       return 0;
                                                                                        }
               }


    if(r-rant>1000){
         																				cout<<"\nEl sistema no converge ya que el error se hace cada vez mas grande.";
         																				cout<<"\nInicie de nuevo el programa porfavor ";
																						cout<<"\nRecuerde con  valores: x=0 , y=0 , z=0, se indetermina el sistema.";
																						getch();
                                                                                        return 0;

		 }
      rant=r;
      rant=signo(rant);

     x=nx;
     y=ny;
     z=nz;
     getch();



     }
     cout<<"\n Iteraciones Completas presione una tecla para salir";
     }
int menu1(){
cout << "\t\tMetodos numericos II" << endl;
cout << "\tPaquete Final" << endl;
cout << "\tSistemas de ecuacionales no lineales" << endl;
cout << "\tInterpolacion y ajuste de curvas" << endl;
cout << "\tDiferenciacion e integracion (Datos igualmente espaciados)" << endl;
cout << "\tGrupo: 2403" << endl;
cout << "\t\tEquipo:" << endl;
cout << "\tAlvarez Cortes Kevin Alejandro" << endl;
cout << "\tBautista Gaona Luis Eduardo" << endl;
cout << "\tFlores Hernandez Itzel" << endl;
cout << "\tFlores Velasco Jose Juan\n\n" << endl;

return 0;
}
int menu12(){
	cout<<"\t\tDigite (1).       Sistema 1:  f1(x,y)= x^2+xy-10;   f2(x,y)= y+3xy^2-57\n";
    cout<<"\t\tDigite (2).       Sistema 2:  f1(x,y)= 4-x^2-y^2;   f2(x,y)= 1-e^x-y; \n\n";
    cout<<"\t\tDigite (3).       Sistema 3:  f1(x,y,z)= 2x^2-4x+y^2+3z^2+6z+2;\n";
    cout<<"\t\t                     f2(x,y,z)=x^2+y^2-2y+2z^2-5;\n";
    cout<<"\t\t                     f3(x,y,z)= 3x^2-12x+y^2+3z^2+8;\n\n";
    cout<<"\t\tDigite (4).       Sistema 4:  f1(x,y,z)= x^2-4x+y^2;\n";
    cout<<"\t\t                     f2(x,y,z)= x^2-x-12y+1;\n";
    cout<<"\t\t                     f3(x,y,z)= 3x^2-12x+y^2+3z^2+8;\n\n";
    cout<<"\t\tDigite (5).   Para Salir\n\n";
    cout<<"\t\tOpcion:  ";
return 0;
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
}void crearTabla(int **K,double **Xs,double **Ys,int *tam)
{
	puts("Cuantas datos se insertaran en la tabla?");
	scanf("%d",tam);
	*K=(int *)calloc(sizeof(int),*tam);
	*Xs=(double *)calloc(sizeof(double),*tam);
	*Ys=(double *)calloc(sizeof(double),*tam);
	if(*Xs==NULL&&*Ys==NULL)
	{
		puts("Error Memoria Insuficiente");
		getch();
		exit(-1);
	}
}
void Llenar(double *Xs, double *Ys,int tam,float *inter)
{
	int x;
	float h,h2;
	puts("Recuerda que las X's deben de estar igualmente espaciadas");
	for(x=0;x<tam;++x)
	{
		printf("Digita el valor de X%d\n",x);
		if(x==0)
			scanf("%lf",(Xs+x));
		else
			if(x==1)
			{
				scanf("%lf",(Xs+x));
				*inter=(*(Xs+0)-(*(Xs+1)));
				h=*inter;
				if(h<0)
				h*=-1;
			}
			else
			{
				do
				{
					scanf("%lf",(Xs+x));
					h2=(*(Xs+(x-1))-(*(Xs+x)));
					if(h2<0)
						h2*=-1;
					if(h2!=h)
						printf("Recuerda que las X's deben estar igualmente espaciadas\nDigita otro numero porfavor con separacion de (%.8lf)\n",h);
					else
						if(*(Xs+(x-2))==*(Xs+x))
							puts("Valor de X repetido por favor digitar otro");
				}
				while(h2!=h||*(Xs+(x-2))==*(Xs+x));
			}
		printf("Digita el valor de Y%d(\"F(x%d))\"\n",x,x);
		scanf("%lf",(Ys+x));
	}
}
void Imprime(double *X,double *Y,int tam)
{
	int z;
	puts("Tabla dada\n|     X    |  |  f(x)    |");
	for(z=0;z<tam;++z)
		printf("|%4.8lf|  |%4.8lf|\n",*(X+z),*(Y+z));
}
void libera(double *X,double *Y)
{
	free(X);
	free(Y);
}
void libera2(double **De,int tam)
{
	int x;
	for(x=0;x<tam;++x)
		free(*(De+x));
	free(De);
}
void creafil(double ***D,int tam,double *X,double *Y)
{
	*D=(double **)calloc(sizeof(double*),tam);
	if(*D==NULL)
	{
		libera(X,Y);
		puts("Error Memoria Insuficiente");
		getch();
		exit(-1);
	}
}
void creacol(double **D,int tam,double *X,double *Y)
{
	int x,y;
	for(x=0;x<tam;++x)
	{
		*(D+x)=(double *)calloc(sizeof(double),2);
		if(*(D+x)==NULL)
		{
			if(x==0)
			free(D);
			else
			{
				for(y=x;y>=0;--y)
				{
					free(*(D+y));
				}
			}
			free(D);
			libera(X,Y);
			puts("Error Memoria Insuficiente");
			getch();
			exit(-1);
		}
	}
}
void imprime2(double *X,double *Y,double **De,int tam)
{
	int x,y;
	printf("Tabla dada\n|     X    |  |  f(x)    |  F'(x)    |  |   F''(x)   |\n");
	for(x=0;x<tam;++x)
	{
		printf("|%4.8lf|  |%4.8lf|  ",*(X+x),*(Y+x));
		//if(x>0&&x<tam-1)
		//{
			for(y=0;y<2;++y)
			printf("|%4.8lf|  ",*(*(De+x)+y));
		//}
		putchar('\n');
	}
}
void Derivadas(double *Xs,double *Ys,int tam, float inter)
{
	int x;
	double **Deri;
	creafil(&Deri,tam,Xs,Ys);
	creacol(Deri,tam,Xs,Ys);
	for(x=1;x<tam-1;++x)
	{
		*(*(Deri+x)+0)=((*(Ys+(x-1)))-(*(Ys+(x+1))))/(2*inter);
		*(*(Deri+x)+1)=(*(Ys+(x+1))-((*(Ys+x))*2)+(*(Ys+(x-1))))/(pow(inter,2));
	}
	imprime2(Xs,Ys,Deri,tam);
	libera2(Deri,tam);
}
void crear(double *X,double *Y,float **H,int lim)
{
	*H=(float *)calloc(sizeof(float),lim);
	if(*H==NULL)
	{
		libera(X,Y);
		puts("Error memoria insuficiente");
		getch();
		exit(-1);
	}
}
void crea2fil(double ***extra,int lim,double *X,double *Y)
{
	*extra=(double **)calloc(sizeof(double *),lim);
	if(*extra==NULL)
	{
		libera(X,Y);
		puts("Error Memoria Insuficiente");
		getch();
		exit(-1);
	}
}
void crea2col(double **extra,int lim,double *X,double *Y)
{
	int x,y;
	for(x=0;x<lim;++x)
	{
		*(extra+x)=(double *)calloc(sizeof(double),lim);
		if(*(extra+x)==NULL)
		{
			if(x==0)
			free(extra);
			else
			{
				for(y=x;y>=0;--y)
				{
					free(*(extra+y));
				}
			}
			libera(X,Y);
			free(extra);
			puts("Error Memoria Insuficiente");
			getch();
			exit(-1);
		}
	}
	puts("Hola");
}
void richardson(double *X,double *Y,float *H,int tam,int lim,double **extra,int grad,int posib)
{
	int z,n,g;
	for(n=0;n<posib;++n)
	{
		for(z=0;z<posib-n;++z)
		{
			if(grad==1)
			{
				if(n==0)
				{
					*(*(extra+z)+n)=((*(Y+(lim+(z+1))))-(*(Y+(lim-(z+1)))))/(*(H+z)*2);
				}
				else
				{
					g=pow(2,2*n);
					*(*(extra+z)+n)=*(*(extra+z)+(n-1))+(((((*(*(extra+z)+(n-1)))))-(*(*(extra+(z+1))+(n-1))))/(g-1));
				}
			}
			else
			{
				if(n==0)
				{
					*(*(extra+z)+n)=(*(Y+(lim+(z+1)))-((*(Y+lim))*2)+(*(Y+(lim-(z+1)))))/(pow(*(H+z),2));
				}
				else
				{
					g=pow(2,2*n);
					*(*(extra+z)+n)=*(*(extra+z)+(n-1))+(((((*(*(extra+z)+(n-1)))))-(*(*(extra+(z+1))+(n-1))))/(g-1));
				}
			}
		}
	}
}
void richardsonInt(double *X,double *Y,float *H,int tam,int lim,double **extra,int grad,int posib,float inter,int lon)
{
	int z,n,g,espa;
	for(n=0;n<posib;++n)
	{
		for(z=0;z<posib-n;++z)
		{
			if(grad==1)
			{
				if(n==0)
				{
					for(espa=1;espa<=lon&&(espa*(-1*inter))!=*(H+z);++espa);
					*(*(extra+z)+n)=(*(Y+(lim+espa))-(*(Y+(lim-espa))))/(*(H+z)*2);
				}
				else
				{
					g=pow(2,2*n);
					*(*(extra+z)+n)=*(*(extra+z)+(n-1))+(((((*(*(extra+z)+(n-1)))))-(*(*(extra+(z+1))+(n-1))))/(g-1));
				}
			}
			else
			{
				if(n==0)
				{
					for(espa=1;espa<=lon&&(espa*(-1*inter))!=*(H+z);++espa);
					*(*(extra+z)+n)=(*(Y+(lim+espa))-((*(Y+lim))*2)+(*(Y+(lim-espa))))/(pow(*(H+z),2));
				}
				else
				{
					g=pow(2,2*n);
					*(*(extra+z)+n)=*(*(extra+z)+(n-1))+(((((*(*(extra+z)+(n-1)))))-(*(*(extra+(z+1))+(n-1))))/(g-1));
				}
			}
		}
	}
}
void imprime(float *H,double **extra,int lim,double valor)
{
	int x,y;
	printf("|    h      |  |  F'[%4.4lf]  |  |Extra de 1 orden|  |Extra de 2 orden|\n",valor);
	for(x=0;x<lim;++x)
		printf("|%4.8lf|  |%4.8lf|  |%4.8lf|  |%4.8lf|\n",*(H+x),*(*(extra+x)+0),*(*(extra+x)+1),*(*(extra+x)+2));
}
void libera3(double **extra,int lim)
{
	int x;
	for(x=0;x<lim;++x)
		free(*(extra+x));
	free(extra);
}
void extrapolacion(double *Xs,double *Ys,int tam,float inter)
{
	float *Hs;
	double valor,**extra;
	int hs,lim,x,y,cont,cent=0,posib,tam2,mult,residuo;
	puts("Digite el valor de X que se desea extrapolar de la tabla de valores dados\nSe recomienda dar el valor que sea mayor apartir de X2\n Y tambien menor a X(n-2)");
	do
	{
		scanf("%lf",&valor);
		for(cont=0;cont<tam&&valor!=(*(Xs+cont));++cont);
		if(cont==tam)
		{
			cent=1;
		}
		else
		{
			lim=cont;
			cent=0;
		}
		if(cent!=0)
			puts("Digite un valor que pertenezca a la tabla de valores porfavor\nDigite un nuevo valor porfavor");
		else
			if(lim<3&&lim>tam-4)
				puts("Digite un valor que sea mayor a x2, para tener tres valores a interpolar\nDigite un nuevo valor porfavor\n Y tambien menor a X(n-2)");
	}
	while(cent!=0&&lim<3&&lim>tam-4);
	if(lim==3||lim==tam-4)
	{
		if(lim==tam-4)
		{
			crear(Xs,Ys,&Hs,3);
			for(x=0;x<3;++x)
				*(Hs+x)=-1*(inter*(x+1));
			crea2fil(&extra,3,Xs,Ys);
			crea2col(extra,3,Xs,Ys);
			for(y=1;y<=2;++y)
			{
				richardson(Xs,Ys,Hs,tam,lim,extra,y,3);
			}
			imprime(Hs,extra,3,valor);
		}
		else
		{
			crear(Xs,Ys,&Hs,3);
			for(x=0;x<3;++x)
				*(Hs+x)=-1*(inter*(x+1));
			crea2fil(&extra,3,Xs,Ys);
			crea2col(extra,3,Xs,Ys);
			for(y=1;y<=2;++y)
			{
				richardson(Xs,Ys,Hs,tam,lim,extra,y,3);
				imprime(Hs,extra,3,valor);
			}
		}

	}
	else
	{
		posib=(tam-1)/2;
		printf("Recuerda que necesitas 3 y tienes %d posibles intervalos de h\nPuedes iniciar con h=%f\n",posib,-1*inter);
		tam2=3;
		crear(Xs,Ys,&Hs,tam2);
			for(x=0;x<tam2;++x)
			{
				do
				{
					puts("Digita un intervalo de h");
					scanf("%f",(Hs+x));
					mult=*(Hs+x)/inter;
					residuo=(mult*inter)-*(Hs+x);
					if(residuo!=0||*(Hs+x)<(-1*inter))
					{
						puts("Digite un intervalo que sea multiplo del espacio de X's de la tabla\nY que sea mayor al intervalo original");
						cent=1;
					}
					else
					{
						if(x>0)
						{
							for(y=x;y>0;--y)
							{
								if(*(Hs+x)==*(Hs+(y-1))||*(Hs+x)<*(Hs+(y-1)))
								{
									puts("Digita un intervalo mayor y que sea multiplo porfavor");
									cent=1;
									break;
								}
							}
						}
						else
						 cent=0;
					}
				}
				while(cent!=0);
			}
		crea2fil(&extra,tam2,Xs,Ys);
		crea2col(extra,tam2,Xs,Ys);
		for(y=1;y<=2;++y)
		{
			richardsonInt(Xs,Ys,Hs,tam,lim,extra,y,tam2,inter,posib);
			imprime(Hs,extra,tam2,valor);
		}
	}
	libera3(extra,tam2);
}
void integracion(double *Xs,double *Ys,int tam)
{
	double inte=0.0,inte2=0.0,intef=0.0;
	float h=0.0;
	int s=0,e=0,aux=0;
	h=(*(Xs+1))-(*(Xs+0));
	if(tam==6)
	{

		inte=(4*(*(Ys+1)))+(*(Ys+0))+(*(Ys+2));
		inte*=h;
		inte/=3;
		for(e=3;e<tam;++e)
		{
			inte2+=(3*(*(Ys+e)));
		}
		inte2+=(*(Ys+2))+(*(Ys+(tam-1)));
		inte2*=(3*h);
		inte2/=8;
		intef=inte+inte2;
		printf("La integral es:%lf\n",intef);
	}
	else
	{
		if(tam==8)
		{
			for(e=1;e<=3;e+=2)
			{
				inte+=(4*(*(Ys+e)));
			}
			inte+=(*(Ys+0))+(*(Ys+4))+(2*(*(Ys+2)));
			inte*=h;
			inte/=3;
			for(e=5;e<=6;++e)
			{
				inte2+=(3*(*(Ys+e)));
			}
			inte2+=(*(Ys+4))+(*(Ys+(tam-1)));
			inte2*=(3*h);
			inte2/=8;
			intef=inte+inte2;
			printf("La integral es:%lf\n",intef);
		}
		else
		{
			if(tam==10)
			{
				for(e=1;e<=5;e+=2)
				{
					inte+=(4*(*(Ys+e)));
				}
				for(e=2;e<=4;e+=2)
				{
					inte2+=(2*(*(Ys+e)));
				}
				inte+=(*(Ys+0))+(*(Ys+6));
				inte*=h;
				inte/=3;
				for(e=7;e<=9;++e)
				{
					inte2+=(3*(*(Ys+e)));
				}
				inte2+=(*(Ys+6))+(*(Ys+(tam-1)));
				inte2*=(3*h);
				inte2/=8;
				intef=inte+inte2;
				printf("La integral es:%lf\n",intef);
			}
			else
			{
				s=tam%2;
				if(s!=0)
				{
					for(e=1;e<=tam-1;e+=2)
					{
						inte+=(4*(*(Ys+e)));
					}
					for(e=2;e<=tam-2;e+=2)
					{
						inte2+=(2*(*(Ys+e)));
					}
					intef=inte2+inte;
					intef+=(*(Ys+0))+(*(Ys+(tam-1)));
					intef*=h;
					intef/=3;
					printf("La integral es:%lf\n",intef);
				}
				else
				{
					aux=tam-4;
					for(e=1;e<aux;e+=2)
					{
						inte+=(4*(*(Ys+e)));
					}
					for(e=2;e<aux-1;e+=2)
					{
						inte+=(2*(*(Ys+e)));
					}
					inte+=(*(Ys+0))+(*(Ys+aux));
					inte*=h;
					inte/=3;
					for(e=aux+1;e<tam;++e)
					{
						inte2+=(3*(*(Ys+e)));
					}
					inte2+=(*(Ys+aux))+(*(Ys+(tam-1)));
					inte2*=(3*h);
					inte2/=8;
					intef=inte+inte2;
					printf("La integral es:%lf\n",intef);
				}
			}
		}
	}
}
main(){
	int metods;
	bienvenida();
	menu();
	printf("Que opcion desea Realizar:\n>");
	scanf("%d", &metods);
	switch(metods){
			case 1:
				{
					int op;
					char c;
    				do{
    					system("cls");
    					puts("\t\t\t Metodos Numericos 2");
    					puts("\t\t(1)Sistemas de Ecuaciones no Lineales");
    					menu12();
    					do
    					{
						}
						while(scanf("%d%c",&op,&c)==2&&c!='\n');
						fflush(stdin);

					   	switch (op)
						   {

	                    		case 1:
	                        	{
									system("cls");
    	                            sistema1();
    	                        }
        	                	break;

                        		case 2:
                        			{
										system("cls");
                                		sistema2();
                                	}
                                break;
                        		case 3:
                        			{
										system("cls");
                                		sistema3();
                                	}
                                break;
                         		case 4:
                         			{
										system("cls");
                                		sistema4();
                                	}
                            	break;
	                    }
	                        if(op<1||op>5)
	                        	cout<<"Digite una de las opciones dadas porfavor. \n\"Apreta cualquier tecla para continuar\"";
    				}while(op!=5);
					cout<<"\n\"Apreta cualquier tecla para continuar\"";
				    getch();

				}
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
				{
					double *X,*Y;
					float inter;
					int *K,tam,op,op2,op3,cent=0;
					system("cls");
					puts("\t\t(3)Diferenciacion e Integracion");
					crearTabla(&K,&X,&Y,&tam);
					Llenar(X,Y,tam,&inter);
					Imprime(X,Y,tam);
					do
					{
						do
						{
							puts("Que quieres hacer? \n(1)Derivar\n(2)Extrapolar\n(3)Integrar");
							do
							{
								scanf("%d",&op);
								if(op<1||op>3)
									printf("Digite una de las opciones porfavor");
							}
							while(op<1||op>3);
							if(op==2&&tam<7)
							{
								cent=1;
								puts("El minimo de valores para extrapolar son 7 valores digite otra opcion porfavor");
							}
							else
								cent=0;
						}
						while(cent!=0);
						switch(op)
						{
							case 1:
							{
								system("cls");
								Imprime(X,Y,tam);
								Derivadas(X,Y,tam,inter);
							}
							break;
							case 2:
							{
								system("cls");
								Imprime(X,Y,tam);
								extrapolacion(X,Y,tam,inter);
							}
							break;
							case 3:
							{
								system("cls");
								Imprime(X,Y,tam);
								integracion(X,Y,tam);
							}
							break;
						}
						printf("Desea Hacer otro metodo?\n(1)Si\n(2)No\n");
						do
						{
							scanf("%d",&op2);
							if(op2<1||op2>2)
								printf("Digite una de las opciones porfavor\nDigite una opcion porfavor\n");
						}
						while(op2<1||op2>2);
						if(op2!=2)
						{
							puts("Desea nuevos valores de la tabla?\n(1)Si\n(2)No\n");
							do
							{
								scanf("%d",&op3);
								if(op3<1||op3>2)
									printf("Digite una de las opciones porfavor\n");
							}
							while(op3<1||op3>2);
							if(op3==1)
							{
								system("cls");
								Llenar(X,Y,tam,&inter);
							}
						}
					}
					while(op2!=2);
					libera(X,Y);
				}
			break;
	}
	
	system("cls");
	despedida();
	puts("Gracias por usar el programa..\nAprieta cualquiera tecla para terminar");
	getch();
}
