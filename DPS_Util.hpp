#include "stdafx.h"

namespace DPS
{
	class Backup
	{
	private:
		std::vector<std::wstring> _filters;
		std::vector<std::wstring> _sources;
		std::wstring _destination_root;
		std::vector<std::wstring> _selection;
		std::vector<std::wstring> _report;
	public:
		void AddSourceDirectory(std::wstring directory);
		void SetDestination(std::wstring destination_root);
		void AddFilters(std::wstring filters);
		void gather(void);
		void copy(void);
	};
	class CSV
	{
	private:
		char _delimeter = ',';
		char _quoted_delimeter = '"';
		char _endline = '\n';
		std::vector<std::vector<std::pair<std::string::const_iterator, std::string::const_iterator>>> _tokens;
		std::string _rawFileContent;
		void debugPrintRecord(int i);
	public:
		bool LoadFromFile(std::string filename);
	};
}
