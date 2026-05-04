/* Problema 2:
Dado una cadena C, valide si C se encuentra en notación FEN (Forsyth-Edwards Notation),
Forsyth–Edwards Notation. FEN (Wikipedia, 2025).
*/

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <vector>

using namespace std;

// Función para verificar si un caracter es pieza válida (p,n,b,r,q,k)
bool esPiezaValida(char c) {
    string piezas = "PNBRQKpnbrqk";
    return piezas.find(c) != string::npos;
}

// Función para validar el Campo 1: posiciones de las piezas
bool validarPiezas(const string& campo) {
    // Debe tener 8 filas separadas por '/'
    vector<string> filas;
    stringstream ss(campo);
    string fila;

    while (getline(ss, fila, '/')) {
        filas.push_back(fila);
    }

    if (filas.size() != 8) {
        return false;
    }

    // Validar cada fila
    for (const string& fila : filas) {
        int suma = 0;
        for (char c : fila) {
            if (esPiezaValida(c)) {
                suma++;
            }
            else if (isdigit(c)) {
                int num = c - '0';
                if (num < 1 || num > 8) {
                    return false;
                }
                suma += num;
            }
            else {
                return false;  // Carácter inválido
            }
        }
        if (suma != 8) {
            return false;
        }
    }

    return true;
}

// Función para validar Campo 2: turno
bool validarTurno(const string& campo) {
    return campo == "w" || campo == "b";
}

// Función para validar Campo 3: derechos de enroque
bool validarEnroques(const string& campo) {
    // Caso especial: sin enroques
    if (campo == "-") {
        return true;
    }

    // Verificar que solo contenga K, Q, k, q
    for (char c : campo) {
        if (c != 'K' && c != 'Q' && c != 'k' && c != 'q') {
            return false;
        }
    }

    // Verificar que no haya caracteres repetidos
    bool tieneK = false, tieneQ = false, tieneK_min = false, tieneQ_min = false;
    for (char c : campo) {
        if (c == 'K') {
            if (tieneK) return false;
            tieneK = true;
        }
        else if (c == 'Q') {
            if (tieneQ) return false;
            tieneQ = true;
        }
        else if (c == 'k') {
            if (tieneK_min) return false;
            tieneK_min = true;
        }
        else if (c == 'q') {
            if (tieneQ_min) return false;
            tieneQ_min = true;
        }
    }

    return true;
}

// Función para validar Campo 4: captura al paso
bool validarAlPaso(const string& campo) {
    // Caso especial: sin captura al paso
    if (campo == "-") {
        return true;
    }

    // Debe tener exactamente 2 caracteres
    if (campo.length() != 2) {
        return false;
    }

    char letra = campo[0];
    char numero = campo[1];

    // Validar letra (a-h)
    if (letra < 'a' || letra > 'h') {
        return false;
    }

    // Validar número (solo 3 o 6 para al paso)
    if (numero != '3' && numero != '6') {
        return false;
    }

    return true;
}

// Función para verificar si un string es número entero
bool esNumeroEntero(const string& str) {
    if (str.empty()) return false;

    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

// Función principal de validación FEN
bool validarFEN(const string& fen) {
    // Separar los 6 campos por espacios
    vector<string> campos;
    stringstream ss(fen);
    string campo;

    while (ss >> campo) {
        campos.push_back(campo);
    }

    // Debe tener exactamente 6 campos
    if (campos.size() != 6) {
        cout << "Error: Debe tener 6 campos, tiene " << campos.size() << endl;
        return false;
    }

    // Campo 1: Posiciones de las piezas
    if (!validarPiezas(campos[0])) {
        cout << "Error en Campo 1 (posiciones de piezas): " << campos[0] << endl;
        return false;
    }

    // Campo 2: Turno
    if (!validarTurno(campos[1])) {
        cout << "Error en Campo 2 (turno): " << campos[1] << " (debe ser 'w' o 'b')" << endl;
        return false;
    }

    // Campo 3: Enroques
    if (!validarEnroques(campos[2])) {
        cout << "Error en Campo 3 (enroques): " << campos[2] << " (debe ser '-' o combinacion de K,Q,k,q)" << endl;
        return false;
    }

    // Campo 4: Captura al paso
    if (!validarAlPaso(campos[3])) {
        cout << "Error en Campo 4 (captura al paso): " << campos[3] << " (debe ser '-' o casilla como e3/a6)" << endl;
        return false;
    }

    // Campo 5: Contador de medios movimientos
    if (!esNumeroEntero(campos[4])) {
        cout << "Error en Campo 5 (contador): " << campos[4] << " (debe ser un numero entero)" << endl;
        return false;
    }
    int contador = stoi(campos[4]);
    if (contador < 0) {
        cout << "Error en Campo 5 (contador): " << contador << " (debe ser >= 0)" << endl;
        return false;
    }

    // Campo 6: Número de movimiento completo
    if (!esNumeroEntero(campos[5])) {
        cout << "Error en Campo 6 (movimiento): " << campos[5] << " (debe ser un numero entero)" << endl;
        return false;
    }
    int movimiento = stoi(campos[5]);
    if (movimiento < 1) {
        cout << "Error en Campo 6 (movimiento): " << movimiento << " (debe ser >= 1)" << endl;
        return false;
    }

    return true;
}

int main() {
    string entrada;

    cout << "=== VALIDADOR DE NOTACION FEN (Forsyth-Edwards Notation) ===" << endl;
    cout << "Ingrese una cadena FEN: ";
    getline(cin, entrada);

    cout << "\n--- RESULTADO ---" << endl;

    if (validarFEN(entrada)) {
        cout << "FEN VALIDO" << endl;
    } else {
        cout << "FEN INVALIDO" << endl;
    }

    return 0;
}
