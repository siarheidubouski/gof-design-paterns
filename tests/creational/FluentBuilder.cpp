#include <gtest/gtest.h>
#include <string>
#include <sstream>
#include "../../src/creational/FluentBuilder.h"

static std::string build_html_tags() {
  std::ostringstream oss;
  oss << "<ul>\n" << "  <li>\n" << "    Hello\n" << "  </li>\n" <<
         "  <li>\n" << "    world!\n" << "  </li>\n" << "</ul>\n";
  return oss.str();
}

TEST (FluentBuilderTest, htmlTags) {

  HtmlBuilder builder{"ul"};
  builder.add_child("li", "Hello").add_child("li", "world!");

  EXPECT_EQ(build_html_tags(), builder.str());
}
