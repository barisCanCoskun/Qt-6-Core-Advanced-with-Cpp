# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "04QTcpSocket_autogen"
  "CMakeFiles/04QTcpSocket_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/04QTcpSocket_autogen.dir/ParseCache.txt"
  )
endif()
