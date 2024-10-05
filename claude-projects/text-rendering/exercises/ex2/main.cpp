#include <SDL.h>
#include <SDL_events.h>
#include <SDL_render.h>
#include <SDL_timer.h>
#include <SDL_video.h>
#include <stdexcept>
#include <string>

using namespace std;

class WindowRendererException : public runtime_error {
public:
  WindowRendererException(const string &message) : runtime_error(message) {};
};

class WindowRenderer {
public:
  WindowRenderer(int width, int height) {
    int init_flags = SDL_INIT_VIDEO;
    if (auto error = SDL_Init(init_flags) != 0) {
      throw WindowRendererException("failed to init SDL2 library");
    }

    int win_ren_flags = 0;
    if (auto error = SDL_CreateWindowAndRenderer(width, height, win_ren_flags,
                                                 &window, &renderer) != 0) {
      throw WindowRendererException("failed to create window and renderer");
    }
  }

  void run() {
    bool run = true;
    while (run) {
      SDL_Event e;
      while (SDL_PollEvent(&e)) {
        switch (e.type) {
        case SDL_QUIT:
          run = false;
          break;
        }
      }
    }
  };

  ~WindowRenderer() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
  };

private:
  SDL_Window *window;
  SDL_Renderer *renderer;
};

/*
Implement a basic text wrapping function that breaks a long string
into lines based on a given width.
*/
int main() {
  WindowRenderer wr(1000, 800);
  wr.run();
}