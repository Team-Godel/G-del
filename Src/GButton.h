//---------------------------------------------------------------------------

#ifndef GButtonH
#define GButtonH
#include "GItem.h"
#include "GWindow.h"
//---------------------------------------------------------------------------

namespace gdl{
	class GButton : public item{
	public:
		// The first constructor, just without parameters
		GButton() : isPulsed(false) {};
		void altPulsed();
		void link(GWindow*wnd);
		// auto ifIsPulsed(callFunction);
	private:
		HINSTANCE instance;
		bool isPulsed;
		// I think that this function should be in the item class, because
		// every children of that class need to has one
		static LRESULT CALLBACK buttonProcedure(HWND, UINT, WPARAM, LPARAM);
	};
}
#endif
