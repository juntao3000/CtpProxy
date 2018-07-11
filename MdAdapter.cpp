#include <string.h>
#include "MdSpi.h"
#include "MdAdapter.h"

namespace TaiTanXing
{
	namespace Ctp
	{
		namespace CtpProxy
		{
			/// <summary>
			/// 行情对象
			/// </summary>
			MdAdapter::MdAdapter()
					: MdAdapter("", false, false)
				{}
			//{
			//	m_pApi = CThostFtdcMdApi::CreateFtdcMdApi("", false, false);
			//	m_pSpi = new CMdSpi((MdAdapter^)this);
			//	m_pApi->RegisterSpi(m_pSpi);
			//}

			/// <summary>
			/// 行情对象
			/// </summary>
			MdAdapter::MdAdapter(String^ pszFlowPath, bool bIsUsingUdp)
					: MdAdapter(pszFlowPath, bIsUsingUdp, false)
				{}
			//{
			//	CAutoStrPtr asp(pszFlowPath);
			//	m_pApi = CThostFtdcMdApi::CreateFtdcMdApi(asp.m_pChar, bIsUsingUdp, false);
			//	m_pSpi = new CMdSpi((MdAdapter^)this);
			//	m_pApi->RegisterSpi(m_pSpi);
			//}

			/// <summary>
			/// 行情对象
			/// </summary>
			MdAdapter::MdAdapter(String^ pszFlowPath, bool bIsUsingUdp, bool bIsMulticast)
			{
				CAutoStrPtr asp(pszFlowPath);
				m_pApi = CThostFtdcMdApi::CreateFtdcMdApi(asp.m_pChar, bIsUsingUdp, bIsMulticast);
				m_pSpi = new CMdSpi((MdAdapter^)this);
				m_pApi->RegisterSpi(m_pSpi);

				//动态解析程序集
				System::AppDomain::CurrentDomain->AssemblyResolve += gcnew System::ResolveEventHandler(this, &MdAdapter::OnAssemblyResolve);
			}

			/// <summary>
			/// 动态解析程序集
			/// </summary>
			System::Reflection::Assembly^ MdAdapter::OnAssemblyResolve(System::Object ^sender, System::ResolveEventArgs ^args)
			{
				for each (auto assm in m_ppAssembly)
				{
					if (assm->FullName->Contains(args->Name))
					{
						return assm;
					}
				}

				return nullptr;
			}

			/// <summary>
			/// 设置可以动态解析的程序集(内部使用)
			/// </summary>
			void MdAdapter::SetAssembly(array<System::Reflection::Assembly^>^ assm)
			{
				m_ppAssembly = assm;
			}

		    /// <summary>
		    /// 行情命令请求
		    /// </summary>
		    MdAdapter::~MdAdapter()
		    {
		    	Release();
		    }

		    /// <summary>
		    /// 删除接口对象本身
		    /// <para>不再使用本接口对象时,调用该函数删除接口对象</para>
		    /// </summary>
		    void MdAdapter::Release()
		    {
		    	if (m_pApi != nullptr)
		    	{
		    		m_pApi->RegisterSpi(0);
			    	m_pApi->Release();
				    m_pApi = nullptr;
			    }
			    if (m_pSpi != nullptr)
   			    {
	    			delete m_pSpi;
	    			m_pSpi = nullptr;
	    		}
	    	}

   		    /// <summary>
   		    /// 初始化
   		    /// <para>初始化运行环境,只有调用后,接口才开始工作</para>
   		    /// </summary>
   		    void MdAdapter::Init()
   		    {
   		    	m_pApi->Init();
   		    }

   		    /// <summary>
   		    /// 等待接口线程结束运行
   		    /// <para>返回线程退出代码</para>
   		    /// </summary>
   		    int MdAdapter::Join()
   		    {
   		    	return m_pApi->Join();
   		    }

   		    /// <summary>
   		    /// 获取当前交易日
   		    /// <para>只有登录成功后,才能得到正确的交易日</para>
   		    /// </summary>
   		    String^ MdAdapter::GetTradingDay()
   		    {
   		    	return gcnew String(m_pApi->GetTradingDay());
   		    }

