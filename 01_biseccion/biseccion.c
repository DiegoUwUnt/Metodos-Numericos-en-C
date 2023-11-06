////// Metodo de biseccion
@/*
@@@@@Autor: Villagran Salazar Diego
@*/
@@@#include <bits/stdc++.h>
@using namespace std;
@@////// Función para calcular f(x).
@float f(float x) {
@@@@@return exp(-x) - x;
@}
@@////// Función para el método de la bisección.
////// Bisect(iter, absulute err, x_result, x_left, x_superior, max_iter, supose err)
@float bisect(int i, float ae, float xr, float xl, float xu, int imax, float se) {
////// Comprueba si los límites iniciales son válidos.
@@@@@if (f(xl) * f(xu) > 0) {
@@@@@@@@@cout << "Incorrect limits";
@@@@@@@@@return -1;
@@@@@}
@@////// Condición de parada para el método de la bisección.
@@@@@if (i > imax || ae <= se) {
@@@@@@@@@return xr;
@@@@@} else {
@@@@@@@@@cout << i << ": ";
@@@@@@@@@cout << "xl = " << xl << " | ";
@@@@@@@@@cout << "xu = " << xu << " | ";
@@@@@@@@@float xrold = xr;
@@@@@@@@@xr = (xl + xu) / 2;
@@@@@@@@@cout << "xr = " << xr << " | ";
@@@@@@@@@ae = (float)(abs((xr - xrold) / xr) * 100);  
@@@@@@@@@@////// Cálculo del error absoluto.
@@@@@@@@@@@@@@@@@@@cout << "ae = " << ae << " | ";
@@@@@@@@@i++;
@@@@@@@@@cout << "\n";
@@@@@@@@@@@float test = f(xl) * f(xr);
@@@@@@@@@if (test < 0) {
@@@@@@@@@@@@@return bisect(i, ae, xr, xl, xr, imax, se);  
@@@@@@@@@@@@@@////// Llamada recursiva para la parte izquierda.
@@@@@@@@@@@@@@@@@@@} else if (test > 0) {
@@@@@@@@@@@@@return bisect(i, ae, xr, xr, xu, imax, se);  
@@@@@@@@@@@@@@////// Llamada recursiva para la parte derecha.
@@@@@@@@@@@@@@@@@@@} else {
@@@@@@@@@@@@@return xr;
@@@@@@@@@}
@@@@@}   
@}
@@@int main(int args, char *argv[]) {
@@@@@cout.setf(ios::fixed);
@@@@@cout.setf(ios::showpoint);
@@@@@cout.precision(5);
@@@@@@@int i = 0;
@@@@@float ae = 100;
@@@@@float xr = 0;
@@@@@float xl = atof(argv[1]);
@@@@@float xu = atof(argv[2]);
@@@@@int imax = atof(argv[3]);
@@@@@float se = atof(argv[4]);
@@@@@@@float r = bisect(i, ae, xr, xl, xu, imax, se); 
@@@@@@////// Llama al método de la bisección.
@@@@@@@return 0;
@}
