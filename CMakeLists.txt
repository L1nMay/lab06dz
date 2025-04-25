cmake_minimum_required(VERSION 3.15)
project(Solver VERSION 1.0.0)

# Настройка CPack
set(CPACK_PACKAGE_VENDOR "YourName")
set(CPACK_PACKAGE_DESCRIPTION "Equation solver application")
set(CPACK_PACKAGE_CONTACT "you@example.com")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")

# Для Windows
if(WIN32)
  set(CPACK_WIX_PRODUCT_GUID "PUT-GUID-HERE")
  set(CPACK_WIX_UPGRADE_GUID "PUT-GUID-HERE")
endif()

include(CPack)
