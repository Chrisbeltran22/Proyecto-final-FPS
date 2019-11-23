#include <iostream> //Se utiliza para operaciones de entrada y salida.
#include <iomanip> //Permite manipular el formateo de salida.
#include <ctime> //Permite manipular y formatear la fecha y la hora del sistema.
#include <stdlib.h> //Sirve para convertir un entero a cadena de caracteres.
#include <fstream> //Permite la manipulación de archivos desde el programar, tanto leer como escribir en ellos.
#include <string.h> 
#include <conio.h>


using namespace std;

int vehiculo;
int placa;
int espacio;

void buscarPlaca(){ //Función para buscar placa en salida de vehículo.
	int placa;
	cout << "Ingrese la placa a buscar" << endl;
	cin >> placa;
	ifstream parqueo; //Lectura de dato
	ifstream espacios; //Lectura de dato
	parqueo.open("parqueo.txt"); //Abrir archivo
	espacios.open("espacios.txt"); //Abrir archivo
	while(!parqueo.eof() || !espacios.eof()){ //Se ejecutará mientras el archivo no llegue a su última linea
		time_t now = time(0);  //Variable de captura de tiempo
		tm* time = localtime(&now);
		int placaAux;
		string tipoV; //Tipo de vehículo
		string hora; //Hora actual del sistema
		int lugar;
		parqueo >> placaAux >> lugar >> tipoV >> hora; //Guarda los datos en el archivo "parqueo"
		cout<<endl;
		espacios>> lugar >> hora; //Guarda los datos en el archivo "espacios"
		cout<< endl;
		if(placaAux == placa){ //Comparamos las placas ya obtenidas con la que se digita al salir del parqueo
			cout<< placaAux << " " << lugar << " " << tipoV << " " << hora << endl;
			return;	
		}
		
	}
	
	espacios.close(); //Se cierra el archivo espacios
	parqueo.close(); //Se cierra el archivo parqueo
	cout<<"Debe cancelar $0.50"<<endl;
	cout<<"Gracias por hacer uso de nuestros servicios";
	system("pause");

}

void escribir1(int vehiculo){ //Archivo de historial de parqueo.
	
	time_t now = time(0); //variables para capturar la hora real del sistema.
	tm* time = localtime(&now);
	int espacio, opcion, k=1;
	string matrizparqueo[4][5]={{"1","2","3","4","5"},{"6","7","8","9","10"},{"11","12","13","14","15"},{"16","17","18","19","20"}};
		
		while(k=1){
			
			for (int i=0;i<4;i++){ //muestro la matriz de los espacios del parqueo
				for (int j=0;j<5;j++){
					cout<<" | "<<setw(3)<<matrizparqueo[i][j]<<" | ";
				}
				cout<<endl;
			}
			
			cout<<"1-Seleccionar un espacio\n2-Ver espacios ocupados\n3-Terminar proceso"<<endl; //menu
			cout<<"Opcion: ";cin>>opcion;
			
			if(opcion==1){
				for (int i=0;i<4;i++){
					for (int j=0;j<5;j++){
						cout<<" | "<<setw(3)<<matrizparqueo[i][j]<<" | "; //le muestro de nuevo la matriz
					}
					cout<<endl;
				}
				
				cout<<"Elija un espacio: ";cin>>espacio; //pido una opcion de espacio
				cout<<"Digite la placa de su vehiculo: ";cin>>placa; //pido la placa del usuario

				ofstream parqueo("parqueo.txt",ios_base::app);//Guardo la placa en un archivo
				ofstream espacios("espacios.txt",ios_base::app); //Guardo el espacio en un archivo
				
				if (espacios.is_open()){ //Si el archivo se abre
					espacios<<espacio<<" "<<time->tm_hour<<":"<<time->tm_min<<endl;
					cout<<endl;
					espacios.close();
				}
				
				if(parqueo.is_open()){ //Si el archivo se abre
					parqueo<<placa<<" "<<espacio<<" "<<vehiculo<<endl;
					cout<<endl;
					parqueo.close();
				}
				
				else{
					cout<<"No se puede abrir el archivo o no existe"<<endl;
				}
				system("cls");
			}
			if(opcion==2){
				system("cls");
				string line; //leo el archivo con los espacion guardados
				ifstream espacios("espacios.txt");
				if (espacios.is_open()){ //Si el archivo se abre
					while (getline (espacios,line)){	
						cout << line << '\n';
					}
					system("pause");
					system("cls");
							
					if(espacios.eof()){	
						cout<<"Se ha terminado de leer. Fin del archivo"<<endl;
							
					}
					espacios.close();
				}
				else cout << "No se puede abrir el archivo o no existe.";					
			}
					
			if(opcion==3){
				break;
			}		
		
		}

}
				
int automovilsalida(){  //Función de salida del parqueo para autos y camiones.
	buscarPlaca();
}


int bicimotosalida(){ //Función de salida del parqueo para motocicletas y bicicletas.
	buscarPlaca();
}

int menu(){
	int programa=0;
	int proceso;
	while(programa!=3){
		system("cls"); //Comando para limpiar pantalla
		cout<<"Bienvenido"<<endl;
		time_t now = time(0); //variables para capturar la hora real del sistema.
		tm* time = localtime(&now);
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
		    		escribir1(1); //Llama a la función de los autos o camiones.
		    		break;
		    	case 2:
		    		escribir1(2); //Llama a la función de las motocicletas o bicicletas.
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


int main (){
	menu();
}



