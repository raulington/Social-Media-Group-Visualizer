# Path definitions.
set(lib_dir ${CMAKE_CURRENT_SOURCE_DIR})

set(myfolder_dir ${lib_dir}/myfolder)
file(GLOB_RECURSE myfolder_sources CONFIGURE_DEPENDS ${myfolder_dir}/*.cpp)
add_library(myfolder ${myfolder_sources})
target_include_directories(myfolder PRIVATE ${lib_dir})

# Add overall libs library.
add_library(libs INTERFACE)
target_include_directories(libs INTERFACE ${lib_dir})
target_link_libraries(libs INTERFACE myfolder)