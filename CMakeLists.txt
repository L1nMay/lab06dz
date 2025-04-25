cmake_minimum_required(VERSION 3.20)
project(Solver
    VERSION 1.0.0
    DESCRIPTION "Equation Solver Application"
    LANGUAGES CXX
)

# Настройки компилятора
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# Исходные файлы
set(SOURCES src/main.cpp)
set(HEADERS include/solver.h)

# Исполняемый файл
add_executable(solver ${SOURCES} ${HEADERS})
target_include_directories(solver PUBLIC include)
target_link_libraries(solver PUBLIC m)  # Для Linux: связываем с математической библиотекой

# Установка
install(TARGETS solver DESTINATION bin)

# Настройки CPack
set(CPACK_PACKAGE_NAME "${PROJECT_NAME}")
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_PACKAGE_DESCRIPTION "Simple equation solver")
set(CPACK_PACKAGE_VENDOR "Your Organization")
set(CPACK_PACKAGE_CONTACT "contact@example.com")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")

# Платформозависимые настройки
if(WIN32)
    set(CPACK_GENERATOR "ZIP")
elseif(APPLE)
    set(CPACK_GENERATOR "ZIP")
else()
    set(CPACK_GENERATOR "TGZ")
endif()

include(CPack)
