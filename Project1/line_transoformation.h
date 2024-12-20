#include <iostream>
#include "Mylist.cpp"

DoubleList<char> line_transformation(DoubleList<char> line) {
	char letter;
	int line_length = line.size();

	if ((line.size() - 1) % 2 == 0) {
		for (int i = 0; i < line.size() / 2; i++) {
			letter = line[i];
			line[i] = line[line.size() - i - 2];
			line[line.size() - i - 2] = letter;
		}
	}

	for (int i = 0; i < line.size() - 1; i++) {
		if (line[i] == '+' or line[i] == '-') {
			if (line[i] == '+') {
				line.insert(i + 1, '+');
				i++;
			}
			else {
				line.insert(i + 1, '-');
				i++;
			}
		}

		if (int(line[i]) > 47 and int(line[i]) < 58) {
			for (int j = i; j < line.size() - 1; j++) {
				line[j] = line[j + 1];
			}
			i--;
			line[line.size()] = '\0';
		}
	}

	return line;
}

OneList<char> line_transformation(OneList<char> line) {
	char letter;
	int line_length = line.size();

	if ((line.size() - 1) % 2 == 0) {
		for (int i = 0; i < line.size() / 2; i++) {
			letter = line[i];
			line[i] = line[line.size() - i - 2];
			line[line.size() - i - 2] = letter;
		}
	}

	for (int i = 0; i < line.size() - 1; i++) {
		if (line[i] == '+' or line[i] == '-') {
			if (line[i] == '+') {
				line.insert(i + 1, '+');
				i++;
			}
			else {
				line.insert(i + 1, '-');
				i++;
			}
		}

		if (int(line[i]) > 47 and int(line[i]) < 58) {
			for (int j = i; j < line.size() - 1; j++) {
				line[j] = line[j + 1];
			}
			i--;
			line[line.size()] = '\0';
		}
	}

	return line;
}