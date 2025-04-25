cmake_minimum_required(VERSION 3.20)
project(Solver
    VERSION 1.0.0
    DESCRIPTION "Lab06 Solver Application"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(solver src/main.cpp)
target_include_directories(solver PUBLIC include)

install(TARGETS solver DESTINATION bin)

set(CPACK_PACKAGE_NAME "${PROJECT_NAME}")
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_PACKAGE_DESCRIPTION "Equation solver for Lab06")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")
set(CPACK_GENERATOR "TGZ;ZIP")
# DEB package settings
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Your Name <email@example.com>")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6 (>= 2.14), zlib1g (>= 1:1.2.3.4)")
set(CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)

# RPM package settings
set(CPACK_RPM_PACKAGE_REQUIRES "zlib >= 1.2.3")

# Windows settings
set(CPACK_WIX_PRODUCT_GUID "PUT-GUID-HERE")  # generate with 'uuidgen'
set(CPACK_WIX_UPGRADE_GUID "PUT-GUID-HERE")  # generate with 'uuidgen'

# General settings
set(CPACK_PACKAGE_CONTACT "Your Name <email@example.com>")
set(CPACK_PACKAGE_VENDOR "Your Organization")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")

include(CPack)
