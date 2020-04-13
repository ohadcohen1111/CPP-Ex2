 #include "FamilyTree.cpp"
 
 int main()
 {
//  family::Tree T ("Ido");
//     T.addFather("Ido","Roni").
//     addMother("Ido", "Moran").
//     addMother("Roni", "Tzipi");
//     T.addFather("Roni", "Tzvi");
//     T.addFather("Moran", "Shalom");
//     T.addMother("Moran", "Avigail");
//     T.addFather("Tzvi","Kuti");
//     T.addMother("Tzvi","Hana");
//     T.display();
//     cout << T.relation("Avigail") << endl;

    family::Tree T ("Ido");
    T.addFather("Ido","Roni").addMother("Ido", "Moran").addFather("Roni", "Tzvi")
    .addMother("Roni", "Tzipi").addFather("Moran", "Shalom").addMother("Moran", "Avigail")
    .addFather("Tzvi","Kuti").addMother("Tzvi","Hana");
    T.display();
 }
