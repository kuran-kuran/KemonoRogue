#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#include "Game.hpp"
#include "Ending.hpp"
#include "GameData.hpp"

//#define DISABLE_SELECT_CHARACTER
//#if defined(__APPLE__) && defined(DISABLE_SELECT_CHARACTER)
//#undef DISABLE_SELECT_CHARACTER
//#endif

class Global
{
public:
	enum
	{
		PHASE_TUCHIKURE_LOGO = 0,
		PHASE_OTOYOI_LOGO,
		PHASE_HMIX_LOGO,
		PHASE_DAIMON_LOGO,
		PHASE_TITLE,
		PHASE_SELECT_CHARACTER,
		PHASE_LEVEL_UP,
		PHASE_EVOLUTION,
		PHASE_INITIALIZE_GAME,
		PHASE_GAME,
		PHASE_GAME_END,
		PHASE_GAME_RESULT,
		PHASE_ENDING,
		PHASE_QUIT_MENU,
		PHASE_QUIT_MENU_WAIT
	};
	Global(void);
	~Global(void);
	static Global* global;
	static Global& GetInstance();
	static void Initialize(void);
	static void Finalize(void);
	int phase;
	int before_phase;
	unsigned char back_color;
	unsigned int before_button;
	Game* game;
	int count;
	int draw_volume_count;
	int draw_language_count;
	unsigned long micros_time;
	unsigned long interval_time;
	bool display_fps;
	unsigned long screen_flip_time;
	int player_type;
	int player_anime_count;
	int x;
	GameData game_data;
	int player_select_cursor;
	int reward_crystal;
	bool resume;
	bool enable_button;
	Ending* ending;
	bool quit_menu;
	int quit_menu_wait_counter;
private:
	Global(Global&);
	Global& operator = (Global&);
};

#endif
