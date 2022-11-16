import csv
import time
from datetime import datetime

import schedule
import serial

int readtime = 15 #reads serial port every 15 seconds
ser = serial.Serial('COM3', 9600, timeout=1)

print("Initalizing   Please Wait......................")
time.sleep(1)


def collectdata():
    ser.flushInput()
    cc = str(ser.readline())
    clcc = str(cc[2:][:-5])
    data = clcc.split(',')
    data.insert(0,datetime.now())
    print (data)

    with open("test_data.csv", 'a', newline='') as f:
        w = csv.writer(f,delimiter=",")
        w.writerow(data)
 
schedule.every(readtime).seconds.do(collectdata)

while 1:
    schedule.run_pending()
    print("waiting for next data")
    time.sleep(1)

