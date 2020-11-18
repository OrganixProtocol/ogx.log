# ogx.log 介绍

core contract of ogx.log protocol

# organix编译部署

## 依赖环境

1. eosio.cdt --- tag: v1.7.0 或以上
2. eosio.contract --- tag:  v1.9.1 或以上

## 编译

#### 1. 将organix目录放入eosio.contracts内,跟eosio.token同级即可。
#### 2. 编辑文件 eosio.contracts/CMakeLists.txt:

```
add_subdirectory(ogx.log)
```
#### 3. 运行eosio.contracts/build.sh完成编译
 ```
 ./build.sh
 ```
 
## 方案
```
合约帐号: log.ogx
```

## 部署
```
cleos -u 'https://eospush.tokenpocket.pro' system newaccount ogx log.ogx EOS5ivbcmkXpjTcmHDjS9Ywh8spFQSnZzsniJ1rLtqUHW2DkNbRMu EOS5ivbcmkXpjTcmHDjS9Ywh8spFQSnZzsniJ1rLtqUHW2DkNbRMu --buy-ram '10.0000 EOS' --stake-net '0.0100 EOS' --stake-cpu '0.0100 EOS'
cleos -u 'https://eospush.tokenpocket.pro' set account permission log.ogx active '{"threshold": 1,"keys": [{"key": "EOS5ivbcmkXpjTcmHDjS9Ywh8spFQSnZzsniJ1rLtqUHW2DkNbRMu", "weight": 1}],"accounts": [{"permission":{"actor":"core.ogx","permission":"eosio.code"},"weight":1}]}' owner -p log.ogx@owner

cd build

cleos -u 'https://eospush.tokenpocket.pro' set contract log.ogx ./ogx.log -p log.ogx -x 180

```