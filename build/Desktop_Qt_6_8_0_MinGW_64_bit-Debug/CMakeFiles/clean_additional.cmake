# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\StristSystemQT_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\StristSystemQT_autogen.dir\\ParseCache.txt"
  "StristSystemQT_autogen"
  )
endif()