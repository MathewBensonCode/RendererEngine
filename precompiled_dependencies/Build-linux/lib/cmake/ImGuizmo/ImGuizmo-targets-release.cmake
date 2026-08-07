#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "ImGuizmo::ImGuizmo" for configuration "Release"
set_property(TARGET ImGuizmo::ImGuizmo APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(ImGuizmo::ImGuizmo PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libImGuizmo.a"
  )

list(APPEND _cmake_import_check_targets ImGuizmo::ImGuizmo )
list(APPEND _cmake_import_check_files_for_ImGuizmo::ImGuizmo "${_IMPORT_PREFIX}/lib/libImGuizmo.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
