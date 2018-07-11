#pragma once

namespace TaiTanXing
{
   namespace Ctp
   {
       namespace CtpProxy
       {
           /// <summary>
           /// 网络流的重传方式
           /// </summary>
           public enum class CtpNetResumeType
           {
               /// <summary>
               /// 从本交易日开始重传(数值:0)
               /// </summary>
               Restart = 0,

               /// <summary>
               /// 从上次收到的续传(数值:1)
               /// </summary>
               Resume = 1,

               /// <summary>
               /// 只传送登录后私有流的内容(数值:2)
               /// </summary>
               Quick = 2
           };

           /// <summary>
           /// 交易所属性类型
           /// </summary>
           public enum class CtpNetExchangePropertyType
           {
               /// <summary>
               /// 正常(数值:48,字符:'0')
               /// </summary>
               Normal = 48,

               /// <summary>
               /// 根据成交生成报单(数值:49,字符:'1')
               /// </summary>
               GenOrderByTrade = 49
           };

           /// <summary>
           /// 证件类型
           /// </summary>
           public enum class CtpNetIdCardTypeType
           {
               /// <summary>
               /// 组织机构代码(数值:48,字符:'0')
               /// </summary>
               EID = 48,

               /// <summary>
               /// 中国公民身份证(数值:49,字符:'1')
               /// </summary>
               IDCard = 49,

               /// <summary>
               /// 军官证(数值:50,字符:'2')
               /// </summary>
               OfficerIDCard = 50,

               /// <summary>
               /// 警官证(数值:51,字符:'3')
               /// </summary>
               PoliceIDCard = 51,

               /// <summary>
               /// 士兵证(数值:52,字符:'4')
               /// </summary>
               SoldierIDCard = 52,

               /// <summary>
               /// 户口簿(数值:53,字符:'5')
               /// </summary>
               HouseholdRegister = 53,

               /// <summary>
               /// 护照(数值:54,字符:'6')
               /// </summary>
               Passport = 54,

               /// <summary>
               /// 台胞证(数值:55,字符:'7')
               /// </summary>
               TaiwanCompatriotIDCard = 55,

               /// <summary>
               /// 回乡证(数值:56,字符:'8')
               /// </summary>
               HomeComingCard = 56,

               /// <summary>
               /// 营业执照号(数值:57,字符:'9')
               /// </summary>
               LicenseNo = 57,

               /// <summary>
               /// 税务登记号/当地纳税ID(数值:65,字符:'A')
               /// </summary>
               TaxNo = 65,

               /// <summary>
               /// 港澳居民来往内地通行证(数值:66,字符:'B')
               /// </summary>
               HMMainlandTravelPermit = 66,

               /// <summary>
               /// 台湾居民来往大陆通行证(数值:67,字符:'C')
               /// </summary>
               TwMainlandTravelPermit = 67,

               /// <summary>
               /// 驾照(数值:68,字符:'D')
               /// </summary>
               DrivingLicense = 68,

               /// <summary>
               /// 当地社保ID(数值:70,字符:'F')
               /// </summary>
               SocialID = 70,

               /// <summary>
               /// 当地身份证(数值:71,字符:'G')
               /// </summary>
               LocalID = 71,

               /// <summary>
               /// 商业登记证(数值:72,字符:'H')
               /// </summary>
               BusinessRegistration = 72,

               /// <summary>
               /// 港澳永久性居民身份证(数值:73,字符:'I')
               /// </summary>
               HKMCIDCard = 73,

               /// <summary>
               /// 人行开户许可证(数值:74,字符:'J')
               /// </summary>
               AccountsPermits = 74,

               /// <summary>
               /// 其他证件(数值:120,字符:'x')
               /// </summary>
               OtherCard = 120
           };

           /// <summary>
           /// 投资者范围类型
           /// </summary>
           public enum class CtpNetInvestorRangeType
           {
               /// <summary>
               /// 所有(数值:49,字符:'1')
               /// </summary>
               All = 49,

               /// <summary>
               /// 投资者组(数值:50,字符:'2')
               /// </summary>
               Group = 50,

               /// <summary>
               /// 单一投资者(数值:51,字符:'3')
               /// </summary>
               Single = 51
           };

           /// <summary>
           /// 投资者范围类型
           /// </summary>
           public enum class CtpNetDepartmentRangeType
           {
               /// <summary>
               /// 所有(数值:49,字符:'1')
               /// </summary>
               All = 49,

               /// <summary>
               /// 组织架构(数值:50,字符:'2')
               /// </summary>
               Group = 50,

               /// <summary>
               /// 单一投资者(数值:51,字符:'3')
               /// </summary>
               Single = 51
           };

           /// <summary>
           /// 数据同步状态类型
           /// </summary>
           public enum class CtpNetDataSyncStatusType
           {
               /// <summary>
               /// 未同步(数值:49,字符:'1')
               /// </summary>
               Asynchronous = 49,

               /// <summary>
               /// 同步中(数值:50,字符:'2')
               /// </summary>
               Synchronizing = 50,

               /// <summary>
               /// 已同步(数值:51,字符:'3')
               /// </summary>
               Synchronized = 51
           };

           /// <summary>
           /// 经纪公司数据同步状态类型
           /// </summary>
           public enum class CtpNetBrokerDataSyncStatusType
           {
               /// <summary>
               /// 已同步(数值:49,字符:'1')
               /// </summary>
               Synchronized = 49,

               /// <summary>
               /// 同步中(数值:50,字符:'2')
               /// </summary>
               Synchronizing = 50
           };

           /// <summary>
           /// 交易所连接状态类型
           /// </summary>
           public enum class CtpNetExchangeConnectStatusType
           {
               /// <summary>
               /// 没有任何连接(数值:49,字符:'1')
               /// </summary>
               NoConnection = 49,

               /// <summary>
               /// 已经发出合约查询请求(数值:50,字符:'2')
               /// </summary>
               QryInstrumentSent = 50,

               /// <summary>
               /// 已经获取信息(数值:57,字符:'9')
               /// </summary>
               GotInformation = 57
           };

           /// <summary>
           /// 交易所交易员连接状态类型
           /// </summary>
           public enum class CtpNetTraderConnectStatusType
           {
               /// <summary>
               /// 没有任何连接(数值:49,字符:'1')
               /// </summary>
               NotConnected = 49,

               /// <summary>
               /// 已经连接(数值:50,字符:'2')
               /// </summary>
               Connected = 50,

               /// <summary>
               /// 已经发出合约查询请求(数值:51,字符:'3')
               /// </summary>
               QryInstrumentSent = 51,

               /// <summary>
               /// 订阅私有流(数值:52,字符:'4')
               /// </summary>
               SubPrivateFlow = 52
           };

           /// <summary>
           /// 功能代码类型
           /// </summary>
           public enum class CtpNetFunctionCodeType
           {
               /// <summary>
               /// 数据异步化(数值:49,字符:'1')
               /// </summary>
               DataAsync = 49,

               /// <summary>
               /// 强制用户登出(数值:50,字符:'2')
               /// </summary>
               ForceUserLogout = 50,

               /// <summary>
               /// 变更管理用户口令(数值:51,字符:'3')
               /// </summary>
               UserPasswordUpdate = 51,

               /// <summary>
               /// 变更经纪公司口令(数值:52,字符:'4')
               /// </summary>
               BrokerPasswordUpdate = 52,

               /// <summary>
               /// 变更投资者口令(数值:53,字符:'5')
               /// </summary>
               InvestorPasswordUpdate = 53,

               /// <summary>
               /// 报单插入(数值:54,字符:'6')
               /// </summary>
               OrderInsert = 54,

               /// <summary>
               /// 报单操作(数值:55,字符:'7')
               /// </summary>
               OrderAction = 55,

               /// <summary>
               /// 同步系统数据(数值:56,字符:'8')
               /// </summary>
               SyncSystemData = 56,

               /// <summary>
               /// 同步经纪公司数据(数值:57,字符:'9')
               /// </summary>
               SyncBrokerData = 57,

               /// <summary>
               /// 批量同步经纪公司数据(数值:65,字符:'A')
               /// </summary>
               BachSyncBrokerData = 65,

               /// <summary>
               /// 超级查询(数值:66,字符:'B')
               /// </summary>
               SuperQuery = 66,

               /// <summary>
               /// 预埋报单插入(数值:67,字符:'C')
               /// </summary>
               ParkedOrderInsert = 67,

               /// <summary>
               /// 预埋报单操作(数值:68,字符:'D')
               /// </summary>
               ParkedOrderAction = 68,

               /// <summary>
               /// 同步动态令牌(数值:69,字符:'E')
               /// </summary>
               SyncOTP = 69,

               /// <summary>
               /// 删除未知单(数值:70,字符:'F')
               /// </summary>
               DeleteOrder = 70
           };

           /// <summary>
           /// 经纪公司功能代码类型
           /// </summary>
           public enum class CtpNetBrokerFunctionCodeType
           {
               /// <summary>
               /// 强制用户登出(数值:49,字符:'1')
               /// </summary>
               ForceUserLogout = 49,

               /// <summary>
               /// 变更用户口令(数值:50,字符:'2')
               /// </summary>
               UserPasswordUpdate = 50,

               /// <summary>
               /// 同步经纪公司数据(数值:51,字符:'3')
               /// </summary>
               SyncBrokerData = 51,

               /// <summary>
               /// 批量同步经纪公司数据(数值:52,字符:'4')
               /// </summary>
               BachSyncBrokerData = 52,

               /// <summary>
               /// 报单插入(数值:53,字符:'5')
               /// </summary>
               OrderInsert = 53,

               /// <summary>
               /// 报单操作(数值:54,字符:'6')
               /// </summary>
               OrderAction = 54,

               /// <summary>
               /// 全部查询(数值:55,字符:'7')
               /// </summary>
               AllQuery = 55,

               /// <summary>
               /// 系统功能：登入/登出/修改密码等(数值:97,字符:'a')
               /// </summary>
               log = 97,

               /// <summary>
               /// 基本查询：查询基础数据，如合约，交易所等常量(数值:98,字符:'b')
               /// </summary>
               BaseQry = 98,

               /// <summary>
               /// 交易查询：如查成交，委托(数值:99,字符:'c')
               /// </summary>
               TradeQry = 99,

               /// <summary>
               /// 交易功能：报单，撤单(数值:100,字符:'d')
               /// </summary>
               Trade = 100,

               /// <summary>
               /// 银期转账(数值:101,字符:'e')
               /// </summary>
               Virement = 101,

               /// <summary>
               /// 风险监控(数值:102,字符:'f')
               /// </summary>
               Risk = 102,

               /// <summary>
               /// 查询/管理：查询会话，踢人等(数值:103,字符:'g')
               /// </summary>
               Session = 103,

               /// <summary>
               /// 风控通知控制(数值:104,字符:'h')
               /// </summary>
               RiskNoticeCtl = 104,

               /// <summary>
               /// 风控通知发送(数值:105,字符:'i')
               /// </summary>
               RiskNotice = 105,

               /// <summary>
               /// 察看经纪公司资金权限(数值:106,字符:'j')
               /// </summary>
               BrokerDeposit = 106,

               /// <summary>
               /// 资金查询(数值:107,字符:'k')
               /// </summary>
               QueryFund = 107,

               /// <summary>
               /// 报单查询(数值:108,字符:'l')
               /// </summary>
               QueryOrder = 108,

               /// <summary>
               /// 成交查询(数值:109,字符:'m')
               /// </summary>
               QueryTrade = 109,

               /// <summary>
               /// 持仓查询(数值:110,字符:'n')
               /// </summary>
               QueryPosition = 110,

               /// <summary>
               /// 行情查询(数值:111,字符:'o')
               /// </summary>
               QueryMarketData = 111,

               /// <summary>
               /// 用户事件查询(数值:112,字符:'p')
               /// </summary>
               QueryUserEvent = 112,

               /// <summary>
               /// 风险通知查询(数值:113,字符:'q')
               /// </summary>
               QueryRiskNotify = 113,

               /// <summary>
               /// 出入金查询(数值:114,字符:'r')
               /// </summary>
               QueryFundChange = 114,

               /// <summary>
               /// 投资者信息查询(数值:115,字符:'s')
               /// </summary>
               QueryInvestor = 115,

               /// <summary>
               /// 交易编码查询(数值:116,字符:'t')
               /// </summary>
               QueryTradingCode = 116,

               /// <summary>
               /// 强平(数值:117,字符:'u')
               /// </summary>
               ForceClose = 117,

               /// <summary>
               /// 压力测试(数值:118,字符:'v')
               /// </summary>
               PressTest = 118,

               /// <summary>
               /// 权益反算(数值:119,字符:'w')
               /// </summary>
               RemainCalc = 119,

               /// <summary>
               /// 净持仓保证金指标(数值:120,字符:'x')
               /// </summary>
               NetPositionInd = 120,

               /// <summary>
               /// 风险预算(数值:121,字符:'y')
               /// </summary>
               RiskPredict = 121,

               /// <summary>
               /// 数据导出(数值:122,字符:'z')
               /// </summary>
               DataExport = 122,

               /// <summary>
               /// 风控指标设置(数值:65,字符:'A')
               /// </summary>
               RiskTargetSetup = 65,

               /// <summary>
               /// 行情预警(数值:66,字符:'B')
               /// </summary>
               MarketDataWarn = 66,

               /// <summary>
               /// 业务通知查询(数值:67,字符:'C')
               /// </summary>
               QryBizNotice = 67,

               /// <summary>
               /// 业务通知模板设置(数值:68,字符:'D')
               /// </summary>
               CfgBizNotice = 68,

               /// <summary>
               /// 同步动态令牌(数值:69,字符:'E')
               /// </summary>
               SyncOTP = 69,

               /// <summary>
               /// 发送业务通知(数值:70,字符:'F')
               /// </summary>
               SendBizNotice = 70,

               /// <summary>
               /// 风险级别标准设置(数值:71,字符:'G')
               /// </summary>
               CfgRiskLevelStd = 71,

               /// <summary>
               /// 交易终端应急功能(数值:72,字符:'H')
               /// </summary>
               TbCommand = 72,

               /// <summary>
               /// 删除未知单(数值:74,字符:'J')
               /// </summary>
               DeleteOrder = 74,

               /// <summary>
               /// 预埋报单插入(数值:75,字符:'K')
               /// </summary>
               ParkedOrderInsert = 75,

               /// <summary>
               /// 预埋报单操作(数值:76,字符:'L')
               /// </summary>
               ParkedOrderAction = 76,

               /// <summary>
               /// 资金不够仍允许行权(数值:77,字符:'M')
               /// </summary>
               ExecOrderNoCheck = 77,

               /// <summary>
               /// 指定(数值:78,字符:'N')
               /// </summary>
               Designate = 78,

               /// <summary>
               /// 证券处置(数值:79,字符:'O')
               /// </summary>
               StockDisposal = 79,

               /// <summary>
               /// 席位资金预警(数值:81,字符:'Q')
               /// </summary>
               BrokerDepositWarn = 81,

               /// <summary>
               /// 备兑不足预警(数值:83,字符:'S')
               /// </summary>
               CoverWarn = 83,

               /// <summary>
               /// 行权试算(数值:84,字符:'T')
               /// </summary>
               PreExecOrder = 84,

               /// <summary>
               /// 行权交收风险(数值:80,字符:'P')
               /// </summary>
               ExecOrderRisk = 80,

               /// <summary>
               /// 持仓限额预警(数值:85,字符:'U')
               /// </summary>
               PosiLimitWarn = 85,

               /// <summary>
               /// 持仓限额查询(数值:86,字符:'V')
               /// </summary>
               QryPosiLimit = 86,

               /// <summary>
               /// 银期签到签退(数值:87,字符:'W')
               /// </summary>
               FBSign = 87,

               /// <summary>
               /// 银期签约解约(数值:88,字符:'X')
               /// </summary>
               FBAccount = 88
           };

           /// <summary>
           /// 报单操作状态类型
           /// </summary>
           public enum class CtpNetOrderActionStatusType
           {
               /// <summary>
               /// 已经提交(数值:97,字符:'a')
               /// </summary>
               Submitted = 97,

               /// <summary>
               /// 已经接受(数值:98,字符:'b')
               /// </summary>
               Accepted = 98,

               /// <summary>
               /// 已经被拒绝(数值:99,字符:'c')
               /// </summary>
               Rejected = 99
           };

           /// <summary>
           /// 报单状态类型
           /// </summary>
           public enum class CtpNetOrderStatusType
           {
               /// <summary>
               /// 全部成交(数值:48,字符:'0')
               /// </summary>
               AllTraded = 48,

               /// <summary>
               /// 部分成交还在队列中(数值:49,字符:'1')
               /// </summary>
               PartTradedQueueing = 49,

               /// <summary>
               /// 部分成交不在队列中(数值:50,字符:'2')
               /// </summary>
               PartTradedNotQueueing = 50,

               /// <summary>
               /// 未成交还在队列中(数值:51,字符:'3')
               /// </summary>
               NoTradeQueueing = 51,

               /// <summary>
               /// 未成交不在队列中(数值:52,字符:'4')
               /// </summary>
               NoTradeNotQueueing = 52,

               /// <summary>
               /// 撤单(数值:53,字符:'5')
               /// </summary>
               Canceled = 53,

               /// <summary>
               /// 未知(数值:97,字符:'a')
               /// </summary>
               Unknown = 97,

               /// <summary>
               /// 尚未触发(数值:98,字符:'b')
               /// </summary>
               NotTouched = 98,

               /// <summary>
               /// 已触发(数值:99,字符:'c')
               /// </summary>
               Touched = 99
           };

           /// <summary>
           /// 报单提交状态类型
           /// </summary>
           public enum class CtpNetOrderSubmitStatusType
           {
               /// <summary>
               /// 已经提交(数值:48,字符:'0')
               /// </summary>
               InsertSubmitted = 48,

               /// <summary>
               /// 撤单已经提交(数值:49,字符:'1')
               /// </summary>
               CancelSubmitted = 49,

               /// <summary>
               /// 修改已经提交(数值:50,字符:'2')
               /// </summary>
               ModifySubmitted = 50,

               /// <summary>
               /// 已经接受(数值:51,字符:'3')
               /// </summary>
               Accepted = 51,

               /// <summary>
               /// 报单已经被拒绝(数值:52,字符:'4')
               /// </summary>
               InsertRejected = 52,

               /// <summary>
               /// 撤单已经被拒绝(数值:53,字符:'5')
               /// </summary>
               CancelRejected = 53,

               /// <summary>
               /// 改单已经被拒绝(数值:54,字符:'6')
               /// </summary>
               ModifyRejected = 54
           };

           /// <summary>
           /// 持仓日期类型
           /// </summary>
           public enum class CtpNetPositionDateType
           {
               /// <summary>
               /// 今日持仓(数值:49,字符:'1')
               /// </summary>
               Today = 49,

               /// <summary>
               /// 历史持仓(数值:50,字符:'2')
               /// </summary>
               History = 50
           };

           /// <summary>
           /// 持仓日期类型
           /// </summary>
           public enum class CtpNetPositionDateTypeType
           {
               /// <summary>
               /// 使用历史持仓(数值:49,字符:'1')
               /// </summary>
               UseHistory = 49,

               /// <summary>
               /// 不使用历史持仓(数值:50,字符:'2')
               /// </summary>
               NoUseHistory = 50
           };

           /// <summary>
           /// 交易角色类型
           /// </summary>
           public enum class CtpNetTradingRoleType
           {
               /// <summary>
               /// 代理(数值:49,字符:'1')
               /// </summary>
               Broker = 49,

               /// <summary>
               /// 自营(数值:50,字符:'2')
               /// </summary>
               Host = 50,

               /// <summary>
               /// 做市商(数值:51,字符:'3')
               /// </summary>
               Maker = 51
           };

           /// <summary>
           /// 产品类型
           /// </summary>
           public enum class CtpNetProductClassType
           {
               /// <summary>
               /// 期货(数值:49,字符:'1')
               /// </summary>
               Futures = 49,

               /// <summary>
               /// 期货期权(数值:50,字符:'2')
               /// </summary>
               Options = 50,

               /// <summary>
               /// 组合(数值:51,字符:'3')
               /// </summary>
               Combination = 51,

               /// <summary>
               /// 即期(数值:52,字符:'4')
               /// </summary>
               Spot = 52,

               /// <summary>
               /// 期转现(数值:53,字符:'5')
               /// </summary>
               EFP = 53,

               /// <summary>
               /// 现货期权(数值:54,字符:'6')
               /// </summary>
               SpotOption = 54
           };

           /// <summary>
           /// 合约生命周期状态类型
           /// </summary>
           public enum class CtpNetInstLifePhaseType
           {
               /// <summary>
               /// 未上市(数值:48,字符:'0')
               /// </summary>
               NotStart = 48,

               /// <summary>
               /// 上市(数值:49,字符:'1')
               /// </summary>
               Started = 49,

               /// <summary>
               /// 停牌(数值:50,字符:'2')
               /// </summary>
               Pause = 50,

               /// <summary>
               /// 到期(数值:51,字符:'3')
               /// </summary>
               Expired = 51
           };

           /// <summary>
           /// 买卖方向类型
           /// </summary>
           public enum class CtpNetDirectionType
           {
               /// <summary>
               /// 买(数值:48,字符:'0')
               /// </summary>
               Buy = 48,

               /// <summary>
               /// 卖(数值:49,字符:'1')
               /// </summary>
               Sell = 49
           };

           /// <summary>
           /// 持仓类型
           /// </summary>
           public enum class CtpNetPositionTypeType
           {
               /// <summary>
               /// 净持仓(数值:49,字符:'1')
               /// </summary>
               Net = 49,

               /// <summary>
               /// 综合持仓(数值:50,字符:'2')
               /// </summary>
               Gross = 50
           };

           /// <summary>
           /// 持仓多空方向类型
           /// </summary>
           public enum class CtpNetPosiDirectionType
           {
               /// <summary>
               /// 净(数值:49,字符:'1')
               /// </summary>
               Net = 49,

               /// <summary>
               /// 多头(数值:50,字符:'2')
               /// </summary>
               Long = 50,

               /// <summary>
               /// 空头(数值:51,字符:'3')
               /// </summary>
               Short = 51
           };

           /// <summary>
           /// 系统结算状态类型
           /// </summary>
           public enum class CtpNetSysSettlementStatusType
           {
               /// <summary>
               /// 不活跃(数值:49,字符:'1')
               /// </summary>
               NonActive = 49,

               /// <summary>
               /// 启动(数值:50,字符:'2')
               /// </summary>
               Startup = 50,

               /// <summary>
               /// 操作(数值:51,字符:'3')
               /// </summary>
               Operating = 51,

               /// <summary>
               /// 结算(数值:52,字符:'4')
               /// </summary>
               Settlement = 52,

