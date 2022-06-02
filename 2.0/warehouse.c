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
 * 2022 - francisco dot rodriguez at ingenieria dot unam dot edu
 */

/**
* @brief Funciones para el manejo del almacen
*
* Este codigo inserta, crea, borra, encola entre varias cosas mas a onjetos de tipo product.
*
* @author Equipo 10 EDA 1
* @version 1.0
* @date 30/05/2022
*
*
* @code
*
*int main(){
*	product_DLL* mylist=DLL_Product_New();
*	DLL_Product_Push_Front(mylist, 10056, "Chanclas", 20, 150 );
*	DLL_Product_Push_Front(mylist, 55954, "Papitas", 20, 25 );
*	DLL_Product_Push_Front(mylist, 7978, "Pizza", 40, 150 );
*	DLL_Product_Push_Front(mylist, 15679, "Cheetos", 1, 28 );
*	
*	
*	DLL_Product_Print(mylist);
*	
*	DLL_Product_Pop_Front(mylist);
*	DLL_Product_Pop_Back(mylist);
*	
*	int cantidad=DLL_Product_Len(mylist);
*	printf("\n Existencia de %i productos",cantidad);
*	bool existe = DLL_Product_Find(mylist, 7978);
*	
*	if(existe == true){
*		printf("\n EL PRODUCTO SI EXISTE");
*	}
*	else{
*		printf("\n EL PRODUCTO NO EXISTE");
*	}
*	
*	Product_Buy_Stock(mylist->cursor,5);
*	
*	DLL_Product_Cursor_Print(mylist);
*	
*	Product_Sell_Stock(mylist->cursor,45);
*	
*	DLL_Product_Cursor_Print(mylist);
*	
*	int SolCambio[MAX_DENOMS] = {0};
*	int num_monedas = Calcula_cambio( 1895, SolCambio );
*	
*	Imprimir_Cambio( num_monedas, SolCambio );
*	
*	
*	
*	//DLL_Product_Print(mylist);
*	
*	DLL_Product_Delete( &mylist );
*	return 0;
*}
*
* @endcode
*
* 
*/
#include "warehouse_INC.h"

////////////////////////////////// PRODUCT_NODE FUNCIONES ////////////

/**
 * @brief Crea un nodo de tipo product.
 *
 * @param id Id de producto.
 * @param name  Nombre de producto.
 * @param stock  Número de producto .
 * @param price  Precio de producto.
 *
 * @return Nodo tipo product.
 */
static product_node* Product_New_Node( int id, char name[], int stock, int price ) {
	product_node* mynode=(product_node*)malloc(sizeof(product_node));

	if(mynode != NULL) {
		mynode->next=NULL;
		mynode->prev=NULL;
		mynode->product_id=id;
		mynode->product_stock=stock;
		strncpy(mynode->product_name,name,MAX_CHAR+1);
		mynode->product_price = price;
	} else {
	#ifdef DEBUG
		fprintf(stderr,"\n Problema con memoria");
	#endif
		exit (1);
	}
	return mynode;
}

/**
 * @brief Borra nodo de tipo product.
 *
 * @param this Nodo product.
 *
 * @pre this ya existe
 */
void Product_Delete_Node(product_node* this) {
	assert(this);
	free(this);
	this=NULL;
}

/**
 * @brief Busca el producto a vender y reasigna el valor de stock de un producto, regresa TRUE si si hay Stock suficiente, FALSE en caso contrario.
 *
 * @param this Nodo tipo product.
 * @param howmany  Cantidad de stock a vender.
 *
 * @return True si hay Stock suficiente en caso contrario retorna false.
 */
bool Product_Sell_Stock(product_node* this, int howmany) {
	bool enough_stock = false;
	
	if( this->product_stock < howmany ) {
//#ifdef DEBUG
		printf("\nNo hay stock suficiente");//fprintf("stderr,"\nNo hay stock suficiente");
//#endif
	} else if( howmany<0 ){
		printf("\nDATO NO VÁLIDO (%d)\nOPERACIÓN FINALIZADA", howmany);
		
	} else {
		this->product_stock-=howmany; 
		enough_stock = true;
	}
	
	return enough_stock;
}

