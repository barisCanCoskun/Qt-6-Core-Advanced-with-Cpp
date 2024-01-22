# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "17QFutureWatcher-Slots_autogen"
  "CMakeFiles/17QFutureWatcher-Slots_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/17QFutureWatcher-Slots_autogen.dir/ParseCache.txt"
  )
endif()
