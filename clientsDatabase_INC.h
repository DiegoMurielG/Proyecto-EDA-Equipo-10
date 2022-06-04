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
 * 2022 - EDA 1 - |	Equipo 10				|
 *		  |	Herrera Romero Juan Pablo		|
 *		  |	Muriel Gonz?lez Diego	(Equipo 10)	|
 */


#ifndef  clientsDatabase_INC
#define  clientsDatabase_INC

//#include "warehouse_INC.h"
//#include "warehouse.c"

#define MAX_CHAR 30

#include <stdlib.h>
// para malloc and friends y size_t
#include <string.h>
// para usar strncpy

#include <stdbool.h>
// para bool and friends

#include <assert.h>
// para las aserciones: assert()

#include <stdio.h>
// para fprintf()
typedef struct ticket_node{
    int quantityBuyed;
    char product_name[ MAX_CHAR ];
    
	struct ticket_node* prev;
	struct ticket_node* next;
}ticket_node;

typedef struct{
 	ticket_node* first;
	ticket_node* last;
	ticket_node* cursor;
	int len;
	
} ticket_DLL;

typedef struct customer_node
{
  char name[MAX_CHAR];
  int id;
  int lenTickets;
  
  ticket_DLL* listaTickets;
  
  struct customer_node* next;
  struct customer_node* prev;
  
} customer_node;

typedef struct{
 	customer_node* first;
	customer_node* last;
	customer_node* cursor;
	int len;
	
} customer_DLL;
///////////////////////////////// TICKET FUNCIONES /////////////////////////
void Ticket_Delete_Node(ticket_node* this);
//void Ticket_Sell_Stock(product_node* this, int howmany);
//void Ticket_Buy_Stock(product_node* this, int howmany);
///////////////////////////////// TICKET DLL FUNCIONES /////////////////////////
ticket_DLL* DLL_Ticket_New();
void DLL_Ticket_Delete(ticket_DLL** this);
void DLL_Ticket_Cursor_Front(ticket_DLL* this);
void DLL_Ticket_Cursor_Last(ticket_DLL* this);
void DLL_Ticket_Cursor_Next(ticket_DLL* this);
void DLL_Ticket_Cursor_Prev(ticket_DLL* this);
void DLL_Ticket_Pop_Front(ticket_DLL* this);
void DLL_Ticket_Pop_Back(ticket_DLL* this);
void DLL_Ticket_Push_Front(ticket_DLL* this, int quantityBuyed, char name[] );
void DLL_Ticket_Push_Back(ticket_DLL* this, int quantityBuyed, char name[] );
ticket_node* DLL_Ticket_Get(ticket_DLL* this);
bool DLL_Ticket_Is_Empty(ticket_DLL* this);
int DLL_Ticket_Len(ticket_DLL* this);
void DLL_Ticket_Make_Empty( ticket_DLL* this );
customer_node* DLL_Customer_Front(customer_DLL* this );
customer_node* DLL_Customer_Back( customer_DLL* this);
//bool DLL_Ticket_Find(ticket_DLL* this,int id );
void DLL_Tickets_Print(ticket_DLL* this);
//void DLL_Ticket_Cursor_Print(ticket_DLL* this);

///////////////////////////////// CUSTOMER FUNCIONES /////////////////////////
void Customer_Delete_Node(customer_node* this);
//void Ticket_Sell_Stock(product_node* this, int howmany);
//void Ticket_Buy_Stock(product_node* this, int howmany);
///////////////////////////////// CUSTOMER DLL FUNCIONES /////////////////////////
customer_DLL* DLL_Customer_New();
void DLL_Customer_Delete(customer_DLL** this);
void DLL_Customer_Cursor_Front(customer_DLL* this);
void DLL_Customer_Cursor_Last(customer_DLL* this);
void DLL_Customer_Cursor_Next(customer_DLL* this);
void DLL_Customer_Cursor_Prev(customer_DLL* this);
void DLL_Customer_Pop_Front(customer_DLL* this);
void DLL_Customer_Pop_Back(customer_DLL* this);
void DLL_Customer_Remove(customer_DLL* this);
void DLL_Customer_Push_Front(customer_DLL* this, char name[], int id);
void DLL_Customer_Push_Back(customer_DLL* this, char name[], int id);
void DLL_Customer_Cursor_Push_Ticket(customer_DLL* this, ticket_DLL* thisTicket);
customer_node* DLL_Customer_Get(customer_DLL* this);
bool DLL_Customer_Is_Empty(customer_DLL* this);
int DLL_Customer_Len(customer_DLL* this);
void DLL_Customer_Make_Empty( customer_DLL* this );
customer_node* DLL_Customer_Front(customer_DLL* this );
customer_node* DLL_Customer_Back( customer_DLL* this);
bool DLL_Customer_Find(customer_DLL* this,int id );
void DLL_Customer_Print(customer_DLL* this);
//void DLL_Ticket_Cursor_Print(customer_DLL* this);								   
#endif   /* ----- #ifndef CustomerDatabase_INC  -----*/
