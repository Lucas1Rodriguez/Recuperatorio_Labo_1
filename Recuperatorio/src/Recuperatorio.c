/*
 ============================================================================
 Name        : Recuperatorio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
 1) Leer un archivo con los datos de libros, guardándolos en un linkedList de entidades
eLibro.
ACLARACION: El nombre del archivo se debe pasar como parámetro por línea de comandos.

2) Ordenar la lista generada en el ítem anterior, con la función ll_sort, según el criterio de
ordenamiento “Autor” de manera ascendente.

3) Imprimir por pantalla todos los datos de los libros.
ACLARACION: Se deberá imprimir la descripción de la editorial.

4) Desarrollar la función ll_map en la biblioteca linkedList, la cual recibirá la lista y una
función. La función ll_map ejecutará la función recibida como parámetro por cada ítem
de la lista, de este modo se realizarán descuentos a los precios según se detalla:

* Planeta: 20% (si el monto es mayor o igual a $300)

* SIGLO XXI EDITORES: 10% (si el monto es menor o igual a $200)

5) Generar el archivo de salida: mapeado.csv
ACLARACION: Se deberá poder filtrar la lista por el autor.

1) Desarrollar la función ll_filter en la biblioteca linkedList, la cual recibirá la lista y una
función. Esta deberá filtrar la lista por la editorial MINOTAURO.

2) Generar el archivo de salida: minotauroLibros.csv
 */

#include <stdio.h>
#include <stdlib.h>
#include "Libro.h"
#include "LinkedList.h"
#include "Controller.h"
#include "utn_biblioteca.h"
#include "parser.h"

int main(void) {
	setbuf(stdout,NULL);
	LinkedList* librosList = ll_newLinkedList();
	 int option;
	    do{
	    	if(librosList != NULL)
	    	{
				if (utn_getNumeroInt(&option, "\nBienvenido \n1)Leer libros desde el archivo \n2)Ordenar libros por autor de manera ascendente \n3)Imprimir libros \n4)Hacer descuentos y generar archivo del mapeo \n5)Filtrar por editorial Minotauro \n6)Salir \n", "\nError opcion Invalida",  1, 6, 5)==0)
				{
					switch(option)
					{
						case 1:
							// 1) Leer un archivo con los datos de libros
							if(controller_loadFromText("Datos_Recu_2_Dic_2021_TN.csv",librosList)==0)
							{
								printf("\nSe cargaron los datos como texto");
							}
							else
							{
								printf("\nHubo un error");
							}
							break;
						case 2:
							// 2) Ordenar la lista generada
							if(controller_sortAutor(librosList) == 0)
							{
								printf("\nLibros ordenados y listados");
							}
							else
							{
								printf("\nNo se pudo ordenar y listar los libros");
							}
							break;
						case 3:
							// 3) Imprimir
							if(controller_listLibro(librosList) == 0)
							{
								printf("\nLibros listados");
							}
							else
							{
								printf("\nNo se pudo listar los libros");
							}
							break;
						case 4:
							// 4) Descuentos
							if(controller_Descuentos(librosList) == 0)
							{
								printf("\nDescuentos hechos");
							}
							else
							{
								printf("\nNo se pudieron hacer los descuentos");
							}
							break;
						case 5:
							// 5) Filtrar editorial Minotauro
							if(controller_FilterMinotauro(librosList) == 0)
							{
								printf("\nFiltrado por editorial Minotauro");
							}
							else
							{
								printf("\nNo se pudo filtrar");
							}
							break;
						case 6:
							printf("\nSaliendo");
							break;
					}
				}
	    	}
		}while (option <6);


return EXIT_SUCCESS;
}
