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

Company* Company_new( char name[], char members[], int operations_year, product_DLL* my_warehouse, customer_DLL* my_customers_database ){
	
	Company* myCompany = (Company*)malloc( sizeof(Company) );
	
	printf("\n\tMemory requested for Company structure");
	
	if( myCompany ){
		strncpy( myCompany->name, name, MAX_CHAR +1 );
		strncpy( myCompany->members, members, MAX_MEMBERS +1 );
		myCompany->operations_year = operations_year;
		
		printf("\n\tCompany normal fields set");
		
		product_DLL* my_warehouse = DLL_Product_New();
		myCompany->my_warehouse = my_warehouse;
		
		printf("\n\tCompany Warehouse set");
		
		customer_DLL* my_customers_database = DLL_Customer_New();
		myCompany->my_customers_database = my_customers_database;
		
		printf("\n\tCompany DB set");
		
	}else{
		#ifdef DEBUG
			fprintf(stderr,"\nProblema con memoria");
		#endif
		assert( myCompany );
	}
	
	return myCompany;
	
	
	
}

void Company_delete(Company** this){
	assert( *this );
	
	
	free(*this);
	*this=NULL;
	
	
}
