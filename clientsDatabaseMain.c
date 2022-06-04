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


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "clientsDatabase_INC.h"


int main( void ){
	
	customer_DLL* customerDatabase = DLL_Customer_New();
	
	DLL_Customer_Push_Front( customerDatabase, "Francisco Javier Rodriguez", 333 );
	
	DLL_Customer_Cursor_Print( customerDatabase );
	
	DLL_Customer_Push_Front( customerDatabase, "Ellito", 123 );
	DLL_Customer_Push_Back( customerDatabase, "Juanpa", 456 );
	DLL_Customer_Push_Front( customerDatabase, "Gerry", 789 );
	
	DLL_Customer_Print( customerDatabase );
	
	
	ticket_DLL* ticket = DLL_Ticket_New();
	
	DLL_Ticket_Push_Front( ticket, 6, "Almohadas" );
	DLL_Ticket_Push_Front( ticket, 5, "Papas" );
	DLL_Ticket_Push_Front( ticket, 105, "Hot Wheels" );
	
	ticket_DLL* ticket2 = DLL_Ticket_New();
	
	DLL_Ticket_Push_Front( ticket, 1, "Pretzels" );
	DLL_Ticket_Push_Front( ticket, 2, "Teclado RGB" );
	DLL_Ticket_Push_Front( ticket, 3, "Chocolate" );
	
	
	DLL_Customer_Find( customerDatabase, 456 );
	DLL_Customer_Cursor_Push_Ticket( customerDatabase, ticket );
	DLL_Customer_Cursor_Print( customerDatabase );
	DLL_Tickets_Print( ticket );
	
	//DLL_Customer_Pop_Front( customerDatabase );
	//DLL_Customer_Remove( customerDatabase );
	
	//DLL_Customer_Print( customerDatabase );
	
	DLL_Ticket_Delete( &ticket );
	DLL_Customer_Delete( &customerDatabase );
	
	return 0;
}
