cmake_minimum_required(VERSION 3.15)
project(Solver VERSION 1.1.6 LANGUAGES CXX)

# Базовые настройки
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_DEBUG_POSTFIX "_d")

# Исходные файлы
add_executable(solver src/main.cpp)

# Настройки установки
install(TARGETS solver
  RUNTIME DESTINATION bin
  BUNDLE DESTINATION bin
)

# Настройки CPack
include(InstallRequiredSystemLibraries)
set(CPACK_PACKAGE_NAME "${PROJECT_NAME}")
set(CPACK_PACKAGE_VENDOR "Your Company")
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Solver application")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE.rtf")

# Настройки для Windows (WIX)
if(WIN32)
  set(CPACK_GENERATOR "WIX")
  set(CPACK_WIX_UPGRADE_GUID "YOUR-GUID-HERE") # Сгенерируйте новый GUID
  set(CPACK_WIX_PRODUCT_ICON "${CMAKE_SOURCE_DIR}/assets/icon.ico")
  set(CPACK_WIX_UI_BANNER "${CMAKE_SOURCE_DIR}/assets/banner.bmp")
  set(CPACK_WIX_UI_DIALOG "${CMAKE_SOURCE_DIR}/assets/dialog.bmp")
  set(CPACK_WIX_CULTURES "en-us")
  set(CPACK_WIX_EXTRA_SOURCES "${CMAKE_SOURCE_DIR}/assets/extra.wxs")
endif()

# Настройки для Linux
if(UNIX AND NOT APPLE)
  set(CPACK_GENERATOR "DEB;RPM")
  set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Your Name <your.email@example.com>")
  set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6 (>= 2.14)")
endif()

# Настройки для macOS
if(APPLE)
  set(CPACK_GENERATOR "DragNDrop")
  set(CPACK_DMG_VOLUME_NAME "Solver")
  set(CPACK_DMG_DS_STORE "${CMAKE_SOURCE_DIR}/assets/DS_Store")
endif()

include(CPack)
