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


#ifndef  clients_database_INC
#define  clients_database_INC
#define MAX_CHAR 30

#include <stdlib.h>
// para malloc and friends y size_t

#include <stdbool.h>
// para bool and friends

#include <assert.h>
// para las aserciones: assert()

#include <stdio.h>
// para fprintf()

typedef struct ticket_node
{
	char product_name[ MAX_CHAR ];
	int product_amount_buyed;
	char customer_name[ MAX_CHAR ];
	char date[ MAX_CHAR ];
	

	struct ticket_node* next;
	struct ticket_node* prev;
} ticket_node;

typedef struct customer_node
{
	char customer_name[ MAX_CHAR ];
	int customer_id;
	
	ticket_node* first;
	ticket_node* last;
	ticket_node* cursor;
	size_t ticket_len;
	

	struct customer_node* next;
	struct customer_node* prev;
} customer_node;

typedef struct
{
	customer_node* first;
	customer_node* last;
	customer_node* cursor;
	size_t customer_database_len;
} customer_database_DLL;

DLL* DLL_New();
void DLL_Delete( DLL** this );

int DLL_Front( DLL* this );
int DLL_Back( DLL* this );

void DLL_Push_front( DLL* this, int item );
void DLL_Push_back( DLL* this, int item );
void DLL_Insert( DLL* this, int item );

void DLL_Pop_front( DLL* this );
void DLL_Pop_back( DLL* this );

void DLL_Erase( DLL* this );
void DLL_Remove( DLL* this, int key );

void DLL_MakeEmpty( DLL* this );

bool DLL_Find( DLL* this, int key );

int  DLL_Cursor_Get( DLL* this );
void DLL_Cursor_front( DLL* this );
void DLL_Cursor_back( DLL* this );
void DLL_Cursor_next( DLL* this );
void DLL_Cursor_prev( DLL* this );
bool DLL_Cursor_end( DLL* this );

bool DLL_IsEmpty( DLL* this );
size_t DLL_Len( DLL* this );


void DLL_PrintStructure( DLL* this );




#endif   /* ----- #ifndef clients_database_INC  ----- */
