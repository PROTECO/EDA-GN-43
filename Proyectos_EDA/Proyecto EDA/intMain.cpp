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
			case 1: break;
			case 2: break;
			case 3: break;
			case 4: break;
			case 5: vacia(); break;
			case 6: vaciarLista(); break;
			case 7: break;
			case 8: cout<<"Adios\n"; break;
			default: cout<<"Opcion no valida\n"; break;
		}		
		
	}while(op!=8);
	return 0;
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

void eliminarAlumno()
{
	
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
	
}
