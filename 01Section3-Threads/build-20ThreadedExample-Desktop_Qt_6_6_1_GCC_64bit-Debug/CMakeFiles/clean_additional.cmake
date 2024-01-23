# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "20ThreadedExample_autogen"
  "CMakeFiles/20ThreadedExample_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/20ThreadedExample_autogen.dir/ParseCache.txt"
  )
endif()
