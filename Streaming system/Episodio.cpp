#include "Episodio.h"

Episodio::Episodio()
    : Video(), serieNom("Kardashians"), numEpi(0), temporadaEpi(0) {}

Episodio::Episodio(int id, string titulo, string genero, int duracion, int calificacion, string serieNom, int numEpi, int temporadaEpi): Video(id, titulo, genero, duracion, calificacion), serieNom(serieNom), numEpi(numEpi), temporadaEpi(temporadaEpi) {}

void Episodio::setSerieNom(std::string serieNom) {
    this->serieNom = serieNom;
}

void Episodio::setNumEpi(int numEpi) {
    this->numEpi = numEpi;
}

void Episodio::setTemporadaEpi(int temporadaEpi) {
    this->temporadaEpi = temporadaEpi;
}

std::string Episodio::getSerieNom() {
    return serieNom;
}

int Episodio::getNumEpi() {
    return numEpi;
}

int Episodio::getTemporadaEpi() {
    return temporadaEpi;
}

std::string Episodio::mostrar() {
    std::string detallesVideo = to_string(id) + " " + titulo + " " + genero + " "+ to_string(duracion) + " " + to_string(calificacion);
    return string("e") + " "+ detallesVideo + " " + serieNom + " " + to_string(numEpi) + " " + to_string(temporadaEpi);
}
