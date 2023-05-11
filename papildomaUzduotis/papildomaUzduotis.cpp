// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include <iostream>
#include <fstream>
#include <regex>
#include <map>
#include <sstream>
#include <string>
#include <algorithm>
#include <set>

using std::cout;
using std::string;
using std::ifstream;
using std::stringstream;
using std::endl;
using std::map;

void skaitytiIrRasyti(map<string, int>& zodziai);
//void Rasyti();

int main()
{
	map<string, int> zodziai;
	skaitytiIrRasyti(zodziai);

	return 0;
}
void skaitytiIrRasyti(map<string, int>& zodziai) {
	// ieskome link'u
	string filename = "tekstas.txt";
	std::locale::global(std::locale("lt_LT.UTF-8")); // Set the global locale to Lithuanian UTF-8
	ifstream file(filename);
	std::ofstream outfile("output.txt", std::ios_base::out | std::ios_base::binary); // open file in binary mode
	outfile.imbue(std::locale("lt_LT.UTF-8")); // set the encoding of the file to UTF-8
	string text((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	file.close();
	std::regex url_regex(R"((https?://|www\.)\S+(\.lt|\.com)\b)");
	std::smatch matches;
	outfile << "URLs found in the text:" << endl;
	std::set<string> unique_urls; // set to keep track of unique URLs found
	while (regex_search(text, matches, url_regex)) {
		string url = matches[0].str();
		if (unique_urls.count(url) == 0) { // check if URL is unique
			unique_urls.insert(url); // add URL to set of unique URLs
			outfile << url << endl; // output unique URL
		}

		text = matches.prefix().str() + matches.suffix().str();
	}

	// skaiciuojame zodzius
	stringstream ss(text);
	string zodis;
	while (ss >> zodis) {
		if (!regex_match(zodis, url_regex)) {
			zodis.erase(std::remove_if(zodis.begin(), zodis.end(), ispunct), zodis.end());
		}
		if (!zodis.empty()) {
			zodziai[zodis]++;
		}
	}
	outfile << endl;
	outfile << "Word counts:" << endl;
	for (const auto& pair : zodziai) {
		if (pair.second > 1 && !all_of(pair.first.begin(), pair.first.end(), ::isdigit)) {
			outfile << pair.first << ": " << pair.second << endl;
		}
	}
}