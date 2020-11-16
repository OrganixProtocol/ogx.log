# organix 介绍

organix contract

# organix编译部署

## 依赖环境

1. eosio.cdt --- tag: v1.7.0 或以上
2. eosio.contract --- tag:  v1.9.1 或以上

## 编译

#### 1. 将organix目录放入eosio.contracts内,跟eosio.token同级即可。
#### 2. 编辑文件 eosio.contracts/CMakeLists.txt:

```
add_subdirectory(organix)
```
#### 3. 运行eosio.contracts/build.sh完成编译
 ```
 ./build.sh
 ```
 
## 方案
```
合约帐号: ogxprestoken
代币OGX合约帐号: organixtoken
代币EOS合约帐号: eosio.token
代币TPT合约帐号: eosiotptoken

```

## 部署
```
cd build
cleos -u 'https://eospush.tokenpocket.pro' system newaccount itokenpocket ogxfundation EOS77f1D5xApr9RaE7vS6ZDqWb9HteXhakoHgU6GZV6RzFu4tzTSR EOS77f1D5xApr9RaE7vS6ZDqWb9HteXhakoHgU6GZV6RzFu4tzTSR --buy-ram '1.0000 EOS' --stake-net '1.0000 EOS' --stake-cpu '0.0001 EOS'
cleos -u 'https://eospush.tokenpocket.pro' system newaccount itokenpocket ogxmarketing EOS77f1D5xApr9RaE7vS6ZDqWb9HteXhakoHgU6GZV6RzFu4tzTSR EOS77f1D5xApr9RaE7vS6ZDqWb9HteXhakoHgU6GZV6RzFu4tzTSR --buy-ram '1.0000 EOS' --stake-net '1.0000 EOS' --stake-cpu '0.0001 EOS'
cleos -u 'https://eospush.tokenpocket.pro' system newaccount itokenpocket ogxeosioteam EOS77f1D5xApr9RaE7vS6ZDqWb9HteXhakoHgU6GZV6RzFu4tzTSR EOS77f1D5xApr9RaE7vS6ZDqWb9HteXhakoHgU6GZV6RzFu4tzTSR --buy-ram '0.3000 EOS' --stake-net '1.0000 EOS' --stake-cpu '0.0001 EOS'
cleos -u 'https://eospush.tokenpocket.pro' system newaccount itokenpocket ogxprestoken EOS77f1D5xApr9RaE7vS6ZDqWb9HteXhakoHgU6GZV6RzFu4tzTSR EOS77f1D5xApr9RaE7vS6ZDqWb9HteXhakoHgU6GZV6RzFu4tzTSR --buy-ram '1.0000 EOS' --stake-net '1.0000 EOS' --stake-cpu '0.0001 EOS'
cleos -u 'https://eospush.tokenpocket.pro' set account permission ogxprestoken active '{"threshold": 1,"keys": [{"key": "EOS77f1D5xApr9RaE7vS6ZDqWb9HteXhakoHgU6GZV6RzFu4tzTSR", "weight": 1}],"accounts": [{"permission":{"actor":"ogxprestoken","permission":"eosio.code"},"weight":1}]}' owner -p ogxprestoken@owner
cleos -u 'https://eospush.tokenpocket.pro' set contract ogxprestoken ./organix -p ogxprestoken

//代币合约授权
cleos -u 'https://eospush.tokenpocket.pro' set account permission organixtoken active '{"threshold": 1,"keys": [{"key": "EOS77f1D5xApr9RaE7vS6ZDqWb9HteXhakoHgU6GZV6RzFu4tzTSR", "weight": 1}],"accounts": [{"permission":{"actor":"ogxprestoken","permission":"eosio.code"},"weight":1}]}' owner -p organixtoken@owner

```
## 配置初始数据
```
cleos -u 'https://eospush.tokenpocket.pro' push action ogxprestoken addpair '["organixtoken", "15000000.0000 OGX", "15000000.0000 OGX", "eosio.token", "0.0000 EOS"]' -p ogxprestoken
cleos -u 'https://eospush.tokenpocket.pro' push action ogxprestoken addpair '["organixtoken", "5000000.0000 OGX", "5000000.0000 OGX", "eosiotptoken", "0.0000 TPT"]' -p ogxprestoken

cleos -u 'https://eospush.tokenpocket.pro' push action ogxprestoken deletepair '["1"]' -p ogxprestoken

```

## 查询
```
cleos -u 'https://eospush.tokenpocket.pro' get table ogxprestoken ogxprestoken pair
cleos -u 'https://eospush.tokenpocket.pro' get table ogxprestoken ogxprestoken pairinfo

cleos -u 'https://eospush.tokenpocket.pro' get currency balance organixtoken ogxfundation OGX
```

## 参与presale
```
//给organixtoken预留2000w OGX
cleos -u 'https://eospush.tokenpocket.pro' push action organixtoken transfer '["organixtoken", "ogxfundation", "79999999.9999 OGX", ""]' -p organixtoken
cleos -u 'https://eospush.tokenpocket.pro' push action organixtoken transfer '["ogxfundation", "ogxmarketing", "6000000.0000 OGX", ""]' -p ogxfundation
cleos -u 'https://eospush.tokenpocket.pro' push action organixtoken transfer '["ogxfundation", "ogxeosioteam", "25000000.0000 OGX", ""]' -p ogxfundation
cleos -u 'https://eospush.tokenpocket.pro' push action organixtoken transfer '["ogxfundation", "ogxprivate11", "31484537.5006 OGX", ""]' -p ogxfundation

//参与
cleos -u 'https://eospush.tokenpocket.pro' push action eosio.token transfer '["tokenfletest", "ogxprestoken", "100.0000 EOS", ""]' -p tokenfletest
cleos -u 'https://eospush.tokenpocket.pro' push action eosiotptoken transfer '["tokenfletest", "ogxprestoken", "500000.0000 TPT", ""]' -p tokenfletest
```

## 清算
```
cleos -u 'https://eospush.tokenpocket.pro' push action ogxprestoken dist '["eosiotptoken", "4,TPT", "200"]' -p ogxprestoken
```

## 其他
```
cleos -u 'https://eospush.tokenpocket.pro' push action organixtoken transfer '["ogxfundation", "gonglianyun1", "50.0000 OGX", ""]' -p ogxfundation
cleos -u 'https://eospush.tokenpocket.pro' push action organixtoken transfer '["ogxfundation", "newdexsweety", "50.0000 OGX", ""]' -p ogxfundation
cleos -u 'https://eospush.tokenpocket.pro' push action organixtoken transfer '["ogxfundation", "ruyi11111111", "50.0000 OGX", ""]' -p ogxfundation
cleos -u 'https://eospush.tokenpocket.pro' push action organixtoken transfer '["ogxfundation", "newdexsweety", "20000.0000 OGX", ""]' -p ogxfundation

```