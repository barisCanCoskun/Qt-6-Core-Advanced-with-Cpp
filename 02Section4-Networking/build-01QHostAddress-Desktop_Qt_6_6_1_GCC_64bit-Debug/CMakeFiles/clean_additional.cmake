# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "01QHostAddress_autogen"
  "CMakeFiles/01QHostAddress_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/01QHostAddress_autogen.dir/ParseCache.txt"
  )
endif()
