file(GLOB test_default_src "test_default_rtti.cpp" "ClassesDefault/*.cpp" "ClassesDefault/*.h")
add_executable(test_defalt_rtti ${test_default_src})

# -------------------------------------------------------------

# test_fast_rtti — ускоренная реализация с отключённым RTTI
file(GLOB test_fast_src "test_fast_rtti.cpp" "ClassesFast/*.cpp" "ClassesFast/*.h")
add_executable(test_fast_rtti ${test_fast_src})

target_link_libraries(test_fast_rtti PRIVATE FastRTTI)
target_include_directories(test_fast_rtti PRIVATE ${PROJECT_SOURCE_DIR}/RTTI)

if(MSVC)
    target_compile_options(test_fast_rtti PRIVATE /GR-)
else()
    target_compile_options(test_fast_rtti PRIVATE
        -fno-rtti
    )
    target_link_options(test_fast_rtti PRIVATE -fsanitize=undefined)
endif()