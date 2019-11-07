#define GLEW_STATIC
#define GLFW_INCLUDE_NONE

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

using namespace std;

void key_callback(GLFWwindow*, int, int, int, int);

float xc = 0.0f, yc = 0.0f;

int main(int argc, char** argv) {
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

  glfwSetKeyCallback(window, key_callback);

  // Roda até que o usuário feche a janela.
  while (!glfwWindowShouldClose(window)) {
    // Código de renderização do OpenGL.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Define a cor atual como sendo azul.
    glColor3f(0, 0, 1);
    // Definimos o estado de montagem de triângulos.
    glBegin(GL_TRIANGLES);
    glColor3f(0, 0, 1);
    glVertex2f(xc - 0.5f, yc - 0.5f);
    glColor3f(0, 1, 0);
    glVertex2d(xc + 0.0f, yc + 0.5f);
    glColor3f(1, 0, 0);
    glVertex2d(xc + 0.5f, yc - 0.5f);
    glEnd();
    // Troca o buffer de fundo com o buffer de exibição.
    glfwSwapBuffers(window);
    // Captura e trata eventos do teclado.
    glfwPollEvents();
  }

  glfwTerminate();
  return EXIT_SUCCESS;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
  if (key == GLFW_KEY_LEFT) xc = xc - 0.01;
  if (key == GLFW_KEY_RIGHT) xc = xc + 0.01;
  if (key == GLFW_KEY_UP) yc = yc + 0.01;
  if (key == GLFW_KEY_DOWN) yc = yc - 0.01;
}
