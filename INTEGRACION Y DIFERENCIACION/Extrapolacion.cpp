void crear(double *X,double *Y,float **H,int lim){
	*H=(float *)calloc(sizeof(float),lim);
	if(*H==NULL){
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
void libera3(double **extra,int lim)
{
	int x;
	for(x=0;x<lim;++x)
		free(*(extra+x));
	free(extra);
}
void extrapolacion(double *Xs,double *Ys,int tam,float inter){
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
			imprimeExtrapolacion(Hs,extra,3,valor);
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
				imprimeExtrapolacion(Hs,extra,3,valor);
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
			imprimeExtrapolacion(Hs,extra,tam2,valor);
		}
	}
	libera3(extra,tam2);
}