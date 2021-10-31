// ESP32
#include <SPI.h>
#include <LoRa.h>

#define SS 5
#define RST 14
#define DIO0 2

int counter = 0;

void setup() {
	Serial.begin(115200);
	Serial.println("LoRa Receiver");
	LoRa.setPins(SS, RST, DIO0);

	while(!LoRa.begin(433E6)) {
		Serial.println(".");
		delay(500);
	}
	LoRa.setSyncWord(0xA5);
	Serial.println("LoRA Initializing OK!");
	/*
	LoRa.setTxPower(20);
	LoRa.setFrequency();
	LoRa.setSpreadingFactor();
	LoRa.setSignalBandwidth();
	*/
}

void loop() {
	Serial.print("Sending Packet : ");
	Serial.println(counter);
	LoRa.beginPacket();
	LoRa.print(counter);
	LoRa.endPacket();
	counter++;
	delay(1000);
}