/**
 * @brief Busca el producto a comprar y reasigna el valor de stock de un producto, si el producto no existe crea uno nuevo .
 *
 * @param this Nodo tipo product.
 * @param howmany  Cantidad de stock a comprar.
 */
void Product_Buy_Stock(product_node* this, int howmany) {
	if(howmany<0) {
#ifdef DEBUG
		fprintf(stderr,"\n Error con la compra de productos howmany= %i",howmany);
#endif
	} else {
		this->product_stock+=howmany;
	}
}

/**
 * @brief Evalua si nuestro candidato c mas el acumulado de cambio acum soluciona el 
 * problema del cambio p y si si retorna true .
 *
 * @param c Candidato (la moneda).
 * @param p Problema mas pequeño.
 * @param acum Lo que se lleva de cambio.
 *
 * @return True si la evaluacion es factibel en caso contrario retorna false
 */
bool Cambio_Es_factible( int c, int p, int acum ) {
	return ( c + acum ) <= p ? true : false;
}

/**
 * @brief Evalua si acum es igual a la cantidad de cambio p.
 *
 * @param p Problema mas pequeño.
 * @param acum Lo que se lleva de cambio.
 *
 * @return True si la igualdad se cumple caso contrario retorna false
 */
bool Candidato_Es_solucion( int p, int acum ) {
	return acum == p;
}

/**
* @brief Determina las denominaciones para un cambio dado.
*
* @param c[] Conjunto de candidatos
* @param i Índice 'libre' para el conjunto de candidatos
* @param j Tamaño del conjunto de candidatos
* @param s[] Conjunto solución
* @param s_idx Índice 'libre' para el conjunto solución
* @param p Cambio por dar
* @param acum Acumulador interno
*
* @return true si se encontró una solución. false en caso contrario.
*/
bool Cambio_bt( int c[], int i, int j, int s[], int *s_idx, int p, int *acum ) {
	bool success = false;

	for( int x = i; x < j; ++x ) {
		if( Cambio_Es_factible( c[x], p, *acum ) ) {
			s[*s_idx] = c[x];
			++*s_idx;
			*acum += c[x];

			if( !Candidato_Es_solucion( p, *acum ) ) {
				success = Cambio_bt( c, x + 1, j, s, s_idx, p, acum );

				if( not success ) {
					--*s_idx;
					*acum -= c[x];
				}
			} else {
				return true;
			}
		}

		if( success == true ) {
			break;
		}
	}

	return success;
}

/**
* @brief Función de activación
*
* @param c[] Conjunto de candidatos
* @param tam_c Número de candidatos
* @param s[] Conjunto solución
* @param tam_s Número máximo de elementos en el conjunto solución
* @param p El cambio que queremos dar
*
* @return El tamaño del conjunto solución; si es cero, entonces no se encontró
* ninguna solución
*/
int Activar_Cambio_bt( int c[], int tam_c, int s[], int tam_s, int p ) {
	int acum = 0;
	int s_idx = 0;

	bool res = Cambio_bt(
	               c, 0, tam_c, // envía al conjunto de candidatos completo
	               s, &s_idx, // conjunto solución
	               p, // instancia particular del problema
	               &acum ); // acumulador

	return res ? s_idx : 0;
}

