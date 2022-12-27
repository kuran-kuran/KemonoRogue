#include "TinyLibrary.hpp"
#include "Global.hpp"
#include "Sound.hpp"
#include "Popup.hpp"

Popup::Popup(void)
:type(TYPE_SELECT)
,result(RESULT_NONE)
,select(RESULT_CANCEL)
,before_select(RESULT_CANCEL)
,popup_x(0)
,popup_y((Screen::HEIGHT - 38) / 2)
,before_button(1)
{
}

Popup::~Popup(void)
{
}

void Popup::Initialize(int type)
{
	this->type = type;
}

void Popup::Update(void)
{
	Global& global = Global::GetInstance();
	Controller& controller = Controller::GetInstance();
	Sound& sound = Sound::GetInstance();
	unsigned int button = controller.GetButton();
	if(this->type == TYPE_SELECT)
	{
		if((this->before_button == 0) && (button & Controller::BUTTON_UP))
		{
			this->select = RESULT_DECISION;
		}
		else if((this->before_button == 0) && (button & Controller::BUTTON_DOWN))
		{
			this->select = RESULT_CANCEL;
		}
	}
	else
	{
		this->select = RESULT_DECISION;
	}
	if((this->before_button == 0) && (button & (Controller::BUTTON_1 | Controller::BUTTON_2)))
	{
		sound.Play(SOUND_DECISION);
		this->result = this->select;
	}
	else
	{
		if(this->select != this->before_select)
		{
			if(this->type == TYPE_SELECT)
			{
				sound.Play(SOUND_CURSOR);
			}
		}
	}
	this->before_select = this->select;
	this->before_button = button;
	controller.Reset();
}

void Popup::DrawFrame(void)
{
	Screen& screen = Screen::GetInstance();
	const ImageData* image_data = GetImageData(WINDOW);
	screen.DrawSpriteFrame(image_data->buffer, this->popup_x, this->popup_y, Screen::WIDTH, image_data->height, image_data->width, image_data->height, 0);
	if(this->type == TYPE_SELECT)
	{
		if(this->select != RESULT_NONE)
		{
			Screen& screen = Screen::GetInstance();
			int draw_x = this->popup_x + 46;
			int draw_width = Screen::WIDTH - draw_x - 3;
			if(this->select == RESULT_DECISION)
			{
				image_data = GetImageData(BUTTON_ON);
				screen.DrawSpriteFrame(image_data->buffer, draw_x, this->popup_y + 16, draw_width, image_data->height, image_data->width, image_data->height, 0);
				image_data = GetImageData(BUTTON_OFF);
				screen.DrawSpriteFrame(image_data->buffer, draw_x, this->popup_y + 25, draw_width, image_data->height, image_data->width, image_data->height, 0);
			}
			else
			{
				image_data = GetImageData(BUTTON_OFF);
				screen.DrawSpriteFrame(image_data->buffer, draw_x, this->popup_y + 16, draw_width, image_data->height, image_data->width, image_data->height, 0);
				image_data = GetImageData(BUTTON_ON);
				screen.DrawSpriteFrame(image_data->buffer, draw_x, this->popup_y + 25, draw_width, image_data->height, image_data->width, image_data->height, 0);
			}
		}
	}
}

int Popup::GetResult(void)
{
	return this->result;
}
