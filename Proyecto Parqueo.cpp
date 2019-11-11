#include <iostream>
#include <ctime>

using namespace std;

int vehiculo;
int espacio;

int lugarauto(){
	cout<<"Seleccione su lugar de estacionamiento\nMostrando mapa de estacionamiento"<<endl;
    cout<<"Lugares disponibles se denotan con letra D"<<endl<<"Lugares ocupados se denotan con letra R"<<endl;
    cin>>espacio;
	return 0;
} 

int lugarbicimoto(){
	cout<<"Seleccione su lugar de estacionamiento\nMostrando mapa de estacionamiento"<<endl;
    cout<<"Lugares disponibles se denotan con letra D"<<endl<<"Lugares ocupados se denotan con letra R"<<endl;
    cin>>espacio;
	return 0;
}

int automovil(){
	int placa;
    cout<<"Ingrese numero de placa de su vehiculo:"<<endl;
	cin>>placa;
	lugarauto();
	return 0;
}

int bicimoto(){
    int placa;
    cout<<"Ingrese numero de placa de su motocicleta o bicicleta:"<<endl;
	cin>>placa;
	lugarbicimoto();
	return 0; 
}


int main (){
	int programa=0;
	int proceso;
	while(programa!=3){
		time_t now = time(0);
		tm* time = localtime(&now);
		cout<<"Bienvenido"<<endl;
		cout<<"Son las "<<time->tm_hour<<":"<<time->tm_min<<endl;
		cout<<"1- Proceso de entrada al parqueo"<<endl;
		cout<<"2- Proceso de salida del parqueo"<<endl;
		cin>>proceso;
		if(proceso==1){	
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
		else{
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
		    }
		}	
	}
	return 0;
}



