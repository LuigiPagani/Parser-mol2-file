#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Atom {
    char name[10];
    float x, y, z;
};

struct Bond {
    int i;
    int n1;
    int n2;
    char t[2];
};

struct Molecule {
    std::string name;
    std::vector<Atom> atoms;
    std::vector<Bond> bonds;
};

int main() {
    std::string line;
    Molecule molecule;
    std::ifstream mol2file("test.mol2");

    if (mol2file.is_open()) {
        while (getline(mol2file, line)) {
            if (line.find("@<TRIPOS>MOLECULE") != std::string::npos ) {
                getline(mol2file, line);
                molecule.name = line;
            }
            if (line.find("@<TRIPOS>ATOM") != std::string::npos ) {
                while (getline(mol2file, line) && line.find("@<TRIPOS>BOND") == std::string::npos)  {
                    if (line.empty()) break;
                    Atom atom;
                    sscanf(line.c_str(), "%*s %s %f %f %f", atom.name, &atom.x, &atom.y, &atom.z);
                    molecule.atoms.push_back(atom);
                }
            }
            if (line.find("@<TRIPOS>BOND") != std::string::npos ) {
                while (getline(mol2file, line)&& line.find("@<TRIPOS>SUBSTRUCTURE") == std::string::npos) {
                    if (line.empty()) break;
                    Bond bond;
                    sscanf(line.c_str(), "%d %d %d %s", &bond.i, &bond.n1, &bond.n2,bond.t);
                    molecule.bonds.push_back(bond);
                }
            }
        }
        mol2file.close();
    }
    else {
        std::cout << "Unable to open file";
    }

    // print the data stored in the molecule
    std::cout << "Molecule name: " << molecule.name << '\n';
    for (const auto& atom : molecule.atoms) {
        printf("Atom name: %s, x: %.3f, y: %.3f, z: %.3f\n", atom.name, atom.x, atom.y, atom.z);
    }
    std::cout<<"\nBonds:\n";
    for (const auto& bond : molecule.bonds) {
        printf("Bond number: %d, na1: %d, na2: %d, type: %s\n", bond.i, bond.n1, bond.n2, bond.t);
    }


    return 0;
}


