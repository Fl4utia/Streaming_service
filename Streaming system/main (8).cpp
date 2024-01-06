//Claudia Ximena Tobias Garcia a00837960

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "Video.h"  
#include "Pelicula.h"  
#include "Episodio.h"  

using namespace std;

//Función para mostrar el menu de opciones
void mostrarMenu() {
    cout << "------------- MENU -------------" << endl;
    cout << "1. Cargar archivo de videos" << endl;
    cout << "2.  Mostrar los videos en general con una cierta calificación o de un cierto género" << endl;
    cout << "3. Mostrar los episodios de una determinada serie con una calificacion determinada" << endl;
    cout << "4. Mostrar películas por calificación" << endl;
    cout << "5. Calificar video" << endl;
    cout << "0. Salir" << endl;
    cout << "Ingrese una opción: ";
}

// Implemento una funcion para cargar un archivo y los videos a partir de un input que otorga el usuario
void cargarArchivo(vector<Video*>& videos) {
    string nombreArchivo;
    cout << "Ingrese el nombre del archivo: ";
    cin >> nombreArchivo;

    ifstream archivo(nombreArchivo);

    if (!archivo) {
        cout << "Error " << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string tipo;
        ss >> tipo;

        if (tipo == "p") {
            int id, duracion, calificacion;
            string titulo, genero;
            ss >> id >> titulo >> genero >> duracion >> calificacion;
            videos.push_back(new Pelicula(id, titulo, genero, duracion, calificacion));
        } else if (tipo == "e") {
            int id, duracion, calificacion, numEpi, temporadaEpi;
            string titulo, genero, serieNom;
            ss >> id >> titulo >> genero >> duracion >> calificacion >> serieNom >> numEpi >> temporadaEpi;
            videos.push_back(new Episodio(id, titulo, genero, duracion, calificacion, serieNom, numEpi, temporadaEpi));
        }
    }
}

//Funcion para mostrar los videos cargados
void mostrarVideos(const vector<Video*>& videos) {
    if (videos.empty()) {
        cout << "No hay videos cargados." << endl;
        return;
    }

    cout << "Listado de videos:" << endl;
    for (const auto& video : videos) {
        cout << video->mostrar() << endl;  
    }
}

//Funcion para mostrar los videos por genero
void mostrarVideosPorGenero(const vector<Video*>& videos) {
    string genero;
    cout << "Ingresa alguno de los siguientes géneros: Comedia, Drama, Ciencia_ficción, Romance, Terror, Fantasía, Aventura, Animación, Suspenso" << endl;
    cin >> genero;

    // Validar si el género ingresado es válido
    if (genero != "Comedia" && genero != "Drama" && genero != "Ciencia_ficción" && genero != "Romance" && genero != "Terror" &&
        genero != "Fantasía" && genero != "Aventura" && genero != "Animación" && genero != "Suspenso") {
        cout << "Género inválido." << endl;
        return;
    }

    cout << "Videos con género " << genero << ":" << endl;
    bool foundVideos = false;
    for (const auto& video : videos) {
        if (video->getGenero() == genero) {
            cout << video->mostrar() << endl;
            foundVideos = true;
        }
    }

    if (!foundVideos) {
        cout << "No se encontraron videos con el género especificado." << endl;
    }
}

// Funcion para mostrar videos por calificacion
void mostrarVideosPorCalificacion(const vector<Video*>& videos) {
    int calificacion;
    cout << "Ingresa una calificación (1-5): ";
    cin >> calificacion;

    // Validar si la calificación ingresada es válida
    if (calificacion < 1 || calificacion > 5) {
        cout << "Calificación inválida." << endl;
        return;
    }

    cout << "Videos con calificación " << calificacion << ":" << endl;
    bool foundVideos = false;
    for (const auto& video : videos) {
        if (video->getCalificacion() == calificacion) {
            cout << video->mostrar() << endl;
            foundVideos = true;
        }
    }

    if (!foundVideos) {
        cout << "No se encontraron videos con la calificación especificada." << endl;
    }
}

