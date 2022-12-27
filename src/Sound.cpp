#include "TinyLibrary.hpp"
#include "Global.hpp"
#include "Sound.hpp"

Sound* Sound::sound;

Sound::Sound(void)
:before_bgm_sound_number(-1)
,playing_bgm(false)
{
	for(int i = 0; i < SOUND_MAX; ++ i)
	{
		sound_handle[i] = 0;
	}
}

Sound::~Sound(void)
{
	for(int i = 0; i < SOUND_MAX; ++ i)
	{
		this->sound_handle[i] = 0;
	}
}

void Sound::Initialize(void)
{
	Sound::sound = new Sound();
	SoundPlayer::Initialize(11025);
}

void Sound::Finalize(void)
{
	SoundPlayer::Finalize();
	if(Sound::sound != NULL)
	{
		delete Sound::sound;
		Sound::sound = NULL;
	}
}

Sound& Sound::GetInstance()
{
	return *Sound::sound;
}

void Sound::Load(void)
{
	SoundPlayer& sound_player = SoundPlayer::GetInstance();
	Global& global = Global::GetInstance();
	this->sound_handle[SOUND_BGM_TITLE] = sound_player.Append(0, "KemonoRogue/title.raw", true, SoundPlayer::RAW);
	if(this->sound_handle[SOUND_BGM_TITLE] == -1)
	{
		this->sound_handle[SOUND_BGM_TITLE] = sound_player.Append(0, "KemonoRogue/title.adp", true, SoundPlayer::ADP);
	}
	this->sound_handle[SOUND_BGM_STAGE] = sound_player.Append(0, "KemonoRogue/stage.raw", true, SoundPlayer::RAW);
	if(this->sound_handle[SOUND_BGM_STAGE] == -1)
	{
		this->sound_handle[SOUND_BGM_STAGE] = sound_player.Append(0, "KemonoRogue/stage.adp", true, SoundPlayer::ADP);
	}
	const SoundData* sound_data = GetSoundData(SOUND_CURSOR);
	this->sound_handle[SOUND_CURSOR] = sound_player.Append(1, sound_data->buffer, sound_data->size, false, SoundPlayer::RAW);
	sound_data = GetSoundData(SOUND_DECISION);
	this->sound_handle[SOUND_DECISION] = sound_player.Append(1, sound_data->buffer, sound_data->size, false, SoundPlayer::RAW);
	sound_data = GetSoundData(SOUND_DOWN);
	this->sound_handle[SOUND_DOWN] = sound_player.Append(1, sound_data->buffer, sound_data->size, false, SoundPlayer::RAW);
	sound_data = GetSoundData(SOUND_OPEN);
	this->sound_handle[SOUND_OPEN] = sound_player.Append(1, sound_data->buffer, sound_data->size, false, SoundPlayer::RAW);
	sound_data = GetSoundData(SOUND_HIT001);
	this->sound_handle[SOUND_HIT001] = sound_player.Append(1, sound_data->buffer, sound_data->size, false, SoundPlayer::RAW);
}

void Sound::Release(void)
{
	SoundPlayer& sound_player = SoundPlayer::GetInstance();
	sound_player.StopAll();
	sound_player.Delete(this->sound_handle[SOUND_BGM_TITLE]);
	sound_player.Delete(this->sound_handle[SOUND_BGM_STAGE]);
	sound_player.Delete(this->sound_handle[SOUND_CURSOR]);
	sound_player.Delete(this->sound_handle[SOUND_DECISION]);
	sound_player.Delete(this->sound_handle[SOUND_DOWN]);
	sound_player.Delete(this->sound_handle[SOUND_OPEN]);
	sound_player.Delete(this->sound_handle[SOUND_HIT001]);
}

void Sound::Play(int sound_number)
{
	Global& global = Global::GetInstance();
	if((sound_number >= BGM_START) && (sound_number <= BGM_END))
	{
		this->playing_bgm = true;
		before_bgm_sound_number = sound_number;
	}
	if(global.game_data.GetSoundVolume() == 0)
	{
		return;
	}
	SoundPlayer& sound_player = SoundPlayer::GetInstance();
	sound_player.Play(this->sound_handle[sound_number]);
}

void Sound::StopAll(void)
{
	SoundPlayer& sound_player = SoundPlayer::GetInstance();
	sound_player.StopAll();
	this->playing_bgm = false;
}

void Sound::Update(void)
{
	SoundPlayer& sound_player = SoundPlayer::GetInstance();
	sound_player.Update();
}

void Sound::Replay(void)
{
	if(this->before_bgm_sound_number == -1)
	{
		return;
	}
	Play(this->before_bgm_sound_number);
}

void Sound::ResetReplay(void)
{
	this->before_bgm_sound_number = -1;
}

bool Sound::BgmStatus(void)
{
	return this->playing_bgm;
}