               /// <summary>
               /// 结算完成(数值:53,字符:'5')
               /// </summary>
               SettlementFinished = 53
           };

           /// <summary>
           /// 费率属性类型
           /// </summary>
           public enum class CtpNetRatioAttrType
           {
               /// <summary>
               /// 交易费率(数值:48,字符:'0')
               /// </summary>
               Trade = 48,

               /// <summary>
               /// 结算费率(数值:49,字符:'1')
               /// </summary>
               Settlement = 49
           };

           /// <summary>
           /// 投机套保标志类型
           /// </summary>
           public enum class CtpNetHedgeFlagType
           {
               /// <summary>
               /// 投机(数值:49,字符:'1')
               /// </summary>
               Speculation = 49,

               /// <summary>
               /// 套利(数值:50,字符:'2')
               /// </summary>
               Arbitrage = 50,

               /// <summary>
               /// 套保(数值:51,字符:'3')
               /// </summary>
               Hedge = 51,

               /// <summary>
               /// 做市商(数值:53,字符:'5')
               /// </summary>
               MarketMaker = 53
           };

           /// <summary>
           /// 投机套保标志类型
           /// </summary>
           public enum class CtpNetBillHedgeFlagType
           {
               /// <summary>
               /// 投机(数值:49,字符:'1')
               /// </summary>
               Speculation = 49,

               /// <summary>
               /// 套利(数值:50,字符:'2')
               /// </summary>
               Arbitrage = 50,

               /// <summary>
               /// 套保(数值:51,字符:'3')
               /// </summary>
               Hedge = 51
           };

           /// <summary>
           /// 交易编码类型
           /// </summary>
           public enum class CtpNetClientIDTypeType
           {
               /// <summary>
               /// 投机(数值:49,字符:'1')
               /// </summary>
               Speculation = 49,

               /// <summary>
               /// 套利(数值:50,字符:'2')
               /// </summary>
               Arbitrage = 50,

               /// <summary>
               /// 套保(数值:51,字符:'3')
               /// </summary>
               Hedge = 51,

               /// <summary>
               /// 做市商(数值:53,字符:'5')
               /// </summary>
               MarketMaker = 53
           };

           /// <summary>
           /// 报单价格条件类型
           /// </summary>
           public enum class CtpNetOrderPriceTypeType
           {
               /// <summary>
               /// 任意价(数值:49,字符:'1')
               /// </summary>
               AnyPrice = 49,

               /// <summary>
               /// 限价(数值:50,字符:'2')
               /// </summary>
               LimitPrice = 50,

               /// <summary>
               /// 最优价(数值:51,字符:'3')
               /// </summary>
               BestPrice = 51,

               /// <summary>
               /// 最新价(数值:52,字符:'4')
               /// </summary>
               LastPrice = 52,

               /// <summary>
               /// 最新价浮动上浮1个ticks(数值:53,字符:'5')
               /// </summary>
               LastPricePlusOneTicks = 53,

               /// <summary>
               /// 最新价浮动上浮2个ticks(数值:54,字符:'6')
               /// </summary>
               LastPricePlusTwoTicks = 54,

               /// <summary>
               /// 最新价浮动上浮3个ticks(数值:55,字符:'7')
               /// </summary>
               LastPricePlusThreeTicks = 55,

               /// <summary>
               /// 卖一价(数值:56,字符:'8')
               /// </summary>
               AskPrice1 = 56,

               /// <summary>
               /// 卖一价浮动上浮1个ticks(数值:57,字符:'9')
               /// </summary>
               AskPrice1PlusOneTicks = 57,

               /// <summary>
               /// 卖一价浮动上浮2个ticks(数值:65,字符:'A')
               /// </summary>
               AskPrice1PlusTwoTicks = 65,

               /// <summary>
               /// 卖一价浮动上浮3个ticks(数值:66,字符:'B')
               /// </summary>
               AskPrice1PlusThreeTicks = 66,

               /// <summary>
               /// 买一价(数值:67,字符:'C')
               /// </summary>
               BidPrice1 = 67,

               /// <summary>
               /// 买一价浮动上浮1个ticks(数值:68,字符:'D')
               /// </summary>
               BidPrice1PlusOneTicks = 68,

               /// <summary>
               /// 买一价浮动上浮2个ticks(数值:69,字符:'E')
               /// </summary>
               BidPrice1PlusTwoTicks = 69,

               /// <summary>
               /// 买一价浮动上浮3个ticks(数值:70,字符:'F')
               /// </summary>
               BidPrice1PlusThreeTicks = 70,

               /// <summary>
               /// 五档价(数值:71,字符:'G')
               /// </summary>
               FiveLevelPrice = 71
           };

           /// <summary>
           /// 开平标志类型
           /// </summary>
           public enum class CtpNetOffsetFlagType
           {
               /// <summary>
               /// 开仓(数值:48,字符:'0')
               /// </summary>
               Open = 48,

               /// <summary>
               /// 平仓(数值:49,字符:'1')
               /// </summary>
               Close = 49,

               /// <summary>
               /// 强平(数值:50,字符:'2')
               /// </summary>
               ForceClose = 50,

               /// <summary>
               /// 平今(数值:51,字符:'3')
               /// </summary>
               CloseToday = 51,

               /// <summary>
               /// 平昨(数值:52,字符:'4')
               /// </summary>
               CloseYesterday = 52,

               /// <summary>
               /// 强减(数值:53,字符:'5')
               /// </summary>
               ForceOff = 53,

               /// <summary>
               /// 本地强平(数值:54,字符:'6')
               /// </summary>
               LocalForceClose = 54
           };

           /// <summary>
           /// 强平原因类型
           /// </summary>
           public enum class CtpNetForceCloseReasonType
           {
               /// <summary>
               /// 非强平(数值:48,字符:'0')
               /// </summary>
               NotForceClose = 48,

               /// <summary>
               /// 资金不足(数值:49,字符:'1')
               /// </summary>
               LackDeposit = 49,

               /// <summary>
               /// 客户超仓(数值:50,字符:'2')
               /// </summary>
               ClientOverPositionLimit = 50,

               /// <summary>
               /// 会员超仓(数值:51,字符:'3')
               /// </summary>
               MemberOverPositionLimit = 51,

               /// <summary>
               /// 持仓非整数倍(数值:52,字符:'4')
               /// </summary>
               NotMultiple = 52,

               /// <summary>
               /// 违规(数值:53,字符:'5')
               /// </summary>
               Violation = 53,

               /// <summary>
               /// 其它(数值:54,字符:'6')
               /// </summary>
               Other = 54,

               /// <summary>
               /// 自然人临近交割(数值:55,字符:'7')
               /// </summary>
               PersonDeliv = 55
           };

           /// <summary>
           /// 报单类型
           /// </summary>
           public enum class CtpNetOrderTypeType
           {
               /// <summary>
               /// 正常(数值:48,字符:'0')
               /// </summary>
               Normal = 48,

               /// <summary>
               /// 报价衍生(数值:49,字符:'1')
               /// </summary>
               DeriveFromQuote = 49,

               /// <summary>
               /// 组合衍生(数值:50,字符:'2')
               /// </summary>
               DeriveFromCombination = 50,

               /// <summary>
               /// 组合报单(数值:51,字符:'3')
               /// </summary>
               Combination = 51,

               /// <summary>
               /// 条件单(数值:52,字符:'4')
               /// </summary>
               ConditionalOrder = 52,

               /// <summary>
               /// 互换单(数值:53,字符:'5')
               /// </summary>
               Swap = 53
           };

           /// <summary>
           /// 有效期类型
           /// </summary>
           public enum class CtpNetTimeConditionType
           {
               /// <summary>
               /// 立即完成，否则撤销(数值:49,字符:'1')
               /// </summary>
               IOC = 49,

               /// <summary>
               /// 本节有效(数值:50,字符:'2')
               /// </summary>
               GFS = 50,

               /// <summary>
               /// 当日有效(数值:51,字符:'3')
               /// </summary>
               GFD = 51,

               /// <summary>
               /// 指定日期前有效(数值:52,字符:'4')
               /// </summary>
               GTD = 52,

               /// <summary>
               /// 撤销前有效(数值:53,字符:'5')
               /// </summary>
               GTC = 53,

               /// <summary>
               /// 集合竞价有效(数值:54,字符:'6')
               /// </summary>
               GFA = 54
           };

           /// <summary>
           /// 成交量类型
           /// </summary>
           public enum class CtpNetVolumeConditionType
           {
               /// <summary>
               /// 任何数量(数值:49,字符:'1')
               /// </summary>
               AV = 49,

               /// <summary>
               /// 最小数量(数值:50,字符:'2')
               /// </summary>
               MV = 50,

               /// <summary>
               /// 全部数量(数值:51,字符:'3')
               /// </summary>
               CV = 51
           };

           /// <summary>
           /// 触发条件类型
           /// </summary>
           public enum class CtpNetContingentConditionType
           {
               /// <summary>
               /// 立即(数值:49,字符:'1')
               /// </summary>
               Immediately = 49,

               /// <summary>
               /// 止损(数值:50,字符:'2')
               /// </summary>
               Touch = 50,

               /// <summary>
               /// 止赢(数值:51,字符:'3')
               /// </summary>
               TouchProfit = 51,

               /// <summary>
               /// 预埋单(数值:52,字符:'4')
               /// </summary>
               ParkedOrder = 52,

               /// <summary>
               /// 最新价大于条件价(数值:53,字符:'5')
               /// </summary>
               LastPriceGreaterThanStopPrice = 53,

               /// <summary>
               /// 最新价大于等于条件价(数值:54,字符:'6')
               /// </summary>
               LastPriceGreaterEqualStopPrice = 54,

               /// <summary>
               /// 最新价小于条件价(数值:55,字符:'7')
               /// </summary>
               LastPriceLesserThanStopPrice = 55,

               /// <summary>
               /// 最新价小于等于条件价(数值:56,字符:'8')
               /// </summary>
               LastPriceLesserEqualStopPrice = 56,

               /// <summary>
               /// 卖一价大于条件价(数值:57,字符:'9')
               /// </summary>
               AskPriceGreaterThanStopPrice = 57,

               /// <summary>
               /// 卖一价大于等于条件价(数值:65,字符:'A')
               /// </summary>
               AskPriceGreaterEqualStopPrice = 65,

               /// <summary>
               /// 卖一价小于条件价(数值:66,字符:'B')
               /// </summary>
               AskPriceLesserThanStopPrice = 66,

               /// <summary>
               /// 卖一价小于等于条件价(数值:67,字符:'C')
               /// </summary>
               AskPriceLesserEqualStopPrice = 67,

               /// <summary>
               /// 买一价大于条件价(数值:68,字符:'D')
               /// </summary>
               BidPriceGreaterThanStopPrice = 68,

               /// <summary>
               /// 买一价大于等于条件价(数值:69,字符:'E')
               /// </summary>
               BidPriceGreaterEqualStopPrice = 69,

               /// <summary>
               /// 买一价小于条件价(数值:70,字符:'F')
               /// </summary>
               BidPriceLesserThanStopPrice = 70,

               /// <summary>
               /// 买一价小于等于条件价(数值:72,字符:'H')
               /// </summary>
               BidPriceLesserEqualStopPrice = 72
           };

           /// <summary>
           /// 操作标志类型
           /// </summary>
           public enum class CtpNetActionFlagType
           {
               /// <summary>
               /// 删除(数值:48,字符:'0')
               /// </summary>
               Delete = 48,

               /// <summary>
               /// 修改(数值:51,字符:'3')
               /// </summary>
               Modify = 51
           };

           /// <summary>
           /// 交易权限类型
           /// </summary>
           public enum class CtpNetTradingRightType
           {
               /// <summary>
               /// 可以交易(数值:48,字符:'0')
               /// </summary>
               Allow = 48,

               /// <summary>
               /// 只能平仓(数值:49,字符:'1')
               /// </summary>
               CloseOnly = 49,

               /// <summary>
               /// 不能交易(数值:50,字符:'2')
               /// </summary>
               Forbidden = 50
           };

           /// <summary>
           /// 报单来源类型
           /// </summary>
           public enum class CtpNetOrderSourceType
           {
               /// <summary>
               /// 来自参与者(数值:48,字符:'0')
               /// </summary>
               Participant = 48,

               /// <summary>
               /// 来自管理员(数值:49,字符:'1')
               /// </summary>
               Administrator = 49
           };

           /// <summary>
           /// 成交类型
           /// </summary>
           public enum class CtpNetTradeTypeType
           {
               /// <summary>
               /// 组合持仓拆分为单一持仓,初始化不应包含该类型的持仓(数值:35,字符:'#')
               /// </summary>
               SplitCombination = 35,

               /// <summary>
               /// 普通成交(数值:48,字符:'0')
               /// </summary>
               Common = 48,

               /// <summary>
               /// 期权执行(数值:49,字符:'1')
               /// </summary>
               OptionsExecution = 49,

               /// <summary>
               /// OTC成交(数值:50,字符:'2')
               /// </summary>
               OTC = 50,

               /// <summary>
               /// 期转现衍生成交(数值:51,字符:'3')
               /// </summary>
               EFPDerived = 51,

               /// <summary>
               /// 组合衍生成交(数值:52,字符:'4')
               /// </summary>
               CombinationDerived = 52
           };

           /// <summary>
           /// 成交价来源类型
           /// </summary>
           public enum class CtpNetPriceSourceType
           {
               /// <summary>
               /// 前成交价(数值:48,字符:'0')
               /// </summary>
               LastPrice = 48,

               /// <summary>
               /// 买委托价(数值:49,字符:'1')
               /// </summary>
               Buy = 49,

               /// <summary>
               /// 卖委托价(数值:50,字符:'2')
               /// </summary>
               Sell = 50
           };

           /// <summary>
           /// 合约交易状态类型
           /// </summary>
           public enum class CtpNetInstrumentStatusType
           {
               /// <summary>
               /// 开盘前(数值:48,字符:'0')
               /// </summary>
               BeforeTrading = 48,

               /// <summary>
               /// 非交易(数值:49,字符:'1')
               /// </summary>
               NoTrading = 49,

               /// <summary>
               /// 连续交易(数值:50,字符:'2')
               /// </summary>
               Continous = 50,

               /// <summary>
               /// 集合竞价报单(数值:51,字符:'3')
               /// </summary>
               AuctionOrdering = 51,

               /// <summary>
               /// 集合竞价价格平衡(数值:52,字符:'4')
               /// </summary>
               AuctionBalance = 52,

               /// <summary>
               /// 集合竞价撮合(数值:53,字符:'5')
               /// </summary>
               AuctionMatch = 53,

               /// <summary>
               /// 收盘(数值:54,字符:'6')
               /// </summary>
               Closed = 54
           };

           /// <summary>
           /// 品种进入交易状态原因类型
           /// </summary>
           public enum class CtpNetInstStatusEnterReasonType
           {
               /// <summary>
               /// 自动切换(数值:49,字符:'1')
               /// </summary>
               Automatic = 49,

               /// <summary>
               /// 手动切换(数值:50,字符:'2')
               /// </summary>
               Manual = 50,

               /// <summary>
               /// 熔断(数值:51,字符:'3')
               /// </summary>
               Fuse = 51
           };

           /// <summary>
           /// 处理状态类型
           /// </summary>
           public enum class CtpNetBatchStatusType
           {
               /// <summary>
               /// 未上传(数值:49,字符:'1')
               /// </summary>
               NoUpload = 49,

               /// <summary>
               /// 已上传(数值:50,字符:'2')
               /// </summary>
               Uploaded = 50,

               /// <summary>
               /// 审核失败(数值:51,字符:'3')
               /// </summary>
               Failed = 51
           };

           /// <summary>
           /// 按品种返还方式类型
           /// </summary>
           public enum class CtpNetReturnStyleType
           {
               /// <summary>
               /// 按所有品种(数值:49,字符:'1')
               /// </summary>
               All = 49,

               /// <summary>
               /// 按品种(数值:50,字符:'2')
               /// </summary>
               ByProduct = 50
           };

           /// <summary>
           /// 返还模式类型
           /// </summary>
           public enum class CtpNetReturnPatternType
           {
               /// <summary>
               /// 按成交手数(数值:49,字符:'1')
               /// </summary>
               ByVolume = 49,

               /// <summary>
               /// 按留存手续费(数值:50,字符:'2')
               /// </summary>
               ByFeeOnHand = 50
           };

           /// <summary>
           /// 返还级别类型
           /// </summary>
           public enum class CtpNetReturnLevelType
           {
               /// <summary>
               /// 级别1(数值:49,字符:'1')
               /// </summary>
               Level1 = 49,

               /// <summary>
               /// 级别2(数值:50,字符:'2')
               /// </summary>
               Level2 = 50,

               /// <summary>
               /// 级别3(数值:51,字符:'3')
               /// </summary>
               Level3 = 51,

               /// <summary>
               /// 级别4(数值:52,字符:'4')
               /// </summary>
               Level4 = 52,

               /// <summary>
               /// 级别5(数值:53,字符:'5')
               /// </summary>
               Level5 = 53,

               /// <summary>
               /// 级别6(数值:54,字符:'6')
               /// </summary>
               Level6 = 54,

               /// <summary>
               /// 级别7(数值:55,字符:'7')
               /// </summary>
               Level7 = 55,

               /// <summary>
               /// 级别8(数值:56,字符:'8')
               /// </summary>
               Level8 = 56,

               /// <summary>
               /// 级别9(数值:57,字符:'9')
               /// </summary>
               Level9 = 57
           };

           /// <summary>
           /// 返还标准类型
           /// </summary>
           public enum class CtpNetReturnStandardType
           {
               /// <summary>
               /// 分阶段返还(数值:49,字符:'1')
               /// </summary>
               ByPeriod = 49,

               /// <summary>
               /// 按某一标准(数值:50,字符:'2')
               /// </summary>
               ByStandard = 50
           };

           /// <summary>
           /// 质押类型
           /// </summary>
           public enum class CtpNetMortgageTypeType
           {
               /// <summary>
               /// 质出(数值:48,字符:'0')
               /// </summary>
               Out = 48,

               /// <summary>
               /// 质入(数值:49,字符:'1')
               /// </summary>
               In = 49
           };

           /// <summary>
           /// 投资者结算参数代码类型
           /// </summary>
           public enum class CtpNetInvestorSettlementParamIDType
           {
               /// <summary>
               /// 质押比例(数值:52,字符:'4')
               /// </summary>
               MortgageRatio = 52,

               /// <summary>
               /// 保证金算法(数值:53,字符:'5')
               /// </summary>
               MarginWay = 53,

               /// <summary>
               /// 结算单结存是否包含质押(数值:57,字符:'9')
               /// </summary>
               BillDeposit = 57
           };

           /// <summary>
           /// 交易所结算参数代码类型
           /// </summary>
           public enum class CtpNetExchangeSettlementParamIDType
           {
               /// <summary>
               /// 质押比例(数值:49,字符:'1')
               /// </summary>
               MortgageRatio = 49,

               /// <summary>
               /// 分项资金导入项(数值:50,字符:'2')
               /// </summary>
               OtherFundItem = 50,

               /// <summary>
               /// 分项资金入交易所出入金(数值:51,字符:'3')
               /// </summary>
               OtherFundImport = 51,

               /// <summary>
               /// 中金所开户最低可用金额(数值:54,字符:'6')
               /// </summary>
               CFFEXMinPrepa = 54,

               /// <summary>
               /// 郑商所结算方式(数值:55,字符:'7')
               /// </summary>
               CZCESettlementType = 55,

               /// <summary>
               /// 交易所交割手续费收取方式(数值:57,字符:'9')
               /// </summary>
               ExchDelivFeeMode = 57,

               /// <summary>
               /// 投资者交割手续费收取方式(数值:48,字符:'0')
               /// </summary>
               DelivFeeMode = 48,

               /// <summary>
               /// 郑商所组合持仓保证金收取方式(数值:65,字符:'A')
               /// </summary>
               CZCEComMarginType = 65,

               /// <summary>
               /// 大商所套利保证金是否优惠(数值:66,字符:'B')
               /// </summary>
               DceComMarginType = 66,

               /// <summary>
               /// 虚值期权保证金优惠比率(数值:97,字符:'a')
               /// </summary>
               OptOutDisCountRate = 97,

               /// <summary>
               /// 最低保障系数(数值:98,字符:'b')
               /// </summary>
               OptMiniGuarantee = 98
           };

           /// <summary>
           /// 系统参数代码类型
           /// </summary>
           public enum class CtpNetSystemParamIDType
           {
               /// <summary>
               /// 投资者代码最小长度(数值:49,字符:'1')
               /// </summary>
               InvestorIDMinLength = 49,

               /// <summary>
               /// 投资者帐号代码最小长度(数值:50,字符:'2')
               /// </summary>
               AccountIDMinLength = 50,

               /// <summary>
               /// 投资者开户默认登录权限(数值:51,字符:'3')
               /// </summary>
               UserRightLogon = 51,

               /// <summary>
               /// 投资者交易结算单成交汇总方式(数值:52,字符:'4')
               /// </summary>
               SettlementBillTrade = 52,

               /// <summary>
               /// 统一开户更新交易编码方式(数值:53,字符:'5')
               /// </summary>
               TradingCode = 53,

               /// <summary>
               /// 结算是否判断存在未复核的出入金和分项资金(数值:54,字符:'6')
               /// </summary>
               CheckFund = 54,

               /// <summary>
               /// 是否启用手续费模板数据权限(数值:55,字符:'7')
               /// </summary>
               CommModelRight = 55,

               /// <summary>
               /// 是否启用保证金率模板数据权限(数值:57,字符:'9')
               /// </summary>
               MarginModelRight = 57,

               /// <summary>
               /// 是否规范用户才能激活(数值:56,字符:'8')
               /// </summary>
               IsStandardActive = 56,

               /// <summary>
               /// 上传的交易所结算文件路径(数值:85,字符:'U')
               /// </summary>
               UploadSettlementFile = 85,

               /// <summary>
               /// 上报保证金监控中心文件路径(数值:68,字符:'D')
               /// </summary>
               DownloadCSRCFile = 68,

               /// <summary>
               /// 生成的结算单文件路径(数值:83,字符:'S')
               /// </summary>
               SettlementBillFile = 83,

               /// <summary>
               /// 证监会文件标识(数值:67,字符:'C')
               /// </summary>
               CSRCOthersFile = 67,

               /// <summary>
               /// 投资者照片路径(数值:80,字符:'P')
               /// </summary>
               InvestorPhoto = 80,

               /// <summary>
               /// 全结经纪公司上传文件路径(数值:82,字符:'R')
               /// </summary>
               CSRCData = 82,

               /// <summary>
               /// 开户密码录入方式(数值:73,字符:'I')
               /// </summary>
               InvestorPwdModel = 73,

