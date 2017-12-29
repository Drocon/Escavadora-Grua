#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <cstdlib>
using namespace std;
#include <Windows.h>

//	**************** CONSTANTES  ****************
const int MAX_PROD = 25;
const int PROD_NULO = 0;
const int CENTINELA = -1;
const int AUX = MAX_PROD;

typedef int tArray[MAX_PROD];
typedef int tAux[AUX];


//	********************** FUNCIOONES **********************

//	**************** VERSION 1.0 ****************
//Manejo de filas
void mostrarFila(const tArray fila, int tam);
/*
Muestra por pantalla en el formato acorcado, el contenido del array lista.
	Entrada: El array y el tamaño del array.
	Salida: La visualización del array.
*/

bool esPosValida(int tam, int pos);
/*
Comprueba si la posición es valida o no.
	Entrada: El tamaño del array y la posición.
	Salida: Un booleano con TRUE o FALSE sobre si es valida la posición.
*/

bool estaVacia(const tArray fila, int pos);
/*
Comprueba si una posición del array esta vacia.
	Entrada: El array y la posición.
	Salida: Un booleano con TRUE o FALSE viendo si esta vacia la posicion.
*/

//Manejo de ficheros
void leerFilaFich(ifstream &fich, tArray fila, int &tam);
/*
En un fichero .txt abierto, carga su contenido en el array.
	Entrada: Un fichero valido abierto, el array y el tamaño del array.
	Salida: Actualizar el array.
*/

void escribirFilaFich(ofstream &fich, const tArray fila, int tam);
/*
Guarda en un fichero .txt el contenido del array lista.
	Entrada: Un fichero, el array y el tamaño del array.
	Salida: Guardar en un fichero la información del array.
*/

//Metodos de grua
bool esPosibleGrua1Entre(const tArray fila, int tam, int posIni, int posSoltar);
/*
Comprueba si es posible mover posIni a posSoltar.
	Entrada: El array con su tamaño, y ambas posiciones a tratar.
	Salida: Si es posible o no mover la posición.
*/

bool grua1Elemento(tArray fila, int tam, int posIni, int posSoltar);
/*
Siendo posibel el movimiento de mover posIni a posSoltar, lo realiza.
	Entrada: El array con su tamaño, y ambas posiciones a tratar.
	Salida: Movimiento realizado o no.
*/

//Metodos de escavacion
int posHuecoLibreDerecha(const tArray fila, int tam, int posIni);
/*
Muestra la posición en el array desde un punto inicial donde hay un hueco libre.
	Entrada: El array con su tamaño y la posicion inicial.
	Salida: La posicion hacia su derecha que se encuentra vacia.
*/

bool excavadora1Derecha(tArray fila, int tam, int posIni);
/*
Comprueba que se pueda mover hacia la derecha una posicion en el array. Tiene en cuenta que 
si hay dos numero juntos, tiene que mover ambos. Tambien, no puede salirse por la derecha 
del tamaño del array.
	Entrada: El array, su tamaño y la posicionicial.
	Salida: Si se puede mover o no a la derecha.
*/

//Menu
int menu();
/*
Menu de la aplicación.
	Entrada: Opcion del case.
	Salida: Case seleccionado.
*/

void ejecutarLeerFichero(tArray fila, int &tam);
/*
Realiza todas las tareas para leer un fichero .txt y guardar su contenido en el array.
	Entrada: El array y su tamaño.
	Salida: El array cargado con la información del fichero.
*/

void ejecutarGuardarFichero(const tArray fila, int tam);
/*
Realiza las tareas para guardar en un fichero .txt la informacion que haya en el array.
	Entrada: El array con su tamaño.
	Salida: Creado un .txt con la informacion del array.
*/

void ejecutarGrua(tArray fila, int tam);
/*
Realiza el movimiento de una posicion valida a otra posicion vacia del numero de ella. La
posicion inicial se vuelve 0 tras movimiento valido.
	Entrada: El array y su tamaño.
	Salida: Las posiciones del array actualizadas.
*/

