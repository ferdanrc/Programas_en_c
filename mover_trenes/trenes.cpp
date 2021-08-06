#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>


//	Simulación de la Pista
//   /----HHHHHHH-------------HHHHHHH-------------HHHHHHH----\
//   |														 |
//   |														 |
//   \-------------------------------------------------------/
//			\								  /
//			 ---------------------------------

struct nodo {
	char nombre[15],nombre2[15];
	int treni[3];
    struct nodo *sig;
    struct nodo *sig2;
    struct nodo *ant;
    struct nodo *ant2;
};

struct nodo *pista=NULL;
struct nodo *tren[3]={NULL};
struct nodo *inicio=NULL;
struct nodo *fin=NULL;

void insertar(int tren, int tren2,char* nombre) {
    struct nodo *link = (struct nodo*) malloc(sizeof(struct nodo));
    strcpy(link->nombre, nombre);
    link->treni[0]=0;
    link->treni[1]=tren;
    link->treni[2]=tren2;
	link->sig = pista;
	if(strcmp(nombre,"bifurcacion1")==0)
	{
		strcpy(link->nombre2, "bifurcacion2");
		link->sig2 = pista;
	}
    pista=link;
}

void insertarant(struct nodo* pista) {
    struct nodo *link = pista;
    while(pista->sig != NULL) 
	{
		link=link->sig;
		link->ant=pista;
		pista=link;
	}
	fin=pista;
}

void imprimirsig(struct nodo* ptr) {

    while(ptr != NULL) 
	{
        printf("(%s) ",ptr->nombre);
        if(strlen(ptr->nombre2)>5)
        {
        	printf(", (%s) ",ptr->nombre2);
		}
        printf("\n");
        ptr = ptr->sig;
    }
}

void imprimirant(struct nodo* ptr) {

    while(ptr != NULL) 
	{
        printf("(%s) ",ptr->nombre);
        if(strlen(ptr->nombre2)>5)
        {
        	printf(", (%s) ",ptr->nombre2);
		}
        printf("\n");
        ptr = ptr->ant;
    }
}

void imprimirnodo(struct nodo* ptr) {
		int i=0;
        printf("(%s) ",ptr->nombre);
        for(i=0;i<16-strlen(ptr->nombre);i++)
        {
        	printf(" ");
		}

        if(strlen(ptr->nombre2)>5)
        {
        	printf(", (%s)",ptr->nombre2);
		}
		else
		{
			printf("                ");
		}
		
		if(ptr->treni[1]==1)
    	{
    		printf(" , esta ocupado");
		}
		else
		{
			printf("               ");
		}
		
		if(ptr->treni[2]==1)
		{
			printf(" , el camino alterno esta ocupado ");
		}
		else
		{
			printf("                                  ");
		}
		
		printf("-- ");
		printf(" %d ,",ptr->treni[1]);
    	printf(" %d",ptr->treni[2]);
        printf("\n");
}

void mov_sig(struct nodo* ptr)
{
	while(ptr->sig != NULL) 
	{
		ptr=ptr->sig;
	}
	imprimirnodo(ptr);
	
}

void mov_ant(struct nodo* ptr)
{
	while(ptr->ant != NULL) 
	{
		imprimirnodo(ptr);
		ptr=ptr->ant;
	}	
}

void segmentos_limpios(int seg)
{
	switch(seg)
	{
		case 0://Estacion1
			printf("   +-----------||[     ]||-----");
		break;
		case 1://Tramo1
			printf("-----[     ]-----");
		break;
		case 2://Estacion2
			printf("-----||[     ]||-----");
		break;
		case 3://Tramo2
			printf("-----[     ]-----");
		break;
		case 4://Estacion3
			printf("-----||[     ]||-----------+   \n");
		break;
		case 5://Tramo3
			printf("----[     ]-------+   \n");
		break;
		case 6://Bifurcacion1
			printf("----+---------------------------[     ]----------------------------+----");
		break;
		case 7://Bifurcacion2
			printf("                           |---------------------------[     ]----------------------------|                          \n");
		break;
		case 8://Tramo4
		printf("   +--------[     ]----");
		break;
	}
}

void segmentos_trenes(int seg, int tren)
{
	switch(seg)
	{
		case 0://Estacion1
			printf("   +-----------||[TREN%d]||-----",tren);
		break;
		case 1://Tramo1
			printf("-----[TREN%d]-----",tren);
		break;
		case 2://Estacion2
			printf("-----||[TREN%d]||-----",tren);
		break;
		case 3://Tramo2
			printf("-----[TREN%d]-----",tren);
		break;
		case 4://Estacion3
			printf("-----||[TREN%d]||-----------+   \n",tren);
		break;
		case 5://Tramo3
			printf("----[TREN%d]-------+   \n",tren);
		break;
		case 6://Bifurcacion1
			printf("----+---------------------------[TREN%d]----------------------------+----",tren);
		break;
		case 7://Bifurcacion2
			printf("                           |---------------------------[TREN%d]----------------------------|                          \n",tren);
		break;
		case 8://Tramo4
		printf("   +--------[TREN%d]----",tren);
		break;
	}
}

