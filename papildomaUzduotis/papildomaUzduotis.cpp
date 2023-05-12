#include <iostream>
#include <fstream>
#include <regex>
#include <map>
#include <sstream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>

using std::cout;
using std::string;
using std::ifstream;
using std::stringstream;
using std::endl;
using std::map;
using std::vector;

void skaitytiIrRasyti(map<string, int>& zodziai, map<string, vector<int>>& zodziuLines);

int main()
{
	map<string, int> zodziai;
	map<string, vector<int>> zodziuLines;
	skaitytiIrRasyti(zodziai, zodziuLines);

	return 0;
}
void skaitytiIrRasyti(map<string, int>& zodziai, map<string, vector<int>>& zodziuLines) {
	// ieskome link'u
	string filename = "tekstas.txt";
	std::locale::global(std::locale("lt_LT.UTF-8"));
	ifstream file(filename);
	std::ofstream outfile("output.txt", std::ios_base::out | std::ios_base::binary); // open file in binary mode
	string text((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	file.close();
	std::regex url_regex("(?:(http|https)://)?([a-zA-Z0-9\\-.]+\\.(com|org|net|edu|gov|mil|biz|info|io|lt|me|tv))(\\S*)?");
	std::smatch matches;
	outfile << "URLs found in the text:" << endl;
	std::set<string> unique_urls;
	while (regex_search(text, matches, url_regex)) {
		string url = matches[0].str();
		if (unique_urls.count(url) == 0) {
			unique_urls.insert(url);
			outfile << url << endl;
		}

		text = matches.prefix().str() + matches.suffix().str();
	}

	// skaiciuojame zodzius
	stringstream ss(text);
	string zodis;
	int lineNum = 1;
	while (ss >> zodis) {
		if (!regex_match(zodis, url_regex)) {
			zodis.erase(std::remove_if(zodis.begin(), zodis.end(), ispunct), zodis.end());
		}
		if (!zodis.empty()) {
			zodziai[zodis]++;
			zodziuLines[zodis].push_back(lineNum);
		}
		lineNum++;
	}
	outfile << endl;
	outfile << "Word counts:" << endl;
	for (const auto& pair : zodziai) {
		outfile.imbue(std::locale("lt_LT.UTF-8"));
		if (pair.second > 1 && !all_of(pair.first.begin(), pair.first.end(), ::isdigit)) {
			outfile << pair.first << ": " << pair.second << endl;
			outfile << " Lines: ";
			outfile.imbue(std::locale("en_US.UTF-8"));
			for (const auto& lineNum : zodziuLines[pair.first]) {
				outfile << lineNum << " ";
			}
			outfile << endl;
		}
	}
}