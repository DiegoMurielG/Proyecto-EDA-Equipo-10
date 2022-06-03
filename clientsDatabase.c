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
* Todas las funciones para crear, destruir, insertar, extraer y buscar tickets y clientes de la base de datos.
*
* @author Equipo 10 EDA 1
* @version 1.0
* @date 30/05/2022
*
*
* @code
*
*int main(){
*	customer_DLL* customerDatabase = DLL_Customer_New();
*	
*	DLL_Customer_Push_Front( customerDatabase, "Francisco Javier Rodriguez", 333 );
*	
*	DLL_Customer_Cursor_Print( customerDatabase );
*	
*	DLL_Customer_Push_Front( customerDatabase, "Ellito", 123 );
*	DLL_Customer_Push_Back( customerDatabase, "Juanpa", 456 );
*	DLL_Customer_Push_Front( customerDatabase, "Gerry", 789 );
*	
*	DLL_Customer_Print( customerDatabase );
*	
*	ticket_DLL* ticket = DLL_Ticket_New();
*	
*	DLL_Ticket_Push_Front( ticket, 6, "Almohadas" );
*	DLL_Ticket_Push_Front( ticket, 5, "Papas" );
*	DLL_Ticket_Push_Front( ticket, 105, "Hot Wheels" );
*	
*	DLL_Ticket_Print( ticket );
*	
*	DLL_Customer_Find( customerDatabase, 456 );
*	DLL_Customer_Cursor_Push_Ticket( customerDatabase, ticket );
*	DLL_Customer_Cursor_Print( customerDatabase );
*	
*	//DLL_Customer_Pop_Front( customerDatabase );
*	//DLL_Customer_Remove( customerDatabase );
*	
*	DLL_Customer_Print( customerDatabase );
*	
*	DLL_Ticket_Delete( &ticket );
*	DLL_Customer_Delete( &customerDatabase );
*	
*	return 0;
*}
*
* @endcode
*
* 
*/
#include "clientsDatabase_INC.h"

////////////////////////////////// TICKET_NODE FUNCIONES ////////////

/**
 * @brief Crea un nodo de tipo ticket.
 *
 * @param quantityBuyed La cantidad del producto vendido.
 * @param name[] Nombre del producto vendido .
 *
 * @return Nodo tipo ticket.
 */
static ticket_node* Ticket_New_Node( int quantityBuyed, char name[] ) {
	ticket_node* mynode=(ticket_node*)malloc(sizeof(ticket_node));

	if(mynode != NULL) {
		mynode->next=NULL;
		mynode->prev=NULL;
		mynode->quantityBuyed = quantityBuyed;
		strncpy(mynode->product_name,name,MAX_CHAR+1);
		
	} else {
	#ifdef DEBUG
		fprintf(stderr,"\n Problema con memoria");
	#endif
		exit (1);
	}
	return mynode;
}

/**
 * @brief Borra un nodo tipo ticket.
 *
 * @param this Nodo tipo ticket.
 *
 * @pre this ya existe
 */
void Ticket_Delete_Node(ticket_node* this){
	assert(this);
	free(this);
	this=NULL;
}

/*void Product_Sell_Stock(product_node* this, int howmany) {
	if( this->product_stock < howmany ) {
//#ifdef DEBUG
		printf("\nNo hay stock suficiente");//fprintf("stderr,"\nNo hay stock suficiente");
//#endif
	} else if( howmany<0 ){
		printf("\nDATO NO VÁLIDO (%d)\nOPERACIÓN FINALIZADA", howmany);
		
	} else {
		this->product_stock-=howmany;
	}
}
void Product_Buy_Stock(product_node* this, int howmany) {
	if(howmany<0) {
#ifdef DEBUG
		fprintf(stderr,"\n Error con la compra de productos howmany= %i",howmany);
#endif
	} else {
		this->product_stock+=howmany;
	}
}*/
///////////////////////////////////// TICKET DLL FUNCIONES //////////////////////////

/**
 * @brief Crea una DLL de objetos de tipo de tipo ticket.
 */
