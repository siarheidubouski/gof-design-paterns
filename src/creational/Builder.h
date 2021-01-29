#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class HtmlElement
{
 public:
  HtmlElement() {}

  HtmlElement(const std::string& name, const std::string& text)
    : m_name{ name }, m_text{ text } {}

  std::string str(int indentation = 0) const
  {
    std::ostringstream oss;
    std::string i(m_indentation * indentation, ' ');
    oss << i << "<" << m_name << ">" << std::endl;

    if (m_text.size() > 0) 
      oss << std::string(m_indentation * (indentation + 1), ' ')
          << m_text << std::endl;

    for (const auto& e: m_elements)
      oss << e.str(indentation + 1);

    oss << i << "</" << m_name << ">" << std::endl;

    return oss.str();
  }

  void set_name(const std::string& name) { m_name = name; }
  std::vector<HtmlElement>& get_elements() { return m_elements; }
 private:
  std::string m_name;
  std::string m_text;
  std::vector<HtmlElement> m_elements;
  static constexpr std::size_t m_indentation{ 2 };
};

class HtmlBuilder {
 public:
  HtmlBuilder(const std::string& root_name)
  {
    root.set_name(root_name);
  }

  void add_child(const std::string& child_name,
      const std::string& child_text)
  {
    HtmlElement e{child_name, child_text};
    root.get_elements().emplace_back(e);
  }

  std::string str() const { return root.str(); }
 private:
  HtmlElement root;
};
