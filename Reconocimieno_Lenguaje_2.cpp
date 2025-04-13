// Escribir un programa para reconocer los lenguajes denotados por las siguientes expresiones regulares:
// “(letra|espacio|digito|especial)+”
// Donde   	especial à#|$|%|:

#include <iostream>
#include <ctype.h>  // Para isalpha, isdigit
#include <string.h> // Para strlen

using namespace std;

// Verifica si el caracter es especial
bool esEspecial(char c)
{
    return (c == '#' || c == '$' || c == '%' || c == ':');
}

// Función Scanner para reconocer el lenguaje (letra|espacio|digito|especial)+
bool Scanner(char w[])
{
    int i = 0;
    int longitud = strlen(w); // Obtenemos la longitud de la cadena

    // Verifica que la cadena no este vacia
    if (longitud == 0)
    {
        return false;
    }

    // Verifica que los caracteres sean todos los permitidos en el lenguaje
    while (w[i] != '\0')
    { // Recorremos cada caracter de la cadena
        char caracterActual = w[i];

        // Verificamos si el caracter es letra, espacio, dígito o especial
        bool caracterValido = isalpha(caracterActual) ||
                              caracterActual == ' ' ||
                              isdigit(caracterActual) ||
                              esEspecial(caracterActual);

        // Verifica que el caracter sea valido
        if (!caracterValido)
        {
            return false;
        }

        i++; // Pasamos al siguiente caracter
    }
    return true; // Todos los caracteres son validos
}

int main()
{
    char w[20];
    cout << "Ingrese una cadena a reconocer (letra|espacio|digito|especial)+ :" << endl;

    // Permite leer cadenas con espacios
    cin.getline(w, sizeof(w));

    if (Scanner(w))
    {
        cout << "ACEPTADA" << endl;
    }
    else
    {
        cout << "ERROR" << endl;
    }

    return 0;
}