cmake_minimum_required(VERSION 3.5)
project(YourAllegroProject)

# Set Allegro 5 path
set(ALLEGRO_DIR "C:/AllegroLib_5.2.8")

# Add ENet directory
set(ENET_DIR "C:/ENetLib")

# Include Allegro 5 and project headers
include_directories(${ALLEGRO_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)  

# Include ENet directory
include_directories(${ENET_DIR}/include)

# Find Allegro 5 libraries
find_library(ALLEGRO_LIBRARY allegro PATHS ${ALLEGRO_DIR}/lib)
find_library(ALLEGRO_PRIMITIVES_LIBRARY allegro_primitives PATHS ${ALLEGRO_DIR}/lib)
find_library(ALLEGRO_IMAGE_LIBRARY allegro_image PATHS ${ALLEGRO_DIR}/lib)
find_library(ALLEGRO_AUDIO_LIBRARY allegro_audio PATHS ${ALLEGRO_DIR}/lib)
find_library(ALLEGRO_ACODEC_LIBRARY allegro_acodec PATHS ${ALLEGRO_DIR}/lib)
find_library(ALLEGRO_FONT_LIBRARY allegro_font PATHS ${ALLEGRO_DIR}/lib)
find_library(ALLEGRO_TTF_LIBRARY allegro_ttf PATHS ${ALLEGRO_DIR}/lib)
find_library(ALLEGRO_DIALOG_LIBRARY allegro_dialog PATHS ${ALLEGRO_DIR}/lib)

# Search all source files
file(GLOB SOURCE_FILES "src/*.c") 

# Set executable output directory
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})  

# Add executable
add_executable(YourProgram ${SOURCE_FILES})

# Link Allegro 5 libraries
target_link_libraries(YourProgram 
                      ${ALLEGRO_LIBRARY} 
                      ${ALLEGRO_PRIMITIVES_LIBRARY} 
                      ${ALLEGRO_IMAGE_LIBRARY} 
                      ${ALLEGRO_AUDIO_LIBRARY} 
                      ${ALLEGRO_ACODEC_LIBRARY} 
                      ${ALLEGRO_FONT_LIBRARY} 
                      ${ALLEGRO_TTF_LIBRARY} 
                      ${ALLEGRO_DIALOG_LIBRARY})

# Add ENet
include(CheckFunctionExists)
include(CheckStructHasMember)
include(CheckTypeSize)
check_function_exists("fcntl" HAS_FCNTL)
check_function_exists("poll" HAS_POLL)
check_function_exists("getaddrinfo" HAS_GETADDRINFO)
check_function_exists("getnameinfo" HAS_GETNAMEINFO)
check_function_exists("gethostbyname_r" HAS_GETHOSTBYNAME_R)
check_function_exists("gethostbyaddr_r" HAS_GETHOSTBYADDR_R)
check_function_exists("inet_pton" HAS_INET_PTON)
check_function_exists("inet_ntop" HAS_INET_NTOP)
check_struct_has_member("struct msghdr" "msg_flags" "sys/types.h;sys/socket.h" HAS_MSGHDR_FLAGS)
set(CMAKE_EXTRA_INCLUDE_FILES "sys/types.h" "sys/socket.h")
check_type_size("socklen_t" HAS_SOCKLEN_T BUILTIN_TYPES_ONLY)
unset(CMAKE_EXTRA_INCLUDE_FILES)
if(MSVC)
    add_definitions(-W3)
else()
    add_definitions(-Wno-error)
endif()

if(HAS_FCNTL)
    add_definitions(-DHAS_FCNTL=1)
endif()
if(HAS_POLL)
    add_definitions(-DHAS_POLL=1)
endif()
if(HAS_GETNAMEINFO)
    add_definitions(-DHAS_GETNAMEINFO=1)
endif()
if(HAS_GETADDRINFO)
    add_definitions(-DHAS_GETADDRINFO=1)
endif()
if(HAS_GETHOSTBYNAME_R)
    add_definitions(-DHAS_GETHOSTBYNAME_R=1)
endif()
if(HAS_GETHOSTBYADDR_R)
    add_definitions(-DHAS_GETHOSTBYADDR_R=1)
endif()
if(HAS_INET_PTON)
    add_definitions(-DHAS_INET_PTON=1)
endif()
if(HAS_INET_NTOP)
    add_definitions(-DHAS_INET_NTOP=1)
endif()
if(HAS_MSGHDR_FLAGS)
    add_definitions(-DHAS_MSGHDR_FLAGS=1)
endif()
if(HAS_SOCKLEN_T)
    add_definitions(-DHAS_SOCKLEN_T=1)
endif()

set(ENET_INCLUDE_FILES_PREFIX ${ENET_DIR}/include/enet)
set(ENET_INCLUDE_FILES
    ${ENET_INCLUDE_FILES_PREFIX}/callbacks.h
    ${ENET_INCLUDE_FILES_PREFIX}/enet.h
    ${ENET_INCLUDE_FILES_PREFIX}/list.h
    ${ENET_INCLUDE_FILES_PREFIX}/protocol.h
    ${ENET_INCLUDE_FILES_PREFIX}/time.h
    ${ENET_INCLUDE_FILES_PREFIX}/types.h
    ${ENET_INCLUDE_FILES_PREFIX}/unix.h
    ${ENET_INCLUDE_FILES_PREFIX}/utility.h
    ${ENET_INCLUDE_FILES_PREFIX}/win32.h
)

set(ENET_SOURCE_FILES
    ${ENET_DIR}/callbacks.c
    ${ENET_DIR}/compress.c
    ${ENET_DIR}/host.c
    ${ENET_DIR}/list.c
    ${ENET_DIR}/packet.c
    ${ENET_DIR}/peer.c
    ${ENET_DIR}/protocol.c
    ${ENET_DIR}/unix.c
    ${ENET_DIR}/win32.c)

add_library(enet STATIC
    ${ENET_INCLUDE_FILES}
    ${ENET_SOURCE_FILES}
)

if (WIN32)
    target_link_libraries(enet winmm ws2_32)
endif()

# Link ENet Library
target_link_libraries(YourProgram enet)