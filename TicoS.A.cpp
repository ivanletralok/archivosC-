#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string.h>
#include <sys/types.h>
#include <sys/stat.h>
using namespace std;

//Variables globales
string fecha = "00/00/0000";
int opc, i = 1, j = 0;

//Prototipo de funciones
void ingreso_pasajeros();
void validacion_datos(int opcion_seleccionada, int iterador);
void converterDecToHexa(string date);
bool validar_fecha(string fecha_actual);
void validar_siExiste_archivo();
void Menu_Administrativo();
void Menu_Principal();

int main(){
	system("color 02");
	//Menu de inicio
	//Ingresar la fecha
	while(1){
		cout<<"Ingresa la fecha en el siguiente formato con / (dd/mm/yyyy): ";
		getline(cin,fecha);
		if(validar_fecha(fecha)){
			break;
		}else{
			cout<<"Parametro de la fecha incorrectos, vuelve a intentarlo"<<endl;
			system("pause");
			system("cls");
		}
	}
	Menu_Principal();
	
	
    return 0;
}
//Menu principal
void Menu_Principal(){
	system("Pause");
	system("cls");
	while(i){
		cout<<"     --------------------------------\r\n";
	    cout<<"     >>    Programa de Analisis    <<\r\n";
		cout<<"     --------------------------------\r\n";
		cout<<"²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²\r\n";
		cout<<"²²     Transporte Turismo_Tico S.A     ²²\r\n";
		cout<<"²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²\r\n";
		cout<<"²²²²                                 ²²²²\r\n";
		cout<<"²²                                     ²²\r\n";
		cout<<"²²   1.Ingreso de Datos de Pasajeros.  ²²\r\n";
		cout<<"²²   2.Analisis Administrativo.        ²²\r\n";
		cout<<"²²                                     ²²\r\n";
		cout<<"²²²²                                 ²²²²\r\n";
		cout<<"²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²\r\n";
		cout<<"      Elige una Opcion [1 - 2]: ";
		cin>>opc; 
		cout<<"²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²\r\n\n\n"; 
		//Ingreso de pasajeros
		switch(opc){
			case 1:
				system("Pause");
				system("cls");
				ingreso_pasajeros();
				i = 0; //Para salir del ciclo infinito
			break;
			case 2:
				system("Pause");
				system("cls");
				Menu_Administrativo();
			break;
			default:
				cout<<">> ERROR, VUELVE A INTENTAR <<\r\n";
				system("Pause");
				system("cls");	
		}	
	}
}
//Funcion para convertir de decimal a hexadecimal
void converterDecToHexa(string date){
	validar_siExiste_archivo();
	ofstream archivo;
	archivo.open("Datos_Usuario.txt",ios::app); //app = para añadir texto extra
	if(archivo.fail()){
		cout<<"ERRORAL INTENTAR ABRIR ARCHIVO\r\n";
		exit(1);
	}
	int a;
	int numero = 0;
	int vec[3], x = 0;
	for(a = 0; a<11 ;a++){
		if((date[a] >= '0' && date[a] <= '9')){
			numero = numero*10+(date[a]-0x30);
		}else{
			vec[x] = numero;
			x++;
			numero = 0;
		}
	}
	//convertir
	int m = 0;
	int digitoex[20];
	int decimal, residuo, resultado;
	for(m=0; m<3; m++){
		decimal = vec[m];
	    int residuo, resultado, i = 0;
	    do{
	        residuo = decimal % 16;
	        resultado = decimal / 16;
	        digitoex[i] = residuo;
	        decimal = resultado;
	        i++;
	    }while(resultado > 15);
	    digitoex[i] = resultado;
	    archivo<<"&";
	    int bandera = 1;
	    for (int j = i; j >= 0; j--){	
	    	switch(digitoex[j]){
	    		case 0:
	    			if(bandera==0){
	    				archivo<<"0";
					}
					bandera = 0;
				break;
				case 1:
					archivo<<"1";
				break;
				case 2:
					archivo<<"2";
				break;
				case 3:
					archivo<<"3";
				break;
	    		case 4:
					archivo<<"4";
				break;
				case 5:
					archivo<<"5";
				break;
				case 6:
					archivo<<"6";
				break;
				case 7:
					archivo<<"7";
				break;
				case 8:
					archivo<<"8";
				break;
				case 9:
					archivo<<"9";
				break;
	    		case 10:
					archivo<<"A";
				break;
				case 11:
					archivo<<"B";
				break;
				case 12:
					archivo<<"C";
				break;
				case 13:
					archivo<<"D";
				break;
				case 14:
					archivo<<"E";
				break;
				case 15:
					archivo<<"F";
				break;
			}
	    }
	}
	archivo.close();
}

