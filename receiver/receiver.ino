// ESP32
#include <SPI.h>
#include <LoRa.h>

#define SS 5
#define RST 14
#define DIO0 2

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
}

void loop() {
	int packet_size = LoRa.parsePacket();
	if(packet_size) {
		Serial.print("Packet Size : ");
		Serial.print(packet_size);
		Serial.print(", Received Packet : ");
		while(LoRa.available()) {
			Serial.print((char) LoRa.read());
		}

		Serial.print(", with RSSI ");
		Serial.println(LoRa.packetRssi());
	}
}
