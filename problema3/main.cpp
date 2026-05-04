/*
Problema 3:
Escriba un código que verifique si se cumple la conjetura de collatz en enteros de un intervalo [p,q].
La conjetura indica que para cualquier número entero positivo n se aplica:
Si n es par → n = n / 2, Si n es impar → n = 3n + 1,
Ejemplo: 6 ≤ n ≤ 8
n=6: 6 → 3 → 10 → 5 → 16 → 8 → 4 → 2 → 1
n=7: 7 → 22 → 11 → 34 → 17 → 52 → 26 → 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
n=8: 8 → 4 → 2 → 1
Demostrado...
Regla q ≥ 100p para poder aplicar la demostración.
*/

#include <iostream>
using namespace std;

// Función que muestra la secuencia de Collatz para un número n
void mostrarSecuencia(long long n) {
    cout << n;
    while (n > 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
        cout << " -> " << n;
    }
    cout << endl;
}

int main() {
    long long p, q;
    cout << "=== CONJETURA DE COLLATZ ===" << endl;
    cout << "Ingrese el valor de p: ";
    cin >> p;
    cout << "Ingrese el valor de q: ";
    cin >> q;
    cout << endl;

    // Validar números positivos
    if (p <= 0 || q <= 0) {
        cout << "Error: p y q deben ser numeros enteros positivos." << endl;
        return 1;
    }
    // Validar la condición q >= 100 * p
    if (q < 100 * p) {
        cout << "Error: Para aplicar la demostracion, q debe ser >= 100 * p" << endl;
        cout << "q = " << q << ", 100 * p = " << 100 * p << endl;
        return 1;
    }
    // Verificar la conjetura para cada número en el intervalo
    for (long long n = p; n <= q; n++) {
        cout << "n=" << n << ": ";
        mostrarSecuencia(n);
    }

    cout << "\nDemostrado..." << endl;
    return 0;
}
