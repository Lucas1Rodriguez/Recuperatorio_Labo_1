/*
 * Libro.c
 *
 *  Created on: 29 nov. 2021
 *      Author: USURIO
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn_biblioteca.h"
#include "Libro.h"
#include "Validacion.h"
#define CHARS_LEN 128


Libro* libro_new()
{
	Libro* pArcadeAux = NULL;

	pArcadeAux = (Libro*) malloc(sizeof(Libro));

	return pArcadeAux;
}

Libro* libro_newParametros(char* idStr,char* tituloStr,char* autorStr, char* precioStr,char* editorialStr)
{
	Libro* pLibro = NULL;

	pLibro = libro_new();
	if(pLibro != NULL && idStr != NULL && tituloStr != NULL && autorStr != NULL && precioStr != NULL && editorialStr != NULL)
	{
		if(libro_setId(pLibro,atoi(idStr)) == -1 ||
		libro_setTitulo(pLibro,tituloStr) == -1 ||
		libro_setAutor(pLibro,autorStr) == -1 ||
		libro_setPrecio(pLibro,atoi(precioStr)) == -1 ||
		libro_setEditorial(pLibro,editorialStr) == -1)
		{
			printf("Algo salio mal \n");
			free(pLibro);
		}
	}
	return pLibro;
}

int libro_setId(Libro* this, int id)
{
    int retorno=1;
    if(this!=NULL && id>=0 )
    {

        this->id=id;
        retorno=0;
    }

    return retorno;
}

int libro_getId(Libro* this, int* id)
{
    int retorno=1;
    if(this!=NULL)
    {
        *id = this->id;
        retorno=0;
    }

    return retorno;
}

int libro_setTitulo(Libro* this,char* titulo)
{
    int retorno=1;
    if(this!=NULL &&  titulo!=NULL)
    {
        strncpy(this->titulo,titulo,CHARS_LEN);

        retorno=0;
    }
    return retorno;
}

int libro_getTitulo(Libro* this,char* titulo)
{
    int retorno=1;
    if(this!=NULL)
    {
        strncpy(titulo,this->titulo,CHARS_LEN);
        retorno=0;
    }
    return retorno;
}

int libro_setAutor(Libro* this,char* autor)
{
    int retorno=1;
    if(this!=NULL &&  autor!=NULL)
    {
        strncpy(this->autor,autor,CHARS_LEN);

        retorno=0;
    }
    return retorno;
}

int libro_getAutor(Libro* this,char* autor)
{
    int retorno=1;
    if(this!=NULL)
    {
        strncpy(autor,this->autor,CHARS_LEN);
        retorno=0;
    }
    return retorno;
}


int libro_setPrecio(Libro* this,int precio)
{
    int retorno=1;
    if(this!=NULL && precio>=0)
    {
        this->precio=precio;
        retorno=0;
    }
    return retorno;
}

int libro_getPrecio(Libro* this,int* precio)
{
    int retorno=1;
    if(this!=NULL && precio>=0)
    {
        *precio=this->precio;
        retorno=0;
    }
    return retorno;
}

int libro_setEditorial(Libro* this,char* editorial)
{
    int retorno=1;
    if(this!=NULL && editorial!=NULL)
    {

        strncpy(this->editorialId,editorial,CHARS_LEN);

        retorno=0;
    }
    return retorno;
}

int libro_getEditorial(Libro* this,char* editorial)
{
    int retorno=1;
    if(this!=NULL && editorial!=NULL)
    {
        strncpy(editorial,this->editorialId,CHARS_LEN);
        retorno=0;
    }
    return retorno;
}

int libro_imprimir(Libro* auxArcade, int indice)
{
	int retorno=-1;
	int auxId;
	char auxAutor[CHARS_LEN];
	char auxTitulo[CHARS_LEN];
	int auxPrecio;
	char auxEditorial[CHARS_LEN];

	libro_getId(auxArcade,&auxId);
	libro_getTitulo(auxArcade,auxTitulo);
	libro_getPrecio(auxArcade,&auxPrecio);
	libro_getAutor(auxArcade,auxAutor);
	libro_getEditorial(auxArcade,auxEditorial);

	if(auxArcade!=NULL && indice>=0)
	{
		printf("Id: %d Titulo: %s Autor: %s Precio: %d Editorial: %s \n",auxId,auxTitulo,auxAutor,auxPrecio,auxEditorial);
		retorno=0;
	}
	return retorno;
}
