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
	GUILabel::GUILabel(GUIWindow *parent, std::string name)
	{
		ID = (unsigned)(long) Aurora::Debug::LastID;
		Aurora::Debug::LastID++;
		Shell::Log(Shell::Debug, "creating new label: id_", ID, " on window id_", parent->ID);
		Label = gtk_label_new (name.c_str());
		WindowParent = parent->Window;
		gtk_container_add(GTK_CONTAINER(WindowParent), Label);
		Shell::Log(Shell::Debug, "label id_", ID, " is created on window id_", parent->ID);
		gtk_widget_show_all(WindowParent);
		Shell::Log(Shell::Debug, "showing label id_", ID, " on window id_", parent->ID);
	}

	//Settings
	void GUILabel::setText(std::string text)
	{
		Shell::Log(Shell::Debug, "setting text on label id_", ID);
		gtk_label_set_text((GtkLabel*)Label, text.c_str());
	}
	std::string GUILabel::getText()
	{
		Shell::Log(Shell::Debug, "getting text from label id_", ID);
		return std::string(gtk_label_get_text ((GtkLabel*)Label));
	}
	void GUILabel::setSelectable(bool value)
	{
		Shell::Log(Shell::Debug, "setting selectable property on label id_", ID);
		gtk_label_set_selectable((GtkLabel*)Label, value);
	}
	bool GUILabel::isSelectable()
	{
		Shell::Log(Shell::Debug, "getting selectable property from label id_", ID);
		return gtk_label_get_selectable((GtkLabel*)Label);
	}
	void GUILabel::setWrap(bool value)
	{
		Shell::Log(Shell::Debug, "setting wrap property on label id_", ID);
		gtk_label_set_line_wrap((GtkLabel*)Label, value);
	}
	bool GUILabel::isWrap()
	{
		Shell::Log(Shell::Debug, "getting wrap property from label id_", ID);
		return gtk_label_get_line_wrap((GtkLabel*)Label);
	}
	void GUILabel::setWrapMode(WrapMode mode)
	{
		Shell::Log(Shell::Debug, "setting wrap mode property on label id_", ID);
		gtk_label_set_line_wrap_mode((GtkLabel*)Label, (PangoWrapMode)mode);
	}
	WrapMode GUILabel::getWrapMode()
	{
		Shell::Log(Shell::Debug, "getting wrap mode property from label id_", ID);
		return (WrapMode)gtk_label_get_line_wrap_mode((GtkLabel*)Label);
	}
	void GUILabel::setAlignment(AlignMode mode)
	{
		bool isCustom = false;
		switch(mode)
		{
			case AlignMode::TopLeft :
				Shell::Log(Shell::Debug, "setting alignment mode to 'TopLeft' property from label id_", ID);
				gtk_label_set_xalign((GtkLabel*)Label, 0);
				gtk_label_set_yalign((GtkLabel*)Label, 0);
				break;
			case AlignMode::TopCenter :
				Shell::Log(Shell::Debug, "setting alignment mode to 'TopCenter' property from label id_", ID);
				gtk_label_set_xalign((GtkLabel*)Label, 0.5);
				gtk_label_set_yalign((GtkLabel*)Label, 0);
				break;
			case AlignMode::TopRight :
				Shell::Log(Shell::Debug, "setting alignment mode to 'TopRight' property from label id_", ID);
				gtk_label_set_xalign((GtkLabel*)Label, 1);
				gtk_label_set_yalign((GtkLabel*)Label, 0);
				break;
			case AlignMode::Left :
				Shell::Log(Shell::Debug, "setting alignment mode to 'Left' property from label id_", ID);
				gtk_label_set_xalign((GtkLabel*)Label, 0);
				gtk_label_set_yalign((GtkLabel*)Label, 0.5);
				break;
			case AlignMode::Center :
				Shell::Log(Shell::Debug, "setting alignment mode to 'Center' property from label id_", ID);
				gtk_label_set_xalign((GtkLabel*)Label, 0.5);
				gtk_label_set_yalign((GtkLabel*)Label, 0.5);
				break;
			case AlignMode::Right :
				Shell::Log(Shell::Debug, "setting alignment mode to 'Right' property from label id_", ID);
				gtk_label_set_xalign((GtkLabel*)Label, 1);
				gtk_label_set_yalign((GtkLabel*)Label, 0.5);
				break;
			case AlignMode::BottomLeft :
				Shell::Log(Shell::Debug, "setting alignment mode to 'BottomLeft' property from label id_", ID);
				gtk_label_set_xalign((GtkLabel*)Label, 0);
				gtk_label_set_yalign((GtkLabel*)Label, 1);
				break;
			case AlignMode::BottomCenter :
				Shell::Log(Shell::Debug, "setting alignment mode to 'BottomCenter' property from label id_", ID);
				gtk_label_set_xalign((GtkLabel*)Label, 0.5);
				gtk_label_set_yalign((GtkLabel*)Label, 1);
				break;
			case AlignMode::BottomRight :
				Shell::Log(Shell::Debug, "setting alignment mode to 'BottomRight' property from label id_", ID);
				gtk_label_set_xalign((GtkLabel*)Label, 1);
				gtk_label_set_yalign((GtkLabel*)Label, 1);
				break;
			case AlignMode::Custom :
				isCustom = true;
				break;
		}
		assert(isCustom);
	}

	void GUILabel::setAlignment(const float x, const float y)
	// x and y is acceptable between 0 and 1
	// x value for horizontal	| x >>
	// y value for vertical		| y \/
	{
		Shell::Log(Shell::Debug, "setting alignment mode to ", x, "(x value) and ", y, "(y value) ", "property from label id_", ID);
		gtk_label_set_xalign((GtkLabel*)Label, x);
		gtk_label_set_yalign((GtkLabel*)Label, y);
	}

	AlignMode GUILabel::getAlignment()
	{
		const float x = gtk_label_get_xalign((GtkLabel*)Label);
		const float y = gtk_label_get_yalign((GtkLabel*)Label);
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

	float GUILabel::getXAlignment()
	{
		Shell::Log(Shell::Debug, "getting alignment mode property from label id_", ID, ": ", gtk_label_get_xalign((GtkLabel*)Label), "(x value)");
		return gtk_label_get_xalign((GtkLabel*)Label);
	}

	float GUILabel::getYAlignment()
	{
		Shell::Log(Shell::Debug, "getting alignment mode property from label id_", ID, ": ", gtk_label_get_yalign((GtkLabel*)Label), "(y value)");
		return gtk_label_get_yalign((GtkLabel*)Label);
	}

}
