////// Método de punto falso
@/*
@@@@@@autor: Villagran Salazar Diego
@*/
@@@#include <iostream>
@#include <cmath>
@@@using namespace std;
@@////// Definimos la función objetivo que queremos encontrar su raíz.
@float funcion_objetivo(float x) {
@@@@@return pow(x, 10) - 1;
@}
@@////// Función que implementa el método de interpolación lineal.
@float interpolacion_lineal(int iteracion, float error_absoluto, float raiz_actual, float limite_inferior, float limite_superior, int max_iteraciones, float error_maximo) {
////// Verificamos si los límites tienen signos opuestos, lo que es necesario para aplicar el método.
@@@@@if (funcion_objetivo(limite_inferior) * funcion_objetivo(limite_superior) > 0) {
@@@@@@@@@cout << "Intervalo incorrecto"; 
////// Mensaje de error si los límites no son válidos.
@@@@@@@@@return -1;
@@@@@}
@@////// Comprobamos si hemos alcanzado el número máximo de iteraciones o si el error es menor o igual al error máximo deseado.
@@@@@if (iteracion > max_iteraciones || error_absoluto <= error_maximo) {
@@@@@@@@@return raiz_actual; 
////// Devolvemos el valor calculado de la raíz.
@@@@@} else {
@@@@@@@@@cout << iteracion << ": "; 
////// Mostramos el número de iteración.
@@@@@@@@@cout << "Limite Inferior = " << limite_inferior << " | "; 
////// Mostramos el límite inferior.
@@@@@@@@@cout << "Limite Superior = " << limite_superior << " | "; 
////// Mostramos el límite superior.
@@@@@@@@@@@float raiz_anterior = raiz_actual; 
////// Almacenamos el valor anterior de la raíz.
@@@@@@@@@raiz_actual = limite_superior - ((funcion_objetivo(limite_superior) * (limite_inferior - limite_superior)) / (funcion_objetivo(limite_inferior) - funcion_objetivo(limite_superior))); 
////// Calculamos la nueva raíz.
@@@@@@@@@cout << "Raiz = " << raiz_actual << " | "; 
////// Mostramos la nueva raíz.
@@@@@@@@@@@error_absoluto = (float)(abs((raiz_actual - raiz_anterior) / raiz_actual) * 100); 
////// Calculamos el error absoluto.
@@@@@@@@@cout << "Error Absoluto = " << error_absoluto << " | "; 
////// Mostramos el error absoluto.
@@@@@@@@@@@iteracion++; 
////// Incrementamos el número de iteración.
@@@@@@@@@cout << "\n"; 
////// Nueva línea para formato.
@@@@@@@@@@@float test = funcion_objetivo(limite_inferior) * funcion_objetivo(raiz_actual); 
////// Verificamos en qué intervalo se encuentra la raíz.
@@@@@@@@@if (test < 0) {
////// Llamamos recursivamente con el nuevo intervalo izquierdo.
@@@@@@@@@@@@@return interpolacion_lineal(iteracion, error_absoluto, raiz_actual, limite_inferior, raiz_actual, max_iteraciones, error_maximo);
@@@@@@@@@} else if (test > 0) {
////// Llamamos recursivamente con el nuevo intervalo derecho.
@@@@@@@@@@@@@return interpolacion_lineal(iteracion, error_absoluto, raiz_actual, raiz_actual, limite_superior, max_iteraciones, error_maximo);
@@@@@@@@@} else {
@@@@@@@@@@@@@return raiz_actual; 
////// Devolvemos el valor calculado de la raíz.
@@@@@@@@@}
@@@@@}
@}
@@@int main(int argc, char* argv[]) {
@@@@@cout.setf(ios::fixed); 
////// Configuramos la salida para mostrar números en notación decimal fija.
@@@@@cout.setf(ios::showpoint);
@@@@@cout.precision(5); 
////// Configuramos la precisión decimal en 5 lugares.
@@@@@@@int iteracion = 0; 
////// Número de iteración inicial.
@@@@@float error_absoluto = 100; 
////// Error absoluto inicial.
@@@@@float raiz_actual = 0; 
////// Valor inicial de la raíz.
@@@@@float limite_inferior = atof(argv[1]); 
////// Límite inferior (tomado como argumento).
@@@@@float limite_superior = atof(argv[2]); 
////// Límite superior (tomado como argumento).
@@@@@int max_iteraciones = atof(argv[3]); 
////// Número máximo de iteraciones (tomado como argumento).
@@@@@float error_maximo = atof(argv[4]); 
////// Error máximo deseado (tomado como argumento).
@@@@@@@float raiz_encontrada = interpolacion_lineal(iteracion, error_absoluto, raiz_actual, limite_inferior, limite_superior, max_iteraciones, error_maximo); 
////// Llamamos a la función interpolacion_lineal.
@@@@@@@return 0; 
////// Salida exitosa del programa.
@}