               /// <summary>
               /// 投资者中金所结算文件下载路径(数值:70,字符:'F')
               /// </summary>
               CFFEXInvestorSettleFile = 70,

               /// <summary>
               /// 投资者代码编码方式(数值:97,字符:'a')
               /// </summary>
               InvestorIDType = 97,

               /// <summary>
               /// 休眠户最高权益(数值:114,字符:'r')
               /// </summary>
               FreezeMaxReMain = 114,

               /// <summary>
               /// 手续费相关操作实时上场开关(数值:65,字符:'A')
               /// </summary>
               IsSync = 65,

               /// <summary>
               /// 解除开仓权限限制(数值:79,字符:'O')
               /// </summary>
               RelieveOpenLimit = 79,

               /// <summary>
               /// 是否规范用户才能休眠(数值:88,字符:'X')
               /// </summary>
               IsStandardFreeze = 88,

               /// <summary>
               /// 郑商所是否开放所有品种套保交易(数值:66,字符:'B')
               /// </summary>
               CZCENormalProductHedge = 66
           };

           /// <summary>
           /// 交易系统参数代码类型
           /// </summary>
           public enum class CtpNetTradeParamIDType
           {
               /// <summary>
               /// 系统加密算法(数值:69,字符:'E')
               /// </summary>
               EncryptionStandard = 69,

               /// <summary>
               /// 系统风险算法(数值:82,字符:'R')
               /// </summary>
               RiskMode = 82,

               /// <summary>
               /// 系统风险算法是否全局 0-否 1-是(数值:71,字符:'G')
               /// </summary>
               RiskModeGlobal = 71,

               /// <summary>
               /// 密码加密算法(数值:80,字符:'P')
               /// </summary>
               modeEncode = 80,

               /// <summary>
               /// 价格小数位数参数(数值:84,字符:'T')
               /// </summary>
               tickMode = 84,

               /// <summary>
               /// 用户最大会话数(数值:83,字符:'S')
               /// </summary>
               SingleUserSessionMaxNum = 83,

               /// <summary>
               /// 最大连续登录失败数(数值:76,字符:'L')
               /// </summary>
               LoginFailMaxNum = 76,

               /// <summary>
               /// 是否强制认证(数值:65,字符:'A')
               /// </summary>
               IsAuthForce = 65,

               /// <summary>
               /// 是否冻结证券持仓(数值:70,字符:'F')
               /// </summary>
               IsPosiFreeze = 70,

               /// <summary>
               /// 是否限仓(数值:77,字符:'M')
               /// </summary>
               IsPosiLimit = 77,

               /// <summary>
               /// 郑商所询价时间间隔(数值:81,字符:'Q')
               /// </summary>
               ForQuoteTimeInterval = 81,

               /// <summary>
               /// 是否期货限仓(数值:66,字符:'B')
               /// </summary>
               IsFuturePosiLimit = 66,

               /// <summary>
               /// 是否期货下单频率限制(数值:67,字符:'C')
               /// </summary>
               IsFutureOrderFreq = 67,

               /// <summary>
               /// 行权冻结是否计算盈利(数值:72,字符:'H')
               /// </summary>
               IsExecOrderProfit = 72,

               /// <summary>
               /// 银期开户是否验证开户银行卡号是否是预留银行账户(数值:73,字符:'I')
               /// </summary>
               IsCheckBankAcc = 73,

               /// <summary>
               /// 弱密码最后修改日期(数值:74,字符:'J')
               /// </summary>
               PasswordDeadLine = 74,

               /// <summary>
               /// 强密码校验(数值:75,字符:'K')
               /// </summary>
               IsStrongPassword = 75,

               /// <summary>
               /// 自有资金质押比(数值:97,字符:'a')
               /// </summary>
               BalanceMorgage = 97,

               /// <summary>
               /// 最小密码长度(数值:79,字符:'O')
               /// </summary>
               MinPwdLen = 79,

               /// <summary>
               /// IP当日最大登陆失败次数(数值:85,字符:'U')
               /// </summary>
               LoginFailMaxNumForIP = 85,

               /// <summary>
               /// 密码有效期(数值:86,字符:'V')
               /// </summary>
               PasswordPeriod = 86
           };

           /// <summary>
           /// 文件标识类型
           /// </summary>
           public enum class CtpNetFileIDType
           {
               /// <summary>
               /// 资金数据(数值:70,字符:'F')
               /// </summary>
               SettlementFund = 70,

               /// <summary>
               /// 成交数据(数值:84,字符:'T')
               /// </summary>
               Trade = 84,

               /// <summary>
               /// 投资者持仓数据(数值:80,字符:'P')
               /// </summary>
               InvestorPosition = 80,

               /// <summary>
               /// 投资者分项资金数据(数值:79,字符:'O')
               /// </summary>
               SubEntryFund = 79,

               /// <summary>
               /// 组合持仓数据(数值:67,字符:'C')
               /// </summary>
               CZCECombinationPos = 67,

               /// <summary>
               /// 上报保证金监控中心数据(数值:82,字符:'R')
               /// </summary>
               CSRCData = 82,

               /// <summary>
               /// 郑商所平仓了结数据(数值:76,字符:'L')
               /// </summary>
               CZCEClose = 76,

               /// <summary>
               /// 郑商所非平仓了结数据(数值:78,字符:'N')
               /// </summary>
               CZCENoClose = 78,

               /// <summary>
               /// 持仓明细数据(数值:68,字符:'D')
               /// </summary>
               PositionDtl = 68,

               /// <summary>
               /// 期权执行文件(数值:83,字符:'S')
               /// </summary>
               OptionStrike = 83,

               /// <summary>
               /// 结算价比对文件(数值:77,字符:'M')
               /// </summary>
               SettlementPriceComparison = 77,

               /// <summary>
               /// 上期所非持仓变动明细(数值:66,字符:'B')
               /// </summary>
               NonTradePosChange = 66
           };

           /// <summary>
           /// 文件上传类型
           /// </summary>
           public enum class CtpNetFileTypeType
           {
               /// <summary>
               /// 结算(数值:48,字符:'0')
               /// </summary>
               Settlement = 48,

               /// <summary>
               /// 核对(数值:49,字符:'1')
               /// </summary>
               Check = 49
           };

           /// <summary>
           /// 文件格式类型
           /// </summary>
           public enum class CtpNetFileFormatType
           {
               /// <summary>
               /// 文本文件(.txt)(数值:48,字符:'0')
               /// </summary>
               Txt = 48,

               /// <summary>
               /// 压缩文件(.zip)(数值:49,字符:'1')
               /// </summary>
               Zip = 49,

               /// <summary>
               /// DBF文件(.dbf)(数值:50,字符:'2')
               /// </summary>
               DBF = 50
           };

           /// <summary>
           /// 文件状态类型
           /// </summary>
           public enum class CtpNetFileUploadStatusType
           {
               /// <summary>
               /// 上传成功(数值:49,字符:'1')
               /// </summary>
               SucceedUpload = 49,

               /// <summary>
               /// 上传失败(数值:50,字符:'2')
               /// </summary>
               FailedUpload = 50,

               /// <summary>
               /// 导入成功(数值:51,字符:'3')
               /// </summary>
               SucceedLoad = 51,

               /// <summary>
               /// 导入部分成功(数值:52,字符:'4')
               /// </summary>
               PartSucceedLoad = 52,

               /// <summary>
               /// 导入失败(数值:53,字符:'5')
               /// </summary>
               FailedLoad = 53
           };

           /// <summary>
           /// 移仓方向类型
           /// </summary>
           public enum class CtpNetTransferDirectionType
           {
               /// <summary>
               /// 移出(数值:48,字符:'0')
               /// </summary>
               Out = 48,

               /// <summary>
               /// 移入(数值:49,字符:'1')
               /// </summary>
               In = 49
           };

           /// <summary>
           /// 特殊的创建规则类型
           /// </summary>
           public enum class CtpNetSpecialCreateRuleType
           {
               /// <summary>
               /// 没有特殊创建规则(数值:48,字符:'0')
               /// </summary>
               NoSpecialRule = 48,

               /// <summary>
               /// 不包含春节(数值:49,字符:'1')
               /// </summary>
               NoSpringFestival = 49
           };

           /// <summary>
           /// 挂牌基准价类型
           /// </summary>
           public enum class CtpNetBasisPriceTypeType
           {
               /// <summary>
               /// 上一合约结算价(数值:49,字符:'1')
               /// </summary>
               LastSettlement = 49,

               /// <summary>
               /// 上一合约收盘价(数值:50,字符:'2')
               /// </summary>
               LaseClose = 50
           };

           /// <summary>
           /// 产品生命周期状态类型
           /// </summary>
           public enum class CtpNetProductLifePhaseType
           {
               /// <summary>
               /// 活跃(数值:49,字符:'1')
               /// </summary>
               Active = 49,

               /// <summary>
               /// 不活跃(数值:50,字符:'2')
               /// </summary>
               NonActive = 50,

               /// <summary>
               /// 注销(数值:51,字符:'3')
               /// </summary>
               Canceled = 51
           };

           /// <summary>
           /// 交割方式类型
           /// </summary>
           public enum class CtpNetDeliveryModeType
           {
               /// <summary>
               /// 现金交割(数值:49,字符:'1')
               /// </summary>
               CashDeliv = 49,

               /// <summary>
               /// 实物交割(数值:50,字符:'2')
               /// </summary>
               CommodityDeliv = 50
           };

           /// <summary>
           /// 出入金类型
           /// </summary>
           public enum class CtpNetFundIOTypeType
           {
               /// <summary>
               /// 出入金(数值:49,字符:'1')
               /// </summary>
               FundIO = 49,

               /// <summary>
               /// 银期转帐(数值:50,字符:'2')
               /// </summary>
               Transfer = 50,

               /// <summary>
               /// 银期换汇(数值:51,字符:'3')
               /// </summary>
               SwapCurrency = 51
           };

           /// <summary>
           /// 资金类型
           /// </summary>
           public enum class CtpNetFundTypeType
           {
               /// <summary>
               /// 银行存款(数值:49,字符:'1')
               /// </summary>
               Deposite = 49,

               /// <summary>
               /// 分项资金(数值:50,字符:'2')
               /// </summary>
               ItemFund = 50,

               /// <summary>
               /// 公司调整(数值:51,字符:'3')
               /// </summary>
               Company = 51,

               /// <summary>
               /// 资金内转(数值:52,字符:'4')
               /// </summary>
               InnerTransfer = 52
           };

           /// <summary>
           /// 出入金方向类型
           /// </summary>
           public enum class CtpNetFundDirectionType
           {
               /// <summary>
               /// 入金(数值:49,字符:'1')
               /// </summary>
               In = 49,

               /// <summary>
               /// 出金(数值:50,字符:'2')
               /// </summary>
               Out = 50
           };

           /// <summary>
           /// 资金状态类型
           /// </summary>
           public enum class CtpNetFundStatusType
           {
               /// <summary>
               /// 已录入(数值:49,字符:'1')
               /// </summary>
               Record = 49,

               /// <summary>
               /// 已复核(数值:50,字符:'2')
               /// </summary>
               Check = 50,

               /// <summary>
               /// 已冲销(数值:51,字符:'3')
               /// </summary>
               Charge = 51
           };

           /// <summary>
           /// 发布状态类型
           /// </summary>
           public enum class CtpNetPublishStatusType
           {
               /// <summary>
               /// 未发布(数值:49,字符:'1')
               /// </summary>
               None = 49,

               /// <summary>
               /// 正在发布(数值:50,字符:'2')
               /// </summary>
               Publishing = 50,

               /// <summary>
               /// 已发布(数值:51,字符:'3')
               /// </summary>
               Published = 51
           };

           /// <summary>
           /// 系统状态类型
           /// </summary>
           public enum class CtpNetSystemStatusType
           {
               /// <summary>
               /// 不活跃(数值:49,字符:'1')
               /// </summary>
               NonActive = 49,

               /// <summary>
               /// 启动(数值:50,字符:'2')
               /// </summary>
               Startup = 50,

               /// <summary>
               /// 交易开始初始化(数值:51,字符:'3')
               /// </summary>
               Initialize = 51,

               /// <summary>
               /// 交易完成初始化(数值:52,字符:'4')
               /// </summary>
               Initialized = 52,

               /// <summary>
               /// 收市开始(数值:53,字符:'5')
               /// </summary>
               Close = 53,

               /// <summary>
               /// 收市完成(数值:54,字符:'6')
               /// </summary>
               Closed = 54,

               /// <summary>
               /// 结算(数值:55,字符:'7')
               /// </summary>
               Settlement = 55
           };

           /// <summary>
           /// 结算状态类型
           /// </summary>
           public enum class CtpNetSettlementStatusType
           {
               /// <summary>
               /// 初始(数值:48,字符:'0')
               /// </summary>
               Initialize = 48,

               /// <summary>
               /// 结算中(数值:49,字符:'1')
               /// </summary>
               Settlementing = 49,

               /// <summary>
               /// 已结算(数值:50,字符:'2')
               /// </summary>
               Settlemented = 50,

               /// <summary>
               /// 结算完成(数值:51,字符:'3')
               /// </summary>
               Finished = 51
           };

           /// <summary>
           /// 投资者类型
           /// </summary>
           public enum class CtpNetInvestorTypeType
           {
               /// <summary>
               /// 自然人(数值:48,字符:'0')
               /// </summary>
               Person = 48,

               /// <summary>
               /// 法人(数值:49,字符:'1')
               /// </summary>
               Company = 49,

               /// <summary>
               /// 投资基金(数值:50,字符:'2')
               /// </summary>
               Fund = 50,

               /// <summary>
               /// 特殊法人(数值:51,字符:'3')
               /// </summary>
               SpecialOrgan = 51,

               /// <summary>
               /// 资管户(数值:52,字符:'4')
               /// </summary>
               Asset = 52
           };

           /// <summary>
           /// 经纪公司类型
           /// </summary>
           public enum class CtpNetBrokerTypeType
           {
               /// <summary>
               /// 交易会员(数值:48,字符:'0')
               /// </summary>
               Trade = 48,

               /// <summary>
               /// 交易结算会员(数值:49,字符:'1')
               /// </summary>
               TradeSettle = 49
           };

           /// <summary>
           /// 风险等级类型
           /// </summary>
           public enum class CtpNetRiskLevelType
           {
               /// <summary>
               /// 低风险客户(数值:49,字符:'1')
               /// </summary>
               Low = 49,

               /// <summary>
               /// 普通客户(数值:50,字符:'2')
               /// </summary>
               Normal = 50,

               /// <summary>
               /// 关注客户(数值:51,字符:'3')
               /// </summary>
               Focus = 51,

               /// <summary>
               /// 风险客户(数值:52,字符:'4')
               /// </summary>
               Risk = 52
           };

           /// <summary>
           /// 手续费收取方式类型
           /// </summary>
           public enum class CtpNetFeeAcceptStyleType
           {
               /// <summary>
               /// 按交易收取(数值:49,字符:'1')
               /// </summary>
               ByTrade = 49,

               /// <summary>
               /// 按交割收取(数值:50,字符:'2')
               /// </summary>
               ByDeliv = 50,

               /// <summary>
               /// 不收(数值:51,字符:'3')
               /// </summary>
               None = 51,

               /// <summary>
               /// 按指定手续费收取(数值:52,字符:'4')
               /// </summary>
               FixFee = 52
           };

           /// <summary>
           /// 密码类型
           /// </summary>
           public enum class CtpNetPasswordTypeType
           {
               /// <summary>
               /// 交易密码(数值:49,字符:'1')
               /// </summary>
               Trade = 49,

               /// <summary>
               /// 资金密码(数值:50,字符:'2')
               /// </summary>
               Account = 50
           };

           /// <summary>
           /// 盈亏算法类型
           /// </summary>
           public enum class CtpNetAlgorithmType
           {
               /// <summary>
               /// 浮盈浮亏都计算(数值:49,字符:'1')
               /// </summary>
               All = 49,

               /// <summary>
               /// 浮盈不计，浮亏计(数值:50,字符:'2')
               /// </summary>
               OnlyLost = 50,

               /// <summary>
               /// 浮盈计，浮亏不计(数值:51,字符:'3')
               /// </summary>
               OnlyGain = 51,

               /// <summary>
               /// 浮盈浮亏都不计算(数值:52,字符:'4')
               /// </summary>
               None = 52
           };

           /// <summary>
           /// 是否包含平仓盈利类型
           /// </summary>
           public enum class CtpNetIncludeCloseProfitType
           {
               /// <summary>
               /// 包含平仓盈利(数值:48,字符:'0')
               /// </summary>
               Include = 48,

               /// <summary>
               /// 不包含平仓盈利(数值:50,字符:'2')
               /// </summary>
               NotInclude = 50
           };

           /// <summary>
           /// 是否受可提比例限制类型
           /// </summary>
           public enum class CtpNetAllWithoutTradeType
           {
               /// <summary>
               /// 无仓无成交不受可提比例限制(数值:48,字符:'0')
               /// </summary>
               Enable = 48,

               /// <summary>
               /// 受可提比例限制(数值:50,字符:'2')
               /// </summary>
               Disable = 50,

               /// <summary>
               /// 无仓不受可提比例限制(数值:51,字符:'3')
               /// </summary>
               NoHoldEnable = 51
           };

           /// <summary>
           /// 资金密码核对标志类型
           /// </summary>
           public enum class CtpNetFuturePwdFlagType
           {
               /// <summary>
               /// 不核对(数值:48,字符:'0')
               /// </summary>
               UnCheck = 48,

               /// <summary>
               /// 核对(数值:49,字符:'1')
               /// </summary>
               Check = 49
           };

           /// <summary>
           /// 银期转账类型
           /// </summary>
           public enum class CtpNetTransferTypeType
           {
               /// <summary>
               /// 银行转期货(数值:48,字符:'0')
               /// </summary>
               BankToFuture = 48,

               /// <summary>
               /// 期货转银行(数值:49,字符:'1')
               /// </summary>
               FutureToBank = 49
           };

           /// <summary>
           /// 转账有效标志类型
           /// </summary>
           public enum class CtpNetTransferValidFlagType
           {
               /// <summary>
               /// 无效或失败(数值:48,字符:'0')
               /// </summary>
               Invalid = 48,

               /// <summary>
               /// 有效(数值:49,字符:'1')
               /// </summary>
               Valid = 49,

               /// <summary>
               /// 冲正(数值:50,字符:'2')
               /// </summary>
               Reverse = 50
           };

           /// <summary>
           /// 事由类型
           /// </summary>
           public enum class CtpNetReasonType
           {
               /// <summary>
               /// 错单(数值:48,字符:'0')
               /// </summary>
               CD = 48,

               /// <summary>
               /// 资金在途(数值:49,字符:'1')
               /// </summary>
               ZT = 49,

               /// <summary>
               /// 其它(数值:50,字符:'2')
               /// </summary>
               QT = 50
           };

           /// <summary>
           /// 性别类型
           /// </summary>
           public enum class CtpNetSexType
           {
               /// <summary>
               /// 未知(数值:48,字符:'0')
               /// </summary>
               None = 48,

               /// <summary>
               /// 男(数值:49,字符:'1')
               /// </summary>
               Man = 49,

               /// <summary>
               /// 女(数值:50,字符:'2')
               /// </summary>
               Woman = 50
           };

           /// <summary>
           /// 用户类型
           /// </summary>
           public enum class CtpNetUserTypeType
           {
               /// <summary>
               /// 投资者(数值:48,字符:'0')
               /// </summary>
               Investor = 48,

               /// <summary>
               /// 操作员(数值:49,字符:'1')
               /// </summary>
               Operator = 49,

               /// <summary>
               /// 管理员(数值:50,字符:'2')
               /// </summary>
               SuperUser = 50
           };

           /// <summary>
           /// 费率类型
           /// </summary>
           public enum class CtpNetRateTypeType
           {
               /// <summary>
               /// 保证金率(数值:50,字符:'2')
               /// </summary>
               MarginRate = 50
           };

           /// <summary>
           /// 通知类型
           /// </summary>
           public enum class CtpNetNoteTypeType
           {
               /// <summary>
               /// 交易结算单(数值:49,字符:'1')
               /// </summary>
               TradeSettleBill = 49,

               /// <summary>
               /// 交易结算月报(数值:50,字符:'2')
               /// </summary>
               TradeSettleMonth = 50,

               /// <summary>
               /// 追加保证金通知书(数值:51,字符:'3')
               /// </summary>
               CallMarginNotes = 51,

               /// <summary>
               /// 强行平仓通知书(数值:52,字符:'4')
               /// </summary>
               ForceCloseNotes = 52,

               /// <summary>
               /// 成交通知书(数值:53,字符:'5')
               /// </summary>
               TradeNotes = 53,

               /// <summary>
               /// 交割通知书(数值:54,字符:'6')
               /// </summary>
               DelivNotes = 54
           };

           /// <summary>
           /// 结算单方式类型
           /// </summary>
           public enum class CtpNetSettlementStyleType
           {
               /// <summary>
               /// 逐日盯市(数值:49,字符:'1')
               /// </summary>
               Day = 49,

               /// <summary>
               /// 逐笔对冲(数值:50,字符:'2')
               /// </summary>
               Volume = 50
           };

           /// <summary>
           /// 结算单类型
           /// </summary>
           public enum class CtpNetSettlementBillTypeType
           {
               /// <summary>
               /// 日报(数值:48,字符:'0')
               /// </summary>
               Day = 48,

               /// <summary>
               /// 月报(数值:49,字符:'1')
               /// </summary>
               Month = 49
           };

           /// <summary>
           /// 客户权限类型
           /// </summary>
           public enum class CtpNetUserRightTypeType
           {
               /// <summary>
               /// 登录(数值:49,字符:'1')
               /// </summary>
               Logon = 49,

               /// <summary>
               /// 银期转帐(数值:50,字符:'2')
               /// </summary>
               Transfer = 50,

               /// <summary>
               /// 邮寄结算单(数值:51,字符:'3')
               /// </summary>
               EMail = 51,

               /// <summary>
               /// 传真结算单(数值:52,字符:'4')
               /// </summary>
               Fax = 52,

               /// <summary>
               /// 条件单(数值:53,字符:'5')
               /// </summary>
               ConditionOrder = 53
           };

           /// <summary>
           /// 保证金价格类型
           /// </summary>
           public enum class CtpNetMarginPriceTypeType
           {
               /// <summary>
               /// 昨结算价(数值:49,字符:'1')
               /// </summary>
               PreSettlementPrice = 49,

               /// <summary>
               /// 最新价(数值:50,字符:'2')
               /// </summary>
               SettlementPrice = 50,

               /// <summary>
               /// 成交均价(数值:51,字符:'3')
               /// </summary>
               AveragePrice = 51,

