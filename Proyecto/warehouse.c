/*Copyright (C) 
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 * 
 * 2022 - EDA 1 - |	Team 10											|
 * 				  |	Casanova Torres Gerardo Aldahir (Equipo 10) 	|
 *				  |	Herrera Romero Juan Pablo						|
 *				  |	Muriel Gonz�lez Diego							|
 *				  |	Olvera Negrete Elliot Eusebio					|
 */


#include "warehouse_INC.h"

static product_node* product_new_node( char name[],int amount, int id ){
	
   product_node* myproduct = (product_node*) malloc( sizeof( product_node ) );
   assert(myproduct);
   /*if( myproduct == NULL ){
		#ifdef DEBUG
		fprintf(stderr,"\n Problema con memoria en product");
		#endif

   }
   else{  */
		myproduct->next=NULL;
		myproduct->prev=NULL;
		myproduct->product_id=id;
		myproduct->product_amount=amount;
		strncpy(myproduct->product_name,name,MAX_CHAR+1);
  // }

   return myproduct;
}
///////////////////////////////////////////////////////////// PRODUCT ///////////////////////////

void Product_Set_amount(warehouse_DLL* this, int id, int amount){
	Warehouse_Product_get(this,id);
	this->cursor->product_amount=amount;
}

////////////////////////////////////////////////////////////////////////////////////////////////


/**
 * @brief Crea un obeto Warehouse
 *
 * @return Una referencia al nuevo Wrehouse
 * @post Un Warehouse existente en el heap
 */
warehouse_DLL* Warehouse_New(){
	warehouse_DLL* myware = ( warehouse_DLL* )malloc( sizeof(warehouse_DLL) );
	if( myware == NULL ){
		#ifdef DEBUG
		fprintf(stderr,"\n Problema con memoria");
		#endif
		exit (1);
	}
	else{
		myware->cursor=NULL;
		myware->first=NULL;
		myware->last=NULL;
		myware->warehouse_len=0;
	}
	return myware;
}

/**
 * @brief Destruye un Warehouse.
 *
 * @param this Un Warehouse.
 */
 
void Warehouse_Delete( warehouse_DLL** this )
{
	assert( *this );
	
	Warehouse_MakeEmpty( *this );
	free( *this );
	*this = NULL;
}

void Warehouse_Product_new(warehouse_DLL* this,char name[], int amount, int id){
	
	Warehouse_Push_back(this,name,amount,id);
}

/**
 * @brief Inserta un elemento a la derecha del cursor
 *
 * @param lista Una referencia a la lista de trabajo
 * @param item El elemento a insertar
 *
 * @post Coloca al cursor en el nuevo nodo
 *
 */
void Warehouse_Insert( warehouse_DLL* this, char name[], int amount, int id ){
	
	assert( this );
	assert( this->cursor );
	
	if( Warehouse_IsEmpty( this )){
		product_node* prod = product_new_node(name, amount, id );
		#ifdef DEBUG
		fprintf(stderr,"\n Producto creado");
		#endif
		this->first = this->last = this->cursor = prod;
		++this->warehouse_len;
	}else if( this->cursor == this->last ){
		Warehouse_Push_back( this, name, amount, id );
	}else{
		product_node* prod = product_new_node(name, amount, id );
		#ifdef DEBUG
		fprintf(stderr,"\n Producto creado");
		#endif
		product_node* right = this->cursor->next;
		prod->next = right;
		this->cursor->next = prod;
		right->prev = prod;
		prod->prev = this->cursor;
		this->cursor = prod;
		
		++this->warehouse_len;
	}
}

/**
 * @brief Inserta un elemento en el frente de la lista.
 *
 * @param this Una lista.
 * @param item El elemento a insertar
 */
void Warehouse_Push_front( warehouse_DLL* this, char name[], int amount, int id )
{
	product_node* prod = product_new_node(name, amount, id );
	#ifdef DEBUG
	fprintf(stderr,"\n Producto creado");
	#endif
   	assert( prod );
   	
	if( Warehouse_IsEmpty( this ) ){
		this->first = this->last = this->cursor = prod;
		
	}else{
		product_node* right = this->first;
		this->first = prod;
		this->first->next = right;
		right->prev = this->first;
		
	}
	++this->warehouse_len;
}

/**
 * @brief Inserta un elemento en el fondo de la lista.
 *
 * @param this Una lista.
 * @param item El elemento a insertar
 */
