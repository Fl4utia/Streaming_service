#ifndef VIDEO_H
#define VIDEO_H
#include <iostream>
using namespace std;
#include <string>

class Video {
protected:
    int id;
    string titulo;
    int duracion;
    string genero;
    int calificacion;
    int numCalificaciones;

public:
    Video();
    Video(int id, string titulo,string genero, int duracion, int calificacion);

//SETTERS
    void setID(int id);
    void setTitulo(string titulo);
    void setDuracion(int duracion);
    void setGenero(string genero);
    void setCalificacion(int calificacion);
  
//GETTERS
    int getID();
    string getTitulo();
    int getDuracion();
    string getGenero();
    int getCalificacion();
// clase abstracta debido a la función virtual pura mostrar() esta se implementa en Pelicula y Episodio
    virtual string mostrar()=0;
    void operator+(int nuevaCalificacion);
};

#endif