	    	/// <summary>
	    	/// 注册前置机网络地址
	    	/// <para>pszFrontAddress：前置机网络地址。</para>
	    	/// <para>网络地址的格式为：“protocol:ipaddress:port”，如：”tcp:127.0.0.1:17001”。</para>
	    	/// <para>“tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。</para>
	    	/// </summary>
	    	void MdAdapter::RegisterFront(String^ pszFrontAddress)
	    	{
	    		//if (pszFrontAddress != nullptr)
	    		{
	    			CAutoStrPtr asp = CAutoStrPtr(pszFrontAddress);
	    			m_pApi->RegisterFront(asp.m_pChar);
	    		}
	    	}

	    	/// <summary>
	    	/// 注册名字服务器网络地址
	    	/// <para>pszNsAddress：名字服务器网络地址。</para>
	    	/// <para>网络地址的格式为：“protocol:ipaddress:port”，如：”tcp:127.0.0.1:12001”。</para>
	    	/// <para>“tcp”代表传输协议，“127.0.0.1”代表服务器地址。”12001”代表服务器端口号。</para>
	    	/// <para>RegisterNameServer优先于RegisterFront</para>
	    	/// </summary>
	    	void MdAdapter::RegisterNameServer(String^ pszNsAddress)
	    	{
	    		//if (pszNsAddress != nullptr)
	    		{
	    			CAutoStrPtr asp = CAutoStrPtr(pszNsAddress);
	    			m_pApi->RegisterNameServer(asp.m_pChar);
	    		}
	    	}

	    	/// <summary>
	    	/// 注册名字服务器用户信息
	    	/// <para>pFensUserInfo：用户信息。</para>
	    	/// </summary>
	    	void MdAdapter::RegisterFensUserInfo(CtpNetFensUserInfoField^ pFensUserInfo)
	    	{
	    		if (pFensUserInfo == nullptr)
    			{
	    			m_pApi->RegisterFensUserInfo(nullptr);
	    			return;
	    		}
	    		
	    		CThostFtdcFensUserInfoField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pFensUserInfo->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pFensUserInfo->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//用户代码
	    		if (pFensUserInfo->UserID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pFensUserInfo->UserID);
	    			strcpy_s(native.UserID, 16, asp2.m_pChar);
	    		}
	    		
	    		//登录模式
	    		native.LoginMode = (Byte)pFensUserInfo->LoginMode;
			
	    		m_pApi->RegisterFensUserInfo(&native);
	    	}

	    	/// <summary>
	    	/// 订阅行情。
	    	/// <para>ppInstrumentID 合约ID</para>
	    	/// <para>nCount 要订阅/退订行情的合约个数</para>
	    	/// </summary>
	    	int MdAdapter::SubscribeMarketData(array<String^>^ ppInstrumentID)
	    	{
	    		if(ppInstrumentID == nullptr)
	    		{
	    			return m_pApi->SubscribeMarketData(nullptr, 0);
	    		}

	    		if(ppInstrumentID->Length <= 0)
	    		{
	    			char** pp = new char*[0];
	    			int result = m_pApi->SubscribeMarketData(pp, 0);
	    			delete[] pp;
	    			return result;
	    		}

	    		int count = ppInstrumentID->Length;
	    		char** pp = new char*[count];
	    		CAutoStrPtr** asp = new CAutoStrPtr*[count];
	    		for(int i = 0; i < count; i++)
	    		{
	    			CAutoStrPtr* ptr = new CAutoStrPtr(ppInstrumentID[i]);
	    			asp[i] = ptr;
	    			pp[i] = ptr->m_pChar;
	    		}

	    		int result = m_pApi->SubscribeMarketData(pp, count);

	    		for(int i = 0; i < count; i++) delete asp[i];
	    		delete[] asp;
	    		delete[] pp;

	    		return result;
	    	}

