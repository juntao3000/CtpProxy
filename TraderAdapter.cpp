#include <string.h>
#include "TraderSpi.h"
#include "TraderAdapter.h"

namespace TaiTanXing
{
	namespace Ctp
	{
		namespace CtpProxy
		{
			/// <summary>
			/// 交易对象
			/// </summary>
			TraderAdapter::TraderAdapter()
					: TraderAdapter("")
				{}
			//{
			//	m_pApi = CThostFtdcTraderApi::CreateFtdcTraderApi("");
			//	m_pSpi = new CTraderSpi((TraderAdapter^)this);
			//	m_pApi->RegisterSpi(m_pSpi);
			//}

			/// <summary>
			/// 交易对象
			/// </summary>
			TraderAdapter::TraderAdapter(String^ pszFlowPath, bool bIsUsingUdp)
					: TraderAdapter(pszFlowPath)
				{}
			//{
			//	CAutoStrPtr asp(pszFlowPath);
			//	m_pApi = CThostFtdcTraderApi::CreateFtdcTraderApi(asp.m_pChar);
			//	m_pSpi = new CTraderSpi((TraderAdapter^)this);
			//	m_pApi->RegisterSpi(m_pSpi);
			//}

			/// <summary>
			/// 交易对象
			/// </summary>
			TraderAdapter::TraderAdapter(String^ pszFlowPath)
			{
				CAutoStrPtr asp(pszFlowPath);
				m_pApi = CThostFtdcTraderApi::CreateFtdcTraderApi(asp.m_pChar);
				m_pSpi = new CTraderSpi((TraderAdapter^)this);
				m_pApi->RegisterSpi(m_pSpi);

				//动态解析程序集
				System::AppDomain::CurrentDomain->AssemblyResolve += gcnew System::ResolveEventHandler(this, &TraderAdapter::OnAssemblyResolve);
			}

			/// <summary>
			/// 动态解析程序集
			/// </summary>
			System::Reflection::Assembly^ TraderAdapter::OnAssemblyResolve(System::Object ^sender, System::ResolveEventArgs ^args)
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
			void TraderAdapter::SetAssembly(array<System::Reflection::Assembly^>^ assm)
			{
				m_ppAssembly = assm;
			}

		    /// <summary>
		    /// 交易命令请求
		    /// </summary>
		    TraderAdapter::~TraderAdapter()
		    {
		    	Release();
		    }

		    /// <summary>
		    /// 删除接口对象本身
		    /// <para>不再使用本接口对象时,调用该函数删除接口对象</para>
		    /// </summary>
		    void TraderAdapter::Release()
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
   		    void TraderAdapter::Init()
   		    {
   		    	m_pApi->Init();
   		    }

   		    /// <summary>
   		    /// 等待接口线程结束运行
   		    /// <para>返回线程退出代码</para>
   		    /// </summary>
   		    int TraderAdapter::Join()
   		    {
   		    	return m_pApi->Join();
   		    }

   		    /// <summary>
   		    /// 获取当前交易日
   		    /// <para>只有登录成功后,才能得到正确的交易日</para>
   		    /// </summary>
   		    String^ TraderAdapter::GetTradingDay()
   		    {
   		    	return gcnew String(m_pApi->GetTradingDay());
   		    }

	    	/// <summary>
	    	/// 注册前置机网络地址
	    	/// <para>pszFrontAddress：前置机网络地址。</para>
	    	/// <para>网络地址的格式为：“protocol:ipaddress:port”，如：”tcp:127.0.0.1:17001”。</para>
	    	/// <para>“tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。</para>
	    	/// </summary>
	    	void TraderAdapter::RegisterFront(String^ pszFrontAddress)
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
	    	void TraderAdapter::RegisterNameServer(String^ pszNsAddress)
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
	    	void TraderAdapter::RegisterFensUserInfo(CtpNetFensUserInfoField^ pFensUserInfo)
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
	    	/// 订阅私有流。
	    	/// <para>nResumeType 私有流重传方式</para>
	    	/// <para>THOST_TERT_RESTART:从本交易日开始重传</para>
	    	/// <para>THOST_TERT_RESUME:从上次收到的续传</para>
	    	/// <para>THOST_TERT_QUICK:只传送登录后私有流的内容</para>
	    	/// <para>该方法要在Init方法前调用。若不调用则不会收到私有流的数据。</para>
	    	/// </summary>
	    	void TraderAdapter::SubscribePrivateTopic(CtpNetResumeType nResumeType)
	    	{
	    		m_pApi->SubscribePrivateTopic((THOST_TE_RESUME_TYPE)nResumeType);
    		}

	    	/// <summary>
	    	/// 订阅公共流。
	    	/// <para>nResumeType 公共流重传方式</para>
	    	/// <para>THOST_TERT_RESTART:从本交易日开始重传</para>
	    	/// <para>THOST_TERT_RESUME:从上次收到的续传</para>
	    	/// <para>THOST_TERT_QUICK:只传送登录后公共流的内容</para>
	    	/// <para>该方法要在Init方法前调用。若不调用则不会收到公共流的数据。</para>
	    	/// </summary>
	    	void TraderAdapter::SubscribePublicTopic(CtpNetResumeType nResumeType)
	    	{
	    		m_pApi->SubscribePublicTopic((THOST_TE_RESUME_TYPE)nResumeType);
    		}

