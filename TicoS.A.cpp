#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string.h>
using namespace std;

//Variables globales
string fecha = "00/00/0000";

//Prototipo de funciones
void ingreso_pasajeros();
void validacion_datos(int opcion_seleccionada, int iterador);
void converterDecToHexa(string date);

int main()
{
	system("color 02");
	//Menu de inicio
	int opc, i = 1, j = 0;
	//Ingresar la fecha
	cout << "Ingresa la fecha en el siguiente formato con / (dd/mm/yyyy): ";
	getline(cin, fecha);
	system("Pause");
	system("cls");
	while (i)
	{
		cout << "     --------------------------------\r\n";
		cout << "     >>    Programa de Analisis    <<\r\n";
		cout << "     --------------------------------\r\n";
		cout << "�����������������������������������������\r\n";
		cout << "��     Transporte Turismo_Tico S.A     ��\r\n";
		cout << "�����������������������������������������\r\n";
		cout << "����                                 ����\r\n";
		cout << "��                                     ��\r\n";
		cout << "��   1.Ingreso de Datos de Pasajeros.  ��\r\n";
		cout << "��   2.Analisis Administrativo.        ��\r\n";
		cout << "��                                     ��\r\n";
		cout << "����                                 ����\r\n";
		cout << "�����������������������������������������\r\n";
		cout << "      Elige una Opcion [1 - 2]: ";
		cin >> opc;
		cout << "�����������������������������������������\r\n\n\n";
		//Ingreso de pasajeros
		switch (opc)
		{
		case 1:
			system("Pause");
			system("cls");
			ingreso_pasajeros();
			i = 0; //Para salir del ciclo infinito
			break;
		case 2:

			break;
		default:
			cout << ">> ERROR, VUELVE A INTENTAR <<\r\n";
			system("Pause");
			system("cls");
		}
	}

	return 0;
}
//Funcion para convertir de decimal a hexadecimal
void converterDecToHexa(string date)
{
	try
	{
		ofstream archivo;
		archivo.open("Datos_Usuario.txt", ios::app); //app = para a�adir texto extra
		if (archivo.fail())
		{
			cout << "ERRORAL INTENTAR ABRIR ARCHIVO\r\n";
			exit(1);
		}
		int a;
		int numero = 0;
		int vec[3], x = 0;
		for (a = 0; a < 11; a++)
		{
			if ((date[a] >= '0' && date[a] <= '9'))
			{
				numero = numero * 10 + (date[a] - 0x30);
			}
			else
			{
				vec[x] = numero;
				x++;
				numero = 0;
			}
		}
		//convertir
		int m = 0;
		int digitoex[20];
		int decimal, residuo, resultado;
		for (m = 0; m < 3; m++)
		{
			decimal = vec[m];
			int residuo, resultado, i = 0;
			do
			{
				residuo = decimal % 16;
				resultado = decimal / 16;
				digitoex[i] = residuo;
				decimal = resultado;
				i++;
			} while (resultado > 15);
			digitoex[i] = resultado;
			archivo << "&";
			int bandera = 1;
			for (int j = i; j >= 0; j--)
			{
				switch (digitoex[j])
				{
				case 0:
					if (bandera == 0)
					{
						archivo << "0";
					}
					bandera = 0;
					break;
				case 1:
					archivo << "1";
					break;
				case 2:
					archivo << "2";
					break;
				case 3:
					archivo << "3";
					break;
				case 4:
					archivo << "4";
					break;
				case 5:
					archivo << "5";
					break;
				case 6:
					archivo << "6";
					break;
				case 7:
					archivo << "7";
					break;
				case 8:
					archivo << "8";
					break;
				case 9:
					archivo << "9";
					break;
				case 10:
					archivo << "A";
					break;
				case 11:
					archivo << "B";
					break;
				case 12:
					archivo << "C";
					break;
				case 13:
					archivo << "D";
					break;
				case 14:
					archivo << "E";
					break;
				case 15:
					archivo << "F";
					break;
				}
			}
		}
		archivo.close();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}

void ingreso_pasajeros()
{
	system("cls");
	string parametros[16]; //16 es lo maximo que puede almacenar
	int i = 0, opc, flag, valid;
	char petition, other_passenger;
	while (i < 5)
	{
		flag = 1;
		switch (i)
		{
		case 0:
			while (flag)
			{
				cout << "     --------------------------------\r\n";
				cout << "     >>    Programa de Analisis    <<\r\n";
				cout << "     --------------------------------\r\n";
				cout << "�����������������������������������������\r\n";
				cout << "��     Transporte Turismo_Tico S.A     ��\r\n";
				cout << "�����������������������������������������\r\n";
				cout << "����                                 ����\r\n";
				cout << "��  1.Ingreso de Datos de Pasajeros.   ��\r\n";
				cout << "��      Fecha Actual: " << fecha << "       ��\r\n";
				cout << "����                                 ����\r\n";
				cout << "�����������������������������������������\r\n";
				cout << "��   Tipo Turismo                      ��\r\n";
				cout << "�����������������������������������������\r\n";
				cout << "�� 1. Volcanes                         ��\r\n";
				cout << "�� 2. Playa                            ��\r\n";
				cout << "�� 3. Monta" << char(-92) << "a                          ��\r\n";
				cout << "�� 4. Aventura                         ��\r\n";
				cout << "�� 5. Rapidos                          ��\r\n";
				cout << "��   Elige una Opcion [1 - 4]:         ��\r\n";
				cout << "�����������������������������������������\r\n  :>> ";
				cin >> opc;
				if (opc > 5 || opc < 1)
				{
					flag = 1;
					cout << ">> ERROR, VUELVE A INTENTAR <<\r\n";
					system("Pause");
					system("cls");
				}
				else
				{
					validacion_datos(opc, i);
					flag = 0;
					i++;
				}
			}
			break;
		case 1:
			while (flag)
			{
				cout << "�����������������������������������������\r\n";
				cout << "��   Tipo de Personas                  ��\r\n";
				cout << "�����������������������������������������\r\n";
				cout << "�� 1. Pensionado(65 a" << char(-92) << "os en adelante)  ��\r\n";
				cout << "�� 2. Ni" << char(-92) << "o(a) (0-11a" << char(-92) << "os)               ��\r\n";
				cout << "�� 3. Adolecente (12-17 a" << char(-92) << "os)          ��\r\n";
				cout << "�� 4. Adulto (de 18 a" << char(-92) << "os en adelante,  ��\r\n";
				cout << "��    antes de los 65 a" << char(-92) << "os)            ��\r\n";
				cout << "�� 5. Discapacitado                    ��\r\n";
				cout << "��   Elige una Opcion [1 - 5]:         ��\r\n";
				cout << "�����������������������������������������\r\n  :>> ";
				cin >> opc;
				if (opc > 5 || opc < 1)
				{
					flag = 1;
					cout << ">> ERROR, VUELVE A INTENTAR <<\r\n";
					system("Pause");
					system("cls");
					cout << "     --------------------------------\r\n";
					cout << "     >>    Programa de Analisis    <<\r\n";
					cout << "     --------------------------------\r\n";
				}
				else
				{
					validacion_datos(opc, i);
					flag = 0;
					i++;
				}
			}
			break;
		case 2:
			while (flag)
			{
				cout << "�����������������������������������������\r\n";
				cout << "��   Genero                            ��\r\n";
				cout << "�����������������������������������������\r\n";
				cout << "�� 1. Femenino                         ��\r\n";
				cout << "�� 2. Masculino                        ��\r\n";
				cout << "�� 3. Otro                             ��\r\n";
				cout << "��   Elige una Opcion [1 - 3]:         ��\r\n";
				cout << "�����������������������������������������\r\n  :>> ";
				cin >> opc;
				if (opc > 3 || opc < 1)
				{
					flag = 1;
					cout << ">> ERROR, VUELVE A INTENTAR <<\r\n";
					system("Pause");
					system("cls");
					cout << "     --------------------------------\r\n";
					cout << "     >>    Programa de Analisis    <<\r\n";
					cout << "     --------------------------------\r\n";
				}
				else
				{
					validacion_datos(opc, i);
					flag = 0;
					i++;
				}
			}
			break;
		case 3:
			while (flag)
			{
				cout << "�����������������������������������������\r\n";
				cout << "��   Peticiones                        ��\r\n";
				cout << "�����������������������������������������\r\n";
				cout << "�� 1. Silla para ni" << char(-92) << "o(a)               ��\r\n";
				cout << "�� 2. servicio sanitario               ��\r\n";
				cout << "�� 3. Aire Acondicionado               ��\r\n";
				cout << "�� 4. Espacio para silla de rueda      ��\r\n";
				cout << "�� 5. Asistencia para subir y bajar    ��\r\n";
				cout << "��    del autobus                      ��\r\n";
				cout << "�� 6. Rampa en el autobus              ��\r\n";
				cout << "�� 7. Vegano                           ��\r\n";
				cout << "�� 8. Comida sin gluten                ��\r\n";
				cout << "�� 9. Comida sin semillas              ��\r\n";
				cout << "�� 10. Traductor                       ��\r\n";
				cout << "��   Elige una Opcion [1 - 10]:        ��\r\n";
				cout << "�����������������������������������������\r\n  :>> ";
				cin >> opc;
				if (opc > 10 || opc < 1)
				{
					flag = 1;
					cout << ">> ERROR, VUELVE A INTENTAR <<\r\n";
					system("Pause");
					system("cls");
					cout << "     --------------------------------\r\n";
					cout << "     >>    Programa de Analisis    <<\r\n";
					cout << "     --------------------------------\r\n";
				}
				else
				{
					valid = 1;
					while (valid)
					{
						cout << " Desea ingresar otra peticion: (S/N): ";
						cin >> petition;
						if (petition == 's' || petition == 'S')
						{
							flag = 1;
							valid = 0; //Para salir del bucle infinito xD
							validacion_datos(opc, i);
						}
						else if (petition != 'n' && petition != 'N')
						{
							cout << ">> ERROR, VUELVE A INTENTAR <<\r\n";
							system("pause");
							system("cls");
						}
						else
						{ //En este caso no quiere ingresar mas peticiones
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
			while (valid)
			{ //Entra en un buble infinito
				cout << "\r\n\n Desea ingresar otro Pasajero: (S/N): ";
				cin >> other_passenger;
				if (other_passenger == 's' || other_passenger == 'S')
				{
					ofstream archivo;
					archivo.open("Datos_Usuario.txt", ios::app); //app = para a�adir texto extra
					if (archivo.fail())
					{
						cout << "ERRORAL INTENTAR ABRIR ARCHIVO\r\n";
						exit(1);
					}
					archivo << "\r\n";
					archivo.close();
					flag = 1;
					cout << endl;
					i = 0;
					valid = 0; //Para salir del bucle infinito xD
				}
				else if (other_passenger != 'n' && other_passenger != 'N')
				{
					cout << ">> ERROR, VUELVE A INTENTAR <<\r\n";
				}
				else
				{ //En este caso no quiere ingresar mas pasajeros
					i++;
					flag = 0; //Ultimo valor de flag (OPCIONAL)
					cout << "\r\n�����������������������������������������\r\n";
					cout << "��    Datos Guardados exitosamente.    ��\r\n";
					cout << "�����������������������������������������\r\n";
					valid = 0;
				}
			}
			break;
		}
	}
}

void validacion_datos(int opcion_seleccionada, int iterador)
{

	//archivo.close();

	switch (iterador)
	{
	case 0:
	{
		ofstream archivo;
		archivo.open("Datos_Usuario.txt", ios::app); //app = para a�adir texto extra
		if (archivo.fail())
		{
			cout << "ERRORAL INTENTAR ABRIR ARCHIVO\r\n";
			exit(1);
		}
		switch (opcion_seleccionada)
		{
		case 1:
			archivo << "vol";
			break;
		case 2:
			archivo << "pla";
			break;
		case 3:
			archivo << "mon";
			break;
		case 4:
			archivo << "avt";
			break;
		case 5:
			archivo << "rap";
			break;
		}
		archivo.close();
	}
	break;
	case 1:
	{
		ofstream archivo;
		archivo.open("Datos_Usuario.txt", ios::app); //app = para a�adir texto extra
		if (archivo.fail())
		{
			cout << "ERRORAL INTENTAR ABRIR ARCHIVO\r\n";
			exit(1);
		}
		archivo << "&";
		switch (opcion_seleccionada)
		{
		case 1:
			archivo << "pen";
			break;
		case 2:
			archivo << "nin";
			break;
		case 3:
			archivo << "ado";
			break;
		case 4:
			archivo << "adu";
			break;
		case 5:
			archivo << "dis";
			break;
		}
		archivo.close();
	}
	break;
	case 2:
	{
		ofstream archivo;
		archivo.open("Datos_Usuario.txt", ios::app); //app = para a�adir texto extra
		if (archivo.fail())
		{
			cout << "ERRORAL INTENTAR ABRIR ARCHIVO\r\n";
			exit(1);
		}
		archivo << "&";
		switch (opcion_seleccionada)
		{
		case 1:
			archivo << "fe";
			break;
		case 2:
			archivo << "ma";
			break;
		case 3:
			archivo << "otr";
			break;
		}
		archivo.close();
		//Fecha actual en hexadecimal
		converterDecToHexa(fecha);
		//vuelvo a abrir el archivo
	}
	break;
	case 3:
	{
		ofstream archivo;
		archivo.open("Datos_Usuario.txt", ios::app); //app = para a�adir texto extra
		if (archivo.fail())
		{
			cout << "ERRORAL INTENTAR ABRIR ARCHIVO\r\n";
			exit(1);
		}
		archivo << "&";
		switch (opcion_seleccionada)
		{
		case 1:
			archivo << "sin";
			break;
		case 2:
			archivo << "wc";
			break;
		case 3:
			archivo << "aic";
			break;
		case 4:
			archivo << "sir";
			break;
		case 5:
			archivo << "asi";
			break;
		case 6:
			archivo << "rap";
			break;
		case 7:
			archivo << "veg";
			break;
		case 8:
			archivo << "sgl";
			break;
		case 9:
			archivo << "css";
			break;
		case 10:
			archivo << "tra";
			break;
		}
		archivo.close();
	}
	break;
	case 4:
		ofstream archivo;
		archivo.open("Datos_Usuario.txt", ios::app); //app = para a�adir texto extra
		if (archivo.fail())
		{
			cout << "ERRORAL INTENTAR ABRIR ARCHIVO\r\n";
			exit(1);
		}
		archivo << endl;
		archivo.close();
		break;
	}
}
