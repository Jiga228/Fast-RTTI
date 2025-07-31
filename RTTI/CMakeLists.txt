file(GLOB SRC "*.cpp" "*.h")

add_library(FastRTTI STATIC ${SRC})

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    if(MSVC)
        target_compile_options(FastRTTI PRIVATE /GR-)
        target_link_options(FastRTTI PRIVATE /LTCG)
    else()
        # GCC / Clang
        target_compile_options(FastRTTI PRIVATE -fno-rtti)
        target_link_options(FastRTTI PRIVATE -flto)
    endif()

elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
    if(MSVC)
        target_compile_options(FastRTTI PRIVATE /GR-)
    else()
        target_compile_options(FastRTTI PRIVATE
            -g
            -fno-rtti)
    endif()
endif()
