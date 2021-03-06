#!/bin/bash
DATADIR="./blockchain"
CURDIRNAME=${PWD##*/}

if [ ! -d $DATADIR ]; then
  mkdir -p $DATADIR;
fi

if [  -f $DATADIR"/nodeos.log" ]; then
  echo "" > $DATADIR"/nodeos.log"
fi

nodeos \
--signature-provider EOS5CXYetxpcMwkpTc2DaL3iurGZUPHoAKXg1QZdLrwF15JYRYUHY=KEY:5JqVhpCGS38iqo55BikWsnNcvKRQYK6be6uRvcKKsBtAWbMVvKC \
--plugin eosio::producer_plugin \
--plugin eosio::producer_api_plugin \
--plugin eosio::chain_plugin \
--plugin eosio::chain_api_plugin \
--plugin eosio::http_plugin \
--plugin eosio::history_api_plugin \
--plugin eosio::history_plugin \
--data-dir $DATADIR"/data" \
--blocks-dir $DATADIR"/blocks" \
--config-dir $DATADIR"/config" \
--producer-name $CURDIRNAME \
--http-server-address 127.0.0.1:18012 \
--p2p-listen-endpoint 127.0.0.1:19012 \
--access-control-allow-origin=* \
--contracts-console \
--http-validate-host=false \
--verbose-http-errors \
--enable-stale-production \
--filter-on=* \
--p2p-peer-address localhost:19010 \
--p2p-peer-address localhost:19011 \
--p2p-peer-address localhost:19013 \
>> $DATADIR"/nodeos.log" 2>&1 & \
echo $! > $DATADIR"/eosd.pid"
