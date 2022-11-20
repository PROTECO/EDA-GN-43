#include<iostream>
#include<stdlib.h>

using namespace std;

struct nombres
{
	nombres *siguiente;
	char nombre[30];
	int id;
};

nombres *lista;

void insertarNombre()
{
	nombres *nuevo=new nombres();
	nuevo->siguiente=lista;
	cout<<"ingrese id del nombre: ";
	cin>>nuevo->id;
	cout<<"ingrese el nombre: ";
	cin>>nuevo->nombre;
	lista=nuevo;
}

int eliminarNombre()
{
	nombres *actual=new nombres();
	actual=lista;
	nombres *anterior=new nombres();
	anterior=NULL;
	
	int nodoBuscado;
	int B=0;
	
	cout<<("\nDame el ID que desea eliminar: ");
	cin>>nodoBuscado;
	
	if(lista!=NULL)
	{
		do{
			if(actual->id==nodoBuscado){
				if(actual==lista){
					lista=lista->siguiente;
				}
				else{
					anterior->siguiente=actual->siguiente;	
				} 
				B=1;
			}
				anterior=actual;
				actual=actual->siguiente;
			
		} while(actual!=NULL&&B==0);
	
	}
	if(B==1)
	free(anterior);
	return nodoBuscado;
}

void imprimirNombres(nombres*)
{
	nombres *indice=lista;
	if(lista!=NULL)
	{
		while(indice!=NULL)
		{
			printf("%d --- %s\n",indice->id,indice->nombre);;
			indice=indice->siguiente;
		}
		cout<<"\n";
	}
	else
		cout<<"no hay nombres que mostrar";
}

int main()
{
	int op;
	cout<<"1. Insertar\n";
	cout<<"2. Eliminar\n";
	cout<<"3. Mostrar\n";
	cout<<"4. Salir\n";
		
	do{
		cout<<"\n>>";
		cin>>op;
		switch(op){
			case 1: insertarNombre(); break;
			case 2:	
				printf("se ha eliminado el elemento %i",eliminarNombre());	
				break;
			case 3: 
			{
				imprimirNombres(lista); 
				break;
			}
			case 4:
				cout<<"Adiooos\n";
				break;
			default: cout<<"opcion no valida\n"; break;
		}
	}while(op!=4);
	return 0;
}
