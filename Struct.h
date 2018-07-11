#pragma once

#include "DataType.h"

using namespace System;
using namespace System::Runtime::InteropServices;

namespace TaiTanXing
{
	namespace Ctp
	{
		namespace CtpProxy
		{
			/// <summary>
			/// 信息分发
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetDisseminationField
			{
				/// <summary>
				/// 序列系列号
				/// </summary>
				short SequenceSeries;

				/// <summary>
				/// 序列号
				/// </summary>
				int SequenceNo;
			};

			/// <summary>
			/// 用户登录请求
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetReqUserLoginField
			{
				/// <summary>
				/// 交易日
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Password;

				/// <summary>
				/// 用户端产品信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ UserProductInfo;

				/// <summary>
				/// 接口端产品信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ InterfaceProductInfo;

				/// <summary>
				/// 协议信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ProtocolInfo;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;

				/// <summary>
				/// 动态密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ OneTimePassword;

				/// <summary>
				/// 终端IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ ClientIPAddress;

				/// <summary>
				/// 登录备注
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
				String^ LoginRemark;
			};

			/// <summary>
			/// 用户登录应答
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetRspUserLoginField
			{
				/// <summary>
				/// 交易日
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 登录成功时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ LoginTime;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 交易系统名称
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ SystemName;

				/// <summary>
				/// 前置编号
				/// </summary>
				int FrontID;

				/// <summary>
				/// 会话编号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 最大报单引用
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ MaxOrderRef;

				/// <summary>
				/// 上期所时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ SHFETime;

				/// <summary>
				/// 大商所时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ DCETime;

				/// <summary>
				/// 郑商所时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ CZCETime;

				/// <summary>
				/// 中金所时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ FFEXTime;

				/// <summary>
				/// 能源中心时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ INETime;
			};

			/// <summary>
			/// 用户登出请求
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetUserLogoutField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;
			};

			/// <summary>
			/// 强制交易员退出
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetForceUserLogoutField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;
			};

			/// <summary>
			/// 客户端认证请求
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetReqAuthenticateField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 用户端产品信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ UserProductInfo;