	    	/// <summary>
	    	/// 退订行情。
	    	/// <para>ppInstrumentID 合约ID</para>
	    	/// <para>nCount 要订阅/退订行情的合约个数</para>
	    	/// </summary>
	    	int MdAdapter::UnSubscribeMarketData(array<String^>^ ppInstrumentID)
	    	{
	    		if(ppInstrumentID == nullptr)
	    		{
	    			return m_pApi->UnSubscribeMarketData(nullptr, 0);
	    		}

	    		if(ppInstrumentID->Length <= 0)
	    		{
	    			char** pp = new char*[0];
	    			int result = m_pApi->UnSubscribeMarketData(pp, 0);
	    			delete[] pp;
	    			return result;
	    		}

	    		int count = ppInstrumentID->Length;
	    		char** pp = new char*[count];
	    		CAutoStrPtr** asp = new CAutoStrPtr*[count];
	    		for(int i = 0; i < count; i++)
	    		{
	    			CAutoStrPtr* ptr = new CAutoStrPtr(ppInstrumentID[i]);
	    			asp[i] = ptr;
	    			pp[i] = ptr->m_pChar;
	    		}

	    		int result = m_pApi->UnSubscribeMarketData(pp, count);

	    		for(int i = 0; i < count; i++) delete asp[i];
	    		delete[] asp;
	    		delete[] pp;

	    		return result;
	    	}

	    	/// <summary>
	    	/// 订阅询价。
	    	/// <para>ppInstrumentID 合约ID</para>
	    	/// <para>nCount 要订阅/退订行情的合约个数</para>
	    	/// </summary>
	    	int MdAdapter::SubscribeForQuoteRsp(array<String^>^ ppInstrumentID)
	    	{
	    		if(ppInstrumentID == nullptr)
	    		{
	    			return m_pApi->SubscribeForQuoteRsp(nullptr, 0);
	    		}

	    		if(ppInstrumentID->Length <= 0)
	    		{
	    			char** pp = new char*[0];
	    			int result = m_pApi->SubscribeForQuoteRsp(pp, 0);
	    			delete[] pp;
	    			return result;
	    		}

	    		int count = ppInstrumentID->Length;
	    		char** pp = new char*[count];
	    		CAutoStrPtr** asp = new CAutoStrPtr*[count];
	    		for(int i = 0; i < count; i++)
	    		{
	    			CAutoStrPtr* ptr = new CAutoStrPtr(ppInstrumentID[i]);
	    			asp[i] = ptr;
	    			pp[i] = ptr->m_pChar;
	    		}

	    		int result = m_pApi->SubscribeForQuoteRsp(pp, count);

	    		for(int i = 0; i < count; i++) delete asp[i];
	    		delete[] asp;
	    		delete[] pp;

	    		return result;
	    	}

	    	/// <summary>
	    	/// 退订询价。
	    	/// <para>ppInstrumentID 合约ID</para>
	    	/// <para>nCount 要订阅/退订行情的合约个数</para>
	    	/// </summary>
	    	int MdAdapter::UnSubscribeForQuoteRsp(array<String^>^ ppInstrumentID)
	    	{
	    		if(ppInstrumentID == nullptr)
	    		{
	    			return m_pApi->UnSubscribeForQuoteRsp(nullptr, 0);
	    		}

	    		if(ppInstrumentID->Length <= 0)
	    		{
	    			char** pp = new char*[0];
	    			int result = m_pApi->UnSubscribeForQuoteRsp(pp, 0);
	    			delete[] pp;
	    			return result;
	    		}

	    		int count = ppInstrumentID->Length;
	    		char** pp = new char*[count];
	    		CAutoStrPtr** asp = new CAutoStrPtr*[count];
	    		for(int i = 0; i < count; i++)
	    		{
	    			CAutoStrPtr* ptr = new CAutoStrPtr(ppInstrumentID[i]);
	    			asp[i] = ptr;
	    			pp[i] = ptr->m_pChar;
	    		}

	    		int result = m_pApi->UnSubscribeForQuoteRsp(pp, count);

	    		for(int i = 0; i < count; i++) delete asp[i];
	    		delete[] asp;
	    		delete[] pp;

	    		return result;
	    	}

