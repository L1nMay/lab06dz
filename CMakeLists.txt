cmake_minimum_required(VERSION 3.20)
project(Solver
    VERSION 1.0.0
    DESCRIPTION "Equation Solver Application"
    LANGUAGES CXX
)

# Настройки компилятора
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Разные флаги для разных компиляторов
if(MSVC)
    # Настройки для Visual Studio
    add_compile_options(/W4 /WX)
else()
    # Настройки для GCC/Clang
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

# Исходные файлы
set(SOURCES src/main.cpp)
set(HEADERS include/solver.h)

# Исполняемый файл
add_executable(solver ${SOURCES} ${HEADERS})
target_include_directories(solver PUBLIC include)

# Для Linux: связываем с математической библиотекой
if(UNIX AND NOT APPLE)
    target_link_libraries(solver PUBLIC m)
endif()

# Установка для CPack
install(TARGETS solver DESTINATION bin)

# Настройки CPack
# В разделе CPack настройки добавьте:
if(WIN32)
    set(CPACK_GENERATOR "WIX;ZIP")
    # Дополнительные настройки для WiX
    set(CPACK_WIX_UPGRADE_GUID "YOUR-GUID-HERE") # Замените на реальный GUID
    set(CPACK_WIX_PRODUCT_GUID "YOUR-GUID-HERE") # Замените на реальный GUID
    set(CPACK_WIX_LICENSE_RTF "${CMAKE_SOURCE_DIR}/LICENSE.rtf")
    set(CPACK_WIX_PRODUCT_ICON "${CMAKE_SOURCE_DIR}/assets/icon.ico")
    set(CPACK_WIX_CULTURES "en-us")
    set(CPACK_WIX_TEMPLATE "${CMAKE_SOURCE_DIR}/WixTemplate.wxi") # Если нужно
endif()
set(CPACK_PACKAGE_NAME "${PROJECT_NAME}")
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_PACKAGE_DESCRIPTION "Simple equation solver")
set(CPACK_PACKAGE_VENDOR "Your Organization")
set(CPACK_PACKAGE_CONTACT "contact@example.com")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")
set(CPACK_PACKAGE_FILE_NAME "${PROJECT_NAME}-${PROJECT_VERSION}-${CMAKE_SYSTEM_NAME}")

# Разные генераторы для разных систем
if(WIN32)
    set(CPACK_GENERATOR "WIX;ZIP")
elseif(APPLE)
    set(CPACK_GENERATOR "DragNDrop;ZIP")
else()
    set(CPACK_GENERATOR "DEB;RPM;TGZ")
endif()

include(CPack)