               /// <summary>
               /// 开仓价(数值:52,字符:'4')
               /// </summary>
               OpenPrice = 52
           };

           /// <summary>
           /// 结算单生成状态类型
           /// </summary>
           public enum class CtpNetBillGenStatusType
           {
               /// <summary>
               /// 未生成(数值:48,字符:'0')
               /// </summary>
               None = 48,

               /// <summary>
               /// 生成中(数值:49,字符:'1')
               /// </summary>
               NoGenerated = 49,

               /// <summary>
               /// 已生成(数值:50,字符:'2')
               /// </summary>
               Generated = 50
           };

           /// <summary>
           /// 算法类型
           /// </summary>
           public enum class CtpNetAlgoTypeType
           {
               /// <summary>
               /// 持仓处理算法(数值:49,字符:'1')
               /// </summary>
               HandlePositionAlgo = 49,

               /// <summary>
               /// 寻找保证金率算法(数值:50,字符:'2')
               /// </summary>
               FindMarginRateAlgo = 50
           };

           /// <summary>
           /// 持仓处理算法编号类型
           /// </summary>
           public enum class CtpNetHandlePositionAlgoIDType
           {
               /// <summary>
               /// 基本(数值:49,字符:'1')
               /// </summary>
               Base = 49,

               /// <summary>
               /// 大连商品交易所(数值:50,字符:'2')
               /// </summary>
               DCE = 50,

               /// <summary>
               /// 郑州商品交易所(数值:51,字符:'3')
               /// </summary>
               CZCE = 51
           };

           /// <summary>
           /// 寻找保证金率算法编号类型
           /// </summary>
           public enum class CtpNetFindMarginRateAlgoIDType
           {
               /// <summary>
               /// 基本(数值:49,字符:'1')
               /// </summary>
               Base = 49,

               /// <summary>
               /// 大连商品交易所(数值:50,字符:'2')
               /// </summary>
               DCE = 50,

               /// <summary>
               /// 郑州商品交易所(数值:51,字符:'3')
               /// </summary>
               CZCE = 51
           };

           /// <summary>
           /// 资金处理算法编号类型
           /// </summary>
           public enum class CtpNetHandleTradingAccountAlgoIDType
           {
               /// <summary>
               /// 基本(数值:49,字符:'1')
               /// </summary>
               Base = 49,

               /// <summary>
               /// 大连商品交易所(数值:50,字符:'2')
               /// </summary>
               DCE = 50,

               /// <summary>
               /// 郑州商品交易所(数值:51,字符:'3')
               /// </summary>
               CZCE = 51
           };

           /// <summary>
           /// 联系人类型
           /// </summary>
           public enum class CtpNetPersonTypeType
           {
               /// <summary>
               /// 指定下单人(数值:49,字符:'1')
               /// </summary>
               Order = 49,

               /// <summary>
               /// 开户授权人(数值:50,字符:'2')
               /// </summary>
               Open = 50,

               /// <summary>
               /// 资金调拨人(数值:51,字符:'3')
               /// </summary>
               Fund = 51,

               /// <summary>
               /// 结算单确认人(数值:52,字符:'4')
               /// </summary>
               Settlement = 52,

               /// <summary>
               /// 法人(数值:53,字符:'5')
               /// </summary>
               Company = 53,

               /// <summary>
               /// 法人代表(数值:54,字符:'6')
               /// </summary>
               Corporation = 54,

               /// <summary>
               /// 投资者联系人(数值:55,字符:'7')
               /// </summary>
               LinkMan = 55,

               /// <summary>
               /// 分户管理资产负责人(数值:56,字符:'8')
               /// </summary>
               Ledger = 56,

               /// <summary>
               /// 托（保）管人(数值:57,字符:'9')
               /// </summary>
               Trustee = 57,

               /// <summary>
               /// 托（保）管机构法人代表(数值:65,字符:'A')
               /// </summary>
               TrusteeCorporation = 65,

               /// <summary>
               /// 托（保）管机构开户授权人(数值:66,字符:'B')
               /// </summary>
               TrusteeOpen = 66,

               /// <summary>
               /// 托（保）管机构联系人(数值:67,字符:'C')
               /// </summary>
               TrusteeContact = 67,

               /// <summary>
               /// 境外自然人参考证件(数值:68,字符:'D')
               /// </summary>
               ForeignerRefer = 68,

               /// <summary>
               /// 法人代表参考证件(数值:69,字符:'E')
               /// </summary>
               CorporationRefer = 69
           };

           /// <summary>
           /// 查询范围类型
           /// </summary>
           public enum class CtpNetQueryInvestorRangeType
           {
               /// <summary>
               /// 所有(数值:49,字符:'1')
               /// </summary>
               All = 49,

               /// <summary>
               /// 查询分类(数值:50,字符:'2')
               /// </summary>
               Group = 50,

               /// <summary>
               /// 单一投资者(数值:51,字符:'3')
               /// </summary>
               Single = 51
           };

           /// <summary>
           /// 投资者风险状态类型
           /// </summary>
           public enum class CtpNetInvestorRiskStatusType
           {
               /// <summary>
               /// 正常(数值:49,字符:'1')
               /// </summary>
               Normal = 49,

               /// <summary>
               /// 警告(数值:50,字符:'2')
               /// </summary>
               Warn = 50,

               /// <summary>
               /// 追保(数值:51,字符:'3')
               /// </summary>
               Call = 51,

               /// <summary>
               /// 强平(数值:52,字符:'4')
               /// </summary>
               Force = 52,

               /// <summary>
               /// 异常(数值:53,字符:'5')
               /// </summary>
               Exception = 53
           };

           /// <summary>
           /// 用户事件类型
           /// </summary>
           public enum class CtpNetUserEventTypeType
           {
               /// <summary>
               /// 登录(数值:49,字符:'1')
               /// </summary>
               Login = 49,

               /// <summary>
               /// 登出(数值:50,字符:'2')
               /// </summary>
               Logout = 50,

               /// <summary>
               /// 交易成功(数值:51,字符:'3')
               /// </summary>
               Trading = 51,

               /// <summary>
               /// 交易失败(数值:52,字符:'4')
               /// </summary>
               TradingError = 52,

               /// <summary>
               /// 修改密码(数值:53,字符:'5')
               /// </summary>
               UpdatePassword = 53,

               /// <summary>
               /// 客户端认证(数值:54,字符:'6')
               /// </summary>
               Authenticate = 54,

               /// <summary>
               /// 其他(数值:57,字符:'9')
               /// </summary>
               Other = 57
           };

           /// <summary>
           /// 平仓方式类型
           /// </summary>
           public enum class CtpNetCloseStyleType
           {
               /// <summary>
               /// 先开先平(数值:48,字符:'0')
               /// </summary>
               Close = 48,

               /// <summary>
               /// 先平今再平昨(数值:49,字符:'1')
               /// </summary>
               CloseToday = 49
           };

           /// <summary>
           /// 统计方式类型
           /// </summary>
           public enum class CtpNetStatModeType
           {
               /// <summary>
               /// ----(数值:48,字符:'0')
               /// </summary>
               Non = 48,

               /// <summary>
               /// 按合约统计(数值:49,字符:'1')
               /// </summary>
               Instrument = 49,

               /// <summary>
               /// 按产品统计(数值:50,字符:'2')
               /// </summary>
               Product = 50,

               /// <summary>
               /// 按投资者统计(数值:51,字符:'3')
               /// </summary>
               Investor = 51
           };

           /// <summary>
           /// 预埋单状态类型
           /// </summary>
           public enum class CtpNetParkedOrderStatusType
           {
               /// <summary>
               /// 未发送(数值:49,字符:'1')
               /// </summary>
               NotSend = 49,

               /// <summary>
               /// 已发送(数值:50,字符:'2')
               /// </summary>
               Send = 50,

               /// <summary>
               /// 已删除(数值:51,字符:'3')
               /// </summary>
               Deleted = 51
           };

           /// <summary>
           /// 处理状态类型
           /// </summary>
           public enum class CtpNetVirDealStatusType
           {
               /// <summary>
               /// 正在处理(数值:49,字符:'1')
               /// </summary>
               Dealing = 49,

               /// <summary>
               /// 处理成功(数值:50,字符:'2')
               /// </summary>
               DeaclSucceed = 50
           };

           /// <summary>
           /// 原有系统代码类型
           /// </summary>
           public enum class CtpNetOrgSystemIDType
           {
               /// <summary>
               /// 综合交易平台(数值:48,字符:'0')
               /// </summary>
               Standard = 48,

               /// <summary>
               /// 易盛系统(数值:49,字符:'1')
               /// </summary>
               ESunny = 49,

               /// <summary>
               /// 金仕达V6系统(数值:50,字符:'2')
               /// </summary>
               KingStarV6 = 50
           };

           /// <summary>
           /// 交易状态类型
           /// </summary>
           public enum class CtpNetVirTradeStatusType
           {
               /// <summary>
               /// 正常处理中(数值:48,字符:'0')
               /// </summary>
               NaturalDeal = 48,

               /// <summary>
               /// 成功结束(数值:49,字符:'1')
               /// </summary>
               SucceedEnd = 49,

               /// <summary>
               /// 失败结束(数值:50,字符:'2')
               /// </summary>
               FailedEND = 50,

               /// <summary>
               /// 异常中(数值:51,字符:'3')
               /// </summary>
               Exception = 51,

               /// <summary>
               /// 已人工异常处理(数值:52,字符:'4')
               /// </summary>
               ManualDeal = 52,

               /// <summary>
               /// 通讯异常 ，请人工处理(数值:53,字符:'5')
               /// </summary>
               MesException = 53,

               /// <summary>
               /// 系统出错，请人工处理(数值:54,字符:'6')
               /// </summary>
               SysException = 54
           };

           /// <summary>
           /// 银行帐户类型
           /// </summary>
           public enum class CtpNetVirBankAccTypeType
           {
               /// <summary>
               /// 存折(数值:49,字符:'1')
               /// </summary>
               BankBook = 49,

               /// <summary>
               /// 储蓄卡(数值:50,字符:'2')
               /// </summary>
               BankCard = 50,

               /// <summary>
               /// 信用卡(数值:51,字符:'3')
               /// </summary>
               CreditCard = 51
           };

           /// <summary>
           /// 银行帐户类型
           /// </summary>
           public enum class CtpNetVirementStatusType
           {
               /// <summary>
               /// 正常(数值:48,字符:'0')
               /// </summary>
               Natural = 48,

               /// <summary>
               /// 销户(数值:57,字符:'9')
               /// </summary>
               Canceled = 57
           };

           /// <summary>
           /// 有效标志类型
           /// </summary>
           public enum class CtpNetVirementAvailAbilityType
           {
               /// <summary>
               /// 未确认(数值:48,字符:'0')
               /// </summary>
               NoAvailAbility = 48,

               /// <summary>
               /// 有效(数值:49,字符:'1')
               /// </summary>
               AvailAbility = 49,

               /// <summary>
               /// 冲正(数值:50,字符:'2')
               /// </summary>
               Repeal = 50
           };

           /// <summary>
           /// 交易代码类型
           /// </summary>
           public enum class CtpNetVirementTradeCodeType
           {
               /// <summary>
               /// 银行发起银行资金转期货(数值:49,字符:'0')
               /// </summary>
               BankBankToFuture_102001 = 49,

               /// <summary>
               /// 银行发起期货资金转银行(数值:50,字符:'1')
               /// </summary>
               BankFutureToBank_102002 = 50,

               /// <summary>
               /// 期货发起银行资金转期货(数值:51,字符:'2')
               /// </summary>
               FutureBankToFuture_202001 = 51,

               /// <summary>
               /// 期货发起期货资金转银行(数值:52,字符:'3')
               /// </summary>
               FutureFutureToBank_202002 = 52
           };

           /// <summary>
           /// Aml生成方式类型
           /// </summary>
           public enum class CtpNetAMLGenStatusType
           {
               /// <summary>
               /// 程序生成(数值:48,字符:'0')
               /// </summary>
               Program = 48,

               /// <summary>
               /// 人工生成(数值:49,字符:'1')
               /// </summary>
               HandWork = 49
           };

           /// <summary>
           /// 动态密钥类别(保证金监管)类型
           /// </summary>
           public enum class CtpNetCFMMCKeyKindType
           {
               /// <summary>
               /// 主动请求更新(数值:82,字符:'R')
               /// </summary>
               REQUEST = 82,

               /// <summary>
               /// CFMMC自动更新(数值:65,字符:'A')
               /// </summary>
               AUTO = 65,

               /// <summary>
               /// CFMMC手动更新(数值:77,字符:'M')
               /// </summary>
               MANUAL = 77
           };

           /// <summary>
           /// 证件类型
           /// </summary>
           public enum class CtpNetCertificationTypeType
           {
               /// <summary>
               /// 身份证(数值:48,字符:'0')
               /// </summary>
               IDCard = 48,

               /// <summary>
               /// 护照(数值:49,字符:'1')
               /// </summary>
               Passport = 49,

               /// <summary>
               /// 军官证(数值:50,字符:'2')
               /// </summary>
               OfficerIDCard = 50,

               /// <summary>
               /// 士兵证(数值:51,字符:'3')
               /// </summary>
               SoldierIDCard = 51,

               /// <summary>
               /// 回乡证(数值:52,字符:'4')
               /// </summary>
               HomeComingCard = 52,

               /// <summary>
               /// 户口簿(数值:53,字符:'5')
               /// </summary>
               HouseholdRegister = 53,

               /// <summary>
               /// 营业执照号(数值:54,字符:'6')
               /// </summary>
               LicenseNo = 54,

               /// <summary>
               /// 组织机构代码证(数值:55,字符:'7')
               /// </summary>
               InstitutionCodeCard = 55,

               /// <summary>
               /// 临时营业执照号(数值:56,字符:'8')
               /// </summary>
               TempLicenseNo = 56,

               /// <summary>
               /// 民办非企业登记证书(数值:57,字符:'9')
               /// </summary>
               NoEnterpriseLicenseNo = 57,

               /// <summary>
               /// 其他证件(数值:120,字符:'x')
               /// </summary>
               OtherCard = 120,

               /// <summary>
               /// 主管部门批文(数值:97,字符:'a')
               /// </summary>
               SuperDepAgree = 97
           };

           /// <summary>
           /// 文件业务功能类型
           /// </summary>
           public enum class CtpNetFileBusinessCodeType
           {
               /// <summary>
               /// 其他(数值:48,字符:'0')
               /// </summary>
               Others = 48,

               /// <summary>
               /// 转账交易明细对账(数值:49,字符:'1')
               /// </summary>
               TransferDetails = 49,

               /// <summary>
               /// 客户账户状态对账(数值:50,字符:'2')
               /// </summary>
               CustAccStatus = 50,

               /// <summary>
               /// 账户类交易明细对账(数值:51,字符:'3')
               /// </summary>
               AccountTradeDetails = 51,

               /// <summary>
               /// 期货账户信息变更明细对账(数值:52,字符:'4')
               /// </summary>
               FutureAccountChangeInfoDetails = 52,

               /// <summary>
               /// 客户资金台账余额明细对账(数值:53,字符:'5')
               /// </summary>
               CustMoneyDetail = 53,

               /// <summary>
               /// 客户销户结息明细对账(数值:54,字符:'6')
               /// </summary>
               CustCancelAccountInfo = 54,

               /// <summary>
               /// 客户资金余额对账结果(数值:55,字符:'7')
               /// </summary>
               CustMoneyResult = 55,

               /// <summary>
               /// 其它对账异常结果文件(数值:56,字符:'8')
               /// </summary>
               OthersExceptionResult = 56,

               /// <summary>
               /// 客户结息净额明细(数值:57,字符:'9')
               /// </summary>
               CustInterestNetMoneyDetails = 57,

               /// <summary>
               /// 客户资金交收明细(数值:97,字符:'a')
               /// </summary>
               CustMoneySendAndReceiveDetails = 97,

               /// <summary>
               /// 法人存管银行资金交收汇总(数值:98,字符:'b')
               /// </summary>
               CorporationMoneyTotal = 98,

               /// <summary>
               /// 主体间资金交收汇总(数值:99,字符:'c')
               /// </summary>
               MainbodyMoneyTotal = 99,

               /// <summary>
               /// 总分平衡监管数据(数值:100,字符:'d')
               /// </summary>
               MainPartMonitorData = 100,

               /// <summary>
               /// 存管银行备付金余额(数值:101,字符:'e')
               /// </summary>
               PreparationMoney = 101,

               /// <summary>
               /// 协办存管银行资金监管数据(数值:102,字符:'f')
               /// </summary>
               BankMoneyMonitorData = 102
           };

           /// <summary>
           /// 汇钞标志类型
           /// </summary>
           public enum class CtpNetCashExchangeCodeType
           {
               /// <summary>
               /// 汇(数值:49,字符:'1')
               /// </summary>
               Exchange = 49,

               /// <summary>
               /// 钞(数值:50,字符:'2')
               /// </summary>
               Cash = 50
           };

           /// <summary>
           /// 是或否标识类型
           /// </summary>
           public enum class CtpNetYesNoIndicatorType
           {
               /// <summary>
               /// 是(数值:48,字符:'0')
               /// </summary>
               Yes = 48,

               /// <summary>
               /// 否(数值:49,字符:'1')
               /// </summary>
               No = 49
           };

           /// <summary>
           /// 余额类型
           /// </summary>
           public enum class CtpNetBanlanceTypeType
           {
               /// <summary>
               /// 当前余额(数值:48,字符:'0')
               /// </summary>
               CurrentMoney = 48,

               /// <summary>
               /// 可用余额(数值:49,字符:'1')
               /// </summary>
               UsableMoney = 49,

               /// <summary>
               /// 可取余额(数值:50,字符:'2')
               /// </summary>
               FetchableMoney = 50,

               /// <summary>
               /// 冻结余额(数值:51,字符:'3')
               /// </summary>
               FreezeMoney = 51
           };

           /// <summary>
           /// 性别类型
           /// </summary>
           public enum class CtpNetGenderType
           {
               /// <summary>
               /// 未知状态(数值:48,字符:'0')
               /// </summary>
               Unknown = 48,

               /// <summary>
               /// 男(数值:49,字符:'1')
               /// </summary>
               Male = 49,

               /// <summary>
               /// 女(数值:50,字符:'2')
               /// </summary>
               Female = 50
           };

           /// <summary>
           /// 费用支付标志类型
           /// </summary>
           public enum class CtpNetFeePayFlagType
           {
               /// <summary>
               /// 由受益方支付费用(数值:48,字符:'0')
               /// </summary>
               BEN = 48,

               /// <summary>
               /// 由发送方支付费用(数值:49,字符:'1')
               /// </summary>
               OUR = 49,

               /// <summary>
               /// 由发送方支付发起的费用，受益方支付接受的费用(数值:50,字符:'2')
               /// </summary>
               SHA = 50
           };

           /// <summary>
           /// 密钥类型
           /// </summary>
           public enum class CtpNetPassWordKeyTypeType
           {
               /// <summary>
               /// 交换密钥(数值:48,字符:'0')
               /// </summary>
               ExchangeKey = 48,

               /// <summary>
               /// 密码密钥(数值:49,字符:'1')
               /// </summary>
               PassWordKey = 49,

               /// <summary>
               /// MAC密钥(数值:50,字符:'2')
               /// </summary>
               MACKey = 50,

               /// <summary>
               /// 报文密钥(数值:51,字符:'3')
               /// </summary>
               MessageKey = 51
           };

           /// <summary>
           /// 密码类型
           /// </summary>
           public enum class CtpNetFBTPassWordTypeType
           {
               /// <summary>
               /// 查询(数值:48,字符:'0')
               /// </summary>
               Query = 48,

               /// <summary>
               /// 取款(数值:49,字符:'1')
               /// </summary>
               Fetch = 49,

               /// <summary>
               /// 转帐(数值:50,字符:'2')
               /// </summary>
               Transfer = 50,

               /// <summary>
               /// 交易(数值:51,字符:'3')
               /// </summary>
               Trade = 51
           };

           /// <summary>
           /// 加密方式类型
           /// </summary>
           public enum class CtpNetFBTEncryModeType
           {
               /// <summary>
               /// 不加密(数值:48,字符:'0')
               /// </summary>
               NoEncry = 48,

               /// <summary>
               /// DES(数值:49,字符:'1')
               /// </summary>
               DES = 49,

               /// <summary>
               /// 3DES(数值:50,字符:'2')
               /// </summary>
               _3DES = 50
           };

           /// <summary>
           /// 银行冲正标志类型
           /// </summary>
           public enum class CtpNetBankRepealFlagType
           {
               /// <summary>
               /// 银行无需自动冲正(数值:48,字符:'0')
               /// </summary>
               BankNotNeedRepeal = 48,

               /// <summary>
               /// 银行待自动冲正(数值:49,字符:'1')
               /// </summary>
               BankWaitingRepeal = 49,

               /// <summary>
               /// 银行已自动冲正(数值:50,字符:'2')
               /// </summary>
               BankBeenRepealed = 50
           };

           /// <summary>
           /// 期商冲正标志类型
           /// </summary>
           public enum class CtpNetBrokerRepealFlagType
           {
               /// <summary>
               /// 期商无需自动冲正(数值:48,字符:'0')
               /// </summary>
               BrokerNotNeedRepeal = 48,

               /// <summary>
               /// 期商待自动冲正(数值:49,字符:'1')
               /// </summary>
               BrokerWaitingRepeal = 49,

               /// <summary>
               /// 期商已自动冲正(数值:50,字符:'2')
               /// </summary>
               BrokerBeenRepealed = 50
           };

           /// <summary>
           /// 机构类别类型
           /// </summary>
           public enum class CtpNetInstitutionTypeType
           {
               /// <summary>
               /// 银行(数值:48,字符:'0')
               /// </summary>
               Bank = 48,

               /// <summary>
               /// 期商(数值:49,字符:'1')
               /// </summary>
               Future = 49,

               /// <summary>
               /// 券商(数值:50,字符:'2')
               /// </summary>
               Store = 50
           };

           /// <summary>
           /// 最后分片标志类型
           /// </summary>
           public enum class CtpNetLastFragmentType
           {
               /// <summary>
               /// 是最后分片(数值:48,字符:'0')
               /// </summary>
               Yes = 48,

               /// <summary>
               /// 不是最后分片(数值:49,字符:'1')
               /// </summary>
               No = 49
           };

           /// <summary>
           /// 银行账户状态类型
           /// </summary>
           public enum class CtpNetBankAccStatusType
           {
               /// <summary>
               /// 正常(数值:48,字符:'0')
               /// </summary>
               Normal = 48,

               /// <summary>
               /// 冻结(数值:49,字符:'1')
               /// </summary>
               Freeze = 49,

               /// <summary>
               /// 挂失(数值:50,字符:'2')
               /// </summary>
               ReportLoss = 50
           };

