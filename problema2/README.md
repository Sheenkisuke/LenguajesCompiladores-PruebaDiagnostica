# Problema 2: Validador de Notación FEN (Forsyth-Edwards Notation)

Autor: Sheen Alburquerque  
Materia: Lenguajes y Compiladores  
Profesor: Msc. Félix Márquez  
Periodo: 2026-I

---

## 📌 Enunciado

Dado una cadena C, valide si C se encuentra en notación FEN (Forsyth-Edwards Notation), Forsyth–Edwards Notation. FEN (Wikipedia, 2025).

La notación FEN es un estándar para representar posiciones de ajedrez. Consta de 6 campos separados por espacios:

|Campo|         Significado          |          Valores posibles                   |
|-----|------------------------------|---------------------------------------------|
| 1 | Posición de las piezas         | 8 filas separadas por `/`, cada fila suma 8 |
| 2 | Turno                          | `w` (blancas) o `b` (negras)                |
| 3 | Derechos de enroque            | `KQkq` o combinación, o `-`                 |
| 4 | Captura al paso                | Casilla (ej: `e3`, `a6`) o `-`              |
| 5 | Contador de medios movimientos | Número ≥ 0                                  |
| 6 | Número de movimiento completo  | Número ≥ 1                                  |

### Ejemplo de FEN válido (posición inicial)

Entrada:
rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1

Salida:
FEN VALIDO

🔧 Cómo Compilar y Ejecutar
Opción 1: Code::Blocks (Recomendado)
Abrir Code::Blocks

Abrir el proyecto problema2.cbp (si existe)

Presionar F9 (Compilar y ejecutar)

Opción 2: Línea de comandos con MinGW
g++ main.cpp -o main.exe
./main.exe

Opción 3: Usar setup.bat
Hacer doble clic en setup.bat para ver instrucciones

📋 Ejemplos de Prueba:

1. FEN válido (posición inicial)
Entrada: rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1
Salida Esperada: FEN VALIDO

2. FEN válido (después de 1.e4)
Entrada: rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1
Salida Esperada: FEN VALIDO

3. FEN inválido (fila con suma incorrecta)
Entrada: rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBN w KQkq - 0 1
Salida Esperada: FEN INVALIDO (Error en Campo 1)

4. FEN inválido (turno incorrecto)
Entrada: rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR x KQkq - 0 1
Salida Esperada: FEN INVALIDO (Error en Campo 2: debe ser 'w' o 'b')

5. FEN inválido (faltan campos)
Entrada: rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0
Salida Esperada: FEN INVALIDO (Debe tener 6 campos)
