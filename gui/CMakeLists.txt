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
include_directories(src/ClientGUI)
include_directories(src/GameData)
include_directories(src/GameData/Tile)

add_executable(zappy_gui
        src/Main.cpp
        ## GUI Parts
        src/ZappyGUI/ZappyGUI.cpp
        src/ClientGUI/ClientGUI.cpp
        ## Scenes
        src/Scenes/Menu/Menu.cpp
        src/Scenes/Playground/Playground.cpp
        ## Components
        src/Components/Button/Button.cpp
        src/Components/Slider/Slider.cpp
        src/Components/Text/Text.cpp
        src/Components/TextInput/TextInput.cpp
        src/Components/Checkbox/Checkbox.cpp
        src/Components/Image/Image.cpp
        ## GameData
        src/GameData/GameData.cpp
        src/GameData/Tile/Tile.cpp
        ## Utils
        src/Utils/ErrorHandling.cpp
        src/Utils/Help.cpp
        src/Utils/GetArgs.cpp
        )

if (WIN32)
    set(SFML_DIR "C:/SFML-2.5.1/lib/cmake/SFML")
    find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
    target_link_libraries(zappy_gui
            sfml-graphics
            sfml-window
            sfml-system
            sfml-network
            sfml-system
            )
elseif (UNIX AND NOT APPLE)
    find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
    target_link_libraries(zappy_gui
            sfml-graphics
            sfml-window
            sfml-system
            sfml-network
            sfml-system
            )
endif()