           /// <summary>
           /// 资金账户状态类型
           /// </summary>
           public enum class CtpNetMoneyAccountStatusType
           {
               /// <summary>
               /// 正常(数值:48,字符:'0')
               /// </summary>
               Normal = 48,

               /// <summary>
               /// 销户(数值:49,字符:'1')
               /// </summary>
               Cancel = 49
           };

           /// <summary>
           /// 存管状态类型
           /// </summary>
           public enum class CtpNetManageStatusType
           {
               /// <summary>
               /// 指定存管(数值:48,字符:'0')
               /// </summary>
               Point = 48,

               /// <summary>
               /// 预指定(数值:49,字符:'1')
               /// </summary>
               PrePoint = 49,

               /// <summary>
               /// 撤销指定(数值:50,字符:'2')
               /// </summary>
               CancelPoint = 50
           };

           /// <summary>
           /// 应用系统类型
           /// </summary>
           public enum class CtpNetSystemTypeType
           {
               /// <summary>
               /// 银期转帐(数值:48,字符:'0')
               /// </summary>
               FutureBankTransfer = 48,

               /// <summary>
               /// 银证转帐(数值:49,字符:'1')
               /// </summary>
               StockBankTransfer = 49,

               /// <summary>
               /// 第三方存管(数值:50,字符:'2')
               /// </summary>
               TheThirdPartStore = 50
           };

           /// <summary>
           /// 银期转帐划转结果标志类型
           /// </summary>
           public enum class CtpNetTxnEndFlagType
           {
               /// <summary>
               /// 正常处理中(数值:48,字符:'0')
               /// </summary>
               NormalProcessing = 48,

               /// <summary>
               /// 成功结束(数值:49,字符:'1')
               /// </summary>
               Success = 49,

               /// <summary>
               /// 失败结束(数值:50,字符:'2')
               /// </summary>
               Failed = 50,

               /// <summary>
               /// 异常中(数值:51,字符:'3')
               /// </summary>
               Abnormal = 51,

               /// <summary>
               /// 已人工异常处理(数值:52,字符:'4')
               /// </summary>
               ManualProcessedForException = 52,

               /// <summary>
               /// 通讯异常 ，请人工处理(数值:53,字符:'5')
               /// </summary>
               CommuFailedNeedManualProcess = 53,

               /// <summary>
               /// 系统出错，请人工处理(数值:54,字符:'6')
               /// </summary>
               SysErrorNeedManualProcess = 54
           };

           /// <summary>
           /// 银期转帐服务处理状态类型
           /// </summary>
           public enum class CtpNetProcessStatusType
           {
               /// <summary>
               /// 未处理(数值:48,字符:'0')
               /// </summary>
               NotProcess = 48,

               /// <summary>
               /// 开始处理(数值:49,字符:'1')
               /// </summary>
               StartProcess = 49,

               /// <summary>
               /// 处理完成(数值:50,字符:'2')
               /// </summary>
               Finished = 50
           };

           /// <summary>
           /// 客户类型
           /// </summary>
           public enum class CtpNetCustTypeType
           {
               /// <summary>
               /// 自然人(数值:48,字符:'0')
               /// </summary>
               Person = 48,

               /// <summary>
               /// 机构户(数值:49,字符:'1')
               /// </summary>
               Institution = 49
           };

           /// <summary>
           /// 银期转帐方向类型
           /// </summary>
           public enum class CtpNetFBTTransferDirectionType
           {
               /// <summary>
               /// 入金，银行转期货(数值:49,字符:'1')
               /// </summary>
               FromBankToFuture = 49,

               /// <summary>
               /// 出金，期货转银行(数值:50,字符:'2')
               /// </summary>
               FromFutureToBank = 50
           };

           /// <summary>
           /// 开销户类别类型
           /// </summary>
           public enum class CtpNetOpenOrDestroyType
           {
               /// <summary>
               /// 开户(数值:49,字符:'1')
               /// </summary>
               Open = 49,

               /// <summary>
               /// 销户(数值:48,字符:'0')
               /// </summary>
               Destroy = 48
           };

           /// <summary>
           /// 有效标志类型
           /// </summary>
           public enum class CtpNetAvailabilityFlagType
           {
               /// <summary>
               /// 未确认(数值:48,字符:'0')
               /// </summary>
               Invalid = 48,

               /// <summary>
               /// 有效(数值:49,字符:'1')
               /// </summary>
               Valid = 49,

               /// <summary>
               /// 冲正(数值:50,字符:'2')
               /// </summary>
               Repeal = 50
           };

           /// <summary>
           /// 机构类型
           /// </summary>
           public enum class CtpNetOrganTypeType
           {
               /// <summary>
               /// 银行代理(数值:49,字符:'1')
               /// </summary>
               Bank = 49,

               /// <summary>
               /// 交易前置(数值:50,字符:'2')
               /// </summary>
               Future = 50,

               /// <summary>
               /// 银期转帐平台管理(数值:57,字符:'9')
               /// </summary>
               PlateForm = 57
           };

           /// <summary>
           /// 机构级别类型
           /// </summary>
           public enum class CtpNetOrganLevelType
           {
               /// <summary>
               /// 银行总行或期商总部(数值:49,字符:'1')
               /// </summary>
               HeadQuarters = 49,

               /// <summary>
               /// 银行分中心或期货公司营业部(数值:50,字符:'2')
               /// </summary>
               Branch = 50
           };

           /// <summary>
           /// 协议类型
           /// </summary>
           public enum class CtpNetProtocalIDType
           {
               /// <summary>
               /// 期商协议(数值:48,字符:'0')
               /// </summary>
               FutureProtocal = 48,

               /// <summary>
               /// 工行协议(数值:49,字符:'1')
               /// </summary>
               ICBCProtocal = 49,

               /// <summary>
               /// 农行协议(数值:50,字符:'2')
               /// </summary>
               ABCProtocal = 50,

               /// <summary>
               /// 中国银行协议(数值:51,字符:'3')
               /// </summary>
               CBCProtocal = 51,

               /// <summary>
               /// 建行协议(数值:52,字符:'4')
               /// </summary>
               CCBProtocal = 52,

               /// <summary>
               /// 交行协议(数值:53,字符:'5')
               /// </summary>
               BOCOMProtocal = 53,

               /// <summary>
               /// 银期转帐平台协议(数值:88,字符:'X')
               /// </summary>
               FBTPlateFormProtocal = 88
           };

           /// <summary>
           /// 套接字连接方式类型
           /// </summary>
           public enum class CtpNetConnectModeType
           {
               /// <summary>
               /// 短连接(数值:48,字符:'0')
               /// </summary>
               ShortConnect = 48,

               /// <summary>
               /// 长连接(数值:49,字符:'1')
               /// </summary>
               LongConnect = 49
           };

           /// <summary>
           /// 套接字通信方式类型
           /// </summary>
           public enum class CtpNetSyncModeType
           {
               /// <summary>
               /// 异步(数值:48,字符:'0')
               /// </summary>
               ASync = 48,

               /// <summary>
               /// 同步(数值:49,字符:'1')
               /// </summary>
               Sync = 49
           };

           /// <summary>
           /// 银行帐号类型
           /// </summary>
           public enum class CtpNetBankAccTypeType
           {
               /// <summary>
               /// 银行存折(数值:49,字符:'1')
               /// </summary>
               BankBook = 49,

               /// <summary>
               /// 储蓄卡(数值:50,字符:'2')
               /// </summary>
               SavingCard = 50,

               /// <summary>
               /// 信用卡(数值:51,字符:'3')
               /// </summary>
               CreditCard = 51
           };

           /// <summary>
           /// 期货公司帐号类型
           /// </summary>
           public enum class CtpNetFutureAccTypeType
           {
               /// <summary>
               /// 银行存折(数值:49,字符:'1')
               /// </summary>
               BankBook = 49,

               /// <summary>
               /// 储蓄卡(数值:50,字符:'2')
               /// </summary>
               SavingCard = 50,

               /// <summary>
               /// 信用卡(数值:51,字符:'3')
               /// </summary>
               CreditCard = 51
           };

           /// <summary>
           /// 接入机构状态类型
           /// </summary>
           public enum class CtpNetOrganStatusType
           {
               /// <summary>
               /// 启用(数值:48,字符:'0')
               /// </summary>
               Ready = 48,

               /// <summary>
               /// 签到(数值:49,字符:'1')
               /// </summary>
               CheckIn = 49,

               /// <summary>
               /// 签退(数值:50,字符:'2')
               /// </summary>
               CheckOut = 50,

               /// <summary>
               /// 对帐文件到达(数值:51,字符:'3')
               /// </summary>
               CheckFileArrived = 51,

               /// <summary>
               /// 对帐(数值:52,字符:'4')
               /// </summary>
               CheckDetail = 52,

               /// <summary>
               /// 日终清理(数值:53,字符:'5')
               /// </summary>
               DayEndClean = 53,

               /// <summary>
               /// 注销(数值:57,字符:'9')
               /// </summary>
               Invalid = 57
           };

           /// <summary>
           /// 建行收费模式类型
           /// </summary>
           public enum class CtpNetCCBFeeModeType
           {
               /// <summary>
               /// 按金额扣收(数值:49,字符:'1')
               /// </summary>
               ByAmount = 49,

               /// <summary>
               /// 按月扣收(数值:50,字符:'2')
               /// </summary>
               ByMonth = 50
           };

           /// <summary>
           /// 通讯API类型
           /// </summary>
           public enum class CtpNetCommApiTypeType
           {
               /// <summary>
               /// 客户端(数值:49,字符:'1')
               /// </summary>
               Client = 49,

               /// <summary>
               /// 服务端(数值:50,字符:'2')
               /// </summary>
               Server = 50,

               /// <summary>
               /// 交易系统的UserApi(数值:51,字符:'3')
               /// </summary>
               UserApi = 51
           };

           /// <summary>
           /// 连接状态类型
           /// </summary>
           public enum class CtpNetLinkStatusType
           {
               /// <summary>
               /// 已经连接(数值:49,字符:'1')
               /// </summary>
               Connected = 49,

               /// <summary>
               /// 没有连接(数值:50,字符:'2')
               /// </summary>
               Disconnected = 50
           };

           /// <summary>
           /// 密码核对标志类型
           /// </summary>
           public enum class CtpNetPwdFlagType
           {
               /// <summary>
               /// 不核对(数值:48,字符:'0')
               /// </summary>
               NoCheck = 48,

               /// <summary>
               /// 明文核对(数值:49,字符:'1')
               /// </summary>
               BlankCheck = 49,

               /// <summary>
               /// 密文核对(数值:50,字符:'2')
               /// </summary>
               EncryptCheck = 50
           };

           /// <summary>
           /// 期货帐号类型
           /// </summary>
           public enum class CtpNetSecuAccTypeType
           {
               /// <summary>
               /// 资金帐号(数值:49,字符:'1')
               /// </summary>
               AccountID = 49,

               /// <summary>
               /// 资金卡号(数值:50,字符:'2')
               /// </summary>
               CardID = 50,

               /// <summary>
               /// 上海股东帐号(数值:51,字符:'3')
               /// </summary>
               SHStockholderID = 51,

               /// <summary>
               /// 深圳股东帐号(数值:52,字符:'4')
               /// </summary>
               SZStockholderID = 52
           };

           /// <summary>
           /// 转账交易状态类型
           /// </summary>
           public enum class CtpNetTransferStatusType
           {
               /// <summary>
               /// 正常(数值:48,字符:'0')
               /// </summary>
               Normal = 48,

               /// <summary>
               /// 被冲正(数值:49,字符:'1')
               /// </summary>
               Repealed = 49
           };

           /// <summary>
           /// 发起方类型
           /// </summary>
           public enum class CtpNetSponsorTypeType
           {
               /// <summary>
               /// 期商(数值:48,字符:'0')
               /// </summary>
               Broker = 48,

               /// <summary>
               /// 银行(数值:49,字符:'1')
               /// </summary>
               Bank = 49
           };

           /// <summary>
           /// 请求响应类别类型
           /// </summary>
           public enum class CtpNetReqRspTypeType
           {
               /// <summary>
               /// 请求(数值:48,字符:'0')
               /// </summary>
               Request = 48,

               /// <summary>
               /// 响应(数值:49,字符:'1')
               /// </summary>
               Response = 49
           };

           /// <summary>
           /// 银期转帐用户事件类型
           /// </summary>
           public enum class CtpNetFBTUserEventTypeType
           {
               /// <summary>
               /// 签到(数值:48,字符:'0')
               /// </summary>
               SignIn = 48,

               /// <summary>
               /// 银行转期货(数值:49,字符:'1')
               /// </summary>
               FromBankToFuture = 49,

               /// <summary>
               /// 期货转银行(数值:50,字符:'2')
               /// </summary>
               FromFutureToBank = 50,

               /// <summary>
               /// 开户(数值:51,字符:'3')
               /// </summary>
               OpenAccount = 51,

               /// <summary>
               /// 销户(数值:52,字符:'4')
               /// </summary>
               CancelAccount = 52,

               /// <summary>
               /// 变更银行账户(数值:53,字符:'5')
               /// </summary>
               ChangeAccount = 53,

               /// <summary>
               /// 冲正银行转期货(数值:54,字符:'6')
               /// </summary>
               RepealFromBankToFuture = 54,

               /// <summary>
               /// 冲正期货转银行(数值:55,字符:'7')
               /// </summary>
               RepealFromFutureToBank = 55,

               /// <summary>
               /// 查询银行账户(数值:56,字符:'8')
               /// </summary>
               QueryBankAccount = 56,

               /// <summary>
               /// 查询期货账户(数值:57,字符:'9')
               /// </summary>
               QueryFutureAccount = 57,

               /// <summary>
               /// 签退(数值:65,字符:'A')
               /// </summary>
               SignOut = 65,

               /// <summary>
               /// 密钥同步(数值:66,字符:'B')
               /// </summary>
               SyncKey = 66,

               /// <summary>
               /// 预约开户(数值:67,字符:'C')
               /// </summary>
               ReserveOpenAccount = 67,

               /// <summary>
               /// 撤销预约开户(数值:68,字符:'D')
               /// </summary>
               CancelReserveOpenAccount = 68,

               /// <summary>
               /// 预约开户确认(数值:69,字符:'E')
               /// </summary>
               ReserveOpenAccountConfirm = 69,

               /// <summary>
               /// 其他(数值:90,字符:'Z')
               /// </summary>
               Other = 90
           };

           /// <summary>
           /// 记录操作类型
           /// </summary>
           public enum class CtpNetDBOperationType
           {
               /// <summary>
               /// 插入(数值:48,字符:'0')
               /// </summary>
               Insert = 48,

               /// <summary>
               /// 更新(数值:49,字符:'1')
               /// </summary>
               Update = 49,

               /// <summary>
               /// 删除(数值:50,字符:'2')
               /// </summary>
               Delete = 50
           };

           /// <summary>
           /// 同步标记类型
           /// </summary>
           public enum class CtpNetSyncFlagType
           {
               /// <summary>
               /// 已同步(数值:48,字符:'0')
               /// </summary>
               Yes = 48,

               /// <summary>
               /// 未同步(数值:49,字符:'1')
               /// </summary>
               No = 49
           };

           /// <summary>
           /// 同步类型
           /// </summary>
           public enum class CtpNetSyncTypeType
           {
               /// <summary>
               /// 一次同步(数值:48,字符:'0')
               /// </summary>
               OneOffSync = 48,

               /// <summary>
               /// 定时同步(数值:49,字符:'1')
               /// </summary>
               TimerSync = 49,

               /// <summary>
               /// 定时完全同步(数值:50,字符:'2')
               /// </summary>
               TimerFullSync = 50
           };

           /// <summary>
           /// 换汇方向类型
           /// </summary>
           public enum class CtpNetExDirectionType
           {
               /// <summary>
               /// 结汇(数值:48,字符:'0')
               /// </summary>
               Settlement = 48,

               /// <summary>
               /// 售汇(数值:49,字符:'1')
               /// </summary>
               Sale = 49
           };

           /// <summary>
           /// 换汇成功标志类型
           /// </summary>
           public enum class CtpNetFBEResultFlagType
           {
               /// <summary>
               /// 成功(数值:48,字符:'0')
               /// </summary>
               Success = 48,

               /// <summary>
               /// 账户余额不足(数值:49,字符:'1')
               /// </summary>
               InsufficientBalance = 49,

               /// <summary>
               /// 交易结果未知(数值:56,字符:'8')
               /// </summary>
               UnknownTrading = 56,

               /// <summary>
               /// 失败(数值:120,字符:'x')
               /// </summary>
               Fail = 120
           };

           /// <summary>
           /// 换汇交易状态类型
           /// </summary>
           public enum class CtpNetFBEExchStatusType
           {
               /// <summary>
               /// 正常(数值:48,字符:'0')
               /// </summary>
               Normal = 48,

               /// <summary>
               /// 交易重发(数值:49,字符:'1')
               /// </summary>
               ReExchange = 49
           };

           /// <summary>
           /// 换汇文件标志类型
           /// </summary>
           public enum class CtpNetFBEFileFlagType
           {
               /// <summary>
               /// 数据包(数值:48,字符:'0')
               /// </summary>
               DataPackage = 48,

               /// <summary>
               /// 文件(数值:49,字符:'1')
               /// </summary>
               File = 49
           };

           /// <summary>
           /// 换汇已交易标志类型
           /// </summary>
           public enum class CtpNetFBEAlreadyTradeType
           {
               /// <summary>
               /// 未交易(数值:48,字符:'0')
               /// </summary>
               NotTrade = 48,

               /// <summary>
               /// 已交易(数值:49,字符:'1')
               /// </summary>
               Trade = 49
           };

           /// <summary>
           /// 银期换汇用户事件类型
           /// </summary>
           public enum class CtpNetFBEUserEventTypeType
           {
               /// <summary>
               /// 签到(数值:48,字符:'0')
               /// </summary>
               SignIn = 48,

               /// <summary>
               /// 换汇(数值:49,字符:'1')
               /// </summary>
               Exchange = 49,

               /// <summary>
               /// 换汇重发(数值:50,字符:'2')
               /// </summary>
               ReExchange = 50,

               /// <summary>
               /// 银行账户查询(数值:51,字符:'3')
               /// </summary>
               QueryBankAccount = 51,

               /// <summary>
               /// 换汇明细查询(数值:52,字符:'4')
               /// </summary>
               QueryExchDetial = 52,

               /// <summary>
               /// 换汇汇总查询(数值:53,字符:'5')
               /// </summary>
               QueryExchSummary = 53,

               /// <summary>
               /// 换汇汇率查询(数值:54,字符:'6')
               /// </summary>
               QueryExchRate = 54,

               /// <summary>
               /// 对账文件通知(数值:55,字符:'7')
               /// </summary>
               CheckBankAccount = 55,

               /// <summary>
               /// 签退(数值:56,字符:'8')
               /// </summary>
               SignOut = 56,

               /// <summary>
               /// 其他(数值:90,字符:'Z')
               /// </summary>
               Other = 90
           };

           /// <summary>
           /// 换汇发送标志类型
           /// </summary>
           public enum class CtpNetFBEReqFlagType
           {
               /// <summary>
               /// 未处理(数值:48,字符:'0')
               /// </summary>
               UnProcessed = 48,

               /// <summary>
               /// 等待发送(数值:49,字符:'1')
               /// </summary>
               WaitSend = 49,

               /// <summary>
               /// 发送成功(数值:50,字符:'2')
               /// </summary>
               SendSuccess = 50,

               /// <summary>
               /// 发送失败(数值:51,字符:'3')
               /// </summary>
               SendFailed = 51,

               /// <summary>
               /// 等待重发(数值:52,字符:'4')
               /// </summary>
               WaitReSend = 52
           };

           /// <summary>
           /// 风险通知类型
           /// </summary>
           public enum class CtpNetNotifyClassType
           {
               /// <summary>
               /// 正常(数值:48,字符:'0')
               /// </summary>
               NOERROR = 48,

               /// <summary>
               /// 警示(数值:49,字符:'1')
               /// </summary>
               Warn = 49,

               /// <summary>
               /// 追保(数值:50,字符:'2')
               /// </summary>
               Call = 50,

               /// <summary>
               /// 强平(数值:51,字符:'3')
               /// </summary>
               Force = 51,

               /// <summary>
               /// 穿仓(数值:52,字符:'4')
               /// </summary>
               CHUANCANG = 52,

               /// <summary>
               /// 异常(数值:53,字符:'5')
               /// </summary>
               Exception = 53
           };

           /// <summary>
           /// 强平单类型
           /// </summary>
           public enum class CtpNetForceCloseTypeType
           {
               /// <summary>
               /// 手工强平(数值:48,字符:'0')
               /// </summary>
               Manual = 48,

               /// <summary>
               /// 单一投资者辅助强平(数值:49,字符:'1')
               /// </summary>
               Single = 49,

               /// <summary>
               /// 批量投资者辅助强平(数值:50,字符:'2')
               /// </summary>
               Group = 50
           };

           /// <summary>
           /// 风险通知途径类型
           /// </summary>
           public enum class CtpNetRiskNotifyMethodType
           {
               /// <summary>
               /// 系统通知(数值:48,字符:'0')
               /// </summary>
               System = 48,

               /// <summary>
               /// 短信通知(数值:49,字符:'1')
               /// </summary>
               SMS = 49,

               /// <summary>
               /// 邮件通知(数值:50,字符:'2')
               /// </summary>
               EMail = 50,

               /// <summary>
               /// 人工通知(数值:51,字符:'3')
               /// </summary>
               Manual = 51
           };

           /// <summary>
           /// 风险通知状态类型
           /// </summary>
           public enum class CtpNetRiskNotifyStatusType
           {
               /// <summary>
               /// 未生成(数值:48,字符:'0')
               /// </summary>
               NotGen = 48,

               /// <summary>
               /// 已生成未发送(数值:49,字符:'1')
               /// </summary>
               Generated = 49,

               /// <summary>
               /// 发送失败(数值:50,字符:'2')
               /// </summary>
               SendError = 50,

               /// <summary>
               /// 已发送未接收(数值:51,字符:'3')
               /// </summary>
               SendOk = 51,

               /// <summary>
               /// 已接收未确认(数值:52,字符:'4')
               /// </summary>
               Received = 52,

               /// <summary>
               /// 已确认(数值:53,字符:'5')
               /// </summary>
               Confirmed = 53
           };

           /// <summary>
           /// 风控用户操作事件类型
           /// </summary>
           public enum class CtpNetRiskUserEventType
           {
               /// <summary>
               /// 导出数据(数值:48,字符:'0')
               /// </summary>
               ExportData = 48
           };