	    	/// <summary>
	    	/// 用户登录请求
	    	/// </summary>
	    	int MdAdapter::ReqUserLogin(CtpNetReqUserLoginField^ pReqUserLoginField, int nRequestID)
	    	{
	    		if (pReqUserLoginField == nullptr)
    			{
	    			return m_pApi->ReqUserLogin(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcReqUserLoginField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//交易日
	    		if (pReqUserLoginField->TradingDay != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pReqUserLoginField->TradingDay);
	    			strcpy_s(native.TradingDay, 9, asp1.m_pChar);
	    		}
	    		
	    		//经纪公司代码
	    		if (pReqUserLoginField->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pReqUserLoginField->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp2.m_pChar);
	    		}
	    		
	    		//用户代码
	    		if (pReqUserLoginField->UserID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pReqUserLoginField->UserID);
	    			strcpy_s(native.UserID, 16, asp3.m_pChar);
	    		}
	    		
	    		//密码
	    		if (pReqUserLoginField->Password != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pReqUserLoginField->Password);
	    			strcpy_s(native.Password, 41, asp4.m_pChar);
	    		}
	    		
	    		//用户端产品信息
	    		if (pReqUserLoginField->UserProductInfo != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pReqUserLoginField->UserProductInfo);
	    			strcpy_s(native.UserProductInfo, 11, asp5.m_pChar);
	    		}
	    		
	    		//接口端产品信息
	    		if (pReqUserLoginField->InterfaceProductInfo != nullptr)
	    		{
	    			CAutoStrPtr asp6 = CAutoStrPtr(pReqUserLoginField->InterfaceProductInfo);
	    			strcpy_s(native.InterfaceProductInfo, 11, asp6.m_pChar);
	    		}
	    		
	    		//协议信息
	    		if (pReqUserLoginField->ProtocolInfo != nullptr)
	    		{
	    			CAutoStrPtr asp7 = CAutoStrPtr(pReqUserLoginField->ProtocolInfo);
	    			strcpy_s(native.ProtocolInfo, 11, asp7.m_pChar);
	    		}
	    		
	    		//Mac地址
	    		if (pReqUserLoginField->MacAddress != nullptr)
	    		{
	    			CAutoStrPtr asp8 = CAutoStrPtr(pReqUserLoginField->MacAddress);
	    			strcpy_s(native.MacAddress, 21, asp8.m_pChar);
	    		}
	    		
	    		//动态密码
	    		if (pReqUserLoginField->OneTimePassword != nullptr)
	    		{
	    			CAutoStrPtr asp9 = CAutoStrPtr(pReqUserLoginField->OneTimePassword);
	    			strcpy_s(native.OneTimePassword, 41, asp9.m_pChar);
	    		}
	    		
	    		//终端IP地址
	    		if (pReqUserLoginField->ClientIPAddress != nullptr)
	    		{
	    			CAutoStrPtr asp10 = CAutoStrPtr(pReqUserLoginField->ClientIPAddress);
	    			strcpy_s(native.ClientIPAddress, 16, asp10.m_pChar);
	    		}
	    		
	    		//登录备注
	    		if (pReqUserLoginField->LoginRemark != nullptr)
	    		{
	    			CAutoStrPtr asp11 = CAutoStrPtr(pReqUserLoginField->LoginRemark);
	    			strcpy_s(native.LoginRemark, 36, asp11.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqUserLogin(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 登出请求
	    	/// </summary>
	    	int MdAdapter::ReqUserLogout(CtpNetUserLogoutField^ pUserLogout, int nRequestID)
	    	{
	    		if (pUserLogout == nullptr)
    			{
	    			return m_pApi->ReqUserLogout(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcUserLogoutField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pUserLogout->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pUserLogout->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//用户代码
	    		if (pUserLogout->UserID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pUserLogout->UserID);
	    			strcpy_s(native.UserID, 16, asp2.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqUserLogout(&native, nRequestID);
	    	}
	    }
	}
}
