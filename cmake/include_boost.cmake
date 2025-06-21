# find_package(Boost REQUIRED)
# if(${Boost_FOUND})
#     message("Boost found version ${Boost_VERSION_MACRO}")
#     message("Boost_LIBRARIES: ${Boost_LIBRARIES}")
#     message("Boost_LIBRARY_DIRS: ${Boost_LIBRARY_DIRS}")
# else()
#     message("Boost not found")
# endif()

# add_library(Boost::property_tree ALIAS ${BOOST_LIBRARIES})
#Include specific Boost components using CPM
CPMAddPackage(
  NAME Boost
  GIT_REPOSITORY "https://github.com/boostorg/boost.git"
  GIT_TAG "boost-1.85.0"
  OPTIONS
  "BOOST_CMAKE_BUILD_TESTS OFF"
  "BOOST_CMAKE_BUILD_EXAMPLES OFF"
  "BOOST_JSON_BUILD_TESTS OFF"
  "BOOST_JSON_BUILD_EXAMPLES OFF"
  "BOOST_URL_BUILD_TESTS OFF"
  "BOOST_URL_BUILD_EXAMPLES OFF"
  COMPONENTS system filesystem serialization smart_ptr property_tree  container_hash program_options
)
