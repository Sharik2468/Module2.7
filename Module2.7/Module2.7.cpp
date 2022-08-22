#include <iostream>
#include <array>
#include <algorithm>
#include <ctime>
#include <vector>

int f()
{
	static int i1 = 100;
	return i1--;
}

auto print1 = [](const auto& v, std::string end = "") {
	std::cout << "{ ";
	for (auto i : v) std::cout << i << ' ';
	std::cout << "} " << end;
};

void print(std::array<int, 10> c)
{
	auto i = c.begin();
	for (i; i != c.end(); i++)
		std::cout << " " << *i;
	std::cout << std::endl;
}

int main()
{
	std::array<int, 10> a, b,d;
	std::array<int, 3> c = { 91,92,93 };
	std::generate(a.begin(), a.end(), f);
	std::generate(b.begin(), b.end(), f);
	print(a);
	print(b);

	std::partial_sort_copy(a.begin(), a.end(), b.begin(), b.end());
	print(a);
	print(b);

	std::array<int, 10>::iterator low, up;
	low = std::lower_bound(b.begin(), b.end(), 91); //          ^
	up = std::upper_bound(b.begin(), b.end(), 95); //                   ^

	std::cout << "lower_bound at position " << (low - b.begin()) << '\n';
	std::cout << "upper_bound at position " << (up - b.begin()) << '\n';

	const std::vector<int> v1{ 1, 2, 5, 5, 5, 9 };
	const std::vector<int> v2{ 2, 5, 7 };
	std::vector<int> diff;

	std::set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(),
		std::inserter(diff, diff.begin()));
	print1(v1, "∖ ");
	print1(v2, "= ");
	print1(diff, "\n");
}