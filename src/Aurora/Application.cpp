#include <iostream>
#include <Aurora/Application.h>
#include <Aurora/Macros.h>

AuroraApplication::AuroraApplication(void (*mainFucntion)(), bool debug)
{
    AuroraMacros::Debug = debug;
    (*mainFucntion)();
}

AuroraApplication::~AuroraApplication()
{
    exit(0);
}