#pragma once

enum GameStates { GAME_READY, GAME_PLAYING, GAME_PAUSE, GAME_OVER };

#define SCREEN_WIDTH 450
#define SCREEN_HEIGHT 600

#define SPLASH_STATE_SHOW_TIME 3.0
#define FLASH_SPEED 1500.0f
#define TIME_BEFORE_GAME_OVER_APPEARS 1.5f

#define BIRD_TOTAL_FRAMES 4
#define BIRD_ANIMATION_DURATION 0.4f

#define GRAVITY 350.0f
#define FLYING_SPEED 350.0f
#define FLYING_DURATION 0.25f
#define ROTATION_SPEED 100.0f

#define PIPE_SIZE_POOL 7
#define PIPE_MOVEMENT_SPEED 200.0f
#define PIPE_SPAWN_FREQUENCY 2.5f

#define BRONZE_MEDAL_SCORE 0
#define SILVER_MEDAL_SCORE 5
#define GOLD_MEDAL_SCORE 25
#define PLATINUM_MEDAL_SCORE 100

#define FLAPPY_FONT_FILEPATH "Resources/fonts/FlappyFont.ttf"
#define KEY_FONT_FLAPPY "Flappy Font"

#define HIGHSCORE_PATH "Resources/Highscore.txt"

#pragma region File paths
#define SPLASH_SCENE_BACKGROUND_FILEPATH "Resources/res/Splash Background.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "Resources/res/sky.png"
#define GAME_TITLE_FILEPATH "Resources/res/title.png"
#define PLAY_BUTTON_FILEPATH "Resources/res/PlayButton.png"
#define GAME_BACKGROUND_FILEPATH "Resources/res/sky.png"
#define GAME_OVER_BACKGROUND_FILEPATH "Resources/res/sky.png"
#define GAME_OVER_TITLE_FILEPATH "Resources/res/Game-Over-Title.png"
#define GAME_OVER_BODY_FILEPATH "Resources/res/Game-Over-Body.png"
#define BRONZE_MEDAL_FIREPATH "Resources/res/Bronze-Medal.png"
#define SILVER_MEDAL_FIREPATH "Resources/res/Silver-Medal.png"
#define GOLD_MEDAL_FIREPATH "Resources/res/Gold-Medal.png"
#define PLATINUM_MEDAL_FIREPATH "Resources/res/Platinum-Medal.png"
#define PIPE_UP_FILEPATH "Resources/res/PipeUp.png"
#define PIPE_DOWN_FILEPATH "Resources/res/PipeDown.png"
#define LAND_FILEPATH "Resources/res/Land.png"
#define BIRD_FILE_FRAME1_FILEPATH "Resources/res/bird-01.png"
#define BIRD_FILE_FRAME2_FILEPATH "Resources/res/bird-02.png"
#define BIRD_FILE_FRAME3_FILEPATH "Resources/res/bird-03.png"
#define BIRD_FILE_FRAME4_FILEPATH "Resources/res/bird-04.png"
#pragma endregion

#pragma region Key Textures
#define KEY_TEX_SPLASH_STATE "Splash State Background"
#define KEY_TEX_MAIN_MENU_BACKGROUND "Main Menu Background"
#define KEY_TEX_GAME_TITLE "Game Title"
#define KEY_TEX_PLAY_BUTTON "Play Button"
#define KEY_TEX_GAME_BACKGROUND "Game Background"
#define KEY_TEX_GAME_OVER_BACKGROUND "Game Over Background"
#define KEY_TEX_GAME_OVER_TITLE "Game Over Title"
#define KEY_TEX_GAME_OVER_BODY "Game Over Body"
#define KEY_TEX_BRONZE_MEDAL "Bronze Medal"
#define KEY_TEX_SILVER_MEDAL "Silver Medal"
#define KEY_TEX_GOLD_MEDAL "Gold Medal"
#define KEY_TEX_PLATINUM_MEDAL "Platinum Medal"
#define KEY_TEX_PIPE_UP "Pipe Up"
#define KEY_TEX_PIPE_DOWN "Pipe Down"
#define KEY_TEX_LAND "Land"
#define KEY_TEX_BIRD_FRAME1 "Bird Frame 1"
#define KEY_TEX_BIRD_FRAME2 "Bird Frame 2"
#define KEY_TEX_BIRD_FRAME3 "Bird Frame 3"
#define KEY_TEX_BIRD_FRAME4 "Bird Frame 4"
#pragma endregion

#define HIT_SOUND_FILEPATH "Resources/audio/Hit.wav"
#define POINT_SOUND_FILEPATH "Resources/audio/Point.wav"
#define WING_SOUND_FILEPATH "Resources/audio/Wing.wav"
