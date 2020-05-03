#include <iostream>
#include <string>
#include <sstream>
using namespace std;
struct colegio{
  int id;
  string nombre;
  float nota;
};
int main() {
  int i,n=0;  
  float sumatotal=0,media,nota_mayor;
  string estudiante =" ";
  ostringstream ssal;  //ostringstream
  ostringstream ssmsv;
  ostringstream ssmt;
  cout<<"¿Cuantos estudiantes almacenara? ";
  cin>>n;
  
  colegio establecimiento[n];
  /*Ingreso de Datos*/
  	for(i=0;i<n;i++){
    	cout<<"Ingrese id del estudiante: "<<endl;
    	cin>>establecimiento[i].id;
    	cout<<"Ingrese Nombre del estudiante: "<<endl;
    	cin>>establecimiento[i].nombre;
    	cout<<"Ingrese la nota del estudiante: "<<endl;
    	cin>>establecimiento[i].nota;
    	sumatotal=sumatotal+establecimiento[i].nota;
    	system("CLS");
  	}
  	
  	/*Calculo de Media General*/
  	media= sumatotal/n; //float(n);
  	nota_mayor=media;

	/*Deshabilitado*/
  	/*Determinar el id de almacen mas alto*/
  	/*for(i=0;i<n;i++){
    	if(ventas[i].almacenid>mayor)
    	  mayor=ventas[i].almacenid;
  	} */ 
	/*Determinar Ventas Mayores*/
  	for(i=0;i<n;i++){
  		//Doble validación para que no se duplique en la cadena final
  		if(establecimiento[i].nota>media){
		  if(establecimiento[i].nota>nota_mayor){
		  	/*Convertir Int to String*/
	  		ssal << establecimiento[i].id;
	  		ssmsv << establecimiento[i].nombre;
	  		ssmt << establecimiento[i].nota;
	  		/*Concatenar valores*/
	  		estudiante=estudiante+"ID Estudiante: "+ssal.str()+"-Nombre: "+ ssmsv.str()+"-Nota:"+ssmt.str()+" / ";
	  		/*Limpiar stream ostringstream*/
	  		ssmsv.str("");
	  		ssmt.str("");
	  		ssal.str("");
	  		ssmsv.clear();
  			ssmt.clear();
  			ssal.clear();
			nota_mayor=establecimiento[i].nota;
		  }			  			
  		}
	}
	//Imprisión en pantalla final
	cout<<"Media: "<<media<<endl;
	cout<<"Nota Mayor: "<<estudiante.substr(0,estudiante.length()-2)<<endl;
	
}
