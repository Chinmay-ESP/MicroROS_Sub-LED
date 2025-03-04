# LED Control via ROS2 (Micro-ROS with ESP32)

## Overview
This project demonstrates how to control an LED on an ESP32 using ROS2 (Micro-ROS). The ESP32 acts as a ROS2 node that subscribes to an `Int32` message from the topic `led_control`. The received integer value (0 or 1) determines the LED state.

## Hardware Requirements
- ESP32 Development Board
- LED (Optional, if using an external LED)
- USB Cable for programming

## Software Requirements
- PlatformIO
- Micro-ROS library
- ROS2 installed on a PC

## Code Explanation
- The ESP32 subscribes to the `led_control` topic.
- When a message is received, it controls the LED state based on the received value.
- Uses Micro-ROS for communication between ESP32 and ROS2.

## Setup Instructions
1. **Install Micro-ROS**:
   - Follow the official Micro-ROS documentation to set up the environment for ESP32.
   - Install the required dependencies for Arduino or PlatformIO.

2. **Upload the Code**:
   - Connect the ESP32 to your PC.
   - Compile and upload the code using PlatformIO or Arduino IDE.

3. **Run ROS2 Publisher**:
   - Ensure ROS2 is installed on your PC.
   - Run the following command to publish LED state messages:
     ```bash
     ros2 topic pub /led_control std_msgs/msg/Int32 "{data: 1}"
     ```
     - Send `1` to turn the LED ON.
     - Send `0` to turn the LED OFF.

4. **Monitor Serial Output**:
   - Open the Serial Monitor at 115200 baud rate to observe received messages.

## Function Breakdown
- **`setup()`**:
  - Initializes the serial communication.
  - Configures the LED pin as an output.
  - Sets up Micro-ROS, creates a node, and subscribes to the `led_control` topic.

- **`subscription_callback()`**:
  - Receives an integer value from ROS2.
  - Controls the LED state accordingly.
  - Prints the received data to the Serial Monitor.

- **`loop()`**:
  - Executes the Micro-ROS executor to handle incoming messages.

## Notes
- Ensure ROS2 is properly configured on your PC before running the publisher.
- Modify the `LED_PIN` macro if using a different GPIO for the LED.

## References
- [Micro-ROS Documentation](https://micro.ros.org/)
- [ROS-2(Humble) Documentation](https://docs.ros.org/en/humble/index.html)

