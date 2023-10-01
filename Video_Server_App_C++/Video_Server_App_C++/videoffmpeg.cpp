#include "videoffmpeg.hpp"

void VideoffmpegService::videoffmpegTrim(std::string& _infile, std::string& _outfile, unsigned int start, unsigned int end)
{
	system("D:\ffmpeg\ffmpeg_win64\bin\ffmpeg.exe -ss 00:01:00 -to 00:02:00 -i D:\ffmpeg\ffmpeg_win64\bin\input1.mp4 -c copy D:\ffmpeg\ffmpeg_win64\bin\output1.mp4");
}

void VideoffmpegService::videoffmpegMerge(std::string& _infile1, std::string& _infile2, std::string& _outfile)
{
	system("D:\ffmpeg\ffmpeg_win64\bin\ffmpeg.exe - f concat - safe 0 - i D : \ffmpeg\ffmpeg_win64\bin\videolist.txt - c copy output1.mp4");
}