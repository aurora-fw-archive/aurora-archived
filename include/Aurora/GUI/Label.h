// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#include <Aurora/TLib/Target/PragmaOnce.h>
#if defined(AURORA_TARGET_PRAGMA_ONCE_SUPPORT) && AURORA_TARGET_PRAGMA_ONCE_SUPPORT
    #pragma once
#endif

#ifndef AURORA_FW
#define AURORA_FW 1
#endif // AURORA_FW

#ifndef INCLUDE_H_AURORA_GUI_LABEL
#define INCLUDE_H_AURORA_GUI_LABEL

#include <Aurora/GUI/Window.h>
#include <Aurora/GUI/Layout.h>
#include <Aurora/TLib/Target.h>

#ifdef AURORA_TARGET_CXX
	#include <cassert>
#elif defined(AURORA_TARGET_CC)
	#include <assert.h>
#endif

/* TODO:
** Setters
**	void setSingleLineMode(bool);
**	void setJustify(JustifyMode);
**	void setLength(int);
**	void setMaxLength(int);
**	void setSelection(int, int);
**	void setAngle(double);
**
** Getters
**	bool isSingleLineMode();
**	JustifyMode getJustify();
**	int getLength();
**	int getMaxLength();
**	int getLines();
**	double getAngle();
**
** Signals
** 	> Use g_signal_connect()
**
**	onCursorMove(void);
**	onCopyToClipboard(void);
**	onLinkClick(void);
*/

typedef struct _GtkWidget GtkWidget;

namespace Aurora
{
	class GUILabel
	{
	public:
		GUILabel(GUIWindow *parent, std::string name = "New Label");

		//Setters
		void setText(std::string);
		void setSelectable(bool);
		void setWrap(bool);
		void setWrapMode(WrapMode);
		void setAlignment(AlignMode);
		void setAlignment(const float, const float);

		//Getters
		std::string getText();
		bool isSelectable();
		bool isWrap();
		WrapMode getWrapMode();
		AlignMode getAlignment();
		float getXAlignment();
		float getYAlignment();

		//Signals


	protected:
		unsigned long ID = 0;
		GtkWidget *Label;
	private:
		GtkWidget *WindowParent;
	};
}

#endif // INCLUDE_H_AURORA_GUI_LABEL
