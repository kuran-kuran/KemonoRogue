#include "TinyLibrary.hpp"
#include "Character.h"
#include "Player.h"
#include "Item.h"
#include "DustEffect.h"
#include "Enemy.h"
#include "Window.h"
#include "StatusWindow.h"
#include "ItemWindow.h"
#include "Button.h"
#include "TuchikureLogo.h"
#include "Otoyoi.h"
#include "hmix3.h"
#include "DaimonLogo.h"
#include "Title.h"
#include "Title_en.h"
#include "EndingBG.h"
#include "EndingCongratulations.h"
#include "EndingMessage.h"
#include "EndingMessage_jp.h"
#include "Shadow.h"
#include "Cursor.h"
#include "Decision.h"
#include "Tinyrogue_down001.h"
#include "Tinyrogue_open.h"
#include "Tinyrogue_hit001.h"
#include "LeftArrow.h"
#include "RightArrow.h"
#include "Resource.hpp"

Data data[DATA_MAX] = 
{
	// buffer, size
	{NULL, 0}
};

const ImageData image_data[IMAGE_MAX] =
{
	// buffer, width, height
	{NULL, 12, 12},
	{Path1, 12, 12},
	{Wall1, 12, 12},
	{Exit, 12, 12},
	{Treasure, 12, 12},
	{TreasureOpen, 12, 12},
	{SwitchOff, 12, 12},
	{SwitchOn, 12, 12},
	{Path2, 12, 12},
	{Wall2, 12, 12},
	{Exit, 12, 12},
	{Treasure, 12, 12},
	{TreasureOpen, 12, 12},
	{SwitchOff, 12, 12},
	{SwitchOn, 12, 12},
	{Path3, 12, 12},
	{Wall3, 12, 12},
	{Exit, 12, 12},
	{Treasure, 12, 12},
	{TreasureOpen, 12, 12},
	{SwitchOff, 12, 12},
	{SwitchOn, 12, 12},
	{Player1, 96, 12},
	{Player2, 96, 12},
	{Player3, 96, 12},
	{Player4, 96, 12},
	{Item, 84, 36},
	{DustEffect, 24, 12},
	{CeruleanSmallBlue, 24, 12},
	{CeruleanSmallGreen, 24, 12},
	{CeruleanSmallYellow, 24, 12},
	{CeruleanSmallRed, 24, 12},
	{CeruleanSmallPurple, 24, 12},
	{CeruleanMediumBlue, 24, 12},
	{CeruleanMediumGreen, 24, 12},
	{CeruleanMediumYellow, 24, 12},
	{CeruleanMediumRed, 24, 12},
	{CeruleanMediumPurple, 24, 12},
	{CeruleanBigRed, 24, 12},
	{CeruleanBigPurple, 24, 12},
	{CeruleanBlack, 96, 12},
	{Window, 96, 38},
	{StatusWindow, 36, 14},
	{PlayerStatus, 5, 17},
	{ItemWindow, 36, 14},
	{Button_off, 48, 8},
	{Button_on, 48, 8},
	{TuchikureLogo, 96, 64},
	{Otoyoi, 96, 64},
	{hmix3, 96, 64},
	{DaimonLogo, 96, 64},
	{Title, 96, 64},
	{Title_en, 96, 64},
	{EndingBG, 96, 64},
	{EndingCongratulations, 82, 13},
	{EndingMessage, 80, 12},
	{EndingMessage_jp, 44, 12},
	{Shadow, 10, 1},
	{LeftArrow, 4, 7},
	{RightArrow, 4, 7},
};

const BgMapData bg_map_data[BG_MAP_MAX] = 
{
	// buffer, width, height, back_red, back_green, back_blue
	{NULL, 0, 0, 0, 0, 0},
};

const SoundData sound_data[SOUND_MAX] = 
{
	// buffer, size
	{NULL, 0},
	{NULL, 0},
	{Cursor_wave, sizeof(Cursor_wave)},
	{Decision_wave, sizeof(Decision_wave)},
	{Tinyrogue_down001_wave, sizeof(Tinyrogue_down001_wave)},
	{Tinyrogue_open_wave, sizeof(Tinyrogue_open_wave)},
	{Tinyrogue_hit001_wave, sizeof(Tinyrogue_hit001_wave)},
};

const Data* GetData(int number)
{
	return &data[number];
}

const ImageData* GetImageData(int number)
{
	return &image_data[number];
}

const BgMapData* GetBgMapData(int number)
{
	return &bg_map_data[number];
}

const SoundData* GetSoundData(int number)
{
	return &sound_data[number];
}
