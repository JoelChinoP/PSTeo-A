#include <iostream>
using namespace std;

// Definición de la estructura para representar una fecha
struct Fecha
{
    int dia;
    int mes;
    int anio;
};

// Función para verificar si un año es bisiesto
bool esBisiesto(int anio)
{
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

// Función para calcular el número de días entre dos fechas
int calcularDiferencia(const Fecha &fecha1, const Fecha &fecha2)
{
    // Días en cada mes (no bisiesto)
    int diasPorMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Suma los días de los años completos entre las fechas
    int totalDias = 0;
    for (int anio = fecha1.anio; anio < fecha2.anio; ++anio)
    {
        totalDias += esBisiesto(anio) ? 366 : 365;
    }

    // Suma los días del año parcial de fecha1
    for (int mes = 1; mes < fecha1.mes; ++mes)
    {
        totalDias -= diasPorMes[mes];
        if (mes == 2 && esBisiesto(fecha1.anio))
        {
            totalDias -= 1; // Febrero en año bisiesto tiene 29 días
        }
    }
    totalDias -= fecha1.dia;

    // Suma los días del año parcial de fecha2
    for (int mes = 1; mes < fecha2.mes; ++mes)
    {
        totalDias += diasPorMes[mes];
        if (mes == 2 && esBisiesto(fecha2.anio))
        {
            totalDias += 1; // Febrero en año bisiesto tiene 29 días
        }
    }
    totalDias += fecha2.dia;

    return totalDias;
}

int main()
{
    Fecha fecha1 = {1, 1, 2023};  // Primera fecha (día, mes, año)
    Fecha fecha2 = {15, 6, 2024}; // Segunda fecha (día, mes, año)

    int diferencia = calcularDiferencia(fecha1, fecha2);
    cout << "Dias entre las fechas: " << diferencia << endl;

    return 0;
}