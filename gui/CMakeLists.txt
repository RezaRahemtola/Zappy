cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Release)
project(zappy_gui)

include_directories(include)
include_directories(include/Interface)
## GUI Parts
include_directories(src/ZappyGUI)
include_directories(src/ClientGUI)
## Scenes
include_directories(src/Scenes/Menu)
include_directories(src/Scenes/Playground)
## Components
include_directories(src/Components/Button)
## GameData
include_directories(src/GameData)
include_directories(src/GameData/Tile)
include_directories(src/GameData/Player)
include_directories(src/GameData/Egg)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

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
        src/GameData/Player/Player.cpp
        ## Utils
        src/Utils/ErrorHandling.cpp
        src/Utils/Help.cpp
        src/Utils/GetArgs.cpp
        src/Tokenize.cpp
        )


find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
target_link_libraries(zappy_gui
        sfml-graphics
        sfml-window
        sfml-system
        sfml-network
        sfml-system
        raylib
        )
