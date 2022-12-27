#ifndef POPUP_HPP
#define POPUP_HPP

class Popup
{
public:
	enum
	{
		TYPE_MESSAGE = 0,
		TYPE_SELECT,
		RESULT_NONE = 0,
		RESULT_DECISION,
		RESULT_CANCEL,
	};
	Popup(void);
	virtual ~Popup(void);
	void Initialize(int type);
	void Update(void);
	void DrawFrame(void);
	virtual void Draw(void) = 0;
	int GetResult(void);
private:
	Popup(Popup&);
	Popup& operator = (Popup&);
protected:
	int type;
	int result;
	int select;
	int before_select;
	int popup_y;
	int popup_x;
	unsigned int before_button;
};

#endif
