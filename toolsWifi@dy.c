#!/bin/bash
#echo "Agus Edy Cahyono G.211.13.0047"
OPTIONS="AP-without-Internet-sharing WPA+WPA2-passphrase Internet-sharing-from-the-same-WiFi-interface Ifconfig Quit"
SSID="w3_@dy.c"
PASS="1q2w3e4r5t6y7u8i"
select opt in $OPTIONS; do
	if [ "$opt" = "Quit" ]; then
		echo done
		exit
	
	elif [ "$opt" = "AP-without-Internet-sharing" ]; then
		create_ap -n wlan0 $SSID $PASS

	elif [ "$opt" = "WPA+WPA2-passphrase" ]; then
		create_ap wlan0 eth0 $SSID $PASS

	elif [ "$opt" = "Internet-sharing-from-the-same-WiFi-interface" ]; then
		create_ap wlan0 wlan0 $SSID $PASS

	elif [ "$opt" = "Ifconfig" ]; then
		ifconfig
	else
		clear
		echo bad option
	fi
done
