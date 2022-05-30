
#include "New_warehouse_INC.h"

////////////////////////////////// PRODUCT_NODE FUNCIONES ////////////
static product_node* Product_New_Node( char name[],int stock, int id ){
	product_node* mynode=(product_node*)malloc(sizeof(product_node));
	
	if(mynode != NULL){
		mynode->next=NULL;
		mynode->prev=NULL;
		mynode->product_id=id;
		mynode->product_stock=stock;
		strncpy(mynode->product_name,name,MAX_CHAR+1);
	}
	else{
		#ifdef DEBUG
		fprintf(stderr,"\n Problema con memoria");
		#endif
		exit (1);
	}
	return mynode;
}

void Product_Delete_Node(product_node* this){
	assert(this);
	free(this);
	this=NULL;
}

void Product_Sell_Stock(product_node* this, int howmany){
	if(this->product_stock < howmany && howmany<0){
		#ifdef DEBUG
		fprintf(stderr,"\n No hay stock suficiente");
		#endif
	}
	else{
		this->product_stock-=howmany;
	}
}
void Product_Buy_Stock(product_node* this, int howmany){
	if(howmany<0){
		#ifdef DEBUG
		fprintf(stderr,"\n Error con la compra de productos howmany= %i",howmany);
		#endif
	}
	else{
		this->product_stock+=howmany;
	}
}
///////////////////////////////////// PRODUCT DLL FUNCIONES //////////////////////////

product_DLL* DLL_Product_New(){
	product_DLL* mylist=(product_DLL*)malloc(sizeof(product_DLL));
	if(mylist != NULL){
		mylist->cursor=NULL;
		mylist->first=NULL;
		mylist->last=NULL;
		mylist->len=0;
	}
	else{
		#ifdef DEBUG
		fprintf(stderr,"\n Problema con memoria");
		#endif
		exit (1);
	}
}

// FUNCIONES CURSOR
void DLL_Product_Cursor_Front(product_DLL* this){
	assert(this->len>0);
	this->cursor=this->first;
}
void DLL_Product_Cursor_Last(product_DLL* this){
	assert(this->len>0);
	this->cursor=this->last;
}
void DLL_Product_Cursor_Next(product_DLL* this){
	assert(this->len>0);
	this->cursor=this->cursor->next;
}
void DLL_Product_Cursor_Prev(product_DLL* this){
	assert(this->len>0);
	this->cursor=this->cursor->prev;
}

// FUNCIONES POP
/// ELIMINA EL NODO EN FRONT
void DLL_Product_Pop_Front(product_DLL* this){
	assert(this->len>0);
	if(this->len == 1){
	 	free(this->first);
	 	this->first = this->last = this->cursor = NULL;
	}
	else{
		product_node* right = this->first->next;
		free(this->first);
		this->first=right;
		right->prev=NULL;
		this->cursor=this->first;
	}
	this->len -=1;

}
void DLL_Product_Pop_Back(product_DLL* this){
	assert(this->len>0);
	if(this->len == 1){
		free(this->last);
	 	this->first = this->last = this->cursor = NULL;
	}
	else{
		product_node* left=this->last->prev;
		free(this->last);
		this->last=left;
		this->last->next=NULL;
		this->cursor=this->last;
	}
	this->len-=1;
}
void DLL_Product_Remove(product_DLL* this){
	assert(this->len>0);
	if(this->len == 1){
		free(this->cursor);
	 	this->first = this->last = this->cursor = NULL;
	 	this->len-=1;
	}
	else if(this->cursor == this->last){
		DLL_Product_Pop_Back(this);
	}
	else if(this->cursor == this->first){
		DLL_Product_Pop_Front(this);
	}
	else{
		product_node* right=this->cursor->next;
		product_node* left=this->cursor->prev;
		free(this->cursor);
		this->cursor=this->first;
		left->next=right;
		right->prev=left;
		this->len-=1;
	}

}
///////////// FUNCIONES PUSH