void ejecutarExcavadora(tArray fila, int tam);
/*
Realiza el desplazamiento de una posicion del array a la derecha. Comprueba que haya 
posiciones vacias a su derecha. Si esta ocupada, tambien se mueve.
	Entrada: El array y su tamaño.
	Salida: La realizacion del movimiento y la actualizacion del array.

********************************** ACTUALIZACION ************************************

Realiza el desplazamiento de una posicion del array a la derecha o a la izquierda, segun
quiera el usuario. Comprueba que haya posiciones vacias al lado designado. Si esta 
ocupada, tambien se mueve.
	Entrada: El array y su tamaño.
	Salida: La realizacion del movimiento y la actualizacion del array.
*/

void ejecutarOpc(int opc, tArray fila, int &tam);
/*
Le pasa una opcion escogida y se lleva a cabo esa parte del menu().
	Entrada: El array y su tamaño, con la opcion del menu.
	Salida: El case que corresponda con la opcion.
*/

int posHuecoLibreDir(const tArray fila, int tam, int posIni, int direccion);
/*
Muestra la posición en el array desde un punto inicial donde hay un hueco libre, teniendo
en cuenta la direccion.
	Entrada: El array con su tamaño y la posicion inicial.
	Salida: La posicion hacia una direccion que se encuentra vacia.
*/

bool excavadora1Dir(tArray fila, int tam, int posIni, int direccion);
/*
Comprueba que se pueda mover hacia la derecha o la izquierda una posicion en el 
array. Tiene en cuenta que si hay dos numero juntos, tiene que mover ambos. 
Tambien, no puede salirse por la derecha o la izquerda del tamaño del array.
	Entrada: El array, su tamaño y la posicionicial.
	Salida: Si se puede mover o no a la derecha o la izquierda.
*/

//	**************** VERSION 2.0 ****************
//Metodos de grua
bool sonPosicionesPosibles(int tam, int posIni, int posFin, int posSoltar);
/*
Comprueba que tanto la posicion inicial como la final es posible. Tambien comprueba
la posicion que se van a soltar y en la cual va a terminar de soltarse, pero no mira
las posiciones intermedias.
	Entrada: El tamaño del array, y las posiciones inicial, final y la posicion a soltar.
	Salida:  Un booleano a TRUE si es cierto todas la condiciones descritas.
*/

bool esPosibleGrua(const tArray fila, int tam, int posIni, int posFin, int posSoltar);
/*
Comprueba si se puede llevar a cabo el movimiento de la grua, pasando por todas las 
posiciones de las posiciones desde la posicion a soltar hasta donde termina a soltar.
	Entrada: El array con su tamaño, la posicion inicial a coger, la final a coger
		y la posicion a soltar la grua.
	Salida: Un booleano a TRUE si es posible realizar el movimiento.
*/

bool grua(tArray fila, int tam, int posIni, int posFin, int posSoltar);
/*
Comprueba si puede cargar en un array auxiliar los datos a mover con la grua; poniendo 
a 0 los valores en el tArray, y carga los datos en la posicion nueva habiendo antes 
comprobado si es posible realizar el movimiento de la grua.
	Entrada: El array con su tamaño, la posicion inicial a coger, la final a coger
		y la posicion a soltar la grua.
	Salida: El Array con sus posiciones actualizadas y con un booleano indicando que 
		se ha podido llevar a cabo esta accion.
*/

//Metodos de excavadora
bool excavadora(tArray fila, int tam, int posIni, int numDespla, int direccion);
/*
Comprueba si se puede realizar un movimiento lateral de varios desplazamientos a la
derecha o a la izquierda (segun introduzca el usuario). Tiene en cuenta no salirse del
tamaño maximo del array por ambos lados y que al moverse se llevara consigo elementos 
que se vaya encontrando hasta que deje de realizar el desplazamiento.
	Entrada: El array con su tamaño, la posicion inicial del desplazamiento, el numero
		total de desplazamientos y la direccion hacia donde va a ir dirigido.
	Salida: El array actualizado con sus nuevas posiciones y un booleano que dice que ha
		sido posible realizar el movimiento.
*/

//	**************** VERSION 3.0 ****************
bool filaOrdenada(tArray fila, int tam);
/*
Comprueba que el contenido que hay en el Array esta ordenado. Hace caso omiso a los huecos 
vacios. 
	Entrada: el array y su tamaño.
	Salida: Un booleano de si esta ordenado.
*/


