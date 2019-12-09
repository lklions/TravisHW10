#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "college.h"
#include "course.h"
#include "node.h"

TEST_CASE( "A, B, and C with same weight should 3.0" ) {
	College Kevin("Kevin");
	course a,b,c;
 	a.set_course("cs2401","A",3);
	Kevin.add(a);
 	b.set_course("cs2400","B",3);
	Kevin.add(b);
 	c.set_course("ise3200","C",3);
	Kevin.add(c);

 	REQUIRE(Kevin.gpa() == 3.0);
}


TEST_CASE( "All A's should return 4.0" ) {
	College Carolyn("Carolyn");
	course d,e,f;
 	d.set_course("ee1024","A",6);
	Carolyn.add(d);
	e.set_course("cs3610","A",3);
	Carolyn.add(e);
	f.set_course("ET2200","A",2);
	Carolyn.add(f);

 	REQUIRE(Carolyn.gpa() == 4.0);
}


TEST_CASE( "All D's should return 1.0" ) {
	College Julie("Julie");
	course h,i,j;
 	h.set_course("cs200","D",1);
	Julie.add(h);
	i.set_course("ma3200","D",3);
	Julie.add(i);
	j.set_course("cs2401","D",9);
	Julie.add(j);

 	REQUIRE(Julie.gpa() == 1.0);
}
