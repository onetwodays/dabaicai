#pragma once

#define USING_ACTION(contract_name, action_name) using action_name##_action = action_wrapper<#action_name##_n, &contract_name::action_name>
#define ZERO_ASSET(symbol) (asset(0, symbol))

#define TOKEN_CONTRACT_NAME "eosio.token"
#define TOKEN_CONTRACT_TRANSFER_ACTION "transfer"
#define TOKEN_TEMP_ACCOUNT "otcexchange"

#define BALANCE_TYPE_AVAILABLE 1
#define BALANCE_TYPE_FREEZE 2

#define DEAL_STATUS_UNPAID 10                //未付款
#define DEAL_STATUS_UNPAID_MAN_CANCEL 11     //未付款手动取消
#define DEAL_STATUS_UNPAID_TIMEOUT_CANCEL 12 //未付款超时取消

#define DEAL_STATUS_PAID_WAIT_PLAYCOIN 20 //已付款等待放币
#define DEAL_STATUS_PAID_APPEAL_ASK 21    //已付款待放币(买卖方都可以申述)广告方申诉
#define DEAL_STATUS_PAID_APPEAL_BID 22    //已付款待放币(买卖方都可以申述)吃单方申诉
#define DEAL_STATUS_PAID_APPEAL_ALL 23    //已付款待放币(买卖方都可以申述)双方申诉

#define DEAL_STATUS_PAID_ARBIARATE_ING 24      //已付款待放币仲裁中
#define DEAL_STATUS_PAID_ARBIARATE_CANCEL 25   //已付款待放币仲裁取消结果，合约修改的
#define DEAL_STATUS_PAID_ARBIARATE_PALYCOIN 26 //已付款待放币仲裁放币结果，合约修改

#define DEAL_STATUS_PAID_PLAYCOIN_ING 27 //自己放币中

#define DEAL_STATUS_PAID_JUDGE_CANCEL 28   //终审结果为取消放币
#define DEAL_STATUS_PAID_JUDGE_PLAYCOIN 29 //终审结果为放币

#define DEAL_STATUS_PAID_PLAYCOIN_FINISH 30 //放币完成
#define DEAL_STATUS_CANCEL_FINISH 31        //放币取消完成

#define MARKET_STATUS_ON 1  //允许交易
#define MARKET_STATUS_OFF 2 //不允许交易

#define MARKET_STATUS_ON_STR "allow trade"      //允许交易
#define MARKET_STATUS_OFF_STR "not allow trade" //不允许交易

#define AD_STATUS_ONTHESHELF 1      //上架中
#define AD_STATUS_MAN_OFFTHESHELF 2 //手动下架
#define AD_STATUS_AUT_OFFTHESHELF 3 //自动下架
#define AD_STATUS_CANCELED 4        //已撤销
#define AD_STATUS_FINISHED 5        //已完成

#define MARKET_ORDER_TYPE_LIMIT 1
#define MARKET_ORDER_TYPE_MARKET 2

#define MARKET_ORDER_SIDE_INVAID 0
#define MARKET_ORDER_SIDE_ASK 1
#define MARKET_ORDER_SIDE_BID 2

#define MARKET_ROLE_INVAID 0
#define MARKET_ROLE_MAKER 1
#define MARKET_ROLE_TAKER 2

#define MARKET_ORDER_SIDE_ASK_STR "ask"
#define MARKET_ORDER_SIDE_BID_STR "bid"

#define MARKET_ROLE_MAKER_STR "mk" //maker的简称 12字符的限制啊
#define MARKET_ROLE_TAKER_STR "tk" //taker的简称

#define ROLE_INVALID_STR " role must be 1(广告挂单mk) or  2(OTC下单tk）"
#define SIDE_INVALID_STR " side must be 1(ask)     or 2(bid）"
#define PAIR_EXIST_STR " pair is exist"
#define PAIR_NOT_EXIST_STR " is not exist"
#define DEAL_NOT_EXIST_STR " deal  not exist"
#define ORDER_NOT_EXIST_STR " order  not exist"
#define DEAL_STATUS_SAME " deal status same"
#define MAKER_ORDER_NOR_EXIST_STR " maker order not exist"

#define TOKEN_SYMBOL_CODE "SYS" //代币的符号

#define EOS_SYMBOL symbol(symbol_code("EOS") 4)

#define SG_MARKETS_SCOPE_STR "markets"

#define ERR_CANCEL_ORDER_NOT_BELONG_TO " not can cancel other user order"
#define ERR_RM_ORDER_NOT_BELONG_TO " not can cancel other user order"
#define ERR_ORDER_CANCELED " order has be canceled"
#define ERR_ORDER_SIDE_SAME " order side is same"
#define ERR_FORBID_SELF_EXCHANGE " forbid self exchange"
#define ERR_NOT_ENOUGH_TOKEN_TO_SELL " counterparty not enough token to sell"
#define ERR_CHECK_PRICE_GREAT_ZERO " price  must > 0"
#define ERR_CHECK_AMOUNT_GREAT_ZERO " amount must > 0"
#define ERR_CHECK_FORBIN_CANCEL_SELL_ORDER " forbid cancel ask order"

