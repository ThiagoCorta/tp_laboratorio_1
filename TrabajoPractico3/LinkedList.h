/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
LinkedList* ll_newLinkedList(void);
int ll_len(LinkedList* this);
Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
int ll_add(LinkedList* this, void* pElement);
void* ll_get(LinkedList* this, int index);
int ll_set(LinkedList* this, int index,void* pElement);
///El remove lo saca de la lista! :D
int ll_remove(LinkedList* this,int index);

///limpia todo! deja solo el 0
int ll_clear(LinkedList* this);
///limpia t odo y libera la memoria.
int ll_deleteLinkedList(LinkedList* this);

///es un buscar! pasa el indez
int ll_indexOf(LinkedList* this, void* pElement);

///si esta vacio el linked o no esta vacio.
int ll_isEmpty(LinkedList* this);

int ll_push(LinkedList* this, int index, void* pElement);
/// devuelve la referencia y lo saca de la lista al elemento el POP.
void* ll_pop(LinkedList* this,int index);

///parecido al indexof este nos dice si esta o no !
int ll_contains(LinkedList* this, void* pElement);

/// 2 linked list dice si todos los elementos del 2do estan en el 1ro.
int ll_containsAll(LinkedList* this,LinkedList* this2);

/// pasamos el linkedlist de donde hasta donde y nos devuelve una copia de eso, un subconjunto de ese linkedlist
LinkedList* ll_subList(LinkedList* this,int from,int to);

/// devuelve un linkedlist igual pero con otro puntero, osea hay 2 iguales.
LinkedList* ll_clone(LinkedList* this);

///Ordenamiento pide puntero a una funcion, hay q hacer una funcion, pasamos un puntero a la funcion, osea la funcion sin ().
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
