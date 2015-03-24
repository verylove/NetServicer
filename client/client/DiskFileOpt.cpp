#include "StdAfx.h"
#include "DiskFileOpt.h"
#include <io.h>


CDiskFileOpt::CDiskFileOpt(void)
{
}


CDiskFileOpt::~CDiskFileOpt(void)
{
}

//此函数至获取当前目录下的一级目录 (已测)
int CDiskFileOpt::GetFileList(ListFile& list,const std::string& strPath) const
{
	int nCount = 0;
	if (!strPath.empty())
	{
		std::string strVal = strPath;
		strVal += "*.*";
		_finddata_t file;
		long lf = 0;
		if ((lf = _findfirst(strVal.c_str(),&file)) != -1)
		{
			while( _findnext( lf, &file ) == 0 )
			{
				stFile st;
				st.lnSize = file.size;
				st.nFileType = file.attrib;
				st.strFile = file.name;
				list.push_back(st);
			}
			nCount = list.size();
			_findclose(lf);
		}
	}
	return nCount;
}