#ifndef PELICULA_H
#define PELICULA_H

#include "Video.h"

class Pelicula : public Video {
public:
    Pelicula();
    Pelicula(int id, std::string titulo, string genero, int duracion, int calificacion);
    string mostrar() override;
};

#endif
