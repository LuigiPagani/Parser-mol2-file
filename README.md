# Molecule Parser

This code is a simple molecule parser that reads data from a file in the .mol2 format and extracts information about atoms and bonds in the molecule. The parsed data is then printed to the console.

## Usage

1. Ensure that you have a file named "test.mol2" in the same directory as the code.
2. Compile and run the code using a C++ compiler.

## Code Explanation

The code begins by including the necessary header files for input/output operations, string manipulation, and vector data structure. It also includes the necessary structures for representing atoms, bonds, and molecules.

The main function initializes variables and opens the "test.mol2" file for reading. If the file is successfully opened, the code proceeds to read the file line by line.

- The code searches for the line containing "@<TRIPOS>MOLECULE" to extract the name of the molecule.
- Next, it searches for the line containing "@<TRIPOS>ATOM" to start parsing the atom data. It continues reading lines until it encounters the line "@<TRIPOS>BOND".
- For each atom line, the code creates a new Atom structure, extracts the atom's name, coordinates (x, y, z), and adds it to the `molecule.atoms` vector.
- After parsing the atom data, the code searches for the line containing "@<TRIPOS>BOND" to start parsing the bond data. It continues reading lines until it encounters the line "@<TRIPOS>SUBSTRUCTURE".
- For each bond line, the code creates a new Bond structure, extracts the bond's index, connected atom indices (n1, n2), and bond type, and adds it to the `molecule.bonds` vector.

Once the file is fully processed, it is closed. If the file opening fails, an error message is displayed.

Finally, the code prints the parsed data to the console. It displays the molecule's name, followed by each atom's name and coordinates (x, y, z). Then, it prints the bond information, including the bond number, connected atom indices, and bond type.

## Limitations

- The code assumes that the "test.mol2" file is formatted correctly and contains valid data in the expected locations. It may produce unexpected results if the file format is incorrect.
- The code has limited error handling. It only checks if the file opening operation fails.
- The code has fixed buffer sizes for reading atom and bond data. If the molecule file contains atom names or bond types exceeding 10 or 2 characters respectively, they may be truncated.
- The code uses the `sscanf` function, which can be error-prone and may not handle all possible input variations correctly. A more robust parsing mechanism could be implemented using string manipulation and tokenization techniques.
- The code does not perform any validation or verification of the parsed data. It assumes the input file is correctly formatted and contains valid data.

## Dependencies

The code uses the following C++ standard libraries:

- `iostream` for input/output operations
- `fstream` for file input/output operations
- `string` for string manipulation
- `vector` for dynamic arrays of elements
