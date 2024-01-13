#include "TinyLibrary.hpp"
#include "Global.hpp"

Global* Global::global = NULL;

Global::Global(void)
:phase(PHASE_TUCHIKURE_LOGO)
,before_phase(PHASE_TUCHIKURE_LOGO)
,back_color(0)
,before_button(0)
,game(NULL)
,count(0)
,draw_volume_count(0)
,draw_language_count(0)
,micros_time(0)
,interval_time(0)
,display_fps(false)
,screen_flip_time(0)
,player_type(0)
,player_anime_count(0)
,x(0)
,game_data()
,player_select_cursor(0)
,reward_crystal(0)
,resume(false)
,enable_button(true)
,ending(NULL)
{
}

Global::~Global(void)
{
}

void Global::Initialize(void)
{
	if(Global::global == NULL)
	{
		Global::global = new Global;
	}
}

void Global::Finalize(void)
{
	if(Global::global != NULL)
	{
		delete Global::global;
		Global::global = NULL;
	}
}

Global& Global::GetInstance()
{
	return *Global::global;
}
