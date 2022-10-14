# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Spect_Device_Emulator_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Spect_Device_Emulator_autogen.dir\\ParseCache.txt"
  "Spect_Device_Emulator_autogen"
  )
endif()
