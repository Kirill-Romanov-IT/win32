# coros

This is a basic C++20 project that demonstrates how to set up a graphical application using GLFW and OpenGL. The project is built using CMake and is configured to run on Windows.

## Project Structure

- **`coros.cpp`**: Contains the main application logic, which initializes GLFW, creates a window with an OpenGL context, and runs a simple event loop.
- **`CMakeLists.txt`**: Manages the project's build process. It uses `FetchContent` to download and link the `GLFW` library and also links against `OpenGL`.
- **`glfw/`**: This directory contains the `GLFW` library, which is added to the project as a Git submodule.

## Features

- **Window Creation**: Creates a simple window with a resolution of 1200x800.
- **OpenGL Context**: Initializes an OpenGL 3.3 Core profile context.
- **Basic Render Loop**: The main loop clears the screen with a dark blue color and handles window events.
- **Windows Subsystem**: Includes a `WinMain` entry point, making it a proper Windows GUI application.

## How to Build

1.  **Clone the repository**:
    ```bash
    git clone https://github.com/Kirill-Romanov-IT/win32.git
    cd win32
    ```

2.  **Configure and build with CMake**:
    ```bash
    cmake -B build
    cmake --build build
    ```

3.  **Run the application**:
    The executable will be located in the `build/Debug` or `build/Release` directory.
    ```bash
    ./build/Debug/coros.exe
    ``` 