//	********************** PROGRAMA **********************
int main() {
	int opcion = -1;
	int tam = 0;
	int contador = 0;
	tArray fila;
	bool orden;

	while (opcion != 0) {

		opcion = menu();
		ejecutarOpc(opcion, fila, tam);

		if (opcion == 1) {
			contador = 0;
			cout << endl;
			cout << " *************************************" << endl;
			cout << " *******                       *******" << endl;
			cout << " ******* MOVIMIENTOS RESETADOS *******" << endl;
			cout << " *******                       *******" << endl;
			cout << " *************************************" << endl;
			cout << endl;
			system("pause");
			system("cls");
		}
		else if (opcion == 3 || opcion == 4) {
			contador++;

			orden = filaOrdenada(fila, tam);
			if (orden) {
				cout << endl;
				cout << " **************************************************" << endl;
				cout << " *** LA FILA ESTA ORDENADA Y EN " << contador << " MOVIMIENTOS   ***" << endl;
				cout << " **************************************************" << endl;
				cout << endl;
				system("pause");
				system("cls");
			}
			else {
				cout << endl;
				cout << " ***********************************" << endl;
				cout << " ***  MOVIMIENTOS REALIZADOS: " << contador << "  ***"<< endl;
				cout << " ***********************************" << endl;
				cout << endl;
				system("pause");
				system("cls");
			}
		}
	}

	return 0;
}

//	**************** VERSION 1.0 ****************
//Metodos de manejo de filas
void mostrarFila(const tArray fila, int tam) {
	int i;

	cout << " ";
	for (i = 0; i < tam; i++) {
		if (esPosValida(tam, i)) {
			if (!estaVacia(fila, i)) {
				if (fila[i] >= 10) {
					cout << "|" << fila[i];
				}
				else {
					cout << "| " << fila[i];
				}
			}
			else{
				cout << "|  ";
			}
		}
	}
	cout << "|" << endl;

	cout << " ";
	for (i = 0; i <tam; i++) {
		cout << "---";
	}
	cout << "-" << endl;

	cout << " ";
	for (i = 0; i < tam; i++) {
		cout << "|";
		if (i < 10) {
			cout << " ";
		}
		cout << i;
	}
	cout << "|" << endl;

}

bool esPosValida(int tam, int pos) {
	return pos < tam;
}

bool estaVacia(const tArray fila, int pos) {
	return fila[pos] == PROD_NULO;
}

//Metodos de manejo de ficheros
void leerFilaFich(ifstream &fich, tArray fila, int &tam) {
	string nombre;

	cout << endl;
	cout << " *******************************************" << endl;
	cout << " *NOMBRE DEL FICHERO A ABRIR: ";
	cin >> nombre;
	cout << " *******************************************" << endl;
	nombre = nombre + ".txt";
	tam = 0;
	fich.open(nombre);
	if (fich.is_open()) {
		fich >> fila[tam++];
		while(tam <= MAX_PROD && fila[tam-1] != CENTINELA) {
			fich >> fila[tam];
			tam++;
		}
		tam--;
	}
	else {
		cout << endl;
		cout << " **************************************" << endl;
		cout << " *El archivo no se ha podido encontrar*" << endl;
		cout << " **************************************" << endl;
	}
	fich.close();
}

void escribirFilaFich(ofstream &fich, const tArray fila, int tam) {
	string nombre;
	int i;

	cout << endl;
	cout << " *******************************************" << endl;
	cout << " *NOMBRE DEL FICHERO A ESCRIBIR: ";
	cin >> nombre;
	cout << " *******************************************" << endl;
	nombre = nombre + ".txt";
	fich.open(nombre);
	for (i = 0; i < tam; i++) {
		fich << fila[i] << " ";
	}
	fich << -1;
	fich.close();
}

//Metodos de grua
bool esPosibleGrua1Entre(const tArray fila, int tam, int posIni, int posSoltar) {
	return esPosValida(tam, posIni) && esPosValida(tam, posSoltar) && estaVacia(fila, posSoltar);
}

bool grua1Elemento(tArray fila, int tam, int posIni, int posSoltar) {
	bool realizado = false;

	if (esPosibleGrua1Entre(fila, tam, posIni, posSoltar)) {
		fila[posSoltar] = fila[posIni];
		fila[posIni] = PROD_NULO;
		realizado = true;
	}
	else {
		cout << endl;
		cout << "****************************************" << endl;
		cout << "-No se ha podido realizar el movimiento- " << endl;
		cout << "****************************************" << endl;
	}

	return realizado;
}

