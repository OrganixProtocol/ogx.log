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
合约帐号: organixlogll
```

## 部署
```
cleos -u 'https://eospush.tokenpocket.pro' system newaccount itokenpocket organixlogll EOS5ivbcmkXpjTcmHDjS9Ywh8spFQSnZzsniJ1rLtqUHW2DkNbRMu EOS5ivbcmkXpjTcmHDjS9Ywh8spFQSnZzsniJ1rLtqUHW2DkNbRMu --buy-ram '50.0000 EOS' --stake-net '5.0000 EOS' --stake-cpu '10.0000 EOS'
cleos -u 'https://eospush.tokenpocket.pro' set account permission organixlogll active '{"threshold": 1,"keys": [{"key": "EOS5ivbcmkXpjTcmHDjS9Ywh8spFQSnZzsniJ1rLtqUHW2DkNbRMu", "weight": 1}],"accounts": [{"permission":{"actor":"organixtokeo","permission":"eosio.code"},"weight":1}]}' owner -p organixlogll@owner

cd build

cleos -u 'https://eospush.tokenpocket.pro' set contract organixlogll ./ogx.log -p organixlogll -x 180

```