void ingreso_pasajeros(){
	system("cls");
	string parametros[16]; //16 es lo maximo que puede almacenar
	int i = 0, opc, flag, valid;
	char petition, other_passenger;
	while(i<5){
		flag = 1;
		switch(i){
			case 0:
				while(flag){
					cout<<"     --------------------------------\r\n";
				    cout<<"     >>    Programa de Analisis    <<\r\n";
					cout<<"     --------------------------------\r\n";
					cout<<"²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²\r\n";
					cout<<"²²     Transporte Turismo_Tico S.A     ²²\r\n";
					cout<<"²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²\r\n";
					cout<<"²²²²                                 ²²²²\r\n";
					cout<<"²²  1.Ingreso de Datos de Pasajeros.   ²²\r\n";
					cout<<"²²      Fecha Actual: "<<fecha<<"       ²²\r\n";
					cout<<"²²²²                                 ²²²²\r\n";
					cout<<"²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²\r\n";
					cout<<"²²   Tipo Turismo                      ²²\r\n";
					cout<<"²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²\r\n";
					cout<<"²² 1. Volcanes                         ²²\r\n"; 	
					cout<<"²² 2. Playa                            ²²\r\n";
					cout<<"²² 3. Monta"<<char(-92)<<"a                          ²²\r\n";
					cout<<"²² 4. Aventura                         ²²\r\n";
					cout<<"²² 5. Rapidos                          ²²\r\n";
					cout<<"²²   Elige una Opcion [1 - 4]:         ²²\r\n";
					cout<<"²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²\r\n  :>> "; 
					cin>>opc;
					if(opc>5 || opc<1){
						flag = 1;
						cout<<">> ERROR, VUELVE A INTENTAR <<\r\n";
						system("Pause");
						system("cls");
					}else{
						//
						try
					    {
					        validacion_datos(opc,i);
					    }
					    catch (const char *msg)
					    {
					        cerr << msg << endl;
					    }
						flag = 0;
						i++;
					}	
				}
			break;
			case 1:
				while(flag){
					cout<<"²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²\r\n";
					cout<<"²²   Tipo de Personas                  ²²\r\n";
					cout<<"²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²\r\n";
					cout<<"²² 1. Pensionado(65 a"<<char(-92)<<"os en adelante)  ²²\r\n"; 	
					cout<<"²² 2. Ni"<<char(-92)<<"o(a) (0-11a"<<char(-92)<<"os)               ²²\r\n";
					cout<<"²² 3. Adolecente (12-17 a"<<char(-92)<<"os)          ²²\r\n";
					cout<<"²² 4. Adulto (de 18 a"<<char(-92)<<"os en adelante,  ²²\r\n";
					cout<<"²²    antes de los 65 a"<<char(-92)<<"os)            ²²\r\n";
					cout<<"²² 5. Discapacitado                    ²²\r\n";
					cout<<"²²   Elige una Opcion [1 - 5]:         ²²\r\n";
					cout<<"²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²\r\n  :>> "; 
					cin>>opc;
					if(opc>5 || opc<1){
						flag = 1;
						cout<<">> ERROR, VUELVE A INTENTAR <<\r\n";
						system("Pause");
						system("cls");
						cout<<"     --------------------------------\r\n";
					    cout<<"     >>    Programa de Analisis    <<\r\n";
						cout<<"     --------------------------------\r\n";
					}else{
						validar_siExiste_archivo(); //Validar si el archivo aun existe o se borro
						flag = 0;
						i++;
					}	
				}
			break;
			case 2:
				while(flag){
					cout<<"²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²\r\n";
					cout<<"²²   Genero                            ²²\r\n";
					cout<<"²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²\r\n";
					cout<<"²² 1. Femenino                         ²²\r\n"; 	
					cout<<"²² 2. Masculino                        ²²\r\n";
					cout<<"²² 3. Otro                             ²²\r\n";
					cout<<"²²   Elige una Opcion [1 - 3]:         ²²\r\n";
					cout<<"²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²\r\n  :>> ";
					cin>>opc; 
				if(opc>3 || opc<1){
						flag = 1;
						cout<<">> ERROR, VUELVE A INTENTAR <<\r\n";
						system("Pause");
						system("cls");
						cout<<"     --------------------------------\r\n";
					    cout<<"     >>    Programa de Analisis    <<\r\n";
						cout<<"     --------------------------------\r\n";
					}else{
						validar_siExiste_archivo(); //Validar si el archivo aun existe o se borro
						converterDecToHexa(fecha);
						flag = 0;
						i++;
					}	
				}
			break;
			case 3:
				while(flag){
					cout<<"²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²\r\n";
					cout<<"²²   Peticiones                        ²²\r\n";
					cout<<"²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²\r\n";
					cout<<"²² 1. Silla oara ni"<<char(-92)<<"o(a)               ²²\r\n"; 	
					cout<<"²² 2. Sercivio sanitario               ²²\r\n";
					cout<<"²² 3. Aire Acondicionado               ²²\r\n";
					cout<<"²² 4. Espacio para silla de rueda      ²²\r\n"; 	
					cout<<"²² 5. Asistencia para subir y bajar    ²²\r\n";
					cout<<"²²    del autobus                      ²²\r\n";
					cout<<"²² 6. Rampa en el autobus              ²²\r\n"; 	
					cout<<"²² 7. Vegano                           ²²\r\n";
					cout<<"²² 8. Comida sin gluten                ²²\r\n";
					cout<<"²² 9. Comida sin semillas              ²²\r\n";
					cout<<"²² 10. Traductor                       ²²\r\n";
					cout<<"²²   Elige una Opcion [1 - 10]:        ²²\r\n";
					cout<<"²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²\r\n  :>> "; 
					cin>>opc;
					if(opc>10 || opc<1){
						flag = 1;
						cout<<">> ERROR, VUELVE A INTENTAR <<\r\n";
						system("Pause");
						system("cls");
						cout<<"     --------------------------------\r\n";
					    cout<<"     >>    Programa de Analisis    <<\r\n";
						cout<<"     --------------------------------\r\n";
					}else{
						valid = 1;
						while(valid){
							cout<<" Desea ingresar otra peticion: (S/N): ";
							cin>>petition;
							if(petition == 's' || petition == 'S'){
								flag = 1;
								valid = 0; //Para salir del bucle infinito xD
								validar_siExiste_archivo(); //Validar si el archivo aun existe o se borro
							}else if(petition != 'n' && petition != 'N'){
								cout<<">> ERROR, VUELVE A INTENTAR <<\r\n";
								system("pause");
								system("cls");
							}else{ //En este caso no quiere ingresar mas peticiones
								i++;
								flag = 0;
								valid = 0;
							}	
						}
					}
				}
			break;
			case 4:
				valid = 1;
				while(valid){ //Entra en un buble infinito
					cout<<"\r\n\n Desea ingresar otro Pasajero: (S/N): ";
					cin>>other_passenger;
					if(other_passenger == 's' || other_passenger == 'S'){
						ofstream archivo;
						archivo.open("Datos_Usuario.txt",ios::app); //app = para añadir texto extra
						if(archivo.fail()){
							cout<<"ERRORAL INTENTAR ABRIR ARCHIVO\r\n";
							exit(1);
						}
						archivo<<"\r\n";
						archivo.close();
						flag = 1;	cout<<endl;
						i = 0;
						valid = 0; //Para salir del bucle infinito xD
					}else if(other_passenger != 'n' && other_passenger != 'N'){
						cout<<">> ERROR, VUELVE A INTENTAR <<\r\n";
					}else{ //En este caso no quiere ingresar mas pasajeros
						i++;
						flag = 0; //Ultimo valor de flag (OPCIONAL)
						cout<<"\r\n²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²\r\n";
						cout<<"²²    Datos Guardados exitosamente.    ²²\r\n";
						cout<<"²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²\r\n";
						valid = 0;
					}	
				}	
			break;
		}	
	}
}
//Menu administrativo
void Menu_Administrativo(){
	int opcion_admin, flag = 1;
	while(flag==1){
		cout<<"     --------------------------------\r\n";
	    cout<<"     >>    Programa de Analisis    <<\r\n";
		cout<<"     --------------------------------\r\n";
		cout<<"²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²\r\n";
		cout<<"²²     Transporte Turismo_Tico S.A     ²²\r\n";
		cout<<"²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²\r\n";
		cout<<"²²²²                                 ²²²²\r\n";
		cout<<"²²                                     ²²\r\n";
		cout<<"²²   1.Proceso de archivo.             ²²\r\n";
		cout<<"²²   2.Reporte del archivo.            ²²\r\n";
		cout<<"²²   3.Salir.                          ²²\r\n";
		cout<<"²²                                     ²²\r\n";
		cout<<"²²²²                                 ²²²²\r\n";
		cout<<"²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²\r\n";
		cout<<"      Elige una Opcion [1 - 3]: ";
		cin>>opcion_admin; 
		cout<<"²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²\r\n\n\n";
		switch(opcion_admin){
			case 1:
				
			break;
			case 2:
				
			break;
			case 3:
				cout<<"\r\n²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²\r\n";
				cout<<"²²   Se regresara al menu principal.   ²²\r\n";
				cout<<"²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²\r\n";
				flag = 2;
			break;
			default:
				cout<<">> ERROR, VUELVE A INTENTAR <<\r\n";
				system("Pause");
				system("cls");	
		} 	
	}	
	if(flag == 2){
		Menu_Principal();
	}
}