//交易对的错误信息
#define ERR_MSG_PAIR_NOT_EXIST " exchange pair not  exist"
#define ERR_MSG_PAIR_NOT_ALLOW_TRADE " exchange pair not  allow trade"
#define ERR_MSG_PAIR_HAS_EXISTED " exchange pair has  exist"

//广告订单的错误消息
#define ERR_MSG_AD_NOT_EXIST " adorder not exist"

//校验入参 错误消息拼接成字符串

#define ERR_MSG_CHECK_FAILED(ecode, msg) (std::string(R"1({"ecode":)1").append(std::to_string(ecode)).append(R"1(","msg":")1").append(msg).append(R"1("})1"))
#define ERR_MSG_SIDE ERR_MSG_CHECK_FAILED(50800, SIDE_INVALID_STR)

#define ERR_MSG_PARAM_LT_ZERO(ecode, param, tip) (std::string(R"1({"ecode":)1").append(std::to_string(ecode)).append(R"1(","msg":")1").append(#param).append(" value <  0 |").append(tip).append(R"1("})1"))         //param的value must be >=0
#define ERR_MSG_PARAM_LE_ZERO(ecode, param, tip) (std::string(R"1({"ecode":)1").append(std::to_string(ecode)).append(R"1(","msg":")1").append(#param).append(" value <=  0 |").append(tip).append(R"1("})1"))        //param的value must be >0
#define ERR_MSG_PARAM_LT(ecode, p1, p2, tip) (std::string(R"1({"ecode":)1").append(std::to_string(ecode)).append(R"1(","msg":")1").append(#p1).append(" < ").append(#p2).append("|").append(tip).append(R"1("})1"))  //param的value must be >0
#define ERR_MSG_PARAM_LE(ecode, p1, p2, tip) (std::string(R"1({"ecode":)1").append(std::to_string(ecode)).append(R"1(","msg":")1").append(#p1).append(" <= ").append(#p2).append("|").append(tip).append(R"1("})1")) //param的value must be >0

//pair error
#define ERR_MSG_PARAM_PAIR_TAKER_FEE_RATE_MUST_GE_ZERO "taker fee rate must ge zero"
#define ERR_MSG_PARAM_PAIR_MAKER_FEE_RATE_MUST_GE_ZERO "maker fee rate must ge zero"

#define ERR_MSG_PARAM_PAIR_AMOUNT_MIN_MUST_GT_ZERO "ad order allow min_amount must gt zero"
#define ERR_MSG_PARAM_PAIR_AMOUNT_MAX_MUST_GT_ZERO "ad order allow mxn_amount must gt zero"
#define ERR_MSG_PARAM_PAIR_AMOUNT_MAX_MUST_GE_MIN "ad order allow amount max must ge min"

#define ERR_MSG_PARAM_PAIR_PRICE_MIN_MUST_GT_ZERO "ad order allow min_price must gt zero"
#define ERR_MSG_PARAM_PAIR_PRICE_MAX_MUST_GT_ZERO "ad order allow max_price must gt zero"
#define ERR_MSG_PARAM_PAIR_PRICE_MAX_MUST_GE_MIN "ad order allow price max must ge min"

#define ERR_MSG_PARAM_PAIR_PAY_TIMEOUT_MUST_GT_ZERO "allow pay timeout(s) must gt zero"
#define ERR_MSG_PARAM_PAIR_AD_CANCEL_NUM_MUST_GT_ZERO "allow ad cancel num must gt zero"

//put ad error

#define ERR_MSG_PARAM_AD_AMOUNT_MUST_GT_ZERO "ad order amount  must ge zero"
#define ERR_MSG_PARAM_AD_AMOUNT_RANGE "ad order amount  in exchange pair amount range"

#define ERR_MSG_PARAM_AD_AMOUNT_MIN_MUST_GT_ZERO "ad order allow  deal min_amount must gt zero"
#define ERR_MSG_PARAM_AD_AMOUNT_MAX_MUST_GT_ZERO "ad order allow  deal mxn_amount must gt zero"
#define ERR_MSG_PARAM_AD_AMOUNT_MAX_MUST_GE_MIN "ad order allow  amount deal max must ge min"
#define ERR_MSG_PARAM_AD_AMOUNT_MUST_GE_AMOUNT_MAX "ad order allow  amount must ge deal max amount"
#define ERR_MSG_PARAM_AD_PRICE_MUST_GT_ZERO "ad order price   must ge zero"
#define ERR_MSG_PARAM_AD_PRICE_RANGE "ad order price  in exchange pair price range"

#define ERR_MSG_
#define ERR_MSG_
#define ERR_MSG_
#define ERR_MSG_
#define ERR_MSG_
#define ERR_MSG_
#define ERR_MSG_

//错误码分配 500100-500199 分配给market