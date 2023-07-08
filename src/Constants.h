//
// Created by mechuon1 on 5/4/23.
//

#ifndef SEMESTRALKA_CONSTANTS_H
#define SEMESTRALKA_CONSTANTS_H

#endif //SEMESTRALKA_CONSTANTS_H

/**
 * @brief All constant values used by game
 * */



// Parsing delimeters
#define PRIMARY_DELIMETER ';'
#define SECONDARY_DELIMETER ':'
#define THERNARY_DELIMETER ','

// Runtime errors
#define COLOR_PARSING_ERROR  "Colors parsing failed\n"
#define ITEMS_PARSING_ERROR "Items parsing failed\n"
#define CONTROLS_PARSING_ERROR "Controls parsing failed\n"
#define WORLD_VALS_PARSING_ERROR  "World values parsing failed\n"
#define PLAYER_PARSING_ERROR "Player parsing failed\n"
#define WORLD_GENERATOR_PARSING_ERROR "World generator error\n"
#define MOBS_PARSING_ERROR "Mobs parsing failed \n"

// Game states
#define GAME_RUNNING 0
#define GAME_TERMINATED (-1)


// colors
#define RGB_VALUE_MIN 0
#define RGB_VALUE_MAX 255

// Action keys
#define MOVE_LEFT_KEY "move_left"
#define MOVE_RIGHT_KEY "move_right"
#define MOVE_JUMP_KEY "move_jump"
#define ACTION_LEFT_KEY "action_left"
#define ACTION_RIGHT_KEY "action_right"
#define ACTION_UP_KEY "action_up"
#define ACTION_DOWN_KEY "action_down"
#define CONTROL_QUIT_KEY "control_quit"
#define CONTROL_ENTER_KEY "control_enter"
#define CONTROL_SAVE_KEY "control_save"
#define CONTEXT_BACK_KEY "context_back"
#define CONTEXT_NEXT_KEY "context_next"
#define OPTION_0_KEY "option_0"
#define OPTION_1_KEY "option_1"
#define OPTION_2_KEY "option_2"
#define OPTION_3_KEY "option_3"
#define OPTION_4_KEY "option_4"
#define OPTION_5_KEY "option_5"
#define OPTION_6_KEY "option_6"
#define OPTION_7_KEY "option_7"
#define OPTION_8_KEY "option_8"
#define OPTION_9_KEY "option_9"
#define GAME_INVENTORY_KEY "game_inventory"
#define GAME_CRAFTING_KEY "game_crafting"
#define GAME_CRAFTING_REMOVE_KEY "game_crafting_remove"

// world configuration keys
#define WORLD_HEIGHT_KEY "world_height"
#define WORLD_WIDTH_KEY "world_width_default"
#define BEDROCK_COLOR_ID_KEY "bedrock_color_id"
#define AIR_COLOR_ID_KEY "air_color_id"
#define LAVA_COLOR_ID_KEY "lava_color_id"
#define DAY_BACKGROUND_COLOR_ID "day_background_color_id"
#define NIGHT_BACKGROUND_COLOR_ID "night_background_color_id"
#define LAVA_PROBABILITY 0.02


// player values
#define PLAYER_MAX_HEALTH_KEY "player_max_health"
#define PLAYER_DAMAGE_KEY "player_dmg"
#define PLAYER_JUMP_HEIGHT_KEY "jump_height"
#define PLAYER_FALL_DAMAGE_HEIGHT_KEY "fall_damage_height"
#define PLAYER_COLOR_ID_KEY "player_color_id"

// world generator values
#define MIN_AIR_ALT_KEY "min_air_alt"
#define MIN_MID_ALT_KEY "min_mid_alt"
#define MIN_BOTTOM_ALT_KEY "min_bottom_alt"
#define MID_BLOCKS_KEY "mid_blocks"
#define BOTTOM_BLOCKS_KEY "bottom_blocks"

// world values
#define MIN_WORLD_WIDTH 100
#define MIN_WORLD_HEIGHT 4
#define PERIODIC_ACTION_INTERVAL 1 // seconds
#define DAY_PHASE_SWITCH_INTERVAL 1 // minutes

// jump timer
#define JUMP_TIME_INTERVAL_MS 1

// Renderer values
#define REFRESH_RATE 50000
#define FRAME_HEIGHT 0.6


// Player values
#define PLAYER_ID (-1)
#define PLAYER_NAME "Player"
#define PLAYER_CHAR 'L'

#define PLAYER_HEALTH_SIGN '*'

#define INVENTORY_SIZE 10
#define MAX_STACK_SIZE 64
#define INVENTORY_SELECTION_SIGN '*'
#define INVENTORY_EMPTY_SLOT_SIGN "[]"
#define STACK_PRINT_FORMAT  "[%s] %d x  "

#define HAND_ID (-10)
#define HAND_NAME "Hand"
#define HAND_CHAR 'H'

// messages
#define FALL_DEATH_MSG "Player tried to fly"
#define STARVING_DEATH_MSG "Player forgot to eat"
#define LAVA_DEATH_MSG "Player tried to swim in Lava"

// default materials


#define AIR_ID  (-1)
#define AIR_NAME "Air"
#define AIR_CHAR 'A'

#define BEDROCK_ID (-2)
#define BEDROCK_NAME "Bedrock"
#define BEDROCK_CHAR 'B'

#define LAVA_ID (-3)
#define LAVA_NAME "Lava"
#define LAVA_CHAR 'L'



#define COMMENT_MARK '#'

// Save
#define SAVE_FILE_NAME "game_save.save"
#define SAVE_SUCCESS "Save success"
#define SAVE_FAILURE "Save failure"

// Config file paths
#define CONFIG_DIR "../src/config/"

#define COLORS_PATH "colors.cfg"
#define TOOLS_PATH "tools.cfg"
#define FOOD_PATH "food.cfg"
#define BLOCKS_PATH "blocks.cfg"
#define CONTROLS_PATH "controls.cfg"
#define WORLD_PATH "world.cfg"
#define PLAYER_PATH "player.cfg"
#define MAP_GENERATOR_PATH "map_generator.cfg"
#define MOBS_PATH "mobs.cfg"

// screens
#define CRAFTING_TITLE "Items available for crafting"



// Main menu
#define NEW_GAME_OPTION_TITLE "New game"
#define LOAD_GAME_OPTION_TITLE "Load game"
#define EXIT_GAME_OPTION_TITLE "Exit game"

#define MENU_SELECT_MARK '*'


