#pragma once

namespace Aurora {
    namespace GEngine {
        class Window
        {
        private:
            const char *name;
            int width, height;

        public:
            Window(const char *name, int width, int height);
            ~Window();
        };
    }
}
