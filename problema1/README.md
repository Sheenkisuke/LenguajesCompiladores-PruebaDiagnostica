# Problema 1: Clasificación de Expresiones Aritméticas

Autor: Sheen Alburquerque  
Materia: Lenguajes y Compiladores  
Profesor: Msc. Félix Márquez  
Periodo: 2026-I

---

## 📌 Enunciado

Dado una cadena de expresión aritmética, imprima cada componente según su clasificación:

- NUMERO: entero o real con punto (`.`), sin signo
- OPERADOR: `+` `-` `*` `/`
- PAREN_IZQ: `(`
- PAREN_DER: `)`
- OPERANDO: no debe tener espacios ni iniciar con número (ej: VALOR, A, B, CONT)
- ERROR: cualquier carácter no reconocido o número mal formado

Además, debe indicar si los paréntesis están balanceados o no.

### Ejemplo de salida

Entrada: 12+ 3 * (4)

Salida: NUMERO 12 OPERADOR + NUMERO 3 OPERADOR * PAREN_IZQ ( NUMERO 4 PAREN_DER )
PARÉNTESIS BALANCEADOS.

🔧 Cómo Compilar y Ejecutar
Opción 1: Code::Blocks (Recomendado)
Abrir Code::Blocks

Abrir el proyecto problema1.cbp

Presionar F9 (Compilar y ejecutar)

Opción 2: Línea de comandos con MinGW
g++ main.cpp -o main.exe
./problema1.exe

Opción 3: Usar setup.bat
Hacer doble clic en setup.bat para ver instrucciones

📋 Ejemplos de Prueba:
1--
Entrada: 12+ 3 * (4)
Salida Esperada: NUMERO 12 OPERADOR + NUMERO 3 OPERADOR * PAREN_IZQ ( NUMERO 4 PAREN_DER ) + PARÉNTESIS BALANCEADOS.

2--
Entrada: A + B12
Salida Esperada: OPERANDO A OPERADOR + OPERANDO B12 + PARÉNTESIS BALANCEADOS.

3--
Entrada: (12+3
Salida Esperada: PAREN_IZQ ( NUMERO 12 OPERADOR + NUMERO 3 + PARÉNTESIS NO BALANCEADOS.

4--
Entrada: 12..5
Salida Esperada: ERROR 12..5 + PARÉNTESIS BALANCEADOS.

5--
Entrada: 12 + $
Salida Esperada: NUMERO 12 OPERADOR + ERROR $ + PARÉNTESIS BALANCEADOS.
