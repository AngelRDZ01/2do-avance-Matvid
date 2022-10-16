#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<string.h>
#include<fstream>
#include<ctime>
#include<cmath>
using namespace std;
struct cliente
{
	char nombre[30];
	int edad;
	int tratamiento;
	double codigo;
	int costo;
	cliente* next;
};
cliente* first = NULL;
cliente* last = NULL;
cliente* auxiliar = NULL;
int accion, day, week, month, back;
char dw[7][15] = { "Lunes", "Martes", "Miercoles" ,"Jueves", "Viernes", "Sabado", "Domingo" };
char m[12][15] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };
void agendarcita();
void fechadelacita();
void mostrarcita();
void eliminarcita();
void modificarcita();
void guardarclientes();
void montototal();
int main()
{
	while (true)
	{
		//Manual de Usuario
		cout << "Bienvenido a Imagen dental" << endl;
		cout << "A continuacion se le dara un breve manual" << endl;
		system("pause");
		system("cls");
		cout << "Trataremos de ser los mas breves y eficientes tratando de explicar como funciona nuestra plataforma" << endl;
		cout << "Para comodidad de nuestros clientes se utilizaran numeros para casi todos los campos a excepcion de los tratamientos y el nombre del cliente" << endl;
		system("pause");
		system("cls");
		cout << "Para agendar una cita se le pedira que rellenar unos campos con informacion, despues se le pedira que introduzca la fecha de la cita" << endl;
		cout << "Para confirmar la fecha los dias de la semana son del 1 al 7, los meses son del 1 al 12 para agendar un lunes 11 de noviembre de pone 1-11" << endl;
		system("pause");
		system("cls");
		cout << "Para modificar/eliminar la cita es dirigiendose al apartado designado del menu" << endl;
		cout << "En el caso de ya tener un diagnostico por parte de un dentista simplemente en la seccion de Tratamiento debera ingresar ya sea los tratamientos disponibles o escribiendo otro" << endl;
		system("pause");
		system("cls");
		cout << "Y con eso concluye el manual de usuario esperamos no haberte hecho leer demasiado como para provocarte fatiga y esperemos que continues con tu registro.\nRecuerda que el folio es primordial para casi todos nuestros servicios.\nEsperamos brindarte un buen servicio, hasta aqui termina nuestra parte" << endl;
		system("pause");
		system("cls");

		do
		{
			system("pause");
			system("cls");
			cout << "Bienvenido, Seleccione que desea hacer" << endl;
			cout << "1-Agendar Cita" << endl;
			cout << "2-Ver Cita" << endl;
			cout << "3-Modificar Cita" << endl;
			cout << "4-Cancelar Cita" << endl;
			cout << "5-guardarclientes Citas" << endl;
			cout << "6-Salir" << endl;
			cin >> accion;
			switch (accion)
			{
			case 1:
			{
				system("cls");
				agendarcita();
				system("pause");
				system("cls");
				cout << "Volveral menu\n1-Si  2-No" << endl;
				cin >> back;
			}break;
			case 2:
			{
				system("cls");
				mostrarcita();
				system("pause");
				system("cls");
				cout << "Volveral menu\n1-Si  2-No" << endl;
				cin >> back;
			}
			break;
			case 3:
			{
				system("cls");
				modificarcita();
				system("pause");
				system("cls");
				cout << "Volveral menu\n1-Si  2-No" << endl;
				cin >> back;

			}
			break;
			case 4:
			{
				system("cls");
				eliminarcita();
				system("pause");
				system("cls");
				cout << "Volveral menu\n1-Si  2-No" << endl;
				cin >> back;
			}
			break;
			case 5:
			{
				system("cls");
				guardarclientes();
				system("pause");
				system("cls");
				cout << "Volveral menu\n1-Si  2-No" << endl;
				cin >> back;
			}
			break;
			case 6:
			{
				return 0;
			}
			break;
			default:
				break;
			}
		} while (back == 1);


	}
	system("pause");
	return 0;
}

