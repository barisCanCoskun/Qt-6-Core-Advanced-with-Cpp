# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "07SynchronousTCP_autogen"
  "CMakeFiles/07SynchronousTCP_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/07SynchronousTCP_autogen.dir/ParseCache.txt"
  )
endif()
