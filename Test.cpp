 
#include <string>
#include "doctest.h"
#include "FamilyTree.hpp"

using namespace std;
using namespace family;


TEST_CASE("Test 1")
{
    Tree T ("Ido");
    T.addFather("Ido","Roni");
	T.addMother("Ido", "Moran");
	T.addFather("Roni", "Tzvi");
    T.addMother("Roni", "Tzipi");
	T.addFather("Moran", "Shalom");
	T.addMother("Moran", "Avigail");
    T.addFather("Tzvi","Kuti");
	T.addMother("Tzvi","Hana");
    T.display();

	//relation function

	CHECK(T.relation("Roni") == string("father"));
	CHECK(T.relation("Moran") == string("mother"));
	CHECK(T.relation("Tzipi") == string("grandmother"));
	CHECK(T.relation("Kuti") == string("great-grandfather"));
	CHECK(T.relation("Hana") == string("great-grandmother"));
	CHECK(T.relation("xyz") == string("unrelated"));
	CHECK(T.relation("Ido") == string("me"));

    CHECK_THROWS_AS(T.addFather("reut","shay"), exception);
    CHECK_THROWS_AS(T.addFather("hadar","ayyala"), exception);
    CHECK_THROWS_AS(T.addFather("tair","shaked"), exception);

	//find function

	CHECK(T.find("father") == string("Roni"));
	CHECK(T.find("mother") == string("Moran"));
	CHECK(T.find("grandmother") == string("Tzipi"));
	CHECK(T.find("great-grandfather") == string("Kuti"));
	CHECK(T.find("great-grandmother") == string("Hana"));
	CHECK(T.find("me") == string("Ido"));

    CHECK_THROWS_AS(T.find("great-grandmother") == string("Moran"), exception);
    CHECK_THROWS_AS(T.find("grandmother") == string("Moran"), exception);
    CHECK_THROWS_AS(T.find("mother") == string("Tzipi"), exception);

	
}

TEST_CASE("Test 2")
{
	family::Tree T("Ayelet");
	T.addMother("Ayelet", "Tamar").addFather("Ayelet", "Liron").addFather("Liron", "Yossi").addMother("Liron", "Sara");

	//relation function

	CHECK(T.relation("Ayelet") == string("me"));
	CHECK(T.relation("Liron") == string("father"));
	CHECK(T.relation("Tamar") == string("mother"));
	CHECK(T.relation("Yossi") == string("grandfather"));
	CHECK(T.relation("Sara") == string("grandmother"));
	CHECK(T.relation("Moshe") == string("unrelated"));

    
	//find function

	CHECK(T.find("father") == string("Liron"));
	CHECK(T.find("mother") == string("Tamar"));
	CHECK(T.find("grandmother") == string("Sara"));
	CHECK(T.find("grandfather") == string("Yossi"));
	CHECK(T.find("me") == string("Ayelet"));

    CHECK_THROWS_AS(T.find("father") == string("Tamar"), exception);
    CHECK_THROWS_AS(T.find("me") == string("Liron"), exception);

	//remove function

	T.remove("Liron");
	CHECK(T.find("Yossi") == string("unrelated"));
	CHECK(T.find("Sara") == string("unrelated"));
	CHECK(T.find("Liron") == string("unrelated"));

	CHECK_THROWS_AS(T.remove("Liron"), exception);

	T.remove("Ayelet");
	CHECK(T.find("mother") == string("unrelated"));
	CHECK(T.find("father") == string("unrelated"));
	CHECK(T.find("me") == string("unrelated"));

	CHECK_THROWS_AS(T.remove("Ayelet"), exception);

    CHECK_THROWS_AS(T.find("mother") == string("Tamar"), exception);
    CHECK_THROWS_AS(T.find("father") == string("Liron"), exception);

	CHECK(T.relation("Tamar") == string("unrelated"));
	CHECK(T.relation("Liron") == string("unrelated"));
	CHECK(T.relation("Ayelet") == string("unrelated"));

	CHECK_THROWS_AS(T.relation("Tamar") == string("mother"), exception);
	CHECK_THROWS_AS(T.relation("Ayelet") == string("me"), exception);
	CHECK_THROWS_AS(T.relation("Liron") == string("father"), exception);


}

