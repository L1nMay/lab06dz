cmake_minimum_required(VERSION 3.20)
project(Solver
    VERSION 1.1.5
    DESCRIPTION "Equation Solver Application"
    LANGUAGES CXX
)

# Настройки компилятора
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Разные флаги для разных компиляторов
if(MSVC)
    add_compile_options(/W4 /WX)
else()
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
set(CPACK_PACKAGE_NAME "${PROJECT_NAME}")
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_PACKAGE_DESCRIPTION "Simple equation solver")
set(CPACK_PACKAGE_VENDOR "Your Organization")
set(CPACK_PACKAGE_CONTACT "contact@example.com")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")
set(CPACK_PACKAGE_FILE_NAME "${PROJECT_NAME}-${PROJECT_VERSION}-${CMAKE_SYSTEM_NAME}")

# Настройки для WiX (Windows)
if(WIN32)
    set(CPACK_GENERATOR "WIX;ZIP")
    set(CPACK_WIX_UPGRADE_GUID "YOUR-UPGRADE-GUID") # Замените на реальный GUID
    set(CPACK_WIX_PRODUCT_GUID "YOUR-PRODUCT-GUID") # Замените на реальный GUID
    set(CPACK_WIX_LICENSE_RTF "${CMAKE_SOURCE_DIR}/LICENSE.rtf")
    set(CPACK_WIX_PRODUCT_ICON "${CMAKE_SOURCE_DIR}/assets/icon.ico")
    set(CPACK_WIX_UI_BANNER "${CMAKE_SOURCE_DIR}/assets/wix_banner.bmp")
    set(CPACK_WIX_UI_DIALOG "${CMAKE_SOURCE_DIR}/assets/wix_dialog.bmp")
    set(CPACK_WIX_CULTURES "en-us")
    set(CPACK_WIX_PROPERTY_ARPURLINFOABOUT "https://yourwebsite.com")
elseif(APPLE)
    set(CPACK_GENERATOR "DragNDrop;ZIP")
else()
    set(CPACK_GENERATOR "DEB;RPM;TGZ")
endif()

include(CPack)
