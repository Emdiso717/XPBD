aux_source_directory(. source)
file(GLOB header *.h)

add_library(solver SHARED ${source})
target_link_libraries(solver
  Eigen3_WITH_BLAS
  # Spectra
  # SuiteSparse::CHOLMOD
)


target_compile_features(solver PUBLIC cxx_std_20)