/**
* @brief Pasa la cantidad de cambio necesario a la funcion Activar_Cambio_bt 
* y regresa la cantidad de monedas necesarias para dar el cambio deseado y el 
* arreglo de las monedas para el cambio.
*
* @param cambio El cambio que te queda.
* @param SolCambio[] Arreglo oversiced que guarda las monedas del cambio.
*
* @return La cantidad de monedas necesarias para dar el cambio y el arreglo de las monedas para el cambio.
*/
int Calcula_cambio( int cambio, int SolCambio[]){//Regresamos el arreglo por referencia
	
	int candidatos[MAX_DENOMS] = { 1000, 500, 200, 100, 50, 20, 10, 5, 5, 2, 2, 1 };

	int solucion[MAX_DENOMS] = {0};
// a lo más, habrá MAX_DENOMS monedas

	int p = cambio;
/*#if 1
	printf( "Cantidad:\n$ " );
	scanf( "%d", &p );
#endif*/

	int num_monedas = Activar_Cambio_bt( candidatos, MAX_DENOMS, solucion, MAX_DENOMS, p );

	
	if ( num_monedas > 0 ) {
		for( int i = 0; i < num_monedas; ++i ) {
			SolCambio[i] = solucion[i];
		}
// Coloca al conjunto solución
	} else {
		for( int i = 0; i < num_monedas; ++i ) {
			SolCambio[i] = -1;
		}
// Coloca al conjunto solución con el valor sentinela -1 que indica que no se haló una solución		
	}
	
	return num_monedas;
}

/**
* @brief Imprime las monedas con las que se dara el cambio.
*
* @param num_monedas La cantidad de monedas que se usan para dar el cambio
* @param SolCambio[] Arreglo oversiced que guarda las monedas del cambio.
*/
void Imprimir_Cambio( int num_monedas, int SolCambio[] ){
	
	#ifdef DEBUG
		fprintf( stderr, "\n\tEl cambio es dando billetes y monedas de: ");
	#endif
	
	for( int i = 0; i < num_monedas; ++i ) {
		printf( "%d, ", SolCambio[i] );
	}
// imprime al conjunto solución

}
///////////////////////////////////// PRODUCT DLL FUNCIONES //////////////////////////

/**
 * @brief Crea una lista doblemente enlazada de nodos de tipo product.
 *
 * @return DLL de products.
 *
 * @post mylist ya existe
 */
product_DLL* DLL_Product_New(){
	product_DLL* mylist=(product_DLL*)malloc(sizeof(product_DLL));
	if(mylist != NULL) {
		mylist->cursor=NULL;
		mylist->first=NULL;
		mylist->last=NULL;
		mylist->len=0;
	} else {
#ifdef DEBUG
		fprintf(stderr,"\n Problema con memoria");
#endif
		assert( mylist );
	}
}

// FUNCIONES CURSOR

/**
 * @brief Coloca el cursor de una DLL en Front.
 *
 * @param this DLL de  products.
 *
 * @pre len de this es mayor a 0
 */
void DLL_Product_Cursor_Front(product_DLL* this) {
	assert(this->len>0);
	this->cursor=this->first;
}

/**
 * @brief Coloca el cursor de una DLL en Last.
 * 
 * @param this DLL de  products.
 *
 * @pre len de this es mayor a 0
 */
void DLL_Product_Cursor_Last(product_DLL* this) {
	assert(this->len>0);
	this->cursor=this->last;
}

/**
 * @brief Coloca el cursor de una DLL en Next de cursor.
 * 
 * @param this DLL de  products.
 *
 * @pre len de this es mayor a 0.
 */
void DLL_Product_Cursor_Next(product_DLL* this) {
	assert(this->len>0);
	this->cursor=this->cursor->next;
}

/**
 * @brief Coloca el cursor de una DLL en Prev de cursor.
 *  
 * @param this DLL de  products.
 *
 * @pre len de this es mayor a 0.
 */
void DLL_Product_Cursor_Prev(product_DLL* this) {
	assert(this->len>0);
	this->cursor=this->cursor->prev;
}

// FUNCIONES POP
/// ELIMINA EL NODO EN FRONT

/**
 * @brief Elimina el producto de la DLL señalado por Front.
 *   
 * @param this DLL de  products.
 *
 * @pre len de this es mayor a 0. 
 */
void DLL_Product_Pop_Front(product_DLL* this) {
	assert(this->len>0);
	if(this->len == 1) {
		free(this->first);
		this->first = this->last = this->cursor = NULL;
	} else {
		product_node* right = this->first->next;
		free(this->first);
		this->first=right;
		right->prev=NULL;
		this->cursor=this->first;
	}
	this->len -=1;
}