void agendarcita()
{
	if (first != NULL) {
		last->next = new cliente;   //aquí preguntamos si inicio es diferente de NULL, de ser cierto e inicio tiene algo dentro, el apuntador fin se deberá
		last = last->next;            //recorrer a la siguiente posición para crear un nuevo producto, hecho esto, fin deberá apuntar a la siguiente posición de la anterior.
	}
	else {
		first = new cliente;           //en caso de que inicio sea igual a NULL inicio deberá crear un nuevo producto en la posición inicial y fin apuntará al 
		last = first;					 //mismo lugar que inicio.
	}
	cout << "\nNombre (sin espacios en blanco): ";
	cin >> last->nombre;
	cout << "\nEdad:" << endl;
	cin >> last->edad;
	cout << "\nTratamiento:" << endl;
	cout << "-Limpieza Dental(1).\n-Brackets.(2)" << endl;
	cout << "-Endodoncia.(3)\n-Implantes dentales.(4)" << endl;
	cout << "-Extraccion de muelas del juicio(5)\n-Empastes-Dentales(6)" << endl;
	cin >> last->tratamiento;
	montototal();
	cout << "\nGenerando codigo de busqueda:" << endl;
	srand(time(NULL));
	printf("%d", rand());
	cout << "\nIngrese el codigo generado:";
	cin >> last->codigo;
	fechadelacita();
	last->next = NULL;
	cout << "Cita confirmada" << endl;
}
void fechadelacita()
{
	system("pause");
	system("cls");

	cout << "Ingrese el numero del dia(1 al 30)\n" << endl;
	cout << "";
	cin >> day;

	cout << "Ingrese el dia de la semana en numero(1 al 7)\n" << endl;
	cout << "";
	cin >> week;

	cout << "Ingrese numero del mes(1 al 12)\n" << endl;
	cout << "";
	cin >> month;
	cout << "Fecha de la cita:" << dw[week - 1] << " " << day << " de " << m[month - 1] << endl;
}
void mostrarcita()
{
	cliente* auxiliar = first;
	if (first == NULL)
	{
		cout << "Sin citas registradas" << endl;
		return;
	}

	while (auxiliar != NULL)
	{
		cout << "\ncliente:" << auxiliar->nombre << endl << "\nEdad:" << auxiliar->edad << endl << "\nFolio de registro:" << auxiliar->codigo << endl << "\nTratamiento por aplicar:" << auxiliar->tratamiento << endl;
		auxiliar = auxiliar->next;

	}

}
void modificarcita()
{
	cliente* auxiliar = first;
	if (first == NULL) {
		cout << "La lista esta vacia." << endl;
		return;
	}
	int clienteeliminar;
	cout << "Digite el folio a modificar" << endl;
	cin >> clienteeliminar;

	while ((auxiliar != NULL) && (auxiliar->codigo != clienteeliminar))
	{
		auxiliar = auxiliar->next;
	}
	cout << "Nombre:" << "(Antes era:" << auxiliar->nombre << ")" << endl;
	cin >> auxiliar->nombre;

	cout << "Edad:" << "(Antes era:" << auxiliar->edad << ")" << endl;
	cin >> auxiliar->edad;

	cout << "Tratamiento:" << "(Antes era:" << auxiliar->tratamiento << ")" << endl;
	cin >> auxiliar->tratamiento;

	fechadelacita();

	cout << "Informacion Actualizada" << endl;
}
void eliminarcita()
{
	cliente* auxiliar = first;
	cliente* anterior = NULL;
	if (first == NULL)
	{
		cout << "Sin clientes registrados" << endl;
		return;
	}
	int citaeliminar;
	cout << "Folio del cliente a eliminar:" << endl;
	cin >> citaeliminar;
	while ((auxiliar != NULL) && (auxiliar->codigo != citaeliminar))
	{
		anterior = auxiliar;
		auxiliar = auxiliar->next;
	}
	if (first == last && auxiliar == first)
	{
		delete auxiliar;
		first = NULL;
		last = NULL;
		cout << "Informacion eliminada Exitosamente" << endl;
		return;
	}
	if (anterior == NULL)
	{
		first = auxiliar->next;
	}
	else
	{
		anterior->next = anterior->next->next;
		if (auxiliar->next == NULL)
		{
			last = anterior;
		}
	}
}
void guardarclientes() {
	cliente* auxiliar = first;

	if (first == NULL) {
		cout << "La lista esta vacia" << endl;
		return;
	}
	char cadena[255];
	cout << "Nombre del archivo:";
	cin >> cadena;
	ofstream escribir;
	escribir.open(cadena, ios::out | ios::binary);
	if (escribir.is_open()) {
		while (auxiliar != NULL) {
			escribir.write(reinterpret_cast<char*>(auxiliar), sizeof(cliente));
			auxiliar = auxiliar->next;
		}
	}
	escribir.close();
	cout << "Guardado exitosamente." << endl << endl;
}
void montototal()
{
	int precio, totalclientes;
	cout << "Vuelva a seleccionar para confirmar el servicio que desea recibir" << endl;
	cin >> last->tratamiento;
	switch (last->tratamiento)
	{
	case 1:
		precio = 350;
		cout << "Limpieza dental" << endl;
		cout << "Descripcion:\nEl objetivo es remover el sarro acumulado de tus dientes para evitar enfermedades que puedan dañarlos a largo plazo\nEsta se realiza en una clínica dental y dura aproximadamente 45 minutos." << endl;
		cout << "Precio:" << precio << endl;
		cout << "Cantidad de clientes a tratar:";
		cin >> totalclientes;
		last->costo = precio * totalclientes;
		cout << "El costo sera de:" << last->costo;
		break;

	case 2:
		precio = 1200;
		cout << "Brackets" << endl;
		cout << "Descripcion:\nson instrumentos utilizados con el objetivo de poder reparar una serie de problemas dentales\nPara corregir los dientes torcidos o volver a la posición normal aquellos que se encuentran mal ubicados." << endl;
		cout << "Precio:" << precio << endl;;
		cout << "Cantidad de clientes a tratar:";
		cin >> totalclientes;
		last->costo = precio * totalclientes;
		cout << "El costo sera de:" << last->costo;
		break;
	case 3:
		precio = 2500;
		cout << "Endodoncia" << endl;
		cout << "Descripcion:\n" << endl;
		cout << "Precio:" << precio << endl;
		cout << "Cantidad de clientes a tratar:";
		cin >> totalclientes;
		last->costo = precio * totalclientes;
		cout << "El costo sera de:" << last->costo;
		break;
	case 4:
		precio = 2800;
		cout << "Implantes Dentales" << endl;
		cout << "Descripcion:\n" << endl;
		cout << "Precio:" << precio << endl;
		cout << "Cantidad de clientes a tratar:";
		cin >> totalclientes;
		last->costo = precio * totalclientes;
		cout << "El costo sera de:" << last->costo;
		break;
	case 5:
		precio = 1500;
		cout << "Extraccion de muelas del juicio" << endl;
		cout << "Descripcion:\n" << endl;
		cout << "Precio:" << precio << endl;
		cout << "Cantidad de clientes a tratar:";
		cin >> totalclientes;
		last->costo = precio * totalclientes;
		cout << "El costo sera de:" << last->costo;
		break;
	case 6:
		precio = 2000;
		cout << "Empastes Dentales" << endl;
		cout << "Descripcion:\n" << endl;
		cout << "Precio:" << precio << endl;
		cout << "Cantidad de clientes a tratar:";
		cin >> totalclientes;
		last->costo = precio * totalclientes;
		cout << "El costo sera de:" << last->costo;
		break;
	default:
		break;
	}
}