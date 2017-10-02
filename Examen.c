#include <stdio.h>
#include <stdlib.h>

struct Nodo
{
  int dato;
  struct Nodo *siguiente;
};

void
agregarFinal (struct Nodo *Cabeza, int num)
{
  struct Nodo *NuevoNodo = malloc (sizeof (struct Nodo));

  struct Nodo *NodoIterador = Cabeza;


  while (NodoIterador->siguiente != NULL)
    {

      NodoIterador = NodoIterador->siguiente;
    }

  NuevoNodo->dato = num;
  NodoIterador->siguiente = NuevoNodo;

}

struct Nodo *
getNodo (struct Nodo *Cabeza, int numNodo)
{
  struct Nodo *NodoIterador = Cabeza;
  int count = 0;

  while (count != numNodo)
    {

      NodoIterador = NodoIterador->siguiente;
      count++;
      if (NodoIterador->siguiente == NULL)
	{
	  printf ("Index out of Bound");
	  return NULL;
	}
    }


  return NodoIterador;
}

void
reordenar (struct Nodo *Cabeza1, struct Nodo *Cabeza2)
{
  struct Nodo *NodoTemp1 = Cabeza1;
  struct Nodo *NodoTemp2 = Cabeza2;
  int count = 0;
  while (count != 5)
    {
      NodoTemp2 = NodoTemp2->siguiente;
      NodoTemp1 = NodoTemp1->siguiente;
      count++;
    }
  NodoTemp2->siguiente = NodoTemp1;	//cambia el siguiente del espacio 5 en la lista 2 por el espacio 5 de la lista 1

  NodoTemp1 = Cabeza1;
  NodoTemp2 = Cabeza2;
  count = 0;
  while (count != 4)
    {
      NodoTemp2 = NodoTemp2->siguiente;

      count++;
    }
  count = 0;

  while (count != 3)
    {
      NodoTemp1 = NodoTemp1->siguiente;

      count++;
    }
  Cabeza1->siguiente->siguiente->siguiente = NodoTemp2;	//cambia el siguiente del espacio 2 en la lista 1 por el espacio 4 de la lista 2  
  Cabeza2->siguiente->siguiente->siguiente->siguiente = NodoTemp1;//cambia el siguiente del espacio 3 en la lista 2 por el espacio 3 de la lista 1 
  count = 0;

  count = 0;
  NodoTemp1 = Cabeza1;
  NodoTemp2 = Cabeza2;
  while (count != 2)
    {
      NodoTemp2 = NodoTemp2->siguiente;

      count++;
    }
  count = 0; 


  NodoTemp1 = NodoTemp1->siguiente;
  Cabeza1->siguiente = NodoTemp2;//cambia el siguiente de la cabeza en la lista 1 por el espacio 2 de la lista 1 
  Cabeza2->siguiente->siguiente = NodoTemp1;//cambia el siguiente del espacio 2 en la lista 2 por el espacio 1 de la lista 1 
  count = 0;



  count = 0;
  NodoTemp1 = Cabeza1;
  NodoTemp2 = Cabeza2;
  while (count != 4)
    {
      NodoTemp1 = NodoTemp1->siguiente;

      count++;
    }
  count = 0;



  NodoTemp1->siguiente = Cabeza2;	//cambia el siguiente del espacio 4 en la lista 1 por la cabeza de la segunda lista





}

void
print (struct Nodo *Cabeza)
{
  struct Nodo *NodoTemp = Cabeza;
  while (NodoTemp != NULL)
    {

      printf ("%d ", NodoTemp->dato);
      NodoTemp = NodoTemp->siguiente;
    }

}

int
main ()
{

  struct Nodo *L1 = malloc (sizeof (struct Nodo));
  L1->dato = 6;

  agregarFinal (L1, 1);
  agregarFinal (L1, 2);
  agregarFinal (L1, 3);
  agregarFinal (L1, 4);
  agregarFinal (L1, 8);
  struct Nodo *L2 = malloc (sizeof (struct Nodo));
  L2->dato = 9;

  agregarFinal (L2, 10);
  agregarFinal (L2, 11);
  agregarFinal (L2, 12);
  agregarFinal (L2, 13);
  agregarFinal (L2, 14);
  print (L1);
  printf ("\n");
  print (L2);
  printf ("\n");

  reordenar (L1, L2);
  printf ("\n");

  print (L1);
  printf ("\n");
  print (L2);

  return 0;
}