/**
 * @brief Elimina el producto de la DLL señalado por Back.
 *    
 * @param this DLL de  products.
 *
 * @pre len de this es mayor a 0. 
 */
void DLL_Product_Pop_Back(product_DLL* this) {
	assert(this->len>0);
	if(this->len == 1) {
		free(this->last);
		this->first = this->last = this->cursor = NULL;
	} else {
		product_node* left=this->last->prev;
		free(this->last);
		this->last=left;
		this->last->next=NULL;
		this->cursor=this->last;
	}
	this->len-=1;
}

/**
 * @brief Elimina el producto de la DLL señalado por Cursor.
 *  
 * @param this DLL de  products.
 *
 * @pre len de this es mayor a 0. 
 */
void DLL_Product_Remove(product_DLL* this) {
	assert(this->len>0);
	if(this->len == 1) {
		free(this->cursor);
		this->first = this->last = this->cursor = NULL;
		this->len-=1;
	} else if(this->cursor == this->last) {
		DLL_Product_Pop_Back(this);
	} else if(this->cursor == this->first) {
		DLL_Product_Pop_Front(this);
	} else {
		product_node* right=this->cursor->next;
		product_node* left=this->cursor->prev;
		free(this->cursor);
		this->cursor=this->first;
		left->next=right;
		right->prev=left;
		this->len-=1;
	}

}
///////////// FUNCIONES PUSH

/**
 * @brief Crea el producto de la DLL y lo inserta en Front.
 *   
 * @param this DLL de  products.
 * @param id Id del producto.
 * @param name Nombre del producto.
 * @param stock Numero de existencias del producto.
 * @param price Precio del producto.
 *
 * @pre this DLL ya existe 
 */
void DLL_Product_Push_Front(product_DLL* this, int id, char name[], int stock, int price) {
	assert(this);
	product_node* myproduct=Product_New_Node( id, name, stock, price );

	if(this->len == 0) {
		this->cursor=this->first=this->last=myproduct;
	} else {
		this->first->prev=myproduct;
		myproduct->next=this->first;
		this->first=myproduct;
	}
	this->len+=1;
}

/**
 * @brief Inserta un product la DLL señalado por Back.
 *    
 * @param this DLL de  products.
 * @param id Id del producto.
 * @param name Nombre del producto.
 * @param stock Numero de existencias del producto.
 * @param price Precio del producto.
 *
 * @pre this DLL ya existe 
 */
void DLL_Porduct_Push_Back(product_DLL* this, int id, char name[], int stock, int price ) {
	assert(this);
	product_node* myproduct=Product_New_Node( id, name, stock, price );
	if(this->len == 0) {
		this->cursor=this->first=this->last=myproduct;
	} else {
		this->last->next=myproduct;
		myproduct->prev=this->last;
		this->last = myproduct;

	}
	this->len+=1;
}

/**
 * @brief Regresa el nodo product señalado por cursor.
 *
 * @param this DLL de  products.
 *
 * @return el product señalado por cursor.
 */
product_node* DLL_Products_Get(product_DLL* this) {
	return this->cursor;
	// return this->cursor->product_Var
}

/**
 * @brief Regresa TRUE si len de this es 0 o FALSE en caso contrario .
 *
 * @param this DLL de  products.
 *
 * @return true o false.
 *
 * @pre this ya existe. 
 */
bool DLL_Product_Is_Empty(product_DLL* this) {
	assert(this);
	return this->len == 0;
}

/**
 * @brief Regresa el tamaño de la DLL.
 *
 * @param this DLL de  products.
 *
 * @return El len de this.
 *
 * @pre this ya existe. 
 */
int DLL_Product_Len(product_DLL* this) {
	assert(this);
	return this->len;
}

/**
 * @brief Vacia la DLL eliminando nodo por nodo y asignando len a 0.
 *
 * @param this DLL de  products.
 *
 * @pre this ya existe.
 */
void DLL_Product_Make_Empty( product_DLL* this ) {
	assert(this);
	DLL_Product_Cursor_Front(this);
	while(DLL_Product_Len(this) > 0) {
		DLL_Product_Pop_Front(this);
	}
}

