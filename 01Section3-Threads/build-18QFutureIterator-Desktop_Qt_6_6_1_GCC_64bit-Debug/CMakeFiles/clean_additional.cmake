# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "18QFutureIterator_autogen"
  "CMakeFiles/18QFutureIterator_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/18QFutureIterator_autogen.dir/ParseCache.txt"
  )
endif()