void Warehouse_Push_back( warehouse_DLL* this, char name[], int amount, int id ){
   product_node* prod = product_new_node(name,amount,id );
   assert( prod );

   if( this->first != NULL ){

      this->last->next = prod;
      prod->prev = this->last;
      this->last = prod;
   } else{
      this->first = this->last = this->cursor = prod;
   }
   ++this->warehouse_len;
}

/**
 * @brief Elimina el elemento al frente de la lista.
 *
 * @param this Referencia a una lista.
 *
 * @post El cursor se mantiene en la posición en la que estaba cuando entró la
 * función.
 */
void Warehouse_Pop_front( warehouse_DLL* this )
{
	assert( this );
	assert( this->warehouse_len );//Len es mayor a 0; 0 es NULL
   // ERR: no se puede borrar nada de una lista vacía
	
	if( this->first == this->last ){//Solo 1 elemento
		free( this->first );
		this->first = this->last = this->cursor = NULL;
	}else{ //Mas de 1 elemento en la lista
		product_node* right = this->first->next;
		free( this->first );
		this->first = right;
		
		this->first->prev = NULL;
	}
	--this->warehouse_len;
}

/**
 * @brief Elimina el elemento al fondo de la lista.
 *
 * @param this Referencia a una lista.
 *
 * @post El cursor se mantiene en la posición en la que estaba cuando entró la
 * función.
 */
void Warehouse_Pop_back( warehouse_DLL* this )
{
   assert( this->warehouse_len );
   // ERR: no se puede borrar nada de una lista vacía

   if( this->last != this->first ) // también funciona: if( this->len > 1 ){...}
   { 
      product_node* x = this->last->prev;
      free( this->last );
      x->next = NULL;
      this->last = x;
      
   } else{
      free( this->last );
      this->first = this->last = this->cursor = NULL;
   }
   --this->warehouse_len;
}

/**
 * @brief Devuelve una copia del valor apuntado por el cursor
 *
 * @param this Una lista
 *
 * @return El valor apuntado por el cursor
 */
int Warehouse_Cursor_Get( warehouse_DLL* this )
{
	return this->cursor->product_id;
}

/**
 * @brief Coloca al cursor al inicio de la lista.
 *
 * @param this Una referencia a la lista de trabajo
 */
void Warehouse_Cursor_front( warehouse_DLL* this )
{
   this->cursor = this->first;
}



/**
 * @brief Mueve al cursor al siguiente elemento a la derecha.
 *
 * @param this Una lista.
 */
void Warehouse_Cursor_next( warehouse_DLL* this ){
	assert(this->cursor->next != NULL);
	this->cursor= this->cursor->next;
}



/**
 * @brief Indica si la lista está vacía.
 *
 * @param this Referencia a una lista.
 *
 * @return true si la lista está vacía; false en caso contrario.
 */
bool Warehouse_IsEmpty( warehouse_DLL* this )
{
   return this->first==NULL;
}

/**
 * @brief Devuelve el número actual de elementos en la lista.
 *
 * @param this Una lista.
 *
 * @return Devuelve el número actual de elementos en la lista.
 */
int Warehouse_Len( warehouse_DLL* this ){
	return this->warehouse_len;
}

/**
 * @brief Elimina todos los elementos de la lista sin eliminar la lista.
 *
 * @param this Una lista
 */
void Warehouse_MakeEmpty( warehouse_DLL* this )
{
	Warehouse_Cursor_front( this );
	
	while( !Warehouse_IsEmpty( this ) ){// DLL_IsEmpty( this ) == false
		Warehouse_Pop_back(this);
	}
	assert( this->warehouse_len == 0 );
	//Assert si len no se coloo en 0 al borrar toda la lista
	
	
	//Estado seguro de Reset de la lista
	this->first = this->last = this->cursor = NULL;
	this->warehouse_len = 0; // Lo ponemos porque se pueden desactivar los assert
	
}

/**
 * @brief Devuelve una copia del elemento en el frente de la lista
 *
 * @param this Una lista
 *
 * @return La copia del elemento en el frente de la lista
 *
 * @pre La lista NO debe estar vacía
 */
int Warehouse_Front( warehouse_DLL* this )
{
   assert( this->first != NULL );
   // ERR: no se puede leer de una lista vacía

   return this->first->product_id;
}

