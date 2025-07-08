project(arborescence)
cmake_minimum_required(VERSION 3.5)

include(cmake/CPM.cmake)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/;${CMAKE_MODULE_PATH}")


#O3 optimization
message("cmake build type: ${CMAKE_BUILD_TYPE}")
if("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 ")
endif()
#enable all instructions
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native -Wno-c++11-narrowing -Wno-unused-variable -Wno-unused-parameter -Wno-array-bounds -Wno-dangling-reference -Wno-tautological-compare")


set(INCLUDES
  # suitesparse
  # openmp
  eigen #Eigen3_WITH_BLAS
  # spectra
  # fast_matrix_market
)

foreach(INCLUDE IN LISTS INCLUDES)
  include(cmake/include_${INCLUDE}.cmake)
  message("Load ${INCLUDE} done.")
endforeach()


add_subdirectory(src)
add_executable(XPBD main.cpp
)
target_link_libraries(XPBD
  solver
)














