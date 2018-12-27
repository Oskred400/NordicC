#!/bin/sh
#This file contains path variables for 
#1. armgcc toolchain
#2. nRf5-SDK for thread and zigbee
#3. The blink LED example.
#4. Included the makefile

#!/bin/sh

echo "Setting up the environment"


export NRF_SDK=/home/cyborg1-0/Downloads/nRF5_SDK_for_Thread_and_Zigbee_2.0.0_29775ac
export NRF_BLINK=/home/cyborg1-0/OSProj/blink
export GNU_ARM_EMBEDDED=/home/cyborg1-0/Downloads/gcc-arm-none-eabi-7-2018-q2-update
export NRF52_DK=/home/cyborg1-0/mynewt_nordic/hw/bsp/include
export NRF_802154_DRIVER=/home/cyborg1-0/nRF-IEEE-802.15.4-radio-driver/src
export APP_TIMER=/home/cyborg1-0/Downloads/nRF5_SDK_15.2.0_9412b96/components/libraries



echo "NRF_SDK=${NRF_SDK}"

echo "NRF_BLINK=${NRF_BLINK}"
echo "GNU_ARM_EMBEDDED=${GNU_ARM_EMBEDDED}"
#echo BSP="${BSP}"
echo "NRF_802154_DRIVER=${NRF_802154_DRIVER}"
#echo NRF52_DRIVER="${NRF52_DRIVER}"


echo "APP_TIMER=${APP_TIMER}"

echo "NRF52_DK=${NRF52_DK}"




