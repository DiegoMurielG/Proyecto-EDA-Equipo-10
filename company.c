
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
	
	/*printf("\n\tCompany Pointer to direction: %p", &this);
	
	product_DLL* my_product = &(*(this->my_warehouse));
	customer_DLL* my_customers_database = &this->my_customers_database;
	
	DLL_Product_Delete( &my_product );//this->my_warehouse
	
	DLL_Customer_Delete( &my_customers_database );//**this->my_customers_database*/
	
	free(*this);
	*this=NULL;
	
	
}
