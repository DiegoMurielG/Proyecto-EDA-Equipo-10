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
#include "warehouse_INC.h"

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
