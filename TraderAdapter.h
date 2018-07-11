#pragma once

#include "Util.h"
#include "ThostFtdcTraderApi.h"
//#include "Delegate.h"

using namespace Native;

namespace Native
{
	// 交易命令响应
	class CTraderSpi;
};

namespace TaiTanXing
{
	namespace Ctp
	{
		namespace CtpProxy
		{
			/// <summary>
			/// 交易对象
			/// </summary>
			public ref class TraderAdapter
			{
			private:
				/// <summary>
				/// 交易命令请求
				/// </summary>
				CThostFtdcTraderApi* m_pApi;

				/// <summary>
				/// 交易命令响应
				/// </summary>
				CTraderSpi* m_pSpi;

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
				/// 交易对象析构函数
				/// </summary>
				~TraderAdapter();

			public:
				/// <summary>
				/// 交易对象
				/// </summary>
				TraderAdapter();

				/// <summary>
				/// 交易对象
				/// </summary>
				TraderAdapter(String^ pszFlowPath);

				/// <summary>
				/// 交易对象
				/// </summary>
				TraderAdapter(String^ pszFlowPath, bool bIsUsingUdp);

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

			    //客户端认证响应
			    RspAuthenticate^ OnRspAuthenticate_delegate;

			    //用户口令更新请求响应
			    RspUserPasswordUpdate^ OnRspUserPasswordUpdate_delegate;

			    //资金账户口令更新请求响应
			    RspTradingAccountPasswordUpdate^ OnRspTradingAccountPasswordUpdate_delegate;

			    //报单录入请求响应
			    RspOrderInsert^ OnRspOrderInsert_delegate;

			    //预埋单录入请求响应
			    RspParkedOrderInsert^ OnRspParkedOrderInsert_delegate;

			    //预埋撤单录入请求响应
			    RspParkedOrderAction^ OnRspParkedOrderAction_delegate;

			    //报单操作请求响应
			    RspOrderAction^ OnRspOrderAction_delegate;

			    //查询最大报单数量响应
			    RspQueryMaxOrderVolume^ OnRspQueryMaxOrderVolume_delegate;

			    //投资者结算结果确认响应
			    RspSettlementInfoConfirm^ OnRspSettlementInfoConfirm_delegate;

			    //删除预埋单响应
			    RspRemoveParkedOrder^ OnRspRemoveParkedOrder_delegate;

			    //删除预埋撤单响应
			    RspRemoveParkedOrderAction^ OnRspRemoveParkedOrderAction_delegate;

			    //执行宣告录入请求响应
			    RspExecOrderInsert^ OnRspExecOrderInsert_delegate;

			    //执行宣告操作请求响应
			    RspExecOrderAction^ OnRspExecOrderAction_delegate;

			    //询价录入请求响应
			    RspForQuoteInsert^ OnRspForQuoteInsert_delegate;

			    //报价录入请求响应
			    RspQuoteInsert^ OnRspQuoteInsert_delegate;

			    //报价操作请求响应
			    RspQuoteAction^ OnRspQuoteAction_delegate;

			    //批量报单操作请求响应
			    RspBatchOrderAction^ OnRspBatchOrderAction_delegate;

			    //期权自对冲录入请求响应
			    RspOptionSelfCloseInsert^ OnRspOptionSelfCloseInsert_delegate;

			    //期权自对冲操作请求响应
			    RspOptionSelfCloseAction^ OnRspOptionSelfCloseAction_delegate;

			    //申请组合录入请求响应
			    RspCombActionInsert^ OnRspCombActionInsert_delegate;

			    //请求查询报单响应
			    RspQryOrder^ OnRspQryOrder_delegate;

			    //请求查询成交响应
			    RspQryTrade^ OnRspQryTrade_delegate;

			    //请求查询投资者持仓响应
			    RspQryInvestorPosition^ OnRspQryInvestorPosition_delegate;

			    //请求查询资金账户响应
			    RspQryTradingAccount^ OnRspQryTradingAccount_delegate;

			    //请求查询投资者响应
			    RspQryInvestor^ OnRspQryInvestor_delegate;

			    //请求查询交易编码响应
			    RspQryTradingCode^ OnRspQryTradingCode_delegate;

			    //请求查询合约保证金率响应
			    RspQryInstrumentMarginRate^ OnRspQryInstrumentMarginRate_delegate;

			    //请求查询合约手续费率响应
			    RspQryInstrumentCommissionRate^ OnRspQryInstrumentCommissionRate_delegate;

			    //请求查询交易所响应
			    RspQryExchange^ OnRspQryExchange_delegate;

			    //请求查询产品响应
			    RspQryProduct^ OnRspQryProduct_delegate;

			    //请求查询合约响应
			    RspQryInstrument^ OnRspQryInstrument_delegate;

			    //请求查询行情响应
			    RspQryDepthMarketData^ OnRspQryDepthMarketData_delegate;

			    //请求查询投资者结算结果响应
			    RspQrySettlementInfo^ OnRspQrySettlementInfo_delegate;

			    //请求查询转帐银行响应
			    RspQryTransferBank^ OnRspQryTransferBank_delegate;

			    //请求查询投资者持仓明细响应
			    RspQryInvestorPositionDetail^ OnRspQryInvestorPositionDetail_delegate;

			    //请求查询客户通知响应
			    RspQryNotice^ OnRspQryNotice_delegate;

			    //请求查询结算信息确认响应
			    RspQrySettlementInfoConfirm^ OnRspQrySettlementInfoConfirm_delegate;

			    //请求查询投资者持仓明细响应
			    RspQryInvestorPositionCombineDetail^ OnRspQryInvestorPositionCombineDetail_delegate;

			    //查询保证金监管系统经纪公司资金账户密钥响应
			    RspQryCFMMCTradingAccountKey^ OnRspQryCFMMCTradingAccountKey_delegate;

			    //请求查询仓单折抵信息响应
			    RspQryEWarrantOffset^ OnRspQryEWarrantOffset_delegate;

			    //请求查询投资者品种/跨品种保证金响应
			    RspQryInvestorProductGroupMargin^ OnRspQryInvestorProductGroupMargin_delegate;

			    //请求查询交易所保证金率响应
			    RspQryExchangeMarginRate^ OnRspQryExchangeMarginRate_delegate;

			    //请求查询交易所调整保证金率响应
			    RspQryExchangeMarginRateAdjust^ OnRspQryExchangeMarginRateAdjust_delegate;

			    //请求查询汇率响应
			    RspQryExchangeRate^ OnRspQryExchangeRate_delegate;

			    //请求查询二级代理操作员银期权限响应
			    RspQrySecAgentACIDMap^ OnRspQrySecAgentACIDMap_delegate;

			    //请求查询产品报价汇率
			    RspQryProductExchRate^ OnRspQryProductExchRate_delegate;

			    //请求查询产品组
			    RspQryProductGroup^ OnRspQryProductGroup_delegate;

			    //请求查询做市商合约手续费率响应
			    RspQryMMInstrumentCommissionRate^ OnRspQryMMInstrumentCommissionRate_delegate;

			    //请求查询做市商期权合约手续费响应
			    RspQryMMOptionInstrCommRate^ OnRspQryMMOptionInstrCommRate_delegate;

			    //请求查询报单手续费响应
			    RspQryInstrumentOrderCommRate^ OnRspQryInstrumentOrderCommRate_delegate;

			    //请求查询资金账户响应
			    RspQrySecAgentTradingAccount^ OnRspQrySecAgentTradingAccount_delegate;

			    //请求查询二级代理商资金校验模式响应
			    RspQrySecAgentCheckMode^ OnRspQrySecAgentCheckMode_delegate;

			    //请求查询期权交易成本响应
			    RspQryOptionInstrTradeCost^ OnRspQryOptionInstrTradeCost_delegate;

			    //请求查询期权合约手续费响应
			    RspQryOptionInstrCommRate^ OnRspQryOptionInstrCommRate_delegate;

			    //请求查询执行宣告响应
			    RspQryExecOrder^ OnRspQryExecOrder_delegate;

			    //请求查询询价响应
			    RspQryForQuote^ OnRspQryForQuote_delegate;

			    //请求查询报价响应
			    RspQryQuote^ OnRspQryQuote_delegate;

			    //请求查询期权自对冲响应
			    RspQryOptionSelfClose^ OnRspQryOptionSelfClose_delegate;

			    //请求查询投资单元响应
			    RspQryInvestUnit^ OnRspQryInvestUnit_delegate;

			    //请求查询组合合约安全系数响应
			    RspQryCombInstrumentGuard^ OnRspQryCombInstrumentGuard_delegate;

			    //请求查询申请组合响应
			    RspQryCombAction^ OnRspQryCombAction_delegate;

			    //请求查询转帐流水响应
			    RspQryTransferSerial^ OnRspQryTransferSerial_delegate;

			    //请求查询银期签约关系响应
			    RspQryAccountregister^ OnRspQryAccountregister_delegate;

			    //报单通知
			    RtnOrder^ OnRtnOrder_delegate;

			    //成交通知
			    RtnTrade^ OnRtnTrade_delegate;

			    //报单录入错误回报
			    ErrRtnOrderInsert^ OnErrRtnOrderInsert_delegate;

			    //报单操作错误回报
			    ErrRtnOrderAction^ OnErrRtnOrderAction_delegate;

			    //合约交易状态通知
			    RtnInstrumentStatus^ OnRtnInstrumentStatus_delegate;

			    //交易所公告通知
			    RtnBulletin^ OnRtnBulletin_delegate;

			    //交易通知
			    RtnTradingNotice^ OnRtnTradingNotice_delegate;

			    //提示条件单校验错误
			    RtnErrorConditionalOrder^ OnRtnErrorConditionalOrder_delegate;

			    //执行宣告通知
			    RtnExecOrder^ OnRtnExecOrder_delegate;

			    //执行宣告录入错误回报
			    ErrRtnExecOrderInsert^ OnErrRtnExecOrderInsert_delegate;

			    //执行宣告操作错误回报
			    ErrRtnExecOrderAction^ OnErrRtnExecOrderAction_delegate;

			    //询价录入错误回报
			    ErrRtnForQuoteInsert^ OnErrRtnForQuoteInsert_delegate;

			    //报价通知
			    RtnQuote^ OnRtnQuote_delegate;

			    //报价录入错误回报
			    ErrRtnQuoteInsert^ OnErrRtnQuoteInsert_delegate;

			    //报价操作错误回报
			    ErrRtnQuoteAction^ OnErrRtnQuoteAction_delegate;

			    //保证金监控中心用户令牌
			    RtnCFMMCTradingAccountToken^ OnRtnCFMMCTradingAccountToken_delegate;

			    //批量报单操作错误回报
			    ErrRtnBatchOrderAction^ OnErrRtnBatchOrderAction_delegate;

			    //期权自对冲通知
			    RtnOptionSelfClose^ OnRtnOptionSelfClose_delegate;

			    //期权自对冲录入错误回报
			    ErrRtnOptionSelfCloseInsert^ OnErrRtnOptionSelfCloseInsert_delegate;

			    //期权自对冲操作错误回报
			    ErrRtnOptionSelfCloseAction^ OnErrRtnOptionSelfCloseAction_delegate;

			    //申请组合通知
			    RtnCombAction^ OnRtnCombAction_delegate;

			    //申请组合录入错误回报
			    ErrRtnCombActionInsert^ OnErrRtnCombActionInsert_delegate;

			    //请求查询签约银行响应
			    RspQryContractBank^ OnRspQryContractBank_delegate;

			    //请求查询预埋单响应
			    RspQryParkedOrder^ OnRspQryParkedOrder_delegate;

			    //请求查询预埋撤单响应
			    RspQryParkedOrderAction^ OnRspQryParkedOrderAction_delegate;

			    //请求查询交易通知响应
			    RspQryTradingNotice^ OnRspQryTradingNotice_delegate;

			    //请求查询经纪公司交易参数响应
			    RspQryBrokerTradingParams^ OnRspQryBrokerTradingParams_delegate;

			    //请求查询经纪公司交易算法响应
			    RspQryBrokerTradingAlgos^ OnRspQryBrokerTradingAlgos_delegate;

			    //请求查询监控中心用户令牌
			    RspQueryCFMMCTradingAccountToken^ OnRspQueryCFMMCTradingAccountToken_delegate;

			    //银行发起银行资金转期货通知
			    RtnFromBankToFutureByBank^ OnRtnFromBankToFutureByBank_delegate;

			    //银行发起期货资金转银行通知
			    RtnFromFutureToBankByBank^ OnRtnFromFutureToBankByBank_delegate;

			    //银行发起冲正银行转期货通知
			    RtnRepealFromBankToFutureByBank^ OnRtnRepealFromBankToFutureByBank_delegate;

			    //银行发起冲正期货转银行通知
			    RtnRepealFromFutureToBankByBank^ OnRtnRepealFromFutureToBankByBank_delegate;

			    //期货发起银行资金转期货通知
			    RtnFromBankToFutureByFuture^ OnRtnFromBankToFutureByFuture_delegate;

			    //期货发起期货资金转银行通知
			    RtnFromFutureToBankByFuture^ OnRtnFromFutureToBankByFuture_delegate;

			    //系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
			    RtnRepealFromBankToFutureByFutureManual^ OnRtnRepealFromBankToFutureByFutureManual_delegate;

			    //系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
			    RtnRepealFromFutureToBankByFutureManual^ OnRtnRepealFromFutureToBankByFutureManual_delegate;

			    //期货发起查询银行余额通知
			    RtnQueryBankBalanceByFuture^ OnRtnQueryBankBalanceByFuture_delegate;

			    //期货发起银行资金转期货错误回报
			    ErrRtnBankToFutureByFuture^ OnErrRtnBankToFutureByFuture_delegate;

			    //期货发起期货资金转银行错误回报
			    ErrRtnFutureToBankByFuture^ OnErrRtnFutureToBankByFuture_delegate;

			    //系统运行时期货端手工发起冲正银行转期货错误回报
			    ErrRtnRepealBankToFutureByFutureManual^ OnErrRtnRepealBankToFutureByFutureManual_delegate;

			    //系统运行时期货端手工发起冲正期货转银行错误回报
			    ErrRtnRepealFutureToBankByFutureManual^ OnErrRtnRepealFutureToBankByFutureManual_delegate;

			    //期货发起查询银行余额错误回报
			    ErrRtnQueryBankBalanceByFuture^ OnErrRtnQueryBankBalanceByFuture_delegate;

			    //期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
			    RtnRepealFromBankToFutureByFuture^ OnRtnRepealFromBankToFutureByFuture_delegate;

			    //期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
			    RtnRepealFromFutureToBankByFuture^ OnRtnRepealFromFutureToBankByFuture_delegate;

			    //期货发起银行资金转期货应答
			    RspFromBankToFutureByFuture^ OnRspFromBankToFutureByFuture_delegate;

			    //期货发起期货资金转银行应答
			    RspFromFutureToBankByFuture^ OnRspFromFutureToBankByFuture_delegate;

			    //期货发起查询银行余额应答
			    RspQueryBankAccountMoneyByFuture^ OnRspQueryBankAccountMoneyByFuture_delegate;

			    //银行发起银期开户通知
			    RtnOpenAccountByBank^ OnRtnOpenAccountByBank_delegate;

			    //银行发起银期销户通知
			    RtnCancelAccountByBank^ OnRtnCancelAccountByBank_delegate;

			    //银行发起变更银行账号通知
			    RtnChangeAccountByBank^ OnRtnChangeAccountByBank_delegate;

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
			    // void RegisterSpi(CtpNetTraderSpi *pSpi);

			    // 订阅私有流。
			    // nResumeType 私有流重传方式
			    //         THOST_TERT_RESTART:从本交易日开始重传
			    //         THOST_TERT_RESUME:从上次收到的续传
			    //         THOST_TERT_QUICK:只传送登录后私有流的内容
			    // 该方法要在Init方法前调用。若不调用则不会收到私有流的数据。
			    void SubscribePrivateTopic(CtpNetResumeType nResumeType);

			    // 订阅公共流。
			    // nResumeType 公共流重传方式
			    //         THOST_TERT_RESTART:从本交易日开始重传
			    //         THOST_TERT_RESUME:从上次收到的续传
			    //         THOST_TERT_QUICK:只传送登录后公共流的内容
			    // 该方法要在Init方法前调用。若不调用则不会收到公共流的数据。
			    void SubscribePublicTopic(CtpNetResumeType nResumeType);

			    // 客户端认证请求
			    int ReqAuthenticate(CtpNetReqAuthenticateField^ pReqAuthenticateField, int nRequestID);

			    // 用户登录请求
			    int ReqUserLogin(CtpNetReqUserLoginField^ pReqUserLoginField, int nRequestID);

			    // 登出请求
			    int ReqUserLogout(CtpNetUserLogoutField^ pUserLogout, int nRequestID);

			    // 用户口令更新请求
			    int ReqUserPasswordUpdate(CtpNetUserPasswordUpdateField^ pUserPasswordUpdate, int nRequestID);

			    // 资金账户口令更新请求
			    int ReqTradingAccountPasswordUpdate(CtpNetTradingAccountPasswordUpdateField^ pTradingAccountPasswordUpdate, int nRequestID);

			    // 登录请求2
			    int ReqUserLogin2(CtpNetReqUserLoginField^ pReqUserLogin, int nRequestID);

			    // 用户口令更新请求2
			    int ReqUserPasswordUpdate2(CtpNetUserPasswordUpdateField^ pUserPasswordUpdate, int nRequestID);

			    // 报单录入请求
			    int ReqOrderInsert(CtpNetInputOrderField^ pInputOrder, int nRequestID);

			    // 预埋单录入请求
			    int ReqParkedOrderInsert(CtpNetParkedOrderField^ pParkedOrder, int nRequestID);

			    // 预埋撤单录入请求
			    int ReqParkedOrderAction(CtpNetParkedOrderActionField^ pParkedOrderAction, int nRequestID);

			    // 报单操作请求
			    int ReqOrderAction(CtpNetInputOrderActionField^ pInputOrderAction, int nRequestID);

			    // 查询最大报单数量请求
			    int ReqQueryMaxOrderVolume(CtpNetQueryMaxOrderVolumeField^ pQueryMaxOrderVolume, int nRequestID);

			    // 投资者结算结果确认
			    int ReqSettlementInfoConfirm(CtpNetSettlementInfoConfirmField^ pSettlementInfoConfirm, int nRequestID);

			    // 请求删除预埋单
			    int ReqRemoveParkedOrder(CtpNetRemoveParkedOrderField^ pRemoveParkedOrder, int nRequestID);

			    // 请求删除预埋撤单
			    int ReqRemoveParkedOrderAction(CtpNetRemoveParkedOrderActionField^ pRemoveParkedOrderAction, int nRequestID);

			    // 执行宣告录入请求
			    int ReqExecOrderInsert(CtpNetInputExecOrderField^ pInputExecOrder, int nRequestID);

			    // 执行宣告操作请求
			    int ReqExecOrderAction(CtpNetInputExecOrderActionField^ pInputExecOrderAction, int nRequestID);

			    // 询价录入请求
			    int ReqForQuoteInsert(CtpNetInputForQuoteField^ pInputForQuote, int nRequestID);

			    // 报价录入请求
			    int ReqQuoteInsert(CtpNetInputQuoteField^ pInputQuote, int nRequestID);

			    // 报价操作请求
			    int ReqQuoteAction(CtpNetInputQuoteActionField^ pInputQuoteAction, int nRequestID);

			    // 批量报单操作请求
			    int ReqBatchOrderAction(CtpNetInputBatchOrderActionField^ pInputBatchOrderAction, int nRequestID);

			    // 期权自对冲录入请求
			    int ReqOptionSelfCloseInsert(CtpNetInputOptionSelfCloseField^ pInputOptionSelfClose, int nRequestID);

			    // 期权自对冲操作请求
			    int ReqOptionSelfCloseAction(CtpNetInputOptionSelfCloseActionField^ pInputOptionSelfCloseAction, int nRequestID);

			    // 申请组合录入请求
			    int ReqCombActionInsert(CtpNetInputCombActionField^ pInputCombAction, int nRequestID);

			    // 请求查询报单
			    int ReqQryOrder(CtpNetQryOrderField^ pQryOrder, int nRequestID);

			    // 请求查询成交
			    int ReqQryTrade(CtpNetQryTradeField^ pQryTrade, int nRequestID);

			    // 请求查询投资者持仓
			    int ReqQryInvestorPosition(CtpNetQryInvestorPositionField^ pQryInvestorPosition, int nRequestID);

			    // 请求查询资金账户
			    int ReqQryTradingAccount(CtpNetQryTradingAccountField^ pQryTradingAccount, int nRequestID);

			    // 请求查询投资者
			    int ReqQryInvestor(CtpNetQryInvestorField^ pQryInvestor, int nRequestID);

			    // 请求查询交易编码
			    int ReqQryTradingCode(CtpNetQryTradingCodeField^ pQryTradingCode, int nRequestID);

			    // 请求查询合约保证金率
			    int ReqQryInstrumentMarginRate(CtpNetQryInstrumentMarginRateField^ pQryInstrumentMarginRate, int nRequestID);

			    // 请求查询合约手续费率
			    int ReqQryInstrumentCommissionRate(CtpNetQryInstrumentCommissionRateField^ pQryInstrumentCommissionRate, int nRequestID);

			    // 请求查询交易所
			    int ReqQryExchange(CtpNetQryExchangeField^ pQryExchange, int nRequestID);

			    // 请求查询产品
			    int ReqQryProduct(CtpNetQryProductField^ pQryProduct, int nRequestID);

			    // 请求查询合约
			    int ReqQryInstrument(CtpNetQryInstrumentField^ pQryInstrument, int nRequestID);

			    // 请求查询行情
			    int ReqQryDepthMarketData(CtpNetQryDepthMarketDataField^ pQryDepthMarketData, int nRequestID);

			    // 请求查询投资者结算结果
			    int ReqQrySettlementInfo(CtpNetQrySettlementInfoField^ pQrySettlementInfo, int nRequestID);

			    // 请求查询转帐银行
			    int ReqQryTransferBank(CtpNetQryTransferBankField^ pQryTransferBank, int nRequestID);

			    // 请求查询投资者持仓明细
			    int ReqQryInvestorPositionDetail(CtpNetQryInvestorPositionDetailField^ pQryInvestorPositionDetail, int nRequestID);

			    // 请求查询客户通知
			    int ReqQryNotice(CtpNetQryNoticeField^ pQryNotice, int nRequestID);

			    // 请求查询结算信息确认
			    int ReqQrySettlementInfoConfirm(CtpNetQrySettlementInfoConfirmField^ pQrySettlementInfoConfirm, int nRequestID);

			    // 请求查询投资者持仓明细
			    int ReqQryInvestorPositionCombineDetail(CtpNetQryInvestorPositionCombineDetailField^ pQryInvestorPositionCombineDetail, int nRequestID);

			    // 请求查询保证金监管系统经纪公司资金账户密钥
			    int ReqQryCFMMCTradingAccountKey(CtpNetQryCFMMCTradingAccountKeyField^ pQryCFMMCTradingAccountKey, int nRequestID);

			    // 请求查询仓单折抵信息
			    int ReqQryEWarrantOffset(CtpNetQryEWarrantOffsetField^ pQryEWarrantOffset, int nRequestID);

			    // 请求查询投资者品种/跨品种保证金
			    int ReqQryInvestorProductGroupMargin(CtpNetQryInvestorProductGroupMarginField^ pQryInvestorProductGroupMargin, int nRequestID);

			    // 请求查询交易所保证金率
			    int ReqQryExchangeMarginRate(CtpNetQryExchangeMarginRateField^ pQryExchangeMarginRate, int nRequestID);

			    // 请求查询交易所调整保证金率
			    int ReqQryExchangeMarginRateAdjust(CtpNetQryExchangeMarginRateAdjustField^ pQryExchangeMarginRateAdjust, int nRequestID);

			    // 请求查询汇率
			    int ReqQryExchangeRate(CtpNetQryExchangeRateField^ pQryExchangeRate, int nRequestID);

			    // 请求查询二级代理操作员银期权限
			    int ReqQrySecAgentACIDMap(CtpNetQrySecAgentACIDMapField^ pQrySecAgentACIDMap, int nRequestID);

			    // 请求查询产品报价汇率
			    int ReqQryProductExchRate(CtpNetQryProductExchRateField^ pQryProductExchRate, int nRequestID);

			    // 请求查询产品组
			    int ReqQryProductGroup(CtpNetQryProductGroupField^ pQryProductGroup, int nRequestID);

			    // 请求查询做市商合约手续费率
			    int ReqQryMMInstrumentCommissionRate(CtpNetQryMMInstrumentCommissionRateField^ pQryMMInstrumentCommissionRate, int nRequestID);

			    // 请求查询做市商期权合约手续费
			    int ReqQryMMOptionInstrCommRate(CtpNetQryMMOptionInstrCommRateField^ pQryMMOptionInstrCommRate, int nRequestID);

			    // 请求查询报单手续费
			    int ReqQryInstrumentOrderCommRate(CtpNetQryInstrumentOrderCommRateField^ pQryInstrumentOrderCommRate, int nRequestID);

			    // 请求查询资金账户
			    int ReqQrySecAgentTradingAccount(CtpNetQryTradingAccountField^ pQryTradingAccount, int nRequestID);

			    // 请求查询二级代理商资金校验模式
			    int ReqQrySecAgentCheckMode(CtpNetQrySecAgentCheckModeField^ pQrySecAgentCheckMode, int nRequestID);

			    // 请求查询期权交易成本
			    int ReqQryOptionInstrTradeCost(CtpNetQryOptionInstrTradeCostField^ pQryOptionInstrTradeCost, int nRequestID);

			    // 请求查询期权合约手续费
			    int ReqQryOptionInstrCommRate(CtpNetQryOptionInstrCommRateField^ pQryOptionInstrCommRate, int nRequestID);

			    // 请求查询执行宣告
			    int ReqQryExecOrder(CtpNetQryExecOrderField^ pQryExecOrder, int nRequestID);

			    // 请求查询询价
			    int ReqQryForQuote(CtpNetQryForQuoteField^ pQryForQuote, int nRequestID);

			    // 请求查询报价
			    int ReqQryQuote(CtpNetQryQuoteField^ pQryQuote, int nRequestID);

			    // 请求查询期权自对冲
			    int ReqQryOptionSelfClose(CtpNetQryOptionSelfCloseField^ pQryOptionSelfClose, int nRequestID);

			    // 请求查询投资单元
			    int ReqQryInvestUnit(CtpNetQryInvestUnitField^ pQryInvestUnit, int nRequestID);

			    // 请求查询组合合约安全系数
			    int ReqQryCombInstrumentGuard(CtpNetQryCombInstrumentGuardField^ pQryCombInstrumentGuard, int nRequestID);

			    // 请求查询申请组合
			    int ReqQryCombAction(CtpNetQryCombActionField^ pQryCombAction, int nRequestID);

			    // 请求查询转帐流水
			    int ReqQryTransferSerial(CtpNetQryTransferSerialField^ pQryTransferSerial, int nRequestID);

			    // 请求查询银期签约关系
			    int ReqQryAccountregister(CtpNetQryAccountregisterField^ pQryAccountregister, int nRequestID);

			    // 请求查询签约银行
			    int ReqQryContractBank(CtpNetQryContractBankField^ pQryContractBank, int nRequestID);

			    // 请求查询预埋单
			    int ReqQryParkedOrder(CtpNetQryParkedOrderField^ pQryParkedOrder, int nRequestID);

			    // 请求查询预埋撤单
			    int ReqQryParkedOrderAction(CtpNetQryParkedOrderActionField^ pQryParkedOrderAction, int nRequestID);

			    // 请求查询交易通知
			    int ReqQryTradingNotice(CtpNetQryTradingNoticeField^ pQryTradingNotice, int nRequestID);

			    // 请求查询经纪公司交易参数
			    int ReqQryBrokerTradingParams(CtpNetQryBrokerTradingParamsField^ pQryBrokerTradingParams, int nRequestID);

			    // 请求查询经纪公司交易算法
			    int ReqQryBrokerTradingAlgos(CtpNetQryBrokerTradingAlgosField^ pQryBrokerTradingAlgos, int nRequestID);

			    // 请求查询监控中心用户令牌
			    int ReqQueryCFMMCTradingAccountToken(CtpNetQueryCFMMCTradingAccountTokenField^ pQueryCFMMCTradingAccountToken, int nRequestID);

			    // 期货发起银行资金转期货请求
			    int ReqFromBankToFutureByFuture(CtpNetReqTransferField^ pReqTransfer, int nRequestID);

			    // 期货发起期货资金转银行请求
			    int ReqFromFutureToBankByFuture(CtpNetReqTransferField^ pReqTransfer, int nRequestID);

			    // 期货发起查询银行余额请求
			    int ReqQueryBankAccountMoneyByFuture(CtpNetReqQueryAccountField^ pReqQueryAccount, int nRequestID);

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
			    /// 客户端认证响应
			    /// </summary>
			    event RspAuthenticate^ OnRspAuthenticate
			    {
				    void add(RspAuthenticate^ handler)
				    {
					    OnRspAuthenticate_delegate += handler;
				    }
				    void remove(RspAuthenticate^ handler)
				    {
					    OnRspAuthenticate_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetRspAuthenticateField^ pRspAuthenticateField, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspAuthenticate_delegate)
						    OnRspAuthenticate_delegate(pRspAuthenticateField, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 用户口令更新请求响应
			    /// </summary>
			    event RspUserPasswordUpdate^ OnRspUserPasswordUpdate
			    {
				    void add(RspUserPasswordUpdate^ handler)
				    {
					    OnRspUserPasswordUpdate_delegate += handler;
				    }
				    void remove(RspUserPasswordUpdate^ handler)
				    {
					    OnRspUserPasswordUpdate_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetUserPasswordUpdateField^ pUserPasswordUpdate, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspUserPasswordUpdate_delegate)
						    OnRspUserPasswordUpdate_delegate(pUserPasswordUpdate, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 资金账户口令更新请求响应
			    /// </summary>
			    event RspTradingAccountPasswordUpdate^ OnRspTradingAccountPasswordUpdate
			    {
				    void add(RspTradingAccountPasswordUpdate^ handler)
				    {
					    OnRspTradingAccountPasswordUpdate_delegate += handler;
				    }
				    void remove(RspTradingAccountPasswordUpdate^ handler)
				    {
					    OnRspTradingAccountPasswordUpdate_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetTradingAccountPasswordUpdateField^ pTradingAccountPasswordUpdate, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspTradingAccountPasswordUpdate_delegate)
						    OnRspTradingAccountPasswordUpdate_delegate(pTradingAccountPasswordUpdate, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 报单录入请求响应
			    /// </summary>
			    event RspOrderInsert^ OnRspOrderInsert
			    {
				    void add(RspOrderInsert^ handler)
				    {
					    OnRspOrderInsert_delegate += handler;
				    }
				    void remove(RspOrderInsert^ handler)
				    {
					    OnRspOrderInsert_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetInputOrderField^ pInputOrder, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspOrderInsert_delegate)
						    OnRspOrderInsert_delegate(pInputOrder, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 预埋单录入请求响应
			    /// </summary>
			    event RspParkedOrderInsert^ OnRspParkedOrderInsert
			    {
				    void add(RspParkedOrderInsert^ handler)
				    {
					    OnRspParkedOrderInsert_delegate += handler;
				    }
				    void remove(RspParkedOrderInsert^ handler)
				    {
					    OnRspParkedOrderInsert_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetParkedOrderField^ pParkedOrder, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspParkedOrderInsert_delegate)
						    OnRspParkedOrderInsert_delegate(pParkedOrder, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 预埋撤单录入请求响应
			    /// </summary>
			    event RspParkedOrderAction^ OnRspParkedOrderAction
			    {
				    void add(RspParkedOrderAction^ handler)
				    {
					    OnRspParkedOrderAction_delegate += handler;
				    }
				    void remove(RspParkedOrderAction^ handler)
				    {
					    OnRspParkedOrderAction_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetParkedOrderActionField^ pParkedOrderAction, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspParkedOrderAction_delegate)
						    OnRspParkedOrderAction_delegate(pParkedOrderAction, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 报单操作请求响应
			    /// </summary>
			    event RspOrderAction^ OnRspOrderAction
			    {
				    void add(RspOrderAction^ handler)
				    {
					    OnRspOrderAction_delegate += handler;
				    }
				    void remove(RspOrderAction^ handler)
				    {
					    OnRspOrderAction_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetInputOrderActionField^ pInputOrderAction, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspOrderAction_delegate)
						    OnRspOrderAction_delegate(pInputOrderAction, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 查询最大报单数量响应
			    /// </summary>
			    event RspQueryMaxOrderVolume^ OnRspQueryMaxOrderVolume
			    {
				    void add(RspQueryMaxOrderVolume^ handler)
				    {
					    OnRspQueryMaxOrderVolume_delegate += handler;
				    }
				    void remove(RspQueryMaxOrderVolume^ handler)
				    {
					    OnRspQueryMaxOrderVolume_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetQueryMaxOrderVolumeField^ pQueryMaxOrderVolume, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQueryMaxOrderVolume_delegate)
						    OnRspQueryMaxOrderVolume_delegate(pQueryMaxOrderVolume, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 投资者结算结果确认响应
			    /// </summary>
			    event RspSettlementInfoConfirm^ OnRspSettlementInfoConfirm
			    {
				    void add(RspSettlementInfoConfirm^ handler)
				    {
					    OnRspSettlementInfoConfirm_delegate += handler;
				    }
				    void remove(RspSettlementInfoConfirm^ handler)
				    {
					    OnRspSettlementInfoConfirm_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetSettlementInfoConfirmField^ pSettlementInfoConfirm, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspSettlementInfoConfirm_delegate)
						    OnRspSettlementInfoConfirm_delegate(pSettlementInfoConfirm, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 删除预埋单响应
			    /// </summary>
			    event RspRemoveParkedOrder^ OnRspRemoveParkedOrder
			    {
				    void add(RspRemoveParkedOrder^ handler)
				    {
					    OnRspRemoveParkedOrder_delegate += handler;
				    }
				    void remove(RspRemoveParkedOrder^ handler)
				    {
					    OnRspRemoveParkedOrder_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetRemoveParkedOrderField^ pRemoveParkedOrder, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspRemoveParkedOrder_delegate)
						    OnRspRemoveParkedOrder_delegate(pRemoveParkedOrder, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 删除预埋撤单响应
			    /// </summary>
			    event RspRemoveParkedOrderAction^ OnRspRemoveParkedOrderAction
			    {
				    void add(RspRemoveParkedOrderAction^ handler)
				    {
					    OnRspRemoveParkedOrderAction_delegate += handler;
				    }
				    void remove(RspRemoveParkedOrderAction^ handler)
				    {
					    OnRspRemoveParkedOrderAction_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetRemoveParkedOrderActionField^ pRemoveParkedOrderAction, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspRemoveParkedOrderAction_delegate)
						    OnRspRemoveParkedOrderAction_delegate(pRemoveParkedOrderAction, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 执行宣告录入请求响应
			    /// </summary>
			    event RspExecOrderInsert^ OnRspExecOrderInsert
			    {
				    void add(RspExecOrderInsert^ handler)
				    {
					    OnRspExecOrderInsert_delegate += handler;
				    }
				    void remove(RspExecOrderInsert^ handler)
				    {
					    OnRspExecOrderInsert_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetInputExecOrderField^ pInputExecOrder, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspExecOrderInsert_delegate)
						    OnRspExecOrderInsert_delegate(pInputExecOrder, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 执行宣告操作请求响应
			    /// </summary>
			    event RspExecOrderAction^ OnRspExecOrderAction
			    {
				    void add(RspExecOrderAction^ handler)
				    {
					    OnRspExecOrderAction_delegate += handler;
				    }
				    void remove(RspExecOrderAction^ handler)
				    {
					    OnRspExecOrderAction_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetInputExecOrderActionField^ pInputExecOrderAction, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspExecOrderAction_delegate)
						    OnRspExecOrderAction_delegate(pInputExecOrderAction, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 询价录入请求响应
			    /// </summary>
			    event RspForQuoteInsert^ OnRspForQuoteInsert
			    {
				    void add(RspForQuoteInsert^ handler)
				    {
					    OnRspForQuoteInsert_delegate += handler;
				    }
				    void remove(RspForQuoteInsert^ handler)
				    {
					    OnRspForQuoteInsert_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetInputForQuoteField^ pInputForQuote, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspForQuoteInsert_delegate)
						    OnRspForQuoteInsert_delegate(pInputForQuote, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 报价录入请求响应
			    /// </summary>
			    event RspQuoteInsert^ OnRspQuoteInsert
			    {
				    void add(RspQuoteInsert^ handler)
				    {
					    OnRspQuoteInsert_delegate += handler;
				    }
				    void remove(RspQuoteInsert^ handler)
				    {
					    OnRspQuoteInsert_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetInputQuoteField^ pInputQuote, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQuoteInsert_delegate)
						    OnRspQuoteInsert_delegate(pInputQuote, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 报价操作请求响应
			    /// </summary>
			    event RspQuoteAction^ OnRspQuoteAction
			    {
				    void add(RspQuoteAction^ handler)
				    {
					    OnRspQuoteAction_delegate += handler;
				    }
				    void remove(RspQuoteAction^ handler)
				    {
					    OnRspQuoteAction_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetInputQuoteActionField^ pInputQuoteAction, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQuoteAction_delegate)
						    OnRspQuoteAction_delegate(pInputQuoteAction, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 批量报单操作请求响应
			    /// </summary>
			    event RspBatchOrderAction^ OnRspBatchOrderAction
			    {
				    void add(RspBatchOrderAction^ handler)
				    {
					    OnRspBatchOrderAction_delegate += handler;
				    }
				    void remove(RspBatchOrderAction^ handler)
				    {
					    OnRspBatchOrderAction_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetInputBatchOrderActionField^ pInputBatchOrderAction, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspBatchOrderAction_delegate)
						    OnRspBatchOrderAction_delegate(pInputBatchOrderAction, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 期权自对冲录入请求响应
			    /// </summary>
			    event RspOptionSelfCloseInsert^ OnRspOptionSelfCloseInsert
			    {
				    void add(RspOptionSelfCloseInsert^ handler)
				    {
					    OnRspOptionSelfCloseInsert_delegate += handler;
				    }
				    void remove(RspOptionSelfCloseInsert^ handler)
				    {
					    OnRspOptionSelfCloseInsert_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetInputOptionSelfCloseField^ pInputOptionSelfClose, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspOptionSelfCloseInsert_delegate)
						    OnRspOptionSelfCloseInsert_delegate(pInputOptionSelfClose, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 期权自对冲操作请求响应
			    /// </summary>
			    event RspOptionSelfCloseAction^ OnRspOptionSelfCloseAction
			    {
				    void add(RspOptionSelfCloseAction^ handler)
				    {
					    OnRspOptionSelfCloseAction_delegate += handler;
				    }
				    void remove(RspOptionSelfCloseAction^ handler)
				    {
					    OnRspOptionSelfCloseAction_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetInputOptionSelfCloseActionField^ pInputOptionSelfCloseAction, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspOptionSelfCloseAction_delegate)
						    OnRspOptionSelfCloseAction_delegate(pInputOptionSelfCloseAction, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 申请组合录入请求响应
			    /// </summary>
			    event RspCombActionInsert^ OnRspCombActionInsert
			    {
				    void add(RspCombActionInsert^ handler)
				    {
					    OnRspCombActionInsert_delegate += handler;
				    }
				    void remove(RspCombActionInsert^ handler)
				    {
					    OnRspCombActionInsert_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetInputCombActionField^ pInputCombAction, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspCombActionInsert_delegate)
						    OnRspCombActionInsert_delegate(pInputCombAction, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询报单响应
			    /// </summary>
			    event RspQryOrder^ OnRspQryOrder
			    {
				    void add(RspQryOrder^ handler)
				    {
					    OnRspQryOrder_delegate += handler;
				    }
				    void remove(RspQryOrder^ handler)
				    {
					    OnRspQryOrder_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetOrderField^ pOrder, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryOrder_delegate)
						    OnRspQryOrder_delegate(pOrder, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询成交响应
			    /// </summary>
			    event RspQryTrade^ OnRspQryTrade
			    {
				    void add(RspQryTrade^ handler)
				    {
					    OnRspQryTrade_delegate += handler;
				    }
				    void remove(RspQryTrade^ handler)
				    {
					    OnRspQryTrade_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetTradeField^ pTrade, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryTrade_delegate)
						    OnRspQryTrade_delegate(pTrade, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询投资者持仓响应
			    /// </summary>
			    event RspQryInvestorPosition^ OnRspQryInvestorPosition
			    {
				    void add(RspQryInvestorPosition^ handler)
				    {
					    OnRspQryInvestorPosition_delegate += handler;
				    }
				    void remove(RspQryInvestorPosition^ handler)
				    {
					    OnRspQryInvestorPosition_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetInvestorPositionField^ pInvestorPosition, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryInvestorPosition_delegate)
						    OnRspQryInvestorPosition_delegate(pInvestorPosition, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询资金账户响应
			    /// </summary>
			    event RspQryTradingAccount^ OnRspQryTradingAccount
			    {
				    void add(RspQryTradingAccount^ handler)
				    {
					    OnRspQryTradingAccount_delegate += handler;
				    }
				    void remove(RspQryTradingAccount^ handler)
				    {
					    OnRspQryTradingAccount_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetTradingAccountField^ pTradingAccount, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryTradingAccount_delegate)
						    OnRspQryTradingAccount_delegate(pTradingAccount, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询投资者响应
			    /// </summary>
			    event RspQryInvestor^ OnRspQryInvestor
			    {
				    void add(RspQryInvestor^ handler)
				    {
					    OnRspQryInvestor_delegate += handler;
				    }
				    void remove(RspQryInvestor^ handler)
				    {
					    OnRspQryInvestor_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetInvestorField^ pInvestor, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryInvestor_delegate)
						    OnRspQryInvestor_delegate(pInvestor, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询交易编码响应
			    /// </summary>
			    event RspQryTradingCode^ OnRspQryTradingCode
			    {
				    void add(RspQryTradingCode^ handler)
				    {
					    OnRspQryTradingCode_delegate += handler;
				    }
				    void remove(RspQryTradingCode^ handler)
				    {
					    OnRspQryTradingCode_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetTradingCodeField^ pTradingCode, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryTradingCode_delegate)
						    OnRspQryTradingCode_delegate(pTradingCode, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询合约保证金率响应
			    /// </summary>
			    event RspQryInstrumentMarginRate^ OnRspQryInstrumentMarginRate
			    {
				    void add(RspQryInstrumentMarginRate^ handler)
				    {
					    OnRspQryInstrumentMarginRate_delegate += handler;
				    }
				    void remove(RspQryInstrumentMarginRate^ handler)
				    {
					    OnRspQryInstrumentMarginRate_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetInstrumentMarginRateField^ pInstrumentMarginRate, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryInstrumentMarginRate_delegate)
						    OnRspQryInstrumentMarginRate_delegate(pInstrumentMarginRate, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询合约手续费率响应
			    /// </summary>
			    event RspQryInstrumentCommissionRate^ OnRspQryInstrumentCommissionRate
			    {
				    void add(RspQryInstrumentCommissionRate^ handler)
				    {
					    OnRspQryInstrumentCommissionRate_delegate += handler;
				    }
				    void remove(RspQryInstrumentCommissionRate^ handler)
				    {
					    OnRspQryInstrumentCommissionRate_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetInstrumentCommissionRateField^ pInstrumentCommissionRate, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryInstrumentCommissionRate_delegate)
						    OnRspQryInstrumentCommissionRate_delegate(pInstrumentCommissionRate, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询交易所响应
			    /// </summary>
			    event RspQryExchange^ OnRspQryExchange
			    {
				    void add(RspQryExchange^ handler)
				    {
					    OnRspQryExchange_delegate += handler;
				    }
				    void remove(RspQryExchange^ handler)
				    {
					    OnRspQryExchange_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetExchangeField^ pExchange, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryExchange_delegate)
						    OnRspQryExchange_delegate(pExchange, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询产品响应
			    /// </summary>
			    event RspQryProduct^ OnRspQryProduct
			    {
				    void add(RspQryProduct^ handler)
				    {
					    OnRspQryProduct_delegate += handler;
				    }
				    void remove(RspQryProduct^ handler)
				    {
					    OnRspQryProduct_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetProductField^ pProduct, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryProduct_delegate)
						    OnRspQryProduct_delegate(pProduct, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询合约响应
			    /// </summary>
			    event RspQryInstrument^ OnRspQryInstrument
			    {
				    void add(RspQryInstrument^ handler)
				    {
					    OnRspQryInstrument_delegate += handler;
				    }
				    void remove(RspQryInstrument^ handler)
				    {
					    OnRspQryInstrument_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetInstrumentField^ pInstrument, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryInstrument_delegate)
						    OnRspQryInstrument_delegate(pInstrument, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询行情响应
			    /// </summary>
			    event RspQryDepthMarketData^ OnRspQryDepthMarketData
			    {
				    void add(RspQryDepthMarketData^ handler)
				    {
					    OnRspQryDepthMarketData_delegate += handler;
				    }
				    void remove(RspQryDepthMarketData^ handler)
				    {
					    OnRspQryDepthMarketData_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetDepthMarketDataField^ pDepthMarketData, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryDepthMarketData_delegate)
						    OnRspQryDepthMarketData_delegate(pDepthMarketData, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询投资者结算结果响应
			    /// </summary>
			    event RspQrySettlementInfo^ OnRspQrySettlementInfo
			    {
				    void add(RspQrySettlementInfo^ handler)
				    {
					    OnRspQrySettlementInfo_delegate += handler;
				    }
				    void remove(RspQrySettlementInfo^ handler)
				    {
					    OnRspQrySettlementInfo_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetSettlementInfoField^ pSettlementInfo, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQrySettlementInfo_delegate)
						    OnRspQrySettlementInfo_delegate(pSettlementInfo, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询转帐银行响应
			    /// </summary>
			    event RspQryTransferBank^ OnRspQryTransferBank
			    {
				    void add(RspQryTransferBank^ handler)
				    {
					    OnRspQryTransferBank_delegate += handler;
				    }
				    void remove(RspQryTransferBank^ handler)
				    {
					    OnRspQryTransferBank_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetTransferBankField^ pTransferBank, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryTransferBank_delegate)
						    OnRspQryTransferBank_delegate(pTransferBank, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询投资者持仓明细响应
			    /// </summary>
			    event RspQryInvestorPositionDetail^ OnRspQryInvestorPositionDetail
			    {
				    void add(RspQryInvestorPositionDetail^ handler)
				    {
					    OnRspQryInvestorPositionDetail_delegate += handler;
				    }
				    void remove(RspQryInvestorPositionDetail^ handler)
				    {
					    OnRspQryInvestorPositionDetail_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetInvestorPositionDetailField^ pInvestorPositionDetail, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryInvestorPositionDetail_delegate)
						    OnRspQryInvestorPositionDetail_delegate(pInvestorPositionDetail, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询客户通知响应
			    /// </summary>
			    event RspQryNotice^ OnRspQryNotice
			    {
				    void add(RspQryNotice^ handler)
				    {
					    OnRspQryNotice_delegate += handler;
				    }
				    void remove(RspQryNotice^ handler)
				    {
					    OnRspQryNotice_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetNoticeField^ pNotice, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryNotice_delegate)
						    OnRspQryNotice_delegate(pNotice, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询结算信息确认响应
			    /// </summary>
			    event RspQrySettlementInfoConfirm^ OnRspQrySettlementInfoConfirm
			    {
				    void add(RspQrySettlementInfoConfirm^ handler)
				    {
					    OnRspQrySettlementInfoConfirm_delegate += handler;
				    }
				    void remove(RspQrySettlementInfoConfirm^ handler)
				    {
					    OnRspQrySettlementInfoConfirm_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetSettlementInfoConfirmField^ pSettlementInfoConfirm, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQrySettlementInfoConfirm_delegate)
						    OnRspQrySettlementInfoConfirm_delegate(pSettlementInfoConfirm, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询投资者持仓明细响应
			    /// </summary>
			    event RspQryInvestorPositionCombineDetail^ OnRspQryInvestorPositionCombineDetail
			    {
				    void add(RspQryInvestorPositionCombineDetail^ handler)
				    {
					    OnRspQryInvestorPositionCombineDetail_delegate += handler;
				    }
				    void remove(RspQryInvestorPositionCombineDetail^ handler)
				    {
					    OnRspQryInvestorPositionCombineDetail_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetInvestorPositionCombineDetailField^ pInvestorPositionCombineDetail, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryInvestorPositionCombineDetail_delegate)
						    OnRspQryInvestorPositionCombineDetail_delegate(pInvestorPositionCombineDetail, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 查询保证金监管系统经纪公司资金账户密钥响应
			    /// </summary>
			    event RspQryCFMMCTradingAccountKey^ OnRspQryCFMMCTradingAccountKey
			    {
				    void add(RspQryCFMMCTradingAccountKey^ handler)
				    {
					    OnRspQryCFMMCTradingAccountKey_delegate += handler;
				    }
				    void remove(RspQryCFMMCTradingAccountKey^ handler)
				    {
					    OnRspQryCFMMCTradingAccountKey_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetCFMMCTradingAccountKeyField^ pCFMMCTradingAccountKey, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryCFMMCTradingAccountKey_delegate)
						    OnRspQryCFMMCTradingAccountKey_delegate(pCFMMCTradingAccountKey, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询仓单折抵信息响应
			    /// </summary>
			    event RspQryEWarrantOffset^ OnRspQryEWarrantOffset
			    {
				    void add(RspQryEWarrantOffset^ handler)
				    {
					    OnRspQryEWarrantOffset_delegate += handler;
				    }
				    void remove(RspQryEWarrantOffset^ handler)
				    {
					    OnRspQryEWarrantOffset_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetEWarrantOffsetField^ pEWarrantOffset, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryEWarrantOffset_delegate)
						    OnRspQryEWarrantOffset_delegate(pEWarrantOffset, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询投资者品种/跨品种保证金响应
			    /// </summary>
			    event RspQryInvestorProductGroupMargin^ OnRspQryInvestorProductGroupMargin
			    {
				    void add(RspQryInvestorProductGroupMargin^ handler)
				    {
					    OnRspQryInvestorProductGroupMargin_delegate += handler;
				    }
				    void remove(RspQryInvestorProductGroupMargin^ handler)
				    {
					    OnRspQryInvestorProductGroupMargin_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetInvestorProductGroupMarginField^ pInvestorProductGroupMargin, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryInvestorProductGroupMargin_delegate)
						    OnRspQryInvestorProductGroupMargin_delegate(pInvestorProductGroupMargin, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询交易所保证金率响应
			    /// </summary>
			    event RspQryExchangeMarginRate^ OnRspQryExchangeMarginRate
			    {
				    void add(RspQryExchangeMarginRate^ handler)
				    {
					    OnRspQryExchangeMarginRate_delegate += handler;
				    }
				    void remove(RspQryExchangeMarginRate^ handler)
				    {
					    OnRspQryExchangeMarginRate_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetExchangeMarginRateField^ pExchangeMarginRate, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryExchangeMarginRate_delegate)
						    OnRspQryExchangeMarginRate_delegate(pExchangeMarginRate, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询交易所调整保证金率响应
			    /// </summary>
			    event RspQryExchangeMarginRateAdjust^ OnRspQryExchangeMarginRateAdjust
			    {
				    void add(RspQryExchangeMarginRateAdjust^ handler)
				    {
					    OnRspQryExchangeMarginRateAdjust_delegate += handler;
				    }
				    void remove(RspQryExchangeMarginRateAdjust^ handler)
				    {
					    OnRspQryExchangeMarginRateAdjust_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetExchangeMarginRateAdjustField^ pExchangeMarginRateAdjust, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryExchangeMarginRateAdjust_delegate)
						    OnRspQryExchangeMarginRateAdjust_delegate(pExchangeMarginRateAdjust, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询汇率响应
			    /// </summary>
			    event RspQryExchangeRate^ OnRspQryExchangeRate
			    {
				    void add(RspQryExchangeRate^ handler)
				    {
					    OnRspQryExchangeRate_delegate += handler;
				    }
				    void remove(RspQryExchangeRate^ handler)
				    {
					    OnRspQryExchangeRate_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetExchangeRateField^ pExchangeRate, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryExchangeRate_delegate)
						    OnRspQryExchangeRate_delegate(pExchangeRate, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询二级代理操作员银期权限响应
			    /// </summary>
			    event RspQrySecAgentACIDMap^ OnRspQrySecAgentACIDMap
			    {
				    void add(RspQrySecAgentACIDMap^ handler)
				    {
					    OnRspQrySecAgentACIDMap_delegate += handler;
				    }
				    void remove(RspQrySecAgentACIDMap^ handler)
				    {
					    OnRspQrySecAgentACIDMap_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetSecAgentACIDMapField^ pSecAgentACIDMap, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQrySecAgentACIDMap_delegate)
						    OnRspQrySecAgentACIDMap_delegate(pSecAgentACIDMap, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询产品报价汇率
			    /// </summary>
			    event RspQryProductExchRate^ OnRspQryProductExchRate
			    {
				    void add(RspQryProductExchRate^ handler)
				    {
					    OnRspQryProductExchRate_delegate += handler;
				    }
				    void remove(RspQryProductExchRate^ handler)
				    {
					    OnRspQryProductExchRate_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetProductExchRateField^ pProductExchRate, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryProductExchRate_delegate)
						    OnRspQryProductExchRate_delegate(pProductExchRate, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询产品组
			    /// </summary>
			    event RspQryProductGroup^ OnRspQryProductGroup
			    {
				    void add(RspQryProductGroup^ handler)
				    {
					    OnRspQryProductGroup_delegate += handler;
				    }
				    void remove(RspQryProductGroup^ handler)
				    {
					    OnRspQryProductGroup_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetProductGroupField^ pProductGroup, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryProductGroup_delegate)
						    OnRspQryProductGroup_delegate(pProductGroup, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询做市商合约手续费率响应
			    /// </summary>
			    event RspQryMMInstrumentCommissionRate^ OnRspQryMMInstrumentCommissionRate
			    {
				    void add(RspQryMMInstrumentCommissionRate^ handler)
				    {
					    OnRspQryMMInstrumentCommissionRate_delegate += handler;
				    }
				    void remove(RspQryMMInstrumentCommissionRate^ handler)
				    {
					    OnRspQryMMInstrumentCommissionRate_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetMMInstrumentCommissionRateField^ pMMInstrumentCommissionRate, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryMMInstrumentCommissionRate_delegate)
						    OnRspQryMMInstrumentCommissionRate_delegate(pMMInstrumentCommissionRate, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询做市商期权合约手续费响应
			    /// </summary>
			    event RspQryMMOptionInstrCommRate^ OnRspQryMMOptionInstrCommRate
			    {
				    void add(RspQryMMOptionInstrCommRate^ handler)
				    {
					    OnRspQryMMOptionInstrCommRate_delegate += handler;
				    }
				    void remove(RspQryMMOptionInstrCommRate^ handler)
				    {
					    OnRspQryMMOptionInstrCommRate_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetMMOptionInstrCommRateField^ pMMOptionInstrCommRate, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryMMOptionInstrCommRate_delegate)
						    OnRspQryMMOptionInstrCommRate_delegate(pMMOptionInstrCommRate, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询报单手续费响应
			    /// </summary>
			    event RspQryInstrumentOrderCommRate^ OnRspQryInstrumentOrderCommRate
			    {
				    void add(RspQryInstrumentOrderCommRate^ handler)
				    {
					    OnRspQryInstrumentOrderCommRate_delegate += handler;
				    }
				    void remove(RspQryInstrumentOrderCommRate^ handler)
				    {
					    OnRspQryInstrumentOrderCommRate_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetInstrumentOrderCommRateField^ pInstrumentOrderCommRate, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryInstrumentOrderCommRate_delegate)
						    OnRspQryInstrumentOrderCommRate_delegate(pInstrumentOrderCommRate, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询资金账户响应
			    /// </summary>
			    event RspQrySecAgentTradingAccount^ OnRspQrySecAgentTradingAccount
			    {
				    void add(RspQrySecAgentTradingAccount^ handler)
				    {
					    OnRspQrySecAgentTradingAccount_delegate += handler;
				    }
				    void remove(RspQrySecAgentTradingAccount^ handler)
				    {
					    OnRspQrySecAgentTradingAccount_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetTradingAccountField^ pTradingAccount, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQrySecAgentTradingAccount_delegate)
						    OnRspQrySecAgentTradingAccount_delegate(pTradingAccount, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询二级代理商资金校验模式响应
			    /// </summary>
			    event RspQrySecAgentCheckMode^ OnRspQrySecAgentCheckMode
			    {
				    void add(RspQrySecAgentCheckMode^ handler)
				    {
					    OnRspQrySecAgentCheckMode_delegate += handler;
				    }
				    void remove(RspQrySecAgentCheckMode^ handler)
				    {
					    OnRspQrySecAgentCheckMode_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetSecAgentCheckModeField^ pSecAgentCheckMode, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQrySecAgentCheckMode_delegate)
						    OnRspQrySecAgentCheckMode_delegate(pSecAgentCheckMode, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询期权交易成本响应
			    /// </summary>
			    event RspQryOptionInstrTradeCost^ OnRspQryOptionInstrTradeCost
			    {
				    void add(RspQryOptionInstrTradeCost^ handler)
				    {
					    OnRspQryOptionInstrTradeCost_delegate += handler;
				    }
				    void remove(RspQryOptionInstrTradeCost^ handler)
				    {
					    OnRspQryOptionInstrTradeCost_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetOptionInstrTradeCostField^ pOptionInstrTradeCost, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryOptionInstrTradeCost_delegate)
						    OnRspQryOptionInstrTradeCost_delegate(pOptionInstrTradeCost, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询期权合约手续费响应
			    /// </summary>
			    event RspQryOptionInstrCommRate^ OnRspQryOptionInstrCommRate
			    {
				    void add(RspQryOptionInstrCommRate^ handler)
				    {
					    OnRspQryOptionInstrCommRate_delegate += handler;
				    }
				    void remove(RspQryOptionInstrCommRate^ handler)
				    {
					    OnRspQryOptionInstrCommRate_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetOptionInstrCommRateField^ pOptionInstrCommRate, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryOptionInstrCommRate_delegate)
						    OnRspQryOptionInstrCommRate_delegate(pOptionInstrCommRate, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询执行宣告响应
			    /// </summary>
			    event RspQryExecOrder^ OnRspQryExecOrder
			    {
				    void add(RspQryExecOrder^ handler)
				    {
					    OnRspQryExecOrder_delegate += handler;
				    }
				    void remove(RspQryExecOrder^ handler)
				    {
					    OnRspQryExecOrder_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetExecOrderField^ pExecOrder, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryExecOrder_delegate)
						    OnRspQryExecOrder_delegate(pExecOrder, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询询价响应
			    /// </summary>
			    event RspQryForQuote^ OnRspQryForQuote
			    {
				    void add(RspQryForQuote^ handler)
				    {
					    OnRspQryForQuote_delegate += handler;
				    }
				    void remove(RspQryForQuote^ handler)
				    {
					    OnRspQryForQuote_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetForQuoteField^ pForQuote, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryForQuote_delegate)
						    OnRspQryForQuote_delegate(pForQuote, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询报价响应
			    /// </summary>
			    event RspQryQuote^ OnRspQryQuote
			    {
				    void add(RspQryQuote^ handler)
				    {
					    OnRspQryQuote_delegate += handler;
				    }
				    void remove(RspQryQuote^ handler)
				    {
					    OnRspQryQuote_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetQuoteField^ pQuote, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryQuote_delegate)
						    OnRspQryQuote_delegate(pQuote, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询期权自对冲响应
			    /// </summary>
			    event RspQryOptionSelfClose^ OnRspQryOptionSelfClose
			    {
				    void add(RspQryOptionSelfClose^ handler)
				    {
					    OnRspQryOptionSelfClose_delegate += handler;
				    }
				    void remove(RspQryOptionSelfClose^ handler)
				    {
					    OnRspQryOptionSelfClose_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetOptionSelfCloseField^ pOptionSelfClose, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryOptionSelfClose_delegate)
						    OnRspQryOptionSelfClose_delegate(pOptionSelfClose, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询投资单元响应
			    /// </summary>
			    event RspQryInvestUnit^ OnRspQryInvestUnit
			    {
				    void add(RspQryInvestUnit^ handler)
				    {
					    OnRspQryInvestUnit_delegate += handler;
				    }
				    void remove(RspQryInvestUnit^ handler)
				    {
					    OnRspQryInvestUnit_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetInvestUnitField^ pInvestUnit, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryInvestUnit_delegate)
						    OnRspQryInvestUnit_delegate(pInvestUnit, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询组合合约安全系数响应
			    /// </summary>
			    event RspQryCombInstrumentGuard^ OnRspQryCombInstrumentGuard
			    {
				    void add(RspQryCombInstrumentGuard^ handler)
				    {
					    OnRspQryCombInstrumentGuard_delegate += handler;
				    }
				    void remove(RspQryCombInstrumentGuard^ handler)
				    {
					    OnRspQryCombInstrumentGuard_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetCombInstrumentGuardField^ pCombInstrumentGuard, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryCombInstrumentGuard_delegate)
						    OnRspQryCombInstrumentGuard_delegate(pCombInstrumentGuard, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询申请组合响应
			    /// </summary>
			    event RspQryCombAction^ OnRspQryCombAction
			    {
				    void add(RspQryCombAction^ handler)
				    {
					    OnRspQryCombAction_delegate += handler;
				    }
				    void remove(RspQryCombAction^ handler)
				    {
					    OnRspQryCombAction_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetCombActionField^ pCombAction, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryCombAction_delegate)
						    OnRspQryCombAction_delegate(pCombAction, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询转帐流水响应
			    /// </summary>
			    event RspQryTransferSerial^ OnRspQryTransferSerial
			    {
				    void add(RspQryTransferSerial^ handler)
				    {
					    OnRspQryTransferSerial_delegate += handler;
				    }
				    void remove(RspQryTransferSerial^ handler)
				    {
					    OnRspQryTransferSerial_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetTransferSerialField^ pTransferSerial, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryTransferSerial_delegate)
						    OnRspQryTransferSerial_delegate(pTransferSerial, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询银期签约关系响应
			    /// </summary>
			    event RspQryAccountregister^ OnRspQryAccountregister
			    {
				    void add(RspQryAccountregister^ handler)
				    {
					    OnRspQryAccountregister_delegate += handler;
				    }
				    void remove(RspQryAccountregister^ handler)
				    {
					    OnRspQryAccountregister_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetAccountregisterField^ pAccountregister, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryAccountregister_delegate)
						    OnRspQryAccountregister_delegate(pAccountregister, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 报单通知
			    /// </summary>
			    event RtnOrder^ OnRtnOrder
			    {
				    void add(RtnOrder^ handler)
				    {
					    OnRtnOrder_delegate += handler;
				    }
				    void remove(RtnOrder^ handler)
				    {
					    OnRtnOrder_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetOrderField^ pOrder)
				    {
					    if (OnRtnOrder_delegate)
						    OnRtnOrder_delegate(pOrder);
				    }
			    }

			    /// <summary>
			    /// 成交通知
			    /// </summary>
			    event RtnTrade^ OnRtnTrade
			    {
				    void add(RtnTrade^ handler)
				    {
					    OnRtnTrade_delegate += handler;
				    }
				    void remove(RtnTrade^ handler)
				    {
					    OnRtnTrade_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetTradeField^ pTrade)
				    {
					    if (OnRtnTrade_delegate)
						    OnRtnTrade_delegate(pTrade);
				    }
			    }

			    /// <summary>
			    /// 报单录入错误回报
			    /// </summary>
			    event ErrRtnOrderInsert^ OnErrRtnOrderInsert
			    {
				    void add(ErrRtnOrderInsert^ handler)
				    {
					    OnErrRtnOrderInsert_delegate += handler;
				    }
				    void remove(ErrRtnOrderInsert^ handler)
				    {
					    OnErrRtnOrderInsert_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetInputOrderField^ pInputOrder, CtpNetRspInfoField^ pRspInfo)
				    {
					    if (OnErrRtnOrderInsert_delegate)
						    OnErrRtnOrderInsert_delegate(pInputOrder, pRspInfo);
				    }
			    }

			    /// <summary>
			    /// 报单操作错误回报
			    /// </summary>
			    event ErrRtnOrderAction^ OnErrRtnOrderAction
			    {
				    void add(ErrRtnOrderAction^ handler)
				    {
					    OnErrRtnOrderAction_delegate += handler;
				    }
				    void remove(ErrRtnOrderAction^ handler)
				    {
					    OnErrRtnOrderAction_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetOrderActionField^ pOrderAction, CtpNetRspInfoField^ pRspInfo)
				    {
					    if (OnErrRtnOrderAction_delegate)
						    OnErrRtnOrderAction_delegate(pOrderAction, pRspInfo);
				    }
			    }

			    /// <summary>
			    /// 合约交易状态通知
			    /// </summary>
			    event RtnInstrumentStatus^ OnRtnInstrumentStatus
			    {
				    void add(RtnInstrumentStatus^ handler)
				    {
					    OnRtnInstrumentStatus_delegate += handler;
				    }
				    void remove(RtnInstrumentStatus^ handler)
				    {
					    OnRtnInstrumentStatus_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetInstrumentStatusField^ pInstrumentStatus)
				    {
					    if (OnRtnInstrumentStatus_delegate)
						    OnRtnInstrumentStatus_delegate(pInstrumentStatus);
				    }
			    }

			    /// <summary>
			    /// 交易所公告通知
			    /// </summary>
			    event RtnBulletin^ OnRtnBulletin
			    {
				    void add(RtnBulletin^ handler)
				    {
					    OnRtnBulletin_delegate += handler;
				    }
				    void remove(RtnBulletin^ handler)
				    {
					    OnRtnBulletin_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetBulletinField^ pBulletin)
				    {
					    if (OnRtnBulletin_delegate)
						    OnRtnBulletin_delegate(pBulletin);
				    }
			    }

			    /// <summary>
			    /// 交易通知
			    /// </summary>
			    event RtnTradingNotice^ OnRtnTradingNotice
			    {
				    void add(RtnTradingNotice^ handler)
				    {
					    OnRtnTradingNotice_delegate += handler;
				    }
				    void remove(RtnTradingNotice^ handler)
				    {
					    OnRtnTradingNotice_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetTradingNoticeInfoField^ pTradingNoticeInfo)
				    {
					    if (OnRtnTradingNotice_delegate)
						    OnRtnTradingNotice_delegate(pTradingNoticeInfo);
				    }
			    }

			    /// <summary>
			    /// 提示条件单校验错误
			    /// </summary>
			    event RtnErrorConditionalOrder^ OnRtnErrorConditionalOrder
			    {
				    void add(RtnErrorConditionalOrder^ handler)
				    {
					    OnRtnErrorConditionalOrder_delegate += handler;
				    }
				    void remove(RtnErrorConditionalOrder^ handler)
				    {
					    OnRtnErrorConditionalOrder_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetErrorConditionalOrderField^ pErrorConditionalOrder)
				    {
					    if (OnRtnErrorConditionalOrder_delegate)
						    OnRtnErrorConditionalOrder_delegate(pErrorConditionalOrder);
				    }
			    }

			    /// <summary>
			    /// 执行宣告通知
			    /// </summary>
			    event RtnExecOrder^ OnRtnExecOrder
			    {
				    void add(RtnExecOrder^ handler)
				    {
					    OnRtnExecOrder_delegate += handler;
				    }
				    void remove(RtnExecOrder^ handler)
				    {
					    OnRtnExecOrder_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetExecOrderField^ pExecOrder)
				    {
					    if (OnRtnExecOrder_delegate)
						    OnRtnExecOrder_delegate(pExecOrder);
				    }
			    }

			    /// <summary>
			    /// 执行宣告录入错误回报
			    /// </summary>
			    event ErrRtnExecOrderInsert^ OnErrRtnExecOrderInsert
			    {
				    void add(ErrRtnExecOrderInsert^ handler)
				    {
					    OnErrRtnExecOrderInsert_delegate += handler;
				    }
				    void remove(ErrRtnExecOrderInsert^ handler)
				    {
					    OnErrRtnExecOrderInsert_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetInputExecOrderField^ pInputExecOrder, CtpNetRspInfoField^ pRspInfo)
				    {
					    if (OnErrRtnExecOrderInsert_delegate)
						    OnErrRtnExecOrderInsert_delegate(pInputExecOrder, pRspInfo);
				    }
			    }

			    /// <summary>
			    /// 执行宣告操作错误回报
			    /// </summary>
			    event ErrRtnExecOrderAction^ OnErrRtnExecOrderAction
			    {
				    void add(ErrRtnExecOrderAction^ handler)
				    {
					    OnErrRtnExecOrderAction_delegate += handler;
				    }
				    void remove(ErrRtnExecOrderAction^ handler)
				    {
					    OnErrRtnExecOrderAction_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetExecOrderActionField^ pExecOrderAction, CtpNetRspInfoField^ pRspInfo)
				    {
					    if (OnErrRtnExecOrderAction_delegate)
						    OnErrRtnExecOrderAction_delegate(pExecOrderAction, pRspInfo);
				    }
			    }

			    /// <summary>
			    /// 询价录入错误回报
			    /// </summary>
			    event ErrRtnForQuoteInsert^ OnErrRtnForQuoteInsert
			    {
				    void add(ErrRtnForQuoteInsert^ handler)
				    {
					    OnErrRtnForQuoteInsert_delegate += handler;
				    }
				    void remove(ErrRtnForQuoteInsert^ handler)
				    {
					    OnErrRtnForQuoteInsert_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetInputForQuoteField^ pInputForQuote, CtpNetRspInfoField^ pRspInfo)
				    {
					    if (OnErrRtnForQuoteInsert_delegate)
						    OnErrRtnForQuoteInsert_delegate(pInputForQuote, pRspInfo);
				    }
			    }

			    /// <summary>
			    /// 报价通知
			    /// </summary>
			    event RtnQuote^ OnRtnQuote
			    {
				    void add(RtnQuote^ handler)
				    {
					    OnRtnQuote_delegate += handler;
				    }
				    void remove(RtnQuote^ handler)
				    {
					    OnRtnQuote_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetQuoteField^ pQuote)
				    {
					    if (OnRtnQuote_delegate)
						    OnRtnQuote_delegate(pQuote);
				    }
			    }

			    /// <summary>
			    /// 报价录入错误回报
			    /// </summary>
			    event ErrRtnQuoteInsert^ OnErrRtnQuoteInsert
			    {
				    void add(ErrRtnQuoteInsert^ handler)
				    {
					    OnErrRtnQuoteInsert_delegate += handler;
				    }
				    void remove(ErrRtnQuoteInsert^ handler)
				    {
					    OnErrRtnQuoteInsert_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetInputQuoteField^ pInputQuote, CtpNetRspInfoField^ pRspInfo)
				    {
					    if (OnErrRtnQuoteInsert_delegate)
						    OnErrRtnQuoteInsert_delegate(pInputQuote, pRspInfo);
				    }
			    }

			    /// <summary>
			    /// 报价操作错误回报
			    /// </summary>
			    event ErrRtnQuoteAction^ OnErrRtnQuoteAction
			    {
				    void add(ErrRtnQuoteAction^ handler)
				    {
					    OnErrRtnQuoteAction_delegate += handler;
				    }
				    void remove(ErrRtnQuoteAction^ handler)
				    {
					    OnErrRtnQuoteAction_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetQuoteActionField^ pQuoteAction, CtpNetRspInfoField^ pRspInfo)
				    {
					    if (OnErrRtnQuoteAction_delegate)
						    OnErrRtnQuoteAction_delegate(pQuoteAction, pRspInfo);
				    }
			    }

			    /// <summary>
			    /// 保证金监控中心用户令牌
			    /// </summary>
			    event RtnCFMMCTradingAccountToken^ OnRtnCFMMCTradingAccountToken
			    {
				    void add(RtnCFMMCTradingAccountToken^ handler)
				    {
					    OnRtnCFMMCTradingAccountToken_delegate += handler;
				    }
				    void remove(RtnCFMMCTradingAccountToken^ handler)
				    {
					    OnRtnCFMMCTradingAccountToken_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetCFMMCTradingAccountTokenField^ pCFMMCTradingAccountToken)
				    {
					    if (OnRtnCFMMCTradingAccountToken_delegate)
						    OnRtnCFMMCTradingAccountToken_delegate(pCFMMCTradingAccountToken);
				    }
			    }

			    /// <summary>
			    /// 批量报单操作错误回报
			    /// </summary>
			    event ErrRtnBatchOrderAction^ OnErrRtnBatchOrderAction
			    {
				    void add(ErrRtnBatchOrderAction^ handler)
				    {
					    OnErrRtnBatchOrderAction_delegate += handler;
				    }
				    void remove(ErrRtnBatchOrderAction^ handler)
				    {
					    OnErrRtnBatchOrderAction_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetBatchOrderActionField^ pBatchOrderAction, CtpNetRspInfoField^ pRspInfo)
				    {
					    if (OnErrRtnBatchOrderAction_delegate)
						    OnErrRtnBatchOrderAction_delegate(pBatchOrderAction, pRspInfo);
				    }
			    }

			    /// <summary>
			    /// 期权自对冲通知
			    /// </summary>
			    event RtnOptionSelfClose^ OnRtnOptionSelfClose
			    {
				    void add(RtnOptionSelfClose^ handler)
				    {
					    OnRtnOptionSelfClose_delegate += handler;
				    }
				    void remove(RtnOptionSelfClose^ handler)
				    {
					    OnRtnOptionSelfClose_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetOptionSelfCloseField^ pOptionSelfClose)
				    {
					    if (OnRtnOptionSelfClose_delegate)
						    OnRtnOptionSelfClose_delegate(pOptionSelfClose);
				    }
			    }

			    /// <summary>
			    /// 期权自对冲录入错误回报
			    /// </summary>
			    event ErrRtnOptionSelfCloseInsert^ OnErrRtnOptionSelfCloseInsert
			    {
				    void add(ErrRtnOptionSelfCloseInsert^ handler)
				    {
					    OnErrRtnOptionSelfCloseInsert_delegate += handler;
				    }
				    void remove(ErrRtnOptionSelfCloseInsert^ handler)
				    {
					    OnErrRtnOptionSelfCloseInsert_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetInputOptionSelfCloseField^ pInputOptionSelfClose, CtpNetRspInfoField^ pRspInfo)
				    {
					    if (OnErrRtnOptionSelfCloseInsert_delegate)
						    OnErrRtnOptionSelfCloseInsert_delegate(pInputOptionSelfClose, pRspInfo);
				    }
			    }

			    /// <summary>
			    /// 期权自对冲操作错误回报
			    /// </summary>
			    event ErrRtnOptionSelfCloseAction^ OnErrRtnOptionSelfCloseAction
			    {
				    void add(ErrRtnOptionSelfCloseAction^ handler)
				    {
					    OnErrRtnOptionSelfCloseAction_delegate += handler;
				    }
				    void remove(ErrRtnOptionSelfCloseAction^ handler)
				    {
					    OnErrRtnOptionSelfCloseAction_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetOptionSelfCloseActionField^ pOptionSelfCloseAction, CtpNetRspInfoField^ pRspInfo)
				    {
					    if (OnErrRtnOptionSelfCloseAction_delegate)
						    OnErrRtnOptionSelfCloseAction_delegate(pOptionSelfCloseAction, pRspInfo);
				    }
			    }

			    /// <summary>
			    /// 申请组合通知
			    /// </summary>
			    event RtnCombAction^ OnRtnCombAction
			    {
				    void add(RtnCombAction^ handler)
				    {
					    OnRtnCombAction_delegate += handler;
				    }
				    void remove(RtnCombAction^ handler)
				    {
					    OnRtnCombAction_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetCombActionField^ pCombAction)
				    {
					    if (OnRtnCombAction_delegate)
						    OnRtnCombAction_delegate(pCombAction);
				    }
			    }

			    /// <summary>
			    /// 申请组合录入错误回报
			    /// </summary>
			    event ErrRtnCombActionInsert^ OnErrRtnCombActionInsert
			    {
				    void add(ErrRtnCombActionInsert^ handler)
				    {
					    OnErrRtnCombActionInsert_delegate += handler;
				    }
				    void remove(ErrRtnCombActionInsert^ handler)
				    {
					    OnErrRtnCombActionInsert_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetInputCombActionField^ pInputCombAction, CtpNetRspInfoField^ pRspInfo)
				    {
					    if (OnErrRtnCombActionInsert_delegate)
						    OnErrRtnCombActionInsert_delegate(pInputCombAction, pRspInfo);
				    }
			    }

			    /// <summary>
			    /// 请求查询签约银行响应
			    /// </summary>
			    event RspQryContractBank^ OnRspQryContractBank
			    {
				    void add(RspQryContractBank^ handler)
				    {
					    OnRspQryContractBank_delegate += handler;
				    }
				    void remove(RspQryContractBank^ handler)
				    {
					    OnRspQryContractBank_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetContractBankField^ pContractBank, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryContractBank_delegate)
						    OnRspQryContractBank_delegate(pContractBank, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询预埋单响应
			    /// </summary>
			    event RspQryParkedOrder^ OnRspQryParkedOrder
			    {
				    void add(RspQryParkedOrder^ handler)
				    {
					    OnRspQryParkedOrder_delegate += handler;
				    }
				    void remove(RspQryParkedOrder^ handler)
				    {
					    OnRspQryParkedOrder_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetParkedOrderField^ pParkedOrder, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryParkedOrder_delegate)
						    OnRspQryParkedOrder_delegate(pParkedOrder, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询预埋撤单响应
			    /// </summary>
			    event RspQryParkedOrderAction^ OnRspQryParkedOrderAction
			    {
				    void add(RspQryParkedOrderAction^ handler)
				    {
					    OnRspQryParkedOrderAction_delegate += handler;
				    }
				    void remove(RspQryParkedOrderAction^ handler)
				    {
					    OnRspQryParkedOrderAction_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetParkedOrderActionField^ pParkedOrderAction, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryParkedOrderAction_delegate)
						    OnRspQryParkedOrderAction_delegate(pParkedOrderAction, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询交易通知响应
			    /// </summary>
			    event RspQryTradingNotice^ OnRspQryTradingNotice
			    {
				    void add(RspQryTradingNotice^ handler)
				    {
					    OnRspQryTradingNotice_delegate += handler;
				    }
				    void remove(RspQryTradingNotice^ handler)
				    {
					    OnRspQryTradingNotice_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetTradingNoticeField^ pTradingNotice, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryTradingNotice_delegate)
						    OnRspQryTradingNotice_delegate(pTradingNotice, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询经纪公司交易参数响应
			    /// </summary>
			    event RspQryBrokerTradingParams^ OnRspQryBrokerTradingParams
			    {
				    void add(RspQryBrokerTradingParams^ handler)
				    {
					    OnRspQryBrokerTradingParams_delegate += handler;
				    }
				    void remove(RspQryBrokerTradingParams^ handler)
				    {
					    OnRspQryBrokerTradingParams_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetBrokerTradingParamsField^ pBrokerTradingParams, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryBrokerTradingParams_delegate)
						    OnRspQryBrokerTradingParams_delegate(pBrokerTradingParams, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询经纪公司交易算法响应
			    /// </summary>
			    event RspQryBrokerTradingAlgos^ OnRspQryBrokerTradingAlgos
			    {
				    void add(RspQryBrokerTradingAlgos^ handler)
				    {
					    OnRspQryBrokerTradingAlgos_delegate += handler;
				    }
				    void remove(RspQryBrokerTradingAlgos^ handler)
				    {
					    OnRspQryBrokerTradingAlgos_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetBrokerTradingAlgosField^ pBrokerTradingAlgos, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQryBrokerTradingAlgos_delegate)
						    OnRspQryBrokerTradingAlgos_delegate(pBrokerTradingAlgos, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 请求查询监控中心用户令牌
			    /// </summary>
			    event RspQueryCFMMCTradingAccountToken^ OnRspQueryCFMMCTradingAccountToken
			    {
				    void add(RspQueryCFMMCTradingAccountToken^ handler)
				    {
					    OnRspQueryCFMMCTradingAccountToken_delegate += handler;
				    }
				    void remove(RspQueryCFMMCTradingAccountToken^ handler)
				    {
					    OnRspQueryCFMMCTradingAccountToken_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetQueryCFMMCTradingAccountTokenField^ pQueryCFMMCTradingAccountToken, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQueryCFMMCTradingAccountToken_delegate)
						    OnRspQueryCFMMCTradingAccountToken_delegate(pQueryCFMMCTradingAccountToken, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 银行发起银行资金转期货通知
			    /// </summary>
			    event RtnFromBankToFutureByBank^ OnRtnFromBankToFutureByBank
			    {
				    void add(RtnFromBankToFutureByBank^ handler)
				    {
					    OnRtnFromBankToFutureByBank_delegate += handler;
				    }
				    void remove(RtnFromBankToFutureByBank^ handler)
				    {
					    OnRtnFromBankToFutureByBank_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetRspTransferField^ pRspTransfer)
				    {
					    if (OnRtnFromBankToFutureByBank_delegate)
						    OnRtnFromBankToFutureByBank_delegate(pRspTransfer);
				    }
			    }

			    /// <summary>
			    /// 银行发起期货资金转银行通知
			    /// </summary>
			    event RtnFromFutureToBankByBank^ OnRtnFromFutureToBankByBank
			    {
				    void add(RtnFromFutureToBankByBank^ handler)
				    {
					    OnRtnFromFutureToBankByBank_delegate += handler;
				    }
				    void remove(RtnFromFutureToBankByBank^ handler)
				    {
					    OnRtnFromFutureToBankByBank_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetRspTransferField^ pRspTransfer)
				    {
					    if (OnRtnFromFutureToBankByBank_delegate)
						    OnRtnFromFutureToBankByBank_delegate(pRspTransfer);
				    }
			    }

			    /// <summary>
			    /// 银行发起冲正银行转期货通知
			    /// </summary>
			    event RtnRepealFromBankToFutureByBank^ OnRtnRepealFromBankToFutureByBank
			    {
				    void add(RtnRepealFromBankToFutureByBank^ handler)
				    {
					    OnRtnRepealFromBankToFutureByBank_delegate += handler;
				    }
				    void remove(RtnRepealFromBankToFutureByBank^ handler)
				    {
					    OnRtnRepealFromBankToFutureByBank_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetRspRepealField^ pRspRepeal)
				    {
					    if (OnRtnRepealFromBankToFutureByBank_delegate)
						    OnRtnRepealFromBankToFutureByBank_delegate(pRspRepeal);
				    }
			    }

			    /// <summary>
			    /// 银行发起冲正期货转银行通知
			    /// </summary>
			    event RtnRepealFromFutureToBankByBank^ OnRtnRepealFromFutureToBankByBank
			    {
				    void add(RtnRepealFromFutureToBankByBank^ handler)
				    {
					    OnRtnRepealFromFutureToBankByBank_delegate += handler;
				    }
				    void remove(RtnRepealFromFutureToBankByBank^ handler)
				    {
					    OnRtnRepealFromFutureToBankByBank_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetRspRepealField^ pRspRepeal)
				    {
					    if (OnRtnRepealFromFutureToBankByBank_delegate)
						    OnRtnRepealFromFutureToBankByBank_delegate(pRspRepeal);
				    }
			    }

			    /// <summary>
			    /// 期货发起银行资金转期货通知
			    /// </summary>
			    event RtnFromBankToFutureByFuture^ OnRtnFromBankToFutureByFuture
			    {
				    void add(RtnFromBankToFutureByFuture^ handler)
				    {
					    OnRtnFromBankToFutureByFuture_delegate += handler;
				    }
				    void remove(RtnFromBankToFutureByFuture^ handler)
				    {
					    OnRtnFromBankToFutureByFuture_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetRspTransferField^ pRspTransfer)
				    {
					    if (OnRtnFromBankToFutureByFuture_delegate)
						    OnRtnFromBankToFutureByFuture_delegate(pRspTransfer);
				    }
			    }

			    /// <summary>
			    /// 期货发起期货资金转银行通知
			    /// </summary>
			    event RtnFromFutureToBankByFuture^ OnRtnFromFutureToBankByFuture
			    {
				    void add(RtnFromFutureToBankByFuture^ handler)
				    {
					    OnRtnFromFutureToBankByFuture_delegate += handler;
				    }
				    void remove(RtnFromFutureToBankByFuture^ handler)
				    {
					    OnRtnFromFutureToBankByFuture_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetRspTransferField^ pRspTransfer)
				    {
					    if (OnRtnFromFutureToBankByFuture_delegate)
						    OnRtnFromFutureToBankByFuture_delegate(pRspTransfer);
				    }
			    }

			    /// <summary>
			    /// 系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
			    /// </summary>
			    event RtnRepealFromBankToFutureByFutureManual^ OnRtnRepealFromBankToFutureByFutureManual
			    {
				    void add(RtnRepealFromBankToFutureByFutureManual^ handler)
				    {
					    OnRtnRepealFromBankToFutureByFutureManual_delegate += handler;
				    }
				    void remove(RtnRepealFromBankToFutureByFutureManual^ handler)
				    {
					    OnRtnRepealFromBankToFutureByFutureManual_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetRspRepealField^ pRspRepeal)
				    {
					    if (OnRtnRepealFromBankToFutureByFutureManual_delegate)
						    OnRtnRepealFromBankToFutureByFutureManual_delegate(pRspRepeal);
				    }
			    }

			    /// <summary>
			    /// 系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
			    /// </summary>
			    event RtnRepealFromFutureToBankByFutureManual^ OnRtnRepealFromFutureToBankByFutureManual
			    {
				    void add(RtnRepealFromFutureToBankByFutureManual^ handler)
				    {
					    OnRtnRepealFromFutureToBankByFutureManual_delegate += handler;
				    }
				    void remove(RtnRepealFromFutureToBankByFutureManual^ handler)
				    {
					    OnRtnRepealFromFutureToBankByFutureManual_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetRspRepealField^ pRspRepeal)
				    {
					    if (OnRtnRepealFromFutureToBankByFutureManual_delegate)
						    OnRtnRepealFromFutureToBankByFutureManual_delegate(pRspRepeal);
				    }
			    }

			    /// <summary>
			    /// 期货发起查询银行余额通知
			    /// </summary>
			    event RtnQueryBankBalanceByFuture^ OnRtnQueryBankBalanceByFuture
			    {
				    void add(RtnQueryBankBalanceByFuture^ handler)
				    {
					    OnRtnQueryBankBalanceByFuture_delegate += handler;
				    }
				    void remove(RtnQueryBankBalanceByFuture^ handler)
				    {
					    OnRtnQueryBankBalanceByFuture_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetNotifyQueryAccountField^ pNotifyQueryAccount)
				    {
					    if (OnRtnQueryBankBalanceByFuture_delegate)
						    OnRtnQueryBankBalanceByFuture_delegate(pNotifyQueryAccount);
				    }
			    }

			    /// <summary>
			    /// 期货发起银行资金转期货错误回报
			    /// </summary>
			    event ErrRtnBankToFutureByFuture^ OnErrRtnBankToFutureByFuture
			    {
				    void add(ErrRtnBankToFutureByFuture^ handler)
				    {
					    OnErrRtnBankToFutureByFuture_delegate += handler;
				    }
				    void remove(ErrRtnBankToFutureByFuture^ handler)
				    {
					    OnErrRtnBankToFutureByFuture_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetReqTransferField^ pReqTransfer, CtpNetRspInfoField^ pRspInfo)
				    {
					    if (OnErrRtnBankToFutureByFuture_delegate)
						    OnErrRtnBankToFutureByFuture_delegate(pReqTransfer, pRspInfo);
				    }
			    }

			    /// <summary>
			    /// 期货发起期货资金转银行错误回报
			    /// </summary>
			    event ErrRtnFutureToBankByFuture^ OnErrRtnFutureToBankByFuture
			    {
				    void add(ErrRtnFutureToBankByFuture^ handler)
				    {
					    OnErrRtnFutureToBankByFuture_delegate += handler;
				    }
				    void remove(ErrRtnFutureToBankByFuture^ handler)
				    {
					    OnErrRtnFutureToBankByFuture_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetReqTransferField^ pReqTransfer, CtpNetRspInfoField^ pRspInfo)
				    {
					    if (OnErrRtnFutureToBankByFuture_delegate)
						    OnErrRtnFutureToBankByFuture_delegate(pReqTransfer, pRspInfo);
				    }
			    }

			    /// <summary>
			    /// 系统运行时期货端手工发起冲正银行转期货错误回报
			    /// </summary>
			    event ErrRtnRepealBankToFutureByFutureManual^ OnErrRtnRepealBankToFutureByFutureManual
			    {
				    void add(ErrRtnRepealBankToFutureByFutureManual^ handler)
				    {
					    OnErrRtnRepealBankToFutureByFutureManual_delegate += handler;
				    }
				    void remove(ErrRtnRepealBankToFutureByFutureManual^ handler)
				    {
					    OnErrRtnRepealBankToFutureByFutureManual_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetReqRepealField^ pReqRepeal, CtpNetRspInfoField^ pRspInfo)
				    {
					    if (OnErrRtnRepealBankToFutureByFutureManual_delegate)
						    OnErrRtnRepealBankToFutureByFutureManual_delegate(pReqRepeal, pRspInfo);
				    }
			    }

			    /// <summary>
			    /// 系统运行时期货端手工发起冲正期货转银行错误回报
			    /// </summary>
			    event ErrRtnRepealFutureToBankByFutureManual^ OnErrRtnRepealFutureToBankByFutureManual
			    {
				    void add(ErrRtnRepealFutureToBankByFutureManual^ handler)
				    {
					    OnErrRtnRepealFutureToBankByFutureManual_delegate += handler;
				    }
				    void remove(ErrRtnRepealFutureToBankByFutureManual^ handler)
				    {
					    OnErrRtnRepealFutureToBankByFutureManual_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetReqRepealField^ pReqRepeal, CtpNetRspInfoField^ pRspInfo)
				    {
					    if (OnErrRtnRepealFutureToBankByFutureManual_delegate)
						    OnErrRtnRepealFutureToBankByFutureManual_delegate(pReqRepeal, pRspInfo);
				    }
			    }

			    /// <summary>
			    /// 期货发起查询银行余额错误回报
			    /// </summary>
			    event ErrRtnQueryBankBalanceByFuture^ OnErrRtnQueryBankBalanceByFuture
			    {
				    void add(ErrRtnQueryBankBalanceByFuture^ handler)
				    {
					    OnErrRtnQueryBankBalanceByFuture_delegate += handler;
				    }
				    void remove(ErrRtnQueryBankBalanceByFuture^ handler)
				    {
					    OnErrRtnQueryBankBalanceByFuture_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetReqQueryAccountField^ pReqQueryAccount, CtpNetRspInfoField^ pRspInfo)
				    {
					    if (OnErrRtnQueryBankBalanceByFuture_delegate)
						    OnErrRtnQueryBankBalanceByFuture_delegate(pReqQueryAccount, pRspInfo);
				    }
			    }

			    /// <summary>
			    /// 期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
			    /// </summary>
			    event RtnRepealFromBankToFutureByFuture^ OnRtnRepealFromBankToFutureByFuture
			    {
				    void add(RtnRepealFromBankToFutureByFuture^ handler)
				    {
					    OnRtnRepealFromBankToFutureByFuture_delegate += handler;
				    }
				    void remove(RtnRepealFromBankToFutureByFuture^ handler)
				    {
					    OnRtnRepealFromBankToFutureByFuture_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetRspRepealField^ pRspRepeal)
				    {
					    if (OnRtnRepealFromBankToFutureByFuture_delegate)
						    OnRtnRepealFromBankToFutureByFuture_delegate(pRspRepeal);
				    }
			    }

			    /// <summary>
			    /// 期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
			    /// </summary>
			    event RtnRepealFromFutureToBankByFuture^ OnRtnRepealFromFutureToBankByFuture
			    {
				    void add(RtnRepealFromFutureToBankByFuture^ handler)
				    {
					    OnRtnRepealFromFutureToBankByFuture_delegate += handler;
				    }
				    void remove(RtnRepealFromFutureToBankByFuture^ handler)
				    {
					    OnRtnRepealFromFutureToBankByFuture_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetRspRepealField^ pRspRepeal)
				    {
					    if (OnRtnRepealFromFutureToBankByFuture_delegate)
						    OnRtnRepealFromFutureToBankByFuture_delegate(pRspRepeal);
				    }
			    }

			    /// <summary>
			    /// 期货发起银行资金转期货应答
			    /// </summary>
			    event RspFromBankToFutureByFuture^ OnRspFromBankToFutureByFuture
			    {
				    void add(RspFromBankToFutureByFuture^ handler)
				    {
					    OnRspFromBankToFutureByFuture_delegate += handler;
				    }
				    void remove(RspFromBankToFutureByFuture^ handler)
				    {
					    OnRspFromBankToFutureByFuture_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetReqTransferField^ pReqTransfer, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspFromBankToFutureByFuture_delegate)
						    OnRspFromBankToFutureByFuture_delegate(pReqTransfer, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 期货发起期货资金转银行应答
			    /// </summary>
			    event RspFromFutureToBankByFuture^ OnRspFromFutureToBankByFuture
			    {
				    void add(RspFromFutureToBankByFuture^ handler)
				    {
					    OnRspFromFutureToBankByFuture_delegate += handler;
				    }
				    void remove(RspFromFutureToBankByFuture^ handler)
				    {
					    OnRspFromFutureToBankByFuture_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetReqTransferField^ pReqTransfer, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspFromFutureToBankByFuture_delegate)
						    OnRspFromFutureToBankByFuture_delegate(pReqTransfer, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 期货发起查询银行余额应答
			    /// </summary>
			    event RspQueryBankAccountMoneyByFuture^ OnRspQueryBankAccountMoneyByFuture
			    {
				    void add(RspQueryBankAccountMoneyByFuture^ handler)
				    {
					    OnRspQueryBankAccountMoneyByFuture_delegate += handler;
				    }
				    void remove(RspQueryBankAccountMoneyByFuture^ handler)
				    {
					    OnRspQueryBankAccountMoneyByFuture_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetReqQueryAccountField^ pReqQueryAccount, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
				    {
					    if (OnRspQueryBankAccountMoneyByFuture_delegate)
						    OnRspQueryBankAccountMoneyByFuture_delegate(pReqQueryAccount, pRspInfo, nRequestID, bIsLast);
				    }
			    }

			    /// <summary>
			    /// 银行发起银期开户通知
			    /// </summary>
			    event RtnOpenAccountByBank^ OnRtnOpenAccountByBank
			    {
				    void add(RtnOpenAccountByBank^ handler)
				    {
					    OnRtnOpenAccountByBank_delegate += handler;
				    }
				    void remove(RtnOpenAccountByBank^ handler)
				    {
					    OnRtnOpenAccountByBank_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetOpenAccountField^ pOpenAccount)
				    {
					    if (OnRtnOpenAccountByBank_delegate)
						    OnRtnOpenAccountByBank_delegate(pOpenAccount);
				    }
			    }

			    /// <summary>
			    /// 银行发起银期销户通知
			    /// </summary>
			    event RtnCancelAccountByBank^ OnRtnCancelAccountByBank
			    {
				    void add(RtnCancelAccountByBank^ handler)
				    {
					    OnRtnCancelAccountByBank_delegate += handler;
				    }
				    void remove(RtnCancelAccountByBank^ handler)
				    {
					    OnRtnCancelAccountByBank_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetCancelAccountField^ pCancelAccount)
				    {
					    if (OnRtnCancelAccountByBank_delegate)
						    OnRtnCancelAccountByBank_delegate(pCancelAccount);
				    }
			    }

			    /// <summary>
			    /// 银行发起变更银行账号通知
			    /// </summary>
			    event RtnChangeAccountByBank^ OnRtnChangeAccountByBank
			    {
				    void add(RtnChangeAccountByBank^ handler)
				    {
					    OnRtnChangeAccountByBank_delegate += handler;
				    }
				    void remove(RtnChangeAccountByBank^ handler)
				    {
					    OnRtnChangeAccountByBank_delegate -= handler;
				    }
			    internal:
				    void raise(CtpNetChangeAccountField^ pChangeAccount)
				    {
					    if (OnRtnChangeAccountByBank_delegate)
						    OnRtnChangeAccountByBank_delegate(pChangeAccount);
				    }
			    }
		    };
		};
	};
};
