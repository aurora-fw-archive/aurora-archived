#include <Aurora/GUI/Button.h>

#include <gtk/gtk.h>

namespace Aurora {
	namespace GUI {
		Button::Button(Window* &parent, std::string name) {
			button = gtk_button_new_with_label(name.c_str());
			WindowParent = parent->window;
			gtk_container_add(GTK_CONTAINER(WindowParent), button);
		}

		Button::~Button() {
			delete button;
		}
	}
}
