/*
 * Libro.h
 *
 *  Created on: 29 nov. 2021
 *      Author: USURIO
 */

#ifndef LIBRO_H_
#define LIBRO_H_

typedef struct
{
	int id;
	char titulo;
	char autor;
	int precio;
	char editorialId;
}Libro;

Libro* libro_new();
Libro* libro_newParametros(char* idStr,char* tituloStr,char* autorStr, char* precioStr,char* editorialStr);

int libro_setId(Libro* this, int id);
int libro_getId(Libro* this, int* id);

int libro_setTitulo(Libro* this,char* titulo);
int libro_getTitulo(Libro* this,char* titulo);

int libro_setAutor(Libro* this,char* autor);
int libro_getAutor(Libro* this,char* autor);

int libro_setPrecio(Libro* this,int precio);
int libro_getPrecio(Libro* this,int* precio);

int libro_setEditorial(Libro* this,char* editorial);
int libro_getEditorial(Libro* this,char* editorial);

int libro_imprimir(Libro* auxArcade, int indice);
Libro* libro_newParametrosAdd(int idStr,char* tituloStr,char* autorStr, int precioStr, char* editorialStr);

#endif /* LIBRO_H_ */
