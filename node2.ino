//include required libraries
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

static SensorManager sensors;

void onConnected() 
{
  Serial.println("Connected to ThingsBoard");
}

void setup() 
{
  Serial.begin(9600);
  Serial.print("Node2 is booting...");

  sensor_begin();
  sensor_init(&sensors);

  actuators_begin();

  telemetry_init(sharedBuf, sizeof(sharedBuf));
  rpc_init(&mqttClient, sharedBuf, sizeof(sharedBuf));

  network_begin(&mqttClient, onConnected);
}

void loop() 
{
  network_maintain();

  SensorData data;
  
  sensor_read(&sensors, &data);

  if(data.humidity >= HUMIDITY_CRIT && !actuators_getRelayState())
  {
    actuators_setRelay(1);
  }

  if(network_isConnected())
  {
    unsigned long now = millis();

    if(now - lastTelemetry >= TELEMETRY_INTERVAL)
    {
      lastTelemetry = now;   
      telemetry_publishTelemetry(&data, actuators_getRelayState());
    }
  }

  actuators_updateStatusLEDs(network_isConnected(), &data);
}