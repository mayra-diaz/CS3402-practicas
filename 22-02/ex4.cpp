/* Determine si la siguiente gramatica es LL(1):
 * A → a A a | e
 * 
 * Primeros(A)={a, e}
 * Siguientes(A)={$, a}
 * No es LL(1), pues epsilon pertenece a Primeros(A) y P(A) interseccion S(A) es diferente de vacio.
 *
 * Escriba un analizador sintactico en C++ correspondiente a la gramatica
 * */


