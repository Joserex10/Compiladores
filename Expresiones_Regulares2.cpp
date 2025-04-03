// Escribir un programa para reconocer los lenguajes denotados por las siguientes expreciones regulares:
//  [0-9]+[0-9]+ = [0-9][0-9]*[0-9][0-9]*

#include <iostream>
#include <ctype.h>
#include <string.h>

using namespace std;

bool Scanner(char w[])
{
    int I = 0;
    int flag = 0;
    int length = strlen(w); // Identifica la longitud del arreglo

    while (w[I] == '0' || w[I] == '1' || w[I] == '2' || w[I] == '3' || w[I] == '4' || w[I] == '5' || w[I] == '6' || w[I] == '7' || w[I] == '8' || w[I] == '9') // bucle que permite ingresar indefinidamente caracteres
    {
        I++;      // si los caracteres ingresados son entre un rango de 1 a 9 I va sumando
        flag = 1; // se estable flag como 1 para saber que por lo menos tenemos 1 caracter ingresado
        if (flag) // si flag es igual a 1 entra al if
        {
            while (w[I] == '0' || w[I] == '1' || w[I] == '2' || w[I] == '3' || w[I] == '4' || w[I] == '5' || w[I] == '6' || w[I] == '7' || w[I] == '8' || w[I] == '9') // bucle que permite ingresar indefinidamente caracteres
            {
                I++;      // si los caracteres ingresados son entre un rango de 1 a 9 I va sumando
                flag = 2; // se estable flag como 2 para saber que por lo menos tenemos 2 caracter ingresados y ya cumplimos los requisitos
            }
        }
    }

    if (I == length && flag == 2) // comprueba que I sea igual a la longitud del arreglo y tambien comprueba que flag sea igual a 2 significando que ya tenemos los 2 caracteres necesarios para completar el ejercicio
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
    if (Scanner(w))
        cout << "Correcto";
    else
        cout << "Error";
    return (0);
}