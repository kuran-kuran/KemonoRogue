#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TinyLibrary.hpp"
#include "Global.hpp"
#include "Sound.hpp"
#include "Resume.hpp"

void MainLoop_Setup(void)
{
	Global::Initialize();
	Screen::Initialize(8);
	Controller::Initialize();
	Sound::Initialize();
	Global& global = Global::GetInstance();
	global.phase = Global::PHASE_TUCHIKURE_LOGO;
	global.back_color = 0;
	global.before_button = 1;
	global.count = 0;
	Sound& sound = Sound::GetInstance();
	sound.Load();
	if(global.game_data.Load() == true)
	{
		Resume::Data resume_data;
		if(Resume::Load(&resume_data) == true)
		{
			global.resume = true;
			global.phase = Global::PHASE_INITIALIZE_GAME;
		}
	}
	SoundStream& sound_stream = SoundStream::GetInstance();
	sound_stream.SetVolume(global.game_data.GetSoundVolume());
	sound.StopAll();
}

void MainLoop_Finalize(void)
{
	Global& global = Global::GetInstance();
	if(global.ending != NULL)
	{
		delete global.ending;
		global.ending = NULL;
	}
	if(global.game != NULL)
	{
		delete global.game;
		global.game = NULL;
	}
	Sound& sound = Sound::GetInstance();
	sound.StopAll();
	sound.Release();
	Sound::Finalize();
	Controller::Finalize();
	Screen::Finalize();
	Global::Finalize();
}