	    	/// <summary>
	    	/// 客户端认证请求
	    	/// </summary>
	    	int TraderAdapter::ReqAuthenticate(CtpNetReqAuthenticateField^ pReqAuthenticateField, int nRequestID)
	    	{
	    		if (pReqAuthenticateField == nullptr)
    			{
	    			return m_pApi->ReqAuthenticate(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcReqAuthenticateField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pReqAuthenticateField->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pReqAuthenticateField->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//用户代码
	    		if (pReqAuthenticateField->UserID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pReqAuthenticateField->UserID);
	    			strcpy_s(native.UserID, 16, asp2.m_pChar);
	    		}
	    		
	    		//用户端产品信息
	    		if (pReqAuthenticateField->UserProductInfo != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pReqAuthenticateField->UserProductInfo);
	    			strcpy_s(native.UserProductInfo, 11, asp3.m_pChar);
	    		}
	    		
	    		//认证码
	    		if (pReqAuthenticateField->AuthCode != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pReqAuthenticateField->AuthCode);
	    			strcpy_s(native.AuthCode, 17, asp4.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqAuthenticate(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 用户登录请求
	    	/// </summary>
	    	int TraderAdapter::ReqUserLogin(CtpNetReqUserLoginField^ pReqUserLoginField, int nRequestID)
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
	    	int TraderAdapter::ReqUserLogout(CtpNetUserLogoutField^ pUserLogout, int nRequestID)
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

	    	/// <summary>
	    	/// 用户口令更新请求
	    	/// </summary>
	    	int TraderAdapter::ReqUserPasswordUpdate(CtpNetUserPasswordUpdateField^ pUserPasswordUpdate, int nRequestID)
	    	{
	    		if (pUserPasswordUpdate == nullptr)
    			{
	    			return m_pApi->ReqUserPasswordUpdate(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcUserPasswordUpdateField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pUserPasswordUpdate->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pUserPasswordUpdate->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//用户代码
	    		if (pUserPasswordUpdate->UserID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pUserPasswordUpdate->UserID);
	    			strcpy_s(native.UserID, 16, asp2.m_pChar);
	    		}
	    		
	    		//原来的口令
	    		if (pUserPasswordUpdate->OldPassword != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pUserPasswordUpdate->OldPassword);
	    			strcpy_s(native.OldPassword, 41, asp3.m_pChar);
	    		}
	    		
	    		//新的口令
	    		if (pUserPasswordUpdate->NewPassword != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pUserPasswordUpdate->NewPassword);
	    			strcpy_s(native.NewPassword, 41, asp4.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqUserPasswordUpdate(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 资金账户口令更新请求
	    	/// </summary>
	    	int TraderAdapter::ReqTradingAccountPasswordUpdate(CtpNetTradingAccountPasswordUpdateField^ pTradingAccountPasswordUpdate, int nRequestID)
	    	{
	    		if (pTradingAccountPasswordUpdate == nullptr)
    			{
	    			return m_pApi->ReqTradingAccountPasswordUpdate(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcTradingAccountPasswordUpdateField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pTradingAccountPasswordUpdate->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pTradingAccountPasswordUpdate->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者帐号
	    		if (pTradingAccountPasswordUpdate->AccountID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pTradingAccountPasswordUpdate->AccountID);
	    			strcpy_s(native.AccountID, 13, asp2.m_pChar);
	    		}
	    		
	    		//原来的口令
	    		if (pTradingAccountPasswordUpdate->OldPassword != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pTradingAccountPasswordUpdate->OldPassword);
	    			strcpy_s(native.OldPassword, 41, asp3.m_pChar);
	    		}
	    		
	    		//新的口令
	    		if (pTradingAccountPasswordUpdate->NewPassword != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pTradingAccountPasswordUpdate->NewPassword);
	    			strcpy_s(native.NewPassword, 41, asp4.m_pChar);
	    		}
	    		
	    		//币种代码
	    		if (pTradingAccountPasswordUpdate->CurrencyID != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pTradingAccountPasswordUpdate->CurrencyID);
	    			strcpy_s(native.CurrencyID, 4, asp5.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqTradingAccountPasswordUpdate(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 登录请求2
	    	/// </summary>
	    	int TraderAdapter::ReqUserLogin2(CtpNetReqUserLoginField^ pReqUserLogin, int nRequestID)
	    	{
	    		if (pReqUserLogin == nullptr)
    			{
	    			return m_pApi->ReqUserLogin2(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcReqUserLoginField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//交易日
	    		if (pReqUserLogin->TradingDay != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pReqUserLogin->TradingDay);
	    			strcpy_s(native.TradingDay, 9, asp1.m_pChar);
	    		}
	    		
	    		//经纪公司代码
	    		if (pReqUserLogin->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pReqUserLogin->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp2.m_pChar);
	    		}
	    		
	    		//用户代码
	    		if (pReqUserLogin->UserID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pReqUserLogin->UserID);
	    			strcpy_s(native.UserID, 16, asp3.m_pChar);
	    		}
	    		
	    		//密码
	    		if (pReqUserLogin->Password != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pReqUserLogin->Password);
	    			strcpy_s(native.Password, 41, asp4.m_pChar);
	    		}
	    		
	    		//用户端产品信息
	    		if (pReqUserLogin->UserProductInfo != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pReqUserLogin->UserProductInfo);
	    			strcpy_s(native.UserProductInfo, 11, asp5.m_pChar);
	    		}
	    		
	    		//接口端产品信息
	    		if (pReqUserLogin->InterfaceProductInfo != nullptr)
	    		{
	    			CAutoStrPtr asp6 = CAutoStrPtr(pReqUserLogin->InterfaceProductInfo);
	    			strcpy_s(native.InterfaceProductInfo, 11, asp6.m_pChar);
	    		}
	    		
	    		//协议信息
	    		if (pReqUserLogin->ProtocolInfo != nullptr)
	    		{
	    			CAutoStrPtr asp7 = CAutoStrPtr(pReqUserLogin->ProtocolInfo);
	    			strcpy_s(native.ProtocolInfo, 11, asp7.m_pChar);
	    		}
	    		
	    		//Mac地址
	    		if (pReqUserLogin->MacAddress != nullptr)
	    		{
	    			CAutoStrPtr asp8 = CAutoStrPtr(pReqUserLogin->MacAddress);
	    			strcpy_s(native.MacAddress, 21, asp8.m_pChar);
	    		}
	    		
	    		//动态密码
	    		if (pReqUserLogin->OneTimePassword != nullptr)
	    		{
	    			CAutoStrPtr asp9 = CAutoStrPtr(pReqUserLogin->OneTimePassword);
	    			strcpy_s(native.OneTimePassword, 41, asp9.m_pChar);
	    		}
	    		
	    		//终端IP地址
	    		if (pReqUserLogin->ClientIPAddress != nullptr)
	    		{
	    			CAutoStrPtr asp10 = CAutoStrPtr(pReqUserLogin->ClientIPAddress);
	    			strcpy_s(native.ClientIPAddress, 16, asp10.m_pChar);
	    		}
	    		
	    		//登录备注
	    		if (pReqUserLogin->LoginRemark != nullptr)
	    		{
	    			CAutoStrPtr asp11 = CAutoStrPtr(pReqUserLogin->LoginRemark);
	    			strcpy_s(native.LoginRemark, 36, asp11.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqUserLogin2(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 用户口令更新请求2
	    	/// </summary>
	    	int TraderAdapter::ReqUserPasswordUpdate2(CtpNetUserPasswordUpdateField^ pUserPasswordUpdate, int nRequestID)
	    	{
	    		if (pUserPasswordUpdate == nullptr)
    			{
	    			return m_pApi->ReqUserPasswordUpdate2(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcUserPasswordUpdateField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pUserPasswordUpdate->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pUserPasswordUpdate->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//用户代码
	    		if (pUserPasswordUpdate->UserID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pUserPasswordUpdate->UserID);
	    			strcpy_s(native.UserID, 16, asp2.m_pChar);
	    		}
	    		
	    		//原来的口令
	    		if (pUserPasswordUpdate->OldPassword != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pUserPasswordUpdate->OldPassword);
	    			strcpy_s(native.OldPassword, 41, asp3.m_pChar);
	    		}
	    		
	    		//新的口令
	    		if (pUserPasswordUpdate->NewPassword != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pUserPasswordUpdate->NewPassword);
	    			strcpy_s(native.NewPassword, 41, asp4.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqUserPasswordUpdate2(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 报单录入请求
	    	/// </summary>
	    	int TraderAdapter::ReqOrderInsert(CtpNetInputOrderField^ pInputOrder, int nRequestID)
	    	{
	    		if (pInputOrder == nullptr)
    			{
	    			return m_pApi->ReqOrderInsert(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcInputOrderField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pInputOrder->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pInputOrder->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pInputOrder->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pInputOrder->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//合约代码
	    		if (pInputOrder->InstrumentID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pInputOrder->InstrumentID);
	    			strcpy_s(native.InstrumentID, 31, asp3.m_pChar);
	    		}
	    		
	    		//报单引用
	    		if (pInputOrder->OrderRef != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pInputOrder->OrderRef);
	    			strcpy_s(native.OrderRef, 13, asp4.m_pChar);
	    		}
	    		
	    		//用户代码
	    		if (pInputOrder->UserID != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pInputOrder->UserID);
	    			strcpy_s(native.UserID, 16, asp5.m_pChar);
	    		}
	    		
	    		//报单价格条件
	    		native.OrderPriceType = (Byte)pInputOrder->OrderPriceType;
			
	    		//买卖方向
	    		native.Direction = (Byte)pInputOrder->Direction;
			
	    		//组合开平标志1
	    		native.CombOffsetFlag[0] = (Byte)pInputOrder->CombOffsetFlag1;
	    		
	    		//组合开平标志2
	    		native.CombOffsetFlag[1] = (Byte)pInputOrder->CombOffsetFlag2;
	    		
	    		//组合开平标志3
	    		native.CombOffsetFlag[2] = (Byte)pInputOrder->CombOffsetFlag3;
	    		
	    		//组合开平标志4
	    		native.CombOffsetFlag[3] = (Byte)pInputOrder->CombOffsetFlag4;
	    		
	    		//组合开平标志5
	    		native.CombOffsetFlag[4] = (Byte)pInputOrder->CombOffsetFlag5;
	    		
	    		//组合投机套保标志1
	    		native.CombHedgeFlag[0] = (Byte)pInputOrder->CombHedgeFlag1;
			
	    		//组合投机套保标志2
	    		native.CombHedgeFlag[1] = (Byte)pInputOrder->CombHedgeFlag2;
			
	    		//组合投机套保标志3
	    		native.CombHedgeFlag[2] = (Byte)pInputOrder->CombHedgeFlag3;
			
	    		//组合投机套保标志4
	    		native.CombHedgeFlag[3] = (Byte)pInputOrder->CombHedgeFlag4;
			
	    		//组合投机套保标志5
	    		native.CombHedgeFlag[4] = (Byte)pInputOrder->CombHedgeFlag5;
			
	    		//价格
	    		native.LimitPrice = pInputOrder->LimitPrice;
			
	    		//数量
	    		native.VolumeTotalOriginal = pInputOrder->VolumeTotalOriginal;
			
	    		//有效期类型
	    		native.TimeCondition = (Byte)pInputOrder->TimeCondition;
			
	    		//GTD日期
	    		if (pInputOrder->GTDDate != nullptr)
	    		{
	    			CAutoStrPtr asp6 = CAutoStrPtr(pInputOrder->GTDDate);
	    			strcpy_s(native.GTDDate, 9, asp6.m_pChar);
	    		}
	    		
	    		//成交量类型
	    		native.VolumeCondition = (Byte)pInputOrder->VolumeCondition;
			
	    		//最小成交量
	    		native.MinVolume = pInputOrder->MinVolume;
			
	    		//触发条件
	    		native.ContingentCondition = (Byte)pInputOrder->ContingentCondition;
			
	    		//止损价
	    		native.StopPrice = pInputOrder->StopPrice;
			
	    		//强平原因
	    		native.ForceCloseReason = (Byte)pInputOrder->ForceCloseReason;
			
	    		//自动挂起标志
	    		native.IsAutoSuspend = pInputOrder->IsAutoSuspend;
			
	    		//业务单元
	    		if (pInputOrder->BusinessUnit != nullptr)
	    		{
	    			CAutoStrPtr asp7 = CAutoStrPtr(pInputOrder->BusinessUnit);
	    			strcpy_s(native.BusinessUnit, 21, asp7.m_pChar);
	    		}
	    		
	    		//请求编号
	    		native.RequestID = pInputOrder->RequestID;
			
	    		//用户强评标志
	    		native.UserForceClose = pInputOrder->UserForceClose;
			
	    		//互换单标志
	    		native.IsSwapOrder = pInputOrder->IsSwapOrder;
			
	    		//交易所代码
	    		if (pInputOrder->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp8 = CAutoStrPtr(pInputOrder->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp8.m_pChar);
	    		}
	    		
	    		//投资单元代码
	    		if (pInputOrder->InvestUnitID != nullptr)
	    		{
	    			CAutoStrPtr asp9 = CAutoStrPtr(pInputOrder->InvestUnitID);
	    			strcpy_s(native.InvestUnitID, 17, asp9.m_pChar);
	    		}
	    		
	    		//资金账号
	    		if (pInputOrder->AccountID != nullptr)
	    		{
	    			CAutoStrPtr asp10 = CAutoStrPtr(pInputOrder->AccountID);
	    			strcpy_s(native.AccountID, 13, asp10.m_pChar);
	    		}
	    		
	    		//币种代码
	    		if (pInputOrder->CurrencyID != nullptr)
	    		{
	    			CAutoStrPtr asp11 = CAutoStrPtr(pInputOrder->CurrencyID);
	    			strcpy_s(native.CurrencyID, 4, asp11.m_pChar);
	    		}
	    		
	    		//交易编码
	    		if (pInputOrder->ClientID != nullptr)
	    		{
	    			CAutoStrPtr asp12 = CAutoStrPtr(pInputOrder->ClientID);
	    			strcpy_s(native.ClientID, 11, asp12.m_pChar);
	    		}
	    		
	    		//IP地址
	    		if (pInputOrder->IPAddress != nullptr)
	    		{
	    			CAutoStrPtr asp13 = CAutoStrPtr(pInputOrder->IPAddress);
	    			strcpy_s(native.IPAddress, 16, asp13.m_pChar);
	    		}
	    		
	    		//Mac地址
	    		if (pInputOrder->MacAddress != nullptr)
	    		{
	    			CAutoStrPtr asp14 = CAutoStrPtr(pInputOrder->MacAddress);
	    			strcpy_s(native.MacAddress, 21, asp14.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqOrderInsert(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 预埋单录入请求
	    	/// </summary>
	    	int TraderAdapter::ReqParkedOrderInsert(CtpNetParkedOrderField^ pParkedOrder, int nRequestID)
	    	{
	    		if (pParkedOrder == nullptr)
    			{
	    			return m_pApi->ReqParkedOrderInsert(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcParkedOrderField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pParkedOrder->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pParkedOrder->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pParkedOrder->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pParkedOrder->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//合约代码
	    		if (pParkedOrder->InstrumentID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pParkedOrder->InstrumentID);
	    			strcpy_s(native.InstrumentID, 31, asp3.m_pChar);
	    		}
	    		
	    		//报单引用
	    		if (pParkedOrder->OrderRef != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pParkedOrder->OrderRef);
	    			strcpy_s(native.OrderRef, 13, asp4.m_pChar);
	    		}
	    		
	    		//用户代码
	    		if (pParkedOrder->UserID != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pParkedOrder->UserID);
	    			strcpy_s(native.UserID, 16, asp5.m_pChar);
	    		}
	    		
	    		//报单价格条件
	    		native.OrderPriceType = (Byte)pParkedOrder->OrderPriceType;
			
	    		//买卖方向
	    		native.Direction = (Byte)pParkedOrder->Direction;
			
	    		//组合开平标志1
	    		native.CombOffsetFlag[0] = (Byte)pParkedOrder->CombOffsetFlag1;
	    		
	    		//组合开平标志2
	    		native.CombOffsetFlag[1] = (Byte)pParkedOrder->CombOffsetFlag2;
	    		
	    		//组合开平标志3
	    		native.CombOffsetFlag[2] = (Byte)pParkedOrder->CombOffsetFlag3;
	    		
	    		//组合开平标志4
	    		native.CombOffsetFlag[3] = (Byte)pParkedOrder->CombOffsetFlag4;
	    		
	    		//组合开平标志5
	    		native.CombOffsetFlag[4] = (Byte)pParkedOrder->CombOffsetFlag5;
	    		
	    		//组合投机套保标志1
	    		native.CombHedgeFlag[0] = (Byte)pParkedOrder->CombHedgeFlag1;
			
	    		//组合投机套保标志2
	    		native.CombHedgeFlag[1] = (Byte)pParkedOrder->CombHedgeFlag2;
			
	    		//组合投机套保标志3
	    		native.CombHedgeFlag[2] = (Byte)pParkedOrder->CombHedgeFlag3;
			
	    		//组合投机套保标志4
	    		native.CombHedgeFlag[3] = (Byte)pParkedOrder->CombHedgeFlag4;
			
	    		//组合投机套保标志5
	    		native.CombHedgeFlag[4] = (Byte)pParkedOrder->CombHedgeFlag5;
			
	    		//价格
	    		native.LimitPrice = pParkedOrder->LimitPrice;
			
	    		//数量
	    		native.VolumeTotalOriginal = pParkedOrder->VolumeTotalOriginal;
			
	    		//有效期类型
	    		native.TimeCondition = (Byte)pParkedOrder->TimeCondition;
			
	    		//GTD日期
	    		if (pParkedOrder->GTDDate != nullptr)
	    		{
	    			CAutoStrPtr asp6 = CAutoStrPtr(pParkedOrder->GTDDate);
	    			strcpy_s(native.GTDDate, 9, asp6.m_pChar);
	    		}
	    		
	    		//成交量类型
	    		native.VolumeCondition = (Byte)pParkedOrder->VolumeCondition;
			
	    		//最小成交量
	    		native.MinVolume = pParkedOrder->MinVolume;
			
	    		//触发条件
	    		native.ContingentCondition = (Byte)pParkedOrder->ContingentCondition;
			
	    		//止损价
	    		native.StopPrice = pParkedOrder->StopPrice;
			
	    		//强平原因
	    		native.ForceCloseReason = (Byte)pParkedOrder->ForceCloseReason;
			
	    		//自动挂起标志
	    		native.IsAutoSuspend = pParkedOrder->IsAutoSuspend;
			
	    		//业务单元
	    		if (pParkedOrder->BusinessUnit != nullptr)
	    		{
	    			CAutoStrPtr asp7 = CAutoStrPtr(pParkedOrder->BusinessUnit);
	    			strcpy_s(native.BusinessUnit, 21, asp7.m_pChar);
	    		}
	    		
	    		//请求编号
	    		native.RequestID = pParkedOrder->RequestID;
			
	    		//用户强评标志
	    		native.UserForceClose = pParkedOrder->UserForceClose;
			
	    		//交易所代码
	    		if (pParkedOrder->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp8 = CAutoStrPtr(pParkedOrder->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp8.m_pChar);
	    		}
	    		
	    		//预埋报单编号
	    		if (pParkedOrder->ParkedOrderID != nullptr)
	    		{
	    			CAutoStrPtr asp9 = CAutoStrPtr(pParkedOrder->ParkedOrderID);
	    			strcpy_s(native.ParkedOrderID, 13, asp9.m_pChar);
	    		}
	    		
	    		//用户类型
	    		native.UserType = (Byte)pParkedOrder->UserType;
			
	    		//预埋单状态
	    		native.Status = (Byte)pParkedOrder->Status;
			
	    		//错误代码
	    		native.ErrorID = pParkedOrder->ErrorID;
			
	    		//错误信息
	    		if (pParkedOrder->ErrorMsg != nullptr)
	    		{
	    			CAutoStrPtr asp10 = CAutoStrPtr(pParkedOrder->ErrorMsg);
	    			strcpy_s(native.ErrorMsg, 81, asp10.m_pChar);
	    		}
	    		
	    		//互换单标志
	    		native.IsSwapOrder = pParkedOrder->IsSwapOrder;
			
	    		//资金账号
	    		if (pParkedOrder->AccountID != nullptr)
	    		{
	    			CAutoStrPtr asp11 = CAutoStrPtr(pParkedOrder->AccountID);
	    			strcpy_s(native.AccountID, 13, asp11.m_pChar);
	    		}
	    		
	    		//币种代码
	    		if (pParkedOrder->CurrencyID != nullptr)
	    		{
	    			CAutoStrPtr asp12 = CAutoStrPtr(pParkedOrder->CurrencyID);
	    			strcpy_s(native.CurrencyID, 4, asp12.m_pChar);
	    		}
	    		
	    		//交易编码
	    		if (pParkedOrder->ClientID != nullptr)
	    		{
	    			CAutoStrPtr asp13 = CAutoStrPtr(pParkedOrder->ClientID);
	    			strcpy_s(native.ClientID, 11, asp13.m_pChar);
	    		}
	    		
	    		//投资单元代码
	    		if (pParkedOrder->InvestUnitID != nullptr)
	    		{
	    			CAutoStrPtr asp14 = CAutoStrPtr(pParkedOrder->InvestUnitID);
	    			strcpy_s(native.InvestUnitID, 17, asp14.m_pChar);
	    		}
	    		
	    		//IP地址
	    		if (pParkedOrder->IPAddress != nullptr)
	    		{
	    			CAutoStrPtr asp15 = CAutoStrPtr(pParkedOrder->IPAddress);
	    			strcpy_s(native.IPAddress, 16, asp15.m_pChar);
	    		}
	    		
	    		//Mac地址
	    		if (pParkedOrder->MacAddress != nullptr)
	    		{
	    			CAutoStrPtr asp16 = CAutoStrPtr(pParkedOrder->MacAddress);
	    			strcpy_s(native.MacAddress, 21, asp16.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqParkedOrderInsert(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 预埋撤单录入请求
	    	/// </summary>
	    	int TraderAdapter::ReqParkedOrderAction(CtpNetParkedOrderActionField^ pParkedOrderAction, int nRequestID)
	    	{
	    		if (pParkedOrderAction == nullptr)
    			{
	    			return m_pApi->ReqParkedOrderAction(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcParkedOrderActionField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pParkedOrderAction->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pParkedOrderAction->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pParkedOrderAction->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pParkedOrderAction->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//报单操作引用
	    		native.OrderActionRef = pParkedOrderAction->OrderActionRef;
			
	    		//报单引用
	    		if (pParkedOrderAction->OrderRef != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pParkedOrderAction->OrderRef);
	    			strcpy_s(native.OrderRef, 13, asp3.m_pChar);
	    		}
	    		
	    		//请求编号
	    		native.RequestID = pParkedOrderAction->RequestID;
			
	    		//前置编号
	    		native.FrontID = pParkedOrderAction->FrontID;
			
	    		//会话编号
	    		native.SessionID = pParkedOrderAction->SessionID;
			
	    		//交易所代码
	    		if (pParkedOrderAction->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pParkedOrderAction->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp4.m_pChar);
	    		}
	    		
	    		//报单编号
	    		if (pParkedOrderAction->OrderSysID != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pParkedOrderAction->OrderSysID);
	    			strcpy_s(native.OrderSysID, 21, asp5.m_pChar);
	    		}
	    		
	    		//操作标志
	    		native.ActionFlag = (Byte)pParkedOrderAction->ActionFlag;
			
	    		//价格
	    		native.LimitPrice = pParkedOrderAction->LimitPrice;
			
	    		//数量变化
	    		native.VolumeChange = pParkedOrderAction->VolumeChange;
			
	    		//用户代码
	    		if (pParkedOrderAction->UserID != nullptr)
	    		{
	    			CAutoStrPtr asp6 = CAutoStrPtr(pParkedOrderAction->UserID);
	    			strcpy_s(native.UserID, 16, asp6.m_pChar);
	    		}
	    		
	    		//合约代码
	    		if (pParkedOrderAction->InstrumentID != nullptr)
	    		{
	    			CAutoStrPtr asp7 = CAutoStrPtr(pParkedOrderAction->InstrumentID);
	    			strcpy_s(native.InstrumentID, 31, asp7.m_pChar);
	    		}
	    		
	    		//预埋撤单单编号
	    		if (pParkedOrderAction->ParkedOrderActionID != nullptr)
	    		{
	    			CAutoStrPtr asp8 = CAutoStrPtr(pParkedOrderAction->ParkedOrderActionID);
	    			strcpy_s(native.ParkedOrderActionID, 13, asp8.m_pChar);
	    		}
	    		
	    		//用户类型
	    		native.UserType = (Byte)pParkedOrderAction->UserType;
			
	    		//预埋撤单状态
	    		native.Status = (Byte)pParkedOrderAction->Status;
			
	    		//错误代码
	    		native.ErrorID = pParkedOrderAction->ErrorID;
			
	    		//错误信息
	    		if (pParkedOrderAction->ErrorMsg != nullptr)
	    		{
	    			CAutoStrPtr asp9 = CAutoStrPtr(pParkedOrderAction->ErrorMsg);
	    			strcpy_s(native.ErrorMsg, 81, asp9.m_pChar);
	    		}
	    		
	    		//投资单元代码
	    		if (pParkedOrderAction->InvestUnitID != nullptr)
	    		{
	    			CAutoStrPtr asp10 = CAutoStrPtr(pParkedOrderAction->InvestUnitID);
	    			strcpy_s(native.InvestUnitID, 17, asp10.m_pChar);
	    		}
	    		
	    		//IP地址
	    		if (pParkedOrderAction->IPAddress != nullptr)
	    		{
	    			CAutoStrPtr asp11 = CAutoStrPtr(pParkedOrderAction->IPAddress);
	    			strcpy_s(native.IPAddress, 16, asp11.m_pChar);
	    		}
	    		
	    		//Mac地址
	    		if (pParkedOrderAction->MacAddress != nullptr)
	    		{
	    			CAutoStrPtr asp12 = CAutoStrPtr(pParkedOrderAction->MacAddress);
	    			strcpy_s(native.MacAddress, 21, asp12.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqParkedOrderAction(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 报单操作请求
	    	/// </summary>
	    	int TraderAdapter::ReqOrderAction(CtpNetInputOrderActionField^ pInputOrderAction, int nRequestID)
	    	{
	    		if (pInputOrderAction == nullptr)
    			{
	    			return m_pApi->ReqOrderAction(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcInputOrderActionField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pInputOrderAction->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pInputOrderAction->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pInputOrderAction->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pInputOrderAction->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//报单操作引用
	    		native.OrderActionRef = pInputOrderAction->OrderActionRef;
			
	    		//报单引用
	    		if (pInputOrderAction->OrderRef != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pInputOrderAction->OrderRef);
	    			strcpy_s(native.OrderRef, 13, asp3.m_pChar);
	    		}
	    		
	    		//请求编号
	    		native.RequestID = pInputOrderAction->RequestID;
			
	    		//前置编号
	    		native.FrontID = pInputOrderAction->FrontID;
			
	    		//会话编号
	    		native.SessionID = pInputOrderAction->SessionID;
			
	    		//交易所代码
	    		if (pInputOrderAction->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pInputOrderAction->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp4.m_pChar);
	    		}
	    		
	    		//报单编号
	    		if (pInputOrderAction->OrderSysID != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pInputOrderAction->OrderSysID);
	    			strcpy_s(native.OrderSysID, 21, asp5.m_pChar);
	    		}
	    		
	    		//操作标志
	    		native.ActionFlag = (Byte)pInputOrderAction->ActionFlag;
			
	    		//价格
	    		native.LimitPrice = pInputOrderAction->LimitPrice;
			
	    		//数量变化
	    		native.VolumeChange = pInputOrderAction->VolumeChange;
			
	    		//用户代码
	    		if (pInputOrderAction->UserID != nullptr)
	    		{
	    			CAutoStrPtr asp6 = CAutoStrPtr(pInputOrderAction->UserID);
	    			strcpy_s(native.UserID, 16, asp6.m_pChar);
	    		}
	    		
	    		//合约代码
	    		if (pInputOrderAction->InstrumentID != nullptr)
	    		{
	    			CAutoStrPtr asp7 = CAutoStrPtr(pInputOrderAction->InstrumentID);
	    			strcpy_s(native.InstrumentID, 31, asp7.m_pChar);
	    		}
	    		
	    		//投资单元代码
	    		if (pInputOrderAction->InvestUnitID != nullptr)
	    		{
	    			CAutoStrPtr asp8 = CAutoStrPtr(pInputOrderAction->InvestUnitID);
	    			strcpy_s(native.InvestUnitID, 17, asp8.m_pChar);
	    		}
	    		
	    		//IP地址
	    		if (pInputOrderAction->IPAddress != nullptr)
	    		{
	    			CAutoStrPtr asp9 = CAutoStrPtr(pInputOrderAction->IPAddress);
	    			strcpy_s(native.IPAddress, 16, asp9.m_pChar);
	    		}
	    		
	    		//Mac地址
	    		if (pInputOrderAction->MacAddress != nullptr)
	    		{
	    			CAutoStrPtr asp10 = CAutoStrPtr(pInputOrderAction->MacAddress);
	    			strcpy_s(native.MacAddress, 21, asp10.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqOrderAction(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 查询最大报单数量请求
	    	/// </summary>
	    	int TraderAdapter::ReqQueryMaxOrderVolume(CtpNetQueryMaxOrderVolumeField^ pQueryMaxOrderVolume, int nRequestID)
	    	{
	    		if (pQueryMaxOrderVolume == nullptr)
    			{
	    			return m_pApi->ReqQueryMaxOrderVolume(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQueryMaxOrderVolumeField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQueryMaxOrderVolume->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQueryMaxOrderVolume->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pQueryMaxOrderVolume->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQueryMaxOrderVolume->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//合约代码
	    		if (pQueryMaxOrderVolume->InstrumentID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pQueryMaxOrderVolume->InstrumentID);
	    			strcpy_s(native.InstrumentID, 31, asp3.m_pChar);
	    		}
	    		
	    		//买卖方向
	    		native.Direction = (Byte)pQueryMaxOrderVolume->Direction;
			
	    		//开平标志
	    		native.OffsetFlag = (Byte)pQueryMaxOrderVolume->OffsetFlag;
			
	    		//投机套保标志
	    		native.HedgeFlag = (Byte)pQueryMaxOrderVolume->HedgeFlag;
			
	    		//最大允许报单数量
	    		native.MaxVolume = pQueryMaxOrderVolume->MaxVolume;
			
	    		//交易所代码
	    		if (pQueryMaxOrderVolume->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pQueryMaxOrderVolume->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp4.m_pChar);
	    		}
	    		
	    		//投资单元代码
	    		if (pQueryMaxOrderVolume->InvestUnitID != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pQueryMaxOrderVolume->InvestUnitID);
	    			strcpy_s(native.InvestUnitID, 17, asp5.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQueryMaxOrderVolume(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 投资者结算结果确认
	    	/// </summary>
	    	int TraderAdapter::ReqSettlementInfoConfirm(CtpNetSettlementInfoConfirmField^ pSettlementInfoConfirm, int nRequestID)
	    	{
	    		if (pSettlementInfoConfirm == nullptr)
    			{
	    			return m_pApi->ReqSettlementInfoConfirm(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcSettlementInfoConfirmField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pSettlementInfoConfirm->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pSettlementInfoConfirm->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pSettlementInfoConfirm->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pSettlementInfoConfirm->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//确认日期
	    		if (pSettlementInfoConfirm->ConfirmDate != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pSettlementInfoConfirm->ConfirmDate);
	    			strcpy_s(native.ConfirmDate, 9, asp3.m_pChar);
	    		}
	    		
	    		//确认时间
	    		if (pSettlementInfoConfirm->ConfirmTime != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pSettlementInfoConfirm->ConfirmTime);
	    			strcpy_s(native.ConfirmTime, 9, asp4.m_pChar);
	    		}
	    		
	    		//结算编号
	    		native.SettlementID = pSettlementInfoConfirm->SettlementID;
			
	    		//投资者帐号
	    		if (pSettlementInfoConfirm->AccountID != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pSettlementInfoConfirm->AccountID);
	    			strcpy_s(native.AccountID, 13, asp5.m_pChar);
	    		}
	    		
	    		//币种代码
	    		if (pSettlementInfoConfirm->CurrencyID != nullptr)
	    		{
	    			CAutoStrPtr asp6 = CAutoStrPtr(pSettlementInfoConfirm->CurrencyID);
	    			strcpy_s(native.CurrencyID, 4, asp6.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqSettlementInfoConfirm(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求删除预埋单
	    	/// </summary>
	    	int TraderAdapter::ReqRemoveParkedOrder(CtpNetRemoveParkedOrderField^ pRemoveParkedOrder, int nRequestID)
	    	{
	    		if (pRemoveParkedOrder == nullptr)
    			{
	    			return m_pApi->ReqRemoveParkedOrder(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcRemoveParkedOrderField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pRemoveParkedOrder->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pRemoveParkedOrder->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pRemoveParkedOrder->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pRemoveParkedOrder->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//预埋报单编号
	    		if (pRemoveParkedOrder->ParkedOrderID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pRemoveParkedOrder->ParkedOrderID);
	    			strcpy_s(native.ParkedOrderID, 13, asp3.m_pChar);
	    		}
	    		
	    		//投资单元代码
	    		if (pRemoveParkedOrder->InvestUnitID != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pRemoveParkedOrder->InvestUnitID);
	    			strcpy_s(native.InvestUnitID, 17, asp4.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqRemoveParkedOrder(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求删除预埋撤单
	    	/// </summary>
	    	int TraderAdapter::ReqRemoveParkedOrderAction(CtpNetRemoveParkedOrderActionField^ pRemoveParkedOrderAction, int nRequestID)
	    	{
	    		if (pRemoveParkedOrderAction == nullptr)
    			{
	    			return m_pApi->ReqRemoveParkedOrderAction(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcRemoveParkedOrderActionField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pRemoveParkedOrderAction->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pRemoveParkedOrderAction->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pRemoveParkedOrderAction->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pRemoveParkedOrderAction->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//预埋撤单编号
	    		if (pRemoveParkedOrderAction->ParkedOrderActionID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pRemoveParkedOrderAction->ParkedOrderActionID);
	    			strcpy_s(native.ParkedOrderActionID, 13, asp3.m_pChar);
	    		}
	    		
	    		//投资单元代码
	    		if (pRemoveParkedOrderAction->InvestUnitID != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pRemoveParkedOrderAction->InvestUnitID);
	    			strcpy_s(native.InvestUnitID, 17, asp4.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqRemoveParkedOrderAction(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 执行宣告录入请求
	    	/// </summary>
	    	int TraderAdapter::ReqExecOrderInsert(CtpNetInputExecOrderField^ pInputExecOrder, int nRequestID)
	    	{
	    		if (pInputExecOrder == nullptr)
    			{
	    			return m_pApi->ReqExecOrderInsert(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcInputExecOrderField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pInputExecOrder->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pInputExecOrder->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pInputExecOrder->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pInputExecOrder->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//合约代码
	    		if (pInputExecOrder->InstrumentID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pInputExecOrder->InstrumentID);
	    			strcpy_s(native.InstrumentID, 31, asp3.m_pChar);
	    		}
	    		
	    		//执行宣告引用
	    		if (pInputExecOrder->ExecOrderRef != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pInputExecOrder->ExecOrderRef);
	    			strcpy_s(native.ExecOrderRef, 13, asp4.m_pChar);
	    		}
	    		
	    		//用户代码
	    		if (pInputExecOrder->UserID != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pInputExecOrder->UserID);
	    			strcpy_s(native.UserID, 16, asp5.m_pChar);
	    		}
	    		
	    		//数量
	    		native.Volume = pInputExecOrder->Volume;
			
	    		//请求编号
	    		native.RequestID = pInputExecOrder->RequestID;
			
	    		//业务单元
	    		if (pInputExecOrder->BusinessUnit != nullptr)
	    		{
	    			CAutoStrPtr asp6 = CAutoStrPtr(pInputExecOrder->BusinessUnit);
	    			strcpy_s(native.BusinessUnit, 21, asp6.m_pChar);
	    		}
	    		
	    		//开平标志
	    		native.OffsetFlag = (Byte)pInputExecOrder->OffsetFlag;
			
	    		//投机套保标志
	    		native.HedgeFlag = (Byte)pInputExecOrder->HedgeFlag;
			
	    		//执行类型
	    		native.ActionType = (Byte)pInputExecOrder->ActionType;
			
	    		//保留头寸申请的持仓方向
	    		native.PosiDirection = (Byte)pInputExecOrder->PosiDirection;
			
	    		//期权行权后是否保留期货头寸的标记,该字段已废弃
	    		native.ReservePositionFlag = (Byte)pInputExecOrder->ReservePositionFlag;
			
	    		//期权行权后生成的头寸是否自动平仓
	    		native.CloseFlag = (Byte)pInputExecOrder->CloseFlag;
			
	    		//交易所代码
	    		if (pInputExecOrder->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp7 = CAutoStrPtr(pInputExecOrder->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp7.m_pChar);
	    		}
	    		
	    		//投资单元代码
	    		if (pInputExecOrder->InvestUnitID != nullptr)
	    		{
	    			CAutoStrPtr asp8 = CAutoStrPtr(pInputExecOrder->InvestUnitID);
	    			strcpy_s(native.InvestUnitID, 17, asp8.m_pChar);
	    		}
	    		
	    		//资金账号
	    		if (pInputExecOrder->AccountID != nullptr)
	    		{
	    			CAutoStrPtr asp9 = CAutoStrPtr(pInputExecOrder->AccountID);
	    			strcpy_s(native.AccountID, 13, asp9.m_pChar);
	    		}
	    		
	    		//币种代码
	    		if (pInputExecOrder->CurrencyID != nullptr)
	    		{
	    			CAutoStrPtr asp10 = CAutoStrPtr(pInputExecOrder->CurrencyID);
	    			strcpy_s(native.CurrencyID, 4, asp10.m_pChar);
	    		}
	    		
	    		//交易编码
	    		if (pInputExecOrder->ClientID != nullptr)
	    		{
	    			CAutoStrPtr asp11 = CAutoStrPtr(pInputExecOrder->ClientID);
	    			strcpy_s(native.ClientID, 11, asp11.m_pChar);
	    		}
	    		
	    		//IP地址
	    		if (pInputExecOrder->IPAddress != nullptr)
	    		{
	    			CAutoStrPtr asp12 = CAutoStrPtr(pInputExecOrder->IPAddress);
	    			strcpy_s(native.IPAddress, 16, asp12.m_pChar);
	    		}
	    		
	    		//Mac地址
	    		if (pInputExecOrder->MacAddress != nullptr)
	    		{
	    			CAutoStrPtr asp13 = CAutoStrPtr(pInputExecOrder->MacAddress);
	    			strcpy_s(native.MacAddress, 21, asp13.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqExecOrderInsert(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 执行宣告操作请求
	    	/// </summary>
	    	int TraderAdapter::ReqExecOrderAction(CtpNetInputExecOrderActionField^ pInputExecOrderAction, int nRequestID)
	    	{
	    		if (pInputExecOrderAction == nullptr)
    			{
	    			return m_pApi->ReqExecOrderAction(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcInputExecOrderActionField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pInputExecOrderAction->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pInputExecOrderAction->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pInputExecOrderAction->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pInputExecOrderAction->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//执行宣告操作引用
	    		native.ExecOrderActionRef = pInputExecOrderAction->ExecOrderActionRef;
			
	    		//执行宣告引用
	    		if (pInputExecOrderAction->ExecOrderRef != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pInputExecOrderAction->ExecOrderRef);
	    			strcpy_s(native.ExecOrderRef, 13, asp3.m_pChar);
	    		}
	    		
	    		//请求编号
	    		native.RequestID = pInputExecOrderAction->RequestID;
			
	    		//前置编号
	    		native.FrontID = pInputExecOrderAction->FrontID;
			
	    		//会话编号
	    		native.SessionID = pInputExecOrderAction->SessionID;
			
	    		//交易所代码
	    		if (pInputExecOrderAction->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pInputExecOrderAction->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp4.m_pChar);
	    		}
	    		
	    		//执行宣告操作编号
	    		if (pInputExecOrderAction->ExecOrderSysID != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pInputExecOrderAction->ExecOrderSysID);
	    			strcpy_s(native.ExecOrderSysID, 21, asp5.m_pChar);
	    		}
	    		
	    		//操作标志
	    		native.ActionFlag = (Byte)pInputExecOrderAction->ActionFlag;
			
	    		//用户代码
	    		if (pInputExecOrderAction->UserID != nullptr)
	    		{
	    			CAutoStrPtr asp6 = CAutoStrPtr(pInputExecOrderAction->UserID);
	    			strcpy_s(native.UserID, 16, asp6.m_pChar);
	    		}
	    		
	    		//合约代码
	    		if (pInputExecOrderAction->InstrumentID != nullptr)
	    		{
	    			CAutoStrPtr asp7 = CAutoStrPtr(pInputExecOrderAction->InstrumentID);
	    			strcpy_s(native.InstrumentID, 31, asp7.m_pChar);
	    		}
	    		
	    		//投资单元代码
	    		if (pInputExecOrderAction->InvestUnitID != nullptr)
	    		{
	    			CAutoStrPtr asp8 = CAutoStrPtr(pInputExecOrderAction->InvestUnitID);
	    			strcpy_s(native.InvestUnitID, 17, asp8.m_pChar);
	    		}
	    		
	    		//IP地址
	    		if (pInputExecOrderAction->IPAddress != nullptr)
	    		{
	    			CAutoStrPtr asp9 = CAutoStrPtr(pInputExecOrderAction->IPAddress);
	    			strcpy_s(native.IPAddress, 16, asp9.m_pChar);
	    		}
	    		
	    		//Mac地址
	    		if (pInputExecOrderAction->MacAddress != nullptr)
	    		{
	    			CAutoStrPtr asp10 = CAutoStrPtr(pInputExecOrderAction->MacAddress);
	    			strcpy_s(native.MacAddress, 21, asp10.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqExecOrderAction(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 询价录入请求
	    	/// </summary>
	    	int TraderAdapter::ReqForQuoteInsert(CtpNetInputForQuoteField^ pInputForQuote, int nRequestID)
	    	{
	    		if (pInputForQuote == nullptr)
    			{
	    			return m_pApi->ReqForQuoteInsert(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcInputForQuoteField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pInputForQuote->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pInputForQuote->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pInputForQuote->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pInputForQuote->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//合约代码
	    		if (pInputForQuote->InstrumentID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pInputForQuote->InstrumentID);
	    			strcpy_s(native.InstrumentID, 31, asp3.m_pChar);
	    		}
	    		
	    		//询价引用
	    		if (pInputForQuote->ForQuoteRef != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pInputForQuote->ForQuoteRef);
	    			strcpy_s(native.ForQuoteRef, 13, asp4.m_pChar);
	    		}
	    		
	    		//用户代码
	    		if (pInputForQuote->UserID != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pInputForQuote->UserID);
	    			strcpy_s(native.UserID, 16, asp5.m_pChar);
	    		}
	    		
	    		//交易所代码
	    		if (pInputForQuote->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp6 = CAutoStrPtr(pInputForQuote->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp6.m_pChar);
	    		}
	    		
	    		//投资单元代码
	    		if (pInputForQuote->InvestUnitID != nullptr)
	    		{
	    			CAutoStrPtr asp7 = CAutoStrPtr(pInputForQuote->InvestUnitID);
	    			strcpy_s(native.InvestUnitID, 17, asp7.m_pChar);
	    		}
	    		
	    		//IP地址
	    		if (pInputForQuote->IPAddress != nullptr)
	    		{
	    			CAutoStrPtr asp8 = CAutoStrPtr(pInputForQuote->IPAddress);
	    			strcpy_s(native.IPAddress, 16, asp8.m_pChar);
	    		}
	    		
	    		//Mac地址
	    		if (pInputForQuote->MacAddress != nullptr)
	    		{
	    			CAutoStrPtr asp9 = CAutoStrPtr(pInputForQuote->MacAddress);
	    			strcpy_s(native.MacAddress, 21, asp9.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqForQuoteInsert(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 报价录入请求
	    	/// </summary>
	    	int TraderAdapter::ReqQuoteInsert(CtpNetInputQuoteField^ pInputQuote, int nRequestID)
	    	{
	    		if (pInputQuote == nullptr)
    			{
	    			return m_pApi->ReqQuoteInsert(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcInputQuoteField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pInputQuote->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pInputQuote->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pInputQuote->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pInputQuote->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//合约代码
	    		if (pInputQuote->InstrumentID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pInputQuote->InstrumentID);
	    			strcpy_s(native.InstrumentID, 31, asp3.m_pChar);
	    		}
	    		
	    		//报价引用
	    		if (pInputQuote->QuoteRef != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pInputQuote->QuoteRef);
	    			strcpy_s(native.QuoteRef, 13, asp4.m_pChar);
	    		}
	    		
	    		//用户代码
	    		if (pInputQuote->UserID != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pInputQuote->UserID);
	    			strcpy_s(native.UserID, 16, asp5.m_pChar);
	    		}
	    		
	    		//卖价格
	    		native.AskPrice = pInputQuote->AskPrice;
			
	    		//买价格
	    		native.BidPrice = pInputQuote->BidPrice;
			
	    		//卖数量
	    		native.AskVolume = pInputQuote->AskVolume;
			
	    		//买数量
	    		native.BidVolume = pInputQuote->BidVolume;
			
	    		//请求编号
	    		native.RequestID = pInputQuote->RequestID;
			
	    		//业务单元
	    		if (pInputQuote->BusinessUnit != nullptr)
	    		{
	    			CAutoStrPtr asp6 = CAutoStrPtr(pInputQuote->BusinessUnit);
	    			strcpy_s(native.BusinessUnit, 21, asp6.m_pChar);
	    		}
	    		
	    		//卖开平标志
	    		native.AskOffsetFlag = (Byte)pInputQuote->AskOffsetFlag;
			
	    		//买开平标志
	    		native.BidOffsetFlag = (Byte)pInputQuote->BidOffsetFlag;
			
	    		//卖投机套保标志
	    		native.AskHedgeFlag = (Byte)pInputQuote->AskHedgeFlag;
			
	    		//买投机套保标志
	    		native.BidHedgeFlag = (Byte)pInputQuote->BidHedgeFlag;
			
	    		//衍生卖报单引用
	    		if (pInputQuote->AskOrderRef != nullptr)
	    		{
	    			CAutoStrPtr asp7 = CAutoStrPtr(pInputQuote->AskOrderRef);
	    			strcpy_s(native.AskOrderRef, 13, asp7.m_pChar);
	    		}
	    		
	    		//衍生买报单引用
	    		if (pInputQuote->BidOrderRef != nullptr)
	    		{
	    			CAutoStrPtr asp8 = CAutoStrPtr(pInputQuote->BidOrderRef);
	    			strcpy_s(native.BidOrderRef, 13, asp8.m_pChar);
	    		}
	    		
	    		//应价编号
	    		if (pInputQuote->ForQuoteSysID != nullptr)
	    		{
	    			CAutoStrPtr asp9 = CAutoStrPtr(pInputQuote->ForQuoteSysID);
	    			strcpy_s(native.ForQuoteSysID, 21, asp9.m_pChar);
	    		}
	    		
	    		//交易所代码
	    		if (pInputQuote->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp10 = CAutoStrPtr(pInputQuote->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp10.m_pChar);
	    		}
	    		
	    		//投资单元代码
	    		if (pInputQuote->InvestUnitID != nullptr)
	    		{
	    			CAutoStrPtr asp11 = CAutoStrPtr(pInputQuote->InvestUnitID);
	    			strcpy_s(native.InvestUnitID, 17, asp11.m_pChar);
	    		}
	    		
	    		//交易编码
	    		if (pInputQuote->ClientID != nullptr)
	    		{
	    			CAutoStrPtr asp12 = CAutoStrPtr(pInputQuote->ClientID);
	    			strcpy_s(native.ClientID, 11, asp12.m_pChar);
	    		}
	    		
	    		//IP地址
	    		if (pInputQuote->IPAddress != nullptr)
	    		{
	    			CAutoStrPtr asp13 = CAutoStrPtr(pInputQuote->IPAddress);
	    			strcpy_s(native.IPAddress, 16, asp13.m_pChar);
	    		}
	    		
	    		//Mac地址
	    		if (pInputQuote->MacAddress != nullptr)
	    		{
	    			CAutoStrPtr asp14 = CAutoStrPtr(pInputQuote->MacAddress);
	    			strcpy_s(native.MacAddress, 21, asp14.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQuoteInsert(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 报价操作请求
	    	/// </summary>
	    	int TraderAdapter::ReqQuoteAction(CtpNetInputQuoteActionField^ pInputQuoteAction, int nRequestID)
	    	{
	    		if (pInputQuoteAction == nullptr)
    			{
	    			return m_pApi->ReqQuoteAction(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcInputQuoteActionField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pInputQuoteAction->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pInputQuoteAction->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pInputQuoteAction->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pInputQuoteAction->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//报价操作引用
	    		native.QuoteActionRef = pInputQuoteAction->QuoteActionRef;
			
	    		//报价引用
	    		if (pInputQuoteAction->QuoteRef != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pInputQuoteAction->QuoteRef);
	    			strcpy_s(native.QuoteRef, 13, asp3.m_pChar);
	    		}
	    		
	    		//请求编号
	    		native.RequestID = pInputQuoteAction->RequestID;
			
	    		//前置编号
	    		native.FrontID = pInputQuoteAction->FrontID;
			
	    		//会话编号
	    		native.SessionID = pInputQuoteAction->SessionID;
			
	    		//交易所代码
	    		if (pInputQuoteAction->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pInputQuoteAction->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp4.m_pChar);
	    		}
	    		
	    		//报价操作编号
	    		if (pInputQuoteAction->QuoteSysID != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pInputQuoteAction->QuoteSysID);
	    			strcpy_s(native.QuoteSysID, 21, asp5.m_pChar);
	    		}
	    		
	    		//操作标志
	    		native.ActionFlag = (Byte)pInputQuoteAction->ActionFlag;
			
	    		//用户代码
	    		if (pInputQuoteAction->UserID != nullptr)
	    		{
	    			CAutoStrPtr asp6 = CAutoStrPtr(pInputQuoteAction->UserID);
	    			strcpy_s(native.UserID, 16, asp6.m_pChar);
	    		}
	    		
	    		//合约代码
	    		if (pInputQuoteAction->InstrumentID != nullptr)
	    		{
	    			CAutoStrPtr asp7 = CAutoStrPtr(pInputQuoteAction->InstrumentID);
	    			strcpy_s(native.InstrumentID, 31, asp7.m_pChar);
	    		}
	    		
	    		//投资单元代码
	    		if (pInputQuoteAction->InvestUnitID != nullptr)
	    		{
	    			CAutoStrPtr asp8 = CAutoStrPtr(pInputQuoteAction->InvestUnitID);
	    			strcpy_s(native.InvestUnitID, 17, asp8.m_pChar);
	    		}
	    		
	    		//交易编码
	    		if (pInputQuoteAction->ClientID != nullptr)
	    		{
	    			CAutoStrPtr asp9 = CAutoStrPtr(pInputQuoteAction->ClientID);
	    			strcpy_s(native.ClientID, 11, asp9.m_pChar);
	    		}
	    		
	    		//IP地址
	    		if (pInputQuoteAction->IPAddress != nullptr)
	    		{
	    			CAutoStrPtr asp10 = CAutoStrPtr(pInputQuoteAction->IPAddress);
	    			strcpy_s(native.IPAddress, 16, asp10.m_pChar);
	    		}
	    		
	    		//Mac地址
	    		if (pInputQuoteAction->MacAddress != nullptr)
	    		{
	    			CAutoStrPtr asp11 = CAutoStrPtr(pInputQuoteAction->MacAddress);
	    			strcpy_s(native.MacAddress, 21, asp11.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQuoteAction(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 批量报单操作请求
	    	/// </summary>
	    	int TraderAdapter::ReqBatchOrderAction(CtpNetInputBatchOrderActionField^ pInputBatchOrderAction, int nRequestID)
	    	{
	    		if (pInputBatchOrderAction == nullptr)
    			{
	    			return m_pApi->ReqBatchOrderAction(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcInputBatchOrderActionField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pInputBatchOrderAction->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pInputBatchOrderAction->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pInputBatchOrderAction->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pInputBatchOrderAction->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//报单操作引用
	    		native.OrderActionRef = pInputBatchOrderAction->OrderActionRef;
			
	    		//请求编号
	    		native.RequestID = pInputBatchOrderAction->RequestID;
			
	    		//前置编号
	    		native.FrontID = pInputBatchOrderAction->FrontID;
			
	    		//会话编号
	    		native.SessionID = pInputBatchOrderAction->SessionID;
			
	    		//交易所代码
	    		if (pInputBatchOrderAction->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pInputBatchOrderAction->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp3.m_pChar);
	    		}
	    		
	    		//用户代码
	    		if (pInputBatchOrderAction->UserID != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pInputBatchOrderAction->UserID);
	    			strcpy_s(native.UserID, 16, asp4.m_pChar);
	    		}
	    		
	    		//投资单元代码
	    		if (pInputBatchOrderAction->InvestUnitID != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pInputBatchOrderAction->InvestUnitID);
	    			strcpy_s(native.InvestUnitID, 17, asp5.m_pChar);
	    		}
	    		
	    		//IP地址
	    		if (pInputBatchOrderAction->IPAddress != nullptr)
	    		{
	    			CAutoStrPtr asp6 = CAutoStrPtr(pInputBatchOrderAction->IPAddress);
	    			strcpy_s(native.IPAddress, 16, asp6.m_pChar);
	    		}
	    		
	    		//Mac地址
	    		if (pInputBatchOrderAction->MacAddress != nullptr)
	    		{
	    			CAutoStrPtr asp7 = CAutoStrPtr(pInputBatchOrderAction->MacAddress);
	    			strcpy_s(native.MacAddress, 21, asp7.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqBatchOrderAction(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 期权自对冲录入请求
	    	/// </summary>
	    	int TraderAdapter::ReqOptionSelfCloseInsert(CtpNetInputOptionSelfCloseField^ pInputOptionSelfClose, int nRequestID)
	    	{
	    		if (pInputOptionSelfClose == nullptr)
    			{
	    			return m_pApi->ReqOptionSelfCloseInsert(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcInputOptionSelfCloseField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pInputOptionSelfClose->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pInputOptionSelfClose->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pInputOptionSelfClose->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pInputOptionSelfClose->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//合约代码
	    		if (pInputOptionSelfClose->InstrumentID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pInputOptionSelfClose->InstrumentID);
	    			strcpy_s(native.InstrumentID, 31, asp3.m_pChar);
	    		}
	    		
	    		//期权自对冲引用
	    		if (pInputOptionSelfClose->OptionSelfCloseRef != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pInputOptionSelfClose->OptionSelfCloseRef);
	    			strcpy_s(native.OptionSelfCloseRef, 13, asp4.m_pChar);
	    		}
	    		
	    		//用户代码
	    		if (pInputOptionSelfClose->UserID != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pInputOptionSelfClose->UserID);
	    			strcpy_s(native.UserID, 16, asp5.m_pChar);
	    		}
	    		
	    		//数量
	    		native.Volume = pInputOptionSelfClose->Volume;
			
	    		//请求编号
	    		native.RequestID = pInputOptionSelfClose->RequestID;
			
	    		//业务单元
	    		if (pInputOptionSelfClose->BusinessUnit != nullptr)
	    		{
	    			CAutoStrPtr asp6 = CAutoStrPtr(pInputOptionSelfClose->BusinessUnit);
	    			strcpy_s(native.BusinessUnit, 21, asp6.m_pChar);
	    		}
	    		
	    		//投机套保标志
	    		native.HedgeFlag = (Byte)pInputOptionSelfClose->HedgeFlag;
			
	    		//期权行权的头寸是否自对冲
	    		native.OptSelfCloseFlag = (Byte)pInputOptionSelfClose->OptSelfCloseFlag;
			
	    		//交易所代码
	    		if (pInputOptionSelfClose->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp7 = CAutoStrPtr(pInputOptionSelfClose->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp7.m_pChar);
	    		}
	    		
	    		//投资单元代码
	    		if (pInputOptionSelfClose->InvestUnitID != nullptr)
	    		{
	    			CAutoStrPtr asp8 = CAutoStrPtr(pInputOptionSelfClose->InvestUnitID);
	    			strcpy_s(native.InvestUnitID, 17, asp8.m_pChar);
	    		}
	    		
	    		//资金账号
	    		if (pInputOptionSelfClose->AccountID != nullptr)
	    		{
	    			CAutoStrPtr asp9 = CAutoStrPtr(pInputOptionSelfClose->AccountID);
	    			strcpy_s(native.AccountID, 13, asp9.m_pChar);
	    		}
	    		
	    		//币种代码
	    		if (pInputOptionSelfClose->CurrencyID != nullptr)
	    		{
	    			CAutoStrPtr asp10 = CAutoStrPtr(pInputOptionSelfClose->CurrencyID);
	    			strcpy_s(native.CurrencyID, 4, asp10.m_pChar);
	    		}
	    		
	    		//交易编码
	    		if (pInputOptionSelfClose->ClientID != nullptr)
	    		{
	    			CAutoStrPtr asp11 = CAutoStrPtr(pInputOptionSelfClose->ClientID);
	    			strcpy_s(native.ClientID, 11, asp11.m_pChar);
	    		}
	    		
	    		//IP地址
	    		if (pInputOptionSelfClose->IPAddress != nullptr)
	    		{
	    			CAutoStrPtr asp12 = CAutoStrPtr(pInputOptionSelfClose->IPAddress);
	    			strcpy_s(native.IPAddress, 16, asp12.m_pChar);
	    		}
	    		
	    		//Mac地址
	    		if (pInputOptionSelfClose->MacAddress != nullptr)
	    		{
	    			CAutoStrPtr asp13 = CAutoStrPtr(pInputOptionSelfClose->MacAddress);
	    			strcpy_s(native.MacAddress, 21, asp13.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqOptionSelfCloseInsert(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 期权自对冲操作请求
	    	/// </summary>
	    	int TraderAdapter::ReqOptionSelfCloseAction(CtpNetInputOptionSelfCloseActionField^ pInputOptionSelfCloseAction, int nRequestID)
	    	{
	    		if (pInputOptionSelfCloseAction == nullptr)
    			{
	    			return m_pApi->ReqOptionSelfCloseAction(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcInputOptionSelfCloseActionField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pInputOptionSelfCloseAction->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pInputOptionSelfCloseAction->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pInputOptionSelfCloseAction->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pInputOptionSelfCloseAction->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//期权自对冲操作引用
	    		native.OptionSelfCloseActionRef = pInputOptionSelfCloseAction->OptionSelfCloseActionRef;
			
	    		//期权自对冲引用
	    		if (pInputOptionSelfCloseAction->OptionSelfCloseRef != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pInputOptionSelfCloseAction->OptionSelfCloseRef);
	    			strcpy_s(native.OptionSelfCloseRef, 13, asp3.m_pChar);
	    		}
	    		
	    		//请求编号
	    		native.RequestID = pInputOptionSelfCloseAction->RequestID;
			
	    		//前置编号
	    		native.FrontID = pInputOptionSelfCloseAction->FrontID;
			
	    		//会话编号
	    		native.SessionID = pInputOptionSelfCloseAction->SessionID;
			
	    		//交易所代码
	    		if (pInputOptionSelfCloseAction->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pInputOptionSelfCloseAction->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp4.m_pChar);
	    		}
	    		
	    		//期权自对冲操作编号
	    		if (pInputOptionSelfCloseAction->OptionSelfCloseSysID != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pInputOptionSelfCloseAction->OptionSelfCloseSysID);
	    			strcpy_s(native.OptionSelfCloseSysID, 21, asp5.m_pChar);
	    		}
	    		
	    		//操作标志
	    		native.ActionFlag = (Byte)pInputOptionSelfCloseAction->ActionFlag;
			
	    		//用户代码
	    		if (pInputOptionSelfCloseAction->UserID != nullptr)
	    		{
	    			CAutoStrPtr asp6 = CAutoStrPtr(pInputOptionSelfCloseAction->UserID);
	    			strcpy_s(native.UserID, 16, asp6.m_pChar);
	    		}
	    		
	    		//合约代码
	    		if (pInputOptionSelfCloseAction->InstrumentID != nullptr)
	    		{
	    			CAutoStrPtr asp7 = CAutoStrPtr(pInputOptionSelfCloseAction->InstrumentID);
	    			strcpy_s(native.InstrumentID, 31, asp7.m_pChar);
	    		}
	    		
	    		//投资单元代码
	    		if (pInputOptionSelfCloseAction->InvestUnitID != nullptr)
	    		{
	    			CAutoStrPtr asp8 = CAutoStrPtr(pInputOptionSelfCloseAction->InvestUnitID);
	    			strcpy_s(native.InvestUnitID, 17, asp8.m_pChar);
	    		}
	    		
	    		//IP地址
	    		if (pInputOptionSelfCloseAction->IPAddress != nullptr)
	    		{
	    			CAutoStrPtr asp9 = CAutoStrPtr(pInputOptionSelfCloseAction->IPAddress);
	    			strcpy_s(native.IPAddress, 16, asp9.m_pChar);
	    		}
	    		
	    		//Mac地址
	    		if (pInputOptionSelfCloseAction->MacAddress != nullptr)
	    		{
	    			CAutoStrPtr asp10 = CAutoStrPtr(pInputOptionSelfCloseAction->MacAddress);
	    			strcpy_s(native.MacAddress, 21, asp10.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqOptionSelfCloseAction(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 申请组合录入请求
	    	/// </summary>
	    	int TraderAdapter::ReqCombActionInsert(CtpNetInputCombActionField^ pInputCombAction, int nRequestID)
	    	{
	    		if (pInputCombAction == nullptr)
    			{
	    			return m_pApi->ReqCombActionInsert(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcInputCombActionField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pInputCombAction->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pInputCombAction->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pInputCombAction->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pInputCombAction->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//合约代码
	    		if (pInputCombAction->InstrumentID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pInputCombAction->InstrumentID);
	    			strcpy_s(native.InstrumentID, 31, asp3.m_pChar);
	    		}
	    		
	    		//组合引用
	    		if (pInputCombAction->CombActionRef != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pInputCombAction->CombActionRef);
	    			strcpy_s(native.CombActionRef, 13, asp4.m_pChar);
	    		}
	    		
	    		//用户代码
	    		if (pInputCombAction->UserID != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pInputCombAction->UserID);
	    			strcpy_s(native.UserID, 16, asp5.m_pChar);
	    		}
	    		
	    		//买卖方向
	    		native.Direction = (Byte)pInputCombAction->Direction;
			
	    		//数量
	    		native.Volume = pInputCombAction->Volume;
			
	    		//组合指令方向
	    		native.CombDirection = (Byte)pInputCombAction->CombDirection;
			
	    		//投机套保标志
	    		native.HedgeFlag = (Byte)pInputCombAction->HedgeFlag;
			
	    		//交易所代码
	    		if (pInputCombAction->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp6 = CAutoStrPtr(pInputCombAction->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp6.m_pChar);
	    		}
	    		
	    		//IP地址
	    		if (pInputCombAction->IPAddress != nullptr)
	    		{
	    			CAutoStrPtr asp7 = CAutoStrPtr(pInputCombAction->IPAddress);
	    			strcpy_s(native.IPAddress, 16, asp7.m_pChar);
	    		}
	    		
	    		//Mac地址
	    		if (pInputCombAction->MacAddress != nullptr)
	    		{
	    			CAutoStrPtr asp8 = CAutoStrPtr(pInputCombAction->MacAddress);
	    			strcpy_s(native.MacAddress, 21, asp8.m_pChar);
	    		}
	    		
	    		//投资单元代码
	    		if (pInputCombAction->InvestUnitID != nullptr)
	    		{
	    			CAutoStrPtr asp9 = CAutoStrPtr(pInputCombAction->InvestUnitID);
	    			strcpy_s(native.InvestUnitID, 17, asp9.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqCombActionInsert(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询报单
	    	/// </summary>
	    	int TraderAdapter::ReqQryOrder(CtpNetQryOrderField^ pQryOrder, int nRequestID)
	    	{
	    		if (pQryOrder == nullptr)
    			{
	    			return m_pApi->ReqQryOrder(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryOrderField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQryOrder->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryOrder->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pQryOrder->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryOrder->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//合约代码
	    		if (pQryOrder->InstrumentID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pQryOrder->InstrumentID);
	    			strcpy_s(native.InstrumentID, 31, asp3.m_pChar);
	    		}
	    		
	    		//交易所代码
	    		if (pQryOrder->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pQryOrder->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp4.m_pChar);
	    		}
	    		
	    		//报单编号
	    		if (pQryOrder->OrderSysID != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pQryOrder->OrderSysID);
	    			strcpy_s(native.OrderSysID, 21, asp5.m_pChar);
	    		}
	    		
	    		//开始时间
	    		if (pQryOrder->InsertTimeStart != nullptr)
	    		{
	    			CAutoStrPtr asp6 = CAutoStrPtr(pQryOrder->InsertTimeStart);
	    			strcpy_s(native.InsertTimeStart, 9, asp6.m_pChar);
	    		}
	    		
	    		//结束时间
	    		if (pQryOrder->InsertTimeEnd != nullptr)
	    		{
	    			CAutoStrPtr asp7 = CAutoStrPtr(pQryOrder->InsertTimeEnd);
	    			strcpy_s(native.InsertTimeEnd, 9, asp7.m_pChar);
	    		}
	    		
	    		//投资单元代码
	    		if (pQryOrder->InvestUnitID != nullptr)
	    		{
	    			CAutoStrPtr asp8 = CAutoStrPtr(pQryOrder->InvestUnitID);
	    			strcpy_s(native.InvestUnitID, 17, asp8.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryOrder(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询成交
	    	/// </summary>
	    	int TraderAdapter::ReqQryTrade(CtpNetQryTradeField^ pQryTrade, int nRequestID)
	    	{
	    		if (pQryTrade == nullptr)
    			{
	    			return m_pApi->ReqQryTrade(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryTradeField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQryTrade->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryTrade->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pQryTrade->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryTrade->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//合约代码
	    		if (pQryTrade->InstrumentID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pQryTrade->InstrumentID);
	    			strcpy_s(native.InstrumentID, 31, asp3.m_pChar);
	    		}
	    		
	    		//交易所代码
	    		if (pQryTrade->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pQryTrade->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp4.m_pChar);
	    		}
	    		
	    		//成交编号
	    		if (pQryTrade->TradeID != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pQryTrade->TradeID);
	    			strcpy_s(native.TradeID, 21, asp5.m_pChar);
	    		}
	    		
	    		//开始时间
	    		if (pQryTrade->TradeTimeStart != nullptr)
	    		{
	    			CAutoStrPtr asp6 = CAutoStrPtr(pQryTrade->TradeTimeStart);
	    			strcpy_s(native.TradeTimeStart, 9, asp6.m_pChar);
	    		}
	    		
	    		//结束时间
	    		if (pQryTrade->TradeTimeEnd != nullptr)
	    		{
	    			CAutoStrPtr asp7 = CAutoStrPtr(pQryTrade->TradeTimeEnd);
	    			strcpy_s(native.TradeTimeEnd, 9, asp7.m_pChar);
	    		}
	    		
	    		//投资单元代码
	    		if (pQryTrade->InvestUnitID != nullptr)
	    		{
	    			CAutoStrPtr asp8 = CAutoStrPtr(pQryTrade->InvestUnitID);
	    			strcpy_s(native.InvestUnitID, 17, asp8.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryTrade(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询投资者持仓
	    	/// </summary>
	    	int TraderAdapter::ReqQryInvestorPosition(CtpNetQryInvestorPositionField^ pQryInvestorPosition, int nRequestID)
	    	{
	    		if (pQryInvestorPosition == nullptr)
    			{
	    			return m_pApi->ReqQryInvestorPosition(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryInvestorPositionField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQryInvestorPosition->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryInvestorPosition->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pQryInvestorPosition->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryInvestorPosition->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//合约代码
	    		if (pQryInvestorPosition->InstrumentID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pQryInvestorPosition->InstrumentID);
	    			strcpy_s(native.InstrumentID, 31, asp3.m_pChar);
	    		}
	    		
	    		//交易所代码
	    		if (pQryInvestorPosition->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pQryInvestorPosition->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp4.m_pChar);
	    		}
	    		
	    		//投资单元代码
	    		if (pQryInvestorPosition->InvestUnitID != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pQryInvestorPosition->InvestUnitID);
	    			strcpy_s(native.InvestUnitID, 17, asp5.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryInvestorPosition(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询资金账户
	    	/// </summary>
	    	int TraderAdapter::ReqQryTradingAccount(CtpNetQryTradingAccountField^ pQryTradingAccount, int nRequestID)
	    	{
	    		if (pQryTradingAccount == nullptr)
    			{
	    			return m_pApi->ReqQryTradingAccount(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryTradingAccountField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQryTradingAccount->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryTradingAccount->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pQryTradingAccount->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryTradingAccount->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//币种代码
	    		if (pQryTradingAccount->CurrencyID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pQryTradingAccount->CurrencyID);
	    			strcpy_s(native.CurrencyID, 4, asp3.m_pChar);
	    		}
	    		
	    		//业务类型
	    		native.BizType = (Byte)pQryTradingAccount->BizType;
			
	    		//投资者帐号
	    		if (pQryTradingAccount->AccountID != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pQryTradingAccount->AccountID);
	    			strcpy_s(native.AccountID, 13, asp4.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryTradingAccount(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询投资者
	    	/// </summary>
	    	int TraderAdapter::ReqQryInvestor(CtpNetQryInvestorField^ pQryInvestor, int nRequestID)
	    	{
	    		if (pQryInvestor == nullptr)
    			{
	    			return m_pApi->ReqQryInvestor(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryInvestorField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQryInvestor->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryInvestor->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pQryInvestor->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryInvestor->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryInvestor(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询交易编码
	    	/// </summary>
	    	int TraderAdapter::ReqQryTradingCode(CtpNetQryTradingCodeField^ pQryTradingCode, int nRequestID)
	    	{
	    		if (pQryTradingCode == nullptr)
    			{
	    			return m_pApi->ReqQryTradingCode(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryTradingCodeField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQryTradingCode->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryTradingCode->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pQryTradingCode->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryTradingCode->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//交易所代码
	    		if (pQryTradingCode->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pQryTradingCode->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp3.m_pChar);
	    		}
	    		
	    		//客户代码
	    		if (pQryTradingCode->ClientID != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pQryTradingCode->ClientID);
	    			strcpy_s(native.ClientID, 11, asp4.m_pChar);
	    		}
	    		
	    		//交易编码类型
	    		native.ClientIDType = (Byte)pQryTradingCode->ClientIDType;
			
	    		//投资单元代码
	    		if (pQryTradingCode->InvestUnitID != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pQryTradingCode->InvestUnitID);
	    			strcpy_s(native.InvestUnitID, 17, asp5.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryTradingCode(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询合约保证金率
	    	/// </summary>
	    	int TraderAdapter::ReqQryInstrumentMarginRate(CtpNetQryInstrumentMarginRateField^ pQryInstrumentMarginRate, int nRequestID)
	    	{
	    		if (pQryInstrumentMarginRate == nullptr)
    			{
	    			return m_pApi->ReqQryInstrumentMarginRate(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryInstrumentMarginRateField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQryInstrumentMarginRate->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryInstrumentMarginRate->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pQryInstrumentMarginRate->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryInstrumentMarginRate->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//合约代码
	    		if (pQryInstrumentMarginRate->InstrumentID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pQryInstrumentMarginRate->InstrumentID);
	    			strcpy_s(native.InstrumentID, 31, asp3.m_pChar);
	    		}
	    		
	    		//投机套保标志
	    		native.HedgeFlag = (Byte)pQryInstrumentMarginRate->HedgeFlag;
			
	    		//交易所代码
	    		if (pQryInstrumentMarginRate->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pQryInstrumentMarginRate->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp4.m_pChar);
	    		}
	    		
	    		//投资单元代码
	    		if (pQryInstrumentMarginRate->InvestUnitID != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pQryInstrumentMarginRate->InvestUnitID);
	    			strcpy_s(native.InvestUnitID, 17, asp5.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryInstrumentMarginRate(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询合约手续费率
	    	/// </summary>
	    	int TraderAdapter::ReqQryInstrumentCommissionRate(CtpNetQryInstrumentCommissionRateField^ pQryInstrumentCommissionRate, int nRequestID)
	    	{
	    		if (pQryInstrumentCommissionRate == nullptr)
    			{
	    			return m_pApi->ReqQryInstrumentCommissionRate(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryInstrumentCommissionRateField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQryInstrumentCommissionRate->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryInstrumentCommissionRate->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pQryInstrumentCommissionRate->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryInstrumentCommissionRate->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//合约代码
	    		if (pQryInstrumentCommissionRate->InstrumentID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pQryInstrumentCommissionRate->InstrumentID);
	    			strcpy_s(native.InstrumentID, 31, asp3.m_pChar);
	    		}
	    		
	    		//交易所代码
	    		if (pQryInstrumentCommissionRate->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pQryInstrumentCommissionRate->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp4.m_pChar);
	    		}
	    		
	    		//投资单元代码
	    		if (pQryInstrumentCommissionRate->InvestUnitID != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pQryInstrumentCommissionRate->InvestUnitID);
	    			strcpy_s(native.InvestUnitID, 17, asp5.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryInstrumentCommissionRate(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询交易所
	    	/// </summary>
	    	int TraderAdapter::ReqQryExchange(CtpNetQryExchangeField^ pQryExchange, int nRequestID)
	    	{
	    		if (pQryExchange == nullptr)
    			{
	    			return m_pApi->ReqQryExchange(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryExchangeField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//交易所代码
	    		if (pQryExchange->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryExchange->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp1.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryExchange(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询产品
	    	/// </summary>
	    	int TraderAdapter::ReqQryProduct(CtpNetQryProductField^ pQryProduct, int nRequestID)
	    	{
	    		if (pQryProduct == nullptr)
    			{
	    			return m_pApi->ReqQryProduct(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryProductField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//产品代码
	    		if (pQryProduct->ProductID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryProduct->ProductID);
	    			strcpy_s(native.ProductID, 31, asp1.m_pChar);
	    		}
	    		
	    		//产品类型
	    		native.ProductClass = (Byte)pQryProduct->ProductClass;
			
	    		//交易所代码
	    		if (pQryProduct->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryProduct->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp2.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryProduct(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询合约
	    	/// </summary>
	    	int TraderAdapter::ReqQryInstrument(CtpNetQryInstrumentField^ pQryInstrument, int nRequestID)
	    	{
	    		if (pQryInstrument == nullptr)
    			{
	    			return m_pApi->ReqQryInstrument(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryInstrumentField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//合约代码
	    		if (pQryInstrument->InstrumentID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryInstrument->InstrumentID);
	    			strcpy_s(native.InstrumentID, 31, asp1.m_pChar);
	    		}
	    		
	    		//交易所代码
	    		if (pQryInstrument->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryInstrument->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp2.m_pChar);
	    		}
	    		
	    		//合约在交易所的代码
	    		if (pQryInstrument->ExchangeInstID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pQryInstrument->ExchangeInstID);
	    			strcpy_s(native.ExchangeInstID, 31, asp3.m_pChar);
	    		}
	    		
	    		//产品代码
	    		if (pQryInstrument->ProductID != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pQryInstrument->ProductID);
	    			strcpy_s(native.ProductID, 31, asp4.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryInstrument(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询行情
	    	/// </summary>
	    	int TraderAdapter::ReqQryDepthMarketData(CtpNetQryDepthMarketDataField^ pQryDepthMarketData, int nRequestID)
	    	{
	    		if (pQryDepthMarketData == nullptr)
    			{
	    			return m_pApi->ReqQryDepthMarketData(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryDepthMarketDataField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//合约代码
	    		if (pQryDepthMarketData->InstrumentID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryDepthMarketData->InstrumentID);
	    			strcpy_s(native.InstrumentID, 31, asp1.m_pChar);
	    		}
	    		
	    		//交易所代码
	    		if (pQryDepthMarketData->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryDepthMarketData->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp2.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryDepthMarketData(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询投资者结算结果
	    	/// </summary>
	    	int TraderAdapter::ReqQrySettlementInfo(CtpNetQrySettlementInfoField^ pQrySettlementInfo, int nRequestID)
	    	{
	    		if (pQrySettlementInfo == nullptr)
    			{
	    			return m_pApi->ReqQrySettlementInfo(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQrySettlementInfoField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQrySettlementInfo->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQrySettlementInfo->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pQrySettlementInfo->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQrySettlementInfo->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//交易日
	    		if (pQrySettlementInfo->TradingDay != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pQrySettlementInfo->TradingDay);
	    			strcpy_s(native.TradingDay, 9, asp3.m_pChar);
	    		}
	    		
	    		//投资者帐号
	    		if (pQrySettlementInfo->AccountID != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pQrySettlementInfo->AccountID);
	    			strcpy_s(native.AccountID, 13, asp4.m_pChar);
	    		}
	    		
	    		//币种代码
	    		if (pQrySettlementInfo->CurrencyID != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pQrySettlementInfo->CurrencyID);
	    			strcpy_s(native.CurrencyID, 4, asp5.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQrySettlementInfo(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询转帐银行
	    	/// </summary>
	    	int TraderAdapter::ReqQryTransferBank(CtpNetQryTransferBankField^ pQryTransferBank, int nRequestID)
	    	{
	    		if (pQryTransferBank == nullptr)
    			{
	    			return m_pApi->ReqQryTransferBank(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryTransferBankField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//银行代码
	    		if (pQryTransferBank->BankID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryTransferBank->BankID);
	    			strcpy_s(native.BankID, 4, asp1.m_pChar);
	    		}
	    		
	    		//银行分中心代码
	    		if (pQryTransferBank->BankBrchID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryTransferBank->BankBrchID);
	    			strcpy_s(native.BankBrchID, 5, asp2.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryTransferBank(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询投资者持仓明细
	    	/// </summary>
	    	int TraderAdapter::ReqQryInvestorPositionDetail(CtpNetQryInvestorPositionDetailField^ pQryInvestorPositionDetail, int nRequestID)
	    	{
	    		if (pQryInvestorPositionDetail == nullptr)
    			{
	    			return m_pApi->ReqQryInvestorPositionDetail(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryInvestorPositionDetailField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQryInvestorPositionDetail->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryInvestorPositionDetail->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pQryInvestorPositionDetail->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryInvestorPositionDetail->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//合约代码
	    		if (pQryInvestorPositionDetail->InstrumentID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pQryInvestorPositionDetail->InstrumentID);
	    			strcpy_s(native.InstrumentID, 31, asp3.m_pChar);
	    		}
	    		
	    		//交易所代码
	    		if (pQryInvestorPositionDetail->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pQryInvestorPositionDetail->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp4.m_pChar);
	    		}
	    		
	    		//投资单元代码
	    		if (pQryInvestorPositionDetail->InvestUnitID != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pQryInvestorPositionDetail->InvestUnitID);
	    			strcpy_s(native.InvestUnitID, 17, asp5.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryInvestorPositionDetail(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询客户通知
	    	/// </summary>
	    	int TraderAdapter::ReqQryNotice(CtpNetQryNoticeField^ pQryNotice, int nRequestID)
	    	{
	    		if (pQryNotice == nullptr)
    			{
	    			return m_pApi->ReqQryNotice(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryNoticeField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQryNotice->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryNotice->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryNotice(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询结算信息确认
	    	/// </summary>
	    	int TraderAdapter::ReqQrySettlementInfoConfirm(CtpNetQrySettlementInfoConfirmField^ pQrySettlementInfoConfirm, int nRequestID)
	    	{
	    		if (pQrySettlementInfoConfirm == nullptr)
    			{
	    			return m_pApi->ReqQrySettlementInfoConfirm(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQrySettlementInfoConfirmField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQrySettlementInfoConfirm->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQrySettlementInfoConfirm->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pQrySettlementInfoConfirm->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQrySettlementInfoConfirm->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//投资者帐号
	    		if (pQrySettlementInfoConfirm->AccountID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pQrySettlementInfoConfirm->AccountID);
	    			strcpy_s(native.AccountID, 13, asp3.m_pChar);
	    		}
	    		
	    		//币种代码
	    		if (pQrySettlementInfoConfirm->CurrencyID != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pQrySettlementInfoConfirm->CurrencyID);
	    			strcpy_s(native.CurrencyID, 4, asp4.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQrySettlementInfoConfirm(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询投资者持仓明细
	    	/// </summary>
	    	int TraderAdapter::ReqQryInvestorPositionCombineDetail(CtpNetQryInvestorPositionCombineDetailField^ pQryInvestorPositionCombineDetail, int nRequestID)
	    	{
	    		if (pQryInvestorPositionCombineDetail == nullptr)
    			{
	    			return m_pApi->ReqQryInvestorPositionCombineDetail(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryInvestorPositionCombineDetailField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQryInvestorPositionCombineDetail->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryInvestorPositionCombineDetail->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pQryInvestorPositionCombineDetail->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryInvestorPositionCombineDetail->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//组合持仓合约编码
	    		if (pQryInvestorPositionCombineDetail->CombInstrumentID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pQryInvestorPositionCombineDetail->CombInstrumentID);
	    			strcpy_s(native.CombInstrumentID, 31, asp3.m_pChar);
	    		}
	    		
	    		//交易所代码
	    		if (pQryInvestorPositionCombineDetail->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pQryInvestorPositionCombineDetail->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp4.m_pChar);
	    		}
	    		
	    		//投资单元代码
	    		if (pQryInvestorPositionCombineDetail->InvestUnitID != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pQryInvestorPositionCombineDetail->InvestUnitID);
	    			strcpy_s(native.InvestUnitID, 17, asp5.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryInvestorPositionCombineDetail(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询保证金监管系统经纪公司资金账户密钥
	    	/// </summary>
	    	int TraderAdapter::ReqQryCFMMCTradingAccountKey(CtpNetQryCFMMCTradingAccountKeyField^ pQryCFMMCTradingAccountKey, int nRequestID)
	    	{
	    		if (pQryCFMMCTradingAccountKey == nullptr)
    			{
	    			return m_pApi->ReqQryCFMMCTradingAccountKey(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryCFMMCTradingAccountKeyField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQryCFMMCTradingAccountKey->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryCFMMCTradingAccountKey->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pQryCFMMCTradingAccountKey->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryCFMMCTradingAccountKey->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryCFMMCTradingAccountKey(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询仓单折抵信息
	    	/// </summary>
	    	int TraderAdapter::ReqQryEWarrantOffset(CtpNetQryEWarrantOffsetField^ pQryEWarrantOffset, int nRequestID)
	    	{
	    		if (pQryEWarrantOffset == nullptr)
    			{
	    			return m_pApi->ReqQryEWarrantOffset(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryEWarrantOffsetField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQryEWarrantOffset->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryEWarrantOffset->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pQryEWarrantOffset->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryEWarrantOffset->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//交易所代码
	    		if (pQryEWarrantOffset->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pQryEWarrantOffset->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp3.m_pChar);
	    		}
	    		
	    		//合约代码
	    		if (pQryEWarrantOffset->InstrumentID != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pQryEWarrantOffset->InstrumentID);
	    			strcpy_s(native.InstrumentID, 31, asp4.m_pChar);
	    		}
	    		
	    		//投资单元代码
	    		if (pQryEWarrantOffset->InvestUnitID != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pQryEWarrantOffset->InvestUnitID);
	    			strcpy_s(native.InvestUnitID, 17, asp5.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryEWarrantOffset(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询投资者品种/跨品种保证金
	    	/// </summary>
	    	int TraderAdapter::ReqQryInvestorProductGroupMargin(CtpNetQryInvestorProductGroupMarginField^ pQryInvestorProductGroupMargin, int nRequestID)
	    	{
	    		if (pQryInvestorProductGroupMargin == nullptr)
    			{
	    			return m_pApi->ReqQryInvestorProductGroupMargin(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryInvestorProductGroupMarginField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQryInvestorProductGroupMargin->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryInvestorProductGroupMargin->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pQryInvestorProductGroupMargin->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryInvestorProductGroupMargin->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//品种/跨品种标示
	    		if (pQryInvestorProductGroupMargin->ProductGroupID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pQryInvestorProductGroupMargin->ProductGroupID);
	    			strcpy_s(native.ProductGroupID, 31, asp3.m_pChar);
	    		}
	    		
	    		//投机套保标志
	    		native.HedgeFlag = (Byte)pQryInvestorProductGroupMargin->HedgeFlag;
			
	    		//交易所代码
	    		if (pQryInvestorProductGroupMargin->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pQryInvestorProductGroupMargin->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp4.m_pChar);
	    		}
	    		
	    		//投资单元代码
	    		if (pQryInvestorProductGroupMargin->InvestUnitID != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pQryInvestorProductGroupMargin->InvestUnitID);
	    			strcpy_s(native.InvestUnitID, 17, asp5.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryInvestorProductGroupMargin(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询交易所保证金率
	    	/// </summary>
	    	int TraderAdapter::ReqQryExchangeMarginRate(CtpNetQryExchangeMarginRateField^ pQryExchangeMarginRate, int nRequestID)
	    	{
	    		if (pQryExchangeMarginRate == nullptr)
    			{
	    			return m_pApi->ReqQryExchangeMarginRate(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryExchangeMarginRateField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQryExchangeMarginRate->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryExchangeMarginRate->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//合约代码
	    		if (pQryExchangeMarginRate->InstrumentID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryExchangeMarginRate->InstrumentID);
	    			strcpy_s(native.InstrumentID, 31, asp2.m_pChar);
	    		}
	    		
	    		//投机套保标志
	    		native.HedgeFlag = (Byte)pQryExchangeMarginRate->HedgeFlag;
			
	    		//交易所代码
	    		if (pQryExchangeMarginRate->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pQryExchangeMarginRate->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp3.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryExchangeMarginRate(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询交易所调整保证金率
	    	/// </summary>
	    	int TraderAdapter::ReqQryExchangeMarginRateAdjust(CtpNetQryExchangeMarginRateAdjustField^ pQryExchangeMarginRateAdjust, int nRequestID)
	    	{
	    		if (pQryExchangeMarginRateAdjust == nullptr)
    			{
	    			return m_pApi->ReqQryExchangeMarginRateAdjust(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryExchangeMarginRateAdjustField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQryExchangeMarginRateAdjust->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryExchangeMarginRateAdjust->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//合约代码
	    		if (pQryExchangeMarginRateAdjust->InstrumentID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryExchangeMarginRateAdjust->InstrumentID);
	    			strcpy_s(native.InstrumentID, 31, asp2.m_pChar);
	    		}
	    		
	    		//投机套保标志
	    		native.HedgeFlag = (Byte)pQryExchangeMarginRateAdjust->HedgeFlag;
			
	    		return m_pApi->ReqQryExchangeMarginRateAdjust(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询汇率
	    	/// </summary>
	    	int TraderAdapter::ReqQryExchangeRate(CtpNetQryExchangeRateField^ pQryExchangeRate, int nRequestID)
	    	{
	    		if (pQryExchangeRate == nullptr)
    			{
	    			return m_pApi->ReqQryExchangeRate(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryExchangeRateField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQryExchangeRate->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryExchangeRate->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//源币种
	    		if (pQryExchangeRate->FromCurrencyID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryExchangeRate->FromCurrencyID);
	    			strcpy_s(native.FromCurrencyID, 4, asp2.m_pChar);
	    		}
	    		
	    		//目标币种
	    		if (pQryExchangeRate->ToCurrencyID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pQryExchangeRate->ToCurrencyID);
	    			strcpy_s(native.ToCurrencyID, 4, asp3.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryExchangeRate(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询二级代理操作员银期权限
	    	/// </summary>
	    	int TraderAdapter::ReqQrySecAgentACIDMap(CtpNetQrySecAgentACIDMapField^ pQrySecAgentACIDMap, int nRequestID)
	    	{
	    		if (pQrySecAgentACIDMap == nullptr)
    			{
	    			return m_pApi->ReqQrySecAgentACIDMap(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQrySecAgentACIDMapField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQrySecAgentACIDMap->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQrySecAgentACIDMap->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//用户代码
	    		if (pQrySecAgentACIDMap->UserID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQrySecAgentACIDMap->UserID);
	    			strcpy_s(native.UserID, 16, asp2.m_pChar);
	    		}
	    		
	    		//资金账户
	    		if (pQrySecAgentACIDMap->AccountID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pQrySecAgentACIDMap->AccountID);
	    			strcpy_s(native.AccountID, 13, asp3.m_pChar);
	    		}
	    		
	    		//币种
	    		if (pQrySecAgentACIDMap->CurrencyID != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pQrySecAgentACIDMap->CurrencyID);
	    			strcpy_s(native.CurrencyID, 4, asp4.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQrySecAgentACIDMap(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询产品报价汇率
	    	/// </summary>
	    	int TraderAdapter::ReqQryProductExchRate(CtpNetQryProductExchRateField^ pQryProductExchRate, int nRequestID)
	    	{
	    		if (pQryProductExchRate == nullptr)
    			{
	    			return m_pApi->ReqQryProductExchRate(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryProductExchRateField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//产品代码
	    		if (pQryProductExchRate->ProductID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryProductExchRate->ProductID);
	    			strcpy_s(native.ProductID, 31, asp1.m_pChar);
	    		}
	    		
	    		//交易所代码
	    		if (pQryProductExchRate->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryProductExchRate->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp2.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryProductExchRate(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询产品组
	    	/// </summary>
	    	int TraderAdapter::ReqQryProductGroup(CtpNetQryProductGroupField^ pQryProductGroup, int nRequestID)
	    	{
	    		if (pQryProductGroup == nullptr)
    			{
	    			return m_pApi->ReqQryProductGroup(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryProductGroupField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//产品代码
	    		if (pQryProductGroup->ProductID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryProductGroup->ProductID);
	    			strcpy_s(native.ProductID, 31, asp1.m_pChar);
	    		}
	    		
	    		//交易所代码
	    		if (pQryProductGroup->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryProductGroup->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp2.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryProductGroup(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询做市商合约手续费率
	    	/// </summary>
	    	int TraderAdapter::ReqQryMMInstrumentCommissionRate(CtpNetQryMMInstrumentCommissionRateField^ pQryMMInstrumentCommissionRate, int nRequestID)
	    	{
	    		if (pQryMMInstrumentCommissionRate == nullptr)
    			{
	    			return m_pApi->ReqQryMMInstrumentCommissionRate(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryMMInstrumentCommissionRateField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQryMMInstrumentCommissionRate->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryMMInstrumentCommissionRate->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pQryMMInstrumentCommissionRate->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryMMInstrumentCommissionRate->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//合约代码
	    		if (pQryMMInstrumentCommissionRate->InstrumentID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pQryMMInstrumentCommissionRate->InstrumentID);
	    			strcpy_s(native.InstrumentID, 31, asp3.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryMMInstrumentCommissionRate(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询做市商期权合约手续费
	    	/// </summary>
	    	int TraderAdapter::ReqQryMMOptionInstrCommRate(CtpNetQryMMOptionInstrCommRateField^ pQryMMOptionInstrCommRate, int nRequestID)
	    	{
	    		if (pQryMMOptionInstrCommRate == nullptr)
    			{
	    			return m_pApi->ReqQryMMOptionInstrCommRate(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryMMOptionInstrCommRateField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQryMMOptionInstrCommRate->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryMMOptionInstrCommRate->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pQryMMOptionInstrCommRate->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryMMOptionInstrCommRate->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//合约代码
	    		if (pQryMMOptionInstrCommRate->InstrumentID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pQryMMOptionInstrCommRate->InstrumentID);
	    			strcpy_s(native.InstrumentID, 31, asp3.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryMMOptionInstrCommRate(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询报单手续费
	    	/// </summary>
	    	int TraderAdapter::ReqQryInstrumentOrderCommRate(CtpNetQryInstrumentOrderCommRateField^ pQryInstrumentOrderCommRate, int nRequestID)
	    	{
	    		if (pQryInstrumentOrderCommRate == nullptr)
    			{
	    			return m_pApi->ReqQryInstrumentOrderCommRate(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryInstrumentOrderCommRateField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQryInstrumentOrderCommRate->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryInstrumentOrderCommRate->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pQryInstrumentOrderCommRate->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryInstrumentOrderCommRate->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//合约代码
	    		if (pQryInstrumentOrderCommRate->InstrumentID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pQryInstrumentOrderCommRate->InstrumentID);
	    			strcpy_s(native.InstrumentID, 31, asp3.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryInstrumentOrderCommRate(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询资金账户
	    	/// </summary>
	    	int TraderAdapter::ReqQrySecAgentTradingAccount(CtpNetQryTradingAccountField^ pQryTradingAccount, int nRequestID)
	    	{
	    		if (pQryTradingAccount == nullptr)
    			{
	    			return m_pApi->ReqQrySecAgentTradingAccount(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryTradingAccountField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQryTradingAccount->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryTradingAccount->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pQryTradingAccount->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryTradingAccount->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//币种代码
	    		if (pQryTradingAccount->CurrencyID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pQryTradingAccount->CurrencyID);
	    			strcpy_s(native.CurrencyID, 4, asp3.m_pChar);
	    		}
	    		
	    		//业务类型
	    		native.BizType = (Byte)pQryTradingAccount->BizType;
			
	    		//投资者帐号
	    		if (pQryTradingAccount->AccountID != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pQryTradingAccount->AccountID);
	    			strcpy_s(native.AccountID, 13, asp4.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQrySecAgentTradingAccount(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询二级代理商资金校验模式
	    	/// </summary>
	    	int TraderAdapter::ReqQrySecAgentCheckMode(CtpNetQrySecAgentCheckModeField^ pQrySecAgentCheckMode, int nRequestID)
	    	{
	    		if (pQrySecAgentCheckMode == nullptr)
    			{
	    			return m_pApi->ReqQrySecAgentCheckMode(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQrySecAgentCheckModeField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQrySecAgentCheckMode->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQrySecAgentCheckMode->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pQrySecAgentCheckMode->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQrySecAgentCheckMode->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQrySecAgentCheckMode(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询期权交易成本
	    	/// </summary>
	    	int TraderAdapter::ReqQryOptionInstrTradeCost(CtpNetQryOptionInstrTradeCostField^ pQryOptionInstrTradeCost, int nRequestID)
	    	{
	    		if (pQryOptionInstrTradeCost == nullptr)
    			{
	    			return m_pApi->ReqQryOptionInstrTradeCost(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryOptionInstrTradeCostField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQryOptionInstrTradeCost->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryOptionInstrTradeCost->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pQryOptionInstrTradeCost->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryOptionInstrTradeCost->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//合约代码
	    		if (pQryOptionInstrTradeCost->InstrumentID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pQryOptionInstrTradeCost->InstrumentID);
	    			strcpy_s(native.InstrumentID, 31, asp3.m_pChar);
	    		}
	    		
	    		//投机套保标志
	    		native.HedgeFlag = (Byte)pQryOptionInstrTradeCost->HedgeFlag;
			
	    		//期权合约报价
	    		native.InputPrice = pQryOptionInstrTradeCost->InputPrice;
			
	    		//标的价格,填0则用昨结算价
	    		native.UnderlyingPrice = pQryOptionInstrTradeCost->UnderlyingPrice;
			
	    		//交易所代码
	    		if (pQryOptionInstrTradeCost->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pQryOptionInstrTradeCost->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp4.m_pChar);
	    		}
	    		
	    		//投资单元代码
	    		if (pQryOptionInstrTradeCost->InvestUnitID != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pQryOptionInstrTradeCost->InvestUnitID);
	    			strcpy_s(native.InvestUnitID, 17, asp5.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryOptionInstrTradeCost(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询期权合约手续费
	    	/// </summary>
	    	int TraderAdapter::ReqQryOptionInstrCommRate(CtpNetQryOptionInstrCommRateField^ pQryOptionInstrCommRate, int nRequestID)
	    	{
	    		if (pQryOptionInstrCommRate == nullptr)
    			{
	    			return m_pApi->ReqQryOptionInstrCommRate(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryOptionInstrCommRateField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQryOptionInstrCommRate->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryOptionInstrCommRate->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pQryOptionInstrCommRate->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryOptionInstrCommRate->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//合约代码
	    		if (pQryOptionInstrCommRate->InstrumentID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pQryOptionInstrCommRate->InstrumentID);
	    			strcpy_s(native.InstrumentID, 31, asp3.m_pChar);
	    		}
	    		
	    		//交易所代码
	    		if (pQryOptionInstrCommRate->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pQryOptionInstrCommRate->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp4.m_pChar);
	    		}
	    		
	    		//投资单元代码
	    		if (pQryOptionInstrCommRate->InvestUnitID != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pQryOptionInstrCommRate->InvestUnitID);
	    			strcpy_s(native.InvestUnitID, 17, asp5.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryOptionInstrCommRate(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询执行宣告
	    	/// </summary>
	    	int TraderAdapter::ReqQryExecOrder(CtpNetQryExecOrderField^ pQryExecOrder, int nRequestID)
	    	{
	    		if (pQryExecOrder == nullptr)
    			{
	    			return m_pApi->ReqQryExecOrder(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryExecOrderField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQryExecOrder->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryExecOrder->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pQryExecOrder->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryExecOrder->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//合约代码
	    		if (pQryExecOrder->InstrumentID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pQryExecOrder->InstrumentID);
	    			strcpy_s(native.InstrumentID, 31, asp3.m_pChar);
	    		}
	    		
	    		//交易所代码
	    		if (pQryExecOrder->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pQryExecOrder->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp4.m_pChar);
	    		}
	    		
	    		//执行宣告编号
	    		if (pQryExecOrder->ExecOrderSysID != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pQryExecOrder->ExecOrderSysID);
	    			strcpy_s(native.ExecOrderSysID, 21, asp5.m_pChar);
	    		}
	    		
	    		//开始时间
	    		if (pQryExecOrder->InsertTimeStart != nullptr)
	    		{
	    			CAutoStrPtr asp6 = CAutoStrPtr(pQryExecOrder->InsertTimeStart);
	    			strcpy_s(native.InsertTimeStart, 9, asp6.m_pChar);
	    		}
	    		
	    		//结束时间
	    		if (pQryExecOrder->InsertTimeEnd != nullptr)
	    		{
	    			CAutoStrPtr asp7 = CAutoStrPtr(pQryExecOrder->InsertTimeEnd);
	    			strcpy_s(native.InsertTimeEnd, 9, asp7.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryExecOrder(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询询价
	    	/// </summary>
	    	int TraderAdapter::ReqQryForQuote(CtpNetQryForQuoteField^ pQryForQuote, int nRequestID)
	    	{
	    		if (pQryForQuote == nullptr)
    			{
	    			return m_pApi->ReqQryForQuote(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryForQuoteField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQryForQuote->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryForQuote->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pQryForQuote->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryForQuote->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//合约代码
	    		if (pQryForQuote->InstrumentID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pQryForQuote->InstrumentID);
	    			strcpy_s(native.InstrumentID, 31, asp3.m_pChar);
	    		}
	    		
	    		//交易所代码
	    		if (pQryForQuote->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pQryForQuote->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp4.m_pChar);
	    		}
	    		
	    		//开始时间
	    		if (pQryForQuote->InsertTimeStart != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pQryForQuote->InsertTimeStart);
	    			strcpy_s(native.InsertTimeStart, 9, asp5.m_pChar);
	    		}
	    		
	    		//结束时间
	    		if (pQryForQuote->InsertTimeEnd != nullptr)
	    		{
	    			CAutoStrPtr asp6 = CAutoStrPtr(pQryForQuote->InsertTimeEnd);
	    			strcpy_s(native.InsertTimeEnd, 9, asp6.m_pChar);
	    		}
	    		
	    		//投资单元代码
	    		if (pQryForQuote->InvestUnitID != nullptr)
	    		{
	    			CAutoStrPtr asp7 = CAutoStrPtr(pQryForQuote->InvestUnitID);
	    			strcpy_s(native.InvestUnitID, 17, asp7.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryForQuote(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询报价
	    	/// </summary>
	    	int TraderAdapter::ReqQryQuote(CtpNetQryQuoteField^ pQryQuote, int nRequestID)
	    	{
	    		if (pQryQuote == nullptr)
    			{
	    			return m_pApi->ReqQryQuote(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryQuoteField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQryQuote->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryQuote->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pQryQuote->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryQuote->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//合约代码
	    		if (pQryQuote->InstrumentID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pQryQuote->InstrumentID);
	    			strcpy_s(native.InstrumentID, 31, asp3.m_pChar);
	    		}
	    		
	    		//交易所代码
	    		if (pQryQuote->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pQryQuote->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp4.m_pChar);
	    		}
	    		
	    		//报价编号
	    		if (pQryQuote->QuoteSysID != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pQryQuote->QuoteSysID);
	    			strcpy_s(native.QuoteSysID, 21, asp5.m_pChar);
	    		}
	    		
	    		//开始时间
	    		if (pQryQuote->InsertTimeStart != nullptr)
	    		{
	    			CAutoStrPtr asp6 = CAutoStrPtr(pQryQuote->InsertTimeStart);
	    			strcpy_s(native.InsertTimeStart, 9, asp6.m_pChar);
	    		}
	    		
	    		//结束时间
	    		if (pQryQuote->InsertTimeEnd != nullptr)
	    		{
	    			CAutoStrPtr asp7 = CAutoStrPtr(pQryQuote->InsertTimeEnd);
	    			strcpy_s(native.InsertTimeEnd, 9, asp7.m_pChar);
	    		}
	    		
	    		//投资单元代码
	    		if (pQryQuote->InvestUnitID != nullptr)
	    		{
	    			CAutoStrPtr asp8 = CAutoStrPtr(pQryQuote->InvestUnitID);
	    			strcpy_s(native.InvestUnitID, 17, asp8.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryQuote(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询期权自对冲
	    	/// </summary>
	    	int TraderAdapter::ReqQryOptionSelfClose(CtpNetQryOptionSelfCloseField^ pQryOptionSelfClose, int nRequestID)
	    	{
	    		if (pQryOptionSelfClose == nullptr)
    			{
	    			return m_pApi->ReqQryOptionSelfClose(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryOptionSelfCloseField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQryOptionSelfClose->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryOptionSelfClose->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pQryOptionSelfClose->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryOptionSelfClose->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//合约代码
	    		if (pQryOptionSelfClose->InstrumentID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pQryOptionSelfClose->InstrumentID);
	    			strcpy_s(native.InstrumentID, 31, asp3.m_pChar);
	    		}
	    		
	    		//交易所代码
	    		if (pQryOptionSelfClose->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pQryOptionSelfClose->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp4.m_pChar);
	    		}
	    		
	    		//期权自对冲编号
	    		if (pQryOptionSelfClose->OptionSelfCloseSysID != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pQryOptionSelfClose->OptionSelfCloseSysID);
	    			strcpy_s(native.OptionSelfCloseSysID, 21, asp5.m_pChar);
	    		}
	    		
	    		//开始时间
	    		if (pQryOptionSelfClose->InsertTimeStart != nullptr)
	    		{
	    			CAutoStrPtr asp6 = CAutoStrPtr(pQryOptionSelfClose->InsertTimeStart);
	    			strcpy_s(native.InsertTimeStart, 9, asp6.m_pChar);
	    		}
	    		
	    		//结束时间
	    		if (pQryOptionSelfClose->InsertTimeEnd != nullptr)
	    		{
	    			CAutoStrPtr asp7 = CAutoStrPtr(pQryOptionSelfClose->InsertTimeEnd);
	    			strcpy_s(native.InsertTimeEnd, 9, asp7.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryOptionSelfClose(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询投资单元
	    	/// </summary>
	    	int TraderAdapter::ReqQryInvestUnit(CtpNetQryInvestUnitField^ pQryInvestUnit, int nRequestID)
	    	{
	    		if (pQryInvestUnit == nullptr)
    			{
	    			return m_pApi->ReqQryInvestUnit(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryInvestUnitField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQryInvestUnit->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryInvestUnit->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pQryInvestUnit->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryInvestUnit->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//投资单元代码
	    		if (pQryInvestUnit->InvestUnitID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pQryInvestUnit->InvestUnitID);
	    			strcpy_s(native.InvestUnitID, 17, asp3.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryInvestUnit(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询组合合约安全系数
	    	/// </summary>
	    	int TraderAdapter::ReqQryCombInstrumentGuard(CtpNetQryCombInstrumentGuardField^ pQryCombInstrumentGuard, int nRequestID)
	    	{
	    		if (pQryCombInstrumentGuard == nullptr)
    			{
	    			return m_pApi->ReqQryCombInstrumentGuard(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryCombInstrumentGuardField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQryCombInstrumentGuard->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryCombInstrumentGuard->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//合约代码
	    		if (pQryCombInstrumentGuard->InstrumentID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryCombInstrumentGuard->InstrumentID);
	    			strcpy_s(native.InstrumentID, 31, asp2.m_pChar);
	    		}
	    		
	    		//交易所代码
	    		if (pQryCombInstrumentGuard->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pQryCombInstrumentGuard->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp3.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryCombInstrumentGuard(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询申请组合
	    	/// </summary>
	    	int TraderAdapter::ReqQryCombAction(CtpNetQryCombActionField^ pQryCombAction, int nRequestID)
	    	{
	    		if (pQryCombAction == nullptr)
    			{
	    			return m_pApi->ReqQryCombAction(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryCombActionField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQryCombAction->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryCombAction->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pQryCombAction->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryCombAction->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//合约代码
	    		if (pQryCombAction->InstrumentID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pQryCombAction->InstrumentID);
	    			strcpy_s(native.InstrumentID, 31, asp3.m_pChar);
	    		}
	    		
	    		//交易所代码
	    		if (pQryCombAction->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pQryCombAction->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp4.m_pChar);
	    		}
	    		
	    		//投资单元代码
	    		if (pQryCombAction->InvestUnitID != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pQryCombAction->InvestUnitID);
	    			strcpy_s(native.InvestUnitID, 17, asp5.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryCombAction(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询转帐流水
	    	/// </summary>
	    	int TraderAdapter::ReqQryTransferSerial(CtpNetQryTransferSerialField^ pQryTransferSerial, int nRequestID)
	    	{
	    		if (pQryTransferSerial == nullptr)
    			{
	    			return m_pApi->ReqQryTransferSerial(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryTransferSerialField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQryTransferSerial->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryTransferSerial->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者帐号
	    		if (pQryTransferSerial->AccountID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryTransferSerial->AccountID);
	    			strcpy_s(native.AccountID, 13, asp2.m_pChar);
	    		}
	    		
	    		//银行编码
	    		if (pQryTransferSerial->BankID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pQryTransferSerial->BankID);
	    			strcpy_s(native.BankID, 4, asp3.m_pChar);
	    		}
	    		
	    		//币种代码
	    		if (pQryTransferSerial->CurrencyID != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pQryTransferSerial->CurrencyID);
	    			strcpy_s(native.CurrencyID, 4, asp4.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryTransferSerial(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询银期签约关系
	    	/// </summary>
	    	int TraderAdapter::ReqQryAccountregister(CtpNetQryAccountregisterField^ pQryAccountregister, int nRequestID)
	    	{
	    		if (pQryAccountregister == nullptr)
    			{
	    			return m_pApi->ReqQryAccountregister(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryAccountregisterField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQryAccountregister->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryAccountregister->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者帐号
	    		if (pQryAccountregister->AccountID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryAccountregister->AccountID);
	    			strcpy_s(native.AccountID, 13, asp2.m_pChar);
	    		}
	    		
	    		//银行编码
	    		if (pQryAccountregister->BankID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pQryAccountregister->BankID);
	    			strcpy_s(native.BankID, 4, asp3.m_pChar);
	    		}
	    		
	    		//银行分支机构编码
	    		if (pQryAccountregister->BankBranchID != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pQryAccountregister->BankBranchID);
	    			strcpy_s(native.BankBranchID, 5, asp4.m_pChar);
	    		}
	    		
	    		//币种代码
	    		if (pQryAccountregister->CurrencyID != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pQryAccountregister->CurrencyID);
	    			strcpy_s(native.CurrencyID, 4, asp5.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryAccountregister(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询签约银行
	    	/// </summary>
	    	int TraderAdapter::ReqQryContractBank(CtpNetQryContractBankField^ pQryContractBank, int nRequestID)
	    	{
	    		if (pQryContractBank == nullptr)
    			{
	    			return m_pApi->ReqQryContractBank(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryContractBankField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQryContractBank->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryContractBank->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//银行代码
	    		if (pQryContractBank->BankID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryContractBank->BankID);
	    			strcpy_s(native.BankID, 4, asp2.m_pChar);
	    		}
	    		
	    		//银行分中心代码
	    		if (pQryContractBank->BankBrchID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pQryContractBank->BankBrchID);
	    			strcpy_s(native.BankBrchID, 5, asp3.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryContractBank(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询预埋单
	    	/// </summary>
	    	int TraderAdapter::ReqQryParkedOrder(CtpNetQryParkedOrderField^ pQryParkedOrder, int nRequestID)
	    	{
	    		if (pQryParkedOrder == nullptr)
    			{
	    			return m_pApi->ReqQryParkedOrder(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryParkedOrderField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQryParkedOrder->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryParkedOrder->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pQryParkedOrder->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryParkedOrder->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//合约代码
	    		if (pQryParkedOrder->InstrumentID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pQryParkedOrder->InstrumentID);
	    			strcpy_s(native.InstrumentID, 31, asp3.m_pChar);
	    		}
	    		
	    		//交易所代码
	    		if (pQryParkedOrder->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pQryParkedOrder->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp4.m_pChar);
	    		}
	    		
	    		//投资单元代码
	    		if (pQryParkedOrder->InvestUnitID != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pQryParkedOrder->InvestUnitID);
	    			strcpy_s(native.InvestUnitID, 17, asp5.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryParkedOrder(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询预埋撤单
	    	/// </summary>
	    	int TraderAdapter::ReqQryParkedOrderAction(CtpNetQryParkedOrderActionField^ pQryParkedOrderAction, int nRequestID)
	    	{
	    		if (pQryParkedOrderAction == nullptr)
    			{
	    			return m_pApi->ReqQryParkedOrderAction(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryParkedOrderActionField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQryParkedOrderAction->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryParkedOrderAction->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pQryParkedOrderAction->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryParkedOrderAction->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//合约代码
	    		if (pQryParkedOrderAction->InstrumentID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pQryParkedOrderAction->InstrumentID);
	    			strcpy_s(native.InstrumentID, 31, asp3.m_pChar);
	    		}
	    		
	    		//交易所代码
	    		if (pQryParkedOrderAction->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pQryParkedOrderAction->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp4.m_pChar);
	    		}
	    		
	    		//投资单元代码
	    		if (pQryParkedOrderAction->InvestUnitID != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pQryParkedOrderAction->InvestUnitID);
	    			strcpy_s(native.InvestUnitID, 17, asp5.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryParkedOrderAction(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询交易通知
	    	/// </summary>
	    	int TraderAdapter::ReqQryTradingNotice(CtpNetQryTradingNoticeField^ pQryTradingNotice, int nRequestID)
	    	{
	    		if (pQryTradingNotice == nullptr)
    			{
	    			return m_pApi->ReqQryTradingNotice(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryTradingNoticeField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQryTradingNotice->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryTradingNotice->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pQryTradingNotice->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryTradingNotice->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//投资单元代码
	    		if (pQryTradingNotice->InvestUnitID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pQryTradingNotice->InvestUnitID);
	    			strcpy_s(native.InvestUnitID, 17, asp3.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryTradingNotice(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询经纪公司交易参数
	    	/// </summary>
	    	int TraderAdapter::ReqQryBrokerTradingParams(CtpNetQryBrokerTradingParamsField^ pQryBrokerTradingParams, int nRequestID)
	    	{
	    		if (pQryBrokerTradingParams == nullptr)
    			{
	    			return m_pApi->ReqQryBrokerTradingParams(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryBrokerTradingParamsField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQryBrokerTradingParams->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryBrokerTradingParams->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pQryBrokerTradingParams->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryBrokerTradingParams->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//币种代码
	    		if (pQryBrokerTradingParams->CurrencyID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pQryBrokerTradingParams->CurrencyID);
	    			strcpy_s(native.CurrencyID, 4, asp3.m_pChar);
	    		}
	    		
	    		//投资者帐号
	    		if (pQryBrokerTradingParams->AccountID != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pQryBrokerTradingParams->AccountID);
	    			strcpy_s(native.AccountID, 13, asp4.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryBrokerTradingParams(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询经纪公司交易算法
	    	/// </summary>
	    	int TraderAdapter::ReqQryBrokerTradingAlgos(CtpNetQryBrokerTradingAlgosField^ pQryBrokerTradingAlgos, int nRequestID)
	    	{
	    		if (pQryBrokerTradingAlgos == nullptr)
    			{
	    			return m_pApi->ReqQryBrokerTradingAlgos(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQryBrokerTradingAlgosField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQryBrokerTradingAlgos->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQryBrokerTradingAlgos->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//交易所代码
	    		if (pQryBrokerTradingAlgos->ExchangeID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQryBrokerTradingAlgos->ExchangeID);
	    			strcpy_s(native.ExchangeID, 9, asp2.m_pChar);
	    		}
	    		
	    		//合约代码
	    		if (pQryBrokerTradingAlgos->InstrumentID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pQryBrokerTradingAlgos->InstrumentID);
	    			strcpy_s(native.InstrumentID, 31, asp3.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQryBrokerTradingAlgos(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 请求查询监控中心用户令牌
	    	/// </summary>
	    	int TraderAdapter::ReqQueryCFMMCTradingAccountToken(CtpNetQueryCFMMCTradingAccountTokenField^ pQueryCFMMCTradingAccountToken, int nRequestID)
	    	{
	    		if (pQueryCFMMCTradingAccountToken == nullptr)
    			{
	    			return m_pApi->ReqQueryCFMMCTradingAccountToken(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcQueryCFMMCTradingAccountTokenField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//经纪公司代码
	    		if (pQueryCFMMCTradingAccountToken->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pQueryCFMMCTradingAccountToken->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp1.m_pChar);
	    		}
	    		
	    		//投资者代码
	    		if (pQueryCFMMCTradingAccountToken->InvestorID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pQueryCFMMCTradingAccountToken->InvestorID);
	    			strcpy_s(native.InvestorID, 13, asp2.m_pChar);
	    		}
	    		
	    		//投资单元代码
	    		if (pQueryCFMMCTradingAccountToken->InvestUnitID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pQueryCFMMCTradingAccountToken->InvestUnitID);
	    			strcpy_s(native.InvestUnitID, 17, asp3.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQueryCFMMCTradingAccountToken(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 期货发起银行资金转期货请求
	    	/// </summary>
	    	int TraderAdapter::ReqFromBankToFutureByFuture(CtpNetReqTransferField^ pReqTransfer, int nRequestID)
	    	{
	    		if (pReqTransfer == nullptr)
    			{
	    			return m_pApi->ReqFromBankToFutureByFuture(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcReqTransferField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//业务功能码
	    		if (pReqTransfer->TradeCode != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pReqTransfer->TradeCode);
	    			strcpy_s(native.TradeCode, 7, asp1.m_pChar);
	    		}
	    		
	    		//银行代码
	    		if (pReqTransfer->BankID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pReqTransfer->BankID);
	    			strcpy_s(native.BankID, 4, asp2.m_pChar);
	    		}
	    		
	    		//银行分支机构代码
	    		if (pReqTransfer->BankBranchID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pReqTransfer->BankBranchID);
	    			strcpy_s(native.BankBranchID, 5, asp3.m_pChar);
	    		}
	    		
	    		//期商代码
	    		if (pReqTransfer->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pReqTransfer->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp4.m_pChar);
	    		}
	    		
	    		//期商分支机构代码
	    		if (pReqTransfer->BrokerBranchID != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pReqTransfer->BrokerBranchID);
	    			strcpy_s(native.BrokerBranchID, 31, asp5.m_pChar);
	    		}
	    		
	    		//交易日期
	    		if (pReqTransfer->TradeDate != nullptr)
	    		{
	    			CAutoStrPtr asp6 = CAutoStrPtr(pReqTransfer->TradeDate);
	    			strcpy_s(native.TradeDate, 9, asp6.m_pChar);
	    		}
	    		
	    		//交易时间
	    		if (pReqTransfer->TradeTime != nullptr)
	    		{
	    			CAutoStrPtr asp7 = CAutoStrPtr(pReqTransfer->TradeTime);
	    			strcpy_s(native.TradeTime, 9, asp7.m_pChar);
	    		}
	    		
	    		//银行流水号
	    		if (pReqTransfer->BankSerial != nullptr)
	    		{
	    			CAutoStrPtr asp8 = CAutoStrPtr(pReqTransfer->BankSerial);
	    			strcpy_s(native.BankSerial, 13, asp8.m_pChar);
	    		}
	    		
	    		//交易系统日期
	    		if (pReqTransfer->TradingDay != nullptr)
	    		{
	    			CAutoStrPtr asp9 = CAutoStrPtr(pReqTransfer->TradingDay);
	    			strcpy_s(native.TradingDay, 9, asp9.m_pChar);
	    		}
	    		
	    		//银期平台消息流水号
	    		native.PlateSerial = pReqTransfer->PlateSerial;
			
	    		//最后分片标志
	    		native.LastFragment = (Byte)pReqTransfer->LastFragment;
			
	    		//会话号
	    		native.SessionID = pReqTransfer->SessionID;
			
	    		//客户姓名
	    		if (pReqTransfer->CustomerName != nullptr)
	    		{
	    			CAutoStrPtr asp10 = CAutoStrPtr(pReqTransfer->CustomerName);
	    			strcpy_s(native.CustomerName, 51, asp10.m_pChar);
	    		}
	    		
	    		//证件类型
	    		native.IdCardType = (Byte)pReqTransfer->IdCardType;
			
	    		//证件号码
	    		if (pReqTransfer->IdentifiedCardNo != nullptr)
	    		{
	    			CAutoStrPtr asp11 = CAutoStrPtr(pReqTransfer->IdentifiedCardNo);
	    			strcpy_s(native.IdentifiedCardNo, 51, asp11.m_pChar);
	    		}
	    		
	    		//客户类型
	    		native.CustType = (Byte)pReqTransfer->CustType;
			
	    		//银行帐号
	    		if (pReqTransfer->BankAccount != nullptr)
	    		{
	    			CAutoStrPtr asp12 = CAutoStrPtr(pReqTransfer->BankAccount);
	    			strcpy_s(native.BankAccount, 41, asp12.m_pChar);
	    		}
	    		
	    		//银行密码
	    		if (pReqTransfer->BankPassWord != nullptr)
	    		{
	    			CAutoStrPtr asp13 = CAutoStrPtr(pReqTransfer->BankPassWord);
	    			strcpy_s(native.BankPassWord, 41, asp13.m_pChar);
	    		}
	    		
	    		//投资者帐号
	    		if (pReqTransfer->AccountID != nullptr)
	    		{
	    			CAutoStrPtr asp14 = CAutoStrPtr(pReqTransfer->AccountID);
	    			strcpy_s(native.AccountID, 13, asp14.m_pChar);
	    		}
	    		
	    		//期货密码
	    		if (pReqTransfer->Password != nullptr)
	    		{
	    			CAutoStrPtr asp15 = CAutoStrPtr(pReqTransfer->Password);
	    			strcpy_s(native.Password, 41, asp15.m_pChar);
	    		}
	    		
	    		//安装编号
	    		native.InstallID = pReqTransfer->InstallID;
			
	    		//期货公司流水号
	    		native.FutureSerial = pReqTransfer->FutureSerial;
			
	    		//用户标识
	    		if (pReqTransfer->UserID != nullptr)
	    		{
	    			CAutoStrPtr asp16 = CAutoStrPtr(pReqTransfer->UserID);
	    			strcpy_s(native.UserID, 16, asp16.m_pChar);
	    		}
	    		
	    		//验证客户证件号码标志
	    		native.VerifyCertNoFlag = (Byte)pReqTransfer->VerifyCertNoFlag;
			
	    		//币种代码
	    		if (pReqTransfer->CurrencyID != nullptr)
	    		{
	    			CAutoStrPtr asp17 = CAutoStrPtr(pReqTransfer->CurrencyID);
	    			strcpy_s(native.CurrencyID, 4, asp17.m_pChar);
	    		}
	    		
	    		//转帐金额
	    		native.TradeAmount = pReqTransfer->TradeAmount;
			
	    		//期货可取金额
	    		native.FutureFetchAmount = pReqTransfer->FutureFetchAmount;
			
	    		//费用支付标志
	    		native.FeePayFlag = (Byte)pReqTransfer->FeePayFlag;
			
	    		//应收客户费用
	    		native.CustFee = pReqTransfer->CustFee;
			
	    		//应收期货公司费用
	    		native.BrokerFee = pReqTransfer->BrokerFee;
			
	    		//发送方给接收方的消息
	    		if (pReqTransfer->Message != nullptr)
	    		{
	    			CAutoStrPtr asp18 = CAutoStrPtr(pReqTransfer->Message);
	    			strcpy_s(native.Message, 129, asp18.m_pChar);
	    		}
	    		
	    		//摘要
	    		if (pReqTransfer->Digest != nullptr)
	    		{
	    			CAutoStrPtr asp19 = CAutoStrPtr(pReqTransfer->Digest);
	    			strcpy_s(native.Digest, 36, asp19.m_pChar);
	    		}
	    		
	    		//银行帐号类型
	    		native.BankAccType = (Byte)pReqTransfer->BankAccType;
			
	    		//渠道标志
	    		if (pReqTransfer->DeviceID != nullptr)
	    		{
	    			CAutoStrPtr asp20 = CAutoStrPtr(pReqTransfer->DeviceID);
	    			strcpy_s(native.DeviceID, 3, asp20.m_pChar);
	    		}
	    		
	    		//期货单位帐号类型
	    		native.BankSecuAccType = (Byte)pReqTransfer->BankSecuAccType;
			
	    		//期货公司银行编码
	    		if (pReqTransfer->BrokerIDByBank != nullptr)
	    		{
	    			CAutoStrPtr asp21 = CAutoStrPtr(pReqTransfer->BrokerIDByBank);
	    			strcpy_s(native.BrokerIDByBank, 33, asp21.m_pChar);
	    		}
	    		
	    		//期货单位帐号
	    		if (pReqTransfer->BankSecuAcc != nullptr)
	    		{
	    			CAutoStrPtr asp22 = CAutoStrPtr(pReqTransfer->BankSecuAcc);
	    			strcpy_s(native.BankSecuAcc, 41, asp22.m_pChar);
	    		}
	    		
	    		//银行密码标志
	    		native.BankPwdFlag = (Byte)pReqTransfer->BankPwdFlag;
			
	    		//期货资金密码核对标志
	    		native.SecuPwdFlag = (Byte)pReqTransfer->SecuPwdFlag;
			
	    		//交易柜员
	    		if (pReqTransfer->OperNo != nullptr)
	    		{
	    			CAutoStrPtr asp23 = CAutoStrPtr(pReqTransfer->OperNo);
	    			strcpy_s(native.OperNo, 17, asp23.m_pChar);
	    		}
	    		
	    		//请求编号
	    		native.RequestID = pReqTransfer->RequestID;
			
	    		//交易ID
	    		native.TID = pReqTransfer->TID;
			
	    		//转账交易状态
	    		native.TransferStatus = (Byte)pReqTransfer->TransferStatus;
			
	    		//长客户姓名
	    		if (pReqTransfer->LongCustomerName != nullptr)
	    		{
	    			CAutoStrPtr asp24 = CAutoStrPtr(pReqTransfer->LongCustomerName);
	    			strcpy_s(native.LongCustomerName, 161, asp24.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqFromBankToFutureByFuture(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 期货发起期货资金转银行请求
	    	/// </summary>
	    	int TraderAdapter::ReqFromFutureToBankByFuture(CtpNetReqTransferField^ pReqTransfer, int nRequestID)
	    	{
	    		if (pReqTransfer == nullptr)
    			{
	    			return m_pApi->ReqFromFutureToBankByFuture(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcReqTransferField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//业务功能码
	    		if (pReqTransfer->TradeCode != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pReqTransfer->TradeCode);
	    			strcpy_s(native.TradeCode, 7, asp1.m_pChar);
	    		}
	    		
	    		//银行代码
	    		if (pReqTransfer->BankID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pReqTransfer->BankID);
	    			strcpy_s(native.BankID, 4, asp2.m_pChar);
	    		}
	    		
	    		//银行分支机构代码
	    		if (pReqTransfer->BankBranchID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pReqTransfer->BankBranchID);
	    			strcpy_s(native.BankBranchID, 5, asp3.m_pChar);
	    		}
	    		
	    		//期商代码
	    		if (pReqTransfer->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pReqTransfer->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp4.m_pChar);
	    		}
	    		
	    		//期商分支机构代码
	    		if (pReqTransfer->BrokerBranchID != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pReqTransfer->BrokerBranchID);
	    			strcpy_s(native.BrokerBranchID, 31, asp5.m_pChar);
	    		}
	    		
	    		//交易日期
	    		if (pReqTransfer->TradeDate != nullptr)
	    		{
	    			CAutoStrPtr asp6 = CAutoStrPtr(pReqTransfer->TradeDate);
	    			strcpy_s(native.TradeDate, 9, asp6.m_pChar);
	    		}
	    		
	    		//交易时间
	    		if (pReqTransfer->TradeTime != nullptr)
	    		{
	    			CAutoStrPtr asp7 = CAutoStrPtr(pReqTransfer->TradeTime);
	    			strcpy_s(native.TradeTime, 9, asp7.m_pChar);
	    		}
	    		
	    		//银行流水号
	    		if (pReqTransfer->BankSerial != nullptr)
	    		{
	    			CAutoStrPtr asp8 = CAutoStrPtr(pReqTransfer->BankSerial);
	    			strcpy_s(native.BankSerial, 13, asp8.m_pChar);
	    		}
	    		
	    		//交易系统日期
	    		if (pReqTransfer->TradingDay != nullptr)
	    		{
	    			CAutoStrPtr asp9 = CAutoStrPtr(pReqTransfer->TradingDay);
	    			strcpy_s(native.TradingDay, 9, asp9.m_pChar);
	    		}
	    		
	    		//银期平台消息流水号
	    		native.PlateSerial = pReqTransfer->PlateSerial;
			
	    		//最后分片标志
	    		native.LastFragment = (Byte)pReqTransfer->LastFragment;
			
	    		//会话号
	    		native.SessionID = pReqTransfer->SessionID;
			
	    		//客户姓名
	    		if (pReqTransfer->CustomerName != nullptr)
	    		{
	    			CAutoStrPtr asp10 = CAutoStrPtr(pReqTransfer->CustomerName);
	    			strcpy_s(native.CustomerName, 51, asp10.m_pChar);
	    		}
	    		
	    		//证件类型
	    		native.IdCardType = (Byte)pReqTransfer->IdCardType;
			
	    		//证件号码
	    		if (pReqTransfer->IdentifiedCardNo != nullptr)
	    		{
	    			CAutoStrPtr asp11 = CAutoStrPtr(pReqTransfer->IdentifiedCardNo);
	    			strcpy_s(native.IdentifiedCardNo, 51, asp11.m_pChar);
	    		}
	    		
	    		//客户类型
	    		native.CustType = (Byte)pReqTransfer->CustType;
			
	    		//银行帐号
	    		if (pReqTransfer->BankAccount != nullptr)
	    		{
	    			CAutoStrPtr asp12 = CAutoStrPtr(pReqTransfer->BankAccount);
	    			strcpy_s(native.BankAccount, 41, asp12.m_pChar);
	    		}
	    		
	    		//银行密码
	    		if (pReqTransfer->BankPassWord != nullptr)
	    		{
	    			CAutoStrPtr asp13 = CAutoStrPtr(pReqTransfer->BankPassWord);
	    			strcpy_s(native.BankPassWord, 41, asp13.m_pChar);
	    		}
	    		
	    		//投资者帐号
	    		if (pReqTransfer->AccountID != nullptr)
	    		{
	    			CAutoStrPtr asp14 = CAutoStrPtr(pReqTransfer->AccountID);
	    			strcpy_s(native.AccountID, 13, asp14.m_pChar);
	    		}
	    		
	    		//期货密码
	    		if (pReqTransfer->Password != nullptr)
	    		{
	    			CAutoStrPtr asp15 = CAutoStrPtr(pReqTransfer->Password);
	    			strcpy_s(native.Password, 41, asp15.m_pChar);
	    		}
	    		
	    		//安装编号
	    		native.InstallID = pReqTransfer->InstallID;
			
	    		//期货公司流水号
	    		native.FutureSerial = pReqTransfer->FutureSerial;
			
	    		//用户标识
	    		if (pReqTransfer->UserID != nullptr)
	    		{
	    			CAutoStrPtr asp16 = CAutoStrPtr(pReqTransfer->UserID);
	    			strcpy_s(native.UserID, 16, asp16.m_pChar);
	    		}
	    		
	    		//验证客户证件号码标志
	    		native.VerifyCertNoFlag = (Byte)pReqTransfer->VerifyCertNoFlag;
			
	    		//币种代码
	    		if (pReqTransfer->CurrencyID != nullptr)
	    		{
	    			CAutoStrPtr asp17 = CAutoStrPtr(pReqTransfer->CurrencyID);
	    			strcpy_s(native.CurrencyID, 4, asp17.m_pChar);
	    		}
	    		
	    		//转帐金额
	    		native.TradeAmount = pReqTransfer->TradeAmount;
			
	    		//期货可取金额
	    		native.FutureFetchAmount = pReqTransfer->FutureFetchAmount;
			
	    		//费用支付标志
	    		native.FeePayFlag = (Byte)pReqTransfer->FeePayFlag;
			
	    		//应收客户费用
	    		native.CustFee = pReqTransfer->CustFee;
			
	    		//应收期货公司费用
	    		native.BrokerFee = pReqTransfer->BrokerFee;
			
	    		//发送方给接收方的消息
	    		if (pReqTransfer->Message != nullptr)
	    		{
	    			CAutoStrPtr asp18 = CAutoStrPtr(pReqTransfer->Message);
	    			strcpy_s(native.Message, 129, asp18.m_pChar);
	    		}
	    		
	    		//摘要
	    		if (pReqTransfer->Digest != nullptr)
	    		{
	    			CAutoStrPtr asp19 = CAutoStrPtr(pReqTransfer->Digest);
	    			strcpy_s(native.Digest, 36, asp19.m_pChar);
	    		}
	    		
	    		//银行帐号类型
	    		native.BankAccType = (Byte)pReqTransfer->BankAccType;
			
	    		//渠道标志
	    		if (pReqTransfer->DeviceID != nullptr)
	    		{
	    			CAutoStrPtr asp20 = CAutoStrPtr(pReqTransfer->DeviceID);
	    			strcpy_s(native.DeviceID, 3, asp20.m_pChar);
	    		}
	    		
	    		//期货单位帐号类型
	    		native.BankSecuAccType = (Byte)pReqTransfer->BankSecuAccType;
			
	    		//期货公司银行编码
	    		if (pReqTransfer->BrokerIDByBank != nullptr)
	    		{
	    			CAutoStrPtr asp21 = CAutoStrPtr(pReqTransfer->BrokerIDByBank);
	    			strcpy_s(native.BrokerIDByBank, 33, asp21.m_pChar);
	    		}
	    		
	    		//期货单位帐号
	    		if (pReqTransfer->BankSecuAcc != nullptr)
	    		{
	    			CAutoStrPtr asp22 = CAutoStrPtr(pReqTransfer->BankSecuAcc);
	    			strcpy_s(native.BankSecuAcc, 41, asp22.m_pChar);
	    		}
	    		
	    		//银行密码标志
	    		native.BankPwdFlag = (Byte)pReqTransfer->BankPwdFlag;
			
	    		//期货资金密码核对标志
	    		native.SecuPwdFlag = (Byte)pReqTransfer->SecuPwdFlag;
			
	    		//交易柜员
	    		if (pReqTransfer->OperNo != nullptr)
	    		{
	    			CAutoStrPtr asp23 = CAutoStrPtr(pReqTransfer->OperNo);
	    			strcpy_s(native.OperNo, 17, asp23.m_pChar);
	    		}
	    		
	    		//请求编号
	    		native.RequestID = pReqTransfer->RequestID;
			
	    		//交易ID
	    		native.TID = pReqTransfer->TID;
			
	    		//转账交易状态
	    		native.TransferStatus = (Byte)pReqTransfer->TransferStatus;
			
	    		//长客户姓名
	    		if (pReqTransfer->LongCustomerName != nullptr)
	    		{
	    			CAutoStrPtr asp24 = CAutoStrPtr(pReqTransfer->LongCustomerName);
	    			strcpy_s(native.LongCustomerName, 161, asp24.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqFromFutureToBankByFuture(&native, nRequestID);
	    	}

	    	/// <summary>
	    	/// 期货发起查询银行余额请求
	    	/// </summary>
	    	int TraderAdapter::ReqQueryBankAccountMoneyByFuture(CtpNetReqQueryAccountField^ pReqQueryAccount, int nRequestID)
	    	{
	    		if (pReqQueryAccount == nullptr)
    			{
	    			return m_pApi->ReqQueryBankAccountMoneyByFuture(nullptr, nRequestID);
	    		}
	    		
	    		CThostFtdcReqQueryAccountField native;
	    		memset(&native, 0, sizeof(native));
	    		
	    		//业务功能码
	    		if (pReqQueryAccount->TradeCode != nullptr)
	    		{
	    			CAutoStrPtr asp1 = CAutoStrPtr(pReqQueryAccount->TradeCode);
	    			strcpy_s(native.TradeCode, 7, asp1.m_pChar);
	    		}
	    		
	    		//银行代码
	    		if (pReqQueryAccount->BankID != nullptr)
	    		{
	    			CAutoStrPtr asp2 = CAutoStrPtr(pReqQueryAccount->BankID);
	    			strcpy_s(native.BankID, 4, asp2.m_pChar);
	    		}
	    		
	    		//银行分支机构代码
	    		if (pReqQueryAccount->BankBranchID != nullptr)
	    		{
	    			CAutoStrPtr asp3 = CAutoStrPtr(pReqQueryAccount->BankBranchID);
	    			strcpy_s(native.BankBranchID, 5, asp3.m_pChar);
	    		}
	    		
	    		//期商代码
	    		if (pReqQueryAccount->BrokerID != nullptr)
	    		{
	    			CAutoStrPtr asp4 = CAutoStrPtr(pReqQueryAccount->BrokerID);
	    			strcpy_s(native.BrokerID, 11, asp4.m_pChar);
	    		}
	    		
	    		//期商分支机构代码
	    		if (pReqQueryAccount->BrokerBranchID != nullptr)
	    		{
	    			CAutoStrPtr asp5 = CAutoStrPtr(pReqQueryAccount->BrokerBranchID);
	    			strcpy_s(native.BrokerBranchID, 31, asp5.m_pChar);
	    		}
	    		
	    		//交易日期
	    		if (pReqQueryAccount->TradeDate != nullptr)
	    		{
	    			CAutoStrPtr asp6 = CAutoStrPtr(pReqQueryAccount->TradeDate);
	    			strcpy_s(native.TradeDate, 9, asp6.m_pChar);
	    		}
	    		
	    		//交易时间
	    		if (pReqQueryAccount->TradeTime != nullptr)
	    		{
	    			CAutoStrPtr asp7 = CAutoStrPtr(pReqQueryAccount->TradeTime);
	    			strcpy_s(native.TradeTime, 9, asp7.m_pChar);
	    		}
	    		
	    		//银行流水号
	    		if (pReqQueryAccount->BankSerial != nullptr)
	    		{
	    			CAutoStrPtr asp8 = CAutoStrPtr(pReqQueryAccount->BankSerial);
	    			strcpy_s(native.BankSerial, 13, asp8.m_pChar);
	    		}
	    		
	    		//交易系统日期
	    		if (pReqQueryAccount->TradingDay != nullptr)
	    		{
	    			CAutoStrPtr asp9 = CAutoStrPtr(pReqQueryAccount->TradingDay);
	    			strcpy_s(native.TradingDay, 9, asp9.m_pChar);
	    		}
	    		
	    		//银期平台消息流水号
	    		native.PlateSerial = pReqQueryAccount->PlateSerial;
			
	    		//最后分片标志
	    		native.LastFragment = (Byte)pReqQueryAccount->LastFragment;
			
	    		//会话号
	    		native.SessionID = pReqQueryAccount->SessionID;
			
	    		//客户姓名
	    		if (pReqQueryAccount->CustomerName != nullptr)
	    		{
	    			CAutoStrPtr asp10 = CAutoStrPtr(pReqQueryAccount->CustomerName);
	    			strcpy_s(native.CustomerName, 51, asp10.m_pChar);
	    		}
	    		
	    		//证件类型
	    		native.IdCardType = (Byte)pReqQueryAccount->IdCardType;
			
	    		//证件号码
	    		if (pReqQueryAccount->IdentifiedCardNo != nullptr)
	    		{
	    			CAutoStrPtr asp11 = CAutoStrPtr(pReqQueryAccount->IdentifiedCardNo);
	    			strcpy_s(native.IdentifiedCardNo, 51, asp11.m_pChar);
	    		}
	    		
	    		//客户类型
	    		native.CustType = (Byte)pReqQueryAccount->CustType;
			
	    		//银行帐号
	    		if (pReqQueryAccount->BankAccount != nullptr)
	    		{
	    			CAutoStrPtr asp12 = CAutoStrPtr(pReqQueryAccount->BankAccount);
	    			strcpy_s(native.BankAccount, 41, asp12.m_pChar);
	    		}
	    		
	    		//银行密码
	    		if (pReqQueryAccount->BankPassWord != nullptr)
	    		{
	    			CAutoStrPtr asp13 = CAutoStrPtr(pReqQueryAccount->BankPassWord);
	    			strcpy_s(native.BankPassWord, 41, asp13.m_pChar);
	    		}
	    		
	    		//投资者帐号
	    		if (pReqQueryAccount->AccountID != nullptr)
	    		{
	    			CAutoStrPtr asp14 = CAutoStrPtr(pReqQueryAccount->AccountID);
	    			strcpy_s(native.AccountID, 13, asp14.m_pChar);
	    		}
	    		
	    		//期货密码
	    		if (pReqQueryAccount->Password != nullptr)
	    		{
	    			CAutoStrPtr asp15 = CAutoStrPtr(pReqQueryAccount->Password);
	    			strcpy_s(native.Password, 41, asp15.m_pChar);
	    		}
	    		
	    		//期货公司流水号
	    		native.FutureSerial = pReqQueryAccount->FutureSerial;
			
	    		//安装编号
	    		native.InstallID = pReqQueryAccount->InstallID;
			
	    		//用户标识
	    		if (pReqQueryAccount->UserID != nullptr)
	    		{
	    			CAutoStrPtr asp16 = CAutoStrPtr(pReqQueryAccount->UserID);
	    			strcpy_s(native.UserID, 16, asp16.m_pChar);
	    		}
	    		
	    		//验证客户证件号码标志
	    		native.VerifyCertNoFlag = (Byte)pReqQueryAccount->VerifyCertNoFlag;
			
	    		//币种代码
	    		if (pReqQueryAccount->CurrencyID != nullptr)
	    		{
	    			CAutoStrPtr asp17 = CAutoStrPtr(pReqQueryAccount->CurrencyID);
	    			strcpy_s(native.CurrencyID, 4, asp17.m_pChar);
	    		}
	    		
	    		//摘要
	    		if (pReqQueryAccount->Digest != nullptr)
	    		{
	    			CAutoStrPtr asp18 = CAutoStrPtr(pReqQueryAccount->Digest);
	    			strcpy_s(native.Digest, 36, asp18.m_pChar);
	    		}
	    		
	    		//银行帐号类型
	    		native.BankAccType = (Byte)pReqQueryAccount->BankAccType;
			
	    		//渠道标志
	    		if (pReqQueryAccount->DeviceID != nullptr)
	    		{
	    			CAutoStrPtr asp19 = CAutoStrPtr(pReqQueryAccount->DeviceID);
	    			strcpy_s(native.DeviceID, 3, asp19.m_pChar);
	    		}
	    		
	    		//期货单位帐号类型
	    		native.BankSecuAccType = (Byte)pReqQueryAccount->BankSecuAccType;
			
	    		//期货公司银行编码
	    		if (pReqQueryAccount->BrokerIDByBank != nullptr)
	    		{
	    			CAutoStrPtr asp20 = CAutoStrPtr(pReqQueryAccount->BrokerIDByBank);
	    			strcpy_s(native.BrokerIDByBank, 33, asp20.m_pChar);
	    		}
	    		
	    		//期货单位帐号
	    		if (pReqQueryAccount->BankSecuAcc != nullptr)
	    		{
	    			CAutoStrPtr asp21 = CAutoStrPtr(pReqQueryAccount->BankSecuAcc);
	    			strcpy_s(native.BankSecuAcc, 41, asp21.m_pChar);
	    		}
	    		
	    		//银行密码标志
	    		native.BankPwdFlag = (Byte)pReqQueryAccount->BankPwdFlag;
			
	    		//期货资金密码核对标志
	    		native.SecuPwdFlag = (Byte)pReqQueryAccount->SecuPwdFlag;
			
	    		//交易柜员
	    		if (pReqQueryAccount->OperNo != nullptr)
	    		{
	    			CAutoStrPtr asp22 = CAutoStrPtr(pReqQueryAccount->OperNo);
	    			strcpy_s(native.OperNo, 17, asp22.m_pChar);
	    		}
	    		
	    		//请求编号
	    		native.RequestID = pReqQueryAccount->RequestID;
			
	    		//交易ID
	    		native.TID = pReqQueryAccount->TID;
			
	    		//长客户姓名
	    		if (pReqQueryAccount->LongCustomerName != nullptr)
	    		{
	    			CAutoStrPtr asp23 = CAutoStrPtr(pReqQueryAccount->LongCustomerName);
	    			strcpy_s(native.LongCustomerName, 161, asp23.m_pChar);
	    		}
	    		
	    		return m_pApi->ReqQueryBankAccountMoneyByFuture(&native, nRequestID);
	    	}
	    }
	}
}
