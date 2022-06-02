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


#include "company_INC.h"
#include "company.c"

#define MAX_CHAR 30
#define MAX_MEMBERS 250
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
	
	Company* Company = Company_new( "Soriana Híper", "Casanova Torres Gerardo Aldahir/nHerrera Romero Juan Pablo/nMuriel Gonz?lez Diego/nOlvera Negrete Elliot Eusebio", 2022, warehouse, customers_database );
	
	printf("\nCree  Company bien");
	
	
	////////////////////////////DELETE EVERYTHING////////////////////////////
	
	DLL_Product_Delete( &warehouse );
	DLL_Customer_Delete( &customers_database );
	Company_delete( &Company );
	*/
	
	
	//////////////////////////BIENVENIDA//////////////////////////
	printf("\n\t\tBIENVENID@ A LA APLICACIÓN PARA ADMINISTRAR\n\t\tUN ALMACÉN Y UNA BASE DE DATOS DE CLIENTES.");
	printf("\n\t\t\tA.A.B.D.C.\n\t\t(APLICACIÓN ADMINISTRADORA DE ALMACÉN Y BASE DE DATOS DE CLIENTES)");
	
	printf("\n\n\n\tIngrese la información de su compañía en los siguientes campos:");
	printf("\n\t\t1)Nombre de la compañía.");
	printf("\n\t\t2)Miembros de la compañía.");
	printf("\n\t\t3)Año de inicio de operaciones de la compañía.");
	
	char company_name[MAX_CHAR];
	char company_members[MAX_MEMBERS];
	int company_operations_time;
	
	printf("\n\n\tIngrese el nombre de su compañía: $");
	fflush( stdin );
	fgets( company_name, MAX_CHAR, stdin );
	
	#ifdef DEBUG
		fprintf( stderr, "\n\tNombre de la compañía: %s", company_name );
	#endif
	
	
	printf("\n\n\tIngrese los miembros de su compañía: $");
	fflush( stdin );
	fgets( company_members, MAX_MEMBERS, stdin );
	
	#ifdef DEBUG
		fprintf( stderr, "\n\tMiembros de la compañía: %s", company_members );
	#endif
	
	
	printf("\n\n\tIngrese el año de inicio de operaciones de su compañía: $");
	scanf("%d", &company_operations_time);
	
	#ifdef DEBUG
		fprintf( stderr, "\n\tAño de operaciones de la compañía: %d", company_operations_time );
	#endif
	
	
	/////////CREAMOS LOS CAMBOS DE COMPANY Y A COMPANY
	product_DLL* warehouse = DLL_Product_New();
	
	customer_DLL* customers_database = DLL_Customer_New();
	
	ticket_DLL* compras_ticket = DLL_Ticket_New();
	
	Company* Company = Company_new( company_name, company_members, company_operations_time, warehouse, customers_database );
	
	int op = 0;
	////////ELECCIÓN DE ACCIÓN A REALIZAR
	printf("\n\n\n\tEliga una acción a realizar:");
	printf("\n\t\t1)Consulta de almacén.");
	printf("\n\t\t2)Consulta de clientes.");
	printf("\n\t\t3)Compra de produtos para el almacén.");
	printf("\n\t\t4)Venta de productos al cliente.");
	printf("\n\t\t5)Borrar datos.");
	printf("\n\t\t6)Borrar todo y finalizar programa.");
	printf("\n\t\tElección: $");
	scanf("%d", &op );
	
	while( op<1 || op >6 ){
		printf("\n\n\tAcción no válida, se aceptan números enteros del 1 al 6.");
		printf("\n\tEliga una acción a realizar:");
		printf("\n\t\t1)Consulta de almacén.");
		printf("\n\t\t2)Consulta de clientes.");
		printf("\n\t\t3)Compra de produtos para el almacén.");
		printf("\n\t\t4)Venta de productos al cliente.");
		printf("\n\t\t5)Borrar datos.");
		printf("\n\t\t6)Borrar todo y finalizar programa.");
		printf("\n\t\tElección: $");
		scanf("%d", &op );
	}
	
	while( op>=1 || op <=6 ){
		
		switch( op ){
			case 1:
				if( DLL_Product_Is_Empty( warehouse ) == false ){
					DLL_Product_Print( warehouse );
				}else{
					printf("\n\n\t\tEl almacén está vacío, elgia la acción 3 para añadir productos.");
				}
			break;
			
			case 2:
				if( DLL_Customer_Is_Empty( customers_database ) == false ){
					DLL_Customer_Print( customers_database );
					printf("\n\n\t\tDesea consultar la información de la base de datos?( 1->YES ||0->NO) $");
					scanf("%d", &op );
					
					while( op<0 || op>1 ){
						printf("\n\n\tAcción no válida, se aceptan números enteros del 0 al 1.");
						printf("\n\n\t\tDesea consultar la información de la base de datos?( 1->YES ||0->NO) $");
						scanf("%d", &op );
					}
					
					int id_cliente = 0;
										
					while( op == 1 ){
						printf("\n\n\n\tEliga una opción:");
						printf( "\n\n\t\t1)Consultar la información de un cliente" );
						printf( "\n\n\t\t2)Consultar las ventas de la compañía" );
						printf("\n\t\tElección: $");
						scanf( "%d", &op );
						
						while( op<1 || op>2 ){
							printf("\n\n\tOpción no válida, se aceptan números enteros del 1 al 2.");
							printf("\n\n\n\tEliga una opción:");
							printf( "\n\n\t\t1)Consultar la información de un cliente" );
							printf( "\n\n\t\t2)Consultar las ventas de la compañía" );
							printf("\n\t\tElección: $");
							scanf( "%d", &op );
						}
					
						
						if( op==1 ){
							printf("\n\n\t\tIngrese el ID del cliente: %");
							scanf("%d", &id_cliente );
							
							if( DLL_Customer_Find( customers_database, id_cliente ) ){
								DLL_Customer_Cursor_Print( customers_database );
								
								/**/	
							}else{
								printf("\n\n\tID %d no encontrado, eliga la opción 1 y vuelva a ingresar el ID del cliente.", customers_database->cursor->name );						
							}
													
							
							printf("\n\n\t\tDesea consultar más información de la base de datos?( 1->YES ||0->NO) $");
							scanf("%d", &op );
							
							while( op<0 || op>1 ){
								printf("\n\n\tAcción no válida, se aceptan números enteros del 0 al 1.");
								printf("\n\n\t\tDesea consultar más información de la base de datos?( 1->YES ||0->NO) $");
								scanf("%d", &op );
							}	
						}else{//( op==2 )
							
							DLL_Tickets_Print( customers_database->cursor->listaTickets );
							
						}
						
						
					}
					
				}else{
					printf("\n\n\t\tLa base de datos de clientes está vacía.\n\t\tElgia la acción 4, al vender productos añada un cliente nuevo.");
				}
			break;
			
			case 3:
				if( DLL_Product_Is_Empty( warehouse ) == false ){
					DLL_Product_Print( warehouse );
				}else{
					printf("\n\n\t\tEl almacén está vacío, eliga la acción 1 y añada a continuación los productos comprados.");
				}
				
				printf("\n\n\n\tEliga una acción a realizar en el almacén:");
				printf("\n\t\t1)Añadir un producto nuevo.");
				printf("\n\t\t2)Modificar la cantidad en inventario de un producto existente.");
				printf("\n\t\t3)Regresar al menú de acciones.");
				printf("\n\t\tElección: $");
				scanf("%d", &op );
				
				while( op<1 || op >3 ){
					printf("\n\n\tAcción no válida, se aceptan números enteros del 1 al 3.");
					printf("\n\n\n\tEliga una acción a realizar en el almacén:");
					printf("\n\t\t1)Añadir un producto nuevo.");
					printf("\n\t\t2)Modificar la cantidad en inventario de un producto existente.");
					printf("\n\t\t3)Regresar al menú de acciones.");
					printf("\n\t\tElección: $");
					scanf("%d", &op );
				}
				
				while( op==1 || op ==2 ){
					
					if( op == 1 ){
						
						char product_name[MAX_CHAR];
						int product_stock;
						int product_id;
						int product_price;
						
						printf("\n\n\t\tAñada el nombre de su producto: $");
						//scanf("%s", product_name );
						fflush( stdin );
						fgets( product_name, MAX_CHAR, stdin );
						
						
						#ifdef DEBUG
							fprintf( stderr, "\n\tNombre del producto: %s", product_name );
						#endif
						
						
						printf("\n\n\t\tAñada la cantidad de inventario de su producto: $");
						scanf("%d", &product_stock );
						
						while( product_stock<=0 ){
							printf("\n\n\tInventario no válido, se aceptan números enteros del 1 en adelante.");
							printf("\n\n\t\tAñada la cantidad de inventario de su producto: $");
							scanf("%d", &product_stock );
						}
						
						
						printf("\n\n\t\tAñada el ID de su producto: $");
						scanf("%d", &product_id );
						
						while( product_id<=0 ){
							printf("\n\n\tID no válido, se aceptan números enteros del 1 en adelante que y no empiecen con 0.");
							printf("\n\n\t\tAñada el ID de su producto: $");
							scanf("%d", &product_id );
						}
						
						printf("\n\n\t\tAñada el precio de su producto: $");
						scanf("%d", &product_price );
						
						while( product_price<=0 ){
							printf("\n\n\tPrecio no válido, se aceptan números enteros del 1 en adelante.");
							printf("\n\n\t\tAñada el precio de su producto: $");
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
								printf("\n\t\tCuantos %s\t\tcompró? $", warehouse->cursor->product_name );
								scanf("%d", &product_stock );
								
								while( product_stock<=0 ){
									printf("\n\n\tStock no válido, se aceptan números enteros desde el 1 en adelante y que no empiecen con 0.");
									printf("\n\t\tCuantos %s\t\tcompró? $", warehouse->cursor->product_name );
									scanf("%d", &product_stock );
								}
								
								
								Product_Buy_Stock( warehouse->cursor, product_stock );
								printf("\n\t\tCantidad de %s\t\tactualizada", warehouse->cursor->product_name );
								DLL_Product_Cursor_Print( warehouse );
								
							}else{
								printf("\n\n\tEl producto con ID %d no existe.\n\tVuelva a elegir la acción 2 e ingrese el ID de un produto existente.", product_id );
							}
						}else{
							printf("\n\n\t\tEl almacén está vacío, eliga la acción 1 y añada a continuación los productos comprados.");
						}
						
					}
					
					printf("\n\n\n\tEliga una acción a realizar en el almacén:");
					printf("\n\t\t1)Añadir un producto nuevo.");
					printf("\n\t\t2)Modificar la cantidad en inventario de un producto existente.");
					printf("\n\t\t3)Regresar al menú de acciones.");
					printf("\n\t\tElección: $");
					scanf("%d", &op );
					
					while( op<1 || op >3 ){
						printf("\n\n\tAcción no válida, se aceptan números enteros del 1 al 3.");
						printf("\n\n\n\tEliga una acción a realizar en el almacén:");
						printf("\n\t\t1)Añadir un producto nuevo.");
						printf("\n\t\t2)Modificar la cantidad en inventario de un producto existente.");
						printf("\n\t\t3)Regresar al menú de acciones.");
						printf("\n\t\tElección: $");
						scanf("%d", &op );
					}
				}
				
			break;
			
			case 4:
				if( DLL_Product_Is_Empty( warehouse ) == false ){
					printf("\n==================== ALMACÉN ====================");
					DLL_Product_Print( warehouse );
					if( DLL_Customer_Is_Empty( customers_database ) == false ){
						DLL_Customer_Print( customers_database );
					}else{
						printf("\n\n\t\tLa base de datos de clientes está vacía.\n\t\tVéndale productos a un cliente nuevo y añada su ID.");
					}
					
					int customer_id;
					
					printf("\n\t\tIngrese el ID del Cliente: $" );
					scanf("%d", &customer_id );
								
					while( customer_id<=0 ){
						printf("\n\n\tID no válido, se aceptan números enteros desde el 1 en adelante y que no empiecen con 0.");
						printf("\n\t\tIngrese el ID del Cliente: $" );
						scanf("%d", &customer_id );
					}
					
					//El cliente no existe, se da la opción de crear uno o regreasr al menú de acciones
					while( DLL_Customer_Find( customers_database, customer_id ) == false ){
						printf("\n\n\t\tEliga una de la siguientes acciones:");
						printf("\n\t1)Volver a inroducir el ID del cliente.");
						printf("\n\t2)Registrar un nuevo cliente.");
						printf("\n\t3)Regresar al menú de acción.");
						printf("\n\t\tElección: $");
						scanf("%d", &op );
						
						while( op<1 || op >3 ){
							printf("\n\n\tAcción no válida, se aceptan números enteros del 1 al 3.");
							printf("\n\n\t\tEliga una de la siguientes acciones:");
							printf("\n\t1)Volver a inroducir el ID del cliente.");
							printf("\n\t2)Registrar un nuevo cliente.");
							printf("\n\t3)Regresar al menú de acción.");
							printf("\n\t\tElección: $");
							scanf("%d", &op );
						}
						
						if( op==1 ){
							printf("\n\t\tIngrese el ID del Cliente: $" );
							scanf("%d", &customer_id );
										
							while( customer_id<=0 ){
								printf("\n\n\tID no válido, se aceptan números enteros desde el 1 en adelante y que no empiecen con 0.");
								printf("\n\t\tIngrese el ID del Cliente: $" );
								scanf("%d", &customer_id );
							}
						}else if( op==2 ){//
							
							char customer_name[MAX_CHAR];
							
							printf("\n\n\t\tUsted va a registrar un Cliente Nuevo.");
							printf("\n\n\tIngrese el nombre completo del Cliente Nuevo: $");
							//scanf("%s", customer_name);
							fflush( stdin );
							fgets( customer_name, MAX_CHAR, stdin );
							
							printf("\n\t\tIngrese el ID del Cliente Nuevo: $" );
							scanf("%d", &customer_id );
										
							while( customer_id<=0 ){
								printf("\n\n\tID no válido, se aceptan números enteros desde el 1 en adelante y que no empiecen con 0.");
								printf("\n\t\tIngrese el ID del Cliente Nuevo: $" );
								scanf("%d", &customer_id );
							}
							
							DLL_Customer_Push_Front( customers_database, customer_name, customer_id );
							
							#ifdef DEBUG
								DLL_Customer_Print( customers_database );
							#endif
						}else{
							#ifdef DEBUG
								fprintf( stderr, "\nElegido 3\n" );
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
								printf("\n\n\tID no válido, se aceptan números enteros desde el 1 en adelante y que no empiecen con 0.");
								printf( "\n\n\tIngrese el ID del producto a vender: $" );
								scanf( "%d", &product_id );
							}
														
							if( DLL_Product_Find( warehouse, product_id ) == true ){
								
								printf( "\n\n\tIngrese la cantidad de %s\tque se le venderá al cliente %d: $", warehouse->cursor->product_name, customer_id );
								scanf( "%d", &product_sell_quantity );
								
								while( product_sell_quantity<=0 ){
									printf("\n\n\tCantidad no válida, se aceptan números enteros desde el 1 en adelante y que no empiecen con 0.");
									printf( "\n\n\tIngrese la cantidad de %s\tque se le venderá al cliente: $", warehouse->cursor->product_name );
									scanf( "%d", &product_sell_quantity );
								}
								
								if( Product_Sell_Stock( warehouse->cursor, product_sell_quantity ) ){
									DLL_Ticket_Push_Front( compras_ticket, product_sell_quantity, warehouse->cursor->product_name );
																		
									DLL_Customer_Cursor_Push_Ticket( customers_database, compras_ticket );
								}
																
							}else{
								printf("\n\n\t\tEl ID=(%d) del producto no se encontró.\n\t\telgia la opción 1 para volver a ingresar el ID del producto.");
							}
															
							
							printf("\n\t\tVenderle otro porducto al mismo Cliente ID=(%d)?( 1->YES ||0->NO) $", customer_id );
							scanf("%d", &op );
										
							while( op<0 || op>1 ){
								printf("\n\n\tOpción no válida, se aceptan los números enteros 0 y 1.");
								printf("\n\t\tVenderle otro porducto al mismo Cliente ID=(%d)?( 1->YES ||0->NO) $", customer_id );
								scanf("%d", &op );
							}
						}
						
						printf("\n\nCAMBIO\n\n");
						
						acum_ticket = warehouse->cursor->product_price * product_sell_quantity;
						
						printf( "\n\n\tIngrese la cantidad con la que pagó el cliente %d: $", customer_id );
						scanf( "%d", &pago_ticket );
						
						while( pago_ticket<acum_ticket ){
							printf("\n\n\tCantidad no válida, se aceptan números enteros desde el %d en adelante y que no empiecen con 0.", acum_ticket );
							printf( "\n\n\tIngrese la cantidad con la que pagó el cliente %d: $", customer_id );
							scanf( "%d", &pago_ticket );
						}
						
						pago_ticket -= acum_ticket;
						
						int num_monedas = Calcula_cambio( pago_ticket, SolCambio );
						
						Imprimir_Cambio( num_monedas, SolCambio );
						
						
					}else{
						printf("\n\n\t\tNO SE PUEDE VENDER, CANCELANDO OPERACIÓN.");
						printf("\n\n\t\tEl almacén está vacío, elgia la acción 3 para añadir productos.");
					}
					
					
					
				}else{
					printf("\n\n\t\tEl almacén está vacío, elgia la acción 3 para añadir productos.");
				}
			break;
			
			case 5:
				
				
			break;
			
			case 6:
				////////////////////////////DELETE EVERYTHING////////////////////////////
				
				DLL_Ticket_Delete( &compras_ticket );
				DLL_Product_Delete( &warehouse );
				DLL_Customer_Delete( &customers_database );
				Company_delete( &Company );
				//Salida por caso Default
				exit(0);
			break;
			
			default:
				printf("\n\n\tError Fatal, borrando todos los datos y finalizando ejecución");
				////////////////////////////DELETE EVERYTHING////////////////////////////
				
				DLL_Product_Delete( &warehouse );
				DLL_Customer_Delete( &customers_database );
				Company_delete( &Company );
				//Salida por caso Default
				exit(7);
			break;
		}
		
		
		////////ELECCIÓN DE ACCIÓN A REALIZAR
		printf("\n\n\n\tEliga una acción a realizar:");
		printf("\n\t\t1)Consulta de almacén.");
		printf("\n\t\t2)Consulta de clientes.");
		printf("\n\t\t3)Compra de produtos para el almacén.");
		printf("\n\t\t4)Venta de productos al cliente.");
		printf("\n\t\t5)Borrar datos.");
		printf("\n\t\t6)Borrar todo y finalizar programa.");
		printf("\n\t\tElección: $");
		scanf("%d", &op );
		
		while( op<1 || op >6 ){
			printf("\n\n\tAcción no válida, se aceptan números enteros del 1 al 6.");
			printf("\n\tEliga una acción a realizar:");
			printf("\n\t\t1)Consulta de almacén.");
			printf("\n\t\t2)Consulta de clientes.");
			printf("\n\t\t3)Compra de produtos para el almacén.");
			printf("\n\t\t4)Venta de productos al cliente.");
			printf("\n\t\t5)Borrar datos.");
			printf("\n\t\t6)Borrar todo y finalizar programa.");
			printf("\n\t\tElección: $");
			scanf("%d", &op );
		}
	}
	
	
	
	

	
	
	
	
	
	
	return 0;
}

