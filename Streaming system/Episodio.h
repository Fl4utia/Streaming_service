#include "Video.h"

class Episodio : public Video {
  private:
    string serieNom;
    int numEpi;
    int temporadaEpi;

  public:
    Episodio();
    Episodio(int id, string titulo, string genero, int duracion, int calificacion, string serieNom, int numEpi, int temporadaEpi);

    void setSerieNom(string serieNom);
    void setNumEpi(int numEpi);
    void setTemporadaEpi(int temporadaEpi);
  
    string getSerieNom();
    int getNumEpi();
    int getTemporadaEpi();
  
    string mostrar() override;
};

