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


#ifndef  company_INC
#define  company_INC
#define MAX_CHAR 30
#define MAX_MEMBERS 250
//#define MAX_DENOMS 30
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

//////////////////////////////MÓDULOS///////////////////////////////
#include "warehouse_INC.h"
#include "warehouse.c"

#include "clientsDatabase_INC.h"
#include "clientsDatabase.c"

typedef struct{
	char name[ MAX_CHAR ];
	char members[ MAX_MEMBERS ];
	int operations_year;
	
	product_DLL* my_warehouse;
	customer_DLL* my_customers_database;
	
}Company;

Company* Company_new( char name[], char members[], int operations_year, product_DLL* my_warehouse, customer_DLL* my_customers_database );

void Company_delete(Company** this);


#endif   /* ----- #ifndef company_INC  -----*/
