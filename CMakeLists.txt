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
    set(CPACK_GENERATOR "ZIP;WIX")
    set(CPACK_WIX_PRODUCT_GUID "653cd22f-cbc0-43d7-a59b-e2af6ad931f7")
    set(CPACK_WIX_UPGRADE_GUID "d4e5f6a7-b8c9-4d0e-a1b2-c3d4e5f6a7b8")
elseif(APPLE)
    set(CPACK_GENERATOR "ZIP")  # DragNDrop требует background.png
else()
    set(CPACK_GENERATOR "TGZ;DEB")
    set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Maintainer <maintainer@example.com>")
    set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6 (>= 2.14)")
endif()

include(CPack)
