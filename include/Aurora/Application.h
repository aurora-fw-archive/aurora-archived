#include <Aurora/Typedef.h>

struct AuroraApplication
{
public:
    AuroraApplication(void (*mainFunction)()=[]{}, bool debug = false);
    ~AuroraApplication();
};