           /// <summary>
           /// 条件单索引条件类型
           /// </summary>
           public enum class CtpNetConditionalOrderSortTypeType
           {
               /// <summary>
               /// 使用最新价升序(数值:48,字符:'0')
               /// </summary>
               LastPriceAsc = 48,

               /// <summary>
               /// 使用最新价降序(数值:49,字符:'1')
               /// </summary>
               LastPriceDesc = 49,

               /// <summary>
               /// 使用卖价升序(数值:50,字符:'2')
               /// </summary>
               AskPriceAsc = 50,

               /// <summary>
               /// 使用卖价降序(数值:51,字符:'3')
               /// </summary>
               AskPriceDesc = 51,

               /// <summary>
               /// 使用买价升序(数值:52,字符:'4')
               /// </summary>
               BidPriceAsc = 52,

               /// <summary>
               /// 使用买价降序(数值:53,字符:'5')
               /// </summary>
               BidPriceDesc = 53
           };

           /// <summary>
           /// 报送状态类型
           /// </summary>
           public enum class CtpNetSendTypeType
           {
               /// <summary>
               /// 未发送(数值:48,字符:'0')
               /// </summary>
               NoSend = 48,

               /// <summary>
               /// 已发送(数值:49,字符:'1')
               /// </summary>
               Sended = 49,

               /// <summary>
               /// 已生成(数值:50,字符:'2')
               /// </summary>
               Generated = 50,

               /// <summary>
               /// 报送失败(数值:51,字符:'3')
               /// </summary>
               SendFail = 51,

               /// <summary>
               /// 接收成功(数值:52,字符:'4')
               /// </summary>
               Success = 52,

               /// <summary>
               /// 接收失败(数值:53,字符:'5')
               /// </summary>
               Fail = 53,

               /// <summary>
               /// 取消报送(数值:54,字符:'6')
               /// </summary>
               Cancel = 54
           };

           /// <summary>
           /// 交易编码状态类型
           /// </summary>
           public enum class CtpNetClientIDStatusType
           {
               /// <summary>
               /// 未申请(数值:49,字符:'1')
               /// </summary>
               NoApply = 49,

               /// <summary>
               /// 已提交申请(数值:50,字符:'2')
               /// </summary>
               Submited = 50,

               /// <summary>
               /// 已发送申请(数值:51,字符:'3')
               /// </summary>
               Sended = 51,

               /// <summary>
               /// 完成(数值:52,字符:'4')
               /// </summary>
               Success = 52,

               /// <summary>
               /// 拒绝(数值:53,字符:'5')
               /// </summary>
               Refuse = 53,

               /// <summary>
               /// 已撤销编码(数值:54,字符:'6')
               /// </summary>
               Cancel = 54
           };

           /// <summary>
           /// 特有信息类型
           /// </summary>
           public enum class CtpNetQuestionTypeType
           {
               /// <summary>
               /// 单选(数值:49,字符:'1')
               /// </summary>
               Radio = 49,

               /// <summary>
               /// 多选(数值:50,字符:'2')
               /// </summary>
               Option = 50,

               /// <summary>
               /// 填空(数值:51,字符:'3')
               /// </summary>
               Blank = 51
           };

           /// <summary>
           /// 业务类型
           /// </summary>
           public enum class CtpNetBusinessTypeType
           {
               /// <summary>
               /// 请求(数值:49,字符:'1')
               /// </summary>
               Request = 49,

               /// <summary>
               /// 应答(数值:50,字符:'2')
               /// </summary>
               Response = 50,

               /// <summary>
               /// 通知(数值:51,字符:'3')
               /// </summary>
               Notice = 51
           };

           /// <summary>
           /// 监控中心返回码类型
           /// </summary>
           public enum class CtpNetCfmmcReturnCodeType
           {
               /// <summary>
               /// 成功(数值:48,字符:'0')
               /// </summary>
               Success = 48,

               /// <summary>
               /// 该客户已经有流程在处理中(数值:49,字符:'1')
               /// </summary>
               Working = 49,

               /// <summary>
               /// 监控中客户资料检查失败(数值:50,字符:'2')
               /// </summary>
               InfoFail = 50,

               /// <summary>
               /// 监控中实名制检查失败(数值:51,字符:'3')
               /// </summary>
               IDCardFail = 51,

               /// <summary>
               /// 其他错误(数值:52,字符:'4')
               /// </summary>
               OtherFail = 52
           };

           /// <summary>
           /// 客户类型
           /// </summary>
           public enum class CtpNetClientTypeType
           {
               /// <summary>
               /// 所有(数值:48,字符:'0')
               /// </summary>
               All = 48,

               /// <summary>
               /// 个人(数值:49,字符:'1')
               /// </summary>
               Person = 49,

               /// <summary>
               /// 单位(数值:50,字符:'2')
               /// </summary>
               Company = 50,

               /// <summary>
               /// 其他(数值:51,字符:'3')
               /// </summary>
               Other = 51,

               /// <summary>
               /// 特殊法人(数值:52,字符:'4')
               /// </summary>
               SpecialOrgan = 52,

               /// <summary>
               /// 资管户(数值:53,字符:'5')
               /// </summary>
               Asset = 53
           };

           /// <summary>
           /// 交易所编号类型
           /// </summary>
           public enum class CtpNetExchangeIDTypeType
           {
               /// <summary>
               /// 上海期货交易所(数值:83,字符:'S')
               /// </summary>
               SHFE = 83,

               /// <summary>
               /// 郑州商品交易所(数值:90,字符:'Z')
               /// </summary>
               CZCE = 90,

               /// <summary>
               /// 大连商品交易所(数值:68,字符:'D')
               /// </summary>
               DCE = 68,

               /// <summary>
               /// 中国金融期货交易所(数值:74,字符:'J')
               /// </summary>
               CFFEX = 74,

               /// <summary>
               /// 上海国际能源交易中心股份有限公司(数值:78,字符:'N')
               /// </summary>
               INE = 78
           };

           /// <summary>
           /// 交易编码类型
           /// </summary>
           public enum class CtpNetExClientIDTypeType
           {
               /// <summary>
               /// 套保(数值:49,字符:'1')
               /// </summary>
               Hedge = 49,

               /// <summary>
               /// 套利(数值:50,字符:'2')
               /// </summary>
               Arbitrage = 50,

               /// <summary>
               /// 投机(数值:51,字符:'3')
               /// </summary>
               Speculation = 51
           };

           /// <summary>
           /// 更新状态类型
           /// </summary>
           public enum class CtpNetUpdateFlagType
           {
               /// <summary>
               /// 未更新(数值:48,字符:'0')
               /// </summary>
               NoUpdate = 48,

               /// <summary>
               /// 更新全部信息成功(数值:49,字符:'1')
               /// </summary>
               Success = 49,

               /// <summary>
               /// 更新全部信息失败(数值:50,字符:'2')
               /// </summary>
               Fail = 50,

               /// <summary>
               /// 更新交易编码成功(数值:51,字符:'3')
               /// </summary>
               TCSuccess = 51,

               /// <summary>
               /// 更新交易编码失败(数值:52,字符:'4')
               /// </summary>
               TCFail = 52,

               /// <summary>
               /// 已丢弃(数值:53,字符:'5')
               /// </summary>
               Cancel = 53
           };

           /// <summary>
           /// 申请动作类型
           /// </summary>
           public enum class CtpNetApplyOperateIDType
           {
               /// <summary>
               /// 开户(数值:49,字符:'1')
               /// </summary>
               OpenInvestor = 49,

               /// <summary>
               /// 修改身份信息(数值:50,字符:'2')
               /// </summary>
               ModifyIDCard = 50,

               /// <summary>
               /// 修改一般信息(数值:51,字符:'3')
               /// </summary>
               ModifyNoIDCard = 51,

               /// <summary>
               /// 申请交易编码(数值:52,字符:'4')
               /// </summary>
               ApplyTradingCode = 52,

               /// <summary>
               /// 撤销交易编码(数值:53,字符:'5')
               /// </summary>
               CancelTradingCode = 53,

               /// <summary>
               /// 销户(数值:54,字符:'6')
               /// </summary>
               CancelInvestor = 54,

               /// <summary>
               /// 账户休眠(数值:56,字符:'8')
               /// </summary>
               FreezeAccount = 56,

               /// <summary>
               /// 激活休眠账户(数值:57,字符:'9')
               /// </summary>
               ActiveFreezeAccount = 57
           };

           /// <summary>
           /// 申请状态类型
           /// </summary>
           public enum class CtpNetApplyStatusIDType
           {
               /// <summary>
               /// 未补全(数值:49,字符:'1')
               /// </summary>
               NoComplete = 49,

               /// <summary>
               /// 已提交(数值:50,字符:'2')
               /// </summary>
               Submited = 50,

               /// <summary>
               /// 已审核(数值:51,字符:'3')
               /// </summary>
               Checked = 51,

               /// <summary>
               /// 已拒绝(数值:52,字符:'4')
               /// </summary>
               Refused = 52,

               /// <summary>
               /// 已删除(数值:53,字符:'5')
               /// </summary>
               Deleted = 53
           };

           /// <summary>
           /// 发送方式类型
           /// </summary>
           public enum class CtpNetSendMethodType
           {
               /// <summary>
               /// 文件发送(数值:49,字符:'1')
               /// </summary>
               ByAPI = 49,

               /// <summary>
               /// 电子发送(数值:50,字符:'2')
               /// </summary>
               ByFile = 50
           };

           /// <summary>
           /// 操作方法类型
           /// </summary>
           public enum class CtpNetEventModeType
           {
               /// <summary>
               /// 增加(数值:49,字符:'1')
               /// </summary>
               ADD = 49,

               /// <summary>
               /// 修改(数值:50,字符:'2')
               /// </summary>
               UPDATE = 50,

               /// <summary>
               /// 删除(数值:51,字符:'3')
               /// </summary>
               DELETE = 51,

               /// <summary>
               /// 复核(数值:52,字符:'4')
               /// </summary>
               CHECK = 52,

               /// <summary>
               /// 复制(数值:53,字符:'5')
               /// </summary>
               COPY = 53,

               /// <summary>
               /// 注销(数值:54,字符:'6')
               /// </summary>
               CANCEL = 54,

               /// <summary>
               /// 冲销(数值:55,字符:'7')
               /// </summary>
               Reverse = 55
           };

           /// <summary>
           /// 统一开户申请自动发送类型
           /// </summary>
           public enum class CtpNetUOAAutoSendType
           {
               /// <summary>
               /// 自动发送并接收(数值:49,字符:'1')
               /// </summary>
               ASR = 49,

               /// <summary>
               /// 自动发送，不自动接收(数值:50,字符:'2')
               /// </summary>
               ASNR = 50,

               /// <summary>
               /// 不自动发送，自动接收(数值:51,字符:'3')
               /// </summary>
               NSAR = 51,

               /// <summary>
               /// 不自动发送，也不自动接收(数值:52,字符:'4')
               /// </summary>
               NSR = 52
           };

           /// <summary>
           /// 流程ID类型
           /// </summary>
           public enum class CtpNetFlowIDType
           {
               /// <summary>
               /// 投资者对应投资者组设置(数值:49,字符:'1')
               /// </summary>
               InvestorGroupFlow = 49,

               /// <summary>
               /// 投资者手续费率设置(数值:50,字符:'2')
               /// </summary>
               InvestorRate = 50,

               /// <summary>
               /// 投资者手续费率模板关系设置(数值:51,字符:'3')
               /// </summary>
               InvestorCommRateModel = 51
           };

           /// <summary>
           /// 复核级别类型
           /// </summary>
           public enum class CtpNetCheckLevelType
           {
               /// <summary>
               /// 零级复核(数值:48,字符:'0')
               /// </summary>
               Zero = 48,

               /// <summary>
               /// 一级复核(数值:49,字符:'1')
               /// </summary>
               One = 49,

               /// <summary>
               /// 二级复核(数值:50,字符:'2')
               /// </summary>
               Two = 50
           };

           /// <summary>
           /// 复核级别类型
           /// </summary>
           public enum class CtpNetCheckStatusType
           {
               /// <summary>
               /// 未复核(数值:48,字符:'0')
               /// </summary>
               Init = 48,

               /// <summary>
               /// 复核中(数值:49,字符:'1')
               /// </summary>
               Checking = 49,

               /// <summary>
               /// 已复核(数值:50,字符:'2')
               /// </summary>
               Checked = 50,

               /// <summary>
               /// 拒绝(数值:51,字符:'3')
               /// </summary>
               Refuse = 51,

               /// <summary>
               /// 作废(数值:52,字符:'4')
               /// </summary>
               Cancel = 52
           };

           /// <summary>
           /// 生效状态类型
           /// </summary>
           public enum class CtpNetUsedStatusType
           {
               /// <summary>
               /// 未生效(数值:48,字符:'0')
               /// </summary>
               Unused = 48,

               /// <summary>
               /// 已生效(数值:49,字符:'1')
               /// </summary>
               Used = 49,

               /// <summary>
               /// 生效失败(数值:50,字符:'2')
               /// </summary>
               Fail = 50
           };

           /// <summary>
           /// 账户来源类型
           /// </summary>
           public enum class CtpNetBankAcountOriginType
           {
               /// <summary>
               /// 手工录入(数值:48,字符:'0')
               /// </summary>
               ByAccProperty = 48,

               /// <summary>
               /// 银期转账(数值:49,字符:'1')
               /// </summary>
               ByFBTransfer = 49
           };

           /// <summary>
           /// 结算单月报成交汇总方式类型
           /// </summary>
           public enum class CtpNetMonthBillTradeSumType
           {
               /// <summary>
               /// 同日同合约(数值:48,字符:'0')
               /// </summary>
               ByInstrument = 48,

               /// <summary>
               /// 同日同合约同价格(数值:49,字符:'1')
               /// </summary>
               ByDayInsPrc = 49,

               /// <summary>
               /// 同合约(数值:50,字符:'2')
               /// </summary>
               ByDayIns = 50
           };

           /// <summary>
           /// 银期交易代码枚举类型
           /// </summary>
           public enum class CtpNetFBTTradeCodeEnumType
           {
               /// <summary>
               /// 银行发起银行转期货(数值:49,字符:'0')
               /// </summary>
               BankLaunchBankToBroker_102001 = 49,

               /// <summary>
               /// 期货发起银行转期货(数值:50,字符:'1')
               /// </summary>
               BrokerLaunchBankToBroker_202001 = 50,

               /// <summary>
               /// 银行发起期货转银行(数值:51,字符:'2')
               /// </summary>
               BankLaunchBrokerToBank_102002 = 51,

               /// <summary>
               /// 期货发起期货转银行(数值:52,字符:'3')
               /// </summary>
               BrokerLaunchBrokerToBank_202002 = 52
           };

           /// <summary>
           /// 动态令牌类型
           /// </summary>
           public enum class CtpNetOTPTypeType
           {
               /// <summary>
               /// 无动态令牌(数值:48,字符:'0')
               /// </summary>
               NONE = 48,

               /// <summary>
               /// 时间令牌(数值:49,字符:'1')
               /// </summary>
               TOTP = 49
           };

           /// <summary>
           /// 动态令牌状态类型
           /// </summary>
           public enum class CtpNetOTPStatusType
           {
               /// <summary>
               /// 未使用(数值:48,字符:'0')
               /// </summary>
               Unused = 48,

               /// <summary>
               /// 已使用(数值:49,字符:'1')
               /// </summary>
               Used = 49,

               /// <summary>
               /// 注销(数值:50,字符:'2')
               /// </summary>
               Disuse = 50
           };

           /// <summary>
           /// 经济公司用户类型
           /// </summary>
           public enum class CtpNetBrokerUserTypeType
           {
               /// <summary>
               /// 投资者(数值:49,字符:'1')
               /// </summary>
               Investor = 49,

               /// <summary>
               /// 操作员(数值:50,字符:'2')
               /// </summary>
               BrokerUser = 50
           };

           /// <summary>
           /// 期货类型
           /// </summary>
           public enum class CtpNetFutureTypeType
           {
               /// <summary>
               /// 商品期货(数值:49,字符:'1')
               /// </summary>
               Commodity = 49,

               /// <summary>
               /// 金融期货(数值:50,字符:'2')
               /// </summary>
               Financial = 50
           };

           /// <summary>
           /// 资金管理操作类型
           /// </summary>
           public enum class CtpNetFundEventTypeType
           {
               /// <summary>
               /// 转账限额(数值:48,字符:'0')
               /// </summary>
               Restriction = 48,

               /// <summary>
               /// 当日转账限额(数值:49,字符:'1')
               /// </summary>
               TodayRestriction = 49,

               /// <summary>
               /// 期商流水(数值:50,字符:'2')
               /// </summary>
               Transfer = 50,

               /// <summary>
               /// 资金冻结(数值:51,字符:'3')
               /// </summary>
               Credit = 51,

               /// <summary>
               /// 投资者可提资金比例(数值:52,字符:'4')
               /// </summary>
               InvestorWithdrawAlm = 52,

               /// <summary>
               /// 单个银行帐户转账限额(数值:53,字符:'5')
               /// </summary>
               BankRestriction = 53,

               /// <summary>
               /// 银期签约账户(数值:54,字符:'6')
               /// </summary>
               Accountregister = 54,

               /// <summary>
               /// 交易所出入金(数值:55,字符:'7')
               /// </summary>
               ExchangeFundIO = 55,

               /// <summary>
               /// 投资者出入金(数值:56,字符:'8')
               /// </summary>
               InvestorFundIO = 56
           };

           /// <summary>
           /// 资金账户来源类型
           /// </summary>
           public enum class CtpNetAccountSourceTypeType
           {
               /// <summary>
               /// 银期同步(数值:48,字符:'0')
               /// </summary>
               FBTransfer = 48,

               /// <summary>
               /// 手工录入(数值:49,字符:'1')
               /// </summary>
               ManualEntry = 49
           };

           /// <summary>
           /// 交易编码来源类型
           /// </summary>
           public enum class CtpNetCodeSourceTypeType
           {
               /// <summary>
               /// 统一开户(已规范)(数值:48,字符:'0')
               /// </summary>
               UnifyAccount = 48,

               /// <summary>
               /// 手工录入(未规范)(数值:49,字符:'1')
               /// </summary>
               ManualEntry = 49
           };

           /// <summary>
           /// 操作员范围类型
           /// </summary>
           public enum class CtpNetUserRangeType
           {
               /// <summary>
               /// 所有(数值:48,字符:'0')
               /// </summary>
               All = 48,

               /// <summary>
               /// 单一操作员(数值:49,字符:'1')
               /// </summary>
               Single = 49
           };

           /// <summary>
           /// 交易统计表按客户统计方式类型
           /// </summary>
           public enum class CtpNetByGroupType
           {
               /// <summary>
               /// 按投资者统计(数值:50,字符:'2')
               /// </summary>
               Investor = 50,

               /// <summary>
               /// 按类统计(数值:49,字符:'1')
               /// </summary>
               Group = 49
           };

           /// <summary>
           /// 交易统计表按范围统计方式类型
           /// </summary>
           public enum class CtpNetTradeSumStatModeType
           {
               /// <summary>
               /// 按合约统计(数值:49,字符:'1')
               /// </summary>
               Instrument = 49,

               /// <summary>
               /// 按产品统计(数值:50,字符:'2')
               /// </summary>
               Product = 50,

               /// <summary>
               /// 按交易所统计(数值:51,字符:'3')
               /// </summary>
               Exchange = 51
           };

           /// <summary>
           /// 日期表达式设置类型
           /// </summary>
           public enum class CtpNetExprSetModeType
           {
               /// <summary>
               /// 相对已有规则设置(数值:49,字符:'1')
               /// </summary>
               Relative = 49,

               /// <summary>
               /// 典型设置(数值:50,字符:'2')
               /// </summary>
               Typical = 50
           };

           /// <summary>
           /// 投资者范围类型
           /// </summary>
           public enum class CtpNetRateInvestorRangeType
           {
               /// <summary>
               /// 公司标准(数值:49,字符:'1')
               /// </summary>
               All = 49,

               /// <summary>
               /// 模板(数值:50,字符:'2')
               /// </summary>
               Model = 50,

               /// <summary>
               /// 单一投资者(数值:51,字符:'3')
               /// </summary>
               Single = 51
           };

           /// <summary>
           /// 主次用系统数据同步状态类型
           /// </summary>
           public enum class CtpNetSyncDataStatusType
           {
               /// <summary>
               /// 未同步(数值:48,字符:'0')
               /// </summary>
               Initialize = 48,

               /// <summary>
               /// 同步中(数值:49,字符:'1')
               /// </summary>
               Settlementing = 49,

               /// <summary>
               /// 已同步(数值:50,字符:'2')
               /// </summary>
               Settlemented = 50
           };

           /// <summary>
           /// 成交来源类型
           /// </summary>
           public enum class CtpNetTradeSourceType
           {
               /// <summary>
               /// 来自交易所普通回报(数值:48,字符:'0')
               /// </summary>
               NORMAL = 48,

               /// <summary>
               /// 来自查询(数值:49,字符:'1')
               /// </summary>
               QUERY = 49
           };

           /// <summary>
           /// 产品合约统计方式类型
           /// </summary>
           public enum class CtpNetFlexStatModeType
           {
               /// <summary>
               /// 产品统计(数值:49,字符:'1')
               /// </summary>
               Product = 49,

               /// <summary>
               /// 交易所统计(数值:50,字符:'2')
               /// </summary>
               Exchange = 50,

               /// <summary>
               /// 统计所有(数值:51,字符:'3')
               /// </summary>
               All = 51
           };

           /// <summary>
           /// 投资者范围统计方式类型
           /// </summary>
           public enum class CtpNetByInvestorRangeType
           {
               /// <summary>
               /// 属性统计(数值:49,字符:'1')
               /// </summary>
               Property = 49,

               /// <summary>
               /// 统计所有(数值:50,字符:'2')
               /// </summary>
               All = 50
           };

           /// <summary>
           /// 投资者范围类型
           /// </summary>
           public enum class CtpNetPropertyInvestorRangeType
           {
               /// <summary>
               /// 所有(数值:49,字符:'1')
               /// </summary>
               All = 49,

               /// <summary>
               /// 投资者属性(数值:50,字符:'2')
               /// </summary>
               Property = 50,

               /// <summary>
               /// 单一投资者(数值:51,字符:'3')
               /// </summary>
               Single = 51
           };

           /// <summary>
           /// 文件状态类型
           /// </summary>
           public enum class CtpNetFileStatusType
           {
               /// <summary>
               /// 未生成(数值:48,字符:'0')
               /// </summary>
               NoCreate = 48,

               /// <summary>
               /// 已生成(数值:49,字符:'1')
               /// </summary>
               Created = 49,

               /// <summary>
               /// 生成失败(数值:50,字符:'2')
               /// </summary>
               Failed = 50
           };

