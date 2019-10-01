#define GLEW_STATIC
#define GLFW_INCLUDE_NONE

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

#define OPTION_HORIZONTAL 1
#define OPTION_VERTICAL 2
#define OPTION_BORDERS 3
#define INCREMENT 0.01f

using namespace std;

void update_coordenates(int mode, float* xc, float* yc, int* mtx, int* mty);

int main(int argc, char** argv) {
  if (argc < 2) {
    cerr << "Usage: ./triangle <mode>" << endl;
    return EXIT_FAILURE;
  }

  int mode = stoi(argv[1]);

  if (mode < OPTION_HORIZONTAL || mode > OPTION_BORDERS) {
    cerr << "Invalid mode. Must be 1, 2 or 3." << endl;
    return EXIT_FAILURE;
  }

  GLFWwindow* window;

  // Inicializa a biblioteca.
  if (!glfwInit()) return EXIT_FAILURE;

  // Cria uma janela com contexto OpenGL.
  window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
  if (!window) {
    glfwTerminate();
    return EXIT_FAILURE;
  }

  // Ative o contexto OpenGL na janela.
  glfwMakeContextCurrent(window);

  if (glewInit() != GLEW_OK) {
    cout << "Erro ao iniciar o GLEW." << endl;
    return EXIT_FAILURE;
  }

  float xc = 0.0f, yc = 0.0f;
  int mtx = 1, mty = 1;

  if (OPTION_BORDERS == mode) {
    xc = -0.2f;
    yc = 0.1f;
  }

  // Roda até que o usuário feche a janela.
  while (!glfwWindowShouldClose(window)) {
    // Código de renderização do OpenGL.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Define a cor atual como sendo azul.
    glColor3f(0, 0, 1);
    // Definimos o estado de montagem de triângulos.
    glBegin(GL_TRIANGLES);
    glColor3f(0, 0, 1);
    glVertex2f(xc - 0.3f, yc - 0.3f);
    glColor3f(0, 1, 0);
    glVertex2d(xc + 0.0f, yc + 0.3f);
    glColor3f(1, 0, 0);
    glVertex2d(xc + 0.3f, yc - 0.3f);
    glEnd();

    // Altera o xc e yc dependendo do modo.
    update_coordenates(mode, &xc, &yc, &mtx, &mty);

    // Troca o buffer de fundo com o buffer de exibição.
    glfwSwapBuffers(window);
    // Captura e trata eventos do teclado.
    glfwPollEvents();
  }

  glfwTerminate();
  return EXIT_SUCCESS;
}

/**
 * Atualiza as coordenadas, sempre somando mtx * INCREMENT nas variáveis
 * utilizadas no modo escolhido. Quando o xc e/ou yc chegam aos extremos,
 * os multiplicadores associados a eles tem seus valores invertidos.
 *
 * @param mode modo de animação
 * @param xc posição em x
 * @param yc posição em y
 * @param mtx multiplicador do x
 * @param mty multiplicador do y
 */
void update_coordenates(int mode, float* xc, float* yc, int* mtx, int* mty) {
  if (mode == OPTION_BORDERS || mode == OPTION_HORIZONTAL) {
    *mtx = (*xc + 0.3f >= 1.0f) ? -1 : (*xc - 0.3f <= -1.0f ? 1 : *mtx);
    *xc += *mtx * INCREMENT;
  }

  if (mode == OPTION_BORDERS || mode == OPTION_VERTICAL) {
    *mty = (*yc + 0.3f >= 1.0f) ? -1 : (*yc - 0.3f <= -1.0f ? 1 : *mty);
    *yc += *mty * INCREMENT;
  }
}
