#include <iostream>

using namespace std;

int main (){
	
    int consola=1;
    int placa;
    int vehiculo;
    int lugar = 0;


while(consola != 0){
	 cout<<"Bienvenido a Super Walmart"<<endl;
	 cout<<"Ingrese numero de placa de su vehiculo\n";
	 cin>>placa;
	 cout<<"1- Continuar"<<endl<<"0- Cancelar"<<endl;
	 cin>>consola;
	 	if (consola == 1){
        	cout<<"Seleccione su tipo de vehiculo\n";
         	cout<<"1- Automovil"<<endl<<"2- Motocicleta / Bicicleta"<<endl<<"0- Cancelar\n";
         	cin>>vehiculo;
			         
	        if (vehiculo == 1){
	        	cout<<"Seleccione su lugar de estacionamiento\nMostrando mapa de estacionamiento"<<endl;
	        	cout<<"Lugares disponibles se denotan con letra D"<<endl<<"Lugares reservados se denotan con letra R"<<endl;
	        	cin>>lugar;
	        }
	        if (vehiculo == 2){
	        	cout<<"Seleccione su lugar de estacionamiento\nMostrando mapa de estacionamiento"<<endl;
	        	cout<<"Lugares disponibles se denotan con letra D"<<endl<<"Lugares reservados se denotan con letra R"<<endl;
	        	cin>>lugar;
			}
			return 0;		
		 }
	}
	cout<<"La operacion ha sido cancelada"<<endl;
}
