cmake_minimum_required(VERSION 3.12)
include(pico_sdk_import.cmake)
project(Pico_ePaper_Code)
pico_sdk_init()

# Add a compilation subdirectory
add_subdirectory(lib/Config)
add_subdirectory(lib/Infrared)
add_subdirectory(lib/Icm20948)
add_subdirectory(lib/LCD)
add_subdirectory(lib/Fonts)
add_subdirectory(lib/GUI)

# Add a header directory
include_directories(./lib/Config)
include_directories(./lib/GUI)
include_directories(./lib/Icm20948)
include_directories(./lib/LCD)
include_directories(./lib/Infrared)

# create an executable file
add_executable(KemonoRogue 
src/TinyLibrary/AdpcmDecorder.cpp
src/TinyLibrary/Mathmatics.cpp
src/TinyLibrary/SoundMixer.cpp
src/TinyLibrary/SoundPlayer.cpp
src/TinyLibrary/Pico/Controller.cpp
src/TinyLibrary/Pico/Screen.cpp
src/TinyLibrary/Pico/SoundStream.cpp
src/TinyLibrary/Pico/TinyFile.cpp
src/Cerulean.cpp
src/Ending.cpp
src/Enemy.cpp
src/FloorMap.cpp
src/Game.cpp
src/GameData.cpp
src/Global.cpp
src/Item.cpp
src/Kaban.cpp
src/MainLoop.cpp
src/Maze.cpp
src/Object.cpp
src/Player.cpp
src/Popup.cpp
src/Resource.cpp
src/Resume.cpp
src/Serval.cpp
src/Sound.cpp
src/Toki.cpp
src/Tsuchinoko.cpp
KemonoRogue.cpp
)

# enable usb output, disable uart output
#pico_enable_stdio_usb(KemonoRogue 0)
#pico_enable_stdio_uart(KemonoRogue 0)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(KemonoRogue)

target_link_libraries(KemonoRogue LCD Infrared Icm20948 GUI Fonts Config pico_stdlib hardware_spi)