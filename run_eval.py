#!/usr/bin/python3
#
# AutoCast evaluation runner, now re-implemented in Python for more options!
# NOTE: this is a WIP, currently it only runs scenario #10...
#
import os, sys, itertools, subprocess

# Do we want to run, for real?
runForReal = True

# Standard definitions
agent = "AutoCastSim/AVR/autocast_agents/simple_agent.py"

# CARLA ports and host. This is the default for AutoCast in
# a containerized environment
carlaPort = 2001
carlaHost = "172.17.0.1"

# Ego vehicle speeds to try:
egoSpeeds = [20, 40, 60]

# Ego vehicle distances to try
egoDistances = [3, 6, 12]

# Collider speeds to try
colliderSpeeds = [20, 40, 60]

# Collider distances to try
colliderDistances = [10, 20, 30]

# Collider acceleration distance(?) to try
colliderAccelDistances = [0]

# Background traffic settings to try
backgroundTraffic = [0]

# ======================================================================

# Calculate MQTT and TrafficManager ports
trafficManagerPort = int(carlaPort) + 50
mqttPort = int(carlaPort) + 100
print(f"Traffic manager will use port {trafficManagerPort}")

# Launch MQTT in the background (mosquitto -p $MQTTPORT -d)
if runForReal:
    os.system("killall -sigkill mosquitto")
    subprocess.Popen(["mosquitto", "-p", str(mqttPort), "-d"])
    print(f"MQTT daemon launched in background (port {mqttPort})")
else:
    print("Scenario combination debug mode set (runForReal = False), we will not be launching MQTT")

# ======================================================================

# Create combinations of scenarios to try:
scenarios = list(itertools.product(egoSpeeds, egoDistances, colliderSpeeds, colliderDistances, colliderAccelDistances, backgroundTraffic))
print(f"We have a total of {len(scenarios)} scenarios to run")

for i, scenario in enumerate(scenarios):

    egoSpeed = scenario[0]
    egoDistance = scenario[1]
    colliderSpeed = scenario[2]
    colliderDistance = scenario[3]
    colliderAccelDistance = scenario[4]
    backgroundTraffic = scenario[5]

    outputSubDir = f"test/run_{egoSpeed}_{egoDistance}_{colliderSpeed}_{colliderDistance}_{colliderAccelDistance}_{backgroundTraffic}/"

    print("")
    print(f"Scenario {i}")
    print(f"Ego speed {egoSpeed}, Ego distance {egoDistance}, Collider speed {colliderSpeed}, Collider distance {colliderDistance}, Collider accel distance {colliderAccelDistance}, Background traffic {backgroundTraffic}")
    print(f"Output directory: {outputSubDir}")
    print("-" * 120)

    # Run command
    runCmd = f"python3 scenario_runner.py \
            --route AutoCastSim/srunner/data/routes_training_town03_autocast10.xml \
                AutoCastSim/srunner/data/towns03_traffic_scenarios_autocast10.json   \
            --reloadWorld \
            --agent {agent} \
            --eval {egoSpeed} {egoDistance} {colliderSpeed} {colliderDistance} {colliderAccelDistance} \
            --bgtraffic {backgroundTraffic} \
            --port {carlaPort} \
            --host {carlaHost} \
            --trafficManagerPort {trafficManagerPort} \
            --mqttport {mqttPort} \
            --outputdir {outputSubDir} \
            --sharing \
            --seed 1300 \
            --hud"

    if runForReal:
        os.system(runCmd)
    else:
        print("<<<< RUN SKIPPED >>>>")
    print("=" * 120)
