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
 *				  |	Muriel González Diego							|
 *				  |	Olvera Negrete Elliot Eusebio					|
 */


#ifndef  warehouse_INC
#define  warehouse_INC
#define MAX_CHAR 30

#include <stdlib.h>
// para malloc and friends y size_t

#include <stdbool.h>
// para bool and friends

#include <assert.h>
// para las aserciones: assert()

#include <stdio.h>
// para fprintf()

typedef struct product_node
{
	char product_name[ MAX_CHAR ];
	int product_amount;
	int product_id;
	

	struct product_node* next;
	struct product_node* prev;
} product_node;

typedef struct
{
	product_node* first;
	product_node* last;
	product_node* cursor;
	size_t warehouse_len;
} warehouse_DLL;
/////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////
warehouse_DLL* Warehouse_New();
void Warehouse_Delete( warehouse_DLL** this );

int Warehouse_Front( warehouse_DLL* this );
int Warehouse_Back( warehouse_DLL* this );

void Warehouse_Insert( warehouse_DLL* this, char name[], int amount, int id );
void Warehouse_Push_front( warehouse_DLL* this, char name[], int amount, int id );
void Warehouse_Push_back( warehouse_DLL* this, char name[], int amount, int id );

void Warehouse_Pop_front( warehouse_DLL* this );
void Warehouse_Pop_back( warehouse_DLL* this );

void Warehouse_Remove( warehouse_DLL* this, int key );

void Warehouse_MakeEmpty( warehouse_DLL* this );

bool Warehouse_Find( warehouse_DLL* this, int key );

int  Warehouse_Cursor_Get( warehouse_DLL* this );
void Warehouse_Cursor_front( warehouse_DLL* this );
void Warehouse_Cursor_back( warehouse_DLL* this );
void Warehouse_Cursor_next( warehouse_DLL* this );
void Warehouse_Cursor_prev( warehouse_DLL* this );
bool Warehouse_Cursor_end( warehouse_DLL* this );

product_node* Warehouse_busqueda_producto_id(warehouse_DLL* this,int id );
bool Warehouse_IsEmpty( warehouse_DLL* this );
int Warehouse_Len( warehouse_DLL* this );


void Warehouse_PrintStructure( warehouse_DLL* this );





#endif   /* ----- #ifndef warehouse_INC  ----- */
