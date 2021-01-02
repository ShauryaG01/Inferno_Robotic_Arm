#!/usr/bin/env python
import rospy
import serial
from std_msgs.msg import String
from std_msgs.msg import UInt16
from sensor_msgs.msg import Joy
from geometry_msgs.msg import Point

arduino = serial.Serial("/dev/ttyACM0", 9600, timeout = 1 )

def sub_values(data) : #to read values sent from the joy_pub_node
    val=0
    rate= rospy.Rate(10)
    value = "X" + str(int(data.x)) + "Y" + str(int(data.y)) + "Z" + str(int(data.z)) + "E" + "\0"
    print ("The value in string is : " + value)
    arduino.write(str(value))
   # val = str(arduino.readline())
    #print("Value from arduino is : "  + str(val))
    rate.sleep()

def joy_reciever() :
    rospy.init_node('joy_reciever', anonymous=True)
    rospy.Subscriber("robotic_arm", Point, sub_values, queue_size=1)
    rospy.spin()

if __name__ == '__main__':
    joy_reciever()