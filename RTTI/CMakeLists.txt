file(GLOB SRC "*.cpp" "*.h")

add_library(FastRTTI STATIC ${SRC})

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    message(STATUS "Release mode: enabling optimizations")

    if(MSVC)
        # /O2 - высокая оптимизация
        # /GL - link-time optimization
        # /DNDEBUG - отключить assert()
        # /GR- - отключить RTTI
        target_compile_options(FastRTTI PRIVATE /O2 /GL /DNDEBUG /GR-)
        target_link_options(FastRTTI PRIVATE /LTCG)
    else()
        # GCC / Clang
        target_compile_options(FastRTTI PRIVATE
            -O3
            -march=native
            -flto
            -fno-rtti
            -DNDEBUG
        )
        target_link_options(FastRTTI PRIVATE -flto)
    endif()
endif()
