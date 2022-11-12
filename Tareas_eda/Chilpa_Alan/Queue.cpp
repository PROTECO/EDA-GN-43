#include<iostream>
#include<stdlib.h>
#include<stdbool.h>

using namespace std;

struct nodo{
	int dato;
	struct nodo *siguiente;
	
};
struct nodo *primer=NULL;
struct nodo *ultimo=NULL;

bool empty(){
	bool vacia;
	if (primer==NULL){
		cout<<"********La cola esta vacía********\n";
		vacia=true;
	} 
	else{
		vacia=false;
	}
	return vacia;
}

void insertar(int x){
	nodo *nuevo;
	nuevo=malloc(sizeof(struct nodo));
	nuevo->dato=x;
	nuevo->siguiente=NULL;
	if(empty()){
		primer=nuevo;
		ultimo=nuevo;
	}
	else{
		ultimo->siguiente=nuevo;
		ultimo=nuevo;
	}
}

int extraer(){
	if(!empty()){
		int informacion=primer->dato;
		struct nodo *aux=primer;
		if(primer==ultimo){
			primer=NULL;
			ultimo=NULL;
		}
		else{
			primer=primer->siguiente;
		}
		free(aux);
		return informacion;
	}else{
		return -1;
	}
}

void imprimir(){
	struct nodo *reco=primer;
	cout<<"\nElementos de la cola\n";
	while (reco!=NULL){
		cout<<" | "<<reco->dato<<" | ";
		reco=reco->siguiente;
	}
	cout<<"\n";
}

int menu(){
	int op;
	cout<<"\n\t Menu ";
	cout<<"\n 1. Insertar un elemento en la COLA ";
	cout<<"\n 2. Quitar un elemento de la COLA ";
	cout<<"\n 3. Mostrar la COLA ";
	cout<<"\n 4. Salir ";
	cout<<"\n\nIngrese la opcion: ";
	cin>>op;
	return op;
}

int main(){
	int opc, info;
	opc=menu();
	while(opc!=4){
		if(opc==1){
			cout<<"\nDa un elemento para la cola: ";
			cin>>info;
			insertar(info);	
		}
		if(opc==2){
			extraer();	
		}
		if(opc==3){
			imprimir();
	    }
	    opc=menu();
	}
	
	cout<<"Adioooooooooooos! \n";
	return 0;
}
