#include <iostream> //
#include <iomanip> //
#include <ctime> //
#include <stdlib.h> //
#include <fstream> //

using namespace std;

int vehiculo;
int placa;
int espacio;
int matrizautos[2][5]={{1,2,3,4,5},{6,7,8,9,10}};
int matrizbicimoto[2][5]={{11,12,13,14,15},{16,17,18,19,20}};

int pago(){ //Funci�n para c�lcular el pago del usuario por el uso del parqueo.
	/*Esta casilla ser� para c�lcular los pagos que los usuarios del parqueo deber�n
	cancelar al hacer uso de 0 a 15 minutos (Gratis), de 16 a 30 minutos ($0.25),
	de 31 minutos a 1 hora ($0.50) y de 1 hora 1 minuto en adelante ($1 cada hora)
	sebas te toca hacer el c�lculo.*/
}

void buscarPlaca(){ //Funci�n para buscar placa en salida de veh�culo.
	int placa;
	cout << "Ingrese la placa a buscar" << endl;
	cin >> placa;
	ifstream myFile;
	myFile.open("parqueo.txt");
	while(!myFile.eof()){
		time_t now = time(0); 
		tm* time = localtime(&now);
		int placaAux;
		string tipoV;
		string hora;
		int lugar;
		myFile >> placaAux >> lugar >> tipoV >> hora;
		if(placaAux == placa){
			cout<< placaAux << " " << lugar << " " << tipoV << " " << hora << endl;
			return;	
		}
	}
	myFile.close();
}

void escribir1(int vehiculo){ //Archivo de historial de parqueo.
	time_t now = time(0); //variables para capturar la hora real del sistema.
	tm* time = localtime(&now);
	ofstream archivo;
	archivo.open("parqueo.txt", ios::app); //Se crea y abre el archivo si este no existe ya.
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		return;
	}
	cin>>placa;
	cin>>espacio;
	archivo << placa << " " << espacio << " " << vehiculo << " "<< time->tm_hour<<":"<<time->tm_min;
	archivo<<endl;
	archivo.close();
}

int automovilsalida(){
	buscarPlaca();
}

int automovil(){ //Funci�n que se encarga de pedir la placa del auto o cami�n y lugar de parqueo.
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
    escribir1(1);
	return 0;
}

int bicimotosalida(){
	buscarPlaca();
}

int bicimoto(){ //Funci�n que se encarga de pedir la placa de la motocicleta o bicicleta y lugar de parqueo.
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
	escribir1(2);
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



