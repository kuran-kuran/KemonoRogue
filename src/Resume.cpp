#include <string.h>
#include "TinyLibrary.hpp"
#include "Global.hpp"
#include "Resume.hpp"

#ifdef RGNANO
static const char* RESUME_FILEPATH = "/mnt/KemonoRogue_Resume.sav";
#else
static const char* RESUME_FILEPATH = "KemonoRogue/Resume.sav";
#endif

bool Resume::Load(Resume::Data* data)
{
	Global& global = Global::GetInstance();
	TinyFile file;
	if(file.Open(RESUME_FILEPATH, TinyFile::READ) == false)
	{
		return false;
	}
	file.Read(data, sizeof(Resume::Data));
	file.Close();
	if(data->floor == 0)
	{
		return false;
	}
	return true;
}

void Resume::Save(Resume::Data* data)
{
	Global& global = Global::GetInstance();
	TinyFile file;
	if(file.Open(RESUME_FILEPATH, TinyFile::WRITE) == false)
	{
		return;
	}
	file.Write(data, sizeof(Resume::Data));
	file.Close();
}

void Resume::DeleteResumeDataFile(void)
{
	Global& global = Global::GetInstance();
	Resume::Data data;
	memset(&data, 0, sizeof(Resume::Data));
	TinyFile file;
	if(file.Open(RESUME_FILEPATH, TinyFile::WRITE) == false)
	{
		return;
	}
	file.Write(&data, sizeof(Resume::Data));
	file.Close();
}
