#include <string>
#include "doctest.h"
#include "FamilyTree.hpp"

using namespace std;
using namespace family;

TEST_CASE("Test 1")
{
    family::Tree T ("Ido");
    T.addFather("Ido","Roni").addMother("Ido", "Moran").addFather("Roni", "Tzvi")
    .addMother("Roni", "Tzipi").addFather("Moran", "Shalom").addMother("Moran", "Avigail")
    .addFather("Tzvi","Kuti").addMother("Tzvi","Hana");
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

    CHECK_THROWS_AS(T.find("great-grandmother"), exception);
    CHECK_THROWS_AS(T.find("grandmother"), exception);
    CHECK_THROWS_AS(T.find("mother"), exception);
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

    CHECK_THROWS_AS(T.find("father"), exception);
    CHECK_THROWS_AS(T.find("me"), exception);

	//remove function

	T.remove("Liron");
	CHECK(T.find("Yossi") == string("unrelated"));
	CHECK(T.find("Sara") == string("unrelated"));
	CHECK(T.find("Liron") == string("unrelated"));
	
	T.remove("Ayelet");
	CHECK(T.find("mother") == string("unrelated"));
	CHECK(T.find("father") == string("unrelated"));
	CHECK(T.find("me") == string("unrelated"));

    CHECK_THROWS_AS(T.find("mother"), exception);
    CHECK_THROWS_AS(T.find("father"), exception);

	CHECK(T.relation("Tamar") == string("unrelated"));
	CHECK(T.relation("Liron") == string("unrelated"));
	CHECK(T.relation("Ayelet") == string("unrelated"));

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

    // CHECK_THROWS_AS(T.find("grandmother"), exception);
    // CHECK_THROWS_AS(T.find("grandfather"), exception);

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
}