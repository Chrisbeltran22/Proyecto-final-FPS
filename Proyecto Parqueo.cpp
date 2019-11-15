#include <iostream>
#include <iomanip>
#include <ctime>
#include <stdlib.h>
#include <fstream>

using namespace std;

int vehiculo;
int placa;
int espacio;
int matrizautos[2][5]={{1,2,3,4,5},{6,7,8,9,10}};
int matrizbicimoto[2][5]={{11,12,13,14,15},{16,17,18,19,20}};

int bicimotosalida(){
	
}

int automovilsalida(){
	
}

int pago(){ //Función para cálcular el pago del usuario por el uso del parqueo.
	/*Esta casilla será para cálcular los pagos que los usuarios del parqueo deberán
	cancelar al hacer uso de 0 a 15 minutos (Gratis), de 16 a30 minutos ($0.25),
	de 31 minutos a 1 hora ($0.50) y de 1 hora 1 minuto en adelante ($1 cada hora)
	sebas te toca hacer el cálculo.*/
}

void escribir1(){
	ofstream archivo;
	archivo.open("Historial de uso parqueo de autos y camiones.txt", ios::app); //Se crea y abre el archivo si este no existe ya.
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	cin>>placa;
	cin>>espacio;
	archivo<<placa;
	cout<<endl;
	archivo<<espacio;
	cout<<endl;
	archivo.close();
}

int automovil(){ //Función que se encarga de pedir la placa del auto o camión y lugar de parqueo.
	int placa;
	int filas = (sizeof(matrizautos)/sizeof(matrizautos[0]));
    int columnas = (sizeof(matrizautos[0])/sizeof(matrizautos[0][0]));
    cout<<"Ingrese numero de placa de su vehiculo y seleccion lugar de parqueo:"<<endl;
    for (int i= 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            cout<<setw(3)<<matrizautos[i][j]<<" ";
        }
        cout << endl;
    }
    escribir1();
	return 0;
}

void escribir2(){
	ofstream archivo;
	archivo.open("Historial de uso parqueo de motos y bicis.txt", ios::app); //Se crea y abre el archivo si este no existe ya.
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	cin>>placa;
	cin>>espacio;
	archivo<<placa;
	cout<<endl;
	archivo<<espacio;
	cout<<endl;
	archivo.close();
}

int bicimoto(){ //Función que se encarga de pedir la placa de la motocicleta o bicicleta y lugar de parqueo.
	int placa;
    int filas = (sizeof(matrizbicimoto)/sizeof(matrizbicimoto[0]));
    int columnas = (sizeof(matrizbicimoto[0])/sizeof(matrizbicimoto[0][0]));
    cout<<"Ingrese numero de placa de su motocicleta o bicicleta y seleccione lugar de parqueo:"<<endl;
    for (int i= 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            cout<<setw(3)<<matrizbicimoto[i][j]<<" ";
        }
        cout << endl;
    }
	escribir2();
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
		
		if(proceso==1){	//Proceso que comenzará si el usuario selecciona el uso del menú de entrada del parqueo.
			cout<<"Seleccione su tipo de vehiculo por favor:"<<endl; 
			cout<<"1- Automovil o Camion"<<endl<<"2- Motocicleta / Bicicleta"<<endl<<"3- Cancelar\n";
		    cin>>vehiculo;
		    switch(vehiculo){ //Switch para definir la acción a hacer según sea el caso.
		    	case 1:
		    		automovil(); //Llama a la función de los autos o camiones.
		    		break;
		    	case 2:
		    		bicimoto(); //Llama a la función de las motocicletas o bicicletas.
		    		break;
		    	case 3: //Operación que hará que el usuario retorne al menú principal si este cometió un error en su desición
		    		cout<<"Operacion cancelada"<<endl;
		    		cout<<"REINICIANDO"<<endl;
					cout<<endl;
					cout<<endl;
		    		break;
		    }
		}
		
		else{ //Proceso que comenzará si el usuario selecciona el uso del menú de salida del parqueo.
			cout<<"Seleccione su tipo de vehiculo por favor:"<<endl; 
			cout<<"1- Automovil o Camion"<<endl<<"2- Motocicleta / Bicicleta"<<endl<<"3- Cancelar\n";
		    cin>>vehiculo;
		    switch(vehiculo){
		    	case 1:
		    		automovilsalida(); //Llama a la función de los autos o camiones.
		    		break;
		    	case 2:
		    		bicimotosalida(); //Llama a la función de las motocicletas o bicicletas.
		    		break;
		    	case 3: //Operación que hará que el usuario retorne al menú principal si este cometió un error en su desición
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



