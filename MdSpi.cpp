#include "MdSpi.h"

namespace Native
{
	// 行情命令响应
	CMdSpi::CMdSpi(MdAdapter^ pAdapter)
	{
		m_pAdapter = pAdapter;
	};

	// 当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
	void CMdSpi::OnFrontConnected()
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
	void CMdSpi::OnFrontDisconnected(int nReason)
	{
		if (m_pAdapter->OnFrontDisconnected_delegate == nullptr) return;
		
		m_pAdapter->OnFrontDisconnected(nReason);
	};

	// 心跳超时警告。当长时间未收到报文时，该方法被调用。
	// nTimeLapse 距离上次接收报文的时间
	void CMdSpi::OnHeartBeatWarning(int nTimeLapse)
	{
		if (m_pAdapter->OnHeartBeatWarning_delegate == nullptr) return;
		
		m_pAdapter->OnHeartBeatWarning(nTimeLapse);
	};

	// 登录请求响应
	void CMdSpi::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
	void CMdSpi::OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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

	// 错误应答
	void CMdSpi::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspError_delegate == nullptr) return;
		
		m_pAdapter->OnRspError(RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 订阅行情应答
	void CMdSpi::OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspSubMarketData_delegate == nullptr) return;
		
		CtpNetSpecificInstrumentField^ field = nullptr;
		if (pSpecificInstrument != nullptr)
		{
			field = gcnew CtpNetSpecificInstrumentField;
			
			//合约代码
			if (pSpecificInstrument->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pSpecificInstrument->InstrumentID);
			}
		}
		
		m_pAdapter->OnRspSubMarketData(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 取消订阅行情应答
	void CMdSpi::OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspUnSubMarketData_delegate == nullptr) return;
		
		CtpNetSpecificInstrumentField^ field = nullptr;
		if (pSpecificInstrument != nullptr)
		{
			field = gcnew CtpNetSpecificInstrumentField;
			
			//合约代码
			if (pSpecificInstrument->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pSpecificInstrument->InstrumentID);
			}
		}
		
		m_pAdapter->OnRspUnSubMarketData(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 订阅询价应答
	void CMdSpi::OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspSubForQuoteRsp_delegate == nullptr) return;
		
		CtpNetSpecificInstrumentField^ field = nullptr;
		if (pSpecificInstrument != nullptr)
		{
			field = gcnew CtpNetSpecificInstrumentField;
			
			//合约代码
			if (pSpecificInstrument->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pSpecificInstrument->InstrumentID);
			}
		}
		
		m_pAdapter->OnRspSubForQuoteRsp(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 取消订阅询价应答
	void CMdSpi::OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		if (m_pAdapter->OnRspUnSubForQuoteRsp_delegate == nullptr) return;
		
		CtpNetSpecificInstrumentField^ field = nullptr;
		if (pSpecificInstrument != nullptr)
		{
			field = gcnew CtpNetSpecificInstrumentField;
			
			//合约代码
			if (pSpecificInstrument->InstrumentID != nullptr)
			{
				field->InstrumentID = gcnew String(pSpecificInstrument->InstrumentID);
			}
		}
		
		m_pAdapter->OnRspUnSubForQuoteRsp(field, RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	// 深度行情通知
	void CMdSpi::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData)
	{
		if (m_pAdapter->OnRtnDepthMarketData_delegate == nullptr) return;
		
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
		
		m_pAdapter->OnRtnDepthMarketData(field);
	};

	// 询价通知
	void CMdSpi::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp)
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
};