/**
 * @brief Si la lista esta vacía, solo libera la memoria pedida, caso contrario llama a DLL_Product_Make_Empty y borra la DLL a su vez que livera la memoria solicitada para esto.
 *
 * @param this DLL de  products.
 *
 * @pre this ya existe.
 */
void DLL_Product_Delete(product_DLL** this) {
	
	product_DLL* productDLL = *this;
	
	if( productDLL->len == 0 ){
		assert(*this);
		free(*this);
		*this=NULL;
	}else{
		assert(*this);
		DLL_Product_Make_Empty(*this);
		free(*this);
		*this=NULL;
	}
	
	
}

/**
 * @brief Regresa una copia del product en la DLL que se encuentra en Front.
 *
 * @param this DLL de  products.
 *
 * @return La copia de el product en front de this.
 *
 * @pre this ya existe.
 * @pre len de this es mayor a 0. 
 */
product_node* DLL_Product_Front(product_DLL* this ) {
	assert(this);
	assert(this->len>0);
	product_node* copy=this->first;
	return copy;
}

/**
 * @brief Regresa una copia del product en la DLL que se encuentra en Back.
 *
 * @param this DLL de  products.
 *
 * @return La copia de el product en back de this.
 *
 * @pre this ya existe.
 * @pre len de this es mayor a 0. 
 */
product_node* DLL_Product_Back( product_DLL* this) {
	assert(this);
	assert(this->len>0);
	product_node* copy=this->last;
	return copy;
}

/**
 * @brief Hace una busqueda con dividir y vencer y busca una coincidencia con el id dado, 
 * si la encuentra coloca ahi el cursor y retorna true en caso contracio regresa false.
 *
 * @param this DLL de  products.
 * @param id El id de un producto.
 *
 * @return True si se encuentra unac coincidencia o false si no.
 */
bool DLL_Product_Find(product_DLL* this,int id ) {
	bool encontrado = false;
	int i = 0;
	
	DLL_Product_Cursor_Front( this );
	
	while( this->cursor != NULL ){
		#ifdef DEBUG
			fprintf( stderr, "BUSQUEDA LINEAL -> Cursor en First ID=(%d)\tNAME=(%s)\tPRICE=(%d)\tSTOCK=(%d)\n", this->cursor->product_id, this->cursor->product_name, this->cursor->product_price, this->cursor->product_stock );
		#endif
		
		if( this->cursor->product_id == id ){
			printf("\n\nEtnrE al if \n\n");
			encontrado = true;
			return encontrado;	
		}
		DLL_Product_Cursor_Next( this );
		//i++;
		printf("i=(%d)\n\n", i );
	}

	printf("encontrado=(%d)\n\n", encontrado );
	

	return encontrado;
}

/**
 * @brief Imprime todos los productos de toda la DLL de products.
 *
 * @param this DLL de  products.
 */
void DLL_Product_Print(product_DLL* this) {
	if( DLL_Product_Is_Empty( this ) ) {
		printf("\nEmpty list. Nothing to show." );
	} else {
		printf("\n\tID\t\tNombre\t\tCantidad\t\tPrecio");

		// usando un for en lugar de while (mi preferido):
		for( product_node* it = this->first; it != NULL; it = it->next ) {
			printf("\n\t(%i)\t|", it->product_id );
			printf("|\t(%s)\t|", it->product_name );
			printf("|\t(%i)\t|", it->product_stock );
			printf("|\t(%.2f)\n", it->product_price );
		}

	}
}

/**
 * @brief Imprime todos los campos de Product señalado por el cursor.
 *
 * @param this DLL de  products.
 */
void DLL_Product_Cursor_Print(product_DLL* this) {
	assert(this->cursor != NULL);
	printf("\n\tID\t\tNombre\t\tCantidad\t\tPrecio");
	printf("\n\t(%i)\t|", this->cursor->product_id );
	printf("|\t(%s)\t|", this->cursor->product_name );
	printf("|\t(%i)\t|", this->cursor->product_stock );
	printf("|\t(%.2f)\n", this->cursor->product_price );

}





