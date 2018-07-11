#pragma once

#include "Struct.h"

namespace TaiTanXing
{
	namespace Ctp
	{
		namespace CtpProxy
		{
			//////////////////////////////////////////////////////////////////////
			/// 行情与交易共用
			//////////////////////////////////////////////////////////////////////

			/// <summary>
			/// 当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
			/// </summary>
			public delegate void FrontConnected();

			/// <summary>
			/// 当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
			/// </summary>
			public delegate void FrontDisconnected(int nReason);

			/// <summary>
			/// 心跳超时警告。当长时间未收到报文时，该方法被调用。
			/// </summary>
			public delegate void HeartBeatWarning(int nTimeLapse);

			/// <summary>
			/// 登录请求响应
			/// </summary>
			public delegate void RspUserLogin(CtpNetRspUserLoginField^ pRspUserLogin, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 登出请求响应
			/// </summary>
			public delegate void RspUserLogout(CtpNetUserLogoutField^ pUserLogout, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 错误应答
			/// </summary>
			public delegate void RspError(CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 询价通知
			/// </summary>
			public delegate void RtnForQuoteRsp(CtpNetForQuoteRspField^ pForQuoteRsp);

			//////////////////////////////////////////////////////////////////////
			/// 行情
			//////////////////////////////////////////////////////////////////////

			/// <summary>
			/// 订阅行情应答
			/// </summary>
			public delegate void RspSubMarketData(CtpNetSpecificInstrumentField^ pSpecificInstrument, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 取消订阅行情应答
			/// </summary>
			public delegate void RspUnSubMarketData(CtpNetSpecificInstrumentField^ pSpecificInstrument, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 订阅询价应答
			/// </summary>
			public delegate void RspSubForQuoteRsp(CtpNetSpecificInstrumentField^ pSpecificInstrument, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 取消订阅询价应答
			/// </summary>
			public delegate void RspUnSubForQuoteRsp(CtpNetSpecificInstrumentField^ pSpecificInstrument, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 深度行情通知
			/// </summary>
			public delegate void RtnDepthMarketData(CtpNetDepthMarketDataField^ pDepthMarketData);

			//////////////////////////////////////////////////////////////////////
			/// 交易
			//////////////////////////////////////////////////////////////////////

			/// <summary>
			/// 客户端认证响应
			/// </summary>
			public delegate void RspAuthenticate(CtpNetRspAuthenticateField^ pRspAuthenticateField, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 用户口令更新请求响应
			/// </summary>
			public delegate void RspUserPasswordUpdate(CtpNetUserPasswordUpdateField^ pUserPasswordUpdate, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 资金账户口令更新请求响应
			/// </summary>
			public delegate void RspTradingAccountPasswordUpdate(CtpNetTradingAccountPasswordUpdateField^ pTradingAccountPasswordUpdate, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 报单录入请求响应
			/// </summary>
			public delegate void RspOrderInsert(CtpNetInputOrderField^ pInputOrder, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 预埋单录入请求响应
			/// </summary>
			public delegate void RspParkedOrderInsert(CtpNetParkedOrderField^ pParkedOrder, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 预埋撤单录入请求响应
			/// </summary>
			public delegate void RspParkedOrderAction(CtpNetParkedOrderActionField^ pParkedOrderAction, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 报单操作请求响应
			/// </summary>
			public delegate void RspOrderAction(CtpNetInputOrderActionField^ pInputOrderAction, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 查询最大报单数量响应
			/// </summary>
			public delegate void RspQueryMaxOrderVolume(CtpNetQueryMaxOrderVolumeField^ pQueryMaxOrderVolume, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 投资者结算结果确认响应
			/// </summary>
			public delegate void RspSettlementInfoConfirm(CtpNetSettlementInfoConfirmField^ pSettlementInfoConfirm, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 删除预埋单响应
			/// </summary>
			public delegate void RspRemoveParkedOrder(CtpNetRemoveParkedOrderField^ pRemoveParkedOrder, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 删除预埋撤单响应
			/// </summary>
			public delegate void RspRemoveParkedOrderAction(CtpNetRemoveParkedOrderActionField^ pRemoveParkedOrderAction, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 执行宣告录入请求响应
			/// </summary>
			public delegate void RspExecOrderInsert(CtpNetInputExecOrderField^ pInputExecOrder, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 执行宣告操作请求响应
			/// </summary>
			public delegate void RspExecOrderAction(CtpNetInputExecOrderActionField^ pInputExecOrderAction, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 询价录入请求响应
			/// </summary>
			public delegate void RspForQuoteInsert(CtpNetInputForQuoteField^ pInputForQuote, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 报价录入请求响应
			/// </summary>
			public delegate void RspQuoteInsert(CtpNetInputQuoteField^ pInputQuote, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 报价操作请求响应
			/// </summary>
			public delegate void RspQuoteAction(CtpNetInputQuoteActionField^ pInputQuoteAction, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 批量报单操作请求响应
			/// </summary>
			public delegate void RspBatchOrderAction(CtpNetInputBatchOrderActionField^ pInputBatchOrderAction, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 期权自对冲录入请求响应
			/// </summary>
			public delegate void RspOptionSelfCloseInsert(CtpNetInputOptionSelfCloseField^ pInputOptionSelfClose, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 期权自对冲操作请求响应
			/// </summary>
			public delegate void RspOptionSelfCloseAction(CtpNetInputOptionSelfCloseActionField^ pInputOptionSelfCloseAction, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 申请组合录入请求响应
			/// </summary>
			public delegate void RspCombActionInsert(CtpNetInputCombActionField^ pInputCombAction, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询报单响应
			/// </summary>
			public delegate void RspQryOrder(CtpNetOrderField^ pOrder, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询成交响应
			/// </summary>
			public delegate void RspQryTrade(CtpNetTradeField^ pTrade, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询投资者持仓响应
			/// </summary>
			public delegate void RspQryInvestorPosition(CtpNetInvestorPositionField^ pInvestorPosition, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询资金账户响应
			/// </summary>
			public delegate void RspQryTradingAccount(CtpNetTradingAccountField^ pTradingAccount, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询投资者响应
			/// </summary>
			public delegate void RspQryInvestor(CtpNetInvestorField^ pInvestor, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询交易编码响应
			/// </summary>
			public delegate void RspQryTradingCode(CtpNetTradingCodeField^ pTradingCode, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询合约保证金率响应
			/// </summary>
			public delegate void RspQryInstrumentMarginRate(CtpNetInstrumentMarginRateField^ pInstrumentMarginRate, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询合约手续费率响应
			/// </summary>
			public delegate void RspQryInstrumentCommissionRate(CtpNetInstrumentCommissionRateField^ pInstrumentCommissionRate, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询交易所响应
			/// </summary>
			public delegate void RspQryExchange(CtpNetExchangeField^ pExchange, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询产品响应
			/// </summary>
			public delegate void RspQryProduct(CtpNetProductField^ pProduct, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询合约响应
			/// </summary>
			public delegate void RspQryInstrument(CtpNetInstrumentField^ pInstrument, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询行情响应
			/// </summary>
			public delegate void RspQryDepthMarketData(CtpNetDepthMarketDataField^ pDepthMarketData, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询投资者结算结果响应
			/// </summary>
			public delegate void RspQrySettlementInfo(CtpNetSettlementInfoField^ pSettlementInfo, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询转帐银行响应
			/// </summary>
			public delegate void RspQryTransferBank(CtpNetTransferBankField^ pTransferBank, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询投资者持仓明细响应
			/// </summary>
			public delegate void RspQryInvestorPositionDetail(CtpNetInvestorPositionDetailField^ pInvestorPositionDetail, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询客户通知响应
			/// </summary>
			public delegate void RspQryNotice(CtpNetNoticeField^ pNotice, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询结算信息确认响应
			/// </summary>
			public delegate void RspQrySettlementInfoConfirm(CtpNetSettlementInfoConfirmField^ pSettlementInfoConfirm, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询投资者持仓明细响应
			/// </summary>
			public delegate void RspQryInvestorPositionCombineDetail(CtpNetInvestorPositionCombineDetailField^ pInvestorPositionCombineDetail, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 查询保证金监管系统经纪公司资金账户密钥响应
			/// </summary>
			public delegate void RspQryCFMMCTradingAccountKey(CtpNetCFMMCTradingAccountKeyField^ pCFMMCTradingAccountKey, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询仓单折抵信息响应
			/// </summary>
			public delegate void RspQryEWarrantOffset(CtpNetEWarrantOffsetField^ pEWarrantOffset, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询投资者品种/跨品种保证金响应
			/// </summary>
			public delegate void RspQryInvestorProductGroupMargin(CtpNetInvestorProductGroupMarginField^ pInvestorProductGroupMargin, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询交易所保证金率响应
			/// </summary>
			public delegate void RspQryExchangeMarginRate(CtpNetExchangeMarginRateField^ pExchangeMarginRate, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询交易所调整保证金率响应
			/// </summary>
			public delegate void RspQryExchangeMarginRateAdjust(CtpNetExchangeMarginRateAdjustField^ pExchangeMarginRateAdjust, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询汇率响应
			/// </summary>
			public delegate void RspQryExchangeRate(CtpNetExchangeRateField^ pExchangeRate, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询二级代理操作员银期权限响应
			/// </summary>
			public delegate void RspQrySecAgentACIDMap(CtpNetSecAgentACIDMapField^ pSecAgentACIDMap, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询产品报价汇率
			/// </summary>
			public delegate void RspQryProductExchRate(CtpNetProductExchRateField^ pProductExchRate, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询产品组
			/// </summary>
			public delegate void RspQryProductGroup(CtpNetProductGroupField^ pProductGroup, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询做市商合约手续费率响应
			/// </summary>
			public delegate void RspQryMMInstrumentCommissionRate(CtpNetMMInstrumentCommissionRateField^ pMMInstrumentCommissionRate, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询做市商期权合约手续费响应
			/// </summary>
			public delegate void RspQryMMOptionInstrCommRate(CtpNetMMOptionInstrCommRateField^ pMMOptionInstrCommRate, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询报单手续费响应
			/// </summary>
			public delegate void RspQryInstrumentOrderCommRate(CtpNetInstrumentOrderCommRateField^ pInstrumentOrderCommRate, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询资金账户响应
			/// </summary>
			public delegate void RspQrySecAgentTradingAccount(CtpNetTradingAccountField^ pTradingAccount, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询二级代理商资金校验模式响应
			/// </summary>
			public delegate void RspQrySecAgentCheckMode(CtpNetSecAgentCheckModeField^ pSecAgentCheckMode, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询期权交易成本响应
			/// </summary>
			public delegate void RspQryOptionInstrTradeCost(CtpNetOptionInstrTradeCostField^ pOptionInstrTradeCost, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询期权合约手续费响应
			/// </summary>
			public delegate void RspQryOptionInstrCommRate(CtpNetOptionInstrCommRateField^ pOptionInstrCommRate, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询执行宣告响应
			/// </summary>
			public delegate void RspQryExecOrder(CtpNetExecOrderField^ pExecOrder, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询询价响应
			/// </summary>
			public delegate void RspQryForQuote(CtpNetForQuoteField^ pForQuote, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询报价响应
			/// </summary>
			public delegate void RspQryQuote(CtpNetQuoteField^ pQuote, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询期权自对冲响应
			/// </summary>
			public delegate void RspQryOptionSelfClose(CtpNetOptionSelfCloseField^ pOptionSelfClose, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询投资单元响应
			/// </summary>
			public delegate void RspQryInvestUnit(CtpNetInvestUnitField^ pInvestUnit, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询组合合约安全系数响应
			/// </summary>
			public delegate void RspQryCombInstrumentGuard(CtpNetCombInstrumentGuardField^ pCombInstrumentGuard, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询申请组合响应
			/// </summary>
			public delegate void RspQryCombAction(CtpNetCombActionField^ pCombAction, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询转帐流水响应
			/// </summary>
			public delegate void RspQryTransferSerial(CtpNetTransferSerialField^ pTransferSerial, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询银期签约关系响应
			/// </summary>
			public delegate void RspQryAccountregister(CtpNetAccountregisterField^ pAccountregister, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 报单通知
			/// </summary>
			public delegate void RtnOrder(CtpNetOrderField^ pOrder);

			/// <summary>
			/// 成交通知
			/// </summary>
			public delegate void RtnTrade(CtpNetTradeField^ pTrade);

			/// <summary>
			/// 报单录入错误回报
			/// </summary>
			public delegate void ErrRtnOrderInsert(CtpNetInputOrderField^ pInputOrder, CtpNetRspInfoField^ pRspInfo);

			/// <summary>
			/// 报单操作错误回报
			/// </summary>
			public delegate void ErrRtnOrderAction(CtpNetOrderActionField^ pOrderAction, CtpNetRspInfoField^ pRspInfo);

			/// <summary>
			/// 合约交易状态通知
			/// </summary>
			public delegate void RtnInstrumentStatus(CtpNetInstrumentStatusField^ pInstrumentStatus);

			/// <summary>
			/// 交易所公告通知
			/// </summary>
			public delegate void RtnBulletin(CtpNetBulletinField^ pBulletin);

			/// <summary>
			/// 交易通知
			/// </summary>
			public delegate void RtnTradingNotice(CtpNetTradingNoticeInfoField^ pTradingNoticeInfo);

			/// <summary>
			/// 提示条件单校验错误
			/// </summary>
			public delegate void RtnErrorConditionalOrder(CtpNetErrorConditionalOrderField^ pErrorConditionalOrder);

			/// <summary>
			/// 执行宣告通知
			/// </summary>
			public delegate void RtnExecOrder(CtpNetExecOrderField^ pExecOrder);

			/// <summary>
			/// 执行宣告录入错误回报
			/// </summary>
			public delegate void ErrRtnExecOrderInsert(CtpNetInputExecOrderField^ pInputExecOrder, CtpNetRspInfoField^ pRspInfo);

			/// <summary>
			/// 执行宣告操作错误回报
			/// </summary>
			public delegate void ErrRtnExecOrderAction(CtpNetExecOrderActionField^ pExecOrderAction, CtpNetRspInfoField^ pRspInfo);

			/// <summary>
			/// 询价录入错误回报
			/// </summary>
			public delegate void ErrRtnForQuoteInsert(CtpNetInputForQuoteField^ pInputForQuote, CtpNetRspInfoField^ pRspInfo);

			/// <summary>
			/// 报价通知
			/// </summary>
			public delegate void RtnQuote(CtpNetQuoteField^ pQuote);

			/// <summary>
			/// 报价录入错误回报
			/// </summary>
			public delegate void ErrRtnQuoteInsert(CtpNetInputQuoteField^ pInputQuote, CtpNetRspInfoField^ pRspInfo);

			/// <summary>
			/// 报价操作错误回报
			/// </summary>
			public delegate void ErrRtnQuoteAction(CtpNetQuoteActionField^ pQuoteAction, CtpNetRspInfoField^ pRspInfo);

			/// <summary>
			/// 保证金监控中心用户令牌
			/// </summary>
			public delegate void RtnCFMMCTradingAccountToken(CtpNetCFMMCTradingAccountTokenField^ pCFMMCTradingAccountToken);

			/// <summary>
			/// 批量报单操作错误回报
			/// </summary>
			public delegate void ErrRtnBatchOrderAction(CtpNetBatchOrderActionField^ pBatchOrderAction, CtpNetRspInfoField^ pRspInfo);

			/// <summary>
			/// 期权自对冲通知
			/// </summary>
			public delegate void RtnOptionSelfClose(CtpNetOptionSelfCloseField^ pOptionSelfClose);

			/// <summary>
			/// 期权自对冲录入错误回报
			/// </summary>
			public delegate void ErrRtnOptionSelfCloseInsert(CtpNetInputOptionSelfCloseField^ pInputOptionSelfClose, CtpNetRspInfoField^ pRspInfo);

			/// <summary>
			/// 期权自对冲操作错误回报
			/// </summary>
			public delegate void ErrRtnOptionSelfCloseAction(CtpNetOptionSelfCloseActionField^ pOptionSelfCloseAction, CtpNetRspInfoField^ pRspInfo);

			/// <summary>
			/// 申请组合通知
			/// </summary>
			public delegate void RtnCombAction(CtpNetCombActionField^ pCombAction);

			/// <summary>
			/// 申请组合录入错误回报
			/// </summary>
			public delegate void ErrRtnCombActionInsert(CtpNetInputCombActionField^ pInputCombAction, CtpNetRspInfoField^ pRspInfo);

			/// <summary>
			/// 请求查询签约银行响应
			/// </summary>
			public delegate void RspQryContractBank(CtpNetContractBankField^ pContractBank, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询预埋单响应
			/// </summary>
			public delegate void RspQryParkedOrder(CtpNetParkedOrderField^ pParkedOrder, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询预埋撤单响应
			/// </summary>
			public delegate void RspQryParkedOrderAction(CtpNetParkedOrderActionField^ pParkedOrderAction, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询交易通知响应
			/// </summary>
			public delegate void RspQryTradingNotice(CtpNetTradingNoticeField^ pTradingNotice, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询经纪公司交易参数响应
			/// </summary>
			public delegate void RspQryBrokerTradingParams(CtpNetBrokerTradingParamsField^ pBrokerTradingParams, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询经纪公司交易算法响应
			/// </summary>
			public delegate void RspQryBrokerTradingAlgos(CtpNetBrokerTradingAlgosField^ pBrokerTradingAlgos, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 请求查询监控中心用户令牌
			/// </summary>
			public delegate void RspQueryCFMMCTradingAccountToken(CtpNetQueryCFMMCTradingAccountTokenField^ pQueryCFMMCTradingAccountToken, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 银行发起银行资金转期货通知
			/// </summary>
			public delegate void RtnFromBankToFutureByBank(CtpNetRspTransferField^ pRspTransfer);

			/// <summary>
			/// 银行发起期货资金转银行通知
			/// </summary>
			public delegate void RtnFromFutureToBankByBank(CtpNetRspTransferField^ pRspTransfer);

			/// <summary>
			/// 银行发起冲正银行转期货通知
			/// </summary>
			public delegate void RtnRepealFromBankToFutureByBank(CtpNetRspRepealField^ pRspRepeal);

			/// <summary>
			/// 银行发起冲正期货转银行通知
			/// </summary>
			public delegate void RtnRepealFromFutureToBankByBank(CtpNetRspRepealField^ pRspRepeal);

			/// <summary>
			/// 期货发起银行资金转期货通知
			/// </summary>
			public delegate void RtnFromBankToFutureByFuture(CtpNetRspTransferField^ pRspTransfer);

			/// <summary>
			/// 期货发起期货资金转银行通知
			/// </summary>
			public delegate void RtnFromFutureToBankByFuture(CtpNetRspTransferField^ pRspTransfer);

			/// <summary>
			/// 系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
			/// </summary>
			public delegate void RtnRepealFromBankToFutureByFutureManual(CtpNetRspRepealField^ pRspRepeal);

			/// <summary>
			/// 系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
			/// </summary>
			public delegate void RtnRepealFromFutureToBankByFutureManual(CtpNetRspRepealField^ pRspRepeal);

			/// <summary>
			/// 期货发起查询银行余额通知
			/// </summary>
			public delegate void RtnQueryBankBalanceByFuture(CtpNetNotifyQueryAccountField^ pNotifyQueryAccount);

			/// <summary>
			/// 期货发起银行资金转期货错误回报
			/// </summary>
			public delegate void ErrRtnBankToFutureByFuture(CtpNetReqTransferField^ pReqTransfer, CtpNetRspInfoField^ pRspInfo);

			/// <summary>
			/// 期货发起期货资金转银行错误回报
			/// </summary>
			public delegate void ErrRtnFutureToBankByFuture(CtpNetReqTransferField^ pReqTransfer, CtpNetRspInfoField^ pRspInfo);

			/// <summary>
			/// 系统运行时期货端手工发起冲正银行转期货错误回报
			/// </summary>
			public delegate void ErrRtnRepealBankToFutureByFutureManual(CtpNetReqRepealField^ pReqRepeal, CtpNetRspInfoField^ pRspInfo);

			/// <summary>
			/// 系统运行时期货端手工发起冲正期货转银行错误回报
			/// </summary>
			public delegate void ErrRtnRepealFutureToBankByFutureManual(CtpNetReqRepealField^ pReqRepeal, CtpNetRspInfoField^ pRspInfo);

			/// <summary>
			/// 期货发起查询银行余额错误回报
			/// </summary>
			public delegate void ErrRtnQueryBankBalanceByFuture(CtpNetReqQueryAccountField^ pReqQueryAccount, CtpNetRspInfoField^ pRspInfo);

			/// <summary>
			/// 期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
			/// </summary>
			public delegate void RtnRepealFromBankToFutureByFuture(CtpNetRspRepealField^ pRspRepeal);

			/// <summary>
			/// 期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
			/// </summary>
			public delegate void RtnRepealFromFutureToBankByFuture(CtpNetRspRepealField^ pRspRepeal);

			/// <summary>
			/// 期货发起银行资金转期货应答
			/// </summary>
			public delegate void RspFromBankToFutureByFuture(CtpNetReqTransferField^ pReqTransfer, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 期货发起期货资金转银行应答
			/// </summary>
			public delegate void RspFromFutureToBankByFuture(CtpNetReqTransferField^ pReqTransfer, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 期货发起查询银行余额应答
			/// </summary>
			public delegate void RspQueryBankAccountMoneyByFuture(CtpNetReqQueryAccountField^ pReqQueryAccount, CtpNetRspInfoField^ pRspInfo, int nRequestID, bool bIsLast);

			/// <summary>
			/// 银行发起银期开户通知
			/// </summary>
			public delegate void RtnOpenAccountByBank(CtpNetOpenAccountField^ pOpenAccount);

			/// <summary>
			/// 银行发起银期销户通知
			/// </summary>
			public delegate void RtnCancelAccountByBank(CtpNetCancelAccountField^ pCancelAccount);

			/// <summary>
			/// 银行发起变更银行账号通知
			/// </summary>
			public delegate void RtnChangeAccountByBank(CtpNetChangeAccountField^ pChangeAccount);
		};
	};
};
