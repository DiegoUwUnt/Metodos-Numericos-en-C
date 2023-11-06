// Método de secante
/*
    @autor: Villagran Salazar Diego
*/

#include <iostream>
#include <cmath>

using namespace std;

// Definimos la función f(x), la cual queremos encontrar su raíz.
float funcion_f(float x) {
    return exp(-x) - x;
}

// Implementamos el método de la secante para encontrar la raíz.
float metodo_secante(float error_absoluto, float x0, float x1, int max_iteraciones, float error_supuesto) {
    float xr; 
    // Valor estimado de la raíz.
    int iteracion = 0; 
    // Contador de iteraciones.
    float x_actual = x0; 
    // Valor inicial x0.
    float x_anterior = x1; 
    // Valor inicial x1.
    
    do {
        cout << iteracion << ": "; 
        // Mostramos el número de iteración.
        cout << "xr = " << xr << " | "; 
        // Mostramos el valor actual de xr.
        
        // Calculamos el nuevo valor de xr utilizando el método de la secante.
        xr = x_anterior - ((funcion_f(x_anterior) * (x_actual - x_anterior)) / (funcion_f(x_actual) - funcion_f(x_anterior)));
        
        x_actual = x_anterior; 
        // Actualizamos los valores de x_actual y x_anterior para la próxima iteración.
        x_anterior = xr;
        
        iteracion++; 
        // Incrementamos el contador de iteraciones.
        
        cout << "error_absoluto = " << error_absoluto << " | "; 
        // Mostramos el error absoluto actual.
        
        if (xr != 0) {
            error_absoluto = abs(((xr - x_anterior) / xr)) * 100; 
            // Calculamos el nuevo error absoluto si xr no es igual a cero.
        }
        
        cout << "\n"; 
        // Salto de línea para el formato.
    } while (error_absoluto > error_supuesto && iteracion <= max_iteraciones); 
    // Continuamos iterando mientras el error absoluto sea mayor que el error deseado y no se exceda el número máximo de iteraciones.
    
    return xr; 
    // Devolvemos el valor de xr como resultado.
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed); 
    // Configuramos la salida para mostrar números en notación decimal fija.
    cout.setf(ios::showpoint);
    cout.precision(5); 
    // Configuramos la precisión decimal en 5 lugares.

    float error_absoluto = 100; 
    // Inicializamos el error absoluto.
    float x0 = 0; 
    // Valor inicial para x0.
    float x1 = 1; 
    // Valor inicial para x1.
    int max_iteraciones = atoi(argv[1]); 
    // Número máximo de iteraciones (tomado como argumento).
    float error_supuesto = atof(argv[2]); 
    // Error supuesto deseado (tomado como argumento).

    float raiz_encontrada = metodo_secante(error_absoluto, x0, x1, max_iteraciones, error_supuesto); 
    // Llamamos a la función metodo_secante para encontrar la raíz.

    return 0; 
    // Salida exitosa del programa.
}
