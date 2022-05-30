#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "New_warehouse_INC.h"
#include "New_warehouse.c"

int main(){
	product_DLL* mylist=DLL_Product_New();
	DLL_Product_Push_Front(mylist,"Chanclas",20,10056);
	DLL_Product_Push_Front(mylist,"Papitas",20,55954);
	DLL_Product_Push_Front(mylist,"Pizza",40,7978);
	DLL_Product_Push_Front(mylist,"Cheetos",1,15679);
	
	
	//DLL_Product_Print(mylist);
	
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
	
	Product_Buy_Stock(mylist->cursor,-5);
	
	DLL_Product_Cursor_Print(mylist);
	
	
	//DLL_Product_Print(mylist);
	
	DLL_Product_Delete(mylist);
	return 0;
}
