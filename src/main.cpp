#include <Arduino.h>
#include <micro_ros_platformio.h>
#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <std_msgs/msg/int32.h>

#define LED_PIN 23  

rcl_subscription_t subscriber;
std_msgs__msg__Int32 received_msg;
rclc_support_t support;
rcl_allocator_t allocator;
rcl_node_t node;
rclc_executor_t executor;

void subscription_callback(const void *msg)
{
    const std_msgs__msg__Int32 *data = (const std_msgs__msg__Int32 *)msg;
    digitalWrite(LED_PIN, data->data); // Control LED
    Serial.printf("Received LED State: %d\n", data->data);
}

void setup()
{
    Serial.begin(115200);  
    delay(2000); // 

    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);

    set_microros_serial_transports(Serial);

    
    allocator = rcl_get_default_allocator();
    rclc_support_init(&support, 0, NULL, &allocator);
    rclc_node_init_default(&node, "led_subscriber_node", "", &support);
    
    rclc_subscription_init_default(
        &subscriber,
        &node,
        ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32),
        "led_control"
    );

    rclc_executor_init(&executor, &support.context, 1, &allocator);
    rclc_executor_add_subscription(&executor, &subscriber, &received_msg, &subscription_callback, ON_NEW_DATA);

}

void loop()
{
    rclc_executor_spin_some(&executor, RCL_MS_TO_NS(100));
}
