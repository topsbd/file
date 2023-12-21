#pragma once
#include <string>

struct Student {
	std::string name;
	int age;
	std::string group;

	std::string to_string() {
		std::string str = name;
		str.append(";");
		str.append(std::to_string(age));
		str.append(";");
		str.append(group);

		return str;
	}
};