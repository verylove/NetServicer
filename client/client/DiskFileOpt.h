#pragma once

#include <iostream>
#include <string>
#include <list>

struct stFile //�����ļ�����
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

//��ɶ�Ӳ���ļ��Ĳ���
class CDiskFileOpt
{
public:
	CDiskFileOpt(void);
	~CDiskFileOpt(void);
	
	//�˺�������ȡ��ǰĿ¼�µ�һ��Ŀ¼
	int GetFileList(ListFile& list,const std::string& strPath) const;
private:

 };