           /// <summary>
           /// 文件生成方式类型
           /// </summary>
           public enum class CtpNetFileGenStyleType
           {
               /// <summary>
               /// 下发(数值:48,字符:'0')
               /// </summary>
               FileTransmit = 48,

               /// <summary>
               /// 生成(数值:49,字符:'1')
               /// </summary>
               FileGen = 49
           };

           /// <summary>
           /// 系统日志操作方法类型
           /// </summary>
           public enum class CtpNetSysOperModeType
           {
               /// <summary>
               /// 增加(数值:49,字符:'1')
               /// </summary>
               Add = 49,

               /// <summary>
               /// 修改(数值:50,字符:'2')
               /// </summary>
               Update = 50,

               /// <summary>
               /// 删除(数值:51,字符:'3')
               /// </summary>
               Delete = 51,

               /// <summary>
               /// 复制(数值:52,字符:'4')
               /// </summary>
               Copy = 52,

               /// <summary>
               /// 激活(数值:53,字符:'5')
               /// </summary>
               AcTive = 53,

               /// <summary>
               /// 注销(数值:54,字符:'6')
               /// </summary>
               CanCel = 54,

               /// <summary>
               /// 重置(数值:55,字符:'7')
               /// </summary>
               ReSet = 55
           };

           /// <summary>
           /// 系统日志操作类型
           /// </summary>
           public enum class CtpNetSysOperTypeType
           {
               /// <summary>
               /// 修改操作员密码(数值:48,字符:'0')
               /// </summary>
               UpdatePassword = 48,

               /// <summary>
               /// 操作员组织架构关系(数值:49,字符:'1')
               /// </summary>
               UserDepartment = 49,

               /// <summary>
               /// 角色管理(数值:50,字符:'2')
               /// </summary>
               RoleManager = 50,

               /// <summary>
               /// 角色功能设置(数值:51,字符:'3')
               /// </summary>
               RoleFunction = 51,

               /// <summary>
               /// 基础参数设置(数值:52,字符:'4')
               /// </summary>
               BaseParam = 52,

               /// <summary>
               /// 设置操作员(数值:53,字符:'5')
               /// </summary>
               SetUserID = 53,

               /// <summary>
               /// 用户角色设置(数值:54,字符:'6')
               /// </summary>
               SetUserRole = 54,

               /// <summary>
               /// 用户IP限制(数值:55,字符:'7')
               /// </summary>
               UserIpRestriction = 55,

               /// <summary>
               /// 组织架构管理(数值:56,字符:'8')
               /// </summary>
               DepartmentManager = 56,

               /// <summary>
               /// 组织架构向查询分类复制(数值:57,字符:'9')
               /// </summary>
               DepartmentCopy = 57,

               /// <summary>
               /// 交易编码管理(数值:65,字符:'A')
               /// </summary>
               Tradingcode = 65,

               /// <summary>
               /// 投资者状态维护(数值:66,字符:'B')
               /// </summary>
               InvestorStatus = 66,

               /// <summary>
               /// 投资者权限管理(数值:67,字符:'C')
               /// </summary>
               InvestorAuthority = 67,

               /// <summary>
               /// 属性设置(数值:68,字符:'D')
               /// </summary>
               PropertySet = 68,

               /// <summary>
               /// 重置投资者密码(数值:69,字符:'E')
               /// </summary>
               ReSetInvestorPasswd = 69,

               /// <summary>
               /// 投资者个性信息维护(数值:70,字符:'F')
               /// </summary>
               InvestorPersonalityInfo = 70
           };

           /// <summary>
           /// 上报数据查询类型
           /// </summary>
           public enum class CtpNetCSRCDataQueyTypeType
           {
               /// <summary>
               /// 查询当前交易日报送的数据(数值:48,字符:'0')
               /// </summary>
               Current = 48,

               /// <summary>
               /// 查询历史报送的代理经纪公司的数据(数值:49,字符:'1')
               /// </summary>
               History = 49
           };

           /// <summary>
           /// 休眠状态类型
           /// </summary>
           public enum class CtpNetFreezeStatusType
           {
               /// <summary>
               /// 活跃(数值:49,字符:'1')
               /// </summary>
               Normal = 49,

               /// <summary>
               /// 休眠(数值:48,字符:'0')
               /// </summary>
               Freeze = 48
           };

           /// <summary>
           /// 规范状态类型
           /// </summary>
           public enum class CtpNetStandardStatusType
           {
               /// <summary>
               /// 已规范(数值:48,字符:'0')
               /// </summary>
               Standard = 48,

               /// <summary>
               /// 未规范(数值:49,字符:'1')
               /// </summary>
               NonStandard = 49
           };

           /// <summary>
           /// 配置类型
           /// </summary>
           public enum class CtpNetRightParamTypeType
           {
               /// <summary>
               /// 休眠户(数值:49,字符:'1')
               /// </summary>
               Freeze = 49,

               /// <summary>
               /// 激活休眠户(数值:50,字符:'2')
               /// </summary>
               FreezeActive = 50,

               /// <summary>
               /// 开仓权限限制(数值:51,字符:'3')
               /// </summary>
               OpenLimit = 51,

               /// <summary>
               /// 解除开仓权限限制(数值:52,字符:'4')
               /// </summary>
               RelieveOpenLimit = 52
           };

           /// <summary>
           /// 反洗钱审核表数据状态类型
           /// </summary>
           public enum class CtpNetDataStatusType
           {
               /// <summary>
               /// 正常(数值:48,字符:'0')
               /// </summary>
               Normal = 48,

               /// <summary>
               /// 已删除(数值:49,字符:'1')
               /// </summary>
               Deleted = 49
           };

           /// <summary>
           /// 审核状态类型
           /// </summary>
           public enum class CtpNetAMLCheckStatusType
           {
               /// <summary>
               /// 未复核(数值:48,字符:'0')
               /// </summary>
               Init = 48,

               /// <summary>
               /// 复核中(数值:49,字符:'1')
               /// </summary>
               Checking = 49,

               /// <summary>
               /// 已复核(数值:50,字符:'2')
               /// </summary>
               Checked = 50,

               /// <summary>
               /// 拒绝上报(数值:51,字符:'3')
               /// </summary>
               RefuseReport = 51
           };

           /// <summary>
           /// 日期类型
           /// </summary>
           public enum class CtpNetAmlDateTypeType
           {
               /// <summary>
               /// 检查日期(数值:48,字符:'0')
               /// </summary>
               DrawDay = 48,

               /// <summary>
               /// 发生日期(数值:49,字符:'1')
               /// </summary>
               TouchDay = 49
           };

           /// <summary>
           /// 审核级别类型
           /// </summary>
           public enum class CtpNetAmlCheckLevelType
           {
               /// <summary>
               /// 零级审核(数值:48,字符:'0')
               /// </summary>
               CheckLevel0 = 48,

               /// <summary>
               /// 一级审核(数值:49,字符:'1')
               /// </summary>
               CheckLevel1 = 49,

               /// <summary>
               /// 二级审核(数值:50,字符:'2')
               /// </summary>
               CheckLevel2 = 50,

               /// <summary>
               /// 三级审核(数值:51,字符:'3')
               /// </summary>
               CheckLevel3 = 51
           };

           /// <summary>
           /// 导出文件类型
           /// </summary>
           public enum class CtpNetExportFileTypeType
           {
               /// <summary>
               /// CSV(数值:48,字符:'0')
               /// </summary>
               CSV = 48,

               /// <summary>
               /// Excel(数值:49,字符:'1')
               /// </summary>
               EXCEL = 49,

               /// <summary>
               /// DBF(数值:50,字符:'2')
               /// </summary>
               DBF = 50
           };

           /// <summary>
           /// 结算配置类型
           /// </summary>
           public enum class CtpNetSettleManagerTypeType
           {
               /// <summary>
               /// 结算前准备(数值:49,字符:'1')
               /// </summary>
               Before = 49,

               /// <summary>
               /// 结算(数值:50,字符:'2')
               /// </summary>
               Settlement = 50,

               /// <summary>
               /// 结算后核对(数值:51,字符:'3')
               /// </summary>
               After = 51,

               /// <summary>
               /// 结算后处理(数值:52,字符:'4')
               /// </summary>
               Settlemented = 52
           };

           /// <summary>
           /// 结算配置等级类型
           /// </summary>
           public enum class CtpNetSettleManagerLevelType
           {
               /// <summary>
               /// 必要(数值:49,字符:'1')
               /// </summary>
               Must = 49,

               /// <summary>
               /// 警告(数值:50,字符:'2')
               /// </summary>
               Alarm = 50,

               /// <summary>
               /// 提示(数值:51,字符:'3')
               /// </summary>
               Prompt = 51,

               /// <summary>
               /// 不检查(数值:52,字符:'4')
               /// </summary>
               Ignore = 52
           };

           /// <summary>
           /// 模块分组类型
           /// </summary>
           public enum class CtpNetSettleManagerGroupType
           {
               /// <summary>
               /// 交易所核对(数值:49,字符:'1')
               /// </summary>
               Exhcange = 49,

               /// <summary>
               /// 内部核对(数值:50,字符:'2')
               /// </summary>
               ASP = 50,

               /// <summary>
               /// 上报数据核对(数值:51,字符:'3')
               /// </summary>
               CSRC = 51
           };

           /// <summary>
           /// 保值额度使用类型
           /// </summary>
           public enum class CtpNetLimitUseTypeType
           {
               /// <summary>
               /// 可重复使用(数值:49,字符:'1')
               /// </summary>
               Repeatable = 49,

               /// <summary>
               /// 不可重复使用(数值:50,字符:'2')
               /// </summary>
               Unrepeatable = 50
           };

           /// <summary>
           /// 数据来源类型
           /// </summary>
           public enum class CtpNetDataResourceType
           {
               /// <summary>
               /// 本系统(数值:49,字符:'1')
               /// </summary>
               Settle = 49,

               /// <summary>
               /// 交易所(数值:50,字符:'2')
               /// </summary>
               Exchange = 50,

               /// <summary>
               /// 报送数据(数值:51,字符:'3')
               /// </summary>
               CSRC = 51
           };

           /// <summary>
           /// 保证金类型
           /// </summary>
           public enum class CtpNetMarginTypeType
           {
               /// <summary>
               /// 交易所保证金率(数值:48,字符:'0')
               /// </summary>
               ExchMarginRate = 48,

               /// <summary>
               /// 投资者保证金率(数值:49,字符:'1')
               /// </summary>
               InstrMarginRate = 49,

               /// <summary>
               /// 投资者交易保证金率(数值:50,字符:'2')
               /// </summary>
               InstrMarginRateTrade = 50
           };

           /// <summary>
           /// 生效类型
           /// </summary>
           public enum class CtpNetActiveTypeType
           {
               /// <summary>
               /// 仅当日生效(数值:49,字符:'1')
               /// </summary>
               Intraday = 49,

               /// <summary>
               /// 长期生效(数值:50,字符:'2')
               /// </summary>
               Long = 50
           };

           /// <summary>
           /// 冲突保证金率类型
           /// </summary>
           public enum class CtpNetMarginRateTypeType
           {
               /// <summary>
               /// 交易所保证金率(数值:49,字符:'1')
               /// </summary>
               Exchange = 49,

               /// <summary>
               /// 投资者保证金率(数值:50,字符:'2')
               /// </summary>
               Investor = 50,

               /// <summary>
               /// 投资者交易保证金率(数值:51,字符:'3')
               /// </summary>
               InvestorTrade = 51
           };

           /// <summary>
           /// 备份数据状态类型
           /// </summary>
           public enum class CtpNetBackUpStatusType
           {
               /// <summary>
               /// 未生成备份数据(数值:48,字符:'0')
               /// </summary>
               UnBak = 48,

               /// <summary>
               /// 备份数据生成中(数值:49,字符:'1')
               /// </summary>
               BakUp = 49,

               /// <summary>
               /// 已生成备份数据(数值:50,字符:'2')
               /// </summary>
               BakUped = 50,

               /// <summary>
               /// 备份数据失败(数值:51,字符:'3')
               /// </summary>
               BakFail = 51
           };

           /// <summary>
           /// 结算初始化状态类型
           /// </summary>
           public enum class CtpNetInitSettlementType
           {
               /// <summary>
               /// 结算初始化未开始(数值:48,字符:'0')
               /// </summary>
               UnInitialize = 48,

               /// <summary>
               /// 结算初始化中(数值:49,字符:'1')
               /// </summary>
               Initialize = 49,

               /// <summary>
               /// 结算初始化完成(数值:50,字符:'2')
               /// </summary>
               Initialized = 50
           };

           /// <summary>
           /// 报表数据生成状态类型
           /// </summary>
           public enum class CtpNetReportStatusType
           {
               /// <summary>
               /// 未生成报表数据(数值:48,字符:'0')
               /// </summary>
               NoCreate = 48,

               /// <summary>
               /// 报表数据生成中(数值:49,字符:'1')
               /// </summary>
               Create = 49,

               /// <summary>
               /// 已生成报表数据(数值:50,字符:'2')
               /// </summary>
               Created = 50,

               /// <summary>
               /// 生成报表数据失败(数值:51,字符:'3')
               /// </summary>
               CreateFail = 51
           };

           /// <summary>
           /// 数据归档状态类型
           /// </summary>
           public enum class CtpNetSaveStatusType
           {
               /// <summary>
               /// 归档未完成(数值:48,字符:'0')
               /// </summary>
               UnSaveData = 48,

               /// <summary>
               /// 归档完成(数值:49,字符:'1')
               /// </summary>
               SaveDatad = 49
           };

           /// <summary>
           /// 结算确认数据归档状态类型
           /// </summary>
           public enum class CtpNetSettArchiveStatusType
           {
               /// <summary>
               /// 未归档数据(数值:48,字符:'0')
               /// </summary>
               UnArchived = 48,

               /// <summary>
               /// 数据归档中(数值:49,字符:'1')
               /// </summary>
               Archiving = 49,

               /// <summary>
               /// 已归档数据(数值:50,字符:'2')
               /// </summary>
               Archived = 50,

               /// <summary>
               /// 归档数据失败(数值:51,字符:'3')
               /// </summary>
               ArchiveFail = 51
           };

           /// <summary>
           /// CTP交易系统类型
           /// </summary>
           public enum class CtpNetCTPTypeType
           {
               /// <summary>
               /// 未知类型(数值:48,字符:'0')
               /// </summary>
               Unkown = 48,

               /// <summary>
               /// 主中心(数值:49,字符:'1')
               /// </summary>
               MainCenter = 49,

               /// <summary>
               /// 备中心(数值:50,字符:'2')
               /// </summary>
               BackUp = 50
           };

           /// <summary>
           /// 平仓处理类型
           /// </summary>
           public enum class CtpNetCloseDealTypeType
           {
               /// <summary>
               /// 正常(数值:48,字符:'0')
               /// </summary>
               Normal = 48,

               /// <summary>
               /// 投机平仓优先(数值:49,字符:'1')
               /// </summary>
               SpecFirst = 49
           };

           /// <summary>
           /// 货币质押资金可用范围类型
           /// </summary>
           public enum class CtpNetMortgageFundUseRangeType
           {
               /// <summary>
               /// 不能使用(数值:48,字符:'0')
               /// </summary>
               None = 48,

               /// <summary>
               /// 用于保证金(数值:49,字符:'1')
               /// </summary>
               Margin = 49,

               /// <summary>
               /// 用于手续费、盈亏、保证金(数值:50,字符:'2')
               /// </summary>
               All = 50
           };

           /// <summary>
           /// 特殊产品类型
           /// </summary>
           public enum class CtpNetSpecProductTypeType
           {
               /// <summary>
               /// 郑商所套保产品(数值:49,字符:'1')
               /// </summary>
               CzceHedge = 49,

               /// <summary>
               /// 货币质押产品(数值:50,字符:'2')
               /// </summary>
               IneForeignCurrency = 50,

               /// <summary>
               /// 大连短线开平仓产品(数值:51,字符:'3')
               /// </summary>
               DceOpenClose = 51
           };

           /// <summary>
           /// 货币质押类型
           /// </summary>
           public enum class CtpNetFundMortgageTypeType
           {
               /// <summary>
               /// 质押(数值:49,字符:'1')
               /// </summary>
               Mortgage = 49,

               /// <summary>
               /// 解质(数值:50,字符:'2')
               /// </summary>
               Redemption = 50
           };

           /// <summary>
           /// 投资者账户结算参数代码类型
           /// </summary>
           public enum class CtpNetAccountSettlementParamIDType
           {
               /// <summary>
               /// 基础保证金(数值:49,字符:'1')
               /// </summary>
               BaseMargin = 49,

               /// <summary>
               /// 最低权益标准(数值:50,字符:'2')
               /// </summary>
               LowestInterest = 50
           };

           /// <summary>
           /// 货币质押方向类型
           /// </summary>
           public enum class CtpNetFundMortDirectionType
           {
               /// <summary>
               /// 货币质入(数值:49,字符:'1')
               /// </summary>
               In = 49,

               /// <summary>
               /// 货币质出(数值:50,字符:'2')
               /// </summary>
               Out = 50
           };

           /// <summary>
           /// 换汇类别类型
           /// </summary>
           public enum class CtpNetBusinessClassType
           {
               /// <summary>
               /// 盈利(数值:48,字符:'0')
               /// </summary>
               Profit = 48,

               /// <summary>
               /// 亏损(数值:49,字符:'1')
               /// </summary>
               Loss = 49,

               /// <summary>
               /// 其他(数值:90,字符:'Z')
               /// </summary>
               Other = 90
           };

           /// <summary>
           /// 换汇数据来源类型
           /// </summary>
           public enum class CtpNetSwapSourceTypeType
           {
               /// <summary>
               /// 手工(数值:48,字符:'0')
               /// </summary>
               Manual = 48,

               /// <summary>
               /// 自动生成(数值:49,字符:'1')
               /// </summary>
               Automatic = 49
           };

           /// <summary>
           /// 换汇类型
           /// </summary>
           public enum class CtpNetCurrExDirectionType
           {
               /// <summary>
               /// 结汇(数值:48,字符:'0')
               /// </summary>
               Settlement = 48,

               /// <summary>
               /// 售汇(数值:49,字符:'1')
               /// </summary>
               Sale = 49
           };

           /// <summary>
           /// 申请状态类型
           /// </summary>
           public enum class CtpNetCurrencySwapStatusType
           {
               /// <summary>
               /// 已录入(数值:49,字符:'1')
               /// </summary>
               Entry = 49,

               /// <summary>
               /// 已审核(数值:50,字符:'2')
               /// </summary>
               Approve = 50,

               /// <summary>
               /// 已拒绝(数值:51,字符:'3')
               /// </summary>
               Refuse = 51,

               /// <summary>
               /// 已撤销(数值:52,字符:'4')
               /// </summary>
               Revoke = 52,

               /// <summary>
               /// 已发送(数值:53,字符:'5')
               /// </summary>
               Send = 53,

               /// <summary>
               /// 换汇成功(数值:54,字符:'6')
               /// </summary>
               Success = 54,

               /// <summary>
               /// 换汇失败(数值:55,字符:'7')
               /// </summary>
               Failure = 55
           };

           /// <summary>
           /// 换汇发送标志类型
           /// </summary>
           public enum class CtpNetReqFlagType
           {
               /// <summary>
               /// 未发送(数值:48,字符:'0')
               /// </summary>
               NoSend = 48,

               /// <summary>
               /// 发送成功(数值:49,字符:'1')
               /// </summary>
               SendSuccess = 49,

               /// <summary>
               /// 发送失败(数值:50,字符:'2')
               /// </summary>
               SendFailed = 50,

               /// <summary>
               /// 等待重发(数值:51,字符:'3')
               /// </summary>
               WaitReSend = 51
           };

           /// <summary>
           /// 换汇返回成功标志类型
           /// </summary>
           public enum class CtpNetResFlagType
           {
               /// <summary>
               /// 成功(数值:48,字符:'0')
               /// </summary>
               Success = 48,

               /// <summary>
               /// 账户余额不足(数值:49,字符:'1')
               /// </summary>
               InsuffiCient = 49,

               /// <summary>
               /// 交易结果未知(数值:56,字符:'8')
               /// </summary>
               UnKnown = 56
           };

           /// <summary>
           /// 修改状态类型
           /// </summary>
           public enum class CtpNetExStatusType
           {
               /// <summary>
               /// 修改前(数值:48,字符:'0')
               /// </summary>
               Before = 48,

               /// <summary>
               /// 修改后(数值:49,字符:'1')
               /// </summary>
               After = 49
           };

           /// <summary>
           /// 开户客户地域类型
           /// </summary>
           public enum class CtpNetClientRegionType
           {
               /// <summary>
               /// 国内客户(数值:49,字符:'1')
               /// </summary>
               Domestic = 49,

               /// <summary>
               /// 港澳台客户(数值:50,字符:'2')
               /// </summary>
               GMT = 50,

               /// <summary>
               /// 国外客户(数值:51,字符:'3')
               /// </summary>
               Foreign = 51
           };

           /// <summary>
           /// 是否有董事会类型
           /// </summary>
           public enum class CtpNetHasBoardType
           {
               /// <summary>
               /// 没有(数值:48,字符:'0')
               /// </summary>
               No = 48,

               /// <summary>
               /// 有(数值:49,字符:'1')
               /// </summary>
               Yes = 49
           };

           /// <summary>
           /// 启动模式类型
           /// </summary>
           public enum class CtpNetStartModeType
           {
               /// <summary>
               /// 正常(数值:49,字符:'1')
               /// </summary>
               Normal = 49,

               /// <summary>
               /// 应急(数值:50,字符:'2')
               /// </summary>
               Emerge = 50,

               /// <summary>
               /// 恢复(数值:51,字符:'3')
               /// </summary>
               Restore = 51
           };

           /// <summary>
           /// 模型类型
           /// </summary>
           public enum class CtpNetTemplateTypeType
           {
               /// <summary>
               /// 全量(数值:49,字符:'1')
               /// </summary>
               Full = 49,

               /// <summary>
               /// 增量(数值:50,字符:'2')
               /// </summary>
               Increment = 50,

               /// <summary>
               /// 备份(数值:51,字符:'3')
               /// </summary>
               BackUp = 51
           };

           /// <summary>
           /// 登录模式类型
           /// </summary>
           public enum class CtpNetLoginModeType
           {
               /// <summary>
               /// 交易(数值:48,字符:'0')
               /// </summary>
               Trade = 48,

               /// <summary>
               /// 转账(数值:49,字符:'1')
               /// </summary>
               Transfer = 49
           };

           /// <summary>
           /// 日历提示类型
           /// </summary>
           public enum class CtpNetPromptTypeType
           {
               /// <summary>
               /// 合约上下市(数值:49,字符:'1')
               /// </summary>
               Instrument = 49,