//Metodos de excavadora
int posHuecoLibreDerecha(const tArray fila, int tam, int posIni) {
	int num = posIni;

	while (!estaVacia(fila, num) && num < tam) {
		num++;
	}

	return num;
}

bool excavadora1Derecha(tArray fila, int tam, int posIni) {
	bool mover = false;
	int pos;

	pos = posHuecoLibreDerecha(fila, tam, posIni);
	
	if (pos+1 < tam) {
		while (pos >= posIni) {
			fila[pos] = fila[pos - 1];
			pos--;
			mover = true;
		}
		fila[posIni] = 0;
	}
	return mover;
}

int menu() {
	int op = -1;

	while ((op < 0) || (op > 4)) {
		cout << endl;
		cout << " **************************************************************** " << endl;;
		cout << " ******  Practica 2: Al ladrillo con excavadora y grua **********" << endl;
		cout << " *	  1.- Cargar fila de fichero.				*" << endl;
		cout << " *	  2.- Guardar fila en fichero.		   		*" << endl;
		cout << " *	  3.- Usar grua.					*" << endl;
		cout << " *	  4.- Usar excavadora.					*" << endl;
		cout << " *	  0 - Salir.						*" << endl;
		cout << " **************************************************************** " << endl;;
		cout << " ****************************************************************" << endl;;
		cout << " ** Opcion: ";
		cin >> op;

		
		if ((op < 0) || (op > 4)) {
			cout << "¡Opcion no valida!" << endl;
		}
		system("cls");
	}

	return op;
}

void ejecutarLeerFichero(tArray fila, int &tam) {
	ifstream fin;
	
	leerFilaFich(fin, fila, tam);
	cout << endl;
	if (tam != 0) {
		mostrarFila(fila, tam);
	}
}

void ejecutarGuardarFichero(const tArray fila, int tam) {
	ofstream fout;
	
	escribirFilaFich(fout, fila, tam);
	cout << endl;
	mostrarFila(fila, tam);
}

void ejecutarGrua(tArray fila, int tam) {
	int posInicial, posFinal, posSoltar;
	
	cout << endl;
	mostrarFila(fila, tam);
	cout << endl;
	cout << " ************************************************" << endl;
	cout << " *POSICION INICIAL A LEVANTAR (0 hasta " << tam - 1 << "): "; 
	cin >> posInicial;
	cout << " *POSICION FINAL A LEVANTAR (" << posInicial << " hasta " << tam - 1 << "): "; 
	cin >> posFinal;
	cout << " *POSICION A SOLTAR (0 hasta " << tam - 1 << "): ";
	cin >> posSoltar;
	cout << " ************************************************" << endl;

	grua(fila, tam, posInicial, posFinal, posSoltar);

	cout << endl;
	mostrarFila(fila, tam);
}

void ejecutarExcavadora(tArray fila, int tam) {
	int posIni, direc, numDespla;
	
	cout << endl;
	mostrarFila(fila, tam);
	cout << endl;
	cout << " ************************************************" << endl;
	cout << " *POSICION INICIAL A MOVER (0 hasta " << tam - 1 << "): ";
	cin >> posIni;
	cout << " *POSICIONES A DESPLAZAR: ";
	cin >> numDespla;
	cout << " *DERECHA O IZQUIERDA ( 1 -> Derecha // -1 -> Izquierda): ";
	cin >> direc;
	cout << " ************************************************" << endl;

	excavadora(fila, tam, posIni, numDespla, direc);
}

void ejecutarOpc(int opc, tArray fila, int &tam) {
	switch (opc) {
	case 1:
		ejecutarLeerFichero(fila, tam);

		break;
	case 2:
		ejecutarGuardarFichero(fila, tam);

		system("pause");
		system("cls");
		break;
	case 3:
		ejecutarGrua(fila, tam);

		break;
	case 4:
		ejecutarExcavadora(fila, tam);

		break;
	}
}

int posHuecoLibreDir(const tArray fila, int tam, int posIni, int direccion) {
	int num = posIni;

	while (!estaVacia(fila, num) && num < tam) {
		if (direccion == 1) {
			num++;
		}
		else if (direccion == -1) {
			num--;
		}
	}

	return num;
}

