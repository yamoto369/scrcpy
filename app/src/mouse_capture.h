#ifndef SC_MOUSE_CAPTURE_H
#define SC_MOUSE_CAPTURE_H

#include "common.h"

#include <stdbool.h>

#include <SDL2/SDL.h>

struct sc_mouse_capture {
    SDL_Window *window;
    uint16_t sdl_mouse_capture_keys;

    // To enable/disable mouse capture, a mouse capture key (LALT, LGUI or
    // RGUI) must be pressed. This variable tracks the pressed capture key.
    SDL_Keycode mouse_capture_key_pressed;

    // Virtual cursor position accumulated from relative mouse motion deltas.
    // Used to detect when the cursor reaches the window edge and release
    // the mouse capture automatically.
    int32_t virtual_x;
    int32_t virtual_y;
};

void
sc_mouse_capture_init(struct sc_mouse_capture *mc, SDL_Window *window,
                      uint8_t shortcut_mods);

void
sc_mouse_capture_set_active(struct sc_mouse_capture *mc, bool capture);

bool
sc_mouse_capture_is_active(struct sc_mouse_capture *mc);

void
sc_mouse_capture_toggle(struct sc_mouse_capture *mc);

// Return true if it consumed the event
bool
sc_mouse_capture_handle_event(struct sc_mouse_capture *mc,
                              const SDL_Event *event);

#endif
