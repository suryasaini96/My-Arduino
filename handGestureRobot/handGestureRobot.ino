#include <VirtualWire.h>

const int ledTxPin=4;
const int ledRxPin=13;
const int txPin=2;
const int rxPin=8;

char data[1];

void setup() {
  pinMode(13,OUTPUT);
  pinMode(4,OUTPUT);
  vw_set_ptt_inverted(true);
  vw_set_tx_pin(txPin);
  vw_set_rx_pin(rxPin);
  vw_setup(4000); //Set at 2000 bits per sec
  vw_rx_start();
}

void loop() {

  data[0]='1';
  vw_send((uint8_t*)data,1);
  vw_wait_tx();
  digitalWrite(ledTxPin,HIGH);
  Serial.println('1');
  delay(2000);

  data[0]='0';
  vw_send((uint8_t*)data,1);
  vw_wait_tx();
  digitalWrite(ledTxPin,LOW);
  Serial.println('1');
  delay(2000);
  
  uint8_t buff[VW_MAX_MESSAGE_LEN];
  uint8_t buffLen = VW_MAX_MESSAGE_LEN;

  if(vw_get_message(buff,&buffLen))
  {
    if(buff[0]=='1'){
      Serial.println('1');
      digitalWrite(ledRxPin,HIGH);
      delay(2000);
    }
    else if(buff[0]=='0'){
      Serial.println('0');
      digitalWrite(ledRxPin,LOW);
      delay(2000);
    }
  }
}

