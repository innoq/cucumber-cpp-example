project(test_example)
cmake_minimum_required(VERSION 3.22)

option(ENABLE_TESTS "Enable tests" OFF)
if (${ENABLE_TESTS})
  enable_testing()
endif()

find_package(Boost COMPONENTS program_options filesystem unit_test_framework regex thread REQUIRED)

set(CALC_SOURCE_FILES src/Calculator.cpp src/Calculator.h)
add_library(calc ${CALC_SOURCE_FILES})

add_executable(calcexe src/main.cpp)
target_link_libraries(calcexe calc)

if (${ENABLE_TESTS})
  function(add_cucumber_executable)
    add_executable(FeatureSteps ${ARGV})
    target_link_libraries(FeatureSteps PRIVATE cucumber-cpp  ${Boost_LIBRARIES} calc)
    target_include_directories(FeatureSteps PRIVATE src)
    foreach(_arg ${ARGN})
      get_filename_component(OBJECT_PREFIX ${_arg} NAME_WE)
      set_source_files_properties(${_arg} PROPERTIES COMPILE_FLAGS "-DCUKE_OBJECT_PREFIX=${OBJECT_PREFIX}")
    endforeach(_arg)
  endfunction()

  add_cucumber_executable(
    features/step_definitions/SomeSteps.cpp
    #        features/step_definitions/TableSteps
    )

endif()