TEST_CASE("Test 3")
{
	family::Tree T("Amit");
	T.addFather("Amit", "Gal").addMother("Amit","Galit").addFather("Gal", "Reuven").addMother("Gal","Rachel");
	
	//relation function

	CHECK(T.relation("Rachel") == string("grandmother"));
	CHECK(T.relation("Reuven") == string("grandfather"));
	CHECK(T.relation("Gal") == string("father"));
	CHECK(T.relation("Galit") == string("mother"));
	CHECK(T.relation("Amit") == string("me"));
	
	//find function

	CHECK(T.find("father") == string("Gal"));
	CHECK(T.find("mother") == string("Galit"));
	CHECK(T.find("grandmother") == string("Rachel"));
	CHECK(T.find("grandfather") == string("Reuven"));
	CHECK(T.find("me") == string("Amit"));

    CHECK_THROWS_AS(T.find("grandmother"), exception);
    CHECK_THROWS_AS(T.find("grandfather"), exception);

	//remove function

	T.remove("Gal");
	CHECK(T.find("father") == string("unrelated"));
	CHECK(T.find("mother") == string("Galit"));
	CHECK(T.find("grandmother") == string("unrelated"));
	CHECK(T.find("me") == string("Amit"));
	CHECK(T.find("grandfather") == string("unrelated"));

	
	T.remove("Galit");
	CHECK(T.find("father") == string("unrelated"));
	CHECK(T.find("mother") == string("unrelated"));
	CHECK(T.find("grandmother") == string("unrelated"));
	CHECK(T.find("grandfather") == string("unrelated"));
	CHECK(T.find("me") == string("Amit"));

	CHECK_THROWS_AS(T.remove("Galit"), exception);
    CHECK_THROWS_AS(T.remove("Gal"), exception);

	CHECK_THROWS_AS(T.relation("Galit") == string("mother"), exception);
	CHECK_THROWS_AS(T.relation("Amit") == string("mother"), exception);
	CHECK_THROWS_AS(T.relation("Gal") == string("father"), exception);

	
	}

	TEST_CASE("Test 4")
{
	family::Tree T("Ayyala");
	T.addFather("Ayyala", "Shai").addMother("Ayyala","Hadar").addFather("Shai", "Shaked").addMother("Shai","Reut").addFather("Hadar","Orian").addMother("Hadar","Dganit");
	
	//relation function

	CHECK(T.relation("Reut") == string("grandmother"));
	CHECK(T.relation("Shaked") == string("grandfather"));
	CHECK(T.relation("Dganit") == string("grandmother"));
	CHECK(T.relation("Orian") == string("grandfather"));
	CHECK(T.relation("Shai") == string("father"));
	CHECK(T.relation("Hadar") == string("mother"));
	CHECK(T.relation("Ayyala") == string("me"));
	
	//find function

	CHECK(T.find("father") == string("Shai"));
	CHECK(T.find("mother") == string("Hadar"));
	CHECK(T.find("grandmother") == string("Reut"));
	CHECK(T.find("grandfather") == string("Shaked"));
	CHECK(T.find("grandmother") == string("Orian"));
	CHECK(T.find("grandfather") == string("Dganit"));
	CHECK(T.find("me") == string("Ayyala"));
	

    CHECK_THROWS_AS(T.find("grend-grandmother"), exception);
    CHECK_THROWS_AS(T.find("grend-grandfather"), exception);

	//remove function

	T.remove("Shai");
	CHECK(T.find("father") == string("unrelated"));
	CHECK(T.find("mother") == string("Hadar"));
	CHECK(T.find("grandmother") == string("unrelated"));
	CHECK(T.find("grandmother") == string("Dganit"));
	CHECK(T.find("me") == string("Ayyala"));
	CHECK(T.find("grandfather") == string("unrelated"));
	CHECK(T.find("grandfather") == string("Orian"));
	
	T.remove("Hadar");
	CHECK(T.find("father") == string("unrelated"));
	CHECK(T.find("mother") == string("unrelated"));
	CHECK(T.find("grandmother") == string("unrelated"));
	CHECK(T.find("grandfather") == string("unrelated"));
	CHECK(T.find("me") == string("Ayyala"));

	CHECK_THROWS_AS(T.remove("Hadar"), exception);
    CHECK_THROWS_AS(T.remove("Shai"), exception);
	CHECK_THROWS_AS(T.remove("Reut"), exception);
    CHECK_THROWS_AS(T.remove("Orian"), exception);
	CHECK_THROWS_AS(T.remove("Dganit"), exception);
    CHECK_THROWS_AS(T.remove("Shaked"), exception);

	CHECK_THROWS_AS(T.relation("Hada") == string("mother"), exception);
	CHECK_THROWS_AS(T.relation("Ayyala") == string("me"), exception);
	CHECK_THROWS_AS(T.relation("Shai") == string("father"), exception);

	}