#include <iostream>
#include <string>
using namespace std;

string entrada;

// Función para verificar si una cadena es un numero entero con signo
bool esEnteroConSigno(const string &cadena)
{
    // Verificar si la cadena esta vacia
    if (cadena.empty())
        return false;

    // Verificar el primer caracter (puede ser +, - o un dígito)
    size_t inicio = 0;
    if (cadena[0] == '+' || cadena[0] == '-')
    {
        inicio = 1; // Si hay signo, empezar a verificar desde el segundo caracter
    }

    // Verificar que los caracteres restantes sean digitos
    for (size_t i = inicio; i < cadena.length(); i++)
    {
        if (!isdigit(cadena[i]))
        {
            return false; // Si no es un digito, la cadena no es valida
        }
    }

    // La cadena es valida si tiene al menos un digito despues del signo (si lo hay)
    return (cadena.length() > inicio);
}

// Funcion para verificar si una cadena es un numero real sin signo
bool esRealSinSigno(const string &cadena)
{
    // Verificar si la cadena esta vacia
    if (cadena.empty())
        return false;

    // Variables para contar puntos y dígitos
    size_t puntoCount = 0;
    size_t digitoCount = 0;

    // Recorrer cada caracter de la cadena
    for (size_t i = 0; i < cadena.length(); i++)
    {
        if (cadena[i] == '.')
        {
            puntoCount++; // Contar puntos
        }
        else if (isdigit(cadena[i]))
        {
            digitoCount++; // Contar dígitos
        }
        else
        {
            return false; // Si no es un digito ni un punto, la cadena no es valida
        }
    }

    // La cadena es valida si tiene exactamente un punto y al menos un digito
    return (puntoCount == 1) && (digitoCount > 0);
}

void enteroSigno()
{
    // Prueba para numeros enteros con signo
    cout << "Ingrese un numero entero con signo (ejemplo: +123, -456): ";
    cin >> entrada;
    if (esEnteroConSigno(entrada))
    {
        cout << "La cadena '" << entrada << "' es un numero entero con signo válido." << endl;
    }
    else
    {
        cout << "La cadena '" << entrada << "' NO es un numero entero con signo valido." << endl;
        enteroSigno();
    }
}

void realSinSigno()
{
    // Prueba para numeros reales sin signo
    cout << "Ingrese un numero real sin signo (ejemplo: 123.456, 0.789): ";
    cin >> entrada;
    if (esRealSinSigno(entrada))
    {
        cout << "La cadena '" << entrada << "' es un numero real sin signo valido." << endl;
    }
    else
    {
        cout << "La cadena '" << entrada << "' NO es un numero real sin signo valido." << endl;
        realSinSigno();
    }
}

int main()
{
    enteroSigno();
    realSinSigno();

    return 0;
}