void imprimir_pista(struct nodo* tren[], char* nombre[])
{
	int i,j,pos[4],segmentos[]={0,1,2,3,4,8,6,5,7},segval,segvalbif,tren8=0;
	printf("\n");
	for(i=0,segvalbif=0;i<9;i++)
	{
		switch(segmentos[i])
		{
			case 0:
				printf("   +            ESTACION1            TRAMO1           ESTACION2            TRAMO2           ESTACION3            +   \n");
			break;
			case 8:
				printf("   |                                                                                                             |   \n");
				printf("   |                                                BIFURCACION1                                                 |   \n");
			break;
			case 7:
				printf("            TRAMO4         |                        BIFURCACION2                          |        TRAMO3            \n");
			break;
		}
		for(j=1,segval=0;j<4;j++)
		{
			if(strcmp(tren[j]->nombre,nombre[segmentos[i]])==0)
			{
				if(strcmp("bifurcacion1",nombre[segmentos[i]])==0)
				{
					segval++;
					if(segvalbif==0)
					{
						segmentos_trenes(segmentos[i],j);
						segvalbif++;
					}else
					{
						segvalbif++;
						tren8=j;
					}
				}
				else
				{
					segmentos_trenes(segmentos[i],j);
					segval++;
				}

			}
		}
		if(segval==0)
		{
			if(segvalbif==2 && i==8)
			{
				segmentos_trenes(segmentos[i],tren8);
			}
			else
			{
			segmentos_limpios(segmentos[i]);
			}
		}
		
	}
	printf("\n");
}

void imprimir_pos_trenes(struct nodo* tren[])
{
	printf("Tren 1 en :");
	imprimirnodo(tren[1]);
	printf("Tren 2 en :");
	imprimirnodo(tren[2]);
	printf("Tren 3 en :");
	imprimirnodo(tren[3]);
}

void Espacios_libres(struct nodo* tren[],int mov_trenes[], int* mov_libres)
{
	int i=0,pp=0,ppi=0;
	for(i=1;i<=3;i++)
	{
		if(mov_trenes[i]==1)
		{
			if(strcmp(tren[i]->ant->nombre,"bifurcacion1")==0)
			{
				if(tren[i]->ant->treni[1]==0)
				{
					printf("El tren %d se puede mover a la bifurcacion 1\n",i);
					mov_libres[i]=1;
				}
				else if(tren[i]->ant->treni[2]==0)
				{
					if(ppi==1)
					{
						printf("El tren %d se puede mover a la bifurcacion 1\n",i);
						mov_libres[i]=1;
					}else
					{
						printf("El tren %d se puede mover a la bifurcacion 2\n",i);
						mov_libres[i]=2;	
					}
					
				}
				else
				{
					if(ppi==1)
					{
						printf("El tren %d se puede mover a la bifurcacion 1\n",i);
						mov_libres[i]=1;
					}
					else if(ppi==2)
					{
						printf("El tren %d se puede mover a la bifurcacion 1\n",i);
						mov_libres[i]=1;
					}
					else
					{
						printf("El tren %d no se puede mover, ambas bifurcaciones estan ocupadas\n",i);
						mov_libres[i]=0;		
					}
				}
			}
			else if(strcmp(tren[i]->nombre,"bifurcacion1")==0)
			{
				if(tren[i]->ant->treni[1]==0)
				{
					if(tren[i]->treni[1]==1 && pp==0)
					{
						printf("El tren %d se puede mover y tiene prioridad\n",i);
						mov_libres[i]=1;
						pp++;
						ppi=1;
					}
					else if(tren[i]->treni[2]==1 && pp==0)
					{
						printf("El tren %d se puede mover de la bifurcacion\n",i);
						mov_libres[i]=1;
						ppi=2;
					}
					else
					{
						printf("El tren %d no se puede mover porque no tiene prioridad\n",i);
						mov_libres[i]=0;
					}
				}
				else
				{
					printf("El tren %d no se puede mover\n",i);
					mov_libres[i]=0;
				}
			}
			else
			{
				if(tren[i]->ant->treni[1]==0)
				{
					printf("El tren %d se puede mover\n",i);
					mov_libres[i]=1;
				}
				else
				{
					printf("El tren %d no se puede mover\n",i);
					mov_libres[i]=0;
				}
			}
		}
	}
}

