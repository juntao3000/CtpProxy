#pragma once

#include "ThostFtdcUserApiStruct.h"
//#include "Struct.h"

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace TaiTanXing::Ctp::CtpNet;

namespace Native
{
	// 非托管类,自动释放字符串指针内存
	class CAutoStrPtr
	{
	public:
		// 字符串指针
		char* m_pChar;
		// 非托管类,自动释放字符串指针内存
		CAutoStrPtr(String^ str);
		// 非托管类,自动释放字符串指针内存
		~CAutoStrPtr();
	};

	// 全局函数
	// 把CTP的错误响应信息 CThostFtdcRspInfoField 转换为托管的 CtpNetRspInfoField
	CtpNetRspInfoField^ RspInfoField(CThostFtdcRspInfoField *pRspInfo);
};