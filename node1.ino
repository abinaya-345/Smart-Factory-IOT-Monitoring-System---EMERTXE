// include required libraries
#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>
#include <DHT.h>

#include "config.h"
#include "SensorManager.h"
#include "actuator.h"
#include "network.h"
#include "telemetry.h"
#include "rpc.h"

static char sharedBuf[200];

// create object of type ethernet pubsubclient
static EthernetClient ethClient;
static PubSubClient mqttClient(ethClient);

unsigned long lastTelemetry = 0;

void setup() 
{
  Serial.begin(9600);
  Serial.print("Node1 is booting...");

  // initialise sensor
  sensor_begin();
  // initialise actuators
  actuators_begin();

  telemetry_init(sharedBuf, sizeof(sharedBuf));
  rpc_init(&mqttClient, sharedBuf, sizeof(sharedBuf));  // initialising rpc request

  // upon reciving the data whhich function needs to be called back
  mqttClient.setCallback(rpc_mqttCallback);
  // connect board to internet and mqtt
  network_begin(&mqttClient);
  mqttClient.setCallback(rpc_mqttCallback);

  pinMode(PIN_LED_RED, OUTPUT);   
  digitalWrite(PIN_LED_RED, LOW);
}

void loop() 
{
  network_maintain();

  SensorData data;
  sensors_read(&data);

  if(network_isConnected())
  {
    unsigned long now = millis();

    if(now - lastTelemetry >= TELEMETRY_INTERVAL)
    {
      lastTelemetry = now;   
      telemetry_publishTelemetry(&data, actuators_getRelayState);
    }
  }

  actuators_updateStatusLEDs(network_isConnected(), data.sensorError);
  
}
