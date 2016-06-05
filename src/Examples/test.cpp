#include <Aurora/GUIWindow.h>
#include <Aurora/Application.h>
using namespace std;

arslot_t slot_MyWindow_on_open();

arslot_t AuroraMain()
{
	GUIWindow *MyWindow = new GUIWindow("Test Window", 800, 600, slot_MyWindow_on_open);
}

arslot_t slot_MyWindow_on_open()
{
	GUIWindow *MyOtherWindow = new GUIWindow("Other Test Window", 600, 800);
}

int main(int argc, char * argv[])
{
	AuroraApplication *MyApp = new AuroraApplication(AuroraMain, true);
	delete MyApp;
	return 1;
}
