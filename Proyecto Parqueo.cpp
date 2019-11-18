#include <iostream> //Se utiliza para operaciones de entrada y salida.
#include <iomanip> //Permite manipular el formateo de salida.
#include <ctime> //Permite manipular y formatear la fecha y la hora del sistema.
#include <stdlib.h> //Sirve para convertir un entero a cadena de caracteres.
#include <fstream> //Permite la manipulación de archivos desde el programar, tanto leer como escribir en ellos.

using namespace std;

int vehiculo;
int placa;
int espacio;
int matrizautos[2][5]={{1,2,3,4,5},{6,7,8,9,10}};
int matrizbicimoto[2][5]={{11,12,13,14,15},{16,17,18,19,20}};

int pago(){
	ifstream myFile; //Lectura de dato
	myFile.open("parqueo.txt"); //Abrir archivo 
	while(!myFile.eof()){ //Se ejecutará mientras el archivo no llegue a su última linea
		time_t now = time(0); 
		tm* time = localtime(&now);
		int cobro;
		string hora; //Hora actual del sistema
		myFile >> hora;
		if(&now<hora){
			cout<<"No debe pagar nada"<<endl;
			return;	
		}
	}
	if(cobro<0.25){
	    cout<<"no debe pagar nada";
	    cout<<endl;
	}
	
	if(cobro<0.5){
	    cout<<"debe pagar $0.25";
	    cout<<endl;
	}
	
	if(cobro<1){ 
	    cout<<"debe pagar $0.50";
	    cout<<endl;
	}
	
	if(cobro>=1){
	    cout<<"debe pagar $1.00";
	    cout<<endl;
	}
	myFile.close();
}

void buscarPlaca(){ //Función para buscar placa en salida de vehículo.
	int placa;
	cout << "Ingrese la placa a buscar" << endl;
	cin >> placa;
	ifstream myFile; //Lectura de dato
	myFile.open("parqueo.txt"); //Abrir archivo 
	while(!myFile.eof()){ //Se ejecutará mientras el archivo no llegue a su última linea
		time_t now = time(0); 
		tm* time = localtime(&now);
		int placaAux;
		string tipoV; //Tipo de vehículo
		string hora; //Hora actual del sistema
		int lugar;
		myFile >> placaAux >> lugar >> tipoV >> hora;
		if(placaAux == placa){
			cout<< placaAux << " " << lugar << " " << tipoV << " " << hora << endl;
			return;	
		}
	}
	myFile.close();
	pago();
}

void escribir1(int vehiculo){ //Archivo de historial de parqueo.
	int placa;
	int espacioP;
	time_t now = time(0); //variables para capturar la hora real del sistema.
	tm* time = localtime(&now);
	ofstream archivo;
	archivo.open("parqueo.txt", ios::app); //Se crea y abre el archivo si este no existe ya.
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		return;
	}
	cin>>placa;
	cin>>espacioP;
	archivo << placa << " " << espacio << " " << vehiculo << " "<< time->tm_hour<<":"<<time->tm_min;
	archivo<<endl;
	archivo.close();
}

int automovilsalida(){  //Función de salida del parqueo para autos y camiones.
	buscarPlaca();
}

int automovil(){ //Función que se encarga de pedir la placa del auto o camión y lugar de parqueo.
	int filas = (sizeof(matrizautos)/sizeof(matrizautos[0]));
    int columnas = (sizeof(matrizautos[0])/sizeof(matrizautos[0][0]));
    cout<<"Ingrese numero de placa de su vehiculo y seleccion lugar de parqueo:"<<endl;
    for (int i= 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            cout<<setw(3)<<" | "<<matrizautos[i][j]<<" | ";
        }
        cout<<endl<<endl;
    }
    escribir1(1);
	return 0;
}

int bicimotosalida(){ //Función de salida del parqueo para motocicletas y bicicletas.
	buscarPlaca();
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



