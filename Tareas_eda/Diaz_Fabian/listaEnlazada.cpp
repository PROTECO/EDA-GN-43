/*
	Lista Simplemente Enlazada en C++

	Curso Prebecarios Estructura de Datos | PROTECO
	
	Elaboro: Fabian Josafat Diaz Silleros

*/

// Librerias
#include <iostream>
#include <cstdlib>

using namespace std;

// Declaracion Nodo de la lista

struct Nodo {
	
	int data;
	Nodo *next;
	
};

// Clase lista

class List{
	
	public:
		
		Nodo *_first; // Primer Nodo
		
		List(); // Constructor
		~List(); // Destructor
		void addNodo(int); // Agregar un Nodo
		void deleteNodo(int); // Borrar un nodo
		bool isEmpty(); // Comprobar si esta vacia
		void searchNodo(int); // Buscar un nodo
		void displayList(); // Imprimir elementos de la lista
	
};

// Constructor

List::List(){
	
	_first = NULL;
	
}

// Destructor

List::~List(){
	
	Nodo *actual = _first; // Asignamos a actual el primer nodo
	
	while(actual != NULL){ // Ciclo while hasta que sea Nulo el nodo
		
		Nodo *aux = actual->next; // Se almacena en auxiliar el nodo siguiente del actual
		
		delete actual; // Se borra el nodo actual
		
		actual = aux; // Ahora actual es el nodo auxiliar (para hacer lo mismo en la sig iteracion)
		
	}
	
}

// Agregar un Nodo a la lista

void List::addNodo(int d){
	
	Nodo *new_nodo = new Nodo(); // Creamos un nuevo nodo
	
	new_nodo->data = d; // Asignamos el valor del nodo
	
	new_nodo->next = NULL; // Hacemos que apunte a Null
	
	if( this->isEmpty() ){ // Si el primer nodo de la lista es nulo
		
		_first = new_nodo; // Hacemos el nuevo nodo el primero de la lista
		
	}
	else{ // Si existe al menos un nodo en la lista
		
		Nodo *actual = _first; // Creamos nodo actual y le asignamos el primer nodo
		
		while(actual->next != NULL){ // Mientras el nodo actual no apunte a null
			
			actual = actual->next; // Asignamos a actual el nodo siguiente
			
		}
		
		// Una vez llegamos al ultimo nodo
		
		actual->next = new_nodo; // Referenciamos al nuevo nodo en el nodo que antes era el ultimo
		
	}
	
}

// Borrar un nodo elegido

void List::deleteNodo(int d){
	
	if(this->isEmpty()){ // Si la lista esta vacia
		
		cout<<"\n\nThere's not Nodos to delete\n"<<endl;
		
	}
	else{ // Si la lista tiene nodos
		
		Nodo *anterior = _first; // asignamos a nodo anterior el primer nodo
		
		
		
		if(anterior->data == d){ // En caso de que el primer valor sea el que deseamos eliminar
				
			if(anterior->next == NULL){ // Si solo hay un nodo
				
				_first = NULL; // Borramos el unico nodo
				return; // Retornamos
				
			}
			else{ // Si hay mas de un nodo
				
				_first = anterior->next; // Volvemos el primer nodo al nodo siguiente
				
				return; // Retornamos
				
			}
			
		}
		
		// En caso de ser mas de un nodo y el primer no ser el nodo a eliminar
		
		Nodo *actual = anterior->next; // nodo actual al siguiente del primero
		
		bool seg = true; // variable de seguir
		
		while(true){ // while infinito
			
			if(actual->data == d && actual->next != NULL){ // si el dato del nodo actual es igual al numero dado y next diferente a null
				
				anterior->next = actual->next; // asignamos la direccion del siguiente nodo al nodo anterior
				actual = NULL; // asignamos null
				
				return; // retornamos
				
			}
			
			if(actual->data == d && actual->next == NULL){ // si el dato del nodo actual es igual al numero dado y next igual a null
				
				anterior->next = NULL; // asignamos a next del nodo anterior nulo
				actual = NULL; // asignamos null
				
				return; // retornamos
				
			}
			
			anterior = actual; // le asignamos a anterior el nodo actual
			actual = actual->next; // Asignamos a actual el nodo siguiente
			
			// Una vez asignado el nuevo nodo
			if(actual->next == NULL){ // si siguiente apunta a null (o sea que es el ultimo nodo)
				
				if (seg == true){ // Para llegar al ultimo nodo
					
					seg = false; // ponemos seguir en falso
					continue; // forzamos la siguiente iteracion (ultimo nodo)
					
				}
				
				if (seg == false){ // ya que se paso el ultimo nodo
					
					break; // cortamos el while
					
				}
				
			}
			
		}
 		
		// Si llega aqui es porque no hubo coincidencias
		cout<<"\n\nNo match found\n"<<endl;
		
	}
	
}