               /// <summary>
               /// 保证金分段生效(数值:50,字符:'2')
               /// </summary>
               Margin = 50
           };

           /// <summary>
           /// 是否有托管人类型
           /// </summary>
           public enum class CtpNetHasTrusteeType
           {
               /// <summary>
               /// 有(数值:49,字符:'1')
               /// </summary>
               Yes = 49,

               /// <summary>
               /// 没有(数值:48,字符:'0')
               /// </summary>
               No = 48
           };

           /// <summary>
           /// 机构类型
           /// </summary>
           public enum class CtpNetAmTypeType
           {
               /// <summary>
               /// 银行(数值:49,字符:'1')
               /// </summary>
               Bank = 49,

               /// <summary>
               /// 证券公司(数值:50,字符:'2')
               /// </summary>
               Securities = 50,

               /// <summary>
               /// 基金公司(数值:51,字符:'3')
               /// </summary>
               Fund = 51,

               /// <summary>
               /// 保险公司(数值:52,字符:'4')
               /// </summary>
               Insurance = 52,

               /// <summary>
               /// 信托公司(数值:53,字符:'5')
               /// </summary>
               Trust = 53,

               /// <summary>
               /// 其他(数值:57,字符:'9')
               /// </summary>
               Other = 57
           };

           /// <summary>
           /// 出入金类型
           /// </summary>
           public enum class CtpNetCSRCFundIOTypeType
           {
               /// <summary>
               /// 出入金(数值:48,字符:'0')
               /// </summary>
               FundIO = 48,

               /// <summary>
               /// 银期换汇(数值:49,字符:'1')
               /// </summary>
               SwapCurrency = 49
           };

           /// <summary>
           /// 结算账户类型
           /// </summary>
           public enum class CtpNetCusAccountTypeType
           {
               /// <summary>
               /// 期货结算账户(数值:49,字符:'1')
               /// </summary>
               Futures = 49,

               /// <summary>
               /// 纯期货资管业务下的资管结算账户(数值:50,字符:'2')
               /// </summary>
               AssetmgrFuture = 50,

               /// <summary>
               /// 综合类资管业务下的期货资管托管账户(数值:51,字符:'3')
               /// </summary>
               AssetmgrTrustee = 51,

               /// <summary>
               /// 综合类资管业务下的资金中转账户(数值:52,字符:'4')
               /// </summary>
               AssetmgrTransfer = 52
           };

           /// <summary>
           /// 通知语言类型
           /// </summary>
           public enum class CtpNetLanguageTypeType
           {
               /// <summary>
               /// 中文(数值:49,字符:'1')
               /// </summary>
               Chinese = 49,

               /// <summary>
               /// 英文(数值:50,字符:'2')
               /// </summary>
               English = 50
           };

           /// <summary>
           /// 资产管理客户类型
           /// </summary>
           public enum class CtpNetAssetmgrClientTypeType
           {
               /// <summary>
               /// 个人资管客户(数值:49,字符:'1')
               /// </summary>
               Person = 49,

               /// <summary>
               /// 单位资管客户(数值:50,字符:'2')
               /// </summary>
               Organ = 50,

               /// <summary>
               /// 特殊单位资管客户(数值:52,字符:'4')
               /// </summary>
               SpecialOrgan = 52
           };

           /// <summary>
           /// 投资类型
           /// </summary>
           public enum class CtpNetAssetmgrTypeType
           {
               /// <summary>
               /// 期货类(数值:51,字符:'3')
               /// </summary>
               Futures = 51,

               /// <summary>
               /// 综合类(数值:52,字符:'4')
               /// </summary>
               SpecialOrgan = 52
           };

           /// <summary>
           /// 合约比较类型
           /// </summary>
           public enum class CtpNetCheckInstrTypeType
           {
               /// <summary>
               /// 合约交易所不存在(数值:48,字符:'0')
               /// </summary>
               HasExch = 48,

               /// <summary>
               /// 合约本系统不存在(数值:49,字符:'1')
               /// </summary>
               HasATP = 49,

               /// <summary>
               /// 合约比较不一致(数值:50,字符:'2')
               /// </summary>
               HasDiff = 50
           };

           /// <summary>
           /// 交割类型
           /// </summary>
           public enum class CtpNetDeliveryTypeType
           {
               /// <summary>
               /// 手工交割(数值:49,字符:'1')
               /// </summary>
               HandDeliv = 49,

               /// <summary>
               /// 到期交割(数值:50,字符:'2')
               /// </summary>
               PersonDeliv = 50
           };

           /// <summary>
           /// 大额单边保证金算法类型
           /// </summary>
           public enum class CtpNetMaxMarginSideAlgorithmType
           {
               /// <summary>
               /// 不使用大额单边保证金算法(数值:48,字符:'0')
               /// </summary>
               NO = 48,

               /// <summary>
               /// 使用大额单边保证金算法(数值:49,字符:'1')
               /// </summary>
               YES = 49
           };

           /// <summary>
           /// 资产管理客户类型
           /// </summary>
           public enum class CtpNetDAClientTypeType
           {
               /// <summary>
               /// 自然人(数值:48,字符:'0')
               /// </summary>
               Person = 48,

               /// <summary>
               /// 法人(数值:49,字符:'1')
               /// </summary>
               Company = 49,

               /// <summary>
               /// 其他(数值:50,字符:'2')
               /// </summary>
               Other = 50
           };

           /// <summary>
           /// 投资类型
           /// </summary>
           public enum class CtpNetUOAAssetmgrTypeType
           {
               /// <summary>
               /// 期货类(数值:49,字符:'1')
               /// </summary>
               Futures = 49,

               /// <summary>
               /// 综合类(数值:50,字符:'2')
               /// </summary>
               SpecialOrgan = 50
           };

           /// <summary>
           /// 买卖方向类型
           /// </summary>
           public enum class CtpNetDirectionEnType
           {
               /// <summary>
               /// Buy(数值:48,字符:'0')
               /// </summary>
               Buy = 48,

               /// <summary>
               /// Sell(数值:49,字符:'1')
               /// </summary>
               Sell = 49
           };

           /// <summary>
           /// 开平标志类型
           /// </summary>
           public enum class CtpNetOffsetFlagEnType
           {
               /// <summary>
               /// Position Opening(数值:48,字符:'0')
               /// </summary>
               Open = 48,

               /// <summary>
               /// Position Close(数值:49,字符:'1')
               /// </summary>
               Close = 49,

               /// <summary>
               /// Forced Liquidation(数值:50,字符:'2')
               /// </summary>
               ForceClose = 50,

               /// <summary>
               /// Close Today(数值:51,字符:'3')
               /// </summary>
               CloseToday = 51,

               /// <summary>
               /// Close Prev.(数值:52,字符:'4')
               /// </summary>
               CloseYesterday = 52,

               /// <summary>
               /// Forced Reduction(数值:53,字符:'5')
               /// </summary>
               ForceOff = 53,

               /// <summary>
               /// Local Forced Liquidation(数值:54,字符:'6')
               /// </summary>
               LocalForceClose = 54
           };

           /// <summary>
           /// 投机套保标志类型
           /// </summary>
           public enum class CtpNetHedgeFlagEnType
           {
               /// <summary>
               /// Speculation(数值:49,字符:'1')
               /// </summary>
               Speculation = 49,

               /// <summary>
               /// Arbitrage(数值:50,字符:'2')
               /// </summary>
               Arbitrage = 50,

               /// <summary>
               /// Hedge(数值:51,字符:'3')
               /// </summary>
               Hedge = 51
           };

           /// <summary>
           /// 出入金类型
           /// </summary>
           public enum class CtpNetFundIOTypeEnType
           {
               /// <summary>
               /// Deposit/Withdrawal(数值:49,字符:'1')
               /// </summary>
               FundIO = 49,

               /// <summary>
               /// Bank-Futures Transfer(数值:50,字符:'2')
               /// </summary>
               Transfer = 50,

               /// <summary>
               /// Bank-Futures FX Exchange(数值:51,字符:'3')
               /// </summary>
               SwapCurrency = 51
           };

           /// <summary>
           /// 资金类型
           /// </summary>
           public enum class CtpNetFundTypeEnType
           {
               /// <summary>
               /// Bank Deposit(数值:49,字符:'1')
               /// </summary>
               Deposite = 49,

               /// <summary>
               /// Payment/Fee(数值:50,字符:'2')
               /// </summary>
               ItemFund = 50,

               /// <summary>
               /// Brokerage Adj(数值:51,字符:'3')
               /// </summary>
               Company = 51,

               /// <summary>
               /// Internal Transfer(数值:52,字符:'4')
               /// </summary>
               InnerTransfer = 52
           };

           /// <summary>
           /// 出入金方向类型
           /// </summary>
           public enum class CtpNetFundDirectionEnType
           {
               /// <summary>
               /// Deposit(数值:49,字符:'1')
               /// </summary>
               In = 49,

               /// <summary>
               /// Withdrawal(数值:50,字符:'2')
               /// </summary>
               Out = 50
           };

           /// <summary>
           /// 货币质押方向类型
           /// </summary>
           public enum class CtpNetFundMortDirectionEnType
           {
               /// <summary>
               /// Pledge(数值:49,字符:'1')
               /// </summary>
               In = 49,

               /// <summary>
               /// Redemption(数值:50,字符:'2')
               /// </summary>
               Out = 50
           };

           /// <summary>
           /// 期权类型
           /// </summary>
           public enum class CtpNetOptionsTypeType
           {
               /// <summary>
               /// 看涨(数值:49,字符:'1')
               /// </summary>
               CallOptions = 49,

               /// <summary>
               /// 看跌(数值:50,字符:'2')
               /// </summary>
               PutOptions = 50
           };

           /// <summary>
           /// 执行方式类型
           /// </summary>
           public enum class CtpNetStrikeModeType
           {
               /// <summary>
               /// 欧式(数值:48,字符:'0')
               /// </summary>
               Continental = 48,

               /// <summary>
               /// 美式(数值:49,字符:'1')
               /// </summary>
               American = 49,

               /// <summary>
               /// 百慕大(数值:50,字符:'2')
               /// </summary>
               Bermuda = 50
           };

           /// <summary>
           /// 执行类型
           /// </summary>
           public enum class CtpNetStrikeTypeType
           {
               /// <summary>
               /// 自身对冲(数值:48,字符:'0')
               /// </summary>
               Hedge = 48,

               /// <summary>
               /// 匹配执行(数值:49,字符:'1')
               /// </summary>
               Match = 49
           };

           /// <summary>
           /// 中金所期权放弃执行申请类型
           /// </summary>
           public enum class CtpNetApplyTypeType
           {
               /// <summary>
               /// 不执行数量(数值:52,字符:'4')
               /// </summary>
               NotStrikeNum = 52
           };

           /// <summary>
           /// 放弃执行申请数据来源类型
           /// </summary>
           public enum class CtpNetGiveUpDataSourceType
           {
               /// <summary>
               /// 系统生成(数值:48,字符:'0')
               /// </summary>
               Gen = 48,

               /// <summary>
               /// 手工添加(数值:49,字符:'1')
               /// </summary>
               Hand = 49
           };

           /// <summary>
           /// 执行结果类型
           /// </summary>
           public enum class CtpNetExecResultType
           {
               /// <summary>
               /// 没有执行(数值:110,字符:'n')
               /// </summary>
               NoExec = 110,

               /// <summary>
               /// 已经取消(数值:99,字符:'c')
               /// </summary>
               Canceled = 99,

               /// <summary>
               /// 执行成功(数值:48,字符:'0')
               /// </summary>
               OK = 48,

               /// <summary>
               /// 期权持仓不够(数值:49,字符:'1')
               /// </summary>
               NoPosition = 49,

               /// <summary>
               /// 资金不够(数值:50,字符:'2')
               /// </summary>
               NoDeposit = 50,

               /// <summary>
               /// 会员不存在(数值:51,字符:'3')
               /// </summary>
               NoParticipant = 51,

               /// <summary>
               /// 客户不存在(数值:52,字符:'4')
               /// </summary>
               NoClient = 52,

               /// <summary>
               /// 合约不存在(数值:54,字符:'6')
               /// </summary>
               NoInstrument = 54,

               /// <summary>
               /// 没有执行权限(数值:55,字符:'7')
               /// </summary>
               NoRight = 55,

               /// <summary>
               /// 不合理的数量(数值:56,字符:'8')
               /// </summary>
               InvalidVolume = 56,

               /// <summary>
               /// 没有足够的历史成交(数值:57,字符:'9')
               /// </summary>
               NoEnoughHistoryTrade = 57,

               /// <summary>
               /// 未知(数值:97,字符:'a')
               /// </summary>
               Unknown = 97
           };

           /// <summary>
           /// 组合类型
           /// </summary>
           public enum class CtpNetCombinationTypeType
           {
               /// <summary>
               /// 期货组合(数值:48,字符:'0')
               /// </summary>
               Future = 48,

               /// <summary>
               /// 垂直价差BUL(数值:49,字符:'1')
               /// </summary>
               BUL = 49,

               /// <summary>
               /// 垂直价差BER(数值:50,字符:'2')
               /// </summary>
               BER = 50,

               /// <summary>
               /// 跨式组合(数值:51,字符:'3')
               /// </summary>
               STD = 51,

               /// <summary>
               /// 宽跨式组合(数值:52,字符:'4')
               /// </summary>
               STG = 52,

               /// <summary>
               /// 备兑组合(数值:53,字符:'5')
               /// </summary>
               PRT = 53,

               /// <summary>
               /// 时间价差组合(数值:54,字符:'6')
               /// </summary>
               CLD = 54
           };

           /// <summary>
           /// 期权权利金价格类型
           /// </summary>
           public enum class CtpNetOptionRoyaltyPriceTypeType
           {
               /// <summary>
               /// 昨结算价(数值:49,字符:'1')
               /// </summary>
               PreSettlementPrice = 49,

               /// <summary>
               /// 开仓价(数值:52,字符:'4')
               /// </summary>
               OpenPrice = 52,

               /// <summary>
               /// 最新价与昨结算价较大值(数值:53,字符:'5')
               /// </summary>
               MaxPreSettlementPrice = 53
           };

           /// <summary>
           /// 权益算法类型
           /// </summary>
           public enum class CtpNetBalanceAlgorithmType
           {
               /// <summary>
               /// 不计算期权市值盈亏(数值:49,字符:'1')
               /// </summary>
               Default = 49,

               /// <summary>
               /// 计算期权市值亏损(数值:50,字符:'2')
               /// </summary>
               IncludeOptValLost = 50
           };

           /// <summary>
           /// 执行类型
           /// </summary>
           public enum class CtpNetActionTypeType
           {
               /// <summary>
               /// 执行(数值:49,字符:'1')
               /// </summary>
               Exec = 49,

               /// <summary>
               /// 放弃(数值:50,字符:'2')
               /// </summary>
               Abandon = 50
           };

           /// <summary>
           /// 询价状态类型
           /// </summary>
           public enum class CtpNetForQuoteStatusType
           {
               /// <summary>
               /// 已经提交(数值:97,字符:'a')
               /// </summary>
               Submitted = 97,

               /// <summary>
               /// 已经接受(数值:98,字符:'b')
               /// </summary>
               Accepted = 98,

               /// <summary>
               /// 已经被拒绝(数值:99,字符:'c')
               /// </summary>
               Rejected = 99
           };

           /// <summary>
           /// 取值方式类型
           /// </summary>
           public enum class CtpNetValueMethodType
           {
               /// <summary>
               /// 按绝对值(数值:48,字符:'0')
               /// </summary>
               Absolute = 48,

               /// <summary>
               /// 按比率(数值:49,字符:'1')
               /// </summary>
               Ratio = 49
           };

           /// <summary>
           /// 期权行权后是否保留期货头寸的标记类型
           /// </summary>
           public enum class CtpNetExecOrderPositionFlagType
           {
               /// <summary>
               /// 保留(数值:48,字符:'0')
               /// </summary>
               Reserve = 48,

               /// <summary>
               /// 不保留(数值:49,字符:'1')
               /// </summary>
               UnReserve = 49
           };

           /// <summary>
           /// 期权行权后生成的头寸是否自动平仓类型
           /// </summary>
           public enum class CtpNetExecOrderCloseFlagType
           {
               /// <summary>
               /// 自动平仓(数值:48,字符:'0')
               /// </summary>
               AutoClose = 48,

               /// <summary>
               /// 免于自动平仓(数值:49,字符:'1')
               /// </summary>
               NotToClose = 49
           };

           /// <summary>
           /// 产品类型
           /// </summary>
           public enum class CtpNetProductTypeType
           {
               /// <summary>
               /// 期货(数值:49,字符:'1')
               /// </summary>
               Futures = 49,

               /// <summary>
               /// 期权(数值:50,字符:'2')
               /// </summary>
               Options = 50
           };

           /// <summary>
           /// 郑商所结算文件名类型
           /// </summary>
           public enum class CtpNetCZCEUploadFileNameType
           {
               /// <summary>
               /// (数值:79,字符:'O')
               /// </summary>
               O = 79,

               /// <summary>
               /// 成交表(数值:84,字符:'T')
               /// </summary>
               T = 84,

               /// <summary>
               /// 单腿持仓表new(数值:80,字符:'P')
               /// </summary>
               P = 80,

               /// <summary>
               /// 非平仓了结表(数值:78,字符:'N')
               /// </summary>
               N = 78,

               /// <summary>
               /// 平仓表(数值:76,字符:'L')
               /// </summary>
               L = 76,

               /// <summary>
               /// 资金表(数值:70,字符:'F')
               /// </summary>
               F = 70,

               /// <summary>
               /// 组合持仓表(数值:67,字符:'C')
               /// </summary>
               C = 67,

               /// <summary>
               /// 保证金参数表(数值:77,字符:'M')
               /// </summary>
               M = 77
           };

           /// <summary>
           /// 大商所结算文件名类型
           /// </summary>
           public enum class CtpNetDCEUploadFileNameType
           {
               /// <summary>
               /// dl_(数值:79,字符:'O')
               /// </summary>
               O = 79,

               /// <summary>
               /// 成交表(数值:84,字符:'T')
               /// </summary>
               T = 84,

               /// <summary>
               /// 持仓表(数值:80,字符:'P')
               /// </summary>
               P = 80,

               /// <summary>
               /// 资金结算表(数值:70,字符:'F')
               /// </summary>
               F = 70,

               /// <summary>
               /// 优惠组合持仓明细表(数值:67,字符:'C')
               /// </summary>
               C = 67,

               /// <summary>
               /// 持仓明细表(数值:68,字符:'D')
               /// </summary>
               D = 68,

               /// <summary>
               /// 保证金参数表(数值:77,字符:'M')
               /// </summary>
               M = 77,

               /// <summary>
               /// 期权执行表(数值:83,字符:'S')
               /// </summary>
               S = 83
           };

           /// <summary>
           /// 上期所结算文件名类型
           /// </summary>
           public enum class CtpNetSHFEUploadFileNameType
           {
               /// <summary>
               /// DailyFundChg(数值:79,字符:'O')
               /// </summary>
               O = 79,

               /// <summary>
               /// Trade(数值:84,字符:'T')
               /// </summary>
               T = 84,

               /// <summary>
               /// SettlementDetail(数值:80,字符:'P')
               /// </summary>
               P = 80,

               /// <summary>
               /// Capital(数值:70,字符:'F')
               /// </summary>
               F = 70
           };

           /// <summary>
           /// 中金所结算文件名类型
           /// </summary>
           public enum class CtpNetCFFEXUploadFileNameType
           {
               /// <summary>
               /// SGTrade(数值:84,字符:'T')
               /// </summary>
               T = 84,

               /// <summary>
               /// SGSettlementDetail(数值:80,字符:'P')
               /// </summary>
               P = 80,

               /// <summary>
               /// SGCapital(数值:70,字符:'F')
               /// </summary>
               F = 70,

               /// <summary>
               /// SGOptionExec(数值:83,字符:'S')
               /// </summary>
               S = 83
           };

           /// <summary>
           /// 组合指令方向类型
           /// </summary>
           public enum class CtpNetCombDirectionType
           {
               /// <summary>
               /// 申请组合(数值:48,字符:'0')
               /// </summary>
               Comb = 48,

               /// <summary>
               /// 申请拆分(数值:49,字符:'1')
               /// </summary>
               UnComb = 49
           };

           /// <summary>
           /// 行权偏移类型
           /// </summary>
           public enum class CtpNetStrikeOffsetTypeType
           {
               /// <summary>
               /// 实值额(数值:49,字符:'1')
               /// </summary>
               RealValue = 49,

               /// <summary>
               /// 盈利额(数值:50,字符:'2')
               /// </summary>
               ProfitValue = 50,

               /// <summary>
               /// 实值比例(数值:51,字符:'3')
               /// </summary>
               RealRatio = 51,

               /// <summary>
               /// 盈利比例(数值:52,字符:'4')
               /// </summary>
               ProfitRatio = 52
           };

           /// <summary>
           /// 预约开户状态类型
           /// </summary>
           public enum class CtpNetReserveOpenAccStasType
           {
               /// <summary>
               /// 等待处理中(数值:48,字符:'0')
               /// </summary>
               Processing = 48,

               /// <summary>
               /// 已撤销(数值:49,字符:'1')
               /// </summary>
               Cancelled = 49,

               /// <summary>
               /// 已开户(数值:50,字符:'2')
               /// </summary>
               Opened = 50,

               /// <summary>
               /// 无效请求(数值:51,字符:'3')
               /// </summary>
               Invalid = 51
           };

           /// <summary>
           /// 弱密码来源类型
           /// </summary>
           public enum class CtpNetWeakPasswordSourceType
           {
               /// <summary>
               /// 弱密码库(数值:49,字符:'1')
               /// </summary>
               Lib = 49,

               /// <summary>
               /// 手工录入(数值:50,字符:'2')
               /// </summary>
               Manual = 50
           };

           /// <summary>
           /// 期权行权的头寸是否自对冲类型
           /// </summary>
           public enum class CtpNetOptSelfCloseFlagType
           {
               /// <summary>
               /// 自对冲期权仓位(数值:49,字符:'1')
               /// </summary>
               CloseSelfOptionPosition = 49,

               /// <summary>
               /// 保留期权仓位(数值:50,字符:'2')
               /// </summary>
               ReserveOptionPosition = 50,

               /// <summary>
               /// 自对冲卖方履约后的期货仓位(数值:51,字符:'3')
               /// </summary>
               SellCloseSelfFuturePosition = 51
           };

           /// <summary>
           /// 业务类型
           /// </summary>
           public enum class CtpNetBizTypeType
           {
               /// <summary>
               /// 期货(数值:49,字符:'1')
               /// </summary>
               Future = 49,

               /// <summary>
               /// 证券(数值:50,字符:'2')
               /// </summary>
               Stock = 50
           };
       };
   };
};
