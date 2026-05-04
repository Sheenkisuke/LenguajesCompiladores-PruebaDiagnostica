# Problema 3: Conjetura de Collatz

Autor: Sheen Alburquerque  
Materia: Lenguajes y Compiladores  
Profesor: Msc. Félix Márquez  
Periodo: 2026-I

---

## 📌 Enunciado

Escriba un código que verifique si se cumple la conjetura de Collatz en enteros de un intervalo `[p, q]`.

La conjetura indica que para cualquier número entero positivo `n` se aplica:

- Si `n` es par → `n = n / 2`
- Si `n` es impar → `n = 3n + 1`

Regla especial: `q ≥ 100p` para poder aplicar la demostración.

### Ejemplo

Para `6 ≤ n ≤ 8`:
n=6: 6 → 3 → 10 → 5 → 16 → 8 → 4 → 2 → 1
n=7: 7 → 22 → 11 → 34 → 17 → 52 → 26 → 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
n=8: 8 → 4 → 2 → 1
Demostrado...

---

🔧 Cómo Compilar y Ejecutar
Opción 1: Code::Blocks (Recomendado)
Abrir Code::Blocks

Crear nuevo proyecto o abrir problema3.cbp

Presionar F9 (Compilar y ejecutar)

Opción 2: Línea de comandos con MinGW
g++ main.cpp -o main.exe
./main.exe

Opción 3: Usar setup.bat
Hacer doble clic en setup.bat para ver instrucciones

📋 Ejemplos de Prueba

1. Válido (cumple la regla)
Entrada:
p = 1
q = 100

Salida Esperada: Muestra las secuencias de Collatz para los números del 1 al 100 y finaliza con Demostrado...

2. Válido (intervalo mínimo)
Entrada:
p = 2
q = 200

Salida Esperada: q ≥ 100 * p → 200 ≥ 200 ✅

3. Inválido (no cumple la regla)
Entrada:
p = 6
q = 8

Salida Esperada: Error: Para aplicar la demostracion, q debe ser >= 100 * p q = 8, 100 * p = 600

4. Inválido (números negativos)
Entrada:
p = -1
q = 100

Salida Esperada: Error: p y q deben ser numeros enteros positivos.
