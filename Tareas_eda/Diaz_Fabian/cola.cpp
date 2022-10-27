/*
    Queue - Cola en C++

    Curso Prebecarios Estructura de Datos | PROTECO UNAM

    Elaborado: Fabian Josafat Diaz Silleros

*/

// Librerias

#include <iostream>
#include <stdlib.h>

using namespace std;

// Estructura, Definition of the Queue

struct Nodo{
    int data;
    Nodo *next;
};

// Nodos totales
int nNodos = -1;

// Prototypes
void menu();
void enqueue(Nodo *&, Nodo *&, int);
void dequeue(Nodo *&, Nodo *&, int &);
bool isEmpty();
void display(Nodo *&, Nodo *&);

// Main Function 

int main(){
    
    // Inicializamos el frente y el final en nulos
    Nodo *front = NULL;
    Nodo *back = NULL;

	bool cont = true; // Variable para el ciclo while
	
	int d = 0; // Variable para leer el dato a ingresar
	
    while(cont == true){

        int opc = 0; // Variable para elegir opcion y dato a ingresar
        menu(); // Imprimimos el menu
        cout<<"Choice an option: ";
        cin>>opc; // Leemos la opcion

        switch (opc) // switch case de la opcion
        {
        case 1: // opcion agregar nodo
            cout<<"\n\nEnter an int data: ";
            cin>>d; // leemos el dato del nodo
            enqueue(front, back, d); // llamamos funcion enqueue
            break;
        
		case 2: // opcion eliminar nodo
			dequeue(front, back, d); // llamamos funcion dequeue
			cout<<"\nNodo has been deleted.\n"<<endl;
        	break;
        	
        case 3: // opcion para saber si esta vacia la cola
            if(isEmpty()){ // llamamos funcion esta vacia
                cout<<"\nThe queue is empty\n"<<endl;
            }
            else{
                cout<<"\nThe queue is not empty\n"<<endl;
            }
            break;
		
		case 4: // opcion para imprimir la cola
			display(front, back);
			break;
			
		case 5: // opcion para salir
			cont = false; // rompe el ciclo while
			break;
        default: // en caso de ingresar algo diferente
            cout<<"\nChoice a valid option.\n"<<endl;
            break;
        }

    }

	cout<<"\n\nbye bye";
    return 0;
}


// Insert Nodo Function
void enqueue(Nodo *&front,Nodo *&back, int n){

    // Declaramos un nuevo nodo
    Nodo *new_nodo = new Nodo();
    // Asignamos el dato y ponemos en NULL el siguiente
    new_nodo->data = n;
    new_nodo->next = NULL;

    // Comprobamos si la cola esta vacia
    if(isEmpty()){
        front = new_nodo; // volvemos el frente al nodo creado
    }
    else{
        back->next = new_nodo; // referenciamos al nuevo nodo en el nodo anterior
    }

    back = new_nodo; // volvemos el final al nuevo nodo

    cout<<"\nElement added successfully\n"<<endl;
    
    // Sumamos uno al numero de nodos
    nNodos += 1;

}

// Delete first Nodo Function
void dequeue(Nodo *&front, Nodo *&back, int &n){
	
	// Asignamos el dato del frente a n
	n = front->data;
	
	// Creamos un nodo auxiliar
	Nodo *aux = front;
	
	if(front == back){ // Si solo hay un nodo
		
		// Igualamos el frente y el fin a null
		front = NULL;
		back = NULL;
		
	}
	else{
		// frente ahora es el nodo al que apuntaba frente
		front = front->next;
		
	}
	
	// Restamos uno a los nodos existentes
	nNodos -= 1;
	
	// Eliminamos el nodo auxiliar
	delete aux;
	
}

// isEmpty Function
bool isEmpty(){

    if(nNodos == -1){
        return true; // Si esta vacia (numeroNodos es igual a -1)
    }
    else{
        return false; // Existen nodos (numeroNodos mayor o igual a 0)
    }

}

// Display Queue
void display(Nodo *&front, Nodo *&back){
	
	if(isEmpty()){
        cout<<"\nThere's not a single Nodo, try again after adding a nodo\n"<<endl;
    }
    else{
        
        // Asignamos a un nodo auxiliar el frente
        Nodo *aux = front;
        
        cout<<"\n\n";
    	
    	// For que va a iterar cuantos nodos existan
        for(int i=0; i <= nNodos; i++){
        	
        	// Imprime el valor del dato
        	cout<<" "<<aux->data;
			// Asigna a auxiliar el nodo siguiente
			aux = aux->next;
        	
        }
        
        cout<<"\n"<<endl;
        
    }
	
}

// Menu
void menu(){

    cout<<"\n1. Enqueue"<<endl;
    cout<<"2. Dequeue"<<endl;
    cout<<"3. Is the Queue Empty?"<<endl;
    cout<<"4. Display all the elements"<<endl;
    cout<<"5. Exit"<<endl;

}
