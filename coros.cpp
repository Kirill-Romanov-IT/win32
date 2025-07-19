// ===== coros.cpp =====
#include <GLFW/glfw3.h>
#include <iostream>

#ifdef _WIN32                         // код нужен только под Windows
#include <windows.h>

// Предварительно объявляем main(), чтобы компилятор знал о нём
int main(int argc, char** argv);

// WinMain – точка входа для подсистемы WINDOWS, создаёт
// те же argc/argv и просто вызывает ваш привычный main().
int WINAPI WinMain(HINSTANCE /*hInst*/,
    HINSTANCE /*hPrev*/,
    LPSTR     /*lpCmdLine*/,
    int       /*nShowCmd*/)
{
    return main(__argc, __argv);
}
#endif  // _WIN32


int main(int /*argc*/, char** /*argv*/)
{
    // 1. Инициализация GLFW
    if (!glfwInit())
    {
        std::cerr << "Ошибка: не удалось инициализировать GLFW\n";
        return -1;
    }

    // Минимально требуемая версия OpenGL 3.3 Core
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // 2. Создание окна
    GLFWwindow* window = glfwCreateWindow(1200, 800, "Окно Coros", nullptr, nullptr);
    if (!window)
    {
        std::cerr << "Ошибка: не удалось создать окно GLFW\n";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // 3. Основной цикл приложения
    while (!glfwWindowShouldClose(window))
    {
        // Очистка экрана (фон – тёмно‑синий)
        glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Переключение кадров и обработка событий
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // 4. Освобождение ресурсов
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
