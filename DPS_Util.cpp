#include "stdafx.h"
#include "DPS_Util.hpp"
#include <boost\filesystem.hpp>


void DPS::CSV::debugPrintRecord(int i)
{
	for (auto j : _tokens[i])
	{
		std::cout << std::string(j.first, j.second) + "#";
	}
	std::cout << std::endl;
}

bool DPS::CSV::LoadFromFile(std::string filename)
{
	using namespace std;
	ifstream infile;
	string str;
	infile.open(filename);
	infile.seekg(0, ios::end);
	_rawFileContent.reserve((int)infile.tellg());
	infile.seekg(0, ios::beg);
	_rawFileContent.assign((std::istreambuf_iterator<char>(infile)),
		std::istreambuf_iterator<char>());
	int quote_count = 0;
	std::vector<std::pair<std::string::const_iterator, std::string::const_iterator>> line_tokens;
	std::string::const_iterator s;
	std::string::const_iterator e;
	for (auto c = _rawFileContent.cbegin(), s = e = c; c != _rawFileContent.cend(); c++)
	{
		if (*c == _quoted_delimeter)
		{
			quote_count++;
			if (quote_count & 1)
				s = c + 1;
			else
				e = c;
		}
		else if (*c == _delimeter)
		{
			if (quote_count & 1) continue;
			if (e == s) e = c;
			line_tokens.push_back(make_pair(s, e));
			e = s = c + 1;
		}
		else if (*c == _endline)
		{
			if (!(quote_count & 1))
			{
				if (s != e)line_tokens.push_back(make_pair(s, e));
				if (line_tokens.size() != 0)_tokens.push_back(move(line_tokens));
				s = e = c + 1;
			}
			line_tokens.clear();
		}
	}
	return true;
}