echo  'KERNEL=="ttyUSB*", ATTRS{idVendor}=="0403", ATTRS{idProduct}=="6001", MODE:="0777", GROUP:="dialout", SYMLINK+="rm_servo"' >/etc/udev/rules.d/rm_servo.rules
service udev reload
sleep 2
service udev restart
