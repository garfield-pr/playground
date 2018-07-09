import threading as thread
import time

def getinput():
    while True:
        if raw_input("Press q to stop") == "q":
            return
        time.sleep(1) 

t = thread.Thread(target=getinput)
t.start()
while True:
    if thread.active_count() == 0:
        break
    print("still working...")
    time.sleep(1)