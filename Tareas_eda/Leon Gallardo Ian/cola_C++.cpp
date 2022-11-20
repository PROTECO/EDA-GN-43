#include<iostream>
#include<stdlib.h>

struct nodo
{
	int dato;
	nodo *sig;
};

using namespace std;

nodo *primero = NULL;
nodo *ultimo = NULL;

void insertar()
{
	nodo *nuevo = new nodo();
	cout<<"ingrese un dato: ";
	cin>>nuevo->dato;
	nuevo->sig==NULL;
	
	if(primero==NULL)
	{
		primero=nuevo;
		ultimo=nuevo;
	}
	else
	{
		ultimo->sig=nuevo;
		ultimo=nuevo;
	}
}

void eliminar()
{
	if(primero==NULL)
	{
		cout<<"no hay datos que eliminar";
	}
	else
	{
		if(primero==ultimo)
		{
			primero==NULL;
			ultimo==NULL;
		}
		else
		{
			primero=primero->sig;	
		}
	}
}

void mostrar()
{
	nodo *indice=primero;
	cout<<"\nElementos guardados:\n";
	while(indice!=NULL)
	{
		cout<<" | "<<indice->dato<<" | ";
		indice=indice->sig;
	}
	cout<<"\n";
}

int main()
{
    int op;
    
    
	cout<<"\nMENU:\n";
	cout<<"1. insertar elemento\n";
	cout<<"2. eliminar elemento\n";
	cout<<"3. mostrar la cola\n";
	cout<<"4. salir\n";
	
	do
	{
		cout<<"\n>>";
		cin>>op;
		
		switch(op)
		{
			case 1: 
				insertar(); 
				break;
			case 2: 
				eliminar(); 
				break;
			case 3: 
				mostrar(); 
				break;
			case 4: 
				cout<<"adiosito"; 
				break;
			default: 
				cout<<"opcion no valida"; 
				break;
		}	
	}while(op!=4);
    return 0;
}

