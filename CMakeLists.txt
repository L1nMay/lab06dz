cmake_minimum_required(VERSION 3.20)
project(Solver
    VERSION 1.1.5
    DESCRIPTION "Quadratic Equation Solver Application"
    LANGUAGES CXX
)

# Настройки компилятора
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

# Исходные файлы
add_executable(solver
    src/main.cpp
    include/solver.h
)

target_include_directories(solver PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

if(UNIX AND NOT APPLE)
    target_link_libraries(solver PUBLIC m)
endif()

# Установка
install(TARGETS solver
    RUNTIME DESTINATION bin
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)
# Дополнительные настройки для DEB пакетов
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Maintainer Name <maintainer@example.com>")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6 (>= 2.14)")
set(CPACK_DEBIAN_PACKAGE_HOMEPAGE "https://github.com/your/repo")

# Дополнительные настройки для WIX (Windows)
set(CPACK_WIX_UPGRADE_GUID "59C3599E-9B55-493D-930C-43AAA0A67E7F")
set(CPACK_WIX_PRODUCT_GUID "89D3599E-9B55-493D-930C-43AAA0A67E8F")
set(CPACK_WIX_UPGRADE_CODE "B5D3599E-9B55-493D-930C-43AAA0A67E9F")

# Настройки для RPM пакетов
set(CPACK_RPM_PACKAGE_REQUIRES "libc >= 2.14")

# Настройки CPack
include(CPack)
set(CPACK_PACKAGE_NAME "${PROJECT_NAME}")
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Quadratic equation solver")
set(CPACK_PACKAGE_VENDOR "Your Organization")
set(CPACK_PACKAGE_CONTACT "contact@example.com")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")

if(WIN32)
    set(CPACK_GENERATOR "WIX;ZIP")
    set(CPACK_WIX_UPGRADE_GUID "A5F0D3B9-4E2A-45C1-BA6D-123456789ABC")
    set(CPACK_WIX_PRODUCT_GUID "B6E1D4C0-5F3B-46D2-AB7E-987654321DEF")
    set(CPACK_WIX_LICENSE_RTF "${CMAKE_SOURCE_DIR}/LICENSE.rtf")
    set(CPACK_WIX_PRODUCT_ICON "${CMAKE_SOURCE_DIR}/assets/icon.ico")
    set(CPACK_WIX_UI_BANNER "${CMAKE_SOURCE_DIR}/assets/wix_banner.bmp")
    set(CPACK_WIX_UI_DIALOG "${CMAKE_SOURCE_DIR}/assets/wix_dialog.bmp")
elseif(APPLE)
    set(CPACK_GENERATOR "DragNDrop;ZIP")
else()
    set(CPACK_GENERATOR "DEB;RPM;TGZ")
    set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6 (>= 2.14)")
endif()
