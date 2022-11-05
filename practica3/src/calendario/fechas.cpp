/******************************************************************************\
 * Curso de Programación 1. Práctica 3
 * Autores originales: Miguel Ángel Latre y Javier Martínez
 * Modificado por: ¡PON AQUÍ TU NOMBRE! (código de las funciones establecidas en
 *                 la práctica 3)
 * Última revisión: 8 de octubre de 2021
 * Resumen: Fichero de implementación de un módulo «fechas» que ofrece
 *          funciones para trabajar con fechas del calendario
\******************************************************************************/

#include "fechas.hpp"



/*
 * Pre:  La terna de parámetros «dia», «mes» y «agno» definen una fecha
 *       válida del calendario gregoriano, la fecha «dia/mes/agno».
 * Post: El valor del parámetro «f», al ser escrito en base 10, tiene un
 *       formato de ocho dígitos «aaaammdd» que representa
 *       la fecha «dia/mes/agno» donde los dígitos «aaaa» representan el
 *       año de la fecha, los dígitos «mm», el mes y los dígitos «dd», el
 *       día.
 */
void componer(unsigned dia, unsigned mes, unsigned agno,
              unsigned& f) {
    f = agno * 10000 + mes * 100 + dia;
}


/*
 * Pre:  El valor de «f» escrito en base 10 tiene la forma «aaaammdd»
 *       donde los dígitos «aaaa» representan el año de una fecha válida
 *       del calendario gregoriano, los dígitos «mm», el mes y los dígitos
 *       «dd», el día.
 * Post: Los valores de los parámetros «dia», «mes» y «agno» son iguales,
 *       respectivamente, al día, al mes y al año de la fecha «f».
 */
void descomponer(unsigned f,
                 unsigned& dia, unsigned& mes, unsigned& agno) {
    agno = f / 10000;
    f = f % 10000;
    mes = f / 100;
    f = f % 100;
    dia = f;
}


/*
 * Pre:  Los valores de los parámetros «f1» y «f2» escritos en base 10
 *       tienen la forma «aaaammdd», donde los dígitos «aaaa» representan
 *       el año, los dígitos «mm», el mes y los dígitos «dd» el día de
 *       sendas fechas del calendario gregoriano.
 * Post: Devuelve true si y solo si la fecha representada por el valor
 *       del parámetro «f1» es anterior a la representada por «f2».
 */
bool esAnterior(unsigned f1, unsigned f2) {
    if (f1<f2) {
        return true;
    }
    else {
        return false;
    }
}


/*
 * Pre:  agno > 1582.
 * Post: Devuelve true si y solo si el año «agno» es bisiesto de
 *       acuerdo con las reglas del calendario gregoriano.
 */
bool esBisiesto(unsigned agno) {
    bool multiplo4   = (agno %   4 == 0);
    bool multiplo100 = (agno % 100 == 0);
    bool multiplo400 = (agno % 400 == 0);
    return multiplo400 || (multiplo4 && !multiplo100);
}


/*
 * Pre:  1 ≤ mes ≤ 12 y agno > 1582.
 * Post: Devuelve el número de días del mes correspondiente al parámetro «mes»
 *       del año correspondiente al parámetro «agno».
 *       Por ejemplo: diasDelMes(10, 2018) devuelve 31,
 *                    diasDelMes(2, 2018) devuelve 28 y
 *                    diasDelMes(2, 2020) devuelve 29.
 */
unsigned diasDelMes(unsigned mes, unsigned agno) {    
    unsigned diasDelMes;
    bool bisiesto = esBisiesto(agno);
    if (bisiesto && mes==2)
    {    
        diasDelMes=29;
    }
    else if ((mes <= 7 && mes%2==1) || (mes > 7 && mes%2==0))
    {
        diasDelMes=31;
    }
    else if (mes == 2)
    {
        diasDelMes = 28;
    }
    else
    {
        diasDelMes=30;
    }

    return diasDelMes;
}



