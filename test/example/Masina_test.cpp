#include <gtest/gtest.h>
#include "Masina.h"

TEST(MasinaTest, ConstructorExplicitTest) {
    Masina masina("AUDI", "A3", 12384.14, 2014);
    EXPECT_EQ(masina.GetMarca(), "AUDI");
    EXPECT_EQ(masina.GetModel(), "A3");
    EXPECT_EQ(masina.GetPret(), 12384.14);
    EXPECT_EQ(masina.GetAn(), 2014);
}

TEST(MasinaTest, ConstructorCuParametriReferintaTest) {
    string marca = "AUDI";
    string model = "A3";
    double pret = 12384.14;
    Masina masina(marca, model, pret);
    EXPECT_EQ(masina.GetMarca(), marca);
    EXPECT_EQ(masina.GetModel(), model);
    EXPECT_EQ(masina.GetPret(), pret);
}

TEST(MasinaTest, OperatorAtribuireTest) {
    Masina masina1("AUDI", "A3", 12384.14, 2014);
    Masina masina2;
    masina2 = masina1;
    EXPECT_EQ(masina2, masina1); // Verificăm dacă obiectul a fost atribuit corect
}

TEST(MasinaTest, ConstructorDeCopiereTest) {
    Masina masina1("AUDI", "A3", 12384.14, 2014);
    Masina masina2(masina1);
    EXPECT_EQ(masina2, masina1); // Verificăm dacă obiectul a fost copiat corect
}

TEST(MasinaTest, OperatorEgalitateTest) {
    Masina masina1("AUDI", "A3", 12384.14, 2014);
    Masina masina2("AUDI", "A3", 12384.14, 2014);
    EXPECT_EQ(masina1, masina2); // Verificăm dacă cele două obiecte sunt egale
}

TEST(MasinaTest, GetMarcaTest) {
    Masina masina("AUDI", "A3", 12384.14, 2014);
    EXPECT_EQ(masina.GetMarca(), "AUDI");
}

TEST(MasinaTest, GetModelTest) {
    Masina masina("AUDI", "A3", 12384.14, 2014);
    EXPECT_EQ(masina.GetModel(), "A3");
}

TEST(MasinaTest, GetPretTest) {
    Masina masina("AUDI", "A3", 12384.14, 2014);
    EXPECT_EQ(masina.GetPret(), 12384.14);
}

TEST(MasinaTest, GetAnTest) {
    Masina masina("AUDI", "A3", 12384.14, 2014);
    EXPECT_EQ(masina.GetAn(), 2014);
}

TEST(MasinaTest, ObtinePretPePiataTest) {
    Masina masina("AUDI", "A3", 12384.14, 2014);
    EXPECT_EQ(masina.ObtinePretPePiata(), 12384.14); 
}

TEST(MasinaTest, CreeazaMasinaElectricaTest) {
    Masina masina("AUDI", "A3", 12384.14, 2014);
    EXPECT_EQ(masina.CreeazaMasinaElectrica(), 0); 
}

TEST(MasinaTest, OperatorCitireSupraincarcatTest) {
    std::istringstream input("AUDI A3 12384.14 2014");
    Masina masina;
    input >> masina;
    EXPECT_EQ(masina.GetMarca(), "AUDI");
    EXPECT_EQ(masina.GetModel(), "A3");
    EXPECT_EQ(masina.GetPret(), 12384.14);
    EXPECT_EQ(masina.GetAn(), 2014);
}

TEST(MasinaTest, OperatorAfisareSupraincarcatTest) {
    Masina masina("AUDI", "A3", 12384.14, 2014);
    std::ostringstream output;
    output << masina;
    EXPECT_EQ(output.str(), "AUDI A3 12384.14 2014"); 
}