ticket_DLL* DLL_Ticket_New(){
	ticket_DLL* mylist=(ticket_DLL*)malloc(sizeof(ticket_DLL));
	if(mylist != NULL) {
		mylist->cursor=NULL;
		mylist->first=NULL;
		mylist->last=NULL;
		mylist->len=0;
	} else {
#ifdef DEBUG
		fprintf(stderr,"\n Problema con memoria");
#endif
		exit (1);
	}
	return mylist;
}

// FUNCIONES CURSOR
/**
 * @brief Coloca el cursor de una DLL en Front.
 *
 * @param this DLL de  tickets.
 *
 * @pre len de this es mayor a 0
 */
void DLL_Ticket_Cursor_Front(ticket_DLL* this){
	assert(this->len>0);
	this->cursor=this->first;
}

/**
 * @brief Coloca el cursor de una DLL en Last.
 * 
 * @param this DLL de  tickets.
 *
 * @pre len de this es mayor a 0
 */
void DLL_Ticket_Cursor_Last(ticket_DLL* this){
	assert(this->len>0);
	this->cursor=this->last;
}

/**
 * @brief Coloca el cursor de una DLL en Next de cursor.
 * 
 * @param this DLL de  tickets.
 *
 * @pre len de this es mayor a 0.
 */
void DLL_Ticket_Cursor_Next(ticket_DLL* this){
	assert(this->len>0);
	this->cursor=this->cursor->next;
}

/**
 * @brief Coloca el cursor de una DLL en Prev de cursor.
 *  
 * @param this DLL de  tickets.
 *
 * @pre len de this es mayor a 0.
 */
void DLL_Ticket_Cursor_Prev(ticket_DLL* this){
	assert(this->len>0);
	this->cursor=this->cursor->prev;
}

// FUNCIONES POP
/// ELIMINA EL NODO EN FRONT

/**
 * @brief Elimina el producto de la DLL señalado por Front.
 *   
 * @param this DLL de  tickets.
 *
 * @pre len de this es mayor a 0. 
 */
