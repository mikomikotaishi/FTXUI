// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#ifndef FTXUI_BUILD_MODULES
#include <ftxui/dom/elements.hpp>  // for text, center, separator, operator|, flex, Element, vbox, Fit, hbox, border
#include <ftxui/screen/screen.hpp>  // for Full, Screen
#endif

#include <memory>                   // for allocator

#ifndef FTXUI_BUILD_MODULES
#include "ftxui/dom/node.hpp"      // for Render
#include "ftxui/screen/color.hpp"  // for ftxui
#else
import ftxui.dom;
import ftxui.screen;
#endif

int main() {
  using namespace ftxui;
  auto document = hbox({
                      text("left-column"),
                      separator(),
                      vbox({
                          center(text("top")) | flex,
                          separator(),
                          center(text("bottom")),
                      }) | flex,
                      separator(),
                      text("right-column"),
                  }) |
                  border;
  auto screen = Screen::Create(Dimension::Full(), Dimension::Fit(document));
  Render(screen, document);
  screen.Print();

  return 0;
}
