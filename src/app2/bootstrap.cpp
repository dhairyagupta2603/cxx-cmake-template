#include <ftxui/component/screen_interactive.hpp>

#include "tui.h"

int main() { ftxui::ScreenInteractive::FitComponent().Loop(getTui()); }
