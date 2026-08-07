#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "tlsf::tlsf" for configuration "Release"
set_property(TARGET tlsf::tlsf APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(tlsf::tlsf PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libtlsf.a"
  )

list(APPEND _cmake_import_check_targets tlsf::tlsf )
list(APPEND _cmake_import_check_files_for_tlsf::tlsf "${_IMPORT_PREFIX}/lib/libtlsf.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
