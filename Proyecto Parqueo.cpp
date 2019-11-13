#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <fstream>

using namespace std;

int vehiculo;
int espacio;
int matrizespacio[3][5]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}};

int bicimotosalida(){
	
}

int automovilsalida(){
	
}

int pago(){ //Funci�n para c�lcular el pago del usuario por el uso del parqueo.
	/*Esta casilla ser� para c�lcular los pagos que los usuarios del parqueo deber�n
	cancelar al hacer uso de 0 a 15 minutos (Gratis), de 16 a30 minutos ($0.25),
	de 31 minutos a 1 hora ($0.50) y de 1 hora 1 minuto en adelante ($1 cada hora)
	sebas te toca hacer el c�lculo.*/
}

int lugarauto(){
    int filas = (sizeof(matrizespacio)/sizeof(matrizespacio[0]));
    int columnas = (sizeof(matrizespacio[0])/sizeof(matrizespacio[0][0]));
	cout<<"Seleccione su lugar de estacionamiento\nMostrando mapa de estacionamiento"<<endl;
    cout<<"Lugares disponibles se denotan con letra D"<<endl<<"Lugares ocupados se denotan con letra R"<<endl;
    cout<<"matrizespacio"<<endl;
    for (int i= 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
             cout<<matrizespacio[i][j]<<" ";
        }
        cout << endl;
    }
    cin>>espacio;
	return 0;
} 

int lugarbicimoto(){
    int filas = (sizeof(matrizespacio)/sizeof(matrizespacio[0]));
    int columnas = (sizeof(matrizespacio[0])/sizeof(matrizespacio[0][0]));
	cout<<"Seleccione su lugar de estacionamiento\nMostrando mapa de estacionamiento"<<endl;
    cout<<"Lugares disponibles se denotan con letra D"<<endl<<"Lugares ocupados se denotan con letra R"<<endl;
    cout<<"matrizespacio"<<endl;
    for (int i= 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            cout<<matrizespacio[i][j]<<" ";
        }
        cout << endl;
    }
    cin>>espacio;
	return 0;
}

int automovil(){ //Funci�n que se encarga de pedir la placa del auto o cami�n.
	int placa;
    cout<<"Ingrese numero de placa de su vehiculo:"<<endl;
	cin>>placa;
	lugarauto();
	return 0;
}

int bicimoto(){ //Funci�n que se encarga de pedir la placa de la motocicleta o bicicleta.
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
		time_t now = time(0); //variables para capturar la hora real del sistema.
		tm* time = localtime(&now);
		cout<<"Bienvenido"<<endl;
		cout<<"Son las "<<time->tm_hour<<":"<<time->tm_min<<endl; //Se muestra la hora y minutos acorde al sistema.
		cout<<"1- Proceso de entrada al parqueo"<<endl;
		cout<<"2- Proceso de salida del parqueo"<<endl;
		cin>>proceso;
		
		if(proceso==1){	//Proceso que comenzar� si el usuario selecciona el uso del men� de entrada del parqueo.
			cout<<"Seleccione su tipo de vehiculo por favor:"<<endl; 
			cout<<"1- Automovil o Camion"<<endl<<"2- Motocicleta / Bicicleta"<<endl<<"3- Cancelar\n";
		    cin>>vehiculo;
		    switch(vehiculo){ //Switch para definir la acci�n a hacer seg�n sea el caso.
		    	case 1:
		    		automovil(); //Llama a la funci�n de los autos o camiones.
		    		break;
		    	case 2:
		    		bicimoto(); //Llama a la funci�n de las motocicletas o bicicletas.
		    		break;
		    	case 3: //Operaci�n que har� que el usuario retorne al men� principal si este cometi� un error en su desici�n
		    		cout<<"Operacion cancelada"<<endl;
		    		cout<<"REINICIANDO"<<endl;
					cout<<endl;
					cout<<endl;
		    		break;
		    }
		}
		
		else{ //Proceso que comenzar� si el usuario selecciona el uso del men� de salida del parqueo.
			cout<<"Seleccione su tipo de vehiculo por favor:"<<endl; 
			cout<<"1- Automovil o Camion"<<endl<<"2- Motocicleta / Bicicleta"<<endl<<"3- Cancelar\n";
		    cin>>vehiculo;
		    switch(vehiculo){
		    	case 1:
		    		automovilsalida(); //Llama a la funci�n de los autos o camiones.
		    		break;
		    	case 2:
		    		bicimotosalida(); //Llama a la funci�n de las motocicletas o bicicletas.
		    		break;
		    	case 3: //Operaci�n que har� que el usuario retorne al men� principal si este cometi� un error en su desici�n
		    		cout<<"Operacion cancelada"<<endl;
		    		cout<<"REINICIANDO"<<endl;
					cout<<endl;
					cout<<endl;
		    		break;
		    }
		}	
	}
	return 0;
}



