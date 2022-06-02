#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "clientsDatabase_INC.h"
#include "clientsDatabase.c"

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
