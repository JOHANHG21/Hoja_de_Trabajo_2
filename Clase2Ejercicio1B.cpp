#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include<ctime> 
#include <stdio.h>
#include <vector>
using namespace std;

struct Existencias{
  string id;
  int minimo;
  int actual;
  string proveedor;
  float precio;
};

// Hacemos el vector
std::vector<Existencias> producto;

void agregar_stock(){
  Existencias x;
  cout << "Ingrese ID del stock"<< "\n";
  cin >> x.id;
  cout << "Ingrese el minimo del stock"<< "\n";
  cin >> x.minimo;
  cout << "Ingrese cantidad actual del stock"<< "\n";
  cin >> x.actual;
  cout << "Ingrese el proveedor del stock"<< "\n";
  cin >> x.proveedor;
  cout << "Ingrese precio del stock"<< "\n";
  cin >> x.precio;

    // grabamos producto en el archivo.
    ofstream miarchivo("PRODUCTOS.txt", std::ios_base::app);
    miarchivo << x.id << "\t" << x.minimo << "\t" << x.actual << "\t" << x.proveedor << "\t" << x.precio << endl;
    //Cerramos la escritura del archivo.
    miarchivo.close();
}

void mostrar_datos(){
  
cout << "El producto siguiente necesita reabastecimiento" << endl;
cout << "---------------------------------------------" << endl;
cout << "CODIGO"<< "\t" << "MINIMO" << "\t" << "EXISTENCIA" << "\t" << "PROVEEDOR" << "\t" << "PRECIO" << endl;
cout << "---------------------------------------------" << endl; 

 for (int i=0; i< producto.size(); i++){
   if (producto[i].minimo>=producto[i].actual){
      cout << producto[i].id << "\t" << producto[i] .minimo << "\t" << producto[i].actual << "\t" <<   producto[i].proveedor << "\t" << producto[i].precio <<  "\t" << endl;
   }
 }
   string empty;
    cin >> empty;
    return;
}

void leer_archivo(){
    //declaramos la variable para leer archivo
    ifstream miarchivo;

    //Limpiamos el vector
    producto.clear();
    
    // creamos la variable con la estructura
    Existencias prod;

    //abrimos archivo 
    miarchivo.open("PRODUCTOS.txt",ios::in);
    
   //Obtenemos las columnas del archivo por linea
    while(miarchivo >> prod.id >> prod.minimo >> prod.actual >> prod.proveedor >> prod.precio)
    {
        // Grabamos en memoria, con vectores
        producto.push_back(prod);
    }

    //Cerramos el archivo
    miarchivo.close();
    mostrar_datos();
    return;
}

int main() {
  char tecla;
  string empty;
  bool bandera=false;
  
  do
    {
        system("clear");
        cin.clear();
        cout << "MENÚ DE PRODUCTOS" << endl;
        cout << "-----------" << endl << endl;
        cout << "\t1 .- Agregar Nuevo Producto" <<endl;
        cout << "\t2 .- Leer archivo y mostrar menor stock" <<endl;
        cout << "\t3 .- Salir" << endl << endl;
        cout << "Elije una opcion: ";
 
        cin >> tecla;
 
		switch(tecla)
    		{
			case '1':
				system("clear");
        agregar_stock();
        break;
 
			case '2':
        system("clear");
        leer_archivo();
        break;
      
      case '3':
				bandera=true;
				//exit(1);
				break;
 
			default:
				system("clear");
				cout << "Opcion no valida.\a\n";
				getchar();
        getline(cin, empty);
				break;
		}
    }while(bandera!=true);
  
  return 0;
}
