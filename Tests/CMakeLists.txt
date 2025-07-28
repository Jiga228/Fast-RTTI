file(GLOB test_default_src "test_default_rtti.cpp" "ClassesDefault/*.cpp" "ClassesDefault/*.h")

add_executable(test_defalt_rtti ${test_default_src})

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    message(STATUS "Release mode: enabling optimizations")

    if(MSVC)
        # /O2 - высокая оптимизация
        # /GL - link-time optimization
        # /DNDEBUG - отключить assert()
        target_compile_options(test_defalt_rtti PRIVATE /O2 /GL /DNDEBUG)
        target_link_options(test_defalt_rtti PRIVATE /LTCG)
    else()
        # GCC / Clang
        target_compile_options(test_defalt_rtti PRIVATE
            -O3
            -march=native
            -flto
            -DNDEBUG
        )
        target_link_options(Tests PRIVATE -flto)
    endif()
endif()



file(GLOB test_fast_src "test_fast_rtti.cpp" "ClassesFast/*.cpp" "ClassesFast/*.h")

add_executable(test_fast_rtti ${test_fast_src})
target_link_libraries(test_fast_rtti PRIVATE FastRTTI)
target_include_directories(test_fast_rtti PRIVATE ${PROJECT_SOURCE_DIR}/RTTI)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    message(STATUS "Release mode: enabling optimizations")

    if(MSVC)
        # /O2 - высокая оптимизация
        # /GL - link-time optimization
        # /DNDEBUG - отключить assert()
        # /GR- - отключить RTTI
        target_compile_options(test_fast_rtti PRIVATE /O2 /GL /DNDEBUG /GR-)
        target_link_options(test_fast_rtti PRIVATE /LTCG)
    else()
        # GCC / Clang
        target_compile_options(test_fast_rtti PRIVATE
            -O3
            -march=native
            -flto
            -fno-rtti
            -DNDEBUG
        )
        target_link_options(test_fast_rtti PRIVATE -flto)
    endif()
endif()