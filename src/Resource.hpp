#ifndef RESOURCE_DATA_HPP
#define RESOURCE_DATA_HPP

#include <stdlib.h>

enum
{
	DUMMY_DATA = 0,
	DATA_MAX,
	IMAGE_START = 0,
	PATH,
	WALL,
	EXIT,
	TREASURE,
	TREASURE_OPEN,
	SWITCH_OFF,
	SWITCH_ON,
	PATH2,
	WALL2,
	EXIT2,
	TREASURE2,
	TREASURE_OPEN2,
	SWITCH_OFF2,
	SWITCH_ON2,
	PATH3,
	WALL3,
	EXIT3,
	TREASURE3,
	TREASURE_OPEN3,
	SWITCH_OFF3,
	SWITCH_ON3,
	PLAYER1,
	PLAYER2,
	PLAYER3,
	PLAYER4,
	ITEM,
	DUST_EFFECT,
	CERULEAN_SMALL_BLUE,
	CERULEAN_SMALL_GREEN,
	CERULEAN_SMALL_YELLOW,
	CERULEAN_SMALL_RED,
	CERULEAN_SMALL_PURPLE,
	CERULEAN_MEDIUM_BLUE,
	CERULEAN_MEDIUM_GREEN,
	CERULEAN_MEDIUM_YELLOW,
	CERULEAN_MEDIUM_RED,
	CERULEAN_MEDIUM_PURPLE,
	CERULEAN_BIG_RED,
	CERULEAN_BIG_PURPLE,
	CERULEAN_BLACK,
	WINDOW,
	STATUS_WINDOW,
	PLAYER_STATUS,
	ITEM_WINDOW,
	BUTTON_OFF,
	BUTTON_ON,
	TUCHIKURE_LOGO,
	OTOYOI_LOGO,
	HMIX_LOGO,
	DAIMON_LOGO,
	TITLE,
	TITLE_EN,
	ENDING_BG,
	ENDING_ENDINGCONGRATULATIONS,
	ENDING_MESSAGE,
	ENDING_MESSAGE_JP,
	SHADOW,
	LEFT_ARROW,
	RIGHT_ARROW,
	IMAGE_MAX,
	DUMMY_BG_MAP = 0,
	BG_MAP_MAX,
	SOUND_BGM_TITLE = 0,
	SOUND_BGM_STAGE,
	SOUND_CURSOR,
	SOUND_DECISION,
	SOUND_DOWN,
	SOUND_OPEN,
	SOUND_HIT001,
	SOUND_MAX,
};

struct Data
{
	const void* buffer;
	int size;
};

struct ImageData
{
	const void* buffer;
	int width;
	int height;
};

struct BgMapData
{
	const unsigned char* buffer;
	int width;
	int height;
	int back_red;
	int back_green;
	int back_blue;
};

struct SoundData
{
	const unsigned char* buffer;
	int size;
};

const Data* GetData(int number);
const ImageData* GetImageData(int number);
const BgMapData* GetBgMapData(int number);
const SoundData* GetSoundData(int number);

#endif
