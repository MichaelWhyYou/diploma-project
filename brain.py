
# sudo chmod -R a+r /sys/class/powercap/intel-rapl
# Above command allows code to access intel-rapl

### Libraries ###
import csv
import subprocess
import pyRAPL # Imports the pyRAPL library: https://pyrapl.readthedocs.io/en/latest/API.html
pyRAPL.setup(devices=[pyRAPL.Device.PKG]) # Specifies the monitoring of the CPU


### SETTINGS ###

# Trials to be conducted per test case
trials = 10 

# Registry of test cases, identical to file names
TEST_CASES = ["loop","linear_regression","heap_sort"] 

# Dictionary of language options, consisting of interpreter and file extension
language_options = {  
    "python": ["python3",".py"],
    "javascript": ["node",".js"],
    "cpp": ["./",""],
    "c": ["./",""]
}


### USER INPUT FOR LANGUAGE TO TEST ###
print("[Info] The Energy Consumption Measurement System Has Been Launched\n[Info] Made by Michael Yu")

while True:
    print("\nSelect which language to test [" + ", ".join(map(str, language_options.keys())) + "]")
    selected_language = input("Language: ")
    if selected_language in language_options:
        break


### TRIALS ###
for test_case in TEST_CASES:
    
    pkg_measure = 0.0 # Micro Joules
    time_measure = 0.0 # Micro Seconds
    CSV_Data = [["TRIAL", test_case + "-Energy", test_case + "-Time"]]
    command = [language_options[selected_language][0], "TEST_" + selected_language + "/" + test_case + language_options[selected_language][1]] # Command to execute
    if selected_language == "cpp" or selected_language == "c": 
        command = ["./TEST_" + selected_language + "/"+test_case]
    print("=== " + selected_language + ": Starting " + test_case + " Trials ===")
    for n in range(trials):

        print("Running Trial " + str(n))
        measure = pyRAPL.Measurement("Trial-" + str(n)) # Initialize the Measurement class
        
        measure.begin() # Start the energy consumption and time recording
        subprocess.run(command)
        measure.end() # End the energy consumption and time recording

        # Record Results
        pkg_measure += measure.result.pkg[0]
        time_measure += measure.result.duration
        CSV_Data.append([n+1, measure.result.pkg[0], measure.result.duration])
        print(measure.result) 

        
    print("============\nTest Results | " + "PKG: " + str(pkg_measure/trials) + " | Duration: " + str(time_measure/trials) + " | Total Trials: " + str(trials) + "\n\n")
    CSV_Data.append(["Average", pkg_measure/trials, time_measure/trials])
    # Create CSV File
    with open(selected_language + "_" + test_case + ".csv", "w", newline="") as file:
        writer = csv.writer(file)
        writer.writerows(CSV_Data)