bool excavadora1Dir(tArray fila, int tam, int posIni, int direccion) {
	bool mover = false;
	int pos;

	pos = posHuecoLibreDir(fila, tam, posIni, direccion);

	if (direccion == 1) {
		if (pos + 1 < tam) {
			while (pos >= posIni) {
				fila[pos] = fila[pos - 1];
				pos--;
				mover = true;
			}
			fila[posIni] = 0;
		}
	}
	else if (direccion == -1) {
		if (pos >=0) {
			while (pos <= posIni) {
				fila[pos] = fila[pos + 1];
				pos++;
				mover = true;
			}
			fila[posIni] = 0;
		}
	}

	return mover;
}

//	**************** VERSION 2.0 ****************
//Metodos de grua
bool sonPosicionesPosibles(int tam, int posIni, int posFin, int posSoltar) {
	return posIni <= posFin && esPosValida(tam, posIni) && esPosValida(tam, posFin) 
		&& esPosValida(tam, posSoltar) && esPosValida(tam, posSoltar + (posFin - posIni));
}

bool esPosibleGrua(const tArray fila, int tam, int posIni, int posFin, int posSoltar) {
	int ini, num, pIni;
	bool ok;

	ok = sonPosicionesPosibles(tam, posIni, posFin, posSoltar);

	pIni = posIni;
	ini = posSoltar;
	num = posSoltar + (posFin - posIni);
	while (ok && ini<num) {
		if (fila[pIni] != PROD_NULO) {
			if (fila[ini] != PROD_NULO && posFin!=posSoltar) {
				ok = false;
			}
			else {
				ok = true;
			}
		}
		pIni++;
		ini++;
	}

	return ok;
}

bool grua(tArray fila, int tam, int posIni, int posFin, int posSoltar) {
	int pIni, pFin, posFinalSoltar, pSoltar;
	int posAux = 0;
	bool valido;
	tAux auxiliar;

	pIni = posIni;
	pFin = posFin;
	posFinalSoltar = posSoltar + (posFin - posIni);
	valido = esPosibleGrua(fila, tam, posIni, posFin, posSoltar);

	if (valido) {
		while (pIni <= pFin) {
			auxiliar[posAux++] = fila[pIni];
			fila[pIni] = PROD_NULO;
			pIni++;
		}
		
		posAux = 0;
		for (pSoltar = posSoltar; pSoltar <= posFinalSoltar; pSoltar++) {
			if (fila[pSoltar] == PROD_NULO) {
				fila[pSoltar] = auxiliar[posAux];
				auxiliar[posAux] = PROD_NULO;
			}
			posAux++;
		}

	}
	else {
		cout << endl;
		cout << "****************************************" << endl;
		cout << "-No se ha podido realizar el movimiento- " << endl;
		cout << "****************************************" << endl;
	}

	return valido;
}

//Metodos de excavadora
bool excavadora(tArray fila, int tam, int posIni, int numDespla, int direccion) {
	bool mover = false;
	int pos, pIni;
	int i = 0;
	int tiempo = 100;
	
	pIni = posIni;

	while (i < numDespla) {
		pos = posHuecoLibreDir(fila, tam, pIni, direccion);

		if (direccion == 1) {
			if (pos + 1 <=tam) {
				while (pos >= pIni) {
					fila[pos] = fila[pos - 1];
					pos--;
					mover = true;
				}
				fila[pIni] = 0;
			}
			pIni++;
		}
		else if (direccion == -1) {
			if (pos >= 0) {
				while (pos < pIni) {
					fila[pos] = fila[pos + 1];
					pos++;
					mover = true;
				}
				fila[pIni] = 0;
			}
			pIni--;
		}
		i++;

		if (MAX_PROD != pos && pos >= -1) {
			system("cls");
			cout << endl;
			mostrarFila(fila, tam);
			Sleep(tiempo);
		}
	}

	return mover;
}

//	**************** VERSION 3.0 ****************
bool filaOrdenada(tArray fila, int tam) {
	bool orden = true;
	int i = 0;
	int aux = 0;

	while (i < tam && orden) {
		if (fila[i] != PROD_NULO) {
			if (fila[i]>aux) {
				aux = fila[i];
				orden = true;
			}
			else {
				orden = false;
			}
		}
		i++;
	}

	return orden;
}