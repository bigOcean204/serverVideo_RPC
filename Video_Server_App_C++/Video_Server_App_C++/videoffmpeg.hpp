#include <string>

class VideoffmpegService
{
public:
	void videoffmpegTrim(std::string& _infile, std::string& _outfile, unsigned int start, unsigned int end);

	void videoffmpegMerge(std::string& _infile1, std::string& _infile2, std::string& _outfile);
};