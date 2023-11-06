// Método punto fijo
// Autor: Villagran Salazar Diego

#include <iostream>
#include <cmath>

using namespace std;

// Definimos la función f(x), que es la función cuya raíz queremos encontrar.
float funcion_f(float x) {
    return x;
}

// Definimos la función g(x), que representa la función utilizada en el método del punto fijo.
float funcion_g(float x) {
    return funcion_f(x) + exp(-x);
}

// Implementamos el método del punto fijo para encontrar una raíz.
float puntoFijo(float error_absoluto, float valor_inicial, int max_iteraciones, float error_supuesto) {
    float xr = valor_inicial;  
    // Inicializamos xr con el valor inicial proporcionado.
    
    int iteracion = 0;  
    // Inicializamos el contador de iteraciones.

    do {
        cout << iteracion << ": ";  
        // Mostramos el número de iteración.
        
        cout << "xr = " << xr << " | ";  
        // Mostramos el valor actual de xr.

        float xr_anterior = xr;  
        // Almacenamos el valor anterior de xr.
        
        xr = funcion_g(xr);  
        // Calculamos el nuevo valor de xr utilizando la función g(x).
        
        iteracion++;  
        // Incrementamos el contador de iteraciones.

        cout << "error_absoluto = " << error_absoluto << " | ";  
        // Mostramos el error absoluto actual.

        if (xr != 0) {
            error_absoluto = abs(((xr - xr_anterior) / xr)) * 100;  
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
    
    float valor_inicial = 0;  
    // Valor inicial para el método del punto fijo.
    
    int max_iteraciones = atoi(argv[1]);  
    // Número máximo de iteraciones (tomado como argumento).
    
    float error_supuesto = atof(argv[2]);  
    // Error supuesto deseado (tomado como argumento).

    float raiz = puntoFijo(error_absoluto, valor_inicial, max_iteraciones, error_supuesto);  
    // Llamamos a la función puntoFijo para encontrar la raíz.

    return 0;  
    // Salida exitosa del programa.
}
