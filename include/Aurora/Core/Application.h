// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#ifndef INCLUDE_H_AURORA_CORE_APPLICATION
#define INCLUDE_H_AURORA_CORE_APPLICATION

#pragma once

#include <Aurora/Core/Aurora.h>
#include <stddef.h>

namespace Aurora
{
    struct Application
    {
    public:
        Application(void (*mainFunction)(), int argc = 0, char *argv[] = NULL);
        ~Application();
        static void ExitSuccess();
        static void ExitFail();
    private:
        unsigned long ID = 0;
    };
}

#endif // INCLUDE_H_AURORA_CORE_APPLICATION