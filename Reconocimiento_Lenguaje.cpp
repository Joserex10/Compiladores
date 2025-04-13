#include <iostream>
#include <ctype.h> // Necesario para isdigit
#include <string.h> // Necesario para strlen
#include <stdio.h>  // Opcional, para compatibilidad si usaras gets_s o fgets

using namespace std;

// Función Scanner para reconocer el lenguaje (+|-)digito+
// Devuelve true si w pertenece al lenguaje, false en caso contrario.
bool Scanner(char w[])
{
    int i = 0;         // Índice para recorrer la cadena
    int longitud = strlen(w); // Longitud de la cadena

    // --- Estado Inicial ---
    // Paso 1: Verificar la longitud mínima (signo + al menos un dígito)
    if (longitud < 2) {
        return false; // No puede ser válida si tiene menos de 2 caracteres
    }

    // --- Transición por Signo ---
    // Paso 2: Verificar el primer carácter (debe ser '+' o '-')
    if (w[i] == '+' || w[i] == '-') {
        i++; // Avanza al siguiente carácter si es un signo válido
    } else {
        return false; // El primer carácter no es '+' ni '-'
    }

    // --- Transición por Primer Dígito ---
    // Paso 3: Verificar que el carácter actual (el segundo) sea un dígito.
    //         Esto asegura que haya al menos un dígito (digito+)
    if (i >= longitud || !isdigit(w[i])) {
         // Si i >= longitud, significa que la cadena era solo "+" o "-"
         // Si !isdigit(w[i]), el carácter después del signo no es un dígito.
        return false;
    }
    i++; // Avanzamos al siguiente carácter después del primer dígito confirmado

    // --- Estado de Aceptación (mientras sean dígitos) ---
    // Paso 4: Verificar que todos los caracteres restantes sean dígitos.
    while (i < longitud) {
        if (!isdigit(w[i])) {
            // Si encontramos un carácter que no es dígito, la cadena es inválida
            return false; // Sale del estado de aceptación
        }
        i++; // Avanza al siguiente carácter
    }

    // --- Fin de Cadena en Estado de Aceptación ---
    // Si llegamos hasta aquí, significa que:
    // 1. Empezó con '+' o '-'.
    // 2. Siguió con al menos un dígito.
    // 3. Todos los caracteres restantes (si los hubo) también fueron dígitos.
    // 4. Llegamos al final de la cadena (i == longitud).
    // Por lo tanto, la cadena es aceptada.
    return true;
}

int main(void)
{
	char w[100]; // Aumentamos un poco el tamaño para cadenas más largas
	cout << "Reconocedor para el lenguaje: (+|-)digito+" << endl;
	cout << "Ingrese una cadena a reconocer: ";
	cin >> w; // Lee la cadena desde la entrada estándar

	if (Scanner(w)) {
		cout << "Resultado: ACEPTADA" << endl;
	} else {
		cout << "Resultado: ERROR (NO ACEPTADA)" << endl;
	}
	return (0);
}