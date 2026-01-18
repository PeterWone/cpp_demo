cmake_minimum_required(VERSION 3.20)
project(CppInheritanceDemo VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Export compile commands for better IDE support
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Enable debug symbols for all configurations
if(MSVC)
    # Visual Studio compiler flags
    add_compile_options(/W4 /Zi)
    set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} /DEBUG:FULL")
else()
    # GCC/Clang compiler flags
    add_compile_options(-Wall -Wextra -g)
endif()

# Source files
set(SOURCES
    main.cpp
    Animal.cpp
    Dog.cpp
    Cat.cpp
    Bird.cpp
)

# Header files (for IDE support)
set(HEADERS
    Animal.h
    Dog.h
    Cat.h
    Bird.h
)

# Main executable
add_executable(inheritance_demo ${SOURCES} ${HEADERS})

# Platform-specific settings
if(WIN32)
    message(STATUS "Configuring for Windows 11")
    # Windows-specific settings
    set_target_properties(inheritance_demo PROPERTIES
        WIN32_EXECUTABLE FALSE  # Keep console window
    )
elseif(UNIX AND NOT APPLE)
    message(STATUS "Configuring for Ubuntu/Linux")
    # Linux-specific settings
    target_link_libraries(inheritance_demo PRIVATE pthread)
endif()

# Installation settings (optional)
install(TARGETS inheritance_demo
    RUNTIME DESTINATION bin
)

# Print build information
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Compiler: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
