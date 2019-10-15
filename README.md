# CG-2019.3
![Year][year] ![Id][id] ![T-P-I][tpi]

Repository for the code written in the discipline of
Computer Graphics (*Computação Gráfica*) at the
Federal University of ABC (UFABC).

[year]: https://flat.badgen.net/badge/year/2019.3/blue
[id]: https://flat.badgen.net/badge/id/MCTA008-13/orange
[tpi]: https://flat.badgen.net/badge/T-P-I/3-1-4/grey

## Schedule

- **24/09/2019** *(Theory)*: Introduction and Graphic Primitives.
- **01/10/2019** *(Laboratory)*: [Math Review and Implementation].
- **03/10/2019** *(Theory)*: Linear Algebra Review.
- **08/10/2019** *(Theory)*: Transformation matrices.
- **10/10/2019** *(Theory)*: Raster images.
- **15/10/2019** *(Laboratory)*: [Vertex Buffer Objects and Shaders].

[Math Review and Implementation]: laboratory/2019.10.01/
[Vertex Buffer Objects and Shaders]: laboratory/2019.10.15/

## Build instructions

The codes available in this repository uses [OpenGL], [GLFW] and [GLEW], so
first make sure you have the dependencies installed in your machine. You
can use the commands bellow to install them in a Linux distribution.

```bash
# If you use a debian-based distribution.
$ sudo apt-get install mesa-utils libglew-dev libglfw3 libglfw3-dev
# If you use a arch-based distribution.
$ sudo pacman -S mesa-demos glfw glew
```

To compile any project, just go to the correct folder and use `make`.
The executable will be generated at the `bin` folder.

[OpenGL]: https://www.opengl.org/
[GLFW]: https://www.glfw.org/download.html
[GLEW]: http://glew.sourceforge.net/

## Bibliography

- Shirley, P. et al. **Fundamentals of computer graphics**, 3rd edition.
  Wellesley: A K PETERS, 2009.

## License

> You can check out the full license [here](LICENSE).

This repository is licensed under the terms of the **MIT** license.
