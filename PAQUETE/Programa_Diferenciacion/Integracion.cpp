

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
		sl(1);
        esi(1);bh(27);esd(1);sl(1);
        bv(1);espacios (1);
		printf("La integral es:");formato2_float(intef);
        espacios(1);bv(1);sl(1);
        eii(1);bh(27);eid(1);sl(1);
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
			sl(1);
            esi(1);bh(27);esd(1);sl(1);
            bv(1);espacios (1);
		    printf("La integral es:");formato2_float(intef);
            espacios(1);bv(1);sl(1);
            eii(1);bh(27);eid(1);sl(1);
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
				sl(1);
                esi(1);bh(27);esd(1);sl(1);
                bv(1);espacios (1);
                printf("La integral es:");formato2_float(intef);
                espacios(1);bv(1);sl(1);
                eii(1);bh(27);eid(1);sl(1);
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
					sl(1);
                    esi(1);bh(27);esd(1);sl(1);
                    bv(1);espacios (1);
                    printf("La integral es:");formato2_float(intef);
                    espacios(1);bv(1);sl(1);
                    eii(1);bh(27);eid(1);sl(1);
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
                    sl(1);
                    esi(1);bh(27);esd(1);sl(1);
                    bv(1);espacios (1);
                    printf("La integral es:");formato2_float(intef);
                    espacios(1);bv(1);sl(1);
                    eii(1);bh(27);eid(1);sl(1);
				}
			}
		}
	}
}