				/// <summary>
				/// 认证码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ AuthCode;
			};

			/// <summary>
			/// 客户端认证响应
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetRspAuthenticateField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 用户端产品信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ UserProductInfo;
			};

			/// <summary>
			/// 客户端认证信息
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetAuthenticationInfoField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 用户端产品信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ UserProductInfo;

				/// <summary>
				/// 认证信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
				String^ AuthInfo;

				/// <summary>
				/// 是否为认证结果
				/// </summary>
				int IsResult;
			};

			/// <summary>
			/// 用户登录应答2
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetRspUserLogin2Field
			{
				/// <summary>
				/// 交易日
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 登录成功时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ LoginTime;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 交易系统名称
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ SystemName;

				/// <summary>
				/// 前置编号
				/// </summary>
				int FrontID;

				/// <summary>
				/// 会话编号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 最大报单引用
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ MaxOrderRef;

				/// <summary>
				/// 上期所时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ SHFETime;

				/// <summary>
				/// 大商所时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ DCETime;

				/// <summary>
				/// 郑商所时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ CZCETime;

				/// <summary>
				/// 中金所时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ FFEXTime;

				/// <summary>
				/// 能源中心时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ INETime;

				/// <summary>
				/// 随机串
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ RandomString;
			};

			/// <summary>
			/// 银期转帐报文头
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetTransferHeaderField
			{
				/// <summary>
				/// 版本号，常量，1.0
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ Version;

				/// <summary>
				/// 交易代码，必填
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ TradeCode;

				/// <summary>
				/// 交易日期，必填，格式：yyyymmdd
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeDate;

				/// <summary>
				/// 交易时间，必填，格式：hhmmss
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeTime;

				/// <summary>
				/// 发起方流水号，N/A
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeSerial;

				/// <summary>
				/// 期货公司代码，必填
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ FutureID;

				/// <summary>
				/// 银行代码，根据查询银行得到，必填
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ BankID;

				/// <summary>
				/// 银行分中心代码，根据查询银行得到，必填
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
				String^ BankBrchID;

				/// <summary>
				/// 操作员，N/A
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ OperNo;

				/// <summary>
				/// 交易设备类型，N/A
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
				String^ DeviceID;

				/// <summary>
				/// 记录数，N/A
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ RecordNum;

				/// <summary>
				/// 会话编号，N/A
				/// </summary>
				int SessionID;

				/// <summary>
				/// 请求编号，N/A
				/// </summary>
				int RequestID;
			};

			/// <summary>
			/// 银行资金转期货请求，TradeCode=202001
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetTransferBankToFutureReqField
			{
				/// <summary>
				/// 期货资金账户
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ FutureAccount;

				/// <summary>
				/// 密码标志
				/// </summary>
				CtpNetFuturePwdFlagType FuturePwdFlag;

				/// <summary>
				/// 密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ FutureAccPwd;

				/// <summary>
				/// 转账金额
				/// </summary>
				double TradeAmt;

				/// <summary>
				/// 客户手续费
				/// </summary>
				double CustFee;

				/// <summary>
				/// 币种：RMB-人民币 USD-美圆 HKD-港元
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyCode;
			};

			/// <summary>
			/// 银行资金转期货请求响应
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetTransferBankToFutureRspField
			{
				/// <summary>
				/// 响应代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
				String^ RetCode;

				/// <summary>
				/// 响应信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
				String^ RetInfo;

				/// <summary>
				/// 资金账户
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ FutureAccount;

				/// <summary>
				/// 转帐金额
				/// </summary>
				double TradeAmt;

				/// <summary>
				/// 应收客户手续费
				/// </summary>
				double CustFee;

				/// <summary>
				/// 币种
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyCode;
			};

			/// <summary>
			/// 期货资金转银行请求，TradeCode=202002
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetTransferFutureToBankReqField
			{
				/// <summary>
				/// 期货资金账户
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ FutureAccount;

				/// <summary>
				/// 密码标志
				/// </summary>
				CtpNetFuturePwdFlagType FuturePwdFlag;

				/// <summary>
				/// 密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ FutureAccPwd;

				/// <summary>
				/// 转账金额
				/// </summary>
				double TradeAmt;

				/// <summary>
				/// 客户手续费
				/// </summary>
				double CustFee;

				/// <summary>
				/// 币种：RMB-人民币 USD-美圆 HKD-港元
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyCode;
			};

			/// <summary>
			/// 期货资金转银行请求响应
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetTransferFutureToBankRspField
			{
				/// <summary>
				/// 响应代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
				String^ RetCode;

				/// <summary>
				/// 响应信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
				String^ RetInfo;

				/// <summary>
				/// 资金账户
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ FutureAccount;

				/// <summary>
				/// 转帐金额
				/// </summary>
				double TradeAmt;

				/// <summary>
				/// 应收客户手续费
				/// </summary>
				double CustFee;

				/// <summary>
				/// 币种
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyCode;
			};

			/// <summary>
			/// 查询银行资金请求，TradeCode=204002
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetTransferQryBankReqField
			{
				/// <summary>
				/// 期货资金账户
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ FutureAccount;

				/// <summary>
				/// 密码标志
				/// </summary>
				CtpNetFuturePwdFlagType FuturePwdFlag;

				/// <summary>
				/// 密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ FutureAccPwd;

				/// <summary>
				/// 币种：RMB-人民币 USD-美圆 HKD-港元
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyCode;
			};

			/// <summary>
			/// 查询银行资金请求响应
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetTransferQryBankRspField
			{
				/// <summary>
				/// 响应代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
				String^ RetCode;

				/// <summary>
				/// 响应信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
				String^ RetInfo;

				/// <summary>
				/// 资金账户
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ FutureAccount;

				/// <summary>
				/// 银行余额
				/// </summary>
				double TradeAmt;

				/// <summary>
				/// 银行可用余额
				/// </summary>
				double UseAmt;

				/// <summary>
				/// 银行可取余额
				/// </summary>
				double FetchAmt;

				/// <summary>
				/// 币种
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyCode;
			};

			/// <summary>
			/// 查询银行交易明细请求，TradeCode=204999
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetTransferQryDetailReqField
			{
				/// <summary>
				/// 期货资金账户
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ FutureAccount;
			};

			/// <summary>
			/// 查询银行交易明细请求响应
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetTransferQryDetailRspField
			{
				/// <summary>
				/// 交易日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeDate;

				/// <summary>
				/// 交易时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeTime;

				/// <summary>
				/// 交易代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ TradeCode;

				/// <summary>
				/// 期货流水号
				/// </summary>
				int FutureSerial;

				/// <summary>
				/// 期货公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ FutureID;

				/// <summary>
				/// 资金帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 22)]
				String^ FutureAccount;

				/// <summary>
				/// 银行流水号
				/// </summary>
				int BankSerial;

				/// <summary>
				/// 银行代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ BankID;

				/// <summary>
				/// 银行分中心代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
				String^ BankBrchID;

				/// <summary>
				/// 银行账号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankAccount;

				/// <summary>
				/// 证件号码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ CertCode;

				/// <summary>
				/// 货币代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyCode;

				/// <summary>
				/// 发生金额
				/// </summary>
				double TxAmount;

				/// <summary>
				/// 有效标志
				/// </summary>
				CtpNetTransferValidFlagType Flag;
			};

			/// <summary>
			/// 响应信息
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetRspInfoField
			{
				/// <summary>
				/// 错误代码
				/// </summary>
				int ErrorID;

				/// <summary>
				/// 错误信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ ErrorMsg;
			};

			/// <summary>
			/// 交易所
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetExchangeField
			{
				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 交易所名称
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 61)]
				String^ ExchangeName;

				/// <summary>
				/// 交易所属性
				/// </summary>
				CtpNetExchangePropertyType ExchangeProperty;
			};

			/// <summary>
			/// 产品
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetProductField
			{
				/// <summary>
				/// 产品代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ ProductID;

				/// <summary>
				/// 产品名称
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ ProductName;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 产品类型
				/// </summary>
				CtpNetProductClassType ProductClass;

				/// <summary>
				/// 合约数量乘数
				/// </summary>
				int VolumeMultiple;

				/// <summary>
				/// 最小变动价位
				/// </summary>
				double PriceTick;

				/// <summary>
				/// 市价单最大下单量
				/// </summary>
				int MaxMarketOrderVolume;

				/// <summary>
				/// 市价单最小下单量
				/// </summary>
				int MinMarketOrderVolume;

				/// <summary>
				/// 限价单最大下单量
				/// </summary>
				int MaxLimitOrderVolume;

				/// <summary>
				/// 限价单最小下单量
				/// </summary>
				int MinLimitOrderVolume;

				/// <summary>
				/// 持仓类型
				/// </summary>
				CtpNetPositionTypeType PositionType;

				/// <summary>
				/// 持仓日期类型
				/// </summary>
				CtpNetPositionDateTypeType PositionDateType;

				/// <summary>
				/// 平仓处理类型
				/// </summary>
				CtpNetCloseDealTypeType CloseDealType;

				/// <summary>
				/// 交易币种类型
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ TradeCurrencyID;

				/// <summary>
				/// 质押资金可用范围
				/// </summary>
				CtpNetMortgageFundUseRangeType MortgageFundUseRange;

				/// <summary>
				/// 交易所产品代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ ExchangeProductID;

				/// <summary>
				/// 合约基础商品乘数
				/// </summary>
				double UnderlyingMultiple;
			};

			/// <summary>
			/// 合约
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetInstrumentField
			{
				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 合约名称
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ InstrumentName;

				/// <summary>
				/// 合约在交易所的代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ ExchangeInstID;

				/// <summary>
				/// 产品代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ ProductID;

				/// <summary>
				/// 产品类型
				/// </summary>
				CtpNetProductClassType ProductClass;

				/// <summary>
				/// 交割年份
				/// </summary>
				int DeliveryYear;

				/// <summary>
				/// 交割月
				/// </summary>
				int DeliveryMonth;

				/// <summary>
				/// 市价单最大下单量
				/// </summary>
				int MaxMarketOrderVolume;

				/// <summary>
				/// 市价单最小下单量
				/// </summary>
				int MinMarketOrderVolume;

				/// <summary>
				/// 限价单最大下单量
				/// </summary>
				int MaxLimitOrderVolume;

				/// <summary>
				/// 限价单最小下单量
				/// </summary>
				int MinLimitOrderVolume;

				/// <summary>
				/// 合约数量乘数
				/// </summary>
				int VolumeMultiple;

				/// <summary>
				/// 最小变动价位
				/// </summary>
				double PriceTick;

				/// <summary>
				/// 创建日
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ CreateDate;

				/// <summary>
				/// 上市日
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ OpenDate;

				/// <summary>
				/// 到期日
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExpireDate;

				/// <summary>
				/// 开始交割日
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ StartDelivDate;

				/// <summary>
				/// 结束交割日
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ EndDelivDate;

				/// <summary>
				/// 合约生命周期状态
				/// </summary>
				CtpNetInstLifePhaseType InstLifePhase;

				/// <summary>
				/// 当前是否交易
				/// </summary>
				int IsTrading;

				/// <summary>
				/// 持仓类型
				/// </summary>
				CtpNetPositionTypeType PositionType;

				/// <summary>
				/// 持仓日期类型
				/// </summary>
				CtpNetPositionDateTypeType PositionDateType;

				/// <summary>
				/// 多头保证金率
				/// </summary>
				double LongMarginRatio;

				/// <summary>
				/// 空头保证金率
				/// </summary>
				double ShortMarginRatio;

				/// <summary>
				/// 是否使用大额单边保证金算法
				/// </summary>
				CtpNetMaxMarginSideAlgorithmType MaxMarginSideAlgorithm;

				/// <summary>
				/// 基础商品代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ UnderlyingInstrID;

				/// <summary>
				/// 执行价
				/// </summary>
				double StrikePrice;

				/// <summary>
				/// 期权类型
				/// </summary>
				CtpNetOptionsTypeType OptionsType;

				/// <summary>
				/// 合约基础商品乘数
				/// </summary>
				double UnderlyingMultiple;

				/// <summary>
				/// 组合类型
				/// </summary>
				CtpNetCombinationTypeType CombinationType;
			};

			/// <summary>
			/// 经纪公司
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetBrokerField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 经纪公司简称
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ BrokerAbbr;

				/// <summary>
				/// 经纪公司名称
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ BrokerName;

				/// <summary>
				/// 是否活跃
				/// </summary>
				int IsActive;
			};

			/// <summary>
			/// 交易所交易员
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetTraderField
			{
				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;

				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Password;

				/// <summary>
				/// 安装数量
				/// </summary>
				int InstallCount;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;
			};

			/// <summary>
			/// 投资者
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetInvestorField
			{
				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者分组代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorGroupID;

				/// <summary>
				/// 投资者名称
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ InvestorName;

				/// <summary>
				/// 证件类型
				/// </summary>
				CtpNetIdCardTypeType IdentifiedCardType;

				/// <summary>
				/// 证件号码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
				String^ IdentifiedCardNo;

				/// <summary>
				/// 是否活跃
				/// </summary>
				int IsActive;

				/// <summary>
				/// 联系电话
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Telephone;

				/// <summary>
				/// 通讯地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 101)]
				String^ Address;

				/// <summary>
				/// 开户日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ OpenDate;

				/// <summary>
				/// 手机
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Mobile;

				/// <summary>
				/// 手续费率模板代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ CommModelID;

				/// <summary>
				/// 保证金率模板代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ MarginModelID;
			};

			/// <summary>
			/// 交易编码
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetTradingCodeField
			{
				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 客户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// 是否活跃
				/// </summary>
				int IsActive;

				/// <summary>
				/// 交易编码类型
				/// </summary>
				CtpNetClientIDTypeType ClientIDType;

				/// <summary>
				/// 营业部编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ BranchID;

				/// <summary>
				/// 业务类型
				/// </summary>
				CtpNetBizTypeType BizType;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;
			};

			/// <summary>
			/// 会员编码和经纪公司编码对照表
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetPartBrokerField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 是否活跃
				/// </summary>
				int IsActive;
			};

			/// <summary>
			/// 管理用户
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetSuperUserField
			{
				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 用户名称
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ UserName;

				/// <summary>
				/// 密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Password;

				/// <summary>
				/// 是否活跃
				/// </summary>
				int IsActive;
			};

			/// <summary>
			/// 管理用户功能权限
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetSuperUserFunctionField
			{
				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 功能代码
				/// </summary>
				CtpNetFunctionCodeType FunctionCode;
			};

			/// <summary>
			/// 投资者组
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetInvestorGroupField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者分组代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorGroupID;

				/// <summary>
				/// 投资者分组名称
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ InvestorGroupName;
			};

			/// <summary>
			/// 资金账户
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetTradingAccountField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 上次质押金额
				/// </summary>
				double PreMortgage;

				/// <summary>
				/// 上次信用额度
				/// </summary>
				double PreCredit;

				/// <summary>
				/// 上次存款额
				/// </summary>
				double PreDeposit;

				/// <summary>
				/// 上次结算准备金
				/// </summary>
				double PreBalance;

				/// <summary>
				/// 上次占用的保证金
				/// </summary>
				double PreMargin;

				/// <summary>
				/// 利息基数
				/// </summary>
				double InterestBase;

				/// <summary>
				/// 利息收入
				/// </summary>
				double Interest;

				/// <summary>
				/// 入金金额
				/// </summary>
				double Deposit;

				/// <summary>
				/// 出金金额
				/// </summary>
				double Withdraw;

				/// <summary>
				/// 冻结的保证金
				/// </summary>
				double FrozenMargin;

				/// <summary>
				/// 冻结的资金
				/// </summary>
				double FrozenCash;

				/// <summary>
				/// 冻结的手续费
				/// </summary>
				double FrozenCommission;

				/// <summary>
				/// 当前保证金总额
				/// </summary>
				double CurrMargin;

				/// <summary>
				/// 资金差额
				/// </summary>
				double CashIn;

				/// <summary>
				/// 手续费
				/// </summary>
				double Commission;

				/// <summary>
				/// 平仓盈亏
				/// </summary>
				double CloseProfit;

				/// <summary>
				/// 持仓盈亏
				/// </summary>
				double PositionProfit;

				/// <summary>
				/// 期货结算准备金
				/// </summary>
				double Balance;

				/// <summary>
				/// 可用资金
				/// </summary>
				double Available;

				/// <summary>
				/// 可取资金
				/// </summary>
				double WithdrawQuota;

				/// <summary>
				/// 基本准备金
				/// </summary>
				double Reserve;

				/// <summary>
				/// 交易日
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 结算编号
				/// </summary>
				int SettlementID;

				/// <summary>
				/// 信用额度
				/// </summary>
				double Credit;

				/// <summary>
				/// 质押金额
				/// </summary>
				double Mortgage;

				/// <summary>
				/// 交易所保证金
				/// </summary>
				double ExchangeMargin;

				/// <summary>
				/// 投资者交割保证金
				/// </summary>
				double DeliveryMargin;

				/// <summary>
				/// 交易所交割保证金
				/// </summary>
				double ExchangeDeliveryMargin;

				/// <summary>
				/// 保底期货结算准备金
				/// </summary>
				double ReserveBalance;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// 上次货币质入金额
				/// </summary>
				double PreFundMortgageIn;

				/// <summary>
				/// 上次货币质出金额
				/// </summary>
				double PreFundMortgageOut;

				/// <summary>
				/// 货币质入金额
				/// </summary>
				double FundMortgageIn;

				/// <summary>
				/// 货币质出金额
				/// </summary>
				double FundMortgageOut;

				/// <summary>
				/// 货币质押余额
				/// </summary>
				double FundMortgageAvailable;

				/// <summary>
				/// 可质押货币金额
				/// </summary>
				double MortgageableFund;

				/// <summary>
				/// 特殊产品占用保证金
				/// </summary>
				double SpecProductMargin;

				/// <summary>
				/// 特殊产品冻结保证金
				/// </summary>
				double SpecProductFrozenMargin;

				/// <summary>
				/// 特殊产品手续费
				/// </summary>
				double SpecProductCommission;

				/// <summary>
				/// 特殊产品冻结手续费
				/// </summary>
				double SpecProductFrozenCommission;

				/// <summary>
				/// 特殊产品持仓盈亏
				/// </summary>
				double SpecProductPositionProfit;

				/// <summary>
				/// 特殊产品平仓盈亏
				/// </summary>
				double SpecProductCloseProfit;

				/// <summary>
				/// 根据持仓盈亏算法计算的特殊产品持仓盈亏
				/// </summary>
				double SpecProductPositionProfitByAlg;

				/// <summary>
				/// 特殊产品交易所保证金
				/// </summary>
				double SpecProductExchangeMargin;

				/// <summary>
				/// 业务类型
				/// </summary>
				CtpNetBizTypeType BizType;

				/// <summary>
				/// 延时换汇冻结金额
				/// </summary>
				double FrozenSwap;

				/// <summary>
				/// 剩余换汇额度
				/// </summary>
				double RemainSwap;
			};

			/// <summary>
			/// 投资者持仓
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetInvestorPositionField
			{
				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 持仓多空方向
				/// </summary>
				CtpNetPosiDirectionType PosiDirection;

				/// <summary>
				/// 投机套保标志
				/// </summary>
				CtpNetHedgeFlagType HedgeFlag;

				/// <summary>
				/// 持仓日期
				/// </summary>
				CtpNetPositionDateType PositionDate;

				/// <summary>
				/// 上日持仓
				/// </summary>
				int YdPosition;

				/// <summary>
				/// 今日持仓
				/// </summary>
				int Position;

				/// <summary>
				/// 多头冻结
				/// </summary>
				int LongFrozen;

				/// <summary>
				/// 空头冻结
				/// </summary>
				int ShortFrozen;

				/// <summary>
				/// 开仓冻结金额
				/// </summary>
				double LongFrozenAmount;

				/// <summary>
				/// 开仓冻结金额
				/// </summary>
				double ShortFrozenAmount;

				/// <summary>
				/// 开仓量
				/// </summary>
				int OpenVolume;

				/// <summary>
				/// 平仓量
				/// </summary>
				int CloseVolume;

				/// <summary>
				/// 开仓金额
				/// </summary>
				double OpenAmount;

				/// <summary>
				/// 平仓金额
				/// </summary>
				double CloseAmount;

				/// <summary>
				/// 持仓成本
				/// </summary>
				double PositionCost;

				/// <summary>
				/// 上次占用的保证金
				/// </summary>
				double PreMargin;

				/// <summary>
				/// 占用的保证金
				/// </summary>
				double UseMargin;

				/// <summary>
				/// 冻结的保证金
				/// </summary>
				double FrozenMargin;

				/// <summary>
				/// 冻结的资金
				/// </summary>
				double FrozenCash;

				/// <summary>
				/// 冻结的手续费
				/// </summary>
				double FrozenCommission;

				/// <summary>
				/// 资金差额
				/// </summary>
				double CashIn;

				/// <summary>
				/// 手续费
				/// </summary>
				double Commission;

				/// <summary>
				/// 平仓盈亏
				/// </summary>
				double CloseProfit;

				/// <summary>
				/// 持仓盈亏
				/// </summary>
				double PositionProfit;

				/// <summary>
				/// 上次结算价
				/// </summary>
				double PreSettlementPrice;

				/// <summary>
				/// 本次结算价
				/// </summary>
				double SettlementPrice;

				/// <summary>
				/// 交易日
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 结算编号
				/// </summary>
				int SettlementID;

				/// <summary>
				/// 开仓成本
				/// </summary>
				double OpenCost;

				/// <summary>
				/// 交易所保证金
				/// </summary>
				double ExchangeMargin;

				/// <summary>
				/// 组合成交形成的持仓
				/// </summary>
				int CombPosition;

				/// <summary>
				/// 组合多头冻结
				/// </summary>
				int CombLongFrozen;

				/// <summary>
				/// 组合空头冻结
				/// </summary>
				int CombShortFrozen;

				/// <summary>
				/// 逐日盯市平仓盈亏
				/// </summary>
				double CloseProfitByDate;

				/// <summary>
				/// 逐笔对冲平仓盈亏
				/// </summary>
				double CloseProfitByTrade;

				/// <summary>
				/// 今日持仓
				/// </summary>
				int TodayPosition;

				/// <summary>
				/// 保证金率
				/// </summary>
				double MarginRateByMoney;

				/// <summary>
				/// 保证金率(按手数)
				/// </summary>
				double MarginRateByVolume;

				/// <summary>
				/// 执行冻结
				/// </summary>
				int StrikeFrozen;

				/// <summary>
				/// 执行冻结金额
				/// </summary>
				double StrikeFrozenAmount;

				/// <summary>
				/// 放弃执行冻结
				/// </summary>
				int AbandonFrozen;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 执行冻结的昨仓
				/// </summary>
				int YdStrikeFrozen;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;
			};

			/// <summary>
			/// 合约保证金率
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetInstrumentMarginRateField
			{
				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 投资者范围
				/// </summary>
				CtpNetInvestorRangeType InvestorRange;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 投机套保标志
				/// </summary>
				CtpNetHedgeFlagType HedgeFlag;

				/// <summary>
				/// 多头保证金率
				/// </summary>
				double LongMarginRatioByMoney;

				/// <summary>
				/// 多头保证金费
				/// </summary>
				double LongMarginRatioByVolume;

				/// <summary>
				/// 空头保证金率
				/// </summary>
				double ShortMarginRatioByMoney;

				/// <summary>
				/// 空头保证金费
				/// </summary>
				double ShortMarginRatioByVolume;

				/// <summary>
				/// 是否相对交易所收取
				/// </summary>
				int IsRelative;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;
			};

			/// <summary>
			/// 合约手续费率
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetInstrumentCommissionRateField
			{
				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 投资者范围
				/// </summary>
				CtpNetInvestorRangeType InvestorRange;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 开仓手续费率
				/// </summary>
				double OpenRatioByMoney;

				/// <summary>
				/// 开仓手续费
				/// </summary>
				double OpenRatioByVolume;

				/// <summary>
				/// 平仓手续费率
				/// </summary>
				double CloseRatioByMoney;

				/// <summary>
				/// 平仓手续费
				/// </summary>
				double CloseRatioByVolume;

				/// <summary>
				/// 平今手续费率
				/// </summary>
				double CloseTodayRatioByMoney;

				/// <summary>
				/// 平今手续费
				/// </summary>
				double CloseTodayRatioByVolume;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 业务类型
				/// </summary>
				CtpNetBizTypeType BizType;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;
			};

			/// <summary>
			/// 深度行情
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetDepthMarketDataField
			{
				/// <summary>
				/// 交易日
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 合约在交易所的代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ ExchangeInstID;

				/// <summary>
				/// 最新价
				/// </summary>
				double LastPrice;

				/// <summary>
				/// 上次结算价
				/// </summary>
				double PreSettlementPrice;

				/// <summary>
				/// 昨收盘
				/// </summary>
				double PreClosePrice;

				/// <summary>
				/// 昨持仓量
				/// </summary>
				double PreOpenInterest;

				/// <summary>
				/// 今开盘
				/// </summary>
				double OpenPrice;

				/// <summary>
				/// 最高价
				/// </summary>
				double HighestPrice;

				/// <summary>
				/// 最低价
				/// </summary>
				double LowestPrice;

				/// <summary>
				/// 数量
				/// </summary>
				int Volume;

				/// <summary>
				/// 成交金额
				/// </summary>
				double Turnover;

				/// <summary>
				/// 持仓量
				/// </summary>
				double OpenInterest;

				/// <summary>
				/// 今收盘
				/// </summary>
				double ClosePrice;

				/// <summary>
				/// 本次结算价
				/// </summary>
				double SettlementPrice;

				/// <summary>
				/// 涨停板价
				/// </summary>
				double UpperLimitPrice;

				/// <summary>
				/// 跌停板价
				/// </summary>
				double LowerLimitPrice;

				/// <summary>
				/// 昨虚实度
				/// </summary>
				double PreDelta;

				/// <summary>
				/// 今虚实度
				/// </summary>
				double CurrDelta;

				/// <summary>
				/// 最后修改时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ UpdateTime;

				/// <summary>
				/// 最后修改毫秒
				/// </summary>
				int UpdateMillisec;

				/// <summary>
				/// 申买价一
				/// </summary>
				double BidPrice1;

				/// <summary>
				/// 申买量一
				/// </summary>
				int BidVolume1;

				/// <summary>
				/// 申卖价一
				/// </summary>
				double AskPrice1;

				/// <summary>
				/// 申卖量一
				/// </summary>
				int AskVolume1;

				/// <summary>
				/// 申买价二
				/// </summary>
				double BidPrice2;

				/// <summary>
				/// 申买量二
				/// </summary>
				int BidVolume2;

				/// <summary>
				/// 申卖价二
				/// </summary>
				double AskPrice2;

				/// <summary>
				/// 申卖量二
				/// </summary>
				int AskVolume2;

				/// <summary>
				/// 申买价三
				/// </summary>
				double BidPrice3;

				/// <summary>
				/// 申买量三
				/// </summary>
				int BidVolume3;

				/// <summary>
				/// 申卖价三
				/// </summary>
				double AskPrice3;

				/// <summary>
				/// 申卖量三
				/// </summary>
				int AskVolume3;

				/// <summary>
				/// 申买价四
				/// </summary>
				double BidPrice4;

				/// <summary>
				/// 申买量四
				/// </summary>
				int BidVolume4;

				/// <summary>
				/// 申卖价四
				/// </summary>
				double AskPrice4;

				/// <summary>
				/// 申卖量四
				/// </summary>
				int AskVolume4;

				/// <summary>
				/// 申买价五
				/// </summary>
				double BidPrice5;

				/// <summary>
				/// 申买量五
				/// </summary>
				int BidVolume5;

				/// <summary>
				/// 申卖价五
				/// </summary>
				double AskPrice5;

				/// <summary>
				/// 申卖量五
				/// </summary>
				int AskVolume5;

				/// <summary>
				/// 当日均价
				/// </summary>
				double AveragePrice;

				/// <summary>
				/// 业务日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ActionDay;
			};

			/// <summary>
			/// 投资者合约交易权限
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetInstrumentTradingRightField
			{
				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 投资者范围
				/// </summary>
				CtpNetInvestorRangeType InvestorRange;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 交易权限
				/// </summary>
				CtpNetTradingRightType TradingRight;
			};

			/// <summary>
			/// 经纪公司用户
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetBrokerUserField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 用户名称
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ UserName;

				/// <summary>
				/// 用户类型
				/// </summary>
				CtpNetUserTypeType UserType;

				/// <summary>
				/// 是否活跃
				/// </summary>
				int IsActive;

				/// <summary>
				/// 是否使用令牌
				/// </summary>
				int IsUsingOTP;

				/// <summary>
				/// 是否强制终端认证
				/// </summary>
				int IsAuthForce;
			};

			/// <summary>
			/// 经纪公司用户口令
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetBrokerUserPasswordField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Password;

				/// <summary>
				/// 上次修改时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ LastUpdateTime;

				/// <summary>
				/// 上次登陆时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ LastLoginTime;

				/// <summary>
				/// 密码过期时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExpireDate;

				/// <summary>
				/// 弱密码过期时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ WeakExpireDate;
			};

			/// <summary>
			/// 经纪公司用户功能权限
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetBrokerUserFunctionField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 经纪公司功能代码
				/// </summary>
				CtpNetBrokerFunctionCodeType BrokerFunctionCode;
			};

			/// <summary>
			/// 交易所交易员报盘机
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetTraderOfferField
			{
				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;

				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Password;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 本地报单编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ OrderLocalID;

				/// <summary>
				/// 交易所交易员连接状态
				/// </summary>
				CtpNetTraderConnectStatusType TraderConnectStatus;

				/// <summary>
				/// 发出连接请求的日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ConnectRequestDate;

				/// <summary>
				/// 发出连接请求的时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ConnectRequestTime;

				/// <summary>
				/// 上次报告日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ LastReportDate;

				/// <summary>
				/// 上次报告时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ LastReportTime;

				/// <summary>
				/// 完成连接日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ConnectDate;

				/// <summary>
				/// 完成连接时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ConnectTime;

				/// <summary>
				/// 启动日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ StartDate;

				/// <summary>
				/// 启动时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ StartTime;

				/// <summary>
				/// 交易日
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 本席位最大成交编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MaxTradeID;

				/// <summary>
				/// 本席位最大报单备拷
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ MaxOrderMessageReference;
			};

			/// <summary>
			/// 投资者结算结果
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetSettlementInfoField
			{
				/// <summary>
				/// 交易日
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 结算编号
				/// </summary>
				int SettlementID;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 序号
				/// </summary>
				int SequenceNo;

				/// <summary>
				/// 消息正文
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 501)]
				String^ Content;

				/// <summary>
				/// 投资者帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;
			};

			/// <summary>
			/// 合约保证金率调整
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetInstrumentMarginRateAdjustField
			{
				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 投资者范围
				/// </summary>
				CtpNetInvestorRangeType InvestorRange;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 投机套保标志
				/// </summary>
				CtpNetHedgeFlagType HedgeFlag;

				/// <summary>
				/// 多头保证金率
				/// </summary>
				double LongMarginRatioByMoney;

				/// <summary>
				/// 多头保证金费
				/// </summary>
				double LongMarginRatioByVolume;

				/// <summary>
				/// 空头保证金率
				/// </summary>
				double ShortMarginRatioByMoney;

				/// <summary>
				/// 空头保证金费
				/// </summary>
				double ShortMarginRatioByVolume;

				/// <summary>
				/// 是否相对交易所收取
				/// </summary>
				int IsRelative;
			};

			/// <summary>
			/// 交易所保证金率
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetExchangeMarginRateField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 投机套保标志
				/// </summary>
				CtpNetHedgeFlagType HedgeFlag;

				/// <summary>
				/// 多头保证金率
				/// </summary>
				double LongMarginRatioByMoney;

				/// <summary>
				/// 多头保证金费
				/// </summary>
				double LongMarginRatioByVolume;

				/// <summary>
				/// 空头保证金率
				/// </summary>
				double ShortMarginRatioByMoney;

				/// <summary>
				/// 空头保证金费
				/// </summary>
				double ShortMarginRatioByVolume;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;
			};

			/// <summary>
			/// 交易所保证金率调整
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetExchangeMarginRateAdjustField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 投机套保标志
				/// </summary>
				CtpNetHedgeFlagType HedgeFlag;

				/// <summary>
				/// 跟随交易所投资者多头保证金率
				/// </summary>
				double LongMarginRatioByMoney;

				/// <summary>
				/// 跟随交易所投资者多头保证金费
				/// </summary>
				double LongMarginRatioByVolume;

				/// <summary>
				/// 跟随交易所投资者空头保证金率
				/// </summary>
				double ShortMarginRatioByMoney;

				/// <summary>
				/// 跟随交易所投资者空头保证金费
				/// </summary>
				double ShortMarginRatioByVolume;

				/// <summary>
				/// 交易所多头保证金率
				/// </summary>
				double ExchLongMarginRatioByMoney;

				/// <summary>
				/// 交易所多头保证金费
				/// </summary>
				double ExchLongMarginRatioByVolume;

				/// <summary>
				/// 交易所空头保证金率
				/// </summary>
				double ExchShortMarginRatioByMoney;

				/// <summary>
				/// 交易所空头保证金费
				/// </summary>
				double ExchShortMarginRatioByVolume;

				/// <summary>
				/// 不跟随交易所投资者多头保证金率
				/// </summary>
				double NoLongMarginRatioByMoney;

				/// <summary>
				/// 不跟随交易所投资者多头保证金费
				/// </summary>
				double NoLongMarginRatioByVolume;

				/// <summary>
				/// 不跟随交易所投资者空头保证金率
				/// </summary>
				double NoShortMarginRatioByMoney;

				/// <summary>
				/// 不跟随交易所投资者空头保证金费
				/// </summary>
				double NoShortMarginRatioByVolume;
			};

			/// <summary>
			/// 汇率
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetExchangeRateField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 源币种
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ FromCurrencyID;

				/// <summary>
				/// 源币种单位数量
				/// </summary>
				double FromCurrencyUnit;

				/// <summary>
				/// 目标币种
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ ToCurrencyID;

				/// <summary>
				/// 汇率
				/// </summary>
				double ExchangeRate;
			};

			/// <summary>
			/// 结算引用
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetSettlementRefField
			{
				/// <summary>
				/// 交易日
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 结算编号
				/// </summary>
				int SettlementID;
			};

			/// <summary>
			/// 当前时间
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetCurrentTimeField
			{
				/// <summary>
				/// 当前日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ CurrDate;

				/// <summary>
				/// 当前时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ CurrTime;

				/// <summary>
				/// 当前时间（毫秒）
				/// </summary>
				int CurrMillisec;

				/// <summary>
				/// 业务日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ActionDay;
			};

			/// <summary>
			/// 通讯阶段
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetCommPhaseField
			{
				/// <summary>
				/// 交易日
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 通讯时段编号
				/// </summary>
				short CommPhaseNo;

				/// <summary>
				/// 系统编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ SystemID;
			};

			/// <summary>
			/// 登录信息
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetLoginInfoField
			{
				/// <summary>
				/// 前置编号
				/// </summary>
				int FrontID;

				/// <summary>
				/// 会话编号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 登录日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ LoginDate;

				/// <summary>
				/// 登录时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ LoginTime;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// 用户端产品信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ UserProductInfo;

				/// <summary>
				/// 接口端产品信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ InterfaceProductInfo;

				/// <summary>
				/// 协议信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ProtocolInfo;

				/// <summary>
				/// 系统名称
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ SystemName;

				/// <summary>
				/// 密码,已弃用
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ PasswordDeprecated;

				/// <summary>
				/// 最大报单引用
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ MaxOrderRef;

				/// <summary>
				/// 上期所时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ SHFETime;

				/// <summary>
				/// 大商所时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ DCETime;

				/// <summary>
				/// 郑商所时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ CZCETime;

				/// <summary>
				/// 中金所时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ FFEXTime;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;

				/// <summary>
				/// 动态密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ OneTimePassword;

				/// <summary>
				/// 能源中心时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ INETime;

				/// <summary>
				/// 查询时是否需要流控
				/// </summary>
				int IsQryControl;

				/// <summary>
				/// 登录备注
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
				String^ LoginRemark;

				/// <summary>
				/// 密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Password;
			};

			/// <summary>
			/// 登录信息
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetLogoutAllField
			{
				/// <summary>
				/// 前置编号
				/// </summary>
				int FrontID;

				/// <summary>
				/// 会话编号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 系统名称
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ SystemName;
			};

			/// <summary>
			/// 前置状态
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetFrontStatusField
			{
				/// <summary>
				/// 前置编号
				/// </summary>
				int FrontID;

				/// <summary>
				/// 上次报告日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ LastReportDate;

				/// <summary>
				/// 上次报告时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ LastReportTime;

				/// <summary>
				/// 是否活跃
				/// </summary>
				int IsActive;
			};

			/// <summary>
			/// 用户口令变更
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetUserPasswordUpdateField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 原来的口令
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ OldPassword;

				/// <summary>
				/// 新的口令
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ NewPassword;
			};

			/// <summary>
			/// 输入报单
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetInputOrderField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 报单引用
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ OrderRef;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 报单价格条件
				/// </summary>
				CtpNetOrderPriceTypeType OrderPriceType;

				/// <summary>
				/// 买卖方向
				/// </summary>
				CtpNetDirectionType Direction;

				/// <summary>
				/// 组合开平标志1
				/// </summary>
				CtpNetOffsetFlagType CombOffsetFlag1;
				
				/// <summary>
				/// 组合开平标志2
				/// </summary>
				CtpNetOffsetFlagType CombOffsetFlag2;
				
				/// <summary>
				/// 组合开平标志3
				/// </summary>
				CtpNetOffsetFlagType CombOffsetFlag3;
				
				/// <summary>
				/// 组合开平标志4
				/// </summary>
				CtpNetOffsetFlagType CombOffsetFlag4;
				
				/// <summary>
				/// 组合开平标志5
				/// </summary>
				CtpNetOffsetFlagType CombOffsetFlag5;

				/// <summary>
				/// 组合投机套保标志1
				/// </summary>
				CtpNetHedgeFlagType CombHedgeFlag1;
				
				/// <summary>
				/// 组合投机套保标志2
				/// </summary>
				CtpNetHedgeFlagType CombHedgeFlag2;
				
				/// <summary>
				/// 组合投机套保标志3
				/// </summary>
				CtpNetHedgeFlagType CombHedgeFlag3;
				
				/// <summary>
				/// 组合投机套保标志4
				/// </summary>
				CtpNetHedgeFlagType CombHedgeFlag4;
				
				/// <summary>
				/// 组合投机套保标志5
				/// </summary>
				CtpNetHedgeFlagType CombHedgeFlag5;

				/// <summary>
				/// 价格
				/// </summary>
				double LimitPrice;

				/// <summary>
				/// 数量
				/// </summary>
				int VolumeTotalOriginal;

				/// <summary>
				/// 有效期类型
				/// </summary>
				CtpNetTimeConditionType TimeCondition;

				/// <summary>
				/// GTD日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ GTDDate;

				/// <summary>
				/// 成交量类型
				/// </summary>
				CtpNetVolumeConditionType VolumeCondition;

				/// <summary>
				/// 最小成交量
				/// </summary>
				int MinVolume;

				/// <summary>
				/// 触发条件
				/// </summary>
				CtpNetContingentConditionType ContingentCondition;

				/// <summary>
				/// 止损价
				/// </summary>
				double StopPrice;

				/// <summary>
				/// 强平原因
				/// </summary>
				CtpNetForceCloseReasonType ForceCloseReason;

				/// <summary>
				/// 自动挂起标志
				/// </summary>
				int IsAutoSuspend;

				/// <summary>
				/// 业务单元
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ BusinessUnit;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 用户强评标志
				/// </summary>
				int UserForceClose;

				/// <summary>
				/// 互换单标志
				/// </summary>
				int IsSwapOrder;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;

				/// <summary>
				/// 资金账号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// 交易编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;
			};

			/// <summary>
			/// 报单
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetOrderField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 报单引用
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ OrderRef;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 报单价格条件
				/// </summary>
				CtpNetOrderPriceTypeType OrderPriceType;

				/// <summary>
				/// 买卖方向
				/// </summary>
				CtpNetDirectionType Direction;

				/// <summary>
				/// 组合开平标志1
				/// </summary>
				CtpNetOffsetFlagType CombOffsetFlag1;
				
				/// <summary>
				/// 组合开平标志2
				/// </summary>
				CtpNetOffsetFlagType CombOffsetFlag2;
				
				/// <summary>
				/// 组合开平标志3
				/// </summary>
				CtpNetOffsetFlagType CombOffsetFlag3;
				
				/// <summary>
				/// 组合开平标志4
				/// </summary>
				CtpNetOffsetFlagType CombOffsetFlag4;
				
				/// <summary>
				/// 组合开平标志5
				/// </summary>
				CtpNetOffsetFlagType CombOffsetFlag5;

				/// <summary>
				/// 组合投机套保标志1
				/// </summary>
				CtpNetHedgeFlagType CombHedgeFlag1;
				
				/// <summary>
				/// 组合投机套保标志2
				/// </summary>
				CtpNetHedgeFlagType CombHedgeFlag2;
				
				/// <summary>
				/// 组合投机套保标志3
				/// </summary>
				CtpNetHedgeFlagType CombHedgeFlag3;
				
				/// <summary>
				/// 组合投机套保标志4
				/// </summary>
				CtpNetHedgeFlagType CombHedgeFlag4;
				
				/// <summary>
				/// 组合投机套保标志5
				/// </summary>
				CtpNetHedgeFlagType CombHedgeFlag5;

				/// <summary>
				/// 价格
				/// </summary>
				double LimitPrice;

				/// <summary>
				/// 数量
				/// </summary>
				int VolumeTotalOriginal;

				/// <summary>
				/// 有效期类型
				/// </summary>
				CtpNetTimeConditionType TimeCondition;

				/// <summary>
				/// GTD日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ GTDDate;

				/// <summary>
				/// 成交量类型
				/// </summary>
				CtpNetVolumeConditionType VolumeCondition;

				/// <summary>
				/// 最小成交量
				/// </summary>
				int MinVolume;

				/// <summary>
				/// 触发条件
				/// </summary>
				CtpNetContingentConditionType ContingentCondition;

				/// <summary>
				/// 止损价
				/// </summary>
				double StopPrice;

				/// <summary>
				/// 强平原因
				/// </summary>
				CtpNetForceCloseReasonType ForceCloseReason;

				/// <summary>
				/// 自动挂起标志
				/// </summary>
				int IsAutoSuspend;

				/// <summary>
				/// 业务单元
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ BusinessUnit;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 本地报单编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ OrderLocalID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 客户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// 合约在交易所的代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ ExchangeInstID;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 报单提交状态
				/// </summary>
				CtpNetOrderSubmitStatusType OrderSubmitStatus;

				/// <summary>
				/// 报单提示序号
				/// </summary>
				int NotifySequence;

				/// <summary>
				/// 交易日
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 结算编号
				/// </summary>
				int SettlementID;

				/// <summary>
				/// 报单编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ OrderSysID;

				/// <summary>
				/// 报单来源
				/// </summary>
				CtpNetOrderSourceType OrderSource;

				/// <summary>
				/// 报单状态
				/// </summary>
				CtpNetOrderStatusType OrderStatus;

				/// <summary>
				/// 报单类型
				/// </summary>
				CtpNetOrderTypeType OrderType;

				/// <summary>
				/// 今成交数量
				/// </summary>
				int VolumeTraded;

				/// <summary>
				/// 剩余数量
				/// </summary>
				int VolumeTotal;

				/// <summary>
				/// 报单日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ InsertDate;

				/// <summary>
				/// 委托时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ InsertTime;

				/// <summary>
				/// 激活时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ActiveTime;

				/// <summary>
				/// 挂起时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ SuspendTime;

				/// <summary>
				/// 最后修改时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ UpdateTime;

				/// <summary>
				/// 撤销时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ CancelTime;

				/// <summary>
				/// 最后修改交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ ActiveTraderID;

				/// <summary>
				/// 结算会员编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClearingPartID;

				/// <summary>
				/// 序号
				/// </summary>
				int SequenceNo;

				/// <summary>
				/// 前置编号
				/// </summary>
				int FrontID;

				/// <summary>
				/// 会话编号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 用户端产品信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ UserProductInfo;

				/// <summary>
				/// 状态信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ StatusMsg;

				/// <summary>
				/// 用户强评标志
				/// </summary>
				int UserForceClose;

				/// <summary>
				/// 操作用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ ActiveUserID;

				/// <summary>
				/// 经纪公司报单编号
				/// </summary>
				int BrokerOrderSeq;

				/// <summary>
				/// 相关报单
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ RelativeOrderSysID;

				/// <summary>
				/// 郑商所成交数量
				/// </summary>
				int ZCETotalTradedVolume;

				/// <summary>
				/// 互换单标志
				/// </summary>
				int IsSwapOrder;

				/// <summary>
				/// 营业部编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ BranchID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;

				/// <summary>
				/// 资金账号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;
			};

			/// <summary>
			/// 交易所报单
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetExchangeOrderField
			{
				/// <summary>
				/// 报单价格条件
				/// </summary>
				CtpNetOrderPriceTypeType OrderPriceType;

				/// <summary>
				/// 买卖方向
				/// </summary>
				CtpNetDirectionType Direction;

				/// <summary>
				/// 组合开平标志1
				/// </summary>
				CtpNetOffsetFlagType CombOffsetFlag1;
				
				/// <summary>
				/// 组合开平标志2
				/// </summary>
				CtpNetOffsetFlagType CombOffsetFlag2;
				
				/// <summary>
				/// 组合开平标志3
				/// </summary>
				CtpNetOffsetFlagType CombOffsetFlag3;
				
				/// <summary>
				/// 组合开平标志4
				/// </summary>
				CtpNetOffsetFlagType CombOffsetFlag4;
				
				/// <summary>
				/// 组合开平标志5
				/// </summary>
				CtpNetOffsetFlagType CombOffsetFlag5;

				/// <summary>
				/// 组合投机套保标志1
				/// </summary>
				CtpNetHedgeFlagType CombHedgeFlag1;
				
				/// <summary>
				/// 组合投机套保标志2
				/// </summary>
				CtpNetHedgeFlagType CombHedgeFlag2;
				
				/// <summary>
				/// 组合投机套保标志3
				/// </summary>
				CtpNetHedgeFlagType CombHedgeFlag3;
				
				/// <summary>
				/// 组合投机套保标志4
				/// </summary>
				CtpNetHedgeFlagType CombHedgeFlag4;
				
				/// <summary>
				/// 组合投机套保标志5
				/// </summary>
				CtpNetHedgeFlagType CombHedgeFlag5;

				/// <summary>
				/// 价格
				/// </summary>
				double LimitPrice;

				/// <summary>
				/// 数量
				/// </summary>
				int VolumeTotalOriginal;

				/// <summary>
				/// 有效期类型
				/// </summary>
				CtpNetTimeConditionType TimeCondition;

				/// <summary>
				/// GTD日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ GTDDate;

				/// <summary>
				/// 成交量类型
				/// </summary>
				CtpNetVolumeConditionType VolumeCondition;

				/// <summary>
				/// 最小成交量
				/// </summary>
				int MinVolume;

				/// <summary>
				/// 触发条件
				/// </summary>
				CtpNetContingentConditionType ContingentCondition;

				/// <summary>
				/// 止损价
				/// </summary>
				double StopPrice;

				/// <summary>
				/// 强平原因
				/// </summary>
				CtpNetForceCloseReasonType ForceCloseReason;

				/// <summary>
				/// 自动挂起标志
				/// </summary>
				int IsAutoSuspend;

				/// <summary>
				/// 业务单元
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ BusinessUnit;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 本地报单编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ OrderLocalID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 客户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// 合约在交易所的代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ ExchangeInstID;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 报单提交状态
				/// </summary>
				CtpNetOrderSubmitStatusType OrderSubmitStatus;

				/// <summary>
				/// 报单提示序号
				/// </summary>
				int NotifySequence;

				/// <summary>
				/// 交易日
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 结算编号
				/// </summary>
				int SettlementID;

				/// <summary>
				/// 报单编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ OrderSysID;

				/// <summary>
				/// 报单来源
				/// </summary>
				CtpNetOrderSourceType OrderSource;

				/// <summary>
				/// 报单状态
				/// </summary>
				CtpNetOrderStatusType OrderStatus;

				/// <summary>
				/// 报单类型
				/// </summary>
				CtpNetOrderTypeType OrderType;

				/// <summary>
				/// 今成交数量
				/// </summary>
				int VolumeTraded;

				/// <summary>
				/// 剩余数量
				/// </summary>
				int VolumeTotal;

				/// <summary>
				/// 报单日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ InsertDate;

				/// <summary>
				/// 委托时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ InsertTime;

				/// <summary>
				/// 激活时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ActiveTime;

				/// <summary>
				/// 挂起时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ SuspendTime;

				/// <summary>
				/// 最后修改时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ UpdateTime;

				/// <summary>
				/// 撤销时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ CancelTime;

				/// <summary>
				/// 最后修改交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ ActiveTraderID;

				/// <summary>
				/// 结算会员编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClearingPartID;

				/// <summary>
				/// 序号
				/// </summary>
				int SequenceNo;

				/// <summary>
				/// 营业部编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ BranchID;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;
			};

			/// <summary>
			/// 交易所报单插入失败
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetExchangeOrderInsertErrorField
			{
				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 本地报单编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ OrderLocalID;

				/// <summary>
				/// 错误代码
				/// </summary>
				int ErrorID;

				/// <summary>
				/// 错误信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ ErrorMsg;
			};

			/// <summary>
			/// 输入报单操作
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetInputOrderActionField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 报单操作引用
				/// </summary>
				int OrderActionRef;

				/// <summary>
				/// 报单引用
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ OrderRef;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 前置编号
				/// </summary>
				int FrontID;

				/// <summary>
				/// 会话编号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 报单编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ OrderSysID;

				/// <summary>
				/// 操作标志
				/// </summary>
				CtpNetActionFlagType ActionFlag;

				/// <summary>
				/// 价格
				/// </summary>
				double LimitPrice;

				/// <summary>
				/// 数量变化
				/// </summary>
				int VolumeChange;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;
			};

			/// <summary>
			/// 报单操作
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetOrderActionField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 报单操作引用
				/// </summary>
				int OrderActionRef;

				/// <summary>
				/// 报单引用
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ OrderRef;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 前置编号
				/// </summary>
				int FrontID;

				/// <summary>
				/// 会话编号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 报单编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ OrderSysID;

				/// <summary>
				/// 操作标志
				/// </summary>
				CtpNetActionFlagType ActionFlag;

				/// <summary>
				/// 价格
				/// </summary>
				double LimitPrice;

				/// <summary>
				/// 数量变化
				/// </summary>
				int VolumeChange;

				/// <summary>
				/// 操作日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ActionDate;

				/// <summary>
				/// 操作时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ActionTime;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 本地报单编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ OrderLocalID;

				/// <summary>
				/// 操作本地编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ ActionLocalID;

				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 客户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// 业务单元
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ BusinessUnit;

				/// <summary>
				/// 报单操作状态
				/// </summary>
				CtpNetOrderActionStatusType OrderActionStatus;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 状态信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ StatusMsg;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 营业部编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ BranchID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;
			};

			/// <summary>
			/// 交易所报单操作
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetExchangeOrderActionField
			{
				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 报单编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ OrderSysID;

				/// <summary>
				/// 操作标志
				/// </summary>
				CtpNetActionFlagType ActionFlag;

				/// <summary>
				/// 价格
				/// </summary>
				double LimitPrice;

				/// <summary>
				/// 数量变化
				/// </summary>
				int VolumeChange;

				/// <summary>
				/// 操作日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ActionDate;

				/// <summary>
				/// 操作时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ActionTime;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 本地报单编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ OrderLocalID;

				/// <summary>
				/// 操作本地编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ ActionLocalID;

				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 客户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// 业务单元
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ BusinessUnit;

				/// <summary>
				/// 报单操作状态
				/// </summary>
				CtpNetOrderActionStatusType OrderActionStatus;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 营业部编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ BranchID;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;
			};

			/// <summary>
			/// 交易所报单操作失败
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetExchangeOrderActionErrorField
			{
				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 报单编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ OrderSysID;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 本地报单编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ OrderLocalID;

				/// <summary>
				/// 操作本地编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ ActionLocalID;

				/// <summary>
				/// 错误代码
				/// </summary>
				int ErrorID;

				/// <summary>
				/// 错误信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ ErrorMsg;
			};

			/// <summary>
			/// 交易所成交
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetExchangeTradeField
			{
				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 成交编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TradeID;

				/// <summary>
				/// 买卖方向
				/// </summary>
				CtpNetDirectionType Direction;

				/// <summary>
				/// 报单编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ OrderSysID;

				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 客户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// 交易角色
				/// </summary>
				CtpNetTradingRoleType TradingRole;

				/// <summary>
				/// 合约在交易所的代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ ExchangeInstID;

				/// <summary>
				/// 开平标志
				/// </summary>
				CtpNetOffsetFlagType OffsetFlag;

				/// <summary>
				/// 投机套保标志
				/// </summary>
				CtpNetHedgeFlagType HedgeFlag;

				/// <summary>
				/// 价格
				/// </summary>
				double Price;

				/// <summary>
				/// 数量
				/// </summary>
				int Volume;

				/// <summary>
				/// 成交时期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeDate;

				/// <summary>
				/// 成交时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeTime;

				/// <summary>
				/// 成交类型
				/// </summary>
				CtpNetTradeTypeType TradeType;

				/// <summary>
				/// 成交价来源
				/// </summary>
				CtpNetPriceSourceType PriceSource;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;

				/// <summary>
				/// 本地报单编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ OrderLocalID;

				/// <summary>
				/// 结算会员编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClearingPartID;

				/// <summary>
				/// 业务单元
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ BusinessUnit;

				/// <summary>
				/// 序号
				/// </summary>
				int SequenceNo;

				/// <summary>
				/// 成交来源
				/// </summary>
				CtpNetTradeSourceType TradeSource;
			};

			/// <summary>
			/// 成交
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetTradeField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 报单引用
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ OrderRef;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 成交编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TradeID;

				/// <summary>
				/// 买卖方向
				/// </summary>
				CtpNetDirectionType Direction;

				/// <summary>
				/// 报单编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ OrderSysID;

				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 客户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// 交易角色
				/// </summary>
				CtpNetTradingRoleType TradingRole;

				/// <summary>
				/// 合约在交易所的代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ ExchangeInstID;

				/// <summary>
				/// 开平标志
				/// </summary>
				CtpNetOffsetFlagType OffsetFlag;

				/// <summary>
				/// 投机套保标志
				/// </summary>
				CtpNetHedgeFlagType HedgeFlag;

				/// <summary>
				/// 价格
				/// </summary>
				double Price;

				/// <summary>
				/// 数量
				/// </summary>
				int Volume;

				/// <summary>
				/// 成交时期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeDate;

				/// <summary>
				/// 成交时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeTime;

				/// <summary>
				/// 成交类型
				/// </summary>
				CtpNetTradeTypeType TradeType;

				/// <summary>
				/// 成交价来源
				/// </summary>
				CtpNetPriceSourceType PriceSource;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;

				/// <summary>
				/// 本地报单编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ OrderLocalID;

				/// <summary>
				/// 结算会员编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClearingPartID;

				/// <summary>
				/// 业务单元
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ BusinessUnit;

				/// <summary>
				/// 序号
				/// </summary>
				int SequenceNo;

				/// <summary>
				/// 交易日
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 结算编号
				/// </summary>
				int SettlementID;

				/// <summary>
				/// 经纪公司报单编号
				/// </summary>
				int BrokerOrderSeq;

				/// <summary>
				/// 成交来源
				/// </summary>
				CtpNetTradeSourceType TradeSource;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;
			};

			/// <summary>
			/// 用户会话
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetUserSessionField
			{
				/// <summary>
				/// 前置编号
				/// </summary>
				int FrontID;

				/// <summary>
				/// 会话编号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 登录日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ LoginDate;

				/// <summary>
				/// 登录时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ LoginTime;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// 用户端产品信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ UserProductInfo;

				/// <summary>
				/// 接口端产品信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ InterfaceProductInfo;

				/// <summary>
				/// 协议信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ProtocolInfo;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;

				/// <summary>
				/// 登录备注
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
				String^ LoginRemark;
			};

			/// <summary>
			/// 查询最大报单数量
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQueryMaxOrderVolumeField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 买卖方向
				/// </summary>
				CtpNetDirectionType Direction;

				/// <summary>
				/// 开平标志
				/// </summary>
				CtpNetOffsetFlagType OffsetFlag;

				/// <summary>
				/// 投机套保标志
				/// </summary>
				CtpNetHedgeFlagType HedgeFlag;

				/// <summary>
				/// 最大允许报单数量
				/// </summary>
				int MaxVolume;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;
			};

			/// <summary>
			/// 投资者结算结果确认信息
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetSettlementInfoConfirmField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 确认日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ConfirmDate;

				/// <summary>
				/// 确认时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ConfirmTime;

				/// <summary>
				/// 结算编号
				/// </summary>
				int SettlementID;

				/// <summary>
				/// 投资者帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;
			};

			/// <summary>
			/// 出入金同步
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetSyncDepositField
			{
				/// <summary>
				/// 出入金流水号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
				String^ DepositSeqNo;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 入金金额
				/// </summary>
				double Deposit;

				/// <summary>
				/// 是否强制进行
				/// </summary>
				int IsForce;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;
			};

			/// <summary>
			/// 货币质押同步
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetSyncFundMortgageField
			{
				/// <summary>
				/// 货币质押流水号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
				String^ MortgageSeqNo;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 源币种
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ FromCurrencyID;

				/// <summary>
				/// 质押金额
				/// </summary>
				double MortgageAmount;

				/// <summary>
				/// 目标币种
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ ToCurrencyID;
			};

			/// <summary>
			/// 经纪公司同步
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetBrokerSyncField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;
			};

			/// <summary>
			/// 正在同步中的投资者
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetSyncingInvestorField
			{
				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者分组代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorGroupID;

				/// <summary>
				/// 投资者名称
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ InvestorName;

				/// <summary>
				/// 证件类型
				/// </summary>
				CtpNetIdCardTypeType IdentifiedCardType;

				/// <summary>
				/// 证件号码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
				String^ IdentifiedCardNo;

				/// <summary>
				/// 是否活跃
				/// </summary>
				int IsActive;

				/// <summary>
				/// 联系电话
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Telephone;

				/// <summary>
				/// 通讯地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 101)]
				String^ Address;

				/// <summary>
				/// 开户日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ OpenDate;

				/// <summary>
				/// 手机
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Mobile;

				/// <summary>
				/// 手续费率模板代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ CommModelID;

				/// <summary>
				/// 保证金率模板代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ MarginModelID;
			};

			/// <summary>
			/// 正在同步中的交易代码
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetSyncingTradingCodeField
			{
				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 客户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// 是否活跃
				/// </summary>
				int IsActive;

				/// <summary>
				/// 交易编码类型
				/// </summary>
				CtpNetClientIDTypeType ClientIDType;
			};

			/// <summary>
			/// 正在同步中的投资者分组
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetSyncingInvestorGroupField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者分组代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorGroupID;

				/// <summary>
				/// 投资者分组名称
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ InvestorGroupName;
			};

			/// <summary>
			/// 正在同步中的交易账号
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetSyncingTradingAccountField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 上次质押金额
				/// </summary>
				double PreMortgage;

				/// <summary>
				/// 上次信用额度
				/// </summary>
				double PreCredit;

				/// <summary>
				/// 上次存款额
				/// </summary>
				double PreDeposit;

				/// <summary>
				/// 上次结算准备金
				/// </summary>
				double PreBalance;

				/// <summary>
				/// 上次占用的保证金
				/// </summary>
				double PreMargin;

				/// <summary>
				/// 利息基数
				/// </summary>
				double InterestBase;

				/// <summary>
				/// 利息收入
				/// </summary>
				double Interest;

				/// <summary>
				/// 入金金额
				/// </summary>
				double Deposit;

				/// <summary>
				/// 出金金额
				/// </summary>
				double Withdraw;

				/// <summary>
				/// 冻结的保证金
				/// </summary>
				double FrozenMargin;

				/// <summary>
				/// 冻结的资金
				/// </summary>
				double FrozenCash;

				/// <summary>
				/// 冻结的手续费
				/// </summary>
				double FrozenCommission;

				/// <summary>
				/// 当前保证金总额
				/// </summary>
				double CurrMargin;

				/// <summary>
				/// 资金差额
				/// </summary>
				double CashIn;

				/// <summary>
				/// 手续费
				/// </summary>
				double Commission;

				/// <summary>
				/// 平仓盈亏
				/// </summary>
				double CloseProfit;

				/// <summary>
				/// 持仓盈亏
				/// </summary>
				double PositionProfit;

				/// <summary>
				/// 期货结算准备金
				/// </summary>
				double Balance;

				/// <summary>
				/// 可用资金
				/// </summary>
				double Available;

				/// <summary>
				/// 可取资金
				/// </summary>
				double WithdrawQuota;

				/// <summary>
				/// 基本准备金
				/// </summary>
				double Reserve;

				/// <summary>
				/// 交易日
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 结算编号
				/// </summary>
				int SettlementID;

				/// <summary>
				/// 信用额度
				/// </summary>
				double Credit;

				/// <summary>
				/// 质押金额
				/// </summary>
				double Mortgage;

				/// <summary>
				/// 交易所保证金
				/// </summary>
				double ExchangeMargin;

				/// <summary>
				/// 投资者交割保证金
				/// </summary>
				double DeliveryMargin;

				/// <summary>
				/// 交易所交割保证金
				/// </summary>
				double ExchangeDeliveryMargin;

				/// <summary>
				/// 保底期货结算准备金
				/// </summary>
				double ReserveBalance;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// 上次货币质入金额
				/// </summary>
				double PreFundMortgageIn;

				/// <summary>
				/// 上次货币质出金额
				/// </summary>
				double PreFundMortgageOut;

				/// <summary>
				/// 货币质入金额
				/// </summary>
				double FundMortgageIn;

				/// <summary>
				/// 货币质出金额
				/// </summary>
				double FundMortgageOut;

				/// <summary>
				/// 货币质押余额
				/// </summary>
				double FundMortgageAvailable;

				/// <summary>
				/// 可质押货币金额
				/// </summary>
				double MortgageableFund;

				/// <summary>
				/// 特殊产品占用保证金
				/// </summary>
				double SpecProductMargin;

				/// <summary>
				/// 特殊产品冻结保证金
				/// </summary>
				double SpecProductFrozenMargin;

				/// <summary>
				/// 特殊产品手续费
				/// </summary>
				double SpecProductCommission;

				/// <summary>
				/// 特殊产品冻结手续费
				/// </summary>
				double SpecProductFrozenCommission;

				/// <summary>
				/// 特殊产品持仓盈亏
				/// </summary>
				double SpecProductPositionProfit;

				/// <summary>
				/// 特殊产品平仓盈亏
				/// </summary>
				double SpecProductCloseProfit;

				/// <summary>
				/// 根据持仓盈亏算法计算的特殊产品持仓盈亏
				/// </summary>
				double SpecProductPositionProfitByAlg;

				/// <summary>
				/// 特殊产品交易所保证金
				/// </summary>
				double SpecProductExchangeMargin;

				/// <summary>
				/// 延时换汇冻结金额
				/// </summary>
				double FrozenSwap;

				/// <summary>
				/// 剩余换汇额度
				/// </summary>
				double RemainSwap;
			};

			/// <summary>
			/// 正在同步中的投资者持仓
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetSyncingInvestorPositionField
			{
				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 持仓多空方向
				/// </summary>
				CtpNetPosiDirectionType PosiDirection;

				/// <summary>
				/// 投机套保标志
				/// </summary>
				CtpNetHedgeFlagType HedgeFlag;

				/// <summary>
				/// 持仓日期
				/// </summary>
				CtpNetPositionDateType PositionDate;

				/// <summary>
				/// 上日持仓
				/// </summary>
				int YdPosition;

				/// <summary>
				/// 今日持仓
				/// </summary>
				int Position;

				/// <summary>
				/// 多头冻结
				/// </summary>
				int LongFrozen;

				/// <summary>
				/// 空头冻结
				/// </summary>
				int ShortFrozen;

				/// <summary>
				/// 开仓冻结金额
				/// </summary>
				double LongFrozenAmount;

				/// <summary>
				/// 开仓冻结金额
				/// </summary>
				double ShortFrozenAmount;

				/// <summary>
				/// 开仓量
				/// </summary>
				int OpenVolume;

				/// <summary>
				/// 平仓量
				/// </summary>
				int CloseVolume;

				/// <summary>
				/// 开仓金额
				/// </summary>
				double OpenAmount;

				/// <summary>
				/// 平仓金额
				/// </summary>
				double CloseAmount;

				/// <summary>
				/// 持仓成本
				/// </summary>
				double PositionCost;

				/// <summary>
				/// 上次占用的保证金
				/// </summary>
				double PreMargin;

				/// <summary>
				/// 占用的保证金
				/// </summary>
				double UseMargin;

				/// <summary>
				/// 冻结的保证金
				/// </summary>
				double FrozenMargin;

				/// <summary>
				/// 冻结的资金
				/// </summary>
				double FrozenCash;

				/// <summary>
				/// 冻结的手续费
				/// </summary>
				double FrozenCommission;

				/// <summary>
				/// 资金差额
				/// </summary>
				double CashIn;

				/// <summary>
				/// 手续费
				/// </summary>
				double Commission;

				/// <summary>
				/// 平仓盈亏
				/// </summary>
				double CloseProfit;

				/// <summary>
				/// 持仓盈亏
				/// </summary>
				double PositionProfit;

				/// <summary>
				/// 上次结算价
				/// </summary>
				double PreSettlementPrice;

				/// <summary>
				/// 本次结算价
				/// </summary>
				double SettlementPrice;

				/// <summary>
				/// 交易日
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 结算编号
				/// </summary>
				int SettlementID;

				/// <summary>
				/// 开仓成本
				/// </summary>
				double OpenCost;

				/// <summary>
				/// 交易所保证金
				/// </summary>
				double ExchangeMargin;

				/// <summary>
				/// 组合成交形成的持仓
				/// </summary>
				int CombPosition;

				/// <summary>
				/// 组合多头冻结
				/// </summary>
				int CombLongFrozen;

				/// <summary>
				/// 组合空头冻结
				/// </summary>
				int CombShortFrozen;

				/// <summary>
				/// 逐日盯市平仓盈亏
				/// </summary>
				double CloseProfitByDate;

				/// <summary>
				/// 逐笔对冲平仓盈亏
				/// </summary>
				double CloseProfitByTrade;

				/// <summary>
				/// 今日持仓
				/// </summary>
				int TodayPosition;

				/// <summary>
				/// 保证金率
				/// </summary>
				double MarginRateByMoney;

				/// <summary>
				/// 保证金率(按手数)
				/// </summary>
				double MarginRateByVolume;

				/// <summary>
				/// 执行冻结
				/// </summary>
				int StrikeFrozen;

				/// <summary>
				/// 执行冻结金额
				/// </summary>
				double StrikeFrozenAmount;

				/// <summary>
				/// 放弃执行冻结
				/// </summary>
				int AbandonFrozen;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 执行冻结的昨仓
				/// </summary>
				int YdStrikeFrozen;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;
			};

			/// <summary>
			/// 正在同步中的合约保证金率
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetSyncingInstrumentMarginRateField
			{
				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 投资者范围
				/// </summary>
				CtpNetInvestorRangeType InvestorRange;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 投机套保标志
				/// </summary>
				CtpNetHedgeFlagType HedgeFlag;

				/// <summary>
				/// 多头保证金率
				/// </summary>
				double LongMarginRatioByMoney;

				/// <summary>
				/// 多头保证金费
				/// </summary>
				double LongMarginRatioByVolume;

				/// <summary>
				/// 空头保证金率
				/// </summary>
				double ShortMarginRatioByMoney;

				/// <summary>
				/// 空头保证金费
				/// </summary>
				double ShortMarginRatioByVolume;

				/// <summary>
				/// 是否相对交易所收取
				/// </summary>
				int IsRelative;
			};

			/// <summary>
			/// 正在同步中的合约手续费率
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetSyncingInstrumentCommissionRateField
			{
				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 投资者范围
				/// </summary>
				CtpNetInvestorRangeType InvestorRange;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 开仓手续费率
				/// </summary>
				double OpenRatioByMoney;

				/// <summary>
				/// 开仓手续费
				/// </summary>
				double OpenRatioByVolume;

				/// <summary>
				/// 平仓手续费率
				/// </summary>
				double CloseRatioByMoney;

				/// <summary>
				/// 平仓手续费
				/// </summary>
				double CloseRatioByVolume;

				/// <summary>
				/// 平今手续费率
				/// </summary>
				double CloseTodayRatioByMoney;

				/// <summary>
				/// 平今手续费
				/// </summary>
				double CloseTodayRatioByVolume;
			};

			/// <summary>
			/// 正在同步中的合约交易权限
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetSyncingInstrumentTradingRightField
			{
				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 投资者范围
				/// </summary>
				CtpNetInvestorRangeType InvestorRange;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 交易权限
				/// </summary>
				CtpNetTradingRightType TradingRight;
			};

			/// <summary>
			/// 查询报单
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryOrderField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 报单编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ OrderSysID;

				/// <summary>
				/// 开始时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ InsertTimeStart;

				/// <summary>
				/// 结束时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ InsertTimeEnd;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;
			};

			/// <summary>
			/// 查询成交
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryTradeField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 成交编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TradeID;

				/// <summary>
				/// 开始时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeTimeStart;

				/// <summary>
				/// 结束时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeTimeEnd;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;
			};

			/// <summary>
			/// 查询投资者持仓
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryInvestorPositionField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;
			};

			/// <summary>
			/// 查询资金账户
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryTradingAccountField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// 业务类型
				/// </summary>
				CtpNetBizTypeType BizType;

				/// <summary>
				/// 投资者帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;
			};

			/// <summary>
			/// 查询投资者
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryInvestorField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;
			};

			/// <summary>
			/// 查询交易编码
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryTradingCodeField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 客户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// 交易编码类型
				/// </summary>
				CtpNetClientIDTypeType ClientIDType;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;
			};

			/// <summary>
			/// 查询投资者组
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryInvestorGroupField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;
			};

			/// <summary>
			/// 查询合约保证金率
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryInstrumentMarginRateField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 投机套保标志
				/// </summary>
				CtpNetHedgeFlagType HedgeFlag;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;
			};

			/// <summary>
			/// 查询手续费率
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryInstrumentCommissionRateField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;
			};

			/// <summary>
			/// 查询合约交易权限
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryInstrumentTradingRightField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;
			};

			/// <summary>
			/// 查询经纪公司
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryBrokerField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;
			};

			/// <summary>
			/// 查询交易员
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryTraderField
			{
				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;
			};

			/// <summary>
			/// 查询管理用户功能权限
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQrySuperUserFunctionField
			{
				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;
			};

			/// <summary>
			/// 查询用户会话
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryUserSessionField
			{
				/// <summary>
				/// 前置编号
				/// </summary>
				int FrontID;

				/// <summary>
				/// 会话编号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;
			};

			/// <summary>
			/// 查询经纪公司会员代码
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryPartBrokerField
			{
				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;
			};

			/// <summary>
			/// 查询前置状态
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryFrontStatusField
			{
				/// <summary>
				/// 前置编号
				/// </summary>
				int FrontID;
			};

			/// <summary>
			/// 查询交易所报单
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryExchangeOrderField
			{
				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 客户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// 合约在交易所的代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ ExchangeInstID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;
			};

			/// <summary>
			/// 查询报单操作
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryOrderActionField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;
			};

			/// <summary>
			/// 查询交易所报单操作
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryExchangeOrderActionField
			{
				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 客户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;
			};

			/// <summary>
			/// 查询管理用户
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQrySuperUserField
			{
				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;
			};

			/// <summary>
			/// 查询交易所
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryExchangeField
			{
				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;
			};

			/// <summary>
			/// 查询产品
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryProductField
			{
				/// <summary>
				/// 产品代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ ProductID;

				/// <summary>
				/// 产品类型
				/// </summary>
				CtpNetProductClassType ProductClass;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;
			};

			/// <summary>
			/// 查询合约
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryInstrumentField
			{
				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 合约在交易所的代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ ExchangeInstID;

				/// <summary>
				/// 产品代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ ProductID;
			};

			/// <summary>
			/// 查询行情
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryDepthMarketDataField
			{
				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;
			};

			/// <summary>
			/// 查询经纪公司用户
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryBrokerUserField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;
			};

			/// <summary>
			/// 查询经纪公司用户权限
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryBrokerUserFunctionField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;
			};

			/// <summary>
			/// 查询交易员报盘机
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryTraderOfferField
			{
				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;
			};

			/// <summary>
			/// 查询出入金流水
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQrySyncDepositField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 出入金流水号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
				String^ DepositSeqNo;
			};

			/// <summary>
			/// 查询投资者结算结果
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQrySettlementInfoField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 交易日
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 投资者帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;
			};

			/// <summary>
			/// 查询交易所保证金率
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryExchangeMarginRateField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 投机套保标志
				/// </summary>
				CtpNetHedgeFlagType HedgeFlag;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;
			};

			/// <summary>
			/// 查询交易所调整保证金率
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryExchangeMarginRateAdjustField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 投机套保标志
				/// </summary>
				CtpNetHedgeFlagType HedgeFlag;
			};

			/// <summary>
			/// 查询汇率
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryExchangeRateField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 源币种
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ FromCurrencyID;

				/// <summary>
				/// 目标币种
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ ToCurrencyID;
			};

			/// <summary>
			/// 查询货币质押流水
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQrySyncFundMortgageField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 货币质押流水号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
				String^ MortgageSeqNo;
			};

			/// <summary>
			/// 查询报单
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryHisOrderField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 报单编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ OrderSysID;

				/// <summary>
				/// 开始时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ InsertTimeStart;

				/// <summary>
				/// 结束时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ InsertTimeEnd;

				/// <summary>
				/// 交易日
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 结算编号
				/// </summary>
				int SettlementID;
			};

			/// <summary>
			/// 当前期权合约最小保证金
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetOptionInstrMiniMarginField
			{
				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 投资者范围
				/// </summary>
				CtpNetInvestorRangeType InvestorRange;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 单位（手）期权合约最小保证金
				/// </summary>
				double MinMargin;

				/// <summary>
				/// 取值方式
				/// </summary>
				CtpNetValueMethodType ValueMethod;

				/// <summary>
				/// 是否跟随交易所收取
				/// </summary>
				int IsRelative;
			};

			/// <summary>
			/// 当前期权合约保证金调整系数
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetOptionInstrMarginAdjustField
			{
				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 投资者范围
				/// </summary>
				CtpNetInvestorRangeType InvestorRange;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 投机空头保证金调整系数
				/// </summary>
				double SShortMarginRatioByMoney;

				/// <summary>
				/// 投机空头保证金调整系数
				/// </summary>
				double SShortMarginRatioByVolume;

				/// <summary>
				/// 保值空头保证金调整系数
				/// </summary>
				double HShortMarginRatioByMoney;

				/// <summary>
				/// 保值空头保证金调整系数
				/// </summary>
				double HShortMarginRatioByVolume;

				/// <summary>
				/// 套利空头保证金调整系数
				/// </summary>
				double AShortMarginRatioByMoney;

				/// <summary>
				/// 套利空头保证金调整系数
				/// </summary>
				double AShortMarginRatioByVolume;

				/// <summary>
				/// 是否跟随交易所收取
				/// </summary>
				int IsRelative;

				/// <summary>
				/// 做市商空头保证金调整系数
				/// </summary>
				double MShortMarginRatioByMoney;

				/// <summary>
				/// 做市商空头保证金调整系数
				/// </summary>
				double MShortMarginRatioByVolume;
			};

			/// <summary>
			/// 当前期权合约手续费的详细内容
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetOptionInstrCommRateField
			{
				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 投资者范围
				/// </summary>
				CtpNetInvestorRangeType InvestorRange;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 开仓手续费率
				/// </summary>
				double OpenRatioByMoney;

				/// <summary>
				/// 开仓手续费
				/// </summary>
				double OpenRatioByVolume;

				/// <summary>
				/// 平仓手续费率
				/// </summary>
				double CloseRatioByMoney;

				/// <summary>
				/// 平仓手续费
				/// </summary>
				double CloseRatioByVolume;

				/// <summary>
				/// 平今手续费率
				/// </summary>
				double CloseTodayRatioByMoney;

				/// <summary>
				/// 平今手续费
				/// </summary>
				double CloseTodayRatioByVolume;

				/// <summary>
				/// 执行手续费率
				/// </summary>
				double StrikeRatioByMoney;

				/// <summary>
				/// 执行手续费
				/// </summary>
				double StrikeRatioByVolume;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;
			};

			/// <summary>
			/// 期权交易成本
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetOptionInstrTradeCostField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 投机套保标志
				/// </summary>
				CtpNetHedgeFlagType HedgeFlag;

				/// <summary>
				/// 期权合约保证金不变部分
				/// </summary>
				double FixedMargin;

				/// <summary>
				/// 期权合约最小保证金
				/// </summary>
				double MiniMargin;

				/// <summary>
				/// 期权合约权利金
				/// </summary>
				double Royalty;

				/// <summary>
				/// 交易所期权合约保证金不变部分
				/// </summary>
				double ExchFixedMargin;

				/// <summary>
				/// 交易所期权合约最小保证金
				/// </summary>
				double ExchMiniMargin;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;
			};

			/// <summary>
			/// 期权交易成本查询
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryOptionInstrTradeCostField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 投机套保标志
				/// </summary>
				CtpNetHedgeFlagType HedgeFlag;

				/// <summary>
				/// 期权合约报价
				/// </summary>
				double InputPrice;

				/// <summary>
				/// 标的价格,填0则用昨结算价
				/// </summary>
				double UnderlyingPrice;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;
			};

			/// <summary>
			/// 期权手续费率查询
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryOptionInstrCommRateField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;
			};

			/// <summary>
			/// 股指现货指数
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetIndexPriceField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 指数现货收盘价
				/// </summary>
				double ClosePrice;
			};

			/// <summary>
			/// 输入的执行宣告
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetInputExecOrderField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 执行宣告引用
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ ExecOrderRef;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 数量
				/// </summary>
				int Volume;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 业务单元
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ BusinessUnit;

				/// <summary>
				/// 开平标志
				/// </summary>
				CtpNetOffsetFlagType OffsetFlag;

				/// <summary>
				/// 投机套保标志
				/// </summary>
				CtpNetHedgeFlagType HedgeFlag;

				/// <summary>
				/// 执行类型
				/// </summary>
				CtpNetActionTypeType ActionType;

				/// <summary>
				/// 保留头寸申请的持仓方向
				/// </summary>
				CtpNetPosiDirectionType PosiDirection;

				/// <summary>
				/// 期权行权后是否保留期货头寸的标记,该字段已废弃
				/// </summary>
				CtpNetExecOrderPositionFlagType ReservePositionFlag;

				/// <summary>
				/// 期权行权后生成的头寸是否自动平仓
				/// </summary>
				CtpNetExecOrderCloseFlagType CloseFlag;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;

				/// <summary>
				/// 资金账号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// 交易编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;
			};

			/// <summary>
			/// 输入执行宣告操作
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetInputExecOrderActionField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 执行宣告操作引用
				/// </summary>
				int ExecOrderActionRef;

				/// <summary>
				/// 执行宣告引用
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ ExecOrderRef;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 前置编号
				/// </summary>
				int FrontID;

				/// <summary>
				/// 会话编号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 执行宣告操作编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ ExecOrderSysID;

				/// <summary>
				/// 操作标志
				/// </summary>
				CtpNetActionFlagType ActionFlag;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;
			};

			/// <summary>
			/// 执行宣告
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetExecOrderField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 执行宣告引用
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ ExecOrderRef;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 数量
				/// </summary>
				int Volume;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 业务单元
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ BusinessUnit;

				/// <summary>
				/// 开平标志
				/// </summary>
				CtpNetOffsetFlagType OffsetFlag;

				/// <summary>
				/// 投机套保标志
				/// </summary>
				CtpNetHedgeFlagType HedgeFlag;

				/// <summary>
				/// 执行类型
				/// </summary>
				CtpNetActionTypeType ActionType;

				/// <summary>
				/// 保留头寸申请的持仓方向
				/// </summary>
				CtpNetPosiDirectionType PosiDirection;

				/// <summary>
				/// 期权行权后是否保留期货头寸的标记,该字段已废弃
				/// </summary>
				CtpNetExecOrderPositionFlagType ReservePositionFlag;

				/// <summary>
				/// 期权行权后生成的头寸是否自动平仓
				/// </summary>
				CtpNetExecOrderCloseFlagType CloseFlag;

				/// <summary>
				/// 本地执行宣告编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ ExecOrderLocalID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 客户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// 合约在交易所的代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ ExchangeInstID;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 执行宣告提交状态
				/// </summary>
				CtpNetOrderSubmitStatusType OrderSubmitStatus;

				/// <summary>
				/// 报单提示序号
				/// </summary>
				int NotifySequence;

				/// <summary>
				/// 交易日
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 结算编号
				/// </summary>
				int SettlementID;

				/// <summary>
				/// 执行宣告编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ ExecOrderSysID;

				/// <summary>
				/// 报单日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ InsertDate;

				/// <summary>
				/// 插入时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ InsertTime;

				/// <summary>
				/// 撤销时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ CancelTime;

				/// <summary>
				/// 执行结果
				/// </summary>
				CtpNetExecResultType ExecResult;

				/// <summary>
				/// 结算会员编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClearingPartID;

				/// <summary>
				/// 序号
				/// </summary>
				int SequenceNo;

				/// <summary>
				/// 前置编号
				/// </summary>
				int FrontID;

				/// <summary>
				/// 会话编号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 用户端产品信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ UserProductInfo;

				/// <summary>
				/// 状态信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ StatusMsg;

				/// <summary>
				/// 操作用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ ActiveUserID;

				/// <summary>
				/// 经纪公司报单编号
				/// </summary>
				int BrokerExecOrderSeq;

				/// <summary>
				/// 营业部编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ BranchID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;

				/// <summary>
				/// 资金账号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;
			};

			/// <summary>
			/// 执行宣告操作
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetExecOrderActionField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 执行宣告操作引用
				/// </summary>
				int ExecOrderActionRef;

				/// <summary>
				/// 执行宣告引用
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ ExecOrderRef;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 前置编号
				/// </summary>
				int FrontID;

				/// <summary>
				/// 会话编号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 执行宣告操作编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ ExecOrderSysID;

				/// <summary>
				/// 操作标志
				/// </summary>
				CtpNetActionFlagType ActionFlag;

				/// <summary>
				/// 操作日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ActionDate;

				/// <summary>
				/// 操作时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ActionTime;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 本地执行宣告编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ ExecOrderLocalID;

				/// <summary>
				/// 操作本地编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ ActionLocalID;

				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 客户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// 业务单元
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ BusinessUnit;

				/// <summary>
				/// 报单操作状态
				/// </summary>
				CtpNetOrderActionStatusType OrderActionStatus;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 执行类型
				/// </summary>
				CtpNetActionTypeType ActionType;

				/// <summary>
				/// 状态信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ StatusMsg;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 营业部编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ BranchID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;
			};

			/// <summary>
			/// 执行宣告查询
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryExecOrderField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 执行宣告编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ ExecOrderSysID;

				/// <summary>
				/// 开始时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ InsertTimeStart;

				/// <summary>
				/// 结束时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ InsertTimeEnd;
			};

			/// <summary>
			/// 交易所执行宣告信息
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetExchangeExecOrderField
			{
				/// <summary>
				/// 数量
				/// </summary>
				int Volume;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 业务单元
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ BusinessUnit;

				/// <summary>
				/// 开平标志
				/// </summary>
				CtpNetOffsetFlagType OffsetFlag;

				/// <summary>
				/// 投机套保标志
				/// </summary>
				CtpNetHedgeFlagType HedgeFlag;

				/// <summary>
				/// 执行类型
				/// </summary>
				CtpNetActionTypeType ActionType;

				/// <summary>
				/// 保留头寸申请的持仓方向
				/// </summary>
				CtpNetPosiDirectionType PosiDirection;

				/// <summary>
				/// 期权行权后是否保留期货头寸的标记,该字段已废弃
				/// </summary>
				CtpNetExecOrderPositionFlagType ReservePositionFlag;

				/// <summary>
				/// 期权行权后生成的头寸是否自动平仓
				/// </summary>
				CtpNetExecOrderCloseFlagType CloseFlag;

				/// <summary>
				/// 本地执行宣告编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ ExecOrderLocalID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 客户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// 合约在交易所的代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ ExchangeInstID;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 执行宣告提交状态
				/// </summary>
				CtpNetOrderSubmitStatusType OrderSubmitStatus;

				/// <summary>
				/// 报单提示序号
				/// </summary>
				int NotifySequence;

				/// <summary>
				/// 交易日
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 结算编号
				/// </summary>
				int SettlementID;

				/// <summary>
				/// 执行宣告编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ ExecOrderSysID;

				/// <summary>
				/// 报单日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ InsertDate;

				/// <summary>
				/// 插入时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ InsertTime;

				/// <summary>
				/// 撤销时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ CancelTime;

				/// <summary>
				/// 执行结果
				/// </summary>
				CtpNetExecResultType ExecResult;

				/// <summary>
				/// 结算会员编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClearingPartID;

				/// <summary>
				/// 序号
				/// </summary>
				int SequenceNo;

				/// <summary>
				/// 营业部编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ BranchID;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;
			};

			/// <summary>
			/// 交易所执行宣告查询
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryExchangeExecOrderField
			{
				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 客户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// 合约在交易所的代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ ExchangeInstID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;
			};

			/// <summary>
			/// 执行宣告操作查询
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryExecOrderActionField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;
			};

			/// <summary>
			/// 交易所执行宣告操作
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetExchangeExecOrderActionField
			{
				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 执行宣告操作编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ ExecOrderSysID;

				/// <summary>
				/// 操作标志
				/// </summary>
				CtpNetActionFlagType ActionFlag;

				/// <summary>
				/// 操作日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ActionDate;

				/// <summary>
				/// 操作时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ActionTime;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 本地执行宣告编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ ExecOrderLocalID;

				/// <summary>
				/// 操作本地编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ ActionLocalID;

				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 客户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// 业务单元
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ BusinessUnit;

				/// <summary>
				/// 报单操作状态
				/// </summary>
				CtpNetOrderActionStatusType OrderActionStatus;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 执行类型
				/// </summary>
				CtpNetActionTypeType ActionType;

				/// <summary>
				/// 营业部编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ BranchID;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;
			};

			/// <summary>
			/// 交易所执行宣告操作查询
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryExchangeExecOrderActionField
			{
				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 客户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;
			};

			/// <summary>
			/// 错误执行宣告
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetErrExecOrderField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 执行宣告引用
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ ExecOrderRef;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 数量
				/// </summary>
				int Volume;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 业务单元
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ BusinessUnit;

				/// <summary>
				/// 开平标志
				/// </summary>
				CtpNetOffsetFlagType OffsetFlag;

				/// <summary>
				/// 投机套保标志
				/// </summary>
				CtpNetHedgeFlagType HedgeFlag;

				/// <summary>
				/// 执行类型
				/// </summary>
				CtpNetActionTypeType ActionType;

				/// <summary>
				/// 保留头寸申请的持仓方向
				/// </summary>
				CtpNetPosiDirectionType PosiDirection;

				/// <summary>
				/// 期权行权后是否保留期货头寸的标记,该字段已废弃
				/// </summary>
				CtpNetExecOrderPositionFlagType ReservePositionFlag;

				/// <summary>
				/// 期权行权后生成的头寸是否自动平仓
				/// </summary>
				CtpNetExecOrderCloseFlagType CloseFlag;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;

				/// <summary>
				/// 资金账号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// 交易编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;

				/// <summary>
				/// 错误代码
				/// </summary>
				int ErrorID;

				/// <summary>
				/// 错误信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ ErrorMsg;
			};

			/// <summary>
			/// 查询错误执行宣告
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryErrExecOrderField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;
			};

			/// <summary>
			/// 错误执行宣告操作
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetErrExecOrderActionField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 执行宣告操作引用
				/// </summary>
				int ExecOrderActionRef;

				/// <summary>
				/// 执行宣告引用
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ ExecOrderRef;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 前置编号
				/// </summary>
				int FrontID;

				/// <summary>
				/// 会话编号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 执行宣告操作编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ ExecOrderSysID;

				/// <summary>
				/// 操作标志
				/// </summary>
				CtpNetActionFlagType ActionFlag;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;

				/// <summary>
				/// 错误代码
				/// </summary>
				int ErrorID;

				/// <summary>
				/// 错误信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ ErrorMsg;
			};

			/// <summary>
			/// 查询错误执行宣告操作
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryErrExecOrderActionField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;
			};

			/// <summary>
			/// 投资者期权合约交易权限
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetOptionInstrTradingRightField
			{
				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 投资者范围
				/// </summary>
				CtpNetInvestorRangeType InvestorRange;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 买卖方向
				/// </summary>
				CtpNetDirectionType Direction;

				/// <summary>
				/// 交易权限
				/// </summary>
				CtpNetTradingRightType TradingRight;
			};

			/// <summary>
			/// 查询期权合约交易权限
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryOptionInstrTradingRightField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 买卖方向
				/// </summary>
				CtpNetDirectionType Direction;
			};

			/// <summary>
			/// 输入的询价
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetInputForQuoteField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 询价引用
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ ForQuoteRef;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;
			};

			/// <summary>
			/// 询价
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetForQuoteField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 询价引用
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ ForQuoteRef;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 本地询价编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ ForQuoteLocalID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 客户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// 合约在交易所的代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ ExchangeInstID;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 报单日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ InsertDate;

				/// <summary>
				/// 插入时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ InsertTime;

				/// <summary>
				/// 询价状态
				/// </summary>
				CtpNetForQuoteStatusType ForQuoteStatus;

				/// <summary>
				/// 前置编号
				/// </summary>
				int FrontID;

				/// <summary>
				/// 会话编号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 状态信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ StatusMsg;

				/// <summary>
				/// 操作用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ ActiveUserID;

				/// <summary>
				/// 经纪公司询价编号
				/// </summary>
				int BrokerForQutoSeq;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;
			};

			/// <summary>
			/// 询价查询
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryForQuoteField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 开始时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ InsertTimeStart;

				/// <summary>
				/// 结束时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ InsertTimeEnd;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;
			};

			/// <summary>
			/// 交易所询价信息
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetExchangeForQuoteField
			{
				/// <summary>
				/// 本地询价编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ ForQuoteLocalID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 客户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// 合约在交易所的代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ ExchangeInstID;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 报单日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ InsertDate;

				/// <summary>
				/// 插入时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ InsertTime;

				/// <summary>
				/// 询价状态
				/// </summary>
				CtpNetForQuoteStatusType ForQuoteStatus;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;
			};

			/// <summary>
			/// 交易所询价查询
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryExchangeForQuoteField
			{
				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 客户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// 合约在交易所的代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ ExchangeInstID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;
			};

			/// <summary>
			/// 输入的报价
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetInputQuoteField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 报价引用
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ QuoteRef;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 卖价格
				/// </summary>
				double AskPrice;

				/// <summary>
				/// 买价格
				/// </summary>
				double BidPrice;

				/// <summary>
				/// 卖数量
				/// </summary>
				int AskVolume;

				/// <summary>
				/// 买数量
				/// </summary>
				int BidVolume;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 业务单元
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ BusinessUnit;

				/// <summary>
				/// 卖开平标志
				/// </summary>
				CtpNetOffsetFlagType AskOffsetFlag;

				/// <summary>
				/// 买开平标志
				/// </summary>
				CtpNetOffsetFlagType BidOffsetFlag;

				/// <summary>
				/// 卖投机套保标志
				/// </summary>
				CtpNetHedgeFlagType AskHedgeFlag;

				/// <summary>
				/// 买投机套保标志
				/// </summary>
				CtpNetHedgeFlagType BidHedgeFlag;

				/// <summary>
				/// 衍生卖报单引用
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AskOrderRef;

				/// <summary>
				/// 衍生买报单引用
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ BidOrderRef;

				/// <summary>
				/// 应价编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ ForQuoteSysID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;

				/// <summary>
				/// 交易编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;
			};

			/// <summary>
			/// 输入报价操作
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetInputQuoteActionField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 报价操作引用
				/// </summary>
				int QuoteActionRef;

				/// <summary>
				/// 报价引用
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ QuoteRef;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 前置编号
				/// </summary>
				int FrontID;

				/// <summary>
				/// 会话编号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 报价操作编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ QuoteSysID;

				/// <summary>
				/// 操作标志
				/// </summary>
				CtpNetActionFlagType ActionFlag;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;

				/// <summary>
				/// 交易编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;
			};

			/// <summary>
			/// 报价
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQuoteField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 报价引用
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ QuoteRef;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 卖价格
				/// </summary>
				double AskPrice;

				/// <summary>
				/// 买价格
				/// </summary>
				double BidPrice;

				/// <summary>
				/// 卖数量
				/// </summary>
				int AskVolume;

				/// <summary>
				/// 买数量
				/// </summary>
				int BidVolume;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 业务单元
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ BusinessUnit;

				/// <summary>
				/// 卖开平标志
				/// </summary>
				CtpNetOffsetFlagType AskOffsetFlag;

				/// <summary>
				/// 买开平标志
				/// </summary>
				CtpNetOffsetFlagType BidOffsetFlag;

				/// <summary>
				/// 卖投机套保标志
				/// </summary>
				CtpNetHedgeFlagType AskHedgeFlag;

				/// <summary>
				/// 买投机套保标志
				/// </summary>
				CtpNetHedgeFlagType BidHedgeFlag;

				/// <summary>
				/// 本地报价编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ QuoteLocalID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 客户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// 合约在交易所的代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ ExchangeInstID;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 报价提示序号
				/// </summary>
				int NotifySequence;

				/// <summary>
				/// 报价提交状态
				/// </summary>
				CtpNetOrderSubmitStatusType OrderSubmitStatus;

				/// <summary>
				/// 交易日
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 结算编号
				/// </summary>
				int SettlementID;

				/// <summary>
				/// 报价编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ QuoteSysID;

				/// <summary>
				/// 报单日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ InsertDate;

				/// <summary>
				/// 插入时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ InsertTime;

				/// <summary>
				/// 撤销时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ CancelTime;

				/// <summary>
				/// 报价状态
				/// </summary>
				CtpNetOrderStatusType QuoteStatus;

				/// <summary>
				/// 结算会员编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClearingPartID;

				/// <summary>
				/// 序号
				/// </summary>
				int SequenceNo;

				/// <summary>
				/// 卖方报单编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ AskOrderSysID;

				/// <summary>
				/// 买方报单编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ BidOrderSysID;

				/// <summary>
				/// 前置编号
				/// </summary>
				int FrontID;

				/// <summary>
				/// 会话编号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 用户端产品信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ UserProductInfo;

				/// <summary>
				/// 状态信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ StatusMsg;

				/// <summary>
				/// 操作用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ ActiveUserID;

				/// <summary>
				/// 经纪公司报价编号
				/// </summary>
				int BrokerQuoteSeq;

				/// <summary>
				/// 衍生卖报单引用
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AskOrderRef;

				/// <summary>
				/// 衍生买报单引用
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ BidOrderRef;

				/// <summary>
				/// 应价编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ ForQuoteSysID;

				/// <summary>
				/// 营业部编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ BranchID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;

				/// <summary>
				/// 资金账号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;
			};

			/// <summary>
			/// 报价操作
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQuoteActionField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 报价操作引用
				/// </summary>
				int QuoteActionRef;

				/// <summary>
				/// 报价引用
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ QuoteRef;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 前置编号
				/// </summary>
				int FrontID;

				/// <summary>
				/// 会话编号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 报价操作编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ QuoteSysID;

				/// <summary>
				/// 操作标志
				/// </summary>
				CtpNetActionFlagType ActionFlag;

				/// <summary>
				/// 操作日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ActionDate;

				/// <summary>
				/// 操作时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ActionTime;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 本地报价编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ QuoteLocalID;

				/// <summary>
				/// 操作本地编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ ActionLocalID;

				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 客户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// 业务单元
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ BusinessUnit;

				/// <summary>
				/// 报单操作状态
				/// </summary>
				CtpNetOrderActionStatusType OrderActionStatus;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 状态信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ StatusMsg;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 营业部编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ BranchID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;
			};

			/// <summary>
			/// 报价查询
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryQuoteField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 报价编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ QuoteSysID;

				/// <summary>
				/// 开始时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ InsertTimeStart;

				/// <summary>
				/// 结束时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ InsertTimeEnd;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;
			};

			/// <summary>
			/// 交易所报价信息
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetExchangeQuoteField
			{
				/// <summary>
				/// 卖价格
				/// </summary>
				double AskPrice;

				/// <summary>
				/// 买价格
				/// </summary>
				double BidPrice;

				/// <summary>
				/// 卖数量
				/// </summary>
				int AskVolume;

				/// <summary>
				/// 买数量
				/// </summary>
				int BidVolume;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 业务单元
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ BusinessUnit;

				/// <summary>
				/// 卖开平标志
				/// </summary>
				CtpNetOffsetFlagType AskOffsetFlag;

				/// <summary>
				/// 买开平标志
				/// </summary>
				CtpNetOffsetFlagType BidOffsetFlag;

				/// <summary>
				/// 卖投机套保标志
				/// </summary>
				CtpNetHedgeFlagType AskHedgeFlag;

				/// <summary>
				/// 买投机套保标志
				/// </summary>
				CtpNetHedgeFlagType BidHedgeFlag;

				/// <summary>
				/// 本地报价编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ QuoteLocalID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 客户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// 合约在交易所的代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ ExchangeInstID;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 报价提示序号
				/// </summary>
				int NotifySequence;

				/// <summary>
				/// 报价提交状态
				/// </summary>
				CtpNetOrderSubmitStatusType OrderSubmitStatus;

				/// <summary>
				/// 交易日
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 结算编号
				/// </summary>
				int SettlementID;

				/// <summary>
				/// 报价编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ QuoteSysID;

				/// <summary>
				/// 报单日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ InsertDate;

				/// <summary>
				/// 插入时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ InsertTime;

				/// <summary>
				/// 撤销时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ CancelTime;

				/// <summary>
				/// 报价状态
				/// </summary>
				CtpNetOrderStatusType QuoteStatus;

				/// <summary>
				/// 结算会员编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClearingPartID;

				/// <summary>
				/// 序号
				/// </summary>
				int SequenceNo;

				/// <summary>
				/// 卖方报单编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ AskOrderSysID;

				/// <summary>
				/// 买方报单编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ BidOrderSysID;

				/// <summary>
				/// 应价编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ ForQuoteSysID;

				/// <summary>
				/// 营业部编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ BranchID;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;
			};

			/// <summary>
			/// 交易所报价查询
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryExchangeQuoteField
			{
				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 客户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// 合约在交易所的代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ ExchangeInstID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;
			};

			/// <summary>
			/// 报价操作查询
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryQuoteActionField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;
			};

			/// <summary>
			/// 交易所报价操作
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetExchangeQuoteActionField
			{
				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 报价操作编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ QuoteSysID;

				/// <summary>
				/// 操作标志
				/// </summary>
				CtpNetActionFlagType ActionFlag;

				/// <summary>
				/// 操作日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ActionDate;

				/// <summary>
				/// 操作时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ActionTime;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 本地报价编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ QuoteLocalID;

				/// <summary>
				/// 操作本地编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ ActionLocalID;

				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 客户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// 业务单元
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ BusinessUnit;

				/// <summary>
				/// 报单操作状态
				/// </summary>
				CtpNetOrderActionStatusType OrderActionStatus;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;
			};

			/// <summary>
			/// 交易所报价操作查询
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryExchangeQuoteActionField
			{
				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 客户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;
			};

			/// <summary>
			/// 期权合约delta值
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetOptionInstrDeltaField
			{
				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 投资者范围
				/// </summary>
				CtpNetInvestorRangeType InvestorRange;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// Delta值
				/// </summary>
				double Delta;
			};

			/// <summary>
			/// 发给做市商的询价请求
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetForQuoteRspField
			{
				/// <summary>
				/// 交易日
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 询价编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ ForQuoteSysID;

				/// <summary>
				/// 询价时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ForQuoteTime;

				/// <summary>
				/// 业务日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ActionDay;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;
			};

			/// <summary>
			/// 当前期权合约执行偏移值的详细内容
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetStrikeOffsetField
			{
				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 投资者范围
				/// </summary>
				CtpNetInvestorRangeType InvestorRange;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 执行偏移值
				/// </summary>
				double Offset;

				/// <summary>
				/// 执行偏移类型
				/// </summary>
				CtpNetStrikeOffsetTypeType OffsetType;
			};

			/// <summary>
			/// 期权执行偏移值查询
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryStrikeOffsetField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;
			};

			/// <summary>
			/// 输入批量报单操作
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetInputBatchOrderActionField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 报单操作引用
				/// </summary>
				int OrderActionRef;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 前置编号
				/// </summary>
				int FrontID;

				/// <summary>
				/// 会话编号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;
			};

			/// <summary>
			/// 批量报单操作
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetBatchOrderActionField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 报单操作引用
				/// </summary>
				int OrderActionRef;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 前置编号
				/// </summary>
				int FrontID;

				/// <summary>
				/// 会话编号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 操作日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ActionDate;

				/// <summary>
				/// 操作时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ActionTime;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 操作本地编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ ActionLocalID;

				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 客户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// 业务单元
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ BusinessUnit;

				/// <summary>
				/// 报单操作状态
				/// </summary>
				CtpNetOrderActionStatusType OrderActionStatus;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 状态信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ StatusMsg;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;
			};

			/// <summary>
			/// 交易所批量报单操作
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetExchangeBatchOrderActionField
			{
				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 操作日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ActionDate;

				/// <summary>
				/// 操作时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ActionTime;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 操作本地编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ ActionLocalID;

				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 客户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// 业务单元
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ BusinessUnit;

				/// <summary>
				/// 报单操作状态
				/// </summary>
				CtpNetOrderActionStatusType OrderActionStatus;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;
			};

			/// <summary>
			/// 查询批量报单操作
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryBatchOrderActionField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;
			};

			/// <summary>
			/// 组合合约安全系数
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetCombInstrumentGuardField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 
				/// </summary>
				double GuarantRatio;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;
			};

			/// <summary>
			/// 组合合约安全系数查询
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryCombInstrumentGuardField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;
			};

			/// <summary>
			/// 输入的申请组合
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetInputCombActionField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 组合引用
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ CombActionRef;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 买卖方向
				/// </summary>
				CtpNetDirectionType Direction;

				/// <summary>
				/// 数量
				/// </summary>
				int Volume;

				/// <summary>
				/// 组合指令方向
				/// </summary>
				CtpNetCombDirectionType CombDirection;

				/// <summary>
				/// 投机套保标志
				/// </summary>
				CtpNetHedgeFlagType HedgeFlag;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;
			};

			/// <summary>
			/// 申请组合
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetCombActionField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 组合引用
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ CombActionRef;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 买卖方向
				/// </summary>
				CtpNetDirectionType Direction;

				/// <summary>
				/// 数量
				/// </summary>
				int Volume;

				/// <summary>
				/// 组合指令方向
				/// </summary>
				CtpNetCombDirectionType CombDirection;

				/// <summary>
				/// 投机套保标志
				/// </summary>
				CtpNetHedgeFlagType HedgeFlag;

				/// <summary>
				/// 本地申请组合编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ ActionLocalID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 客户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// 合约在交易所的代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ ExchangeInstID;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 组合状态
				/// </summary>
				CtpNetOrderActionStatusType ActionStatus;

				/// <summary>
				/// 报单提示序号
				/// </summary>
				int NotifySequence;

				/// <summary>
				/// 交易日
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 结算编号
				/// </summary>
				int SettlementID;

				/// <summary>
				/// 序号
				/// </summary>
				int SequenceNo;

				/// <summary>
				/// 前置编号
				/// </summary>
				int FrontID;

				/// <summary>
				/// 会话编号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 用户端产品信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ UserProductInfo;

				/// <summary>
				/// 状态信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ StatusMsg;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;

				/// <summary>
				/// 组合编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ ComTradeID;

				/// <summary>
				/// 营业部编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ BranchID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;
			};

			/// <summary>
			/// 申请组合查询
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryCombActionField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;
			};

			/// <summary>
			/// 交易所申请组合信息
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetExchangeCombActionField
			{
				/// <summary>
				/// 买卖方向
				/// </summary>
				CtpNetDirectionType Direction;

				/// <summary>
				/// 数量
				/// </summary>
				int Volume;

				/// <summary>
				/// 组合指令方向
				/// </summary>
				CtpNetCombDirectionType CombDirection;

				/// <summary>
				/// 投机套保标志
				/// </summary>
				CtpNetHedgeFlagType HedgeFlag;

				/// <summary>
				/// 本地申请组合编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ ActionLocalID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 客户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// 合约在交易所的代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ ExchangeInstID;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 组合状态
				/// </summary>
				CtpNetOrderActionStatusType ActionStatus;

				/// <summary>
				/// 报单提示序号
				/// </summary>
				int NotifySequence;

				/// <summary>
				/// 交易日
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 结算编号
				/// </summary>
				int SettlementID;

				/// <summary>
				/// 序号
				/// </summary>
				int SequenceNo;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;

				/// <summary>
				/// 组合编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ ComTradeID;

				/// <summary>
				/// 营业部编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ BranchID;
			};

			/// <summary>
			/// 交易所申请组合查询
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryExchangeCombActionField
			{
				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 客户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// 合约在交易所的代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ ExchangeInstID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;
			};

			/// <summary>
			/// 产品报价汇率
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetProductExchRateField
			{
				/// <summary>
				/// 产品代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ ProductID;

				/// <summary>
				/// 报价币种类型
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ QuoteCurrencyID;

				/// <summary>
				/// 汇率
				/// </summary>
				double ExchangeRate;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;
			};

			/// <summary>
			/// 产品报价汇率查询
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryProductExchRateField
			{
				/// <summary>
				/// 产品代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ ProductID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;
			};

			/// <summary>
			/// 查询询价价差参数
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryForQuoteParamField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;
			};

			/// <summary>
			/// 询价价差参数
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetForQuoteParamField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 最新价
				/// </summary>
				double LastPrice;

				/// <summary>
				/// 价差
				/// </summary>
				double PriceInterval;
			};

			/// <summary>
			/// 当前做市商期权合约手续费的详细内容
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetMMOptionInstrCommRateField
			{
				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 投资者范围
				/// </summary>
				CtpNetInvestorRangeType InvestorRange;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 开仓手续费率
				/// </summary>
				double OpenRatioByMoney;

				/// <summary>
				/// 开仓手续费
				/// </summary>
				double OpenRatioByVolume;

				/// <summary>
				/// 平仓手续费率
				/// </summary>
				double CloseRatioByMoney;

				/// <summary>
				/// 平仓手续费
				/// </summary>
				double CloseRatioByVolume;

				/// <summary>
				/// 平今手续费率
				/// </summary>
				double CloseTodayRatioByMoney;

				/// <summary>
				/// 平今手续费
				/// </summary>
				double CloseTodayRatioByVolume;

				/// <summary>
				/// 执行手续费率
				/// </summary>
				double StrikeRatioByMoney;

				/// <summary>
				/// 执行手续费
				/// </summary>
				double StrikeRatioByVolume;
			};

			/// <summary>
			/// 做市商期权手续费率查询
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryMMOptionInstrCommRateField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;
			};

			/// <summary>
			/// 做市商合约手续费率
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetMMInstrumentCommissionRateField
			{
				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 投资者范围
				/// </summary>
				CtpNetInvestorRangeType InvestorRange;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 开仓手续费率
				/// </summary>
				double OpenRatioByMoney;

				/// <summary>
				/// 开仓手续费
				/// </summary>
				double OpenRatioByVolume;

				/// <summary>
				/// 平仓手续费率
				/// </summary>
				double CloseRatioByMoney;

				/// <summary>
				/// 平仓手续费
				/// </summary>
				double CloseRatioByVolume;

				/// <summary>
				/// 平今手续费率
				/// </summary>
				double CloseTodayRatioByMoney;

				/// <summary>
				/// 平今手续费
				/// </summary>
				double CloseTodayRatioByVolume;
			};

			/// <summary>
			/// 查询做市商合约手续费率
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryMMInstrumentCommissionRateField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;
			};

			/// <summary>
			/// 当前报单手续费的详细内容
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetInstrumentOrderCommRateField
			{
				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 投资者范围
				/// </summary>
				CtpNetInvestorRangeType InvestorRange;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 投机套保标志
				/// </summary>
				CtpNetHedgeFlagType HedgeFlag;

				/// <summary>
				/// 报单手续费
				/// </summary>
				double OrderCommByVolume;

				/// <summary>
				/// 撤单手续费
				/// </summary>
				double OrderActionCommByVolume;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;
			};

			/// <summary>
			/// 报单手续费率查询
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryInstrumentOrderCommRateField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;
			};

			/// <summary>
			/// 交易参数
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetTradeParamField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 参数代码
				/// </summary>
				CtpNetTradeParamIDType TradeParamID;

				/// <summary>
				/// 参数代码值
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 256)]
				String^ TradeParamValue;

				/// <summary>
				/// 备注
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 161)]
				String^ Memo;
			};

			/// <summary>
			/// 合约保证金率调整
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetInstrumentMarginRateULField
			{
				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 投资者范围
				/// </summary>
				CtpNetInvestorRangeType InvestorRange;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 投机套保标志
				/// </summary>
				CtpNetHedgeFlagType HedgeFlag;

				/// <summary>
				/// 多头保证金率
				/// </summary>
				double LongMarginRatioByMoney;

				/// <summary>
				/// 多头保证金费
				/// </summary>
				double LongMarginRatioByVolume;

				/// <summary>
				/// 空头保证金率
				/// </summary>
				double ShortMarginRatioByMoney;

				/// <summary>
				/// 空头保证金费
				/// </summary>
				double ShortMarginRatioByVolume;
			};

			/// <summary>
			/// 期货持仓限制参数
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetFutureLimitPosiParamField
			{
				/// <summary>
				/// 投资者范围
				/// </summary>
				CtpNetInvestorRangeType InvestorRange;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 产品代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ ProductID;

				/// <summary>
				/// 当日投机开仓数量限制
				/// </summary>
				int SpecOpenVolume;

				/// <summary>
				/// 当日套利开仓数量限制
				/// </summary>
				int ArbiOpenVolume;

				/// <summary>
				/// 当日投机+套利开仓数量限制
				/// </summary>
				int OpenVolume;
			};

			/// <summary>
			/// 禁止登录IP
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetLoginForbiddenIPField
			{
				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;
			};

			/// <summary>
			/// IP列表
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetIPListField
			{
				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// 是否白名单
				/// </summary>
				int IsWhite;
			};

			/// <summary>
			/// 输入的期权自对冲
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetInputOptionSelfCloseField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 期权自对冲引用
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ OptionSelfCloseRef;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 数量
				/// </summary>
				int Volume;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 业务单元
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ BusinessUnit;

				/// <summary>
				/// 投机套保标志
				/// </summary>
				CtpNetHedgeFlagType HedgeFlag;

				/// <summary>
				/// 期权行权的头寸是否自对冲
				/// </summary>
				CtpNetOptSelfCloseFlagType OptSelfCloseFlag;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;

				/// <summary>
				/// 资金账号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// 交易编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;
			};

			/// <summary>
			/// 输入期权自对冲操作
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetInputOptionSelfCloseActionField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 期权自对冲操作引用
				/// </summary>
				int OptionSelfCloseActionRef;

				/// <summary>
				/// 期权自对冲引用
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ OptionSelfCloseRef;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 前置编号
				/// </summary>
				int FrontID;

				/// <summary>
				/// 会话编号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 期权自对冲操作编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ OptionSelfCloseSysID;

				/// <summary>
				/// 操作标志
				/// </summary>
				CtpNetActionFlagType ActionFlag;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;
			};

			/// <summary>
			/// 期权自对冲
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetOptionSelfCloseField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 期权自对冲引用
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ OptionSelfCloseRef;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 数量
				/// </summary>
				int Volume;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 业务单元
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ BusinessUnit;

				/// <summary>
				/// 投机套保标志
				/// </summary>
				CtpNetHedgeFlagType HedgeFlag;

				/// <summary>
				/// 期权行权的头寸是否自对冲
				/// </summary>
				CtpNetOptSelfCloseFlagType OptSelfCloseFlag;

				/// <summary>
				/// 本地期权自对冲编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ OptionSelfCloseLocalID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 客户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// 合约在交易所的代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ ExchangeInstID;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 期权自对冲提交状态
				/// </summary>
				CtpNetOrderSubmitStatusType OrderSubmitStatus;

				/// <summary>
				/// 报单提示序号
				/// </summary>
				int NotifySequence;

				/// <summary>
				/// 交易日
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 结算编号
				/// </summary>
				int SettlementID;

				/// <summary>
				/// 期权自对冲编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ OptionSelfCloseSysID;

				/// <summary>
				/// 报单日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ InsertDate;

				/// <summary>
				/// 插入时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ InsertTime;

				/// <summary>
				/// 撤销时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ CancelTime;

				/// <summary>
				/// 自对冲结果
				/// </summary>
				CtpNetExecResultType ExecResult;

				/// <summary>
				/// 结算会员编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClearingPartID;

				/// <summary>
				/// 序号
				/// </summary>
				int SequenceNo;

				/// <summary>
				/// 前置编号
				/// </summary>
				int FrontID;

				/// <summary>
				/// 会话编号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 用户端产品信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ UserProductInfo;

				/// <summary>
				/// 状态信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ StatusMsg;

				/// <summary>
				/// 操作用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ ActiveUserID;

				/// <summary>
				/// 经纪公司报单编号
				/// </summary>
				int BrokerOptionSelfCloseSeq;

				/// <summary>
				/// 营业部编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ BranchID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;

				/// <summary>
				/// 资金账号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;
			};

			/// <summary>
			/// 期权自对冲操作
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetOptionSelfCloseActionField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 期权自对冲操作引用
				/// </summary>
				int OptionSelfCloseActionRef;

				/// <summary>
				/// 期权自对冲引用
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ OptionSelfCloseRef;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 前置编号
				/// </summary>
				int FrontID;

				/// <summary>
				/// 会话编号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 期权自对冲操作编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ OptionSelfCloseSysID;

				/// <summary>
				/// 操作标志
				/// </summary>
				CtpNetActionFlagType ActionFlag;

				/// <summary>
				/// 操作日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ActionDate;

				/// <summary>
				/// 操作时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ActionTime;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 本地期权自对冲编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ OptionSelfCloseLocalID;

				/// <summary>
				/// 操作本地编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ ActionLocalID;

				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 客户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// 业务单元
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ BusinessUnit;

				/// <summary>
				/// 报单操作状态
				/// </summary>
				CtpNetOrderActionStatusType OrderActionStatus;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 状态信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ StatusMsg;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 营业部编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ BranchID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;
			};

			/// <summary>
			/// 期权自对冲查询
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryOptionSelfCloseField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 期权自对冲编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ OptionSelfCloseSysID;

				/// <summary>
				/// 开始时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ InsertTimeStart;

				/// <summary>
				/// 结束时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ InsertTimeEnd;
			};

			/// <summary>
			/// 交易所期权自对冲信息
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetExchangeOptionSelfCloseField
			{
				/// <summary>
				/// 数量
				/// </summary>
				int Volume;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 业务单元
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ BusinessUnit;

				/// <summary>
				/// 投机套保标志
				/// </summary>
				CtpNetHedgeFlagType HedgeFlag;

				/// <summary>
				/// 期权行权的头寸是否自对冲
				/// </summary>
				CtpNetOptSelfCloseFlagType OptSelfCloseFlag;

				/// <summary>
				/// 本地期权自对冲编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ OptionSelfCloseLocalID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 客户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// 合约在交易所的代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ ExchangeInstID;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 期权自对冲提交状态
				/// </summary>
				CtpNetOrderSubmitStatusType OrderSubmitStatus;

				/// <summary>
				/// 报单提示序号
				/// </summary>
				int NotifySequence;

				/// <summary>
				/// 交易日
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 结算编号
				/// </summary>
				int SettlementID;

				/// <summary>
				/// 期权自对冲编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ OptionSelfCloseSysID;

				/// <summary>
				/// 报单日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ InsertDate;

				/// <summary>
				/// 插入时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ InsertTime;

				/// <summary>
				/// 撤销时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ CancelTime;

				/// <summary>
				/// 自对冲结果
				/// </summary>
				CtpNetExecResultType ExecResult;

				/// <summary>
				/// 结算会员编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClearingPartID;

				/// <summary>
				/// 序号
				/// </summary>
				int SequenceNo;

				/// <summary>
				/// 营业部编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ BranchID;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;
			};

			/// <summary>
			/// 期权自对冲操作查询
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryOptionSelfCloseActionField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;
			};

			/// <summary>
			/// 交易所期权自对冲操作
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetExchangeOptionSelfCloseActionField
			{
				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 期权自对冲操作编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ OptionSelfCloseSysID;

				/// <summary>
				/// 操作标志
				/// </summary>
				CtpNetActionFlagType ActionFlag;

				/// <summary>
				/// 操作日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ActionDate;

				/// <summary>
				/// 操作时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ActionTime;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 本地期权自对冲编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ OptionSelfCloseLocalID;

				/// <summary>
				/// 操作本地编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ ActionLocalID;

				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 客户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// 业务单元
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ BusinessUnit;

				/// <summary>
				/// 报单操作状态
				/// </summary>
				CtpNetOrderActionStatusType OrderActionStatus;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 营业部编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ BranchID;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;
			};

			/// <summary>
			/// 延时换汇同步
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetSyncDelaySwapField
			{
				/// <summary>
				/// 换汇流水号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
				String^ DelaySwapSeqNo;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 源币种
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ FromCurrencyID;

				/// <summary>
				/// 源金额
				/// </summary>
				double FromAmount;

				/// <summary>
				/// 源换汇冻结金额(可用冻结)
				/// </summary>
				double FromFrozenSwap;

				/// <summary>
				/// 源剩余换汇额度(可提冻结)
				/// </summary>
				double FromRemainSwap;

				/// <summary>
				/// 目标币种
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ ToCurrencyID;

				/// <summary>
				/// 目标金额
				/// </summary>
				double ToAmount;
			};

			/// <summary>
			/// 查询延时换汇同步
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQrySyncDelaySwapField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 延时换汇流水号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
				String^ DelaySwapSeqNo;
			};

			/// <summary>
			/// 投资单元
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetInvestUnitField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;

				/// <summary>
				/// 投资者单元名称
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ InvestorUnitName;

				/// <summary>
				/// 投资者分组代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorGroupID;

				/// <summary>
				/// 手续费率模板代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ CommModelID;

				/// <summary>
				/// 保证金率模板代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ MarginModelID;

				/// <summary>
				/// 资金账号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;
			};

			/// <summary>
			/// 查询投资单元
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryInvestUnitField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;
			};

			/// <summary>
			/// 二级代理商资金校验模式
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetSecAgentCheckModeField
			{
				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 币种
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// 境外中介机构资金帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ BrokerSecAgentID;

				/// <summary>
				/// 是否需要校验自己的资金账户
				/// </summary>
				int CheckSelfAccount;
			};

			/// <summary>
			/// 市场行情
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetMarketDataField
			{
				/// <summary>
				/// 交易日
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 合约在交易所的代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ ExchangeInstID;

				/// <summary>
				/// 最新价
				/// </summary>
				double LastPrice;

				/// <summary>
				/// 上次结算价
				/// </summary>
				double PreSettlementPrice;

				/// <summary>
				/// 昨收盘
				/// </summary>
				double PreClosePrice;

				/// <summary>
				/// 昨持仓量
				/// </summary>
				double PreOpenInterest;

				/// <summary>
				/// 今开盘
				/// </summary>
				double OpenPrice;

				/// <summary>
				/// 最高价
				/// </summary>
				double HighestPrice;

				/// <summary>
				/// 最低价
				/// </summary>
				double LowestPrice;

				/// <summary>
				/// 数量
				/// </summary>
				int Volume;

				/// <summary>
				/// 成交金额
				/// </summary>
				double Turnover;

				/// <summary>
				/// 持仓量
				/// </summary>
				double OpenInterest;

				/// <summary>
				/// 今收盘
				/// </summary>
				double ClosePrice;

				/// <summary>
				/// 本次结算价
				/// </summary>
				double SettlementPrice;

				/// <summary>
				/// 涨停板价
				/// </summary>
				double UpperLimitPrice;

				/// <summary>
				/// 跌停板价
				/// </summary>
				double LowerLimitPrice;

				/// <summary>
				/// 昨虚实度
				/// </summary>
				double PreDelta;

				/// <summary>
				/// 今虚实度
				/// </summary>
				double CurrDelta;

				/// <summary>
				/// 最后修改时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ UpdateTime;

				/// <summary>
				/// 最后修改毫秒
				/// </summary>
				int UpdateMillisec;

				/// <summary>
				/// 业务日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ActionDay;
			};

			/// <summary>
			/// 行情基础属性
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetMarketDataBaseField
			{
				/// <summary>
				/// 交易日
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 上次结算价
				/// </summary>
				double PreSettlementPrice;

				/// <summary>
				/// 昨收盘
				/// </summary>
				double PreClosePrice;

				/// <summary>
				/// 昨持仓量
				/// </summary>
				double PreOpenInterest;

				/// <summary>
				/// 昨虚实度
				/// </summary>
				double PreDelta;
			};

			/// <summary>
			/// 行情静态属性
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetMarketDataStaticField
			{
				/// <summary>
				/// 今开盘
				/// </summary>
				double OpenPrice;

				/// <summary>
				/// 最高价
				/// </summary>
				double HighestPrice;

				/// <summary>
				/// 最低价
				/// </summary>
				double LowestPrice;

				/// <summary>
				/// 今收盘
				/// </summary>
				double ClosePrice;

				/// <summary>
				/// 涨停板价
				/// </summary>
				double UpperLimitPrice;

				/// <summary>
				/// 跌停板价
				/// </summary>
				double LowerLimitPrice;

				/// <summary>
				/// 本次结算价
				/// </summary>
				double SettlementPrice;

				/// <summary>
				/// 今虚实度
				/// </summary>
				double CurrDelta;
			};

			/// <summary>
			/// 行情最新成交属性
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetMarketDataLastMatchField
			{
				/// <summary>
				/// 最新价
				/// </summary>
				double LastPrice;

				/// <summary>
				/// 数量
				/// </summary>
				int Volume;

				/// <summary>
				/// 成交金额
				/// </summary>
				double Turnover;

				/// <summary>
				/// 持仓量
				/// </summary>
				double OpenInterest;
			};

			/// <summary>
			/// 行情最优价属性
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetMarketDataBestPriceField
			{
				/// <summary>
				/// 申买价一
				/// </summary>
				double BidPrice1;

				/// <summary>
				/// 申买量一
				/// </summary>
				int BidVolume1;

				/// <summary>
				/// 申卖价一
				/// </summary>
				double AskPrice1;

				/// <summary>
				/// 申卖量一
				/// </summary>
				int AskVolume1;
			};

			/// <summary>
			/// 行情申买二、三属性
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetMarketDataBid23Field
			{
				/// <summary>
				/// 申买价二
				/// </summary>
				double BidPrice2;

				/// <summary>
				/// 申买量二
				/// </summary>
				int BidVolume2;

				/// <summary>
				/// 申买价三
				/// </summary>
				double BidPrice3;

				/// <summary>
				/// 申买量三
				/// </summary>
				int BidVolume3;
			};

			/// <summary>
			/// 行情申卖二、三属性
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetMarketDataAsk23Field
			{
				/// <summary>
				/// 申卖价二
				/// </summary>
				double AskPrice2;

				/// <summary>
				/// 申卖量二
				/// </summary>
				int AskVolume2;

				/// <summary>
				/// 申卖价三
				/// </summary>
				double AskPrice3;

				/// <summary>
				/// 申卖量三
				/// </summary>
				int AskVolume3;
			};

			/// <summary>
			/// 行情申买四、五属性
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetMarketDataBid45Field
			{
				/// <summary>
				/// 申买价四
				/// </summary>
				double BidPrice4;

				/// <summary>
				/// 申买量四
				/// </summary>
				int BidVolume4;

				/// <summary>
				/// 申买价五
				/// </summary>
				double BidPrice5;

				/// <summary>
				/// 申买量五
				/// </summary>
				int BidVolume5;
			};

			/// <summary>
			/// 行情申卖四、五属性
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetMarketDataAsk45Field
			{
				/// <summary>
				/// 申卖价四
				/// </summary>
				double AskPrice4;

				/// <summary>
				/// 申卖量四
				/// </summary>
				int AskVolume4;

				/// <summary>
				/// 申卖价五
				/// </summary>
				double AskPrice5;

				/// <summary>
				/// 申卖量五
				/// </summary>
				int AskVolume5;
			};

			/// <summary>
			/// 行情更新时间属性
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetMarketDataUpdateTimeField
			{
				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 最后修改时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ UpdateTime;

				/// <summary>
				/// 最后修改毫秒
				/// </summary>
				int UpdateMillisec;

				/// <summary>
				/// 业务日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ActionDay;
			};

			/// <summary>
			/// 行情交易所代码属性
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetMarketDataExchangeField
			{
				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;
			};

			/// <summary>
			/// 指定的合约
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetSpecificInstrumentField
			{
				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;
			};

			/// <summary>
			/// 合约状态
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetInstrumentStatusField
			{
				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 合约在交易所的代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ ExchangeInstID;

				/// <summary>
				/// 结算组代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ SettlementGroupID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 合约交易状态
				/// </summary>
				CtpNetInstrumentStatusType InstrumentStatus;

				/// <summary>
				/// 交易阶段编号
				/// </summary>
				int TradingSegmentSN;

				/// <summary>
				/// 进入本状态时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ EnterTime;

				/// <summary>
				/// 进入本状态原因
				/// </summary>
				CtpNetInstStatusEnterReasonType EnterReason;
			};

			/// <summary>
			/// 查询合约状态
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryInstrumentStatusField
			{
				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 合约在交易所的代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ ExchangeInstID;
			};

			/// <summary>
			/// 投资者账户
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetInvestorAccountField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 投资者帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;
			};

			/// <summary>
			/// 浮动盈亏算法
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetPositionProfitAlgorithmField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 盈亏算法
				/// </summary>
				CtpNetAlgorithmType Algorithm;

				/// <summary>
				/// 备注
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 161)]
				String^ Memo;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;
			};

			/// <summary>
			/// 会员资金折扣
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetDiscountField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者范围
				/// </summary>
				CtpNetInvestorRangeType InvestorRange;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 资金折扣比例
				/// </summary>
				double Discount;
			};

			/// <summary>
			/// 查询转帐银行
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryTransferBankField
			{
				/// <summary>
				/// 银行代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ BankID;

				/// <summary>
				/// 银行分中心代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
				String^ BankBrchID;
			};

			/// <summary>
			/// 转帐银行
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetTransferBankField
			{
				/// <summary>
				/// 银行代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ BankID;

				/// <summary>
				/// 银行分中心代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
				String^ BankBrchID;

				/// <summary>
				/// 银行名称
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 101)]
				String^ BankName;

				/// <summary>
				/// 是否活跃
				/// </summary>
				int IsActive;
			};

			/// <summary>
			/// 查询投资者持仓明细
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryInvestorPositionDetailField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;
			};

			/// <summary>
			/// 投资者持仓明细
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetInvestorPositionDetailField
			{
				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 投机套保标志
				/// </summary>
				CtpNetHedgeFlagType HedgeFlag;

				/// <summary>
				/// 买卖
				/// </summary>
				CtpNetDirectionType Direction;

				/// <summary>
				/// 开仓日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ OpenDate;

				/// <summary>
				/// 成交编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TradeID;

				/// <summary>
				/// 数量
				/// </summary>
				int Volume;

				/// <summary>
				/// 开仓价
				/// </summary>
				double OpenPrice;

				/// <summary>
				/// 交易日
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 结算编号
				/// </summary>
				int SettlementID;

				/// <summary>
				/// 成交类型
				/// </summary>
				CtpNetTradeTypeType TradeType;

				/// <summary>
				/// 组合合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ CombInstrumentID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 逐日盯市平仓盈亏
				/// </summary>
				double CloseProfitByDate;

				/// <summary>
				/// 逐笔对冲平仓盈亏
				/// </summary>
				double CloseProfitByTrade;

				/// <summary>
				/// 逐日盯市持仓盈亏
				/// </summary>
				double PositionProfitByDate;

				/// <summary>
				/// 逐笔对冲持仓盈亏
				/// </summary>
				double PositionProfitByTrade;

				/// <summary>
				/// 投资者保证金
				/// </summary>
				double Margin;

				/// <summary>
				/// 交易所保证金
				/// </summary>
				double ExchMargin;

				/// <summary>
				/// 保证金率
				/// </summary>
				double MarginRateByMoney;

				/// <summary>
				/// 保证金率(按手数)
				/// </summary>
				double MarginRateByVolume;

				/// <summary>
				/// 昨结算价
				/// </summary>
				double LastSettlementPrice;

				/// <summary>
				/// 结算价
				/// </summary>
				double SettlementPrice;

				/// <summary>
				/// 平仓量
				/// </summary>
				int CloseVolume;

				/// <summary>
				/// 平仓金额
				/// </summary>
				double CloseAmount;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;
			};

			/// <summary>
			/// 资金账户口令域
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetTradingAccountPasswordField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Password;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;
			};

			/// <summary>
			/// 交易所行情报盘机
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetMDTraderOfferField
			{
				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;

				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Password;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 本地报单编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ OrderLocalID;

				/// <summary>
				/// 交易所交易员连接状态
				/// </summary>
				CtpNetTraderConnectStatusType TraderConnectStatus;

				/// <summary>
				/// 发出连接请求的日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ConnectRequestDate;

				/// <summary>
				/// 发出连接请求的时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ConnectRequestTime;

				/// <summary>
				/// 上次报告日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ LastReportDate;

				/// <summary>
				/// 上次报告时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ LastReportTime;

				/// <summary>
				/// 完成连接日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ConnectDate;

				/// <summary>
				/// 完成连接时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ConnectTime;

				/// <summary>
				/// 启动日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ StartDate;

				/// <summary>
				/// 启动时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ StartTime;

				/// <summary>
				/// 交易日
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 本席位最大成交编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MaxTradeID;

				/// <summary>
				/// 本席位最大报单备拷
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ MaxOrderMessageReference;
			};

			/// <summary>
			/// 查询行情报盘机
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryMDTraderOfferField
			{
				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;
			};

			/// <summary>
			/// 查询客户通知
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryNoticeField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;
			};

			/// <summary>
			/// 客户通知
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetNoticeField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 消息正文
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 501)]
				String^ Content;

				/// <summary>
				/// 经纪公司通知内容序列号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 2)]
				String^ SequenceLabel;
			};

			/// <summary>
			/// 用户权限
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetUserRightField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 客户权限类型
				/// </summary>
				CtpNetUserRightTypeType UserRightType;

				/// <summary>
				/// 是否禁止
				/// </summary>
				int IsForbidden;
			};

			/// <summary>
			/// 查询结算信息确认域
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQrySettlementInfoConfirmField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 投资者帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;
			};

			/// <summary>
			/// 装载结算信息
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetLoadSettlementInfoField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;
			};

			/// <summary>
			/// 经纪公司可提资金算法表
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetBrokerWithdrawAlgorithmField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 可提资金算法
				/// </summary>
				CtpNetAlgorithmType WithdrawAlgorithm;

				/// <summary>
				/// 资金使用率
				/// </summary>
				double UsingRatio;

				/// <summary>
				/// 可提是否包含平仓盈利
				/// </summary>
				CtpNetIncludeCloseProfitType IncludeCloseProfit;

				/// <summary>
				/// 本日无仓且无成交客户是否受可提比例限制
				/// </summary>
				CtpNetAllWithoutTradeType AllWithoutTrade;

				/// <summary>
				/// 可用是否包含平仓盈利
				/// </summary>
				CtpNetIncludeCloseProfitType AvailIncludeCloseProfit;

				/// <summary>
				/// 是否启用用户事件
				/// </summary>
				int IsBrokerUserEvent;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// 货币质押比率
				/// </summary>
				double FundMortgageRatio;

				/// <summary>
				/// 权益算法
				/// </summary>
				CtpNetBalanceAlgorithmType BalanceAlgorithm;
			};

			/// <summary>
			/// 资金账户口令变更域
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetTradingAccountPasswordUpdateV1Field
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 原来的口令
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ OldPassword;

				/// <summary>
				/// 新的口令
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ NewPassword;
			};

			/// <summary>
			/// 资金账户口令变更域
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetTradingAccountPasswordUpdateField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 原来的口令
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ OldPassword;

				/// <summary>
				/// 新的口令
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ NewPassword;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;
			};

			/// <summary>
			/// 查询组合合约分腿
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryCombinationLegField
			{
				/// <summary>
				/// 组合合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ CombInstrumentID;

				/// <summary>
				/// 单腿编号
				/// </summary>
				int LegID;

				/// <summary>
				/// 单腿合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ LegInstrumentID;
			};

			/// <summary>
			/// 查询组合合约分腿
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQrySyncStatusField
			{
				/// <summary>
				/// 交易日
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;
			};

			/// <summary>
			/// 组合交易合约的单腿
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetCombinationLegField
			{
				/// <summary>
				/// 组合合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ CombInstrumentID;

				/// <summary>
				/// 单腿编号
				/// </summary>
				int LegID;

				/// <summary>
				/// 单腿合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ LegInstrumentID;

				/// <summary>
				/// 买卖方向
				/// </summary>
				CtpNetDirectionType Direction;

				/// <summary>
				/// 单腿乘数
				/// </summary>
				int LegMultiple;

				/// <summary>
				/// 派生层数
				/// </summary>
				int ImplyLevel;
			};

			/// <summary>
			/// 数据同步状态
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetSyncStatusField
			{
				/// <summary>
				/// 交易日
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 数据同步状态
				/// </summary>
				CtpNetDataSyncStatusType DataSyncStatus;
			};

			/// <summary>
			/// 查询联系人
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryLinkManField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;
			};

			/// <summary>
			/// 联系人
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetLinkManField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 联系人类型
				/// </summary>
				CtpNetPersonTypeType PersonType;

				/// <summary>
				/// 证件类型
				/// </summary>
				CtpNetIdCardTypeType IdentifiedCardType;

				/// <summary>
				/// 证件号码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
				String^ IdentifiedCardNo;

				/// <summary>
				/// 名称
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ PersonName;

				/// <summary>
				/// 联系电话
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Telephone;

				/// <summary>
				/// 通讯地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 101)]
				String^ Address;

				/// <summary>
				/// 邮政编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ ZipCode;

				/// <summary>
				/// 优先级
				/// </summary>
				int Priority;

				/// <summary>
				/// 开户邮政编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ UOAZipCode;

				/// <summary>
				/// 全称
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 101)]
				String^ PersonFullName;
			};

			/// <summary>
			/// 查询经纪公司用户事件
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryBrokerUserEventField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 用户事件类型
				/// </summary>
				CtpNetUserEventTypeType UserEventType;
			};

			/// <summary>
			/// 查询经纪公司用户事件
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetBrokerUserEventField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 用户事件类型
				/// </summary>
				CtpNetUserEventTypeType UserEventType;

				/// <summary>
				/// 用户事件序号
				/// </summary>
				int EventSequenceNo;

				/// <summary>
				/// 事件发生日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ EventDate;

				/// <summary>
				/// 事件发生时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ EventTime;

				/// <summary>
				/// 用户事件信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 1025)]
				String^ UserEventInfo;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;
			};

			/// <summary>
			/// 查询签约银行请求
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryContractBankField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 银行代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ BankID;

				/// <summary>
				/// 银行分中心代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
				String^ BankBrchID;
			};

			/// <summary>
			/// 查询签约银行响应
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetContractBankField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 银行代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ BankID;

				/// <summary>
				/// 银行分中心代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
				String^ BankBrchID;

				/// <summary>
				/// 银行名称
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 101)]
				String^ BankName;
			};

			/// <summary>
			/// 投资者组合持仓明细
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetInvestorPositionCombineDetailField
			{
				/// <summary>
				/// 交易日
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 开仓日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ OpenDate;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 结算编号
				/// </summary>
				int SettlementID;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 组合编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ ComTradeID;

				/// <summary>
				/// 撮合编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TradeID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 投机套保标志
				/// </summary>
				CtpNetHedgeFlagType HedgeFlag;

				/// <summary>
				/// 买卖
				/// </summary>
				CtpNetDirectionType Direction;

				/// <summary>
				/// 持仓量
				/// </summary>
				int TotalAmt;

				/// <summary>
				/// 投资者保证金
				/// </summary>
				double Margin;

				/// <summary>
				/// 交易所保证金
				/// </summary>
				double ExchMargin;

				/// <summary>
				/// 保证金率
				/// </summary>
				double MarginRateByMoney;

				/// <summary>
				/// 保证金率(按手数)
				/// </summary>
				double MarginRateByVolume;

				/// <summary>
				/// 单腿编号
				/// </summary>
				int LegID;

				/// <summary>
				/// 单腿乘数
				/// </summary>
				int LegMultiple;

				/// <summary>
				/// 组合持仓合约编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ CombInstrumentID;

				/// <summary>
				/// 成交组号
				/// </summary>
				int TradeGroupID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;
			};

			/// <summary>
			/// 预埋单
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetParkedOrderField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 报单引用
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ OrderRef;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 报单价格条件
				/// </summary>
				CtpNetOrderPriceTypeType OrderPriceType;

				/// <summary>
				/// 买卖方向
				/// </summary>
				CtpNetDirectionType Direction;

				/// <summary>
				/// 组合开平标志1
				/// </summary>
				CtpNetOffsetFlagType CombOffsetFlag1;
				
				/// <summary>
				/// 组合开平标志2
				/// </summary>
				CtpNetOffsetFlagType CombOffsetFlag2;
				
				/// <summary>
				/// 组合开平标志3
				/// </summary>
				CtpNetOffsetFlagType CombOffsetFlag3;
				
				/// <summary>
				/// 组合开平标志4
				/// </summary>
				CtpNetOffsetFlagType CombOffsetFlag4;
				
				/// <summary>
				/// 组合开平标志5
				/// </summary>
				CtpNetOffsetFlagType CombOffsetFlag5;

				/// <summary>
				/// 组合投机套保标志1
				/// </summary>
				CtpNetHedgeFlagType CombHedgeFlag1;
				
				/// <summary>
				/// 组合投机套保标志2
				/// </summary>
				CtpNetHedgeFlagType CombHedgeFlag2;
				
				/// <summary>
				/// 组合投机套保标志3
				/// </summary>
				CtpNetHedgeFlagType CombHedgeFlag3;
				
				/// <summary>
				/// 组合投机套保标志4
				/// </summary>
				CtpNetHedgeFlagType CombHedgeFlag4;
				
				/// <summary>
				/// 组合投机套保标志5
				/// </summary>
				CtpNetHedgeFlagType CombHedgeFlag5;

				/// <summary>
				/// 价格
				/// </summary>
				double LimitPrice;

				/// <summary>
				/// 数量
				/// </summary>
				int VolumeTotalOriginal;

				/// <summary>
				/// 有效期类型
				/// </summary>
				CtpNetTimeConditionType TimeCondition;

				/// <summary>
				/// GTD日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ GTDDate;

				/// <summary>
				/// 成交量类型
				/// </summary>
				CtpNetVolumeConditionType VolumeCondition;

				/// <summary>
				/// 最小成交量
				/// </summary>
				int MinVolume;

				/// <summary>
				/// 触发条件
				/// </summary>
				CtpNetContingentConditionType ContingentCondition;

				/// <summary>
				/// 止损价
				/// </summary>
				double StopPrice;

				/// <summary>
				/// 强平原因
				/// </summary>
				CtpNetForceCloseReasonType ForceCloseReason;

				/// <summary>
				/// 自动挂起标志
				/// </summary>
				int IsAutoSuspend;

				/// <summary>
				/// 业务单元
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ BusinessUnit;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 用户强评标志
				/// </summary>
				int UserForceClose;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 预埋报单编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ ParkedOrderID;

				/// <summary>
				/// 用户类型
				/// </summary>
				CtpNetUserTypeType UserType;

				/// <summary>
				/// 预埋单状态
				/// </summary>
				CtpNetParkedOrderStatusType Status;

				/// <summary>
				/// 错误代码
				/// </summary>
				int ErrorID;

				/// <summary>
				/// 错误信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ ErrorMsg;

				/// <summary>
				/// 互换单标志
				/// </summary>
				int IsSwapOrder;

				/// <summary>
				/// 资金账号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// 交易编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;
			};

			/// <summary>
			/// 输入预埋单操作
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetParkedOrderActionField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 报单操作引用
				/// </summary>
				int OrderActionRef;

				/// <summary>
				/// 报单引用
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ OrderRef;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 前置编号
				/// </summary>
				int FrontID;

				/// <summary>
				/// 会话编号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 报单编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ OrderSysID;

				/// <summary>
				/// 操作标志
				/// </summary>
				CtpNetActionFlagType ActionFlag;

				/// <summary>
				/// 价格
				/// </summary>
				double LimitPrice;

				/// <summary>
				/// 数量变化
				/// </summary>
				int VolumeChange;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 预埋撤单单编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ ParkedOrderActionID;

				/// <summary>
				/// 用户类型
				/// </summary>
				CtpNetUserTypeType UserType;

				/// <summary>
				/// 预埋撤单状态
				/// </summary>
				CtpNetParkedOrderStatusType Status;

				/// <summary>
				/// 错误代码
				/// </summary>
				int ErrorID;

				/// <summary>
				/// 错误信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ ErrorMsg;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;
			};

			/// <summary>
			/// 查询预埋单
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryParkedOrderField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;
			};

			/// <summary>
			/// 查询预埋撤单
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryParkedOrderActionField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;
			};

			/// <summary>
			/// 删除预埋单
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetRemoveParkedOrderField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 预埋报单编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ ParkedOrderID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;
			};

			/// <summary>
			/// 删除预埋撤单
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetRemoveParkedOrderActionField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 预埋撤单编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ ParkedOrderActionID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;
			};

			/// <summary>
			/// 经纪公司可提资金算法表
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetInvestorWithdrawAlgorithmField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者范围
				/// </summary>
				CtpNetInvestorRangeType InvestorRange;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 可提资金比例
				/// </summary>
				double UsingRatio;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// 货币质押比率
				/// </summary>
				double FundMortgageRatio;
			};

			/// <summary>
			/// 查询组合持仓明细
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryInvestorPositionCombineDetailField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 组合持仓合约编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ CombInstrumentID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;
			};

			/// <summary>
			/// 成交均价
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetMarketDataAveragePriceField
			{
				/// <summary>
				/// 当日均价
				/// </summary>
				double AveragePrice;
			};

			/// <summary>
			/// 校验投资者密码
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetVerifyInvestorPasswordField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Password;
			};

			/// <summary>
			/// 用户IP
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetUserIPField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// IP地址掩码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPMask;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;
			};

			/// <summary>
			/// 用户事件通知信息
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetTradingNoticeInfoField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 发送时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ SendTime;

				/// <summary>
				/// 消息正文
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 501)]
				String^ FieldContent;

				/// <summary>
				/// 序列系列号
				/// </summary>
				short SequenceSeries;

				/// <summary>
				/// 序列号
				/// </summary>
				int SequenceNo;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;
			};

			/// <summary>
			/// 用户事件通知
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetTradingNoticeField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者范围
				/// </summary>
				CtpNetInvestorRangeType InvestorRange;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 序列系列号
				/// </summary>
				short SequenceSeries;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 发送时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ SendTime;

				/// <summary>
				/// 序列号
				/// </summary>
				int SequenceNo;

				/// <summary>
				/// 消息正文
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 501)]
				String^ FieldContent;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;
			};

			/// <summary>
			/// 查询交易事件通知
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryTradingNoticeField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;
			};

			/// <summary>
			/// 查询错误报单
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryErrOrderField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;
			};

			/// <summary>
			/// 错误报单
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetErrOrderField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 报单引用
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ OrderRef;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 报单价格条件
				/// </summary>
				CtpNetOrderPriceTypeType OrderPriceType;

				/// <summary>
				/// 买卖方向
				/// </summary>
				CtpNetDirectionType Direction;

				/// <summary>
				/// 组合开平标志1
				/// </summary>
				CtpNetOffsetFlagType CombOffsetFlag1;
				
				/// <summary>
				/// 组合开平标志2
				/// </summary>
				CtpNetOffsetFlagType CombOffsetFlag2;
				
				/// <summary>
				/// 组合开平标志3
				/// </summary>
				CtpNetOffsetFlagType CombOffsetFlag3;
				
				/// <summary>
				/// 组合开平标志4
				/// </summary>
				CtpNetOffsetFlagType CombOffsetFlag4;
				
				/// <summary>
				/// 组合开平标志5
				/// </summary>
				CtpNetOffsetFlagType CombOffsetFlag5;

				/// <summary>
				/// 组合投机套保标志1
				/// </summary>
				CtpNetHedgeFlagType CombHedgeFlag1;
				
				/// <summary>
				/// 组合投机套保标志2
				/// </summary>
				CtpNetHedgeFlagType CombHedgeFlag2;
				
				/// <summary>
				/// 组合投机套保标志3
				/// </summary>
				CtpNetHedgeFlagType CombHedgeFlag3;
				
				/// <summary>
				/// 组合投机套保标志4
				/// </summary>
				CtpNetHedgeFlagType CombHedgeFlag4;
				
				/// <summary>
				/// 组合投机套保标志5
				/// </summary>
				CtpNetHedgeFlagType CombHedgeFlag5;

				/// <summary>
				/// 价格
				/// </summary>
				double LimitPrice;

				/// <summary>
				/// 数量
				/// </summary>
				int VolumeTotalOriginal;

				/// <summary>
				/// 有效期类型
				/// </summary>
				CtpNetTimeConditionType TimeCondition;

				/// <summary>
				/// GTD日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ GTDDate;

				/// <summary>
				/// 成交量类型
				/// </summary>
				CtpNetVolumeConditionType VolumeCondition;

				/// <summary>
				/// 最小成交量
				/// </summary>
				int MinVolume;

				/// <summary>
				/// 触发条件
				/// </summary>
				CtpNetContingentConditionType ContingentCondition;

				/// <summary>
				/// 止损价
				/// </summary>
				double StopPrice;

				/// <summary>
				/// 强平原因
				/// </summary>
				CtpNetForceCloseReasonType ForceCloseReason;

				/// <summary>
				/// 自动挂起标志
				/// </summary>
				int IsAutoSuspend;

				/// <summary>
				/// 业务单元
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ BusinessUnit;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 用户强评标志
				/// </summary>
				int UserForceClose;

				/// <summary>
				/// 错误代码
				/// </summary>
				int ErrorID;

				/// <summary>
				/// 错误信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ ErrorMsg;

				/// <summary>
				/// 互换单标志
				/// </summary>
				int IsSwapOrder;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;

				/// <summary>
				/// 资金账号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// 交易编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;
			};

			/// <summary>
			/// 查询错误报单操作
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetErrorConditionalOrderField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 报单引用
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ OrderRef;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 报单价格条件
				/// </summary>
				CtpNetOrderPriceTypeType OrderPriceType;

				/// <summary>
				/// 买卖方向
				/// </summary>
				CtpNetDirectionType Direction;

				/// <summary>
				/// 组合开平标志1
				/// </summary>
				CtpNetOffsetFlagType CombOffsetFlag1;
				
				/// <summary>
				/// 组合开平标志2
				/// </summary>
				CtpNetOffsetFlagType CombOffsetFlag2;
				
				/// <summary>
				/// 组合开平标志3
				/// </summary>
				CtpNetOffsetFlagType CombOffsetFlag3;
				
				/// <summary>
				/// 组合开平标志4
				/// </summary>
				CtpNetOffsetFlagType CombOffsetFlag4;
				
				/// <summary>
				/// 组合开平标志5
				/// </summary>
				CtpNetOffsetFlagType CombOffsetFlag5;

				/// <summary>
				/// 组合投机套保标志1
				/// </summary>
				CtpNetHedgeFlagType CombHedgeFlag1;
				
				/// <summary>
				/// 组合投机套保标志2
				/// </summary>
				CtpNetHedgeFlagType CombHedgeFlag2;
				
				/// <summary>
				/// 组合投机套保标志3
				/// </summary>
				CtpNetHedgeFlagType CombHedgeFlag3;
				
				/// <summary>
				/// 组合投机套保标志4
				/// </summary>
				CtpNetHedgeFlagType CombHedgeFlag4;
				
				/// <summary>
				/// 组合投机套保标志5
				/// </summary>
				CtpNetHedgeFlagType CombHedgeFlag5;

				/// <summary>
				/// 价格
				/// </summary>
				double LimitPrice;

				/// <summary>
				/// 数量
				/// </summary>
				int VolumeTotalOriginal;

				/// <summary>
				/// 有效期类型
				/// </summary>
				CtpNetTimeConditionType TimeCondition;

				/// <summary>
				/// GTD日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ GTDDate;

				/// <summary>
				/// 成交量类型
				/// </summary>
				CtpNetVolumeConditionType VolumeCondition;

				/// <summary>
				/// 最小成交量
				/// </summary>
				int MinVolume;

				/// <summary>
				/// 触发条件
				/// </summary>
				CtpNetContingentConditionType ContingentCondition;

				/// <summary>
				/// 止损价
				/// </summary>
				double StopPrice;

				/// <summary>
				/// 强平原因
				/// </summary>
				CtpNetForceCloseReasonType ForceCloseReason;

				/// <summary>
				/// 自动挂起标志
				/// </summary>
				int IsAutoSuspend;

				/// <summary>
				/// 业务单元
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ BusinessUnit;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 本地报单编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ OrderLocalID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 客户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// 合约在交易所的代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ ExchangeInstID;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 报单提交状态
				/// </summary>
				CtpNetOrderSubmitStatusType OrderSubmitStatus;

				/// <summary>
				/// 报单提示序号
				/// </summary>
				int NotifySequence;

				/// <summary>
				/// 交易日
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 结算编号
				/// </summary>
				int SettlementID;

				/// <summary>
				/// 报单编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ OrderSysID;

				/// <summary>
				/// 报单来源
				/// </summary>
				CtpNetOrderSourceType OrderSource;

				/// <summary>
				/// 报单状态
				/// </summary>
				CtpNetOrderStatusType OrderStatus;

				/// <summary>
				/// 报单类型
				/// </summary>
				CtpNetOrderTypeType OrderType;

				/// <summary>
				/// 今成交数量
				/// </summary>
				int VolumeTraded;

				/// <summary>
				/// 剩余数量
				/// </summary>
				int VolumeTotal;

				/// <summary>
				/// 报单日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ InsertDate;

				/// <summary>
				/// 委托时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ InsertTime;

				/// <summary>
				/// 激活时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ActiveTime;

				/// <summary>
				/// 挂起时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ SuspendTime;

				/// <summary>
				/// 最后修改时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ UpdateTime;

				/// <summary>
				/// 撤销时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ CancelTime;

				/// <summary>
				/// 最后修改交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ ActiveTraderID;

				/// <summary>
				/// 结算会员编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClearingPartID;

				/// <summary>
				/// 序号
				/// </summary>
				int SequenceNo;

				/// <summary>
				/// 前置编号
				/// </summary>
				int FrontID;

				/// <summary>
				/// 会话编号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 用户端产品信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ UserProductInfo;

				/// <summary>
				/// 状态信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ StatusMsg;

				/// <summary>
				/// 用户强评标志
				/// </summary>
				int UserForceClose;

				/// <summary>
				/// 操作用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ ActiveUserID;

				/// <summary>
				/// 经纪公司报单编号
				/// </summary>
				int BrokerOrderSeq;

				/// <summary>
				/// 相关报单
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ RelativeOrderSysID;

				/// <summary>
				/// 郑商所成交数量
				/// </summary>
				int ZCETotalTradedVolume;

				/// <summary>
				/// 错误代码
				/// </summary>
				int ErrorID;

				/// <summary>
				/// 错误信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ ErrorMsg;

				/// <summary>
				/// 互换单标志
				/// </summary>
				int IsSwapOrder;

				/// <summary>
				/// 营业部编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ BranchID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;

				/// <summary>
				/// 资金账号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;
			};

			/// <summary>
			/// 查询错误报单操作
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryErrOrderActionField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;
			};

			/// <summary>
			/// 错误报单操作
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetErrOrderActionField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 报单操作引用
				/// </summary>
				int OrderActionRef;

				/// <summary>
				/// 报单引用
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ OrderRef;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 前置编号
				/// </summary>
				int FrontID;

				/// <summary>
				/// 会话编号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 报单编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ OrderSysID;

				/// <summary>
				/// 操作标志
				/// </summary>
				CtpNetActionFlagType ActionFlag;

				/// <summary>
				/// 价格
				/// </summary>
				double LimitPrice;

				/// <summary>
				/// 数量变化
				/// </summary>
				int VolumeChange;

				/// <summary>
				/// 操作日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ActionDate;

				/// <summary>
				/// 操作时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ActionTime;

				/// <summary>
				/// 交易所交易员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ TraderID;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 本地报单编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ OrderLocalID;

				/// <summary>
				/// 操作本地编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ ActionLocalID;

				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 客户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ClientID;

				/// <summary>
				/// 业务单元
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ BusinessUnit;

				/// <summary>
				/// 报单操作状态
				/// </summary>
				CtpNetOrderActionStatusType OrderActionStatus;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 状态信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ StatusMsg;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 营业部编号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ BranchID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;

				/// <summary>
				/// Mac地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MacAddress;

				/// <summary>
				/// 错误代码
				/// </summary>
				int ErrorID;

				/// <summary>
				/// 错误信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ ErrorMsg;
			};

			/// <summary>
			/// 查询交易所状态
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryExchangeSequenceField
			{
				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;
			};

			/// <summary>
			/// 交易所状态
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetExchangeSequenceField
			{
				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 序号
				/// </summary>
				int SequenceNo;

				/// <summary>
				/// 合约交易状态
				/// </summary>
				CtpNetInstrumentStatusType MarketStatus;
			};

			/// <summary>
			/// 根据价格查询最大报单数量
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQueryMaxOrderVolumeWithPriceField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 买卖方向
				/// </summary>
				CtpNetDirectionType Direction;

				/// <summary>
				/// 开平标志
				/// </summary>
				CtpNetOffsetFlagType OffsetFlag;

				/// <summary>
				/// 投机套保标志
				/// </summary>
				CtpNetHedgeFlagType HedgeFlag;

				/// <summary>
				/// 最大允许报单数量
				/// </summary>
				int MaxVolume;

				/// <summary>
				/// 报单价格
				/// </summary>
				double Price;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;
			};

			/// <summary>
			/// 查询经纪公司交易参数
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryBrokerTradingParamsField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// 投资者帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;
			};

			/// <summary>
			/// 经纪公司交易参数
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetBrokerTradingParamsField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 保证金价格类型
				/// </summary>
				CtpNetMarginPriceTypeType MarginPriceType;

				/// <summary>
				/// 盈亏算法
				/// </summary>
				CtpNetAlgorithmType Algorithm;

				/// <summary>
				/// 可用是否包含平仓盈利
				/// </summary>
				CtpNetIncludeCloseProfitType AvailIncludeCloseProfit;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// 期权权利金价格类型
				/// </summary>
				CtpNetOptionRoyaltyPriceTypeType OptionRoyaltyPriceType;

				/// <summary>
				/// 投资者帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;
			};

			/// <summary>
			/// 查询经纪公司交易算法
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryBrokerTradingAlgosField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;
			};

			/// <summary>
			/// 经纪公司交易算法
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetBrokerTradingAlgosField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 持仓处理算法编号
				/// </summary>
				CtpNetHandlePositionAlgoIDType HandlePositionAlgoID;

				/// <summary>
				/// 寻找保证金率算法编号
				/// </summary>
				CtpNetFindMarginRateAlgoIDType FindMarginRateAlgoID;

				/// <summary>
				/// 资金处理算法编号
				/// </summary>
				CtpNetHandleTradingAccountAlgoIDType HandleTradingAccountAlgoID;
			};

			/// <summary>
			/// 查询经纪公司资金
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQueryBrokerDepositField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;
			};

			/// <summary>
			/// 经纪公司资金
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetBrokerDepositField
			{
				/// <summary>
				/// 交易日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 会员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 上次结算准备金
				/// </summary>
				double PreBalance;

				/// <summary>
				/// 当前保证金总额
				/// </summary>
				double CurrMargin;

				/// <summary>
				/// 平仓盈亏
				/// </summary>
				double CloseProfit;

				/// <summary>
				/// 期货结算准备金
				/// </summary>
				double Balance;

				/// <summary>
				/// 入金金额
				/// </summary>
				double Deposit;

				/// <summary>
				/// 出金金额
				/// </summary>
				double Withdraw;

				/// <summary>
				/// 可提资金
				/// </summary>
				double Available;

				/// <summary>
				/// 基本准备金
				/// </summary>
				double Reserve;

				/// <summary>
				/// 冻结的保证金
				/// </summary>
				double FrozenMargin;
			};

			/// <summary>
			/// 查询保证金监管系统经纪公司密钥
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryCFMMCBrokerKeyField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;
			};

			/// <summary>
			/// 保证金监管系统经纪公司密钥
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetCFMMCBrokerKeyField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 经纪公司统一编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 密钥生成日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ CreateDate;

				/// <summary>
				/// 密钥生成时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ CreateTime;

				/// <summary>
				/// 密钥编号
				/// </summary>
				int KeyID;

				/// <summary>
				/// 动态密钥
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ CurrentKey;

				/// <summary>
				/// 动态密钥类型
				/// </summary>
				CtpNetCFMMCKeyKindType KeyKind;
			};

			/// <summary>
			/// 保证金监管系统经纪公司资金账户密钥
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetCFMMCTradingAccountKeyField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 经纪公司统一编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 投资者帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 密钥编号
				/// </summary>
				int KeyID;

				/// <summary>
				/// 动态密钥
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ CurrentKey;
			};

			/// <summary>
			/// 请求查询保证金监管系统经纪公司资金账户密钥
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryCFMMCTradingAccountKeyField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;
			};

			/// <summary>
			/// 用户动态令牌参数
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetBrokerUserOTPParamField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 动态令牌提供商
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 2)]
				String^ OTPVendorsID;

				/// <summary>
				/// 动态令牌序列号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ SerialNumber;

				/// <summary>
				/// 令牌密钥
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ AuthKey;

				/// <summary>
				/// 漂移值
				/// </summary>
				int LastDrift;

				/// <summary>
				/// 成功值
				/// </summary>
				int LastSuccess;

				/// <summary>
				/// 动态令牌类型
				/// </summary>
				CtpNetOTPTypeType OTPType;
			};

			/// <summary>
			/// 手工同步用户动态令牌
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetManualSyncBrokerUserOTPField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 动态令牌类型
				/// </summary>
				CtpNetOTPTypeType OTPType;

				/// <summary>
				/// 第一个动态密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ FirstOTP;

				/// <summary>
				/// 第二个动态密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ SecondOTP;
			};

			/// <summary>
			/// 投资者手续费率模板
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetCommRateModelField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 手续费率模板代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ CommModelID;

				/// <summary>
				/// 模板名称
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 161)]
				String^ CommModelName;
			};

			/// <summary>
			/// 请求查询投资者手续费率模板
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryCommRateModelField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 手续费率模板代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ CommModelID;
			};

			/// <summary>
			/// 投资者保证金率模板
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetMarginModelField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 保证金率模板代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ MarginModelID;

				/// <summary>
				/// 模板名称
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 161)]
				String^ MarginModelName;
			};

			/// <summary>
			/// 请求查询投资者保证金率模板
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryMarginModelField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 保证金率模板代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ MarginModelID;
			};

			/// <summary>
			/// 仓单折抵信息
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetEWarrantOffsetField
			{
				/// <summary>
				/// 交易日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 买卖方向
				/// </summary>
				CtpNetDirectionType Direction;

				/// <summary>
				/// 投机套保标志
				/// </summary>
				CtpNetHedgeFlagType HedgeFlag;

				/// <summary>
				/// 数量
				/// </summary>
				int Volume;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;
			};

			/// <summary>
			/// 查询仓单折抵信息
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryEWarrantOffsetField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 合约代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ InstrumentID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;
			};

			/// <summary>
			/// 查询投资者品种/跨品种保证金
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryInvestorProductGroupMarginField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 品种/跨品种标示
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ ProductGroupID;

				/// <summary>
				/// 投机套保标志
				/// </summary>
				CtpNetHedgeFlagType HedgeFlag;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;
			};

			/// <summary>
			/// 投资者品种/跨品种保证金
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetInvestorProductGroupMarginField
			{
				/// <summary>
				/// 品种/跨品种标示
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ ProductGroupID;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 交易日
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 结算编号
				/// </summary>
				int SettlementID;

				/// <summary>
				/// 冻结的保证金
				/// </summary>
				double FrozenMargin;

				/// <summary>
				/// 多头冻结的保证金
				/// </summary>
				double LongFrozenMargin;

				/// <summary>
				/// 空头冻结的保证金
				/// </summary>
				double ShortFrozenMargin;

				/// <summary>
				/// 占用的保证金
				/// </summary>
				double UseMargin;

				/// <summary>
				/// 多头保证金
				/// </summary>
				double LongUseMargin;

				/// <summary>
				/// 空头保证金
				/// </summary>
				double ShortUseMargin;

				/// <summary>
				/// 交易所保证金
				/// </summary>
				double ExchMargin;

				/// <summary>
				/// 交易所多头保证金
				/// </summary>
				double LongExchMargin;

				/// <summary>
				/// 交易所空头保证金
				/// </summary>
				double ShortExchMargin;

				/// <summary>
				/// 平仓盈亏
				/// </summary>
				double CloseProfit;

				/// <summary>
				/// 冻结的手续费
				/// </summary>
				double FrozenCommission;

				/// <summary>
				/// 手续费
				/// </summary>
				double Commission;

				/// <summary>
				/// 冻结的资金
				/// </summary>
				double FrozenCash;

				/// <summary>
				/// 资金差额
				/// </summary>
				double CashIn;

				/// <summary>
				/// 持仓盈亏
				/// </summary>
				double PositionProfit;

				/// <summary>
				/// 折抵总金额
				/// </summary>
				double OffsetAmount;

				/// <summary>
				/// 多头折抵总金额
				/// </summary>
				double LongOffsetAmount;

				/// <summary>
				/// 空头折抵总金额
				/// </summary>
				double ShortOffsetAmount;

				/// <summary>
				/// 交易所折抵总金额
				/// </summary>
				double ExchOffsetAmount;

				/// <summary>
				/// 交易所多头折抵总金额
				/// </summary>
				double LongExchOffsetAmount;

				/// <summary>
				/// 交易所空头折抵总金额
				/// </summary>
				double ShortExchOffsetAmount;

				/// <summary>
				/// 投机套保标志
				/// </summary>
				CtpNetHedgeFlagType HedgeFlag;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;
			};

			/// <summary>
			/// 查询监控中心用户令牌
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQueryCFMMCTradingAccountTokenField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 投资单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ InvestUnitID;
			};

			/// <summary>
			/// 监控中心用户令牌
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetCFMMCTradingAccountTokenField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 经纪公司统一编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ ParticipantID;

				/// <summary>
				/// 投资者帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 密钥编号
				/// </summary>
				int KeyID;

				/// <summary>
				/// 动态令牌
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ Token;
			};

			/// <summary>
			/// 查询产品组
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryProductGroupField
			{
				/// <summary>
				/// 产品代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ ProductID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;
			};

			/// <summary>
			/// 投资者品种/跨品种保证金产品组
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetProductGroupField
			{
				/// <summary>
				/// 产品代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ ProductID;

				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 产品组代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ ProductGroupID;
			};

			/// <summary>
			/// 交易所公告
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetBulletinField
			{
				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 交易日
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 公告编号
				/// </summary>
				int BulletinID;

				/// <summary>
				/// 序列号
				/// </summary>
				int SequenceNo;

				/// <summary>
				/// 公告类型
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
				String^ NewsType;

				/// <summary>
				/// 紧急程度
				/// </summary>
				Byte NewsUrgency;

				/// <summary>
				/// 发送时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ SendTime;

				/// <summary>
				/// 消息摘要
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ Abstract;

				/// <summary>
				/// 消息来源
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ ComeFrom;

				/// <summary>
				/// 消息正文
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 501)]
				String^ Content;

				/// <summary>
				/// WEB地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 201)]
				String^ URLLink;

				/// <summary>
				/// 市场代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ MarketID;
			};

			/// <summary>
			/// 查询交易所公告
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryBulletinField
			{
				/// <summary>
				/// 交易所代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ ExchangeID;

				/// <summary>
				/// 公告编号
				/// </summary>
				int BulletinID;

				/// <summary>
				/// 序列号
				/// </summary>
				int SequenceNo;

				/// <summary>
				/// 公告类型
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
				String^ NewsType;

				/// <summary>
				/// 紧急程度
				/// </summary>
				Byte NewsUrgency;
			};

			/// <summary>
			/// 转帐开户请求
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetReqOpenAccountField
			{
				/// <summary>
				/// 业务功能码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ TradeCode;

				/// <summary>
				/// 银行代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ BankID;

				/// <summary>
				/// 银行分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
				String^ BankBranchID;

				/// <summary>
				/// 期商代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 期商分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ BrokerBranchID;

				/// <summary>
				/// 交易日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeDate;

				/// <summary>
				/// 交易时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeTime;

				/// <summary>
				/// 银行流水号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ BankSerial;

				/// <summary>
				/// 交易系统日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 银期平台消息流水号
				/// </summary>
				int PlateSerial;

				/// <summary>
				/// 最后分片标志
				/// </summary>
				CtpNetLastFragmentType LastFragment;

				/// <summary>
				/// 会话号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 客户姓名
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
				String^ CustomerName;

				/// <summary>
				/// 证件类型
				/// </summary>
				CtpNetIdCardTypeType IdCardType;

				/// <summary>
				/// 证件号码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
				String^ IdentifiedCardNo;

				/// <summary>
				/// 性别
				/// </summary>
				CtpNetGenderType Gender;

				/// <summary>
				/// 国家代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ CountryCode;

				/// <summary>
				/// 客户类型
				/// </summary>
				CtpNetCustTypeType CustType;

				/// <summary>
				/// 地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 101)]
				String^ Address;

				/// <summary>
				/// 邮编
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ ZipCode;

				/// <summary>
				/// 电话号码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Telephone;

				/// <summary>
				/// 手机
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MobilePhone;

				/// <summary>
				/// 传真
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Fax;

				/// <summary>
				/// 电子邮件
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ EMail;

				/// <summary>
				/// 资金账户状态
				/// </summary>
				CtpNetMoneyAccountStatusType MoneyAccountStatus;

				/// <summary>
				/// 银行帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankAccount;

				/// <summary>
				/// 银行密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankPassWord;

				/// <summary>
				/// 投资者帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 期货密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Password;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 验证客户证件号码标志
				/// </summary>
				CtpNetYesNoIndicatorType VerifyCertNoFlag;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// 汇钞标志
				/// </summary>
				CtpNetCashExchangeCodeType CashExchangeCode;

				/// <summary>
				/// 摘要
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
				String^ Digest;

				/// <summary>
				/// 银行帐号类型
				/// </summary>
				CtpNetBankAccTypeType BankAccType;

				/// <summary>
				/// 渠道标志
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
				String^ DeviceID;

				/// <summary>
				/// 期货单位帐号类型
				/// </summary>
				CtpNetBankAccTypeType BankSecuAccType;

				/// <summary>
				/// 期货公司银行编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
				String^ BrokerIDByBank;

				/// <summary>
				/// 期货单位帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankSecuAcc;

				/// <summary>
				/// 银行密码标志
				/// </summary>
				CtpNetPwdFlagType BankPwdFlag;

				/// <summary>
				/// 期货资金密码核对标志
				/// </summary>
				CtpNetPwdFlagType SecuPwdFlag;

				/// <summary>
				/// 交易柜员
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ OperNo;

				/// <summary>
				/// 交易ID
				/// </summary>
				int TID;

				/// <summary>
				/// 用户标识
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 长客户姓名
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 161)]
				String^ LongCustomerName;
			};

			/// <summary>
			/// 转帐销户请求
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetReqCancelAccountField
			{
				/// <summary>
				/// 业务功能码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ TradeCode;

				/// <summary>
				/// 银行代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ BankID;

				/// <summary>
				/// 银行分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
				String^ BankBranchID;

				/// <summary>
				/// 期商代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 期商分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ BrokerBranchID;

				/// <summary>
				/// 交易日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeDate;

				/// <summary>
				/// 交易时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeTime;

				/// <summary>
				/// 银行流水号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ BankSerial;

				/// <summary>
				/// 交易系统日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 银期平台消息流水号
				/// </summary>
				int PlateSerial;

				/// <summary>
				/// 最后分片标志
				/// </summary>
				CtpNetLastFragmentType LastFragment;

				/// <summary>
				/// 会话号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 客户姓名
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
				String^ CustomerName;

				/// <summary>
				/// 证件类型
				/// </summary>
				CtpNetIdCardTypeType IdCardType;

				/// <summary>
				/// 证件号码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
				String^ IdentifiedCardNo;

				/// <summary>
				/// 性别
				/// </summary>
				CtpNetGenderType Gender;

				/// <summary>
				/// 国家代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ CountryCode;

				/// <summary>
				/// 客户类型
				/// </summary>
				CtpNetCustTypeType CustType;

				/// <summary>
				/// 地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 101)]
				String^ Address;

				/// <summary>
				/// 邮编
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ ZipCode;

				/// <summary>
				/// 电话号码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Telephone;

				/// <summary>
				/// 手机
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MobilePhone;

				/// <summary>
				/// 传真
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Fax;

				/// <summary>
				/// 电子邮件
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ EMail;

				/// <summary>
				/// 资金账户状态
				/// </summary>
				CtpNetMoneyAccountStatusType MoneyAccountStatus;

				/// <summary>
				/// 银行帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankAccount;

				/// <summary>
				/// 银行密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankPassWord;

				/// <summary>
				/// 投资者帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 期货密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Password;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 验证客户证件号码标志
				/// </summary>
				CtpNetYesNoIndicatorType VerifyCertNoFlag;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// 汇钞标志
				/// </summary>
				CtpNetCashExchangeCodeType CashExchangeCode;

				/// <summary>
				/// 摘要
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
				String^ Digest;

				/// <summary>
				/// 银行帐号类型
				/// </summary>
				CtpNetBankAccTypeType BankAccType;

				/// <summary>
				/// 渠道标志
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
				String^ DeviceID;

				/// <summary>
				/// 期货单位帐号类型
				/// </summary>
				CtpNetBankAccTypeType BankSecuAccType;

				/// <summary>
				/// 期货公司银行编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
				String^ BrokerIDByBank;

				/// <summary>
				/// 期货单位帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankSecuAcc;

				/// <summary>
				/// 银行密码标志
				/// </summary>
				CtpNetPwdFlagType BankPwdFlag;

				/// <summary>
				/// 期货资金密码核对标志
				/// </summary>
				CtpNetPwdFlagType SecuPwdFlag;

				/// <summary>
				/// 交易柜员
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ OperNo;

				/// <summary>
				/// 交易ID
				/// </summary>
				int TID;

				/// <summary>
				/// 用户标识
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 长客户姓名
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 161)]
				String^ LongCustomerName;
			};

			/// <summary>
			/// 变更银行账户请求
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetReqChangeAccountField
			{
				/// <summary>
				/// 业务功能码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ TradeCode;

				/// <summary>
				/// 银行代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ BankID;

				/// <summary>
				/// 银行分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
				String^ BankBranchID;

				/// <summary>
				/// 期商代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 期商分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ BrokerBranchID;

				/// <summary>
				/// 交易日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeDate;

				/// <summary>
				/// 交易时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeTime;

				/// <summary>
				/// 银行流水号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ BankSerial;

				/// <summary>
				/// 交易系统日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 银期平台消息流水号
				/// </summary>
				int PlateSerial;

				/// <summary>
				/// 最后分片标志
				/// </summary>
				CtpNetLastFragmentType LastFragment;

				/// <summary>
				/// 会话号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 客户姓名
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
				String^ CustomerName;

				/// <summary>
				/// 证件类型
				/// </summary>
				CtpNetIdCardTypeType IdCardType;

				/// <summary>
				/// 证件号码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
				String^ IdentifiedCardNo;

				/// <summary>
				/// 性别
				/// </summary>
				CtpNetGenderType Gender;

				/// <summary>
				/// 国家代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ CountryCode;

				/// <summary>
				/// 客户类型
				/// </summary>
				CtpNetCustTypeType CustType;

				/// <summary>
				/// 地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 101)]
				String^ Address;

				/// <summary>
				/// 邮编
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ ZipCode;

				/// <summary>
				/// 电话号码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Telephone;

				/// <summary>
				/// 手机
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MobilePhone;

				/// <summary>
				/// 传真
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Fax;

				/// <summary>
				/// 电子邮件
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ EMail;

				/// <summary>
				/// 资金账户状态
				/// </summary>
				CtpNetMoneyAccountStatusType MoneyAccountStatus;

				/// <summary>
				/// 银行帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankAccount;

				/// <summary>
				/// 银行密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankPassWord;

				/// <summary>
				/// 新银行帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ NewBankAccount;

				/// <summary>
				/// 新银行密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ NewBankPassWord;

				/// <summary>
				/// 投资者帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 期货密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Password;

				/// <summary>
				/// 银行帐号类型
				/// </summary>
				CtpNetBankAccTypeType BankAccType;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 验证客户证件号码标志
				/// </summary>
				CtpNetYesNoIndicatorType VerifyCertNoFlag;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// 期货公司银行编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
				String^ BrokerIDByBank;

				/// <summary>
				/// 银行密码标志
				/// </summary>
				CtpNetPwdFlagType BankPwdFlag;

				/// <summary>
				/// 期货资金密码核对标志
				/// </summary>
				CtpNetPwdFlagType SecuPwdFlag;

				/// <summary>
				/// 交易ID
				/// </summary>
				int TID;

				/// <summary>
				/// 摘要
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
				String^ Digest;

				/// <summary>
				/// 长客户姓名
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 161)]
				String^ LongCustomerName;
			};

			/// <summary>
			/// 转账请求
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetReqTransferField
			{
				/// <summary>
				/// 业务功能码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ TradeCode;

				/// <summary>
				/// 银行代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ BankID;

				/// <summary>
				/// 银行分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
				String^ BankBranchID;

				/// <summary>
				/// 期商代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 期商分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ BrokerBranchID;

				/// <summary>
				/// 交易日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeDate;

				/// <summary>
				/// 交易时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeTime;

				/// <summary>
				/// 银行流水号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ BankSerial;

				/// <summary>
				/// 交易系统日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 银期平台消息流水号
				/// </summary>
				int PlateSerial;

				/// <summary>
				/// 最后分片标志
				/// </summary>
				CtpNetLastFragmentType LastFragment;

				/// <summary>
				/// 会话号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 客户姓名
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
				String^ CustomerName;

				/// <summary>
				/// 证件类型
				/// </summary>
				CtpNetIdCardTypeType IdCardType;

				/// <summary>
				/// 证件号码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
				String^ IdentifiedCardNo;

				/// <summary>
				/// 客户类型
				/// </summary>
				CtpNetCustTypeType CustType;

				/// <summary>
				/// 银行帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankAccount;

				/// <summary>
				/// 银行密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankPassWord;

				/// <summary>
				/// 投资者帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 期货密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Password;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 期货公司流水号
				/// </summary>
				int FutureSerial;

				/// <summary>
				/// 用户标识
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 验证客户证件号码标志
				/// </summary>
				CtpNetYesNoIndicatorType VerifyCertNoFlag;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// 转帐金额
				/// </summary>
				double TradeAmount;

				/// <summary>
				/// 期货可取金额
				/// </summary>
				double FutureFetchAmount;

				/// <summary>
				/// 费用支付标志
				/// </summary>
				CtpNetFeePayFlagType FeePayFlag;

				/// <summary>
				/// 应收客户费用
				/// </summary>
				double CustFee;

				/// <summary>
				/// 应收期货公司费用
				/// </summary>
				double BrokerFee;

				/// <summary>
				/// 发送方给接收方的消息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
				String^ Message;

				/// <summary>
				/// 摘要
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
				String^ Digest;

				/// <summary>
				/// 银行帐号类型
				/// </summary>
				CtpNetBankAccTypeType BankAccType;

				/// <summary>
				/// 渠道标志
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
				String^ DeviceID;

				/// <summary>
				/// 期货单位帐号类型
				/// </summary>
				CtpNetBankAccTypeType BankSecuAccType;

				/// <summary>
				/// 期货公司银行编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
				String^ BrokerIDByBank;

				/// <summary>
				/// 期货单位帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankSecuAcc;

				/// <summary>
				/// 银行密码标志
				/// </summary>
				CtpNetPwdFlagType BankPwdFlag;

				/// <summary>
				/// 期货资金密码核对标志
				/// </summary>
				CtpNetPwdFlagType SecuPwdFlag;

				/// <summary>
				/// 交易柜员
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ OperNo;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 交易ID
				/// </summary>
				int TID;

				/// <summary>
				/// 转账交易状态
				/// </summary>
				CtpNetTransferStatusType TransferStatus;

				/// <summary>
				/// 长客户姓名
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 161)]
				String^ LongCustomerName;
			};

			/// <summary>
			/// 银行发起银行资金转期货响应
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetRspTransferField
			{
				/// <summary>
				/// 业务功能码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ TradeCode;

				/// <summary>
				/// 银行代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ BankID;

				/// <summary>
				/// 银行分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
				String^ BankBranchID;

				/// <summary>
				/// 期商代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 期商分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ BrokerBranchID;

				/// <summary>
				/// 交易日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeDate;

				/// <summary>
				/// 交易时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeTime;

				/// <summary>
				/// 银行流水号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ BankSerial;

				/// <summary>
				/// 交易系统日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 银期平台消息流水号
				/// </summary>
				int PlateSerial;

				/// <summary>
				/// 最后分片标志
				/// </summary>
				CtpNetLastFragmentType LastFragment;

				/// <summary>
				/// 会话号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 客户姓名
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
				String^ CustomerName;

				/// <summary>
				/// 证件类型
				/// </summary>
				CtpNetIdCardTypeType IdCardType;

				/// <summary>
				/// 证件号码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
				String^ IdentifiedCardNo;

				/// <summary>
				/// 客户类型
				/// </summary>
				CtpNetCustTypeType CustType;

				/// <summary>
				/// 银行帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankAccount;

				/// <summary>
				/// 银行密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankPassWord;

				/// <summary>
				/// 投资者帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 期货密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Password;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 期货公司流水号
				/// </summary>
				int FutureSerial;

				/// <summary>
				/// 用户标识
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 验证客户证件号码标志
				/// </summary>
				CtpNetYesNoIndicatorType VerifyCertNoFlag;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// 转帐金额
				/// </summary>
				double TradeAmount;

				/// <summary>
				/// 期货可取金额
				/// </summary>
				double FutureFetchAmount;

				/// <summary>
				/// 费用支付标志
				/// </summary>
				CtpNetFeePayFlagType FeePayFlag;

				/// <summary>
				/// 应收客户费用
				/// </summary>
				double CustFee;

				/// <summary>
				/// 应收期货公司费用
				/// </summary>
				double BrokerFee;

				/// <summary>
				/// 发送方给接收方的消息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
				String^ Message;

				/// <summary>
				/// 摘要
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
				String^ Digest;

				/// <summary>
				/// 银行帐号类型
				/// </summary>
				CtpNetBankAccTypeType BankAccType;

				/// <summary>
				/// 渠道标志
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
				String^ DeviceID;

				/// <summary>
				/// 期货单位帐号类型
				/// </summary>
				CtpNetBankAccTypeType BankSecuAccType;

				/// <summary>
				/// 期货公司银行编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
				String^ BrokerIDByBank;

				/// <summary>
				/// 期货单位帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankSecuAcc;

				/// <summary>
				/// 银行密码标志
				/// </summary>
				CtpNetPwdFlagType BankPwdFlag;

				/// <summary>
				/// 期货资金密码核对标志
				/// </summary>
				CtpNetPwdFlagType SecuPwdFlag;

				/// <summary>
				/// 交易柜员
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ OperNo;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 交易ID
				/// </summary>
				int TID;

				/// <summary>
				/// 转账交易状态
				/// </summary>
				CtpNetTransferStatusType TransferStatus;

				/// <summary>
				/// 错误代码
				/// </summary>
				int ErrorID;

				/// <summary>
				/// 错误信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ ErrorMsg;

				/// <summary>
				/// 长客户姓名
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 161)]
				String^ LongCustomerName;
			};

			/// <summary>
			/// 冲正请求
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetReqRepealField
			{
				/// <summary>
				/// 冲正时间间隔
				/// </summary>
				int RepealTimeInterval;

				/// <summary>
				/// 已经冲正次数
				/// </summary>
				int RepealedTimes;

				/// <summary>
				/// 银行冲正标志
				/// </summary>
				CtpNetBankRepealFlagType BankRepealFlag;

				/// <summary>
				/// 期商冲正标志
				/// </summary>
				CtpNetBrokerRepealFlagType BrokerRepealFlag;

				/// <summary>
				/// 被冲正平台流水号
				/// </summary>
				int PlateRepealSerial;

				/// <summary>
				/// 被冲正银行流水号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ BankRepealSerial;

				/// <summary>
				/// 被冲正期货流水号
				/// </summary>
				int FutureRepealSerial;

				/// <summary>
				/// 业务功能码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ TradeCode;

				/// <summary>
				/// 银行代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ BankID;

				/// <summary>
				/// 银行分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
				String^ BankBranchID;

				/// <summary>
				/// 期商代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 期商分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ BrokerBranchID;

				/// <summary>
				/// 交易日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeDate;

				/// <summary>
				/// 交易时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeTime;

				/// <summary>
				/// 银行流水号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ BankSerial;

				/// <summary>
				/// 交易系统日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 银期平台消息流水号
				/// </summary>
				int PlateSerial;

				/// <summary>
				/// 最后分片标志
				/// </summary>
				CtpNetLastFragmentType LastFragment;

				/// <summary>
				/// 会话号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 客户姓名
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
				String^ CustomerName;

				/// <summary>
				/// 证件类型
				/// </summary>
				CtpNetIdCardTypeType IdCardType;

				/// <summary>
				/// 证件号码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
				String^ IdentifiedCardNo;

				/// <summary>
				/// 客户类型
				/// </summary>
				CtpNetCustTypeType CustType;

				/// <summary>
				/// 银行帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankAccount;

				/// <summary>
				/// 银行密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankPassWord;

				/// <summary>
				/// 投资者帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 期货密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Password;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 期货公司流水号
				/// </summary>
				int FutureSerial;

				/// <summary>
				/// 用户标识
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 验证客户证件号码标志
				/// </summary>
				CtpNetYesNoIndicatorType VerifyCertNoFlag;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// 转帐金额
				/// </summary>
				double TradeAmount;

				/// <summary>
				/// 期货可取金额
				/// </summary>
				double FutureFetchAmount;

				/// <summary>
				/// 费用支付标志
				/// </summary>
				CtpNetFeePayFlagType FeePayFlag;

				/// <summary>
				/// 应收客户费用
				/// </summary>
				double CustFee;

				/// <summary>
				/// 应收期货公司费用
				/// </summary>
				double BrokerFee;

				/// <summary>
				/// 发送方给接收方的消息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
				String^ Message;

				/// <summary>
				/// 摘要
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
				String^ Digest;

				/// <summary>
				/// 银行帐号类型
				/// </summary>
				CtpNetBankAccTypeType BankAccType;

				/// <summary>
				/// 渠道标志
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
				String^ DeviceID;

				/// <summary>
				/// 期货单位帐号类型
				/// </summary>
				CtpNetBankAccTypeType BankSecuAccType;

				/// <summary>
				/// 期货公司银行编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
				String^ BrokerIDByBank;

				/// <summary>
				/// 期货单位帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankSecuAcc;

				/// <summary>
				/// 银行密码标志
				/// </summary>
				CtpNetPwdFlagType BankPwdFlag;

				/// <summary>
				/// 期货资金密码核对标志
				/// </summary>
				CtpNetPwdFlagType SecuPwdFlag;

				/// <summary>
				/// 交易柜员
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ OperNo;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 交易ID
				/// </summary>
				int TID;

				/// <summary>
				/// 转账交易状态
				/// </summary>
				CtpNetTransferStatusType TransferStatus;

				/// <summary>
				/// 长客户姓名
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 161)]
				String^ LongCustomerName;
			};

			/// <summary>
			/// 冲正响应
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetRspRepealField
			{
				/// <summary>
				/// 冲正时间间隔
				/// </summary>
				int RepealTimeInterval;

				/// <summary>
				/// 已经冲正次数
				/// </summary>
				int RepealedTimes;

				/// <summary>
				/// 银行冲正标志
				/// </summary>
				CtpNetBankRepealFlagType BankRepealFlag;

				/// <summary>
				/// 期商冲正标志
				/// </summary>
				CtpNetBrokerRepealFlagType BrokerRepealFlag;

				/// <summary>
				/// 被冲正平台流水号
				/// </summary>
				int PlateRepealSerial;

				/// <summary>
				/// 被冲正银行流水号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ BankRepealSerial;

				/// <summary>
				/// 被冲正期货流水号
				/// </summary>
				int FutureRepealSerial;

				/// <summary>
				/// 业务功能码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ TradeCode;

				/// <summary>
				/// 银行代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ BankID;

				/// <summary>
				/// 银行分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
				String^ BankBranchID;

				/// <summary>
				/// 期商代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 期商分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ BrokerBranchID;

				/// <summary>
				/// 交易日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeDate;

				/// <summary>
				/// 交易时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeTime;

				/// <summary>
				/// 银行流水号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ BankSerial;

				/// <summary>
				/// 交易系统日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 银期平台消息流水号
				/// </summary>
				int PlateSerial;

				/// <summary>
				/// 最后分片标志
				/// </summary>
				CtpNetLastFragmentType LastFragment;

				/// <summary>
				/// 会话号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 客户姓名
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
				String^ CustomerName;

				/// <summary>
				/// 证件类型
				/// </summary>
				CtpNetIdCardTypeType IdCardType;

				/// <summary>
				/// 证件号码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
				String^ IdentifiedCardNo;

				/// <summary>
				/// 客户类型
				/// </summary>
				CtpNetCustTypeType CustType;

				/// <summary>
				/// 银行帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankAccount;

				/// <summary>
				/// 银行密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankPassWord;

				/// <summary>
				/// 投资者帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 期货密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Password;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 期货公司流水号
				/// </summary>
				int FutureSerial;

				/// <summary>
				/// 用户标识
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 验证客户证件号码标志
				/// </summary>
				CtpNetYesNoIndicatorType VerifyCertNoFlag;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// 转帐金额
				/// </summary>
				double TradeAmount;

				/// <summary>
				/// 期货可取金额
				/// </summary>
				double FutureFetchAmount;

				/// <summary>
				/// 费用支付标志
				/// </summary>
				CtpNetFeePayFlagType FeePayFlag;

				/// <summary>
				/// 应收客户费用
				/// </summary>
				double CustFee;

				/// <summary>
				/// 应收期货公司费用
				/// </summary>
				double BrokerFee;

				/// <summary>
				/// 发送方给接收方的消息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
				String^ Message;

				/// <summary>
				/// 摘要
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
				String^ Digest;

				/// <summary>
				/// 银行帐号类型
				/// </summary>
				CtpNetBankAccTypeType BankAccType;

				/// <summary>
				/// 渠道标志
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
				String^ DeviceID;

				/// <summary>
				/// 期货单位帐号类型
				/// </summary>
				CtpNetBankAccTypeType BankSecuAccType;

				/// <summary>
				/// 期货公司银行编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
				String^ BrokerIDByBank;

				/// <summary>
				/// 期货单位帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankSecuAcc;

				/// <summary>
				/// 银行密码标志
				/// </summary>
				CtpNetPwdFlagType BankPwdFlag;

				/// <summary>
				/// 期货资金密码核对标志
				/// </summary>
				CtpNetPwdFlagType SecuPwdFlag;

				/// <summary>
				/// 交易柜员
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ OperNo;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 交易ID
				/// </summary>
				int TID;

				/// <summary>
				/// 转账交易状态
				/// </summary>
				CtpNetTransferStatusType TransferStatus;

				/// <summary>
				/// 错误代码
				/// </summary>
				int ErrorID;

				/// <summary>
				/// 错误信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ ErrorMsg;

				/// <summary>
				/// 长客户姓名
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 161)]
				String^ LongCustomerName;
			};

			/// <summary>
			/// 查询账户信息请求
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetReqQueryAccountField
			{
				/// <summary>
				/// 业务功能码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ TradeCode;

				/// <summary>
				/// 银行代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ BankID;

				/// <summary>
				/// 银行分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
				String^ BankBranchID;

				/// <summary>
				/// 期商代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 期商分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ BrokerBranchID;

				/// <summary>
				/// 交易日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeDate;

				/// <summary>
				/// 交易时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeTime;

				/// <summary>
				/// 银行流水号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ BankSerial;

				/// <summary>
				/// 交易系统日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 银期平台消息流水号
				/// </summary>
				int PlateSerial;

				/// <summary>
				/// 最后分片标志
				/// </summary>
				CtpNetLastFragmentType LastFragment;

				/// <summary>
				/// 会话号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 客户姓名
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
				String^ CustomerName;

				/// <summary>
				/// 证件类型
				/// </summary>
				CtpNetIdCardTypeType IdCardType;

				/// <summary>
				/// 证件号码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
				String^ IdentifiedCardNo;

				/// <summary>
				/// 客户类型
				/// </summary>
				CtpNetCustTypeType CustType;

				/// <summary>
				/// 银行帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankAccount;

				/// <summary>
				/// 银行密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankPassWord;

				/// <summary>
				/// 投资者帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 期货密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Password;

				/// <summary>
				/// 期货公司流水号
				/// </summary>
				int FutureSerial;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 用户标识
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 验证客户证件号码标志
				/// </summary>
				CtpNetYesNoIndicatorType VerifyCertNoFlag;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// 摘要
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
				String^ Digest;

				/// <summary>
				/// 银行帐号类型
				/// </summary>
				CtpNetBankAccTypeType BankAccType;

				/// <summary>
				/// 渠道标志
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
				String^ DeviceID;

				/// <summary>
				/// 期货单位帐号类型
				/// </summary>
				CtpNetBankAccTypeType BankSecuAccType;

				/// <summary>
				/// 期货公司银行编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
				String^ BrokerIDByBank;

				/// <summary>
				/// 期货单位帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankSecuAcc;

				/// <summary>
				/// 银行密码标志
				/// </summary>
				CtpNetPwdFlagType BankPwdFlag;

				/// <summary>
				/// 期货资金密码核对标志
				/// </summary>
				CtpNetPwdFlagType SecuPwdFlag;

				/// <summary>
				/// 交易柜员
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ OperNo;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 交易ID
				/// </summary>
				int TID;

				/// <summary>
				/// 长客户姓名
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 161)]
				String^ LongCustomerName;
			};

			/// <summary>
			/// 查询账户信息响应
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetRspQueryAccountField
			{
				/// <summary>
				/// 业务功能码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ TradeCode;

				/// <summary>
				/// 银行代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ BankID;

				/// <summary>
				/// 银行分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
				String^ BankBranchID;

				/// <summary>
				/// 期商代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 期商分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ BrokerBranchID;

				/// <summary>
				/// 交易日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeDate;

				/// <summary>
				/// 交易时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeTime;

				/// <summary>
				/// 银行流水号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ BankSerial;

				/// <summary>
				/// 交易系统日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 银期平台消息流水号
				/// </summary>
				int PlateSerial;

				/// <summary>
				/// 最后分片标志
				/// </summary>
				CtpNetLastFragmentType LastFragment;

				/// <summary>
				/// 会话号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 客户姓名
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
				String^ CustomerName;

				/// <summary>
				/// 证件类型
				/// </summary>
				CtpNetIdCardTypeType IdCardType;

				/// <summary>
				/// 证件号码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
				String^ IdentifiedCardNo;

				/// <summary>
				/// 客户类型
				/// </summary>
				CtpNetCustTypeType CustType;

				/// <summary>
				/// 银行帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankAccount;

				/// <summary>
				/// 银行密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankPassWord;

				/// <summary>
				/// 投资者帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 期货密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Password;

				/// <summary>
				/// 期货公司流水号
				/// </summary>
				int FutureSerial;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 用户标识
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 验证客户证件号码标志
				/// </summary>
				CtpNetYesNoIndicatorType VerifyCertNoFlag;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// 摘要
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
				String^ Digest;

				/// <summary>
				/// 银行帐号类型
				/// </summary>
				CtpNetBankAccTypeType BankAccType;

				/// <summary>
				/// 渠道标志
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
				String^ DeviceID;

				/// <summary>
				/// 期货单位帐号类型
				/// </summary>
				CtpNetBankAccTypeType BankSecuAccType;

				/// <summary>
				/// 期货公司银行编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
				String^ BrokerIDByBank;

				/// <summary>
				/// 期货单位帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankSecuAcc;

				/// <summary>
				/// 银行密码标志
				/// </summary>
				CtpNetPwdFlagType BankPwdFlag;

				/// <summary>
				/// 期货资金密码核对标志
				/// </summary>
				CtpNetPwdFlagType SecuPwdFlag;

				/// <summary>
				/// 交易柜员
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ OperNo;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 交易ID
				/// </summary>
				int TID;

				/// <summary>
				/// 银行可用金额
				/// </summary>
				double BankUseAmount;

				/// <summary>
				/// 银行可取金额
				/// </summary>
				double BankFetchAmount;

				/// <summary>
				/// 长客户姓名
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 161)]
				String^ LongCustomerName;
			};

			/// <summary>
			/// 期商签到签退
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetFutureSignIOField
			{
				/// <summary>
				/// 业务功能码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ TradeCode;

				/// <summary>
				/// 银行代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ BankID;

				/// <summary>
				/// 银行分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
				String^ BankBranchID;

				/// <summary>
				/// 期商代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 期商分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ BrokerBranchID;

				/// <summary>
				/// 交易日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeDate;

				/// <summary>
				/// 交易时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeTime;

				/// <summary>
				/// 银行流水号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ BankSerial;

				/// <summary>
				/// 交易系统日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 银期平台消息流水号
				/// </summary>
				int PlateSerial;

				/// <summary>
				/// 最后分片标志
				/// </summary>
				CtpNetLastFragmentType LastFragment;

				/// <summary>
				/// 会话号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 用户标识
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 摘要
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
				String^ Digest;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// 渠道标志
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
				String^ DeviceID;

				/// <summary>
				/// 期货公司银行编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
				String^ BrokerIDByBank;

				/// <summary>
				/// 交易柜员
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ OperNo;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 交易ID
				/// </summary>
				int TID;
			};

			/// <summary>
			/// 期商签到响应
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetRspFutureSignInField
			{
				/// <summary>
				/// 业务功能码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ TradeCode;

				/// <summary>
				/// 银行代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ BankID;

				/// <summary>
				/// 银行分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
				String^ BankBranchID;

				/// <summary>
				/// 期商代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 期商分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ BrokerBranchID;

				/// <summary>
				/// 交易日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeDate;

				/// <summary>
				/// 交易时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeTime;

				/// <summary>
				/// 银行流水号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ BankSerial;

				/// <summary>
				/// 交易系统日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 银期平台消息流水号
				/// </summary>
				int PlateSerial;

				/// <summary>
				/// 最后分片标志
				/// </summary>
				CtpNetLastFragmentType LastFragment;

				/// <summary>
				/// 会话号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 用户标识
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 摘要
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
				String^ Digest;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// 渠道标志
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
				String^ DeviceID;

				/// <summary>
				/// 期货公司银行编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
				String^ BrokerIDByBank;

				/// <summary>
				/// 交易柜员
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ OperNo;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 交易ID
				/// </summary>
				int TID;

				/// <summary>
				/// 错误代码
				/// </summary>
				int ErrorID;

				/// <summary>
				/// 错误信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ ErrorMsg;

				/// <summary>
				/// PIN密钥
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
				String^ PinKey;

				/// <summary>
				/// MAC密钥
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
				String^ MacKey;
			};

			/// <summary>
			/// 期商签退请求
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetReqFutureSignOutField
			{
				/// <summary>
				/// 业务功能码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ TradeCode;

				/// <summary>
				/// 银行代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ BankID;

				/// <summary>
				/// 银行分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
				String^ BankBranchID;

				/// <summary>
				/// 期商代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 期商分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ BrokerBranchID;

				/// <summary>
				/// 交易日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeDate;

				/// <summary>
				/// 交易时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeTime;

				/// <summary>
				/// 银行流水号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ BankSerial;

				/// <summary>
				/// 交易系统日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 银期平台消息流水号
				/// </summary>
				int PlateSerial;

				/// <summary>
				/// 最后分片标志
				/// </summary>
				CtpNetLastFragmentType LastFragment;

				/// <summary>
				/// 会话号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 用户标识
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 摘要
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
				String^ Digest;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// 渠道标志
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
				String^ DeviceID;

				/// <summary>
				/// 期货公司银行编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
				String^ BrokerIDByBank;

				/// <summary>
				/// 交易柜员
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ OperNo;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 交易ID
				/// </summary>
				int TID;
			};

			/// <summary>
			/// 期商签退响应
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetRspFutureSignOutField
			{
				/// <summary>
				/// 业务功能码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ TradeCode;

				/// <summary>
				/// 银行代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ BankID;

				/// <summary>
				/// 银行分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
				String^ BankBranchID;

				/// <summary>
				/// 期商代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 期商分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ BrokerBranchID;

				/// <summary>
				/// 交易日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeDate;

				/// <summary>
				/// 交易时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeTime;

				/// <summary>
				/// 银行流水号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ BankSerial;

				/// <summary>
				/// 交易系统日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 银期平台消息流水号
				/// </summary>
				int PlateSerial;

				/// <summary>
				/// 最后分片标志
				/// </summary>
				CtpNetLastFragmentType LastFragment;

				/// <summary>
				/// 会话号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 用户标识
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 摘要
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
				String^ Digest;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// 渠道标志
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
				String^ DeviceID;

				/// <summary>
				/// 期货公司银行编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
				String^ BrokerIDByBank;

				/// <summary>
				/// 交易柜员
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ OperNo;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 交易ID
				/// </summary>
				int TID;

				/// <summary>
				/// 错误代码
				/// </summary>
				int ErrorID;

				/// <summary>
				/// 错误信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ ErrorMsg;
			};

			/// <summary>
			/// 查询指定流水号的交易结果请求
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetReqQueryTradeResultBySerialField
			{
				/// <summary>
				/// 业务功能码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ TradeCode;

				/// <summary>
				/// 银行代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ BankID;

				/// <summary>
				/// 银行分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
				String^ BankBranchID;

				/// <summary>
				/// 期商代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 期商分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ BrokerBranchID;

				/// <summary>
				/// 交易日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeDate;

				/// <summary>
				/// 交易时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeTime;

				/// <summary>
				/// 银行流水号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ BankSerial;

				/// <summary>
				/// 交易系统日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 银期平台消息流水号
				/// </summary>
				int PlateSerial;

				/// <summary>
				/// 最后分片标志
				/// </summary>
				CtpNetLastFragmentType LastFragment;

				/// <summary>
				/// 会话号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 流水号
				/// </summary>
				int Reference;

				/// <summary>
				/// 本流水号发布者的机构类型
				/// </summary>
				CtpNetInstitutionTypeType RefrenceIssureType;

				/// <summary>
				/// 本流水号发布者机构编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
				String^ RefrenceIssure;

				/// <summary>
				/// 客户姓名
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
				String^ CustomerName;

				/// <summary>
				/// 证件类型
				/// </summary>
				CtpNetIdCardTypeType IdCardType;

				/// <summary>
				/// 证件号码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
				String^ IdentifiedCardNo;

				/// <summary>
				/// 客户类型
				/// </summary>
				CtpNetCustTypeType CustType;

				/// <summary>
				/// 银行帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankAccount;

				/// <summary>
				/// 银行密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankPassWord;

				/// <summary>
				/// 投资者帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 期货密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Password;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// 转帐金额
				/// </summary>
				double TradeAmount;

				/// <summary>
				/// 摘要
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
				String^ Digest;

				/// <summary>
				/// 长客户姓名
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 161)]
				String^ LongCustomerName;
			};

			/// <summary>
			/// 查询指定流水号的交易结果响应
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetRspQueryTradeResultBySerialField
			{
				/// <summary>
				/// 业务功能码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ TradeCode;

				/// <summary>
				/// 银行代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ BankID;

				/// <summary>
				/// 银行分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
				String^ BankBranchID;

				/// <summary>
				/// 期商代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 期商分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ BrokerBranchID;

				/// <summary>
				/// 交易日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeDate;

				/// <summary>
				/// 交易时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeTime;

				/// <summary>
				/// 银行流水号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ BankSerial;

				/// <summary>
				/// 交易系统日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 银期平台消息流水号
				/// </summary>
				int PlateSerial;

				/// <summary>
				/// 最后分片标志
				/// </summary>
				CtpNetLastFragmentType LastFragment;

				/// <summary>
				/// 会话号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 错误代码
				/// </summary>
				int ErrorID;

				/// <summary>
				/// 错误信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ ErrorMsg;

				/// <summary>
				/// 流水号
				/// </summary>
				int Reference;

				/// <summary>
				/// 本流水号发布者的机构类型
				/// </summary>
				CtpNetInstitutionTypeType RefrenceIssureType;

				/// <summary>
				/// 本流水号发布者机构编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
				String^ RefrenceIssure;

				/// <summary>
				/// 原始返回代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ OriginReturnCode;

				/// <summary>
				/// 原始返回码描述
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
				String^ OriginDescrInfoForReturnCode;

				/// <summary>
				/// 银行帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankAccount;

				/// <summary>
				/// 银行密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankPassWord;

				/// <summary>
				/// 投资者帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 期货密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Password;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// 转帐金额
				/// </summary>
				double TradeAmount;

				/// <summary>
				/// 摘要
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
				String^ Digest;
			};

			/// <summary>
			/// 日终文件就绪请求
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetReqDayEndFileReadyField
			{
				/// <summary>
				/// 业务功能码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ TradeCode;

				/// <summary>
				/// 银行代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ BankID;

				/// <summary>
				/// 银行分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
				String^ BankBranchID;

				/// <summary>
				/// 期商代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 期商分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ BrokerBranchID;

				/// <summary>
				/// 交易日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeDate;

				/// <summary>
				/// 交易时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeTime;

				/// <summary>
				/// 银行流水号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ BankSerial;

				/// <summary>
				/// 交易系统日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 银期平台消息流水号
				/// </summary>
				int PlateSerial;

				/// <summary>
				/// 最后分片标志
				/// </summary>
				CtpNetLastFragmentType LastFragment;

				/// <summary>
				/// 会话号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 文件业务功能
				/// </summary>
				CtpNetFileBusinessCodeType FileBusinessCode;

				/// <summary>
				/// 摘要
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
				String^ Digest;
			};

			/// <summary>
			/// 返回结果
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetReturnResultField
			{
				/// <summary>
				/// 返回代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ ReturnCode;

				/// <summary>
				/// 返回码描述
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
				String^ DescrInfoForReturnCode;
			};

			/// <summary>
			/// 验证期货资金密码
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetVerifyFuturePasswordField
			{
				/// <summary>
				/// 业务功能码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ TradeCode;

				/// <summary>
				/// 银行代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ BankID;

				/// <summary>
				/// 银行分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
				String^ BankBranchID;

				/// <summary>
				/// 期商代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 期商分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ BrokerBranchID;

				/// <summary>
				/// 交易日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeDate;

				/// <summary>
				/// 交易时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeTime;

				/// <summary>
				/// 银行流水号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ BankSerial;

				/// <summary>
				/// 交易系统日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 银期平台消息流水号
				/// </summary>
				int PlateSerial;

				/// <summary>
				/// 最后分片标志
				/// </summary>
				CtpNetLastFragmentType LastFragment;

				/// <summary>
				/// 会话号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 投资者帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 期货密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Password;

				/// <summary>
				/// 银行帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankAccount;

				/// <summary>
				/// 银行密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankPassWord;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 交易ID
				/// </summary>
				int TID;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;
			};

			/// <summary>
			/// 验证客户信息
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetVerifyCustInfoField
			{
				/// <summary>
				/// 客户姓名
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
				String^ CustomerName;

				/// <summary>
				/// 证件类型
				/// </summary>
				CtpNetIdCardTypeType IdCardType;

				/// <summary>
				/// 证件号码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
				String^ IdentifiedCardNo;

				/// <summary>
				/// 客户类型
				/// </summary>
				CtpNetCustTypeType CustType;

				/// <summary>
				/// 长客户姓名
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 161)]
				String^ LongCustomerName;
			};

			/// <summary>
			/// 验证期货资金密码和客户信息
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetVerifyFuturePasswordAndCustInfoField
			{
				/// <summary>
				/// 客户姓名
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
				String^ CustomerName;

				/// <summary>
				/// 证件类型
				/// </summary>
				CtpNetIdCardTypeType IdCardType;

				/// <summary>
				/// 证件号码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
				String^ IdentifiedCardNo;

				/// <summary>
				/// 客户类型
				/// </summary>
				CtpNetCustTypeType CustType;

				/// <summary>
				/// 投资者帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 期货密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Password;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// 长客户姓名
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 161)]
				String^ LongCustomerName;
			};

			/// <summary>
			/// 验证期货资金密码和客户信息
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetDepositResultInformField
			{
				/// <summary>
				/// 出入金流水号，该流水号为银期报盘返回的流水号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
				String^ DepositSeqNo;

				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 入金金额
				/// </summary>
				double Deposit;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 返回代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ ReturnCode;

				/// <summary>
				/// 返回码描述
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
				String^ DescrInfoForReturnCode;
			};

			/// <summary>
			/// 交易核心向银期报盘发出密钥同步请求
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetReqSyncKeyField
			{
				/// <summary>
				/// 业务功能码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ TradeCode;

				/// <summary>
				/// 银行代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ BankID;

				/// <summary>
				/// 银行分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
				String^ BankBranchID;

				/// <summary>
				/// 期商代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 期商分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ BrokerBranchID;

				/// <summary>
				/// 交易日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeDate;

				/// <summary>
				/// 交易时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeTime;

				/// <summary>
				/// 银行流水号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ BankSerial;

				/// <summary>
				/// 交易系统日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 银期平台消息流水号
				/// </summary>
				int PlateSerial;

				/// <summary>
				/// 最后分片标志
				/// </summary>
				CtpNetLastFragmentType LastFragment;

				/// <summary>
				/// 会话号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 用户标识
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 交易核心给银期报盘的消息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
				String^ Message;

				/// <summary>
				/// 渠道标志
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
				String^ DeviceID;

				/// <summary>
				/// 期货公司银行编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
				String^ BrokerIDByBank;

				/// <summary>
				/// 交易柜员
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ OperNo;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 交易ID
				/// </summary>
				int TID;
			};

			/// <summary>
			/// 交易核心向银期报盘发出密钥同步响应
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetRspSyncKeyField
			{
				/// <summary>
				/// 业务功能码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ TradeCode;

				/// <summary>
				/// 银行代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ BankID;

				/// <summary>
				/// 银行分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
				String^ BankBranchID;

				/// <summary>
				/// 期商代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 期商分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ BrokerBranchID;

				/// <summary>
				/// 交易日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeDate;

				/// <summary>
				/// 交易时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeTime;

				/// <summary>
				/// 银行流水号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ BankSerial;

				/// <summary>
				/// 交易系统日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 银期平台消息流水号
				/// </summary>
				int PlateSerial;

				/// <summary>
				/// 最后分片标志
				/// </summary>
				CtpNetLastFragmentType LastFragment;

				/// <summary>
				/// 会话号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 用户标识
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 交易核心给银期报盘的消息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
				String^ Message;

				/// <summary>
				/// 渠道标志
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
				String^ DeviceID;

				/// <summary>
				/// 期货公司银行编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
				String^ BrokerIDByBank;

				/// <summary>
				/// 交易柜员
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ OperNo;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 交易ID
				/// </summary>
				int TID;

				/// <summary>
				/// 错误代码
				/// </summary>
				int ErrorID;

				/// <summary>
				/// 错误信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ ErrorMsg;
			};

			/// <summary>
			/// 查询账户信息通知
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetNotifyQueryAccountField
			{
				/// <summary>
				/// 业务功能码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ TradeCode;

				/// <summary>
				/// 银行代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ BankID;

				/// <summary>
				/// 银行分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
				String^ BankBranchID;

				/// <summary>
				/// 期商代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 期商分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ BrokerBranchID;

				/// <summary>
				/// 交易日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeDate;

				/// <summary>
				/// 交易时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeTime;

				/// <summary>
				/// 银行流水号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ BankSerial;

				/// <summary>
				/// 交易系统日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 银期平台消息流水号
				/// </summary>
				int PlateSerial;

				/// <summary>
				/// 最后分片标志
				/// </summary>
				CtpNetLastFragmentType LastFragment;

				/// <summary>
				/// 会话号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 客户姓名
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
				String^ CustomerName;

				/// <summary>
				/// 证件类型
				/// </summary>
				CtpNetIdCardTypeType IdCardType;

				/// <summary>
				/// 证件号码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
				String^ IdentifiedCardNo;

				/// <summary>
				/// 客户类型
				/// </summary>
				CtpNetCustTypeType CustType;

				/// <summary>
				/// 银行帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankAccount;

				/// <summary>
				/// 银行密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankPassWord;

				/// <summary>
				/// 投资者帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 期货密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Password;

				/// <summary>
				/// 期货公司流水号
				/// </summary>
				int FutureSerial;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 用户标识
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 验证客户证件号码标志
				/// </summary>
				CtpNetYesNoIndicatorType VerifyCertNoFlag;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// 摘要
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
				String^ Digest;

				/// <summary>
				/// 银行帐号类型
				/// </summary>
				CtpNetBankAccTypeType BankAccType;

				/// <summary>
				/// 渠道标志
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
				String^ DeviceID;

				/// <summary>
				/// 期货单位帐号类型
				/// </summary>
				CtpNetBankAccTypeType BankSecuAccType;

				/// <summary>
				/// 期货公司银行编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
				String^ BrokerIDByBank;

				/// <summary>
				/// 期货单位帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankSecuAcc;

				/// <summary>
				/// 银行密码标志
				/// </summary>
				CtpNetPwdFlagType BankPwdFlag;

				/// <summary>
				/// 期货资金密码核对标志
				/// </summary>
				CtpNetPwdFlagType SecuPwdFlag;

				/// <summary>
				/// 交易柜员
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ OperNo;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 交易ID
				/// </summary>
				int TID;

				/// <summary>
				/// 银行可用金额
				/// </summary>
				double BankUseAmount;

				/// <summary>
				/// 银行可取金额
				/// </summary>
				double BankFetchAmount;

				/// <summary>
				/// 错误代码
				/// </summary>
				int ErrorID;

				/// <summary>
				/// 错误信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ ErrorMsg;

				/// <summary>
				/// 长客户姓名
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 161)]
				String^ LongCustomerName;
			};

			/// <summary>
			/// 银期转账交易流水表
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetTransferSerialField
			{
				/// <summary>
				/// 平台流水号
				/// </summary>
				int PlateSerial;

				/// <summary>
				/// 交易发起方日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeDate;

				/// <summary>
				/// 交易日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 交易时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeTime;

				/// <summary>
				/// 交易代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ TradeCode;

				/// <summary>
				/// 会话编号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 银行编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ BankID;

				/// <summary>
				/// 银行分支机构编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
				String^ BankBranchID;

				/// <summary>
				/// 银行帐号类型
				/// </summary>
				CtpNetBankAccTypeType BankAccType;

				/// <summary>
				/// 银行帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankAccount;

				/// <summary>
				/// 银行流水号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ BankSerial;

				/// <summary>
				/// 期货公司编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 期商分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ BrokerBranchID;

				/// <summary>
				/// 期货公司帐号类型
				/// </summary>
				CtpNetFutureAccTypeType FutureAccType;

				/// <summary>
				/// 投资者帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;

				/// <summary>
				/// 期货公司流水号
				/// </summary>
				int FutureSerial;

				/// <summary>
				/// 证件类型
				/// </summary>
				CtpNetIdCardTypeType IdCardType;

				/// <summary>
				/// 证件号码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
				String^ IdentifiedCardNo;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// 交易金额
				/// </summary>
				double TradeAmount;

				/// <summary>
				/// 应收客户费用
				/// </summary>
				double CustFee;

				/// <summary>
				/// 应收期货公司费用
				/// </summary>
				double BrokerFee;

				/// <summary>
				/// 有效标志
				/// </summary>
				CtpNetAvailabilityFlagType AvailabilityFlag;

				/// <summary>
				/// 操作员
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ OperatorCode;

				/// <summary>
				/// 新银行帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankNewAccount;

				/// <summary>
				/// 错误代码
				/// </summary>
				int ErrorID;

				/// <summary>
				/// 错误信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ ErrorMsg;
			};

			/// <summary>
			/// 请求查询转帐流水
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryTransferSerialField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 银行编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ BankID;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;
			};

			/// <summary>
			/// 期商签到通知
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetNotifyFutureSignInField
			{
				/// <summary>
				/// 业务功能码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ TradeCode;

				/// <summary>
				/// 银行代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ BankID;

				/// <summary>
				/// 银行分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
				String^ BankBranchID;

				/// <summary>
				/// 期商代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 期商分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ BrokerBranchID;

				/// <summary>
				/// 交易日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeDate;

				/// <summary>
				/// 交易时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeTime;

				/// <summary>
				/// 银行流水号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ BankSerial;

				/// <summary>
				/// 交易系统日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 银期平台消息流水号
				/// </summary>
				int PlateSerial;

				/// <summary>
				/// 最后分片标志
				/// </summary>
				CtpNetLastFragmentType LastFragment;

				/// <summary>
				/// 会话号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 用户标识
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 摘要
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
				String^ Digest;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// 渠道标志
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
				String^ DeviceID;

				/// <summary>
				/// 期货公司银行编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
				String^ BrokerIDByBank;

				/// <summary>
				/// 交易柜员
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ OperNo;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 交易ID
				/// </summary>
				int TID;

				/// <summary>
				/// 错误代码
				/// </summary>
				int ErrorID;

				/// <summary>
				/// 错误信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ ErrorMsg;

				/// <summary>
				/// PIN密钥
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
				String^ PinKey;

				/// <summary>
				/// MAC密钥
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
				String^ MacKey;
			};

			/// <summary>
			/// 期商签退通知
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetNotifyFutureSignOutField
			{
				/// <summary>
				/// 业务功能码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ TradeCode;

				/// <summary>
				/// 银行代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ BankID;

				/// <summary>
				/// 银行分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
				String^ BankBranchID;

				/// <summary>
				/// 期商代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 期商分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ BrokerBranchID;

				/// <summary>
				/// 交易日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeDate;

				/// <summary>
				/// 交易时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeTime;

				/// <summary>
				/// 银行流水号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ BankSerial;

				/// <summary>
				/// 交易系统日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 银期平台消息流水号
				/// </summary>
				int PlateSerial;

				/// <summary>
				/// 最后分片标志
				/// </summary>
				CtpNetLastFragmentType LastFragment;

				/// <summary>
				/// 会话号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 用户标识
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 摘要
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
				String^ Digest;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// 渠道标志
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
				String^ DeviceID;

				/// <summary>
				/// 期货公司银行编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
				String^ BrokerIDByBank;

				/// <summary>
				/// 交易柜员
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ OperNo;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 交易ID
				/// </summary>
				int TID;

				/// <summary>
				/// 错误代码
				/// </summary>
				int ErrorID;

				/// <summary>
				/// 错误信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ ErrorMsg;
			};

			/// <summary>
			/// 交易核心向银期报盘发出密钥同步处理结果的通知
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetNotifySyncKeyField
			{
				/// <summary>
				/// 业务功能码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ TradeCode;

				/// <summary>
				/// 银行代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ BankID;

				/// <summary>
				/// 银行分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
				String^ BankBranchID;

				/// <summary>
				/// 期商代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 期商分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ BrokerBranchID;

				/// <summary>
				/// 交易日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeDate;

				/// <summary>
				/// 交易时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeTime;

				/// <summary>
				/// 银行流水号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ BankSerial;

				/// <summary>
				/// 交易系统日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 银期平台消息流水号
				/// </summary>
				int PlateSerial;

				/// <summary>
				/// 最后分片标志
				/// </summary>
				CtpNetLastFragmentType LastFragment;

				/// <summary>
				/// 会话号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 用户标识
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 交易核心给银期报盘的消息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
				String^ Message;

				/// <summary>
				/// 渠道标志
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
				String^ DeviceID;

				/// <summary>
				/// 期货公司银行编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
				String^ BrokerIDByBank;

				/// <summary>
				/// 交易柜员
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ OperNo;

				/// <summary>
				/// 请求编号
				/// </summary>
				int RequestID;

				/// <summary>
				/// 交易ID
				/// </summary>
				int TID;

				/// <summary>
				/// 错误代码
				/// </summary>
				int ErrorID;

				/// <summary>
				/// 错误信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ ErrorMsg;
			};

			/// <summary>
			/// 请求查询银期签约关系
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryAccountregisterField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 银行编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ BankID;

				/// <summary>
				/// 银行分支机构编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
				String^ BankBranchID;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;
			};

			/// <summary>
			/// 客户开销户信息表
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetAccountregisterField
			{
				/// <summary>
				/// 交易日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeDay;

				/// <summary>
				/// 银行编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ BankID;

				/// <summary>
				/// 银行分支机构编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
				String^ BankBranchID;

				/// <summary>
				/// 银行帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankAccount;

				/// <summary>
				/// 期货公司编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 期货公司分支机构编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ BrokerBranchID;

				/// <summary>
				/// 投资者帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 证件类型
				/// </summary>
				CtpNetIdCardTypeType IdCardType;

				/// <summary>
				/// 证件号码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
				String^ IdentifiedCardNo;

				/// <summary>
				/// 客户姓名
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
				String^ CustomerName;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// 开销户类别
				/// </summary>
				CtpNetOpenOrDestroyType OpenOrDestroy;

				/// <summary>
				/// 签约日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ RegDate;

				/// <summary>
				/// 解约日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ OutDate;

				/// <summary>
				/// 交易ID
				/// </summary>
				int TID;

				/// <summary>
				/// 客户类型
				/// </summary>
				CtpNetCustTypeType CustType;

				/// <summary>
				/// 银行帐号类型
				/// </summary>
				CtpNetBankAccTypeType BankAccType;

				/// <summary>
				/// 长客户姓名
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 161)]
				String^ LongCustomerName;
			};

			/// <summary>
			/// 银期开户信息
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetOpenAccountField
			{
				/// <summary>
				/// 业务功能码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ TradeCode;

				/// <summary>
				/// 银行代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ BankID;

				/// <summary>
				/// 银行分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
				String^ BankBranchID;

				/// <summary>
				/// 期商代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 期商分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ BrokerBranchID;

				/// <summary>
				/// 交易日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeDate;

				/// <summary>
				/// 交易时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeTime;

				/// <summary>
				/// 银行流水号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ BankSerial;

				/// <summary>
				/// 交易系统日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 银期平台消息流水号
				/// </summary>
				int PlateSerial;

				/// <summary>
				/// 最后分片标志
				/// </summary>
				CtpNetLastFragmentType LastFragment;

				/// <summary>
				/// 会话号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 客户姓名
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
				String^ CustomerName;

				/// <summary>
				/// 证件类型
				/// </summary>
				CtpNetIdCardTypeType IdCardType;

				/// <summary>
				/// 证件号码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
				String^ IdentifiedCardNo;

				/// <summary>
				/// 性别
				/// </summary>
				CtpNetGenderType Gender;

				/// <summary>
				/// 国家代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ CountryCode;

				/// <summary>
				/// 客户类型
				/// </summary>
				CtpNetCustTypeType CustType;

				/// <summary>
				/// 地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 101)]
				String^ Address;

				/// <summary>
				/// 邮编
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ ZipCode;

				/// <summary>
				/// 电话号码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Telephone;

				/// <summary>
				/// 手机
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MobilePhone;

				/// <summary>
				/// 传真
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Fax;

				/// <summary>
				/// 电子邮件
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ EMail;

				/// <summary>
				/// 资金账户状态
				/// </summary>
				CtpNetMoneyAccountStatusType MoneyAccountStatus;

				/// <summary>
				/// 银行帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankAccount;

				/// <summary>
				/// 银行密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankPassWord;

				/// <summary>
				/// 投资者帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 期货密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Password;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 验证客户证件号码标志
				/// </summary>
				CtpNetYesNoIndicatorType VerifyCertNoFlag;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// 汇钞标志
				/// </summary>
				CtpNetCashExchangeCodeType CashExchangeCode;

				/// <summary>
				/// 摘要
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
				String^ Digest;

				/// <summary>
				/// 银行帐号类型
				/// </summary>
				CtpNetBankAccTypeType BankAccType;

				/// <summary>
				/// 渠道标志
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
				String^ DeviceID;

				/// <summary>
				/// 期货单位帐号类型
				/// </summary>
				CtpNetBankAccTypeType BankSecuAccType;

				/// <summary>
				/// 期货公司银行编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
				String^ BrokerIDByBank;

				/// <summary>
				/// 期货单位帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankSecuAcc;

				/// <summary>
				/// 银行密码标志
				/// </summary>
				CtpNetPwdFlagType BankPwdFlag;

				/// <summary>
				/// 期货资金密码核对标志
				/// </summary>
				CtpNetPwdFlagType SecuPwdFlag;

				/// <summary>
				/// 交易柜员
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ OperNo;

				/// <summary>
				/// 交易ID
				/// </summary>
				int TID;

				/// <summary>
				/// 用户标识
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 错误代码
				/// </summary>
				int ErrorID;

				/// <summary>
				/// 错误信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ ErrorMsg;

				/// <summary>
				/// 长客户姓名
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 161)]
				String^ LongCustomerName;
			};

			/// <summary>
			/// 银期销户信息
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetCancelAccountField
			{
				/// <summary>
				/// 业务功能码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ TradeCode;

				/// <summary>
				/// 银行代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ BankID;

				/// <summary>
				/// 银行分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
				String^ BankBranchID;

				/// <summary>
				/// 期商代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 期商分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ BrokerBranchID;

				/// <summary>
				/// 交易日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeDate;

				/// <summary>
				/// 交易时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeTime;

				/// <summary>
				/// 银行流水号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ BankSerial;

				/// <summary>
				/// 交易系统日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 银期平台消息流水号
				/// </summary>
				int PlateSerial;

				/// <summary>
				/// 最后分片标志
				/// </summary>
				CtpNetLastFragmentType LastFragment;

				/// <summary>
				/// 会话号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 客户姓名
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
				String^ CustomerName;

				/// <summary>
				/// 证件类型
				/// </summary>
				CtpNetIdCardTypeType IdCardType;

				/// <summary>
				/// 证件号码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
				String^ IdentifiedCardNo;

				/// <summary>
				/// 性别
				/// </summary>
				CtpNetGenderType Gender;

				/// <summary>
				/// 国家代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ CountryCode;

				/// <summary>
				/// 客户类型
				/// </summary>
				CtpNetCustTypeType CustType;

				/// <summary>
				/// 地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 101)]
				String^ Address;

				/// <summary>
				/// 邮编
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ ZipCode;

				/// <summary>
				/// 电话号码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Telephone;

				/// <summary>
				/// 手机
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MobilePhone;

				/// <summary>
				/// 传真
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Fax;

				/// <summary>
				/// 电子邮件
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ EMail;

				/// <summary>
				/// 资金账户状态
				/// </summary>
				CtpNetMoneyAccountStatusType MoneyAccountStatus;

				/// <summary>
				/// 银行帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankAccount;

				/// <summary>
				/// 银行密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankPassWord;

				/// <summary>
				/// 投资者帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 期货密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Password;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 验证客户证件号码标志
				/// </summary>
				CtpNetYesNoIndicatorType VerifyCertNoFlag;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// 汇钞标志
				/// </summary>
				CtpNetCashExchangeCodeType CashExchangeCode;

				/// <summary>
				/// 摘要
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
				String^ Digest;

				/// <summary>
				/// 银行帐号类型
				/// </summary>
				CtpNetBankAccTypeType BankAccType;

				/// <summary>
				/// 渠道标志
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
				String^ DeviceID;

				/// <summary>
				/// 期货单位帐号类型
				/// </summary>
				CtpNetBankAccTypeType BankSecuAccType;

				/// <summary>
				/// 期货公司银行编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
				String^ BrokerIDByBank;

				/// <summary>
				/// 期货单位帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankSecuAcc;

				/// <summary>
				/// 银行密码标志
				/// </summary>
				CtpNetPwdFlagType BankPwdFlag;

				/// <summary>
				/// 期货资金密码核对标志
				/// </summary>
				CtpNetPwdFlagType SecuPwdFlag;

				/// <summary>
				/// 交易柜员
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
				String^ OperNo;

				/// <summary>
				/// 交易ID
				/// </summary>
				int TID;

				/// <summary>
				/// 用户标识
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 错误代码
				/// </summary>
				int ErrorID;

				/// <summary>
				/// 错误信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ ErrorMsg;

				/// <summary>
				/// 长客户姓名
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 161)]
				String^ LongCustomerName;
			};

			/// <summary>
			/// 银期变更银行账号信息
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetChangeAccountField
			{
				/// <summary>
				/// 业务功能码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ TradeCode;

				/// <summary>
				/// 银行代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ BankID;

				/// <summary>
				/// 银行分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
				String^ BankBranchID;

				/// <summary>
				/// 期商代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 期商分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ BrokerBranchID;

				/// <summary>
				/// 交易日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeDate;

				/// <summary>
				/// 交易时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeTime;

				/// <summary>
				/// 银行流水号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ BankSerial;

				/// <summary>
				/// 交易系统日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 银期平台消息流水号
				/// </summary>
				int PlateSerial;

				/// <summary>
				/// 最后分片标志
				/// </summary>
				CtpNetLastFragmentType LastFragment;

				/// <summary>
				/// 会话号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 客户姓名
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
				String^ CustomerName;

				/// <summary>
				/// 证件类型
				/// </summary>
				CtpNetIdCardTypeType IdCardType;

				/// <summary>
				/// 证件号码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
				String^ IdentifiedCardNo;

				/// <summary>
				/// 性别
				/// </summary>
				CtpNetGenderType Gender;

				/// <summary>
				/// 国家代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ CountryCode;

				/// <summary>
				/// 客户类型
				/// </summary>
				CtpNetCustTypeType CustType;

				/// <summary>
				/// 地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 101)]
				String^ Address;

				/// <summary>
				/// 邮编
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ ZipCode;

				/// <summary>
				/// 电话号码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Telephone;

				/// <summary>
				/// 手机
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MobilePhone;

				/// <summary>
				/// 传真
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Fax;

				/// <summary>
				/// 电子邮件
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ EMail;

				/// <summary>
				/// 资金账户状态
				/// </summary>
				CtpNetMoneyAccountStatusType MoneyAccountStatus;

				/// <summary>
				/// 银行帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankAccount;

				/// <summary>
				/// 银行密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankPassWord;

				/// <summary>
				/// 新银行帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ NewBankAccount;

				/// <summary>
				/// 新银行密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ NewBankPassWord;

				/// <summary>
				/// 投资者帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 期货密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Password;

				/// <summary>
				/// 银行帐号类型
				/// </summary>
				CtpNetBankAccTypeType BankAccType;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 验证客户证件号码标志
				/// </summary>
				CtpNetYesNoIndicatorType VerifyCertNoFlag;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// 期货公司银行编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
				String^ BrokerIDByBank;

				/// <summary>
				/// 银行密码标志
				/// </summary>
				CtpNetPwdFlagType BankPwdFlag;

				/// <summary>
				/// 期货资金密码核对标志
				/// </summary>
				CtpNetPwdFlagType SecuPwdFlag;

				/// <summary>
				/// 交易ID
				/// </summary>
				int TID;

				/// <summary>
				/// 摘要
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
				String^ Digest;

				/// <summary>
				/// 错误代码
				/// </summary>
				int ErrorID;

				/// <summary>
				/// 错误信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ ErrorMsg;

				/// <summary>
				/// 长客户姓名
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 161)]
				String^ LongCustomerName;
			};

			/// <summary>
			/// 二级代理操作员银期权限
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetSecAgentACIDMapField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 资金账户
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 币种
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// 境外中介机构资金帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ BrokerSecAgentID;
			};

			/// <summary>
			/// 二级代理操作员银期权限查询
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQrySecAgentACIDMapField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 资金账户
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 币种
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;
			};

			/// <summary>
			/// 灾备中心交易权限
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetUserRightsAssignField
			{
				/// <summary>
				/// 应用单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 交易中心代码
				/// </summary>
				int DRIdentityID;
			};

			/// <summary>
			/// 经济公司是否有在本标示的交易权限
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetBrokerUserRightAssignField
			{
				/// <summary>
				/// 应用单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 交易中心代码
				/// </summary>
				int DRIdentityID;

				/// <summary>
				/// 能否交易
				/// </summary>
				int Tradeable;
			};

			/// <summary>
			/// 灾备交易转换报文
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetDRTransferField
			{
				/// <summary>
				/// 原交易中心代码
				/// </summary>
				int OrigDRIdentityID;

				/// <summary>
				/// 目标交易中心代码
				/// </summary>
				int DestDRIdentityID;

				/// <summary>
				/// 原应用单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ OrigBrokerID;

				/// <summary>
				/// 目标易用单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ DestBrokerID;
			};

			/// <summary>
			/// Fens用户信息
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetFensUserInfoField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// 登录模式
				/// </summary>
				CtpNetLoginModeType LoginMode;
			};

			/// <summary>
			/// 当前银期所属交易中心
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetCurrTransferIdentityField
			{
				/// <summary>
				/// 交易中心代码
				/// </summary>
				int IdentityID;
			};

			/// <summary>
			/// 禁止登录用户
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetLoginForbiddenUserField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;

				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;
			};

			/// <summary>
			/// 查询禁止登录用户
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryLoginForbiddenUserField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;
			};

			/// <summary>
			/// UDP组播组信息
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetMulticastGroupInfoField
			{
				/// <summary>
				/// 组播组IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ GroupIP;

				/// <summary>
				/// 组播组IP端口
				/// </summary>
				int GroupPort;

				/// <summary>
				/// 源地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ SourceIP;
			};

			/// <summary>
			/// 资金账户基本准备金
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetTradingAccountReserveField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 基本准备金
				/// </summary>
				double Reserve;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;
			};

			/// <summary>
			/// 查询禁止登录IP
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryLoginForbiddenIPField
			{
				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;
			};

			/// <summary>
			/// 查询IP列表
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryIPListField
			{
				/// <summary>
				/// IP地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ IPAddress;
			};

			/// <summary>
			/// 查询用户下单权限分配表
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryUserRightsAssignField
			{
				/// <summary>
				/// 应用单元代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 用户代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
				String^ UserID;
			};

			/// <summary>
			/// 银期预约开户确认请求
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetReserveOpenAccountConfirmField
			{
				/// <summary>
				/// 业务功能码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ TradeCode;

				/// <summary>
				/// 银行代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ BankID;

				/// <summary>
				/// 银行分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
				String^ BankBranchID;

				/// <summary>
				/// 期商代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 期商分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ BrokerBranchID;

				/// <summary>
				/// 交易日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeDate;

				/// <summary>
				/// 交易时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeTime;

				/// <summary>
				/// 银行流水号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ BankSerial;

				/// <summary>
				/// 交易系统日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 银期平台消息流水号
				/// </summary>
				int PlateSerial;

				/// <summary>
				/// 最后分片标志
				/// </summary>
				CtpNetLastFragmentType LastFragment;

				/// <summary>
				/// 会话号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 客户姓名
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 161)]
				String^ CustomerName;

				/// <summary>
				/// 证件类型
				/// </summary>
				CtpNetIdCardTypeType IdCardType;

				/// <summary>
				/// 证件号码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
				String^ IdentifiedCardNo;

				/// <summary>
				/// 性别
				/// </summary>
				CtpNetGenderType Gender;

				/// <summary>
				/// 国家代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ CountryCode;

				/// <summary>
				/// 客户类型
				/// </summary>
				CtpNetCustTypeType CustType;

				/// <summary>
				/// 地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 101)]
				String^ Address;

				/// <summary>
				/// 邮编
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ ZipCode;

				/// <summary>
				/// 电话号码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Telephone;

				/// <summary>
				/// 手机
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MobilePhone;

				/// <summary>
				/// 传真
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Fax;

				/// <summary>
				/// 电子邮件
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ EMail;

				/// <summary>
				/// 资金账户状态
				/// </summary>
				CtpNetMoneyAccountStatusType MoneyAccountStatus;

				/// <summary>
				/// 银行帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankAccount;

				/// <summary>
				/// 银行密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankPassWord;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 验证客户证件号码标志
				/// </summary>
				CtpNetYesNoIndicatorType VerifyCertNoFlag;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// 摘要
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
				String^ Digest;

				/// <summary>
				/// 银行帐号类型
				/// </summary>
				CtpNetBankAccTypeType BankAccType;

				/// <summary>
				/// 期货公司银行编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
				String^ BrokerIDByBank;

				/// <summary>
				/// 交易ID
				/// </summary>
				int TID;

				/// <summary>
				/// 投资者帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 期货密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Password;

				/// <summary>
				/// 预约开户银行流水号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ BankReserveOpenSeq;

				/// <summary>
				/// 预约开户日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ BookDate;

				/// <summary>
				/// 预约开户验证密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BookPsw;

				/// <summary>
				/// 错误代码
				/// </summary>
				int ErrorID;

				/// <summary>
				/// 错误信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ ErrorMsg;
			};

			/// <summary>
			/// 银期预约开户
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetReserveOpenAccountField
			{
				/// <summary>
				/// 业务功能码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ TradeCode;

				/// <summary>
				/// 银行代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ BankID;

				/// <summary>
				/// 银行分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
				String^ BankBranchID;

				/// <summary>
				/// 期商代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 期商分支机构代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
				String^ BrokerBranchID;

				/// <summary>
				/// 交易日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeDate;

				/// <summary>
				/// 交易时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradeTime;

				/// <summary>
				/// 银行流水号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ BankSerial;

				/// <summary>
				/// 交易系统日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ TradingDay;

				/// <summary>
				/// 银期平台消息流水号
				/// </summary>
				int PlateSerial;

				/// <summary>
				/// 最后分片标志
				/// </summary>
				CtpNetLastFragmentType LastFragment;

				/// <summary>
				/// 会话号
				/// </summary>
				int SessionID;

				/// <summary>
				/// 客户姓名
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 161)]
				String^ CustomerName;

				/// <summary>
				/// 证件类型
				/// </summary>
				CtpNetIdCardTypeType IdCardType;

				/// <summary>
				/// 证件号码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
				String^ IdentifiedCardNo;

				/// <summary>
				/// 性别
				/// </summary>
				CtpNetGenderType Gender;

				/// <summary>
				/// 国家代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ CountryCode;

				/// <summary>
				/// 客户类型
				/// </summary>
				CtpNetCustTypeType CustType;

				/// <summary>
				/// 地址
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 101)]
				String^ Address;

				/// <summary>
				/// 邮编
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
				String^ ZipCode;

				/// <summary>
				/// 电话号码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Telephone;

				/// <summary>
				/// 手机
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
				String^ MobilePhone;

				/// <summary>
				/// 传真
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ Fax;

				/// <summary>
				/// 电子邮件
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ EMail;

				/// <summary>
				/// 资金账户状态
				/// </summary>
				CtpNetMoneyAccountStatusType MoneyAccountStatus;

				/// <summary>
				/// 银行帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankAccount;

				/// <summary>
				/// 银行密码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankPassWord;

				/// <summary>
				/// 安装编号
				/// </summary>
				int InstallID;

				/// <summary>
				/// 验证客户证件号码标志
				/// </summary>
				CtpNetYesNoIndicatorType VerifyCertNoFlag;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;

				/// <summary>
				/// 摘要
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
				String^ Digest;

				/// <summary>
				/// 银行帐号类型
				/// </summary>
				CtpNetBankAccTypeType BankAccType;

				/// <summary>
				/// 期货公司银行编码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
				String^ BrokerIDByBank;

				/// <summary>
				/// 交易ID
				/// </summary>
				int TID;

				/// <summary>
				/// 预约开户状态
				/// </summary>
				CtpNetReserveOpenAccStasType ReserveOpenAccStas;

				/// <summary>
				/// 错误代码
				/// </summary>
				int ErrorID;

				/// <summary>
				/// 错误信息
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
				String^ ErrorMsg;
			};

			/// <summary>
			/// 银行账户属性
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetAccountPropertyField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者帐号
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ AccountID;

				/// <summary>
				/// 银行统一标识类型
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ BankID;

				/// <summary>
				/// 银行账户
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
				String^ BankAccount;

				/// <summary>
				/// 银行账户的开户人名称
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 101)]
				String^ OpenName;

				/// <summary>
				/// 银行账户的开户行
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 101)]
				String^ OpenBank;

				/// <summary>
				/// 是否活跃
				/// </summary>
				int IsActive;

				/// <summary>
				/// 账户来源
				/// </summary>
				CtpNetAccountSourceTypeType AccountSourceType;

				/// <summary>
				/// 开户日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ OpenDate;

				/// <summary>
				/// 注销日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ CancelDate;

				/// <summary>
				/// 录入员代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 65)]
				String^ OperatorID;

				/// <summary>
				/// 录入日期
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ OperateDate;

				/// <summary>
				/// 录入时间
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
				String^ OperateTime;

				/// <summary>
				/// 币种代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
				String^ CurrencyID;
			};

			/// <summary>
			/// 查询当前交易中心
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQryCurrDRIdentityField
			{
				/// <summary>
				/// 交易中心代码
				/// </summary>
				int DRIdentityID;
			};

			/// <summary>
			/// 当前交易中心
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetCurrDRIdentityField
			{
				/// <summary>
				/// 交易中心代码
				/// </summary>
				int DRIdentityID;
			};

			/// <summary>
			/// 查询二级代理商资金校验模式
			/// </summary>
			[StructLayout(LayoutKind::Sequential)]
			public ref struct CtpNetQrySecAgentCheckModeField
			{
				/// <summary>
				/// 经纪公司代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
				String^ BrokerID;

				/// <summary>
				/// 投资者代码
				/// </summary>
				[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
				String^ InvestorID;
			};
		};
	};
};
