cmake_minimum_required(VERSION 3.10)
project(V64Engine VERSION 1.0 LANGUAGES CXX)

# Вказуємо стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Додаємо бібліотеки
add_library(glfw STATIC IMPORTED)
set_target_properties(glfw PROPERTIES IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/Libraries/lib/glfw3.lib")

# Знаходимо OpenGL
find_package(OpenGL REQUIRED)

# Додаємо нашу бібліотеку
add_library(V64Engine STATIC
        glad.c
        core/window.cpp
        core/event.cpp
        core/render.cpp
        game/object.cpp
        include/window.h
        include/event.h
        include/render.h
        include/object.h
        include/camera.h
        game/camera.cpp
)

# Вказуємо шляхи до заголовкових файлів
target_include_directories(V64Engine PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/core>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/game>
        $<INSTALL_INTERFACE:include/>
)

# Вказуємо шлях до заголовкових файлів бібліотек
target_include_directories(V64Engine PRIVATE
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/Libraries/include>
        ${OPENGL_INCLUDE_DIRS}
)

# Лінкуємо додаткові бібліотеки
target_link_libraries(V64Engine PRIVATE
        glfw
        ${OPENGL_LIBRARIES}
)

# Налаштування встановлення
install(TARGETS V64Engine
        EXPORT V64EngineTargets
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
)

# Встановлення заголовкових файлів
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/ DESTINATION include/ FILES_MATCHING PATTERN "*.h")
install(DIRECTORY ${CMAKE_SOURCE_DIR}/Libraries/include/ DESTINATION include/ FILES_MATCHING PATTERN "*.*")
install(DIRECTORY ${CMAKE_SOURCE_DIR}/Libraries/lib/ DESTINATION lib/ FILES_MATCHING PATTERN "*.lib")
install(DIRECTORY ${CMAKE_SOURCE_DIR}/Libraries/lib/ DESTINATION lib/ FILES_MATCHING PATTERN "*.pdb")

# Генерація файлів конфігурації
install(EXPORT V64EngineTargets
        FILE V64EngineTargets.cmake
        NAMESPACE V64Engine::
        DESTINATION lib/cmake/V64Engine
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/V64EngineConfigVersion.cmake"
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY AnyNewerVersion
)

configure_file(V64EngineConfig.cmake.in
        "${CMAKE_CURRENT_BINARY_DIR}/V64EngineConfig.cmake"
        @ONLY
)

install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/V64EngineConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/V64EngineConfigVersion.cmake"
        DESTINATION lib/cmake/V64Engine
)
