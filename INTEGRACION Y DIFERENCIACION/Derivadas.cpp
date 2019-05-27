void libera(double *X,double *Y)
{
	free(X);
	free(Y);
}
void libera2(double **De,int tam){
	int x;
	for(x=0;x<tam;++x)
		free(*(De+x));
	free(De);
}
void creafil(double ***D,int tam,double *X,double *Y){
	*D=(double **)calloc(sizeof(double*),tam);
	if(*D==NULL)
	{
		libera(X,Y);
		puts("Error Memoria Insuficiente");
		getch();
		exit(-1);
	}
}
void creacol(double **D,int tam,double *X,double *Y){
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

void Derivadas(double *Xs,double *Ys,int tam, float inter){
	int x;
	double **Deri;
	creafil(&Deri,tam,Xs,Ys);
	creacol(Deri,tam,Xs,Ys);
	for(x=1;x<tam-1;++x)
	{
		*(*(Deri+x)+0)=((*(Ys+(x-1)))-(*(Ys+(x+1))))/(2*inter);
		*(*(Deri+x)+1)=(*(Ys+(x+1))-((*(Ys+x))*2)+(*(Ys+(x-1))))/(pow(inter,2));
	}
    system("pause");
	imprimeTablaDer(Xs,Ys,Deri,tam);
	libera2(Deri,tam);
}