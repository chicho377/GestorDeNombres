#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <algorithm> // Para usar std::find y std::remove
#include <cctype>    // Para usar std::toupper

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

// Función para mostrar todos los nombres ingresados ordenados alfabéticamente
void mostrarNombres(const std::vector<std::string>& nombres) {
    std::vector<std::string> nombresOrdenados = nombres;
    std::sort(nombresOrdenados.begin(), nombresOrdenados.end());

    std::cout << "\nHas ingresado " << nombresOrdenados.size() << " nombre(s) ordenados alfabéticamente:" << std::endl;
    for (const std::string& nombre : nombresOrdenados) {
        std::cout << "- " << nombre << std::endl;
    }
}

// Función para mostrar la longitud promedio de los nombres ingresados
void mostrarLongitudPromedio(const std::vector<std::string>& nombres) {
    if (nombres.empty()) {
        std::cout << "No se ingresaron nombres, no se puede calcular la longitud promedio." << std::endl;
        return;
    }

    int totalCaracteres = 0;
    for (const std::string& nombre : nombres) {
        totalCaracteres += nombre.length();
    }

    double promedio = static_cast<double>(totalCaracteres) / nombres.size();
    std::cout << "La longitud promedio de los nombres ingresados es: " << promedio << " caracteres." << std::endl;
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

// Función para buscar un nombre en la lista
bool buscarNombre(const std::vector<std::string>& nombres, const std::string& nombreBuscado) {
    auto it = std::find(nombres.begin(), nombres.end(), nombreBuscado);
    return it != nombres.end();
}

// Función para eliminar un nombre de la lista
void eliminarNombre(std::vector<std::string>& nombres, const std::string& nombreEliminar) {
    auto it = std::remove(nombres.begin(), nombres.end(), nombreEliminar);
    nombres.erase(it, nombres.end());
}

// Función para contar cuántos nombres empiezan con una letra específica
int contarNombresPorLetra(const std::vector<std::string>& nombres, char letra) {
    letra = std::toupper(letra);
    int contador = 0;
    for (const std::string& nombre : nombres) {
        if (std::toupper(nombre.front()) == letra) {
            contador++;
        }
    }
    return contador;
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

    // Mostrar todos los nombres ingresados ordenados alfabéticamente
    mostrarNombres(nombres);

    // Mostrar la longitud promedio de los nombres ingresados
    mostrarLongitudPromedio(nombres);

    // Opciones adicionales: buscar y eliminar un nombre
    std::string nombreBuscar;
    std::cout << "\n¿Deseas buscar un nombre específico en la lista? (Ingrese el nombre o vacío para saltar): ";
    std::getline(std::cin, nombreBuscar);

    if (!nombreBuscar.empty()) {
        if (buscarNombre(nombres, nombreBuscar)) {
            std::cout << "El nombre '" << nombreBuscar << "' está en la lista." << std::endl;
        }
        else {
            std::cout << "El nombre '" << nombreBuscar << "' no está en la lista." << std::endl;
        }
    }

    std::string nombreEliminar;
    std::cout << "\n¿Deseas eliminar un nombre de la lista? (Ingrese el nombre o vacío para saltar): ";
    std::getline(std::cin, nombreEliminar);

    if (!nombreEliminar.empty()) {
        eliminarNombre(nombres, nombreEliminar);
        std::cout << "Nombre '" << nombreEliminar << "' eliminado de la lista." << std::endl;
    }

    // Contar cuántos nombres empiezan con una letra específica
    char letraBuscar;
    std::cout << "\nIngrese una letra para contar cuántos nombres empiezan con esa letra: ";
    std::cin >> letraBuscar;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el buffer de entrada

    int cantidadNombresPorLetra = contarNombresPorLetra(nombres, letraBuscar);
    std::cout << "Cantidad de nombres que empiezan con '" << letraBuscar << "': " << cantidadNombresPorLetra << std::endl;

    // Mostrar un mensaje de despedida aleatorio
    mostrarDespedida();

    return 0;
}
