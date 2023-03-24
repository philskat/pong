
# Pong

A small 2D game engine using OpenGL with the example game pong.

This engine is still heavily in devlopment.


## Acknowledgements

Libraries used in this project

- [GLFW](https://github.com/glfw/glfw) - Windows and Input
- [GLEW](https://github.com/nigels-com/glew) - OpenGL Extensions (Use of [Perlmint/glew-cmake](https://github.com/Perlmint/glew-cmake) for CMake support)
- [GLM](https://github.com/g-trunc/glm) - OpenGL Maths (Vectors, Matrix...)
- [ImGui](https://github.com/ocornut/imgui) - Used for debug menu


## Run Locally

Clone the project

```bash
  git clone https://github.com/philskat/pong
```

Go to the project directory

```bash
  cd pong
```

Run [CMake](https://cmake.org) (needs to be installed alongside a C++ compiler like GCC or MSBuild)

```bash
  cmake -S . -B build
```

Build the Project through the selected IDE (Visual Studio on Windows) or run the make files in the build directory:

```bash
  cd build
  make
```

Alternativly you can run this command to build the project

```bash
  cmake --build build
```

The executable will be located in `build/game` exact placement depends on the build tool.

Visual Studio places the output under `build/game/Debug` \
Make will put the output in `build/game`

## Debug tools
To enable Debug tools with [ImGui](https://github.com/ocornut/imgui) you can run the following command to setup the workspace

```bash
  cmake -S . -B build -DPONGGAME_DEBUG=ON
```

Alternativly you can just change the variable in the `build/CMakeCache.txt` file. Just replace `OFF` in the following line with `ON`.

```
  PONGGAME_DEBUG:BOOL=OFF
```
