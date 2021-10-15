# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "CMakeFiles/atlir5_Bonne_nuit-Tests_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/atlir5_Bonne_nuit-Tests_autogen.dir/ParseCache.txt"
  "CMakeFiles/atlir5_Bonne_nuit_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/atlir5_Bonne_nuit_autogen.dir/ParseCache.txt"
  "atlir5_Bonne_nuit-Tests_autogen"
  "atlir5_Bonne_nuit_autogen"
  )
endif()
