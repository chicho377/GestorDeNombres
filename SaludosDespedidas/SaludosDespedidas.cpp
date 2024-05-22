#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <algorithm>
#include <cctype>

// Funci�n que muestra un saludo personalizado
void mostrarSaludo(const std::string& nombre) {
    std::cout << "Hola, " << nombre << "! Bienvenido al programa en C++." << std::endl;
}

// Funci�n para obtener y validar el nombre del usuario
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

// Funci�n para mostrar todos los nombres ingresados ordenados alfab�ticamente
void mostrarNombres(const std::vector<std::string>& nombres) {
    std::vector<std::string> nombresOrdenados = nombres;
    std::sort(nombresOrdenados.begin(), nombresOrdenados.end());

    std::cout << "\nHas ingresado " << nombresOrdenados.size() << " nombre(s) ordenados alfab�ticamente:" << std::endl;
    for (const std::string& nombre : nombresOrdenados) {
        std::cout << "- " << nombre << std::endl;
    }
}

// Funci�n para mostrar la longitud promedio de los nombres ingresados
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

// Funci�n para mostrar un mensaje de despedida aleatorio
void mostrarDespedida(const std::string& ultimoNombre) {
    std::vector<std::string> despedidas = {
        "�Hasta luego!",
        "�Que tengas un gran d�a!",
        "�Adi�s y cu�date!",
        "�Nos vemos pronto, " + ultimoNombre + "!",
        "�Fue un placer verte, " + ultimoNombre + "!"
    };

    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Semilla para generar n�meros aleatorios
    int indice = std::rand() % despedidas.size();
    std::cout << "\nGracias por usar el programa. " << despedidas[indice] << std::endl;
}

// Funci�n para buscar un nombre en la lista
bool buscarNombre(const std::vector<std::string>& nombres, const std::string& nombreBuscado) {
    auto it = std::find(nombres.begin(), nombres.end(), nombreBuscado);
    return it != nombres.end();
}

// Funci�n para eliminar un nombre de la lista
void eliminarNombre(std::vector<std::string>& nombres, const std::string& nombreEliminar) {
    auto it = std::remove(nombres.begin(), nombres.end(), nombreEliminar);
    nombres.erase(it, nombres.end());
}

// Funci�n para contar cu�ntos nombres empiezan con una letra espec�fica
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

// Funci�n para buscar nombres por longitud
std::vector<std::string> buscarNombresPorLongitud(const std::vector<std::string>& nombres, int longitud) {
    std::vector<std::string> nombresEncontrados;
    for (const std::string& nombre : nombres) {
        if (nombre.length() == longitud) {
            nombresEncontrados.push_back(nombre);
        }
    }
    return nombresEncontrados;
}

// Funci�n para validar una entrada num�rica
int validarEntradaNumerica() {
    int valor;
    while (true) {
        std::cout << "Ingrese un n�mero: ";
        if (std::cin >> valor) {
            break;
        }
        else {
            std::cout << "Entrada inv�lida. Intente nuevamente." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return valor;
}

// Funci�n para validar las opciones del men�
char validarOpcionMenu(const std::string& opcionesValidas) {
    char opcion;
    while (true) {
        std::cout << "Ingrese una opci�n (" << opcionesValidas << "): ";
        std::cin >> opcion;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el buffer de entrada
        opcion = std::toupper(opcion);
        if (opcionesValidas.find(opcion) != std::string::npos) {
            break;
        }
        else {
            std::cout << "Opci�n inv�lida. Intente nuevamente." << std::endl;
        }
    }
    return opcion;
}

// Funci�n para guardar los nombres en un archivo de texto
void guardarNombresEnArchivo(const std::vector<std::string>& nombres, const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo para guardar los nombres." << std::endl;
        return;
    }

    for (const std::string& nombre : nombres) {
        archivo << nombre << std::endl;
    }

    archivo.close();
    std::cout << "Los nombres se han guardado correctamente en el archivo '" << nombreArchivo << "'." << std::endl;
}

// Funci�n para cargar nombres desde un archivo de texto
std::vector<std::string> cargarNombresDesdeArchivo(const std::string& nombreArchivo) {
    std::vector<std::string> nombres;
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo para cargar los nombres." << std::endl;
        return nombres;
    }

    std::string nombre;
    while (std::getline(archivo, nombre)) {
        nombres.push_back(nombre);
    }

    archivo.close();
    std::cout << "Los nombres se han cargado correctamente desde el archivo '" << nombreArchivo << "'." << std::endl;
    return nombres;
}