void validacion_datos(int opcion_seleccionada, int iterador){

	//archivo.close();
	
	switch(iterador){
		case 0:{
			ofstream archivo;
			archivo.open("Datos_Usuario.txt",ios::app); //app = para añadir texto extra
			if(archivo.fail()){
				cout<<"ERRORAL INTENTAR ABRIR ARCHIVO\r\n";
				exit(1);
			}
				switch(opcion_seleccionada){
					case 1:
						archivo<<"vol";
					break;
					case 2:
						archivo<<"pla";
					break;
					case 3:
						archivo<<"mon";
					break;
					case 4:
						archivo<<"avt";
					break;
					case 5:
						archivo<<"rap";
					break;
				}
			archivo.close();
		}break;
		case 1:{
			ofstream archivo;
			archivo.open("Datos_Usuario.txt",ios::app); //app = para añadir texto extra
			if(archivo.fail()){
				cout<<"ERRORAL INTENTAR ABRIR ARCHIVO\r\n";
				exit(1);
			}
				archivo<<"&";
				switch(opcion_seleccionada){
					case 1:
						archivo<<"pen";
					break;
					case 2:
						archivo<<"nin";
					break;
					case 3:
						archivo<<"ado";
					break;
					case 4:
						archivo<<"adu";
					break;
					case 5:
						archivo<<"dis";
					break;
				}
			archivo.close();
		}break;
		case 2:{
			ofstream archivo;
			archivo.open("Datos_Usuario.txt",ios::app); //app = para añadir texto extra
			if(archivo.fail()){
				cout<<"ERRORAL INTENTAR ABRIR ARCHIVO\r\n";
				exit(1);
			}
				archivo<<"&";
				switch(opcion_seleccionada){
					case 1:
						archivo<<"fe";
					break;
					case 2:
						archivo<<"ma";
					break;
					case 3:
						archivo<<"otr";
					break;
				}
			archivo.close();
			//Fecha actual en hexadecimal
			converterDecToHexa(fecha);
			//vuelvo a abrir el archivo				
		}break;
		case 3:{
			ofstream archivo;
			archivo.open("Datos_Usuario.txt",ios::app); //app = para añadir texto extra
			if(archivo.fail()){
				cout<<"ERRORAL INTENTAR ABRIR ARCHIVO\r\n";
				exit(1);
			}
				archivo<<"&";
				switch(opcion_seleccionada){
					case 1:
						archivo<<"sin";
					break;
					case 2:
						archivo<<"wc";
					break;
					case 3:
						archivo<<"aic";
					break;
					case 4:
						archivo<<"sir";
					break;
					case 5:
						archivo<<"asi";
					break;
					case 6:
						archivo<<"rap";
					break;
					case 7:
						archivo<<"veg";
					break;
					case 8:
						archivo<<"sgl";
					break;
					case 9:
						archivo<<"css";
					break;
					case 10:
						archivo<<"tra";
					break;
				}
			archivo.close();					
		}break;
		case 4:
			ofstream archivo;
			archivo.open("Datos_Usuario.txt",ios::app); //app = para añadir texto extra
			if(archivo.fail()){
				cout<<"ERRORAL INTENTAR ABRIR ARCHIVO\r\n";
				exit(1);
			}
				archivo<<endl;
			archivo.close();
		break;		
	}
}

