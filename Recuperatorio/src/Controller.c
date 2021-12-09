#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn_biblioteca.h"
#include "parser.h"
#include "Controller.h"
#include "Libro.h"
#define CHARS_LEN 128


int controller_loadFromText(char* path , LinkedList* pArrayListLibro)
{
	int retorno=-1;
	FILE* auxA;
	auxA =fopen(path,"r");
	if(path != NULL && pArrayListLibro != NULL)
	{
		if(auxA!=NULL)
		{
			if(parser_libroFromTextLec(auxA, pArrayListLibro)==0)
			{
				retorno=0;
			}
		}
	}
	fclose(auxA);
    return retorno;
}

int controller_listLibro(LinkedList* pArrayListLibro)
{
	int retorno = -1;
	int i;
	Libro* aux;
	if(pArrayListLibro != NULL && ll_len(pArrayListLibro) > 0)
	{
		for(i =0;i< ll_len(pArrayListLibro); i++)
		{
			aux = (Libro*)ll_get(pArrayListLibro,i);
			libro_imprimir(aux,i);
			retorno = 0;
		}
	}
    return retorno;
}

int controller_sortAutor(LinkedList* pArrayListLibro)
{
	int retorno=-1;
	if(pArrayListLibro!=NULL)
	{
		if(ll_len(pArrayListLibro)>0)
		{
			if(ll_sort(pArrayListLibro, controller_OrdenamientoPorAutor, 1)==0)
			{
				controller_listLibro(pArrayListLibro);
				retorno=0;
			}
		}
	}
    return retorno;
}

int controller_OrdenamientoPorAutor(void* autor1, void* autor2)
{
	int retorno=0;
	Libro* auxA1=autor1;
	Libro* auxA2=autor2;
	char aux1[CHARS_LEN];
	char aux2[CHARS_LEN];

	libro_getAutor(auxA1, aux1);
	libro_getAutor(auxA2, aux2);

	retorno = stricmp(aux1,aux2);

	return retorno;
}

int controller_Descuentos(LinkedList* pArraylistLibro)
{
	int retorno=1;
	LinkedList* aux;
	if(pArraylistLibro!=NULL)
	{
		if((aux = (LinkedList*)ll_map(pArraylistLibro,funcion_Descuentos))==0)
		{
			if(aux != NULL)
			{
				if(controller_saveAsText("mapeado.csv",aux)==0)
				{
					retorno=0;
				}
			}
		}
	}
	return retorno;
}

void funcion_Descuentos(void* pArrayListLibro)
{
	int auxPrecio;
	char auxEditorial[CHARS_LEN];
	int auxPrecioFinal;
	Libro* auxLibro;

	auxLibro = (Libro*) pArrayListLibro;

	if(pArrayListLibro != NULL)
	{
		libro_getEditorial(auxLibro, auxEditorial);
		libro_getPrecio(auxLibro, &auxPrecio);
		if(stricmp(auxEditorial,"Planeta") == 0 && auxPrecio >= 300)
		{
			auxPrecioFinal = auxPrecio * 0.2;
			libro_setPrecio(auxLibro, auxPrecioFinal);
		}
		else if(stricmp(auxEditorial,"SIGLO XXI EDITORES") == 0 && auxPrecio <= 200)
		{
			auxPrecioFinal = auxPrecio * 0.1;
			libro_setPrecio(auxLibro, auxPrecioFinal);
		}

	}
}

int controller_saveAsText(char* path , LinkedList* pArrayListLibro)
{
	int retorno=-1;
	FILE* aux;
	if(pArrayListLibro!=NULL)
	{
		aux = fopen(path,"w");

		if(aux!=NULL)
		{
			parser_libroFromTextEsc(aux, pArrayListLibro);
			retorno=0;
		}
	}
	fclose(aux);
    return retorno;
}

int controller_FilterMinotauro(LinkedList* pArrayListLibro)
{
	int retorno=-1;
	LinkedList* aux;

	if(pArrayListLibro!=NULL)
	{
		aux = ll_filter(pArrayListLibro, filter_Minotauro);

		if(aux!=NULL)
		{
			if(controller_saveAsText("minotauro.csv",aux)==0)
			{
				retorno=0;
			}
		}
	}
	return retorno;
}

int filter_Minotauro(void* pArrayListLibro)
{
	int retorno=1;
	Libro* aux;
	char auxEditorial[CHARS_LEN];

	aux = (Libro*)pArrayListLibro;
	if(aux!=NULL)
	{
		libro_getEditorial(aux,auxEditorial);
		if(stricmp(auxEditorial,"Minotauro")==0 )
		{
			retorno=0;
		}
	}
	return retorno;
}

int controller_ReduceRowling(LinkedList* pArrayListLibro)
{
	int retorno=-1;
	LinkedList* aux;

	if(pArrayListLibro!=NULL)
	{
		aux = (LinkedList*) ll_reduce(pArrayListLibro, reduce_Rowling);
		if(aux != NULL)
		{
			printf("Entre Controller 2");
			retorno=0;
		}
	}
	return retorno;
}

int reduce_Rowling(void* pArrayListLibro)
{
	Libro* aux;
	char auxAutor[CHARS_LEN];
	int auxPrecio;
	int acum = 0;
	int cont = 0;
	int promedio;

	aux = (Libro*)pArrayListLibro;
	if(aux!=NULL)
	{
		libro_getAutor(aux,auxAutor);
		if(stricmp(auxAutor,"Rowling")==0)
		{
			printf("Entre Reduce 2");
			libro_getPrecio(aux, &auxPrecio);
			controller_listLibro(pArrayListLibro);
			acum+=auxPrecio;
			cont++;
		}
	}
	promedio = acum / cont;
	return promedio;
}