struct nodo* mover_trenes(struct nodo* tren[])
{
	int i;
	int mov_libres[4]={0};
	int mov_trenes[4]={0};
	double prob=0;
	prob=rand()/(double)(RAND_MAX);
	if(prob<(double)1/7)
	{
		printf("Se mueven los trenes 1, 2 y 3\n");
		mov_trenes[1]=1;
		mov_trenes[2]=1;
		mov_trenes[3]=1;
	}
	else if(prob<(double)2/7)
	{
		printf("Se mueven los trenes 1 y 2 \n");
		mov_trenes[1]=1;
		mov_trenes[2]=1;
	}
	else if(prob<(double)3/7)
	{
		printf("Se mueven los trenes 1 y 3\n");
		mov_trenes[1]=1;
		mov_trenes[3]=1;
	}
	else if(prob<(double)4/7)
	{
		printf("Se mueven los trenes 2 y 3\n");
		mov_trenes[2]=1;
		mov_trenes[3]=1;
	}
	else if(prob<(double)5/7)
	{
		printf("Se mueve el tren 1\n");
		mov_trenes[1]=1;
	}
	else if(prob<(double)6/7)
	{
		printf("Se mueve el tren 2\n");
		mov_trenes[2]=1;
	}
	else
	{
		printf("Se mueve el tren 3\n");
		mov_trenes[3]=1;
	}
	
	Espacios_libres(tren,mov_trenes,mov_libres);
	do
	{
		//printf("mov_trenes=%d %d %d al principio\n",mov_trenes[1],mov_trenes[2],mov_trenes[3]);
		//printf("mov_libres=%d %d %d al principio\n",mov_libres[1],mov_libres[2],mov_libres[3]);
	
		for(i=1;i<=3;i++)
		{
			if(mov_trenes[i]==1 && mov_libres[i]==1)
			{
				if(tren[i]->treni[1]==1)
				{
					tren[i]->treni[1]=0;
				}
				else
				{
					tren[i]->treni[2]=0;
				}
				
				tren[i]=tren[i]->ant;
				tren[i]->treni[1]=1;
				mov_trenes[i]=0;
				mov_libres[i]=0;
			}
			else if(mov_trenes[i]==1 && mov_libres[i]==2)
			{
				tren[i]->treni[1]=0;
				tren[i]=tren[i]->ant;
				tren[i]->treni[2]=1;
				mov_trenes[i]=0;
				mov_libres[i]=0;
			}
		}
		
		//printf("mov_trenes=%d %d %d al final\n",mov_trenes[1],mov_trenes[2],mov_trenes[3]);
		//printf("mov_libres=%d %d %d al final\n",mov_libres[1],mov_libres[2],mov_libres[3]);
		
		if(mov_trenes[1]!=0 || mov_trenes[2]!=0 || mov_trenes[3]!=0)
		{
			//printf("Los trenes pueden moverse todavia\n\n\n\n\n");
			//printf("mov_trenes=%d %d %d al final\n",mov_trenes[1],mov_trenes[2],mov_trenes[3]);
			printf("No todos los trenes se movieron. Recalculando...\n");
			Espacios_libres(tren,mov_trenes,mov_libres);
			//printf("mov_libres=%d %d %d ajuste\n",mov_libres[1],mov_libres[2],mov_libres[3]);
		}
	}while(mov_libres[1]!=0 || mov_libres[2]!=0 || mov_libres[3]!=0);
}

int main() {
	char* nombre[9];
	char movs;
	int i,j;
	
	nombre[0]=strdup("estacion1");
	nombre[1]=strdup("tramo1");
	nombre[2]=strdup("estacion2");
	nombre[3]=strdup("tramo2");
	nombre[4]=strdup("estacion3");
	nombre[5]=strdup("tramo3");
	nombre[6]=strdup("bifurcacion1");
	nombre[7]=strdup("bifurcacion2");
	nombre[8]=strdup("tramo4");
	
	inicio=pista;
	insertar(1,0,nombre[0]);
	insertar(0,0,nombre[1]);
	insertar(1,0,nombre[2]);
	insertar(0,0,nombre[3]);
	insertar(1,0,nombre[4]);
	insertar(0,0,nombre[5]);
	insertar(0,0,nombre[6]);
	insertar(0,0,nombre[8]);

	insertarant(pista);
	inicio=pista;
	
	inicio->ant=fin;
	fin->sig=inicio;
	inicio=inicio->ant;
	fin=fin->sig;
	
	pista=inicio;
	tren[1]=pista;
	tren[2]=pista->ant->ant;
	tren[3]=pista->ant->ant->ant->ant;
	
	imprimir_pista(tren,nombre);
	
	do
	{
		printf("Pulsa s para mover los trenes\n");
		movs=getchar();
		getchar();
		mover_trenes(tren);
		imprimir_pista(tren,nombre);
	}while(movs=='s' || movs=='S');
	
	return 0;
}
