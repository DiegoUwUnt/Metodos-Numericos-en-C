////// Método de Newton para encontrar raíces
@/*
@@autor: Villagran Salazar Diego
@*/
@@////// Incluye la biblioteca estándar de C++ para entrada/salida y otras operaciones.
@#include <bits/stdc++.h>
@@////// Espacio de nombres estándar de C++.
@using namespace std;
@@////// Definición de la función f(x) que se utiliza en el método de Newton.
@float f(float x) {
@@@@@return exp(-x) - x;
@}
@@////// Definición de la función dx(x) para calcular la derivada de f(x) numéricamente.
@float dx(float x) {
@@@@@float h = 0.0001;
@@@@@return ((f(x+h) - f(x)) / h);
@}
@@////// Función principal del método de Newton-Raphson.
////// Toma un valor inicial x0, un error relativo se, y un número máximo de iteraciones imax como argumentos.
@float newtonRaphson(float x0, float se, int imax) {
@@@@@float x = x0;
@@@@@int i = 0;
@@@@@@@@@@@while (i < imax) {
@@@@@@@@@cout << i << ": ";
@@@@@@@@@float fx = f(x);
@@@@@@@@@float df = dx(x);
@@@@@@@@@@@cout << "f(x) = " << fx << " | ";
@@@@@@@@@cout << "f'(x) = " << df << " | ";
@@@@@@@@@@////// Comprueba si la derivada es cercana a cero para evitar la división por cero.
@@@@@@@@@if (abs(df) < 1e-6) {
@@@@@@@@@@@@@return -1;
@@@@@@@@@}
@@@@@@@@@@@@@@@@@@@float deltaX = fx / df;
@@@@@@@@@x -= deltaX;
@@@@@@@@@cout << "ae = " << abs(deltaX) << " | ";
@@@@@@@@@@////// Comprueba si el error absoluto es menor que el error relativo deseado.
@@@@@@@@@if (abs(deltaX) < se) {
@@@@@@@@@@@@@return x;
@@@@@@@@@}
@@@@@@@@@@@@@@@@@@@i++;
@@@@@@@@@cout << "\n";
@@@@@}
@@@@@@@@@@@return -1;
@}
@@////// Función principal del programa.
@int main(int args, char *argv[]) {
////// Configura la salida para mostrar un número fijo de decimales.
@@@@@cout.setf(ios::fixed);
@@@@@cout.setf(ios::showpoint);
@@@@@cout.precision(5);
@@////// Lee los argumentos de la línea de comandos: valor inicial, error relativo y número máximo de iteraciones.
@@@@@float x0 = atof(argv[1]);
@@@@@float se = atof(argv[2]);
@@@@@int imax = atoi(argv[3]);
@@////// Llama al método de Newton-Raphson y almacena el resultado en xr.
@@@@@float xr = newtonRaphson(x0, se, imax);
@@@@@@@cout << "\n";
@@@@@return 0;
@}
