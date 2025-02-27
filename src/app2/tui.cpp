#include "tui.h"

#include <ftxui/dom/elements.hpp>

#include "app1/basic.hpp"
#include "buildinfo.h"

using namespace ftxui;
using namespace std;

string a{"12"}, b{"90"};
auto input_a = Input(&a, "");
auto input_b = Input(&b, "");
auto component = Container::Vertical({input_a, input_b});

Component getTui() {
  return Renderer(component, [&] {
    auto sum = app1::Add(stoi(a), stoi(b));
    return vbox({
               text("CalcConsole " + BuildInfo::Version),
               text("Built: " + BuildInfo::Timestamp),
               text("SHA: " + BuildInfo::CommitSHA),
               separator(),
               input_a->Render(),
               input_b->Render(),
               separator(),
               text("Sum: " + to_string(sum)),
           }) |
           border;
  });
}
