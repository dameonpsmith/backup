// backup.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void display_usage()
{
std::cout
	<< "usage : backup [source directory] [destination directory] [file extention list]" << std::endl
	<< "Examples are :" << std::endl
	<< "backup c:\\users d:\\backup .h,.c,.hpp,.cpp" << std::endl
	<< "backup \"c:\\Program files\" \"d:\\backup files\" .txt,.doc" << std::endl
	<< std::endl
	<< "Where files in the source directory, propergating through all subdirectories, have extensions "
	<< "equal to the extensions given as a comma seperated list as the last argument, "
	<< "are copied to the destination directory, reconstructing the directory tree of the source." << std::endl
	<< "Where a file exist in the destination folder, the file will be overwritten." << std::endl;
}
//argv[1] = topmost source directory
//argv[2] = topmost destination directory
//argv[3] = comma seperated list of file extentions including period
int _tmain(int argc, _TCHAR* argv[])
{
	if (argc != 4)
	{
		display_usage();
		return -1;
	}
	DPS::Backup backup;
	backup.AddSourceDirectory(argv[1]);
	backup.SetDestination(argv[2]);
	backup.AddFilters(argv[3]);
	backup.gather();
	backup.copy();
	return 0;
}

