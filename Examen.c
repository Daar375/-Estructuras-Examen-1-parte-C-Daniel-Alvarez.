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

void reordenar(Nodo *  Cabeza1,Nodo *  Cabeza2){
    Nodo * NodoTemp1 = Cabeza1;
    Nodo * NodoTemp2 = Cabeza2;
    int count = 0;
    while(count!=5){
        NodoTemp2=NodoTemp2->siguiente;
        NodoTemp1=NodoTemp1->siguiente;
        count++;
    }
    NodoTemp2->siguiente=NodoTemp1;
    count=0;
    
    NodoTemp1 = Cabeza1;
    NodoTemp2 = Cabeza2;
    while(count!=4){
        NodoTemp1=NodoTemp1->siguiente;
        count++;
    }
    NodoTemp1->siguiente=Cabeza2;
    
    count=0;
    NodoTemp1 = Cabeza1;
    NodoTemp2 = Cabeza2;
    while(count!=4){
        NodoTemp1=NodoTemp1->siguiente;
        count++;
    }
    NodoTemp1->siguiente=Cabeza2;
    count=0;
    
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
    
    Nodo * L1 = malloc(sizeof(Nodo));
    L1 -> dato = 6;

    agregarFinal(L1,1);
    agregarFinal(L1,2);
    agregarFinal(L1,3);
    agregarFinal(L1,4);
    agregarFinal(L1,8);
    Nodo * L2 = malloc(sizeof(Nodo));
    L2 -> dato = 9;

    agregarFinal(L2,10);
    agregarFinal(L2,11);
    agregarFinal(L2,12);
    agregarFinal(L2,13);
    agregarFinal(L2,14);
    print(L1);
    printf("\n");
    print(L2);
    printf("\n");

    reordenar(L1,L2);
    printf("\n");

    print(L1);
    printf("\n");
    print(L2);

    return 0;
}
