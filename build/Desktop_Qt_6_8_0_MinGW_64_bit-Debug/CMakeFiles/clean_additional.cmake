# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\qtlogin_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\qtlogin_autogen.dir\\ParseCache.txt"
  "qtlogin_autogen"
  )
endif()
