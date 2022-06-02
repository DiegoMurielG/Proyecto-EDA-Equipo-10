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
 *				  |	Muriel Gonz?lez Diego							|
 *				  |	Olvera Negrete Elliot Eusebio					|
 */


#ifndef  warehouse_INC
#define  warehouse_INC
#define MAX_CHAR 30
#define MAX_DENOMS 12
#define DEBUG

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

#include <iso646.h>
// para usar and, or y not en lugar de &&, || y !, respectivamente

typedef struct product_node{
    char product_name[ MAX_CHAR ];
    int product_stock;
    int product_id;
    int product_price;
    
	struct product_node* prev;
	struct product_node* next;
}product_node;

typedef struct{
 	product_node* first;
	product_node* last;
	product_node* cursor;
	int len;
	
} product_DLL;

/*typedef struct
{
  product_DLL* lista;
  char name[MAX_CHAR];
  
} DLL_Warehouses;*/
///////////////////////////////// PRODUCT FUNCIONES /////////////////////////
void Product_Delete_Node(product_node* this);
bool Product_Sell_Stock(product_node* this, int howmany);
void Product_Buy_Stock(product_node* this, int howmany);

bool Cambio_Es_factible( int c, int p, int acum );
bool Candidato_Es_solucion( int p, int acum );
bool Cambio_bt( int c[], int i, int j, int s[], int *s_idx, int p, int *acum );
int Activar_Cambio_bt( int c[], int tam_c, int s[], int tam_s, int p );
int Calcula_cambio( int cambio, int SolCambio[] );
void Imprimir_Cambio( int num_monedas, int SolCambio[] );
///////////////////////////////// PRODUCT DLL FUNCIONES /////////////////////////
product_DLL* DLL_Product_New();
void DLL_Product_Delete(product_DLL** this);
void DLL_Product_Cursor_Front(product_DLL* this);
void DLL_Product_Cursor_Last(product_DLL* this);
void DLL_Product_Cursor_Next(product_DLL* this);
void DLL_Product_Cursor_Prev(product_DLL* this);
void DLL_Product_Pop_Front(product_DLL* this);
void DLL_Product_Pop_Back(product_DLL* this);
void DLL_Product_Remove(product_DLL* this);
void DLL_Product_Push_Front(product_DLL* this, int id, char name[], int stock, int price);
void DLL_Product_Push_Back(product_DLL* this, int id, char name[], int stock, int price);
product_node* DLL_Product_Get(product_DLL* this);
bool DLL_Product_Is_Empty(product_DLL* this);
int DLL_Product_Len(product_DLL* this);
void DLL_Product_Make_Empty( product_DLL* this );
product_node* DLL_Product_Front(product_DLL* this );
product_node* DLL_Product_Back( product_DLL* this);
bool DLL_Product_Find(product_DLL* this,int id );
void DLL_Product_Print(product_DLL* this);
void DLL_Product_Cursor_Print(product_DLL* this);

//////////////////////////////////////////////////////////
/*
//DLLProductsNew(): DLLProducts*

//+ DLLProductsDelete( DLLProducts** ): void

//+ DLLProductsPushFront( DLLProducts, Product ): void

//+ DLLProductsPushBack( DLLProducts, Product ): void

//+ DLLProductsPopFront( DLLProducts* ): void

//+ DLLProductsPopBack( DLLProducts* ): void

//+ DLLProductsRemove( DLLProducts, id ): void
/*
//+ DLLProductsGet( DLLProducts ): productNode*

//+ DLLProductsCursorFront( DLLProducts* ): void

//+ DLLProductsCursorBack( DLLProducts* ): void

//+ DLLProductsCursorNext( DLLProducts* ): void

//+ DLLProductsCursorPrev( DLLProducts* ): void

//+ DLLProductsIsEmpty( DLLProducts* ): bool

//+ DLLProductsLen( DLLProducts* ): int

//+ DLLProductsMakeEmpty( DLLProducts* ): void

//+ DLLProductsFront( DLLProducts* ): productNode*

//+ DLLProductsBack( DLLProducts* ): productNode*

//+ DLLProductsFind( DLLProducts*, id ): bool

											   */
#endif   /* ----- #ifndef warehouse_INC  -----*/
