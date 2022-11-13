- Leon Gallardo Ian Yael
- Gerardo Daniel García Cerda


#include<iostream>
#include<stdlib.h>

using namespace std;

struct alumno
{
	char nombre[30];
	int numeroCuenta;
	int edadAlumno;
	alumno *sig;
	alumno *ant;
};

alumno *lista;

void ingresarAlumno();
void eliminarAlumno();
void mostrarAlumnos();
void mostrarAlumnoXAlumno();
void vacia();
void vaciarLista();
void buscarAlumno();

int main()
{
	int op;
	
	cout<<"\nMENU:\n";
	cout<<"1. Ingresar alumno\n";
	cout<<"2. Eliminar alumno\n";
	cout<<"3. Mostrar lista de alumnos\n";
	cout<<"4. Mostrar alumnos x alumno\n";
	cout<<"5. Ver si la lista esta vacia\n";
	cout<<"6. Borrar lista\n";
	cout<<"7. Buscar alumno\n";
	cout<<"8. Terminar y salir\n";
	
	do
	{
		cout<<"\n>>";
		cin>>op;
		
		switch(op)
		{
			case 1: ingresarAlumno(); break;
			case 2: eliminarAlumno(); break;
			case 3: mostrarAlumnos(); break;
			case 4: mostrarAlumnoXAlumno(); break;
			case 5: vacia(); break;
			case 6: vaciarLista(); break;
			case 7: buscarAlumno(); break;
			case 8: cout<<"Adios\n"; break;
			default: cout<<"Opcion no valida\n"; break;
		}		
		
	}while(op!=8);
	return 0;
}

void vacia()
{
	if(lista==NULL)
	{
		cout<<"La lista esta vacia\n";
	}
	else
		cout<<"Negativo, ya hay datos en la lista\n";
}

void vaciarLista()
{
	lista=NULL;
	free(lista);
}

void buscarAlumno()
{
	alumno *actual=new alumno();
	actual=lista;
	
	int nodoBuscado;
	int B=0;
	
	cout<<("Ingresa el numero de cuenta: ");
	cin>>nodoBuscado;
	
	if(lista!=NULL)
	{
		while(actual!=NULL && B==0)
		{
			if(actual->numeroCuenta==nodoBuscado)
			{
				cout<<"Nombre: "<<actual->nombre<<" | Numero de cuenta: "<<nodoBuscado<<" | Edad: "<<actual->edadAlumno<<"\n";
				B=1;
			}		
			actual=actual->sig;
		}
		if(B==0)
		{
			cout<<"Dato no encontrado\n";
		}
	}
	else
	{
		cout<<"La lista esta vacia, no hay datos para buscar\n";
	}
	free(actual);
}

void mostrarAlumnos()
{
	alumno *indice=new alumno();
	indice=lista;
	while(indice!=NULL)
	{
		cout<<"Nombre: "<<indice->nombre<<" | Numero de cuenta: "<<indice->numeroCuenta<<" | Edad: "<<indice->edadAlumno;
		indice=indice->sig;
		cout<<" \n";
	}
	free(indice);
}

void mostrarAlumnoXAlumno()
{
	int op,x=0,y;
	
	alumno *actual=new alumno();
	actual=lista;
	alumno *anterior=new alumno();
	anterior=actual;
	anterior->ant=actual;
	
	while(actual!=NULL)
	{
		if(x==0)
		{
			cout<<"\tNombre: "<<actual->nombre<<" | Numero de cuenta: "<<actual->numeroCuenta<<" | Edad: "<<actual->edadAlumno<<"\n";	
		}
		
		else
		{
			cout<<"\t1. Mostrar al siguiente alumno  |  ";				
			cout<<"\t2. Mostrar al anterior alumno  |  ";
			cout<<"\t3. salir";
			cout<<"\t\n-> ";
			cin>>op;
			if(op==1)
			{
				cout<<"\tNombre: "<<actual->nombre<<" | Numero de cuenta: "<<actual->numeroCuenta<<" | Edad: "<<actual->edadAlumno<<"\n";
			}
			else if(op==2)
			{
				cout<<"\tNombre: "<<anterior->nombre<<" | Numero de cuenta: "<<anterior->numeroCuenta<<" | Edad: "<<anterior->edadAlumno<<"\n";
			}
			else if(op==3)
				break;
		}
		x++;
		actual=actual->sig;
		
	}
}

void eliminarAlumno()
{
	alumno *actual=new alumno();
	actual=lista;
	alumno *anterior=new alumno();
	anterior=NULL;
	
	int nodoBuscado;
	int B=0;
	
	cout<<("Ingresa el numero de cuenta: ");
	cin>>nodoBuscado;
	
	do{
		if(actual->numeroCuenta==nodoBuscado)
		{
			if(actual==lista)
			{
				lista=lista->sig;
			}
			else
			{
				anterior->sig=actual->sig;
			}
			B=1;
		}	
		anterior=actual;
		actual=actual->sig;	
	} while(actual!=NULL&&B==0);

	if(B==1)
	free(anterior);
}

void ingresarAlumno()
{
	alumno *nuevo=new alumno();
	nuevo->sig=lista;
	cout<<"Ingrese el nombre del alumno: ";
	cin>>nuevo->nombre;
	cout<<"Ingrese el numero de cuenta del alumno: ";
	cin>>nuevo->numeroCuenta;
	cout<<"Ingrese la edad del alumno: ";
	cin>>nuevo->edadAlumno;
	lista=nuevo;
}
