# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "06QThreadPool_autogen"
  "CMakeFiles/06QThreadPool_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/06QThreadPool_autogen.dir/ParseCache.txt"
  )
endif()