void DLL_Product_Push_Front(product_DLL* this,char name[],int stock,int id){
	assert(this);
	product_node* myproduct=Product_New_Node(name,stock,id);
	
	if(this->len == 0){
		this->cursor=this->first=this->last=myproduct;
	}
	else{
		this->first->prev=myproduct;
		myproduct->next=this->first;
		this->first=myproduct;
	}
	this->len+=1;
}
void DLL_Porduct_Push_Back(product_DLL* this,char name[],int stock,int id){
	assert(this);
	product_node* myproduct=Product_New_Node(name,stock,id);
	if(this->len == 0){
		this->cursor=this->first=this->last=myproduct;
	}
	else{
		this->last->next=myproduct;
		myproduct->prev=this->last;
		this->last = myproduct;
		
	}
	this->len+=1;
}
product_node* /* Product* */ DLL_Products_Get(product_DLL* this){
	return this->cursor;
	// return this->cursor->product_Var
}
bool DLL_Product_Is_Empty(product_DLL* this){
	assert(this);
	return this->len == 0;
}

int DLL_Product_Len(product_DLL* this){
	assert(this);
	return this->len;
}
void DLL_Product_Make_Empty( product_DLL* this ){
	assert(this);
	DLL_Product_Cursor_Front(this);
	while(DLL_Product_Len(this) > 0){
		DLL_Product_Pop_Front(this);
	}
}

void DLL_Product_Delete(product_DLL* this){
	DLL_Product_Make_Empty(this);
	free(this);
	this=NULL;
}

product_node* DLL_Product_Front(product_DLL* this ){
	assert(this);
	assert(this->len>0);
	product_node* copy=this->first;
	return copy;
}
product_node* DLL_Product_Back( product_DLL* this){
	assert(this);
	assert(this->len>0);
	product_node* copy=this->last;
	return copy;
}

bool DLL_Product_Find(product_DLL* this,int id ){
	bool encontrado = false;
	int sup=(this->len)-1;
	int inf=0;
	while( inf <= sup ){
        int centro = ( sup + inf ) / 2;
        #ifdef DEBUG
            fprintf( stderr, "centro: %d\n", centro );
        #endif
        DLL_Product_Cursor_Front(this);
		for(int i=0; i<centro; i++ ){
			DLL_Product_Cursor_Next(this);
		}

        if( id == this->cursor->product_id ){//Caso base 1
            #ifdef DEBUG
                fprintf( stderr, "Coincidencia encontrada en : %d\n", centro );
            #endif
            return !encontrado;

        }else if( id < this->cursor->product_id ){
            if( sup == inf ){        //Caso base 2
                #ifdef DEBUG
                    fprintf( stderr, "No hay coincidencias (inf = %d)\n", inf );
                #endif
                return encontrado;

            }

            sup = centro - 1;
            #ifdef DEBUG
                fprintf( stderr, "Voy por la izqueirda (%d, %d)\n", inf, sup );
            #endif
        }else{
            inf = centro + 1;
            #ifdef DEBUG
                fprintf( stderr, "Voy por la derecha (%d, %d)\n", inf, sup );
            #endif
        }

    }
    return encontrado;
}

void DLL_Product_Print(product_DLL* this)
{
   if( DLL_Product_Is_Empty( this ) )
   {
      printf("\nEmpty list. Nothing to show." );
   }
   else
   {
      printf("\n\t id \t nombre \t cantidad ");

      // usando un for en lugar de while (mi preferido):
      for( product_node* it = this->first; it != NULL; it = it->next )
      {
         printf("\n\t(%i)->", it->product_id );
         printf("\t(%s)->", it->product_name );
         printf("\t(%i)->\n", it->product_stock );
      }

   }
}

void DLL_Product_Cursor_Print(product_DLL* this){
	assert(this->cursor != NULL);
	printf("\n\t id \t nombre \t cantidad ");
	printf("\n\t(%i)->", this->cursor->product_id );
    printf("\t(%s)->", this->cursor->product_name );
    printf("\t(%i)->\n", this->cursor->product_stock );

}


/*
void DLL_Product_make_empty(product_DLL* this){
	assert(this);
	assert(this->len > 0);
	
	while(this->len > 0){

	}
}*/


