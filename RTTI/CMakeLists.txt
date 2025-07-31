file(GLOB SRC "*.cpp" "*.h")

add_library(FastRTTI STATIC ${SRC})

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    if(MSVC)
        target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE /GR-)
        target_link_options(${CMAKE_PROJECT_NAME} PRIVATE /LTCG)
    else()
        # GCC / Clang
        target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -fno-rtti)
        target_link_options(${CMAKE_PROJECT_NAME} PRIVATE -flto)
    endif()

elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
    if(MSVC)
        target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE /GR-)
    else()
        target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE
            -g
            -fno-rtti)
    endif()
endif()
