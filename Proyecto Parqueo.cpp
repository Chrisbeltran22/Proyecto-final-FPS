#include <iostream>
#include <ctime>

using namespace std;

int vehiculo;
int espacio;

int automovil(){
	int placa;
    cout<<"Ingrese numero de placa de su vehiculo:"<<endl;
	cin>>placa;
	
	return 0;
}

int bicimoto(){
    int placa;
    cout<<"Ingrese numero de placa de su motocicleta o bicicleta:"<<endl;
	cin>>placa;
	return 0; 
}

int lugar(int automovil){
	cout<<"Seleccione su lugar de estacionamiento\nMostrando mapa de estacionamiento"<<endl;
    cout<<"Lugares disponibles se denotan con letra D"<<endl<<"Lugares ocupados se denotan con letra R"<<endl;
    cin>>espacio;
	return 0;
}

int main (){
	int programa=0;
	while(programa!=3){
		time_t now = time(0);
		tm* time = localtime(&now);
		cout<<"Bienvenido"<<endl;
		cout<<"Son las "<<time->tm_hour<<":"<<time->tm_min<<endl;	
		cout<<"Seleccione su tipo de vehiculo por favor:"<<endl; 
		cout<<"1- Automovil o Camion"<<endl<<"2- Motocicleta / Bicicleta"<<endl<<"3- Cancelar\n";
	    cin>>vehiculo;
	    switch(vehiculo){
	    	case 1:
	    		automovil();
	    		break;
	    	case 2:
	    		bicimoto();
	    		break;
	    	case 3:
	    		cout<<"Operacion cancelada"<<endl;
	    		cout<<"REINICIANDO"<<endl;
				cout<<endl;
				cout<<endl;
	    		break;
	    }
	}
	return 0;
}