//Mostramos los episodios de una serie especifica por calificacion
void mostrarEpisodiosDeSeriePorCalificacion(const vector<Video*>& videos) {
    string serieNom;
    cout << "Ingresa el nombre de la serie: ";
    cin >> serieNom;

    // Verificar si la serie existe
    bool serieExists = false;
    for (const auto& video : videos) {
        if (dynamic_cast<Episodio*>(video) != nullptr) {  // Comprueba si el objeto es de tipo Episodio
            Episodio* episodio = dynamic_cast<Episodio*>(video);  // Realiza un casting a Episodio
            if (episodio->getSerieNom() == serieNom) {
                serieExists = true;
                break;
            }
        }
    }

    if (!serieExists) {
        cout << "La serie especificada no existe." << endl;
        return;
    }

    int calificacion;
    cout << "Ingresa una calificación (1-5): ";
    cin >> calificacion;

    // Validar si la calificación ingresada es válida
    if (calificacion < 1 || calificacion > 5) {
        cout << "Calificación inválida." << endl;
        return;
    }

    cout << "Episodios de la serie " << serieNom << " con calificación " << calificacion << ":" << endl;
    bool foundEpisodes = false;
    for (const auto& video : videos) {
        if (dynamic_cast<Episodio*>(video) != nullptr) {
            Episodio* episodio = dynamic_cast<Episodio*>(video);  // Realiza un casting a Episodio
            if (episodio->getSerieNom() == serieNom && episodio->getCalificacion() == calificacion) {
                cout << episodio->mostrar() << endl;
                foundEpisodes = true;
            }
        }
    }
    if (!foundEpisodes) {
        cout << "No se encontraron episodios de la serie con la calificación especificada." << endl;
    }
}

//Funcion para mostrar Peliuclas por calificacion
void mostrarPeliculasPorCalificacion(const vector<Video*>& videos) {
    int calificacion;
    cout << "Ingresa una calificación (1-5): ";
    cin >> calificacion;

    // Validar si la calificación ingresada es válida
    if (calificacion < 1 || calificacion > 5) {
        cout << "Calificación inválida." << endl;
        return;
    }

    cout << "Películas con calificación " << calificacion << ":" << endl;
    bool foundMovies = false;
    for (const auto& video : videos) {
        if (dynamic_cast<Pelicula*>(video) != nullptr) {  // Comprueba si el objeto es de tipo Pelicula
            Pelicula* pelicula = dynamic_cast<Pelicula*>(video);  // Realiza un casting a Pelicula
            if (pelicula->getCalificacion() == calificacion) {
                cout << pelicula->mostrar() << endl;
                foundMovies = true;
            }
        }
    }

    if (!foundMovies) {
        cout << "No se encontraron películas con la calificación especificada." << endl;
    }
}

//Funcion para calificar videos
void calificarVideo(vector<Video*>& videos) {
    string titulo;
    cout << "Ingrese el título del video a calificar: ";
    cin.ignore();
    getline(cin, titulo);

    // Buscar el video con el título especificado
    Video* videoCalificar = nullptr;
    for (const auto& video : videos) {
        if (video->getTitulo() == titulo) {
            videoCalificar = video;
            break;
        }
    }

    if (videoCalificar == nullptr) {
        cout << "No se encontró ningún video con el título especificado." << endl;
        return;
    }

    int calificacion;
    cout << "Ingrese la calificación para el video (1-5): ";
    cin >> calificacion;

    // Validar si la calificación ingresada es válida
    if (calificacion < 1 || calificacion > 5) {
        cout << "Calificación inválida." << endl;
        return;
    }

    (*videoCalificar) + calificacion; // Utilizamos  la sobrecarga del operador '+'
    cout << "El video \"" << videoCalificar->getTitulo() << "\" ha sido calificado con éxito." << endl;
}

int main() {
    vector<Video*> videos;  // Vector para almacenar los punteros a objetos de tipo Video
    int choice;
    int opcion = -1;
    while (opcion != 0) {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                cargarArchivo(videos);
                mostrarVideos(videos);  
                break;
            case 2:
              cout << "Videos por 1.-Genero o 2.-Calificacion" << endl;
              cin >> choice;
              if (choice == 1) {
                  mostrarVideosPorGenero(videos);
              } else if (choice == 2) {
                  mostrarVideosPorCalificacion(videos);
              } else {
                  cout << "Opción inválida. Intente nuevamente." << endl;
              }
          break;
            case 3:
                mostrarEpisodiosDeSeriePorCalificacion(videos);
                break;
            case 4:
                mostrarPeliculasPorCalificacion(videos);
                break;
            case 5:
                calificarVideo(videos);
                break;
            case 0:
                break;
            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
                break;
        }
    }
    return 0;
}