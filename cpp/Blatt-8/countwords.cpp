#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <thread>
#include <map>

// map Schritt
void process_file(
	std::string filename,
	std::map<char, int> & count_char,
	std::map<std::string, int> & count_word)
{
	std::cout << "Processing file " + filename + " ...\n";
	std::ifstream fs(filename.c_str());
	while (!fs.eof())
	{
		std::string word;
		fs >> word;
		std::cout << "-> " + word + "\n";
		// fixme
	}
	std::cout << "Processing file " + filename + " finished!\n";
}

// reduce Schritt
void sum_counts(
	const std::vector<std::map<char, int> > & count_char_list,
	const std::vector<std::map<std::string, int> > & count_word_list,
	std::vector<std::pair<int, char> > & count_char_total,
	std::vector<std::pair<int, std::string> > & count_word_total)
{
	for (const std::map<char, int> & count_char : count_char_list)
		for (const std::pair<char, int> & count_char_pair : count_char)
		{
			// fixme: sum counts
			std::cout << count_char_pair.first << " " << count_char_pair.second << std::endl;
		}
}

int main(int argc, char **argv)
{
	std::vector<std::thread> threads;
	std::vector<std::map<char, int> > count_char_list(argc - 1);
	std::vector<std::map<std::string, int> > count_word_list(argc - 1);

	// map step
	for (int i = 1; i < argc; ++i)  // argv[0] == name of executable
		threads.push_back(std::thread(process_file, argv[i], std::ref(count_char_list[i]), std::ref(count_word_list[i])));
	for (std::thread & t : threads)
		t.join();

	// reduce step
	std::vector<std::pair<int, char> > count_char_total;
	std::vector<std::pair<int, std::string> > count_word_total;
	sum_counts(count_char_list, count_word_list, count_char_total, count_word_total);

	// sort
	std::sort(count_char_total.begin(), count_char_total.end());
	std::sort(count_word_total.begin(), count_word_total.end());

	// display
	// fixme

	return 0;
}
