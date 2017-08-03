// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#include <gtk/gtk.h>

#include <Aurora/GUI/Label.h>
#include <Aurora/GUI/Window.h>
#include <Aurora/CLI/Log.h>
#include <Aurora/Core/Debug.h>

namespace Aurora
{
	namespace GUI {
		Label::Label(Window* &parent, std::string name)
		{
			ID = (unsigned)(long) Aurora::Debug::LastID;
			Aurora::Debug::LastID++;
			Shell::Log(Shell::Debug, "creating new label: id_", ID, " on window id_", parent->ID);
			label = gtk_label_new (name.c_str());
			WindowParent = parent->window;
			gtk_container_add(GTK_CONTAINER(WindowParent), label);
			Shell::Log(Shell::Debug, "label id_", ID, " is created on window id_", parent->ID);
		}

		Label::~Label() {
			delete label;
		}

		//Settings
		void Label::setText(std::string text)
		{
			Shell::Log(Shell::Debug, "setting text on label id_", ID);
			gtk_label_set_text((GtkLabel*)label, text.c_str());
		}
		std::string Label::getText()
		{
			Shell::Log(Shell::Debug, "getting text from label id_", ID);
			return std::string(gtk_label_get_text ((GtkLabel*)label));
		}
		void Label::setSelectable(bool value)
		{
			Shell::Log(Shell::Debug, "setting selectable property on label id_", ID);
			gtk_label_set_selectable((GtkLabel*)label, value);
		}
		bool Label::isSelectable()
		{
			Shell::Log(Shell::Debug, "getting selectable property from label id_", ID);
			return gtk_label_get_selectable((GtkLabel*)label);
		}
		void Label::setWrap(bool value)
		{
			Shell::Log(Shell::Debug, "setting wrap property on label id_", ID);
			gtk_label_set_line_wrap((GtkLabel*)label, value);
		}
		bool Label::isWrap()
		{
			Shell::Log(Shell::Debug, "getting wrap property from label id_", ID);
			return gtk_label_get_line_wrap((GtkLabel*)label);
		}
		void Label::setWrapMode(WrapMode mode)
		{
			Shell::Log(Shell::Debug, "setting wrap mode property on label id_", ID);
			gtk_label_set_line_wrap_mode((GtkLabel*)label, (PangoWrapMode)mode);
		}
		WrapMode Label::getWrapMode()
		{
			Shell::Log(Shell::Debug, "getting wrap mode property from label id_", ID);
			return (WrapMode)gtk_label_get_line_wrap_mode((GtkLabel*)label);
		}
		void Label::setAlignment(AlignMode mode)
		{
			bool isCustom = false;
			switch(mode)
			{
				case AlignMode::TopLeft :
					Shell::Log(Shell::Debug, "setting alignment mode to 'TopLeft' property from label id_", ID);
					gtk_label_set_xalign((GtkLabel*)label, 0);
					gtk_label_set_yalign((GtkLabel*)label, 0);
					break;
				case AlignMode::TopCenter :
					Shell::Log(Shell::Debug, "setting alignment mode to 'TopCenter' property from label id_", ID);
					gtk_label_set_xalign((GtkLabel*)label, 0.5);
					gtk_label_set_yalign((GtkLabel*)label, 0);
					break;
				case AlignMode::TopRight :
					Shell::Log(Shell::Debug, "setting alignment mode to 'TopRight' property from label id_", ID);
					gtk_label_set_xalign((GtkLabel*)label, 1);
					gtk_label_set_yalign((GtkLabel*)label, 0);
					break;
				case AlignMode::Left :
					Shell::Log(Shell::Debug, "setting alignment mode to 'Left' property from label id_", ID);
					gtk_label_set_xalign((GtkLabel*)label, 0);
					gtk_label_set_yalign((GtkLabel*)label, 0.5);
					break;
				case AlignMode::Center :
					Shell::Log(Shell::Debug, "setting alignment mode to 'Center' property from label id_", ID);
					gtk_label_set_xalign((GtkLabel*)label, 0.5);
					gtk_label_set_yalign((GtkLabel*)label, 0.5);
					break;
				case AlignMode::Right :
					Shell::Log(Shell::Debug, "setting alignment mode to 'Right' property from label id_", ID);
					gtk_label_set_xalign((GtkLabel*)label, 1);
					gtk_label_set_yalign((GtkLabel*)label, 0.5);
					break;
				case AlignMode::BottomLeft :
					Shell::Log(Shell::Debug, "setting alignment mode to 'BottomLeft' property from label id_", ID);
					gtk_label_set_xalign((GtkLabel*)label, 0);
					gtk_label_set_yalign((GtkLabel*)label, 1);
					break;
				case AlignMode::BottomCenter :
					Shell::Log(Shell::Debug, "setting alignment mode to 'BottomCenter' property from label id_", ID);
					gtk_label_set_xalign((GtkLabel*)label, 0.5);
					gtk_label_set_yalign((GtkLabel*)label, 1);
					break;
				case AlignMode::BottomRight :
					Shell::Log(Shell::Debug, "setting alignment mode to 'BottomRight' property from label id_", ID);
					gtk_label_set_xalign((GtkLabel*)label, 1);
					gtk_label_set_yalign((GtkLabel*)label, 1);
					break;
				case AlignMode::Custom :
					isCustom = true;
					break;
			}
			assert(isCustom);
		}

		void Label::setAlignment(const float x, const float y)
		// x and y is acceptable between 0 and 1
		// x value for horizontal	| x >>
		// y value for vertical		| y \/
		{
			Shell::Log(Shell::Debug, "setting alignment mode to ", x, "(x value) and ", y, "(y value) ", "property from label id_", ID);
			gtk_label_set_xalign((GtkLabel*)label, x);
			gtk_label_set_yalign((GtkLabel*)label, y);
		}

		AlignMode Label::getAlignment()
		{
			const float x = gtk_label_get_xalign((GtkLabel*)label);
			const float y = gtk_label_get_yalign((GtkLabel*)label);
			Shell::Log(Shell::Debug, "getting alignment mode property from label id_", ID, ": ", x, "(x value) and ", y, "(y value)");
			if(y == 0)
			{
				if(x == 0) return AlignMode::TopLeft;
				else if(x == 0.5) return AlignMode::TopCenter;
				else if(x == 1) return AlignMode::TopRight;
			}
			else if (y == 0.5)
			{
				if(x == 0) return AlignMode::Left;
				else if(x == 0.5) return AlignMode::Center;
				else if(x == 1) return AlignMode::Right;
			}
			else if (y == 1)
			{
				if(x == 0) return AlignMode::BottomLeft;
				else if(x == 0.5) return AlignMode::BottomCenter;
				else if(x == 1) return AlignMode::BottomRight;
			}
			return AlignMode::Custom;
		}

		float Label::getXAlignment()
		{
			Shell::Log(Shell::Debug, "getting alignment mode property from label id_", ID, ": ", gtk_label_get_xalign((GtkLabel*)label), "(x value)");
			return gtk_label_get_xalign((GtkLabel*)label);
		}

		float Label::getYAlignment()
		{
			Shell::Log(Shell::Debug, "getting alignment mode property from label id_", ID, ": ", gtk_label_get_yalign((GtkLabel*)label), "(y value)");
			return gtk_label_get_yalign((GtkLabel*)label);
		}
	}
}
