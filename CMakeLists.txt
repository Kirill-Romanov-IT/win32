cmake_minimum_required(VERSION 3.24)
project ("coros" LANGUAGES CXX)

find_package(OpenGL REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Раздел GLFW ---

# Сделаем FetchContent "разговорчивым", чтобы видеть все его действия

include(FetchContent)

# Шаг 1: Объявляем, что такое glfw
FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG        3.4 
)

# Шаг 2: Принудительно скачиваем содержимое. 
# Мы знаем из наших тестов, что эта команда запускает git.
message(STATUS "ИСПОЛНЯЕТСЯ FetchContent_Populate(glfw)...")
FetchContent_Populate(glfw)
message(STATUS "ЗАВЕРШЕНО FetchContent_Populate(glfw).")

# Шаг 3: Явно добавляем скачанные исходники в нашу сборку.
# Переменная ${glfw_SOURCE_DIR} создается командой Populate.
# Именно эта команда должна создать цель glfw::glfw.
message(STATUS "ИСПОЛНЯЕТСЯ add_subdirectory для glfw...")
add_subdirectory(${glfw_SOURCE_DIR} ${glfw_BINARY_DIR})
message(STATUS "ЗАВЕРШЕНО add_subdirectory для glfw.")


# --- Раздел нашего приложения ---

# Шаг 4: Теперь, когда все зависимости готовы, определяем нашу программу
add_executable(coros
			WIN32
			"coros.cpp"
			"coros.h")

# Шаг 5: И, наконец, связываем ее с GLFW.
# Все должно быть на месте.
target_link_libraries(coros PRIVATE glfw OpenGL::GL)