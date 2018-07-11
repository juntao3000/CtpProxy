#pragma once

#include "Util.h"
//#include "Delegate.h"

using namespace Native;
using namespace TaiTanXing::Ctp::CtpNet;

namespace Native
{
	// 行情命令响应
	class CMdSpi;
};

namespace TaiTanXing
{
	namespace Ctp
	{
		namespace CtpProxy
		{
			/// <summary>
			/// 行情对象
			/// </summary>
			public ref class MdAdapter
			{
			private:
				/// <summary>
				/// 行情命令请求
				/// </summary>
				CThostFtdcMdApi* m_pApi;

				/// <summary>
				/// 行情命令响应
				/// </summary>
				CMdSpi* m_pSpi;

				/// <summary>
				/// 可以动态解析的程序集
				/// </summary>
				array<System::Reflection::Assembly^>^ m_ppAssembly;

				/// <summary>
				/// 动态解析程序集
				/// </summary>
				System::Reflection::Assembly ^ OnAssemblyResolve(System::Object ^sender, System::ResolveEventArgs ^args);

			protected:
				/// <summary>
				/// 行情对象析构函数
				/// </summary>
				~MdAdapter();

			public:
				/// <summary>
				/// 行情对象
				/// </summary>
				MdAdapter();

				/// <summary>
				/// 行情对象
				/// </summary>
				MdAdapter(String^ pszFlowPath, bool bIsUsingUdp);

				/// <summary>
				/// 行情对象
				/// </summary>
				MdAdapter(String^ pszFlowPath, bool bIsUsingUdp, bool bIsMulticast);

				/// <summary>
				/// 设置可以动态解析的程序集(内部使用)
				/// </summary>
				void SetAssembly(array<System::Reflection::Assembly^>^ assm);

			internal:

			    //当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
			    FrontConnected^ OnFrontConnected_delegate;

			    //当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
			    FrontDisconnected^ OnFrontDisconnected_delegate;

			    //心跳超时警告。当长时间未收到报文时，该方法被调用。
			    HeartBeatWarning^ OnHeartBeatWarning_delegate;

			    //登录请求响应
			    RspUserLogin^ OnRspUserLogin_delegate;

			    //登出请求响应
			    RspUserLogout^ OnRspUserLogout_delegate;

			    //错误应答
			    RspError^ OnRspError_delegate;

			    //询价通知
			    RtnForQuoteRsp^ OnRtnForQuoteRsp_delegate;

			    //订阅行情应答
			    RspSubMarketData^ OnRspSubMarketData_delegate;

			    //取消订阅行情应答
			    RspUnSubMarketData^ OnRspUnSubMarketData_delegate;

			    //订阅询价应答
			    RspSubForQuoteRsp^ OnRspSubForQuoteRsp_delegate;

			    //取消订阅询价应答
			    RspUnSubForQuoteRsp^ OnRspUnSubForQuoteRsp_delegate;

			    //深度行情通知
			    RtnDepthMarketData^ OnRtnDepthMarketData_delegate;

		    public:

			    // 删除接口对象本身
			    // 不再使用本接口对象时,调用该函数删除接口对象
			    void Release();

			    // 初始化
			    // 初始化运行环境,只有调用后,接口才开始工作
			    void Init();

			    // 等待接口线程结束运行
			    // @return 线程退出代码
			    int Join();

			    // 获取当前交易日
			    // @retrun 获取到的交易日
			    // 只有登录成功后,才能得到正确的交易日
			    String^ GetTradingDay();

			    // 注册前置机网络地址
			    // pszFrontAddress：前置机网络地址。
			    // 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。
			    // “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。
			    void RegisterFront(String^ pszFrontAddress);

			    // 注册名字服务器网络地址
			    // pszNsAddress：名字服务器网络地址。
			    // 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:12001”。
			    // “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”12001”代表服务器端口号。
			    // RegisterNameServer优先于RegisterFront
			    void RegisterNameServer(String^ pszNsAddress);

			    // 注册名字服务器用户信息
			    // pFensUserInfo：用户信息。
			    void RegisterFensUserInfo(CtpNetFensUserInfoField^ pFensUserInfo);

			    // 注册回调接口
			    // pSpi 派生自回调接口类的实例
			    // void RegisterSpi(CtpNetMdSpi *pSpi);

			    // 订阅行情。
			    // ppInstrumentID 合约ID
			    // nCount 要订阅/退订行情的合约个数
			    int SubscribeMarketData(array<String^>^ ppInstrumentID);

			    // 退订行情。
			    // ppInstrumentID 合约ID
			    // nCount 要订阅/退订行情的合约个数
			    int UnSubscribeMarketData(array<String^>^ ppInstrumentID);

			    // 订阅询价。
			    // ppInstrumentID 合约ID
			    // nCount 要订阅/退订行情的合约个数
			    int SubscribeForQuoteRsp(array<String^>^ ppInstrumentID);

			    // 退订询价。
			    // ppInstrumentID 合约ID
			    // nCount 要订阅/退订行情的合约个数
			    int UnSubscribeForQuoteRsp(array<String^>^ ppInstrumentID);

			    // 用户登录请求
			    int ReqUserLogin(CtpNetReqUserLoginField^ pReqUserLoginField, int nRequestID);

			    // 登出请求
			    int ReqUserLogout(CtpNetUserLogoutField^ pUserLogout, int nRequestID);

			    /// <summary>
			    /// 当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
			    /// </summary>
			    event FrontConnected^ OnFrontConnected
			    {
				    void add(FrontConnected^ handler)
				    {
					    OnFrontConnected_delegate += handler;
				    }
				    void remove(FrontConnected^ handler)
				    {
					    OnFrontConnected_delegate -= handler;
				    }
			    internal:
				    void raise()
				    {
					    if (OnFrontConnected_delegate)
						    OnFrontConnected_delegate();
				    }
			    }

			    /// <summary>
			    /// 当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
			    /// </summary>
			    event FrontDisconnected^ OnFrontDisconnected
			    {
				    void add(FrontDisconnected^ handler)
				    {
					    OnFrontDisconnected_delegate += handler;
				    }
				    void remove(FrontDisconnected^ handler)
				    {
					    OnFrontDisconnected_delegate -= handler;
				    }
			    internal:
				    void raise(int nReason)
				    {
					    if (OnFrontDisconnected_delegate)
						    OnFrontDisconnected_delegate(nReason);
				    }
			    }

			    /// <summary>
			    /// 心跳超时警告。当长时间未收到报文时，该方法被调用。
			    /// </summary>
			    event HeartBeatWarning^ OnHeartBeatWarning
			    {
				    void add(HeartBeatWarning^ handler)
				    {
					    OnHeartBeatWarning_delegate += handler;
				    }
				    void remove(HeartBeatWarning^ handler)
				    {
					    OnHeartBeatWarning_delegate -= handler;
				    }
			    internal:
				    void raise(int nTimeLapse)
				    {
					    if (OnHeartBeatWarning_delegate)
						    OnHeartBeatWarning_delegate(nTimeLapse);
				    }
			    }

			    /// <summary>
			    /// 登录请求响应
			    /// </summary>
			    event RspUserLogin^ OnRspUserLogin
			    {
				    void add(RspUserLogin^ handler)
				    {
					    OnRspUserLogin_delegate += handler;
				    }
				    void remove(RspUserLogin^ handler)
				    {
					    OnRspUserLogin_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetRspUserLoginField^ pRspUserLogin, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspUserLogin_delegate)
						    OnRspUserLogin_delegate(pRspUserLogin, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 登出请求响应
			    /// </summary>
			    event RspUserLogout^ OnRspUserLogout
			    {
				    void add(RspUserLogout^ handler)
				    {
					    OnRspUserLogout_delegate += handler;
				    }
				    void remove(RspUserLogout^ handler)
				    {
					    OnRspUserLogout_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetUserLogoutField^ pUserLogout, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspUserLogout_delegate)
						    OnRspUserLogout_delegate(pUserLogout, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 错误应答
			    /// </summary>
			    event RspError^ OnRspError
			    {
				    void add(RspError^ handler)
				    {
					    OnRspError_delegate += handler;
				    }
				    void remove(RspError^ handler)
				    {
					    OnRspError_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspError_delegate)
						    OnRspError_delegate(pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 询价通知
			    /// </summary>
			    event RtnForQuoteRsp^ OnRtnForQuoteRsp
			    {
				    void add(RtnForQuoteRsp^ handler)
				    {
					    OnRtnForQuoteRsp_delegate += handler;
				    }
				    void remove(RtnForQuoteRsp^ handler)
				    {
					    OnRtnForQuoteRsp_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetForQuoteRspField^ pForQuoteRsp)
				    {
					    if (OnRtnForQuoteRsp_delegate)
						    OnRtnForQuoteRsp_delegate(pForQuoteRsp);
				    }
			    }

			    /// <summary>
			    /// 订阅行情应答
			    /// </summary>
			    event RspSubMarketData^ OnRspSubMarketData
			    {
				    void add(RspSubMarketData^ handler)
				    {
					    OnRspSubMarketData_delegate += handler;
				    }
				    void remove(RspSubMarketData^ handler)
				    {
					    OnRspSubMarketData_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetSpecificInstrumentField^ pSpecificInstrument, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspSubMarketData_delegate)
						    OnRspSubMarketData_delegate(pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 取消订阅行情应答
			    /// </summary>
			    event RspUnSubMarketData^ OnRspUnSubMarketData
			    {
				    void add(RspUnSubMarketData^ handler)
				    {
					    OnRspUnSubMarketData_delegate += handler;
				    }
				    void remove(RspUnSubMarketData^ handler)
				    {
					    OnRspUnSubMarketData_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetSpecificInstrumentField^ pSpecificInstrument, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspUnSubMarketData_delegate)
						    OnRspUnSubMarketData_delegate(pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 订阅询价应答
			    /// </summary>
			    event RspSubForQuoteRsp^ OnRspSubForQuoteRsp
			    {
				    void add(RspSubForQuoteRsp^ handler)
				    {
					    OnRspSubForQuoteRsp_delegate += handler;
				    }
				    void remove(RspSubForQuoteRsp^ handler)
				    {
					    OnRspSubForQuoteRsp_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetSpecificInstrumentField^ pSpecificInstrument, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspSubForQuoteRsp_delegate)
						    OnRspSubForQuoteRsp_delegate(pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 取消订阅询价应答
			    /// </summary>
			    event RspUnSubForQuoteRsp^ OnRspUnSubForQuoteRsp
			    {
				    void add(RspUnSubForQuoteRsp^ handler)
				    {
					    OnRspUnSubForQuoteRsp_delegate += handler;
				    }
				    void remove(RspUnSubForQuoteRsp^ handler)
				    {
					    OnRspUnSubForQuoteRsp_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetSpecificInstrumentField^ pSpecificInstrument, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspUnSubForQuoteRsp_delegate)
						    OnRspUnSubForQuoteRsp_delegate(pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 深度行情通知
			    /// </summary>
			    event RtnDepthMarketData^ OnRtnDepthMarketData
			    {
				    void add(RtnDepthMarketData^ handler)
				    {
					    OnRtnDepthMarketData_delegate += handler;
				    }
				    void remove(RtnDepthMarketData^ handler)
				    {
					    OnRtnDepthMarketData_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetDepthMarketDataField^ pDepthMarketData)
				    {
					    if (OnRtnDepthMarketData_delegate)
						    OnRtnDepthMarketData_delegate(pDepthMarketData);
				    }
			    }
		    };
		};
	};
};
