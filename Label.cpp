#include "DXUT.h"
#include "Label.h"

void Label::Create_Label(int str, vector2 vec)
{
	Delete_Label();

	Addpos = 0;
	_position = vec;

	for (auto it : to_wstring(str))
	{
		Sprite* s = new Sprite;
		s->Create(L"font/" + to_wstring(it - 48) + L".png");
		s->_position = { Addpos + _position.x,_position.y };
		Addpos += 25;
		sp.push_back(s);
	}
}

void Label::Delete_Label()
{
	for (auto it : sp)
	{
		delete it;
	}
	sp.clear();
}
