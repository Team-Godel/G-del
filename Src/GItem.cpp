// ---------------------------------------------------------------------------

#pragma hdrstop

#include "GItem.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

namespace gdl
{
	void item::setHandler(HWND handler)
	{
		this->handler = handler;
	};

	void item::setPosition(int x, int y)
	{
		this->xPosition = x;
		this->yPosition = y;
	};

	void item::setSize(int height, int width)
	{
		this->height = height;
		this->width = width;
	};
}
