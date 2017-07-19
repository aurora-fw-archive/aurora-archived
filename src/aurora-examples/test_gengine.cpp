// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

// File: src/Examples/src/test_gengine.cpp
// Contains: Tests and Examples for Aurora Framework (Graphical Engine Example)

#include <Aurora/Aurora.h>

using namespace Aurora;

Application *MyApp;
GEngine::Application MyGApp("Test GEngine", GEngine::GraphicsAPI::OpenGL);

ArSlot_t slot_Window_on_render(GEngine::Window* window) {
	//Shell::Output << window->getWidth() << "*" << window->getHeight() << Shell::EndLine;
	/* DEBUG ONLY!!!

	glBegin(GL_TRIANGLES);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.5f, 0.5f);
	glVertex2f(0.5f, -0.5f);
	glEnd();*/
	glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
}

ArSlot_t slot_MyApp_on_open()
{
	GEngine::Window* window = new GEngine::Window(MyGApp, "Testing GEngine", GEngine::WindowProperties(800, 600, false, true));
	Shell::Log(Shell::Information, "OpenGL Version: ", GEngine::getGLVersion());


	//DEBUG ONLY!!!
	glClearColor(0.2f, 0.3f, 0.8f, 0.5f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	//...

	while(!window->isClosed())
	{
		window->Clear();
		slot_Window_on_render(window);
		window->Update();
	}
	Application::ExitSuccess();
}

int main(int argc, char * argv[])
{
	MyApp = new Application(slot_MyApp_on_open, argc, argv);
	delete MyApp;
	return 0;
}
