# 🏭 Smart Factory IoT Monitoring System

> **Advanced IoT-based real-time monitoring solution for industrial environments**

[![Language](https://img.shields.io/badge/Language-C%2B%2B-blue?style=flat-square&logo=cplusplus)](https://cplusplus.com/)
[![License](https://img.shields.io/badge/License-MIT-green?style=flat-square)](LICENSE)
[![Status](https://img.shields.io/badge/Status-Active-success?style=flat-square)](#)

---

## 📋 Table of Contents

- [✨ Features](#-features)
- [🎯 Project Overview](#-project-overview)
- [🛠️ Tech Stack](#️-tech-stack)
- [📦 Installation](#-installation)
- [🚀 Quick Start](#-quick-start)
- [📊 Architecture](#-architecture)
- [🔧 Configuration](#-configuration)
- [📝 Usage Examples](#-usage-examples)
- [🐛 Troubleshooting](#-troubleshooting)
- [🤝 Contributing](#-contributing)
- [📺 Project Explanation](#-project-explanation)
- [📄 License](#-license)

---

## ✨ Features

- 🌐 **Real-time Data Collection** - Continuous monitoring of IoT sensors across factory floor
- 📊 **Data Analytics Dashboard** - Visualize metrics and performance indicators
- ⚠️ **Alert System** - Instant notifications for anomalies and critical events
- 🔐 **Secure Communication** - Encrypted data transmission between devices
- 💾 **Data Logging** - Persistent storage with historical trend analysis
- 📱 **Remote Access** - Monitor factory operations from anywhere
- ⚡ **High Performance** - Optimized C++ implementation for low latency
- 🔄 **Scalable Architecture** - Support for multiple sensors and devices
- 🎛️ **Modular Design** - Easy integration and customization

---

## 🎯 Project Overview

The **Smart Factory IoT Monitoring System** is an enterprise-grade solution designed to:

- 📈 Monitor production metrics in real-time
- 🔍 Detect equipment failures before they occur
- 📉 Optimize energy consumption and operational efficiency
- 📊 Generate comprehensive reports for management
- 🛡️ Ensure workplace safety through continuous monitoring
- 🔗 Integrate with existing factory infrastructure

This system leverages IoT sensors distributed across the factory floor to collect critical operational data, process it intelligently, and provide actionable insights.

---

## 🛠️ Tech Stack

| Component | Technology |
|-----------|-----------|
| **Language** | C++ (C++11/14/17) |
| **Architecture** | Embedded Systems & IoT |
| **Communication** | MQTT/REST APIs |
| **Database** | Time-series Database |
| **Networking** | TCP/IP, Wireless |
| **Platforms** | Linux, Embedded Linux, Windows |

---

## 📦 Installation

### Prerequisites

- **C++ Compiler**: GCC 9.0+ or Clang 10.0+
- **Build System**: CMake 3.15+
- **Dependencies**: 
  - Boost Libraries
  - OpenSSL
  - MQTT Client Library
  - SQLite/PostgreSQL

### Step 1: Clone the Repository

```bash
git clone https://github.com/abinaya-345/Smart-Factory-IOT-Monitoring-System---EMERTXE.git
cd Smart-Factory-IOT-Monitoring-System---EMERTXE
```

### Step 2: Install Dependencies

```bash
# Ubuntu/Debian
sudo apt-get install -y \
  libboost-all-dev \
  libssl-dev \
  libmosquitto-dev \
  sqlite3 \
  cmake \
  build-essential

# macOS
brew install boost openssl mosquitto cmake
```

### Step 3: Build the Project

```bash
mkdir build
cd build
cmake ..
make
```

### Step 4: Install

```bash
sudo make install
```

---

## 🚀 Quick Start

### 1️⃣ Start the Monitoring Service

```bash
./smart_factory_monitor --config config/factory.conf
```

### 2️⃣ Configure Sensors

Edit `config/sensors.json`:

```json
{
  "sensors": [
    {
      "id": "sensor_001",
      "type": "temperature",
      "location": "Assembly Line A",
      "interval": 5000
    },
    {
      "id": "sensor_002",
      "type": "pressure",
      "location": "Hydraulic Press 1",
      "interval": 3000
    }
  ]
}
```

### 3️⃣ Access the Dashboard

```
Navigate to: http://localhost:8080
Default credentials: admin / admin
```

---

## 📊 Architecture

```
┌─────────────────────────────────────────────────────────────┐
│                    Smart Factory System                     │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│  ┌──────────┐  ┌──────────┐  ┌──────────┐  ┌──────────┐   │
│  │ Sensor 1 │  │ Sensor 2 │  │ Sensor 3 │  │ Sensor N │   │
│  │(Temp)    │  │(Pressure)│  │(Humidity)│  │  (...)   │   │
│  └────┬─────┘  └────┬─────┘  └────┬─────┘  └────┬─────┘   │
│       │             │             │             │          │
│       └─────────────┼─────────────┼─────────────┘          │
│                     ▼                                      │
│         ┌──────────────────────────┐                      │
│         │   Data Collection Layer   │                      │
│         │ (MQTT/REST Endpoints)    │                      │
│         └────────────┬─────────────┘                      │
│                      ▼                                      │
│         ┌──────────────────────────┐                      │
│         │   Processing Engine      │                      │
│         │ (Real-time Analytics)    │                      │
│         └────────────┬─────────────┘                      │
│                      ▼                                      │
│    ┌─────────────────┼─────────────────┐                 │
│    ▼                 ▼                 ▼                   │
│  ┌─────┐         ┌─────────┐       ┌────────┐            │
│  │Alert│         │Dashboard│       │Storage │            │
│  │Module         │(Web UI) │       │(Data DB)            │
│  └─────┘         └─────────┘       └────────┘            │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

---

## 🔧 Configuration

### Environment Variables

```bash
export FACTORY_MQTT_BROKER=mqtt.example.com
export FACTORY_MQTT_PORT=1883
export FACTORY_DB_PATH=/var/lib/smart-factory/data.db
export FACTORY_LOG_LEVEL=INFO
export FACTORY_API_PORT=8080
```

### Configuration File

Create `config/factory.conf`:

```ini
[mqtt]
broker = localhost
port = 1883
username = factory_user
password = secure_password

[database]
type = sqlite
path = /var/lib/smart-factory/data.db
max_connections = 20

[monitoring]
interval = 5000
log_level = INFO
max_retries = 3

[alerts]
enabled = true
slack_webhook = https://hooks.slack.com/services/YOUR/WEBHOOK
email_recipients = admin@factory.com
```

---

## 📝 Usage Examples

### C++ API Usage

```cpp
#include "smart_factory/monitor.hpp"

int main() {
    // Initialize monitoring system
    SmartFactory::Monitor monitor("config/factory.conf");
    
    // Start data collection
    monitor.start();
    
    // Register alert callback
    monitor.on_alert([](const SmartFactory::Alert& alert) {
        std::cout << "🚨 Alert: " << alert.message << std::endl;
    });
    
    // Keep running
    while(true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    
    return 0;
}
```

### REST API Examples

**Get Current Sensor Data:**
```bash
curl -X GET http://localhost:8080/api/v1/sensors/sensor_001/data
```

**Set Alert Threshold:**
```bash
curl -X POST http://localhost:8080/api/v1/alerts \
  -H "Content-Type: application/json" \
  -d '{
    "sensor_id": "sensor_001",
    "threshold": 75.5,
    "condition": "greater_than"
  }'
```

---

## 🐛 Troubleshooting

### ❌ Connection Issues

**Problem:** Cannot connect to MQTT broker

**Solution:**
```bash
# Check broker status
mosquitto -v

# Test connection
mosquitto_sub -h localhost -t "test/topic"
```

### ❌ High CPU Usage

**Problem:** System consuming excessive CPU

**Solution:**
1. Increase polling interval in config
2. Reduce number of active sensors
3. Check for memory leaks: `valgrind ./smart_factory_monitor`

### ❌ Data Loss

**Problem:** Missing sensor readings

**Solution:**
- Verify sensor connectivity
- Check network bandwidth
- Review logs: `tail -f /var/log/smart-factory/system.log`

---

## 🤝 Contributing

Contributions are welcome! Please:

1. 🍴 Fork the repository
2. 🌿 Create a feature branch (`git checkout -b feature/amazing-feature`)
3. 💬 Commit changes (`git commit -m 'Add amazing feature'`)
4. 📤 Push to branch (`git push origin feature/amazing-feature`)
5. 🔀 Open a Pull Request

### Development Guidelines

- Follow C++ Core Guidelines
- Write unit tests for new features
- Update documentation
- Maintain code style with clang-format

---

## 📺 Project Explanation

For a detailed project walkthrough and live demonstration, check out our video:

📹 **[Smart Factory IoT System - Full Explanation](https://youtu.be/jDjvur5aQtQ?si=bZMonC3xEVy-SiQr)**

The video covers:
- 🏗️ System architecture and design
- 🔌 Sensor integration process
- 📊 Data processing pipeline
- 💻 Dashboard and UI walkthrough
- 🔧 Configuration and deployment
- 📈 Real-world use cases

---

## 📄 License

This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.

---

## 📧 Contact & Support

- 👤 **Author**: Abinaya-345
- 🐛 **Issues**: [GitHub Issues](https://github.com/abinaya-345/Smart-Factory-IOT-Monitoring-System---EMERTXE/issues)
- 💬 **Discussions**: [GitHub Discussions](https://github.com/abinaya-345/Smart-Factory-IOT-Monitoring-System---EMERTXE/discussions)

---

## ⭐ Acknowledgments

- EMERTXE Learning Excellence
- IoT Community Contributors
- Open Source Projects & Libraries

---

<div align="center">

**Made with ❤️ by Abinaya**

[![Give it a Star! ⭐](https://img.shields.io/badge/Give%20it%20a%20Star-⭐-yellow?style=for-the-badge)](https://github.com/abinaya-345/Smart-Factory-IOT-Monitoring-System---EMERTXE/stargazers)

</div>
