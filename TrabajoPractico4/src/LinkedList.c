#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL){
       returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    /*if(this!=NULL && nodeIndex>=0 && nodeIndex< this->size){
        pNode=this->pFirstNode;
            for(int i=0;i<nodeIndex;i++){
                pNode=pNode->pNextNode;
            }
    }*/
    if(this!=NULL && nodeIndex>=0 && nodeIndex<this->size){
        if(nodeIndex==0){
            pNode=this->pFirstNode;
        }else{
            pNode=this->pFirstNode;
            while(nodeIndex>0){
                pNode=pNode->pNextNode;
                nodeIndex--;
            }
        }
    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1, size=0;
    Node* pNewNode=(Node*) malloc(sizeof(Node));

    Node* prevNode=NULL;
    Node* nextNode=NULL;

    if(this!=NULL && nodeIndex<=this->size && nodeIndex>=0){
        if(nodeIndex==0 && this->size==0){
            this->pFirstNode=pNewNode;
            this->pFirstNode->pElement=pElement;
            this->pFirstNode->pNextNode=NULL;
            size = this->size;
            size++;
            this->size = size;
            returnAux=0;
        }else{
            if(nodeIndex==0 && this->size!=0){
                nextNode=getNode(this, 0);
                this->pFirstNode=pNewNode;
                this->pFirstNode->pElement=pElement;
                this->pFirstNode->pNextNode=nextNode;
                size = this->size;
                size++;
                this->size = size;
                returnAux=0;
            }else{
                if(nodeIndex==this->size){
                    prevNode=getNode(this, nodeIndex-1);
                    pNewNode->pElement=pElement;
                    pNewNode->pNextNode=NULL;
                    prevNode->pNextNode=pNewNode;
                    size = this->size;
                    size++;
                    this->size = size;
                    returnAux=0;
                }else{
                    prevNode=getNode(this, nodeIndex-1);
                    nextNode=getNode(this, nodeIndex+1);
                    prevNode->pNextNode=pNewNode;
                    pNewNode->pNextNode=nextNode;
                    pNewNode->pElement=pElement;
                    size = this->size;
                    size++;
                    this->size = size;
                    returnAux=0;
                }
            }
        }
    }

    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL){
        returnAux=addNode(this,ll_len(this),pElement);
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNode;

    if(this!=NULL && index >=0 && index<=this->size){
        pNode=getNode(this,index);
        if(pNode!=NULL){
            returnAux=pNode->pElement;
        }
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNode;

    if(this!=NULL && index>=0 && index<this->size){
        returnAux=0;
        pNode=getNode(this,index);
        if(pNode!=NULL){
            pNode->pElement=pElement;
        }
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNodeI;
    Node* pNodeK;
    Node* pNode;

    if(this!= NULL && index>=0 && index<this->size){
        returnAux=0;
        if(index==0 && this->size==2){
            pNodeI=getNode(this,1);
            this->pFirstNode->pNextNode=pNodeI->pNextNode;
            this->pFirstNode->pElement=pNodeI->pElement;
            this->size--;
            //free(pNodeI);
            pNodeI=NULL;
            returnAux=0;
        }else if(index==0 && this->size==1){
            this->pFirstNode=NULL;
            this->size--;
            returnAux=0;
           // free(this->pFirstNode);
        }else if (index==1){
            pNodeI=getNode(this,index);
            pNodeK=getNode(this,index+1);
            this->pFirstNode->pNextNode=pNodeK;
            this->size--;
            free(pNodeI);
            pNodeI=NULL;
            returnAux=0;
        }else{
            pNode=getNode(this,index);
            pNodeI=getNode(this,index-1);
            pNodeK=getNode(this,index+1);
            pNodeI->pNextNode=pNodeK;
            this->size--;
            free(pNode);
            pNode=NULL;
            returnAux=0;
        }
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    Node* pNodeI;
    Node* pNodeK;

    if(this!=NULL){
        if(this->size==1){
            free(this->pFirstNode);
            this->size--;
            if(this->size==0){
                returnAux=0;
            }
        }else{
            for(int i = 0; i< this->size;i++){
                pNodeI=getNode(this,i);
                if(pNodeI!=NULL){
                    pNodeK=pNodeI->pNextNode;
                    this->size--;
                    free(pNodeI);
                }
                free(pNodeK);
            }
            if(this->size==0){
                returnAux=0;
            }

        }
        returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL){
        ll_clear(this);
        free(this);
        returnAux=0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    //int returnAux = -1;
   // Node* pNode;
   // if(this!=NULL && this->size>0){
            /*for(int i = 1; i<this->size;i++){
                pNode=getNode(this,i);
                if(pNode!=NULL && pNode->pElement == pElement){
                returnAux=i;
                break;
                }*/
    int returnAux = -1;
    Node* pNode;

    if(this!=NULL && this->size>0){
        if(this->pFirstNode->pElement==pElement){
            returnAux=0;
        }else{
            for(int i=0 ; i<this->size;i++){
                pNode=getNode(this, i);
                if(pNode->pElement==pElement){
                    returnAux=i;
                    break;
                }
            }
        }
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL){
        if(this->pFirstNode!=NULL){
            returnAux=0;
        }else{
            returnAux=1;
        }
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;\
    if(this!= NULL && index>=0 && index<=ll_len(this)){
         if(addNode(this,index,pElement)==0){
            returnAux=0;
        }

    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this!=NULL && index >= 0 && index<this->size){
        returnAux=ll_get(this,index);
        ll_remove(this,index);
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL){
       if(ll_indexOf(this,pElement)>=0){
        returnAux=1;
       }else{
        returnAux=0;
       }
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;//,len;
  /* // Node* pNode;
    void* pAux;
    if(this!=NULL && this2!=NULL){
        returnAux=0;
        for(int i=0;i<this2->size;i++){
           // pNode=getNode(this2,i);
           pAux=ll_get(this,i);
            if(ll_contains(this,pAux)){
                returnAux=1;
            }else{
                returnAux=0;
                break;
            }
        }
    }*/

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;

    if(this!=NULL && from >= 0 && from < to && to<this->size){
        cloneArray=(LinkedList*)malloc(sizeof(LinkedList));
        if(cloneArray!=NULL){

        }
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    Node* pNode;

    if(this!=NULL){
        cloneArray=(LinkedList*)malloc(sizeof(LinkedList));
        if(cloneArray!=NULL){
            for(int i = 0; i< this->size;i++){
                pNode=getNode(this,i);
                addNode(cloneArray,i,pNode->pElement);
            }
        }
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;

    return returnAux;

}

