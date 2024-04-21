//
// Created by riges on 4/19/2024.
//
#include <gtest/gtest.h>
#include "Masina.h"

// Test pentru constructorul explicit
TEST(MasinaTest, ConstructorExplicitTest) {
Masina masina("AUDI", "A3", 12384.14, 2014);
EXPECT_EQ(masina.GetMarca(), "AUDI");
EXPECT_EQ(masina.GetModel(), "A3");
EXPECT_EQ(masina.GetPret(), 12384.14);
}

TEST(MasinaTest, ConstructorCuParametriReferintaTest) {
string marca = "AUDI";
string model = "A3";
double pret = 12384.14;
int an = 2024;
Masina masina(marca, model, pret, an);
EXPECT_EQ(masina.GetMarca(), marca);
EXPECT_EQ(masina.GetModel(), model);
EXPECT_EQ(masina.GetPret(), pret);
EXPECT_EQ(masina.GetAn(), an);
}

// Test pentru operatorul de atribuire
TEST(MasinaTest, OperatorAtribuireTest) {
Masina masina1("AUDI", "A3", 12384.14, 2014);
Masina masina2;
masina2 = masina1;
EXPECT_EQ(masina2, masina1); // Verificăm dacă obiectul a fost atribuit corect
}

// Test pentru constructorul de copiere
TEST(MasinaTest, ConstructorDeCopiereTest) {
Masina masina1("AUDI", "A3", 12384.14, 2014);
Masina masina2(masina1);
EXPECT_EQ(masina2, masina1); // Verificăm dacă obiectul a fost copiat corect
}

// Test pentru operatorul de egalitate
TEST(MasinaTest, OperatorEgalitateTest) {
Masina masina1("AUDI", "A3", 12384.14, 2014);
Masina masina2("AUDI", "A3", 12384.14, 2014);
EXPECT_EQ(masina1, masina2); // Verificăm dacă cele două obiecte sunt egale
}

// Test pentru metoda GetMarca
TEST(MasinaTest, GetMarcaTest) {
Masina masina("AUDI", "A3", 12384.14, 2014);
EXPECT_EQ(masina.GetMarca(), "AUDI");
}

// Test pentru metoda GetModel
TEST(MasinaTest, GetModelTest) {
Masina masina("AUDI", "A3", 12384.14, 2014);
EXPECT_EQ(masina.GetModel(), "A3");
}

// Test pentru metoda GetPret
TEST(MasinaTest, GetPretTest) {
Masina masina("AUDI", "A3", 12384.14, 2014);
EXPECT_EQ(masina.GetPret(), 12384.14);
}

// Test pentru metoda ObtinePretPePiata
TEST(MasinaTest, ObtinePretPePiataTest) {
Masina masina("AUDI", "A3", 12384.14, 2014);
EXPECT_EQ(masina.ObtinePretPePiata(), 12384.14); // Presupunând că această metodă returnează același preț
}

// Test pentru metoda CreeazaMasinaElectrica
TEST(MasinaTest, CreeazaMasinaElectricaTest) {
Masina masina("AUDI", "A3", 12384.14, 2014);
EXPECT_EQ(masina.CreeazaMasinaElectrica(), 0); // Presupunând că această metodă returnează 0
}

// Test pentru operatorul de citire supraincarcat
TEST(MasinaTest, OperatorCitireSupraincarcatTest) {
// Simulăm citirea unui obiect Masina dintr-un stream
std::istringstream input("AUDI A3 12384.14 2014");
Masina masina;
input >> masina;
EXPECT_EQ(masina.GetMarca(), "AUDI");
EXPECT_EQ(masina.GetModel(), "A3");
EXPECT_EQ(masina.GetPret(), 12384.14);
}

// Test pentru operatorul de afisare supraincarcat
TEST(MasinaTest, OperatorAfisareSupraincarcatTest) {
Masina masina("AUDI", "A3", 12384.14, 2014);
std::ostringstream output;
output << masina;
EXPECT_EQ(output.str(), "AUDI A3 12384.14 2014");
}
