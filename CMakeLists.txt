cmake_minimum_required(VERSION 3.20)
project(Solver
    VERSION 1.0.0
    DESCRIPTION "Lab06 Solver Application"
    LANGUAGES CXX
)

# Настройки компилятора
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# Исполняемый файл
add_executable(solver src/main.cpp)
target_include_directories(solver PUBLIC include)
install(TARGETS solver DESTINATION bin)

# Базовые настройки пакетов
set(CPACK_PACKAGE_NAME "${PROJECT_NAME}")
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_PACKAGE_DESCRIPTION "Equation solver for Lab06")
set(CPACK_PACKAGE_VENDOR "Your Organization")
set(CPACK_PACKAGE_CONTACT "Your Name <your.email@example.com>")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")

# Настройки для разных ОС
if(WIN32)
    # Windows (WIX installer)
    set(CPACK_GENERATOR "ZIP;WIX")
    set(CPACK_WIX_PRODUCT_GUID "653cd22f-cbc0-43d7-a59b-e2af6ad931f7")
    set(CPACK_WIX_UPGRADE_GUID "d4e5f6a7-b8c9-4d0e-a1b2-c3d4e5f6a7b8")  # Другой GUID для апгрейда
    set(CPACK_WIX_UPGRADE_CODE "b2c3d4e5-f6a7-4b8c-9d0e-a1b2c3d4e5f6")  # И еще один GUID
    set(CPACK_WIX_CULTURES "en-us")
    set(CPACK_WIX_PRODUCT_ICON "${CMAKE_SOURCE_DIR}/assets/icon.ico")
    
elseif(APPLE)
    # macOS
    set(CPACK_GENERATOR "ZIP;DragNDrop")
    set(CPACK_DMG_BACKGROUND_IMAGE "${CMAKE_SOURCE_DIR}/assets/background.png")
    set(CPACK_DMG_VOLUME_NAME "Solver ${PROJECT_VERSION}")
    
else()
    # Linux
    set(CPACK_GENERATOR "TGZ;DEB")
    set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Your Name <your.email@example.com>")
    set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6 (>= 2.14), zlib1g (>= 1:1.2.3.4)")
    set(CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)
    set(CPACK_RPM_PACKAGE_REQUIRES "zlib >= 1.2.3")
endif()

# Проверка наличия LICENSE
if(NOT EXISTS "${CMAKE_SOURCE_DIR}/LICENSE")
    message(WARNING "LICENSE file not found - package generation may fail")
endif()

include(CPack)
