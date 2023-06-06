cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Release)
project(zappy_gui)

include_directories(include)
include_directories(include/Interface)
include_directories(src/ZappyGUI)
include_directories(src/Scenes/Menu)
include_directories(src/Scenes/Playground)
include_directories(src/Components/Button)
include_directories(src/SocketCommunication)

add_executable(zappy_gui
        src/Main.cpp
        src/ZappyGUI/ZappyGUI.cpp
        src/Scenes/Menu/Menu.cpp
        src/Scenes/Playground/Playground.cpp
        src/Components/Button/Button.cpp
        src/SocketCommunication/SocketCommunication.cpp
        src/Utils/ErrorHandling.cpp
        src/Utils/Help.cpp
        )

if (WIN32)
    set(SFML_DIR "C:/SFML-2.5.1/lib/cmake/SFML")
    find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
    target_link_libraries(zappy_gui
            sfml-graphics
            sfml-window
            sfml-system
            )
elseif (UNIX AND NOT APPLE)
    find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
    target_link_libraries(zappy_gui
            sfml-graphics
            sfml-window
            sfml-system
            )
endif()
