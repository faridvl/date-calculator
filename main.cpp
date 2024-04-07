// Proyecto Fundamentos Moisés y Geremias.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
#include <iostream>
#include <iostream>
using namespace std;

bool isLeapYear(int day, int month, int year)
{
    int febraryMonthNumber = 2;
    int maxDaysWithoutLeapYear = 28;
    int maxDaysInLeapYear = 29;

    // Comprobar si el año es bisiesto
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        // Si el año es bisiesto, verificar que no tenga más de 29 días
        if (month == 2 && day > 29)
        {
            cout << "El día ingresado es inválido para un año bisiesto." << endl;
            return false;
        }
    }
    else // Si no es bisiesto
    {
        // Verificar que febrero no tenga más de 28 días
        if (month == 2 && day > 28)
        {
            cout << "El día ingresado es inválido para un año no bisiesto." << endl;
            return false;
        }
    }

    return true;
}

// Mostrar diferecnia o igualdad de fechas
// Verificar si hay coherencia en la funcion
int daysInMonth(int year, int month)
{
    if (month == 2)
    {
        // Check for leap year
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            return 29; // Leap year
        }
        else
        {
            return 28; // Non-leap year
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return 30; // April, June, September, November
    }
    else
    {
        return 31; // January, March, May, July, August, October, December
    }
}

// TBD: VERIFY THIS FUNCTION
int datesDifference(int year1, int month1, int day1, int year2, int month2, int day2)
{
    int date1 = year1 * 365 + day1;
    for (int m = 1; m < month1; ++m)
    {
        date1 += daysInMonth(year1, m);
    }

    int date2 = year2 * 365 + day2;
    for (int m = 1; m < month2; ++m)
    {
        date2 += daysInMonth(year2, m);
    }

    if (date1 > date2)
    {
        cout << "La fecha mayor es " << date1 << endl;
        cout << "La fecha menor es " << date2 << endl;
    }
    else if (date1 < date2)
    {
        cout << "La fecha menor es " << date1 << endl;
        cout << "La fecha mayor es " << date2 << endl;
    }
    else
    {
        cout << "Las fechas son iguales." << endl;
    }
    return abs(date1 - date2);
}

// Suma y resta de ambas fechas
// Verificar si hay coherencia en la funcion
int addOrSubtractDates(int year1, int month1, int day1, int year2, int month2, int day2, bool subtract = false)
{
    // Calcular el número total de días desde una fecha base (1 de enero de 1970)
    // para ambas fechas
    int date1 = year1 * 365 + day1;
    for (int m = 1; m < month1; ++m)
    {
        date1 += daysInMonth(year1, m);
    }

    int date2 = year2 * 365 + day2;
    for (int m = 1; m < month2; ++m)
    {
        date2 += daysInMonth(year2, m);
    }

    // Si se solicita la resta, cambiamos el signo de la segunda fecha
    if (subtract)
    {
        date2 = -date2;
    }

    // Sumar o restar las fechas y devolver el resultado
    return date1 + date2;
}

bool isDigit(char c)
{
    return (c >= '0' && c <= '9');
}

bool isValidDate(string date)
{

    int day = 0, month = 0, year = 0;
    int contador = 0;
    int indice = 0;

    // Leer día
    while (isDigit(date[indice]))
    {
        day = day * 10 + (date[indice] - '0');
        indice++;
        contador++;
    }

    // Si el caracter actual no es una barra, la fecha no es válida
    if (date[indice] != '/')
    {
        return false;
    }

    // Si no se ha leído ningún dígito para el día, la fecha no es válida
    if (contador == 0)
    {
        return false;
    }

    indice++;
    contador = 0;

    // Leer mes
    while (isDigit(date[indice]))
    {
        month = month * 10 + (date[indice] - '0');
        indice++;
        contador++;
    }

    // Si el caracter actual no es una barra, la fecha no es válida
    if (date[indice] != '/')
    {
        return false;
    }

    // Si no se ha leído ningún dígito para el mes, la fecha no es válida
    if (contador == 0)
    {
        return false;
    }

    indice++;
    contador = 0;

    // Leer año
    while (isDigit(date[indice]))
    {
        year = year * 10 + (date[indice] - '0');
        indice++;
        contador++;
    }

    // Si se leyeron menos de 4 dígitos para el año, la fecha no es válida
    if (contador != 2 && contador != 4)
    {
        return false;
    }

    // Verificar si los valores están dentro de rangos válidos
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 0)
    {
        return false;
    }

    // Verificar si el mes tiene 30 días
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    {
        return false;
    }

    // Verificar si el mes es febrero y el año es bisiesto
    if (month == 2)
    {
        return isLeapYear(day, month, year);
    }

    return true;
}

void clearConsole()
{
    system("cls");
}

#include <iostream>
#include <string>
#include <sstream>

std::string formatDates(std::string date)
{
    // Variables para almacenar los valores de día, mes y año
    int day = 0, month = 0, year = 0;

    // Extraer día, mes y año de la cadena de fecha
    sscanf(date.c_str(), "%d/%d/%d", &day, &month, &year);

    // Array de nombres de meses
    std::string monthNames[12] = {
        "enero", "febrero", "marzo", "abril", "mayo", "junio",
        "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};

    // Crear una cadena para almacenar la fecha formateada
    std::string formattedDate;

    // Ajustar el día
    if (day < 10)
    {
        formattedDate += "0";
    }
    formattedDate += std::to_string(day) + "/";

    // Añadir el nombre del mes
    formattedDate += monthNames[month - 1] + "/";

    // Ajustar el año
    if (year < 100)
    {
        formattedDate += "20";
    }
    formattedDate += std::to_string(year);

    // Devolver la fecha formateada
    return formattedDate;
}

int main()
{
    system("chcp 65001"); // Configurar la codificación de la consola a UTF-8 (solo para Windows)

    string firstDate,
        secondDate;

    // Solicitar la primera fecha al usuario
    cout << "Ingrese la primera fecha (en formato dd/mm/aaaa): ";
    getline(cin, firstDate);

    // Validar que la primera fecha tenga el formato correcto y que solo contenga dígitos
    while (/* !contieneSoloDigitos(fecha1) ||  */ !isValidDate(firstDate))
    {
        system("cls");
        cout << "La Fecha '" << firstDate << "' no es valida válida. Por favor, ingrese la primera fecha(en formato dd/mm/aaaa): ";
        getline(cin, firstDate);
    }
    // cout << "fecha LISTA";

    string formattedFirstDate = formatDates(firstDate);
    cout << "fecha formateada" << formattedFirstDate;
    // cout << "Ingrese la segunda fecha (en formato dd/mm/aaaa): ";
    // getline(cin, firstDate);

    // // Validar que la primera fecha tenga el formato correcto y que solo contenga dígitos
    // while (/* !contieneSoloDigitos(fecha1) ||  */ !isValidDate(firstDate))
    // {
    //     cout << "La primera fecha que ingresaste fue: " << firstDate;
    //     system("cls");
    //     cout << "La Fecha '" << firstDate << "' no es valida válida. Por favor, ingrese la primera fecha nuevamente: ";
    //     getline(cin, firstDate);
    // }

    return 0;
}