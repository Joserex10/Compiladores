// Escribir un programa para reconocer los lenguajes denotados por las siguientes expreciones regulares:
//  (a|b)*abb

#include <iostream>
#include <ctype.h>
#include <string.h>

using namespace std;

bool Scanner(char w[])
{
    int I = 0;
    int length = strlen(w);            // Identifica la longitud del arreglo
    while (w[I] == 'a' || w[I] == 'b') // bucle que permite ingresar indefinidamente caracteres
    {
        I++; // si los caracteres ingresados son 'a' o 'b' I va sumando
    }

    if (I == length && w[I - 1] == 'b' && w[I - 2] == 'b' && w[I - 3] == 'a') // comprueba que I sea igual a la longitud del arreglo y va restando en el arreglo posiciones para comparar esas posiciones con los caracteres obligatorios en el problema
    {
        return true;
    }
    return false;
}

int main(void)
{
    char w[20];
    cout << "Ingrese cadena a reconocer:";
    cin >> w;
    if (Scanner(w)) // si retorna true se ejecuta este if
        cout << "Correcto";
    else
        cout << "Error"; // si retona false se ejecuta el else
    return (0);
}