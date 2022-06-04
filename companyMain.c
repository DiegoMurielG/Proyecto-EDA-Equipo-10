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


#include "company_INC.h"

#define MAX_CHAR 30
#define MAX_MEMBERS 250
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
// para fprintf() y fgets()

#include <iso646.h>
// para usar and, or y not en lugar de &&, || y !, respectivamente

int main( void ){
	/*
	////////////////////////////////WAREHOUSE////////////////////////////////
	
	product_DLL* warehouse = DLL_Product_New();
	
	DLL_Product_Push_Front(warehouse, 10056, "Chanclas", 20, 150 );
	DLL_Product_Push_Front(warehouse, 55954, "Papitas", 20, 25 );
	DLL_Product_Push_Front(warehouse, 7978, "Pizza", 40, 150 );
	DLL_Product_Push_Front(warehouse, 15679, "Cheetos", 1, 28 );
	
	
	DLL_Product_Print(warehouse);
	
	DLL_Product_Pop_Front(warehouse);
	DLL_Product_Pop_Back(warehouse);
	
	
	printf("\nCree el Warehouse bien");
	
	///////////////////////////CUSTOMERS DATABASE////////////////////////////
		
	customer_DLL* customers_database = DLL_Customer_New();
	
	DLL_Customer_Push_Front( customers_database, "Francisco Javier Rodriguez", 333 );
	
	DLL_Customer_Cursor_Print( customers_database );
	
	DLL_Customer_Push_Front( customers_database, "Ellito", 123 );
	DLL_Customer_Push_Back( customers_database, "Juanpa", 456 );
	DLL_Customer_Push_Front( customers_database, "Gerry", 789 );
	
	DLL_Customer_Print( customers_database );
	
	
	ticket_DLL* ticket = DLL_Ticket_New();
	
	DLL_Ticket_Push_Front( ticket, 6, "Almohadas" );
	DLL_Ticket_Push_Front( ticket, 5, "Papas" );
	DLL_Ticket_Push_Front( ticket, 105, "Hot Wheels" );
	
	DLL_Ticket_Print( ticket );
	
	DLL_Customer_Find( customers_database, 456 );
	DLL_Customer_Cursor_Push_Ticket( customers_database, ticket );
	DLL_Customer_Cursor_Print( customers_database );
	
	DLL_Customer_Print( customers_database );
	
	printf("\nCree la DB bien");
	
	Company* Company = Company_new( "Soriana H�per", "Casanova Torres Gerardo Aldahir/nHerrera Romero Juan Pablo/nMuriel Gonz?lez Diego/nOlvera Negrete Elliot Eusebio", 2022, warehouse, customers_database );
	
	printf("\nCree  Company bien");
	
	
	////////////////////////////DELETE EVERYTHING////////////////////////////
	
	DLL_Product_Delete( &warehouse );
	DLL_Customer_Delete( &customers_database );
	Company_delete( &Company );
	*/
	
	
	//////////////////////////BIENVENIDA//////////////////////////
	printf("\n\t\tBIENVENID@ A LA APLICACI�N PARA ADMINISTRAR\n\t\tUN ALMAC�N Y UNA BASE DE DATOS DE CLIENTES.");
	printf("\n\t\t\tA.A.B.D.C.\n\t\t(APLICACI�N ADMINISTRADORA DE ALMAC�N Y BASE DE DATOS DE CLIENTES)");
	
	printf("\n\n\n\tIngrese la informaci�n de su compa��a en los siguientes campos:");
	printf("\n\t\t1)Nombre de la compa��a.");
	printf("\n\t\t2)Miembros de la compa��a.");
	printf("\n\t\t3)A�o de inicio de operaciones de la compa��a.");
	
	char company_name[MAX_CHAR];
	char company_members[MAX_MEMBERS];
	int company_operations_time;
	
	printf("\n\n\tIngrese el nombre de su compa��a: $");
	fflush( stdin );
	fgets( company_name, MAX_CHAR, stdin );
	
	#ifdef DEBUG
		fprintf( stderr, "\n\tNombre de la compa��a: %s", company_name );
	#endif
	
	
	printf("\n\n\tIngrese los miembros de su compa��a: $");
	fflush( stdin );
	fgets( company_members, MAX_MEMBERS, stdin );
	
	#ifdef DEBUG
		fprintf( stderr, "\n\tMiembros de la compa��a: %s", company_members );
	#endif
	
	
	printf("\n\n\tIngrese el a�o de inicio de operaciones de su compa��a: $");
	scanf("%d", &company_operations_time);
	
	#ifdef DEBUG
		fprintf( stderr, "\n\tA�o de operaciones de la compa��a: %d", company_operations_time );
	#endif
	
	
	/////////CREAMOS LOS CAMBOS DE COMPANY Y A COMPANY
	product_DLL* warehouse = DLL_Product_New();
	
	customer_DLL* customers_database = DLL_Customer_New();
	
	ticket_DLL* compras_ticket = DLL_Ticket_New();
	
	Company* Company = Company_new( company_name, company_members, company_operations_time, warehouse, customers_database );
	
	int op = 0;
	////////ELECCI�N DE ACCI�N A REALIZAR
	printf("\n\n\n\tEliga una acci�n a realizar:");
	printf("\n\t\t1)Consulta de almac�n.");
	printf("\n\t\t2)Consulta de clientes.");
	printf("\n\t\t3)Compra de produtos para el almac�n.");
	printf("\n\t\t4)Venta de productos al cliente.");
	printf("\n\t\t5)Borrar datos.");
	printf("\n\t\t6)Borrar todo y finalizar programa.");
	printf("\n\t\tElecci�n: $");
	scanf("%d", &op );
	
	while( op<1 || op >6 ){
		printf("\n\n\tAcci�n no v�lida, se aceptan n�meros enteros del 1 al 6.");
		printf("\n\tEliga una acci�n a realizar:");
		printf("\n\t\t1)Consulta de almac�n.");
		printf("\n\t\t2)Consulta de clientes.");
		printf("\n\t\t3)Compra de produtos para el almac�n.");
		printf("\n\t\t4)Venta de productos al cliente.");
		printf("\n\t\t5)Borrar datos.");
		printf("\n\t\t6)Borrar todo y finalizar programa.");
		printf("\n\t\tElecci�n: $");
		scanf("%d", &op );
	}
	
	while( op>=1 || op <=6 ){
		
		switch( op ){
			case 1:
				if( DLL_Product_Is_Empty( warehouse ) == false ){
					DLL_Product_Print( warehouse );
				}else{
					printf("\n\n\t\tEl almac�n est� vac�o, elgia la acci�n 3 para a�adir productos.");
				}
			break;
			
			case 2:
				if( DLL_Customer_Is_Empty( customers_database ) == false ){
					DLL_Customer_Print( customers_database );
					printf("\n\n\t\tDesea consultar la informaci�n de la base de datos?( 1->YES ||0->NO) $");
					scanf("%d", &op );
					
					while( op<0 || op>1 ){
						printf("\n\n\tAcci�n no v�lida, se aceptan n�meros enteros del 0 al 1.");
						printf("\n\n\t\tDesea consultar la informaci�n de la base de datos?( 1->YES ||0->NO) $");
						scanf("%d", &op );
					}
					
					int id_cliente = 0;
										
					while( op == 1 ){
						printf("\n\n\n\tEliga una opci�n:");
						printf( "\n\n\t\t1)Consultar la informaci�n de un cliente" );
						printf( "\n\n\t\t2)Consultar las ventas de la compa��a" );
						printf("\n\t\tElecci�n: $");
						scanf( "%d", &op );
						
						while( op<1 || op>2 ){
							printf("\n\n\tOpci�n no v�lida, se aceptan n�meros enteros del 1 al 2.");
							printf("\n\n\n\tEliga una opci�n:");
							printf( "\n\n\t\t1)Consultar la informaci�n de un cliente" );
							printf( "\n\n\t\t2)Consultar las ventas de la compa��a" );
							printf("\n\t\tElecci�n: $");
							scanf( "%d", &op );
						}
					
						
						if( op==1 ){
							printf("\n\n\t\tIngrese el ID del cliente: $");
							scanf("%d", &id_cliente );
							
							if( DLL_Customer_Find( customers_database, id_cliente ) == true ){
								DLL_Customer_Cursor_Print( customers_database );
								
									
							}else{
								printf("\n\n\tID %d no encontrado, eliga la opci�n 1 y vuelva a ingresar el ID del cliente.", customers_database->cursor->id );						
							}
													
							
							printf("\n\n\t\tDesea consultar m�s informaci�n de la base de datos?( 1->YES ||0->NO) $");
							scanf("%d", &op );
							
							while( op<0 || op>1 ){
								printf("\n\n\tAcci�n no v�lida, se aceptan n�meros enteros del 0 al 1.");
								printf("\n\n\t\tDesea consultar m�s informaci�n de la base de datos?( 1->YES ||0->NO) $");
								scanf("%d", &op );
							}	
						}else{//( op==2 )
							
							DLL_Tickets_Print( customers_database->cursor->listaTickets );
							
						}
						
						
					}
					
				}else{
					printf("\n\n\t\tLa base de datos de clientes est� vac�a.\n\t\tElgia la acci�n 4, al vender productos a�ada un cliente nuevo.");
				}
			break;
			
			case 3:
				if( DLL_Product_Is_Empty( warehouse ) == false ){
					DLL_Product_Print( warehouse );
				}else{
					printf("\n\n\t\tEl almac�n est� vac�o, eliga la opci�n 1 y a�ada a continuaci�n los productos comprados.");
				}
				
				printf("\n\n\n\tEliga una opci�n a realizar en el almac�n:");
				printf("\n\t\t1)A�adir un producto nuevo.");
				printf("\n\t\t2)Modificar la cantidad en inventario de un producto existente.");
				printf("\n\t\t3)Regresar al men� de acciones.");
				printf("\n\t\tElecci�n: $");
				scanf("%d", &op );
				
				while( op<1 || op >3 ){
					printf("\n\n\tAcci�n no v�lida, se aceptan n�meros enteros del 1 al 3.");
					printf("\n\n\n\tEliga una opci�n a realizar en el almac�n:");
					printf("\n\t\t1)A�adir un producto nuevo.");
					printf("\n\t\t2)Modificar la cantidad en inventario de un producto existente.");
					printf("\n\t\t3)Regresar al men� de acciones.");
					printf("\n\t\tElecci�n: $");
					scanf("%d", &op );
				}
				
				while( op==1 || op ==2 ){
					
					if( op == 1 ){
						
						char product_name[MAX_CHAR];
						int product_stock;
						int product_id;
						int product_price;
						
						printf("\n\n\t\tA�ada el nombre de su producto: $");
						//fflush( stdin );
						getchar( );//En caso de no funcionar usar fflush( stdin );
						fgets( product_name, MAX_CHAR, stdin );
						
						
						#ifdef DEBUG
							fprintf( stderr, "\n\tNombre del producto: %s", product_name );
						#endif
						
						
						printf("\n\n\t\tA�ada la cantidad de inventario de su producto: $");
						scanf("%d", &product_stock );
						
						while( product_stock<=0 ){
							printf("\n\n\tInventario no v�lido, se aceptan n�meros enteros del 1 en adelante.");
							printf("\n\n\t\tA�ada la cantidad de inventario de su producto: $");
							scanf("%d", &product_stock );
						}
						
						
						printf("\n\n\t\tA�ada el ID de su producto: $");
						scanf("%d", &product_id );
						
						while( product_id<=0 ){
							printf("\n\n\tID no v�lido, se aceptan n�meros enteros del 1 en adelante que y no empiecen con 0.");
							printf("\n\n\t\tA�ada el ID de su producto: $");
							scanf("%d", &product_id );
						}
						if( DLL_Product_Is_Empty( warehouse ) != true ){
							while( DLL_Product_Find( warehouse, product_id ) == true ){
								printf("\n\n\tID en uso, tngrese un ID diferente a %d.", product_id );
								printf("\n\tSe aceptan n�meros enteros del 1 en adelante que y no empiecen con 0.");
								printf("\n\n\t\tA�ada el ID de su producto: $");
								scanf("%d", &product_id );
							}
						}
						
						
						printf("\n\n\t\tA�ada el precio de su producto: $");
						scanf("%d", &product_price );
						
						while( product_price<=0 ){
							printf("\n\n\tPrecio no v�lido, se aceptan n�meros enteros del 1 en adelante.");
							printf("\n\n\t\tA�ada el precio de su producto: $");
							scanf("%d", &product_price );
						}
						
						DLL_Product_Push_Front( warehouse, product_id, product_name, product_stock, product_price );
						
					}else if( op == 2 ){
						
						if( DLL_Product_Is_Empty( warehouse ) == false ){
							int product_id;
							int product_stock;
							
							printf("\n\n\t\tIntroduzca el ID del producto a modificar: $");
							scanf("%d", &product_id );
							if( DLL_Product_Find( warehouse,product_id ) == true ){
								printf("\n\t\tCuantos %s\t\tcompr�? $", warehouse->cursor->product_name );
								scanf("%d", &product_stock );
								
								while( product_stock<=0 ){
									printf("\n\n\tStock no v�lido, se aceptan n�meros enteros desde el 1 en adelante y que no empiecen con 0.");
									printf("\n\t\tCuantos %s\t\tcompr�? $", warehouse->cursor->product_name );
									scanf("%d", &product_stock );
								}
								
								
								Product_Buy_Stock( warehouse->cursor, product_stock );
								printf("\n\t\tCantidad de %s\t\tactualizada", warehouse->cursor->product_name );
								DLL_Product_Cursor_Print( warehouse );
								
							}else{
								printf("\n\n\tEl producto con ID %d no existe.\n\tVuelva a elegir la acci�n 2 e ingrese el ID de un produto existente.", product_id );
							}
						}else{
							printf("\n\n\t\tEl almac�n est� vac�o, eliga opci�n 1 y a�ada a continuaci�n los productos comprados.");
						}
						
					}
					
					printf("\n\n\n\tEliga una opci�n a realizar en el almac�n:");
					printf("\n\t\t1)A�adir un producto nuevo.");
					printf("\n\t\t2)Modificar la cantidad en inventario de un producto existente.");
					printf("\n\t\t3)Regresar al men� de acciones.");
					printf("\n\t\tElecci�n: $");
					scanf("%d", &op );
					
					while( op<1 || op >3 ){
						printf("\n\n\tAcci�n no v�lida, se aceptan n�meros enteros del 1 al 3.");
						printf("\n\n\n\tEliga una opci�n a realizar en el almac�n:");
						printf("\n\t\t1)A�adir un producto nuevo.");
						printf("\n\t\t2)Modificar la cantidad en inventario de un producto existente.");
						printf("\n\t\t3)Regresar al men� de acciones.");
						printf("\n\t\tElecci�n: $");
						scanf("%d", &op );
					}
				}
				
			break;
			
			case 4:
				if( DLL_Product_Is_Empty( warehouse ) == false ){
					
					DLL_Product_Print( warehouse );
					if( DLL_Customer_Is_Empty( customers_database ) == false ){
						DLL_Customer_Print( customers_database );
					}else{
						printf("\n\n\t\tLa base de datos de clientes est� vac�a.\n\t\tV�ndale productos a un cliente nuevo y a�ada su ID.");
					}
					
					int customer_id;
					
					printf("\n\t\tIngrese el ID del Cliente: $" );
					scanf("%d", &customer_id );
								
					while( customer_id<=0 ){
						printf("\n\n\tID no v�lido, se aceptan n�meros enteros desde el 1 en adelante y que no empiecen con 0.");
						printf("\n\t\tIngrese el ID del Cliente: $" );
						scanf("%d", &customer_id );
					}
					
					//El cliente no existe, se da la opci�n de crear uno o regreasr al men� de acciones
					while( DLL_Customer_Find( customers_database, customer_id ) == false ){
						printf("\n\n\t\tEl cliente %d no existe en la base de datos.", customer_id );
						printf("\n\n\t\tEliga una de la siguientes opciones:");
						printf("\n\t1)Volver a introducir el ID del cliente.");
						printf("\n\t2)Registrar un nuevo cliente.");
						printf("\n\t\tElecci�n: $");
						scanf("%d", &op );
						
						while( op<1 || op >2 ){
							printf("\n\n\tAcci�n no v�lida, se aceptan n�meros enteros del 1 al 3.");
							printf("\n\n\t\tEliga una de la siguientes opciones:");
							printf("\n\t1)Volver a introducir el ID del cliente.");
							printf("\n\t2)Registrar un nuevo cliente.");
							printf("\n\t\tElecci�n: $");
							scanf("%d", &op );
						}
						
						if( op==1 ){
							printf("\n\t\tIngrese el ID del Cliente: $" );
							scanf("%d", &customer_id );
										
							while( customer_id<=0 ){
								printf("\n\n\tID no v�lido, se aceptan n�meros enteros desde el 1 en adelante y que no empiecen con 0.");
								printf("\n\t\tIngrese el ID del Cliente: $" );
								scanf("%d", &customer_id );
							}
						}else{// if( op==2 ){//
							
							char customer_name[MAX_CHAR];
							
							printf("\n\n\t\tUsted va a registrar un Cliente Nuevo.");
							printf("\n\n\tIngrese el nombre completo del Cliente Nuevo: $");
							//fflush( stdin );
							getchar( );//En caso de no funcionar usar fflush( stdin );
							fgets( customer_name, MAX_CHAR, stdin );
							
							printf("\n\t\tIngrese el ID del Cliente Nuevo: $" );
							scanf("%d", &customer_id );
										
							while( customer_id<=0 ){
								printf("\n\n\tID no v�lido, se aceptan n�meros enteros desde el 1 en adelante y que no empiecen con 0.");
								printf("\n\t\tIngrese el ID del Cliente Nuevo: $" );
								scanf("%d", &customer_id );
							}
							
							DLL_Customer_Push_Front( customers_database, customer_name, customer_id );
							
							#ifdef DEBUG
								DLL_Customer_Print( customers_database );
							#endif
						}
						
					}
					//HACER LA VENTA DE PRODUCTO AL CLIENTE QUE YA EXISTE
					
					int product_id;
					int product_sell_quantity;
					int acum_ticket = 0;
					int pago_ticket = 0;
					int SolCambio[ MAX_DENOMS ]={0};
					
					if( DLL_Product_Is_Empty( warehouse ) != true ){
						
						op = 1;
						
						while( op==1 ){
							
							printf( "\n\n\tIngrese el ID del producto a vender: $" );
							scanf( "%d", &product_id );
							
							while( product_id<=0 ){
								printf("\n\n\tID no v�lido, se aceptan n�meros enteros desde el 1 en adelante y que no empiecen con 0.");
								printf( "\n\n\tIngrese el ID del producto a vender: $" );
								scanf( "%d", &product_id );
							}
									
								while(DLL_Product_Find( warehouse, product_id ) != true){
									printf("\n\n\t\tEl ID=(%d) del producto no se encontr�.", product_id );
									printf( "\n\n\tIngrese el ID del producto a vender: $" );
									scanf( "%d", &product_id );
									
									while( product_id<=0 ){
										printf("\n\n\t\tEl ID=(%d) del producto no se encontr�.", product_id );
										printf( "\n\n\tIngrese el ID del producto a vender: $" );
										scanf( "%d", &product_id );
									}
								}					
								
								printf( "\n\n\tIngrese la cantidad de %s\tque se le vender� al cliente %d: $", warehouse->cursor->product_name, customer_id );
								scanf( "%d", &product_sell_quantity );
								
								while( product_sell_quantity<=0 ){
									printf("\n\n\tCantidad no v�lida, se aceptan n�meros enteros desde el 1 en adelante y que no empiecen con 0.");
									printf( "\n\n\tIngrese la cantidad de %s\tque se le vender� al cliente: $", warehouse->cursor->product_name );
									scanf( "%d", &product_sell_quantity );
								}
								
								if( Product_Sell_Stock( warehouse->cursor, product_sell_quantity ) ){
									DLL_Ticket_Push_Front( compras_ticket, product_sell_quantity, warehouse->cursor->product_name );
																		
									DLL_Customer_Cursor_Push_Ticket( customers_database, compras_ticket );
									
									acum_ticket += warehouse->cursor->product_price * product_sell_quantity;
								}
							
										
							
							
						
															
							#ifdef DEBUG
								fprintf( stderr, "\nCantidad a pagar=(%d)\n", acum_ticket );
							#endif
							
							printf("\n\t\tVenderle otro porducto al mismo Cliente ID=(%d)?( 1->YES ||0->NO) $", customer_id );
							scanf("%d", &op );
										
							while( op<0 || op>1 ){
								printf("\n\n\tOpci�n no v�lida, se aceptan los n�meros enteros 0 y 1.");
								printf("\n\t\tVenderle otro porducto al mismo Cliente ID=(%d)?( 1->YES ||0->NO) $", customer_id );
								scanf("%d", &op );
							}
						}
						
						printf("\n\nCAMBIO\n\n");
						
						
						printf( "\n\n\tTOTAL A PAGAR $%d\n\tIngrese la cantidad con la que pag� el cliente %d: $", acum_ticket, customer_id );
						scanf( "%d", &pago_ticket );
						
						while( pago_ticket<acum_ticket ){
							printf("\n\n\tCantidad no v�lida, se aceptan n�meros enteros desde el %d en adelante y que no empiecen con 0.", acum_ticket );
							printf( "\n\n\tIngrese la cantidad con la que pag� el cliente %d: $", customer_id );
							scanf( "%d", &pago_ticket );
						}
						
						pago_ticket -= acum_ticket;
						
						int num_monedas = Calcula_cambio( pago_ticket, SolCambio );
						
						printf( "\nCambio=(%d)\n",pago_ticket );
						printf( "monedaspara dar cambio=(%d)\n",num_monedas );
						
						Imprimir_Cambio( pago_ticket, num_monedas, SolCambio );
						
						
					}else{
						printf("\n\n\t\tNO SE PUEDE VENDER, CANCELANDO OPERACI�N.");
						printf("\n\n\t\tEl almac�n est� vac�o, elgia la acci�n 3 para a�adir productos.");
					}
					
					
					
				}else{
					printf("\n\n\t\tEl almac�n est� vac�o, elgia la acci�n 3 para a�adir productos.");
				}
			break;
			
			case 5:
				printf("\n\n\n\tEliga una opcion a continuaci�n:");
				printf("\n\t\t1)Borrar datos en la base de datos de los clientes.");
				printf("\n\t\t2)Borrar un producto en el almac�n.");
				printf("\n\t\t3)Regresar al men� de aciones.");
				printf("\n\t\tElecci�n: $");
				scanf("%d", &op );
				
				while( op<1 || op >3 ){
					printf("\n\n\n\tEliga una opcion a realizar:");
					printf("\n\t\t1)Borrar datos en la base de datos de los clientes.");
					printf("\n\t\t2)Borrar un producto en el almac�n.");
					printf("\n\t\t3)Regresar al men� de aciones.");
					printf("\n\t\tElecci�n: $");
					scanf("%d", &op );
				}
				
				if( op==1 ){
					
					printf("\n\n\n\tEliga una opcion a continuaci�n:");
					printf("\n\t\t1)Borrar un cliente es espec�fico.");
					printf("\n\t\t2)Borrar todos los datos de la base de datos de los clientes.");
					printf("\n\t\t3)Regresar al men� de aciones.");
					printf("\n\t\tElecci�n: $");
					scanf("%d", &op );
					
					while( op<1 || op >3 ){
						printf("\n\n\n\tEliga una opcion a continuaci�n:");
						printf("\n\t\t1)Borrar un cliente es espec�fico.");
						printf("\n\t\t2)Borrar todos los datos de la base de datos de los clientes.");
						printf("\n\t\t3)Regresar al men� de aciones.");
						printf("\n\t\tElecci�n: $");
						scanf("%d", &op );
					}
					
					if( op==1 ){
						
						if( DLL_Customer_Is_Empty( customers_database ) == false ){
							DLL_Customer_Print( customers_database );
							
							int customer_id;
							
							printf( "\n\n\tIngrese el ID del cliente a borrar de la base de datos: $" );
							scanf("%d", &customer_id );
										
							while( customer_id<=0 ){
								printf("\n\n\tID no v�lido, se aceptan n�meros enteros desde el 1 en adelante y que no empiecen con 0.");
								printf( "\n\n\tIngrese el ID del cliente a borrar de la base de datos: $" );
								scanf("%d", &customer_id );
							}
							
							while( DLL_Customer_Find( customers_database, customer_id ) == false ){
								
								printf("\n\tID %d no encontrado.", customer_id );
								printf("\n\n\t\tEliga una de la siguientes opciones:");
								printf("\n\t1)Volver a introducir el ID del cliente.");
								printf("\n\t2)Regresar.");
								printf("\n\t\tElecci�n: $");
								scanf("%d", &op );
								
								while( op<1 || op >2 ){
									printf("\n\n\tOpci�n no v�lida, se aceptan n�meros enteros del 1 al 3.");
									printf("\n\n\t\tEliga una de la siguientes opciones:");
									printf("\n\t1)Volver a introducir el ID del cliente.");
									printf("\n\t2)Regresar.");
									printf("\n\t\tElecci�n: $");
									scanf("%d", &op );
								}
								
								if( op==1 ){
									
									printf( "\n\n\tIngrese el ID del cliente a borrar de la base de datos: $" );
									scanf("%d", &customer_id );
												
									while( customer_id<=0 ){
										printf("\n\n\tID no v�lido, se aceptan n�meros enteros desde el 1 en adelante y que no empiecen con 0.");
										printf( "\n\n\tIngrese el ID del cliente a borrar de la base de datos: $" );
										scanf("%d", &customer_id );
									}
									
								}else{//( op==2 )
									#ifdef DEBUG
										fprintf( stderr, "\nRegresando al men� de acciones.");
									#endif
								}
								
							}
							
							printf( "\n\n\tSeguro que desea borrar al siguiente cliente:" );
							DLL_Customer_Cursor_Print( customers_database );
							printf("\n\n\t\tEliga una de la siguientes opciones:");
							printf("\n\t1)Si, borrar el cliente.");
							printf("\n\t0)NO borrar el cliente.");
							printf("\n\t\tElecci�n: $");
							scanf( "%d", &op );
							
							while( op<0 || op >1 ){
								printf("\n\n\tOpci�n no v�lida, se aceptan el 0 y el 1.");
								printf("\n\n\t\tEliga una de la siguientes opciones:");
								printf("\n\t1)Si, borrar el cliente.");
								printf("\n\t0)NO borrar el cliente.");
								printf("\n\t\tElecci�n: $");
								scanf( "%d", &op );
							}
							
							if( op==1 ){
								DLL_Customer_Remove( customers_database );
								printf("\n\tCliente borrado correctamente.");
							}else{
								printf("\n\tOperaci�n cancelada.");
							}
							
						}else{
							printf("\n\n\t\tLa base de datos de clientes est� vac�a.\n\t\tElgia la acci�n 4, al vender productos a�ada un cliente nuevo.");
						}
					}else if( op==2 ){
						
						printf( "\n\n\tDesea BORRAR TODA LA BASE DE DATOS DE CLIENTES:" );
						printf("\n\n\t\tEliga una de la siguientes opciones:");
						printf("\n\t1)Si, BORRAR TODA LA BASE DE DATOS DE CLIENTES.");
						printf("\n\t0)NO borrar toda la base de datos de clientes.");
						printf("\n\t\tElecci�n: $");
						scanf( "%d", &op );
						
						while( op<0 || op >1 ){
							printf("\n\n\tOpci�n no v�lida, se aceptan el 0 y el 1.");
							printf("\n\n\t\tEliga una de la siguientes opciones:");
							printf("\n\t1)Si, BORRAR TODA LA BASE DE DATOS DE CLIENTES.");
							printf("\n\t0)NO borrar toda la base de datos de clientes.");
							scanf( "%d", &op );
						}
						
						if( op==1 ){
							printf( "\n\n\tConfirmar 1: seguro que desea BORRAR TODA LA BASE DE DATOS DE CLIENTES" );
							printf("\n\t\tEliga una de la siguientes opciones:");
							printf("\n\t1)Si, BORRAR TODA LA BASE DE DATOS DE CLIENTES.");
							printf("\n\t0)NO borrar toda la base de datos de clientes.");
							printf("\n\t\tElecci�n: $");
							scanf( "%d", &op );
							
							while( op<0 || op >1 ){
								printf("\n\n\tOpci�n no v�lida, se aceptan el 0 y el 1.");
								printf("\n\n\t\tEliga una de la siguientes opciones:");
								printf("\n\t1)Si, BORRAR TODA LA BASE DE DATOS DE CLIENTES.");
								printf("\n\t0)NO borrar toda la base de datos de clientes.");
								printf("\n\t\tElecci�n: $");
								scanf( "%d", &op );
							}
							
							if( op==1 ){
								printf( "\n\n\tConfirmar 2: SEGURO QUE DESEA BORRAR ===TODA=== LA BASE DE DATOS DE CLIENTES" );
								printf("\n\t\tEliga una de la siguientes opciones:");
								printf("\n\t1)SI, DESEO BORRAR ===TODA=== LA BASE DE DATOS DE CLIENTES.");
								printf("\n\t0)NO borrar toda la base de datos de clientes y cancelar la operaci�n.");
								printf("\n\t\tElecci�n: $");
								scanf( "%d", &op );
								
								while( op<0 || op >1 ){
									printf("\n\n\tOpci�n no v�lida, se aceptan el 0 y el 1.");
									printf("\n\n\t\tEliga una de la siguientes opciones:");
									printf("\n\t1)Si, BORRAR TODA LA BASE DE DATOS DE CLIENTES.");
									printf("\n\t0)NO borrar toda la base de datos de clientes.");
									printf("\n\t\tElecci�n: $");
									scanf( "%d", &op );
								}
								
								if( op==1 ){
									
									printf( "\n\n\tBORRANDO TODA LA BASE DE DATOS DE CLIENTES." );
									if( DLL_Customer_Is_Empty( customers_database ) != true ){
										DLL_Customer_Make_Empty( customers_database );
									}
									
									
									printf( "\n\n\tBase de datos borrada correctamente." );
									printf( "\n\tIngrese cualquier n�mero para continuar: $" );
									scanf( "%d", &op );
									
									
								}else{//( op==0 )
									printf( "\n\n\tOperaci�n cancelada." );
								}
								
							}else{//( op==0 )
								printf( "\n\n\tOperaci�n cancelada." );
							}
							
						}else{//( op==0 )
							printf( "\n\n\tOperaci�n cancelada." );
						}
						
					}else{//( op==3 )
						#ifdef DEBUG
							fprintf( stderr, "\nRegresando al men� de acciones.");
						#endif
					}
					
				}else if( op==2 ){
					
					printf("\n\n\n\tEliga una opci�n a continuaci�n:");
					printf("\n\t\t1)Borrar un producto en espec�fico.");
					printf("\n\t\t2)Regresar al men� de aciones.");
					printf("\n\t\tElecci�n: $");
					scanf("%d", &op );
					
					while( op<1 || op >2 ){
						printf( "\n\n\n\tOpci�n no v�lida." );
						printf("\n\tEliga una opci�n a continuaci�n:");
						printf("\n\t\t1)Borrar un producto en espec�fico.");
						printf("\n\t\t2)Regresar al men� de aciones.");
						printf("\n\t\tElecci�n: $");
						scanf("%d", &op );
					}
					
					if( op==1 ){
						
						if( DLL_Product_Is_Empty( warehouse ) != true ){
							int product_id;
							printf( "\n\n\tIngrese el ID del producto a borrar: $" );
							scanf( "%d", &product_id );
							
							while( product_id<=0 ){
								printf("\n\n\tID no v�lido, se aceptan n�meros enteros desde el 1 en adelante y que no empiecen con 0.");
								printf( "\n\n\tIngrese el ID del producto a borrar: $" );
								scanf( "%d", &product_id );
							}
							
							while( DLL_Product_Find( warehouse, product_id ) == false ){
								printf("\n\n\t\tEl producto %d no existe en la base de datos.", product_id );
								printf("\n\n\t\tEliga una de la siguientes opciones:");
								printf("\n\t1)Volver a introducir el ID del cliente.");
								printf("\n\t2)Cancelar la operaci�n.");
								printf("\n\t\tElecci�n: $");
								scanf("%d", &op );
							}
							
							DLL_Product_Remove( warehouse );
							printf("\n\tProducto borrado correctamente.");	
						}else{
							printf("\n\n\t\tEl almac�n est� vac�o, elgia la acci�n 3 para a�adir productos.");
						}
						
						
					}else{
						#ifdef DEBUG
							fprintf( stderr, "\n\n\tRegresando al men� de acciones." );
						#endif
					}
					
					
				}else{//( op==3 )
				
					#ifdef DEBUG
						fprintf( stderr, "\n\n\tRegresando al men� de acciones." );
					#endif
					
				}
				
			break;
			
			case 6:
				////////////////////////////DELETE EVERYTHING////////////////////////////
				
				printf( "\n\n\tConfirmar: SEGURO QUE DESEA BORRAR ===TODA=== LA INFORMACI�N." );
				printf("\n\t\tEliga una de la siguientes opciones:");
				printf("\n\t1)SI, DESEO BORRAR ===TODA=== LA INFORMACI�N.");
				printf("\n\t0)NO borrar toda la informaci�n y cancelar la operaci�n.");
				printf("\n\t\tElecci�n: $");
				scanf( "%d", &op );
				
				if( op==1 ){
					printf( "\n\n\n\tBORRANDO TODOS LOS DATOS, GRACIAS POR USAR LA" );
					printf("\n\t\t\tA.A.B.D.C.\n\t\t(APLICACI�N ADMINISTRADORA DE ALMAC�N Y BASE DE DATOS DE CLIENTES)");
		
					
					DLL_Ticket_Delete( &compras_ticket );
					DLL_Product_Delete( &warehouse );
					DLL_Customer_Delete( &customers_database );
					Company_delete( &Company );
					
					printf( "\n\n\tDatos borrados correctamente." );
					printf( "\n\t1)Continuar y salir." );
					scanf( "%d", &op );
					
					while( op!=1 ){
						printf( "\n\n\tPara salir y terminar la ejecuci�n ingrese 1." );
						printf( "\n\n\tDatos borrados correctamente." );
						printf( "\n\t1)Continuar y salir." );
						scanf( "%d", &op );
					}
					
					//Salida por caso Default
					exit(0);
				}
				
				
			break;
			
			default:
				printf("\n\n\tError Fatal, borrando todos los datos y finalizando ejecuci�n.");
				////////////////////////////DELETE EVERYTHING////////////////////////////
				DLL_Ticket_Delete( &compras_ticket );
				DLL_Product_Delete( &warehouse );
				DLL_Customer_Delete( &customers_database );
				Company_delete( &Company );
				//Salida por caso Default
				exit(7);
			break;
		}
		
		
		////////ELECCI�N DE ACCI�N A REALIZAR
		printf("\n\n\n\tEliga una acci�n a realizar:");
		printf("\n\t\t1)Consulta de almac�n.");
		printf("\n\t\t2)Consulta de clientes.");
		printf("\n\t\t3)Compra de produtos para el almac�n.");
		printf("\n\t\t4)Venta de productos al cliente.");
		printf("\n\t\t5)Borrar datos.");
		printf("\n\t\t6)Borrar todo y finalizar programa.");
		printf("\n\t\tElecci�n: $");
		scanf("%d", &op );
		
		while( op<1 || op >6 ){
			printf("\n\n\tAcci�n no v�lida, se aceptan n�meros enteros del 1 al 6.");
			printf("\n\tEliga una acci�n a realizar:");
			printf("\n\t\t1)Consulta de almac�n.");
			printf("\n\t\t2)Consulta de clientes.");
			printf("\n\t\t3)Compra de produtos para el almac�n.");
			printf("\n\t\t4)Venta de productos al cliente.");
			printf("\n\t\t5)Borrar datos.");
			printf("\n\t\t6)Borrar todo y finalizar programa.");
			printf("\n\t\tElecci�n: $");
			scanf("%d", &op );
		}
	}
	
	
	
	

	
	
	
	
	
	
	return 0;
}

