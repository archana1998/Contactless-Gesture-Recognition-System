import serial #Serial imported for serial communication
import time 
import pyautogui

ArduinoSerial = serial.Serial('com5',9600) #Create Serial port object called arduinoSerialData
time.sleep(2)

while 1:
  incoming = str(ArduinoSerial.readline())
  print(incoming)
  if 'Push' in incoming:
      pyautogui.typewrite(['space'], 0.2)
  if 'Left swipe!' in incoming:
      pyautogui.hotkey('ctrl', 'left')
  if 'Right swipe!' in incoming:
      pyautogui.hotkey('ctrl', 'right')
      
   incoming = "";
