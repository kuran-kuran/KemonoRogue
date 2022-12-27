#ifndef SOUND_HPP
#define SOUND_HPP

#include "Resource.hpp"

class Sound
{
public:
	enum
	{
		BGM_START = SOUND_BGM_TITLE,
		BGM_END = SOUND_BGM_STAGE,
	};
	Sound(void);
	~Sound(void);
	static Sound* sound;
	static void Initialize(void);
	static void Finalize(void);
	static Sound& GetInstance();
	void Load(void);
	void Release(void);
	void Play(int sound_number);
	void StopAll(void);
	void Update(void);
	void Replay(void);
	void ResetReplay(void);
	bool BgmStatus(void);
private:
	Sound(Sound&);
	Sound& operator = (Sound&);
	int sound_handle[SOUND_MAX];
	int before_bgm_sound_number;
	bool playing_bgm;
};

#endif
