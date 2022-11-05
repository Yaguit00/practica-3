/******************************************************************************\
 * Curso de Programación 1. Práctica 3
 * Autores: Yago Torres García
 * Última revisión: 03 noviembre 2022
 * Resumen: Programa que escribe en la pantalla el calendario de un determinado
 *          mes de un año, que se solicitan al usuario. El programa se asegura 
 *          de que el mes introducido está comprendido entre 1 y 12 y de que el 
 *          año es igual o posterior a 1900.
 *          Clase de problemas correspondiente al tema 7 (diseño modular y
 *          descendente) y 3ª práctica.
 * Nota: Leer el fichero README.md, que contiene instrucciones para su 
 *       compilación y ejecución.
\******************************************************************************/
#include <iostream>
#include <string>
#include <iomanip>
#include "fechas.hpp"
using namespace std;

/*
 * Pre:  1 ≤ mes ≤ 12
 * Post: Ha escrito en la pantalla el nombre (en mayúsculas) del mes
 *       correspondiente al valor del parámetro «mes».
 * Nota: Este código lo podrás comprender adecuadamente cuando hayamos visto
 *       los temas 9 (vectores) y 10 (cadenas de caracteres).
 */
void escribirNombreMes(unsigned mes) 
{
    const string NOMBRES_MES[12] = { "ENERO",
            "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO", "JULIO", "AGOSTO",
            "SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE", "DICIEMBRE" };
    cout << right << NOMBRES_MES[mes - 1];
}


/*
 * Pre : --
 * Post : Guarda los datos "mes" y "agno" introducidos por el usuario, siempre 
 * que estos sean válidos. En otro caso, volverá a solicitar los datos, hasta
 * que estos sean correctos.
 */
void pedirDatos(unsigned& mes, unsigned& agno) 
{

    cout << "Introduzca el mes [1-12]: ";  
    cin >> mes;

    while (0 >= mes || 12 < mes) 
    {
        cout << "El mes debe estar comprendido entre 1 y 12: ";
        cin >> mes;
    }

    cout << "Introduzca un año igual o posterior a 1900: ";
    cin >> agno;

    while (agno < 1900) 
    {
        cout << "Introduzca un año igual o posterior a 1900: ";
        cin >> agno;
    }

}

/*
 * Pre : recibe datos válidos. 
 * Post : Devuelve la cabecera del calendario en formato correcto,
 * con el mes y año adecuados.
 */

void escribirCabecera(unsigned mes, unsigned agno) {

    // Se encarga de imprimir el año y el mes a la derecha

    unsigned width = 28;
    cout << setw(width-5) << right;
    escribirNombreMes(mes);
    cout << " " << agno << endl;
    
    // Se encarga de colocar las iniciales de los días

    cout << setw(4) << 'L' 
    << setw(4) << 'M'  
    << setw(4) << 'X'  
    << setw(4) << 'J' 
    << setw(4) << 'V' 
    << setw(4) << 'S' 
    << setw(4) << 'D' 
    << endl;

    // Se encarga de separar la cabecera de los números

    unsigned i = 0;
    for (unsigned i = 0; i < width; i++) {
        cout << "-";
    }
}


/* 
 * Pre : Recibe un mes y año válidos.
 * Post : Devuelve los números del calendario escritos correctamente,
 * con el día 1 colocado donde le corresponda ese mes.
 */
void escribirCalendario(unsigned mes, unsigned agno) 
{
    escribirCabecera(mes, agno);
    cout << endl;

    unsigned dia = diaDeLaSemana(1, mes, agno) + 1;
    for (unsigned i = 1; i < dia; i++)
    {
        cout << "    ";
    }
    
    unsigned j = 1;
    while (j <= diasDelMes(mes, agno))
    {
        cout << setw(4) << j;

        if (dia%7 == 0)
        {
            cout << endl;
            dia = 0;
        }
        j++;
        dia++;
    }

}


/*
 * Pre : --
 * Post : La función main del programa, llamará a pedir datos para
 * recibir datos adecuados, y estos datos son los que se usarán como
 * parámetros para la función escribirCalendario, que devuelve el 
 * calendario escrito de manera correcta, del mes y año especificados.
 */
int main() {
    unsigned mes, agno;
    pedirDatos(mes, agno);
    escribirCalendario(mes, agno);
    return 0;
}