void DLL_Ticket_Pop_Front(ticket_DLL* this){
	assert(this->len>0);
	if(this->len == 1) {
		free(this->first);
		this->first = this->last = this->cursor = NULL;
	} else {
		ticket_node* right = this->first->next;
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
 * @param this DLL de  tickets.
 *
 * @pre len de this es mayor a 0. 
 */
void DLL_Ticket_Pop_Back(ticket_DLL* this){
	assert(this->len>0);
	if(this->len == 1) {
		free(this->last);
		this->first = this->last = this->cursor = NULL;
	} else {
		ticket_node* left=this->last->prev;
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
 * @param this DLL de  tickets.
 *
 * @pre len de this es mayor a 0. 
 */
void DLL_Ticket_Remove(ticket_DLL* this){
	assert(this->len>0);
	if(this->len == 1) {
		free(this->cursor);
		this->first = this->last = this->cursor = NULL;
		this->len-=1;
	} else if(this->cursor == this->last) {
		DLL_Ticket_Pop_Back(this);
	} else if(this->cursor == this->first) {
		DLL_Ticket_Pop_Front(this);
	} else {
		ticket_node* right=this->cursor->next;
		ticket_node* left=this->cursor->prev;
		free(this->cursor);
		this->cursor=this->first;
		left->next=right;
		right->prev=left;
		this->len-=1;
	}

}
///////////// FUNCIONES PUSH

/**
 * @brief Crea el ticket de la DLL y lo inserta en Front.
 *   
 * @param this DLL de  tickets.
 * @param quantityBuyed cantidad vendida de product.
 * @param name[] Nombre del producto.
 *
 * @pre this DLL ya existe 
 */
void DLL_Ticket_Push_Front(ticket_DLL* this, int quantityBuyed, char name[] ){
	assert(this);
	ticket_node* myTicket=Ticket_New_Node( quantityBuyed, name );

	if(this->len == 0) {
		this->cursor=this->first=this->last=myTicket;
	} else {
		this->first->prev=myTicket;
		myTicket->next=this->first;
		this->first=myTicket;
	}
	this->len+=1;
}

/**
 * @brief Inserta un ticket a la DLL señalado por Back.
 *    
 * @param this DLL de  tickets.
 * @param quantityBuyed cantidad vendida de product.
 * @param name[] Nombre del producto.
 *
 * @pre this DLL ya existe 
 */
void DLL_Ticket_Push_Back(ticket_DLL* this, int quantityBuyed, char name[] ){
	assert(this);
	ticket_node* myTicket=Ticket_New_Node( quantityBuyed, name );
	if(this->len == 0) {
		this->cursor=this->first=this->last=myTicket;
	} else {
		this->last->next=myTicket;
		myTicket->prev=this->last;
		this->last = myTicket;

	}
	this->len+=1;
}

/**
 * @brief Regresa el nodo ticket señalado por cursor.
 *
 * @param this DLL de  tickets.
 *
 * @return el ticket señalado por cursor.
 */
ticket_node* DLL_Ticket_Get(ticket_DLL* this){
	return this->cursor;
	// return this->cursor->product_Var
}

/**
 * @brief Regresa TRUE si len de this es 0 o FALSE en caso contrario .
 *
 * @param this DLL de  tickets.
 *
 * @return true o false.
 *
 * @pre this ya existe. 
 */
bool DLL_Ticket_Is_Empty(ticket_DLL* this){
	assert(this);
	return this->len == 0;
}

/**
 * @brief Regresa el tamaño de la DLL.
 *
 * @param this DLL de  tickets.
 *
 * @return El len de this.
 *
 * @pre this ya existe. 
 */
int DLL_Ticket_Len(ticket_DLL* this){
	assert(this);
	return this->len;
}

/**
 * @brief Vacia la DLL eliminando nodo por nodo y asignando len a 0.
 *
 * @param this DLL de  tickets.
 *
 * @pre this ya existe.
 */
void DLL_Ticket_Make_Empty( ticket_DLL* this ){
	assert(this);
	DLL_Ticket_Cursor_Front(this);
	while(DLL_Ticket_Len(this) > 0) {
		DLL_Ticket_Pop_Front(this);
	}
}

/**
 * @brief Llama a DLL_Ticket_Make_Empty y borra la DLL a su vez que livera la memoria solicitada para esto.
 *
 * @param this DLL de  tickets.
 *
 * @pre this ya existe.
 */
void DLL_Ticket_Delete(ticket_DLL** this){
	
	ticket_DLL* ticketDLL = *this;
	
	if( ticketDLL->len == 0 ){
		assert(*this);
		free(*this);
		*this=NULL;
	}else{	
		assert(*this);
		DLL_Ticket_Make_Empty(*this);
		free(*this);
		*this=NULL;
	}
}

/**
 * @brief Regresa una copia del ticket en la DLL que se encuentra en Front.
 *
 * @param this DLL de  tickets.
 *
 * @return La copia de el ticket en front de this.
 *
 * @pre this ya existe.
 * @pre len de this es mayor a 0. 
 */
ticket_node* DLL_Ticket_Front(ticket_DLL* this ){
	assert(this);
	assert(this->len>0);
	ticket_node* copy=this->first;
	return copy;
}

/**
 * @brief Regresa una copia del ticket en la DLL que se encuentra en Back.
 *
 * @param this DLL de  products.
 *
 * @return La copia de el ticket en back de this.
 *
 * @pre this ya existe.
 * @pre len de this es mayor a 0. 
 */
ticket_node* DLL_Ticket_Back( ticket_DLL* this){
	assert(this);
	assert(this->len>0);
	ticket_node* copy=this->last;
	return copy;
}

/**
 * @brief Imprime todos los campos de ticket.
 *
 * @param this DLL de  tickets.
 */
void DLL_Tickets_Print(ticket_DLL* this){
	if( DLL_Ticket_Is_Empty( this ) ) {
		printf("\nEmpty list. Nothing to show." );
	} else {
		printf("\n\n\tMOSTRANDO TODOS LOS TICKETS\n\tNombre del Producto\t\tCantidad");

		// usando un for en lugar de while (mi preferido):
		for( ticket_node* it = this->first; it != NULL; it = it->next ) {
			printf("\n\t(%s)\t|", it->product_name );
			printf("|\t(%i)\t|\n", it->quantityBuyed );
		}
	}
}


////////////////////////////////// CUSTOMER_NODE FUNCIONES ////////////


static customer_node* Customer_New_Node( char name[], int id ) {
	customer_node* mynode=(customer_node*)malloc(sizeof(customer_node));

	if(mynode != NULL) {
		mynode->next=NULL;
		mynode->prev=NULL;
		strncpy(mynode->name,name,MAX_CHAR+1);
		mynode->id=id;
		mynode->lenTickets = 0;
		mynode->listaTickets = NULL;
	} else {
	#ifdef DEBUG
		fprintf(stderr,"\n Problema con memoria");
	#endif
		exit (1);
	}
	return mynode;
}

void Customer_Delete_Node(customer_node* this) {
	assert(this);
	free(this);
	this=NULL;
}

/*void Product_Sell_Stock(product_node* this, int howmany) {
	if( this->product_stock < howmany ) {
//#ifdef DEBUG
		printf("\nNo hay stock suficiente");//fprintf("stderr,"\nNo hay stock suficiente");
//#endif
	} else if( howmany<0 ){
		printf("\nDATO NO VÁLIDO (%d)\nOPERACIÓN FINALIZADA", howmany);
		
	} else {
		this->product_stock-=howmany;
	}
}
void Product_Buy_Stock(product_node* this, int howmany) {
	if(howmany<0) {
#ifdef DEBUG
		fprintf(stderr,"\n Error con la compra de productos howmany= %i",howmany);
#endif
	} else {
		this->product_stock+=howmany;
	}
}*/
///////////////////////////////////// CUSTOMER DLL FUNCIONES //////////////////////////

/**
 * @brief Crea una lista doblemente enlazada de nodos de tipo customer.
 *
 * @return DLL de customers.
 *
 * @post mylist ya existe
 */
customer_DLL* DLL_Customer_New(){
	customer_DLL* mylist=(customer_DLL*)malloc(sizeof(customer_DLL));
	if(mylist != NULL) {
		mylist->cursor=NULL;
		mylist->first=NULL;
		mylist->last=NULL;
		mylist->len=0;
	} else {
#ifdef DEBUG
		fprintf(stderr,"\n Problema con memoria");
#endif
		exit (1);
	}
}

// FUNCIONES CURSOR

/**
 * @brief Coloca el cursor de una DLL en Front.
 *
 * @param this DLL de  customers.
 *
 * @pre len de this es mayor a 0.
 */
void DLL_Customer_Cursor_Front(customer_DLL* this){
	assert(this->len>0);
	this->cursor=this->first;
}

/**
 * @brief Coloca el cursor de una DLL en Last.
 * 
 * @param this DLL de  customers.
 *
 * @pre len de this es mayor a 0
 */
void DLL_Customer_Cursor_Last(customer_DLL* this){
	assert(this->len>0);
	this->cursor=this->last;
}

/**
 * @brief Coloca el cursor de una DLL en Next de cursor.
 * 
 * @param this DLL de  customers.
 *
 * @pre len de this es mayor a 0.
 */
void DLL_Customer_Cursor_Next(customer_DLL* this){
	assert(this->len>0);
	this->cursor=this->cursor->next;
}

/**
 * @brief Coloca el cursor de una DLL en Prev de cursor.
 *  
 * @param this DLL de  customers.
 *
 * @pre len de this es mayor a 0.
 */
void DLL_Customer_Cursor_Prev(customer_DLL* this){
	assert(this->len>0);
	this->cursor=this->cursor->prev;
}

// FUNCIONES POP
/// ELIMINA EL NODO EN FRONT

/**
 * @brief Elimina el customer de la DLL señalado por Front.
 *   
 * @param this DLL de  customers.
 *
 * @pre len de this es mayor a 0. 
 */
void DLL_Customer_Pop_Front(customer_DLL* this){
	assert(this->len>0);
	if(this->len == 1) {
		free(this->first);
		this->first = this->last = this->cursor = NULL;
	} else {
		customer_node* right = this->first->next;
		free(this->first);
		this->first=right;
		right->prev=NULL;
		this->cursor=this->first;
	}
	this->len -=1;

}

/**
 * @brief Elimina el customer de la DLL señalado por Back.
 *    
 * @param this DLL de  customers.
 *
 * @pre len de this es mayor a 0. 
 */
void DLL_Customer_Pop_Back(customer_DLL* this){
	assert(this->len>0);
	if(this->len == 1) {
		free(this->last);
		this->first = this->last = this->cursor = NULL;
	} else {
		customer_node* left=this->last->prev;
		free(this->last);
		this->last=left;
		this->last->next=NULL;
		this->cursor=this->last;
	}
	this->len-=1;
}


/**
 * @brief Elimina el customer de la DLL señalado por Cursor.
 *  
 * @param this DLL de  customers.
 *
 * @pre len de this es mayor a 0. 
 */
void DLL_Customer_Remove(customer_DLL* this){
	assert(this->len>0);
	if(this->len == 1) {
		free(this->cursor);
		this->first = this->last = this->cursor = NULL;
		this->len-=1;
	} else if(this->cursor == this->last) {
		DLL_Customer_Pop_Back(this);
	} else if(this->cursor == this->first) {
		DLL_Customer_Pop_Front(this);
	} else {
		customer_node* right=this->cursor->next;
		customer_node* left=this->cursor->prev;
		free(this->cursor);
		this->cursor=this->first;
		left->next=right;
		right->prev=left;
		this->len-=1;
	}

}
///////////// FUNCIONES PUSH

/**
 * @brief Crea el customer de la DLL y lo inserta en Front.
 *   
 * @param this DLL de  customers.
 * @param name[] Nombre del customer.
 * @param id Id del customer.
 *
 * @pre this DLL ya existe. 
 */
void DLL_Customer_Push_Front(customer_DLL* this, char name[], int id){
	assert(this);
	customer_node* myCustomer=Customer_New_Node( name, id );

	if(this->len == 0) {
		this->cursor=this->first=this->last=myCustomer;
	} else {
		this->first->prev=myCustomer;
		myCustomer->next=this->first;
		this->first=myCustomer;
	}
	this->len+=1;
}

/**
 * @brief Crea el customer de la DLL y lo inserta en Back.
 *    
 * @param this DLL de  customers.
 * @param name[] Nombre del customer.
 * @param id Id del customer.
 *
 * @pre this DLL ya existe 
 */
void DLL_Customer_Push_Back(customer_DLL* this, char name[], int id){
	assert(this);
	customer_node* myCustomer=Customer_New_Node( name, id );
	if(this->len == 0) {
		this->cursor=this->first=this->last=myCustomer;
	} else {
		this->last->next=myCustomer;
		myCustomer->prev=this->last;
		this->last = myCustomer;

	}
	this->len+=1;
}

/**
 * @brief Inserta un nodo de tipo ticket en un customer.
 *    
 * @param this DLL de  customers.
 * @param thisTicket DLL de  tickets. 
 */
void DLL_Customer_Cursor_Push_Ticket(customer_DLL* this, ticket_DLL* thisTicket){
	this->cursor->listaTickets = thisTicket;
	this->cursor->lenTickets++;
}

/**
 * @brief Regresa el nodo customer señalado por cursor.
 *
 * @param this DLL de  customers.
 *
 * @return El customer señalado por cursor.
 */
customer_node* DLL_Customer_Get(customer_DLL* this){
	return this->cursor;
}

/**
 * @brief Regresa TRUE si len de this es 0 o FALSE en caso contrario .
 *
 * @param this DLL de  customers.
 *
 * @return true o false.
 *
 * @pre this ya existe. 
 */
bool DLL_Customer_Is_Empty(customer_DLL* this){
	assert(this);
	return this->len == 0;
}

/**
 * @brief Regresa el tamaño de la DLL.
 *
 * @param this DLL de  customers.
 *
 * @return El len de this.
 *
 * @pre this ya existe. 
 */
int DLL_Customer_Len(customer_DLL* this){
	assert(this);
	return this->len;
}

/**
 * @brief Vacia la DLL eliminando nodo por nodo y asignando len a 0.
 *
 * @param this DLL de  customers.
 *
 * @pre this ya existe.
 */
void DLL_Customer_Make_Empty( customer_DLL* this ){
	assert(this);
	DLL_Customer_Cursor_Front(this);
	while(DLL_Customer_Len(this) > 0) {
		DLL_Customer_Pop_Front(this);
	}
}

/**
 * @brief Llama a DLL_Product_Make_Empty y borra la DLL a su vez que libera la memoria solicitada para esto.
 *
 * @param this DLL de  customers.
 *
 * @pre this ya existe.
 */
void DLL_Customer_Delete(customer_DLL** this){
	
	customer_DLL* customerDLL = *this;
	
	if( customerDLL->len == 0 ){
		assert(*this);
		free(*this);
		*this=NULL;
	}else{
		assert(*this);
		DLL_Customer_Make_Empty(*this);
		free(*this);
		*this=NULL;	
	}
	
}

/**
 * @brief Regresa una copia del customer en la DLL que se encuentra en Front.
 *
 * @param this DLL de  customers.
 *
 * @return La copia de el customer en front de this.
 *
 * @pre this ya existe.
 * @pre len de this es mayor a 0. 
 */
customer_node* DLL_Customer_Front(customer_DLL* this ){
	assert(this);
	assert(this->len>0);
	customer_node* copy=this->first;
	return copy;
}

/**
 * @brief Regresa una copia del customer en la DLL que se encuentra en Back.
 *
 * @param this DLL de  customers.
 *
 * @return La copia de el customer en back de this.
 *
 * @pre this ya existe.
 * @pre len de this es mayor a 0. 
 */
customer_node* DLL_Customer_Back( customer_DLL* this){
	assert(this);
	assert(this->len>0);
	customer_node* copy=this->last;
	return copy;
}

/**
 * @brief Hace una busqueda lineal y busca una coincidencia con el id dado, 
 * si la encuentra coloca ahi el cursor y retorna true en caso contracio regresa false.
 *
 * @param this DLL de  customers.
 * @param id El id de un customer.
 *
 * @return True si se encuentra unac coincidencia o false si no.
 */
bool DLL_Customer_Find(customer_DLL* this,int id ){
	bool encontrado = false;
	int i = 0;
	
	if( this->len == 0 ){
		#ifdef DEBUG
			fprintf( stderr, "No buscar nada en DB vacía\n" );
		#endif
	}else{
		DLL_Customer_Cursor_Front( this );
	
		while( this->cursor != NULL ){//this->cursor->id != id && 
			#ifdef DEBUG
				fprintf( stderr, "BUSQUEDA LINEAL -> Cursor en First NAME=%s\tID=%d\n", this->cursor->name, this->cursor->id );
			#endif
			
			if( this->cursor->id == id ){
				printf("\n\nEtnrE al if \n\n");
				encontrado = true;
				
				return 	encontrado;
			}
		
			DLL_Customer_Cursor_Next( this );
		}

	}
	
	printf("encontrado=(%d)\n\n", encontrado );
	
	return encontrado;
}

/**
 * @brief Imprime todos los campos de customer de toda la DLL de customers.
 *
 * @param this DLL de  customers.
 */
void DLL_Customer_Print(customer_DLL* this){
	if( DLL_Customer_Is_Empty( this ) ) {
		printf("\nEmpty list. Nothing to show." );
	} else {
		// usando un for en lugar de while (mi preferido):
		for( customer_node* it = this->first; it != NULL; it = it->next ) {
			
			printf("\n\n\tSHOWING NEW CUSTOMER");
			printf("\n\tID = %i\t|", it->id );
			printf("|\tNAME = %s\t|", it->name );
			/*if( it->lenTickets == 0 ){
				printf("||\n\tTOTAL OF TICKETS = 0\t||");
			}else{
				printf("||\n\t\tTOTAL OF TICKETS = %i\t||", it->listaTickets->len );
			}*/
		}

	}
}

/**
 * @brief Imprime todos los campos de customer señalado por el cursor.
 *
 * @param this DLL de  customers.
 */
void DLL_Customer_Cursor_Print(customer_DLL* this) {
	assert(this->cursor != NULL);
	printf("\n\tID = %i\t|", this->cursor->id );
	printf("|\tNAME = %s\t|", this->cursor->name );
	/*if( this->cursor->lenTickets == 0 ){
		printf("||\n\tTOTAL OF TICKETS = 0\t||");
	}else{
		printf("||\n\t\tTOTAL OF TICKETS = %i\t||", this->cursor->lenTickets );
	}*/
}





