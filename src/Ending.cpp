#include "Ending.hpp"
#include "Game.hpp"
#include "Item.hpp"
#include "Global.hpp"

Ending::Ending(void)
:time(0)
{
	Global& global = Global::GetInstance();
	int clear_player_count = 0;
	for(int i = 0; i < Game::PLAYER_TYPE_MAX; ++ i)
	{
		if(global.game_data.GetClear(i) == true)
		{
			++ clear_player_count;
		}
	}
	int add_x = Game::CHIP_SIZE + 2;
	int x = (Screen::WIDTH - (add_x * clear_player_count)) / 2;
	for(int i = 0; i < Game::PLAYER_TYPE_MAX; ++ i)
	{
		this->player[i].x = 0;
		this->player[i].y = 0;
		this->player[i].anime_count = 0;
		this->player[i].enable = false;
		if(global.game_data.GetClear(i) == true)
		{
			this->player[i].x = x;
			this->player[i].y = 47;
			this->player[i].anime_count = Mathmatics::Rand() % 15;
			this->player[i].enable = true;
			this->heart[i].x = x;
			this->heart[i].y = 47 - 10;
			this->heart[i].anime_count = this->player[i].anime_count;
			x += add_x;
		}
	}
	this->boss_x = x;
}

Ending::~Ending(void)
{
}

void Ending::Initialize(void)
{
}

bool Ending::Update(void)
{
	Global& global = Global::GetInstance();
	bool result = false;
	Controller& controller = Controller::GetInstance();
	unsigned int button = controller.GetButton();
	if((global.before_button == 0) && (button & (Controller::BUTTON_1 | Controller::BUTTON_2)))
	{
		if(this->time > WAIT_TIME)
		{
			result = true;
		}
	}
	for(int i = 0; i < Game::PLAYER_TYPE_MAX; ++ i)
	{
		if(this->player[i].enable == false)
		{
			continue;
		}
		++ this->player[i].anime_count;
		if(this->player[i].anime_count > 15)
		{
			this->player[i].anime_count = Mathmatics::Rand() % 4;
		}
		++ this->heart[i].anime_count;
		if(this->heart[i].anime_count > 31)
		{
			this->heart[i].anime_count = Mathmatics::Rand() % 4;
		}
	}
	++ this->time;
	return result;
}

void Ending::Draw(void)
{
	Global& global = Global::GetInstance();
	Screen& screen = Screen::GetInstance();
	Item item;
	const ImageData* image_data = image_data = GetImageData(ENDING_BG);
	int draw_x = (Screen::WIDTH - image_data->width) / 2;
	int draw_y = (Screen::HEIGHT - image_data->height) / 2;
	screen.DrawSprite(image_data->buffer, draw_x, draw_y, image_data->width, image_data->height, 0);
	image_data = GetImageData(ENDING_ENDINGCONGRATULATIONS);
	screen.DrawSprite(image_data->buffer, (Screen::WIDTH - image_data->width) / 2, 2, image_data->width, image_data->height, 0);
	if(global.game_data.GetLanguage() == GameData::LANGUAGE_ENGLISH)
	{
		image_data = GetImageData(ENDING_MESSAGE);
	}
	else
	{
		image_data = GetImageData(ENDING_MESSAGE_JP);
	}
	screen.DrawSprite(image_data->buffer, (Screen::WIDTH - image_data->width) / 2, 17, image_data->width, image_data->height, 0);
	for(int i = 0; i < Game::PLAYER_TYPE_MAX; ++ i)
	{
		if(this->player[i].enable == false)
		{
			continue;
		}
		// Friends & Shadow
		int source_x = Game::CHIP_SIZE * 4;
		int add_y = 0;
		int add_x = Mathmatics::Sin8(this->player[i].anime_count * 8) / 48;
		if(this->player[i].anime_count < 8)
		{
			add_y = -this->player[i].anime_count / 2;
		}
		else
		{
			add_y = -(8 - ((this->player[i].anime_count) - 8)) / 2;
		}
		image_data = GetImageData(SHADOW);
		int shadow_add_x = add_x / 2;
		int shadow_width = image_data->width - shadow_add_x * 2;
		screen.DrawSprite(image_data->buffer, this->player[i].x + 1 + shadow_add_x, this->player[i].y + Game::CHIP_SIZE - 1, shadow_width, image_data->height, 0, 0, image_data->width, 0);
		image_data = GetImageData(PLAYER1 + i);
		screen.DrawSprite(image_data->buffer, this->player[i].x, this->player[i].y + add_y, Game::CHIP_SIZE, Game::CHIP_SIZE, source_x, 0, image_data->width, 0);
		// heart
		add_y = -this->heart[i].anime_count / 2;
		item.Set(Item::HEART, 0);
		item.Draw(this->heart[i].x + add_x, this->heart[i].y + add_y);
	}
	// Boss shadow
	image_data = GetImageData(SHADOW);
	screen.DrawSprite(image_data->buffer, boss_x + 2, 51 + Game::CHIP_SIZE - 2, image_data->width, image_data->height, 0);
	// Boss
	item.Set(Item::BOSS, 0);
	item.Draw(boss_x, 51);
}
