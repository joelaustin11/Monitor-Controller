#!/usr/bin/python3

# This script is for building RP2040 firmware

import os 
import shutil

class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

with open ('last_used.txt', 'r') as f: 
        project = f.readline()
        
with open ('firmbuild_mode.txt', 'r') as f: 
    mode = f.readline()
    

    
print("\nConfigure Firmware Build:")
print(bcolors.UNDERLINE +  bcolors.OKGREEN +  "\n\nLast used project folder: " + bcolors.BOLD + bcolors.OKBLUE + f"{project}")
if mode == 'f': 
    print(bcolors.UNDERLINE +  bcolors.OKGREEN +  "\nLast used build mode: " + bcolors.BOLD + bcolors.OKBLUE + "Full Build")
elif mode == 'h': 
    print(bcolors.UNDERLINE +  bcolors.OKGREEN +  "\nLast used build mode: " + bcolors.BOLD + bcolors.OKBLUE + "Half Build")
else: 
    print(bcolors.WARNING + "MODE CONFIG FILE INCOMPLETE" + bcolors.ENDC)


restore_settings = input(bcolors.UNDERLINE +  bcolors.OKGREEN +"\nKeep last used settings? (Enter: yes, press any key to change)\n:" + bcolors.ENDC)

if restore_settings != "":
    
    while True: 
        project = input("\nNew Project Name (Enter for last used project)")
        if project == "": 
            with open ('last_used.txt', 'r') as f: 
                project = f.readline()
                break
            
        else: 
            with open ('last_used.txt', 'w') as f:
                f.write(project)
                break
        
    
    while True: 
        mode = input("\nSelect build mode:\nF: Full Build\nH: Half Build\n:")
        if mode == "": 
            print(bcolors.WARNING + "input cannot be blank" + bcolors.ENDC)
            continue
        elif mode == "f": 
            print("Full build selected" + bcolors.WARNING + "\ncurrent build directory will be deleted" + bcolors.ENDC)
            with open('firmbuild_mode.txt', 'w') as f: 
                f.write(mode)
                break
        elif mode == "h": 
            print("Half build selected")
            with open('firmbuild_mode.txt', 'w') as f: 
                f.write(mode)
                break
        else: 
            print(bcolors.WARNING + "invalid input" + bcolors.ENDC)
            continue
else: 
    print("Restoring settings...")
            
 
if mode == "f": 
    os.system(f"sudo rm -r {project}/build")
    os.chdir(f"{project}")
    os.mkdir("build")
    os.chdir("build")
    os.system("cmake ..")
    os.system("make")
elif mode == "h": 
    try:
        os.chdir(f"{project}/build")
        os.system("make")
    except: 
        print(bcolors.WARNING + "No build directory: aborting build, select Full Build to reconstruct" + bcolors.ENDC)
    



os.system("cmake ..")
os.system("make")

