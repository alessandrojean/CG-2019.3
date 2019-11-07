#include <array>
#include <cmath>
#include <cstdio>
#include <iostream>

#define PI 3.14159265

using namespace std;

class mat33 {
  public:
    // Construtor
    mat33();
    // Destrutor
    ~mat33();

    // Ponteiro público para os elementos da matriz.
    const float *mptr;

    // Principais métodos.
    // Carrega a matriz identidade.
    void identity();
    // Multiplica a esquerda por uma matriz de rotação.
    void rotate(int degrees);
    // Multiplica a esquerda por uma matriz de translação.
    void translate(float dx, float dy);
    // Multiplica a esquerda por uma matriz de escala.
    void scale(float sx, float sy);
    // Imprime no console a matriz atual.
    void print();

  private:
    // Matriz (vetor) principal.
    array<float, 9> m;
    // Matriz (vetor) auxiliar.
    array<float, 9> maux;
};
