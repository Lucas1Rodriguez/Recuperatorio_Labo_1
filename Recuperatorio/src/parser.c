#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Libro.h"

int parser_libroFromTextLec(FILE* pFile , LinkedList* pArraylistLibro)
{
	int retorno=-1;
	int cantidad;
	char bufferId[1024];
	char bufferTitulo[1024];
	char bufferAutor[1024];
	char bufferPrecio[1024];
	char bufferEditorialId[1024];

	Libro* newLibro;

	if(pFile !=NULL && pArraylistLibro != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferTitulo,bufferAutor,bufferPrecio,bufferEditorialId);

		while(!feof(pFile))
		{
			cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferTitulo,bufferAutor,bufferPrecio,bufferEditorialId);

			if(cantidad < 5)
			{
				break;
			}
			newLibro = libro_newParametros(bufferId,bufferTitulo,bufferAutor,bufferPrecio,bufferEditorialId);
			ll_add(pArraylistLibro,newLibro);

			retorno=0;
		}
	}
    return retorno;
}


int parser_libroFromTextEsc(FILE* pFile , LinkedList* pArrayListLibros)
{
	Libro* auxLibro = NULL;
	int retorno=-1;
	int id;
	char titulo[128];
	char autor[128];
	int precio;
	char editorial[128];

	if(pFile!=NULL && pArrayListLibros !=NULL)
	{
		fprintf(pFile, "id,titulo,autor,precio,editorial\n");

		for(int i=0; i<ll_len(pArrayListLibros); i++)
		{
			auxLibro = (Libro*)ll_get(pArrayListLibros, i);
			if(auxLibro!=NULL)
			{
				if(libro_getId(auxLibro, &id)==0 &&
				libro_getTitulo(auxLibro, titulo)==0 &&
				libro_getAutor(auxLibro, autor)==0 &&
				libro_getPrecio(auxLibro, &precio)==0 &&
				libro_getEditorial(auxLibro, editorial)==0)
				{
				fprintf(pFile,"%d,%s,%s,%d,%s\n", id, titulo, autor, precio,editorial);
				retorno=0;
				}
			}
		}
	}

	return retorno;
}
