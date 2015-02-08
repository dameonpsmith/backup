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
}