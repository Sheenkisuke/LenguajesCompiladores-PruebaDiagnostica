/* Problema 1:
Dado una cadena de expresión aritmética imprima cada componente según su clasificación
( NUMERO, OPERADOR, PAREN_IZQ, PAREN_DER, OPERANDO, ERROR).

Reglas:
NUMERO: debe ser un entero o un real con el “.”, como marcador de decimales, sin signo
OPERANDO: no debe tener espacios ni iniciar con un numero (VALOR, A, B, CONT)
OPERADOR: + - * /

Ejemplo de salida para "12+ 3 * (4)":

Salida: NUMERO 12 OPERADOR + NUMERO 3 OPERADOR * PAREN_IZQ ( NUMERO 4 PAREN_DER ) PARÉNTESIS BALANCEADOS.
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Funcion para analizar e imprimir
void analizarExpresion(const string& expresion) {
    int i = 0;
    int longitud = expresion.length();
    int contadorParentesis = 0;

    while (i < longitud) {
        char c = expresion[i];

        // 1. Saltar espacios en blanco
        if (isspace(c)) {
            i++;
            continue;
        }
        // 2. Paréntesis izquierdo
        if (c == '(') {
            cout << "PAREN_IZQ ( ";
            contadorParentesis++;
            i++;
            continue;
        }
        // 3. Paréntesis derecho
        if (c == ')') {
            cout << "PAREN_DER ) ";
            contadorParentesis--;
            i++;
            continue;
        }
        // 4. Operadores
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            cout << "OPERADOR " << c << " ";
            i++;
            continue;
        }
        // 5. NUMERO (entero o real con punto)
        if (isdigit(c)) {
            string numero = "";
            bool tienePunto = false;
            bool valido = true;

            // Leer el numero completo
            while (i < longitud && (isdigit(expresion[i]) || expresion[i] == '.')) {
                char actual = expresion[i];

                if (actual == '.') {
                    if (tienePunto) {
                        valido = false;  // Dos puntos decimales -> ERROR
                    }
                    tienePunto = true;

                    // Verificar que el punto no sea el ultimo carácter
                    if (i + 1 >= longitud || !isdigit(expresion[i + 1])) {
                        valido = false;  // Punto al final o seguido de no-dígito
                    }
                }

                numero += actual;
                i++;
            }

            if (valido && tienePunto && numero.back() == '.') {
                valido = false;  // Termina con punto
            }

            if (valido) {
                cout << "NUMERO " << numero << " ";
            } else {
                cout << "ERROR " << numero << " ";
            }
            continue;
        }

        // 6. OPERANDO (variable: empieza con letra)
        if (isalpha(c)) {
            string operando = "";

            // Leer el operando completo (letras, números y _)
            while (i < longitud && (isalnum(expresion[i]) || expresion[i] == '_')) {
                operando += expresion[i];
                i++;
            }

            cout << "OPERANDO " << operando << " ";
            continue;
        }

        // 7. Cualquier otro carácter -> ERROR
        cout << "ERROR " << c << " ";
        i++;
    }

    // 8. Verificar balance de parentesis
    cout << endl;
    if (contadorParentesis == 0) {
        cout << "PARENTESIS BALANCEADOS." << endl;
    } else {
        cout << "PARENTESIS NO BALANCEADOS." << endl;
    }
}

int main() {
    string entrada;

    cout << "=== CLASIFICACION DE EXPRESIONES ARITMETICAS ===" << endl;
    cout << "Ingrese una expresion: ";
    getline(cin, entrada);  // Lee toda la linea

    cout << "\n--- SALIDA ---" << endl;
    analizarExpresion(entrada);

    return 0;
}
