#include <iostream>  
#include <string>  
#include <vector>  
#include <cstdlib>  
#include <ctime>  

int main() {  
    // Palabras para adivinar  
    std::vector<std::string> palabras = {"programacion", "juego", "computadora", "inteligencia", "algoritmo"};  
    
    // Inicializar la semilla para el generador de números aleatorios  
    std::srand(static_cast<unsigned int>(std::time(nullptr)));  

    // Elegir una palabra aleatoriamente  
    std::string palabraSecreta = palabras[std::rand() % palabras.size()];  
    std::string palabraOculta(palabraSecreta.length(), '*'); // Palabra oculta inicial con asteriscos  
    char letra;  
    int intentos = 0;  
    const int MAX_INTENTOS = 6;  

    std::cout << "¡Bienvenido al juego de adivinar la palabra!" << std::endl;  
    std::cout << "Tienes " << MAX_INTENTOS << " intentos para adivinar la palabra." << std::endl;  

    // Bucle principal del juego  
    while (intentos < MAX_INTENTOS && palabraOculta != palabraSecreta) {  
        std::cout << "Palabra: " << palabraOculta << std::endl;  
        std::cout << "Ingresa una letra: ";  
        std::cin >> letra;  

        bool letraEncontrada = false;  

        // Verificar si la letra está en la palabra secreta  
        for (size_t i = 0; i < palabraSecreta.length(); ++i) {  
            if (palabraSecreta[i] == letra) {  
                palabraOculta[i] = letra; // Revelar la letra en la palabra oculta  
                letraEncontrada = true;  
            }  
        }  

        // Aumentar el contador de intentos  
        if (!letraEncontrada) {  
            intentos++;  
            std::cout << "No has encontrado la letra. Te quedan " << (MAX_INTENTOS - intentos) << " intentos." << std::endl;  
        } else {  
            std::cout << "¡Bien hecho! Has encontrado una letra." << std::endl;  
        }  
    }  

    // Resultado del juego  
    if (palabraOculta == palabraSecreta) {  
        std::cout << "¡Felicidades! Has adivinado la palabra " << palabraSecreta << " en " << intentos << " intentos." << std::endl;  
    } else {  
        std::cout << "¡Has perdido! La palabra era " << palabraSecreta << "." << std::endl;  
    }  

    return 0;  
}