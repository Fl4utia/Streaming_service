#include "Pelicula.h"

Pelicula::Pelicula() {}

Pelicula::Pelicula(int id, string titulo, string genero, int duracion, int calificacion)
    : Video(id, titulo, genero, duracion, calificacion) {}

std::string Pelicula::mostrar() {
    return string("p") + " " + to_string(id) + " " + titulo + " " + genero + " "+ to_string(duracion) + " " + to_string(calificacion);
}