#include "Video.h"
#include <iostream>
#include <cmath>
using namespace std;
Video::Video() {
    id = 1;
    titulo = "Evangelion";
    genero = "Drama";
    duracion = 120;
    calificacion = 5;
}

Video::Video(int id, std::string titulo, std::string genero, int duracion, int calificacion) {
  this->id = id;
  this->titulo = titulo;
  this->genero = genero;
  this->duracion = duracion;
  this->calificacion = calificacion;
  this->numCalificaciones = 1;
}

void Video::setID(int id) {
    this->id = id;
}

void Video::setTitulo(std::string titulo) {
    this->titulo = titulo;
}

void Video::setDuracion(int duracion) {
    this->duracion = duracion;
}

void Video::setGenero(std::string genero) {
    this->genero = genero;
}

void Video::setCalificacion(int calificacion) {
    this->calificacion = calificacion;
}

int Video::getID() {
    return id;
}

std::string Video::getTitulo() {
    return titulo;
}

int Video::getDuracion() {
    return duracion;
}

std::string Video::getGenero() {
    return genero;
}

int Video::getCalificacion() {
    return calificacion;
}

// Sobrecarga del operador + 
void Video::operator+(int nuevaCalificacion) {
    int totalCalificaciones = (calificacion * numCalificaciones) + nuevaCalificacion;
    numCalificaciones++;
    calificacion = floor(totalCalificaciones / numCalificaciones);
}