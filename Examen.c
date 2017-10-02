#include <stdio.h>
#include <stdlib.h>

typedef struct BasicNodo {
  int dato;
  struct Nodo * siguiente;
}Nodo;

void agregarFinal(Nodo * Cabeza, int num){
        Nodo * NuevoNodo = malloc(sizeof(Nodo));

        Nodo * NodoIterador = Cabeza;


        while(NodoIterador->siguiente!=NULL){

            NodoIterador=NodoIterador->siguiente;
        }
        
        NuevoNodo -> dato = num;
        NodoIterador -> siguiente = NuevoNodo;
    
}

Nodo  * getNodo(Nodo * Cabeza, int numNodo){
        Nodo * NodoIterador = Cabeza;
        int count =0;

        while(count!=numNodo ){

            NodoIterador=NodoIterador->siguiente;
            count++;
            if(NodoIterador->siguiente==NULL){
                printf("Index out of Bound");
                return NULL;
            }
        }
        
 
        return NodoIterador;
}



void print(Nodo *  Cabeza){
    Nodo * NodoTemp = Cabeza;
    while(NodoTemp!=NULL){

        printf("%d ",NodoTemp->dato);
        NodoTemp=NodoTemp->siguiente;
    }

}

int main()
{   
    
    Nodo * CabezaLista1 = malloc(sizeof(Nodo));
    CabezaLista1 -> dato = 6;

    agregarFinal(CabezaLista1,11);
    agregarFinal(CabezaLista1,12);
    agregarFinal(CabezaLista1,13);

   print(CabezaLista1);
    printf("Nodo:%d",getNodo(CabezaLista1,10));
    return 0;
}
