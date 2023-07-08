cmake_minimum_required(VERSION 3.15)
project(semestralka)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lncurses ")



add_executable(
        semestralka src/main.cpp
        src/WorldGenerator.cpp
        src/WorldGenerator.h
        src/Runtime.cpp
        src/Runtime.h
        src/Renderer.cpp
        src/Renderer.h
        src/Controller.cpp
        src/Controller.h
        src/Timer.cpp
        src/Timer.h
        src/Item.cpp
        src/Item.h
        src/Blocks/Block.cpp
        src/Blocks/Block.h
        src/Blocks/Air.cpp
        src/Blocks/Air.h
        src/Blocks/Bedrock.cpp
        src/Blocks/Bedrock.h
        src/Chunk.cpp
        src/Chunk.h
        src/Entities/Player.cpp
        src/Entities/Player.h
        src/Inventory.cpp
        src/Inventory.h
        src/RandomGenerator.cpp
        src/RandomGenerator.h
        src/Screens/MainMenu.cpp
        src/Screens/MainMenu.h
        src/Entities/Mob.cpp
        src/Entities/Mob.h
        src/Game.h
        src/Game.cpp
        src/Game.h
        src/World.cpp
        src/World.h
        src/Cache.cpp
        src/Cache.h
        src/Enums/ActionEnum.h
        src/Files/FileReader.cpp
        src/Files/FileReader.h
        src/Utils/StringSplitter.cpp
        src/Utils/StringSplitter.h
        src/NCursesManager.cpp
        src/NCursesManager.h
        src/Utils/NumberParser.cpp
        src/Utils/NumberParser.h
        src/Enums/MenuOption.h
        src/Tools/Tool.cpp
        src/Tools/Tool.h src/Tools/PlayerHand.cpp src/Tools/PlayerHand.h src/Enums/MoveDirection.h src/Color.cpp src/Color.h src/Screens/Screen.cpp src/Screens/Screen.h src/Screens/InventoryScreen.cpp src/Screens/InventoryScreen.h src/Entities/Entity.cpp src/Entities/Entity.h src/Food/Food.cpp src/Food/Food.h src/Screens/CraftingScreen.cpp src/Screens/CraftingScreen.h src/Constants.h src/Screens/MessageScreen.cpp src/Screens/MessageScreen.h src/Death/Death.cpp src/Death/Death.h src/Death/FallDeath.cpp src/Death/FallDeath.h src/Death/HungryDeath.cpp src/Death/HungryDeath.h src/Death/HungryDeath.h src/Files/FileSaver.cpp src/Files/FileSaver.h src/Stack.cpp src/Stack.h src/mainPage.h src/Blocks/Lava.cpp src/Blocks/Lava.h src/Death/LavaDeath.cpp src/Death/LavaDeath.h src/Loaders/WorldLoader.cpp src/Loaders/WorldLoader.h src/Loaders/GameLoader.cpp src/Loaders/GameLoader.h src/Loaders/PlayerLoader.cpp src/Loaders/PlayerLoader.h "src/Loaders/CacheLoaders/ActionsLoader.cpp" "src/Loaders/CacheLoaders/ActionsLoader.h" "src/Loaders/CacheLoaders/ColorLoader.cpp" "src/Loaders/CacheLoaders/ColorLoader.h" "src/Loaders/CacheLoaders/WorldConfigLoader.cpp" "src/Loaders/CacheLoaders/WorldConfigLoader.h" "src/Loaders/CacheLoaders/PlayerValsLoader.cpp" "src/Loaders/CacheLoaders/PlayerValsLoader.h" "src/Loaders/CacheLoaders/MobsLoader.cpp" "src/Loaders/CacheLoaders/MobsLoader.h" "src/Loaders/CacheLoaders/WorldGeneratorLoader.cpp" "src/Loaders/CacheLoaders/WorldGeneratorLoader.h" "src/Loaders/CacheLoaders/BlocksLoader.cpp" "src/Loaders/CacheLoaders/BlocksLoader.h" src/Enums/DayPhase.h "src/Loaders/CacheLoaders/ToolsLoader.cpp" "src/Loaders/CacheLoaders/ToolsLoader.h" "src/Loaders/CacheLoaders/FoodLoader.cpp" "src/Loaders/CacheLoaders/FoodLoader.h")

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    target_link_libraries(semestralka ncurses )
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    target_link_libraries(semestralka ${CURSES_LIBRARIES} )
endif()
