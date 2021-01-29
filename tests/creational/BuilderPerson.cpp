#include <gtest/gtest.h>
#include <string>
#include <sstream>
#include "../../src/creational/Person/Person.h"
#include "../../src/creational/Person/PersonBuilder.h"
#include "../../src/creational/Person/PersonAddressBuilder.h"
#include "../../src/creational/Person/PersonJobBuilder.h"

static std::string build_person() {
  std::ostringstream oss;
  oss << "street_address: " << "400 9th Ave N" << " post_code: " << "98109"
      << " city: " << "Seattle"
      << " company_name: " << "Amazon" << " position: " << "Software Engineer"
      << " annual_income: " << "1000000";
  return oss.str();
}

TEST (BuilderPerson, Person) {

  Person p = Person::create()
    .lives().at("400 9th Ave N")
            .with_postcode("98109")
            .in("Seattle")
    .works().at("Amazon")
            .as_a("Software Engineer")
            .earning(10e5);

  EXPECT_EQ(build_person(), p.getPersonDetails());
}
