#pragma once

#include <Aurora/Common.h>

#include <Aurora/GUI/Window.h>

typedef struct _GtkWidget GtkWidget;

namespace Aurora {
	namespace GUI {
		class AURORA_PREFIX Button {
		public:
			Button(Window*& , std::string );
			~Button();
		protected:
			unsigned long ID = 0;
			GtkWidget *button;
		private:
			GtkWidget *WindowParent;
		};
	}
}