// Funci�n principal del programa
int main() {
    std::vector<std::string> nombres;
    char opcion;

    do {
        mostrarSaludo("Usuario"); // Cambiar "Usuario" por un nombre ficticio

        // Mostrar un men� de opciones
        std::cout << "\n=== Men� ===" << std::endl;
        std::cout << "1. Ingresar un nombre" << std::endl;
        std::cout << "2. Mostrar todos los nombres" << std::endl;
        std::cout << "3. Mostrar la longitud promedio de los nombres" << std::endl;
        std::cout << "4. Buscar un nombre en la lista" << std::endl;
        std::cout << "5. Eliminar un nombre de la lista" << std::endl;
        std::cout << "6. Contar cu�ntos nombres empiezan con una letra espec�fica" << std::endl;
        std::cout << "7. Buscar nombres por longitud" << std::endl;
        std::cout << "8. Guardar los nombres en un archivo" << std::endl;
        std::cout << "9. Cargar nombres desde un archivo" << std::endl;
        std::cout << "0. Salir" << std::endl;

        opcion = validarOpcionMenu("0123456789");

        switch (opcion) {
        case '1': {
            // Obtener y validar el nombre
            std::string nombre = obtenerNombre();
            nombres.push_back(nombre);
            std::cout << "Nombre '" << nombre << "' agregado correctamente." << std::endl;
            break;
        }
        case '2': {
            // Mostrar todos los nombres ingresados
            if (nombres.empty()) {
                std::cout << "No hay nombres ingresados para mostrar." << std::endl;
            }
            else {
                mostrarNombres(nombres);
            }
            break;
        }
        case '3': {
            // Mostrar la longitud promedio de los nombres ingresados
            mostrarLongitudPromedio(nombres);
            break;
        }
        case '4': {
            // Buscar un nombre en la lista
            std::string nombreBuscar;
            std::cout << "Ingrese el nombre que desea buscar: ";
            std::getline(std::cin, nombreBuscar);

            if (buscarNombre(nombres, nombreBuscar)) {
                std::cout << "El nombre '" << nombreBuscar << "' se encuentra en la lista." << std::endl;
            }
            else {
                std::cout << "El nombre '" << nombreBuscar << "' no se encuentra en la lista." << std::endl;
            }
            break;
        }
        case '5': {
            // Eliminar un nombre de la lista
            if (nombres.empty()) {
                std::cout << "No hay nombres para eliminar." << std::endl;
                break;
            }

            std::string nombreEliminar;
            std::cout << "Ingrese el nombre que desea eliminar: ";
            std::getline(std::cin, nombreEliminar);

            eliminarNombre(nombres, nombreEliminar);
            std::cout << "Nombre '" << nombreEliminar << "' eliminado correctamente." << std::endl;
            break;
        }
        case '6': {
            // Contar cu�ntos nombres empiezan con una letra espec�fica
            char letraBuscar;
            std::cout << "Ingrese la letra por la que desea buscar: ";
            std::cin >> letraBuscar;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el buffer de entrada

            int cantidadNombresPorLetra = contarNombresPorLetra(nombres, letraBuscar);
            std::cout << "Cantidad de nombres que empiezan con '" << letraBuscar << "': " << cantidadNombresPorLetra << std::endl;
            break;
        }
        case '7': {
            // Buscar nombres por longitud
            int longitudBuscar;
            std::cout << "Ingrese la longitud que desea buscar: ";
            longitudBuscar = validarEntradaNumerica();

            std::vector<std::string> nombresPorLongitud = buscarNombresPorLongitud(nombres, longitudBuscar);
            if (nombresPorLongitud.empty()) {
                std::cout << "No se encontraron nombres con longitud " << longitudBuscar << "." << std::endl;
            }
            else {
                std::cout << "Nombres con longitud " << longitudBuscar << ":" << std::endl;
                for (const std::string& nombre : nombresPorLongitud) {
                    std::cout << "- " << nombre << std::endl;
                }
            }
            break;
        }
        case '8': {
            // Guardar los nombres en un archivo
            if (nombres.empty()) {
                std::cout << "No hay nombres para guardar." << std::endl;
                break;
            }

            std::string nombreArchivo;
            std::cout << "Ingrese el nombre del archivo donde desea guardar los nombres: ";
            std::getline(std::cin, nombreArchivo);

            guardarNombresEnArchivo(nombres, nombreArchivo);
            break;
        }
        case '9': {
            // Cargar nombres desde un archivo
            std::string nombreArchivo;
            std::cout << "Ingrese el nombre del archivo desde donde desea cargar los nombres: ";
            std::getline(std::cin, nombreArchivo);

            std::vector<std::string> nombresCargados = cargarNombresDesdeArchivo(nombreArchivo);
            if (!nombresCargados.empty()) {
                std::cout << "Nombres cargados desde el archivo:" << std::endl;
                for (const std::string& nombre : nombresCargados) {
                    std::cout << "- " << nombre << std::endl;
                }
                // Combinar los nombres cargados con los nombres existentes
                nombres.insert(nombres.end(), nombresCargados.begin(), nombresCargados.end());
                std::cout << "Se han combinado los nombres cargados con los existentes." << std::endl;
            }
            else {
                std::cout << "No se pudieron cargar nombres desde el archivo." << std::endl;
            }
            break;
        }
        case '0': {
            // Salir del programa
            std::cout << "Saliendo del programa..." << std::endl;
            break;
        }
        default:
            std::cout << "Opci�n no v�lida." << std::endl;
            break;
        }

    } while (opcion != '0');

    // Mostrar un mensaje de despedida aleatorio basado en el �ltimo nombre ingresado
    if (!nombres.empty()) {
        mostrarDespedida(nombres.back());
    }
    else {
        std::cout << "\nGracias por usar el programa." << std::endl;
    }

    return 0;
}
