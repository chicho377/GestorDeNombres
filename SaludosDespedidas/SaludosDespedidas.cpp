#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <cstdlib>
#include <ctime>

// Función que muestra un saludo personalizado
void mostrarSaludo(const std::string& nombre) {
    std::cout << "Hola, " << nombre << "! Bienvenido al programa en C++." << std::endl;
}

// Función principal del programa
int main() {
    std::string nombre;
    char opcion;
    std::vector<std::string> nombres;
    int contador = 0;

    do {
        // Solicitar al usuario que ingrese su nombre
        std::cout << "Por favor, ingresa tu nombre: ";
        std::getline(std::cin, nombre);

        // Validar que el usuario haya ingresado algo
        if (nombre.empty()) {
            std::cerr << "Error: No has ingresado un nombre. Por favor, intenta de nuevo." << std::endl;
            continue;
        }

        // Almacenar el nombre en la lista y aumentar el contador
        nombres.push_back(nombre);
        contador++;

        // Mostrar el saludo personalizado
        mostrarSaludo(nombre);

        // Preguntar al usuario si desea continuar
        std::cout << "¿Quieres ingresar otro nombre? (s/n): ";
        std::cin >> opcion;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el buffer de entrada

    } while (opcion == 's' || opcion == 'S');

    // Mostrar todos los nombres ingresados
    std::cout << "\nHas ingresado " << contador << " nombre(s):" << std::endl;
    for (const std::string& nombre : nombres) {
        std::cout << "- " << nombre << std::endl;
    }

    // Mostrar un mensaje de despedida aleatorio
    std::vector<std::string> despedidas = {
        "¡Hasta luego!",
        "¡Que tengas un gran día!",
        "¡Adiós y cuídate!",
        "¡Nos vemos pronto!",
        "¡Fue un placer verte!"
    };

    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Semilla para generar números aleatorios
    int indice = std::rand() % despedidas.size();
    std::cout << "\nGracias por usar el programa. " << despedidas[indice] << std::endl;

    return 0;
}
