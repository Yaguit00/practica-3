#include <iostream>
#include <iomanip>
using namespace std;
const unsigned noBisiesto = 365;
const unsigned bisiesto = 366;


/*
Funcion que se encarga de pedir los datos a el usuario,
asegura su corrección, y permite que se usen devolviendolos
tras su ejecución
*/


/*
Pre: valores

Post: Devolverá dos valores, el año y el mes, que usaré dentro
de la funcion calendario para conseguir saber que mes y que
año son los que tengo que usar para el calendario
*/




void pedirDatos(unsigned& mes, unsigned& ano) {

    cout << "Introduzca el mes [1-12]: ";
    
    cin >> mes;
   
    while (0 > mes || 12 < mes) {

        cout << "El mes debe estar comprendido entre 1 y 12: ";
        cin >> mes;

    }

    cout << "Introduzca un año igual o posterior a 1900: ";
    
    cin >> ano;

    while (ano < 1900) {

        cout << "Introduzca un año igual o posterior a 1900: ";
        cin >> ano;

    }

}



/*
Funcion que comprueba si un año es bisiesto o no. Para
ser bisiesto, un año debe ser multiplo de 4, pero no de 100, excepto los de 400
*/


/*
Pre: un año del que se quiere comprobar si es bisiesto. Debe ser un año valido

Post: Devolverá un valor booleano, dependiendo de si el año es en efecto bisiesto
o no lo se
*/


bool esBisiesto(unsigned ano) {

    if (ano % 400 == 0) {

        return true;

    }
    else if (ano % 100 == 0) {

        return false;

    }
    else if (ano % 4 == 0) {

        return true;

    }
    else {

        return false;

    }

}









/* 
funcion que, dados un mes y un año, me dirá cuantos
dias tiene ese mes

*/
unsigned diasDelMes(unsigned mes, unsigned ano) {
    
    unsigned diasDelMes;
    

    if (esBisiesto(ano) == true)
    {
        if (mes = 2)
            {

                diasDelMes=29;

            }

    }
    else if (esBisiesto(ano) == false)
    {

        if (mes = 2)
        {

            diasDelMes = 28;

        }

    }
    else if (mes <= 7)
        {
            if (mes%2 == 1)
            {

                diasDelMes=31;

            }
        }
    else if (mes > 7)
        {
            if (mes%2 == 0)
            {
            
                diasDelMes=31;

            }
        }
    else
            {

                diasDelMes=30;

            }
                
        

    return diasDelMes;

}




/* 
funcion que devuelve que dia de la semana será el primero del mes

*/
unsigned diaDeLaSemana(unsigned mes, unsigned ano) {

// diasquehanpasado modulo 7

    unsigned contador = 0;
    unsigned anoMin = 1900;

    while (anoMin < ano)
    {
    
        if (esBisiesto(ano))
        {

            contador = contador + bisiesto;

        }
        else
        {

            contador = contador + noBisiesto;

        }

        anoMin++;

    }

    unsigned i = 1;
    while (i < mes)
    {
        contador = contador + diasDelMes(i, ano);
        i++;
    }

    unsigned diaqueempieza = contador%7;
    return diaqueempieza;

}









/*
Pre: valores validos (0 < mes < 13, 1899 < ano)

Post: cabecera de el calendario
*/

// función que se encarga de imprimir la cabecera del calendario

void escribirCabecera(unsigned mes, unsigned ano) {

    // Se encarga de imprimir el año y el mes a la derecha
    unsigned width = 28;

    cout <<  right << setw(width-2) << ano 
    << " " << mes << endl;

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
Funcion que se encarga de escribir el calendario, dado
un mes valido y un año valido
*/

/*
Pre: Mes y dato, siendo el mes comprendido entre 1 y 12,
y el año mayor que 1900.

Post: Devuelve un calendario escrito correctamente
*/


void escribirCalendario(unsigned mes, unsigned ano) 
{

   
    escribirCabecera(mes, ano);

    cout << endl;

    unsigned dia = diaDeLaSemana(mes, ano);
    unsigned i = 1;

    while (i <= diasDelMes(mes, ano))
    {

        cout << setw(4) << i;

        while (dia%8==1)
        {

            cout << endl;
            dia++;
        }

        i++;
        dia++;
        

    }

}







/*
Programa que pide al usuario un mes y un año, asegura
su validez (dentro de los parametros del programa) y 
escribe en pantalla el calendario de al mismo.
*/

int main () {
    unsigned mes, ano;
    pedirDatos(mes, ano);
    escribirCalendario(mes, ano);
    return 0;
    
}