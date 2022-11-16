import time
import schedule
import serial
import csv
from datetime import datetime

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
 
schedule.every(15).seconds.do(collectdata)

while 1:
    schedule.run_pending()
    print("waiting for next data")
    time.sleep(1)

