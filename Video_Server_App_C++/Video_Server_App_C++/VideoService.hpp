#include <string>

class IVideoService
{
public:
	bool TrimVideo(std::string& _infile, std::string& _outfile, unsigned int start, unsigned int end) {}
	bool MergeVideo(std::string& _infile1, std::string& _infile2, std::string& _outfile) {}
};
