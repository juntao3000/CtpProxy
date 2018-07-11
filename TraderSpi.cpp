#include "TraderSpi.h"

namespace Native
{
	// 交易命令响应
	CTraderSpi::CTraderSpi(TraderAdapter^ pAdapter)
	{
		m_pAdapter = pAdapter;
	};

	// 当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
	void CTraderSpi::OnFrontConnected()
	{
		if (m_pAdapter->OnFrontConnected_delegate == nullptr) return;
		
		m_pAdapter->OnFrontConnected();
	};

	// 当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
	// nReason 错误原因
	//         0x1001 网络读失败
	//         0x1002 网络写失败
	//         0x2001 接收心跳超时
	//         0x2002 发送心跳失败
	//         0x2003 收到错误报文
	void CTraderSpi::OnFrontDisconnected(int nReason)
	{
		if (m_pAdapter->OnFrontDisconnected_delegate == nullptr) return;
		
		m_pAdapter->OnFrontDisconnected(nReason);
	};

	// 心跳超时警告。当长时间未收到报文时，该方法被调用。
	// nTimeLapse 距离上次接收报文的时间
	void CTraderSpi::OnHeartBeatWarning(int nTimeLapse)
	{
		if (m_pAdapter->OnHeartBeatWarning_delegate == nullptr) return;
		
		m_pAdapter->OnHeartBeatWarning(nTimeLapse);
	};

	// 客户端认证响应
	void CTraderSpi::OnRspAuthenticate(CThostFtdcRspAuthenticateField *pRspAuthenticateField, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspAuthenticate_delegate == nullptr) return;
		
		CtpNetRspAuthenticateField^ field = nullptr;
		if (pRspAuthenticateField != nullptr)
		{
			field = gcnew CtpNetRspAuthenticateField;
			
			//经纪公司代码
			if (pRspAuthenticateField->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pRspAuthenticateField->BrokerID);
			}
			//用户代码
			if (pRspAuthenticateField->UserID != nullptr)
			{
				field->UserID = gcnew String(pRspAuthenticateField->UserID);
			}
			//用户端产品信息
			if (pRspAuthenticateField->UserProductInfo != nullptr)
			{
				field->UserProductInfo = gcnew String(pRspAuthenticateField->UserProductInfo);
			}
		}
		
		m_pAdapter->OnRspAuthenticate(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 登录请求响应
	void CTraderSpi::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspUserLogin_delegate == nullptr) return;
		
		CtpNetRspUserLoginField^ field = nullptr;
		if (pRspUserLogin != nullptr)
		{
			field = gcnew CtpNetRspUserLoginField;
			
			//交易日
			if (pRspUserLogin->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pRspUserLogin->TradingDay);
			}
			//登录成功时间
			if (pRspUserLogin->LoginTime != nullptr)
			{
				field->LoginTime = gcnew String(pRspUserLogin->LoginTime);
			}
			//经纪公司代码
			if (pRspUserLogin->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pRspUserLogin->BrokerID);
			}
			//用户代码
			if (pRspUserLogin->UserID != nullptr)
			{
				field->UserID = gcnew String(pRspUserLogin->UserID);
			}
			//交易系统名称
			if (pRspUserLogin->SystemName != nullptr)
			{
				field->SystemName = gcnew String(pRspUserLogin->SystemName);
			}
			//前置编号
			field->FrontID = pRspUserLogin->FrontID;
			//会话编号
			field->SessionID = pRspUserLogin->SessionID;
			//最大报单引用
			if (pRspUserLogin->MaxOrderRef != nullptr)
			{
				field->MaxOrderRef = gcnew String(pRspUserLogin->MaxOrderRef);
			}
			//上期所时间
			if (pRspUserLogin->SHFETime != nullptr)
			{
				field->SHFETime = gcnew String(pRspUserLogin->SHFETime);
			}
			//大商所时间
			if (pRspUserLogin->DCETime != nullptr)
			{
				field->DCETime = gcnew String(pRspUserLogin->DCETime);
			}
			//郑商所时间
			if (pRspUserLogin->CZCETime != nullptr)
			{
				field->CZCETime = gcnew String(pRspUserLogin->CZCETime);
			}
			//中金所时间
			if (pRspUserLogin->FFEXTime != nullptr)
			{
				field->FFEXTime = gcnew String(pRspUserLogin->FFEXTime);
			}
			//能源中心时间
			if (pRspUserLogin->INETime != nullptr)
			{
				field->INETime = gcnew String(pRspUserLogin->INETime);
			}
		}
		
		m_pAdapter->OnRspUserLogin(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 登出请求响应
	void CTraderSpi::OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspUserLogout_delegate == nullptr) return;
		
		CtpNetUserLogoutField^ field = nullptr;
		if (pUserLogout != nullptr)
		{
			field = gcnew CtpNetUserLogoutField;
			
			//经纪公司代码
			if (pUserLogout->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pUserLogout->BrokerID);
			}
			//用户代码
			if (pUserLogout->UserID != nullptr)
			{
				field->UserID = gcnew String(pUserLogout->UserID);
			}
		}
		
		m_pAdapter->OnRspUserLogout(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 用户口令更新请求响应
	void CTraderSpi::OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspUserPasswordUpdate_delegate == nullptr) return;
		
		CtpNetUserPasswordUpdateField^ field = nullptr;
		if (pUserPasswordUpdate != nullptr)
		{
			field = gcnew CtpNetUserPasswordUpdateField;
			
			//经纪公司代码
			if (pUserPasswordUpdate->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pUserPasswordUpdate->BrokerID);
			}
			//用户代码
			if (pUserPasswordUpdate->UserID != nullptr)
			{
				field->UserID = gcnew String(pUserPasswordUpdate->UserID);
			}
			//原来的口令
			if (pUserPasswordUpdate->OldPassword != nullptr)
			{
				field->OldPassword = gcnew String(pUserPasswordUpdate->OldPassword);
			}
			//新的口令
			if (pUserPasswordUpdate->NewPassword != nullptr)
			{
				field->NewPassword = gcnew String(pUserPasswordUpdate->NewPassword);
			}
		}
		
		m_pAdapter->OnRspUserPasswordUpdate(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 资金账户口令更新请求响应
	void CTraderSpi::OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspTradingAccountPasswordUpdate_delegate == nullptr) return;
		
		CtpNetTradingAccountPasswordUpdateField^ field = nullptr;
		if (pTradingAccountPasswordUpdate != nullptr)
		{
			field = gcnew CtpNetTradingAccountPasswordUpdateField;
			
			//经纪公司代码
			if (pTradingAccountPasswordUpdate->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pTradingAccountPasswordUpdate->BrokerID);
			}
			//投资者帐号
			if (pTradingAccountPasswordUpdate->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pTradingAccountPasswordUpdate->AccountID);
			}
			//原来的口令
			if (pTradingAccountPasswordUpdate->OldPassword != nullptr)
			{
				field->OldPassword = gcnew String(pTradingAccountPasswordUpdate->OldPassword);
			}
			//新的口令
			if (pTradingAccountPasswordUpdate->NewPassword != nullptr)
			{
				field->NewPassword = gcnew String(pTradingAccountPasswordUpdate->NewPassword);
			}
			//币种代码
			if (pTradingAccountPasswordUpdate->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pTradingAccountPasswordUpdate->CurrencyID);
			}
		}
		
		m_pAdapter->OnRspTradingAccountPasswordUpdate(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 报单录入请求响应
	void CTraderSpi::OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspOrderInsert_delegate == nullptr) return;
		
		CtpNetInputOrderField^ field = nullptr;
		if (pInputOrder != nullptr)
		{
			field = gcnew CtpNetInputOrderField;
			
			//经纪公司代码
			if (pInputOrder->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pInputOrder->BrokerID);
			}
			//投资者代码
			if (pInputOrder->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pInputOrder->InvestorID);
			}
			//合约代码
			if (pInputOrder->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pInputOrder->InstrumentID);
			}
			//报单引用
			if (pInputOrder->OrderRef != nullptr)
			{
				field->OrderRef = gcnew String(pInputOrder->OrderRef);
			}
			//用户代码
			if (pInputOrder->UserID != nullptr)
			{
				field->UserID = gcnew String(pInputOrder->UserID);
			}
			//报单价格条件
			field->OrderPriceType = (CtpNetOrderPriceTypeType)pInputOrder->OrderPriceType;
			//买卖方向
			field->Direction = (CtpNetDirectionType)pInputOrder->Direction;
			//组合开平标志1
			field->CombOffsetFlag1 = (CtpNetOffsetFlagType)pInputOrder->CombOffsetFlag[0];
			//组合开平标志2
			field->CombOffsetFlag2 = (CtpNetOffsetFlagType)pInputOrder->CombOffsetFlag[1];
			//组合开平标志3
			field->CombOffsetFlag3 = (CtpNetOffsetFlagType)pInputOrder->CombOffsetFlag[2];
			//组合开平标志4
			field->CombOffsetFlag4 = (CtpNetOffsetFlagType)pInputOrder->CombOffsetFlag[3];
			//组合开平标志5
			field->CombOffsetFlag5 = (CtpNetOffsetFlagType)pInputOrder->CombOffsetFlag[4];
			//组合投机套保标志1
			field->CombHedgeFlag1 = (CtpNetHedgeFlagType)pInputOrder->CombHedgeFlag[0];
			//组合投机套保标志2
			field->CombHedgeFlag2 = (CtpNetHedgeFlagType)pInputOrder->CombHedgeFlag[1];
			//组合投机套保标志3
			field->CombHedgeFlag3 = (CtpNetHedgeFlagType)pInputOrder->CombHedgeFlag[2];
			//组合投机套保标志4
			field->CombHedgeFlag4 = (CtpNetHedgeFlagType)pInputOrder->CombHedgeFlag[3];
			//组合投机套保标志5
			field->CombHedgeFlag5 = (CtpNetHedgeFlagType)pInputOrder->CombHedgeFlag[4];
			//价格
			field->LimitPrice = pInputOrder->LimitPrice;
			//数量
			field->VolumeTotalOriginal = pInputOrder->VolumeTotalOriginal;
			//有效期类型
			field->TimeCondition = (CtpNetTimeConditionType)pInputOrder->TimeCondition;
			//GTD日期
			if (pInputOrder->GTDDate != nullptr)
			{
				field->GTDDate = gcnew String(pInputOrder->GTDDate);
			}
			//成交量类型
			field->VolumeCondition = (CtpNetVolumeConditionType)pInputOrder->VolumeCondition;
			//最小成交量
			field->MinVolume = pInputOrder->MinVolume;
			//触发条件
			field->ContingentCondition = (CtpNetContingentConditionType)pInputOrder->ContingentCondition;
			//止损价
			field->StopPrice = pInputOrder->StopPrice;
			//强平原因
			field->ForceCloseReason = (CtpNetForceCloseReasonType)pInputOrder->ForceCloseReason;
			//自动挂起标志
			field->IsAutoSuspend = pInputOrder->IsAutoSuspend;
			//业务单元
			if (pInputOrder->BusinessUnit != nullptr)
			{
				field->BusinessUnit = gcnew String(pInputOrder->BusinessUnit);
			}
			//请求编号
			field->RequestID = pInputOrder->RequestID;
			//用户强评标志
			field->UserForceClose = pInputOrder->UserForceClose;
			//互换单标志
			field->IsSwapOrder = pInputOrder->IsSwapOrder;
			//交易所代码
			if (pInputOrder->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pInputOrder->ExchangeID);
			}
			//投资单元代码
			if (pInputOrder->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pInputOrder->InvestUnitID);
			}
			//资金账号
			if (pInputOrder->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pInputOrder->AccountID);
			}
			//币种代码
			if (pInputOrder->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pInputOrder->CurrencyID);
			}
			//交易编码
			if (pInputOrder->ClientID != nullptr)
			{
				field->ClientID = gcnew String(pInputOrder->ClientID);
			}
			//IP地址
			if (pInputOrder->IPAddress != nullptr)
			{
				field->IPAddress = gcnew String(pInputOrder->IPAddress);
			}
			//Mac地址
			if (pInputOrder->MacAddress != nullptr)
			{
				field->MacAddress = gcnew String(pInputOrder->MacAddress);
			}
		}
		
		m_pAdapter->OnRspOrderInsert(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 预埋单录入请求响应
	void CTraderSpi::OnRspParkedOrderInsert(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspParkedOrderInsert_delegate == nullptr) return;
		
		CtpNetParkedOrderField^ field = nullptr;
		if (pParkedOrder != nullptr)
		{
			field = gcnew CtpNetParkedOrderField;
			
			//经纪公司代码
			if (pParkedOrder->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pParkedOrder->BrokerID);
			}
			//投资者代码
			if (pParkedOrder->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pParkedOrder->InvestorID);
			}
			//合约代码
			if (pParkedOrder->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pParkedOrder->InstrumentID);
			}
			//报单引用
			if (pParkedOrder->OrderRef != nullptr)
			{
				field->OrderRef = gcnew String(pParkedOrder->OrderRef);
			}
			//用户代码
			if (pParkedOrder->UserID != nullptr)
			{
				field->UserID = gcnew String(pParkedOrder->UserID);
			}
			//报单价格条件
			field->OrderPriceType = (CtpNetOrderPriceTypeType)pParkedOrder->OrderPriceType;
			//买卖方向
			field->Direction = (CtpNetDirectionType)pParkedOrder->Direction;
			//组合开平标志1
			field->CombOffsetFlag1 = (CtpNetOffsetFlagType)pParkedOrder->CombOffsetFlag[0];
			//组合开平标志2
			field->CombOffsetFlag2 = (CtpNetOffsetFlagType)pParkedOrder->CombOffsetFlag[1];
			//组合开平标志3
			field->CombOffsetFlag3 = (CtpNetOffsetFlagType)pParkedOrder->CombOffsetFlag[2];
			//组合开平标志4
			field->CombOffsetFlag4 = (CtpNetOffsetFlagType)pParkedOrder->CombOffsetFlag[3];
			//组合开平标志5
			field->CombOffsetFlag5 = (CtpNetOffsetFlagType)pParkedOrder->CombOffsetFlag[4];
			//组合投机套保标志1
			field->CombHedgeFlag1 = (CtpNetHedgeFlagType)pParkedOrder->CombHedgeFlag[0];
			//组合投机套保标志2
			field->CombHedgeFlag2 = (CtpNetHedgeFlagType)pParkedOrder->CombHedgeFlag[1];
			//组合投机套保标志3
			field->CombHedgeFlag3 = (CtpNetHedgeFlagType)pParkedOrder->CombHedgeFlag[2];
			//组合投机套保标志4
			field->CombHedgeFlag4 = (CtpNetHedgeFlagType)pParkedOrder->CombHedgeFlag[3];
			//组合投机套保标志5
			field->CombHedgeFlag5 = (CtpNetHedgeFlagType)pParkedOrder->CombHedgeFlag[4];
			//价格
			field->LimitPrice = pParkedOrder->LimitPrice;
			//数量
			field->VolumeTotalOriginal = pParkedOrder->VolumeTotalOriginal;
			//有效期类型
			field->TimeCondition = (CtpNetTimeConditionType)pParkedOrder->TimeCondition;
			//GTD日期
			if (pParkedOrder->GTDDate != nullptr)
			{
				field->GTDDate = gcnew String(pParkedOrder->GTDDate);
			}
			//成交量类型
			field->VolumeCondition = (CtpNetVolumeConditionType)pParkedOrder->VolumeCondition;
			//最小成交量
			field->MinVolume = pParkedOrder->MinVolume;
			//触发条件
			field->ContingentCondition = (CtpNetContingentConditionType)pParkedOrder->ContingentCondition;
			//止损价
			field->StopPrice = pParkedOrder->StopPrice;
			//强平原因
			field->ForceCloseReason = (CtpNetForceCloseReasonType)pParkedOrder->ForceCloseReason;
			//自动挂起标志
			field->IsAutoSuspend = pParkedOrder->IsAutoSuspend;
			//业务单元
			if (pParkedOrder->BusinessUnit != nullptr)
			{
				field->BusinessUnit = gcnew String(pParkedOrder->BusinessUnit);
			}
			//请求编号
			field->RequestID = pParkedOrder->RequestID;
			//用户强评标志
			field->UserForceClose = pParkedOrder->UserForceClose;
			//交易所代码
			if (pParkedOrder->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pParkedOrder->ExchangeID);
			}
			//预埋报单编号
			if (pParkedOrder->ParkedOrderID != nullptr)
			{
				field->ParkedOrderID = gcnew String(pParkedOrder->ParkedOrderID);
			}
			//用户类型
			field->UserType = (CtpNetUserTypeType)pParkedOrder->UserType;
			//预埋单状态
			field->Status = (CtpNetParkedOrderStatusType)pParkedOrder->Status;
			//错误代码
			field->ErrorID = pParkedOrder->ErrorID;
			//错误信息
			if (pParkedOrder->ErrorMsg != nullptr)
			{
				field->ErrorMsg = gcnew String(pParkedOrder->ErrorMsg);
			}
			//互换单标志
			field->IsSwapOrder = pParkedOrder->IsSwapOrder;
			//资金账号
			if (pParkedOrder->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pParkedOrder->AccountID);
			}
			//币种代码
			if (pParkedOrder->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pParkedOrder->CurrencyID);
			}
			//交易编码
			if (pParkedOrder->ClientID != nullptr)
			{
				field->ClientID = gcnew String(pParkedOrder->ClientID);
			}
			//投资单元代码
			if (pParkedOrder->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pParkedOrder->InvestUnitID);
			}
			//IP地址
			if (pParkedOrder->IPAddress != nullptr)
			{
				field->IPAddress = gcnew String(pParkedOrder->IPAddress);
			}
			//Mac地址
			if (pParkedOrder->MacAddress != nullptr)
			{
				field->MacAddress = gcnew String(pParkedOrder->MacAddress);
			}
		}
		
		m_pAdapter->OnRspParkedOrderInsert(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 预埋撤单录入请求响应
	void CTraderSpi::OnRspParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspParkedOrderAction_delegate == nullptr) return;
		
		CtpNetParkedOrderActionField^ field = nullptr;
		if (pParkedOrderAction != nullptr)
		{
			field = gcnew CtpNetParkedOrderActionField;
			
			//经纪公司代码
			if (pParkedOrderAction->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pParkedOrderAction->BrokerID);
			}
			//投资者代码
			if (pParkedOrderAction->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pParkedOrderAction->InvestorID);
			}
			//报单操作引用
			field->OrderActionRef = pParkedOrderAction->OrderActionRef;
			//报单引用
			if (pParkedOrderAction->OrderRef != nullptr)
			{
				field->OrderRef = gcnew String(pParkedOrderAction->OrderRef);
			}
			//请求编号
			field->RequestID = pParkedOrderAction->RequestID;
			//前置编号
			field->FrontID = pParkedOrderAction->FrontID;
			//会话编号
			field->SessionID = pParkedOrderAction->SessionID;
			//交易所代码
			if (pParkedOrderAction->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pParkedOrderAction->ExchangeID);
			}
			//报单编号
			if (pParkedOrderAction->OrderSysID != nullptr)
			{
				field->OrderSysID = gcnew String(pParkedOrderAction->OrderSysID);
			}
			//操作标志
			field->ActionFlag = (CtpNetActionFlagType)pParkedOrderAction->ActionFlag;
			//价格
			field->LimitPrice = pParkedOrderAction->LimitPrice;
			//数量变化
			field->VolumeChange = pParkedOrderAction->VolumeChange;
			//用户代码
			if (pParkedOrderAction->UserID != nullptr)
			{
				field->UserID = gcnew String(pParkedOrderAction->UserID);
			}
			//合约代码
			if (pParkedOrderAction->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pParkedOrderAction->InstrumentID);
			}
			//预埋撤单单编号
			if (pParkedOrderAction->ParkedOrderActionID != nullptr)
			{
				field->ParkedOrderActionID = gcnew String(pParkedOrderAction->ParkedOrderActionID);
			}
			//用户类型
			field->UserType = (CtpNetUserTypeType)pParkedOrderAction->UserType;
			//预埋撤单状态
			field->Status = (CtpNetParkedOrderStatusType)pParkedOrderAction->Status;
			//错误代码
			field->ErrorID = pParkedOrderAction->ErrorID;
			//错误信息
			if (pParkedOrderAction->ErrorMsg != nullptr)
			{
				field->ErrorMsg = gcnew String(pParkedOrderAction->ErrorMsg);
			}
			//投资单元代码
			if (pParkedOrderAction->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pParkedOrderAction->InvestUnitID);
			}
			//IP地址
			if (pParkedOrderAction->IPAddress != nullptr)
			{
				field->IPAddress = gcnew String(pParkedOrderAction->IPAddress);
			}
			//Mac地址
			if (pParkedOrderAction->MacAddress != nullptr)
			{
				field->MacAddress = gcnew String(pParkedOrderAction->MacAddress);
			}
		}
		
		m_pAdapter->OnRspParkedOrderAction(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 报单操作请求响应
	void CTraderSpi::OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspOrderAction_delegate == nullptr) return;
		
		CtpNetInputOrderActionField^ field = nullptr;
		if (pInputOrderAction != nullptr)
		{
			field = gcnew CtpNetInputOrderActionField;
			
			//经纪公司代码
			if (pInputOrderAction->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pInputOrderAction->BrokerID);
			}
			//投资者代码
			if (pInputOrderAction->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pInputOrderAction->InvestorID);
			}
			//报单操作引用
			field->OrderActionRef = pInputOrderAction->OrderActionRef;
			//报单引用
			if (pInputOrderAction->OrderRef != nullptr)
			{
				field->OrderRef = gcnew String(pInputOrderAction->OrderRef);
			}
			//请求编号
			field->RequestID = pInputOrderAction->RequestID;
			//前置编号
			field->FrontID = pInputOrderAction->FrontID;
			//会话编号
			field->SessionID = pInputOrderAction->SessionID;
			//交易所代码
			if (pInputOrderAction->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pInputOrderAction->ExchangeID);
			}
			//报单编号
			if (pInputOrderAction->OrderSysID != nullptr)
			{
				field->OrderSysID = gcnew String(pInputOrderAction->OrderSysID);
			}
			//操作标志
			field->ActionFlag = (CtpNetActionFlagType)pInputOrderAction->ActionFlag;
			//价格
			field->LimitPrice = pInputOrderAction->LimitPrice;
			//数量变化
			field->VolumeChange = pInputOrderAction->VolumeChange;
			//用户代码
			if (pInputOrderAction->UserID != nullptr)
			{
				field->UserID = gcnew String(pInputOrderAction->UserID);
			}
			//合约代码
			if (pInputOrderAction->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pInputOrderAction->InstrumentID);
			}
			//投资单元代码
			if (pInputOrderAction->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pInputOrderAction->InvestUnitID);
			}
			//IP地址
			if (pInputOrderAction->IPAddress != nullptr)
			{
				field->IPAddress = gcnew String(pInputOrderAction->IPAddress);
			}
			//Mac地址
			if (pInputOrderAction->MacAddress != nullptr)
			{
				field->MacAddress = gcnew String(pInputOrderAction->MacAddress);
			}
		}
		
		m_pAdapter->OnRspOrderAction(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 查询最大报单数量响应
	void CTraderSpi::OnRspQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQueryMaxOrderVolume_delegate == nullptr) return;
		
		CtpNetQueryMaxOrderVolumeField^ field = nullptr;
		if (pQueryMaxOrderVolume != nullptr)
		{
			field = gcnew CtpNetQueryMaxOrderVolumeField;
			
			//经纪公司代码
			if (pQueryMaxOrderVolume->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pQueryMaxOrderVolume->BrokerID);
			}
			//投资者代码
			if (pQueryMaxOrderVolume->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pQueryMaxOrderVolume->InvestorID);
			}
			//合约代码
			if (pQueryMaxOrderVolume->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pQueryMaxOrderVolume->InstrumentID);
			}
			//买卖方向
			field->Direction = (CtpNetDirectionType)pQueryMaxOrderVolume->Direction;
			//开平标志
			field->OffsetFlag = (CtpNetOffsetFlagType)pQueryMaxOrderVolume->OffsetFlag;
			//投机套保标志
			field->HedgeFlag = (CtpNetHedgeFlagType)pQueryMaxOrderVolume->HedgeFlag;
			//最大允许报单数量
			field->MaxVolume = pQueryMaxOrderVolume->MaxVolume;
			//交易所代码
			if (pQueryMaxOrderVolume->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pQueryMaxOrderVolume->ExchangeID);
			}
			//投资单元代码
			if (pQueryMaxOrderVolume->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pQueryMaxOrderVolume->InvestUnitID);
			}
		}
		
		m_pAdapter->OnRspQueryMaxOrderVolume(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 投资者结算结果确认响应
	void CTraderSpi::OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspSettlementInfoConfirm_delegate == nullptr) return;
		
		CtpNetSettlementInfoConfirmField^ field = nullptr;
		if (pSettlementInfoConfirm != nullptr)
		{
			field = gcnew CtpNetSettlementInfoConfirmField;
			
			//经纪公司代码
			if (pSettlementInfoConfirm->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pSettlementInfoConfirm->BrokerID);
			}
			//投资者代码
			if (pSettlementInfoConfirm->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pSettlementInfoConfirm->InvestorID);
			}
			//确认日期
			if (pSettlementInfoConfirm->ConfirmDate != nullptr)
			{
				field->ConfirmDate = gcnew String(pSettlementInfoConfirm->ConfirmDate);
			}
			//确认时间
			if (pSettlementInfoConfirm->ConfirmTime != nullptr)
			{
				field->ConfirmTime = gcnew String(pSettlementInfoConfirm->ConfirmTime);
			}
			//结算编号
			field->SettlementID = pSettlementInfoConfirm->SettlementID;
			//投资者帐号
			if (pSettlementInfoConfirm->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pSettlementInfoConfirm->AccountID);
			}
			//币种代码
			if (pSettlementInfoConfirm->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pSettlementInfoConfirm->CurrencyID);
			}
		}
		
		m_pAdapter->OnRspSettlementInfoConfirm(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 删除预埋单响应
	void CTraderSpi::OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspRemoveParkedOrder_delegate == nullptr) return;
		
		CtpNetRemoveParkedOrderField^ field = nullptr;
		if (pRemoveParkedOrder != nullptr)
		{
			field = gcnew CtpNetRemoveParkedOrderField;
			
			//经纪公司代码
			if (pRemoveParkedOrder->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pRemoveParkedOrder->BrokerID);
			}
			//投资者代码
			if (pRemoveParkedOrder->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pRemoveParkedOrder->InvestorID);
			}
			//预埋报单编号
			if (pRemoveParkedOrder->ParkedOrderID != nullptr)
			{
				field->ParkedOrderID = gcnew String(pRemoveParkedOrder->ParkedOrderID);
			}
			//投资单元代码
			if (pRemoveParkedOrder->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pRemoveParkedOrder->InvestUnitID);
			}
		}
		
		m_pAdapter->OnRspRemoveParkedOrder(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 删除预埋撤单响应
	void CTraderSpi::OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspRemoveParkedOrderAction_delegate == nullptr) return;
		
		CtpNetRemoveParkedOrderActionField^ field = nullptr;
		if (pRemoveParkedOrderAction != nullptr)
		{
			field = gcnew CtpNetRemoveParkedOrderActionField;
			
			//经纪公司代码
			if (pRemoveParkedOrderAction->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pRemoveParkedOrderAction->BrokerID);
			}
			//投资者代码
			if (pRemoveParkedOrderAction->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pRemoveParkedOrderAction->InvestorID);
			}
			//预埋撤单编号
			if (pRemoveParkedOrderAction->ParkedOrderActionID != nullptr)
			{
				field->ParkedOrderActionID = gcnew String(pRemoveParkedOrderAction->ParkedOrderActionID);
			}
			//投资单元代码
			if (pRemoveParkedOrderAction->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pRemoveParkedOrderAction->InvestUnitID);
			}
		}
		
		m_pAdapter->OnRspRemoveParkedOrderAction(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 执行宣告录入请求响应
	void CTraderSpi::OnRspExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspExecOrderInsert_delegate == nullptr) return;
		
		CtpNetInputExecOrderField^ field = nullptr;
		if (pInputExecOrder != nullptr)
		{
			field = gcnew CtpNetInputExecOrderField;
			
			//经纪公司代码
			if (pInputExecOrder->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pInputExecOrder->BrokerID);
			}
			//投资者代码
			if (pInputExecOrder->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pInputExecOrder->InvestorID);
			}
			//合约代码
			if (pInputExecOrder->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pInputExecOrder->InstrumentID);
			}
			//执行宣告引用
			if (pInputExecOrder->ExecOrderRef != nullptr)
			{
				field->ExecOrderRef = gcnew String(pInputExecOrder->ExecOrderRef);
			}
			//用户代码
			if (pInputExecOrder->UserID != nullptr)
			{
				field->UserID = gcnew String(pInputExecOrder->UserID);
			}
			//数量
			field->Volume = pInputExecOrder->Volume;
			//请求编号
			field->RequestID = pInputExecOrder->RequestID;
			//业务单元
			if (pInputExecOrder->BusinessUnit != nullptr)
			{
				field->BusinessUnit = gcnew String(pInputExecOrder->BusinessUnit);
			}
			//开平标志
			field->OffsetFlag = (CtpNetOffsetFlagType)pInputExecOrder->OffsetFlag;
			//投机套保标志
			field->HedgeFlag = (CtpNetHedgeFlagType)pInputExecOrder->HedgeFlag;
			//执行类型
			field->ActionType = (CtpNetActionTypeType)pInputExecOrder->ActionType;
			//保留头寸申请的持仓方向
			field->PosiDirection = (CtpNetPosiDirectionType)pInputExecOrder->PosiDirection;
			//期权行权后是否保留期货头寸的标记,该字段已废弃
			field->ReservePositionFlag = (CtpNetExecOrderPositionFlagType)pInputExecOrder->ReservePositionFlag;
			//期权行权后生成的头寸是否自动平仓
			field->CloseFlag = (CtpNetExecOrderCloseFlagType)pInputExecOrder->CloseFlag;
			//交易所代码
			if (pInputExecOrder->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pInputExecOrder->ExchangeID);
			}
			//投资单元代码
			if (pInputExecOrder->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pInputExecOrder->InvestUnitID);
			}
			//资金账号
			if (pInputExecOrder->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pInputExecOrder->AccountID);
			}
			//币种代码
			if (pInputExecOrder->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pInputExecOrder->CurrencyID);
			}
			//交易编码
			if (pInputExecOrder->ClientID != nullptr)
			{
				field->ClientID = gcnew String(pInputExecOrder->ClientID);
			}
			//IP地址
			if (pInputExecOrder->IPAddress != nullptr)
			{
				field->IPAddress = gcnew String(pInputExecOrder->IPAddress);
			}
			//Mac地址
			if (pInputExecOrder->MacAddress != nullptr)
			{
				field->MacAddress = gcnew String(pInputExecOrder->MacAddress);
			}
		}
		
		m_pAdapter->OnRspExecOrderInsert(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 执行宣告操作请求响应
	void CTraderSpi::OnRspExecOrderAction(CThostFtdcInputExecOrderActionField *pInputExecOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspExecOrderAction_delegate == nullptr) return;
		
		CtpNetInputExecOrderActionField^ field = nullptr;
		if (pInputExecOrderAction != nullptr)
		{
			field = gcnew CtpNetInputExecOrderActionField;
			
			//经纪公司代码
			if (pInputExecOrderAction->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pInputExecOrderAction->BrokerID);
			}
			//投资者代码
			if (pInputExecOrderAction->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pInputExecOrderAction->InvestorID);
			}
			//执行宣告操作引用
			field->ExecOrderActionRef = pInputExecOrderAction->ExecOrderActionRef;
			//执行宣告引用
			if (pInputExecOrderAction->ExecOrderRef != nullptr)
			{
				field->ExecOrderRef = gcnew String(pInputExecOrderAction->ExecOrderRef);
			}
			//请求编号
			field->RequestID = pInputExecOrderAction->RequestID;
			//前置编号
			field->FrontID = pInputExecOrderAction->FrontID;
			//会话编号
			field->SessionID = pInputExecOrderAction->SessionID;
			//交易所代码
			if (pInputExecOrderAction->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pInputExecOrderAction->ExchangeID);
			}
			//执行宣告操作编号
			if (pInputExecOrderAction->ExecOrderSysID != nullptr)
			{
				field->ExecOrderSysID = gcnew String(pInputExecOrderAction->ExecOrderSysID);
			}
			//操作标志
			field->ActionFlag = (CtpNetActionFlagType)pInputExecOrderAction->ActionFlag;
			//用户代码
			if (pInputExecOrderAction->UserID != nullptr)
			{
				field->UserID = gcnew String(pInputExecOrderAction->UserID);
			}
			//合约代码
			if (pInputExecOrderAction->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pInputExecOrderAction->InstrumentID);
			}
			//投资单元代码
			if (pInputExecOrderAction->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pInputExecOrderAction->InvestUnitID);
			}
			//IP地址
			if (pInputExecOrderAction->IPAddress != nullptr)
			{
				field->IPAddress = gcnew String(pInputExecOrderAction->IPAddress);
			}
			//Mac地址
			if (pInputExecOrderAction->MacAddress != nullptr)
			{
				field->MacAddress = gcnew String(pInputExecOrderAction->MacAddress);
			}
		}
		
		m_pAdapter->OnRspExecOrderAction(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 询价录入请求响应
	void CTraderSpi::OnRspForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspForQuoteInsert_delegate == nullptr) return;
		
		CtpNetInputForQuoteField^ field = nullptr;
		if (pInputForQuote != nullptr)
		{
			field = gcnew CtpNetInputForQuoteField;
			
			//经纪公司代码
			if (pInputForQuote->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pInputForQuote->BrokerID);
			}
			//投资者代码
			if (pInputForQuote->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pInputForQuote->InvestorID);
			}
			//合约代码
			if (pInputForQuote->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pInputForQuote->InstrumentID);
			}
			//询价引用
			if (pInputForQuote->ForQuoteRef != nullptr)
			{
				field->ForQuoteRef = gcnew String(pInputForQuote->ForQuoteRef);
			}
			//用户代码
			if (pInputForQuote->UserID != nullptr)
			{
				field->UserID = gcnew String(pInputForQuote->UserID);
			}
			//交易所代码
			if (pInputForQuote->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pInputForQuote->ExchangeID);
			}
			//投资单元代码
			if (pInputForQuote->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pInputForQuote->InvestUnitID);
			}
			//IP地址
			if (pInputForQuote->IPAddress != nullptr)
			{
				field->IPAddress = gcnew String(pInputForQuote->IPAddress);
			}
			//Mac地址
			if (pInputForQuote->MacAddress != nullptr)
			{
				field->MacAddress = gcnew String(pInputForQuote->MacAddress);
			}
		}
		
		m_pAdapter->OnRspForQuoteInsert(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 报价录入请求响应
	void CTraderSpi::OnRspQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQuoteInsert_delegate == nullptr) return;
		
		CtpNetInputQuoteField^ field = nullptr;
		if (pInputQuote != nullptr)
		{
			field = gcnew CtpNetInputQuoteField;
			
			//经纪公司代码
			if (pInputQuote->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pInputQuote->BrokerID);
			}
			//投资者代码
			if (pInputQuote->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pInputQuote->InvestorID);
			}
			//合约代码
			if (pInputQuote->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pInputQuote->InstrumentID);
			}
			//报价引用
			if (pInputQuote->QuoteRef != nullptr)
			{
				field->QuoteRef = gcnew String(pInputQuote->QuoteRef);
			}
			//用户代码
			if (pInputQuote->UserID != nullptr)
			{
				field->UserID = gcnew String(pInputQuote->UserID);
			}
			//卖价格
			field->AskPrice = pInputQuote->AskPrice;
			//买价格
			field->BidPrice = pInputQuote->BidPrice;
			//卖数量
			field->AskVolume = pInputQuote->AskVolume;
			//买数量
			field->BidVolume = pInputQuote->BidVolume;
			//请求编号
			field->RequestID = pInputQuote->RequestID;
			//业务单元
			if (pInputQuote->BusinessUnit != nullptr)
			{
				field->BusinessUnit = gcnew String(pInputQuote->BusinessUnit);
			}
			//卖开平标志
			field->AskOffsetFlag = (CtpNetOffsetFlagType)pInputQuote->AskOffsetFlag;
			//买开平标志
			field->BidOffsetFlag = (CtpNetOffsetFlagType)pInputQuote->BidOffsetFlag;
			//卖投机套保标志
			field->AskHedgeFlag = (CtpNetHedgeFlagType)pInputQuote->AskHedgeFlag;
			//买投机套保标志
			field->BidHedgeFlag = (CtpNetHedgeFlagType)pInputQuote->BidHedgeFlag;
			//衍生卖报单引用
			if (pInputQuote->AskOrderRef != nullptr)
			{
				field->AskOrderRef = gcnew String(pInputQuote->AskOrderRef);
			}
			//衍生买报单引用
			if (pInputQuote->BidOrderRef != nullptr)
			{
				field->BidOrderRef = gcnew String(pInputQuote->BidOrderRef);
			}
			//应价编号
			if (pInputQuote->ForQuoteSysID != nullptr)
			{
				field->ForQuoteSysID = gcnew String(pInputQuote->ForQuoteSysID);
			}
			//交易所代码
			if (pInputQuote->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pInputQuote->ExchangeID);
			}
			//投资单元代码
			if (pInputQuote->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pInputQuote->InvestUnitID);
			}
			//交易编码
			if (pInputQuote->ClientID != nullptr)
			{
				field->ClientID = gcnew String(pInputQuote->ClientID);
			}
			//IP地址
			if (pInputQuote->IPAddress != nullptr)
			{
				field->IPAddress = gcnew String(pInputQuote->IPAddress);
			}
			//Mac地址
			if (pInputQuote->MacAddress != nullptr)
			{
				field->MacAddress = gcnew String(pInputQuote->MacAddress);
			}
		}
		
		m_pAdapter->OnRspQuoteInsert(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 报价操作请求响应
	void CTraderSpi::OnRspQuoteAction(CThostFtdcInputQuoteActionField *pInputQuoteAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQuoteAction_delegate == nullptr) return;
		
		CtpNetInputQuoteActionField^ field = nullptr;
		if (pInputQuoteAction != nullptr)
		{
			field = gcnew CtpNetInputQuoteActionField;
			
			//经纪公司代码
			if (pInputQuoteAction->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pInputQuoteAction->BrokerID);
			}
			//投资者代码
			if (pInputQuoteAction->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pInputQuoteAction->InvestorID);
			}
			//报价操作引用
			field->QuoteActionRef = pInputQuoteAction->QuoteActionRef;
			//报价引用
			if (pInputQuoteAction->QuoteRef != nullptr)
			{
				field->QuoteRef = gcnew String(pInputQuoteAction->QuoteRef);
			}
			//请求编号
			field->RequestID = pInputQuoteAction->RequestID;
			//前置编号
			field->FrontID = pInputQuoteAction->FrontID;
			//会话编号
			field->SessionID = pInputQuoteAction->SessionID;
			//交易所代码
			if (pInputQuoteAction->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pInputQuoteAction->ExchangeID);
			}
			//报价操作编号
			if (pInputQuoteAction->QuoteSysID != nullptr)
			{
				field->QuoteSysID = gcnew String(pInputQuoteAction->QuoteSysID);
			}
			//操作标志
			field->ActionFlag = (CtpNetActionFlagType)pInputQuoteAction->ActionFlag;
			//用户代码
			if (pInputQuoteAction->UserID != nullptr)
			{
				field->UserID = gcnew String(pInputQuoteAction->UserID);
			}
			//合约代码
			if (pInputQuoteAction->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pInputQuoteAction->InstrumentID);
			}
			//投资单元代码
			if (pInputQuoteAction->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pInputQuoteAction->InvestUnitID);
			}
			//交易编码
			if (pInputQuoteAction->ClientID != nullptr)
			{
				field->ClientID = gcnew String(pInputQuoteAction->ClientID);
			}
			//IP地址
			if (pInputQuoteAction->IPAddress != nullptr)
			{
				field->IPAddress = gcnew String(pInputQuoteAction->IPAddress);
			}
			//Mac地址
			if (pInputQuoteAction->MacAddress != nullptr)
			{
				field->MacAddress = gcnew String(pInputQuoteAction->MacAddress);
			}
		}
		
		m_pAdapter->OnRspQuoteAction(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 批量报单操作请求响应
	void CTraderSpi::OnRspBatchOrderAction(CThostFtdcInputBatchOrderActionField *pInputBatchOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspBatchOrderAction_delegate == nullptr) return;
		
		CtpNetInputBatchOrderActionField^ field = nullptr;
		if (pInputBatchOrderAction != nullptr)
		{
			field = gcnew CtpNetInputBatchOrderActionField;
			
			//经纪公司代码
			if (pInputBatchOrderAction->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pInputBatchOrderAction->BrokerID);
			}
			//投资者代码
			if (pInputBatchOrderAction->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pInputBatchOrderAction->InvestorID);
			}
			//报单操作引用
			field->OrderActionRef = pInputBatchOrderAction->OrderActionRef;
			//请求编号
			field->RequestID = pInputBatchOrderAction->RequestID;
			//前置编号
			field->FrontID = pInputBatchOrderAction->FrontID;
			//会话编号
			field->SessionID = pInputBatchOrderAction->SessionID;
			//交易所代码
			if (pInputBatchOrderAction->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pInputBatchOrderAction->ExchangeID);
			}
			//用户代码
			if (pInputBatchOrderAction->UserID != nullptr)
			{
				field->UserID = gcnew String(pInputBatchOrderAction->UserID);
			}
			//投资单元代码
			if (pInputBatchOrderAction->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pInputBatchOrderAction->InvestUnitID);
			}
			//IP地址
			if (pInputBatchOrderAction->IPAddress != nullptr)
			{
				field->IPAddress = gcnew String(pInputBatchOrderAction->IPAddress);
			}
			//Mac地址
			if (pInputBatchOrderAction->MacAddress != nullptr)
			{
				field->MacAddress = gcnew String(pInputBatchOrderAction->MacAddress);
			}
		}
		
		m_pAdapter->OnRspBatchOrderAction(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 期权自对冲录入请求响应
	void CTraderSpi::OnRspOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField *pInputOptionSelfClose, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspOptionSelfCloseInsert_delegate == nullptr) return;
		
		CtpNetInputOptionSelfCloseField^ field = nullptr;
		if (pInputOptionSelfClose != nullptr)
		{
			field = gcnew CtpNetInputOptionSelfCloseField;
			
			//经纪公司代码
			if (pInputOptionSelfClose->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pInputOptionSelfClose->BrokerID);
			}
			//投资者代码
			if (pInputOptionSelfClose->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pInputOptionSelfClose->InvestorID);
			}
			//合约代码
			if (pInputOptionSelfClose->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pInputOptionSelfClose->InstrumentID);
			}
			//期权自对冲引用
			if (pInputOptionSelfClose->OptionSelfCloseRef != nullptr)
			{
				field->OptionSelfCloseRef = gcnew String(pInputOptionSelfClose->OptionSelfCloseRef);
			}
			//用户代码
			if (pInputOptionSelfClose->UserID != nullptr)
			{
				field->UserID = gcnew String(pInputOptionSelfClose->UserID);
			}
			//数量
			field->Volume = pInputOptionSelfClose->Volume;
			//请求编号
			field->RequestID = pInputOptionSelfClose->RequestID;
			//业务单元
			if (pInputOptionSelfClose->BusinessUnit != nullptr)
			{
				field->BusinessUnit = gcnew String(pInputOptionSelfClose->BusinessUnit);
			}
			//投机套保标志
			field->HedgeFlag = (CtpNetHedgeFlagType)pInputOptionSelfClose->HedgeFlag;
			//期权行权的头寸是否自对冲
			field->OptSelfCloseFlag = (CtpNetOptSelfCloseFlagType)pInputOptionSelfClose->OptSelfCloseFlag;
			//交易所代码
			if (pInputOptionSelfClose->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pInputOptionSelfClose->ExchangeID);
			}
			//投资单元代码
			if (pInputOptionSelfClose->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pInputOptionSelfClose->InvestUnitID);
			}
			//资金账号
			if (pInputOptionSelfClose->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pInputOptionSelfClose->AccountID);
			}
			//币种代码
			if (pInputOptionSelfClose->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pInputOptionSelfClose->CurrencyID);
			}
			//交易编码
			if (pInputOptionSelfClose->ClientID != nullptr)
			{
				field->ClientID = gcnew String(pInputOptionSelfClose->ClientID);
			}
			//IP地址
			if (pInputOptionSelfClose->IPAddress != nullptr)
			{
				field->IPAddress = gcnew String(pInputOptionSelfClose->IPAddress);
			}
			//Mac地址
			if (pInputOptionSelfClose->MacAddress != nullptr)
			{
				field->MacAddress = gcnew String(pInputOptionSelfClose->MacAddress);
			}
		}
		
		m_pAdapter->OnRspOptionSelfCloseInsert(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 期权自对冲操作请求响应
	void CTraderSpi::OnRspOptionSelfCloseAction(CThostFtdcInputOptionSelfCloseActionField *pInputOptionSelfCloseAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspOptionSelfCloseAction_delegate == nullptr) return;
		
		CtpNetInputOptionSelfCloseActionField^ field = nullptr;
		if (pInputOptionSelfCloseAction != nullptr)
		{
			field = gcnew CtpNetInputOptionSelfCloseActionField;
			
			//经纪公司代码
			if (pInputOptionSelfCloseAction->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pInputOptionSelfCloseAction->BrokerID);
			}
			//投资者代码
			if (pInputOptionSelfCloseAction->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pInputOptionSelfCloseAction->InvestorID);
			}
			//期权自对冲操作引用
			field->OptionSelfCloseActionRef = pInputOptionSelfCloseAction->OptionSelfCloseActionRef;
			//期权自对冲引用
			if (pInputOptionSelfCloseAction->OptionSelfCloseRef != nullptr)
			{
				field->OptionSelfCloseRef = gcnew String(pInputOptionSelfCloseAction->OptionSelfCloseRef);
			}
			//请求编号
			field->RequestID = pInputOptionSelfCloseAction->RequestID;
			//前置编号
			field->FrontID = pInputOptionSelfCloseAction->FrontID;
			//会话编号
			field->SessionID = pInputOptionSelfCloseAction->SessionID;
			//交易所代码
			if (pInputOptionSelfCloseAction->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pInputOptionSelfCloseAction->ExchangeID);
			}
			//期权自对冲操作编号
			if (pInputOptionSelfCloseAction->OptionSelfCloseSysID != nullptr)
			{
				field->OptionSelfCloseSysID = gcnew String(pInputOptionSelfCloseAction->OptionSelfCloseSysID);
			}
			//操作标志
			field->ActionFlag = (CtpNetActionFlagType)pInputOptionSelfCloseAction->ActionFlag;
			//用户代码
			if (pInputOptionSelfCloseAction->UserID != nullptr)
			{
				field->UserID = gcnew String(pInputOptionSelfCloseAction->UserID);
			}
			//合约代码
			if (pInputOptionSelfCloseAction->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pInputOptionSelfCloseAction->InstrumentID);
			}
			//投资单元代码
			if (pInputOptionSelfCloseAction->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pInputOptionSelfCloseAction->InvestUnitID);
			}
			//IP地址
			if (pInputOptionSelfCloseAction->IPAddress != nullptr)
			{
				field->IPAddress = gcnew String(pInputOptionSelfCloseAction->IPAddress);
			}
			//Mac地址
			if (pInputOptionSelfCloseAction->MacAddress != nullptr)
			{
				field->MacAddress = gcnew String(pInputOptionSelfCloseAction->MacAddress);
			}
		}
		
		m_pAdapter->OnRspOptionSelfCloseAction(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 申请组合录入请求响应
	void CTraderSpi::OnRspCombActionInsert(CThostFtdcInputCombActionField *pInputCombAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspCombActionInsert_delegate == nullptr) return;
		
		CtpNetInputCombActionField^ field = nullptr;
		if (pInputCombAction != nullptr)
		{
			field = gcnew CtpNetInputCombActionField;
			
			//经纪公司代码
			if (pInputCombAction->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pInputCombAction->BrokerID);
			}
			//投资者代码
			if (pInputCombAction->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pInputCombAction->InvestorID);
			}
			//合约代码
			if (pInputCombAction->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pInputCombAction->InstrumentID);
			}
			//组合引用
			if (pInputCombAction->CombActionRef != nullptr)
			{
				field->CombActionRef = gcnew String(pInputCombAction->CombActionRef);
			}
			//用户代码
			if (pInputCombAction->UserID != nullptr)
			{
				field->UserID = gcnew String(pInputCombAction->UserID);
			}
			//买卖方向
			field->Direction = (CtpNetDirectionType)pInputCombAction->Direction;
			//数量
			field->Volume = pInputCombAction->Volume;
			//组合指令方向
			field->CombDirection = (CtpNetCombDirectionType)pInputCombAction->CombDirection;
			//投机套保标志
			field->HedgeFlag = (CtpNetHedgeFlagType)pInputCombAction->HedgeFlag;
			//交易所代码
			if (pInputCombAction->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pInputCombAction->ExchangeID);
			}
			//IP地址
			if (pInputCombAction->IPAddress != nullptr)
			{
				field->IPAddress = gcnew String(pInputCombAction->IPAddress);
			}
			//Mac地址
			if (pInputCombAction->MacAddress != nullptr)
			{
				field->MacAddress = gcnew String(pInputCombAction->MacAddress);
			}
			//投资单元代码
			if (pInputCombAction->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pInputCombAction->InvestUnitID);
			}
		}
		
		m_pAdapter->OnRspCombActionInsert(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询报单响应
	void CTraderSpi::OnRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryOrder_delegate == nullptr) return;
		
		CtpNetOrderField^ field = nullptr;
		if (pOrder != nullptr)
		{
			field = gcnew CtpNetOrderField;
			
			//经纪公司代码
			if (pOrder->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pOrder->BrokerID);
			}
			//投资者代码
			if (pOrder->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pOrder->InvestorID);
			}
			//合约代码
			if (pOrder->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pOrder->InstrumentID);
			}
			//报单引用
			if (pOrder->OrderRef != nullptr)
			{
				field->OrderRef = gcnew String(pOrder->OrderRef);
			}
			//用户代码
			if (pOrder->UserID != nullptr)
			{
				field->UserID = gcnew String(pOrder->UserID);
			}
			//报单价格条件
			field->OrderPriceType = (CtpNetOrderPriceTypeType)pOrder->OrderPriceType;
			//买卖方向
			field->Direction = (CtpNetDirectionType)pOrder->Direction;
			//组合开平标志1
			field->CombOffsetFlag1 = (CtpNetOffsetFlagType)pOrder->CombOffsetFlag[0];
			//组合开平标志2
			field->CombOffsetFlag2 = (CtpNetOffsetFlagType)pOrder->CombOffsetFlag[1];
			//组合开平标志3
			field->CombOffsetFlag3 = (CtpNetOffsetFlagType)pOrder->CombOffsetFlag[2];
			//组合开平标志4
			field->CombOffsetFlag4 = (CtpNetOffsetFlagType)pOrder->CombOffsetFlag[3];
			//组合开平标志5
			field->CombOffsetFlag5 = (CtpNetOffsetFlagType)pOrder->CombOffsetFlag[4];
			//组合投机套保标志1
			field->CombHedgeFlag1 = (CtpNetHedgeFlagType)pOrder->CombHedgeFlag[0];
			//组合投机套保标志2
			field->CombHedgeFlag2 = (CtpNetHedgeFlagType)pOrder->CombHedgeFlag[1];
			//组合投机套保标志3
			field->CombHedgeFlag3 = (CtpNetHedgeFlagType)pOrder->CombHedgeFlag[2];
			//组合投机套保标志4
			field->CombHedgeFlag4 = (CtpNetHedgeFlagType)pOrder->CombHedgeFlag[3];
			//组合投机套保标志5
			field->CombHedgeFlag5 = (CtpNetHedgeFlagType)pOrder->CombHedgeFlag[4];
			//价格
			field->LimitPrice = pOrder->LimitPrice;
			//数量
			field->VolumeTotalOriginal = pOrder->VolumeTotalOriginal;
			//有效期类型
			field->TimeCondition = (CtpNetTimeConditionType)pOrder->TimeCondition;
			//GTD日期
			if (pOrder->GTDDate != nullptr)
			{
				field->GTDDate = gcnew String(pOrder->GTDDate);
			}
			//成交量类型
			field->VolumeCondition = (CtpNetVolumeConditionType)pOrder->VolumeCondition;
			//最小成交量
			field->MinVolume = pOrder->MinVolume;
			//触发条件
			field->ContingentCondition = (CtpNetContingentConditionType)pOrder->ContingentCondition;
			//止损价
			field->StopPrice = pOrder->StopPrice;
			//强平原因
			field->ForceCloseReason = (CtpNetForceCloseReasonType)pOrder->ForceCloseReason;
			//自动挂起标志
			field->IsAutoSuspend = pOrder->IsAutoSuspend;
			//业务单元
			if (pOrder->BusinessUnit != nullptr)
			{
				field->BusinessUnit = gcnew String(pOrder->BusinessUnit);
			}
			//请求编号
			field->RequestID = pOrder->RequestID;
			//本地报单编号
			if (pOrder->OrderLocalID != nullptr)
			{
				field->OrderLocalID = gcnew String(pOrder->OrderLocalID);
			}
			//交易所代码
			if (pOrder->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pOrder->ExchangeID);
			}
			//会员代码
			if (pOrder->ParticipantID != nullptr)
			{
				field->ParticipantID = gcnew String(pOrder->ParticipantID);
			}
			//客户代码
			if (pOrder->ClientID != nullptr)
			{
				field->ClientID = gcnew String(pOrder->ClientID);
			}
			//合约在交易所的代码
			if (pOrder->ExchangeInstID != nullptr)
			{
				field->ExchangeInstID = gcnew String(pOrder->ExchangeInstID);
			}
			//交易所交易员代码
			if (pOrder->TraderID != nullptr)
			{
				field->TraderID = gcnew String(pOrder->TraderID);
			}
			//安装编号
			field->InstallID = pOrder->InstallID;
			//报单提交状态
			field->OrderSubmitStatus = (CtpNetOrderSubmitStatusType)pOrder->OrderSubmitStatus;
			//报单提示序号
			field->NotifySequence = pOrder->NotifySequence;
			//交易日
			if (pOrder->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pOrder->TradingDay);
			}
			//结算编号
			field->SettlementID = pOrder->SettlementID;
			//报单编号
			if (pOrder->OrderSysID != nullptr)
			{
				field->OrderSysID = gcnew String(pOrder->OrderSysID);
			}
			//报单来源
			field->OrderSource = (CtpNetOrderSourceType)pOrder->OrderSource;
			//报单状态
			field->OrderStatus = (CtpNetOrderStatusType)pOrder->OrderStatus;
			//报单类型
			field->OrderType = (CtpNetOrderTypeType)pOrder->OrderType;
			//今成交数量
			field->VolumeTraded = pOrder->VolumeTraded;
			//剩余数量
			field->VolumeTotal = pOrder->VolumeTotal;
			//报单日期
			if (pOrder->InsertDate != nullptr)
			{
				field->InsertDate = gcnew String(pOrder->InsertDate);
			}
			//委托时间
			if (pOrder->InsertTime != nullptr)
			{
				field->InsertTime = gcnew String(pOrder->InsertTime);
			}
			//激活时间
			if (pOrder->ActiveTime != nullptr)
			{
				field->ActiveTime = gcnew String(pOrder->ActiveTime);
			}
			//挂起时间
			if (pOrder->SuspendTime != nullptr)
			{
				field->SuspendTime = gcnew String(pOrder->SuspendTime);
			}
			//最后修改时间
			if (pOrder->UpdateTime != nullptr)
			{
				field->UpdateTime = gcnew String(pOrder->UpdateTime);
			}
			//撤销时间
			if (pOrder->CancelTime != nullptr)
			{
				field->CancelTime = gcnew String(pOrder->CancelTime);
			}
			//最后修改交易所交易员代码
			if (pOrder->ActiveTraderID != nullptr)
			{
				field->ActiveTraderID = gcnew String(pOrder->ActiveTraderID);
			}
			//结算会员编号
			if (pOrder->ClearingPartID != nullptr)
			{
				field->ClearingPartID = gcnew String(pOrder->ClearingPartID);
			}
			//序号
			field->SequenceNo = pOrder->SequenceNo;
			//前置编号
			field->FrontID = pOrder->FrontID;
			//会话编号
			field->SessionID = pOrder->SessionID;
			//用户端产品信息
			if (pOrder->UserProductInfo != nullptr)
			{
				field->UserProductInfo = gcnew String(pOrder->UserProductInfo);
			}
			//状态信息
			if (pOrder->StatusMsg != nullptr)
			{
				field->StatusMsg = gcnew String(pOrder->StatusMsg);
			}
			//用户强评标志
			field->UserForceClose = pOrder->UserForceClose;
			//操作用户代码
			if (pOrder->ActiveUserID != nullptr)
			{
				field->ActiveUserID = gcnew String(pOrder->ActiveUserID);
			}
			//经纪公司报单编号
			field->BrokerOrderSeq = pOrder->BrokerOrderSeq;
			//相关报单
			if (pOrder->RelativeOrderSysID != nullptr)
			{
				field->RelativeOrderSysID = gcnew String(pOrder->RelativeOrderSysID);
			}
			//郑商所成交数量
			field->ZCETotalTradedVolume = pOrder->ZCETotalTradedVolume;
			//互换单标志
			field->IsSwapOrder = pOrder->IsSwapOrder;
			//营业部编号
			if (pOrder->BranchID != nullptr)
			{
				field->BranchID = gcnew String(pOrder->BranchID);
			}
			//投资单元代码
			if (pOrder->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pOrder->InvestUnitID);
			}
			//资金账号
			if (pOrder->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pOrder->AccountID);
			}
			//币种代码
			if (pOrder->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pOrder->CurrencyID);
			}
			//IP地址
			if (pOrder->IPAddress != nullptr)
			{
				field->IPAddress = gcnew String(pOrder->IPAddress);
			}
			//Mac地址
			if (pOrder->MacAddress != nullptr)
			{
				field->MacAddress = gcnew String(pOrder->MacAddress);
			}
		}
		
		m_pAdapter->OnRspQryOrder(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询成交响应
	void CTraderSpi::OnRspQryTrade(CThostFtdcTradeField *pTrade, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryTrade_delegate == nullptr) return;
		
		CtpNetTradeField^ field = nullptr;
		if (pTrade != nullptr)
		{
			field = gcnew CtpNetTradeField;
			
			//经纪公司代码
			if (pTrade->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pTrade->BrokerID);
			}
			//投资者代码
			if (pTrade->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pTrade->InvestorID);
			}
			//合约代码
			if (pTrade->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pTrade->InstrumentID);
			}
			//报单引用
			if (pTrade->OrderRef != nullptr)
			{
				field->OrderRef = gcnew String(pTrade->OrderRef);
			}
			//用户代码
			if (pTrade->UserID != nullptr)
			{
				field->UserID = gcnew String(pTrade->UserID);
			}
			//交易所代码
			if (pTrade->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pTrade->ExchangeID);
			}
			//成交编号
			if (pTrade->TradeID != nullptr)
			{
				field->TradeID = gcnew String(pTrade->TradeID);
			}
			//买卖方向
			field->Direction = (CtpNetDirectionType)pTrade->Direction;
			//报单编号
			if (pTrade->OrderSysID != nullptr)
			{
				field->OrderSysID = gcnew String(pTrade->OrderSysID);
			}
			//会员代码
			if (pTrade->ParticipantID != nullptr)
			{
				field->ParticipantID = gcnew String(pTrade->ParticipantID);
			}
			//客户代码
			if (pTrade->ClientID != nullptr)
			{
				field->ClientID = gcnew String(pTrade->ClientID);
			}
			//交易角色
			field->TradingRole = (CtpNetTradingRoleType)pTrade->TradingRole;
			//合约在交易所的代码
			if (pTrade->ExchangeInstID != nullptr)
			{
				field->ExchangeInstID = gcnew String(pTrade->ExchangeInstID);
			}
			//开平标志
			field->OffsetFlag = (CtpNetOffsetFlagType)pTrade->OffsetFlag;
			//投机套保标志
			field->HedgeFlag = (CtpNetHedgeFlagType)pTrade->HedgeFlag;
			//价格
			field->Price = pTrade->Price;
			//数量
			field->Volume = pTrade->Volume;
			//成交时期
			if (pTrade->TradeDate != nullptr)
			{
				field->TradeDate = gcnew String(pTrade->TradeDate);
			}
			//成交时间
			if (pTrade->TradeTime != nullptr)
			{
				field->TradeTime = gcnew String(pTrade->TradeTime);
			}
			//成交类型
			field->TradeType = (CtpNetTradeTypeType)pTrade->TradeType;
			//成交价来源
			field->PriceSource = (CtpNetPriceSourceType)pTrade->PriceSource;
			//交易所交易员代码
			if (pTrade->TraderID != nullptr)
			{
				field->TraderID = gcnew String(pTrade->TraderID);
			}
			//本地报单编号
			if (pTrade->OrderLocalID != nullptr)
			{
				field->OrderLocalID = gcnew String(pTrade->OrderLocalID);
			}
			//结算会员编号
			if (pTrade->ClearingPartID != nullptr)
			{
				field->ClearingPartID = gcnew String(pTrade->ClearingPartID);
			}
			//业务单元
			if (pTrade->BusinessUnit != nullptr)
			{
				field->BusinessUnit = gcnew String(pTrade->BusinessUnit);
			}
			//序号
			field->SequenceNo = pTrade->SequenceNo;
			//交易日
			if (pTrade->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pTrade->TradingDay);
			}
			//结算编号
			field->SettlementID = pTrade->SettlementID;
			//经纪公司报单编号
			field->BrokerOrderSeq = pTrade->BrokerOrderSeq;
			//成交来源
			field->TradeSource = (CtpNetTradeSourceType)pTrade->TradeSource;
			//投资单元代码
			if (pTrade->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pTrade->InvestUnitID);
			}
		}
		
		m_pAdapter->OnRspQryTrade(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询投资者持仓响应
	void CTraderSpi::OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryInvestorPosition_delegate == nullptr) return;
		
		CtpNetInvestorPositionField^ field = nullptr;
		if (pInvestorPosition != nullptr)
		{
			field = gcnew CtpNetInvestorPositionField;
			
			//合约代码
			if (pInvestorPosition->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pInvestorPosition->InstrumentID);
			}
			//经纪公司代码
			if (pInvestorPosition->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pInvestorPosition->BrokerID);
			}
			//投资者代码
			if (pInvestorPosition->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pInvestorPosition->InvestorID);
			}
			//持仓多空方向
			field->PosiDirection = (CtpNetPosiDirectionType)pInvestorPosition->PosiDirection;
			//投机套保标志
			field->HedgeFlag = (CtpNetHedgeFlagType)pInvestorPosition->HedgeFlag;
			//持仓日期
			field->PositionDate = (CtpNetPositionDateType)pInvestorPosition->PositionDate;
			//上日持仓
			field->YdPosition = pInvestorPosition->YdPosition;
			//今日持仓
			field->Position = pInvestorPosition->Position;
			//多头冻结
			field->LongFrozen = pInvestorPosition->LongFrozen;
			//空头冻结
			field->ShortFrozen = pInvestorPosition->ShortFrozen;
			//开仓冻结金额
			field->LongFrozenAmount = pInvestorPosition->LongFrozenAmount;
			//开仓冻结金额
			field->ShortFrozenAmount = pInvestorPosition->ShortFrozenAmount;
			//开仓量
			field->OpenVolume = pInvestorPosition->OpenVolume;
			//平仓量
			field->CloseVolume = pInvestorPosition->CloseVolume;
			//开仓金额
			field->OpenAmount = pInvestorPosition->OpenAmount;
			//平仓金额
			field->CloseAmount = pInvestorPosition->CloseAmount;
			//持仓成本
			field->PositionCost = pInvestorPosition->PositionCost;
			//上次占用的保证金
			field->PreMargin = pInvestorPosition->PreMargin;
			//占用的保证金
			field->UseMargin = pInvestorPosition->UseMargin;
			//冻结的保证金
			field->FrozenMargin = pInvestorPosition->FrozenMargin;
			//冻结的资金
			field->FrozenCash = pInvestorPosition->FrozenCash;
			//冻结的手续费
			field->FrozenCommission = pInvestorPosition->FrozenCommission;
			//资金差额
			field->CashIn = pInvestorPosition->CashIn;
			//手续费
			field->Commission = pInvestorPosition->Commission;
			//平仓盈亏
			field->CloseProfit = pInvestorPosition->CloseProfit;
			//持仓盈亏
			field->PositionProfit = pInvestorPosition->PositionProfit;
			//上次结算价
			field->PreSettlementPrice = pInvestorPosition->PreSettlementPrice;
			//本次结算价
			field->SettlementPrice = pInvestorPosition->SettlementPrice;
			//交易日
			if (pInvestorPosition->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pInvestorPosition->TradingDay);
			}
			//结算编号
			field->SettlementID = pInvestorPosition->SettlementID;
			//开仓成本
			field->OpenCost = pInvestorPosition->OpenCost;
			//交易所保证金
			field->ExchangeMargin = pInvestorPosition->ExchangeMargin;
			//组合成交形成的持仓
			field->CombPosition = pInvestorPosition->CombPosition;
			//组合多头冻结
			field->CombLongFrozen = pInvestorPosition->CombLongFrozen;
			//组合空头冻结
			field->CombShortFrozen = pInvestorPosition->CombShortFrozen;
			//逐日盯市平仓盈亏
			field->CloseProfitByDate = pInvestorPosition->CloseProfitByDate;
			//逐笔对冲平仓盈亏
			field->CloseProfitByTrade = pInvestorPosition->CloseProfitByTrade;
			//今日持仓
			field->TodayPosition = pInvestorPosition->TodayPosition;
			//保证金率
			field->MarginRateByMoney = pInvestorPosition->MarginRateByMoney;
			//保证金率(按手数)
			field->MarginRateByVolume = pInvestorPosition->MarginRateByVolume;
			//执行冻结
			field->StrikeFrozen = pInvestorPosition->StrikeFrozen;
			//执行冻结金额
			field->StrikeFrozenAmount = pInvestorPosition->StrikeFrozenAmount;
			//放弃执行冻结
			field->AbandonFrozen = pInvestorPosition->AbandonFrozen;
			//交易所代码
			if (pInvestorPosition->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pInvestorPosition->ExchangeID);
			}
			//执行冻结的昨仓
			field->YdStrikeFrozen = pInvestorPosition->YdStrikeFrozen;
			//投资单元代码
			if (pInvestorPosition->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pInvestorPosition->InvestUnitID);
			}
		}
		
		m_pAdapter->OnRspQryInvestorPosition(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询资金账户响应
	void CTraderSpi::OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryTradingAccount_delegate == nullptr) return;
		
		CtpNetTradingAccountField^ field = nullptr;
		if (pTradingAccount != nullptr)
		{
			field = gcnew CtpNetTradingAccountField;
			
			//经纪公司代码
			if (pTradingAccount->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pTradingAccount->BrokerID);
			}
			//投资者帐号
			if (pTradingAccount->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pTradingAccount->AccountID);
			}
			//上次质押金额
			field->PreMortgage = pTradingAccount->PreMortgage;
			//上次信用额度
			field->PreCredit = pTradingAccount->PreCredit;
			//上次存款额
			field->PreDeposit = pTradingAccount->PreDeposit;
			//上次结算准备金
			field->PreBalance = pTradingAccount->PreBalance;
			//上次占用的保证金
			field->PreMargin = pTradingAccount->PreMargin;
			//利息基数
			field->InterestBase = pTradingAccount->InterestBase;
			//利息收入
			field->Interest = pTradingAccount->Interest;
			//入金金额
			field->Deposit = pTradingAccount->Deposit;
			//出金金额
			field->Withdraw = pTradingAccount->Withdraw;
			//冻结的保证金
			field->FrozenMargin = pTradingAccount->FrozenMargin;
			//冻结的资金
			field->FrozenCash = pTradingAccount->FrozenCash;
			//冻结的手续费
			field->FrozenCommission = pTradingAccount->FrozenCommission;
			//当前保证金总额
			field->CurrMargin = pTradingAccount->CurrMargin;
			//资金差额
			field->CashIn = pTradingAccount->CashIn;
			//手续费
			field->Commission = pTradingAccount->Commission;
			//平仓盈亏
			field->CloseProfit = pTradingAccount->CloseProfit;
			//持仓盈亏
			field->PositionProfit = pTradingAccount->PositionProfit;
			//期货结算准备金
			field->Balance = pTradingAccount->Balance;
			//可用资金
			field->Available = pTradingAccount->Available;
			//可取资金
			field->WithdrawQuota = pTradingAccount->WithdrawQuota;
			//基本准备金
			field->Reserve = pTradingAccount->Reserve;
			//交易日
			if (pTradingAccount->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pTradingAccount->TradingDay);
			}
			//结算编号
			field->SettlementID = pTradingAccount->SettlementID;
			//信用额度
			field->Credit = pTradingAccount->Credit;
			//质押金额
			field->Mortgage = pTradingAccount->Mortgage;
			//交易所保证金
			field->ExchangeMargin = pTradingAccount->ExchangeMargin;
			//投资者交割保证金
			field->DeliveryMargin = pTradingAccount->DeliveryMargin;
			//交易所交割保证金
			field->ExchangeDeliveryMargin = pTradingAccount->ExchangeDeliveryMargin;
			//保底期货结算准备金
			field->ReserveBalance = pTradingAccount->ReserveBalance;
			//币种代码
			if (pTradingAccount->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pTradingAccount->CurrencyID);
			}
			//上次货币质入金额
			field->PreFundMortgageIn = pTradingAccount->PreFundMortgageIn;
			//上次货币质出金额
			field->PreFundMortgageOut = pTradingAccount->PreFundMortgageOut;
			//货币质入金额
			field->FundMortgageIn = pTradingAccount->FundMortgageIn;
			//货币质出金额
			field->FundMortgageOut = pTradingAccount->FundMortgageOut;
			//货币质押余额
			field->FundMortgageAvailable = pTradingAccount->FundMortgageAvailable;
			//可质押货币金额
			field->MortgageableFund = pTradingAccount->MortgageableFund;
			//特殊产品占用保证金
			field->SpecProductMargin = pTradingAccount->SpecProductMargin;
			//特殊产品冻结保证金
			field->SpecProductFrozenMargin = pTradingAccount->SpecProductFrozenMargin;
			//特殊产品手续费
			field->SpecProductCommission = pTradingAccount->SpecProductCommission;
			//特殊产品冻结手续费
			field->SpecProductFrozenCommission = pTradingAccount->SpecProductFrozenCommission;
			//特殊产品持仓盈亏
			field->SpecProductPositionProfit = pTradingAccount->SpecProductPositionProfit;
			//特殊产品平仓盈亏
			field->SpecProductCloseProfit = pTradingAccount->SpecProductCloseProfit;
			//根据持仓盈亏算法计算的特殊产品持仓盈亏
			field->SpecProductPositionProfitByAlg = pTradingAccount->SpecProductPositionProfitByAlg;
			//特殊产品交易所保证金
			field->SpecProductExchangeMargin = pTradingAccount->SpecProductExchangeMargin;
			//业务类型
			field->BizType = (CtpNetBizTypeType)pTradingAccount->BizType;
			//延时换汇冻结金额
			field->FrozenSwap = pTradingAccount->FrozenSwap;
			//剩余换汇额度
			field->RemainSwap = pTradingAccount->RemainSwap;
		}
		
		m_pAdapter->OnRspQryTradingAccount(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询投资者响应
	void CTraderSpi::OnRspQryInvestor(CThostFtdcInvestorField *pInvestor, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryInvestor_delegate == nullptr) return;
		
		CtpNetInvestorField^ field = nullptr;
		if (pInvestor != nullptr)
		{
			field = gcnew CtpNetInvestorField;
			
			//投资者代码
			if (pInvestor->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pInvestor->InvestorID);
			}
			//经纪公司代码
			if (pInvestor->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pInvestor->BrokerID);
			}
			//投资者分组代码
			if (pInvestor->InvestorGroupID != nullptr)
			{
				field->InvestorGroupID = gcnew String(pInvestor->InvestorGroupID);
			}
			//投资者名称
			if (pInvestor->InvestorName != nullptr)
			{
				field->InvestorName = gcnew String(pInvestor->InvestorName);
			}
			//证件类型
			field->IdentifiedCardType = (CtpNetIdCardTypeType)pInvestor->IdentifiedCardType;
			//证件号码
			if (pInvestor->IdentifiedCardNo != nullptr)
			{
				field->IdentifiedCardNo = gcnew String(pInvestor->IdentifiedCardNo);
			}
			//是否活跃
			field->IsActive = pInvestor->IsActive;
			//联系电话
			if (pInvestor->Telephone != nullptr)
			{
				field->Telephone = gcnew String(pInvestor->Telephone);
			}
			//通讯地址
			if (pInvestor->Address != nullptr)
			{
				field->Address = gcnew String(pInvestor->Address);
			}
			//开户日期
			if (pInvestor->OpenDate != nullptr)
			{
				field->OpenDate = gcnew String(pInvestor->OpenDate);
			}
			//手机
			if (pInvestor->Mobile != nullptr)
			{
				field->Mobile = gcnew String(pInvestor->Mobile);
			}
			//手续费率模板代码
			if (pInvestor->CommModelID != nullptr)
			{
				field->CommModelID = gcnew String(pInvestor->CommModelID);
			}
			//保证金率模板代码
			if (pInvestor->MarginModelID != nullptr)
			{
				field->MarginModelID = gcnew String(pInvestor->MarginModelID);
			}
		}
		
		m_pAdapter->OnRspQryInvestor(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询交易编码响应
	void CTraderSpi::OnRspQryTradingCode(CThostFtdcTradingCodeField *pTradingCode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryTradingCode_delegate == nullptr) return;
		
		CtpNetTradingCodeField^ field = nullptr;
		if (pTradingCode != nullptr)
		{
			field = gcnew CtpNetTradingCodeField;
			
			//投资者代码
			if (pTradingCode->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pTradingCode->InvestorID);
			}
			//经纪公司代码
			if (pTradingCode->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pTradingCode->BrokerID);
			}
			//交易所代码
			if (pTradingCode->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pTradingCode->ExchangeID);
			}
			//客户代码
			if (pTradingCode->ClientID != nullptr)
			{
				field->ClientID = gcnew String(pTradingCode->ClientID);
			}
			//是否活跃
			field->IsActive = pTradingCode->IsActive;
			//交易编码类型
			field->ClientIDType = (CtpNetClientIDTypeType)pTradingCode->ClientIDType;
			//营业部编号
			if (pTradingCode->BranchID != nullptr)
			{
				field->BranchID = gcnew String(pTradingCode->BranchID);
			}
			//业务类型
			field->BizType = (CtpNetBizTypeType)pTradingCode->BizType;
			//投资单元代码
			if (pTradingCode->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pTradingCode->InvestUnitID);
			}
		}
		
		m_pAdapter->OnRspQryTradingCode(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询合约保证金率响应
	void CTraderSpi::OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryInstrumentMarginRate_delegate == nullptr) return;
		
		CtpNetInstrumentMarginRateField^ field = nullptr;
		if (pInstrumentMarginRate != nullptr)
		{
			field = gcnew CtpNetInstrumentMarginRateField;
			
			//合约代码
			if (pInstrumentMarginRate->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pInstrumentMarginRate->InstrumentID);
			}
			//投资者范围
			field->InvestorRange = (CtpNetInvestorRangeType)pInstrumentMarginRate->InvestorRange;
			//经纪公司代码
			if (pInstrumentMarginRate->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pInstrumentMarginRate->BrokerID);
			}
			//投资者代码
			if (pInstrumentMarginRate->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pInstrumentMarginRate->InvestorID);
			}
			//投机套保标志
			field->HedgeFlag = (CtpNetHedgeFlagType)pInstrumentMarginRate->HedgeFlag;
			//多头保证金率
			field->LongMarginRatioByMoney = pInstrumentMarginRate->LongMarginRatioByMoney;
			//多头保证金费
			field->LongMarginRatioByVolume = pInstrumentMarginRate->LongMarginRatioByVolume;
			//空头保证金率
			field->ShortMarginRatioByMoney = pInstrumentMarginRate->ShortMarginRatioByMoney;
			//空头保证金费
			field->ShortMarginRatioByVolume = pInstrumentMarginRate->ShortMarginRatioByVolume;
			//是否相对交易所收取
			field->IsRelative = pInstrumentMarginRate->IsRelative;
			//交易所代码
			if (pInstrumentMarginRate->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pInstrumentMarginRate->ExchangeID);
			}
			//投资单元代码
			if (pInstrumentMarginRate->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pInstrumentMarginRate->InvestUnitID);
			}
		}
		
		m_pAdapter->OnRspQryInstrumentMarginRate(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询合约手续费率响应
	void CTraderSpi::OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryInstrumentCommissionRate_delegate == nullptr) return;
		
		CtpNetInstrumentCommissionRateField^ field = nullptr;
		if (pInstrumentCommissionRate != nullptr)
		{
			field = gcnew CtpNetInstrumentCommissionRateField;
			
			//合约代码
			if (pInstrumentCommissionRate->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pInstrumentCommissionRate->InstrumentID);
			}
			//投资者范围
			field->InvestorRange = (CtpNetInvestorRangeType)pInstrumentCommissionRate->InvestorRange;
			//经纪公司代码
			if (pInstrumentCommissionRate->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pInstrumentCommissionRate->BrokerID);
			}
			//投资者代码
			if (pInstrumentCommissionRate->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pInstrumentCommissionRate->InvestorID);
			}
			//开仓手续费率
			field->OpenRatioByMoney = pInstrumentCommissionRate->OpenRatioByMoney;
			//开仓手续费
			field->OpenRatioByVolume = pInstrumentCommissionRate->OpenRatioByVolume;
			//平仓手续费率
			field->CloseRatioByMoney = pInstrumentCommissionRate->CloseRatioByMoney;
			//平仓手续费
			field->CloseRatioByVolume = pInstrumentCommissionRate->CloseRatioByVolume;
			//平今手续费率
			field->CloseTodayRatioByMoney = pInstrumentCommissionRate->CloseTodayRatioByMoney;
			//平今手续费
			field->CloseTodayRatioByVolume = pInstrumentCommissionRate->CloseTodayRatioByVolume;
			//交易所代码
			if (pInstrumentCommissionRate->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pInstrumentCommissionRate->ExchangeID);
			}
			//业务类型
			field->BizType = (CtpNetBizTypeType)pInstrumentCommissionRate->BizType;
			//投资单元代码
			if (pInstrumentCommissionRate->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pInstrumentCommissionRate->InvestUnitID);
			}
		}
		
		m_pAdapter->OnRspQryInstrumentCommissionRate(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询交易所响应
	void CTraderSpi::OnRspQryExchange(CThostFtdcExchangeField *pExchange, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryExchange_delegate == nullptr) return;
		
		CtpNetExchangeField^ field = nullptr;
		if (pExchange != nullptr)
		{
			field = gcnew CtpNetExchangeField;
			
			//交易所代码
			if (pExchange->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pExchange->ExchangeID);
			}
			//交易所名称
			if (pExchange->ExchangeName != nullptr)
			{
				field->ExchangeName = gcnew String(pExchange->ExchangeName);
			}
			//交易所属性
			field->ExchangeProperty = (CtpNetExchangePropertyType)pExchange->ExchangeProperty;
		}
		
		m_pAdapter->OnRspQryExchange(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询产品响应
	void CTraderSpi::OnRspQryProduct(CThostFtdcProductField *pProduct, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryProduct_delegate == nullptr) return;
		
		CtpNetProductField^ field = nullptr;
		if (pProduct != nullptr)
		{
			field = gcnew CtpNetProductField;
			
			//产品代码
			if (pProduct->ProductID != nullptr)
			{
				field->ProductID = gcnew String(pProduct->ProductID);
			}
			//产品名称
			if (pProduct->ProductName != nullptr)
			{
				field->ProductName = gcnew String(pProduct->ProductName);
			}
			//交易所代码
			if (pProduct->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pProduct->ExchangeID);
			}
			//产品类型
			field->ProductClass = (CtpNetProductClassType)pProduct->ProductClass;
			//合约数量乘数
			field->VolumeMultiple = pProduct->VolumeMultiple;
			//最小变动价位
			field->PriceTick = pProduct->PriceTick;
			//市价单最大下单量
			field->MaxMarketOrderVolume = pProduct->MaxMarketOrderVolume;
			//市价单最小下单量
			field->MinMarketOrderVolume = pProduct->MinMarketOrderVolume;
			//限价单最大下单量
			field->MaxLimitOrderVolume = pProduct->MaxLimitOrderVolume;
			//限价单最小下单量
			field->MinLimitOrderVolume = pProduct->MinLimitOrderVolume;
			//持仓类型
			field->PositionType = (CtpNetPositionTypeType)pProduct->PositionType;
			//持仓日期类型
			field->PositionDateType = (CtpNetPositionDateTypeType)pProduct->PositionDateType;
			//平仓处理类型
			field->CloseDealType = (CtpNetCloseDealTypeType)pProduct->CloseDealType;
			//交易币种类型
			if (pProduct->TradeCurrencyID != nullptr)
			{
				field->TradeCurrencyID = gcnew String(pProduct->TradeCurrencyID);
			}
			//质押资金可用范围
			field->MortgageFundUseRange = (CtpNetMortgageFundUseRangeType)pProduct->MortgageFundUseRange;
			//交易所产品代码
			if (pProduct->ExchangeProductID != nullptr)
			{
				field->ExchangeProductID = gcnew String(pProduct->ExchangeProductID);
			}
			//合约基础商品乘数
			field->UnderlyingMultiple = pProduct->UnderlyingMultiple;
		}
		
		m_pAdapter->OnRspQryProduct(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询合约响应
	void CTraderSpi::OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryInstrument_delegate == nullptr) return;
		
		CtpNetInstrumentField^ field = nullptr;
		if (pInstrument != nullptr)
		{
			field = gcnew CtpNetInstrumentField;
			
			//合约代码
			if (pInstrument->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pInstrument->InstrumentID);
			}
			//交易所代码
			if (pInstrument->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pInstrument->ExchangeID);
			}
			//合约名称
			if (pInstrument->InstrumentName != nullptr)
			{
				field->InstrumentName = gcnew String(pInstrument->InstrumentName);
			}
			//合约在交易所的代码
			if (pInstrument->ExchangeInstID != nullptr)
			{
				field->ExchangeInstID = gcnew String(pInstrument->ExchangeInstID);
			}
			//产品代码
			if (pInstrument->ProductID != nullptr)
			{
				field->ProductID = gcnew String(pInstrument->ProductID);
			}
			//产品类型
			field->ProductClass = (CtpNetProductClassType)pInstrument->ProductClass;
			//交割年份
			field->DeliveryYear = pInstrument->DeliveryYear;
			//交割月
			field->DeliveryMonth = pInstrument->DeliveryMonth;
			//市价单最大下单量
			field->MaxMarketOrderVolume = pInstrument->MaxMarketOrderVolume;
			//市价单最小下单量
			field->MinMarketOrderVolume = pInstrument->MinMarketOrderVolume;
			//限价单最大下单量
			field->MaxLimitOrderVolume = pInstrument->MaxLimitOrderVolume;
			//限价单最小下单量
			field->MinLimitOrderVolume = pInstrument->MinLimitOrderVolume;
			//合约数量乘数
			field->VolumeMultiple = pInstrument->VolumeMultiple;
			//最小变动价位
			field->PriceTick = pInstrument->PriceTick;
			//创建日
			if (pInstrument->CreateDate != nullptr)
			{
				field->CreateDate = gcnew String(pInstrument->CreateDate);
			}
			//上市日
			if (pInstrument->OpenDate != nullptr)
			{
				field->OpenDate = gcnew String(pInstrument->OpenDate);
			}
			//到期日
			if (pInstrument->ExpireDate != nullptr)
			{
				field->ExpireDate = gcnew String(pInstrument->ExpireDate);
			}
			//开始交割日
			if (pInstrument->StartDelivDate != nullptr)
			{
				field->StartDelivDate = gcnew String(pInstrument->StartDelivDate);
			}
			//结束交割日
			if (pInstrument->EndDelivDate != nullptr)
			{
				field->EndDelivDate = gcnew String(pInstrument->EndDelivDate);
			}
			//合约生命周期状态
			field->InstLifePhase = (CtpNetInstLifePhaseType)pInstrument->InstLifePhase;
			//当前是否交易
			field->IsTrading = pInstrument->IsTrading;
			//持仓类型
			field->PositionType = (CtpNetPositionTypeType)pInstrument->PositionType;
			//持仓日期类型
			field->PositionDateType = (CtpNetPositionDateTypeType)pInstrument->PositionDateType;
			//多头保证金率
			field->LongMarginRatio = pInstrument->LongMarginRatio;
			//空头保证金率
			field->ShortMarginRatio = pInstrument->ShortMarginRatio;
			//是否使用大额单边保证金算法
			field->MaxMarginSideAlgorithm = (CtpNetMaxMarginSideAlgorithmType)pInstrument->MaxMarginSideAlgorithm;
			//基础商品代码
			if (pInstrument->UnderlyingInstrID != nullptr)
			{
				field->UnderlyingInstrID = gcnew String(pInstrument->UnderlyingInstrID);
			}
			//执行价
			field->StrikePrice = pInstrument->StrikePrice;
			//期权类型
			field->OptionsType = (CtpNetOptionsTypeType)pInstrument->OptionsType;
			//合约基础商品乘数
			field->UnderlyingMultiple = pInstrument->UnderlyingMultiple;
			//组合类型
			field->CombinationType = (CtpNetCombinationTypeType)pInstrument->CombinationType;
		}
		
		m_pAdapter->OnRspQryInstrument(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询行情响应
	void CTraderSpi::OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryDepthMarketData_delegate == nullptr) return;
		
		CtpNetDepthMarketDataField^ field = nullptr;
		if (pDepthMarketData != nullptr)
		{
			field = gcnew CtpNetDepthMarketDataField;
			
			//交易日
			if (pDepthMarketData->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pDepthMarketData->TradingDay);
			}
			//合约代码
			if (pDepthMarketData->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pDepthMarketData->InstrumentID);
			}
			//交易所代码
			if (pDepthMarketData->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pDepthMarketData->ExchangeID);
			}
			//合约在交易所的代码
			if (pDepthMarketData->ExchangeInstID != nullptr)
			{
				field->ExchangeInstID = gcnew String(pDepthMarketData->ExchangeInstID);
			}
			//最新价
			field->LastPrice = pDepthMarketData->LastPrice;
			//上次结算价
			field->PreSettlementPrice = pDepthMarketData->PreSettlementPrice;
			//昨收盘
			field->PreClosePrice = pDepthMarketData->PreClosePrice;
			//昨持仓量
			field->PreOpenInterest = pDepthMarketData->PreOpenInterest;
			//今开盘
			field->OpenPrice = pDepthMarketData->OpenPrice;
			//最高价
			field->HighestPrice = pDepthMarketData->HighestPrice;
			//最低价
			field->LowestPrice = pDepthMarketData->LowestPrice;
			//数量
			field->Volume = pDepthMarketData->Volume;
			//成交金额
			field->Turnover = pDepthMarketData->Turnover;
			//持仓量
			field->OpenInterest = pDepthMarketData->OpenInterest;
			//今收盘
			field->ClosePrice = pDepthMarketData->ClosePrice;
			//本次结算价
			field->SettlementPrice = pDepthMarketData->SettlementPrice;
			//涨停板价
			field->UpperLimitPrice = pDepthMarketData->UpperLimitPrice;
			//跌停板价
			field->LowerLimitPrice = pDepthMarketData->LowerLimitPrice;
			//昨虚实度
			field->PreDelta = pDepthMarketData->PreDelta;
			//今虚实度
			field->CurrDelta = pDepthMarketData->CurrDelta;
			//最后修改时间
			if (pDepthMarketData->UpdateTime != nullptr)
			{
				field->UpdateTime = gcnew String(pDepthMarketData->UpdateTime);
			}
			//最后修改毫秒
			field->UpdateMillisec = pDepthMarketData->UpdateMillisec;
			//申买价一
			field->BidPrice1 = pDepthMarketData->BidPrice1;
			//申买量一
			field->BidVolume1 = pDepthMarketData->BidVolume1;
			//申卖价一
			field->AskPrice1 = pDepthMarketData->AskPrice1;
			//申卖量一
			field->AskVolume1 = pDepthMarketData->AskVolume1;
			//申买价二
			field->BidPrice2 = pDepthMarketData->BidPrice2;
			//申买量二
			field->BidVolume2 = pDepthMarketData->BidVolume2;
			//申卖价二
			field->AskPrice2 = pDepthMarketData->AskPrice2;
			//申卖量二
			field->AskVolume2 = pDepthMarketData->AskVolume2;
			//申买价三
			field->BidPrice3 = pDepthMarketData->BidPrice3;
			//申买量三
			field->BidVolume3 = pDepthMarketData->BidVolume3;
			//申卖价三
			field->AskPrice3 = pDepthMarketData->AskPrice3;
			//申卖量三
			field->AskVolume3 = pDepthMarketData->AskVolume3;
			//申买价四
			field->BidPrice4 = pDepthMarketData->BidPrice4;
			//申买量四
			field->BidVolume4 = pDepthMarketData->BidVolume4;
			//申卖价四
			field->AskPrice4 = pDepthMarketData->AskPrice4;
			//申卖量四
			field->AskVolume4 = pDepthMarketData->AskVolume4;
			//申买价五
			field->BidPrice5 = pDepthMarketData->BidPrice5;
			//申买量五
			field->BidVolume5 = pDepthMarketData->BidVolume5;
			//申卖价五
			field->AskPrice5 = pDepthMarketData->AskPrice5;
			//申卖量五
			field->AskVolume5 = pDepthMarketData->AskVolume5;
			//当日均价
			field->AveragePrice = pDepthMarketData->AveragePrice;
			//业务日期
			if (pDepthMarketData->ActionDay != nullptr)
			{
				field->ActionDay = gcnew String(pDepthMarketData->ActionDay);
			}
		}
		
		m_pAdapter->OnRspQryDepthMarketData(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询投资者结算结果响应
	void CTraderSpi::OnRspQrySettlementInfo(CThostFtdcSettlementInfoField *pSettlementInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQrySettlementInfo_delegate == nullptr) return;
		
		CtpNetSettlementInfoField^ field = nullptr;
		if (pSettlementInfo != nullptr)
		{
			field = gcnew CtpNetSettlementInfoField;
			
			//交易日
			if (pSettlementInfo->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pSettlementInfo->TradingDay);
			}
			//结算编号
			field->SettlementID = pSettlementInfo->SettlementID;
			//经纪公司代码
			if (pSettlementInfo->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pSettlementInfo->BrokerID);
			}
			//投资者代码
			if (pSettlementInfo->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pSettlementInfo->InvestorID);
			}
			//序号
			field->SequenceNo = pSettlementInfo->SequenceNo;
			//消息正文
			if (pSettlementInfo->Content != nullptr)
			{
				field->Content = gcnew String(pSettlementInfo->Content);
			}
			//投资者帐号
			if (pSettlementInfo->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pSettlementInfo->AccountID);
			}
			//币种代码
			if (pSettlementInfo->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pSettlementInfo->CurrencyID);
			}
		}
		
		m_pAdapter->OnRspQrySettlementInfo(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询转帐银行响应
	void CTraderSpi::OnRspQryTransferBank(CThostFtdcTransferBankField *pTransferBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryTransferBank_delegate == nullptr) return;
		
		CtpNetTransferBankField^ field = nullptr;
		if (pTransferBank != nullptr)
		{
			field = gcnew CtpNetTransferBankField;
			
			//银行代码
			if (pTransferBank->BankID != nullptr)
			{
				field->BankID = gcnew String(pTransferBank->BankID);
			}
			//银行分中心代码
			if (pTransferBank->BankBrchID != nullptr)
			{
				field->BankBrchID = gcnew String(pTransferBank->BankBrchID);
			}
			//银行名称
			if (pTransferBank->BankName != nullptr)
			{
				field->BankName = gcnew String(pTransferBank->BankName);
			}
			//是否活跃
			field->IsActive = pTransferBank->IsActive;
		}
		
		m_pAdapter->OnRspQryTransferBank(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询投资者持仓明细响应
	void CTraderSpi::OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryInvestorPositionDetail_delegate == nullptr) return;
		
		CtpNetInvestorPositionDetailField^ field = nullptr;
		if (pInvestorPositionDetail != nullptr)
		{
			field = gcnew CtpNetInvestorPositionDetailField;
			
			//合约代码
			if (pInvestorPositionDetail->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pInvestorPositionDetail->InstrumentID);
			}
			//经纪公司代码
			if (pInvestorPositionDetail->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pInvestorPositionDetail->BrokerID);
			}
			//投资者代码
			if (pInvestorPositionDetail->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pInvestorPositionDetail->InvestorID);
			}
			//投机套保标志
			field->HedgeFlag = (CtpNetHedgeFlagType)pInvestorPositionDetail->HedgeFlag;
			//买卖
			field->Direction = (CtpNetDirectionType)pInvestorPositionDetail->Direction;
			//开仓日期
			if (pInvestorPositionDetail->OpenDate != nullptr)
			{
				field->OpenDate = gcnew String(pInvestorPositionDetail->OpenDate);
			}
			//成交编号
			if (pInvestorPositionDetail->TradeID != nullptr)
			{
				field->TradeID = gcnew String(pInvestorPositionDetail->TradeID);
			}
			//数量
			field->Volume = pInvestorPositionDetail->Volume;
			//开仓价
			field->OpenPrice = pInvestorPositionDetail->OpenPrice;
			//交易日
			if (pInvestorPositionDetail->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pInvestorPositionDetail->TradingDay);
			}
			//结算编号
			field->SettlementID = pInvestorPositionDetail->SettlementID;
			//成交类型
			field->TradeType = (CtpNetTradeTypeType)pInvestorPositionDetail->TradeType;
			//组合合约代码
			if (pInvestorPositionDetail->CombInstrumentID != nullptr)
			{
				field->CombInstrumentID = gcnew String(pInvestorPositionDetail->CombInstrumentID);
			}
			//交易所代码
			if (pInvestorPositionDetail->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pInvestorPositionDetail->ExchangeID);
			}
			//逐日盯市平仓盈亏
			field->CloseProfitByDate = pInvestorPositionDetail->CloseProfitByDate;
			//逐笔对冲平仓盈亏
			field->CloseProfitByTrade = pInvestorPositionDetail->CloseProfitByTrade;
			//逐日盯市持仓盈亏
			field->PositionProfitByDate = pInvestorPositionDetail->PositionProfitByDate;
			//逐笔对冲持仓盈亏
			field->PositionProfitByTrade = pInvestorPositionDetail->PositionProfitByTrade;
			//投资者保证金
			field->Margin = pInvestorPositionDetail->Margin;
			//交易所保证金
			field->ExchMargin = pInvestorPositionDetail->ExchMargin;
			//保证金率
			field->MarginRateByMoney = pInvestorPositionDetail->MarginRateByMoney;
			//保证金率(按手数)
			field->MarginRateByVolume = pInvestorPositionDetail->MarginRateByVolume;
			//昨结算价
			field->LastSettlementPrice = pInvestorPositionDetail->LastSettlementPrice;
			//结算价
			field->SettlementPrice = pInvestorPositionDetail->SettlementPrice;
			//平仓量
			field->CloseVolume = pInvestorPositionDetail->CloseVolume;
			//平仓金额
			field->CloseAmount = pInvestorPositionDetail->CloseAmount;
			//投资单元代码
			if (pInvestorPositionDetail->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pInvestorPositionDetail->InvestUnitID);
			}
		}
		
		m_pAdapter->OnRspQryInvestorPositionDetail(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询客户通知响应
	void CTraderSpi::OnRspQryNotice(CThostFtdcNoticeField *pNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryNotice_delegate == nullptr) return;
		
		CtpNetNoticeField^ field = nullptr;
		if (pNotice != nullptr)
		{
			field = gcnew CtpNetNoticeField;
			
			//经纪公司代码
			if (pNotice->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pNotice->BrokerID);
			}
			//消息正文
			if (pNotice->Content != nullptr)
			{
				field->Content = gcnew String(pNotice->Content);
			}
			//经纪公司通知内容序列号
			if (pNotice->SequenceLabel != nullptr)
			{
				field->SequenceLabel = gcnew String(pNotice->SequenceLabel);
			}
		}
		
		m_pAdapter->OnRspQryNotice(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询结算信息确认响应
	void CTraderSpi::OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQrySettlementInfoConfirm_delegate == nullptr) return;
		
		CtpNetSettlementInfoConfirmField^ field = nullptr;
		if (pSettlementInfoConfirm != nullptr)
		{
			field = gcnew CtpNetSettlementInfoConfirmField;
			
			//经纪公司代码
			if (pSettlementInfoConfirm->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pSettlementInfoConfirm->BrokerID);
			}
			//投资者代码
			if (pSettlementInfoConfirm->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pSettlementInfoConfirm->InvestorID);
			}
			//确认日期
			if (pSettlementInfoConfirm->ConfirmDate != nullptr)
			{
				field->ConfirmDate = gcnew String(pSettlementInfoConfirm->ConfirmDate);
			}
			//确认时间
			if (pSettlementInfoConfirm->ConfirmTime != nullptr)
			{
				field->ConfirmTime = gcnew String(pSettlementInfoConfirm->ConfirmTime);
			}
			//结算编号
			field->SettlementID = pSettlementInfoConfirm->SettlementID;
			//投资者帐号
			if (pSettlementInfoConfirm->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pSettlementInfoConfirm->AccountID);
			}
			//币种代码
			if (pSettlementInfoConfirm->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pSettlementInfoConfirm->CurrencyID);
			}
		}
		
		m_pAdapter->OnRspQrySettlementInfoConfirm(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询投资者持仓明细响应
	void CTraderSpi::OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField *pInvestorPositionCombineDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryInvestorPositionCombineDetail_delegate == nullptr) return;
		
		CtpNetInvestorPositionCombineDetailField^ field = nullptr;
		if (pInvestorPositionCombineDetail != nullptr)
		{
			field = gcnew CtpNetInvestorPositionCombineDetailField;
			
			//交易日
			if (pInvestorPositionCombineDetail->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pInvestorPositionCombineDetail->TradingDay);
			}
			//开仓日期
			if (pInvestorPositionCombineDetail->OpenDate != nullptr)
			{
				field->OpenDate = gcnew String(pInvestorPositionCombineDetail->OpenDate);
			}
			//交易所代码
			if (pInvestorPositionCombineDetail->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pInvestorPositionCombineDetail->ExchangeID);
			}
			//结算编号
			field->SettlementID = pInvestorPositionCombineDetail->SettlementID;
			//经纪公司代码
			if (pInvestorPositionCombineDetail->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pInvestorPositionCombineDetail->BrokerID);
			}
			//投资者代码
			if (pInvestorPositionCombineDetail->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pInvestorPositionCombineDetail->InvestorID);
			}
			//组合编号
			if (pInvestorPositionCombineDetail->ComTradeID != nullptr)
			{
				field->ComTradeID = gcnew String(pInvestorPositionCombineDetail->ComTradeID);
			}
			//撮合编号
			if (pInvestorPositionCombineDetail->TradeID != nullptr)
			{
				field->TradeID = gcnew String(pInvestorPositionCombineDetail->TradeID);
			}
			//合约代码
			if (pInvestorPositionCombineDetail->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pInvestorPositionCombineDetail->InstrumentID);
			}
			//投机套保标志
			field->HedgeFlag = (CtpNetHedgeFlagType)pInvestorPositionCombineDetail->HedgeFlag;
			//买卖
			field->Direction = (CtpNetDirectionType)pInvestorPositionCombineDetail->Direction;
			//持仓量
			field->TotalAmt = pInvestorPositionCombineDetail->TotalAmt;
			//投资者保证金
			field->Margin = pInvestorPositionCombineDetail->Margin;
			//交易所保证金
			field->ExchMargin = pInvestorPositionCombineDetail->ExchMargin;
			//保证金率
			field->MarginRateByMoney = pInvestorPositionCombineDetail->MarginRateByMoney;
			//保证金率(按手数)
			field->MarginRateByVolume = pInvestorPositionCombineDetail->MarginRateByVolume;
			//单腿编号
			field->LegID = pInvestorPositionCombineDetail->LegID;
			//单腿乘数
			field->LegMultiple = pInvestorPositionCombineDetail->LegMultiple;
			//组合持仓合约编码
			if (pInvestorPositionCombineDetail->CombInstrumentID != nullptr)
			{
				field->CombInstrumentID = gcnew String(pInvestorPositionCombineDetail->CombInstrumentID);
			}
			//成交组号
			field->TradeGroupID = pInvestorPositionCombineDetail->TradeGroupID;
			//投资单元代码
			if (pInvestorPositionCombineDetail->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pInvestorPositionCombineDetail->InvestUnitID);
			}
		}
		
		m_pAdapter->OnRspQryInvestorPositionCombineDetail(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 查询保证金监管系统经纪公司资金账户密钥响应
	void CTraderSpi::OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField *pCFMMCTradingAccountKey, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryCFMMCTradingAccountKey_delegate == nullptr) return;
		
		CtpNetCFMMCTradingAccountKeyField^ field = nullptr;
		if (pCFMMCTradingAccountKey != nullptr)
		{
			field = gcnew CtpNetCFMMCTradingAccountKeyField;
			
			//经纪公司代码
			if (pCFMMCTradingAccountKey->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pCFMMCTradingAccountKey->BrokerID);
			}
			//经纪公司统一编码
			if (pCFMMCTradingAccountKey->ParticipantID != nullptr)
			{
				field->ParticipantID = gcnew String(pCFMMCTradingAccountKey->ParticipantID);
			}
			//投资者帐号
			if (pCFMMCTradingAccountKey->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pCFMMCTradingAccountKey->AccountID);
			}
			//密钥编号
			field->KeyID = pCFMMCTradingAccountKey->KeyID;
			//动态密钥
			if (pCFMMCTradingAccountKey->CurrentKey != nullptr)
			{
				field->CurrentKey = gcnew String(pCFMMCTradingAccountKey->CurrentKey);
			}
		}
		
		m_pAdapter->OnRspQryCFMMCTradingAccountKey(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询仓单折抵信息响应
	void CTraderSpi::OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField *pEWarrantOffset, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryEWarrantOffset_delegate == nullptr) return;
		
		CtpNetEWarrantOffsetField^ field = nullptr;
		if (pEWarrantOffset != nullptr)
		{
			field = gcnew CtpNetEWarrantOffsetField;
			
			//交易日期
			if (pEWarrantOffset->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pEWarrantOffset->TradingDay);
			}
			//经纪公司代码
			if (pEWarrantOffset->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pEWarrantOffset->BrokerID);
			}
			//投资者代码
			if (pEWarrantOffset->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pEWarrantOffset->InvestorID);
			}
			//交易所代码
			if (pEWarrantOffset->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pEWarrantOffset->ExchangeID);
			}
			//合约代码
			if (pEWarrantOffset->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pEWarrantOffset->InstrumentID);
			}
			//买卖方向
			field->Direction = (CtpNetDirectionType)pEWarrantOffset->Direction;
			//投机套保标志
			field->HedgeFlag = (CtpNetHedgeFlagType)pEWarrantOffset->HedgeFlag;
			//数量
			field->Volume = pEWarrantOffset->Volume;
			//投资单元代码
			if (pEWarrantOffset->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pEWarrantOffset->InvestUnitID);
			}
		}
		
		m_pAdapter->OnRspQryEWarrantOffset(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询投资者品种/跨品种保证金响应
	void CTraderSpi::OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField *pInvestorProductGroupMargin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryInvestorProductGroupMargin_delegate == nullptr) return;
		
		CtpNetInvestorProductGroupMarginField^ field = nullptr;
		if (pInvestorProductGroupMargin != nullptr)
		{
			field = gcnew CtpNetInvestorProductGroupMarginField;
			
			//品种/跨品种标示
			if (pInvestorProductGroupMargin->ProductGroupID != nullptr)
			{
				field->ProductGroupID = gcnew String(pInvestorProductGroupMargin->ProductGroupID);
			}
			//经纪公司代码
			if (pInvestorProductGroupMargin->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pInvestorProductGroupMargin->BrokerID);
			}
			//投资者代码
			if (pInvestorProductGroupMargin->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pInvestorProductGroupMargin->InvestorID);
			}
			//交易日
			if (pInvestorProductGroupMargin->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pInvestorProductGroupMargin->TradingDay);
			}
			//结算编号
			field->SettlementID = pInvestorProductGroupMargin->SettlementID;
			//冻结的保证金
			field->FrozenMargin = pInvestorProductGroupMargin->FrozenMargin;
			//多头冻结的保证金
			field->LongFrozenMargin = pInvestorProductGroupMargin->LongFrozenMargin;
			//空头冻结的保证金
			field->ShortFrozenMargin = pInvestorProductGroupMargin->ShortFrozenMargin;
			//占用的保证金
			field->UseMargin = pInvestorProductGroupMargin->UseMargin;
			//多头保证金
			field->LongUseMargin = pInvestorProductGroupMargin->LongUseMargin;
			//空头保证金
			field->ShortUseMargin = pInvestorProductGroupMargin->ShortUseMargin;
			//交易所保证金
			field->ExchMargin = pInvestorProductGroupMargin->ExchMargin;
			//交易所多头保证金
			field->LongExchMargin = pInvestorProductGroupMargin->LongExchMargin;
			//交易所空头保证金
			field->ShortExchMargin = pInvestorProductGroupMargin->ShortExchMargin;
			//平仓盈亏
			field->CloseProfit = pInvestorProductGroupMargin->CloseProfit;
			//冻结的手续费
			field->FrozenCommission = pInvestorProductGroupMargin->FrozenCommission;
			//手续费
			field->Commission = pInvestorProductGroupMargin->Commission;
			//冻结的资金
			field->FrozenCash = pInvestorProductGroupMargin->FrozenCash;
			//资金差额
			field->CashIn = pInvestorProductGroupMargin->CashIn;
			//持仓盈亏
			field->PositionProfit = pInvestorProductGroupMargin->PositionProfit;
			//折抵总金额
			field->OffsetAmount = pInvestorProductGroupMargin->OffsetAmount;
			//多头折抵总金额
			field->LongOffsetAmount = pInvestorProductGroupMargin->LongOffsetAmount;
			//空头折抵总金额
			field->ShortOffsetAmount = pInvestorProductGroupMargin->ShortOffsetAmount;
			//交易所折抵总金额
			field->ExchOffsetAmount = pInvestorProductGroupMargin->ExchOffsetAmount;
			//交易所多头折抵总金额
			field->LongExchOffsetAmount = pInvestorProductGroupMargin->LongExchOffsetAmount;
			//交易所空头折抵总金额
			field->ShortExchOffsetAmount = pInvestorProductGroupMargin->ShortExchOffsetAmount;
			//投机套保标志
			field->HedgeFlag = (CtpNetHedgeFlagType)pInvestorProductGroupMargin->HedgeFlag;
			//交易所代码
			if (pInvestorProductGroupMargin->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pInvestorProductGroupMargin->ExchangeID);
			}
			//投资单元代码
			if (pInvestorProductGroupMargin->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pInvestorProductGroupMargin->InvestUnitID);
			}
		}
		
		m_pAdapter->OnRspQryInvestorProductGroupMargin(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询交易所保证金率响应
	void CTraderSpi::OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField *pExchangeMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryExchangeMarginRate_delegate == nullptr) return;
		
		CtpNetExchangeMarginRateField^ field = nullptr;
		if (pExchangeMarginRate != nullptr)
		{
			field = gcnew CtpNetExchangeMarginRateField;
			
			//经纪公司代码
			if (pExchangeMarginRate->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pExchangeMarginRate->BrokerID);
			}
			//合约代码
			if (pExchangeMarginRate->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pExchangeMarginRate->InstrumentID);
			}
			//投机套保标志
			field->HedgeFlag = (CtpNetHedgeFlagType)pExchangeMarginRate->HedgeFlag;
			//多头保证金率
			field->LongMarginRatioByMoney = pExchangeMarginRate->LongMarginRatioByMoney;
			//多头保证金费
			field->LongMarginRatioByVolume = pExchangeMarginRate->LongMarginRatioByVolume;
			//空头保证金率
			field->ShortMarginRatioByMoney = pExchangeMarginRate->ShortMarginRatioByMoney;
			//空头保证金费
			field->ShortMarginRatioByVolume = pExchangeMarginRate->ShortMarginRatioByVolume;
			//交易所代码
			if (pExchangeMarginRate->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pExchangeMarginRate->ExchangeID);
			}
		}
		
		m_pAdapter->OnRspQryExchangeMarginRate(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询交易所调整保证金率响应
	void CTraderSpi::OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField *pExchangeMarginRateAdjust, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryExchangeMarginRateAdjust_delegate == nullptr) return;
		
		CtpNetExchangeMarginRateAdjustField^ field = nullptr;
		if (pExchangeMarginRateAdjust != nullptr)
		{
			field = gcnew CtpNetExchangeMarginRateAdjustField;
			
			//经纪公司代码
			if (pExchangeMarginRateAdjust->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pExchangeMarginRateAdjust->BrokerID);
			}
			//合约代码
			if (pExchangeMarginRateAdjust->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pExchangeMarginRateAdjust->InstrumentID);
			}
			//投机套保标志
			field->HedgeFlag = (CtpNetHedgeFlagType)pExchangeMarginRateAdjust->HedgeFlag;
			//跟随交易所投资者多头保证金率
			field->LongMarginRatioByMoney = pExchangeMarginRateAdjust->LongMarginRatioByMoney;
			//跟随交易所投资者多头保证金费
			field->LongMarginRatioByVolume = pExchangeMarginRateAdjust->LongMarginRatioByVolume;
			//跟随交易所投资者空头保证金率
			field->ShortMarginRatioByMoney = pExchangeMarginRateAdjust->ShortMarginRatioByMoney;
			//跟随交易所投资者空头保证金费
			field->ShortMarginRatioByVolume = pExchangeMarginRateAdjust->ShortMarginRatioByVolume;
			//交易所多头保证金率
			field->ExchLongMarginRatioByMoney = pExchangeMarginRateAdjust->ExchLongMarginRatioByMoney;
			//交易所多头保证金费
			field->ExchLongMarginRatioByVolume = pExchangeMarginRateAdjust->ExchLongMarginRatioByVolume;
			//交易所空头保证金率
			field->ExchShortMarginRatioByMoney = pExchangeMarginRateAdjust->ExchShortMarginRatioByMoney;
			//交易所空头保证金费
			field->ExchShortMarginRatioByVolume = pExchangeMarginRateAdjust->ExchShortMarginRatioByVolume;
			//不跟随交易所投资者多头保证金率
			field->NoLongMarginRatioByMoney = pExchangeMarginRateAdjust->NoLongMarginRatioByMoney;
			//不跟随交易所投资者多头保证金费
			field->NoLongMarginRatioByVolume = pExchangeMarginRateAdjust->NoLongMarginRatioByVolume;
			//不跟随交易所投资者空头保证金率
			field->NoShortMarginRatioByMoney = pExchangeMarginRateAdjust->NoShortMarginRatioByMoney;
			//不跟随交易所投资者空头保证金费
			field->NoShortMarginRatioByVolume = pExchangeMarginRateAdjust->NoShortMarginRatioByVolume;
		}
		
		m_pAdapter->OnRspQryExchangeMarginRateAdjust(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询汇率响应
	void CTraderSpi::OnRspQryExchangeRate(CThostFtdcExchangeRateField *pExchangeRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryExchangeRate_delegate == nullptr) return;
		
		CtpNetExchangeRateField^ field = nullptr;
		if (pExchangeRate != nullptr)
		{
			field = gcnew CtpNetExchangeRateField;
			
			//经纪公司代码
			if (pExchangeRate->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pExchangeRate->BrokerID);
			}
			//源币种
			if (pExchangeRate->FromCurrencyID != nullptr)
			{
				field->FromCurrencyID = gcnew String(pExchangeRate->FromCurrencyID);
			}
			//源币种单位数量
			field->FromCurrencyUnit = pExchangeRate->FromCurrencyUnit;
			//目标币种
			if (pExchangeRate->ToCurrencyID != nullptr)
			{
				field->ToCurrencyID = gcnew String(pExchangeRate->ToCurrencyID);
			}
			//汇率
			field->ExchangeRate = pExchangeRate->ExchangeRate;
		}
		
		m_pAdapter->OnRspQryExchangeRate(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询二级代理操作员银期权限响应
	void CTraderSpi::OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField *pSecAgentACIDMap, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQrySecAgentACIDMap_delegate == nullptr) return;
		
		CtpNetSecAgentACIDMapField^ field = nullptr;
		if (pSecAgentACIDMap != nullptr)
		{
			field = gcnew CtpNetSecAgentACIDMapField;
			
			//经纪公司代码
			if (pSecAgentACIDMap->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pSecAgentACIDMap->BrokerID);
			}
			//用户代码
			if (pSecAgentACIDMap->UserID != nullptr)
			{
				field->UserID = gcnew String(pSecAgentACIDMap->UserID);
			}
			//资金账户
			if (pSecAgentACIDMap->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pSecAgentACIDMap->AccountID);
			}
			//币种
			if (pSecAgentACIDMap->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pSecAgentACIDMap->CurrencyID);
			}
			//境外中介机构资金帐号
			if (pSecAgentACIDMap->BrokerSecAgentID != nullptr)
			{
				field->BrokerSecAgentID = gcnew String(pSecAgentACIDMap->BrokerSecAgentID);
			}
		}
		
		m_pAdapter->OnRspQrySecAgentACIDMap(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询产品报价汇率
	void CTraderSpi::OnRspQryProductExchRate(CThostFtdcProductExchRateField *pProductExchRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryProductExchRate_delegate == nullptr) return;
		
		CtpNetProductExchRateField^ field = nullptr;
		if (pProductExchRate != nullptr)
		{
			field = gcnew CtpNetProductExchRateField;
			
			//产品代码
			if (pProductExchRate->ProductID != nullptr)
			{
				field->ProductID = gcnew String(pProductExchRate->ProductID);
			}
			//报价币种类型
			if (pProductExchRate->QuoteCurrencyID != nullptr)
			{
				field->QuoteCurrencyID = gcnew String(pProductExchRate->QuoteCurrencyID);
			}
			//汇率
			field->ExchangeRate = pProductExchRate->ExchangeRate;
			//交易所代码
			if (pProductExchRate->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pProductExchRate->ExchangeID);
			}
		}
		
		m_pAdapter->OnRspQryProductExchRate(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询产品组
	void CTraderSpi::OnRspQryProductGroup(CThostFtdcProductGroupField *pProductGroup, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryProductGroup_delegate == nullptr) return;
		
		CtpNetProductGroupField^ field = nullptr;
		if (pProductGroup != nullptr)
		{
			field = gcnew CtpNetProductGroupField;
			
			//产品代码
			if (pProductGroup->ProductID != nullptr)
			{
				field->ProductID = gcnew String(pProductGroup->ProductID);
			}
			//交易所代码
			if (pProductGroup->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pProductGroup->ExchangeID);
			}
			//产品组代码
			if (pProductGroup->ProductGroupID != nullptr)
			{
				field->ProductGroupID = gcnew String(pProductGroup->ProductGroupID);
			}
		}
		
		m_pAdapter->OnRspQryProductGroup(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询做市商合约手续费率响应
	void CTraderSpi::OnRspQryMMInstrumentCommissionRate(CThostFtdcMMInstrumentCommissionRateField *pMMInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryMMInstrumentCommissionRate_delegate == nullptr) return;
		
		CtpNetMMInstrumentCommissionRateField^ field = nullptr;
		if (pMMInstrumentCommissionRate != nullptr)
		{
			field = gcnew CtpNetMMInstrumentCommissionRateField;
			
			//合约代码
			if (pMMInstrumentCommissionRate->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pMMInstrumentCommissionRate->InstrumentID);
			}
			//投资者范围
			field->InvestorRange = (CtpNetInvestorRangeType)pMMInstrumentCommissionRate->InvestorRange;
			//经纪公司代码
			if (pMMInstrumentCommissionRate->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pMMInstrumentCommissionRate->BrokerID);
			}
			//投资者代码
			if (pMMInstrumentCommissionRate->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pMMInstrumentCommissionRate->InvestorID);
			}
			//开仓手续费率
			field->OpenRatioByMoney = pMMInstrumentCommissionRate->OpenRatioByMoney;
			//开仓手续费
			field->OpenRatioByVolume = pMMInstrumentCommissionRate->OpenRatioByVolume;
			//平仓手续费率
			field->CloseRatioByMoney = pMMInstrumentCommissionRate->CloseRatioByMoney;
			//平仓手续费
			field->CloseRatioByVolume = pMMInstrumentCommissionRate->CloseRatioByVolume;
			//平今手续费率
			field->CloseTodayRatioByMoney = pMMInstrumentCommissionRate->CloseTodayRatioByMoney;
			//平今手续费
			field->CloseTodayRatioByVolume = pMMInstrumentCommissionRate->CloseTodayRatioByVolume;
		}
		
		m_pAdapter->OnRspQryMMInstrumentCommissionRate(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询做市商期权合约手续费响应
	void CTraderSpi::OnRspQryMMOptionInstrCommRate(CThostFtdcMMOptionInstrCommRateField *pMMOptionInstrCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryMMOptionInstrCommRate_delegate == nullptr) return;
		
		CtpNetMMOptionInstrCommRateField^ field = nullptr;
		if (pMMOptionInstrCommRate != nullptr)
		{
			field = gcnew CtpNetMMOptionInstrCommRateField;
			
			//合约代码
			if (pMMOptionInstrCommRate->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pMMOptionInstrCommRate->InstrumentID);
			}
			//投资者范围
			field->InvestorRange = (CtpNetInvestorRangeType)pMMOptionInstrCommRate->InvestorRange;
			//经纪公司代码
			if (pMMOptionInstrCommRate->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pMMOptionInstrCommRate->BrokerID);
			}
			//投资者代码
			if (pMMOptionInstrCommRate->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pMMOptionInstrCommRate->InvestorID);
			}
			//开仓手续费率
			field->OpenRatioByMoney = pMMOptionInstrCommRate->OpenRatioByMoney;
			//开仓手续费
			field->OpenRatioByVolume = pMMOptionInstrCommRate->OpenRatioByVolume;
			//平仓手续费率
			field->CloseRatioByMoney = pMMOptionInstrCommRate->CloseRatioByMoney;
			//平仓手续费
			field->CloseRatioByVolume = pMMOptionInstrCommRate->CloseRatioByVolume;
			//平今手续费率
			field->CloseTodayRatioByMoney = pMMOptionInstrCommRate->CloseTodayRatioByMoney;
			//平今手续费
			field->CloseTodayRatioByVolume = pMMOptionInstrCommRate->CloseTodayRatioByVolume;
			//执行手续费率
			field->StrikeRatioByMoney = pMMOptionInstrCommRate->StrikeRatioByMoney;
			//执行手续费
			field->StrikeRatioByVolume = pMMOptionInstrCommRate->StrikeRatioByVolume;
		}
		
		m_pAdapter->OnRspQryMMOptionInstrCommRate(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询报单手续费响应
	void CTraderSpi::OnRspQryInstrumentOrderCommRate(CThostFtdcInstrumentOrderCommRateField *pInstrumentOrderCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryInstrumentOrderCommRate_delegate == nullptr) return;
		
		CtpNetInstrumentOrderCommRateField^ field = nullptr;
		if (pInstrumentOrderCommRate != nullptr)
		{
			field = gcnew CtpNetInstrumentOrderCommRateField;
			
			//合约代码
			if (pInstrumentOrderCommRate->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pInstrumentOrderCommRate->InstrumentID);
			}
			//投资者范围
			field->InvestorRange = (CtpNetInvestorRangeType)pInstrumentOrderCommRate->InvestorRange;
			//经纪公司代码
			if (pInstrumentOrderCommRate->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pInstrumentOrderCommRate->BrokerID);
			}
			//投资者代码
			if (pInstrumentOrderCommRate->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pInstrumentOrderCommRate->InvestorID);
			}
			//投机套保标志
			field->HedgeFlag = (CtpNetHedgeFlagType)pInstrumentOrderCommRate->HedgeFlag;
			//报单手续费
			field->OrderCommByVolume = pInstrumentOrderCommRate->OrderCommByVolume;
			//撤单手续费
			field->OrderActionCommByVolume = pInstrumentOrderCommRate->OrderActionCommByVolume;
			//交易所代码
			if (pInstrumentOrderCommRate->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pInstrumentOrderCommRate->ExchangeID);
			}
			//投资单元代码
			if (pInstrumentOrderCommRate->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pInstrumentOrderCommRate->InvestUnitID);
			}
		}
		
		m_pAdapter->OnRspQryInstrumentOrderCommRate(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询资金账户响应
	void CTraderSpi::OnRspQrySecAgentTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQrySecAgentTradingAccount_delegate == nullptr) return;
		
		CtpNetTradingAccountField^ field = nullptr;
		if (pTradingAccount != nullptr)
		{
			field = gcnew CtpNetTradingAccountField;
			
			//经纪公司代码
			if (pTradingAccount->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pTradingAccount->BrokerID);
			}
			//投资者帐号
			if (pTradingAccount->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pTradingAccount->AccountID);
			}
			//上次质押金额
			field->PreMortgage = pTradingAccount->PreMortgage;
			//上次信用额度
			field->PreCredit = pTradingAccount->PreCredit;
			//上次存款额
			field->PreDeposit = pTradingAccount->PreDeposit;
			//上次结算准备金
			field->PreBalance = pTradingAccount->PreBalance;
			//上次占用的保证金
			field->PreMargin = pTradingAccount->PreMargin;
			//利息基数
			field->InterestBase = pTradingAccount->InterestBase;
			//利息收入
			field->Interest = pTradingAccount->Interest;
			//入金金额
			field->Deposit = pTradingAccount->Deposit;
			//出金金额
			field->Withdraw = pTradingAccount->Withdraw;
			//冻结的保证金
			field->FrozenMargin = pTradingAccount->FrozenMargin;
			//冻结的资金
			field->FrozenCash = pTradingAccount->FrozenCash;
			//冻结的手续费
			field->FrozenCommission = pTradingAccount->FrozenCommission;
			//当前保证金总额
			field->CurrMargin = pTradingAccount->CurrMargin;
			//资金差额
			field->CashIn = pTradingAccount->CashIn;
			//手续费
			field->Commission = pTradingAccount->Commission;
			//平仓盈亏
			field->CloseProfit = pTradingAccount->CloseProfit;
			//持仓盈亏
			field->PositionProfit = pTradingAccount->PositionProfit;
			//期货结算准备金
			field->Balance = pTradingAccount->Balance;
			//可用资金
			field->Available = pTradingAccount->Available;
			//可取资金
			field->WithdrawQuota = pTradingAccount->WithdrawQuota;
			//基本准备金
			field->Reserve = pTradingAccount->Reserve;
			//交易日
			if (pTradingAccount->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pTradingAccount->TradingDay);
			}
			//结算编号
			field->SettlementID = pTradingAccount->SettlementID;
			//信用额度
			field->Credit = pTradingAccount->Credit;
			//质押金额
			field->Mortgage = pTradingAccount->Mortgage;
			//交易所保证金
			field->ExchangeMargin = pTradingAccount->ExchangeMargin;
			//投资者交割保证金
			field->DeliveryMargin = pTradingAccount->DeliveryMargin;
			//交易所交割保证金
			field->ExchangeDeliveryMargin = pTradingAccount->ExchangeDeliveryMargin;
			//保底期货结算准备金
			field->ReserveBalance = pTradingAccount->ReserveBalance;
			//币种代码
			if (pTradingAccount->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pTradingAccount->CurrencyID);
			}
			//上次货币质入金额
			field->PreFundMortgageIn = pTradingAccount->PreFundMortgageIn;
			//上次货币质出金额
			field->PreFundMortgageOut = pTradingAccount->PreFundMortgageOut;
			//货币质入金额
			field->FundMortgageIn = pTradingAccount->FundMortgageIn;
			//货币质出金额
			field->FundMortgageOut = pTradingAccount->FundMortgageOut;
			//货币质押余额
			field->FundMortgageAvailable = pTradingAccount->FundMortgageAvailable;
			//可质押货币金额
			field->MortgageableFund = pTradingAccount->MortgageableFund;
			//特殊产品占用保证金
			field->SpecProductMargin = pTradingAccount->SpecProductMargin;
			//特殊产品冻结保证金
			field->SpecProductFrozenMargin = pTradingAccount->SpecProductFrozenMargin;
			//特殊产品手续费
			field->SpecProductCommission = pTradingAccount->SpecProductCommission;
			//特殊产品冻结手续费
			field->SpecProductFrozenCommission = pTradingAccount->SpecProductFrozenCommission;
			//特殊产品持仓盈亏
			field->SpecProductPositionProfit = pTradingAccount->SpecProductPositionProfit;
			//特殊产品平仓盈亏
			field->SpecProductCloseProfit = pTradingAccount->SpecProductCloseProfit;
			//根据持仓盈亏算法计算的特殊产品持仓盈亏
			field->SpecProductPositionProfitByAlg = pTradingAccount->SpecProductPositionProfitByAlg;
			//特殊产品交易所保证金
			field->SpecProductExchangeMargin = pTradingAccount->SpecProductExchangeMargin;
			//业务类型
			field->BizType = (CtpNetBizTypeType)pTradingAccount->BizType;
			//延时换汇冻结金额
			field->FrozenSwap = pTradingAccount->FrozenSwap;
			//剩余换汇额度
			field->RemainSwap = pTradingAccount->RemainSwap;
		}
		
		m_pAdapter->OnRspQrySecAgentTradingAccount(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询二级代理商资金校验模式响应
	void CTraderSpi::OnRspQrySecAgentCheckMode(CThostFtdcSecAgentCheckModeField *pSecAgentCheckMode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQrySecAgentCheckMode_delegate == nullptr) return;
		
		CtpNetSecAgentCheckModeField^ field = nullptr;
		if (pSecAgentCheckMode != nullptr)
		{
			field = gcnew CtpNetSecAgentCheckModeField;
			
			//投资者代码
			if (pSecAgentCheckMode->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pSecAgentCheckMode->InvestorID);
			}
			//经纪公司代码
			if (pSecAgentCheckMode->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pSecAgentCheckMode->BrokerID);
			}
			//币种
			if (pSecAgentCheckMode->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pSecAgentCheckMode->CurrencyID);
			}
			//境外中介机构资金帐号
			if (pSecAgentCheckMode->BrokerSecAgentID != nullptr)
			{
				field->BrokerSecAgentID = gcnew String(pSecAgentCheckMode->BrokerSecAgentID);
			}
			//是否需要校验自己的资金账户
			field->CheckSelfAccount = pSecAgentCheckMode->CheckSelfAccount;
		}
		
		m_pAdapter->OnRspQrySecAgentCheckMode(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询期权交易成本响应
	void CTraderSpi::OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField *pOptionInstrTradeCost, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryOptionInstrTradeCost_delegate == nullptr) return;
		
		CtpNetOptionInstrTradeCostField^ field = nullptr;
		if (pOptionInstrTradeCost != nullptr)
		{
			field = gcnew CtpNetOptionInstrTradeCostField;
			
			//经纪公司代码
			if (pOptionInstrTradeCost->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pOptionInstrTradeCost->BrokerID);
			}
			//投资者代码
			if (pOptionInstrTradeCost->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pOptionInstrTradeCost->InvestorID);
			}
			//合约代码
			if (pOptionInstrTradeCost->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pOptionInstrTradeCost->InstrumentID);
			}
			//投机套保标志
			field->HedgeFlag = (CtpNetHedgeFlagType)pOptionInstrTradeCost->HedgeFlag;
			//期权合约保证金不变部分
			field->FixedMargin = pOptionInstrTradeCost->FixedMargin;
			//期权合约最小保证金
			field->MiniMargin = pOptionInstrTradeCost->MiniMargin;
			//期权合约权利金
			field->Royalty = pOptionInstrTradeCost->Royalty;
			//交易所期权合约保证金不变部分
			field->ExchFixedMargin = pOptionInstrTradeCost->ExchFixedMargin;
			//交易所期权合约最小保证金
			field->ExchMiniMargin = pOptionInstrTradeCost->ExchMiniMargin;
			//交易所代码
			if (pOptionInstrTradeCost->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pOptionInstrTradeCost->ExchangeID);
			}
			//投资单元代码
			if (pOptionInstrTradeCost->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pOptionInstrTradeCost->InvestUnitID);
			}
		}
		
		m_pAdapter->OnRspQryOptionInstrTradeCost(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询期权合约手续费响应
	void CTraderSpi::OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField *pOptionInstrCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryOptionInstrCommRate_delegate == nullptr) return;
		
		CtpNetOptionInstrCommRateField^ field = nullptr;
		if (pOptionInstrCommRate != nullptr)
		{
			field = gcnew CtpNetOptionInstrCommRateField;
			
			//合约代码
			if (pOptionInstrCommRate->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pOptionInstrCommRate->InstrumentID);
			}
			//投资者范围
			field->InvestorRange = (CtpNetInvestorRangeType)pOptionInstrCommRate->InvestorRange;
			//经纪公司代码
			if (pOptionInstrCommRate->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pOptionInstrCommRate->BrokerID);
			}
			//投资者代码
			if (pOptionInstrCommRate->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pOptionInstrCommRate->InvestorID);
			}
			//开仓手续费率
			field->OpenRatioByMoney = pOptionInstrCommRate->OpenRatioByMoney;
			//开仓手续费
			field->OpenRatioByVolume = pOptionInstrCommRate->OpenRatioByVolume;
			//平仓手续费率
			field->CloseRatioByMoney = pOptionInstrCommRate->CloseRatioByMoney;
			//平仓手续费
			field->CloseRatioByVolume = pOptionInstrCommRate->CloseRatioByVolume;
			//平今手续费率
			field->CloseTodayRatioByMoney = pOptionInstrCommRate->CloseTodayRatioByMoney;
			//平今手续费
			field->CloseTodayRatioByVolume = pOptionInstrCommRate->CloseTodayRatioByVolume;
			//执行手续费率
			field->StrikeRatioByMoney = pOptionInstrCommRate->StrikeRatioByMoney;
			//执行手续费
			field->StrikeRatioByVolume = pOptionInstrCommRate->StrikeRatioByVolume;
			//交易所代码
			if (pOptionInstrCommRate->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pOptionInstrCommRate->ExchangeID);
			}
			//投资单元代码
			if (pOptionInstrCommRate->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pOptionInstrCommRate->InvestUnitID);
			}
		}
		
		m_pAdapter->OnRspQryOptionInstrCommRate(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询执行宣告响应
	void CTraderSpi::OnRspQryExecOrder(CThostFtdcExecOrderField *pExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryExecOrder_delegate == nullptr) return;
		
		CtpNetExecOrderField^ field = nullptr;
		if (pExecOrder != nullptr)
		{
			field = gcnew CtpNetExecOrderField;
			
			//经纪公司代码
			if (pExecOrder->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pExecOrder->BrokerID);
			}
			//投资者代码
			if (pExecOrder->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pExecOrder->InvestorID);
			}
			//合约代码
			if (pExecOrder->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pExecOrder->InstrumentID);
			}
			//执行宣告引用
			if (pExecOrder->ExecOrderRef != nullptr)
			{
				field->ExecOrderRef = gcnew String(pExecOrder->ExecOrderRef);
			}
			//用户代码
			if (pExecOrder->UserID != nullptr)
			{
				field->UserID = gcnew String(pExecOrder->UserID);
			}
			//数量
			field->Volume = pExecOrder->Volume;
			//请求编号
			field->RequestID = pExecOrder->RequestID;
			//业务单元
			if (pExecOrder->BusinessUnit != nullptr)
			{
				field->BusinessUnit = gcnew String(pExecOrder->BusinessUnit);
			}
			//开平标志
			field->OffsetFlag = (CtpNetOffsetFlagType)pExecOrder->OffsetFlag;
			//投机套保标志
			field->HedgeFlag = (CtpNetHedgeFlagType)pExecOrder->HedgeFlag;
			//执行类型
			field->ActionType = (CtpNetActionTypeType)pExecOrder->ActionType;
			//保留头寸申请的持仓方向
			field->PosiDirection = (CtpNetPosiDirectionType)pExecOrder->PosiDirection;
			//期权行权后是否保留期货头寸的标记,该字段已废弃
			field->ReservePositionFlag = (CtpNetExecOrderPositionFlagType)pExecOrder->ReservePositionFlag;
			//期权行权后生成的头寸是否自动平仓
			field->CloseFlag = (CtpNetExecOrderCloseFlagType)pExecOrder->CloseFlag;
			//本地执行宣告编号
			if (pExecOrder->ExecOrderLocalID != nullptr)
			{
				field->ExecOrderLocalID = gcnew String(pExecOrder->ExecOrderLocalID);
			}
			//交易所代码
			if (pExecOrder->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pExecOrder->ExchangeID);
			}
			//会员代码
			if (pExecOrder->ParticipantID != nullptr)
			{
				field->ParticipantID = gcnew String(pExecOrder->ParticipantID);
			}
			//客户代码
			if (pExecOrder->ClientID != nullptr)
			{
				field->ClientID = gcnew String(pExecOrder->ClientID);
			}
			//合约在交易所的代码
			if (pExecOrder->ExchangeInstID != nullptr)
			{
				field->ExchangeInstID = gcnew String(pExecOrder->ExchangeInstID);
			}
			//交易所交易员代码
			if (pExecOrder->TraderID != nullptr)
			{
				field->TraderID = gcnew String(pExecOrder->TraderID);
			}
			//安装编号
			field->InstallID = pExecOrder->InstallID;
			//执行宣告提交状态
			field->OrderSubmitStatus = (CtpNetOrderSubmitStatusType)pExecOrder->OrderSubmitStatus;
			//报单提示序号
			field->NotifySequence = pExecOrder->NotifySequence;
			//交易日
			if (pExecOrder->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pExecOrder->TradingDay);
			}
			//结算编号
			field->SettlementID = pExecOrder->SettlementID;
			//执行宣告编号
			if (pExecOrder->ExecOrderSysID != nullptr)
			{
				field->ExecOrderSysID = gcnew String(pExecOrder->ExecOrderSysID);
			}
			//报单日期
			if (pExecOrder->InsertDate != nullptr)
			{
				field->InsertDate = gcnew String(pExecOrder->InsertDate);
			}
			//插入时间
			if (pExecOrder->InsertTime != nullptr)
			{
				field->InsertTime = gcnew String(pExecOrder->InsertTime);
			}
			//撤销时间
			if (pExecOrder->CancelTime != nullptr)
			{
				field->CancelTime = gcnew String(pExecOrder->CancelTime);
			}
			//执行结果
			field->ExecResult = (CtpNetExecResultType)pExecOrder->ExecResult;
			//结算会员编号
			if (pExecOrder->ClearingPartID != nullptr)
			{
				field->ClearingPartID = gcnew String(pExecOrder->ClearingPartID);
			}
			//序号
			field->SequenceNo = pExecOrder->SequenceNo;
			//前置编号
			field->FrontID = pExecOrder->FrontID;
			//会话编号
			field->SessionID = pExecOrder->SessionID;
			//用户端产品信息
			if (pExecOrder->UserProductInfo != nullptr)
			{
				field->UserProductInfo = gcnew String(pExecOrder->UserProductInfo);
			}
			//状态信息
			if (pExecOrder->StatusMsg != nullptr)
			{
				field->StatusMsg = gcnew String(pExecOrder->StatusMsg);
			}
			//操作用户代码
			if (pExecOrder->ActiveUserID != nullptr)
			{
				field->ActiveUserID = gcnew String(pExecOrder->ActiveUserID);
			}
			//经纪公司报单编号
			field->BrokerExecOrderSeq = pExecOrder->BrokerExecOrderSeq;
			//营业部编号
			if (pExecOrder->BranchID != nullptr)
			{
				field->BranchID = gcnew String(pExecOrder->BranchID);
			}
			//投资单元代码
			if (pExecOrder->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pExecOrder->InvestUnitID);
			}
			//资金账号
			if (pExecOrder->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pExecOrder->AccountID);
			}
			//币种代码
			if (pExecOrder->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pExecOrder->CurrencyID);
			}
			//IP地址
			if (pExecOrder->IPAddress != nullptr)
			{
				field->IPAddress = gcnew String(pExecOrder->IPAddress);
			}
			//Mac地址
			if (pExecOrder->MacAddress != nullptr)
			{
				field->MacAddress = gcnew String(pExecOrder->MacAddress);
			}
		}
		
		m_pAdapter->OnRspQryExecOrder(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询询价响应
	void CTraderSpi::OnRspQryForQuote(CThostFtdcForQuoteField *pForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryForQuote_delegate == nullptr) return;
		
		CtpNetForQuoteField^ field = nullptr;
		if (pForQuote != nullptr)
		{
			field = gcnew CtpNetForQuoteField;
			
			//经纪公司代码
			if (pForQuote->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pForQuote->BrokerID);
			}
			//投资者代码
			if (pForQuote->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pForQuote->InvestorID);
			}
			//合约代码
			if (pForQuote->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pForQuote->InstrumentID);
			}
			//询价引用
			if (pForQuote->ForQuoteRef != nullptr)
			{
				field->ForQuoteRef = gcnew String(pForQuote->ForQuoteRef);
			}
			//用户代码
			if (pForQuote->UserID != nullptr)
			{
				field->UserID = gcnew String(pForQuote->UserID);
			}
			//本地询价编号
			if (pForQuote->ForQuoteLocalID != nullptr)
			{
				field->ForQuoteLocalID = gcnew String(pForQuote->ForQuoteLocalID);
			}
			//交易所代码
			if (pForQuote->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pForQuote->ExchangeID);
			}
			//会员代码
			if (pForQuote->ParticipantID != nullptr)
			{
				field->ParticipantID = gcnew String(pForQuote->ParticipantID);
			}
			//客户代码
			if (pForQuote->ClientID != nullptr)
			{
				field->ClientID = gcnew String(pForQuote->ClientID);
			}
			//合约在交易所的代码
			if (pForQuote->ExchangeInstID != nullptr)
			{
				field->ExchangeInstID = gcnew String(pForQuote->ExchangeInstID);
			}
			//交易所交易员代码
			if (pForQuote->TraderID != nullptr)
			{
				field->TraderID = gcnew String(pForQuote->TraderID);
			}
			//安装编号
			field->InstallID = pForQuote->InstallID;
			//报单日期
			if (pForQuote->InsertDate != nullptr)
			{
				field->InsertDate = gcnew String(pForQuote->InsertDate);
			}
			//插入时间
			if (pForQuote->InsertTime != nullptr)
			{
				field->InsertTime = gcnew String(pForQuote->InsertTime);
			}
			//询价状态
			field->ForQuoteStatus = (CtpNetForQuoteStatusType)pForQuote->ForQuoteStatus;
			//前置编号
			field->FrontID = pForQuote->FrontID;
			//会话编号
			field->SessionID = pForQuote->SessionID;
			//状态信息
			if (pForQuote->StatusMsg != nullptr)
			{
				field->StatusMsg = gcnew String(pForQuote->StatusMsg);
			}
			//操作用户代码
			if (pForQuote->ActiveUserID != nullptr)
			{
				field->ActiveUserID = gcnew String(pForQuote->ActiveUserID);
			}
			//经纪公司询价编号
			field->BrokerForQutoSeq = pForQuote->BrokerForQutoSeq;
			//投资单元代码
			if (pForQuote->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pForQuote->InvestUnitID);
			}
			//IP地址
			if (pForQuote->IPAddress != nullptr)
			{
				field->IPAddress = gcnew String(pForQuote->IPAddress);
			}
			//Mac地址
			if (pForQuote->MacAddress != nullptr)
			{
				field->MacAddress = gcnew String(pForQuote->MacAddress);
			}
		}
		
		m_pAdapter->OnRspQryForQuote(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询报价响应
	void CTraderSpi::OnRspQryQuote(CThostFtdcQuoteField *pQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryQuote_delegate == nullptr) return;
		
		CtpNetQuoteField^ field = nullptr;
		if (pQuote != nullptr)
		{
			field = gcnew CtpNetQuoteField;
			
			//经纪公司代码
			if (pQuote->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pQuote->BrokerID);
			}
			//投资者代码
			if (pQuote->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pQuote->InvestorID);
			}
			//合约代码
			if (pQuote->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pQuote->InstrumentID);
			}
			//报价引用
			if (pQuote->QuoteRef != nullptr)
			{
				field->QuoteRef = gcnew String(pQuote->QuoteRef);
			}
			//用户代码
			if (pQuote->UserID != nullptr)
			{
				field->UserID = gcnew String(pQuote->UserID);
			}
			//卖价格
			field->AskPrice = pQuote->AskPrice;
			//买价格
			field->BidPrice = pQuote->BidPrice;
			//卖数量
			field->AskVolume = pQuote->AskVolume;
			//买数量
			field->BidVolume = pQuote->BidVolume;
			//请求编号
			field->RequestID = pQuote->RequestID;
			//业务单元
			if (pQuote->BusinessUnit != nullptr)
			{
				field->BusinessUnit = gcnew String(pQuote->BusinessUnit);
			}
			//卖开平标志
			field->AskOffsetFlag = (CtpNetOffsetFlagType)pQuote->AskOffsetFlag;
			//买开平标志
			field->BidOffsetFlag = (CtpNetOffsetFlagType)pQuote->BidOffsetFlag;
			//卖投机套保标志
			field->AskHedgeFlag = (CtpNetHedgeFlagType)pQuote->AskHedgeFlag;
			//买投机套保标志
			field->BidHedgeFlag = (CtpNetHedgeFlagType)pQuote->BidHedgeFlag;
			//本地报价编号
			if (pQuote->QuoteLocalID != nullptr)
			{
				field->QuoteLocalID = gcnew String(pQuote->QuoteLocalID);
			}
			//交易所代码
			if (pQuote->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pQuote->ExchangeID);
			}
			//会员代码
			if (pQuote->ParticipantID != nullptr)
			{
				field->ParticipantID = gcnew String(pQuote->ParticipantID);
			}
			//客户代码
			if (pQuote->ClientID != nullptr)
			{
				field->ClientID = gcnew String(pQuote->ClientID);
			}
			//合约在交易所的代码
			if (pQuote->ExchangeInstID != nullptr)
			{
				field->ExchangeInstID = gcnew String(pQuote->ExchangeInstID);
			}
			//交易所交易员代码
			if (pQuote->TraderID != nullptr)
			{
				field->TraderID = gcnew String(pQuote->TraderID);
			}
			//安装编号
			field->InstallID = pQuote->InstallID;
			//报价提示序号
			field->NotifySequence = pQuote->NotifySequence;
			//报价提交状态
			field->OrderSubmitStatus = (CtpNetOrderSubmitStatusType)pQuote->OrderSubmitStatus;
			//交易日
			if (pQuote->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pQuote->TradingDay);
			}
			//结算编号
			field->SettlementID = pQuote->SettlementID;
			//报价编号
			if (pQuote->QuoteSysID != nullptr)
			{
				field->QuoteSysID = gcnew String(pQuote->QuoteSysID);
			}
			//报单日期
			if (pQuote->InsertDate != nullptr)
			{
				field->InsertDate = gcnew String(pQuote->InsertDate);
			}
			//插入时间
			if (pQuote->InsertTime != nullptr)
			{
				field->InsertTime = gcnew String(pQuote->InsertTime);
			}
			//撤销时间
			if (pQuote->CancelTime != nullptr)
			{
				field->CancelTime = gcnew String(pQuote->CancelTime);
			}
			//报价状态
			field->QuoteStatus = (CtpNetOrderStatusType)pQuote->QuoteStatus;
			//结算会员编号
			if (pQuote->ClearingPartID != nullptr)
			{
				field->ClearingPartID = gcnew String(pQuote->ClearingPartID);
			}
			//序号
			field->SequenceNo = pQuote->SequenceNo;
			//卖方报单编号
			if (pQuote->AskOrderSysID != nullptr)
			{
				field->AskOrderSysID = gcnew String(pQuote->AskOrderSysID);
			}
			//买方报单编号
			if (pQuote->BidOrderSysID != nullptr)
			{
				field->BidOrderSysID = gcnew String(pQuote->BidOrderSysID);
			}
			//前置编号
			field->FrontID = pQuote->FrontID;
			//会话编号
			field->SessionID = pQuote->SessionID;
			//用户端产品信息
			if (pQuote->UserProductInfo != nullptr)
			{
				field->UserProductInfo = gcnew String(pQuote->UserProductInfo);
			}
			//状态信息
			if (pQuote->StatusMsg != nullptr)
			{
				field->StatusMsg = gcnew String(pQuote->StatusMsg);
			}
			//操作用户代码
			if (pQuote->ActiveUserID != nullptr)
			{
				field->ActiveUserID = gcnew String(pQuote->ActiveUserID);
			}
			//经纪公司报价编号
			field->BrokerQuoteSeq = pQuote->BrokerQuoteSeq;
			//衍生卖报单引用
			if (pQuote->AskOrderRef != nullptr)
			{
				field->AskOrderRef = gcnew String(pQuote->AskOrderRef);
			}
			//衍生买报单引用
			if (pQuote->BidOrderRef != nullptr)
			{
				field->BidOrderRef = gcnew String(pQuote->BidOrderRef);
			}
			//应价编号
			if (pQuote->ForQuoteSysID != nullptr)
			{
				field->ForQuoteSysID = gcnew String(pQuote->ForQuoteSysID);
			}
			//营业部编号
			if (pQuote->BranchID != nullptr)
			{
				field->BranchID = gcnew String(pQuote->BranchID);
			}
			//投资单元代码
			if (pQuote->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pQuote->InvestUnitID);
			}
			//资金账号
			if (pQuote->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pQuote->AccountID);
			}
			//币种代码
			if (pQuote->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pQuote->CurrencyID);
			}
			//IP地址
			if (pQuote->IPAddress != nullptr)
			{
				field->IPAddress = gcnew String(pQuote->IPAddress);
			}
			//Mac地址
			if (pQuote->MacAddress != nullptr)
			{
				field->MacAddress = gcnew String(pQuote->MacAddress);
			}
		}
		
		m_pAdapter->OnRspQryQuote(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询期权自对冲响应
	void CTraderSpi::OnRspQryOptionSelfClose(CThostFtdcOptionSelfCloseField *pOptionSelfClose, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryOptionSelfClose_delegate == nullptr) return;
		
		CtpNetOptionSelfCloseField^ field = nullptr;
		if (pOptionSelfClose != nullptr)
		{
			field = gcnew CtpNetOptionSelfCloseField;
			
			//经纪公司代码
			if (pOptionSelfClose->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pOptionSelfClose->BrokerID);
			}
			//投资者代码
			if (pOptionSelfClose->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pOptionSelfClose->InvestorID);
			}
			//合约代码
			if (pOptionSelfClose->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pOptionSelfClose->InstrumentID);
			}
			//期权自对冲引用
			if (pOptionSelfClose->OptionSelfCloseRef != nullptr)
			{
				field->OptionSelfCloseRef = gcnew String(pOptionSelfClose->OptionSelfCloseRef);
			}
			//用户代码
			if (pOptionSelfClose->UserID != nullptr)
			{
				field->UserID = gcnew String(pOptionSelfClose->UserID);
			}
			//数量
			field->Volume = pOptionSelfClose->Volume;
			//请求编号
			field->RequestID = pOptionSelfClose->RequestID;
			//业务单元
			if (pOptionSelfClose->BusinessUnit != nullptr)
			{
				field->BusinessUnit = gcnew String(pOptionSelfClose->BusinessUnit);
			}
			//投机套保标志
			field->HedgeFlag = (CtpNetHedgeFlagType)pOptionSelfClose->HedgeFlag;
			//期权行权的头寸是否自对冲
			field->OptSelfCloseFlag = (CtpNetOptSelfCloseFlagType)pOptionSelfClose->OptSelfCloseFlag;
			//本地期权自对冲编号
			if (pOptionSelfClose->OptionSelfCloseLocalID != nullptr)
			{
				field->OptionSelfCloseLocalID = gcnew String(pOptionSelfClose->OptionSelfCloseLocalID);
			}
			//交易所代码
			if (pOptionSelfClose->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pOptionSelfClose->ExchangeID);
			}
			//会员代码
			if (pOptionSelfClose->ParticipantID != nullptr)
			{
				field->ParticipantID = gcnew String(pOptionSelfClose->ParticipantID);
			}
			//客户代码
			if (pOptionSelfClose->ClientID != nullptr)
			{
				field->ClientID = gcnew String(pOptionSelfClose->ClientID);
			}
			//合约在交易所的代码
			if (pOptionSelfClose->ExchangeInstID != nullptr)
			{
				field->ExchangeInstID = gcnew String(pOptionSelfClose->ExchangeInstID);
			}
			//交易所交易员代码
			if (pOptionSelfClose->TraderID != nullptr)
			{
				field->TraderID = gcnew String(pOptionSelfClose->TraderID);
			}
			//安装编号
			field->InstallID = pOptionSelfClose->InstallID;
			//期权自对冲提交状态
			field->OrderSubmitStatus = (CtpNetOrderSubmitStatusType)pOptionSelfClose->OrderSubmitStatus;
			//报单提示序号
			field->NotifySequence = pOptionSelfClose->NotifySequence;
			//交易日
			if (pOptionSelfClose->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pOptionSelfClose->TradingDay);
			}
			//结算编号
			field->SettlementID = pOptionSelfClose->SettlementID;
			//期权自对冲编号
			if (pOptionSelfClose->OptionSelfCloseSysID != nullptr)
			{
				field->OptionSelfCloseSysID = gcnew String(pOptionSelfClose->OptionSelfCloseSysID);
			}
			//报单日期
			if (pOptionSelfClose->InsertDate != nullptr)
			{
				field->InsertDate = gcnew String(pOptionSelfClose->InsertDate);
			}
			//插入时间
			if (pOptionSelfClose->InsertTime != nullptr)
			{
				field->InsertTime = gcnew String(pOptionSelfClose->InsertTime);
			}
			//撤销时间
			if (pOptionSelfClose->CancelTime != nullptr)
			{
				field->CancelTime = gcnew String(pOptionSelfClose->CancelTime);
			}
			//自对冲结果
			field->ExecResult = (CtpNetExecResultType)pOptionSelfClose->ExecResult;
			//结算会员编号
			if (pOptionSelfClose->ClearingPartID != nullptr)
			{
				field->ClearingPartID = gcnew String(pOptionSelfClose->ClearingPartID);
			}
			//序号
			field->SequenceNo = pOptionSelfClose->SequenceNo;
			//前置编号
			field->FrontID = pOptionSelfClose->FrontID;
			//会话编号
			field->SessionID = pOptionSelfClose->SessionID;
			//用户端产品信息
			if (pOptionSelfClose->UserProductInfo != nullptr)
			{
				field->UserProductInfo = gcnew String(pOptionSelfClose->UserProductInfo);
			}
			//状态信息
			if (pOptionSelfClose->StatusMsg != nullptr)
			{
				field->StatusMsg = gcnew String(pOptionSelfClose->StatusMsg);
			}
			//操作用户代码
			if (pOptionSelfClose->ActiveUserID != nullptr)
			{
				field->ActiveUserID = gcnew String(pOptionSelfClose->ActiveUserID);
			}
			//经纪公司报单编号
			field->BrokerOptionSelfCloseSeq = pOptionSelfClose->BrokerOptionSelfCloseSeq;
			//营业部编号
			if (pOptionSelfClose->BranchID != nullptr)
			{
				field->BranchID = gcnew String(pOptionSelfClose->BranchID);
			}
			//投资单元代码
			if (pOptionSelfClose->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pOptionSelfClose->InvestUnitID);
			}
			//资金账号
			if (pOptionSelfClose->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pOptionSelfClose->AccountID);
			}
			//币种代码
			if (pOptionSelfClose->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pOptionSelfClose->CurrencyID);
			}
			//IP地址
			if (pOptionSelfClose->IPAddress != nullptr)
			{
				field->IPAddress = gcnew String(pOptionSelfClose->IPAddress);
			}
			//Mac地址
			if (pOptionSelfClose->MacAddress != nullptr)
			{
				field->MacAddress = gcnew String(pOptionSelfClose->MacAddress);
			}
		}
		
		m_pAdapter->OnRspQryOptionSelfClose(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询投资单元响应
	void CTraderSpi::OnRspQryInvestUnit(CThostFtdcInvestUnitField *pInvestUnit, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryInvestUnit_delegate == nullptr) return;
		
		CtpNetInvestUnitField^ field = nullptr;
		if (pInvestUnit != nullptr)
		{
			field = gcnew CtpNetInvestUnitField;
			
			//经纪公司代码
			if (pInvestUnit->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pInvestUnit->BrokerID);
			}
			//投资者代码
			if (pInvestUnit->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pInvestUnit->InvestorID);
			}
			//投资单元代码
			if (pInvestUnit->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pInvestUnit->InvestUnitID);
			}
			//投资者单元名称
			if (pInvestUnit->InvestorUnitName != nullptr)
			{
				field->InvestorUnitName = gcnew String(pInvestUnit->InvestorUnitName);
			}
			//投资者分组代码
			if (pInvestUnit->InvestorGroupID != nullptr)
			{
				field->InvestorGroupID = gcnew String(pInvestUnit->InvestorGroupID);
			}
			//手续费率模板代码
			if (pInvestUnit->CommModelID != nullptr)
			{
				field->CommModelID = gcnew String(pInvestUnit->CommModelID);
			}
			//保证金率模板代码
			if (pInvestUnit->MarginModelID != nullptr)
			{
				field->MarginModelID = gcnew String(pInvestUnit->MarginModelID);
			}
			//资金账号
			if (pInvestUnit->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pInvestUnit->AccountID);
			}
			//币种代码
			if (pInvestUnit->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pInvestUnit->CurrencyID);
			}
		}
		
		m_pAdapter->OnRspQryInvestUnit(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询组合合约安全系数响应
	void CTraderSpi::OnRspQryCombInstrumentGuard(CThostFtdcCombInstrumentGuardField *pCombInstrumentGuard, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryCombInstrumentGuard_delegate == nullptr) return;
		
		CtpNetCombInstrumentGuardField^ field = nullptr;
		if (pCombInstrumentGuard != nullptr)
		{
			field = gcnew CtpNetCombInstrumentGuardField;
			
			//经纪公司代码
			if (pCombInstrumentGuard->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pCombInstrumentGuard->BrokerID);
			}
			//合约代码
			if (pCombInstrumentGuard->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pCombInstrumentGuard->InstrumentID);
			}
			//
			field->GuarantRatio = pCombInstrumentGuard->GuarantRatio;
			//交易所代码
			if (pCombInstrumentGuard->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pCombInstrumentGuard->ExchangeID);
			}
		}
		
		m_pAdapter->OnRspQryCombInstrumentGuard(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询申请组合响应
	void CTraderSpi::OnRspQryCombAction(CThostFtdcCombActionField *pCombAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryCombAction_delegate == nullptr) return;
		
		CtpNetCombActionField^ field = nullptr;
		if (pCombAction != nullptr)
		{
			field = gcnew CtpNetCombActionField;
			
			//经纪公司代码
			if (pCombAction->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pCombAction->BrokerID);
			}
			//投资者代码
			if (pCombAction->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pCombAction->InvestorID);
			}
			//合约代码
			if (pCombAction->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pCombAction->InstrumentID);
			}
			//组合引用
			if (pCombAction->CombActionRef != nullptr)
			{
				field->CombActionRef = gcnew String(pCombAction->CombActionRef);
			}
			//用户代码
			if (pCombAction->UserID != nullptr)
			{
				field->UserID = gcnew String(pCombAction->UserID);
			}
			//买卖方向
			field->Direction = (CtpNetDirectionType)pCombAction->Direction;
			//数量
			field->Volume = pCombAction->Volume;
			//组合指令方向
			field->CombDirection = (CtpNetCombDirectionType)pCombAction->CombDirection;
			//投机套保标志
			field->HedgeFlag = (CtpNetHedgeFlagType)pCombAction->HedgeFlag;
			//本地申请组合编号
			if (pCombAction->ActionLocalID != nullptr)
			{
				field->ActionLocalID = gcnew String(pCombAction->ActionLocalID);
			}
			//交易所代码
			if (pCombAction->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pCombAction->ExchangeID);
			}
			//会员代码
			if (pCombAction->ParticipantID != nullptr)
			{
				field->ParticipantID = gcnew String(pCombAction->ParticipantID);
			}
			//客户代码
			if (pCombAction->ClientID != nullptr)
			{
				field->ClientID = gcnew String(pCombAction->ClientID);
			}
			//合约在交易所的代码
			if (pCombAction->ExchangeInstID != nullptr)
			{
				field->ExchangeInstID = gcnew String(pCombAction->ExchangeInstID);
			}
			//交易所交易员代码
			if (pCombAction->TraderID != nullptr)
			{
				field->TraderID = gcnew String(pCombAction->TraderID);
			}
			//安装编号
			field->InstallID = pCombAction->InstallID;
			//组合状态
			field->ActionStatus = (CtpNetOrderActionStatusType)pCombAction->ActionStatus;
			//报单提示序号
			field->NotifySequence = pCombAction->NotifySequence;
			//交易日
			if (pCombAction->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pCombAction->TradingDay);
			}
			//结算编号
			field->SettlementID = pCombAction->SettlementID;
			//序号
			field->SequenceNo = pCombAction->SequenceNo;
			//前置编号
			field->FrontID = pCombAction->FrontID;
			//会话编号
			field->SessionID = pCombAction->SessionID;
			//用户端产品信息
			if (pCombAction->UserProductInfo != nullptr)
			{
				field->UserProductInfo = gcnew String(pCombAction->UserProductInfo);
			}
			//状态信息
			if (pCombAction->StatusMsg != nullptr)
			{
				field->StatusMsg = gcnew String(pCombAction->StatusMsg);
			}
			//IP地址
			if (pCombAction->IPAddress != nullptr)
			{
				field->IPAddress = gcnew String(pCombAction->IPAddress);
			}
			//Mac地址
			if (pCombAction->MacAddress != nullptr)
			{
				field->MacAddress = gcnew String(pCombAction->MacAddress);
			}
			//组合编号
			if (pCombAction->ComTradeID != nullptr)
			{
				field->ComTradeID = gcnew String(pCombAction->ComTradeID);
			}
			//营业部编号
			if (pCombAction->BranchID != nullptr)
			{
				field->BranchID = gcnew String(pCombAction->BranchID);
			}
			//投资单元代码
			if (pCombAction->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pCombAction->InvestUnitID);
			}
		}
		
		m_pAdapter->OnRspQryCombAction(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询转帐流水响应
	void CTraderSpi::OnRspQryTransferSerial(CThostFtdcTransferSerialField *pTransferSerial, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryTransferSerial_delegate == nullptr) return;
		
		CtpNetTransferSerialField^ field = nullptr;
		if (pTransferSerial != nullptr)
		{
			field = gcnew CtpNetTransferSerialField;
			
			//平台流水号
			field->PlateSerial = pTransferSerial->PlateSerial;
			//交易发起方日期
			if (pTransferSerial->TradeDate != nullptr)
			{
				field->TradeDate = gcnew String(pTransferSerial->TradeDate);
			}
			//交易日期
			if (pTransferSerial->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pTransferSerial->TradingDay);
			}
			//交易时间
			if (pTransferSerial->TradeTime != nullptr)
			{
				field->TradeTime = gcnew String(pTransferSerial->TradeTime);
			}
			//交易代码
			if (pTransferSerial->TradeCode != nullptr)
			{
				field->TradeCode = gcnew String(pTransferSerial->TradeCode);
			}
			//会话编号
			field->SessionID = pTransferSerial->SessionID;
			//银行编码
			if (pTransferSerial->BankID != nullptr)
			{
				field->BankID = gcnew String(pTransferSerial->BankID);
			}
			//银行分支机构编码
			if (pTransferSerial->BankBranchID != nullptr)
			{
				field->BankBranchID = gcnew String(pTransferSerial->BankBranchID);
			}
			//银行帐号类型
			field->BankAccType = (CtpNetBankAccTypeType)pTransferSerial->BankAccType;
			//银行帐号
			if (pTransferSerial->BankAccount != nullptr)
			{
				field->BankAccount = gcnew String(pTransferSerial->BankAccount);
			}
			//银行流水号
			if (pTransferSerial->BankSerial != nullptr)
			{
				field->BankSerial = gcnew String(pTransferSerial->BankSerial);
			}
			//期货公司编码
			if (pTransferSerial->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pTransferSerial->BrokerID);
			}
			//期商分支机构代码
			if (pTransferSerial->BrokerBranchID != nullptr)
			{
				field->BrokerBranchID = gcnew String(pTransferSerial->BrokerBranchID);
			}
			//期货公司帐号类型
			field->FutureAccType = (CtpNetFutureAccTypeType)pTransferSerial->FutureAccType;
			//投资者帐号
			if (pTransferSerial->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pTransferSerial->AccountID);
			}
			//投资者代码
			if (pTransferSerial->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pTransferSerial->InvestorID);
			}
			//期货公司流水号
			field->FutureSerial = pTransferSerial->FutureSerial;
			//证件类型
			field->IdCardType = (CtpNetIdCardTypeType)pTransferSerial->IdCardType;
			//证件号码
			if (pTransferSerial->IdentifiedCardNo != nullptr)
			{
				field->IdentifiedCardNo = gcnew String(pTransferSerial->IdentifiedCardNo);
			}
			//币种代码
			if (pTransferSerial->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pTransferSerial->CurrencyID);
			}
			//交易金额
			field->TradeAmount = pTransferSerial->TradeAmount;
			//应收客户费用
			field->CustFee = pTransferSerial->CustFee;
			//应收期货公司费用
			field->BrokerFee = pTransferSerial->BrokerFee;
			//有效标志
			field->AvailabilityFlag = (CtpNetAvailabilityFlagType)pTransferSerial->AvailabilityFlag;
			//操作员
			if (pTransferSerial->OperatorCode != nullptr)
			{
				field->OperatorCode = gcnew String(pTransferSerial->OperatorCode);
			}
			//新银行帐号
			if (pTransferSerial->BankNewAccount != nullptr)
			{
				field->BankNewAccount = gcnew String(pTransferSerial->BankNewAccount);
			}
			//错误代码
			field->ErrorID = pTransferSerial->ErrorID;
			//错误信息
			if (pTransferSerial->ErrorMsg != nullptr)
			{
				field->ErrorMsg = gcnew String(pTransferSerial->ErrorMsg);
			}
		}
		
		m_pAdapter->OnRspQryTransferSerial(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询银期签约关系响应
	void CTraderSpi::OnRspQryAccountregister(CThostFtdcAccountregisterField *pAccountregister, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryAccountregister_delegate == nullptr) return;
		
		CtpNetAccountregisterField^ field = nullptr;
		if (pAccountregister != nullptr)
		{
			field = gcnew CtpNetAccountregisterField;
			
			//交易日期
			if (pAccountregister->TradeDay != nullptr)
			{
				field->TradeDay = gcnew String(pAccountregister->TradeDay);
			}
			//银行编码
			if (pAccountregister->BankID != nullptr)
			{
				field->BankID = gcnew String(pAccountregister->BankID);
			}
			//银行分支机构编码
			if (pAccountregister->BankBranchID != nullptr)
			{
				field->BankBranchID = gcnew String(pAccountregister->BankBranchID);
			}
			//银行帐号
			if (pAccountregister->BankAccount != nullptr)
			{
				field->BankAccount = gcnew String(pAccountregister->BankAccount);
			}
			//期货公司编码
			if (pAccountregister->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pAccountregister->BrokerID);
			}
			//期货公司分支机构编码
			if (pAccountregister->BrokerBranchID != nullptr)
			{
				field->BrokerBranchID = gcnew String(pAccountregister->BrokerBranchID);
			}
			//投资者帐号
			if (pAccountregister->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pAccountregister->AccountID);
			}
			//证件类型
			field->IdCardType = (CtpNetIdCardTypeType)pAccountregister->IdCardType;
			//证件号码
			if (pAccountregister->IdentifiedCardNo != nullptr)
			{
				field->IdentifiedCardNo = gcnew String(pAccountregister->IdentifiedCardNo);
			}
			//客户姓名
			if (pAccountregister->CustomerName != nullptr)
			{
				field->CustomerName = gcnew String(pAccountregister->CustomerName);
			}
			//币种代码
			if (pAccountregister->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pAccountregister->CurrencyID);
			}
			//开销户类别
			field->OpenOrDestroy = (CtpNetOpenOrDestroyType)pAccountregister->OpenOrDestroy;
			//签约日期
			if (pAccountregister->RegDate != nullptr)
			{
				field->RegDate = gcnew String(pAccountregister->RegDate);
			}
			//解约日期
			if (pAccountregister->OutDate != nullptr)
			{
				field->OutDate = gcnew String(pAccountregister->OutDate);
			}
			//交易ID
			field->TID = pAccountregister->TID;
			//客户类型
			field->CustType = (CtpNetCustTypeType)pAccountregister->CustType;
			//银行帐号类型
			field->BankAccType = (CtpNetBankAccTypeType)pAccountregister->BankAccType;
			//长客户姓名
			if (pAccountregister->LongCustomerName != nullptr)
			{
				field->LongCustomerName = gcnew String(pAccountregister->LongCustomerName);
			}
		}
		
		m_pAdapter->OnRspQryAccountregister(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 错误应答
	void CTraderSpi::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspError_delegate == nullptr) return;
		
		m_pAdapter->OnRspError(RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 报单通知
	void CTraderSpi::OnRtnOrder(CThostFtdcOrderField *pOrder)
	{
		if (m_pAdapter->OnRtnOrder_delegate == nullptr) return;
		
		CtpNetOrderField^ field = nullptr;
		if (pOrder != nullptr)
		{
			field = gcnew CtpNetOrderField;
			
			//经纪公司代码
			if (pOrder->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pOrder->BrokerID);
			}
			//投资者代码
			if (pOrder->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pOrder->InvestorID);
			}
			//合约代码
			if (pOrder->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pOrder->InstrumentID);
			}
			//报单引用
			if (pOrder->OrderRef != nullptr)
			{
				field->OrderRef = gcnew String(pOrder->OrderRef);
			}
			//用户代码
			if (pOrder->UserID != nullptr)
			{
				field->UserID = gcnew String(pOrder->UserID);
			}
			//报单价格条件
			field->OrderPriceType = (CtpNetOrderPriceTypeType)pOrder->OrderPriceType;
			//买卖方向
			field->Direction = (CtpNetDirectionType)pOrder->Direction;
			//组合开平标志1
			field->CombOffsetFlag1 = (CtpNetOffsetFlagType)pOrder->CombOffsetFlag[0];
			//组合开平标志2
			field->CombOffsetFlag2 = (CtpNetOffsetFlagType)pOrder->CombOffsetFlag[1];
			//组合开平标志3
			field->CombOffsetFlag3 = (CtpNetOffsetFlagType)pOrder->CombOffsetFlag[2];
			//组合开平标志4
			field->CombOffsetFlag4 = (CtpNetOffsetFlagType)pOrder->CombOffsetFlag[3];
			//组合开平标志5
			field->CombOffsetFlag5 = (CtpNetOffsetFlagType)pOrder->CombOffsetFlag[4];
			//组合投机套保标志1
			field->CombHedgeFlag1 = (CtpNetHedgeFlagType)pOrder->CombHedgeFlag[0];
			//组合投机套保标志2
			field->CombHedgeFlag2 = (CtpNetHedgeFlagType)pOrder->CombHedgeFlag[1];
			//组合投机套保标志3
			field->CombHedgeFlag3 = (CtpNetHedgeFlagType)pOrder->CombHedgeFlag[2];
			//组合投机套保标志4
			field->CombHedgeFlag4 = (CtpNetHedgeFlagType)pOrder->CombHedgeFlag[3];
			//组合投机套保标志5
			field->CombHedgeFlag5 = (CtpNetHedgeFlagType)pOrder->CombHedgeFlag[4];
			//价格
			field->LimitPrice = pOrder->LimitPrice;
			//数量
			field->VolumeTotalOriginal = pOrder->VolumeTotalOriginal;
			//有效期类型
			field->TimeCondition = (CtpNetTimeConditionType)pOrder->TimeCondition;
			//GTD日期
			if (pOrder->GTDDate != nullptr)
			{
				field->GTDDate = gcnew String(pOrder->GTDDate);
			}
			//成交量类型
			field->VolumeCondition = (CtpNetVolumeConditionType)pOrder->VolumeCondition;
			//最小成交量
			field->MinVolume = pOrder->MinVolume;
			//触发条件
			field->ContingentCondition = (CtpNetContingentConditionType)pOrder->ContingentCondition;
			//止损价
			field->StopPrice = pOrder->StopPrice;
			//强平原因
			field->ForceCloseReason = (CtpNetForceCloseReasonType)pOrder->ForceCloseReason;
			//自动挂起标志
			field->IsAutoSuspend = pOrder->IsAutoSuspend;
			//业务单元
			if (pOrder->BusinessUnit != nullptr)
			{
				field->BusinessUnit = gcnew String(pOrder->BusinessUnit);
			}
			//请求编号
			field->RequestID = pOrder->RequestID;
			//本地报单编号
			if (pOrder->OrderLocalID != nullptr)
			{
				field->OrderLocalID = gcnew String(pOrder->OrderLocalID);
			}
			//交易所代码
			if (pOrder->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pOrder->ExchangeID);
			}
			//会员代码
			if (pOrder->ParticipantID != nullptr)
			{
				field->ParticipantID = gcnew String(pOrder->ParticipantID);
			}
			//客户代码
			if (pOrder->ClientID != nullptr)
			{
				field->ClientID = gcnew String(pOrder->ClientID);
			}
			//合约在交易所的代码
			if (pOrder->ExchangeInstID != nullptr)
			{
				field->ExchangeInstID = gcnew String(pOrder->ExchangeInstID);
			}
			//交易所交易员代码
			if (pOrder->TraderID != nullptr)
			{
				field->TraderID = gcnew String(pOrder->TraderID);
			}
			//安装编号
			field->InstallID = pOrder->InstallID;
			//报单提交状态
			field->OrderSubmitStatus = (CtpNetOrderSubmitStatusType)pOrder->OrderSubmitStatus;
			//报单提示序号
			field->NotifySequence = pOrder->NotifySequence;
			//交易日
			if (pOrder->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pOrder->TradingDay);
			}
			//结算编号
			field->SettlementID = pOrder->SettlementID;
			//报单编号
			if (pOrder->OrderSysID != nullptr)
			{
				field->OrderSysID = gcnew String(pOrder->OrderSysID);
			}
			//报单来源
			field->OrderSource = (CtpNetOrderSourceType)pOrder->OrderSource;
			//报单状态
			field->OrderStatus = (CtpNetOrderStatusType)pOrder->OrderStatus;
			//报单类型
			field->OrderType = (CtpNetOrderTypeType)pOrder->OrderType;
			//今成交数量
			field->VolumeTraded = pOrder->VolumeTraded;
			//剩余数量
			field->VolumeTotal = pOrder->VolumeTotal;
			//报单日期
			if (pOrder->InsertDate != nullptr)
			{
				field->InsertDate = gcnew String(pOrder->InsertDate);
			}
			//委托时间
			if (pOrder->InsertTime != nullptr)
			{
				field->InsertTime = gcnew String(pOrder->InsertTime);
			}
			//激活时间
			if (pOrder->ActiveTime != nullptr)
			{
				field->ActiveTime = gcnew String(pOrder->ActiveTime);
			}
			//挂起时间
			if (pOrder->SuspendTime != nullptr)
			{
				field->SuspendTime = gcnew String(pOrder->SuspendTime);
			}
			//最后修改时间
			if (pOrder->UpdateTime != nullptr)
			{
				field->UpdateTime = gcnew String(pOrder->UpdateTime);
			}
			//撤销时间
			if (pOrder->CancelTime != nullptr)
			{
				field->CancelTime = gcnew String(pOrder->CancelTime);
			}
			//最后修改交易所交易员代码
			if (pOrder->ActiveTraderID != nullptr)
			{
				field->ActiveTraderID = gcnew String(pOrder->ActiveTraderID);
			}
			//结算会员编号
			if (pOrder->ClearingPartID != nullptr)
			{
				field->ClearingPartID = gcnew String(pOrder->ClearingPartID);
			}
			//序号
			field->SequenceNo = pOrder->SequenceNo;
			//前置编号
			field->FrontID = pOrder->FrontID;
			//会话编号
			field->SessionID = pOrder->SessionID;
			//用户端产品信息
			if (pOrder->UserProductInfo != nullptr)
			{
				field->UserProductInfo = gcnew String(pOrder->UserProductInfo);
			}
			//状态信息
			if (pOrder->StatusMsg != nullptr)
			{
				field->StatusMsg = gcnew String(pOrder->StatusMsg);
			}
			//用户强评标志
			field->UserForceClose = pOrder->UserForceClose;
			//操作用户代码
			if (pOrder->ActiveUserID != nullptr)
			{
				field->ActiveUserID = gcnew String(pOrder->ActiveUserID);
			}
			//经纪公司报单编号
			field->BrokerOrderSeq = pOrder->BrokerOrderSeq;
			//相关报单
			if (pOrder->RelativeOrderSysID != nullptr)
			{
				field->RelativeOrderSysID = gcnew String(pOrder->RelativeOrderSysID);
			}
			//郑商所成交数量
			field->ZCETotalTradedVolume = pOrder->ZCETotalTradedVolume;
			//互换单标志
			field->IsSwapOrder = pOrder->IsSwapOrder;
			//营业部编号
			if (pOrder->BranchID != nullptr)
			{
				field->BranchID = gcnew String(pOrder->BranchID);
			}
			//投资单元代码
			if (pOrder->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pOrder->InvestUnitID);
			}
			//资金账号
			if (pOrder->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pOrder->AccountID);
			}
			//币种代码
			if (pOrder->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pOrder->CurrencyID);
			}
			//IP地址
			if (pOrder->IPAddress != nullptr)
			{
				field->IPAddress = gcnew String(pOrder->IPAddress);
			}
			//Mac地址
			if (pOrder->MacAddress != nullptr)
			{
				field->MacAddress = gcnew String(pOrder->MacAddress);
			}
		}
		
		m_pAdapter->OnRtnOrder(field);
	};

	// 成交通知
	void CTraderSpi::OnRtnTrade(CThostFtdcTradeField *pTrade)
	{
		if (m_pAdapter->OnRtnTrade_delegate == nullptr) return;
		
		CtpNetTradeField^ field = nullptr;
		if (pTrade != nullptr)
		{
			field = gcnew CtpNetTradeField;
			
			//经纪公司代码
			if (pTrade->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pTrade->BrokerID);
			}
			//投资者代码
			if (pTrade->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pTrade->InvestorID);
			}
			//合约代码
			if (pTrade->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pTrade->InstrumentID);
			}
			//报单引用
			if (pTrade->OrderRef != nullptr)
			{
				field->OrderRef = gcnew String(pTrade->OrderRef);
			}
			//用户代码
			if (pTrade->UserID != nullptr)
			{
				field->UserID = gcnew String(pTrade->UserID);
			}
			//交易所代码
			if (pTrade->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pTrade->ExchangeID);
			}
			//成交编号
			if (pTrade->TradeID != nullptr)
			{
				field->TradeID = gcnew String(pTrade->TradeID);
			}
			//买卖方向
			field->Direction = (CtpNetDirectionType)pTrade->Direction;
			//报单编号
			if (pTrade->OrderSysID != nullptr)
			{
				field->OrderSysID = gcnew String(pTrade->OrderSysID);
			}
			//会员代码
			if (pTrade->ParticipantID != nullptr)
			{
				field->ParticipantID = gcnew String(pTrade->ParticipantID);
			}
			//客户代码
			if (pTrade->ClientID != nullptr)
			{
				field->ClientID = gcnew String(pTrade->ClientID);
			}
			//交易角色
			field->TradingRole = (CtpNetTradingRoleType)pTrade->TradingRole;
			//合约在交易所的代码
			if (pTrade->ExchangeInstID != nullptr)
			{
				field->ExchangeInstID = gcnew String(pTrade->ExchangeInstID);
			}
			//开平标志
			field->OffsetFlag = (CtpNetOffsetFlagType)pTrade->OffsetFlag;
			//投机套保标志
			field->HedgeFlag = (CtpNetHedgeFlagType)pTrade->HedgeFlag;
			//价格
			field->Price = pTrade->Price;
			//数量
			field->Volume = pTrade->Volume;
			//成交时期
			if (pTrade->TradeDate != nullptr)
			{
				field->TradeDate = gcnew String(pTrade->TradeDate);
			}
			//成交时间
			if (pTrade->TradeTime != nullptr)
			{
				field->TradeTime = gcnew String(pTrade->TradeTime);
			}
			//成交类型
			field->TradeType = (CtpNetTradeTypeType)pTrade->TradeType;
			//成交价来源
			field->PriceSource = (CtpNetPriceSourceType)pTrade->PriceSource;
			//交易所交易员代码
			if (pTrade->TraderID != nullptr)
			{
				field->TraderID = gcnew String(pTrade->TraderID);
			}
			//本地报单编号
			if (pTrade->OrderLocalID != nullptr)
			{
				field->OrderLocalID = gcnew String(pTrade->OrderLocalID);
			}
			//结算会员编号
			if (pTrade->ClearingPartID != nullptr)
			{
				field->ClearingPartID = gcnew String(pTrade->ClearingPartID);
			}
			//业务单元
			if (pTrade->BusinessUnit != nullptr)
			{
				field->BusinessUnit = gcnew String(pTrade->BusinessUnit);
			}
			//序号
			field->SequenceNo = pTrade->SequenceNo;
			//交易日
			if (pTrade->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pTrade->TradingDay);
			}
			//结算编号
			field->SettlementID = pTrade->SettlementID;
			//经纪公司报单编号
			field->BrokerOrderSeq = pTrade->BrokerOrderSeq;
			//成交来源
			field->TradeSource = (CtpNetTradeSourceType)pTrade->TradeSource;
			//投资单元代码
			if (pTrade->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pTrade->InvestUnitID);
			}
		}
		
		m_pAdapter->OnRtnTrade(field);
	};

	// 报单录入错误回报
	void CTraderSpi::OnErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo)
	{
		if (m_pAdapter->OnErrRtnOrderInsert_delegate == nullptr) return;
		
		CtpNetInputOrderField^ field = nullptr;
		if (pInputOrder != nullptr)
		{
			field = gcnew CtpNetInputOrderField;
			
			//经纪公司代码
			if (pInputOrder->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pInputOrder->BrokerID);
			}
			//投资者代码
			if (pInputOrder->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pInputOrder->InvestorID);
			}
			//合约代码
			if (pInputOrder->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pInputOrder->InstrumentID);
			}
			//报单引用
			if (pInputOrder->OrderRef != nullptr)
			{
				field->OrderRef = gcnew String(pInputOrder->OrderRef);
			}
			//用户代码
			if (pInputOrder->UserID != nullptr)
			{
				field->UserID = gcnew String(pInputOrder->UserID);
			}
			//报单价格条件
			field->OrderPriceType = (CtpNetOrderPriceTypeType)pInputOrder->OrderPriceType;
			//买卖方向
			field->Direction = (CtpNetDirectionType)pInputOrder->Direction;
			//组合开平标志1
			field->CombOffsetFlag1 = (CtpNetOffsetFlagType)pInputOrder->CombOffsetFlag[0];
			//组合开平标志2
			field->CombOffsetFlag2 = (CtpNetOffsetFlagType)pInputOrder->CombOffsetFlag[1];
			//组合开平标志3
			field->CombOffsetFlag3 = (CtpNetOffsetFlagType)pInputOrder->CombOffsetFlag[2];
			//组合开平标志4
			field->CombOffsetFlag4 = (CtpNetOffsetFlagType)pInputOrder->CombOffsetFlag[3];
			//组合开平标志5
			field->CombOffsetFlag5 = (CtpNetOffsetFlagType)pInputOrder->CombOffsetFlag[4];
			//组合投机套保标志1
			field->CombHedgeFlag1 = (CtpNetHedgeFlagType)pInputOrder->CombHedgeFlag[0];
			//组合投机套保标志2
			field->CombHedgeFlag2 = (CtpNetHedgeFlagType)pInputOrder->CombHedgeFlag[1];
			//组合投机套保标志3
			field->CombHedgeFlag3 = (CtpNetHedgeFlagType)pInputOrder->CombHedgeFlag[2];
			//组合投机套保标志4
			field->CombHedgeFlag4 = (CtpNetHedgeFlagType)pInputOrder->CombHedgeFlag[3];
			//组合投机套保标志5
			field->CombHedgeFlag5 = (CtpNetHedgeFlagType)pInputOrder->CombHedgeFlag[4];
			//价格
			field->LimitPrice = pInputOrder->LimitPrice;
			//数量
			field->VolumeTotalOriginal = pInputOrder->VolumeTotalOriginal;
			//有效期类型
			field->TimeCondition = (CtpNetTimeConditionType)pInputOrder->TimeCondition;
			//GTD日期
			if (pInputOrder->GTDDate != nullptr)
			{
				field->GTDDate = gcnew String(pInputOrder->GTDDate);
			}
			//成交量类型
			field->VolumeCondition = (CtpNetVolumeConditionType)pInputOrder->VolumeCondition;
			//最小成交量
			field->MinVolume = pInputOrder->MinVolume;
			//触发条件
			field->ContingentCondition = (CtpNetContingentConditionType)pInputOrder->ContingentCondition;
			//止损价
			field->StopPrice = pInputOrder->StopPrice;
			//强平原因
			field->ForceCloseReason = (CtpNetForceCloseReasonType)pInputOrder->ForceCloseReason;
			//自动挂起标志
			field->IsAutoSuspend = pInputOrder->IsAutoSuspend;
			//业务单元
			if (pInputOrder->BusinessUnit != nullptr)
			{
				field->BusinessUnit = gcnew String(pInputOrder->BusinessUnit);
			}
			//请求编号
			field->RequestID = pInputOrder->RequestID;
			//用户强评标志
			field->UserForceClose = pInputOrder->UserForceClose;
			//互换单标志
			field->IsSwapOrder = pInputOrder->IsSwapOrder;
			//交易所代码
			if (pInputOrder->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pInputOrder->ExchangeID);
			}
			//投资单元代码
			if (pInputOrder->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pInputOrder->InvestUnitID);
			}
			//资金账号
			if (pInputOrder->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pInputOrder->AccountID);
			}
			//币种代码
			if (pInputOrder->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pInputOrder->CurrencyID);
			}
			//交易编码
			if (pInputOrder->ClientID != nullptr)
			{
				field->ClientID = gcnew String(pInputOrder->ClientID);
			}
			//IP地址
			if (pInputOrder->IPAddress != nullptr)
			{
				field->IPAddress = gcnew String(pInputOrder->IPAddress);
			}
			//Mac地址
			if (pInputOrder->MacAddress != nullptr)
			{
				field->MacAddress = gcnew String(pInputOrder->MacAddress);
			}
		}
		
		m_pAdapter->OnErrRtnOrderInsert(field, RspInfoField(pRspInfo));
	};

	// 报单操作错误回报
	void CTraderSpi::OnErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo)
	{
		if (m_pAdapter->OnErrRtnOrderAction_delegate == nullptr) return;
		
		CtpNetOrderActionField^ field = nullptr;
		if (pOrderAction != nullptr)
		{
			field = gcnew CtpNetOrderActionField;
			
			//经纪公司代码
			if (pOrderAction->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pOrderAction->BrokerID);
			}
			//投资者代码
			if (pOrderAction->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pOrderAction->InvestorID);
			}
			//报单操作引用
			field->OrderActionRef = pOrderAction->OrderActionRef;
			//报单引用
			if (pOrderAction->OrderRef != nullptr)
			{
				field->OrderRef = gcnew String(pOrderAction->OrderRef);
			}
			//请求编号
			field->RequestID = pOrderAction->RequestID;
			//前置编号
			field->FrontID = pOrderAction->FrontID;
			//会话编号
			field->SessionID = pOrderAction->SessionID;
			//交易所代码
			if (pOrderAction->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pOrderAction->ExchangeID);
			}
			//报单编号
			if (pOrderAction->OrderSysID != nullptr)
			{
				field->OrderSysID = gcnew String(pOrderAction->OrderSysID);
			}
			//操作标志
			field->ActionFlag = (CtpNetActionFlagType)pOrderAction->ActionFlag;
			//价格
			field->LimitPrice = pOrderAction->LimitPrice;
			//数量变化
			field->VolumeChange = pOrderAction->VolumeChange;
			//操作日期
			if (pOrderAction->ActionDate != nullptr)
			{
				field->ActionDate = gcnew String(pOrderAction->ActionDate);
			}
			//操作时间
			if (pOrderAction->ActionTime != nullptr)
			{
				field->ActionTime = gcnew String(pOrderAction->ActionTime);
			}
			//交易所交易员代码
			if (pOrderAction->TraderID != nullptr)
			{
				field->TraderID = gcnew String(pOrderAction->TraderID);
			}
			//安装编号
			field->InstallID = pOrderAction->InstallID;
			//本地报单编号
			if (pOrderAction->OrderLocalID != nullptr)
			{
				field->OrderLocalID = gcnew String(pOrderAction->OrderLocalID);
			}
			//操作本地编号
			if (pOrderAction->ActionLocalID != nullptr)
			{
				field->ActionLocalID = gcnew String(pOrderAction->ActionLocalID);
			}
			//会员代码
			if (pOrderAction->ParticipantID != nullptr)
			{
				field->ParticipantID = gcnew String(pOrderAction->ParticipantID);
			}
			//客户代码
			if (pOrderAction->ClientID != nullptr)
			{
				field->ClientID = gcnew String(pOrderAction->ClientID);
			}
			//业务单元
			if (pOrderAction->BusinessUnit != nullptr)
			{
				field->BusinessUnit = gcnew String(pOrderAction->BusinessUnit);
			}
			//报单操作状态
			field->OrderActionStatus = (CtpNetOrderActionStatusType)pOrderAction->OrderActionStatus;
			//用户代码
			if (pOrderAction->UserID != nullptr)
			{
				field->UserID = gcnew String(pOrderAction->UserID);
			}
			//状态信息
			if (pOrderAction->StatusMsg != nullptr)
			{
				field->StatusMsg = gcnew String(pOrderAction->StatusMsg);
			}
			//合约代码
			if (pOrderAction->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pOrderAction->InstrumentID);
			}
			//营业部编号
			if (pOrderAction->BranchID != nullptr)
			{
				field->BranchID = gcnew String(pOrderAction->BranchID);
			}
			//投资单元代码
			if (pOrderAction->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pOrderAction->InvestUnitID);
			}
			//IP地址
			if (pOrderAction->IPAddress != nullptr)
			{
				field->IPAddress = gcnew String(pOrderAction->IPAddress);
			}
			//Mac地址
			if (pOrderAction->MacAddress != nullptr)
			{
				field->MacAddress = gcnew String(pOrderAction->MacAddress);
			}
		}
		
		m_pAdapter->OnErrRtnOrderAction(field, RspInfoField(pRspInfo));
	};

	// 合约交易状态通知
	void CTraderSpi::OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField *pInstrumentStatus)
	{
		if (m_pAdapter->OnRtnInstrumentStatus_delegate == nullptr) return;
		
		CtpNetInstrumentStatusField^ field = nullptr;
		if (pInstrumentStatus != nullptr)
		{
			field = gcnew CtpNetInstrumentStatusField;
			
			//交易所代码
			if (pInstrumentStatus->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pInstrumentStatus->ExchangeID);
			}
			//合约在交易所的代码
			if (pInstrumentStatus->ExchangeInstID != nullptr)
			{
				field->ExchangeInstID = gcnew String(pInstrumentStatus->ExchangeInstID);
			}
			//结算组代码
			if (pInstrumentStatus->SettlementGroupID != nullptr)
			{
				field->SettlementGroupID = gcnew String(pInstrumentStatus->SettlementGroupID);
			}
			//合约代码
			if (pInstrumentStatus->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pInstrumentStatus->InstrumentID);
			}
			//合约交易状态
			field->InstrumentStatus = (CtpNetInstrumentStatusType)pInstrumentStatus->InstrumentStatus;
			//交易阶段编号
			field->TradingSegmentSN = pInstrumentStatus->TradingSegmentSN;
			//进入本状态时间
			if (pInstrumentStatus->EnterTime != nullptr)
			{
				field->EnterTime = gcnew String(pInstrumentStatus->EnterTime);
			}
			//进入本状态原因
			field->EnterReason = (CtpNetInstStatusEnterReasonType)pInstrumentStatus->EnterReason;
		}
		
		m_pAdapter->OnRtnInstrumentStatus(field);
	};

	// 交易所公告通知
	void CTraderSpi::OnRtnBulletin(CThostFtdcBulletinField *pBulletin)
	{
		if (m_pAdapter->OnRtnBulletin_delegate == nullptr) return;
		
		CtpNetBulletinField^ field = nullptr;
		if (pBulletin != nullptr)
		{
			field = gcnew CtpNetBulletinField;
			
			//交易所代码
			if (pBulletin->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pBulletin->ExchangeID);
			}
			//交易日
			if (pBulletin->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pBulletin->TradingDay);
			}
			//公告编号
			field->BulletinID = pBulletin->BulletinID;
			//序列号
			field->SequenceNo = pBulletin->SequenceNo;
			//公告类型
			if (pBulletin->NewsType != nullptr)
			{
				field->NewsType = gcnew String(pBulletin->NewsType);
			}
			//紧急程度
			field->NewsUrgency = (Byte)pBulletin->NewsUrgency;
			//发送时间
			if (pBulletin->SendTime != nullptr)
			{
				field->SendTime = gcnew String(pBulletin->SendTime);
			}
			//消息摘要
			if (pBulletin->Abstract != nullptr)
			{
				field->Abstract = gcnew String(pBulletin->Abstract);
			}
			//消息来源
			if (pBulletin->ComeFrom != nullptr)
			{
				field->ComeFrom = gcnew String(pBulletin->ComeFrom);
			}
			//消息正文
			if (pBulletin->Content != nullptr)
			{
				field->Content = gcnew String(pBulletin->Content);
			}
			//WEB地址
			if (pBulletin->URLLink != nullptr)
			{
				field->URLLink = gcnew String(pBulletin->URLLink);
			}
			//市场代码
			if (pBulletin->MarketID != nullptr)
			{
				field->MarketID = gcnew String(pBulletin->MarketID);
			}
		}
		
		m_pAdapter->OnRtnBulletin(field);
	};

	// 交易通知
	void CTraderSpi::OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField *pTradingNoticeInfo)
	{
		if (m_pAdapter->OnRtnTradingNotice_delegate == nullptr) return;
		
		CtpNetTradingNoticeInfoField^ field = nullptr;
		if (pTradingNoticeInfo != nullptr)
		{
			field = gcnew CtpNetTradingNoticeInfoField;
			
			//经纪公司代码
			if (pTradingNoticeInfo->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pTradingNoticeInfo->BrokerID);
			}
			//投资者代码
			if (pTradingNoticeInfo->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pTradingNoticeInfo->InvestorID);
			}
			//发送时间
			if (pTradingNoticeInfo->SendTime != nullptr)
			{
				field->SendTime = gcnew String(pTradingNoticeInfo->SendTime);
			}
			//消息正文
			if (pTradingNoticeInfo->FieldContent != nullptr)
			{
				field->FieldContent = gcnew String(pTradingNoticeInfo->FieldContent);
			}
			//序列系列号
			field->SequenceSeries = pTradingNoticeInfo->SequenceSeries;
			//序列号
			field->SequenceNo = pTradingNoticeInfo->SequenceNo;
			//投资单元代码
			if (pTradingNoticeInfo->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pTradingNoticeInfo->InvestUnitID);
			}
		}
		
		m_pAdapter->OnRtnTradingNotice(field);
	};

	// 提示条件单校验错误
	void CTraderSpi::OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField *pErrorConditionalOrder)
	{
		if (m_pAdapter->OnRtnErrorConditionalOrder_delegate == nullptr) return;
		
		CtpNetErrorConditionalOrderField^ field = nullptr;
		if (pErrorConditionalOrder != nullptr)
		{
			field = gcnew CtpNetErrorConditionalOrderField;
			
			//经纪公司代码
			if (pErrorConditionalOrder->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pErrorConditionalOrder->BrokerID);
			}
			//投资者代码
			if (pErrorConditionalOrder->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pErrorConditionalOrder->InvestorID);
			}
			//合约代码
			if (pErrorConditionalOrder->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pErrorConditionalOrder->InstrumentID);
			}
			//报单引用
			if (pErrorConditionalOrder->OrderRef != nullptr)
			{
				field->OrderRef = gcnew String(pErrorConditionalOrder->OrderRef);
			}
			//用户代码
			if (pErrorConditionalOrder->UserID != nullptr)
			{
				field->UserID = gcnew String(pErrorConditionalOrder->UserID);
			}
			//报单价格条件
			field->OrderPriceType = (CtpNetOrderPriceTypeType)pErrorConditionalOrder->OrderPriceType;
			//买卖方向
			field->Direction = (CtpNetDirectionType)pErrorConditionalOrder->Direction;
			//组合开平标志1
			field->CombOffsetFlag1 = (CtpNetOffsetFlagType)pErrorConditionalOrder->CombOffsetFlag[0];
			//组合开平标志2
			field->CombOffsetFlag2 = (CtpNetOffsetFlagType)pErrorConditionalOrder->CombOffsetFlag[1];
			//组合开平标志3
			field->CombOffsetFlag3 = (CtpNetOffsetFlagType)pErrorConditionalOrder->CombOffsetFlag[2];
			//组合开平标志4
			field->CombOffsetFlag4 = (CtpNetOffsetFlagType)pErrorConditionalOrder->CombOffsetFlag[3];
			//组合开平标志5
			field->CombOffsetFlag5 = (CtpNetOffsetFlagType)pErrorConditionalOrder->CombOffsetFlag[4];
			//组合投机套保标志1
			field->CombHedgeFlag1 = (CtpNetHedgeFlagType)pErrorConditionalOrder->CombHedgeFlag[0];
			//组合投机套保标志2
			field->CombHedgeFlag2 = (CtpNetHedgeFlagType)pErrorConditionalOrder->CombHedgeFlag[1];
			//组合投机套保标志3
			field->CombHedgeFlag3 = (CtpNetHedgeFlagType)pErrorConditionalOrder->CombHedgeFlag[2];
			//组合投机套保标志4
			field->CombHedgeFlag4 = (CtpNetHedgeFlagType)pErrorConditionalOrder->CombHedgeFlag[3];
			//组合投机套保标志5
			field->CombHedgeFlag5 = (CtpNetHedgeFlagType)pErrorConditionalOrder->CombHedgeFlag[4];
			//价格
			field->LimitPrice = pErrorConditionalOrder->LimitPrice;
			//数量
			field->VolumeTotalOriginal = pErrorConditionalOrder->VolumeTotalOriginal;
			//有效期类型
			field->TimeCondition = (CtpNetTimeConditionType)pErrorConditionalOrder->TimeCondition;
			//GTD日期
			if (pErrorConditionalOrder->GTDDate != nullptr)
			{
				field->GTDDate = gcnew String(pErrorConditionalOrder->GTDDate);
			}
			//成交量类型
			field->VolumeCondition = (CtpNetVolumeConditionType)pErrorConditionalOrder->VolumeCondition;
			//最小成交量
			field->MinVolume = pErrorConditionalOrder->MinVolume;
			//触发条件
			field->ContingentCondition = (CtpNetContingentConditionType)pErrorConditionalOrder->ContingentCondition;
			//止损价
			field->StopPrice = pErrorConditionalOrder->StopPrice;
			//强平原因
			field->ForceCloseReason = (CtpNetForceCloseReasonType)pErrorConditionalOrder->ForceCloseReason;
			//自动挂起标志
			field->IsAutoSuspend = pErrorConditionalOrder->IsAutoSuspend;
			//业务单元
			if (pErrorConditionalOrder->BusinessUnit != nullptr)
			{
				field->BusinessUnit = gcnew String(pErrorConditionalOrder->BusinessUnit);
			}
			//请求编号
			field->RequestID = pErrorConditionalOrder->RequestID;
			//本地报单编号
			if (pErrorConditionalOrder->OrderLocalID != nullptr)
			{
				field->OrderLocalID = gcnew String(pErrorConditionalOrder->OrderLocalID);
			}
			//交易所代码
			if (pErrorConditionalOrder->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pErrorConditionalOrder->ExchangeID);
			}
			//会员代码
			if (pErrorConditionalOrder->ParticipantID != nullptr)
			{
				field->ParticipantID = gcnew String(pErrorConditionalOrder->ParticipantID);
			}
			//客户代码
			if (pErrorConditionalOrder->ClientID != nullptr)
			{
				field->ClientID = gcnew String(pErrorConditionalOrder->ClientID);
			}
			//合约在交易所的代码
			if (pErrorConditionalOrder->ExchangeInstID != nullptr)
			{
				field->ExchangeInstID = gcnew String(pErrorConditionalOrder->ExchangeInstID);
			}
			//交易所交易员代码
			if (pErrorConditionalOrder->TraderID != nullptr)
			{
				field->TraderID = gcnew String(pErrorConditionalOrder->TraderID);
			}
			//安装编号
			field->InstallID = pErrorConditionalOrder->InstallID;
			//报单提交状态
			field->OrderSubmitStatus = (CtpNetOrderSubmitStatusType)pErrorConditionalOrder->OrderSubmitStatus;
			//报单提示序号
			field->NotifySequence = pErrorConditionalOrder->NotifySequence;
			//交易日
			if (pErrorConditionalOrder->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pErrorConditionalOrder->TradingDay);
			}
			//结算编号
			field->SettlementID = pErrorConditionalOrder->SettlementID;
			//报单编号
			if (pErrorConditionalOrder->OrderSysID != nullptr)
			{
				field->OrderSysID = gcnew String(pErrorConditionalOrder->OrderSysID);
			}
			//报单来源
			field->OrderSource = (CtpNetOrderSourceType)pErrorConditionalOrder->OrderSource;
			//报单状态
			field->OrderStatus = (CtpNetOrderStatusType)pErrorConditionalOrder->OrderStatus;
			//报单类型
			field->OrderType = (CtpNetOrderTypeType)pErrorConditionalOrder->OrderType;
			//今成交数量
			field->VolumeTraded = pErrorConditionalOrder->VolumeTraded;
			//剩余数量
			field->VolumeTotal = pErrorConditionalOrder->VolumeTotal;
			//报单日期
			if (pErrorConditionalOrder->InsertDate != nullptr)
			{
				field->InsertDate = gcnew String(pErrorConditionalOrder->InsertDate);
			}
			//委托时间
			if (pErrorConditionalOrder->InsertTime != nullptr)
			{
				field->InsertTime = gcnew String(pErrorConditionalOrder->InsertTime);
			}
			//激活时间
			if (pErrorConditionalOrder->ActiveTime != nullptr)
			{
				field->ActiveTime = gcnew String(pErrorConditionalOrder->ActiveTime);
			}
			//挂起时间
			if (pErrorConditionalOrder->SuspendTime != nullptr)
			{
				field->SuspendTime = gcnew String(pErrorConditionalOrder->SuspendTime);
			}
			//最后修改时间
			if (pErrorConditionalOrder->UpdateTime != nullptr)
			{
				field->UpdateTime = gcnew String(pErrorConditionalOrder->UpdateTime);
			}
			//撤销时间
			if (pErrorConditionalOrder->CancelTime != nullptr)
			{
				field->CancelTime = gcnew String(pErrorConditionalOrder->CancelTime);
			}
			//最后修改交易所交易员代码
			if (pErrorConditionalOrder->ActiveTraderID != nullptr)
			{
				field->ActiveTraderID = gcnew String(pErrorConditionalOrder->ActiveTraderID);
			}
			//结算会员编号
			if (pErrorConditionalOrder->ClearingPartID != nullptr)
			{
				field->ClearingPartID = gcnew String(pErrorConditionalOrder->ClearingPartID);
			}
			//序号
			field->SequenceNo = pErrorConditionalOrder->SequenceNo;
			//前置编号
			field->FrontID = pErrorConditionalOrder->FrontID;
			//会话编号
			field->SessionID = pErrorConditionalOrder->SessionID;
			//用户端产品信息
			if (pErrorConditionalOrder->UserProductInfo != nullptr)
			{
				field->UserProductInfo = gcnew String(pErrorConditionalOrder->UserProductInfo);
			}
			//状态信息
			if (pErrorConditionalOrder->StatusMsg != nullptr)
			{
				field->StatusMsg = gcnew String(pErrorConditionalOrder->StatusMsg);
			}
			//用户强评标志
			field->UserForceClose = pErrorConditionalOrder->UserForceClose;
			//操作用户代码
			if (pErrorConditionalOrder->ActiveUserID != nullptr)
			{
				field->ActiveUserID = gcnew String(pErrorConditionalOrder->ActiveUserID);
			}
			//经纪公司报单编号
			field->BrokerOrderSeq = pErrorConditionalOrder->BrokerOrderSeq;
			//相关报单
			if (pErrorConditionalOrder->RelativeOrderSysID != nullptr)
			{
				field->RelativeOrderSysID = gcnew String(pErrorConditionalOrder->RelativeOrderSysID);
			}
			//郑商所成交数量
			field->ZCETotalTradedVolume = pErrorConditionalOrder->ZCETotalTradedVolume;
			//错误代码
			field->ErrorID = pErrorConditionalOrder->ErrorID;
			//错误信息
			if (pErrorConditionalOrder->ErrorMsg != nullptr)
			{
				field->ErrorMsg = gcnew String(pErrorConditionalOrder->ErrorMsg);
			}
			//互换单标志
			field->IsSwapOrder = pErrorConditionalOrder->IsSwapOrder;
			//营业部编号
			if (pErrorConditionalOrder->BranchID != nullptr)
			{
				field->BranchID = gcnew String(pErrorConditionalOrder->BranchID);
			}
			//投资单元代码
			if (pErrorConditionalOrder->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pErrorConditionalOrder->InvestUnitID);
			}
			//资金账号
			if (pErrorConditionalOrder->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pErrorConditionalOrder->AccountID);
			}
			//币种代码
			if (pErrorConditionalOrder->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pErrorConditionalOrder->CurrencyID);
			}
			//IP地址
			if (pErrorConditionalOrder->IPAddress != nullptr)
			{
				field->IPAddress = gcnew String(pErrorConditionalOrder->IPAddress);
			}
			//Mac地址
			if (pErrorConditionalOrder->MacAddress != nullptr)
			{
				field->MacAddress = gcnew String(pErrorConditionalOrder->MacAddress);
			}
		}
		
		m_pAdapter->OnRtnErrorConditionalOrder(field);
	};

	// 执行宣告通知
	void CTraderSpi::OnRtnExecOrder(CThostFtdcExecOrderField *pExecOrder)
	{
		if (m_pAdapter->OnRtnExecOrder_delegate == nullptr) return;
		
		CtpNetExecOrderField^ field = nullptr;
		if (pExecOrder != nullptr)
		{
			field = gcnew CtpNetExecOrderField;
			
			//经纪公司代码
			if (pExecOrder->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pExecOrder->BrokerID);
			}
			//投资者代码
			if (pExecOrder->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pExecOrder->InvestorID);
			}
			//合约代码
			if (pExecOrder->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pExecOrder->InstrumentID);
			}
			//执行宣告引用
			if (pExecOrder->ExecOrderRef != nullptr)
			{
				field->ExecOrderRef = gcnew String(pExecOrder->ExecOrderRef);
			}
			//用户代码
			if (pExecOrder->UserID != nullptr)
			{
				field->UserID = gcnew String(pExecOrder->UserID);
			}
			//数量
			field->Volume = pExecOrder->Volume;
			//请求编号
			field->RequestID = pExecOrder->RequestID;
			//业务单元
			if (pExecOrder->BusinessUnit != nullptr)
			{
				field->BusinessUnit = gcnew String(pExecOrder->BusinessUnit);
			}
			//开平标志
			field->OffsetFlag = (CtpNetOffsetFlagType)pExecOrder->OffsetFlag;
			//投机套保标志
			field->HedgeFlag = (CtpNetHedgeFlagType)pExecOrder->HedgeFlag;
			//执行类型
			field->ActionType = (CtpNetActionTypeType)pExecOrder->ActionType;
			//保留头寸申请的持仓方向
			field->PosiDirection = (CtpNetPosiDirectionType)pExecOrder->PosiDirection;
			//期权行权后是否保留期货头寸的标记,该字段已废弃
			field->ReservePositionFlag = (CtpNetExecOrderPositionFlagType)pExecOrder->ReservePositionFlag;
			//期权行权后生成的头寸是否自动平仓
			field->CloseFlag = (CtpNetExecOrderCloseFlagType)pExecOrder->CloseFlag;
			//本地执行宣告编号
			if (pExecOrder->ExecOrderLocalID != nullptr)
			{
				field->ExecOrderLocalID = gcnew String(pExecOrder->ExecOrderLocalID);
			}
			//交易所代码
			if (pExecOrder->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pExecOrder->ExchangeID);
			}
			//会员代码
			if (pExecOrder->ParticipantID != nullptr)
			{
				field->ParticipantID = gcnew String(pExecOrder->ParticipantID);
			}
			//客户代码
			if (pExecOrder->ClientID != nullptr)
			{
				field->ClientID = gcnew String(pExecOrder->ClientID);
			}
			//合约在交易所的代码
			if (pExecOrder->ExchangeInstID != nullptr)
			{
				field->ExchangeInstID = gcnew String(pExecOrder->ExchangeInstID);
			}
			//交易所交易员代码
			if (pExecOrder->TraderID != nullptr)
			{
				field->TraderID = gcnew String(pExecOrder->TraderID);
			}
			//安装编号
			field->InstallID = pExecOrder->InstallID;
			//执行宣告提交状态
			field->OrderSubmitStatus = (CtpNetOrderSubmitStatusType)pExecOrder->OrderSubmitStatus;
			//报单提示序号
			field->NotifySequence = pExecOrder->NotifySequence;
			//交易日
			if (pExecOrder->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pExecOrder->TradingDay);
			}
			//结算编号
			field->SettlementID = pExecOrder->SettlementID;
			//执行宣告编号
			if (pExecOrder->ExecOrderSysID != nullptr)
			{
				field->ExecOrderSysID = gcnew String(pExecOrder->ExecOrderSysID);
			}
			//报单日期
			if (pExecOrder->InsertDate != nullptr)
			{
				field->InsertDate = gcnew String(pExecOrder->InsertDate);
			}
			//插入时间
			if (pExecOrder->InsertTime != nullptr)
			{
				field->InsertTime = gcnew String(pExecOrder->InsertTime);
			}
			//撤销时间
			if (pExecOrder->CancelTime != nullptr)
			{
				field->CancelTime = gcnew String(pExecOrder->CancelTime);
			}
			//执行结果
			field->ExecResult = (CtpNetExecResultType)pExecOrder->ExecResult;
			//结算会员编号
			if (pExecOrder->ClearingPartID != nullptr)
			{
				field->ClearingPartID = gcnew String(pExecOrder->ClearingPartID);
			}
			//序号
			field->SequenceNo = pExecOrder->SequenceNo;
			//前置编号
			field->FrontID = pExecOrder->FrontID;
			//会话编号
			field->SessionID = pExecOrder->SessionID;
			//用户端产品信息
			if (pExecOrder->UserProductInfo != nullptr)
			{
				field->UserProductInfo = gcnew String(pExecOrder->UserProductInfo);
			}
			//状态信息
			if (pExecOrder->StatusMsg != nullptr)
			{
				field->StatusMsg = gcnew String(pExecOrder->StatusMsg);
			}
			//操作用户代码
			if (pExecOrder->ActiveUserID != nullptr)
			{
				field->ActiveUserID = gcnew String(pExecOrder->ActiveUserID);
			}
			//经纪公司报单编号
			field->BrokerExecOrderSeq = pExecOrder->BrokerExecOrderSeq;
			//营业部编号
			if (pExecOrder->BranchID != nullptr)
			{
				field->BranchID = gcnew String(pExecOrder->BranchID);
			}
			//投资单元代码
			if (pExecOrder->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pExecOrder->InvestUnitID);
			}
			//资金账号
			if (pExecOrder->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pExecOrder->AccountID);
			}
			//币种代码
			if (pExecOrder->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pExecOrder->CurrencyID);
			}
			//IP地址
			if (pExecOrder->IPAddress != nullptr)
			{
				field->IPAddress = gcnew String(pExecOrder->IPAddress);
			}
			//Mac地址
			if (pExecOrder->MacAddress != nullptr)
			{
				field->MacAddress = gcnew String(pExecOrder->MacAddress);
			}
		}
		
		m_pAdapter->OnRtnExecOrder(field);
	};

	// 执行宣告录入错误回报
	void CTraderSpi::OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo)
	{
		if (m_pAdapter->OnErrRtnExecOrderInsert_delegate == nullptr) return;
		
		CtpNetInputExecOrderField^ field = nullptr;
		if (pInputExecOrder != nullptr)
		{
			field = gcnew CtpNetInputExecOrderField;
			
			//经纪公司代码
			if (pInputExecOrder->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pInputExecOrder->BrokerID);
			}
			//投资者代码
			if (pInputExecOrder->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pInputExecOrder->InvestorID);
			}
			//合约代码
			if (pInputExecOrder->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pInputExecOrder->InstrumentID);
			}
			//执行宣告引用
			if (pInputExecOrder->ExecOrderRef != nullptr)
			{
				field->ExecOrderRef = gcnew String(pInputExecOrder->ExecOrderRef);
			}
			//用户代码
			if (pInputExecOrder->UserID != nullptr)
			{
				field->UserID = gcnew String(pInputExecOrder->UserID);
			}
			//数量
			field->Volume = pInputExecOrder->Volume;
			//请求编号
			field->RequestID = pInputExecOrder->RequestID;
			//业务单元
			if (pInputExecOrder->BusinessUnit != nullptr)
			{
				field->BusinessUnit = gcnew String(pInputExecOrder->BusinessUnit);
			}
			//开平标志
			field->OffsetFlag = (CtpNetOffsetFlagType)pInputExecOrder->OffsetFlag;
			//投机套保标志
			field->HedgeFlag = (CtpNetHedgeFlagType)pInputExecOrder->HedgeFlag;
			//执行类型
			field->ActionType = (CtpNetActionTypeType)pInputExecOrder->ActionType;
			//保留头寸申请的持仓方向
			field->PosiDirection = (CtpNetPosiDirectionType)pInputExecOrder->PosiDirection;
			//期权行权后是否保留期货头寸的标记,该字段已废弃
			field->ReservePositionFlag = (CtpNetExecOrderPositionFlagType)pInputExecOrder->ReservePositionFlag;
			//期权行权后生成的头寸是否自动平仓
			field->CloseFlag = (CtpNetExecOrderCloseFlagType)pInputExecOrder->CloseFlag;
			//交易所代码
			if (pInputExecOrder->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pInputExecOrder->ExchangeID);
			}
			//投资单元代码
			if (pInputExecOrder->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pInputExecOrder->InvestUnitID);
			}
			//资金账号
			if (pInputExecOrder->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pInputExecOrder->AccountID);
			}
			//币种代码
			if (pInputExecOrder->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pInputExecOrder->CurrencyID);
			}
			//交易编码
			if (pInputExecOrder->ClientID != nullptr)
			{
				field->ClientID = gcnew String(pInputExecOrder->ClientID);
			}
			//IP地址
			if (pInputExecOrder->IPAddress != nullptr)
			{
				field->IPAddress = gcnew String(pInputExecOrder->IPAddress);
			}
			//Mac地址
			if (pInputExecOrder->MacAddress != nullptr)
			{
				field->MacAddress = gcnew String(pInputExecOrder->MacAddress);
			}
		}
		
		m_pAdapter->OnErrRtnExecOrderInsert(field, RspInfoField(pRspInfo));
	};

	// 执行宣告操作错误回报
	void CTraderSpi::OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField *pExecOrderAction, CThostFtdcRspInfoField *pRspInfo)
	{
		if (m_pAdapter->OnErrRtnExecOrderAction_delegate == nullptr) return;
		
		CtpNetExecOrderActionField^ field = nullptr;
		if (pExecOrderAction != nullptr)
		{
			field = gcnew CtpNetExecOrderActionField;
			
			//经纪公司代码
			if (pExecOrderAction->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pExecOrderAction->BrokerID);
			}
			//投资者代码
			if (pExecOrderAction->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pExecOrderAction->InvestorID);
			}
			//执行宣告操作引用
			field->ExecOrderActionRef = pExecOrderAction->ExecOrderActionRef;
			//执行宣告引用
			if (pExecOrderAction->ExecOrderRef != nullptr)
			{
				field->ExecOrderRef = gcnew String(pExecOrderAction->ExecOrderRef);
			}
			//请求编号
			field->RequestID = pExecOrderAction->RequestID;
			//前置编号
			field->FrontID = pExecOrderAction->FrontID;
			//会话编号
			field->SessionID = pExecOrderAction->SessionID;
			//交易所代码
			if (pExecOrderAction->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pExecOrderAction->ExchangeID);
			}
			//执行宣告操作编号
			if (pExecOrderAction->ExecOrderSysID != nullptr)
			{
				field->ExecOrderSysID = gcnew String(pExecOrderAction->ExecOrderSysID);
			}
			//操作标志
			field->ActionFlag = (CtpNetActionFlagType)pExecOrderAction->ActionFlag;
			//操作日期
			if (pExecOrderAction->ActionDate != nullptr)
			{
				field->ActionDate = gcnew String(pExecOrderAction->ActionDate);
			}
			//操作时间
			if (pExecOrderAction->ActionTime != nullptr)
			{
				field->ActionTime = gcnew String(pExecOrderAction->ActionTime);
			}
			//交易所交易员代码
			if (pExecOrderAction->TraderID != nullptr)
			{
				field->TraderID = gcnew String(pExecOrderAction->TraderID);
			}
			//安装编号
			field->InstallID = pExecOrderAction->InstallID;
			//本地执行宣告编号
			if (pExecOrderAction->ExecOrderLocalID != nullptr)
			{
				field->ExecOrderLocalID = gcnew String(pExecOrderAction->ExecOrderLocalID);
			}
			//操作本地编号
			if (pExecOrderAction->ActionLocalID != nullptr)
			{
				field->ActionLocalID = gcnew String(pExecOrderAction->ActionLocalID);
			}
			//会员代码
			if (pExecOrderAction->ParticipantID != nullptr)
			{
				field->ParticipantID = gcnew String(pExecOrderAction->ParticipantID);
			}
			//客户代码
			if (pExecOrderAction->ClientID != nullptr)
			{
				field->ClientID = gcnew String(pExecOrderAction->ClientID);
			}
			//业务单元
			if (pExecOrderAction->BusinessUnit != nullptr)
			{
				field->BusinessUnit = gcnew String(pExecOrderAction->BusinessUnit);
			}
			//报单操作状态
			field->OrderActionStatus = (CtpNetOrderActionStatusType)pExecOrderAction->OrderActionStatus;
			//用户代码
			if (pExecOrderAction->UserID != nullptr)
			{
				field->UserID = gcnew String(pExecOrderAction->UserID);
			}
			//执行类型
			field->ActionType = (CtpNetActionTypeType)pExecOrderAction->ActionType;
			//状态信息
			if (pExecOrderAction->StatusMsg != nullptr)
			{
				field->StatusMsg = gcnew String(pExecOrderAction->StatusMsg);
			}
			//合约代码
			if (pExecOrderAction->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pExecOrderAction->InstrumentID);
			}
			//营业部编号
			if (pExecOrderAction->BranchID != nullptr)
			{
				field->BranchID = gcnew String(pExecOrderAction->BranchID);
			}
			//投资单元代码
			if (pExecOrderAction->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pExecOrderAction->InvestUnitID);
			}
			//IP地址
			if (pExecOrderAction->IPAddress != nullptr)
			{
				field->IPAddress = gcnew String(pExecOrderAction->IPAddress);
			}
			//Mac地址
			if (pExecOrderAction->MacAddress != nullptr)
			{
				field->MacAddress = gcnew String(pExecOrderAction->MacAddress);
			}
		}
		
		m_pAdapter->OnErrRtnExecOrderAction(field, RspInfoField(pRspInfo));
	};

	// 询价录入错误回报
	void CTraderSpi::OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo)
	{
		if (m_pAdapter->OnErrRtnForQuoteInsert_delegate == nullptr) return;
		
		CtpNetInputForQuoteField^ field = nullptr;
		if (pInputForQuote != nullptr)
		{
			field = gcnew CtpNetInputForQuoteField;
			
			//经纪公司代码
			if (pInputForQuote->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pInputForQuote->BrokerID);
			}
			//投资者代码
			if (pInputForQuote->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pInputForQuote->InvestorID);
			}
			//合约代码
			if (pInputForQuote->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pInputForQuote->InstrumentID);
			}
			//询价引用
			if (pInputForQuote->ForQuoteRef != nullptr)
			{
				field->ForQuoteRef = gcnew String(pInputForQuote->ForQuoteRef);
			}
			//用户代码
			if (pInputForQuote->UserID != nullptr)
			{
				field->UserID = gcnew String(pInputForQuote->UserID);
			}
			//交易所代码
			if (pInputForQuote->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pInputForQuote->ExchangeID);
			}
			//投资单元代码
			if (pInputForQuote->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pInputForQuote->InvestUnitID);
			}
			//IP地址
			if (pInputForQuote->IPAddress != nullptr)
			{
				field->IPAddress = gcnew String(pInputForQuote->IPAddress);
			}
			//Mac地址
			if (pInputForQuote->MacAddress != nullptr)
			{
				field->MacAddress = gcnew String(pInputForQuote->MacAddress);
			}
		}
		
		m_pAdapter->OnErrRtnForQuoteInsert(field, RspInfoField(pRspInfo));
	};

	// 报价通知
	void CTraderSpi::OnRtnQuote(CThostFtdcQuoteField *pQuote)
	{
		if (m_pAdapter->OnRtnQuote_delegate == nullptr) return;
		
		CtpNetQuoteField^ field = nullptr;
		if (pQuote != nullptr)
		{
			field = gcnew CtpNetQuoteField;
			
			//经纪公司代码
			if (pQuote->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pQuote->BrokerID);
			}
			//投资者代码
			if (pQuote->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pQuote->InvestorID);
			}
			//合约代码
			if (pQuote->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pQuote->InstrumentID);
			}
			//报价引用
			if (pQuote->QuoteRef != nullptr)
			{
				field->QuoteRef = gcnew String(pQuote->QuoteRef);
			}
			//用户代码
			if (pQuote->UserID != nullptr)
			{
				field->UserID = gcnew String(pQuote->UserID);
			}
			//卖价格
			field->AskPrice = pQuote->AskPrice;
			//买价格
			field->BidPrice = pQuote->BidPrice;
			//卖数量
			field->AskVolume = pQuote->AskVolume;
			//买数量
			field->BidVolume = pQuote->BidVolume;
			//请求编号
			field->RequestID = pQuote->RequestID;
			//业务单元
			if (pQuote->BusinessUnit != nullptr)
			{
				field->BusinessUnit = gcnew String(pQuote->BusinessUnit);
			}
			//卖开平标志
			field->AskOffsetFlag = (CtpNetOffsetFlagType)pQuote->AskOffsetFlag;
			//买开平标志
			field->BidOffsetFlag = (CtpNetOffsetFlagType)pQuote->BidOffsetFlag;
			//卖投机套保标志
			field->AskHedgeFlag = (CtpNetHedgeFlagType)pQuote->AskHedgeFlag;
			//买投机套保标志
			field->BidHedgeFlag = (CtpNetHedgeFlagType)pQuote->BidHedgeFlag;
			//本地报价编号
			if (pQuote->QuoteLocalID != nullptr)
			{
				field->QuoteLocalID = gcnew String(pQuote->QuoteLocalID);
			}
			//交易所代码
			if (pQuote->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pQuote->ExchangeID);
			}
			//会员代码
			if (pQuote->ParticipantID != nullptr)
			{
				field->ParticipantID = gcnew String(pQuote->ParticipantID);
			}
			//客户代码
			if (pQuote->ClientID != nullptr)
			{
				field->ClientID = gcnew String(pQuote->ClientID);
			}
			//合约在交易所的代码
			if (pQuote->ExchangeInstID != nullptr)
			{
				field->ExchangeInstID = gcnew String(pQuote->ExchangeInstID);
			}
			//交易所交易员代码
			if (pQuote->TraderID != nullptr)
			{
				field->TraderID = gcnew String(pQuote->TraderID);
			}
			//安装编号
			field->InstallID = pQuote->InstallID;
			//报价提示序号
			field->NotifySequence = pQuote->NotifySequence;
			//报价提交状态
			field->OrderSubmitStatus = (CtpNetOrderSubmitStatusType)pQuote->OrderSubmitStatus;
			//交易日
			if (pQuote->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pQuote->TradingDay);
			}
			//结算编号
			field->SettlementID = pQuote->SettlementID;
			//报价编号
			if (pQuote->QuoteSysID != nullptr)
			{
				field->QuoteSysID = gcnew String(pQuote->QuoteSysID);
			}
			//报单日期
			if (pQuote->InsertDate != nullptr)
			{
				field->InsertDate = gcnew String(pQuote->InsertDate);
			}
			//插入时间
			if (pQuote->InsertTime != nullptr)
			{
				field->InsertTime = gcnew String(pQuote->InsertTime);
			}
			//撤销时间
			if (pQuote->CancelTime != nullptr)
			{
				field->CancelTime = gcnew String(pQuote->CancelTime);
			}
			//报价状态
			field->QuoteStatus = (CtpNetOrderStatusType)pQuote->QuoteStatus;
			//结算会员编号
			if (pQuote->ClearingPartID != nullptr)
			{
				field->ClearingPartID = gcnew String(pQuote->ClearingPartID);
			}
			//序号
			field->SequenceNo = pQuote->SequenceNo;
			//卖方报单编号
			if (pQuote->AskOrderSysID != nullptr)
			{
				field->AskOrderSysID = gcnew String(pQuote->AskOrderSysID);
			}
			//买方报单编号
			if (pQuote->BidOrderSysID != nullptr)
			{
				field->BidOrderSysID = gcnew String(pQuote->BidOrderSysID);
			}
			//前置编号
			field->FrontID = pQuote->FrontID;
			//会话编号
			field->SessionID = pQuote->SessionID;
			//用户端产品信息
			if (pQuote->UserProductInfo != nullptr)
			{
				field->UserProductInfo = gcnew String(pQuote->UserProductInfo);
			}
			//状态信息
			if (pQuote->StatusMsg != nullptr)
			{
				field->StatusMsg = gcnew String(pQuote->StatusMsg);
			}
			//操作用户代码
			if (pQuote->ActiveUserID != nullptr)
			{
				field->ActiveUserID = gcnew String(pQuote->ActiveUserID);
			}
			//经纪公司报价编号
			field->BrokerQuoteSeq = pQuote->BrokerQuoteSeq;
			//衍生卖报单引用
			if (pQuote->AskOrderRef != nullptr)
			{
				field->AskOrderRef = gcnew String(pQuote->AskOrderRef);
			}
			//衍生买报单引用
			if (pQuote->BidOrderRef != nullptr)
			{
				field->BidOrderRef = gcnew String(pQuote->BidOrderRef);
			}
			//应价编号
			if (pQuote->ForQuoteSysID != nullptr)
			{
				field->ForQuoteSysID = gcnew String(pQuote->ForQuoteSysID);
			}
			//营业部编号
			if (pQuote->BranchID != nullptr)
			{
				field->BranchID = gcnew String(pQuote->BranchID);
			}
			//投资单元代码
			if (pQuote->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pQuote->InvestUnitID);
			}
			//资金账号
			if (pQuote->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pQuote->AccountID);
			}
			//币种代码
			if (pQuote->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pQuote->CurrencyID);
			}
			//IP地址
			if (pQuote->IPAddress != nullptr)
			{
				field->IPAddress = gcnew String(pQuote->IPAddress);
			}
			//Mac地址
			if (pQuote->MacAddress != nullptr)
			{
				field->MacAddress = gcnew String(pQuote->MacAddress);
			}
		}
		
		m_pAdapter->OnRtnQuote(field);
	};

	// 报价录入错误回报
	void CTraderSpi::OnErrRtnQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo)
	{
		if (m_pAdapter->OnErrRtnQuoteInsert_delegate == nullptr) return;
		
		CtpNetInputQuoteField^ field = nullptr;
		if (pInputQuote != nullptr)
		{
			field = gcnew CtpNetInputQuoteField;
			
			//经纪公司代码
			if (pInputQuote->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pInputQuote->BrokerID);
			}
			//投资者代码
			if (pInputQuote->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pInputQuote->InvestorID);
			}
			//合约代码
			if (pInputQuote->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pInputQuote->InstrumentID);
			}
			//报价引用
			if (pInputQuote->QuoteRef != nullptr)
			{
				field->QuoteRef = gcnew String(pInputQuote->QuoteRef);
			}
			//用户代码
			if (pInputQuote->UserID != nullptr)
			{
				field->UserID = gcnew String(pInputQuote->UserID);
			}
			//卖价格
			field->AskPrice = pInputQuote->AskPrice;
			//买价格
			field->BidPrice = pInputQuote->BidPrice;
			//卖数量
			field->AskVolume = pInputQuote->AskVolume;
			//买数量
			field->BidVolume = pInputQuote->BidVolume;
			//请求编号
			field->RequestID = pInputQuote->RequestID;
			//业务单元
			if (pInputQuote->BusinessUnit != nullptr)
			{
				field->BusinessUnit = gcnew String(pInputQuote->BusinessUnit);
			}
			//卖开平标志
			field->AskOffsetFlag = (CtpNetOffsetFlagType)pInputQuote->AskOffsetFlag;
			//买开平标志
			field->BidOffsetFlag = (CtpNetOffsetFlagType)pInputQuote->BidOffsetFlag;
			//卖投机套保标志
			field->AskHedgeFlag = (CtpNetHedgeFlagType)pInputQuote->AskHedgeFlag;
			//买投机套保标志
			field->BidHedgeFlag = (CtpNetHedgeFlagType)pInputQuote->BidHedgeFlag;
			//衍生卖报单引用
			if (pInputQuote->AskOrderRef != nullptr)
			{
				field->AskOrderRef = gcnew String(pInputQuote->AskOrderRef);
			}
			//衍生买报单引用
			if (pInputQuote->BidOrderRef != nullptr)
			{
				field->BidOrderRef = gcnew String(pInputQuote->BidOrderRef);
			}
			//应价编号
			if (pInputQuote->ForQuoteSysID != nullptr)
			{
				field->ForQuoteSysID = gcnew String(pInputQuote->ForQuoteSysID);
			}
			//交易所代码
			if (pInputQuote->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pInputQuote->ExchangeID);
			}
			//投资单元代码
			if (pInputQuote->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pInputQuote->InvestUnitID);
			}
			//交易编码
			if (pInputQuote->ClientID != nullptr)
			{
				field->ClientID = gcnew String(pInputQuote->ClientID);
			}
			//IP地址
			if (pInputQuote->IPAddress != nullptr)
			{
				field->IPAddress = gcnew String(pInputQuote->IPAddress);
			}
			//Mac地址
			if (pInputQuote->MacAddress != nullptr)
			{
				field->MacAddress = gcnew String(pInputQuote->MacAddress);
			}
		}
		
		m_pAdapter->OnErrRtnQuoteInsert(field, RspInfoField(pRspInfo));
	};

	// 报价操作错误回报
	void CTraderSpi::OnErrRtnQuoteAction(CThostFtdcQuoteActionField *pQuoteAction, CThostFtdcRspInfoField *pRspInfo)
	{
		if (m_pAdapter->OnErrRtnQuoteAction_delegate == nullptr) return;
		
		CtpNetQuoteActionField^ field = nullptr;
		if (pQuoteAction != nullptr)
		{
			field = gcnew CtpNetQuoteActionField;
			
			//经纪公司代码
			if (pQuoteAction->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pQuoteAction->BrokerID);
			}
			//投资者代码
			if (pQuoteAction->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pQuoteAction->InvestorID);
			}
			//报价操作引用
			field->QuoteActionRef = pQuoteAction->QuoteActionRef;
			//报价引用
			if (pQuoteAction->QuoteRef != nullptr)
			{
				field->QuoteRef = gcnew String(pQuoteAction->QuoteRef);
			}
			//请求编号
			field->RequestID = pQuoteAction->RequestID;
			//前置编号
			field->FrontID = pQuoteAction->FrontID;
			//会话编号
			field->SessionID = pQuoteAction->SessionID;
			//交易所代码
			if (pQuoteAction->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pQuoteAction->ExchangeID);
			}
			//报价操作编号
			if (pQuoteAction->QuoteSysID != nullptr)
			{
				field->QuoteSysID = gcnew String(pQuoteAction->QuoteSysID);
			}
			//操作标志
			field->ActionFlag = (CtpNetActionFlagType)pQuoteAction->ActionFlag;
			//操作日期
			if (pQuoteAction->ActionDate != nullptr)
			{
				field->ActionDate = gcnew String(pQuoteAction->ActionDate);
			}
			//操作时间
			if (pQuoteAction->ActionTime != nullptr)
			{
				field->ActionTime = gcnew String(pQuoteAction->ActionTime);
			}
			//交易所交易员代码
			if (pQuoteAction->TraderID != nullptr)
			{
				field->TraderID = gcnew String(pQuoteAction->TraderID);
			}
			//安装编号
			field->InstallID = pQuoteAction->InstallID;
			//本地报价编号
			if (pQuoteAction->QuoteLocalID != nullptr)
			{
				field->QuoteLocalID = gcnew String(pQuoteAction->QuoteLocalID);
			}
			//操作本地编号
			if (pQuoteAction->ActionLocalID != nullptr)
			{
				field->ActionLocalID = gcnew String(pQuoteAction->ActionLocalID);
			}
			//会员代码
			if (pQuoteAction->ParticipantID != nullptr)
			{
				field->ParticipantID = gcnew String(pQuoteAction->ParticipantID);
			}
			//客户代码
			if (pQuoteAction->ClientID != nullptr)
			{
				field->ClientID = gcnew String(pQuoteAction->ClientID);
			}
			//业务单元
			if (pQuoteAction->BusinessUnit != nullptr)
			{
				field->BusinessUnit = gcnew String(pQuoteAction->BusinessUnit);
			}
			//报单操作状态
			field->OrderActionStatus = (CtpNetOrderActionStatusType)pQuoteAction->OrderActionStatus;
			//用户代码
			if (pQuoteAction->UserID != nullptr)
			{
				field->UserID = gcnew String(pQuoteAction->UserID);
			}
			//状态信息
			if (pQuoteAction->StatusMsg != nullptr)
			{
				field->StatusMsg = gcnew String(pQuoteAction->StatusMsg);
			}
			//合约代码
			if (pQuoteAction->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pQuoteAction->InstrumentID);
			}
			//营业部编号
			if (pQuoteAction->BranchID != nullptr)
			{
				field->BranchID = gcnew String(pQuoteAction->BranchID);
			}
			//投资单元代码
			if (pQuoteAction->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pQuoteAction->InvestUnitID);
			}
			//IP地址
			if (pQuoteAction->IPAddress != nullptr)
			{
				field->IPAddress = gcnew String(pQuoteAction->IPAddress);
			}
			//Mac地址
			if (pQuoteAction->MacAddress != nullptr)
			{
				field->MacAddress = gcnew String(pQuoteAction->MacAddress);
			}
		}
		
		m_pAdapter->OnErrRtnQuoteAction(field, RspInfoField(pRspInfo));
	};

	// 询价通知
	void CTraderSpi::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp)
	{
		if (m_pAdapter->OnRtnForQuoteRsp_delegate == nullptr) return;
		
		CtpNetForQuoteRspField^ field = nullptr;
		if (pForQuoteRsp != nullptr)
		{
			field = gcnew CtpNetForQuoteRspField;
			
			//交易日
			if (pForQuoteRsp->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pForQuoteRsp->TradingDay);
			}
			//合约代码
			if (pForQuoteRsp->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pForQuoteRsp->InstrumentID);
			}
			//询价编号
			if (pForQuoteRsp->ForQuoteSysID != nullptr)
			{
				field->ForQuoteSysID = gcnew String(pForQuoteRsp->ForQuoteSysID);
			}
			//询价时间
			if (pForQuoteRsp->ForQuoteTime != nullptr)
			{
				field->ForQuoteTime = gcnew String(pForQuoteRsp->ForQuoteTime);
			}
			//业务日期
			if (pForQuoteRsp->ActionDay != nullptr)
			{
				field->ActionDay = gcnew String(pForQuoteRsp->ActionDay);
			}
			//交易所代码
			if (pForQuoteRsp->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pForQuoteRsp->ExchangeID);
			}
		}
		
		m_pAdapter->OnRtnForQuoteRsp(field);
	};

	// 保证金监控中心用户令牌
	void CTraderSpi::OnRtnCFMMCTradingAccountToken(CThostFtdcCFMMCTradingAccountTokenField *pCFMMCTradingAccountToken)
	{
		if (m_pAdapter->OnRtnCFMMCTradingAccountToken_delegate == nullptr) return;
		
		CtpNetCFMMCTradingAccountTokenField^ field = nullptr;
		if (pCFMMCTradingAccountToken != nullptr)
		{
			field = gcnew CtpNetCFMMCTradingAccountTokenField;
			
			//经纪公司代码
			if (pCFMMCTradingAccountToken->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pCFMMCTradingAccountToken->BrokerID);
			}
			//经纪公司统一编码
			if (pCFMMCTradingAccountToken->ParticipantID != nullptr)
			{
				field->ParticipantID = gcnew String(pCFMMCTradingAccountToken->ParticipantID);
			}
			//投资者帐号
			if (pCFMMCTradingAccountToken->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pCFMMCTradingAccountToken->AccountID);
			}
			//密钥编号
			field->KeyID = pCFMMCTradingAccountToken->KeyID;
			//动态令牌
			if (pCFMMCTradingAccountToken->Token != nullptr)
			{
				field->Token = gcnew String(pCFMMCTradingAccountToken->Token);
			}
		}
		
		m_pAdapter->OnRtnCFMMCTradingAccountToken(field);
	};

	// 批量报单操作错误回报
	void CTraderSpi::OnErrRtnBatchOrderAction(CThostFtdcBatchOrderActionField *pBatchOrderAction, CThostFtdcRspInfoField *pRspInfo)
	{
		if (m_pAdapter->OnErrRtnBatchOrderAction_delegate == nullptr) return;
		
		CtpNetBatchOrderActionField^ field = nullptr;
		if (pBatchOrderAction != nullptr)
		{
			field = gcnew CtpNetBatchOrderActionField;
			
			//经纪公司代码
			if (pBatchOrderAction->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pBatchOrderAction->BrokerID);
			}
			//投资者代码
			if (pBatchOrderAction->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pBatchOrderAction->InvestorID);
			}
			//报单操作引用
			field->OrderActionRef = pBatchOrderAction->OrderActionRef;
			//请求编号
			field->RequestID = pBatchOrderAction->RequestID;
			//前置编号
			field->FrontID = pBatchOrderAction->FrontID;
			//会话编号
			field->SessionID = pBatchOrderAction->SessionID;
			//交易所代码
			if (pBatchOrderAction->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pBatchOrderAction->ExchangeID);
			}
			//操作日期
			if (pBatchOrderAction->ActionDate != nullptr)
			{
				field->ActionDate = gcnew String(pBatchOrderAction->ActionDate);
			}
			//操作时间
			if (pBatchOrderAction->ActionTime != nullptr)
			{
				field->ActionTime = gcnew String(pBatchOrderAction->ActionTime);
			}
			//交易所交易员代码
			if (pBatchOrderAction->TraderID != nullptr)
			{
				field->TraderID = gcnew String(pBatchOrderAction->TraderID);
			}
			//安装编号
			field->InstallID = pBatchOrderAction->InstallID;
			//操作本地编号
			if (pBatchOrderAction->ActionLocalID != nullptr)
			{
				field->ActionLocalID = gcnew String(pBatchOrderAction->ActionLocalID);
			}
			//会员代码
			if (pBatchOrderAction->ParticipantID != nullptr)
			{
				field->ParticipantID = gcnew String(pBatchOrderAction->ParticipantID);
			}
			//客户代码
			if (pBatchOrderAction->ClientID != nullptr)
			{
				field->ClientID = gcnew String(pBatchOrderAction->ClientID);
			}
			//业务单元
			if (pBatchOrderAction->BusinessUnit != nullptr)
			{
				field->BusinessUnit = gcnew String(pBatchOrderAction->BusinessUnit);
			}
			//报单操作状态
			field->OrderActionStatus = (CtpNetOrderActionStatusType)pBatchOrderAction->OrderActionStatus;
			//用户代码
			if (pBatchOrderAction->UserID != nullptr)
			{
				field->UserID = gcnew String(pBatchOrderAction->UserID);
			}
			//状态信息
			if (pBatchOrderAction->StatusMsg != nullptr)
			{
				field->StatusMsg = gcnew String(pBatchOrderAction->StatusMsg);
			}
			//投资单元代码
			if (pBatchOrderAction->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pBatchOrderAction->InvestUnitID);
			}
			//IP地址
			if (pBatchOrderAction->IPAddress != nullptr)
			{
				field->IPAddress = gcnew String(pBatchOrderAction->IPAddress);
			}
			//Mac地址
			if (pBatchOrderAction->MacAddress != nullptr)
			{
				field->MacAddress = gcnew String(pBatchOrderAction->MacAddress);
			}
		}
		
		m_pAdapter->OnErrRtnBatchOrderAction(field, RspInfoField(pRspInfo));
	};

	// 期权自对冲通知
	void CTraderSpi::OnRtnOptionSelfClose(CThostFtdcOptionSelfCloseField *pOptionSelfClose)
	{
		if (m_pAdapter->OnRtnOptionSelfClose_delegate == nullptr) return;
		
		CtpNetOptionSelfCloseField^ field = nullptr;
		if (pOptionSelfClose != nullptr)
		{
			field = gcnew CtpNetOptionSelfCloseField;
			
			//经纪公司代码
			if (pOptionSelfClose->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pOptionSelfClose->BrokerID);
			}
			//投资者代码
			if (pOptionSelfClose->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pOptionSelfClose->InvestorID);
			}
			//合约代码
			if (pOptionSelfClose->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pOptionSelfClose->InstrumentID);
			}
			//期权自对冲引用
			if (pOptionSelfClose->OptionSelfCloseRef != nullptr)
			{
				field->OptionSelfCloseRef = gcnew String(pOptionSelfClose->OptionSelfCloseRef);
			}
			//用户代码
			if (pOptionSelfClose->UserID != nullptr)
			{
				field->UserID = gcnew String(pOptionSelfClose->UserID);
			}
			//数量
			field->Volume = pOptionSelfClose->Volume;
			//请求编号
			field->RequestID = pOptionSelfClose->RequestID;
			//业务单元
			if (pOptionSelfClose->BusinessUnit != nullptr)
			{
				field->BusinessUnit = gcnew String(pOptionSelfClose->BusinessUnit);
			}
			//投机套保标志
			field->HedgeFlag = (CtpNetHedgeFlagType)pOptionSelfClose->HedgeFlag;
			//期权行权的头寸是否自对冲
			field->OptSelfCloseFlag = (CtpNetOptSelfCloseFlagType)pOptionSelfClose->OptSelfCloseFlag;
			//本地期权自对冲编号
			if (pOptionSelfClose->OptionSelfCloseLocalID != nullptr)
			{
				field->OptionSelfCloseLocalID = gcnew String(pOptionSelfClose->OptionSelfCloseLocalID);
			}
			//交易所代码
			if (pOptionSelfClose->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pOptionSelfClose->ExchangeID);
			}
			//会员代码
			if (pOptionSelfClose->ParticipantID != nullptr)
			{
				field->ParticipantID = gcnew String(pOptionSelfClose->ParticipantID);
			}
			//客户代码
			if (pOptionSelfClose->ClientID != nullptr)
			{
				field->ClientID = gcnew String(pOptionSelfClose->ClientID);
			}
			//合约在交易所的代码
			if (pOptionSelfClose->ExchangeInstID != nullptr)
			{
				field->ExchangeInstID = gcnew String(pOptionSelfClose->ExchangeInstID);
			}
			//交易所交易员代码
			if (pOptionSelfClose->TraderID != nullptr)
			{
				field->TraderID = gcnew String(pOptionSelfClose->TraderID);
			}
			//安装编号
			field->InstallID = pOptionSelfClose->InstallID;
			//期权自对冲提交状态
			field->OrderSubmitStatus = (CtpNetOrderSubmitStatusType)pOptionSelfClose->OrderSubmitStatus;
			//报单提示序号
			field->NotifySequence = pOptionSelfClose->NotifySequence;
			//交易日
			if (pOptionSelfClose->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pOptionSelfClose->TradingDay);
			}
			//结算编号
			field->SettlementID = pOptionSelfClose->SettlementID;
			//期权自对冲编号
			if (pOptionSelfClose->OptionSelfCloseSysID != nullptr)
			{
				field->OptionSelfCloseSysID = gcnew String(pOptionSelfClose->OptionSelfCloseSysID);
			}
			//报单日期
			if (pOptionSelfClose->InsertDate != nullptr)
			{
				field->InsertDate = gcnew String(pOptionSelfClose->InsertDate);
			}
			//插入时间
			if (pOptionSelfClose->InsertTime != nullptr)
			{
				field->InsertTime = gcnew String(pOptionSelfClose->InsertTime);
			}
			//撤销时间
			if (pOptionSelfClose->CancelTime != nullptr)
			{
				field->CancelTime = gcnew String(pOptionSelfClose->CancelTime);
			}
			//自对冲结果
			field->ExecResult = (CtpNetExecResultType)pOptionSelfClose->ExecResult;
			//结算会员编号
			if (pOptionSelfClose->ClearingPartID != nullptr)
			{
				field->ClearingPartID = gcnew String(pOptionSelfClose->ClearingPartID);
			}
			//序号
			field->SequenceNo = pOptionSelfClose->SequenceNo;
			//前置编号
			field->FrontID = pOptionSelfClose->FrontID;
			//会话编号
			field->SessionID = pOptionSelfClose->SessionID;
			//用户端产品信息
			if (pOptionSelfClose->UserProductInfo != nullptr)
			{
				field->UserProductInfo = gcnew String(pOptionSelfClose->UserProductInfo);
			}
			//状态信息
			if (pOptionSelfClose->StatusMsg != nullptr)
			{
				field->StatusMsg = gcnew String(pOptionSelfClose->StatusMsg);
			}
			//操作用户代码
			if (pOptionSelfClose->ActiveUserID != nullptr)
			{
				field->ActiveUserID = gcnew String(pOptionSelfClose->ActiveUserID);
			}
			//经纪公司报单编号
			field->BrokerOptionSelfCloseSeq = pOptionSelfClose->BrokerOptionSelfCloseSeq;
			//营业部编号
			if (pOptionSelfClose->BranchID != nullptr)
			{
				field->BranchID = gcnew String(pOptionSelfClose->BranchID);
			}
			//投资单元代码
			if (pOptionSelfClose->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pOptionSelfClose->InvestUnitID);
			}
			//资金账号
			if (pOptionSelfClose->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pOptionSelfClose->AccountID);
			}
			//币种代码
			if (pOptionSelfClose->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pOptionSelfClose->CurrencyID);
			}
			//IP地址
			if (pOptionSelfClose->IPAddress != nullptr)
			{
				field->IPAddress = gcnew String(pOptionSelfClose->IPAddress);
			}
			//Mac地址
			if (pOptionSelfClose->MacAddress != nullptr)
			{
				field->MacAddress = gcnew String(pOptionSelfClose->MacAddress);
			}
		}
		
		m_pAdapter->OnRtnOptionSelfClose(field);
	};

	// 期权自对冲录入错误回报
	void CTraderSpi::OnErrRtnOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField *pInputOptionSelfClose, CThostFtdcRspInfoField *pRspInfo)
	{
		if (m_pAdapter->OnErrRtnOptionSelfCloseInsert_delegate == nullptr) return;
		
		CtpNetInputOptionSelfCloseField^ field = nullptr;
		if (pInputOptionSelfClose != nullptr)
		{
			field = gcnew CtpNetInputOptionSelfCloseField;
			
			//经纪公司代码
			if (pInputOptionSelfClose->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pInputOptionSelfClose->BrokerID);
			}
			//投资者代码
			if (pInputOptionSelfClose->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pInputOptionSelfClose->InvestorID);
			}
			//合约代码
			if (pInputOptionSelfClose->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pInputOptionSelfClose->InstrumentID);
			}
			//期权自对冲引用
			if (pInputOptionSelfClose->OptionSelfCloseRef != nullptr)
			{
				field->OptionSelfCloseRef = gcnew String(pInputOptionSelfClose->OptionSelfCloseRef);
			}
			//用户代码
			if (pInputOptionSelfClose->UserID != nullptr)
			{
				field->UserID = gcnew String(pInputOptionSelfClose->UserID);
			}
			//数量
			field->Volume = pInputOptionSelfClose->Volume;
			//请求编号
			field->RequestID = pInputOptionSelfClose->RequestID;
			//业务单元
			if (pInputOptionSelfClose->BusinessUnit != nullptr)
			{
				field->BusinessUnit = gcnew String(pInputOptionSelfClose->BusinessUnit);
			}
			//投机套保标志
			field->HedgeFlag = (CtpNetHedgeFlagType)pInputOptionSelfClose->HedgeFlag;
			//期权行权的头寸是否自对冲
			field->OptSelfCloseFlag = (CtpNetOptSelfCloseFlagType)pInputOptionSelfClose->OptSelfCloseFlag;
			//交易所代码
			if (pInputOptionSelfClose->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pInputOptionSelfClose->ExchangeID);
			}
			//投资单元代码
			if (pInputOptionSelfClose->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pInputOptionSelfClose->InvestUnitID);
			}
			//资金账号
			if (pInputOptionSelfClose->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pInputOptionSelfClose->AccountID);
			}
			//币种代码
			if (pInputOptionSelfClose->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pInputOptionSelfClose->CurrencyID);
			}
			//交易编码
			if (pInputOptionSelfClose->ClientID != nullptr)
			{
				field->ClientID = gcnew String(pInputOptionSelfClose->ClientID);
			}
			//IP地址
			if (pInputOptionSelfClose->IPAddress != nullptr)
			{
				field->IPAddress = gcnew String(pInputOptionSelfClose->IPAddress);
			}
			//Mac地址
			if (pInputOptionSelfClose->MacAddress != nullptr)
			{
				field->MacAddress = gcnew String(pInputOptionSelfClose->MacAddress);
			}
		}
		
		m_pAdapter->OnErrRtnOptionSelfCloseInsert(field, RspInfoField(pRspInfo));
	};

	// 期权自对冲操作错误回报
	void CTraderSpi::OnErrRtnOptionSelfCloseAction(CThostFtdcOptionSelfCloseActionField *pOptionSelfCloseAction, CThostFtdcRspInfoField *pRspInfo)
	{
		if (m_pAdapter->OnErrRtnOptionSelfCloseAction_delegate == nullptr) return;
		
		CtpNetOptionSelfCloseActionField^ field = nullptr;
		if (pOptionSelfCloseAction != nullptr)
		{
			field = gcnew CtpNetOptionSelfCloseActionField;
			
			//经纪公司代码
			if (pOptionSelfCloseAction->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pOptionSelfCloseAction->BrokerID);
			}
			//投资者代码
			if (pOptionSelfCloseAction->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pOptionSelfCloseAction->InvestorID);
			}
			//期权自对冲操作引用
			field->OptionSelfCloseActionRef = pOptionSelfCloseAction->OptionSelfCloseActionRef;
			//期权自对冲引用
			if (pOptionSelfCloseAction->OptionSelfCloseRef != nullptr)
			{
				field->OptionSelfCloseRef = gcnew String(pOptionSelfCloseAction->OptionSelfCloseRef);
			}
			//请求编号
			field->RequestID = pOptionSelfCloseAction->RequestID;
			//前置编号
			field->FrontID = pOptionSelfCloseAction->FrontID;
			//会话编号
			field->SessionID = pOptionSelfCloseAction->SessionID;
			//交易所代码
			if (pOptionSelfCloseAction->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pOptionSelfCloseAction->ExchangeID);
			}
			//期权自对冲操作编号
			if (pOptionSelfCloseAction->OptionSelfCloseSysID != nullptr)
			{
				field->OptionSelfCloseSysID = gcnew String(pOptionSelfCloseAction->OptionSelfCloseSysID);
			}
			//操作标志
			field->ActionFlag = (CtpNetActionFlagType)pOptionSelfCloseAction->ActionFlag;
			//操作日期
			if (pOptionSelfCloseAction->ActionDate != nullptr)
			{
				field->ActionDate = gcnew String(pOptionSelfCloseAction->ActionDate);
			}
			//操作时间
			if (pOptionSelfCloseAction->ActionTime != nullptr)
			{
				field->ActionTime = gcnew String(pOptionSelfCloseAction->ActionTime);
			}
			//交易所交易员代码
			if (pOptionSelfCloseAction->TraderID != nullptr)
			{
				field->TraderID = gcnew String(pOptionSelfCloseAction->TraderID);
			}
			//安装编号
			field->InstallID = pOptionSelfCloseAction->InstallID;
			//本地期权自对冲编号
			if (pOptionSelfCloseAction->OptionSelfCloseLocalID != nullptr)
			{
				field->OptionSelfCloseLocalID = gcnew String(pOptionSelfCloseAction->OptionSelfCloseLocalID);
			}
			//操作本地编号
			if (pOptionSelfCloseAction->ActionLocalID != nullptr)
			{
				field->ActionLocalID = gcnew String(pOptionSelfCloseAction->ActionLocalID);
			}
			//会员代码
			if (pOptionSelfCloseAction->ParticipantID != nullptr)
			{
				field->ParticipantID = gcnew String(pOptionSelfCloseAction->ParticipantID);
			}
			//客户代码
			if (pOptionSelfCloseAction->ClientID != nullptr)
			{
				field->ClientID = gcnew String(pOptionSelfCloseAction->ClientID);
			}
			//业务单元
			if (pOptionSelfCloseAction->BusinessUnit != nullptr)
			{
				field->BusinessUnit = gcnew String(pOptionSelfCloseAction->BusinessUnit);
			}
			//报单操作状态
			field->OrderActionStatus = (CtpNetOrderActionStatusType)pOptionSelfCloseAction->OrderActionStatus;
			//用户代码
			if (pOptionSelfCloseAction->UserID != nullptr)
			{
				field->UserID = gcnew String(pOptionSelfCloseAction->UserID);
			}
			//状态信息
			if (pOptionSelfCloseAction->StatusMsg != nullptr)
			{
				field->StatusMsg = gcnew String(pOptionSelfCloseAction->StatusMsg);
			}
			//合约代码
			if (pOptionSelfCloseAction->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pOptionSelfCloseAction->InstrumentID);
			}
			//营业部编号
			if (pOptionSelfCloseAction->BranchID != nullptr)
			{
				field->BranchID = gcnew String(pOptionSelfCloseAction->BranchID);
			}
			//投资单元代码
			if (pOptionSelfCloseAction->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pOptionSelfCloseAction->InvestUnitID);
			}
			//IP地址
			if (pOptionSelfCloseAction->IPAddress != nullptr)
			{
				field->IPAddress = gcnew String(pOptionSelfCloseAction->IPAddress);
			}
			//Mac地址
			if (pOptionSelfCloseAction->MacAddress != nullptr)
			{
				field->MacAddress = gcnew String(pOptionSelfCloseAction->MacAddress);
			}
		}
		
		m_pAdapter->OnErrRtnOptionSelfCloseAction(field, RspInfoField(pRspInfo));
	};

	// 申请组合通知
	void CTraderSpi::OnRtnCombAction(CThostFtdcCombActionField *pCombAction)
	{
		if (m_pAdapter->OnRtnCombAction_delegate == nullptr) return;
		
		CtpNetCombActionField^ field = nullptr;
		if (pCombAction != nullptr)
		{
			field = gcnew CtpNetCombActionField;
			
			//经纪公司代码
			if (pCombAction->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pCombAction->BrokerID);
			}
			//投资者代码
			if (pCombAction->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pCombAction->InvestorID);
			}
			//合约代码
			if (pCombAction->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pCombAction->InstrumentID);
			}
			//组合引用
			if (pCombAction->CombActionRef != nullptr)
			{
				field->CombActionRef = gcnew String(pCombAction->CombActionRef);
			}
			//用户代码
			if (pCombAction->UserID != nullptr)
			{
				field->UserID = gcnew String(pCombAction->UserID);
			}
			//买卖方向
			field->Direction = (CtpNetDirectionType)pCombAction->Direction;
			//数量
			field->Volume = pCombAction->Volume;
			//组合指令方向
			field->CombDirection = (CtpNetCombDirectionType)pCombAction->CombDirection;
			//投机套保标志
			field->HedgeFlag = (CtpNetHedgeFlagType)pCombAction->HedgeFlag;
			//本地申请组合编号
			if (pCombAction->ActionLocalID != nullptr)
			{
				field->ActionLocalID = gcnew String(pCombAction->ActionLocalID);
			}
			//交易所代码
			if (pCombAction->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pCombAction->ExchangeID);
			}
			//会员代码
			if (pCombAction->ParticipantID != nullptr)
			{
				field->ParticipantID = gcnew String(pCombAction->ParticipantID);
			}
			//客户代码
			if (pCombAction->ClientID != nullptr)
			{
				field->ClientID = gcnew String(pCombAction->ClientID);
			}
			//合约在交易所的代码
			if (pCombAction->ExchangeInstID != nullptr)
			{
				field->ExchangeInstID = gcnew String(pCombAction->ExchangeInstID);
			}
			//交易所交易员代码
			if (pCombAction->TraderID != nullptr)
			{
				field->TraderID = gcnew String(pCombAction->TraderID);
			}
			//安装编号
			field->InstallID = pCombAction->InstallID;
			//组合状态
			field->ActionStatus = (CtpNetOrderActionStatusType)pCombAction->ActionStatus;
			//报单提示序号
			field->NotifySequence = pCombAction->NotifySequence;
			//交易日
			if (pCombAction->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pCombAction->TradingDay);
			}
			//结算编号
			field->SettlementID = pCombAction->SettlementID;
			//序号
			field->SequenceNo = pCombAction->SequenceNo;
			//前置编号
			field->FrontID = pCombAction->FrontID;
			//会话编号
			field->SessionID = pCombAction->SessionID;
			//用户端产品信息
			if (pCombAction->UserProductInfo != nullptr)
			{
				field->UserProductInfo = gcnew String(pCombAction->UserProductInfo);
			}
			//状态信息
			if (pCombAction->StatusMsg != nullptr)
			{
				field->StatusMsg = gcnew String(pCombAction->StatusMsg);
			}
			//IP地址
			if (pCombAction->IPAddress != nullptr)
			{
				field->IPAddress = gcnew String(pCombAction->IPAddress);
			}
			//Mac地址
			if (pCombAction->MacAddress != nullptr)
			{
				field->MacAddress = gcnew String(pCombAction->MacAddress);
			}
			//组合编号
			if (pCombAction->ComTradeID != nullptr)
			{
				field->ComTradeID = gcnew String(pCombAction->ComTradeID);
			}
			//营业部编号
			if (pCombAction->BranchID != nullptr)
			{
				field->BranchID = gcnew String(pCombAction->BranchID);
			}
			//投资单元代码
			if (pCombAction->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pCombAction->InvestUnitID);
			}
		}
		
		m_pAdapter->OnRtnCombAction(field);
	};

	// 申请组合录入错误回报
	void CTraderSpi::OnErrRtnCombActionInsert(CThostFtdcInputCombActionField *pInputCombAction, CThostFtdcRspInfoField *pRspInfo)
	{
		if (m_pAdapter->OnErrRtnCombActionInsert_delegate == nullptr) return;
		
		CtpNetInputCombActionField^ field = nullptr;
		if (pInputCombAction != nullptr)
		{
			field = gcnew CtpNetInputCombActionField;
			
			//经纪公司代码
			if (pInputCombAction->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pInputCombAction->BrokerID);
			}
			//投资者代码
			if (pInputCombAction->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pInputCombAction->InvestorID);
			}
			//合约代码
			if (pInputCombAction->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pInputCombAction->InstrumentID);
			}
			//组合引用
			if (pInputCombAction->CombActionRef != nullptr)
			{
				field->CombActionRef = gcnew String(pInputCombAction->CombActionRef);
			}
			//用户代码
			if (pInputCombAction->UserID != nullptr)
			{
				field->UserID = gcnew String(pInputCombAction->UserID);
			}
			//买卖方向
			field->Direction = (CtpNetDirectionType)pInputCombAction->Direction;
			//数量
			field->Volume = pInputCombAction->Volume;
			//组合指令方向
			field->CombDirection = (CtpNetCombDirectionType)pInputCombAction->CombDirection;
			//投机套保标志
			field->HedgeFlag = (CtpNetHedgeFlagType)pInputCombAction->HedgeFlag;
			//交易所代码
			if (pInputCombAction->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pInputCombAction->ExchangeID);
			}
			//IP地址
			if (pInputCombAction->IPAddress != nullptr)
			{
				field->IPAddress = gcnew String(pInputCombAction->IPAddress);
			}
			//Mac地址
			if (pInputCombAction->MacAddress != nullptr)
			{
				field->MacAddress = gcnew String(pInputCombAction->MacAddress);
			}
			//投资单元代码
			if (pInputCombAction->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pInputCombAction->InvestUnitID);
			}
		}
		
		m_pAdapter->OnErrRtnCombActionInsert(field, RspInfoField(pRspInfo));
	};

	// 请求查询签约银行响应
	void CTraderSpi::OnRspQryContractBank(CThostFtdcContractBankField *pContractBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryContractBank_delegate == nullptr) return;
		
		CtpNetContractBankField^ field = nullptr;
		if (pContractBank != nullptr)
		{
			field = gcnew CtpNetContractBankField;
			
			//经纪公司代码
			if (pContractBank->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pContractBank->BrokerID);
			}
			//银行代码
			if (pContractBank->BankID != nullptr)
			{
				field->BankID = gcnew String(pContractBank->BankID);
			}
			//银行分中心代码
			if (pContractBank->BankBrchID != nullptr)
			{
				field->BankBrchID = gcnew String(pContractBank->BankBrchID);
			}
			//银行名称
			if (pContractBank->BankName != nullptr)
			{
				field->BankName = gcnew String(pContractBank->BankName);
			}
		}
		
		m_pAdapter->OnRspQryContractBank(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询预埋单响应
	void CTraderSpi::OnRspQryParkedOrder(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryParkedOrder_delegate == nullptr) return;
		
		CtpNetParkedOrderField^ field = nullptr;
		if (pParkedOrder != nullptr)
		{
			field = gcnew CtpNetParkedOrderField;
			
			//经纪公司代码
			if (pParkedOrder->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pParkedOrder->BrokerID);
			}
			//投资者代码
			if (pParkedOrder->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pParkedOrder->InvestorID);
			}
			//合约代码
			if (pParkedOrder->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pParkedOrder->InstrumentID);
			}
			//报单引用
			if (pParkedOrder->OrderRef != nullptr)
			{
				field->OrderRef = gcnew String(pParkedOrder->OrderRef);
			}
			//用户代码
			if (pParkedOrder->UserID != nullptr)
			{
				field->UserID = gcnew String(pParkedOrder->UserID);
			}
			//报单价格条件
			field->OrderPriceType = (CtpNetOrderPriceTypeType)pParkedOrder->OrderPriceType;
			//买卖方向
			field->Direction = (CtpNetDirectionType)pParkedOrder->Direction;
			//组合开平标志1
			field->CombOffsetFlag1 = (CtpNetOffsetFlagType)pParkedOrder->CombOffsetFlag[0];
			//组合开平标志2
			field->CombOffsetFlag2 = (CtpNetOffsetFlagType)pParkedOrder->CombOffsetFlag[1];
			//组合开平标志3
			field->CombOffsetFlag3 = (CtpNetOffsetFlagType)pParkedOrder->CombOffsetFlag[2];
			//组合开平标志4
			field->CombOffsetFlag4 = (CtpNetOffsetFlagType)pParkedOrder->CombOffsetFlag[3];
			//组合开平标志5
			field->CombOffsetFlag5 = (CtpNetOffsetFlagType)pParkedOrder->CombOffsetFlag[4];
			//组合投机套保标志1
			field->CombHedgeFlag1 = (CtpNetHedgeFlagType)pParkedOrder->CombHedgeFlag[0];
			//组合投机套保标志2
			field->CombHedgeFlag2 = (CtpNetHedgeFlagType)pParkedOrder->CombHedgeFlag[1];
			//组合投机套保标志3
			field->CombHedgeFlag3 = (CtpNetHedgeFlagType)pParkedOrder->CombHedgeFlag[2];
			//组合投机套保标志4
			field->CombHedgeFlag4 = (CtpNetHedgeFlagType)pParkedOrder->CombHedgeFlag[3];
			//组合投机套保标志5
			field->CombHedgeFlag5 = (CtpNetHedgeFlagType)pParkedOrder->CombHedgeFlag[4];
			//价格
			field->LimitPrice = pParkedOrder->LimitPrice;
			//数量
			field->VolumeTotalOriginal = pParkedOrder->VolumeTotalOriginal;
			//有效期类型
			field->TimeCondition = (CtpNetTimeConditionType)pParkedOrder->TimeCondition;
			//GTD日期
			if (pParkedOrder->GTDDate != nullptr)
			{
				field->GTDDate = gcnew String(pParkedOrder->GTDDate);
			}
			//成交量类型
			field->VolumeCondition = (CtpNetVolumeConditionType)pParkedOrder->VolumeCondition;
			//最小成交量
			field->MinVolume = pParkedOrder->MinVolume;
			//触发条件
			field->ContingentCondition = (CtpNetContingentConditionType)pParkedOrder->ContingentCondition;
			//止损价
			field->StopPrice = pParkedOrder->StopPrice;
			//强平原因
			field->ForceCloseReason = (CtpNetForceCloseReasonType)pParkedOrder->ForceCloseReason;
			//自动挂起标志
			field->IsAutoSuspend = pParkedOrder->IsAutoSuspend;
			//业务单元
			if (pParkedOrder->BusinessUnit != nullptr)
			{
				field->BusinessUnit = gcnew String(pParkedOrder->BusinessUnit);
			}
			//请求编号
			field->RequestID = pParkedOrder->RequestID;
			//用户强评标志
			field->UserForceClose = pParkedOrder->UserForceClose;
			//交易所代码
			if (pParkedOrder->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pParkedOrder->ExchangeID);
			}
			//预埋报单编号
			if (pParkedOrder->ParkedOrderID != nullptr)
			{
				field->ParkedOrderID = gcnew String(pParkedOrder->ParkedOrderID);
			}
			//用户类型
			field->UserType = (CtpNetUserTypeType)pParkedOrder->UserType;
			//预埋单状态
			field->Status = (CtpNetParkedOrderStatusType)pParkedOrder->Status;
			//错误代码
			field->ErrorID = pParkedOrder->ErrorID;
			//错误信息
			if (pParkedOrder->ErrorMsg != nullptr)
			{
				field->ErrorMsg = gcnew String(pParkedOrder->ErrorMsg);
			}
			//互换单标志
			field->IsSwapOrder = pParkedOrder->IsSwapOrder;
			//资金账号
			if (pParkedOrder->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pParkedOrder->AccountID);
			}
			//币种代码
			if (pParkedOrder->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pParkedOrder->CurrencyID);
			}
			//交易编码
			if (pParkedOrder->ClientID != nullptr)
			{
				field->ClientID = gcnew String(pParkedOrder->ClientID);
			}
			//投资单元代码
			if (pParkedOrder->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pParkedOrder->InvestUnitID);
			}
			//IP地址
			if (pParkedOrder->IPAddress != nullptr)
			{
				field->IPAddress = gcnew String(pParkedOrder->IPAddress);
			}
			//Mac地址
			if (pParkedOrder->MacAddress != nullptr)
			{
				field->MacAddress = gcnew String(pParkedOrder->MacAddress);
			}
		}
		
		m_pAdapter->OnRspQryParkedOrder(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询预埋撤单响应
	void CTraderSpi::OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryParkedOrderAction_delegate == nullptr) return;
		
		CtpNetParkedOrderActionField^ field = nullptr;
		if (pParkedOrderAction != nullptr)
		{
			field = gcnew CtpNetParkedOrderActionField;
			
			//经纪公司代码
			if (pParkedOrderAction->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pParkedOrderAction->BrokerID);
			}
			//投资者代码
			if (pParkedOrderAction->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pParkedOrderAction->InvestorID);
			}
			//报单操作引用
			field->OrderActionRef = pParkedOrderAction->OrderActionRef;
			//报单引用
			if (pParkedOrderAction->OrderRef != nullptr)
			{
				field->OrderRef = gcnew String(pParkedOrderAction->OrderRef);
			}
			//请求编号
			field->RequestID = pParkedOrderAction->RequestID;
			//前置编号
			field->FrontID = pParkedOrderAction->FrontID;
			//会话编号
			field->SessionID = pParkedOrderAction->SessionID;
			//交易所代码
			if (pParkedOrderAction->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pParkedOrderAction->ExchangeID);
			}
			//报单编号
			if (pParkedOrderAction->OrderSysID != nullptr)
			{
				field->OrderSysID = gcnew String(pParkedOrderAction->OrderSysID);
			}
			//操作标志
			field->ActionFlag = (CtpNetActionFlagType)pParkedOrderAction->ActionFlag;
			//价格
			field->LimitPrice = pParkedOrderAction->LimitPrice;
			//数量变化
			field->VolumeChange = pParkedOrderAction->VolumeChange;
			//用户代码
			if (pParkedOrderAction->UserID != nullptr)
			{
				field->UserID = gcnew String(pParkedOrderAction->UserID);
			}
			//合约代码
			if (pParkedOrderAction->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pParkedOrderAction->InstrumentID);
			}
			//预埋撤单单编号
			if (pParkedOrderAction->ParkedOrderActionID != nullptr)
			{
				field->ParkedOrderActionID = gcnew String(pParkedOrderAction->ParkedOrderActionID);
			}
			//用户类型
			field->UserType = (CtpNetUserTypeType)pParkedOrderAction->UserType;
			//预埋撤单状态
			field->Status = (CtpNetParkedOrderStatusType)pParkedOrderAction->Status;
			//错误代码
			field->ErrorID = pParkedOrderAction->ErrorID;
			//错误信息
			if (pParkedOrderAction->ErrorMsg != nullptr)
			{
				field->ErrorMsg = gcnew String(pParkedOrderAction->ErrorMsg);
			}
			//投资单元代码
			if (pParkedOrderAction->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pParkedOrderAction->InvestUnitID);
			}
			//IP地址
			if (pParkedOrderAction->IPAddress != nullptr)
			{
				field->IPAddress = gcnew String(pParkedOrderAction->IPAddress);
			}
			//Mac地址
			if (pParkedOrderAction->MacAddress != nullptr)
			{
				field->MacAddress = gcnew String(pParkedOrderAction->MacAddress);
			}
		}
		
		m_pAdapter->OnRspQryParkedOrderAction(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询交易通知响应
	void CTraderSpi::OnRspQryTradingNotice(CThostFtdcTradingNoticeField *pTradingNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryTradingNotice_delegate == nullptr) return;
		
		CtpNetTradingNoticeField^ field = nullptr;
		if (pTradingNotice != nullptr)
		{
			field = gcnew CtpNetTradingNoticeField;
			
			//经纪公司代码
			if (pTradingNotice->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pTradingNotice->BrokerID);
			}
			//投资者范围
			field->InvestorRange = (CtpNetInvestorRangeType)pTradingNotice->InvestorRange;
			//投资者代码
			if (pTradingNotice->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pTradingNotice->InvestorID);
			}
			//序列系列号
			field->SequenceSeries = pTradingNotice->SequenceSeries;
			//用户代码
			if (pTradingNotice->UserID != nullptr)
			{
				field->UserID = gcnew String(pTradingNotice->UserID);
			}
			//发送时间
			if (pTradingNotice->SendTime != nullptr)
			{
				field->SendTime = gcnew String(pTradingNotice->SendTime);
			}
			//序列号
			field->SequenceNo = pTradingNotice->SequenceNo;
			//消息正文
			if (pTradingNotice->FieldContent != nullptr)
			{
				field->FieldContent = gcnew String(pTradingNotice->FieldContent);
			}
			//投资单元代码
			if (pTradingNotice->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pTradingNotice->InvestUnitID);
			}
		}
		
		m_pAdapter->OnRspQryTradingNotice(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询经纪公司交易参数响应
	void CTraderSpi::OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField *pBrokerTradingParams, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryBrokerTradingParams_delegate == nullptr) return;
		
		CtpNetBrokerTradingParamsField^ field = nullptr;
		if (pBrokerTradingParams != nullptr)
		{
			field = gcnew CtpNetBrokerTradingParamsField;
			
			//经纪公司代码
			if (pBrokerTradingParams->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pBrokerTradingParams->BrokerID);
			}
			//投资者代码
			if (pBrokerTradingParams->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pBrokerTradingParams->InvestorID);
			}
			//保证金价格类型
			field->MarginPriceType = (CtpNetMarginPriceTypeType)pBrokerTradingParams->MarginPriceType;
			//盈亏算法
			field->Algorithm = (CtpNetAlgorithmType)pBrokerTradingParams->Algorithm;
			//可用是否包含平仓盈利
			field->AvailIncludeCloseProfit = (CtpNetIncludeCloseProfitType)pBrokerTradingParams->AvailIncludeCloseProfit;
			//币种代码
			if (pBrokerTradingParams->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pBrokerTradingParams->CurrencyID);
			}
			//期权权利金价格类型
			field->OptionRoyaltyPriceType = (CtpNetOptionRoyaltyPriceTypeType)pBrokerTradingParams->OptionRoyaltyPriceType;
			//投资者帐号
			if (pBrokerTradingParams->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pBrokerTradingParams->AccountID);
			}
		}
		
		m_pAdapter->OnRspQryBrokerTradingParams(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询经纪公司交易算法响应
	void CTraderSpi::OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField *pBrokerTradingAlgos, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQryBrokerTradingAlgos_delegate == nullptr) return;
		
		CtpNetBrokerTradingAlgosField^ field = nullptr;
		if (pBrokerTradingAlgos != nullptr)
		{
			field = gcnew CtpNetBrokerTradingAlgosField;
			
			//经纪公司代码
			if (pBrokerTradingAlgos->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pBrokerTradingAlgos->BrokerID);
			}
			//交易所代码
			if (pBrokerTradingAlgos->ExchangeID != nullptr)
			{
				field->ExchangeID = gcnew String(pBrokerTradingAlgos->ExchangeID);
			}
			//合约代码
			if (pBrokerTradingAlgos->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pBrokerTradingAlgos->InstrumentID);
			}
			//持仓处理算法编号
			field->HandlePositionAlgoID = (CtpNetHandlePositionAlgoIDType)pBrokerTradingAlgos->HandlePositionAlgoID;
			//寻找保证金率算法编号
			field->FindMarginRateAlgoID = (CtpNetFindMarginRateAlgoIDType)pBrokerTradingAlgos->FindMarginRateAlgoID;
			//资金处理算法编号
			field->HandleTradingAccountAlgoID = (CtpNetHandleTradingAccountAlgoIDType)pBrokerTradingAlgos->HandleTradingAccountAlgoID;
		}
		
		m_pAdapter->OnRspQryBrokerTradingAlgos(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 请求查询监控中心用户令牌
	void CTraderSpi::OnRspQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField *pQueryCFMMCTradingAccountToken, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQueryCFMMCTradingAccountToken_delegate == nullptr) return;
		
		CtpNetQueryCFMMCTradingAccountTokenField^ field = nullptr;
		if (pQueryCFMMCTradingAccountToken != nullptr)
		{
			field = gcnew CtpNetQueryCFMMCTradingAccountTokenField;
			
			//经纪公司代码
			if (pQueryCFMMCTradingAccountToken->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pQueryCFMMCTradingAccountToken->BrokerID);
			}
			//投资者代码
			if (pQueryCFMMCTradingAccountToken->InvestorID != nullptr)
			{
				field->InvestorID = gcnew String(pQueryCFMMCTradingAccountToken->InvestorID);
			}
			//投资单元代码
			if (pQueryCFMMCTradingAccountToken->InvestUnitID != nullptr)
			{
				field->InvestUnitID = gcnew String(pQueryCFMMCTradingAccountToken->InvestUnitID);
			}
		}
		
		m_pAdapter->OnRspQueryCFMMCTradingAccountToken(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 银行发起银行资金转期货通知
	void CTraderSpi::OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField *pRspTransfer)
	{
		if (m_pAdapter->OnRtnFromBankToFutureByBank_delegate == nullptr) return;
		
		CtpNetRspTransferField^ field = nullptr;
		if (pRspTransfer != nullptr)
		{
			field = gcnew CtpNetRspTransferField;
			
			//业务功能码
			if (pRspTransfer->TradeCode != nullptr)
			{
				field->TradeCode = gcnew String(pRspTransfer->TradeCode);
			}
			//银行代码
			if (pRspTransfer->BankID != nullptr)
			{
				field->BankID = gcnew String(pRspTransfer->BankID);
			}
			//银行分支机构代码
			if (pRspTransfer->BankBranchID != nullptr)
			{
				field->BankBranchID = gcnew String(pRspTransfer->BankBranchID);
			}
			//期商代码
			if (pRspTransfer->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pRspTransfer->BrokerID);
			}
			//期商分支机构代码
			if (pRspTransfer->BrokerBranchID != nullptr)
			{
				field->BrokerBranchID = gcnew String(pRspTransfer->BrokerBranchID);
			}
			//交易日期
			if (pRspTransfer->TradeDate != nullptr)
			{
				field->TradeDate = gcnew String(pRspTransfer->TradeDate);
			}
			//交易时间
			if (pRspTransfer->TradeTime != nullptr)
			{
				field->TradeTime = gcnew String(pRspTransfer->TradeTime);
			}
			//银行流水号
			if (pRspTransfer->BankSerial != nullptr)
			{
				field->BankSerial = gcnew String(pRspTransfer->BankSerial);
			}
			//交易系统日期
			if (pRspTransfer->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pRspTransfer->TradingDay);
			}
			//银期平台消息流水号
			field->PlateSerial = pRspTransfer->PlateSerial;
			//最后分片标志
			field->LastFragment = (CtpNetLastFragmentType)pRspTransfer->LastFragment;
			//会话号
			field->SessionID = pRspTransfer->SessionID;
			//客户姓名
			if (pRspTransfer->CustomerName != nullptr)
			{
				field->CustomerName = gcnew String(pRspTransfer->CustomerName);
			}
			//证件类型
			field->IdCardType = (CtpNetIdCardTypeType)pRspTransfer->IdCardType;
			//证件号码
			if (pRspTransfer->IdentifiedCardNo != nullptr)
			{
				field->IdentifiedCardNo = gcnew String(pRspTransfer->IdentifiedCardNo);
			}
			//客户类型
			field->CustType = (CtpNetCustTypeType)pRspTransfer->CustType;
			//银行帐号
			if (pRspTransfer->BankAccount != nullptr)
			{
				field->BankAccount = gcnew String(pRspTransfer->BankAccount);
			}
			//银行密码
			if (pRspTransfer->BankPassWord != nullptr)
			{
				field->BankPassWord = gcnew String(pRspTransfer->BankPassWord);
			}
			//投资者帐号
			if (pRspTransfer->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pRspTransfer->AccountID);
			}
			//期货密码
			if (pRspTransfer->Password != nullptr)
			{
				field->Password = gcnew String(pRspTransfer->Password);
			}
			//安装编号
			field->InstallID = pRspTransfer->InstallID;
			//期货公司流水号
			field->FutureSerial = pRspTransfer->FutureSerial;
			//用户标识
			if (pRspTransfer->UserID != nullptr)
			{
				field->UserID = gcnew String(pRspTransfer->UserID);
			}
			//验证客户证件号码标志
			field->VerifyCertNoFlag = (CtpNetYesNoIndicatorType)pRspTransfer->VerifyCertNoFlag;
			//币种代码
			if (pRspTransfer->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pRspTransfer->CurrencyID);
			}
			//转帐金额
			field->TradeAmount = pRspTransfer->TradeAmount;
			//期货可取金额
			field->FutureFetchAmount = pRspTransfer->FutureFetchAmount;
			//费用支付标志
			field->FeePayFlag = (CtpNetFeePayFlagType)pRspTransfer->FeePayFlag;
			//应收客户费用
			field->CustFee = pRspTransfer->CustFee;
			//应收期货公司费用
			field->BrokerFee = pRspTransfer->BrokerFee;
			//发送方给接收方的消息
			if (pRspTransfer->Message != nullptr)
			{
				field->Message = gcnew String(pRspTransfer->Message);
			}
			//摘要
			if (pRspTransfer->Digest != nullptr)
			{
				field->Digest = gcnew String(pRspTransfer->Digest);
			}
			//银行帐号类型
			field->BankAccType = (CtpNetBankAccTypeType)pRspTransfer->BankAccType;
			//渠道标志
			if (pRspTransfer->DeviceID != nullptr)
			{
				field->DeviceID = gcnew String(pRspTransfer->DeviceID);
			}
			//期货单位帐号类型
			field->BankSecuAccType = (CtpNetBankAccTypeType)pRspTransfer->BankSecuAccType;
			//期货公司银行编码
			if (pRspTransfer->BrokerIDByBank != nullptr)
			{
				field->BrokerIDByBank = gcnew String(pRspTransfer->BrokerIDByBank);
			}
			//期货单位帐号
			if (pRspTransfer->BankSecuAcc != nullptr)
			{
				field->BankSecuAcc = gcnew String(pRspTransfer->BankSecuAcc);
			}
			//银行密码标志
			field->BankPwdFlag = (CtpNetPwdFlagType)pRspTransfer->BankPwdFlag;
			//期货资金密码核对标志
			field->SecuPwdFlag = (CtpNetPwdFlagType)pRspTransfer->SecuPwdFlag;
			//交易柜员
			if (pRspTransfer->OperNo != nullptr)
			{
				field->OperNo = gcnew String(pRspTransfer->OperNo);
			}
			//请求编号
			field->RequestID = pRspTransfer->RequestID;
			//交易ID
			field->TID = pRspTransfer->TID;
			//转账交易状态
			field->TransferStatus = (CtpNetTransferStatusType)pRspTransfer->TransferStatus;
			//错误代码
			field->ErrorID = pRspTransfer->ErrorID;
			//错误信息
			if (pRspTransfer->ErrorMsg != nullptr)
			{
				field->ErrorMsg = gcnew String(pRspTransfer->ErrorMsg);
			}
			//长客户姓名
			if (pRspTransfer->LongCustomerName != nullptr)
			{
				field->LongCustomerName = gcnew String(pRspTransfer->LongCustomerName);
			}
		}
		
		m_pAdapter->OnRtnFromBankToFutureByBank(field);
	};

	// 银行发起期货资金转银行通知
	void CTraderSpi::OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField *pRspTransfer)
	{
		if (m_pAdapter->OnRtnFromFutureToBankByBank_delegate == nullptr) return;
		
		CtpNetRspTransferField^ field = nullptr;
		if (pRspTransfer != nullptr)
		{
			field = gcnew CtpNetRspTransferField;
			
			//业务功能码
			if (pRspTransfer->TradeCode != nullptr)
			{
				field->TradeCode = gcnew String(pRspTransfer->TradeCode);
			}
			//银行代码
			if (pRspTransfer->BankID != nullptr)
			{
				field->BankID = gcnew String(pRspTransfer->BankID);
			}
			//银行分支机构代码
			if (pRspTransfer->BankBranchID != nullptr)
			{
				field->BankBranchID = gcnew String(pRspTransfer->BankBranchID);
			}
			//期商代码
			if (pRspTransfer->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pRspTransfer->BrokerID);
			}
			//期商分支机构代码
			if (pRspTransfer->BrokerBranchID != nullptr)
			{
				field->BrokerBranchID = gcnew String(pRspTransfer->BrokerBranchID);
			}
			//交易日期
			if (pRspTransfer->TradeDate != nullptr)
			{
				field->TradeDate = gcnew String(pRspTransfer->TradeDate);
			}
			//交易时间
			if (pRspTransfer->TradeTime != nullptr)
			{
				field->TradeTime = gcnew String(pRspTransfer->TradeTime);
			}
			//银行流水号
			if (pRspTransfer->BankSerial != nullptr)
			{
				field->BankSerial = gcnew String(pRspTransfer->BankSerial);
			}
			//交易系统日期
			if (pRspTransfer->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pRspTransfer->TradingDay);
			}
			//银期平台消息流水号
			field->PlateSerial = pRspTransfer->PlateSerial;
			//最后分片标志
			field->LastFragment = (CtpNetLastFragmentType)pRspTransfer->LastFragment;
			//会话号
			field->SessionID = pRspTransfer->SessionID;
			//客户姓名
			if (pRspTransfer->CustomerName != nullptr)
			{
				field->CustomerName = gcnew String(pRspTransfer->CustomerName);
			}
			//证件类型
			field->IdCardType = (CtpNetIdCardTypeType)pRspTransfer->IdCardType;
			//证件号码
			if (pRspTransfer->IdentifiedCardNo != nullptr)
			{
				field->IdentifiedCardNo = gcnew String(pRspTransfer->IdentifiedCardNo);
			}
			//客户类型
			field->CustType = (CtpNetCustTypeType)pRspTransfer->CustType;
			//银行帐号
			if (pRspTransfer->BankAccount != nullptr)
			{
				field->BankAccount = gcnew String(pRspTransfer->BankAccount);
			}
			//银行密码
			if (pRspTransfer->BankPassWord != nullptr)
			{
				field->BankPassWord = gcnew String(pRspTransfer->BankPassWord);
			}
			//投资者帐号
			if (pRspTransfer->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pRspTransfer->AccountID);
			}
			//期货密码
			if (pRspTransfer->Password != nullptr)
			{
				field->Password = gcnew String(pRspTransfer->Password);
			}
			//安装编号
			field->InstallID = pRspTransfer->InstallID;
			//期货公司流水号
			field->FutureSerial = pRspTransfer->FutureSerial;
			//用户标识
			if (pRspTransfer->UserID != nullptr)
			{
				field->UserID = gcnew String(pRspTransfer->UserID);
			}
			//验证客户证件号码标志
			field->VerifyCertNoFlag = (CtpNetYesNoIndicatorType)pRspTransfer->VerifyCertNoFlag;
			//币种代码
			if (pRspTransfer->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pRspTransfer->CurrencyID);
			}
			//转帐金额
			field->TradeAmount = pRspTransfer->TradeAmount;
			//期货可取金额
			field->FutureFetchAmount = pRspTransfer->FutureFetchAmount;
			//费用支付标志
			field->FeePayFlag = (CtpNetFeePayFlagType)pRspTransfer->FeePayFlag;
			//应收客户费用
			field->CustFee = pRspTransfer->CustFee;
			//应收期货公司费用
			field->BrokerFee = pRspTransfer->BrokerFee;
			//发送方给接收方的消息
			if (pRspTransfer->Message != nullptr)
			{
				field->Message = gcnew String(pRspTransfer->Message);
			}
			//摘要
			if (pRspTransfer->Digest != nullptr)
			{
				field->Digest = gcnew String(pRspTransfer->Digest);
			}
			//银行帐号类型
			field->BankAccType = (CtpNetBankAccTypeType)pRspTransfer->BankAccType;
			//渠道标志
			if (pRspTransfer->DeviceID != nullptr)
			{
				field->DeviceID = gcnew String(pRspTransfer->DeviceID);
			}
			//期货单位帐号类型
			field->BankSecuAccType = (CtpNetBankAccTypeType)pRspTransfer->BankSecuAccType;
			//期货公司银行编码
			if (pRspTransfer->BrokerIDByBank != nullptr)
			{
				field->BrokerIDByBank = gcnew String(pRspTransfer->BrokerIDByBank);
			}
			//期货单位帐号
			if (pRspTransfer->BankSecuAcc != nullptr)
			{
				field->BankSecuAcc = gcnew String(pRspTransfer->BankSecuAcc);
			}
			//银行密码标志
			field->BankPwdFlag = (CtpNetPwdFlagType)pRspTransfer->BankPwdFlag;
			//期货资金密码核对标志
			field->SecuPwdFlag = (CtpNetPwdFlagType)pRspTransfer->SecuPwdFlag;
			//交易柜员
			if (pRspTransfer->OperNo != nullptr)
			{
				field->OperNo = gcnew String(pRspTransfer->OperNo);
			}
			//请求编号
			field->RequestID = pRspTransfer->RequestID;
			//交易ID
			field->TID = pRspTransfer->TID;
			//转账交易状态
			field->TransferStatus = (CtpNetTransferStatusType)pRspTransfer->TransferStatus;
			//错误代码
			field->ErrorID = pRspTransfer->ErrorID;
			//错误信息
			if (pRspTransfer->ErrorMsg != nullptr)
			{
				field->ErrorMsg = gcnew String(pRspTransfer->ErrorMsg);
			}
			//长客户姓名
			if (pRspTransfer->LongCustomerName != nullptr)
			{
				field->LongCustomerName = gcnew String(pRspTransfer->LongCustomerName);
			}
		}
		
		m_pAdapter->OnRtnFromFutureToBankByBank(field);
	};

	// 银行发起冲正银行转期货通知
	void CTraderSpi::OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField *pRspRepeal)
	{
		if (m_pAdapter->OnRtnRepealFromBankToFutureByBank_delegate == nullptr) return;
		
		CtpNetRspRepealField^ field = nullptr;
		if (pRspRepeal != nullptr)
		{
			field = gcnew CtpNetRspRepealField;
			
			//冲正时间间隔
			field->RepealTimeInterval = pRspRepeal->RepealTimeInterval;
			//已经冲正次数
			field->RepealedTimes = pRspRepeal->RepealedTimes;
			//银行冲正标志
			field->BankRepealFlag = (CtpNetBankRepealFlagType)pRspRepeal->BankRepealFlag;
			//期商冲正标志
			field->BrokerRepealFlag = (CtpNetBrokerRepealFlagType)pRspRepeal->BrokerRepealFlag;
			//被冲正平台流水号
			field->PlateRepealSerial = pRspRepeal->PlateRepealSerial;
			//被冲正银行流水号
			if (pRspRepeal->BankRepealSerial != nullptr)
			{
				field->BankRepealSerial = gcnew String(pRspRepeal->BankRepealSerial);
			}
			//被冲正期货流水号
			field->FutureRepealSerial = pRspRepeal->FutureRepealSerial;
			//业务功能码
			if (pRspRepeal->TradeCode != nullptr)
			{
				field->TradeCode = gcnew String(pRspRepeal->TradeCode);
			}
			//银行代码
			if (pRspRepeal->BankID != nullptr)
			{
				field->BankID = gcnew String(pRspRepeal->BankID);
			}
			//银行分支机构代码
			if (pRspRepeal->BankBranchID != nullptr)
			{
				field->BankBranchID = gcnew String(pRspRepeal->BankBranchID);
			}
			//期商代码
			if (pRspRepeal->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pRspRepeal->BrokerID);
			}
			//期商分支机构代码
			if (pRspRepeal->BrokerBranchID != nullptr)
			{
				field->BrokerBranchID = gcnew String(pRspRepeal->BrokerBranchID);
			}
			//交易日期
			if (pRspRepeal->TradeDate != nullptr)
			{
				field->TradeDate = gcnew String(pRspRepeal->TradeDate);
			}
			//交易时间
			if (pRspRepeal->TradeTime != nullptr)
			{
				field->TradeTime = gcnew String(pRspRepeal->TradeTime);
			}
			//银行流水号
			if (pRspRepeal->BankSerial != nullptr)
			{
				field->BankSerial = gcnew String(pRspRepeal->BankSerial);
			}
			//交易系统日期
			if (pRspRepeal->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pRspRepeal->TradingDay);
			}
			//银期平台消息流水号
			field->PlateSerial = pRspRepeal->PlateSerial;
			//最后分片标志
			field->LastFragment = (CtpNetLastFragmentType)pRspRepeal->LastFragment;
			//会话号
			field->SessionID = pRspRepeal->SessionID;
			//客户姓名
			if (pRspRepeal->CustomerName != nullptr)
			{
				field->CustomerName = gcnew String(pRspRepeal->CustomerName);
			}
			//证件类型
			field->IdCardType = (CtpNetIdCardTypeType)pRspRepeal->IdCardType;
			//证件号码
			if (pRspRepeal->IdentifiedCardNo != nullptr)
			{
				field->IdentifiedCardNo = gcnew String(pRspRepeal->IdentifiedCardNo);
			}
			//客户类型
			field->CustType = (CtpNetCustTypeType)pRspRepeal->CustType;
			//银行帐号
			if (pRspRepeal->BankAccount != nullptr)
			{
				field->BankAccount = gcnew String(pRspRepeal->BankAccount);
			}
			//银行密码
			if (pRspRepeal->BankPassWord != nullptr)
			{
				field->BankPassWord = gcnew String(pRspRepeal->BankPassWord);
			}
			//投资者帐号
			if (pRspRepeal->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pRspRepeal->AccountID);
			}
			//期货密码
			if (pRspRepeal->Password != nullptr)
			{
				field->Password = gcnew String(pRspRepeal->Password);
			}
			//安装编号
			field->InstallID = pRspRepeal->InstallID;
			//期货公司流水号
			field->FutureSerial = pRspRepeal->FutureSerial;
			//用户标识
			if (pRspRepeal->UserID != nullptr)
			{
				field->UserID = gcnew String(pRspRepeal->UserID);
			}
			//验证客户证件号码标志
			field->VerifyCertNoFlag = (CtpNetYesNoIndicatorType)pRspRepeal->VerifyCertNoFlag;
			//币种代码
			if (pRspRepeal->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pRspRepeal->CurrencyID);
			}
			//转帐金额
			field->TradeAmount = pRspRepeal->TradeAmount;
			//期货可取金额
			field->FutureFetchAmount = pRspRepeal->FutureFetchAmount;
			//费用支付标志
			field->FeePayFlag = (CtpNetFeePayFlagType)pRspRepeal->FeePayFlag;
			//应收客户费用
			field->CustFee = pRspRepeal->CustFee;
			//应收期货公司费用
			field->BrokerFee = pRspRepeal->BrokerFee;
			//发送方给接收方的消息
			if (pRspRepeal->Message != nullptr)
			{
				field->Message = gcnew String(pRspRepeal->Message);
			}
			//摘要
			if (pRspRepeal->Digest != nullptr)
			{
				field->Digest = gcnew String(pRspRepeal->Digest);
			}
			//银行帐号类型
			field->BankAccType = (CtpNetBankAccTypeType)pRspRepeal->BankAccType;
			//渠道标志
			if (pRspRepeal->DeviceID != nullptr)
			{
				field->DeviceID = gcnew String(pRspRepeal->DeviceID);
			}
			//期货单位帐号类型
			field->BankSecuAccType = (CtpNetBankAccTypeType)pRspRepeal->BankSecuAccType;
			//期货公司银行编码
			if (pRspRepeal->BrokerIDByBank != nullptr)
			{
				field->BrokerIDByBank = gcnew String(pRspRepeal->BrokerIDByBank);
			}
			//期货单位帐号
			if (pRspRepeal->BankSecuAcc != nullptr)
			{
				field->BankSecuAcc = gcnew String(pRspRepeal->BankSecuAcc);
			}
			//银行密码标志
			field->BankPwdFlag = (CtpNetPwdFlagType)pRspRepeal->BankPwdFlag;
			//期货资金密码核对标志
			field->SecuPwdFlag = (CtpNetPwdFlagType)pRspRepeal->SecuPwdFlag;
			//交易柜员
			if (pRspRepeal->OperNo != nullptr)
			{
				field->OperNo = gcnew String(pRspRepeal->OperNo);
			}
			//请求编号
			field->RequestID = pRspRepeal->RequestID;
			//交易ID
			field->TID = pRspRepeal->TID;
			//转账交易状态
			field->TransferStatus = (CtpNetTransferStatusType)pRspRepeal->TransferStatus;
			//错误代码
			field->ErrorID = pRspRepeal->ErrorID;
			//错误信息
			if (pRspRepeal->ErrorMsg != nullptr)
			{
				field->ErrorMsg = gcnew String(pRspRepeal->ErrorMsg);
			}
			//长客户姓名
			if (pRspRepeal->LongCustomerName != nullptr)
			{
				field->LongCustomerName = gcnew String(pRspRepeal->LongCustomerName);
			}
		}
		
		m_pAdapter->OnRtnRepealFromBankToFutureByBank(field);
	};

	// 银行发起冲正期货转银行通知
	void CTraderSpi::OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField *pRspRepeal)
	{
		if (m_pAdapter->OnRtnRepealFromFutureToBankByBank_delegate == nullptr) return;
		
		CtpNetRspRepealField^ field = nullptr;
		if (pRspRepeal != nullptr)
		{
			field = gcnew CtpNetRspRepealField;
			
			//冲正时间间隔
			field->RepealTimeInterval = pRspRepeal->RepealTimeInterval;
			//已经冲正次数
			field->RepealedTimes = pRspRepeal->RepealedTimes;
			//银行冲正标志
			field->BankRepealFlag = (CtpNetBankRepealFlagType)pRspRepeal->BankRepealFlag;
			//期商冲正标志
			field->BrokerRepealFlag = (CtpNetBrokerRepealFlagType)pRspRepeal->BrokerRepealFlag;
			//被冲正平台流水号
			field->PlateRepealSerial = pRspRepeal->PlateRepealSerial;
			//被冲正银行流水号
			if (pRspRepeal->BankRepealSerial != nullptr)
			{
				field->BankRepealSerial = gcnew String(pRspRepeal->BankRepealSerial);
			}
			//被冲正期货流水号
			field->FutureRepealSerial = pRspRepeal->FutureRepealSerial;
			//业务功能码
			if (pRspRepeal->TradeCode != nullptr)
			{
				field->TradeCode = gcnew String(pRspRepeal->TradeCode);
			}
			//银行代码
			if (pRspRepeal->BankID != nullptr)
			{
				field->BankID = gcnew String(pRspRepeal->BankID);
			}
			//银行分支机构代码
			if (pRspRepeal->BankBranchID != nullptr)
			{
				field->BankBranchID = gcnew String(pRspRepeal->BankBranchID);
			}
			//期商代码
			if (pRspRepeal->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pRspRepeal->BrokerID);
			}
			//期商分支机构代码
			if (pRspRepeal->BrokerBranchID != nullptr)
			{
				field->BrokerBranchID = gcnew String(pRspRepeal->BrokerBranchID);
			}
			//交易日期
			if (pRspRepeal->TradeDate != nullptr)
			{
				field->TradeDate = gcnew String(pRspRepeal->TradeDate);
			}
			//交易时间
			if (pRspRepeal->TradeTime != nullptr)
			{
				field->TradeTime = gcnew String(pRspRepeal->TradeTime);
			}
			//银行流水号
			if (pRspRepeal->BankSerial != nullptr)
			{
				field->BankSerial = gcnew String(pRspRepeal->BankSerial);
			}
			//交易系统日期
			if (pRspRepeal->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pRspRepeal->TradingDay);
			}
			//银期平台消息流水号
			field->PlateSerial = pRspRepeal->PlateSerial;
			//最后分片标志
			field->LastFragment = (CtpNetLastFragmentType)pRspRepeal->LastFragment;
			//会话号
			field->SessionID = pRspRepeal->SessionID;
			//客户姓名
			if (pRspRepeal->CustomerName != nullptr)
			{
				field->CustomerName = gcnew String(pRspRepeal->CustomerName);
			}
			//证件类型
			field->IdCardType = (CtpNetIdCardTypeType)pRspRepeal->IdCardType;
			//证件号码
			if (pRspRepeal->IdentifiedCardNo != nullptr)
			{
				field->IdentifiedCardNo = gcnew String(pRspRepeal->IdentifiedCardNo);
			}
			//客户类型
			field->CustType = (CtpNetCustTypeType)pRspRepeal->CustType;
			//银行帐号
			if (pRspRepeal->BankAccount != nullptr)
			{
				field->BankAccount = gcnew String(pRspRepeal->BankAccount);
			}
			//银行密码
			if (pRspRepeal->BankPassWord != nullptr)
			{
				field->BankPassWord = gcnew String(pRspRepeal->BankPassWord);
			}
			//投资者帐号
			if (pRspRepeal->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pRspRepeal->AccountID);
			}
			//期货密码
			if (pRspRepeal->Password != nullptr)
			{
				field->Password = gcnew String(pRspRepeal->Password);
			}
			//安装编号
			field->InstallID = pRspRepeal->InstallID;
			//期货公司流水号
			field->FutureSerial = pRspRepeal->FutureSerial;
			//用户标识
			if (pRspRepeal->UserID != nullptr)
			{
				field->UserID = gcnew String(pRspRepeal->UserID);
			}
			//验证客户证件号码标志
			field->VerifyCertNoFlag = (CtpNetYesNoIndicatorType)pRspRepeal->VerifyCertNoFlag;
			//币种代码
			if (pRspRepeal->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pRspRepeal->CurrencyID);
			}
			//转帐金额
			field->TradeAmount = pRspRepeal->TradeAmount;
			//期货可取金额
			field->FutureFetchAmount = pRspRepeal->FutureFetchAmount;
			//费用支付标志
			field->FeePayFlag = (CtpNetFeePayFlagType)pRspRepeal->FeePayFlag;
			//应收客户费用
			field->CustFee = pRspRepeal->CustFee;
			//应收期货公司费用
			field->BrokerFee = pRspRepeal->BrokerFee;
			//发送方给接收方的消息
			if (pRspRepeal->Message != nullptr)
			{
				field->Message = gcnew String(pRspRepeal->Message);
			}
			//摘要
			if (pRspRepeal->Digest != nullptr)
			{
				field->Digest = gcnew String(pRspRepeal->Digest);
			}
			//银行帐号类型
			field->BankAccType = (CtpNetBankAccTypeType)pRspRepeal->BankAccType;
			//渠道标志
			if (pRspRepeal->DeviceID != nullptr)
			{
				field->DeviceID = gcnew String(pRspRepeal->DeviceID);
			}
			//期货单位帐号类型
			field->BankSecuAccType = (CtpNetBankAccTypeType)pRspRepeal->BankSecuAccType;
			//期货公司银行编码
			if (pRspRepeal->BrokerIDByBank != nullptr)
			{
				field->BrokerIDByBank = gcnew String(pRspRepeal->BrokerIDByBank);
			}
			//期货单位帐号
			if (pRspRepeal->BankSecuAcc != nullptr)
			{
				field->BankSecuAcc = gcnew String(pRspRepeal->BankSecuAcc);
			}
			//银行密码标志
			field->BankPwdFlag = (CtpNetPwdFlagType)pRspRepeal->BankPwdFlag;
			//期货资金密码核对标志
			field->SecuPwdFlag = (CtpNetPwdFlagType)pRspRepeal->SecuPwdFlag;
			//交易柜员
			if (pRspRepeal->OperNo != nullptr)
			{
				field->OperNo = gcnew String(pRspRepeal->OperNo);
			}
			//请求编号
			field->RequestID = pRspRepeal->RequestID;
			//交易ID
			field->TID = pRspRepeal->TID;
			//转账交易状态
			field->TransferStatus = (CtpNetTransferStatusType)pRspRepeal->TransferStatus;
			//错误代码
			field->ErrorID = pRspRepeal->ErrorID;
			//错误信息
			if (pRspRepeal->ErrorMsg != nullptr)
			{
				field->ErrorMsg = gcnew String(pRspRepeal->ErrorMsg);
			}
			//长客户姓名
			if (pRspRepeal->LongCustomerName != nullptr)
			{
				field->LongCustomerName = gcnew String(pRspRepeal->LongCustomerName);
			}
		}
		
		m_pAdapter->OnRtnRepealFromFutureToBankByBank(field);
	};

	// 期货发起银行资金转期货通知
	void CTraderSpi::OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField *pRspTransfer)
	{
		if (m_pAdapter->OnRtnFromBankToFutureByFuture_delegate == nullptr) return;
		
		CtpNetRspTransferField^ field = nullptr;
		if (pRspTransfer != nullptr)
		{
			field = gcnew CtpNetRspTransferField;
			
			//业务功能码
			if (pRspTransfer->TradeCode != nullptr)
			{
				field->TradeCode = gcnew String(pRspTransfer->TradeCode);
			}
			//银行代码
			if (pRspTransfer->BankID != nullptr)
			{
				field->BankID = gcnew String(pRspTransfer->BankID);
			}
			//银行分支机构代码
			if (pRspTransfer->BankBranchID != nullptr)
			{
				field->BankBranchID = gcnew String(pRspTransfer->BankBranchID);
			}
			//期商代码
			if (pRspTransfer->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pRspTransfer->BrokerID);
			}
			//期商分支机构代码
			if (pRspTransfer->BrokerBranchID != nullptr)
			{
				field->BrokerBranchID = gcnew String(pRspTransfer->BrokerBranchID);
			}
			//交易日期
			if (pRspTransfer->TradeDate != nullptr)
			{
				field->TradeDate = gcnew String(pRspTransfer->TradeDate);
			}
			//交易时间
			if (pRspTransfer->TradeTime != nullptr)
			{
				field->TradeTime = gcnew String(pRspTransfer->TradeTime);
			}
			//银行流水号
			if (pRspTransfer->BankSerial != nullptr)
			{
				field->BankSerial = gcnew String(pRspTransfer->BankSerial);
			}
			//交易系统日期
			if (pRspTransfer->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pRspTransfer->TradingDay);
			}
			//银期平台消息流水号
			field->PlateSerial = pRspTransfer->PlateSerial;
			//最后分片标志
			field->LastFragment = (CtpNetLastFragmentType)pRspTransfer->LastFragment;
			//会话号
			field->SessionID = pRspTransfer->SessionID;
			//客户姓名
			if (pRspTransfer->CustomerName != nullptr)
			{
				field->CustomerName = gcnew String(pRspTransfer->CustomerName);
			}
			//证件类型
			field->IdCardType = (CtpNetIdCardTypeType)pRspTransfer->IdCardType;
			//证件号码
			if (pRspTransfer->IdentifiedCardNo != nullptr)
			{
				field->IdentifiedCardNo = gcnew String(pRspTransfer->IdentifiedCardNo);
			}
			//客户类型
			field->CustType = (CtpNetCustTypeType)pRspTransfer->CustType;
			//银行帐号
			if (pRspTransfer->BankAccount != nullptr)
			{
				field->BankAccount = gcnew String(pRspTransfer->BankAccount);
			}
			//银行密码
			if (pRspTransfer->BankPassWord != nullptr)
			{
				field->BankPassWord = gcnew String(pRspTransfer->BankPassWord);
			}
			//投资者帐号
			if (pRspTransfer->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pRspTransfer->AccountID);
			}
			//期货密码
			if (pRspTransfer->Password != nullptr)
			{
				field->Password = gcnew String(pRspTransfer->Password);
			}
			//安装编号
			field->InstallID = pRspTransfer->InstallID;
			//期货公司流水号
			field->FutureSerial = pRspTransfer->FutureSerial;
			//用户标识
			if (pRspTransfer->UserID != nullptr)
			{
				field->UserID = gcnew String(pRspTransfer->UserID);
			}
			//验证客户证件号码标志
			field->VerifyCertNoFlag = (CtpNetYesNoIndicatorType)pRspTransfer->VerifyCertNoFlag;
			//币种代码
			if (pRspTransfer->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pRspTransfer->CurrencyID);
			}
			//转帐金额
			field->TradeAmount = pRspTransfer->TradeAmount;
			//期货可取金额
			field->FutureFetchAmount = pRspTransfer->FutureFetchAmount;
			//费用支付标志
			field->FeePayFlag = (CtpNetFeePayFlagType)pRspTransfer->FeePayFlag;
			//应收客户费用
			field->CustFee = pRspTransfer->CustFee;
			//应收期货公司费用
			field->BrokerFee = pRspTransfer->BrokerFee;
			//发送方给接收方的消息
			if (pRspTransfer->Message != nullptr)
			{
				field->Message = gcnew String(pRspTransfer->Message);
			}
			//摘要
			if (pRspTransfer->Digest != nullptr)
			{
				field->Digest = gcnew String(pRspTransfer->Digest);
			}
			//银行帐号类型
			field->BankAccType = (CtpNetBankAccTypeType)pRspTransfer->BankAccType;
			//渠道标志
			if (pRspTransfer->DeviceID != nullptr)
			{
				field->DeviceID = gcnew String(pRspTransfer->DeviceID);
			}
			//期货单位帐号类型
			field->BankSecuAccType = (CtpNetBankAccTypeType)pRspTransfer->BankSecuAccType;
			//期货公司银行编码
			if (pRspTransfer->BrokerIDByBank != nullptr)
			{
				field->BrokerIDByBank = gcnew String(pRspTransfer->BrokerIDByBank);
			}
			//期货单位帐号
			if (pRspTransfer->BankSecuAcc != nullptr)
			{
				field->BankSecuAcc = gcnew String(pRspTransfer->BankSecuAcc);
			}
			//银行密码标志
			field->BankPwdFlag = (CtpNetPwdFlagType)pRspTransfer->BankPwdFlag;
			//期货资金密码核对标志
			field->SecuPwdFlag = (CtpNetPwdFlagType)pRspTransfer->SecuPwdFlag;
			//交易柜员
			if (pRspTransfer->OperNo != nullptr)
			{
				field->OperNo = gcnew String(pRspTransfer->OperNo);
			}
			//请求编号
			field->RequestID = pRspTransfer->RequestID;
			//交易ID
			field->TID = pRspTransfer->TID;
			//转账交易状态
			field->TransferStatus = (CtpNetTransferStatusType)pRspTransfer->TransferStatus;
			//错误代码
			field->ErrorID = pRspTransfer->ErrorID;
			//错误信息
			if (pRspTransfer->ErrorMsg != nullptr)
			{
				field->ErrorMsg = gcnew String(pRspTransfer->ErrorMsg);
			}
			//长客户姓名
			if (pRspTransfer->LongCustomerName != nullptr)
			{
				field->LongCustomerName = gcnew String(pRspTransfer->LongCustomerName);
			}
		}
		
		m_pAdapter->OnRtnFromBankToFutureByFuture(field);
	};

	// 期货发起期货资金转银行通知
	void CTraderSpi::OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField *pRspTransfer)
	{
		if (m_pAdapter->OnRtnFromFutureToBankByFuture_delegate == nullptr) return;
		
		CtpNetRspTransferField^ field = nullptr;
		if (pRspTransfer != nullptr)
		{
			field = gcnew CtpNetRspTransferField;
			
			//业务功能码
			if (pRspTransfer->TradeCode != nullptr)
			{
				field->TradeCode = gcnew String(pRspTransfer->TradeCode);
			}
			//银行代码
			if (pRspTransfer->BankID != nullptr)
			{
				field->BankID = gcnew String(pRspTransfer->BankID);
			}
			//银行分支机构代码
			if (pRspTransfer->BankBranchID != nullptr)
			{
				field->BankBranchID = gcnew String(pRspTransfer->BankBranchID);
			}
			//期商代码
			if (pRspTransfer->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pRspTransfer->BrokerID);
			}
			//期商分支机构代码
			if (pRspTransfer->BrokerBranchID != nullptr)
			{
				field->BrokerBranchID = gcnew String(pRspTransfer->BrokerBranchID);
			}
			//交易日期
			if (pRspTransfer->TradeDate != nullptr)
			{
				field->TradeDate = gcnew String(pRspTransfer->TradeDate);
			}
			//交易时间
			if (pRspTransfer->TradeTime != nullptr)
			{
				field->TradeTime = gcnew String(pRspTransfer->TradeTime);
			}
			//银行流水号
			if (pRspTransfer->BankSerial != nullptr)
			{
				field->BankSerial = gcnew String(pRspTransfer->BankSerial);
			}
			//交易系统日期
			if (pRspTransfer->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pRspTransfer->TradingDay);
			}
			//银期平台消息流水号
			field->PlateSerial = pRspTransfer->PlateSerial;
			//最后分片标志
			field->LastFragment = (CtpNetLastFragmentType)pRspTransfer->LastFragment;
			//会话号
			field->SessionID = pRspTransfer->SessionID;
			//客户姓名
			if (pRspTransfer->CustomerName != nullptr)
			{
				field->CustomerName = gcnew String(pRspTransfer->CustomerName);
			}
			//证件类型
			field->IdCardType = (CtpNetIdCardTypeType)pRspTransfer->IdCardType;
			//证件号码
			if (pRspTransfer->IdentifiedCardNo != nullptr)
			{
				field->IdentifiedCardNo = gcnew String(pRspTransfer->IdentifiedCardNo);
			}
			//客户类型
			field->CustType = (CtpNetCustTypeType)pRspTransfer->CustType;
			//银行帐号
			if (pRspTransfer->BankAccount != nullptr)
			{
				field->BankAccount = gcnew String(pRspTransfer->BankAccount);
			}
			//银行密码
			if (pRspTransfer->BankPassWord != nullptr)
			{
				field->BankPassWord = gcnew String(pRspTransfer->BankPassWord);
			}
			//投资者帐号
			if (pRspTransfer->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pRspTransfer->AccountID);
			}
			//期货密码
			if (pRspTransfer->Password != nullptr)
			{
				field->Password = gcnew String(pRspTransfer->Password);
			}
			//安装编号
			field->InstallID = pRspTransfer->InstallID;
			//期货公司流水号
			field->FutureSerial = pRspTransfer->FutureSerial;
			//用户标识
			if (pRspTransfer->UserID != nullptr)
			{
				field->UserID = gcnew String(pRspTransfer->UserID);
			}
			//验证客户证件号码标志
			field->VerifyCertNoFlag = (CtpNetYesNoIndicatorType)pRspTransfer->VerifyCertNoFlag;
			//币种代码
			if (pRspTransfer->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pRspTransfer->CurrencyID);
			}
			//转帐金额
			field->TradeAmount = pRspTransfer->TradeAmount;
			//期货可取金额
			field->FutureFetchAmount = pRspTransfer->FutureFetchAmount;
			//费用支付标志
			field->FeePayFlag = (CtpNetFeePayFlagType)pRspTransfer->FeePayFlag;
			//应收客户费用
			field->CustFee = pRspTransfer->CustFee;
			//应收期货公司费用
			field->BrokerFee = pRspTransfer->BrokerFee;
			//发送方给接收方的消息
			if (pRspTransfer->Message != nullptr)
			{
				field->Message = gcnew String(pRspTransfer->Message);
			}
			//摘要
			if (pRspTransfer->Digest != nullptr)
			{
				field->Digest = gcnew String(pRspTransfer->Digest);
			}
			//银行帐号类型
			field->BankAccType = (CtpNetBankAccTypeType)pRspTransfer->BankAccType;
			//渠道标志
			if (pRspTransfer->DeviceID != nullptr)
			{
				field->DeviceID = gcnew String(pRspTransfer->DeviceID);
			}
			//期货单位帐号类型
			field->BankSecuAccType = (CtpNetBankAccTypeType)pRspTransfer->BankSecuAccType;
			//期货公司银行编码
			if (pRspTransfer->BrokerIDByBank != nullptr)
			{
				field->BrokerIDByBank = gcnew String(pRspTransfer->BrokerIDByBank);
			}
			//期货单位帐号
			if (pRspTransfer->BankSecuAcc != nullptr)
			{
				field->BankSecuAcc = gcnew String(pRspTransfer->BankSecuAcc);
			}
			//银行密码标志
			field->BankPwdFlag = (CtpNetPwdFlagType)pRspTransfer->BankPwdFlag;
			//期货资金密码核对标志
			field->SecuPwdFlag = (CtpNetPwdFlagType)pRspTransfer->SecuPwdFlag;
			//交易柜员
			if (pRspTransfer->OperNo != nullptr)
			{
				field->OperNo = gcnew String(pRspTransfer->OperNo);
			}
			//请求编号
			field->RequestID = pRspTransfer->RequestID;
			//交易ID
			field->TID = pRspTransfer->TID;
			//转账交易状态
			field->TransferStatus = (CtpNetTransferStatusType)pRspTransfer->TransferStatus;
			//错误代码
			field->ErrorID = pRspTransfer->ErrorID;
			//错误信息
			if (pRspTransfer->ErrorMsg != nullptr)
			{
				field->ErrorMsg = gcnew String(pRspTransfer->ErrorMsg);
			}
			//长客户姓名
			if (pRspTransfer->LongCustomerName != nullptr)
			{
				field->LongCustomerName = gcnew String(pRspTransfer->LongCustomerName);
			}
		}
		
		m_pAdapter->OnRtnFromFutureToBankByFuture(field);
	};

	// 系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
	void CTraderSpi::OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField *pRspRepeal)
	{
		if (m_pAdapter->OnRtnRepealFromBankToFutureByFutureManual_delegate == nullptr) return;
		
		CtpNetRspRepealField^ field = nullptr;
		if (pRspRepeal != nullptr)
		{
			field = gcnew CtpNetRspRepealField;
			
			//冲正时间间隔
			field->RepealTimeInterval = pRspRepeal->RepealTimeInterval;
			//已经冲正次数
			field->RepealedTimes = pRspRepeal->RepealedTimes;
			//银行冲正标志
			field->BankRepealFlag = (CtpNetBankRepealFlagType)pRspRepeal->BankRepealFlag;
			//期商冲正标志
			field->BrokerRepealFlag = (CtpNetBrokerRepealFlagType)pRspRepeal->BrokerRepealFlag;
			//被冲正平台流水号
			field->PlateRepealSerial = pRspRepeal->PlateRepealSerial;
			//被冲正银行流水号
			if (pRspRepeal->BankRepealSerial != nullptr)
			{
				field->BankRepealSerial = gcnew String(pRspRepeal->BankRepealSerial);
			}
			//被冲正期货流水号
			field->FutureRepealSerial = pRspRepeal->FutureRepealSerial;
			//业务功能码
			if (pRspRepeal->TradeCode != nullptr)
			{
				field->TradeCode = gcnew String(pRspRepeal->TradeCode);
			}
			//银行代码
			if (pRspRepeal->BankID != nullptr)
			{
				field->BankID = gcnew String(pRspRepeal->BankID);
			}
			//银行分支机构代码
			if (pRspRepeal->BankBranchID != nullptr)
			{
				field->BankBranchID = gcnew String(pRspRepeal->BankBranchID);
			}
			//期商代码
			if (pRspRepeal->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pRspRepeal->BrokerID);
			}
			//期商分支机构代码
			if (pRspRepeal->BrokerBranchID != nullptr)
			{
				field->BrokerBranchID = gcnew String(pRspRepeal->BrokerBranchID);
			}
			//交易日期
			if (pRspRepeal->TradeDate != nullptr)
			{
				field->TradeDate = gcnew String(pRspRepeal->TradeDate);
			}
			//交易时间
			if (pRspRepeal->TradeTime != nullptr)
			{
				field->TradeTime = gcnew String(pRspRepeal->TradeTime);
			}
			//银行流水号
			if (pRspRepeal->BankSerial != nullptr)
			{
				field->BankSerial = gcnew String(pRspRepeal->BankSerial);
			}
			//交易系统日期
			if (pRspRepeal->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pRspRepeal->TradingDay);
			}
			//银期平台消息流水号
			field->PlateSerial = pRspRepeal->PlateSerial;
			//最后分片标志
			field->LastFragment = (CtpNetLastFragmentType)pRspRepeal->LastFragment;
			//会话号
			field->SessionID = pRspRepeal->SessionID;
			//客户姓名
			if (pRspRepeal->CustomerName != nullptr)
			{
				field->CustomerName = gcnew String(pRspRepeal->CustomerName);
			}
			//证件类型
			field->IdCardType = (CtpNetIdCardTypeType)pRspRepeal->IdCardType;
			//证件号码
			if (pRspRepeal->IdentifiedCardNo != nullptr)
			{
				field->IdentifiedCardNo = gcnew String(pRspRepeal->IdentifiedCardNo);
			}
			//客户类型
			field->CustType = (CtpNetCustTypeType)pRspRepeal->CustType;
			//银行帐号
			if (pRspRepeal->BankAccount != nullptr)
			{
				field->BankAccount = gcnew String(pRspRepeal->BankAccount);
			}
			//银行密码
			if (pRspRepeal->BankPassWord != nullptr)
			{
				field->BankPassWord = gcnew String(pRspRepeal->BankPassWord);
			}
			//投资者帐号
			if (pRspRepeal->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pRspRepeal->AccountID);
			}
			//期货密码
			if (pRspRepeal->Password != nullptr)
			{
				field->Password = gcnew String(pRspRepeal->Password);
			}
			//安装编号
			field->InstallID = pRspRepeal->InstallID;
			//期货公司流水号
			field->FutureSerial = pRspRepeal->FutureSerial;
			//用户标识
			if (pRspRepeal->UserID != nullptr)
			{
				field->UserID = gcnew String(pRspRepeal->UserID);
			}
			//验证客户证件号码标志
			field->VerifyCertNoFlag = (CtpNetYesNoIndicatorType)pRspRepeal->VerifyCertNoFlag;
			//币种代码
			if (pRspRepeal->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pRspRepeal->CurrencyID);
			}
			//转帐金额
			field->TradeAmount = pRspRepeal->TradeAmount;
			//期货可取金额
			field->FutureFetchAmount = pRspRepeal->FutureFetchAmount;
			//费用支付标志
			field->FeePayFlag = (CtpNetFeePayFlagType)pRspRepeal->FeePayFlag;
			//应收客户费用
			field->CustFee = pRspRepeal->CustFee;
			//应收期货公司费用
			field->BrokerFee = pRspRepeal->BrokerFee;
			//发送方给接收方的消息
			if (pRspRepeal->Message != nullptr)
			{
				field->Message = gcnew String(pRspRepeal->Message);
			}
			//摘要
			if (pRspRepeal->Digest != nullptr)
			{
				field->Digest = gcnew String(pRspRepeal->Digest);
			}
			//银行帐号类型
			field->BankAccType = (CtpNetBankAccTypeType)pRspRepeal->BankAccType;
			//渠道标志
			if (pRspRepeal->DeviceID != nullptr)
			{
				field->DeviceID = gcnew String(pRspRepeal->DeviceID);
			}
			//期货单位帐号类型
			field->BankSecuAccType = (CtpNetBankAccTypeType)pRspRepeal->BankSecuAccType;
			//期货公司银行编码
			if (pRspRepeal->BrokerIDByBank != nullptr)
			{
				field->BrokerIDByBank = gcnew String(pRspRepeal->BrokerIDByBank);
			}
			//期货单位帐号
			if (pRspRepeal->BankSecuAcc != nullptr)
			{
				field->BankSecuAcc = gcnew String(pRspRepeal->BankSecuAcc);
			}
			//银行密码标志
			field->BankPwdFlag = (CtpNetPwdFlagType)pRspRepeal->BankPwdFlag;
			//期货资金密码核对标志
			field->SecuPwdFlag = (CtpNetPwdFlagType)pRspRepeal->SecuPwdFlag;
			//交易柜员
			if (pRspRepeal->OperNo != nullptr)
			{
				field->OperNo = gcnew String(pRspRepeal->OperNo);
			}
			//请求编号
			field->RequestID = pRspRepeal->RequestID;
			//交易ID
			field->TID = pRspRepeal->TID;
			//转账交易状态
			field->TransferStatus = (CtpNetTransferStatusType)pRspRepeal->TransferStatus;
			//错误代码
			field->ErrorID = pRspRepeal->ErrorID;
			//错误信息
			if (pRspRepeal->ErrorMsg != nullptr)
			{
				field->ErrorMsg = gcnew String(pRspRepeal->ErrorMsg);
			}
			//长客户姓名
			if (pRspRepeal->LongCustomerName != nullptr)
			{
				field->LongCustomerName = gcnew String(pRspRepeal->LongCustomerName);
			}
		}
		
		m_pAdapter->OnRtnRepealFromBankToFutureByFutureManual(field);
	};

	// 系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
	void CTraderSpi::OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField *pRspRepeal)
	{
		if (m_pAdapter->OnRtnRepealFromFutureToBankByFutureManual_delegate == nullptr) return;
		
		CtpNetRspRepealField^ field = nullptr;
		if (pRspRepeal != nullptr)
		{
			field = gcnew CtpNetRspRepealField;
			
			//冲正时间间隔
			field->RepealTimeInterval = pRspRepeal->RepealTimeInterval;
			//已经冲正次数
			field->RepealedTimes = pRspRepeal->RepealedTimes;
			//银行冲正标志
			field->BankRepealFlag = (CtpNetBankRepealFlagType)pRspRepeal->BankRepealFlag;
			//期商冲正标志
			field->BrokerRepealFlag = (CtpNetBrokerRepealFlagType)pRspRepeal->BrokerRepealFlag;
			//被冲正平台流水号
			field->PlateRepealSerial = pRspRepeal->PlateRepealSerial;
			//被冲正银行流水号
			if (pRspRepeal->BankRepealSerial != nullptr)
			{
				field->BankRepealSerial = gcnew String(pRspRepeal->BankRepealSerial);
			}
			//被冲正期货流水号
			field->FutureRepealSerial = pRspRepeal->FutureRepealSerial;
			//业务功能码
			if (pRspRepeal->TradeCode != nullptr)
			{
				field->TradeCode = gcnew String(pRspRepeal->TradeCode);
			}
			//银行代码
			if (pRspRepeal->BankID != nullptr)
			{
				field->BankID = gcnew String(pRspRepeal->BankID);
			}
			//银行分支机构代码
			if (pRspRepeal->BankBranchID != nullptr)
			{
				field->BankBranchID = gcnew String(pRspRepeal->BankBranchID);
			}
			//期商代码
			if (pRspRepeal->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pRspRepeal->BrokerID);
			}
			//期商分支机构代码
			if (pRspRepeal->BrokerBranchID != nullptr)
			{
				field->BrokerBranchID = gcnew String(pRspRepeal->BrokerBranchID);
			}
			//交易日期
			if (pRspRepeal->TradeDate != nullptr)
			{
				field->TradeDate = gcnew String(pRspRepeal->TradeDate);
			}
			//交易时间
			if (pRspRepeal->TradeTime != nullptr)
			{
				field->TradeTime = gcnew String(pRspRepeal->TradeTime);
			}
			//银行流水号
			if (pRspRepeal->BankSerial != nullptr)
			{
				field->BankSerial = gcnew String(pRspRepeal->BankSerial);
			}
			//交易系统日期
			if (pRspRepeal->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pRspRepeal->TradingDay);
			}
			//银期平台消息流水号
			field->PlateSerial = pRspRepeal->PlateSerial;
			//最后分片标志
			field->LastFragment = (CtpNetLastFragmentType)pRspRepeal->LastFragment;
			//会话号
			field->SessionID = pRspRepeal->SessionID;
			//客户姓名
			if (pRspRepeal->CustomerName != nullptr)
			{
				field->CustomerName = gcnew String(pRspRepeal->CustomerName);
			}
			//证件类型
			field->IdCardType = (CtpNetIdCardTypeType)pRspRepeal->IdCardType;
			//证件号码
			if (pRspRepeal->IdentifiedCardNo != nullptr)
			{
				field->IdentifiedCardNo = gcnew String(pRspRepeal->IdentifiedCardNo);
			}
			//客户类型
			field->CustType = (CtpNetCustTypeType)pRspRepeal->CustType;
			//银行帐号
			if (pRspRepeal->BankAccount != nullptr)
			{
				field->BankAccount = gcnew String(pRspRepeal->BankAccount);
			}
			//银行密码
			if (pRspRepeal->BankPassWord != nullptr)
			{
				field->BankPassWord = gcnew String(pRspRepeal->BankPassWord);
			}
			//投资者帐号
			if (pRspRepeal->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pRspRepeal->AccountID);
			}
			//期货密码
			if (pRspRepeal->Password != nullptr)
			{
				field->Password = gcnew String(pRspRepeal->Password);
			}
			//安装编号
			field->InstallID = pRspRepeal->InstallID;
			//期货公司流水号
			field->FutureSerial = pRspRepeal->FutureSerial;
			//用户标识
			if (pRspRepeal->UserID != nullptr)
			{
				field->UserID = gcnew String(pRspRepeal->UserID);
			}
			//验证客户证件号码标志
			field->VerifyCertNoFlag = (CtpNetYesNoIndicatorType)pRspRepeal->VerifyCertNoFlag;
			//币种代码
			if (pRspRepeal->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pRspRepeal->CurrencyID);
			}
			//转帐金额
			field->TradeAmount = pRspRepeal->TradeAmount;
			//期货可取金额
			field->FutureFetchAmount = pRspRepeal->FutureFetchAmount;
			//费用支付标志
			field->FeePayFlag = (CtpNetFeePayFlagType)pRspRepeal->FeePayFlag;
			//应收客户费用
			field->CustFee = pRspRepeal->CustFee;
			//应收期货公司费用
			field->BrokerFee = pRspRepeal->BrokerFee;
			//发送方给接收方的消息
			if (pRspRepeal->Message != nullptr)
			{
				field->Message = gcnew String(pRspRepeal->Message);
			}
			//摘要
			if (pRspRepeal->Digest != nullptr)
			{
				field->Digest = gcnew String(pRspRepeal->Digest);
			}
			//银行帐号类型
			field->BankAccType = (CtpNetBankAccTypeType)pRspRepeal->BankAccType;
			//渠道标志
			if (pRspRepeal->DeviceID != nullptr)
			{
				field->DeviceID = gcnew String(pRspRepeal->DeviceID);
			}
			//期货单位帐号类型
			field->BankSecuAccType = (CtpNetBankAccTypeType)pRspRepeal->BankSecuAccType;
			//期货公司银行编码
			if (pRspRepeal->BrokerIDByBank != nullptr)
			{
				field->BrokerIDByBank = gcnew String(pRspRepeal->BrokerIDByBank);
			}
			//期货单位帐号
			if (pRspRepeal->BankSecuAcc != nullptr)
			{
				field->BankSecuAcc = gcnew String(pRspRepeal->BankSecuAcc);
			}
			//银行密码标志
			field->BankPwdFlag = (CtpNetPwdFlagType)pRspRepeal->BankPwdFlag;
			//期货资金密码核对标志
			field->SecuPwdFlag = (CtpNetPwdFlagType)pRspRepeal->SecuPwdFlag;
			//交易柜员
			if (pRspRepeal->OperNo != nullptr)
			{
				field->OperNo = gcnew String(pRspRepeal->OperNo);
			}
			//请求编号
			field->RequestID = pRspRepeal->RequestID;
			//交易ID
			field->TID = pRspRepeal->TID;
			//转账交易状态
			field->TransferStatus = (CtpNetTransferStatusType)pRspRepeal->TransferStatus;
			//错误代码
			field->ErrorID = pRspRepeal->ErrorID;
			//错误信息
			if (pRspRepeal->ErrorMsg != nullptr)
			{
				field->ErrorMsg = gcnew String(pRspRepeal->ErrorMsg);
			}
			//长客户姓名
			if (pRspRepeal->LongCustomerName != nullptr)
			{
				field->LongCustomerName = gcnew String(pRspRepeal->LongCustomerName);
			}
		}
		
		m_pAdapter->OnRtnRepealFromFutureToBankByFutureManual(field);
	};

	// 期货发起查询银行余额通知
	void CTraderSpi::OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField *pNotifyQueryAccount)
	{
		if (m_pAdapter->OnRtnQueryBankBalanceByFuture_delegate == nullptr) return;
		
		CtpNetNotifyQueryAccountField^ field = nullptr;
		if (pNotifyQueryAccount != nullptr)
		{
			field = gcnew CtpNetNotifyQueryAccountField;
			
			//业务功能码
			if (pNotifyQueryAccount->TradeCode != nullptr)
			{
				field->TradeCode = gcnew String(pNotifyQueryAccount->TradeCode);
			}
			//银行代码
			if (pNotifyQueryAccount->BankID != nullptr)
			{
				field->BankID = gcnew String(pNotifyQueryAccount->BankID);
			}
			//银行分支机构代码
			if (pNotifyQueryAccount->BankBranchID != nullptr)
			{
				field->BankBranchID = gcnew String(pNotifyQueryAccount->BankBranchID);
			}
			//期商代码
			if (pNotifyQueryAccount->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pNotifyQueryAccount->BrokerID);
			}
			//期商分支机构代码
			if (pNotifyQueryAccount->BrokerBranchID != nullptr)
			{
				field->BrokerBranchID = gcnew String(pNotifyQueryAccount->BrokerBranchID);
			}
			//交易日期
			if (pNotifyQueryAccount->TradeDate != nullptr)
			{
				field->TradeDate = gcnew String(pNotifyQueryAccount->TradeDate);
			}
			//交易时间
			if (pNotifyQueryAccount->TradeTime != nullptr)
			{
				field->TradeTime = gcnew String(pNotifyQueryAccount->TradeTime);
			}
			//银行流水号
			if (pNotifyQueryAccount->BankSerial != nullptr)
			{
				field->BankSerial = gcnew String(pNotifyQueryAccount->BankSerial);
			}
			//交易系统日期
			if (pNotifyQueryAccount->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pNotifyQueryAccount->TradingDay);
			}
			//银期平台消息流水号
			field->PlateSerial = pNotifyQueryAccount->PlateSerial;
			//最后分片标志
			field->LastFragment = (CtpNetLastFragmentType)pNotifyQueryAccount->LastFragment;
			//会话号
			field->SessionID = pNotifyQueryAccount->SessionID;
			//客户姓名
			if (pNotifyQueryAccount->CustomerName != nullptr)
			{
				field->CustomerName = gcnew String(pNotifyQueryAccount->CustomerName);
			}
			//证件类型
			field->IdCardType = (CtpNetIdCardTypeType)pNotifyQueryAccount->IdCardType;
			//证件号码
			if (pNotifyQueryAccount->IdentifiedCardNo != nullptr)
			{
				field->IdentifiedCardNo = gcnew String(pNotifyQueryAccount->IdentifiedCardNo);
			}
			//客户类型
			field->CustType = (CtpNetCustTypeType)pNotifyQueryAccount->CustType;
			//银行帐号
			if (pNotifyQueryAccount->BankAccount != nullptr)
			{
				field->BankAccount = gcnew String(pNotifyQueryAccount->BankAccount);
			}
			//银行密码
			if (pNotifyQueryAccount->BankPassWord != nullptr)
			{
				field->BankPassWord = gcnew String(pNotifyQueryAccount->BankPassWord);
			}
			//投资者帐号
			if (pNotifyQueryAccount->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pNotifyQueryAccount->AccountID);
			}
			//期货密码
			if (pNotifyQueryAccount->Password != nullptr)
			{
				field->Password = gcnew String(pNotifyQueryAccount->Password);
			}
			//期货公司流水号
			field->FutureSerial = pNotifyQueryAccount->FutureSerial;
			//安装编号
			field->InstallID = pNotifyQueryAccount->InstallID;
			//用户标识
			if (pNotifyQueryAccount->UserID != nullptr)
			{
				field->UserID = gcnew String(pNotifyQueryAccount->UserID);
			}
			//验证客户证件号码标志
			field->VerifyCertNoFlag = (CtpNetYesNoIndicatorType)pNotifyQueryAccount->VerifyCertNoFlag;
			//币种代码
			if (pNotifyQueryAccount->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pNotifyQueryAccount->CurrencyID);
			}
			//摘要
			if (pNotifyQueryAccount->Digest != nullptr)
			{
				field->Digest = gcnew String(pNotifyQueryAccount->Digest);
			}
			//银行帐号类型
			field->BankAccType = (CtpNetBankAccTypeType)pNotifyQueryAccount->BankAccType;
			//渠道标志
			if (pNotifyQueryAccount->DeviceID != nullptr)
			{
				field->DeviceID = gcnew String(pNotifyQueryAccount->DeviceID);
			}
			//期货单位帐号类型
			field->BankSecuAccType = (CtpNetBankAccTypeType)pNotifyQueryAccount->BankSecuAccType;
			//期货公司银行编码
			if (pNotifyQueryAccount->BrokerIDByBank != nullptr)
			{
				field->BrokerIDByBank = gcnew String(pNotifyQueryAccount->BrokerIDByBank);
			}
			//期货单位帐号
			if (pNotifyQueryAccount->BankSecuAcc != nullptr)
			{
				field->BankSecuAcc = gcnew String(pNotifyQueryAccount->BankSecuAcc);
			}
			//银行密码标志
			field->BankPwdFlag = (CtpNetPwdFlagType)pNotifyQueryAccount->BankPwdFlag;
			//期货资金密码核对标志
			field->SecuPwdFlag = (CtpNetPwdFlagType)pNotifyQueryAccount->SecuPwdFlag;
			//交易柜员
			if (pNotifyQueryAccount->OperNo != nullptr)
			{
				field->OperNo = gcnew String(pNotifyQueryAccount->OperNo);
			}
			//请求编号
			field->RequestID = pNotifyQueryAccount->RequestID;
			//交易ID
			field->TID = pNotifyQueryAccount->TID;
			//银行可用金额
			field->BankUseAmount = pNotifyQueryAccount->BankUseAmount;
			//银行可取金额
			field->BankFetchAmount = pNotifyQueryAccount->BankFetchAmount;
			//错误代码
			field->ErrorID = pNotifyQueryAccount->ErrorID;
			//错误信息
			if (pNotifyQueryAccount->ErrorMsg != nullptr)
			{
				field->ErrorMsg = gcnew String(pNotifyQueryAccount->ErrorMsg);
			}
			//长客户姓名
			if (pNotifyQueryAccount->LongCustomerName != nullptr)
			{
				field->LongCustomerName = gcnew String(pNotifyQueryAccount->LongCustomerName);
			}
		}
		
		m_pAdapter->OnRtnQueryBankBalanceByFuture(field);
	};

	// 期货发起银行资金转期货错误回报
	void CTraderSpi::OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo)
	{
		if (m_pAdapter->OnErrRtnBankToFutureByFuture_delegate == nullptr) return;
		
		CtpNetReqTransferField^ field = nullptr;
		if (pReqTransfer != nullptr)
		{
			field = gcnew CtpNetReqTransferField;
			
			//业务功能码
			if (pReqTransfer->TradeCode != nullptr)
			{
				field->TradeCode = gcnew String(pReqTransfer->TradeCode);
			}
			//银行代码
			if (pReqTransfer->BankID != nullptr)
			{
				field->BankID = gcnew String(pReqTransfer->BankID);
			}
			//银行分支机构代码
			if (pReqTransfer->BankBranchID != nullptr)
			{
				field->BankBranchID = gcnew String(pReqTransfer->BankBranchID);
			}
			//期商代码
			if (pReqTransfer->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pReqTransfer->BrokerID);
			}
			//期商分支机构代码
			if (pReqTransfer->BrokerBranchID != nullptr)
			{
				field->BrokerBranchID = gcnew String(pReqTransfer->BrokerBranchID);
			}
			//交易日期
			if (pReqTransfer->TradeDate != nullptr)
			{
				field->TradeDate = gcnew String(pReqTransfer->TradeDate);
			}
			//交易时间
			if (pReqTransfer->TradeTime != nullptr)
			{
				field->TradeTime = gcnew String(pReqTransfer->TradeTime);
			}
			//银行流水号
			if (pReqTransfer->BankSerial != nullptr)
			{
				field->BankSerial = gcnew String(pReqTransfer->BankSerial);
			}
			//交易系统日期
			if (pReqTransfer->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pReqTransfer->TradingDay);
			}
			//银期平台消息流水号
			field->PlateSerial = pReqTransfer->PlateSerial;
			//最后分片标志
			field->LastFragment = (CtpNetLastFragmentType)pReqTransfer->LastFragment;
			//会话号
			field->SessionID = pReqTransfer->SessionID;
			//客户姓名
			if (pReqTransfer->CustomerName != nullptr)
			{
				field->CustomerName = gcnew String(pReqTransfer->CustomerName);
			}
			//证件类型
			field->IdCardType = (CtpNetIdCardTypeType)pReqTransfer->IdCardType;
			//证件号码
			if (pReqTransfer->IdentifiedCardNo != nullptr)
			{
				field->IdentifiedCardNo = gcnew String(pReqTransfer->IdentifiedCardNo);
			}
			//客户类型
			field->CustType = (CtpNetCustTypeType)pReqTransfer->CustType;
			//银行帐号
			if (pReqTransfer->BankAccount != nullptr)
			{
				field->BankAccount = gcnew String(pReqTransfer->BankAccount);
			}
			//银行密码
			if (pReqTransfer->BankPassWord != nullptr)
			{
				field->BankPassWord = gcnew String(pReqTransfer->BankPassWord);
			}
			//投资者帐号
			if (pReqTransfer->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pReqTransfer->AccountID);
			}
			//期货密码
			if (pReqTransfer->Password != nullptr)
			{
				field->Password = gcnew String(pReqTransfer->Password);
			}
			//安装编号
			field->InstallID = pReqTransfer->InstallID;
			//期货公司流水号
			field->FutureSerial = pReqTransfer->FutureSerial;
			//用户标识
			if (pReqTransfer->UserID != nullptr)
			{
				field->UserID = gcnew String(pReqTransfer->UserID);
			}
			//验证客户证件号码标志
			field->VerifyCertNoFlag = (CtpNetYesNoIndicatorType)pReqTransfer->VerifyCertNoFlag;
			//币种代码
			if (pReqTransfer->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pReqTransfer->CurrencyID);
			}
			//转帐金额
			field->TradeAmount = pReqTransfer->TradeAmount;
			//期货可取金额
			field->FutureFetchAmount = pReqTransfer->FutureFetchAmount;
			//费用支付标志
			field->FeePayFlag = (CtpNetFeePayFlagType)pReqTransfer->FeePayFlag;
			//应收客户费用
			field->CustFee = pReqTransfer->CustFee;
			//应收期货公司费用
			field->BrokerFee = pReqTransfer->BrokerFee;
			//发送方给接收方的消息
			if (pReqTransfer->Message != nullptr)
			{
				field->Message = gcnew String(pReqTransfer->Message);
			}
			//摘要
			if (pReqTransfer->Digest != nullptr)
			{
				field->Digest = gcnew String(pReqTransfer->Digest);
			}
			//银行帐号类型
			field->BankAccType = (CtpNetBankAccTypeType)pReqTransfer->BankAccType;
			//渠道标志
			if (pReqTransfer->DeviceID != nullptr)
			{
				field->DeviceID = gcnew String(pReqTransfer->DeviceID);
			}
			//期货单位帐号类型
			field->BankSecuAccType = (CtpNetBankAccTypeType)pReqTransfer->BankSecuAccType;
			//期货公司银行编码
			if (pReqTransfer->BrokerIDByBank != nullptr)
			{
				field->BrokerIDByBank = gcnew String(pReqTransfer->BrokerIDByBank);
			}
			//期货单位帐号
			if (pReqTransfer->BankSecuAcc != nullptr)
			{
				field->BankSecuAcc = gcnew String(pReqTransfer->BankSecuAcc);
			}
			//银行密码标志
			field->BankPwdFlag = (CtpNetPwdFlagType)pReqTransfer->BankPwdFlag;
			//期货资金密码核对标志
			field->SecuPwdFlag = (CtpNetPwdFlagType)pReqTransfer->SecuPwdFlag;
			//交易柜员
			if (pReqTransfer->OperNo != nullptr)
			{
				field->OperNo = gcnew String(pReqTransfer->OperNo);
			}
			//请求编号
			field->RequestID = pReqTransfer->RequestID;
			//交易ID
			field->TID = pReqTransfer->TID;
			//转账交易状态
			field->TransferStatus = (CtpNetTransferStatusType)pReqTransfer->TransferStatus;
			//长客户姓名
			if (pReqTransfer->LongCustomerName != nullptr)
			{
				field->LongCustomerName = gcnew String(pReqTransfer->LongCustomerName);
			}
		}
		
		m_pAdapter->OnErrRtnBankToFutureByFuture(field, RspInfoField(pRspInfo));
	};

	// 期货发起期货资金转银行错误回报
	void CTraderSpi::OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo)
	{
		if (m_pAdapter->OnErrRtnFutureToBankByFuture_delegate == nullptr) return;
		
		CtpNetReqTransferField^ field = nullptr;
		if (pReqTransfer != nullptr)
		{
			field = gcnew CtpNetReqTransferField;
			
			//业务功能码
			if (pReqTransfer->TradeCode != nullptr)
			{
				field->TradeCode = gcnew String(pReqTransfer->TradeCode);
			}
			//银行代码
			if (pReqTransfer->BankID != nullptr)
			{
				field->BankID = gcnew String(pReqTransfer->BankID);
			}
			//银行分支机构代码
			if (pReqTransfer->BankBranchID != nullptr)
			{
				field->BankBranchID = gcnew String(pReqTransfer->BankBranchID);
			}
			//期商代码
			if (pReqTransfer->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pReqTransfer->BrokerID);
			}
			//期商分支机构代码
			if (pReqTransfer->BrokerBranchID != nullptr)
			{
				field->BrokerBranchID = gcnew String(pReqTransfer->BrokerBranchID);
			}
			//交易日期
			if (pReqTransfer->TradeDate != nullptr)
			{
				field->TradeDate = gcnew String(pReqTransfer->TradeDate);
			}
			//交易时间
			if (pReqTransfer->TradeTime != nullptr)
			{
				field->TradeTime = gcnew String(pReqTransfer->TradeTime);
			}
			//银行流水号
			if (pReqTransfer->BankSerial != nullptr)
			{
				field->BankSerial = gcnew String(pReqTransfer->BankSerial);
			}
			//交易系统日期
			if (pReqTransfer->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pReqTransfer->TradingDay);
			}
			//银期平台消息流水号
			field->PlateSerial = pReqTransfer->PlateSerial;
			//最后分片标志
			field->LastFragment = (CtpNetLastFragmentType)pReqTransfer->LastFragment;
			//会话号
			field->SessionID = pReqTransfer->SessionID;
			//客户姓名
			if (pReqTransfer->CustomerName != nullptr)
			{
				field->CustomerName = gcnew String(pReqTransfer->CustomerName);
			}
			//证件类型
			field->IdCardType = (CtpNetIdCardTypeType)pReqTransfer->IdCardType;
			//证件号码
			if (pReqTransfer->IdentifiedCardNo != nullptr)
			{
				field->IdentifiedCardNo = gcnew String(pReqTransfer->IdentifiedCardNo);
			}
			//客户类型
			field->CustType = (CtpNetCustTypeType)pReqTransfer->CustType;
			//银行帐号
			if (pReqTransfer->BankAccount != nullptr)
			{
				field->BankAccount = gcnew String(pReqTransfer->BankAccount);
			}
			//银行密码
			if (pReqTransfer->BankPassWord != nullptr)
			{
				field->BankPassWord = gcnew String(pReqTransfer->BankPassWord);
			}
			//投资者帐号
			if (pReqTransfer->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pReqTransfer->AccountID);
			}
			//期货密码
			if (pReqTransfer->Password != nullptr)
			{
				field->Password = gcnew String(pReqTransfer->Password);
			}
			//安装编号
			field->InstallID = pReqTransfer->InstallID;
			//期货公司流水号
			field->FutureSerial = pReqTransfer->FutureSerial;
			//用户标识
			if (pReqTransfer->UserID != nullptr)
			{
				field->UserID = gcnew String(pReqTransfer->UserID);
			}
			//验证客户证件号码标志
			field->VerifyCertNoFlag = (CtpNetYesNoIndicatorType)pReqTransfer->VerifyCertNoFlag;
			//币种代码
			if (pReqTransfer->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pReqTransfer->CurrencyID);
			}
			//转帐金额
			field->TradeAmount = pReqTransfer->TradeAmount;
			//期货可取金额
			field->FutureFetchAmount = pReqTransfer->FutureFetchAmount;
			//费用支付标志
			field->FeePayFlag = (CtpNetFeePayFlagType)pReqTransfer->FeePayFlag;
			//应收客户费用
			field->CustFee = pReqTransfer->CustFee;
			//应收期货公司费用
			field->BrokerFee = pReqTransfer->BrokerFee;
			//发送方给接收方的消息
			if (pReqTransfer->Message != nullptr)
			{
				field->Message = gcnew String(pReqTransfer->Message);
			}
			//摘要
			if (pReqTransfer->Digest != nullptr)
			{
				field->Digest = gcnew String(pReqTransfer->Digest);
			}
			//银行帐号类型
			field->BankAccType = (CtpNetBankAccTypeType)pReqTransfer->BankAccType;
			//渠道标志
			if (pReqTransfer->DeviceID != nullptr)
			{
				field->DeviceID = gcnew String(pReqTransfer->DeviceID);
			}
			//期货单位帐号类型
			field->BankSecuAccType = (CtpNetBankAccTypeType)pReqTransfer->BankSecuAccType;
			//期货公司银行编码
			if (pReqTransfer->BrokerIDByBank != nullptr)
			{
				field->BrokerIDByBank = gcnew String(pReqTransfer->BrokerIDByBank);
			}
			//期货单位帐号
			if (pReqTransfer->BankSecuAcc != nullptr)
			{
				field->BankSecuAcc = gcnew String(pReqTransfer->BankSecuAcc);
			}
			//银行密码标志
			field->BankPwdFlag = (CtpNetPwdFlagType)pReqTransfer->BankPwdFlag;
			//期货资金密码核对标志
			field->SecuPwdFlag = (CtpNetPwdFlagType)pReqTransfer->SecuPwdFlag;
			//交易柜员
			if (pReqTransfer->OperNo != nullptr)
			{
				field->OperNo = gcnew String(pReqTransfer->OperNo);
			}
			//请求编号
			field->RequestID = pReqTransfer->RequestID;
			//交易ID
			field->TID = pReqTransfer->TID;
			//转账交易状态
			field->TransferStatus = (CtpNetTransferStatusType)pReqTransfer->TransferStatus;
			//长客户姓名
			if (pReqTransfer->LongCustomerName != nullptr)
			{
				field->LongCustomerName = gcnew String(pReqTransfer->LongCustomerName);
			}
		}
		
		m_pAdapter->OnErrRtnFutureToBankByFuture(field, RspInfoField(pRspInfo));
	};

	// 系统运行时期货端手工发起冲正银行转期货错误回报
	void CTraderSpi::OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo)
	{
		if (m_pAdapter->OnErrRtnRepealBankToFutureByFutureManual_delegate == nullptr) return;
		
		CtpNetReqRepealField^ field = nullptr;
		if (pReqRepeal != nullptr)
		{
			field = gcnew CtpNetReqRepealField;
			
			//冲正时间间隔
			field->RepealTimeInterval = pReqRepeal->RepealTimeInterval;
			//已经冲正次数
			field->RepealedTimes = pReqRepeal->RepealedTimes;
			//银行冲正标志
			field->BankRepealFlag = (CtpNetBankRepealFlagType)pReqRepeal->BankRepealFlag;
			//期商冲正标志
			field->BrokerRepealFlag = (CtpNetBrokerRepealFlagType)pReqRepeal->BrokerRepealFlag;
			//被冲正平台流水号
			field->PlateRepealSerial = pReqRepeal->PlateRepealSerial;
			//被冲正银行流水号
			if (pReqRepeal->BankRepealSerial != nullptr)
			{
				field->BankRepealSerial = gcnew String(pReqRepeal->BankRepealSerial);
			}
			//被冲正期货流水号
			field->FutureRepealSerial = pReqRepeal->FutureRepealSerial;
			//业务功能码
			if (pReqRepeal->TradeCode != nullptr)
			{
				field->TradeCode = gcnew String(pReqRepeal->TradeCode);
			}
			//银行代码
			if (pReqRepeal->BankID != nullptr)
			{
				field->BankID = gcnew String(pReqRepeal->BankID);
			}
			//银行分支机构代码
			if (pReqRepeal->BankBranchID != nullptr)
			{
				field->BankBranchID = gcnew String(pReqRepeal->BankBranchID);
			}
			//期商代码
			if (pReqRepeal->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pReqRepeal->BrokerID);
			}
			//期商分支机构代码
			if (pReqRepeal->BrokerBranchID != nullptr)
			{
				field->BrokerBranchID = gcnew String(pReqRepeal->BrokerBranchID);
			}
			//交易日期
			if (pReqRepeal->TradeDate != nullptr)
			{
				field->TradeDate = gcnew String(pReqRepeal->TradeDate);
			}
			//交易时间
			if (pReqRepeal->TradeTime != nullptr)
			{
				field->TradeTime = gcnew String(pReqRepeal->TradeTime);
			}
			//银行流水号
			if (pReqRepeal->BankSerial != nullptr)
			{
				field->BankSerial = gcnew String(pReqRepeal->BankSerial);
			}
			//交易系统日期
			if (pReqRepeal->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pReqRepeal->TradingDay);
			}
			//银期平台消息流水号
			field->PlateSerial = pReqRepeal->PlateSerial;
			//最后分片标志
			field->LastFragment = (CtpNetLastFragmentType)pReqRepeal->LastFragment;
			//会话号
			field->SessionID = pReqRepeal->SessionID;
			//客户姓名
			if (pReqRepeal->CustomerName != nullptr)
			{
				field->CustomerName = gcnew String(pReqRepeal->CustomerName);
			}
			//证件类型
			field->IdCardType = (CtpNetIdCardTypeType)pReqRepeal->IdCardType;
			//证件号码
			if (pReqRepeal->IdentifiedCardNo != nullptr)
			{
				field->IdentifiedCardNo = gcnew String(pReqRepeal->IdentifiedCardNo);
			}
			//客户类型
			field->CustType = (CtpNetCustTypeType)pReqRepeal->CustType;
			//银行帐号
			if (pReqRepeal->BankAccount != nullptr)
			{
				field->BankAccount = gcnew String(pReqRepeal->BankAccount);
			}
			//银行密码
			if (pReqRepeal->BankPassWord != nullptr)
			{
				field->BankPassWord = gcnew String(pReqRepeal->BankPassWord);
			}
			//投资者帐号
			if (pReqRepeal->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pReqRepeal->AccountID);
			}
			//期货密码
			if (pReqRepeal->Password != nullptr)
			{
				field->Password = gcnew String(pReqRepeal->Password);
			}
			//安装编号
			field->InstallID = pReqRepeal->InstallID;
			//期货公司流水号
			field->FutureSerial = pReqRepeal->FutureSerial;
			//用户标识
			if (pReqRepeal->UserID != nullptr)
			{
				field->UserID = gcnew String(pReqRepeal->UserID);
			}
			//验证客户证件号码标志
			field->VerifyCertNoFlag = (CtpNetYesNoIndicatorType)pReqRepeal->VerifyCertNoFlag;
			//币种代码
			if (pReqRepeal->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pReqRepeal->CurrencyID);
			}
			//转帐金额
			field->TradeAmount = pReqRepeal->TradeAmount;
			//期货可取金额
			field->FutureFetchAmount = pReqRepeal->FutureFetchAmount;
			//费用支付标志
			field->FeePayFlag = (CtpNetFeePayFlagType)pReqRepeal->FeePayFlag;
			//应收客户费用
			field->CustFee = pReqRepeal->CustFee;
			//应收期货公司费用
			field->BrokerFee = pReqRepeal->BrokerFee;
			//发送方给接收方的消息
			if (pReqRepeal->Message != nullptr)
			{
				field->Message = gcnew String(pReqRepeal->Message);
			}
			//摘要
			if (pReqRepeal->Digest != nullptr)
			{
				field->Digest = gcnew String(pReqRepeal->Digest);
			}
			//银行帐号类型
			field->BankAccType = (CtpNetBankAccTypeType)pReqRepeal->BankAccType;
			//渠道标志
			if (pReqRepeal->DeviceID != nullptr)
			{
				field->DeviceID = gcnew String(pReqRepeal->DeviceID);
			}
			//期货单位帐号类型
			field->BankSecuAccType = (CtpNetBankAccTypeType)pReqRepeal->BankSecuAccType;
			//期货公司银行编码
			if (pReqRepeal->BrokerIDByBank != nullptr)
			{
				field->BrokerIDByBank = gcnew String(pReqRepeal->BrokerIDByBank);
			}
			//期货单位帐号
			if (pReqRepeal->BankSecuAcc != nullptr)
			{
				field->BankSecuAcc = gcnew String(pReqRepeal->BankSecuAcc);
			}
			//银行密码标志
			field->BankPwdFlag = (CtpNetPwdFlagType)pReqRepeal->BankPwdFlag;
			//期货资金密码核对标志
			field->SecuPwdFlag = (CtpNetPwdFlagType)pReqRepeal->SecuPwdFlag;
			//交易柜员
			if (pReqRepeal->OperNo != nullptr)
			{
				field->OperNo = gcnew String(pReqRepeal->OperNo);
			}
			//请求编号
			field->RequestID = pReqRepeal->RequestID;
			//交易ID
			field->TID = pReqRepeal->TID;
			//转账交易状态
			field->TransferStatus = (CtpNetTransferStatusType)pReqRepeal->TransferStatus;
			//长客户姓名
			if (pReqRepeal->LongCustomerName != nullptr)
			{
				field->LongCustomerName = gcnew String(pReqRepeal->LongCustomerName);
			}
		}
		
		m_pAdapter->OnErrRtnRepealBankToFutureByFutureManual(field, RspInfoField(pRspInfo));
	};

	// 系统运行时期货端手工发起冲正期货转银行错误回报
	void CTraderSpi::OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo)
	{
		if (m_pAdapter->OnErrRtnRepealFutureToBankByFutureManual_delegate == nullptr) return;
		
		CtpNetReqRepealField^ field = nullptr;
		if (pReqRepeal != nullptr)
		{
			field = gcnew CtpNetReqRepealField;
			
			//冲正时间间隔
			field->RepealTimeInterval = pReqRepeal->RepealTimeInterval;
			//已经冲正次数
			field->RepealedTimes = pReqRepeal->RepealedTimes;
			//银行冲正标志
			field->BankRepealFlag = (CtpNetBankRepealFlagType)pReqRepeal->BankRepealFlag;
			//期商冲正标志
			field->BrokerRepealFlag = (CtpNetBrokerRepealFlagType)pReqRepeal->BrokerRepealFlag;
			//被冲正平台流水号
			field->PlateRepealSerial = pReqRepeal->PlateRepealSerial;
			//被冲正银行流水号
			if (pReqRepeal->BankRepealSerial != nullptr)
			{
				field->BankRepealSerial = gcnew String(pReqRepeal->BankRepealSerial);
			}
			//被冲正期货流水号
			field->FutureRepealSerial = pReqRepeal->FutureRepealSerial;
			//业务功能码
			if (pReqRepeal->TradeCode != nullptr)
			{
				field->TradeCode = gcnew String(pReqRepeal->TradeCode);
			}
			//银行代码
			if (pReqRepeal->BankID != nullptr)
			{
				field->BankID = gcnew String(pReqRepeal->BankID);
			}
			//银行分支机构代码
			if (pReqRepeal->BankBranchID != nullptr)
			{
				field->BankBranchID = gcnew String(pReqRepeal->BankBranchID);
			}
			//期商代码
			if (pReqRepeal->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pReqRepeal->BrokerID);
			}
			//期商分支机构代码
			if (pReqRepeal->BrokerBranchID != nullptr)
			{
				field->BrokerBranchID = gcnew String(pReqRepeal->BrokerBranchID);
			}
			//交易日期
			if (pReqRepeal->TradeDate != nullptr)
			{
				field->TradeDate = gcnew String(pReqRepeal->TradeDate);
			}
			//交易时间
			if (pReqRepeal->TradeTime != nullptr)
			{
				field->TradeTime = gcnew String(pReqRepeal->TradeTime);
			}
			//银行流水号
			if (pReqRepeal->BankSerial != nullptr)
			{
				field->BankSerial = gcnew String(pReqRepeal->BankSerial);
			}
			//交易系统日期
			if (pReqRepeal->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pReqRepeal->TradingDay);
			}
			//银期平台消息流水号
			field->PlateSerial = pReqRepeal->PlateSerial;
			//最后分片标志
			field->LastFragment = (CtpNetLastFragmentType)pReqRepeal->LastFragment;
			//会话号
			field->SessionID = pReqRepeal->SessionID;
			//客户姓名
			if (pReqRepeal->CustomerName != nullptr)
			{
				field->CustomerName = gcnew String(pReqRepeal->CustomerName);
			}
			//证件类型
			field->IdCardType = (CtpNetIdCardTypeType)pReqRepeal->IdCardType;
			//证件号码
			if (pReqRepeal->IdentifiedCardNo != nullptr)
			{
				field->IdentifiedCardNo = gcnew String(pReqRepeal->IdentifiedCardNo);
			}
			//客户类型
			field->CustType = (CtpNetCustTypeType)pReqRepeal->CustType;
			//银行帐号
			if (pReqRepeal->BankAccount != nullptr)
			{
				field->BankAccount = gcnew String(pReqRepeal->BankAccount);
			}
			//银行密码
			if (pReqRepeal->BankPassWord != nullptr)
			{
				field->BankPassWord = gcnew String(pReqRepeal->BankPassWord);
			}
			//投资者帐号
			if (pReqRepeal->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pReqRepeal->AccountID);
			}
			//期货密码
			if (pReqRepeal->Password != nullptr)
			{
				field->Password = gcnew String(pReqRepeal->Password);
			}
			//安装编号
			field->InstallID = pReqRepeal->InstallID;
			//期货公司流水号
			field->FutureSerial = pReqRepeal->FutureSerial;
			//用户标识
			if (pReqRepeal->UserID != nullptr)
			{
				field->UserID = gcnew String(pReqRepeal->UserID);
			}
			//验证客户证件号码标志
			field->VerifyCertNoFlag = (CtpNetYesNoIndicatorType)pReqRepeal->VerifyCertNoFlag;
			//币种代码
			if (pReqRepeal->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pReqRepeal->CurrencyID);
			}
			//转帐金额
			field->TradeAmount = pReqRepeal->TradeAmount;
			//期货可取金额
			field->FutureFetchAmount = pReqRepeal->FutureFetchAmount;
			//费用支付标志
			field->FeePayFlag = (CtpNetFeePayFlagType)pReqRepeal->FeePayFlag;
			//应收客户费用
			field->CustFee = pReqRepeal->CustFee;
			//应收期货公司费用
			field->BrokerFee = pReqRepeal->BrokerFee;
			//发送方给接收方的消息
			if (pReqRepeal->Message != nullptr)
			{
				field->Message = gcnew String(pReqRepeal->Message);
			}
			//摘要
			if (pReqRepeal->Digest != nullptr)
			{
				field->Digest = gcnew String(pReqRepeal->Digest);
			}
			//银行帐号类型
			field->BankAccType = (CtpNetBankAccTypeType)pReqRepeal->BankAccType;
			//渠道标志
			if (pReqRepeal->DeviceID != nullptr)
			{
				field->DeviceID = gcnew String(pReqRepeal->DeviceID);
			}
			//期货单位帐号类型
			field->BankSecuAccType = (CtpNetBankAccTypeType)pReqRepeal->BankSecuAccType;
			//期货公司银行编码
			if (pReqRepeal->BrokerIDByBank != nullptr)
			{
				field->BrokerIDByBank = gcnew String(pReqRepeal->BrokerIDByBank);
			}
			//期货单位帐号
			if (pReqRepeal->BankSecuAcc != nullptr)
			{
				field->BankSecuAcc = gcnew String(pReqRepeal->BankSecuAcc);
			}
			//银行密码标志
			field->BankPwdFlag = (CtpNetPwdFlagType)pReqRepeal->BankPwdFlag;
			//期货资金密码核对标志
			field->SecuPwdFlag = (CtpNetPwdFlagType)pReqRepeal->SecuPwdFlag;
			//交易柜员
			if (pReqRepeal->OperNo != nullptr)
			{
				field->OperNo = gcnew String(pReqRepeal->OperNo);
			}
			//请求编号
			field->RequestID = pReqRepeal->RequestID;
			//交易ID
			field->TID = pReqRepeal->TID;
			//转账交易状态
			field->TransferStatus = (CtpNetTransferStatusType)pReqRepeal->TransferStatus;
			//长客户姓名
			if (pReqRepeal->LongCustomerName != nullptr)
			{
				field->LongCustomerName = gcnew String(pReqRepeal->LongCustomerName);
			}
		}
		
		m_pAdapter->OnErrRtnRepealFutureToBankByFutureManual(field, RspInfoField(pRspInfo));
	};

	// 期货发起查询银行余额错误回报
	void CTraderSpi::OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo)
	{
		if (m_pAdapter->OnErrRtnQueryBankBalanceByFuture_delegate == nullptr) return;
		
		CtpNetReqQueryAccountField^ field = nullptr;
		if (pReqQueryAccount != nullptr)
		{
			field = gcnew CtpNetReqQueryAccountField;
			
			//业务功能码
			if (pReqQueryAccount->TradeCode != nullptr)
			{
				field->TradeCode = gcnew String(pReqQueryAccount->TradeCode);
			}
			//银行代码
			if (pReqQueryAccount->BankID != nullptr)
			{
				field->BankID = gcnew String(pReqQueryAccount->BankID);
			}
			//银行分支机构代码
			if (pReqQueryAccount->BankBranchID != nullptr)
			{
				field->BankBranchID = gcnew String(pReqQueryAccount->BankBranchID);
			}
			//期商代码
			if (pReqQueryAccount->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pReqQueryAccount->BrokerID);
			}
			//期商分支机构代码
			if (pReqQueryAccount->BrokerBranchID != nullptr)
			{
				field->BrokerBranchID = gcnew String(pReqQueryAccount->BrokerBranchID);
			}
			//交易日期
			if (pReqQueryAccount->TradeDate != nullptr)
			{
				field->TradeDate = gcnew String(pReqQueryAccount->TradeDate);
			}
			//交易时间
			if (pReqQueryAccount->TradeTime != nullptr)
			{
				field->TradeTime = gcnew String(pReqQueryAccount->TradeTime);
			}
			//银行流水号
			if (pReqQueryAccount->BankSerial != nullptr)
			{
				field->BankSerial = gcnew String(pReqQueryAccount->BankSerial);
			}
			//交易系统日期
			if (pReqQueryAccount->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pReqQueryAccount->TradingDay);
			}
			//银期平台消息流水号
			field->PlateSerial = pReqQueryAccount->PlateSerial;
			//最后分片标志
			field->LastFragment = (CtpNetLastFragmentType)pReqQueryAccount->LastFragment;
			//会话号
			field->SessionID = pReqQueryAccount->SessionID;
			//客户姓名
			if (pReqQueryAccount->CustomerName != nullptr)
			{
				field->CustomerName = gcnew String(pReqQueryAccount->CustomerName);
			}
			//证件类型
			field->IdCardType = (CtpNetIdCardTypeType)pReqQueryAccount->IdCardType;
			//证件号码
			if (pReqQueryAccount->IdentifiedCardNo != nullptr)
			{
				field->IdentifiedCardNo = gcnew String(pReqQueryAccount->IdentifiedCardNo);
			}
			//客户类型
			field->CustType = (CtpNetCustTypeType)pReqQueryAccount->CustType;
			//银行帐号
			if (pReqQueryAccount->BankAccount != nullptr)
			{
				field->BankAccount = gcnew String(pReqQueryAccount->BankAccount);
			}
			//银行密码
			if (pReqQueryAccount->BankPassWord != nullptr)
			{
				field->BankPassWord = gcnew String(pReqQueryAccount->BankPassWord);
			}
			//投资者帐号
			if (pReqQueryAccount->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pReqQueryAccount->AccountID);
			}
			//期货密码
			if (pReqQueryAccount->Password != nullptr)
			{
				field->Password = gcnew String(pReqQueryAccount->Password);
			}
			//期货公司流水号
			field->FutureSerial = pReqQueryAccount->FutureSerial;
			//安装编号
			field->InstallID = pReqQueryAccount->InstallID;
			//用户标识
			if (pReqQueryAccount->UserID != nullptr)
			{
				field->UserID = gcnew String(pReqQueryAccount->UserID);
			}
			//验证客户证件号码标志
			field->VerifyCertNoFlag = (CtpNetYesNoIndicatorType)pReqQueryAccount->VerifyCertNoFlag;
			//币种代码
			if (pReqQueryAccount->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pReqQueryAccount->CurrencyID);
			}
			//摘要
			if (pReqQueryAccount->Digest != nullptr)
			{
				field->Digest = gcnew String(pReqQueryAccount->Digest);
			}
			//银行帐号类型
			field->BankAccType = (CtpNetBankAccTypeType)pReqQueryAccount->BankAccType;
			//渠道标志
			if (pReqQueryAccount->DeviceID != nullptr)
			{
				field->DeviceID = gcnew String(pReqQueryAccount->DeviceID);
			}
			//期货单位帐号类型
			field->BankSecuAccType = (CtpNetBankAccTypeType)pReqQueryAccount->BankSecuAccType;
			//期货公司银行编码
			if (pReqQueryAccount->BrokerIDByBank != nullptr)
			{
				field->BrokerIDByBank = gcnew String(pReqQueryAccount->BrokerIDByBank);
			}
			//期货单位帐号
			if (pReqQueryAccount->BankSecuAcc != nullptr)
			{
				field->BankSecuAcc = gcnew String(pReqQueryAccount->BankSecuAcc);
			}
			//银行密码标志
			field->BankPwdFlag = (CtpNetPwdFlagType)pReqQueryAccount->BankPwdFlag;
			//期货资金密码核对标志
			field->SecuPwdFlag = (CtpNetPwdFlagType)pReqQueryAccount->SecuPwdFlag;
			//交易柜员
			if (pReqQueryAccount->OperNo != nullptr)
			{
				field->OperNo = gcnew String(pReqQueryAccount->OperNo);
			}
			//请求编号
			field->RequestID = pReqQueryAccount->RequestID;
			//交易ID
			field->TID = pReqQueryAccount->TID;
			//长客户姓名
			if (pReqQueryAccount->LongCustomerName != nullptr)
			{
				field->LongCustomerName = gcnew String(pReqQueryAccount->LongCustomerName);
			}
		}
		
		m_pAdapter->OnErrRtnQueryBankBalanceByFuture(field, RspInfoField(pRspInfo));
	};

	// 期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
	void CTraderSpi::OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField *pRspRepeal)
	{
		if (m_pAdapter->OnRtnRepealFromBankToFutureByFuture_delegate == nullptr) return;
		
		CtpNetRspRepealField^ field = nullptr;
		if (pRspRepeal != nullptr)
		{
			field = gcnew CtpNetRspRepealField;
			
			//冲正时间间隔
			field->RepealTimeInterval = pRspRepeal->RepealTimeInterval;
			//已经冲正次数
			field->RepealedTimes = pRspRepeal->RepealedTimes;
			//银行冲正标志
			field->BankRepealFlag = (CtpNetBankRepealFlagType)pRspRepeal->BankRepealFlag;
			//期商冲正标志
			field->BrokerRepealFlag = (CtpNetBrokerRepealFlagType)pRspRepeal->BrokerRepealFlag;
			//被冲正平台流水号
			field->PlateRepealSerial = pRspRepeal->PlateRepealSerial;
			//被冲正银行流水号
			if (pRspRepeal->BankRepealSerial != nullptr)
			{
				field->BankRepealSerial = gcnew String(pRspRepeal->BankRepealSerial);
			}
			//被冲正期货流水号
			field->FutureRepealSerial = pRspRepeal->FutureRepealSerial;
			//业务功能码
			if (pRspRepeal->TradeCode != nullptr)
			{
				field->TradeCode = gcnew String(pRspRepeal->TradeCode);
			}
			//银行代码
			if (pRspRepeal->BankID != nullptr)
			{
				field->BankID = gcnew String(pRspRepeal->BankID);
			}
			//银行分支机构代码
			if (pRspRepeal->BankBranchID != nullptr)
			{
				field->BankBranchID = gcnew String(pRspRepeal->BankBranchID);
			}
			//期商代码
			if (pRspRepeal->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pRspRepeal->BrokerID);
			}
			//期商分支机构代码
			if (pRspRepeal->BrokerBranchID != nullptr)
			{
				field->BrokerBranchID = gcnew String(pRspRepeal->BrokerBranchID);
			}
			//交易日期
			if (pRspRepeal->TradeDate != nullptr)
			{
				field->TradeDate = gcnew String(pRspRepeal->TradeDate);
			}
			//交易时间
			if (pRspRepeal->TradeTime != nullptr)
			{
				field->TradeTime = gcnew String(pRspRepeal->TradeTime);
			}
			//银行流水号
			if (pRspRepeal->BankSerial != nullptr)
			{
				field->BankSerial = gcnew String(pRspRepeal->BankSerial);
			}
			//交易系统日期
			if (pRspRepeal->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pRspRepeal->TradingDay);
			}
			//银期平台消息流水号
			field->PlateSerial = pRspRepeal->PlateSerial;
			//最后分片标志
			field->LastFragment = (CtpNetLastFragmentType)pRspRepeal->LastFragment;
			//会话号
			field->SessionID = pRspRepeal->SessionID;
			//客户姓名
			if (pRspRepeal->CustomerName != nullptr)
			{
				field->CustomerName = gcnew String(pRspRepeal->CustomerName);
			}
			//证件类型
			field->IdCardType = (CtpNetIdCardTypeType)pRspRepeal->IdCardType;
			//证件号码
			if (pRspRepeal->IdentifiedCardNo != nullptr)
			{
				field->IdentifiedCardNo = gcnew String(pRspRepeal->IdentifiedCardNo);
			}
			//客户类型
			field->CustType = (CtpNetCustTypeType)pRspRepeal->CustType;
			//银行帐号
			if (pRspRepeal->BankAccount != nullptr)
			{
				field->BankAccount = gcnew String(pRspRepeal->BankAccount);
			}
			//银行密码
			if (pRspRepeal->BankPassWord != nullptr)
			{
				field->BankPassWord = gcnew String(pRspRepeal->BankPassWord);
			}
			//投资者帐号
			if (pRspRepeal->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pRspRepeal->AccountID);
			}
			//期货密码
			if (pRspRepeal->Password != nullptr)
			{
				field->Password = gcnew String(pRspRepeal->Password);
			}
			//安装编号
			field->InstallID = pRspRepeal->InstallID;
			//期货公司流水号
			field->FutureSerial = pRspRepeal->FutureSerial;
			//用户标识
			if (pRspRepeal->UserID != nullptr)
			{
				field->UserID = gcnew String(pRspRepeal->UserID);
			}
			//验证客户证件号码标志
			field->VerifyCertNoFlag = (CtpNetYesNoIndicatorType)pRspRepeal->VerifyCertNoFlag;
			//币种代码
			if (pRspRepeal->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pRspRepeal->CurrencyID);
			}
			//转帐金额
			field->TradeAmount = pRspRepeal->TradeAmount;
			//期货可取金额
			field->FutureFetchAmount = pRspRepeal->FutureFetchAmount;
			//费用支付标志
			field->FeePayFlag = (CtpNetFeePayFlagType)pRspRepeal->FeePayFlag;
			//应收客户费用
			field->CustFee = pRspRepeal->CustFee;
			//应收期货公司费用
			field->BrokerFee = pRspRepeal->BrokerFee;
			//发送方给接收方的消息
			if (pRspRepeal->Message != nullptr)
			{
				field->Message = gcnew String(pRspRepeal->Message);
			}
			//摘要
			if (pRspRepeal->Digest != nullptr)
			{
				field->Digest = gcnew String(pRspRepeal->Digest);
			}
			//银行帐号类型
			field->BankAccType = (CtpNetBankAccTypeType)pRspRepeal->BankAccType;
			//渠道标志
			if (pRspRepeal->DeviceID != nullptr)
			{
				field->DeviceID = gcnew String(pRspRepeal->DeviceID);
			}
			//期货单位帐号类型
			field->BankSecuAccType = (CtpNetBankAccTypeType)pRspRepeal->BankSecuAccType;
			//期货公司银行编码
			if (pRspRepeal->BrokerIDByBank != nullptr)
			{
				field->BrokerIDByBank = gcnew String(pRspRepeal->BrokerIDByBank);
			}
			//期货单位帐号
			if (pRspRepeal->BankSecuAcc != nullptr)
			{
				field->BankSecuAcc = gcnew String(pRspRepeal->BankSecuAcc);
			}
			//银行密码标志
			field->BankPwdFlag = (CtpNetPwdFlagType)pRspRepeal->BankPwdFlag;
			//期货资金密码核对标志
			field->SecuPwdFlag = (CtpNetPwdFlagType)pRspRepeal->SecuPwdFlag;
			//交易柜员
			if (pRspRepeal->OperNo != nullptr)
			{
				field->OperNo = gcnew String(pRspRepeal->OperNo);
			}
			//请求编号
			field->RequestID = pRspRepeal->RequestID;
			//交易ID
			field->TID = pRspRepeal->TID;
			//转账交易状态
			field->TransferStatus = (CtpNetTransferStatusType)pRspRepeal->TransferStatus;
			//错误代码
			field->ErrorID = pRspRepeal->ErrorID;
			//错误信息
			if (pRspRepeal->ErrorMsg != nullptr)
			{
				field->ErrorMsg = gcnew String(pRspRepeal->ErrorMsg);
			}
			//长客户姓名
			if (pRspRepeal->LongCustomerName != nullptr)
			{
				field->LongCustomerName = gcnew String(pRspRepeal->LongCustomerName);
			}
		}
		
		m_pAdapter->OnRtnRepealFromBankToFutureByFuture(field);
	};

	// 期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
	void CTraderSpi::OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField *pRspRepeal)
	{
		if (m_pAdapter->OnRtnRepealFromFutureToBankByFuture_delegate == nullptr) return;
		
		CtpNetRspRepealField^ field = nullptr;
		if (pRspRepeal != nullptr)
		{
			field = gcnew CtpNetRspRepealField;
			
			//冲正时间间隔
			field->RepealTimeInterval = pRspRepeal->RepealTimeInterval;
			//已经冲正次数
			field->RepealedTimes = pRspRepeal->RepealedTimes;
			//银行冲正标志
			field->BankRepealFlag = (CtpNetBankRepealFlagType)pRspRepeal->BankRepealFlag;
			//期商冲正标志
			field->BrokerRepealFlag = (CtpNetBrokerRepealFlagType)pRspRepeal->BrokerRepealFlag;
			//被冲正平台流水号
			field->PlateRepealSerial = pRspRepeal->PlateRepealSerial;
			//被冲正银行流水号
			if (pRspRepeal->BankRepealSerial != nullptr)
			{
				field->BankRepealSerial = gcnew String(pRspRepeal->BankRepealSerial);
			}
			//被冲正期货流水号
			field->FutureRepealSerial = pRspRepeal->FutureRepealSerial;
			//业务功能码
			if (pRspRepeal->TradeCode != nullptr)
			{
				field->TradeCode = gcnew String(pRspRepeal->TradeCode);
			}
			//银行代码
			if (pRspRepeal->BankID != nullptr)
			{
				field->BankID = gcnew String(pRspRepeal->BankID);
			}
			//银行分支机构代码
			if (pRspRepeal->BankBranchID != nullptr)
			{
				field->BankBranchID = gcnew String(pRspRepeal->BankBranchID);
			}
			//期商代码
			if (pRspRepeal->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pRspRepeal->BrokerID);
			}
			//期商分支机构代码
			if (pRspRepeal->BrokerBranchID != nullptr)
			{
				field->BrokerBranchID = gcnew String(pRspRepeal->BrokerBranchID);
			}
			//交易日期
			if (pRspRepeal->TradeDate != nullptr)
			{
				field->TradeDate = gcnew String(pRspRepeal->TradeDate);
			}
			//交易时间
			if (pRspRepeal->TradeTime != nullptr)
			{
				field->TradeTime = gcnew String(pRspRepeal->TradeTime);
			}
			//银行流水号
			if (pRspRepeal->BankSerial != nullptr)
			{
				field->BankSerial = gcnew String(pRspRepeal->BankSerial);
			}
			//交易系统日期
			if (pRspRepeal->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pRspRepeal->TradingDay);
			}
			//银期平台消息流水号
			field->PlateSerial = pRspRepeal->PlateSerial;
			//最后分片标志
			field->LastFragment = (CtpNetLastFragmentType)pRspRepeal->LastFragment;
			//会话号
			field->SessionID = pRspRepeal->SessionID;
			//客户姓名
			if (pRspRepeal->CustomerName != nullptr)
			{
				field->CustomerName = gcnew String(pRspRepeal->CustomerName);
			}
			//证件类型
			field->IdCardType = (CtpNetIdCardTypeType)pRspRepeal->IdCardType;
			//证件号码
			if (pRspRepeal->IdentifiedCardNo != nullptr)
			{
				field->IdentifiedCardNo = gcnew String(pRspRepeal->IdentifiedCardNo);
			}
			//客户类型
			field->CustType = (CtpNetCustTypeType)pRspRepeal->CustType;
			//银行帐号
			if (pRspRepeal->BankAccount != nullptr)
			{
				field->BankAccount = gcnew String(pRspRepeal->BankAccount);
			}
			//银行密码
			if (pRspRepeal->BankPassWord != nullptr)
			{
				field->BankPassWord = gcnew String(pRspRepeal->BankPassWord);
			}
			//投资者帐号
			if (pRspRepeal->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pRspRepeal->AccountID);
			}
			//期货密码
			if (pRspRepeal->Password != nullptr)
			{
				field->Password = gcnew String(pRspRepeal->Password);
			}
			//安装编号
			field->InstallID = pRspRepeal->InstallID;
			//期货公司流水号
			field->FutureSerial = pRspRepeal->FutureSerial;
			//用户标识
			if (pRspRepeal->UserID != nullptr)
			{
				field->UserID = gcnew String(pRspRepeal->UserID);
			}
			//验证客户证件号码标志
			field->VerifyCertNoFlag = (CtpNetYesNoIndicatorType)pRspRepeal->VerifyCertNoFlag;
			//币种代码
			if (pRspRepeal->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pRspRepeal->CurrencyID);
			}
			//转帐金额
			field->TradeAmount = pRspRepeal->TradeAmount;
			//期货可取金额
			field->FutureFetchAmount = pRspRepeal->FutureFetchAmount;
			//费用支付标志
			field->FeePayFlag = (CtpNetFeePayFlagType)pRspRepeal->FeePayFlag;
			//应收客户费用
			field->CustFee = pRspRepeal->CustFee;
			//应收期货公司费用
			field->BrokerFee = pRspRepeal->BrokerFee;
			//发送方给接收方的消息
			if (pRspRepeal->Message != nullptr)
			{
				field->Message = gcnew String(pRspRepeal->Message);
			}
			//摘要
			if (pRspRepeal->Digest != nullptr)
			{
				field->Digest = gcnew String(pRspRepeal->Digest);
			}
			//银行帐号类型
			field->BankAccType = (CtpNetBankAccTypeType)pRspRepeal->BankAccType;
			//渠道标志
			if (pRspRepeal->DeviceID != nullptr)
			{
				field->DeviceID = gcnew String(pRspRepeal->DeviceID);
			}
			//期货单位帐号类型
			field->BankSecuAccType = (CtpNetBankAccTypeType)pRspRepeal->BankSecuAccType;
			//期货公司银行编码
			if (pRspRepeal->BrokerIDByBank != nullptr)
			{
				field->BrokerIDByBank = gcnew String(pRspRepeal->BrokerIDByBank);
			}
			//期货单位帐号
			if (pRspRepeal->BankSecuAcc != nullptr)
			{
				field->BankSecuAcc = gcnew String(pRspRepeal->BankSecuAcc);
			}
			//银行密码标志
			field->BankPwdFlag = (CtpNetPwdFlagType)pRspRepeal->BankPwdFlag;
			//期货资金密码核对标志
			field->SecuPwdFlag = (CtpNetPwdFlagType)pRspRepeal->SecuPwdFlag;
			//交易柜员
			if (pRspRepeal->OperNo != nullptr)
			{
				field->OperNo = gcnew String(pRspRepeal->OperNo);
			}
			//请求编号
			field->RequestID = pRspRepeal->RequestID;
			//交易ID
			field->TID = pRspRepeal->TID;
			//转账交易状态
			field->TransferStatus = (CtpNetTransferStatusType)pRspRepeal->TransferStatus;
			//错误代码
			field->ErrorID = pRspRepeal->ErrorID;
			//错误信息
			if (pRspRepeal->ErrorMsg != nullptr)
			{
				field->ErrorMsg = gcnew String(pRspRepeal->ErrorMsg);
			}
			//长客户姓名
			if (pRspRepeal->LongCustomerName != nullptr)
			{
				field->LongCustomerName = gcnew String(pRspRepeal->LongCustomerName);
			}
		}
		
		m_pAdapter->OnRtnRepealFromFutureToBankByFuture(field);
	};

	// 期货发起银行资金转期货应答
	void CTraderSpi::OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspFromBankToFutureByFuture_delegate == nullptr) return;
		
		CtpNetReqTransferField^ field = nullptr;
		if (pReqTransfer != nullptr)
		{
			field = gcnew CtpNetReqTransferField;
			
			//业务功能码
			if (pReqTransfer->TradeCode != nullptr)
			{
				field->TradeCode = gcnew String(pReqTransfer->TradeCode);
			}
			//银行代码
			if (pReqTransfer->BankID != nullptr)
			{
				field->BankID = gcnew String(pReqTransfer->BankID);
			}
			//银行分支机构代码
			if (pReqTransfer->BankBranchID != nullptr)
			{
				field->BankBranchID = gcnew String(pReqTransfer->BankBranchID);
			}
			//期商代码
			if (pReqTransfer->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pReqTransfer->BrokerID);
			}
			//期商分支机构代码
			if (pReqTransfer->BrokerBranchID != nullptr)
			{
				field->BrokerBranchID = gcnew String(pReqTransfer->BrokerBranchID);
			}
			//交易日期
			if (pReqTransfer->TradeDate != nullptr)
			{
				field->TradeDate = gcnew String(pReqTransfer->TradeDate);
			}
			//交易时间
			if (pReqTransfer->TradeTime != nullptr)
			{
				field->TradeTime = gcnew String(pReqTransfer->TradeTime);
			}
			//银行流水号
			if (pReqTransfer->BankSerial != nullptr)
			{
				field->BankSerial = gcnew String(pReqTransfer->BankSerial);
			}
			//交易系统日期
			if (pReqTransfer->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pReqTransfer->TradingDay);
			}
			//银期平台消息流水号
			field->PlateSerial = pReqTransfer->PlateSerial;
			//最后分片标志
			field->LastFragment = (CtpNetLastFragmentType)pReqTransfer->LastFragment;
			//会话号
			field->SessionID = pReqTransfer->SessionID;
			//客户姓名
			if (pReqTransfer->CustomerName != nullptr)
			{
				field->CustomerName = gcnew String(pReqTransfer->CustomerName);
			}
			//证件类型
			field->IdCardType = (CtpNetIdCardTypeType)pReqTransfer->IdCardType;
			//证件号码
			if (pReqTransfer->IdentifiedCardNo != nullptr)
			{
				field->IdentifiedCardNo = gcnew String(pReqTransfer->IdentifiedCardNo);
			}
			//客户类型
			field->CustType = (CtpNetCustTypeType)pReqTransfer->CustType;
			//银行帐号
			if (pReqTransfer->BankAccount != nullptr)
			{
				field->BankAccount = gcnew String(pReqTransfer->BankAccount);
			}
			//银行密码
			if (pReqTransfer->BankPassWord != nullptr)
			{
				field->BankPassWord = gcnew String(pReqTransfer->BankPassWord);
			}
			//投资者帐号
			if (pReqTransfer->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pReqTransfer->AccountID);
			}
			//期货密码
			if (pReqTransfer->Password != nullptr)
			{
				field->Password = gcnew String(pReqTransfer->Password);
			}
			//安装编号
			field->InstallID = pReqTransfer->InstallID;
			//期货公司流水号
			field->FutureSerial = pReqTransfer->FutureSerial;
			//用户标识
			if (pReqTransfer->UserID != nullptr)
			{
				field->UserID = gcnew String(pReqTransfer->UserID);
			}
			//验证客户证件号码标志
			field->VerifyCertNoFlag = (CtpNetYesNoIndicatorType)pReqTransfer->VerifyCertNoFlag;
			//币种代码
			if (pReqTransfer->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pReqTransfer->CurrencyID);
			}
			//转帐金额
			field->TradeAmount = pReqTransfer->TradeAmount;
			//期货可取金额
			field->FutureFetchAmount = pReqTransfer->FutureFetchAmount;
			//费用支付标志
			field->FeePayFlag = (CtpNetFeePayFlagType)pReqTransfer->FeePayFlag;
			//应收客户费用
			field->CustFee = pReqTransfer->CustFee;
			//应收期货公司费用
			field->BrokerFee = pReqTransfer->BrokerFee;
			//发送方给接收方的消息
			if (pReqTransfer->Message != nullptr)
			{
				field->Message = gcnew String(pReqTransfer->Message);
			}
			//摘要
			if (pReqTransfer->Digest != nullptr)
			{
				field->Digest = gcnew String(pReqTransfer->Digest);
			}
			//银行帐号类型
			field->BankAccType = (CtpNetBankAccTypeType)pReqTransfer->BankAccType;
			//渠道标志
			if (pReqTransfer->DeviceID != nullptr)
			{
				field->DeviceID = gcnew String(pReqTransfer->DeviceID);
			}
			//期货单位帐号类型
			field->BankSecuAccType = (CtpNetBankAccTypeType)pReqTransfer->BankSecuAccType;
			//期货公司银行编码
			if (pReqTransfer->BrokerIDByBank != nullptr)
			{
				field->BrokerIDByBank = gcnew String(pReqTransfer->BrokerIDByBank);
			}
			//期货单位帐号
			if (pReqTransfer->BankSecuAcc != nullptr)
			{
				field->BankSecuAcc = gcnew String(pReqTransfer->BankSecuAcc);
			}
			//银行密码标志
			field->BankPwdFlag = (CtpNetPwdFlagType)pReqTransfer->BankPwdFlag;
			//期货资金密码核对标志
			field->SecuPwdFlag = (CtpNetPwdFlagType)pReqTransfer->SecuPwdFlag;
			//交易柜员
			if (pReqTransfer->OperNo != nullptr)
			{
				field->OperNo = gcnew String(pReqTransfer->OperNo);
			}
			//请求编号
			field->RequestID = pReqTransfer->RequestID;
			//交易ID
			field->TID = pReqTransfer->TID;
			//转账交易状态
			field->TransferStatus = (CtpNetTransferStatusType)pReqTransfer->TransferStatus;
			//长客户姓名
			if (pReqTransfer->LongCustomerName != nullptr)
			{
				field->LongCustomerName = gcnew String(pReqTransfer->LongCustomerName);
			}
		}
		
		m_pAdapter->OnRspFromBankToFutureByFuture(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 期货发起期货资金转银行应答
	void CTraderSpi::OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspFromFutureToBankByFuture_delegate == nullptr) return;
		
		CtpNetReqTransferField^ field = nullptr;
		if (pReqTransfer != nullptr)
		{
			field = gcnew CtpNetReqTransferField;
			
			//业务功能码
			if (pReqTransfer->TradeCode != nullptr)
			{
				field->TradeCode = gcnew String(pReqTransfer->TradeCode);
			}
			//银行代码
			if (pReqTransfer->BankID != nullptr)
			{
				field->BankID = gcnew String(pReqTransfer->BankID);
			}
			//银行分支机构代码
			if (pReqTransfer->BankBranchID != nullptr)
			{
				field->BankBranchID = gcnew String(pReqTransfer->BankBranchID);
			}
			//期商代码
			if (pReqTransfer->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pReqTransfer->BrokerID);
			}
			//期商分支机构代码
			if (pReqTransfer->BrokerBranchID != nullptr)
			{
				field->BrokerBranchID = gcnew String(pReqTransfer->BrokerBranchID);
			}
			//交易日期
			if (pReqTransfer->TradeDate != nullptr)
			{
				field->TradeDate = gcnew String(pReqTransfer->TradeDate);
			}
			//交易时间
			if (pReqTransfer->TradeTime != nullptr)
			{
				field->TradeTime = gcnew String(pReqTransfer->TradeTime);
			}
			//银行流水号
			if (pReqTransfer->BankSerial != nullptr)
			{
				field->BankSerial = gcnew String(pReqTransfer->BankSerial);
			}
			//交易系统日期
			if (pReqTransfer->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pReqTransfer->TradingDay);
			}
			//银期平台消息流水号
			field->PlateSerial = pReqTransfer->PlateSerial;
			//最后分片标志
			field->LastFragment = (CtpNetLastFragmentType)pReqTransfer->LastFragment;
			//会话号
			field->SessionID = pReqTransfer->SessionID;
			//客户姓名
			if (pReqTransfer->CustomerName != nullptr)
			{
				field->CustomerName = gcnew String(pReqTransfer->CustomerName);
			}
			//证件类型
			field->IdCardType = (CtpNetIdCardTypeType)pReqTransfer->IdCardType;
			//证件号码
			if (pReqTransfer->IdentifiedCardNo != nullptr)
			{
				field->IdentifiedCardNo = gcnew String(pReqTransfer->IdentifiedCardNo);
			}
			//客户类型
			field->CustType = (CtpNetCustTypeType)pReqTransfer->CustType;
			//银行帐号
			if (pReqTransfer->BankAccount != nullptr)
			{
				field->BankAccount = gcnew String(pReqTransfer->BankAccount);
			}
			//银行密码
			if (pReqTransfer->BankPassWord != nullptr)
			{
				field->BankPassWord = gcnew String(pReqTransfer->BankPassWord);
			}
			//投资者帐号
			if (pReqTransfer->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pReqTransfer->AccountID);
			}
			//期货密码
			if (pReqTransfer->Password != nullptr)
			{
				field->Password = gcnew String(pReqTransfer->Password);
			}
			//安装编号
			field->InstallID = pReqTransfer->InstallID;
			//期货公司流水号
			field->FutureSerial = pReqTransfer->FutureSerial;
			//用户标识
			if (pReqTransfer->UserID != nullptr)
			{
				field->UserID = gcnew String(pReqTransfer->UserID);
			}
			//验证客户证件号码标志
			field->VerifyCertNoFlag = (CtpNetYesNoIndicatorType)pReqTransfer->VerifyCertNoFlag;
			//币种代码
			if (pReqTransfer->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pReqTransfer->CurrencyID);
			}
			//转帐金额
			field->TradeAmount = pReqTransfer->TradeAmount;
			//期货可取金额
			field->FutureFetchAmount = pReqTransfer->FutureFetchAmount;
			//费用支付标志
			field->FeePayFlag = (CtpNetFeePayFlagType)pReqTransfer->FeePayFlag;
			//应收客户费用
			field->CustFee = pReqTransfer->CustFee;
			//应收期货公司费用
			field->BrokerFee = pReqTransfer->BrokerFee;
			//发送方给接收方的消息
			if (pReqTransfer->Message != nullptr)
			{
				field->Message = gcnew String(pReqTransfer->Message);
			}
			//摘要
			if (pReqTransfer->Digest != nullptr)
			{
				field->Digest = gcnew String(pReqTransfer->Digest);
			}
			//银行帐号类型
			field->BankAccType = (CtpNetBankAccTypeType)pReqTransfer->BankAccType;
			//渠道标志
			if (pReqTransfer->DeviceID != nullptr)
			{
				field->DeviceID = gcnew String(pReqTransfer->DeviceID);
			}
			//期货单位帐号类型
			field->BankSecuAccType = (CtpNetBankAccTypeType)pReqTransfer->BankSecuAccType;
			//期货公司银行编码
			if (pReqTransfer->BrokerIDByBank != nullptr)
			{
				field->BrokerIDByBank = gcnew String(pReqTransfer->BrokerIDByBank);
			}
			//期货单位帐号
			if (pReqTransfer->BankSecuAcc != nullptr)
			{
				field->BankSecuAcc = gcnew String(pReqTransfer->BankSecuAcc);
			}
			//银行密码标志
			field->BankPwdFlag = (CtpNetPwdFlagType)pReqTransfer->BankPwdFlag;
			//期货资金密码核对标志
			field->SecuPwdFlag = (CtpNetPwdFlagType)pReqTransfer->SecuPwdFlag;
			//交易柜员
			if (pReqTransfer->OperNo != nullptr)
			{
				field->OperNo = gcnew String(pReqTransfer->OperNo);
			}
			//请求编号
			field->RequestID = pReqTransfer->RequestID;
			//交易ID
			field->TID = pReqTransfer->TID;
			//转账交易状态
			field->TransferStatus = (CtpNetTransferStatusType)pReqTransfer->TransferStatus;
			//长客户姓名
			if (pReqTransfer->LongCustomerName != nullptr)
			{
				field->LongCustomerName = gcnew String(pReqTransfer->LongCustomerName);
			}
		}
		
		m_pAdapter->OnRspFromFutureToBankByFuture(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 期货发起查询银行余额应答
	void CTraderSpi::OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspQueryBankAccountMoneyByFuture_delegate == nullptr) return;
		
		CtpNetReqQueryAccountField^ field = nullptr;
		if (pReqQueryAccount != nullptr)
		{
			field = gcnew CtpNetReqQueryAccountField;
			
			//业务功能码
			if (pReqQueryAccount->TradeCode != nullptr)
			{
				field->TradeCode = gcnew String(pReqQueryAccount->TradeCode);
			}
			//银行代码
			if (pReqQueryAccount->BankID != nullptr)
			{
				field->BankID = gcnew String(pReqQueryAccount->BankID);
			}
			//银行分支机构代码
			if (pReqQueryAccount->BankBranchID != nullptr)
			{
				field->BankBranchID = gcnew String(pReqQueryAccount->BankBranchID);
			}
			//期商代码
			if (pReqQueryAccount->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pReqQueryAccount->BrokerID);
			}
			//期商分支机构代码
			if (pReqQueryAccount->BrokerBranchID != nullptr)
			{
				field->BrokerBranchID = gcnew String(pReqQueryAccount->BrokerBranchID);
			}
			//交易日期
			if (pReqQueryAccount->TradeDate != nullptr)
			{
				field->TradeDate = gcnew String(pReqQueryAccount->TradeDate);
			}
			//交易时间
			if (pReqQueryAccount->TradeTime != nullptr)
			{
				field->TradeTime = gcnew String(pReqQueryAccount->TradeTime);
			}
			//银行流水号
			if (pReqQueryAccount->BankSerial != nullptr)
			{
				field->BankSerial = gcnew String(pReqQueryAccount->BankSerial);
			}
			//交易系统日期
			if (pReqQueryAccount->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pReqQueryAccount->TradingDay);
			}
			//银期平台消息流水号
			field->PlateSerial = pReqQueryAccount->PlateSerial;
			//最后分片标志
			field->LastFragment = (CtpNetLastFragmentType)pReqQueryAccount->LastFragment;
			//会话号
			field->SessionID = pReqQueryAccount->SessionID;
			//客户姓名
			if (pReqQueryAccount->CustomerName != nullptr)
			{
				field->CustomerName = gcnew String(pReqQueryAccount->CustomerName);
			}
			//证件类型
			field->IdCardType = (CtpNetIdCardTypeType)pReqQueryAccount->IdCardType;
			//证件号码
			if (pReqQueryAccount->IdentifiedCardNo != nullptr)
			{
				field->IdentifiedCardNo = gcnew String(pReqQueryAccount->IdentifiedCardNo);
			}
			//客户类型
			field->CustType = (CtpNetCustTypeType)pReqQueryAccount->CustType;
			//银行帐号
			if (pReqQueryAccount->BankAccount != nullptr)
			{
				field->BankAccount = gcnew String(pReqQueryAccount->BankAccount);
			}
			//银行密码
			if (pReqQueryAccount->BankPassWord != nullptr)
			{
				field->BankPassWord = gcnew String(pReqQueryAccount->BankPassWord);
			}
			//投资者帐号
			if (pReqQueryAccount->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pReqQueryAccount->AccountID);
			}
			//期货密码
			if (pReqQueryAccount->Password != nullptr)
			{
				field->Password = gcnew String(pReqQueryAccount->Password);
			}
			//期货公司流水号
			field->FutureSerial = pReqQueryAccount->FutureSerial;
			//安装编号
			field->InstallID = pReqQueryAccount->InstallID;
			//用户标识
			if (pReqQueryAccount->UserID != nullptr)
			{
				field->UserID = gcnew String(pReqQueryAccount->UserID);
			}
			//验证客户证件号码标志
			field->VerifyCertNoFlag = (CtpNetYesNoIndicatorType)pReqQueryAccount->VerifyCertNoFlag;
			//币种代码
			if (pReqQueryAccount->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pReqQueryAccount->CurrencyID);
			}
			//摘要
			if (pReqQueryAccount->Digest != nullptr)
			{
				field->Digest = gcnew String(pReqQueryAccount->Digest);
			}
			//银行帐号类型
			field->BankAccType = (CtpNetBankAccTypeType)pReqQueryAccount->BankAccType;
			//渠道标志
			if (pReqQueryAccount->DeviceID != nullptr)
			{
				field->DeviceID = gcnew String(pReqQueryAccount->DeviceID);
			}
			//期货单位帐号类型
			field->BankSecuAccType = (CtpNetBankAccTypeType)pReqQueryAccount->BankSecuAccType;
			//期货公司银行编码
			if (pReqQueryAccount->BrokerIDByBank != nullptr)
			{
				field->BrokerIDByBank = gcnew String(pReqQueryAccount->BrokerIDByBank);
			}
			//期货单位帐号
			if (pReqQueryAccount->BankSecuAcc != nullptr)
			{
				field->BankSecuAcc = gcnew String(pReqQueryAccount->BankSecuAcc);
			}
			//银行密码标志
			field->BankPwdFlag = (CtpNetPwdFlagType)pReqQueryAccount->BankPwdFlag;
			//期货资金密码核对标志
			field->SecuPwdFlag = (CtpNetPwdFlagType)pReqQueryAccount->SecuPwdFlag;
			//交易柜员
			if (pReqQueryAccount->OperNo != nullptr)
			{
				field->OperNo = gcnew String(pReqQueryAccount->OperNo);
			}
			//请求编号
			field->RequestID = pReqQueryAccount->RequestID;
			//交易ID
			field->TID = pReqQueryAccount->TID;
			//长客户姓名
			if (pReqQueryAccount->LongCustomerName != nullptr)
			{
				field->LongCustomerName = gcnew String(pReqQueryAccount->LongCustomerName);
			}
		}
		
		m_pAdapter->OnRspQueryBankAccountMoneyByFuture(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 银行发起银期开户通知
	void CTraderSpi::OnRtnOpenAccountByBank(CThostFtdcOpenAccountField *pOpenAccount)
	{
		if (m_pAdapter->OnRtnOpenAccountByBank_delegate == nullptr) return;
		
		CtpNetOpenAccountField^ field = nullptr;
		if (pOpenAccount != nullptr)
		{
			field = gcnew CtpNetOpenAccountField;
			
			//业务功能码
			if (pOpenAccount->TradeCode != nullptr)
			{
				field->TradeCode = gcnew String(pOpenAccount->TradeCode);
			}
			//银行代码
			if (pOpenAccount->BankID != nullptr)
			{
				field->BankID = gcnew String(pOpenAccount->BankID);
			}
			//银行分支机构代码
			if (pOpenAccount->BankBranchID != nullptr)
			{
				field->BankBranchID = gcnew String(pOpenAccount->BankBranchID);
			}
			//期商代码
			if (pOpenAccount->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pOpenAccount->BrokerID);
			}
			//期商分支机构代码
			if (pOpenAccount->BrokerBranchID != nullptr)
			{
				field->BrokerBranchID = gcnew String(pOpenAccount->BrokerBranchID);
			}
			//交易日期
			if (pOpenAccount->TradeDate != nullptr)
			{
				field->TradeDate = gcnew String(pOpenAccount->TradeDate);
			}
			//交易时间
			if (pOpenAccount->TradeTime != nullptr)
			{
				field->TradeTime = gcnew String(pOpenAccount->TradeTime);
			}
			//银行流水号
			if (pOpenAccount->BankSerial != nullptr)
			{
				field->BankSerial = gcnew String(pOpenAccount->BankSerial);
			}
			//交易系统日期
			if (pOpenAccount->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pOpenAccount->TradingDay);
			}
			//银期平台消息流水号
			field->PlateSerial = pOpenAccount->PlateSerial;
			//最后分片标志
			field->LastFragment = (CtpNetLastFragmentType)pOpenAccount->LastFragment;
			//会话号
			field->SessionID = pOpenAccount->SessionID;
			//客户姓名
			if (pOpenAccount->CustomerName != nullptr)
			{
				field->CustomerName = gcnew String(pOpenAccount->CustomerName);
			}
			//证件类型
			field->IdCardType = (CtpNetIdCardTypeType)pOpenAccount->IdCardType;
			//证件号码
			if (pOpenAccount->IdentifiedCardNo != nullptr)
			{
				field->IdentifiedCardNo = gcnew String(pOpenAccount->IdentifiedCardNo);
			}
			//性别
			field->Gender = (CtpNetGenderType)pOpenAccount->Gender;
			//国家代码
			if (pOpenAccount->CountryCode != nullptr)
			{
				field->CountryCode = gcnew String(pOpenAccount->CountryCode);
			}
			//客户类型
			field->CustType = (CtpNetCustTypeType)pOpenAccount->CustType;
			//地址
			if (pOpenAccount->Address != nullptr)
			{
				field->Address = gcnew String(pOpenAccount->Address);
			}
			//邮编
			if (pOpenAccount->ZipCode != nullptr)
			{
				field->ZipCode = gcnew String(pOpenAccount->ZipCode);
			}
			//电话号码
			if (pOpenAccount->Telephone != nullptr)
			{
				field->Telephone = gcnew String(pOpenAccount->Telephone);
			}
			//手机
			if (pOpenAccount->MobilePhone != nullptr)
			{
				field->MobilePhone = gcnew String(pOpenAccount->MobilePhone);
			}
			//传真
			if (pOpenAccount->Fax != nullptr)
			{
				field->Fax = gcnew String(pOpenAccount->Fax);
			}
			//电子邮件
			if (pOpenAccount->EMail != nullptr)
			{
				field->EMail = gcnew String(pOpenAccount->EMail);
			}
			//资金账户状态
			field->MoneyAccountStatus = (CtpNetMoneyAccountStatusType)pOpenAccount->MoneyAccountStatus;
			//银行帐号
			if (pOpenAccount->BankAccount != nullptr)
			{
				field->BankAccount = gcnew String(pOpenAccount->BankAccount);
			}
			//银行密码
			if (pOpenAccount->BankPassWord != nullptr)
			{
				field->BankPassWord = gcnew String(pOpenAccount->BankPassWord);
			}
			//投资者帐号
			if (pOpenAccount->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pOpenAccount->AccountID);
			}
			//期货密码
			if (pOpenAccount->Password != nullptr)
			{
				field->Password = gcnew String(pOpenAccount->Password);
			}
			//安装编号
			field->InstallID = pOpenAccount->InstallID;
			//验证客户证件号码标志
			field->VerifyCertNoFlag = (CtpNetYesNoIndicatorType)pOpenAccount->VerifyCertNoFlag;
			//币种代码
			if (pOpenAccount->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pOpenAccount->CurrencyID);
			}
			//汇钞标志
			field->CashExchangeCode = (CtpNetCashExchangeCodeType)pOpenAccount->CashExchangeCode;
			//摘要
			if (pOpenAccount->Digest != nullptr)
			{
				field->Digest = gcnew String(pOpenAccount->Digest);
			}
			//银行帐号类型
			field->BankAccType = (CtpNetBankAccTypeType)pOpenAccount->BankAccType;
			//渠道标志
			if (pOpenAccount->DeviceID != nullptr)
			{
				field->DeviceID = gcnew String(pOpenAccount->DeviceID);
			}
			//期货单位帐号类型
			field->BankSecuAccType = (CtpNetBankAccTypeType)pOpenAccount->BankSecuAccType;
			//期货公司银行编码
			if (pOpenAccount->BrokerIDByBank != nullptr)
			{
				field->BrokerIDByBank = gcnew String(pOpenAccount->BrokerIDByBank);
			}
			//期货单位帐号
			if (pOpenAccount->BankSecuAcc != nullptr)
			{
				field->BankSecuAcc = gcnew String(pOpenAccount->BankSecuAcc);
			}
			//银行密码标志
			field->BankPwdFlag = (CtpNetPwdFlagType)pOpenAccount->BankPwdFlag;
			//期货资金密码核对标志
			field->SecuPwdFlag = (CtpNetPwdFlagType)pOpenAccount->SecuPwdFlag;
			//交易柜员
			if (pOpenAccount->OperNo != nullptr)
			{
				field->OperNo = gcnew String(pOpenAccount->OperNo);
			}
			//交易ID
			field->TID = pOpenAccount->TID;
			//用户标识
			if (pOpenAccount->UserID != nullptr)
			{
				field->UserID = gcnew String(pOpenAccount->UserID);
			}
			//错误代码
			field->ErrorID = pOpenAccount->ErrorID;
			//错误信息
			if (pOpenAccount->ErrorMsg != nullptr)
			{
				field->ErrorMsg = gcnew String(pOpenAccount->ErrorMsg);
			}
			//长客户姓名
			if (pOpenAccount->LongCustomerName != nullptr)
			{
				field->LongCustomerName = gcnew String(pOpenAccount->LongCustomerName);
			}
		}
		
		m_pAdapter->OnRtnOpenAccountByBank(field);
	};

	// 银行发起银期销户通知
	void CTraderSpi::OnRtnCancelAccountByBank(CThostFtdcCancelAccountField *pCancelAccount)
	{
		if (m_pAdapter->OnRtnCancelAccountByBank_delegate == nullptr) return;
		
		CtpNetCancelAccountField^ field = nullptr;
		if (pCancelAccount != nullptr)
		{
			field = gcnew CtpNetCancelAccountField;
			
			//业务功能码
			if (pCancelAccount->TradeCode != nullptr)
			{
				field->TradeCode = gcnew String(pCancelAccount->TradeCode);
			}
			//银行代码
			if (pCancelAccount->BankID != nullptr)
			{
				field->BankID = gcnew String(pCancelAccount->BankID);
			}
			//银行分支机构代码
			if (pCancelAccount->BankBranchID != nullptr)
			{
				field->BankBranchID = gcnew String(pCancelAccount->BankBranchID);
			}
			//期商代码
			if (pCancelAccount->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pCancelAccount->BrokerID);
			}
			//期商分支机构代码
			if (pCancelAccount->BrokerBranchID != nullptr)
			{
				field->BrokerBranchID = gcnew String(pCancelAccount->BrokerBranchID);
			}
			//交易日期
			if (pCancelAccount->TradeDate != nullptr)
			{
				field->TradeDate = gcnew String(pCancelAccount->TradeDate);
			}
			//交易时间
			if (pCancelAccount->TradeTime != nullptr)
			{
				field->TradeTime = gcnew String(pCancelAccount->TradeTime);
			}
			//银行流水号
			if (pCancelAccount->BankSerial != nullptr)
			{
				field->BankSerial = gcnew String(pCancelAccount->BankSerial);
			}
			//交易系统日期
			if (pCancelAccount->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pCancelAccount->TradingDay);
			}
			//银期平台消息流水号
			field->PlateSerial = pCancelAccount->PlateSerial;
			//最后分片标志
			field->LastFragment = (CtpNetLastFragmentType)pCancelAccount->LastFragment;
			//会话号
			field->SessionID = pCancelAccount->SessionID;
			//客户姓名
			if (pCancelAccount->CustomerName != nullptr)
			{
				field->CustomerName = gcnew String(pCancelAccount->CustomerName);
			}
			//证件类型
			field->IdCardType = (CtpNetIdCardTypeType)pCancelAccount->IdCardType;
			//证件号码
			if (pCancelAccount->IdentifiedCardNo != nullptr)
			{
				field->IdentifiedCardNo = gcnew String(pCancelAccount->IdentifiedCardNo);
			}
			//性别
			field->Gender = (CtpNetGenderType)pCancelAccount->Gender;
			//国家代码
			if (pCancelAccount->CountryCode != nullptr)
			{
				field->CountryCode = gcnew String(pCancelAccount->CountryCode);
			}
			//客户类型
			field->CustType = (CtpNetCustTypeType)pCancelAccount->CustType;
			//地址
			if (pCancelAccount->Address != nullptr)
			{
				field->Address = gcnew String(pCancelAccount->Address);
			}
			//邮编
			if (pCancelAccount->ZipCode != nullptr)
			{
				field->ZipCode = gcnew String(pCancelAccount->ZipCode);
			}
			//电话号码
			if (pCancelAccount->Telephone != nullptr)
			{
				field->Telephone = gcnew String(pCancelAccount->Telephone);
			}
			//手机
			if (pCancelAccount->MobilePhone != nullptr)
			{
				field->MobilePhone = gcnew String(pCancelAccount->MobilePhone);
			}
			//传真
			if (pCancelAccount->Fax != nullptr)
			{
				field->Fax = gcnew String(pCancelAccount->Fax);
			}
			//电子邮件
			if (pCancelAccount->EMail != nullptr)
			{
				field->EMail = gcnew String(pCancelAccount->EMail);
			}
			//资金账户状态
			field->MoneyAccountStatus = (CtpNetMoneyAccountStatusType)pCancelAccount->MoneyAccountStatus;
			//银行帐号
			if (pCancelAccount->BankAccount != nullptr)
			{
				field->BankAccount = gcnew String(pCancelAccount->BankAccount);
			}
			//银行密码
			if (pCancelAccount->BankPassWord != nullptr)
			{
				field->BankPassWord = gcnew String(pCancelAccount->BankPassWord);
			}
			//投资者帐号
			if (pCancelAccount->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pCancelAccount->AccountID);
			}
			//期货密码
			if (pCancelAccount->Password != nullptr)
			{
				field->Password = gcnew String(pCancelAccount->Password);
			}
			//安装编号
			field->InstallID = pCancelAccount->InstallID;
			//验证客户证件号码标志
			field->VerifyCertNoFlag = (CtpNetYesNoIndicatorType)pCancelAccount->VerifyCertNoFlag;
			//币种代码
			if (pCancelAccount->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pCancelAccount->CurrencyID);
			}
			//汇钞标志
			field->CashExchangeCode = (CtpNetCashExchangeCodeType)pCancelAccount->CashExchangeCode;
			//摘要
			if (pCancelAccount->Digest != nullptr)
			{
				field->Digest = gcnew String(pCancelAccount->Digest);
			}
			//银行帐号类型
			field->BankAccType = (CtpNetBankAccTypeType)pCancelAccount->BankAccType;
			//渠道标志
			if (pCancelAccount->DeviceID != nullptr)
			{
				field->DeviceID = gcnew String(pCancelAccount->DeviceID);
			}
			//期货单位帐号类型
			field->BankSecuAccType = (CtpNetBankAccTypeType)pCancelAccount->BankSecuAccType;
			//期货公司银行编码
			if (pCancelAccount->BrokerIDByBank != nullptr)
			{
				field->BrokerIDByBank = gcnew String(pCancelAccount->BrokerIDByBank);
			}
			//期货单位帐号
			if (pCancelAccount->BankSecuAcc != nullptr)
			{
				field->BankSecuAcc = gcnew String(pCancelAccount->BankSecuAcc);
			}
			//银行密码标志
			field->BankPwdFlag = (CtpNetPwdFlagType)pCancelAccount->BankPwdFlag;
			//期货资金密码核对标志
			field->SecuPwdFlag = (CtpNetPwdFlagType)pCancelAccount->SecuPwdFlag;
			//交易柜员
			if (pCancelAccount->OperNo != nullptr)
			{
				field->OperNo = gcnew String(pCancelAccount->OperNo);
			}
			//交易ID
			field->TID = pCancelAccount->TID;
			//用户标识
			if (pCancelAccount->UserID != nullptr)
			{
				field->UserID = gcnew String(pCancelAccount->UserID);
			}
			//错误代码
			field->ErrorID = pCancelAccount->ErrorID;
			//错误信息
			if (pCancelAccount->ErrorMsg != nullptr)
			{
				field->ErrorMsg = gcnew String(pCancelAccount->ErrorMsg);
			}
			//长客户姓名
			if (pCancelAccount->LongCustomerName != nullptr)
			{
				field->LongCustomerName = gcnew String(pCancelAccount->LongCustomerName);
			}
		}
		
		m_pAdapter->OnRtnCancelAccountByBank(field);
	};

	// 银行发起变更银行账号通知
	void CTraderSpi::OnRtnChangeAccountByBank(CThostFtdcChangeAccountField *pChangeAccount)
	{
		if (m_pAdapter->OnRtnChangeAccountByBank_delegate == nullptr) return;
		
		CtpNetChangeAccountField^ field = nullptr;
		if (pChangeAccount != nullptr)
		{
			field = gcnew CtpNetChangeAccountField;
			
			//业务功能码
			if (pChangeAccount->TradeCode != nullptr)
			{
				field->TradeCode = gcnew String(pChangeAccount->TradeCode);
			}
			//银行代码
			if (pChangeAccount->BankID != nullptr)
			{
				field->BankID = gcnew String(pChangeAccount->BankID);
			}
			//银行分支机构代码
			if (pChangeAccount->BankBranchID != nullptr)
			{
				field->BankBranchID = gcnew String(pChangeAccount->BankBranchID);
			}
			//期商代码
			if (pChangeAccount->BrokerID != nullptr)
			{
				field->BrokerID = gcnew String(pChangeAccount->BrokerID);
			}
			//期商分支机构代码
			if (pChangeAccount->BrokerBranchID != nullptr)
			{
				field->BrokerBranchID = gcnew String(pChangeAccount->BrokerBranchID);
			}
			//交易日期
			if (pChangeAccount->TradeDate != nullptr)
			{
				field->TradeDate = gcnew String(pChangeAccount->TradeDate);
			}
			//交易时间
			if (pChangeAccount->TradeTime != nullptr)
			{
				field->TradeTime = gcnew String(pChangeAccount->TradeTime);
			}
			//银行流水号
			if (pChangeAccount->BankSerial != nullptr)
			{
				field->BankSerial = gcnew String(pChangeAccount->BankSerial);
			}
			//交易系统日期
			if (pChangeAccount->TradingDay != nullptr)
			{
				field->TradingDay = gcnew String(pChangeAccount->TradingDay);
			}
			//银期平台消息流水号
			field->PlateSerial = pChangeAccount->PlateSerial;
			//最后分片标志
			field->LastFragment = (CtpNetLastFragmentType)pChangeAccount->LastFragment;
			//会话号
			field->SessionID = pChangeAccount->SessionID;
			//客户姓名
			if (pChangeAccount->CustomerName != nullptr)
			{
				field->CustomerName = gcnew String(pChangeAccount->CustomerName);
			}
			//证件类型
			field->IdCardType = (CtpNetIdCardTypeType)pChangeAccount->IdCardType;
			//证件号码
			if (pChangeAccount->IdentifiedCardNo != nullptr)
			{
				field->IdentifiedCardNo = gcnew String(pChangeAccount->IdentifiedCardNo);
			}
			//性别
			field->Gender = (CtpNetGenderType)pChangeAccount->Gender;
			//国家代码
			if (pChangeAccount->CountryCode != nullptr)
			{
				field->CountryCode = gcnew String(pChangeAccount->CountryCode);
			}
			//客户类型
			field->CustType = (CtpNetCustTypeType)pChangeAccount->CustType;
			//地址
			if (pChangeAccount->Address != nullptr)
			{
				field->Address = gcnew String(pChangeAccount->Address);
			}
			//邮编
			if (pChangeAccount->ZipCode != nullptr)
			{
				field->ZipCode = gcnew String(pChangeAccount->ZipCode);
			}
			//电话号码
			if (pChangeAccount->Telephone != nullptr)
			{
				field->Telephone = gcnew String(pChangeAccount->Telephone);
			}
			//手机
			if (pChangeAccount->MobilePhone != nullptr)
			{
				field->MobilePhone = gcnew String(pChangeAccount->MobilePhone);
			}
			//传真
			if (pChangeAccount->Fax != nullptr)
			{
				field->Fax = gcnew String(pChangeAccount->Fax);
			}
			//电子邮件
			if (pChangeAccount->EMail != nullptr)
			{
				field->EMail = gcnew String(pChangeAccount->EMail);
			}
			//资金账户状态
			field->MoneyAccountStatus = (CtpNetMoneyAccountStatusType)pChangeAccount->MoneyAccountStatus;
			//银行帐号
			if (pChangeAccount->BankAccount != nullptr)
			{
				field->BankAccount = gcnew String(pChangeAccount->BankAccount);
			}
			//银行密码
			if (pChangeAccount->BankPassWord != nullptr)
			{
				field->BankPassWord = gcnew String(pChangeAccount->BankPassWord);
			}
			//新银行帐号
			if (pChangeAccount->NewBankAccount != nullptr)
			{
				field->NewBankAccount = gcnew String(pChangeAccount->NewBankAccount);
			}
			//新银行密码
			if (pChangeAccount->NewBankPassWord != nullptr)
			{
				field->NewBankPassWord = gcnew String(pChangeAccount->NewBankPassWord);
			}
			//投资者帐号
			if (pChangeAccount->AccountID != nullptr)
			{
				field->AccountID = gcnew String(pChangeAccount->AccountID);
			}
			//期货密码
			if (pChangeAccount->Password != nullptr)
			{
				field->Password = gcnew String(pChangeAccount->Password);
			}
			//银行帐号类型
			field->BankAccType = (CtpNetBankAccTypeType)pChangeAccount->BankAccType;
			//安装编号
			field->InstallID = pChangeAccount->InstallID;
			//验证客户证件号码标志
			field->VerifyCertNoFlag = (CtpNetYesNoIndicatorType)pChangeAccount->VerifyCertNoFlag;
			//币种代码
			if (pChangeAccount->CurrencyID != nullptr)
			{
				field->CurrencyID = gcnew String(pChangeAccount->CurrencyID);
			}
			//期货公司银行编码
			if (pChangeAccount->BrokerIDByBank != nullptr)
			{
				field->BrokerIDByBank = gcnew String(pChangeAccount->BrokerIDByBank);
			}
			//银行密码标志
			field->BankPwdFlag = (CtpNetPwdFlagType)pChangeAccount->BankPwdFlag;
			//期货资金密码核对标志
			field->SecuPwdFlag = (CtpNetPwdFlagType)pChangeAccount->SecuPwdFlag;
			//交易ID
			field->TID = pChangeAccount->TID;
			//摘要
			if (pChangeAccount->Digest != nullptr)
			{
				field->Digest = gcnew String(pChangeAccount->Digest);
			}
			//错误代码
			field->ErrorID = pChangeAccount->ErrorID;
			//错误信息
			if (pChangeAccount->ErrorMsg != nullptr)
			{
				field->ErrorMsg = gcnew String(pChangeAccount->ErrorMsg);
			}
			//长客户姓名
			if (pChangeAccount->LongCustomerName != nullptr)
			{
				field->LongCustomerName = gcnew String(pChangeAccount->LongCustomerName);
			}
		}
		
		m_pAdapter->OnRtnChangeAccountByBank(field);
	};
};
