import os 
import shutil


    

exist = False 
while exist == False: 
    if os.path.exists("/mnt/e") == True: 
        exist = True 
        print("Pico Detected")
    else:           
        print("No Pico Detected")
        
        