/**
 * @brief Devuelve una copia del elemento en la parte trasera de la lista.
 *
 * @param this Una lista.
 *
 * @return La copia del elemento en la parte trasera de la lista.
 *
 * @pre La lista NO debe estar vacía
 */
int Warehouse_Back( warehouse_DLL* this )
{
	assert( this );
	assert( this->warehouse_len );
	//Assert en caso de que la lista este vacIa
	
	return this->last->product_id;
}

/**
 * @brief Elimina el elemento apuntado por el cursor.
 *
 * @param this Una lista.
 *
 * @post El cursor se mueve a la derecha.
 *
 */
void Product_Delete( warehouse_DLL* this ){
	if( this->cursor == this->first ) {
        Warehouse_Pop_front( this );
        this->cursor = this->first;
    } else if( this->cursor == this->last ) {
        Warehouse_Pop_back( this );
        this->cursor = this->last;
    } else {
        product_node* left = this->cursor->prev;
        product_node* right = this->cursor->next;

        free( this->cursor );

        left->next = right;
        right->prev = left;
        --this->warehouse_len;
        this->cursor = right;
    }

}

/*
  Pone Cursor en la coincidencia
  si no funciona regresa "-1"
*/
bool Warehouse_Product_get(warehouse_DLL* this,int id ){
	bool encontrado = false;
	int sup=(this->warehouse_len)-1;
	int inf=0;
	while( inf <= sup ){
        int centro = ( sup + inf ) / 2;
        #ifdef DEBUG
            fprintf( stderr, "centro: %d\n", centro );
        #endif
        Warehouse_Cursor_front(this);
		for(int i=0; i<centro; i++ ){
			Warehouse_Cursor_next(this);
		}

        if( id == this->cursor->product_id ){//Caso base 1
            #ifdef DEBUG
                fprintf( stderr, "Coincidencia encontrada en : %d\n", centro );
            #endif
            return !encontrado;

        }else if( id < this->cursor->product_id ){
            if( sup == inf ){        //Caso base 2
                #ifdef DEBUG
                    fprintf( stderr, "No hay coincidencias (inf = %d)\n", inf );
                #endif
                return encontrado;

            }

            sup = centro - 1;
            #ifdef DEBUG
                fprintf( stderr, "Voy por la izqueirda (%d, %d)\n", inf, sup );
            #endif
        }else{
            inf = centro + 1;
            #ifdef DEBUG
                fprintf( stderr, "Voy por la derecha (%d, %d)\n", inf, sup );
            #endif
        }

    }
    return encontrado;
}



/**
 * @brief Elimina el primer nodo que coincida con la llave.
 *
 * @param this Una lista
 * @param key  Valor buscado
 *
 */
void Warehouse_Remove( warehouse_DLL* this, int id ){
	Warehouse_Product_get(this,id);
	Warehouse_Delete(&this);
}



/**
 * @brief Busca un valor en la lista. Si lo encuentra coloca ahí al cursor.
 *
 * @param this Una lista.
 * @param key El valor que se está buscando.
 *
 * @post Si se encontró una coincidencia coloca al cursor en ese nodo; en caso contrario el cursor es NULL.
 *
 * @code
 * if( DLL_Find( list, x ) )
 * {
 *    y = DLL_Cursor_Get( list );
 *
 *    // ...
 * }
 * @endcode
 */
bool Warehouse_Find( warehouse_DLL* this, int id )
{
   for( this->cursor = this->first; 
        this->cursor != NULL; 
        this->cursor = this->cursor->next )
   {
      if( this->cursor->product_id == id )
      {
         return true;
      }
   }
   return false;
}

/**
 * @brief Imprime la estructura de la lista. Es para uso de depuración, no es de uso general.
 *
 * @param this Una lista.
 */
void Warehouse_Print_structure( warehouse_DLL* this )
{
   if( Warehouse_IsEmpty( this ) )
   {
      printf("\nEmpty list. Nothing to show." );
   } 
   else
   {
      printf("\n\t id \t nombre \t cantidad ");

      // usando un for en lugar de while (mi preferido):
      for( product_node* it = this->first; it != NULL; it = it->next )
      {
         printf("\n\t(%i)->", it->product_id );
         printf("\t(%s)->", it->product_name );
         printf("\t(%i)->\n", it->product_amount );
      } 

   }
}

