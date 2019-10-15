#define GLEW_STATIC
#define GLFW_INCLUDE_NONE

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string read_file(string filename);

int main(int argc, char** argv) {
  GLFWwindow* window;

  // Inicializa a biblioteca.
  if (!glfwInit()) return EXIT_FAILURE;

  // glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  // glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Cria uma janela com contexto OpenGL.
  window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
  if (!window) {
    glfwTerminate();
    return EXIT_FAILURE;
  }

  // Ative o contexto OpenGL na janela.
  glfwMakeContextCurrent(window);

  // glewExperimental = GL_TRUE;
  if (glewInit() != GLEW_OK) {
    cout << "Erro ao iniciar o GLEW." << endl;
    return EXIT_FAILURE;
  }

  float v[] = {
    +0.0, +0.5,
    -0.5, -0.5,
    +0.5, -0.5
  };

  // GLuint VBO, VAO;
  GLuint VBO1;
  glGenBuffers(1, &VBO1);
  glBindBuffer(GL_ARRAY_BUFFER, VBO1);
  glBufferData(GL_ARRAY_BUFFER, sizeof(v), v, GL_STATIC_DRAW);

  glVertexPointer(2, GL_FLOAT, 0, nullptr);
  glEnableClientState(GL_VERTEX_ARRAY);

  string vss = read_file("vertex.vert");
  string fss = read_file("fragment.frag");

  const char* vertexShaderText = vss.c_str();
  const char* fragmentShaderText = fss.c_str();

  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderText, nullptr);
  glCompileShader(vertexShader);

  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderText, nullptr);
  glCompileShader(fragmentShader);

  GLuint shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);

  glLinkProgram(shaderProgram);
  glUseProgram(shaderProgram);

  // Roda até que o usuário feche a janela.
  while (!glfwWindowShouldClose(window)) {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    // Desenha o triângulo.
    glDrawArrays(GL_TRIANGLES, 0, 3);

    // Troca o buffer de fundo com o buffer de exibição.
    glfwSwapBuffers(window);
    // Captura e trata eventos do teclado.
    glfwPollEvents();
  }

  glDeleteBuffers(1, &VBO1);

  glfwTerminate();
  return EXIT_SUCCESS;
}

string read_file(string filename) {
  ifstream t(filename);
  stringstream buffer;
  buffer << t.rdbuf();
  return buffer.str();
}