bool validar_fecha(string fecha_actual){
	int a;
	int numero = 0;
	int vec[3], x = 0;
	for(a = 0; a<11 ;a++){
		if((fecha_actual[a] >= '0' && fecha_actual[a] <= '9')){
			numero = numero*10+(fecha_actual[a]-0x30);
		}else{
			vec[x] = numero;
			x++;
			numero = 0;
		}
	}
	//Validar si los parametros son correctos
	//MES ESPECIAL = febrero = 2
	if(vec[1] == 2){
        if((vec[2] % 4 == 0) && (vec[2] % 100 != 0) || vec[2] == 2000){
            if(vec[0] >= 1 && vec[0] <= 29){
				return 1;
            }
        }else if(vec[0] >= 1 && vec[0] <= 28){
            	return 1;
		}else{
			return 0;
		}
    }
	//MESES CON 31_ 1,3,5,7,8,10,12
	if(vec[1] == 1 || vec[1] == 3 || vec[1] == 5 || vec[1] == 7 || vec[1] == 8 || vec[1] == 10 || vec[1] == 12){
		if(vec[0] >= 1 && vec[0] <=31){
			return 1;
		}
	}else{
		//MESES CON 30_ 4,6,8,11
		if(vec[1] == 4 || vec[1] == 6 || vec[1] == 8 || vec[1] == 11){
			if(vec[0] >= 1 && vec[0] <=30){
				return 1;
			}
		}else{
			return 0;
		}
	}
}

void validar_siExiste_archivo(){
	try
    {
        struct stat f__stat;
        bool Existe = (stat("Datos_Usuario.txt", &f__stat) != 0);

        if (!Existe)
        {
            validacion_datos(opc,i);
        }else{
            cout<<"Archivo no encontrado o ha sido eliminado!\r\n\n";
            exit(1);
        }
    }
    catch (const char *msg)
    {
        cerr << msg << endl;
    }
}