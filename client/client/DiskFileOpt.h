#pragma once

#include <iostream>
#include <string>
#include <list>

struct stFile //定义文件类型
{
	long lnSize;
	int nFileType;
	std::string strFile;
	stFile()
	{
		lnSize = 0;
		nFileType = 0x00;
		strFile = "";
	}
};
typedef  std::list<stFile> ListFile;

//完成对硬盘文件的操作
class CDiskFileOpt
{
public:
	CDiskFileOpt(void);
	~CDiskFileOpt(void);
	
	//此函数至获取当前目录下的一级目录
	int GetFileList(ListFile& list,const std::string& strPath) const;
private:

 };