bool MainLoop_Loop(void)
{
	bool exit = false;
	bool status;
	const GameData::PlayerData* player_data;
	Item item;
	Global& global = Global::GetInstance();
	Screen& screen = Screen::GetInstance();
	Controller& controller = Controller::GetInstance();
	Sound& sound = Sound::GetInstance();
	controller.Update();
	screen.Clear(global.back_color);
	screen.DrawBegin();
	unsigned int button = controller.GetButton();
	const ImageData* image_data;
	bool unlock_level = false;
	bool unlock_floor = false;
	Resume::Data resume_data;
	int popup_x = 0;
	int popup_y = (Screen::HEIGHT - 38) / 2;
	int popup_width = Screen::WIDTH;
	bool button_up = false;
	bool button_down = false;
	int arrow_x_move;
	int x;
	int y;
	int draw_x;
	int draw_y;
	int draw_width;
	switch(global.phase)
	{
	case Global::PHASE_TUCHIKURE_LOGO:
		image_data = GetImageData(TUCHIKURE_LOGO);
		draw_x = (Screen::WIDTH - image_data->width) / 2;
		draw_y = (Screen::HEIGHT - image_data->height) / 2;
		screen.DrawSprite(image_data->buffer, draw_x, draw_y, image_data->width, image_data->height, 0);
		screen.DrawNumberFont(Screen::CENTER, Screen::HEIGHT - 7, "Tuchikure");
		global.back_color = 0;
		if((global.before_button == 0) && (button & (Controller::BUTTON_1 | Controller::BUTTON_2)))
		{
			global.phase = Global::PHASE_OTOYOI_LOGO;
			global.count = 0;
		}
		++ global.count;
		if(global.count > Screen::FPS * 5)
		{
			global.phase = Global::PHASE_OTOYOI_LOGO;
			global.count = 0;
		}
		Mathmatics::Rand();
		break;
	case Global::PHASE_OTOYOI_LOGO:
		image_data = GetImageData(OTOYOI_LOGO);
		draw_x = (Screen::WIDTH - image_data->width) / 2;
		draw_y = (Screen::HEIGHT - image_data->height) / 2;
		screen.DrawSprite(image_data->buffer, draw_x, draw_y, image_data->width, image_data->height, 0);
		screen.DrawNumberFont(Screen::CENTER, Screen::HEIGHT - 7, "Sound Studio");
		global.back_color = 0;
		if((global.before_button == 0) && (button & (Controller::BUTTON_1 | Controller::BUTTON_2)))
		{
			global.phase = Global::PHASE_HMIX_LOGO;
			global.count = 0;
		}
		++ global.count;
		if(global.count > Screen::FPS * 5)
		{
			global.phase = Global::PHASE_HMIX_LOGO;
			global.count = 0;
		}
		Mathmatics::Rand();
		break;
	case Global::PHASE_HMIX_LOGO:
		image_data = GetImageData(HMIX_LOGO);
		draw_x = (Screen::WIDTH - image_data->width) / 2;
		draw_y = (Screen::HEIGHT - image_data->height) / 2;
		screen.DrawSprite(image_data->buffer, draw_x, draw_y, image_data->width, image_data->height, 0);
		global.back_color = 0;
		if((global.before_button == 0) && (button & (Controller::BUTTON_1 | Controller::BUTTON_2)))
		{
			global.phase = Global::PHASE_DAIMON_LOGO;
			global.count = 0;
		}
		++ global.count;
		if(global.count > Screen::FPS * 5)
		{
			global.phase = Global::PHASE_DAIMON_LOGO;
			global.count = 0;
		}
		Mathmatics::Rand();
		break;
	case Global::PHASE_DAIMON_LOGO:
		image_data = GetImageData(DAIMON_LOGO);
		draw_x = (Screen::WIDTH - image_data->width) / 2;
		draw_y = (Screen::HEIGHT - image_data->height) / 2;
		screen.DrawSprite(image_data->buffer, draw_x, draw_y, image_data->width, image_data->height, 0);
		global.back_color = 0;
		if((global.before_button == 0) && (button & (Controller::BUTTON_1 | Controller::BUTTON_2)))
		{
			if(sound.BgmStatus() == false)
			{
				sound.Play(SOUND_BGM_TITLE);
			}
			global.phase = Global::PHASE_TITLE;
			global.count = 0;
		}
		++ global.count;
		if(global.count > Screen::FPS * 5)
		{
			if(sound.BgmStatus() == false)
			{
				sound.Play(SOUND_BGM_TITLE);
			}
			global.phase = Global::PHASE_TITLE;
			global.count = 0;
		}
		Mathmatics::Rand();
		break;
	case Global::PHASE_TITLE:
		if(global.game_data.GetLanguage() == GameData::LANGUAGE_ENGLISH)
		{
			image_data = GetImageData(TITLE_EN);
		}
		else
		{
			image_data = GetImageData(TITLE);
		}
		draw_x = (Screen::WIDTH - image_data->width) / 2;
		draw_y = (Screen::HEIGHT - image_data->height) / 2;
		screen.DrawSprite(image_data->buffer, draw_x, draw_y, image_data->width, image_data->height, 0);
		if(button != 0)
		{
			global.count = 0;
		}
		if((global.before_button == 0) && (button & (Controller::BUTTON_1 | Controller::BUTTON_2)))
		{
			global.player_select_cursor = 1;
#if defined(DISABLE_SELECT_CHARACTER)
			global.phase = Global::PHASE_LEVEL_UP;
#else
			global.x = 42 - (global.player_type * (Game::CHIP_SIZE + 6));
			global.phase = Global::PHASE_SELECT_CHARACTER;
#endif
			global.game_data.Save();
			sound.Play(SOUND_DECISION);
		}
		++ global.count;
		if(global.count > Screen::FPS * 20)
		{
			global.phase = Global::PHASE_TUCHIKURE_LOGO;
			global.count = 0;
		}
		{
			SoundStream& sound_stream = SoundStream::GetInstance();
			int volume = global.game_data.GetSoundVolume();
			if(!(global.before_button & Controller::BUTTON_UP) && (button & Controller::BUTTON_UP))
			{
				++ volume;
				if(volume > SoundStream::MAX_VOLUME)
				{
					volume = SoundStream::MAX_VOLUME;
				}
				global.draw_volume_count = 30;
				global.draw_language_count = 0;
			}
			else if(!(global.before_button & Controller::BUTTON_DOWN) && (button & Controller::BUTTON_DOWN))
			{
				-- volume;
				if(volume < 0)
				{
					volume = 0;
				}
				global.draw_volume_count = 30;
				global.draw_language_count = 0;
			}
			else if(!(global.before_button & Controller::BUTTON_LEFT) && (button & Controller::BUTTON_LEFT))
			{
				global.game_data.SetLanguage(GameData::LANGUAGE_ENGLISH);
				global.draw_volume_count = 0;
				global.draw_language_count = 30;
			}
			else if(!(global.before_button & Controller::BUTTON_RIGHT) && (button & Controller::BUTTON_RIGHT))
			{
				global.game_data.SetLanguage(GameData::LANGUAGE_JAPANESE);
				global.draw_volume_count = 0;
				global.draw_language_count = 30;
			}
			sound_stream.SetVolume(volume);
			global.game_data.SetSoundVolume(volume);
		}
		if(global.draw_volume_count > 0)
		{
			SoundStream& sound_stream = SoundStream::GetInstance();
			screen.DrawRectangle(0, 0, 12 * 4 + 1, 7, 0);
			screen.DrawNumberFont(1, 1, "Volume %02d/%02d", sound_stream.GetVolume(), SoundStream::MAX_VOLUME);
			-- global.draw_volume_count;
		}
		else if(global.draw_language_count > 0)
		{
			screen.DrawRectangle(0, 0, 6 * 7 + 1, 8, 0);
			if(global.game_data.GetLanguage() == GameData::LANGUAGE_ENGLISH)
			{
				screen.DrawJapaneseFont(0, 0, "English");
			}
			else
			{
				screen.DrawJapaneseFont(0, 0, "\xC6\xCE\xDD\xBA\xDE"); // �ɂق񂱁J
			}
			-- global.draw_language_count;
		}
		Mathmatics::Rand();
		break;
	case Global::PHASE_SELECT_CHARACTER:
		// Name
		screen.DrawFont(Screen::CENTER, 1, global.game_data.GetPlayerName(global.player_type));
		// Wall
		image_data = GetImageData(WALL);
		screen.DrawSprite(image_data->buffer, 42, 14, image_data->width, image_data->height - 2, 0);
		// Player list
		for(int i = 0; i < Game::PLAYER_TYPE_MAX; ++i)
		{
			player_data = global.game_data.GetPlayerData(i);
			image_data = GetImageData(PLAYER1 + i);
			int to_x = 42 - (global.player_type * (Game::CHIP_SIZE + 6));
			if(global.x < to_x)
			{
				++ global.x;
			}
			else if(global.x > to_x)
			{
				-- global.x;
			}
			x = global.x + (Game::CHIP_SIZE + 6) * i;
			y = 10;
			if(x == 42)
			{
				y -= 2;
			}
			screen.DrawSprite(image_data->buffer, x, y, Game::CHIP_SIZE, Game::CHIP_SIZE, Game::CHIP_SIZE * (4 + global.player_anime_count / 8), 0, image_data->width, 0);
		}
		// Arrow
		arrow_x_move = (global.player_anime_count / 8) % 2;
		if(global.player_type > 0)
		{
			image_data = GetImageData(LEFT_ARROW);
			screen.DrawSprite(image_data->buffer, 37 + arrow_x_move, 13, image_data->width, image_data->height, 0);
		}
		if(global.player_type < (Game::PLAYER_TYPE_MAX - 1))
		{
			image_data = GetImageData(RIGHT_ARROW);
			screen.DrawSprite(image_data->buffer, 55 - arrow_x_move, 13, image_data->width, image_data->height, 0);
		}
		// Status window
		player_data = global.game_data.GetPlayerData(global.player_type);
		image_data = GetImageData(WINDOW);
		screen.DrawSpriteFrame(image_data->buffer, popup_x, popup_y + 12, popup_width, image_data->height, image_data->width, image_data->height, 0);
		// Player
		x = popup_x + 10;
		y = popup_y + 22;
		image_data = GetImageData(PLAYER1 + global.player_type);
		screen.DrawSprite(image_data->buffer, x, y, Game::CHIP_SIZE, Game::CHIP_SIZE, Game::CHIP_SIZE * (4 + global.player_anime_count / 8), 0, image_data->width, 0);
		if(player_data->lock == true)
		{
			item.Set(Item::LOCK, 0);
			item.Draw(x, y + 6);
			global.player_select_cursor = 0;
		}
		screen.DrawNumberFont(x - 4, y + 16, "Level %d", player_data->level);
		// Status
		x = popup_x + 6;
		y = popup_y + 12;
		image_data = GetImageData(PLAYER_STATUS);
		screen.DrawSprite(image_data->buffer, x + 20, y + 6 + 6 * 0, image_data->width, image_data->height, 0);
		screen.DrawNumberFont(x + 27, y + 6 + 6 * 0, "%4d", player_data->hp);
		screen.DrawNumberFont(x + 27, y + 6 + 6 * 1, "%4d", player_data->attack);
		screen.DrawNumberFont(x + 27, y + 6 + 6 * 2, "%4d", player_data->dcy);
		// Crystal
		x = popup_x;
		y = popup_y;
		item.Set(Item::CRYSTAL, 0);
		item.Draw(x + 2, y + 1);
		screen.DrawNumberFont(x + 15, y + 7, "%d", global.game_data.GetCrystal());
		// Button
		if(player_data->lock == true)
		{

			int use_crystal = global.game_data.UnlockCrystal(global.player_type);
			// Button
			if(use_crystal <= global.game_data.GetCrystal())
			{
				image_data = GetImageData(BUTTON_ON);
			}
			else
			{
				image_data = GetImageData(BUTTON_OFF);
			}
			draw_x = x + 44;
			draw_width = popup_width - draw_x - 3;
			screen.DrawSpriteFrame(image_data->buffer, draw_x, y + 37, draw_width, image_data->height, image_data->width, image_data->height, 0);
			// Use crystal
			screen.DrawNumberFont(x + 53, y + 39, "Unlock");
			item.Set(Item::CRYSTAL, 0);
			if(use_crystal > 0)
			{
				item.Draw(popup_width - 31, popup_y + 25);
				screen.DrawNumberFont(popup_width - 19, popup_y + 29, "%d", use_crystal);
			}
		}
		else
		{
			// Button
			image_data = GetImageData(BUTTON_ON);
			draw_x = x + 44;
			draw_width = popup_width - draw_x - 3;
			screen.DrawSpriteFrame(image_data->buffer, draw_x, y + 37, draw_width, image_data->height, image_data->width, image_data->height, 0);
			screen.DrawNumberFont(x + 53, y + 39, "Next");
		}
		if(!(global.before_button & Controller::BUTTON_RIGHT) && (button & Controller::BUTTON_RIGHT))
		{
			++ global.player_type;
			if(global.player_type >= Game::PLAYER_TYPE_MAX)
			{
				global.player_type = Game::PLAYER_TYPE_MAX - 1;
			}
			sound.Play(SOUND_CURSOR);
		}
		else if(!(global.before_button & Controller::BUTTON_LEFT) && (button & Controller::BUTTON_LEFT))
		{
			-- global.player_type;
			if(global.player_type < 0)
			{
				global.player_type = 0;
			}
			sound.Play(SOUND_CURSOR);
		}
		++ global.player_anime_count;
		if(global.player_anime_count >= 16)
		{
			global.player_anime_count = 0;
		}
		if((global.before_button == 0) && (button & (Controller::BUTTON_1 | Controller::BUTTON_2)))
		{
			if(player_data->lock == true)
			{
				// Unlock
				if(global.game_data.CheckUnlock(global.player_type) == true)
				{
					global.game_data.Unlock(global.player_type);
				}
			}
			else
			{
				global.phase = Global::PHASE_LEVEL_UP;
			}
			sound.Play(SOUND_DECISION);
		}
		break;
	case Global::PHASE_LEVEL_UP:
		image_data = GetImageData(WINDOW);
		screen.DrawSpriteFrame(image_data->buffer, popup_x, popup_y, popup_width, image_data->height, image_data->width, image_data->height, 0);
		player_data = global.game_data.GetPlayerData(global.player_type);
		if((player_data->lock == false) && (global.player_select_cursor == 1) && (global.before_button == 0) && (button & (Controller::BUTTON_1 | Controller::BUTTON_2)))
		{
			global.phase = Global::PHASE_INITIALIZE_GAME;
			global.game_data.Save();
			sound.Play(SOUND_DECISION);
		}
		if((global.player_select_cursor == 0) && (global.before_button == 0) && (button & (Controller::BUTTON_1 | Controller::BUTTON_2)))
		{
			if(player_data->lock == true)
			{
				// Unlock
				if(global.game_data.CheckUnlock(global.player_type) == true)
				{
					global.game_data.Unlock(global.player_type);
					sound.Play(SOUND_DECISION);
				}
			}
			else if(global.game_data.CheckLevelUp(global.player_type) == true)
			{
				// Level up
				global.game_data.LevelUp(global.player_type);
				sound.Play(SOUND_DECISION);
			}
		}
#if defined(DISABLE_SELECT_CHARACTER)
		if(!(global.before_button & Controller::BUTTON_RIGHT) && (button & Controller::BUTTON_RIGHT))
		{
			++ global.player_type;
			if(global.player_type >= Game::PLAYER_TYPE_MAX)
			{
				global.player_type = Game::PLAYER_TYPE_MAX - 1;
			}
			sound.Play(SOUND_CURSOR);
		}
		else if(!(global.before_button & Controller::BUTTON_LEFT) && (button & Controller::BUTTON_LEFT))
		{
			-- global.player_type;
			if(global.player_type < 0)
			{
				global.player_type = 0;
			}
			sound.Play(SOUND_CURSOR);
		}
#endif
		if(((button_up == true) && (global.player_select_cursor == 1)) || (!(global.before_button & Controller::BUTTON_UP) && (button & Controller::BUTTON_UP)))
		{
			global.player_select_cursor = 0;
			sound.Play(SOUND_CURSOR);
		}
		else if(((button_down == true) && (global.player_select_cursor == 0)) || (!(global.before_button & Controller::BUTTON_DOWN) && (button & Controller::BUTTON_DOWN)))
		{
			global.player_select_cursor = 1;
			if(player_data->lock != true)
			{
				sound.Play(SOUND_CURSOR);
			}
		}
		player_data = global.game_data.GetPlayerData(global.player_type);
		if(player_data->lock == true)
		{
			global.player_select_cursor = 0;
		}
		if(global.player_select_cursor == 0)
		{
			image_data = GetImageData(BUTTON_ON);
		}
		else
		{
			image_data = GetImageData(BUTTON_OFF);
		}
		draw_x = popup_x + 41;
		draw_width = popup_width - draw_x - 3;
		screen.DrawSpriteFrame(image_data->buffer, draw_x, popup_y + 16, draw_width, image_data->height, image_data->width, image_data->height, 0);
		if(player_data->lock == true)
		{
			screen.DrawNumberFont(popup_x + 49, popup_y + 18, "Unlock");
		}
		else
		{
			screen.DrawNumberFont(popup_x + 49, popup_y + 18, "Levelup");
		}
		if(global.player_select_cursor == 1)
		{
			image_data = GetImageData(BUTTON_ON);
		}
		else
		{
			image_data = GetImageData(BUTTON_OFF);
		}
		screen.DrawSpriteFrame(image_data->buffer, draw_x, popup_y + 25, draw_width, image_data->height, image_data->width, image_data->height, 0);
		screen.DrawNumberFont(popup_x + 49, popup_y + 26, "Start");
		image_data = GetImageData(PLAYER1 + global.player_type);
		screen.DrawSprite(image_data->buffer, popup_x + 6, popup_y + 15, Game::CHIP_SIZE, Game::CHIP_SIZE, Game::CHIP_SIZE * (4 + global.player_anime_count / 8), 0, image_data->width, 0);
		if(player_data->lock == true)
		{
			item.Set(Item::LOCK, 0);
			item.Draw(popup_x + 6, popup_y + 21);
			global.player_select_cursor = 0;
		}
		// Use crystal
		if(global.player_select_cursor == 0)
		{
			int use_crystal = 0;
			item.Set(Item::CRYSTAL, 0);
			if(player_data->lock == true)
			{
				use_crystal = global.game_data.UnlockCrystal(global.player_type);
			}
			else if(global.game_data.CheckLevelUp(global.player_type) == true)
			{
				use_crystal = global.game_data.LevelUpCrystal(global.player_type);
			}
			if(use_crystal > 0)
			{
				item.Draw(popup_x + 42, popup_y + 4);
				screen.DrawNumberFont(popup_x + 54, popup_y + 8, "%d", use_crystal);
			}
		}
#if defined(DISABLE_SELECT_CHARACTER)
		if(global.player_type > 0)
		{
			image_data = GetImageData(LEFT_ARROW);
			screen.DrawSprite(image_data->buffer, popup_x + 3 - global.player_anime_count / 8, popup_y + 19, image_data->width, image_data->height, 0);
		}
		if(global.player_type < (Game::PLAYER_TYPE_MAX - 1))
		{
			image_data = GetImageData(RIGHT_ARROW);
			screen.DrawSprite(image_data->buffer, popup_x + 18 + global.player_anime_count / 8, popup_y + 19, image_data->width, image_data->height, 0);
		}
#endif
		++ global.player_anime_count;
		if(global.player_anime_count >= 16)
		{
			global.player_anime_count = 0;
		}
		item.Set(Item::CRYSTAL, 0);
		item.Draw(popup_x + 3, popup_y - 11);
		image_data = GetImageData(PLAYER_STATUS);
		screen.DrawSprite(image_data->buffer, popup_x + 21, popup_y + 6 + 6 * 1, image_data->width, image_data->height, 0);
		screen.DrawNumberFont(popup_x + 16, popup_y - 6, "%d", global.game_data.GetCrystal());
		screen.DrawNumberFont(popup_x + 4, popup_y + 5, "Level %d", player_data->level);
		screen.DrawNumberFont(popup_x + 16, popup_y + 6 + 6 * 1, "  %4d", player_data->hp);
		screen.DrawNumberFont(popup_x + 16, popup_y + 6 + 6 * 2, "  %4d", player_data->attack);
		screen.DrawNumberFont(popup_x + 16, popup_y + 6 + 6 * 3, "  %4d", player_data->dcy);
		// Unlock
		if((player_data->level == 100) && (global.game_data.CheckLevelUp(global.player_type) == true))
		{
			unlock_level = true;
		}
		if(global.game_data.GetClear(global.player_type) == true)
		{
			unlock_floor = true;
		}
		if((unlock_level == true) && (unlock_floor == true))
		{
			screen.DrawNumberFont(Screen::CENTER, popup_y + 40, "Unlock level&floor");
		}
		else if(unlock_level == true)
		{
			screen.DrawNumberFont(Screen::CENTER, popup_y + 40, "Unlock level");
		}
		else if(unlock_floor == true)
		{
			screen.DrawNumberFont(Screen::CENTER, popup_y + 40, "Unlock floor");
		}
		break;
	case Global::PHASE_INITIALIZE_GAME:
		global.game = new Game;
		if(global.resume == true)
		{
			if(Resume::Load(&resume_data) == true)
			{
				global.player_type = resume_data.player_type;
				Mathmatics::RandSeed(resume_data.check_sum);
				global.game->SetFloor(resume_data.floor);
			}
			else
			{
				global.resume = false;
			}
		}
		global.game->Initialize(global.player_type);
		if(global.resume == true)
		{
			global.game->LoadResume(&resume_data);
		}
		global.phase = Global::PHASE_GAME;
		sound.Play(SOUND_BGM_STAGE);
		break;
	case Global::PHASE_GAME:
		status = global.game->Update();
		global.game->Draw();
		global.back_color = global.game->GetBackColor();
		if(status == true)
		{
			sound.StopAll();
			global.phase = Global::PHASE_GAME_END;
		}
		break;
	case Global::PHASE_GAME_END:
		global.game_data.AddCrystal(global.game->GetCrystal());
		global.game_data.Save();
		global.phase = Global::PHASE_GAME_RESULT;
		break;
	case Global::PHASE_GAME_RESULT:
		popup_x = 0;
		popup_y = (Screen::HEIGHT - 38) / 2;
		image_data = GetImageData(WINDOW);
		screen.DrawSpriteFrame(image_data->buffer, popup_x, popup_y, popup_width, image_data->height, image_data->width, image_data->height, 0);
		if(global.game->GetClear() == true)
		{
			screen.DrawNumberFont(Screen::CENTER, popup_y - 10, "Congratulations!");
		}
		else
		{
			screen.DrawFont(Screen::CENTER, popup_y - 10, "GAMEOVER");
		}
		screen.DrawNumberFont(20, popup_y + 6, "Result");
		screen.DrawNumberFont(30, popup_y + 16, "Floor B%02dF", global.game->GetFloor());
		item.Set(Item::CRYSTAL, 0);
		item.Draw(popup_x + 27, popup_y + 21);
		screen.DrawNumberFont(popup_x + 40, popup_y + 25, "%d", global.game->GetCrystal());
		image_data = GetImageData(PLAYER1 + global.player_type);
		screen.DrawSprite(image_data->buffer, popup_x + 8, popup_y + 16, Game::CHIP_SIZE, Game::CHIP_SIZE, Game::CHIP_SIZE * (4 + global.player_anime_count / 8), 0, image_data->width, 0);
		++ global.player_anime_count;
		if(global.player_anime_count >= 16)
		{
			global.player_anime_count = 0;
		}
		if((global.before_button == 0) && (button & (Controller::BUTTON_1 | Controller::BUTTON_2)))
		{
			Resume::DeleteResumeDataFile();
			global.reward_crystal = global.game->GetCrystal();
			if(global.game->GetClear() == true)
			{
				global.ending = new Ending;
				global.ending->Initialize();
				global.phase = Global::PHASE_ENDING;
			}
			else
			{
				global.phase = Global::PHASE_TITLE;
				sound.Play(SOUND_BGM_TITLE);
			}
			delete global.game;
			global.game = NULL;
		}
		break;
	case Global::PHASE_ENDING:
		status = global.ending->Update();
		global.ending->Draw();
		if(status == true)
		{
			if(global.ending != NULL)
			{
				delete global.ending;
				global.ending = NULL;
			}
			global.phase = Global::PHASE_TITLE;
			sound.Play(SOUND_BGM_TITLE);
		}
		break;
	}
	if((button & Controller::BUTTON_START) && (button & Controller::BUTTON_SELECT))
	{
		exit = true;
	}
	screen.DrawEnd();
	global.before_button = button;
	return exit;
}

void MainLoop_NoWaitLoop(void)
{
	Sound& sound = Sound::GetInstance();
	sound.Update();
}
