// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#ifndef INCLUDE_H_AURORA_GUI_LABEL
#define INCLUDE_H_AURORA_GUI_LABEL

#include <Aurora/GUI/Window.h>
#include <Aurora/GUI/Layout.h>
#include <Aurora/Core/Aurora.h>

/* TODO: Add:
	Functions
	- set/get alignment
	- get selected text
	
	Event Functions
	- onClick
	- onTextChange
*/

typedef struct _GtkWidget GtkWidget;

namespace Aurora
{
	class GUILabel
	{
	public:
		GUILabel(GUIWindow *parent, std::string name = "New Label");
		void setText(std::string);
		std::string getText();
		void setSelectable(bool);
		bool getSelectable();
		void setWrap(bool);
		bool getLineWrap();
		void setWrapMode(WrapMode);
		WrapMode getWrapMode();
		void setAlignment(AlignMode);
		void setAlignment(const float, const float);
		AlignMode getAlignment();
		float getXAlignment();
		float getYAlignment();

	protected:
		unsigned long ID = 0;
		GtkWidget *Label;
	private:
		GtkWidget *WindowParent;
	};
}

#endif // INCLUDE_H_AURORA_GUI_LABEL