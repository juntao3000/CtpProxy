#include "Util.h"

namespace Native
{
	// 非托管类,自动释放字符串指针内存
	CAutoStrPtr::CAutoStrPtr(String^ str)
	{
		if (str != nullptr)
			m_pChar = (char*)Marshal::StringToHGlobalAnsi(str).ToPointer();
		else
			m_pChar = nullptr;
	}

	// 非托管类,自动释放字符串指针内存
	CAutoStrPtr::~CAutoStrPtr()
	{
		if (m_pChar != nullptr) Marshal::FreeHGlobal(IntPtr(m_pChar));
	}

	// 全局函数
	// 把CTP的错误响应信息 CThostFtdcRspInfoField 转换为托管的 CtpNetRspInfoFieldEx
	CtpNetRspInfoField^ RspInfoField(CThostFtdcRspInfoField *pRspInfo)
	{
		if (pRspInfo == nullptr) return nullptr;

		auto field = gcnew CtpNetRspInfoField;

		field->ErrorID = pRspInfo->ErrorID;

		if (field->ErrorMsg == nullptr)
		{
			field->ErrorMsg = String::Empty;
		}
		else
		{
			field->ErrorMsg = gcnew String(pRspInfo->ErrorMsg);
		}

		return field;
	}
}