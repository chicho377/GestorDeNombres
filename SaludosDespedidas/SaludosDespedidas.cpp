#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>

// Función que muestra un saludo personalizado
void mostrarSaludo(const std::string& nombre) {
    std::cout << "Hola, " << nombre << "! Bienvenido al programa en C++." << std::endl;
}

// Función para obtener y validar el nombre del usuario
std::string obtenerNombre() {
    std::string nombre;
    while (true) {
        std::cout << "Por favor, ingresa tu nombre: ";
        std::getline(std::cin, nombre);

        // Validar que el usuario haya ingresado algo
        if (!nombre.empty()) {
            return nombre;
        }
        else {
            std::cerr << "Error: No has ingresado un nombre. Por favor, intenta de nuevo." << std::endl;
        }
    }
}

// Función para mostrar todos los nombres ingresados
void mostrarNombres(const std::vector<std::string>& nombres) {
    std::cout << "\nHas ingresado " << nombres.size() << " nombre(s):" << std::endl;
    for (const std::string& nombre : nombres) {
        std::cout << "- " << nombre << std::endl;
    }
}

// Función para mostrar un mensaje de despedida aleatorio
void mostrarDespedida() {
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
}

// Función principal del programa
int main() {
    std::vector<std::string> nombres;
    char opcion;

    do {
        // Obtener y validar el nombre del usuario
        std::string nombre = obtenerNombre();

        // Almacenar el nombre en la lista
        nombres.push_back(nombre);

        // Mostrar el saludo personalizado
        mostrarSaludo(nombre);

        // Preguntar al usuario si desea continuar
        std::cout << "¿Quieres ingresar otro nombre? (s/n): ";
        std::cin >> opcion;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el buffer de entrada

    } while (opcion == 's' || opcion == 'S');

    // Mostrar todos los nombres ingresados
    mostrarNombres(nombres);

    // Mostrar un mensaje de despedida aleatorio
    mostrarDespedida();

    return 0;
}
