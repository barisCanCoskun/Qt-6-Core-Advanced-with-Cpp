# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "14QtConcurrentIssues_autogen"
  "CMakeFiles/14QtConcurrentIssues_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/14QtConcurrentIssues_autogen.dir/ParseCache.txt"
  )
endif()