// Metodo para saber si esta vacia la lista

bool List::isEmpty(){
	
	if(_first == NULL){ // Si el primer nodo es nulo
		
		return true; // Retornamos verdadero (Lista vacia)
		
	}
	else{ // Si el primer nodo tiene contenido
		
		return false; // Retornamos falso (Lista con al menos un nodo)
		
	}
	
}

// Metodo para encontrar un elemento

void List::searchNodo(int d){
	
	if(this->isEmpty()){ // Si la lista esta vacia
		
		cout<<"\n\nThere's not Nodos\n"<<endl;
		
	}
	else{ // Si la lista tiene nodos
		
		Nodo *actual = _first; // Creamos nodo actual y le asignamos el primer nodo
		
		while(true){ // while infinito
			
			if(actual->next != NULL){ // Si existe un siguiente nodo
				
				if(actual->data == d){ // si es el numero
					
					cout<<"\n\n  Element "<<actual->data<<" exist.\n"<<endl; // imprimimos que existe
					return; // retornamos
					
				}
				
			}
			else{ // Si ya se es el ultimo nodo
				
				if(actual->data == d){ // si es el numero
					
					cout<<"\n\n  Element "<<actual->data<<" exist.\n"<<endl; // imprimimos que existe
					return; // retornamos
					
				}
				else{ // si el ultimo nodo tampoco es el numero
					
					cout<<"\n\nNo match found\n"<<endl;
					return; // retornamos
					
				}
				
			}
			
			actual = actual->next; // pasamos al siguiente nodo	
				
		}
			
	}
		
}
	

void List::displayList(){
	
	if(this->isEmpty()){ // Si es nulo
		
		cout<<"\n\nEmpty List\n"<<endl;
		return; // Retornamos
		
	}
	else{ // Si hay uno o mas nodo
		
		Nodo *actual = _first; // Creamos nodo actual y le asignamos el primer nodo
		
		cout<<"\n\n";
		
		while(true){
			
			if(actual->next != NULL){ // Si existe un siguiente nodo
				
				cout<<"  "<<actual->data; // imprimimos
				
			}
			else{ // Si ya se es el ultimo nodo
				
				cout<<"  "<<actual->data<<"\n"<<endl;  // imprimimos
				return; // retornamos
				
			}
			
			actual = actual->next; // pasamos al siguiente nodo
			
		}
		
	}
	
}

// Prototipos
void menu();

// Funcion Main

int main(){
	
	List lista; // Creamos un objeto de List
	
	bool cont = true; // Variable para continuar while
	int d = 0; // Variable para leer el dato a ingresar
	
	while (cont){ // Mientras continuar sea veradero
		
		int opt = 0; // variable de opcion	
		menu(); // Imprimimos menu
		
		cout<<"\nChoice an option: ";
		cin>>opt; // Leemos una opcion
		
		switch(opt){ // Switch case de la opcion
			
			case 1: // case de insertar elemento
				cout<<"\n\nEnter an int data: ";
            	cin>>d; // leemos el dato del nodo
            	lista.addNodo(d);
            	 cout<<"\nElement added successfully\n"<<endl;
				break;
			
			case 2: // case de eliminar elemento
				cout<<"\n\nEnter the element to delete: ";
				cin>>d; // leemos el dato a eleminar
				lista.deleteNodo(d);
				break;
				
			case 3: // Case de comprobar si esta vacia la lista
				if(lista.isEmpty()){ // llamamos metodo esta vacia
                	cout<<"\nThe list is empty\n"<<endl;
            	}
            	else{
                	cout<<"\nThe list is not empty\n"<<endl;
            	}
				break;
				
			case 4: // Case de buscar un elemento
				cout<<"\n\nEnter the element to search: ";
				cin>>d; // leemos el dato a buscar
				lista.searchNodo(d);				
				break;
				
			case 5: // Case de imprimir los elementos
				lista.displayList();
				break;
				
			case 6: // Case de salir
				cont = false; // rompe el ciclo while
				break;
				
			default: // Si se ingresa cualquier otra cosa
				cout<<"\nChoice a valid option.\n"<<endl;
				break;
			
		}
		
	}
	
	//lista.~List(); // liberamos la memoria
	
	cout<<"\n\b bye bye"<<endl;
	
	return 0;
}

// Menu
void menu(){

    cout<<"\n1. Insert Element"<<endl;
    cout<<"2. Delete Element"<<endl;
    cout<<"3. Is the List Empty?"<<endl;
    cout<<"4. Search an Element"<<endl;
    cout<<"5. Display all the elements"<<endl;
    cout<<"6. Exit"<<endl;

}
