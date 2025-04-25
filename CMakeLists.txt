cmake_minimum_required(VERSION 3.20)
project(SolverDZ
    VERSION 1.0.0
    DESCRIPTION "Lab06 Solver Application"
    LANGUAGES CXX
)

# Базовые настройки
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Исходные файлы
file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

# Основной исполняемый файл
add_executable(solver ${SOURCES} ${HEADERS})

# Пути для include
target_include_directories(solver PUBLIC include)

# Установка
install(TARGETS solver DESTINATION bin)

# CPack конфигурация
set(CPACK_PACKAGE_NAME "${PROJECT_NAME}")
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_PACKAGE_DESCRIPTION "Equation solver for Lab06")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")

if(WIN32)
    set(CPACK_GENERATOR "ZIP;WIX")
elseif(APPLE)
    set(CPACK_GENERATOR "ZIP;DragNDrop")
else()
    set(CPACK_GENERATOR "TGZ;DEB;RPM")
endif()

include(CPack)
