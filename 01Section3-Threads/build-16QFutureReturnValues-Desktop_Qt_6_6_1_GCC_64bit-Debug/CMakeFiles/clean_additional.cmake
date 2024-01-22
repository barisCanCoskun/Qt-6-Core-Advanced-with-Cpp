# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "16QFutureReturnValues_autogen"
  "CMakeFiles/16QFutureReturnValues_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/16QFutureReturnValues_autogen.dir/ParseCache.txt"
  )
endif()
