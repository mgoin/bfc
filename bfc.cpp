#include <cstdio>
#include <fstream>

int main(int argc, char** argv) {
    char c;
	std::ifstream infile;
	std::ofstream outfile;

	if (argc != 3)
		printf("Invalid arguments - Expected: bfc bf-file output-file\n");

	infile.open(argv[1]);
	outfile.open(argv[2]);

    outfile << "int main() {\nchar mem[65536] = {0};\nint p = 0;\n";
    while (infile.get(c)) {
		switch(c) {
            case '+':
                outfile << "mem[p]++;\n"; break;
            case '-':
                outfile << "mem[p]--;\n"; break;
            case '>':
                outfile << "p++;\n"; break;
            case '<':
                outfile << "p--;\n"; break;
            case '.':
                outfile << "putchar(mem[p]);\n"; break;
            case ',':
                outfile << "mem[p] = getchar();\n"; break;
            case '[':
                outfile << "while (mem[p]) {\n"; break;
            case ']':
                outfile << "}\n"; break;
        }
    }
    outfile << "return 0;\n}";

    infile.close();
    outfile.close();
	return 0;
}
