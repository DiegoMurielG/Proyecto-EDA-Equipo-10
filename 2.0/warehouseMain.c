#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "warehouse_INC.h"
#include "warehouse.c"

int main(){
	product_DLL* mylist=DLL_Product_New();
	DLL_Product_Push_Front(mylist, 10056, "Chanclas", 20, 150 );
	DLL_Product_Push_Front(mylist, 55954, "Papitas", 20, 25 );
	DLL_Product_Push_Front(mylist, 7978, "Pizza", 40, 150 );
	DLL_Product_Push_Front(mylist, 15679, "Cheetos", 1, 28 );
	
	
	DLL_Product_Print(mylist);
	
	DLL_Product_Pop_Front(mylist);
	DLL_Product_Pop_Back(mylist);
	
	int cantidad=DLL_Product_Len(mylist);
	printf("\n Existencia de %i productos",cantidad);
	bool existe = DLL_Product_Find(mylist, 7978);
	
	if(existe == true){
		printf("\n EL PRODUCTO SI EXISTE");
	}
	else{
		printf("\n EL PRODUCTO NO EXISTE");
	}
	
	Product_Buy_Stock(mylist->cursor,5);
	
	DLL_Product_Cursor_Print(mylist);
	
	Product_Sell_Stock(mylist->cursor,45);
	
	DLL_Product_Cursor_Print(mylist);
	
	int SolCambio[MAX_DENOMS] = {0};
	int num_monedas = Calcula_cambio( 1895, SolCambio );
	
	Imprimir_Cambio( num_monedas, SolCambio );
	
	
	
	//DLL_Product_Print(mylist);
	
	DLL_Product_Delete( &mylist );
	return 0;
}
