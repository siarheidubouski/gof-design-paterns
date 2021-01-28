#include <gtest/gtest.h>
#include <string>
#include <sstream>
#include "../../src/creational/GroovyBuilder.h"

static std::string build_html_tags() {
  std::ostringstream oss;
  oss << "<p>\n" << "<img src=\"http:://amazon.com/pikachu.png\"/>\n" << "</p>\n";
  return oss.str();
}

TEST (GroovyBuilderTest, htmlTags) {
  using namespace html;
  std::string html_tags{ P{ IMG{"http:://amazon.com/pikachu.png"} }.get_html() };

  EXPECT_EQ(build_html_tags(), html_tags);
}