/*
 * Pre:  agno > 1582.
 * Post: Devuelve el número de días que tiene el año «agno».
 *       Por ejemplo: diasDelAgno(2018) devuelve 365 y
 *                    diasDelAgno(2020) devuelve 366.
 */
unsigned diasDelAgno(unsigned agno) {
    bool bisiesto = esBisiesto(agno);
    if (bisiesto)
    {
        return 366;
    }
    else
    {
        return 365;
    }
    
}


/*
 * Pre:  1 ≤ dia ≤ 31, 1 ≤ mes ≤ 12 y agno > 1582 y la fecha formada por
 *       «dia/mes/agno» es una fecha válida del calendario gregoriano.
 * Post: Devuelve el número de día del año de la fecha formada por
 *       «dia/mes/agno».
 *       Por ejemplo: diaEnElAgno(1, 1, 2019) devuelve 1;
 *                    diaEnElAgno(31, 12, 2018) devuelve 365;
 *                    diaEnElAgno(1, 2, 2019) devuelve 32 y
 *                    diaEnElAgno(31, 12, 2020) devuelve 366.
 */
unsigned diaEnElAgno(unsigned dia, unsigned mes, unsigned agno) {
    unsigned contador = 0;
    for (unsigned i = 1; i < mes; i++)
    {
        contador = contador + diasDelMes(i, agno);
    }
    contador = contador + dia;
    return contador;
}


/*
 * Pre:  1 ≤ dia ≤ 31, 1 ≤ mes ≤ 12, agno > 1582 y la fecha formada por
 *       «dia», «mes» y «agno» representan una fecha válida del calendario
 *       gregoriano.
 * Post: Tras la ejecución de la función, los parámetros «fecha», «dia», «mes» y
 *       «agno» representan la fecha correspondiente al día siguiente al que
 *       representaban al iniciarse la ejecución de la función.
 * 
 *       Por ejemplo, si d, m y a son variables de tipo entero y d = 17, m = 10 y
 *       a = 2019, tras la invocación diaSiguiente(d, m, a) los valores de las
 *       variables serían d = 18, m = 10 y a = 2019.
 *       Si los valores fueran d = 29, m = 2 y a = 2020, tras la invocación
 *       diaSiguiente(d, m, a) los valores serían d = 1, m = 3 y a = 2020.
 *       Si los valores fueran d = 31, m = 12 y a = 2022, tras la invocación
 *       diaSiguiente(d, m, a) los valores serían d = 1, m = 1 y a = 2023.
 */
void diaSiguiente(unsigned& dia, unsigned& mes, unsigned& agno) {
    if (dia+1 != diasDelMes(mes, agno))
    {
        dia = (dia+1)%diasDelMes(mes, agno);
    }
    else
    {
        dia = dia + 1;
    }
    if (dia == 1)
    {
        if (mes+1 != 12)
        {
            mes = (mes+1)%12;
        }
        else
        {
            mes = mes + 1;
        }
    }
    if (mes == 1)
    {
        agno = agno + 1;
    }
}


/*
 * Pre:  Los valores de los parámetros «dia», «mes» y «agno» representan
 *       conjuntamente una fecha válida del calendario gregoriano igual o
 *       posterior al 1 de enero de 1900.
 * Post: Devuelve un entero que codifica el día de la semana de la fecha
 *       representada por los valores de los parámetros «dia», «mes» y «agno», de
 *       acuerdo con la siguiente codificación: el 0 codifica el lunes, el 1
 *       codifica martes y así sucesivamente hasta el 6, que codifica el domingo.
 */
unsigned diaDeLaSemana(unsigned dia, unsigned mes, unsigned agno) {
    unsigned contador = 0;
    unsigned aux = AGNO_INICIAL;
    while (aux < agno)
    {   
        contador = contador + diasDelAgno(aux);
        aux++;
    }

    contador = contador + diaEnElAgno(dia, mes, agno);
    return (contador-1)%7;
}
